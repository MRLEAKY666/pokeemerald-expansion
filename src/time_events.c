#include "global.h"
#include "time_events.h"
#include "event_data.h"
#include "field_weather.h"
#include "pokemon.h"
#include "random.h"
#include "overworld.h"
#include "rtc.h"
#include "script.h"
#include "task.h"

#include "battle_setup.h"

static u32 GetMirageRnd(void)
{
    u32 hi = VarGet(VAR_MIRAGE_RND_H);
    u32 lo = VarGet(VAR_MIRAGE_RND_L);
    return (hi << 16) | lo;
}

static void SetMirageRnd(u32 rnd)
{
    VarSet(VAR_MIRAGE_RND_H, rnd >> 16);
    VarSet(VAR_MIRAGE_RND_L, rnd);
}

// unused
void InitMirageRnd(void)
{
    SetMirageRnd(Random32());
}

void UpdateMirageRnd(u16 days)
{
    s32 rnd = GetMirageRnd();
    while (days)
    {
        rnd = ISO_RANDOMIZE2(rnd);
        days--;
    }
    SetMirageRnd(rnd);
}

bool8 IsMirageIslandPresent(void)
{
    u16 rnd = GetMirageRnd() >> 16;
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && (GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY) & 0xFFFF) == rnd)
            return TRUE;

    return FALSE;
}

void UpdateShoalTideFlag(void)
{
    static const u8 tide[] =
    {
        1, // 00
        1, // 01
        1, // 02
        0, // 03
        0, // 04
        0, // 05
        0, // 06
        0, // 07
        0, // 08
        1, // 09
        1, // 10
        1, // 11
        1, // 12
        1, // 13
        1, // 14
        0, // 15
        0, // 16
        0, // 17
        0, // 18
        0, // 19
        0, // 20
        1, // 21
        1, // 22
        1, // 23
    };

    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_GRANITE_COVE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_GRANITE_COVE)))
    {
        RtcCalcLocalTime();
        if (tide[gLocalTime.hours])
            FlagSet(FLAG_SYS_SHOAL_TIDE);
        else
            FlagClear(FLAG_SYS_SHOAL_TIDE);
    }
}

