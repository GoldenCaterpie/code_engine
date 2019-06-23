#ifndef ENGINE7_PC_H
#define ENGINE7_PC_H

#include "../types.h"


struct ov_script
{ //0x3000e40
    u8 push_counter;
    u8 mode;
    u8 comp_result;
    u8 padd;
    void* waiting_routine;
    void* curr_instruction;//0x 3000e48
    void* stack[20];
    void* commands_table_start;
    void* commands_table_end;
    u32 vars[4];
};

extern struct ov_script over_world_script;

struct pokemon_pc
{
    u32 data[20];
};

struct save_block3
{
    u8 current_box;
    u8 pad0;
    u16 padd1;
    struct pokemon_pc pc_pokes[14][30];
    u8 name[14][9];//8344
    u8 bg[14];//83C2
};

extern struct save_block3* sav3;

#define EXPANDED_BOX 8
#define MAX_BOX_COUNT (EXPANDED_BOX + 14) //22

struct save_block3_new
{
    u8 name[EXPANDED_BOX][9];
    u8 bg[EXPANDED_BOX];//100 bytes
    struct pokemon_pc pc_pokes[EXPANDED_BOX][30];
};

extern struct save_block3_new new_sav3;

inline void CpuSet(void* src, void* dst, u32 mode){
    __asm("swi 0xB"::"r"(src), "r"(dst), "r"(mode):);
}
inline void LZ77UnCompWram(const void* src, void* dst){
    __asm("swi 0x11"::"r"(src), "r"(dst):);
}
#define longcall __attribute__((long_call))



struct status_main
{
    u32 sleep : 3;
    u32 poison : 1;
    u32 burn : 1;
    u32 freeze : 1;
    u32 paralysis: 1;
    u32 toxic_poison : 1;
    u32 poison_counter : 4;
};

union main_status
{
    u32 int_status;
    struct status_main flags;
};

#define STATUS_SLEEP 0x7
#define STATUS_POISON 0x8
#define STATUS_BURN 0x10
#define STATUS_FREEZE 0x20
#define STATUS_PARALYSIS 0x40
#define STATUS_TOXIC_POISON 0x80
#define STATUS_CONFUSION 0x1

struct flags2
{
    u32 confusion : 3; //0x1 | 0x2 | 0x4
    u32 flinched : 1; //0x8
    u32 uproar : 3; //0x10 | 0x20 | 0x40
    u32 flag_x80 : 1; //0x80
    u32 bide : 2; //0x100 | 0x200
    u32 locked_and_confuse : 2; //0x400 | 0x800
    u32 multiple_turn_move : 1; //0x1000
    u32 trapped_in_wrap : 3; //0x2000 | 0x4000 | 0x8000
    u32 in_love : 4; //each bit for bank 0x10 000 | 0x20 000 | 0x40 0000 | 0x80 000
    u32 focus_energy : 1; //0x100 000
    u32 transformed : 1; //0x200 000
    u32 recharge : 1; //0x400 000
    u32 raged : 1; //0x800 000
    u32 substitute : 1;// 0x1 000 000
    u32 destinny_bond : 1; //0x2 000 000
    u32 cant_escape : 1; //0x4 000 000
    u32 nightmare : 1; //0x8 000 000
    u32 cursed : 1; //0x10 000 000
    u32 foresight : 1; //0x20 000 000
    u32 defense_curled : 1; //0x40 000 000
    u32 tormented : 1; //0x80 000 000
};

struct iv_set
{
    u32 iv_hp: 5;
    u32 iv_atk: 5;
    u32 iv_def: 5;
    u32 iv_spd: 5;
    u32 iv_sp_atk: 5;
    u32 iv_sp_def: 5;
};

struct battle_participant
{
    u16 species;//0
    u16 atk;//2
    u16 def;//4
    u16 spd;//6
    u16 sp_atk;//8
    u16 sp_def;//10
    u16 moves[4];//12
    struct iv_set ivs;//20
    u8 hp_buff;//24
    u8 atk_buff;//25
    u8 def_buff;//26
    u8 spd_buff;//27
    u8 sp_atk_buff;//
    u8 sp_def_buff;
    u8 acc_buff;
    u8 evasion_buff;
    u8 ability_id;//32
    u8 type1;
    u8 type2;
    u8 padd;
    u8 current_pp[4];
    u16 current_hp;
    u8 level;
    u8 happiness;
    u16 max_hp;
    u16 held_item;
    u8 poke_name[12];
    u8 trainer_name[8];
    u32 padd2;
    u32 pid;
    union main_status status;
    struct flags2 status2;
    u32 otid;
};

extern struct battle_participant battle_participants[4];

struct graphic{
    void* img;
    u32 size;
};

struct animate_template
{
    u16 tiles_tag;
    u16 pal_tag;
    struct sprite* oam;
    struct frame** animation;
    struct graphic* graphics;
    struct rotscale_frame** rotscale;
    void* callback;
};

