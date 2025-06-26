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

void ResetRandomItem(void)
{
    u8 dieroll;
    u8 itemflag;
    u8 hiddenitemflag;
    dieroll = Random() % 3;
    itemflag = Random() % (FLAG_ITEM_GENGARITE - FLAG_ITEM_ROUTE_102_POTION);
    hiddenitemflag = Random() % (FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL - FLAG_HIDDEN_ITEMS_START);
    if ((itemflag == FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL) || (itemflag == FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER) || (itemflag == FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY) || (hiddenitemflag == FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY) || (hiddenitemflag == FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY) || (hiddenitemflag == FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY) || (hiddenitemflag == FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY))
    {
        dieroll = 2;
    }
    switch (dieroll)
    {
    case 0:
        FlagClear(FLAG_ITEM_ROUTE_102_POTION + itemflag);
        break;
    case 1:
        FlagClear(FLAG_HIDDEN_ITEMS_START + hiddenitemflag);
        break;
    case 2:
        break;
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
    if (FlagGet(FLAG_DRAGONS_ROOST_CROCONAW))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_CROCONAW);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_DRAGONAIR))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_DRAGONAIR);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_GYARADOS))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_GYARADOS);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_CARNIVINE1))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_CARNIVINE1);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_CARNIVINE2))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_CARNIVINE2);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_AURORUS))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_AURORUS);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_AURORUS))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_AURORUS);
        }
    }
    if (FlagGet(FLAG_DRAGONS_ROOST_TYRANTRUM))
    {
        if (Random() % 2)
        {
            FlagClear(FLAG_DRAGONS_ROOST_TYRANTRUM);
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