static void Task_WaitWeather(u8 taskId)
{
    if (IsWeatherChangeComplete())
    {
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

void WaitWeather(void)
{
    CreateTask(Task_WaitWeather, 80);
}

void InitBirchState(void)
{
    *GetVarPointer(VAR_BIRCH_STATE) = 0;
}

void UpdateBirchState(u16 days)
{
    u16 *state = GetVarPointer(VAR_BIRCH_STATE);
    *state += days;
    *state %= 7;
}

static const u16 sRespawnableItemFlags[] = {
    FLAG_ITEM_ROUTE_102_POTION,                                  
    FLAG_ITEM_ROUTE_116_X_SPECIAL,                               
    FLAG_ITEM_ROUTE_104_PP_UP,                                   
    FLAG_ITEM_ROUTE_105_IRON,                                    
    FLAG_ITEM_ROUTE_106_PROTEIN,                                 
    FLAG_ITEM_ROUTE_109_PP_UP,                                   
    FLAG_ITEM_ROUTE_110_RARE_CANDY,                              
    FLAG_ITEM_ROUTE_110_DIRE_HIT,                                
    FLAG_ITEM_ROUTE_111_TM_SANDSTORM,                            
    FLAG_ITEM_ROUTE_111_STARDUST,                                
    FLAG_ITEM_ROUTE_111_HP_UP,                                   
    FLAG_ITEM_ROUTE_112_NUGGET,                                  
    FLAG_ITEM_ROUTE_113_MAX_ETHER,                               
    FLAG_ITEM_ROUTE_113_SUPER_REPEL,                             
    FLAG_ITEM_ROUTE_114_RARE_CANDY,                              
    FLAG_ITEM_ROUTE_114_PROTEIN,                                 
    FLAG_ITEM_ROUTE_115_SUPER_POTION,                            
    FLAG_ITEM_ROUTE_115_TM_FOCUS_PUNCH,                          
    FLAG_ITEM_ROUTE_115_IRON,                                    
    FLAG_ITEM_ROUTE_116_ETHER,                                   
    FLAG_ITEM_ROUTE_116_REPEL,                                   
    FLAG_ITEM_ROUTE_116_HP_UP,                                   
    FLAG_ITEM_ROUTE_117_GREAT_BALL,                              
    FLAG_ITEM_ROUTE_117_REVIVE,                                  
    FLAG_ITEM_ROUTE_119_SUPER_REPEL,                             
    FLAG_ITEM_ROUTE_119_ZINC,                                    
    FLAG_ITEM_ROUTE_119_ELIXIR_1,                                
    FLAG_ITEM_ROUTE_119_LEAF_STONE,                              
    FLAG_ITEM_ROUTE_119_RARE_CANDY,                              
    FLAG_ITEM_ROUTE_119_HYPER_POTION_1,                          
    FLAG_ITEM_ROUTE_120_NUGGET,                                  
    FLAG_ITEM_ROUTE_120_FULL_HEAL,                               
    FLAG_ITEM_ROUTE_123_CALCIUM,                                
    FLAG_ITEM_ROUTE_123_RARE_CANDY,                              
    FLAG_ITEM_ROUTE_127_ZINC,                                    
    FLAG_ITEM_ROUTE_127_CARBOS,                                  
    FLAG_ITEM_ROUTE_132_RARE_CANDY,                              
    FLAG_ITEM_ROUTE_133_BIG_PEARL,                               
    FLAG_ITEM_ROUTE_133_STAR_PIECE,                              
    FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE,                         
    FLAG_ITEM_PETALBURG_CITY_ETHER,                              
    FLAG_ITEM_RUSTBORO_CITY_X_DEFEND,                            
    FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL,                           
    FLAG_ITEM_MOSSDEEP_CITY_NET_BALL,                            
    FLAG_ITEM_METEOR_FALLS_1F_1R_TM_IRON_TAIL,                   
    FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL,                      
    FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE,                     
    FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP,                          
    FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL,                          
    FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER,                          
    FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE,                       
    FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL,                        
    FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE,                            
    FLAG_ITEM_GRANITE_CAVE_B2F_REPEL,                            
    FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY,                       
    FLAG_ITEM_PETALBURG_WOODS_X_ATTACK,                          
    FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL,                        
    FLAG_ITEM_ROUTE_104_POKE_BALL,                               
    FLAG_ITEM_PETALBURG_WOODS_ETHER,                             
    FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE,                    
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL,                  
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL,                  
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL,                    
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL,                  
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL,                    
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL,                    
    FLAG_ITEM_ROUTE_124_YELLOW_SHARD,                            
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL,                 
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL,                  
    FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL,                    
    FLAG_ITEM_JAGGED_PASS_BURN_HEAL,                             
    FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR,                       
    FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL,                        
    FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION,                       
    FLAG_ITEM_MT_PYRE_EXTERIOR_TM_SKILL_SWAP,                    
    FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL,                           
    FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE,                          
    FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL,    
    //FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER,        
    FLAG_ITEM_SCORCHED_SLAB_TM_SUNNY_DAY,                        
    FLAG_ITEM_METEOR_FALLS_B1F_2R_TM_DRAGON_CLAW,                
    FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL,                     
    FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY,                  
    FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL,                   
    FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR,                        
    FLAG_ITEM_VICTORY_ROAD_1F_PP_UP,                             
    FLAG_ITEM_VICTORY_ROAD_B1F_TM_PSYCHIC,                       
    FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE,                     
    FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL,                        
    FLAG_ITEM_MT_PYRE_6F_TM_SHADOW_BALL,                         
    FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_EARTHQUAKE,              
    FLAG_ITEM_FIERY_PATH_TM_TOXIC,                               
    FLAG_ITEM_ROUTE_124_RED_SHARD,                               
    FLAG_ITEM_ROUTE_124_BLUE_SHARD,                              
    FLAG_ITEM_SAFARI_ZONE_NORTH_WEST_TM_SOLAR_BEAM,              
    FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL,               
    FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE,              
    FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL,              
    FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_ICE_BEAM,              
    FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE,                  
    //FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY,        
    FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE,    
    FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_RAIN_DANCE,  
    FLAG_ITEM_ROUTE_121_CARBOS,                                  
    FLAG_ITEM_ROUTE_123_ULTRA_BALL,                              
    FLAG_ITEM_ROUTE_126_GREEN_SHARD,                             
    FLAG_ITEM_ROUTE_119_HYPER_POTION_2,                          
    FLAG_ITEM_ROUTE_120_HYPER_POTION,
    FLAG_ITEM_ROUTE_120_NEST_BALL,                               
    FLAG_ITEM_ROUTE_123_ELIXIR,                                  
    FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE,                        
    FLAG_ITEM_FIERY_PATH_FIRE_STONE,                             
    FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM_HAIL,     
    FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE,                
    FLAG_ITEM_ROUTE_103_GUARD_SPEC,                              
    FLAG_ITEM_ROUTE_104_X_ACCURACY,                              
    FLAG_ITEM_MAUVILLE_CITY_X_SPEED,                             
    FLAG_ITEM_PETALBURG_WOODS_PARALYZE_HEAL,                     
    FLAG_ITEM_ROUTE_115_GREAT_BALL,                              
    FLAG_ITEM_SAFARI_ZONE_NORTH_CALCIUM,
    FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL,
    FLAG_ITEM_ROUTE_118_HYPER_POTION,
    FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL,
    FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL,
    //FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL,
    FLAG_ITEM_GRANITE_COVE_I,
    FLAG_ITEM_GRANITE_COVE_II,
    FLAG_ITEM_OLD_MAGMA_HIDEOUT_B2F_NEST_BALL,
    FLAG_UNUSED_0x468,
    FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL,
    FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE,
    FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE,
    FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET,
    //FLAG_ITEM_MOSSDEEP_STEVENS_HOUSE_HM08,
    FLAG_ITEM_ROUTE_119_NUGGET,
    FLAG_ITEM_ROUTE_104_POTION,
    FLAG_UNUSED_0x470,
    FLAG_ITEM_ROUTE_103_PP_UP,
    FLAG_UNUSED_0x472,
    FLAG_ITEM_ROUTE_108_STAR_PIECE,
    FLAG_ITEM_ROUTE_109_POTION,
    FLAG_ITEM_ROUTE_110_ELIXIR,
    FLAG_ITEM_ROUTE_111_ELIXIR,
    FLAG_ITEM_ROUTE_113_HYPER_POTION,
    FLAG_ITEM_ROUTE_115_HEAL_POWDER,
    FLAG_UNUSED_0x479,                           
    FLAG_ITEM_ROUTE_116_POTION,                           
    FLAG_ITEM_ROUTE_119_ELIXIR_2,                          
    FLAG_ITEM_ROUTE_120_REVIVE,                         
    FLAG_ITEM_ROUTE_121_REVIVE,                        
    FLAG_ITEM_ROUTE_121_ZINC,                       
    FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY,                      
    FLAG_ITEM_ROUTE_123_PP_UP,      
    FLAG_ITEM_ROUTE_123_REVIVAL_HERB,     
    FLAG_ITEM_ROUTE_125_BIG_PEARL,
    FLAG_ITEM_ROUTE_127_RARE_CANDY,   
    FLAG_ITEM_ROUTE_132_PROTEIN,  
    FLAG_ITEM_ROUTE_133_MAX_REVIVE, 
    FLAG_ITEM_ROUTE_134_CARBOS,
    FLAG_ITEM_ROUTE_134_STAR_PIECE,
    FLAG_ITEM_ROUTE_114_ENERGY_POWDER,
    FLAG_ITEM_ROUTE_115_PP_UP,
    FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP,
    FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS,
    FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR,
    FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE,
    FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET,
    FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX,
    FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE,
    FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET,
    FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL,
    FLAG_ITEM_CRATERED_CREST_I,                     
    FLAG_ITEM_CRATERED_CREST_II,                     
    FLAG_ITEM_CRATERED_CREST_III,                     
    FLAG_ITEM_CRATERED_CREST_IV,                   
    FLAG_ITEM_CRATERED_CREST_V,                 
    FLAG_ITEM_CRATERED_CREST_VI,                
    FLAG_ITEM_CRATERED_CREST_VII,                 
    FLAG_ITEM_CRATERED_CREST_VIII,               
    FLAG_ITEM_CRATERED_CREST_IX,            
    FLAG_ITEM_CRATERED_CREST_X,           
    FLAG_ITEM_CRATERED_CREST_XI,            
    FLAG_ITEM_CRATERED_CREST_XII,         
    FLAG_ITEM_CRATERED_CREST_XIII,         
    FLAG_ITEM_CRATERED_CREST_XIV,          
    FLAG_ITEM_CRATERED_CREST_XV,        
    FLAG_ITEM_CRATERED_CREST_XVI,        
    FLAG_ITEM_CRATERED_CREST_XVII,       
    FLAG_ITEM_CRATERED_CREST_XVIII,        
    FLAG_ITEM_CRATERED_CREST_XIX,     
    FLAG_ITEM_CRATERED_CREST_XX,   
    FLAG_ITEM_CRATERED_CREST_XXI,   
    FLAG_ITEM_CRATERED_CREST_XXII,   
    FLAG_ITEM_CRATERED_CREST_XXIII,  
    FLAG_ITEM_CRATERED_CREST_XXIV, 
    FLAG_ITEM_CRATERED_CREST_XXV,
    FLAG_ITEM_FORTREE_CLIFFS_1,
    FLAG_UNUSED_0x4AE,
    FLAG_UNUSED_0x4AF,
    FLAG_UNUSED_0x4B0,
    FLAG_UNUSED_0x4B1,
    FLAG_UNUSED_0x4B2,
    FLAG_UNUSED_0x4B3,
    FLAG_UNUSED_0x4B4,
    FLAG_UNUSED_0x4B5,
    FLAG_UNUSED_0x4B6,
    FLAG_UNUSED_0x4B7,
    FLAG_UNUSED_0x4B8,
    FLAG_UNUSED_0x4B9,
    FLAG_UNUSED_0x4BA,
    FLAG_UNUSED_0x4BB,
    FLAG_UNUSED_0x4BC,
    FLAG_UNUSED_0x4BD,
    FLAG_UNUSED_0x4BE,
    FLAG_UNUSED_0x4BF,
    FLAG_UNUSED_0x4C0,
    FLAG_UNUSED_0x4C1,
    FLAG_UNUSED_0x4C2,
    FLAG_ITEM_BEEDRILLITE,   
    FLAG_ITEM_SALAMENCITE,  
    FLAG_ITEM_LOPUNNITE,
    FLAG_ITEM_CAMERUPTITE, 
    FLAG_ITEM_GLALITITE,
    FLAG_ITEM_PIDGEOTITE,
    FLAG_ITEM_STEELIXITE,
    FLAG_ITEM_SLOWBRONITE,
    FLAG_ITEM_SHARPEDONITE,
    FLAG_ITEM_METAGROSSITE,
    FLAG_ITEM_AUDINITE,
    FLAG_ITEM_GALLADITE,
    FLAG_ITEM_ALTARIANITE, 
    FLAG_ITEM_SABLENITE,
    FLAG_ITEM_SCEPTILITE,
    FLAG_ITEM_SWAMPERTITE,
    FLAG_ITEM_LATIOSITE,
    FLAG_ITEM_LATIASITE,
    FLAG_ITEM_GARCHOMPITE, 
    FLAG_ITEM_MANECTITE,
    FLAG_ITEM_MAWILITE,
    FLAG_ITEM_HERACRONTIE,  
    FLAG_ITEM_CHARIZARDITE_Y,    
    FLAG_ITEM_ABSOLITE,
    FLAG_ITEM_GYARADOSITE,  
    FLAG_ITEM_KANGASKHANITE,   
    FLAG_ITEM_ABOMASITE,
    FLAG_ITEM_LUCARIONITE, 
    FLAG_ITEM_AERODACTYLITE,  
    FLAG_ITEM_PINSIRITE,
    FLAG_ITEM_SCIZORITE,
    FLAG_ITEM_TYRANITARITE,  
    FLAG_ITEM_BANETTITE,
    FLAG_ITEM_AGGRONITE,
    FLAG_ITEM_HOUNDOOMITE, 
    FLAG_ITEM_MEDICHAMITE,
    FLAG_ITEM_BLAZIKENITE,
    FLAG_ITEM_MEWTWONITE_Y,
    FLAG_ITEM_MEWTWONITE_X,
    FLAG_ITEM_BLASTOISINITE,
    FLAG_ITEM_CHARIZARDITE_X,
    FLAG_ITEM_VENUSAURITE,
    FLAG_ITEM_AMPHAROSITE,
    FLAG_ITEM_GARDEVOIRITE,
    FLAG_ITEM_GENGARITE,
    FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL,
    FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET,
    FLAG_HIDDEN_ITEM_ROUTE_111_STARDUST,
    FLAG_HIDDEN_ITEM_ROUTE_113_ETHER,
    FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS,
    FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM,
    FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_123_SUPER_REPEL,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_1,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_HEART_SCALE,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON,
    FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL,
    FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE,
    FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP,
    FLAG_HIDDEN_ITEM_UNDERWATER_127_HEART_SCALE,
    FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD,
    FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN,
    FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL,
    FLAG_HIDDEN_ITEM_LILYCOVE_CITY_HEART_SCALE,
    FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET,
    FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_113_TM_DOUBLE_TEAM,
    //FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY,
    //FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY,
    //FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY,
    //FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY,
    FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM,
    FLAG_HIDDEN_ITEM_ROUTE_104_POTION,
    FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_2,
    FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP,
    FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET,
    FLAG_HIDDEN_ITEM_ROUTE_123_REVIVE,
    FLAG_HIDDEN_ITEM_ROUTE_114_REVIVE,
    FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP,
    FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION,
    FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION,
    FLAG_HIDDEN_ITEM_ROUTE_106_STARDUST,
    FLAG_HIDDEN_ITEM_ROUTE_106_HEART_SCALE,
    FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1,
    FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2,
    FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE,
    FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_1,
    FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE,
    FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL,
    FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN,
    FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY,
    FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION,
    FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1,
    FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2,
    FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_109_ETHER,
    FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL,
    FLAG_HIDDEN_ITEM_ROUTE_118_HEART_SCALE,
    FLAG_HIDDEN_ITEM_ROUTE_118_IRON,
    FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL,
    FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2,
    FLAG_HIDDEN_ITEM_ROUTE_120_ZINC,
    FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1,
    FLAG_HIDDEN_ITEM_ROUTE_117_REPEL,
    FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL,
    FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION,
    FLAG_HIDDEN_ITEM_LILYCOVE_CITY_POKE_BALL,
    FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL,
    FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL,
    FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER,
    FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_ZINC,
    FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY,
    FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL,
    FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR,
    FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL,
    FLAG_HIDDEN_ITEM_ROUTE_120_REVIVE,
    FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE,
    FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY,
    FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER,
    FLAG_HIDDEN_ITEM_ROUTE_104_HEART_SCALE,
    FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE,
    FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_2,
    FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_3,
    FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_1,
    FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_2,
    FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_3,
    FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY,
    FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES,
    FLAG_HIDDEN_ITEM_ROUTE_115_HEART_SCALE,
    FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET,
    FLAG_HIDDEN_ITEM_ROUTE_123_PP_UP,
    FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE,
    FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM,
    FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC,
    FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN,
    FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON,
    FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE,
    FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_RARE_CANDY,
    FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_ZINC,
    FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_PP_UP,
    FLAG_HIDDEN_ITEM_NAVEL_ROCK_TOP_SACRED_ASH,
    FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY,
    FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL,
    FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ITEM_1
};

void ResetRandomItem(void)
{
    u32 i;
    for (i = 0; i < 5; i++) { // search 5 times for a set item flag
        u8 dieroll = Random() % ARRAY_COUNT(sRespawnableItemFlags);
        if (FlagGet(sRespawnableItemFlags[dieroll])){ // if the flag is set, clear it
            FlagClear(sRespawnableItemFlags[dieroll]);
            break;
        }
    }
}

void ResetWildOverworldMons(void)
{
    if (FlagGet(FLAG_GRANITE_COVE_SNOVER)) 
    {
        FlagClear(FLAG_GRANITE_COVE_SNOVER);
    }
    if (FlagGet(FLAG_ROOT_CELLAR_SHUCKLE_1))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_ROOT_CELLAR_SHUCKLE_1);
        }
    }
    if (FlagGet(FLAG_ROOT_CELLAR_SHUCKLE_2))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_ROOT_CELLAR_SHUCKLE_2);
        }
    }
    if (FlagGet(FLAG_ROOT_CELLAR_SPINARAK_1))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_ROOT_CELLAR_SPINARAK_1);
        }
    }
    if (FlagGet(FLAG_ROOT_CELLAR_SPINARAK_2))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_ROOT_CELLAR_SPINARAK_2);
        }
    }
    if (FlagGet(FLAG_CRATERED_CREST_DRAGONAIR))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_CRATERED_CREST_DRAGONAIR);
        }
    }
    if (FlagGet(FLAG_CRATERED_CREST_GYARADOS))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_CRATERED_CREST_GYARADOS);
        }
    }
    if (FlagGet(FLAG_CRATERED_CREST_CARNIVINE1))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_CRATERED_CREST_CARNIVINE1);
        }
    }
    if (FlagGet(FLAG_CRATERED_CREST_CARNIVINE2))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_CRATERED_CREST_CARNIVINE2);
        }
    }
    if (FlagGet(FLAG_CRATERED_CREST_TYRANTRUM))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_CRATERED_CREST_TYRANTRUM);
        }
    }
    if (FlagGet(FLAG_FORTREE_CLIFFS_DEN_A_MON))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_FORTREE_CLIFFS_DEN_A_MON);
            if (Random() % 5 == 0)
            {
                VarSet(VAR_FORTREE_CLIFFS_DEN_A_MON, SPECIES_SNORLAX);
            }
        }
    }
    if (FlagGet(FLAG_FORTREE_CLIFFS_DEN_B_MON))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_FORTREE_CLIFFS_DEN_B_MON);
            if (Random() % 5 == 0)
            {
                VarSet(VAR_FORTREE_CLIFFS_DEN_B_MON, SPECIES_SNORLAX);
            }
        }
    }
    if (FlagGet(FLAG_LAVARBOR_TUNNEL_ORTHWORM))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_LAVARBOR_TUNNEL_ORTHWORM);
        }
    }
}

