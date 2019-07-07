#include "../defines/poke_types.h"
#include "../defines/pokes.h"
#include "../defines/abilities.h"
#include "pc.h"

u8* get_box_name(u8 boxid)
{
    if (boxid < 14)
        return sav3->name[boxid];
    else if (boxid < MAX_BOX_COUNT)
    {
        return new_sav3.name[boxid - 14];
    }
    else
        return sav3->name[0];
}

u8* get_box_pal_offset(u8 boxid)
{
    if (boxid < 14)
        return &sav3->bg[boxid];
    else if (boxid < MAX_BOX_COUNT)
        return &new_sav3.bg[boxid - 14];
    else
        return &sav3->bg[0];
}

void set_box_bg(u8 boxid, u8 bgid)
{
    *get_box_pal_offset(boxid) = bgid;
}

u8 get_box_bg(u8 boxid)
{
    return *get_box_pal_offset(boxid);
}

extern u32 sav_index;
extern u16 sav_counterplus1;
#define NEW_SAV3 ((void*)&new_sav3)
#define new_sav ((void*) 0x0203CF64)
#define SAVE_BLOCK_SIZE 14
#define NORMAL_SECTION 1
#define BUFF_SIZE 0xFF4
#define MORE_SECTION ((sizeof(new_sav3) / BUFF_SIZE) + 1)

struct sav_buff_info
{
    u8 section_ID;
    u8 pad0;
    u16 checksum;
    u32 magic_number;
    u32 index;
};

struct sav_buff
{//0x1000
    u8 data[BUFF_SIZE];
    struct sav_buff_info savBuffInfo;
};

extern struct sav_buff* sav_buff_ptr;

struct sav_section
{
    void* ptr;
    u16 size;
    u16 pad;
};

extern struct sav_section sav_sections[15];

extern u16 longcall sav_get_checksum(struct sav_buff* ptr, u32 size);
extern u8 longcall sub_8152908(u32 size, void* ptr);
extern void longcall copy_flash_section(u32 sectionID, void* buffer);

u32 memcpy(void*, void*, u32);

void copy_sav_to_buffer(struct sav_buff* sav_buff_ptr, void* sav, u16 size)
{
    u32* added_bytes = (u32*) 0x02024064;//active_bank
    struct sav_buff_info* savBuffInfo = &sav_buff_ptr->savBuffInfo;
    if (savBuffInfo->section_ID == 0)
        *added_bytes = 0;
    memcpy(sav_buff_ptr, sav, size);
    memcpy(sav_buff_ptr->data + size, new_sav + *added_bytes, BUFF_SIZE - size);
    *added_bytes += sizeof(sav_buff_ptr->data) - size;
    savBuffInfo->checksum = sav_get_checksum(sav_buff_ptr, BUFF_SIZE);
}

void memcpy_newsav3(u8 sectionID, bool swap)
{
    typedef u8 buffer[BUFF_SIZE];
    buffer* new_sav3 = &((buffer*) NEW_SAV3)[sectionID];
    void* src = new_sav3;
    void* dest = sav_buff_ptr;

    if (swap)
    {
        src = sav_buff_ptr;
        dest = new_sav3;
    }

    CpuSet(src, dest, sizeof(buffer) >> 1);
}

#define cpy_from_new3_to_buffer(sectionID) memcpy_newsav3(sectionID, 0)
#define cpy_from_buffer_to_new3(sectionID) memcpy_newsav3(sectionID, 1)

