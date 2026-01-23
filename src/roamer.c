#include "global.h"
#include "event_data.h"
#include "ow_synchronize.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
#define ROAMER_MAP_GROUP 0

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

#define ROAMER(index) (&gSaveBlock1Ptr->roamer[index])
EWRAM_DATA static u8 sLocationHistory[ROAMER_COUNT][3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[ROAMER_COUNT][2] = {0};
EWRAM_DATA u8 gEncounteredRoamerIndex = 0;

#define ___ MAP_NUM(MAP_UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][6] =
{
    { MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE134), ___ },
    { MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE123) },
    { MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE120), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE121), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE123), ___, ___ },
    { MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE123), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE123), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE118), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), ___, ___ },
    { MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE128), ___, ___ },
    { MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE129), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE130), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE131), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE132), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE133), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE134), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE134), MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

void DeactivateAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        SetRoamerInactive(i);
}

static void ClearRoamerLocationHistory(u32 roamerIndex)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sLocationHistory[roamerIndex]); i++)
    {
        sLocationHistory[roamerIndex][i][MAP_GRP] = 0;
        sLocationHistory[roamerIndex][i][MAP_NUM] = 0;
    }
}

void MoveAllRoamersToOtherLocationSets(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMoveToOtherLocationSet(i);
}

void MoveAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMove(i);
}

static void CreateInitialRoamerMon(u8 index, u16 species, u8 level)
{
    u8 isShiny;
    u8 rand;

    ClearRoamerLocationHistory(index);
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(ROAMER_ORIGIN, species),
        GetSynchronizedNature(ROAMER_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    rand = Random() % 100;
    if (rand < 25)
    {
        isShiny = TRUE;
        SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &isShiny);
    }
    ROAMER(index)->isShiny = GetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY);
    ROAMER(index)->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER(index)->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER(index)->species = species;
    ROAMER(index)->level = level;
    ROAMER(index)->statusA = 0;
    ROAMER(index)->statusB = 0;
    ROAMER(index)->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    ROAMER(index)->cool = GetMonData(&gEnemyParty[0], MON_DATA_COOL);
    ROAMER(index)->beauty = GetMonData(&gEnemyParty[0], MON_DATA_BEAUTY);
    ROAMER(index)->cute = GetMonData(&gEnemyParty[0], MON_DATA_CUTE);
    ROAMER(index)->smart = GetMonData(&gEnemyParty[0], MON_DATA_SMART);
    ROAMER(index)->tough = GetMonData(&gEnemyParty[0], MON_DATA_TOUGH);
    ROAMER(index)->active = TRUE;
    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;
    sRoamerLocation[index][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
}

static u8 GetFirstInactiveRoamerIndex(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (!ROAMER(i)->active)
            return i;
    }
    return ROAMER_COUNT;
}

bool8 TryAddRoamer(u16 species, u8 level)
{
    u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        // Create the roamer and stop searching
        CreateInitialRoamerMon(index, species, level);
        return TRUE;
    }

    // Maximum active roamers found: do nothing and let the calling function know
    return FALSE;
}

// gSpecialVar_0x8004 here corresponds to the options in the multichoice MULTI_TV_LATI (0 for 'Red', 1 for 'Blue')
// MR LEAKY UPDATE not anymore sucker,s now it means which roamer arre we initing, 0 for beasts, 1 for articuno, 2 for latis, 3 for moltres, 
void InitRoamer(void)
{
    if (gSpecialVar_Unused_0x8014 == 0)
    {
        if (gSpecialVar_0x8004 == 0) // starter group A
        {
            TryAddRoamer(SPECIES_ENTEI, 60);
            VarSet(VAR_BEAST_SPECIES, SPECIES_ENTEI);
        }
        if (gSpecialVar_0x8004 == 1) // starter group B
        {
            TryAddRoamer(SPECIES_SUICUNE, 60);
            VarSet(VAR_BEAST_SPECIES, SPECIES_SUICUNE);
        }
        if (gSpecialVar_0x8004 == 2) // starter group C
        {
            TryAddRoamer(SPECIES_RAIKOU, 60);
            VarSet(VAR_BEAST_SPECIES, SPECIES_RAIKOU);
        }
    }
    if (gSpecialVar_Unused_0x8014 == 1)
    {
        TryAddRoamer(SPECIES_ARTICUNO, 30);
    }
    if (gSpecialVar_Unused_0x8014 == 3)
    {
        TryAddRoamer(SPECIES_MOLTRES, 35);
    }
    if (gSpecialVar_Unused_0x8014 == 2)
    {
        if (gSpecialVar_0x8004 == 0) // Red
            TryAddRoamer(SPECIES_LATIAS, 60);
        else
            TryAddRoamer(SPECIES_LATIOS, 60);
    }
}