struct b_graphics_loc
{
    void* beg_decompressed_sprites; //ptr to the decompressed sprite of the first pokemon
    void* decompressed_sprite[4]; //four pointers to decompressed sprites
    struct animate_template sprite_template[4];
    struct graphic graphics[4][4];
};

struct b_species_info
{
    u16 invisible : 1; //0x1
    u16 flag_x2 : 1; //0x2
    u16 substitute : 1; //0x4
    u16 flag_x8 : 1; //0x8
    u16 HPnumbers : 1; //0x10 not bar but raw numbers
    //rest seems unused ?
    u16 flag_x20 : 1; //0x20
    u16 flag_x40 : 1; //0x40
    u16 flag_x80 : 1; //0x80
    u16 flag_x100 : 1; //0x100
    u16 flag_x200 : 1; //0x200
    u16 flag_x400 : 1; //0x400
    u16 flag_x800 : 1; //0x800
    u16 pal_change : 1; //0x1000
    u16 transformed_species;
};

struct anim_info
{
    u16 arg;
};

struct b_graphics_data
{
    struct b_species_info (* species_info)[4]; //ptr to an array of b_species_info
    void* field4;
    struct anim_info* anims_info;
};

struct battle_graphics_struct
{
    struct b_graphics_data* graphics_data;
    struct b_graphics_loc* graphics_loc;
};

enum poke_sprite
{
    SPRITE_BACK = 0, SPRITE_FRONT = 1
};

struct pokemon
{
    u32 PID;
    u32 OTID;
    char name[10];
    char language;
    char badegg;
    char OT_name[7];
    char markings;            // only the lowest 4 bits are used
    u16 checksum;
    u16 padding_maybe;        //get_attr 6a674
    u16 spieces;
    u16 item;
    u32 exp;
    char pointup;
    //char	PointUp1 : 2;	// @0x42,
    //char	PointUp2 : 2;	// @0x44,
    //char	PointUp3 : 2;	// @0x46,
    char bIntimate : 8;
    u16 unk0;
    u16 moves[4];        // ID of the Skill
    char movePP[4];        // Skill Points
    char evs_hp;
    char evs_atk;
    char evs_def;
    char evs_spd;
    char evs_spatk;
    char evs_spdef;
    char beauty[0x06];        // 帅气 美丽 可爱 聪明 强壮 光滑
    u32 virus : 4;        // @0x00, if any bit is set, ポケルスがかかる
    u32 blackpoint : 4;        // @0x04, if any bit is set, 黑点
    u32 catchplace : 8;
    u32 catchlevel : 7;
    u32 gameversion : 4;    // @0x17, game version (sapphire=1, ruby=2, emerald=3, fire=4, leaf=5)
    u32 ball : 4;        // @0x1B, Poke-Ball type (Write twice, why?)
    u32 unk1 : 1;            // @0x1F, 0
    u32 iv_hp : 5;
    u32 iv_atk : 5;
    u32 iv_def : 5;
    u32 iv_spd : 5;
    u32 iv_spatk : 5;
    u32 iv_spdef : 5;
    u32 isEgg : 1;
    u32 ability : 1;
    u32 ribbon0 : 3;
    u32 ribbon1 : 3;
    u32 ribbon2 : 3;
    u32 ribbon3 : 3;
    u32 ribbon4 : 3;
    u32 ribbon5 : 12;
    u32 unk2 : 4;
    u32 obedience : 1;
    // only for active (in group) pokemons
    char status;        // bit0-2:异常状态,
    char unkonw[3];
    char level;
    char pokerus;        // this is always 'FF'
    u16 current_hp;
    u16 total_hp;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 sp_attack;
    u16 sp_defense;
};

struct palette
{
    u16 c[16];
};

extern struct battle_graphics_struct battle_graphics;
extern u32 PiD_pbs[4];
extern u8 decompression_buffer[];
u16 get_attributes(const struct pokemon* poke_address, u8 request, void* dst);
u8 __attribute__((long_call)) b_link_related(u8 switchID, u8 bank);
void __attribute__((long_call)) load_poke_sprite_deoxys_form(void* sprite_ptr, void* dst, u16 species_no, u32 PiD, enum poke_sprite sprite);
void __attribute__((long_call)) load_poke_sprite(void* sprite_ptr, void* dst, u16 species_no, u32 PiD, enum poke_sprite sprite);
void* __attribute__((long_call)) poke_get_pal(u16 species, u32 TiD, u32 PiD);
void __attribute__((long_call)) gpu_pal_apply(const struct palette* src, u16 index, u16 num_colours);
u8 get_bank_identity(u8 bank);
void __attribute__((long_call)) pal_fade_1(u16 arg1, u16 arg2, u8 arg3, u16 arg4);

struct mirror_move_set_per_bank
{
    u16 moves_per_target[4];
};

struct sprite_poke
{
    void* sprite;
    u16 unkown;
    u16 species;
};

extern const struct sprite_poke (* front_sprites)[];
extern const struct sprite_poke (* back_sprites)[];