u8 sav_to_flash_section(u8 sectionID, struct sav_section* sav_sections)
{
    struct sav_buff_info* savBuffInfo = &sav_buff_ptr->savBuffInfo;
    savBuffInfo->magic_number = 0x8012025;
    u8 result = 0;
    if (sav_sections)
    {
        savBuffInfo->section_ID = sectionID;
        savBuffInfo->index = NORMAL_SECTION;
        copy_sav_to_buffer(sav_buff_ptr, sav_sections[sectionID].ptr, sav_sections[sectionID].size);
        result = sub_8152908(savBuffInfo->section_ID, sav_buff_ptr);//会先清除存档,复制缓冲数据到存档
    }
    //memcpy(sav_buff_ptr, NEW_SAV3 + BUFF_SIZE * sectionID, BUFF_SIZE);
    cpy_from_new3_to_buffer(sectionID);
    savBuffInfo->section_ID = sectionID;
    savBuffInfo->index = 0;
    sub_8152908(sectionID + 0xE, sav_buff_ptr);//这里必须是0xE,最多10个
    return result;
}

void flash_to_sav()
{
    u32 added_bytes = 0;
    struct sav_buff_info* savBuffInfo = &sav_buff_ptr->savBuffInfo;
    for (u8 savID = 0; savID < 0xE + MORE_SECTION - 1; savID++)//0-14 15-24,不是连续二分，一共32个block 每个0x1000
    {
        copy_flash_section(savID, sav_buff_ptr);
        u16 sectionID = savBuffInfo->section_ID;
        if (savBuffInfo->magic_number != 0x8012025)
            continue;
        if (sectionID < SAVE_BLOCK_SIZE && savBuffInfo->index == NORMAL_SECTION)
        {
            u32 size = sav_sections[sectionID].size;
            memcpy(sav_sections[sectionID].ptr, sav_buff_ptr, size);
            memcpy(new_sav + added_bytes, sav_buff_ptr->data + size, BUFF_SIZE - size);
            added_bytes += BUFF_SIZE - size;
        }
        else if (sectionID < MORE_SECTION && savBuffInfo->index == 0)
        {
            cpy_from_buffer_to_new3(sectionID);
        }
    }
}


void new3_to_flash()
{
    struct sav_buff_info* savBuffInfo = &sav_buff_ptr->savBuffInfo;
    savBuffInfo->magic_number = 0x8012025;
    u8 start = 0xE + MORE_SECTION - 1;
    for (u8 sectionID = 0; sectionID < MORE_SECTION; sectionID++)
    {
        cpy_from_new3_to_buffer(sectionID);
        savBuffInfo->section_ID = sectionID;
        savBuffInfo->index = 0;
        sub_8152908(sectionID + start, sav_buff_ptr);//这里必须是0xE,最多10个
    }
}

bool flash_to_new3()
{
    u8 start = 0xE + MORE_SECTION - 1;
    struct sav_buff_info* savBuffInfo = &sav_buff_ptr->savBuffInfo;
    for (u8 savID = start; savID < start + MORE_SECTION; savID++)
    {
        copy_flash_section(savID, sav_buff_ptr);
        u16 sectionID = savBuffInfo->section_ID;
        if (sectionID < MORE_SECTION && savBuffInfo->index == 0)
        {
            cpy_from_buffer_to_new3(sectionID);
        }
    }
    return 1;
}