void UpdateLocationHistoryForRoamer(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

        sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

        sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }
}

void RoamerMoveToOtherLocationSet(u32 roamerIndex)
{
    u8 mapNum = 0;

    if (!ROAMER(roamerIndex)->active)
        return;

    sRoamerLocation[roamerIndex][MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    do
    {
        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
        if (sRoamerLocation[roamerIndex][MAP_NUM] != mapNum)
        {
            sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
            return;
        }
    } while (sRoamerLocation[roamerIndex][MAP_NUM] == mapNum);
    sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
}

void RoamerMove(u32 roamerIndex)
{
    u8 locSet = 0;

    if ((Random() % 16) == 0)
    {
        RoamerMoveToOtherLocationSet(roamerIndex);
    }
    else
    {
        if (!ROAMER(roamerIndex)->active)
            return;

        while (locSet < NUM_LOCATION_SETS)
        {
            // Find the location set that starts with the roamer's current map
            if (sRoamerLocation[roamerIndex][MAP_NUM] == sRoamerLocations[locSet][0])
            {
                u8 mapNum;
                // Choose a new map (excluding the first) within this set
                // Also exclude a map if the roamer was there 2 moves ago
                do
                {
                    mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                } while ((sLocationHistory[roamerIndex][2][MAP_GRP] == ROAMER_MAP_GROUP
                        && sLocationHistory[roamerIndex][2][MAP_NUM] == mapNum)
                        || mapNum == MAP_NUM(MAP_UNDEFINED));
                sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
                return;
            }
            locSet++;
        }
    }
}

bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum)
{
    if (ROAMER(roamerIndex)->active && mapGroup == sRoamerLocation[roamerIndex][MAP_GRP] && mapNum == sRoamerLocation[roamerIndex][MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

void CreateRoamerMonInstance(u32 roamerIndex)
{
    u32 status = ROAMER(roamerIndex)->statusA + (ROAMER(roamerIndex)->statusB << 8);
    struct Pokemon *mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, ROAMER(roamerIndex)->species, ROAMER(roamerIndex)->level, ROAMER(roamerIndex)->ivs, ROAMER(roamerIndex)->personality);
    SetMonData(mon, MON_DATA_STATUS, &status);
    if (ROAMER(roamerIndex)->hp == 0)
    {
        u16 maxhp = GetMonData(mon, MON_DATA_MAX_HP);
        SetMonData(mon, MON_DATA_HP, &maxhp);
    }
    else 
    {
        SetMonData(mon, MON_DATA_HP, &ROAMER(roamerIndex)->hp);
    }
    SetMonData(mon, MON_DATA_COOL, &ROAMER(roamerIndex)->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER(roamerIndex)->beauty);
    SetMonData(mon, MON_DATA_CUTE, &ROAMER(roamerIndex)->cute);
    SetMonData(mon, MON_DATA_SMART, &ROAMER(roamerIndex)->smart);
    SetMonData(mon, MON_DATA_TOUGH, &ROAMER(roamerIndex)->tough);
    SetMonData(mon, MON_DATA_IS_SHINY, &ROAMER(roamerIndex)->isShiny);
}

bool8 TryStartRoamerEncounter(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
        {
            CreateRoamerMonInstance(i);
            gEncounteredRoamerIndex = i;
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS);

    ROAMER(gEncounteredRoamerIndex)->hp = GetMonData(mon, MON_DATA_HP);
    ROAMER(gEncounteredRoamerIndex)->statusA = status;
    ROAMER(gEncounteredRoamerIndex)->statusB = status >> 8;

    RoamerMoveToOtherLocationSet(gEncounteredRoamerIndex);
}

void SetRoamerInactive(u32 roamerIndex)
{
    ROAMER(roamerIndex)->active = FALSE;
}

void ResetSleepingRoamer(u32 roamerIndex)
{
    if ((ROAMER(roamerIndex)->species == SPECIES_LATIOS) || (ROAMER(roamerIndex)->species == SPECIES_LATIAS))
    {
        VarSet(VAR_ROAMING_LATI_STATE, 2);
    }
    if (ROAMER(roamerIndex)->species == SPECIES_ARTICUNO)
    {
        FlagClear(FLAG_HIDE_ARTICUNO);
    }
    if (ROAMER(roamerIndex)->species == SPECIES_MOLTRES)
    {
        FlagClear(FLAG_HIDE_ARTICUNO);
    }
    if ((ROAMER(roamerIndex)->species == SPECIES_ENTEI) || (ROAMER(roamerIndex)->species == SPECIES_SUICUNE) || (ROAMER(roamerIndex)->species == SPECIES_RAIKOU))
    {
        FlagSet(FLAG_NO_ACTIVE_BEAST);
    }
}

void CaughtRoamer(u32 roamerIndex)
{
    if ((ROAMER(roamerIndex)->species == SPECIES_LATIOS) || (ROAMER(roamerIndex)->species == SPECIES_LATIAS))
    {
        VarSet(VAR_ROAMING_LATI_STATE, 1);
    } 
    if (ROAMER(roamerIndex)->species == SPECIES_ENTEI)
    {
        //VarSet(VAR_BEAST_SPECIES, SPECIES_SUICUNE);
        FlagSet(FLAG_CAUGHT_ROAMING_ENTEI);
        FlagSet(FLAG_NO_ACTIVE_BEAST);
        if ((FlagGet(FLAG_CAUGHT_ROAMING_ENTEI) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_SUICUNE) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_RAIKOU) == TRUE))
        {
            FlagSet(FLAG_ROAMING_BEASTS_CAUGHT);
        }
    }
    if (ROAMER(roamerIndex)->species == SPECIES_SUICUNE)
    {
        //VarSet(VAR_BEAST_SPECIES, SPECIES_RAIKOU);
        FlagSet(FLAG_CAUGHT_ROAMING_SUICUNE);
        FlagSet(FLAG_NO_ACTIVE_BEAST);
        if ((FlagGet(FLAG_CAUGHT_ROAMING_ENTEI) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_SUICUNE) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_RAIKOU) == TRUE))
        {
            FlagSet(FLAG_ROAMING_BEASTS_CAUGHT);
        }
    }
    if (ROAMER(roamerIndex)->species == SPECIES_RAIKOU)
    {
        //VarSet(VAR_BEAST_SPECIES, SPECIES_ENTEI);
        FlagSet(FLAG_CAUGHT_ROAMING_RAIKOU);
        FlagSet(FLAG_NO_ACTIVE_BEAST);
        if ((FlagGet(FLAG_CAUGHT_ROAMING_ENTEI) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_SUICUNE) == TRUE) && (FlagGet(FLAG_CAUGHT_ROAMING_RAIKOU) == TRUE))
        {
            FlagSet(FLAG_ROAMING_BEASTS_CAUGHT);
        }
    }
}

void ActivateRoamer(u32 roamerIndex)
{
    if (gSpecialVar_Unused_0x8014 == 1) // articuno
    {
        roamerIndex = 1;
    }
    if (gSpecialVar_Unused_0x8014 == 3) // moltres
    {
        roamerIndex = 3;
    }
    ROAMER(roamerIndex)->active = TRUE;
}

void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[roamerIndex][MAP_GRP];
    *mapNum = sRoamerLocation[roamerIndex][MAP_NUM];
}