void RestockBerryMasterCellar(void)
{
    u32 CoinFlip;

    if (VarGet(VAR_ROOT_CELLAR_SHELF_1) > 0)
    {
        CoinFlip = Random() % 2;
        VarSet(VAR_ROOT_CELLAR_SHELF_1, (VarGet(VAR_ROOT_CELLAR_SHELF_1) - CoinFlip));
    }
    if (VarGet(VAR_ROOT_CELLAR_SHELF_2) > 0)
    {
        CoinFlip = Random() % 2;
        VarSet(VAR_ROOT_CELLAR_SHELF_2, (VarGet(VAR_ROOT_CELLAR_SHELF_2) - CoinFlip));
    }
    if (VarGet(VAR_ROOT_CELLAR_SHELF_3) > 0)
    {
        CoinFlip = Random() % 3;
        VarSet(VAR_ROOT_CELLAR_SHELF_3, (VarGet(VAR_ROOT_CELLAR_SHELF_3) - CoinFlip));
    }
    if (VarGet(VAR_ROOT_CELLAR_SHELF_4) > 0)
    {
        CoinFlip = Random() % 2;
        VarSet(VAR_ROOT_CELLAR_SHELF_4, (VarGet(VAR_ROOT_CELLAR_SHELF_4) - CoinFlip));
    }
}