void wait_flash_to_new3()
{
    over_world_script.mode = 2;
    over_world_script.waiting_routine = flash_to_new3;
}
/*

static u8 castform_type(u8 bank)
{
    u8 type = battle_participants[bank].type1;
    static u8 castform_type_array[] = {TYPE_NORMAL, TYPE_FIRE, TYPE_WATER, TYPE_ICE};
    u8 i = 0;
    while (i < 4)
        if (castform_type_array[i++] == type)
            break;
    return i;
}

u16 get_transform_species(u8 bank)
{
    return (*battle_graphics.graphics_data->species_info)[bank].transformed_species;
}

static void
b_load_sprite(struct pokemon* poke, u8 bank, const struct sprite_poke (* sprites)[], enum poke_sprite sprite)
{
    u16 species;
    u32 PiD, TiD = get_attributes(poke, ATTR_TID, 0);
    u16 transform_species = get_transform_species(bank);
    void ( * sprite_load)(void* sprite_ptr, void* dst, u16 species_no, u32 PiD, enum poke_sprite sprite);
    if (transform_species)
    {
        species = transform_species;
        PiD = PiD_pbs[bank];
        sprite_load = &load_poke_sprite_deoxys_form;
    }
    else
    {
        species = get_attributes(poke, ATTR_SPECIES, 0);
        PiD = get_attributes(poke, ATTR_PID, 0);
        sprite_load = &load_poke_sprite;
    }
    LZ77UnCompWram(poke_get_pal(species, TiD, PiD), decompression_buffer);
    u16 pal_adder = 256 + bank * 16;
    gpu_pal_apply((struct palette*) (decompression_buffer), pal_adder, 0x20);
    gpu_pal_apply((struct palette*) (decompression_buffer), 0x80 + bank * 16, 0x20);
    void* graphics_loc = battle_graphics.graphics_loc->decompressed_sprite[get_bank_identity(bank)];
    if (species == POKE_CASTFORM)
    {
        CpuSet(decompression_buffer, &battle_stuff_ptr->castform_pal, 0x40);
        gpu_pal_apply(&battle_stuff_ptr->castform_pal[castform_type(bank)], pal_adder, 0x20);
        LZ77UnCompWram((*sprites)[species].sprite, decompression_buffer);
        CpuSet(decompression_buffer + 0x800 * castform_type(bank), graphics_loc, 0x400);
        return;
    }
    sprite_load((void*) &(*sprites)[species].sprite, graphics_loc, species, PiD, sprite);
    if (transform_species)
    {
        pal_fade_1(pal_adder, 0x10, 6, 0x7FFF);
        u32 to_add = (pal_adder) * 2;
        CpuSet((void*) (0x02037B14 + to_add), (void*) (0x02037714 + to_add), 0x4000008);
    }
}

bool check_weather()
{
    bool result = 0;
    for (int i = 0; i < 4; ++i)
    {
        u8 ability=battle_participants[i].ability_id;
        result = ability == ABILITY_AIR_LOCK || ability == ABILITY_CLOUD_NINE;
        if(result)
            break;
    }
    return result;
}

void set_type_in_battle(u8 bank, u8 type)
{
    battle_participants[bank].type1 = battle_participants[bank].type2 = type;
}

enum CastformForm
{
    CastformNormal, //0
    CastformFire, //1
    CastformWater, //2
    CastformIce, //3
    CastformNoChange = 0xFF,
};

#define RAIN_WEATHER ((battle_weather.flags.rain || battle_weather.flags.downpour || battle_weather.flags.permament_rain || battle_weather.flags.heavy_rain))
#define SUN_WEATHER ((battle_weather.flags.sun || battle_weather.flags.permament_sun || battle_weather.flags.harsh_sun))
#define SANDSTORM_WEATHER ((battle_weather.flags.sandstorm || battle_weather.flags.permament_sandstorm))
#define HAIL_WEATHER ((battle_weather.flags.hail || battle_weather.flags.permament_hail))

static enum CastformForm castform_change(u8 bank)
{
    if (battle_participants[bank].species == POKE_CASTFORM)
    {
        u8 type = battle_participants[bank].type1;
        bool weather = check_weather();
        if (type != CastformNormal && (!weather || (!RAIN_WEATHER && !SUN_WEATHER && !HAIL_WEATHER)))
        {
            set_type_in_battle(bank, TYPE_NORMAL);
            return CastformNormal;
        }
        if (weather)
        {
            if (type != TYPE_FIRE && SUN_WEATHER)
            {
                set_type_in_battle(bank, TYPE_FIRE);
                return CastformFire;
            }
            if (type != TYPE_WATER && RAIN_WEATHER)
            {
                set_type_in_battle(bank, TYPE_WATER);
                return CastformWater;
            }
            if (type != TYPE_ICE && HAIL_WEATHER)
            {
                set_type_in_battle(bank, TYPE_ICE);
                return CastformIce;
            }
        }
    }
    return CastformNoChange;
}
*/

