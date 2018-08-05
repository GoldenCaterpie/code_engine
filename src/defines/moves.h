#ifndef MOVE_IDS_H
#define MOVE_IDS_H

#define move_target_selected 0
#define move_target_depends 1
#define move_target_random 4
#define move_target_both 8
#define move_target_user 0x10
#define move_target_foes_and_ally 0x20
#define move_target_opponent_field 0x40

#define MOVE_CONFUSION_DMG ((sizeof(move_table) / sizeof(struct move_info)))

enum MOVE_ID{
    MOVE_POUND = 1,//1
    MOVE_KARATE_CHOP,//2
    MOVE_DOUBLE_SLAP,//3
    MOVE_COMET_PUNCH,//4
    MOVE_MEGA_PUNCH,//5
    MOVE_PAY_DAY,//6
    MOVE_FIRE_PUNCH,//7
    MOVE_ICE_PUNCH,//8
    MOVE_THUNDER_PUNCH,//9
    MOVE_SCRATCH,//10
    MOVE_VICE_GRIP,//11
    MOVE_GUILLOTINE,//12
    MOVE_RAZOR_WIND,//13
    MOVE_SWORDS_DANCE,//14
    MOVE_CUT,//15
    MOVE_GUST,//16
    MOVE_WING_ATTACK,//17
    MOVE_WHIRLWIND,//18
    MOVE_FLY,//19
    MOVE_BIND,//20
    MOVE_SLAM,//21
    MOVE_VINE_WHIP,//22
    MOVE_STOMP,//23
    MOVE_DOUBLE_KICK,//24
    MOVE_MEGA_KICK,//25
    MOVE_JUMP_KICK,//26
    MOVE_ROLLING_KICK,//27
    MOVE_SAND_ATTACK,//28
    MOVE_HEADBUTT,//29
    MOVE_HORN_ATTACK,//30
    MOVE_FURY_ATTACK,//31
    MOVE_HORN_DRILL,//32
    MOVE_TACKLE,//33
    MOVE_BODY_SLAM,//34
    MOVE_WRAP,//35
    MOVE_TAKE_DOWN,//36
    MOVE_THRASH,//37
    MOVE_DOUBLEEDGE,//38
    MOVE_TAIL_WHIP,//39
    MOVE_POISON_STING,//40
    MOVE_TWINEEDLE,//41
    MOVE_PIN_MISSILE,//42
    MOVE_LEER,//43
    MOVE_BITE,//44
    MOVE_GROWL,//45
    MOVE_ROAR,//46
    MOVE_SING,//47
    MOVE_SUPERSONIC,//48
    MOVE_SONIC_BOOM,//49
    MOVE_DISABLE,//50
    MOVE_ACID,//51
    MOVE_EMBER,//52
    MOVE_FLAMETHROWER,//53
    MOVE_MIST,//54
    MOVE_WATER_GUN,//55
    MOVE_HYDRO_PUMP,//56
    MOVE_SURF,//57
    MOVE_ICE_BEAM,//58
    MOVE_BLIZZARD,//59
    MOVE_PSYBEAM,//60
    MOVE_BUBBLE_BEAM,//61
    MOVE_AURORA_BEAM,//62
    MOVE_HYPER_BEAM,//63
    MOVE_PECK,//64
    MOVE_DRILL_PECK,//65
    MOVE_SUBMISSION,//66
    MOVE_LOW_KICK,//67
    MOVE_COUNTER,//68
    MOVE_SEISMIC_TOSS,//69
    MOVE_STRENGTH,//70
    MOVE_ABSORB,//71
    MOVE_MEGA_DRAIN,//72
    MOVE_LEECH_SEED,//73
    MOVE_GROWTH,//74
    MOVE_RAZOR_LEAF,//75
    MOVE_SOLAR_BEAM,//76
    MOVE_POISON_POWDER,//77
    MOVE_STUN_SPORE,//78
    MOVE_SLEEP_POWDER,//79
    MOVE_PETAL_DANCE,//80
    MOVE_STRING_SHOT,//81
    MOVE_DRAGON_RAGE,//82
    MOVE_FIRE_SPIN,//83
    MOVE_THUNDER_SHOCK,//84
    MOVE_THUNDERBOLT,//85
    MOVE_THUNDER_WAVE,//86
    MOVE_THUNDER,//87
    MOVE_ROCK_THROW,//88
    MOVE_EARTHQUAKE,//89
    MOVE_FISSURE,//90
    MOVE_DIG,//91
    MOVE_TOXIC,//92
    MOVE_CONFUSION,//93
    MOVE_PSYCHIC,//94
    MOVE_HYPNOSIS,//95
    MOVE_MEDITATE,//96
    MOVE_AGILITY,//97
    MOVE_QUICK_ATTACK,//98
    MOVE_RAGE,//99
    MOVE_TELEPORT,//100
    MOVE_NIGHT_SHADE,//101
    MOVE_MIMIC,//102
    MOVE_SCREECH,//103
    MOVE_DOUBLE_TEAM,//104
    MOVE_RECOVER,//105
    MOVE_HARDEN,//106
    MOVE_MINIMIZE,//107
    MOVE_SMOKESCREEN,//108
    MOVE_CONFUSE_RAY,//109
    MOVE_WITHDRAW,//110
    MOVE_DEFENSE_CURL,//111
    MOVE_BARRIER,//112
    MOVE_LIGHT_SCREEN,//113
    MOVE_HAZE,//114
    MOVE_REFLECT,//115
    MOVE_FOCUS_ENERGY,//116
    MOVE_BIDE,//117
    MOVE_METRONOME,//118
    MOVE_MIRROR_MOVE,//119
    MOVE_SELFDESTRUCT,//120
    MOVE_EGG_BOMB,//121
    MOVE_LICK,//122
    MOVE_SMOG,//123
    MOVE_SLUDGE,//124
    MOVE_BONE_CLUB,//125
    MOVE_FIRE_BLAST,//126
    MOVE_WATERFALL,//127
    MOVE_CLAMP,//128
    MOVE_SWIFT,//129
    MOVE_SKULL_BASH,//130
    MOVE_SPIKE_CANNON,//131
    MOVE_CONSTRICT,//132
    MOVE_AMNESIA,//133
    MOVE_KINESIS,//134
    MOVE_SOFTBOILED,//135
    MOVE_HIGH_JUMP_KICK,//136
    MOVE_GLARE,//137
    MOVE_DREAM_EATER,//138
    MOVE_POISON_GAS,//139
    MOVE_BARRAGE,//140
    MOVE_LEECH_LIFE,//141
    MOVE_LOVELY_KISS,//142
    MOVE_SKY_ATTACK,//143
    MOVE_TRANSFORM,//144
    MOVE_BUBBLE,//145
    MOVE_DIZZY_PUNCH,//146
    MOVE_SPORE,//147
    MOVE_FLASH,//148
    MOVE_PSYWAVE,//149
    MOVE_SPLASH,//150
    MOVE_ACID_ARMOR,//151
    MOVE_CRABHAMMER,//152
    MOVE_EXPLOSION,//153
    MOVE_FURY_SWIPES,//154
    MOVE_BONEMERANG,//155
    MOVE_REST,//156
    MOVE_ROCK_SLIDE,//157
    MOVE_HYPER_FANG,//158
    MOVE_SHARPEN,//159
    MOVE_CONVERSION,//160
    MOVE_TRI_ATTACK,//161
    MOVE_SUPER_FANG,//162
    MOVE_SLASH,//163
    MOVE_SUBSTITUTE,//164
    MOVE_STRUGGLE,//165
    MOVE_SKETCH,//166
    MOVE_TRIPLE_KICK,//167
    MOVE_THIEF,//168
    MOVE_SPIDER_WEB,//169
    MOVE_MIND_READER,//170
    MOVE_NIGHTMARE,//171
    MOVE_FLAME_WHEEL,//172
    MOVE_SNORE,//173
    MOVE_CURSE,//174
    MOVE_FLAIL,//175
    MOVE_CONVERSION_2,//176
    MOVE_AEROBLAST,//177
    MOVE_COTTON_SPORE,//178
    MOVE_REVERSAL,//179
    MOVE_SPITE,//180
    MOVE_POWDER_SNOW,//181
    MOVE_PROTECT,//182
    MOVE_MACH_PUNCH,//183
    MOVE_SCARY_FACE,//184
    MOVE_FEINT_ATTACK,//185
    MOVE_SWEET_KISS,//186
    MOVE_BELLY_DRUM,//187
    MOVE_SLUDGE_BOMB,//188
    MOVE_MUDSLAP,//189
    MOVE_OCTAZOOKA,//190
    MOVE_SPIKES,//191
    MOVE_ZAP_CANNON,//192
    MOVE_FORESIGHT,//193
    MOVE_DESTINY_BOND,//194
    MOVE_PERISH_SONG,//195
    MOVE_ICY_WIND,//196
    MOVE_DETECT,//197
    MOVE_BONE_RUSH,//198
    MOVE_LOCKON,//199
    MOVE_OUTRAGE,//200
    MOVE_SANDSTORM,//201
    MOVE_GIGA_DRAIN,//202
    MOVE_ENDURE,//203
    MOVE_CHARM,//204
    MOVE_ROLLOUT,//205
    MOVE_FALSE_SWIPE,//206
    MOVE_SWAGGER,//207
    MOVE_MILK_DRINK,//208
    MOVE_SPARK,//209
    MOVE_FURY_CUTTER,//210
    MOVE_STEEL_WING,//211
    MOVE_MEAN_LOOK,//212
    MOVE_ATTRACT,//213
    MOVE_SLEEP_TALK,//214
    MOVE_HEAL_BELL,//215
    MOVE_RETURN,//216
    MOVE_PRESENT,//217
    MOVE_FRUSTRATION,//218
    MOVE_SAFEGUARD,//219
    MOVE_PAIN_SPLIT,//220
    MOVE_SACRED_FIRE,//221
    MOVE_MAGNITUDE,//222
    MOVE_DYNAMIC_PUNCH,//223
    MOVE_MEGAHORN,//224
    MOVE_DRAGON_BREATH,//225
    MOVE_BATON_PASS,//226
    MOVE_ENCORE,//227
    MOVE_PURSUIT,//228
    MOVE_RAPID_SPIN,//229
    MOVE_SWEET_SCENT,//230
    MOVE_IRON_TAIL,//231
    MOVE_METAL_CLAW,//232
    MOVE_VITAL_THROW,//233
    MOVE_MORNING_SUN,//234
    MOVE_SYNTHESIS,//235
    MOVE_MOONLIGHT,//236
    MOVE_HIDDEN_POWER,//237
    MOVE_CROSS_CHOP,//238
    MOVE_TWISTER,//239
    MOVE_RAIN_DANCE,//240
    MOVE_SUNNY_DAY,//241
    MOVE_CRUNCH,//242
    MOVE_MIRROR_COAT,//243
    MOVE_PSYCH_UP,//244
    MOVE_EXTREME_SPEED,//245
    MOVE_ANCIENT_POWER,//246
    MOVE_SHADOW_BALL,//247
    MOVE_FUTURE_SIGHT,//248
    MOVE_ROCK_SMASH,//249
    MOVE_WHIRLPOOL,//250
    MOVE_BEAT_UP,//251
    MOVE_FAKE_OUT,//252
    MOVE_UPROAR,//253
    MOVE_STOCKPILE,//254
    MOVE_SPIT_UP,//255
    MOVE_SWALLOW,//256
    MOVE_HEAT_WAVE,//257
    MOVE_HAIL,//258
    MOVE_TORMENT,//259
    MOVE_FLATTER,//260
    MOVE_WILLOWISP,//261
    MOVE_MEMENTO,//262
    MOVE_FACADE,//263
    MOVE_FOCUS_PUNCH,//264
    MOVE_SMELLING_SALTS,//265
    MOVE_FOLLOW_ME,//266
    MOVE_NATURE_POWER,//267
    MOVE_CHARGE,//268
    MOVE_TAUNT,//269
    MOVE_HELPING_HAND,//270
    MOVE_TRICK,//271
    MOVE_ROLE_PLAY,//272
    MOVE_WISH,//273
    MOVE_ASSIST,//274
    MOVE_INGRAIN,//275
    MOVE_SUPERPOWER,//276
    MOVE_MAGIC_COAT,//277
    MOVE_RECYCLE,//278
    MOVE_REVENGE,//279
    MOVE_BRICK_BREAK,//280
    MOVE_YAWN,//281
    MOVE_KNOCK_OFF,//282
    MOVE_ENDEAVOR,//283
    MOVE_ERUPTION,//284
    MOVE_SKILL_SWAP,//285
    MOVE_IMPRISON,//286
    MOVE_REFRESH,//287
    MOVE_GRUDGE,//288
    MOVE_SNATCH,//289
    MOVE_SECRET_POWER,//290
    MOVE_DIVE,//291
    MOVE_ARM_THRUST,//292
    MOVE_CAMOUFLAGE,//293
    MOVE_TAIL_GLOW,//294
    MOVE_LUSTER_PURGE,//295
    MOVE_MIST_BALL,//296
    MOVE_FEATHER_DANCE,//297
    MOVE_TEETER_DANCE,//298
    MOVE_BLAZE_KICK,//299
    MOVE_MUD_SPORT,//300
    MOVE_ICE_BALL,//301
    MOVE_NEEDLE_ARM,//302
    MOVE_SLACK_OFF,//303
    MOVE_HYPER_VOICE,//304
    MOVE_POISON_FANG,//305
    MOVE_CRUSH_CLAW,//306
    MOVE_BLAST_BURN,//307
    MOVE_HYDRO_CANNON,//308
    MOVE_METEOR_MASH,//309
    MOVE_ASTONISH,//310
    MOVE_WEATHER_BALL,//311
    MOVE_AROMATHERAPY,//312
    MOVE_FAKE_TEARS,//313
    MOVE_AIR_CUTTER,//314
    MOVE_OVERHEAT,//315
    MOVE_ODOR_SLEUTH,//316
    MOVE_ROCK_TOMB,//317
    MOVE_SILVER_WIND,//318
    MOVE_METAL_SOUND,//319
    MOVE_GRASS_WHISTLE,//320
    MOVE_TICKLE,//321
    MOVE_COSMIC_POWER,//322
    MOVE_WATER_SPOUT,//323
    MOVE_SIGNAL_BEAM,//324
    MOVE_SHADOW_PUNCH,//325
    MOVE_EXTRASENSORY,//326
    MOVE_SKY_UPPERCUT,//327
    MOVE_SAND_TOMB,//328
    MOVE_SHEER_COLD,//329
    MOVE_MUDDY_WATER,//330
    MOVE_BULLET_SEED,//331
    MOVE_AERIAL_ACE,//332
    MOVE_ICICLE_SPEAR,//333
    MOVE_IRON_DEFENSE,//334
    MOVE_BLOCK,//335
    MOVE_HOWL,//336
    MOVE_DRAGON_CLAW,//337
    MOVE_FRENZY_PLANT,//338
    MOVE_BULK_UP,//339
    MOVE_BOUNCE,//340
    MOVE_MUD_SHOT,//341
    MOVE_POISON_TAIL,//342
    MOVE_COVET,//343
    MOVE_VOLT_TACKLE,//344
    MOVE_MAGICAL_LEAF,//345
    MOVE_WATER_SPORT,//346
    MOVE_CALM_MIND,//347
    MOVE_LEAF_BLADE,//348
    MOVE_DRAGON_DANCE,//349
    MOVE_ROCK_BLAST,//350
    MOVE_SHOCK_WAVE,//351
    MOVE_WATER_PULSE,//352
    MOVE_DOOM_DESIRE,//353
    MOVE_PSYCHO_BOOST,//354
    MOVE_ROOST,//355
    MOVE_GRAVITY,//356
    MOVE_MIRACLE_EYE,//357
    MOVE_WAKEUP_SLAP,//358
    MOVE_HAMMER_ARM,//359
    MOVE_GYRO_BALL,//360
    MOVE_HEALING_WISH,//361
    MOVE_BRINE,//362
    MOVE_NATURAL_GIFT,//363
    MOVE_FEINT,//364
    MOVE_PLUCK,//365
    MOVE_TAILWIND,//366
    MOVE_ACUPRESSURE,//367
    MOVE_METAL_BURST,//368
    MOVE_UTURN,//369
    MOVE_CLOSE_COMBAT,//370
    MOVE_PAYBACK,//371
    MOVE_ASSURANCE,//372
    MOVE_EMBARGO,//373
    MOVE_FLING,//374
    MOVE_PSYCHO_SHIFT,//375
    MOVE_TRUMP_CARD,//376
    MOVE_HEAL_BLOCK,//377
    MOVE_WRING_OUT,//378
    MOVE_POWER_TRICK,//379
    MOVE_GASTRO_ACID,//380
    MOVE_LUCKY_CHANT,//381
    MOVE_ME_FIRST,//382
    MOVE_COPYCAT,//383
    MOVE_POWER_SWAP,//384
    MOVE_GUARD_SWAP,//385
    MOVE_PUNISHMENT,//386
    MOVE_LAST_RESORT,//387
    MOVE_WORRY_SEED,//388
    MOVE_SUCKER_PUNCH,//389
    MOVE_TOXIC_SPIKES,//390
    MOVE_HEART_SWAP,//391
    MOVE_AQUA_RING,//392
    MOVE_MAGNET_RISE,//393
    MOVE_FLARE_BLITZ,//394
    MOVE_FORCE_PALM,//395
    MOVE_AURA_SPHERE,//396
    MOVE_ROCK_POLISH,//397
    MOVE_POISON_JAB,//398
    MOVE_DARK_PULSE,//399
    MOVE_NIGHT_SLASH,//400
    MOVE_AQUA_TAIL,//401
    MOVE_SEED_BOMB,//402
    MOVE_AIR_SLASH,//403
    MOVE_XSCISSOR,//404
    MOVE_BUG_BUZZ,//405
    MOVE_DRAGON_PULSE,//406
    MOVE_DRAGON_RUSH,//407
    MOVE_POWER_GEM,//408
    MOVE_DRAIN_PUNCH,//409
    MOVE_VACUUM_WAVE,//410
    MOVE_FOCUS_BLAST,//411
    MOVE_ENERGY_BALL,//412
    MOVE_BRAVE_BIRD,//413
    MOVE_EARTH_POWER,//414
    MOVE_SWITCHEROO,//415
    MOVE_GIGA_IMPACT,//416
    MOVE_NASTY_PLOT,//417
    MOVE_BULLET_PUNCH,//418
    MOVE_AVALANCHE,//419
    MOVE_ICE_SHARD,//420
    MOVE_SHADOW_CLAW,//421
    MOVE_THUNDER_FANG,//422
    MOVE_ICE_FANG,//423
    MOVE_FIRE_FANG,//424
    MOVE_SHADOW_SNEAK,//425
    MOVE_MUD_BOMB,//426
    MOVE_PSYCHO_CUT,//427
    MOVE_ZEN_HEADBUTT,//428
    MOVE_MIRROR_SHOT,//429
    MOVE_FLASH_CANNON,//430
    MOVE_ROCK_CLIMB,//431
    MOVE_DEFOG,//432
    MOVE_TRICK_ROOM,//433
    MOVE_DRACO_METEOR,//434
    MOVE_DISCHARGE,//435
    MOVE_LAVA_PLUME,//436
    MOVE_LEAF_STORM,//437
    MOVE_POWER_WHIP,//438
    MOVE_ROCK_WRECKER,//439
    MOVE_CROSS_POISON,//440
    MOVE_GUNK_SHOT,//441
    MOVE_IRON_HEAD,//442
    MOVE_MAGNET_BOMB,//443
    MOVE_STONE_EDGE,//444
    MOVE_CAPTIVATE,//445
    MOVE_STEALTH_ROCK,//446
    MOVE_GRASS_KNOT,//447
    MOVE_CHATTER,//448
    MOVE_JUDGMENT,//449
    MOVE_BUG_BITE,//450
    MOVE_CHARGE_BEAM,//451
    MOVE_WOOD_HAMMER,//452
    MOVE_AQUA_JET,//453
    MOVE_ATTACK_ORDER,//454
    MOVE_DEFEND_ORDER,//455
    MOVE_HEAL_ORDER,//456
    MOVE_HEAD_SMASH,//457
    MOVE_DOUBLE_HIT,//458
    MOVE_ROAR_OF_TIME,//459
    MOVE_SPACIAL_REND,//460
    MOVE_LUNAR_DANCE,//461
    MOVE_CRUSH_GRIP,//462
    MOVE_MAGMA_STORM,//463
    MOVE_DARK_VOID,//464
    MOVE_SEED_FLARE,//465
    MOVE_OMINOUS_WIND,//466
    MOVE_SHADOW_FORCE,//467
    MOVE_HONE_CLAWS,//468
    MOVE_WIDE_GUARD,//469
    MOVE_GUARD_SPLIT,//470
    MOVE_POWER_SPLIT,//471
    MOVE_WONDER_ROOM,//472
    MOVE_PSYSHOCK,//473
    MOVE_VENOSHOCK,//474
    MOVE_AUTOTOMIZE,//475
    MOVE_RAGE_POWDER,//476
    MOVE_TELEKINESIS,//477
    MOVE_MAGIC_ROOM,//478
    MOVE_SMACK_DOWN,//479
    MOVE_STORM_THROW,//480
    MOVE_FLAME_BURST,//481
    MOVE_SLUDGE_WAVE,//482
    MOVE_QUIVER_DANCE,//483
    MOVE_HEAVY_SLAM,//484
    MOVE_SYNCHRONOISE,//485
    MOVE_ELECTRO_BALL,//486
    MOVE_SOAK,//487
    MOVE_FLAME_CHARGE,//488
    MOVE_COIL,//489
    MOVE_LOW_SWEEP,//490
    MOVE_ACID_SPRAY,//491
    MOVE_FOUL_PLAY,//492
    MOVE_SIMPLE_BEAM,//493
    MOVE_ENTRAINMENT,//494
    MOVE_AFTER_YOU,//495
    MOVE_ROUND,//496
    MOVE_ECHOED_VOICE,//497
    MOVE_CHIP_AWAY,//498
    MOVE_CLEAR_SMOG,//499
    MOVE_STORED_POWER,//500
    MOVE_QUICK_GUARD,//501
    MOVE_ALLY_SWITCH,//502
    MOVE_SCALD,//503
    MOVE_SHELL_SMASH,//504
    MOVE_HEAL_PULSE,//505
    MOVE_HEX,//506
    MOVE_SKY_DROP,//507
    MOVE_SHIFT_GEAR,//508
    MOVE_CIRCLE_THROW,//509
    MOVE_INCINERATE,//510
    MOVE_QUASH,//511
    MOVE_ACROBATICS,//512
    MOVE_REFLECT_TYPE,//513
    MOVE_RETALIATE,//514
    MOVE_FINAL_GAMBIT,//515
    MOVE_BESTOW,//516
    MOVE_INFERNO,//517
    MOVE_WATER_PLEDGE,//518
    MOVE_FIRE_PLEDGE,//519
    MOVE_GRASS_PLEDGE,//520
    MOVE_VOLT_SWITCH,//521
    MOVE_STRUGGLE_BUG,//522
    MOVE_BULLDOZE,//523
    MOVE_FROST_BREATH,//524
    MOVE_DRAGON_TAIL,//525
    MOVE_WORK_UP,//526
    MOVE_ELECTROWEB,//527
    MOVE_WILD_CHARGE,//528
    MOVE_DRILL_RUN,//529
    MOVE_DUAL_CHOP,//530
    MOVE_HEART_STAMP,//531
    MOVE_HORN_LEECH,//532
    MOVE_SACRED_SWORD,//533
    MOVE_RAZOR_SHELL,//534
    MOVE_HEAT_CRASH,//535
    MOVE_LEAF_TORNADO,//536
    MOVE_STEAMROLLER,//537
    MOVE_COTTON_GUARD,//538
    MOVE_NIGHT_DAZE,//539
    MOVE_PSYSTRIKE,//540
    MOVE_TAIL_SLAP,//541
    MOVE_HURRICANE,//542
    MOVE_HEAD_CHARGE,//543
    MOVE_GEAR_GRIND,//544
    MOVE_SEARING_SHOT,//545
    MOVE_TECHNO_BLAST,//546
    MOVE_RELIC_SONG,//547
    MOVE_SECRET_SWORD,//548
    MOVE_GLACIATE,//549
    MOVE_BOLT_STRIKE,//550
    MOVE_BLUE_FLARE,//551
    MOVE_FIERY_DANCE,//552
    MOVE_FREEZE_SHOCK,//553
    MOVE_ICE_BURN,//554
    MOVE_SNARL,//555
    MOVE_ICICLE_CRASH,//556
    MOVE_VCREATE,//557
    MOVE_FUSION_FLARE,//558
    MOVE_FUSION_BOLT,//559
    MOVE_FLYING_PRESS,//560
    MOVE_MAT_BLOCK,//561
    MOVE_BELCH,//562
    MOVE_ROTOTILLER,//563
    MOVE_STICKY_WEB,//564
    MOVE_FELL_STINGER,//565
    MOVE_PHANTOM_FORCE,//566
    MOVE_TRICKORTREAT,//567
    MOVE_NOBLE_ROAR,//568
    MOVE_ION_DELUGE,//569
    MOVE_PARABOLIC_CHARGE,//570
    MOVE_FORESTS_CURSE,//571
    MOVE_PETAL_BLIZZARD,//572
    MOVE_FREEZEDRY,//573
    MOVE_DISARMING_VOICE,//574
    MOVE_PARTING_SHOT,//575
    MOVE_TOPSYTURVY,//576
    MOVE_DRAINING_KISS,//577
    MOVE_CRAFTY_SHIELD,//578
    MOVE_FLOWER_SHIELD,//579
    MOVE_GRASSY_TERRAIN,//580
    MOVE_MISTY_TERRAIN,//581
    MOVE_ELECTRIFY,//582
    MOVE_PLAY_ROUGH,//583
    MOVE_FAIRY_WIND,//584
    MOVE_MOONBLAST,//585
    MOVE_BOOMBURST,//586
    MOVE_FAIRY_LOCK,//587
    MOVE_KINGS_SHIELD,//588
    MOVE_PLAY_NICE,//589
    MOVE_CONFIDE,//590
    MOVE_DIAMOND_STORM,//591
    MOVE_STEAM_ERUPTION,//592
    MOVE_HYPERSPACE_HOLE,//593
    MOVE_WATER_SHURIKEN,//594
    MOVE_MYSTICAL_FIRE,//595
    MOVE_SPIKY_SHIELD,//596
    MOVE_AROMATIC_MIST,//597
    MOVE_EERIE_IMPULSE,//598
    MOVE_VENOM_DRENCH,//599
    MOVE_POWDER,//600
    MOVE_GEOMANCY,//601
    MOVE_MAGNETIC_FLUX,//602
    MOVE_HAPPY_HOUR,//603
    MOVE_ELECTRIC_TERRAIN,//604
    MOVE_DAZZLING_GLEAM,//605
    MOVE_CELEBRATE,//606
    MOVE_BABYDOLL_EYES,//608
    MOVE_NUZZLE,//609
    MOVE_HOLD_BACK,//610
    MOVE_INFESTATION,//611
    MOVE_POWERUP_PUNCH,//612
    MOVE_OBLIVION_WING,//613
    MOVE_THOUSAND_ARROWS,//614
    MOVE_HOLD_HANDS,//615
    MOVE_THOUSAND_WAVES,//615
    MOVE_LANDS_WRATH,//616
    MOVE_LIGHT_OF_RUIN,//617
    MOVE_ORIGIN_PULSE,//618
    MOVE_PRECIPICE_BLADES,//619
    MOVE_DRAGON_ASCENT,//620
    MOVE_HYPERSPACE_FURY,//621
    MOVE_Z_NORMAL_PHYS,//622
    MOVE_Z_NORMAL_SPEC,//623
    MOVE_Z_FIGHTING_PHYS,//624
    MOVE_Z_FIGHTING_SPEC,//625
    MOVE_Z_FLYING_PHYS,//626
    MOVE_Z_FLYING_SPEC,//627
    MOVE_Z_POISON_PHYS,//628
    MOVE_Z_POISON_SPEC,//629
    MOVE_Z_GROUND_PHYS,//630
    MOVE_Z_GROUND_SPEC,//631
    MOVE_Z_ROCK_PHYS,//632
    MOVE_Z_ROCK_SPEC,//633
    MOVE_Z_BUG_PHYS,//634
    MOVE_Z_BUG_SPEC,//635
    MOVE_Z_GHOST_PHYS,//636
    MOVE_Z_GHOST_SPEC,//637
    MOVE_Z_STEEL_PHYS,//638
    MOVE_Z_STELL_SPEC,//639
    MOVE_Z_FIRE_PHYS,//640
    MOVE_Z_FIRE_SPEC,//641
    MOVE_Z_WATER_PHYS,//642
    MOVE_Z_WATER_SPEC,//643
    MOVE_Z_GRASS_PHYS,//644
    MOVE_Z_GRASS_SPEC,//645
    MOVE_Z_ELECTRIC_PHYS,//646
    MOVE_Z_ELECTRIC_SPEC,//647
    MOVE_Z_PSYCHIC_PHYS,//648
    MOVE_Z_PSYCHIC_SPEC,//649
    MOVE_Z_ICE_PHYS,//650
    MOVE_Z_ICE_SPEC,//651
    MOVE_Z_DRAGON_PHYS,//652
    MOVE_Z_DRAGON_SPEC,//653
    MOVE_Z_DARK_PHYS,//654
    MOVE_Z_DARK_SPEC,//655
    MOVE_Z_FAIRY_PHYS,//656
    MOVE_Z_FAIRY_SPEC,//657
    MOVE_Z_CATASTROPIKA,//658
    MOVE_SHORE_UP,//659
    MOVE_FIRST_IMPRESSION,//660
    MOVE_BANEFUL_BUNKER,//661
    MOVE_SPIRIT_SHACKLE,//662
    MOVE_DARKEST_LARIAT,//663
    MOVE_SPARKLING_ARIA,//664
    MOVE_ICE_HAMMER,//665
    MOVE_FLORAL_HEALING,//666
    MOVE_HIGH_HORSEPOWER,//667
    MOVE_STRENGTH_SAP,//668
    MOVE_SOLAR_BLADE,//669
    MOVE_LEAFAGE,//670
    MOVE_SPOTLIGHT,//671
    MOVE_TOXIC_THREAD,//672
    MOVE_LASER_FOCUS,//673
    MOVE_GEAR_UP,//674
    MOVE_THROAT_CHOP,//675
    MOVE_POLLEN_PUFF,//676
    MOVE_ANCHOR_SHOT,//677
    MOVE_PSYCHIC_TERRAIN,//678
    MOVE_LUNGE,//679
    MOVE_FIRE_LASH,//680
    MOVE_POWER_TRIP,//681
    MOVE_BURN_UP,//682
    MOVE_SPEED_SWAP,//683
    MOVE_SMART_STRIKE,//684
    MOVE_PURIFY,//685
    MOVE_REVELATION_DANCE,//686
    MOVE_CORE_ENFORCER,//687
    MOVE_TROP_KICK,//688
    MOVE_INSTRUCT,//689
    MOVE_BEAK_BLAST,//690
    MOVE_CLANGING_SCALES,//691
    MOVE_DRAGON_HAMMER,//692
    MOVE_BRUTAL_SWING,//693
    MOVE_AURORA_VEIL,//694
    MOVE_Z_DECIDUEYE,//695
    MOVE_Z_INCINEROAR,//696
    MOVE_Z_PRIMARINA,//697
    MOVE_Z_TAPU,//698
    MOVE_Z_MARSHADOW,//699
    MOVE_Z_ALOLAN_RAICHU,//700
    MOVE_Z_SNORLAX,//701
    MOVE_Z_EEVEE,//702
    MOVE_Z_MEW,//703
    MOVE_SHELL_TRAP,//704
    MOVE_FLEUR_CANNON,//705
    MOVE_PSYCHIC_FANGS,//706
    MOVE_STOMPING_TANTRUM,//707
    MOVE_SHADOW_BONE,//708
    MOVE_ACCELEROCK,//709
    MOVE_LIQUIDATION,//710
    MOVE_PRISMATIC_LASER,//711
    MOVE_SPECTRAL_THIEF,//712
    MOVE_SUNSTEEL_STRIKE,//713
    MOVE_MOONGEIST_BEAM,//714
    MOVE_TEARFUL_LOOK,//715
    MOVE_ZING_ZAP,//716
    MOVE_NATURES_MADNESS,//717
    MOVE_MULTI_ATTACK,//718
    MOVE_Z_ASH_PIKACHU,//719
    MOVE_MIND_BLOWN,//720
    MOVE_PLASMA_FISTS,//721
    MOVE_PHOTON_GEYSER,//722
    MOVE_Z_KOMMO_O,//723
    MOVE_Z_LYCANROC,//724
    MOVE_Z_MIMIKYU,//725
    MOVE_Z_SOLGALEO,//726
    MOVE_Z_LUNALA,//727
    MOVE_Z_NECROZMA,//728
    MOVE_Z_ASH_GRENINJA,//729
};

#endif /* MOVE_IDS_H */