void CountBikeDeliveryDays(u16 days)
{
    if (VarGet(VAR_BIKE_QUEST_STATE) == 1)
    {
        VarSet(VAR_BIKE_DELIVERY_COUNTER, VarGet(VAR_BIKE_DELIVERY_COUNTER) + days);
    }
}

void ResetDailyTrainers(void)
{
    if (!FlagGet(FLAG_BADGE07_GET)){
        if (HasTrainerBeenFought(TRAINER_BRAXTON)){
            ClearTrainerFlag(TRAINER_BRAXTON);
        }
    }
}

void ProgressLavarborTunnelState(void)
{
    if (VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) >= 17) // if tunnel crew is assembled
    {
        // setting the frequency with which digRate will return 0's
        u32 digRate = (VarGet(VAR_LAVARBOR_TUNNEL_WORK_DAYS) + 3) % 3; // normal dig rate produces a 0 every three days after the first day
        if (FlagGet(FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED)) 
        {
            digRate = (VarGet(VAR_LAVARBOR_TUNNEL_WORK_DAYS) + 2) % 2; // if rusturf crew is recruited, produce a 0 every other day
        }

        // open fossil maniac's section if you recruited him
        if (FlagGet(FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED) && !FlagGet(FLAG_LAVARBOR_FALLARBOR_OPENED) && !FlagGet(FLAG_DEFEATED_LAVARBOR_GARCHOMP)) // if you recruited fossil maniac and the garchomp hasn't been defeated, set the fallarbor side of the tunnel to open
        {
            FlagSet(FLAG_LAVARBOR_FALLARBOR_OPENED); // flag should never be set unless FM is recruited befroe defeating garchmp
        }

        // either increment days worked, or open a side room and RETURN EARLY (therefore losing/falling behind one "work day")
        if (FlagGet(FLAG_LAVARBOR_DIGGING_SIDEROOM))
        {
            if ((FlagGet(FLAG_OPENED_SIDEROOM_1) && VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) == 20) 
                 || (FlagGet(FLAG_OPENED_SIDEROOM_2) && VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) == 21) 
                 || (FlagGet(FLAG_OPENED_SIDEROOM_3) && VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) == 22)) // if we're rolling over days after a day where sideroom digging began, clear the flag and end early
            { 
                FlagClear(FLAG_LAVARBOR_DIGGING_SIDEROOM);
                return;
            }
        }
        VarSet(VAR_LAVARBOR_TUNNEL_WORK_DAYS, VarGet(VAR_LAVARBOR_TUNNEL_WORK_DAYS) + 1); // increment days worked


        // incrementing quest state when appropriate
        if (digRate == 0 && VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) < 23) // increment quest state on day one, then every three days, while tunnel is still incomplete
        {
            VarSet(VAR_LAVARBOR_TUNNEL_QUEST_STATE, VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) + 1); // open next tunnel section
            if (FlagGet(FLAG_LAVARBOR_DIGGING_SIDEROOM)) // if this flag is still set, since it is used to route dialogue scripts, clear it now while expanding tunnel
            {
                FlagClear(FLAG_LAVARBOR_DIGGING_SIDEROOM);
            }
        }
        else if (FlagGet(FLAG_DEFEATED_LAVARBOR_GARCHOMP) // if you defeated boss garchomp
                 && VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) == 23 // and penultiamte phase of tunnel dig
                 //&& !FlagGet(FLAG_LAVARBOR_FALLARBOR_OPENED) // and fossil maniac didn't dig the next section yet
                 && digRate == 0) // and it's the day when an expansion would happen
        { 
            VarSet(VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24); // set to quest state 24
        }
        else if (VarGet(VAR_LAVARBOR_TUNNEL_QUEST_STATE) == 24 && digRate == 0)
        {
            VarSet(VAR_LAVARBOR_TUNNEL_QUEST_STATE, 25); // set to quest state 25
        }
    }
}