struct battle_stuff
{
    u8 end_turn_statetracker1; //0x0
    u8 end_turn_checked_bank; //0x1
    u8 field_2; //0x2
    u8 end_turn_statetracker2; //0x3
    u16 binding_move[4]; //0x4 - 0xB
    u8 move_target[4]; //0xC - 0xF
    u8 expgetter_id; //0x10
    u8 field_11; //0x11
    u8 wildvictorysong; //0x12
    u8 dynamic_move_type; //0x13
    u8 binded_by[4];//0x14-0x17
    u8 field_18[48]; //0x18-0x47
    u8 pre_attacks_bank_counter; //0x48
    u8 field_49; //0x49
    u8 money_multiplier; //0x4A
    u8 field_4B; //0x4B
    u8 switch_in_ability_bank_counter; //0x4C
    u8 field_4D; //0x4D
    u8 field_4E; //0x4E
    u8 field_4F; //0x4F
    u16 exp;    //0x50
    u8 field_52; //0x52
    u8 sentin_pokes; //0x53
    u8 field_54; //0x54
    u8 field_55; //0x55
    u8 field_56; //0x56
    u8 field_57; //0x57
    u8 field_58[4]; //0x58 - 0x5B
    u8 field_5C[17]; //0x5C - 0x6C
    u8 caught_nick[15]; //0x6D - 0x7B
    u8 safari_rate; //0x7C
    u8 field_7D; //0x7D
    u8 field_7E; //0x7E
    u8 castform_switch_form; //0x7F
    u8 chosen_move_position[4]; //0x80
    u8 field_84; //0x84
    u8 field_85; //0x85
    u8 field_86; //0x86
    u8 field_87; //0x87
    u8 field_88; //0x88
    u8 field_89; //0x89
    u8 field_8A; //0x8A
    u8 field_8B; //0x8B
    u8 field_8C; //0x8C
    u8 field_8D; //0x8D
    u8 str_movetype; //0x8E
    u8 expgetter_bank; //0x8F
    u8 field_90; //0x90
    u8 absent_bank_flags_prev_turn; //0x91
    u8 field_92[6]; //0x92-0x97
    u16 mirror_moves_pbs[4]; //0x98-0x9F
    u8 field_A0; //0xA0
    u8 field_A1; //0xA1
    u8 field_A2; //0xA2
    u8 field_A3; //0xA3
    u8 field_A4; //0xA4
    u8 field_A5; //0xA5
    u8 field_A6; //0xA6
    u8 field_A7; //0xA7
    u16 hp_on_switchout[4]; //0xA8 - 0xAF
    u8 field_B0; //0xB0
    u8 curr_hp_bad_scale; //0xB1
    u8 synchronize_effect_chooser; //0xB2
    u8 field_B3[5];
    u16 used_held_items[4]; //0xB8-0xBF
    u8 field_C0[8]; //0xC0-0xC7
    u16 choiced_move[4]; //0xC8-0xCF (checked in cmd49)
    u16 changed_held_items[4]; //0xD0-0xD8 (later written to battlestruct in cmd49)
    u8 intimidate_user; //0xD8
    u8 switch_in_item_bank_counter; //0xD9
    u8 field_DA; //0xDA
    u8 field_DB; //0xDB
    u8 field_DC; //0xDC
    u8 field_DD; //0xDD
    u8 field_DE; //0xDE
    u8 got_exp_from; //0xDF
    struct mirror_move_set_per_bank mirror_move_set_pbs[4]; //0xE0-0xFF
    struct palette castform_pal[4]; //0x100 - 0x179
    u8 field_180[34]; //0x180 - 0x1A1
    u8 battle_load_weather_from_map_flag; //0x1A2
    u8 atk_canceller_state_tracker; //0x1A3
    u8 field_1A4[240]; //0x1A4-0x293
    u8 switchout_index[4]; //0x294-0x297
    u8 field_298[11];
    u8 field_2A3;
};

extern struct battle_stuff* battle_stuff_ptr;


struct in_battle_weather
{
    u32 rain : 1;
    u32 downpour : 1;
    u32 permament_rain : 1;
    u32 sandstorm : 1;
    u32 permament_sandstorm : 1;
    u32 sun : 1;
    u32 permament_sun : 1;
    u32 hail : 1;
    //custom flags
    u32 permament_hail : 1;
    u32 fog : 1;
    u32 permament_fog : 1;
    u32 harsh_sun : 1;
    u32 heavy_rain : 1;
    u32 air_current : 1;
};

#define weather_rain 1
#define weather_downpour 2
#define weather_permament_rain 4
#define weather_sandstorm 8
#define weather_permament_sandstorm 0x10
#define weather_sun 0x20
#define weather_permament_sun 0x40
#define weather_hail 0x80
#define weather_permament_hail 0x100
#define weather_fog 0x200
#define weather_permament_fog 0x400
#define weather_harsh_sun 0x800
#define weather_heavy_rain 0x1000
#define weather_air_current 0x2000

union battle_weather
{
    u32 int_bw;
    struct in_battle_weather flags;
};

extern union battle_weather battle_weather;

#include "../defines/get_attr.h"

#endif //ENGINE7_PC_H
