#include "global.h"
#include "data.h"
#include "item.h"
#include "malloc.h"
#include "pokemon.h"
#include "random.h"
#include "trainer_pools.h"
#include "constants/battle.h"
#include "constants/battle_ai.h"
#include "constants/items.h"
#include "event_data.h"

#include "data/battle_pool_rules.h"

static void HasRequiredTag(const struct Trainer *trainer, u8* poolIndexArray, struct PoolRules *rules, u32 *arrayIndex, bool32 *foundRequiredTag, u32 currIndex)
{
    //  Start from index 2, since lead and ace has special handling
    for (u32 currTag = 2; currTag < POOL_NUM_TAGS; currTag++)
    {
        if (rules->tagRequired[currTag]
         && trainer->party[poolIndexArray[currIndex]].tags & (1u << currTag))
        {
            *arrayIndex = currIndex;
            *foundRequiredTag = TRUE;
            break;
        }
    }
}

static u32 DefaultLeadPickFunction(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules)
{
    u32 arrayIndex = 0;
    u32 monIndex = POOL_SLOT_DISABLED;
    //  monIndex is set to 255 if nothing has been chosen yet, this gives an upper limit on pool size of 255
    if ((partyIndex == 0)
     || (partyIndex == 1 && (battleTypeFlags & BATTLE_TYPE_DOUBLE)))
    {
        //  Find required + lead tags
        bool32 foundRequiredTag = FALSE;
        u32 firstLeadIndex = POOL_SLOT_DISABLED;
        for (u32 currIndex = 0; currIndex < trainer->poolSize; currIndex++)
        {
            if ((poolIndexArray[currIndex] != POOL_SLOT_DISABLED)
             && (trainer->party[poolIndexArray[currIndex]].tags & (1u << POOL_TAG_LEAD)))
            {
                if (firstLeadIndex == POOL_SLOT_DISABLED)
                    firstLeadIndex = currIndex;
                //  Start from index 2, since lead and ace has special handling
                HasRequiredTag(trainer, poolIndexArray, rules, &arrayIndex, &foundRequiredTag, currIndex);
            }
            if (foundRequiredTag)
                break;
        }
        //  If a combination of required + lead wasn't found, apply the first found lead
        if (foundRequiredTag)
        {
            monIndex = poolIndexArray[arrayIndex];
            poolIndexArray[arrayIndex] = POOL_SLOT_DISABLED;
        }
        else if (firstLeadIndex != POOL_SLOT_DISABLED)
        {
            monIndex = poolIndexArray[firstLeadIndex];
            poolIndexArray[firstLeadIndex] = POOL_SLOT_DISABLED;
        }
    }
    return monIndex;
}

static u32 DefaultAcePickFunction(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules)
{
    u32 arrayIndex = 0;
    u32 monIndex = POOL_SLOT_DISABLED;
    //  monIndex is set to 255 if nothing has been chosen yet, this gives an upper limit on pool size of 255
    if (((partyIndex == monsCount - 1) || (partyIndex == monsCount - 2 && battleTypeFlags & BATTLE_TYPE_DOUBLE))
     && (rules->tagMaxMembers[1] == POOL_MEMBER_COUNT_UNLIMITED || rules->tagMaxMembers[1] >= 1))
    {
        //  Find required + ace tags
        bool32 foundRequiredTag = FALSE;
        u32 firstAceIndex = POOL_SLOT_DISABLED;
        for (u32 currIndex = 0; currIndex < trainer->poolSize; currIndex++)
        {
            if ((poolIndexArray[currIndex] != POOL_SLOT_DISABLED)
             && (trainer->party[poolIndexArray[currIndex]].tags & (1u << POOL_TAG_ACE)))
            {
                if (firstAceIndex == POOL_SLOT_DISABLED)
                    firstAceIndex = currIndex;
                HasRequiredTag(trainer, poolIndexArray, rules, &arrayIndex, &foundRequiredTag, currIndex);
            }
            if (foundRequiredTag)
                break;
        }
        //  If a combination of required + ace wasn't found, apply the first found lead
        if (foundRequiredTag)
        {
            monIndex = poolIndexArray[arrayIndex];
            poolIndexArray[arrayIndex] = POOL_SLOT_DISABLED;
        }
        else if (firstAceIndex != POOL_SLOT_DISABLED)
        {
            monIndex = poolIndexArray[firstAceIndex];
            poolIndexArray[firstAceIndex] = POOL_SLOT_DISABLED;
        }
    }
    return monIndex;
}

static u32 RivalAcePickFunction(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules)
{
    u32 arrayIndex = 0;
    u32 monIndex = POOL_SLOT_DISABLED;
    //  monIndex is set to 255 if nothing has been chosen yet, this gives an upper limit on pool size of 255
    if (((partyIndex == monsCount - 1) || (partyIndex == monsCount - 2 && battleTypeFlags & BATTLE_TYPE_DOUBLE))
     && (rules->tagMaxMembers[1] == POOL_MEMBER_COUNT_UNLIMITED || rules->tagMaxMembers[1] >= 1))
    {
        //  Find required + ace tags
        bool32 foundRequiredTag = FALSE;
        u32 firstAceIndex = POOL_SLOT_DISABLED;
        u32 starter = VarGet(VAR_STARTER_MON);
        for (u32 currIndex = 0; currIndex < trainer->poolSize; currIndex++)
        {
            u16 currentSpecies = trainer->party[currIndex].species;
            if ((poolIndexArray[currIndex] != POOL_SLOT_DISABLED)
             && (trainer->party[poolIndexArray[currIndex]].tags & (1u << POOL_TAG_ACE)))
            {
//                if (firstAceIndex == POOL_SLOT_DISABLED)
//                    firstAceIndex = currIndex;
                if ((currentSpecies == SPECIES_TORCHIC 
                 || currentSpecies == SPECIES_COMBUSKEN 
                 || currentSpecies == SPECIES_BLAZIKEN)
                 && (starter == SPECIES_TREECKO || starter == SPECIES_PORYGON || starter == SPECIES_SNIVY 
                 || starter == SPECIES_ZORUA || starter == SPECIES_ROWLET || starter == SPECIES_TURTWIG 
                 || starter == SPECIES_BULBASAUR || starter == SPECIES_BUDEW || starter == SPECIES_PAWNIARD))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                } 
                else if ((currentSpecies == SPECIES_MUDKIP 
                 || currentSpecies == SPECIES_MARSHTOMP 
                 || currentSpecies == SPECIES_SWAMPERT)
                 && (starter == SPECIES_TORCHIC || starter == SPECIES_MAGBY || starter == SPECIES_CHARMANDER 
                 || starter == SPECIES_CYNDAQUIL))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                }
                else if ((currentSpecies == SPECIES_TREECKO 
                 || currentSpecies == SPECIES_GROVYLE 
                 || currentSpecies == SPECIES_SCEPTILE)
                 && (starter == SPECIES_MUDKIP || starter == SPECIES_PIPLUP || starter == SPECIES_SQUIRTLE || starter == SPECIES_OSHAWOTT))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;    
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                }
                else if ((currentSpecies == SPECIES_RIOLU 
                 || currentSpecies == SPECIES_LUCARIO)
                 && (starter == SPECIES_CASTFORM || starter == SPECIES_EEVEE || starter == SPECIES_ZORUA_HISUI 
                 || starter == SPECIES_LARVITAR || starter == SPECIES_SPHEAL))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;    
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                }
                else if ((currentSpecies == SPECIES_LARVITAR 
                 || currentSpecies == SPECIES_PUPITAR 
                 || currentSpecies == SPECIES_TYRANITAR)
                 && (starter == SPECIES_PICHU || starter == SPECIES_GOTHITA || starter == SPECIES_SOLOSIS 
                 || starter == SPECIES_LARVESTA || starter == SPECIES_MIME_JR || starter == SPECIES_ELEKID || starter == SPECIES_SHINX))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;    
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                }
                else if ((currentSpecies == SPECIES_SPHEAL 
                 || currentSpecies == SPECIES_SEALEO 
                 || currentSpecies == SPECIES_WALREIN)
                 && (starter == SPECIES_TOGEPI || starter == SPECIES_AXEW || starter == SPECIES_GOOMY 
                 || starter == SPECIES_SWINUB || starter == SPECIES_SANDILE))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;    
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                }
                else if ((currentSpecies == SPECIES_DRATINI 
                 || currentSpecies == SPECIES_DRAGONAIR 
                 || currentSpecies == SPECIES_DRAGONITE)
                 && (starter == SPECIES_APPLIN || starter == SPECIES_MANKEY))
                {
                    if (firstAceIndex == POOL_SLOT_DISABLED)
                        firstAceIndex = currIndex;    
                    poolIndexArray[arrayIndex] = currIndex;
                    poolIndexArray[firstAceIndex] = currIndex;
                    foundRequiredTag = TRUE;
                    //break;
                } 
            }
            if (foundRequiredTag)
                break;
        }
        //  If a combination of required + ace wasn't found, apply the first found lead
        if (foundRequiredTag)
        {
            monIndex = poolIndexArray[arrayIndex];
            poolIndexArray[arrayIndex] = POOL_SLOT_DISABLED;
        }
        else if (firstAceIndex != POOL_SLOT_DISABLED)
        {
            monIndex = poolIndexArray[firstAceIndex];
            poolIndexArray[firstAceIndex] = POOL_SLOT_DISABLED;
        }
    }
    return monIndex;
}

static u32 DefaultOtherPickFunction(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules)
{
    u32 arrayIndex = 0;
    u32 monIndex = POOL_SLOT_DISABLED;
    //  monIndex is set to 255 if nothing has been chosen yet, this gives an upper limit on pool size of 255
    //  Find required tag
    bool32 foundRequiredTag = FALSE;
    u32 firstUnpickedIndex = POOL_SLOT_DISABLED;
    for (u32 currIndex = 0; currIndex < trainer->poolSize; currIndex++)
    {
        if (poolIndexArray[currIndex] != POOL_SLOT_DISABLED
         && !(trainer->party[poolIndexArray[currIndex]].tags & (1u << POOL_TAG_LEAD))
         && !(trainer->party[poolIndexArray[currIndex]].tags & (1u << POOL_TAG_ACE)))
        {
            if (firstUnpickedIndex == POOL_SLOT_DISABLED)
                firstUnpickedIndex = currIndex;
            HasRequiredTag(trainer, poolIndexArray, rules, &arrayIndex, &foundRequiredTag, currIndex);
        }
        if (foundRequiredTag)
            break;
    }
    //  If a combination of required + ace wasn't found, apply the first found lead
    if (foundRequiredTag)
    {
        monIndex = poolIndexArray[arrayIndex];
        poolIndexArray[arrayIndex] = POOL_SLOT_DISABLED;
    }
    else if (firstUnpickedIndex != POOL_SLOT_DISABLED)
    {
        monIndex = poolIndexArray[firstUnpickedIndex];
        poolIndexArray[firstUnpickedIndex] = POOL_SLOT_DISABLED;
    }
    return monIndex;
}

static u32 PickLowest(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules)
{
    u32 monIndex = POOL_SLOT_DISABLED;
    u32 lowestIndex = POOL_SLOT_DISABLED;
    for (u32 i = 0; i < trainer->poolSize; i++)
    {
        if (poolIndexArray[i] < monIndex)
        {
            lowestIndex = i;
            monIndex = poolIndexArray[i];
        }
    }
    if (lowestIndex == POOL_SLOT_DISABLED)
        return POOL_SLOT_DISABLED;
    poolIndexArray[lowestIndex] = POOL_SLOT_DISABLED;
    return monIndex;
}

static u32 PickMonFromPool(const struct Trainer *trainer, u8 *poolIndexArray, u32 partyIndex, u32 monsCount, u32 battleTypeFlags, struct PoolRules *rules, struct PickFunctions pickFunctions)
{
    u32 monIndex = POOL_SLOT_DISABLED;
    //  Pick Lead
    if (monIndex == POOL_SLOT_DISABLED)
        monIndex = pickFunctions.LeadFunction(trainer, poolIndexArray, partyIndex, monsCount, battleTypeFlags, rules);
    //  Pick Ace
    if (monIndex == POOL_SLOT_DISABLED)
        monIndex = pickFunctions.AceFunction(trainer, poolIndexArray, partyIndex, monsCount, battleTypeFlags, rules);
    //  If no mon has been found yet continue looking
    if (monIndex == POOL_SLOT_DISABLED)
        monIndex = pickFunctions.OtherFunction(trainer, poolIndexArray, partyIndex, monsCount, battleTypeFlags, rules);
    //  If a mon still hasn't been found, return POOL_SLOT_DISABLED which makes party generation default to regular party generation
    if (monIndex == POOL_SLOT_DISABLED)
        return monIndex;

    u32 chosenTags = trainer->party[monIndex].tags;
    u16 chosenSpecies = trainer->party[monIndex].species;
    u16 chosenItem = trainer->party[monIndex].heldItem;
    enum NationalDexOrder chosenNatDex = gSpeciesInfo[chosenSpecies].natDexNum;
    //  If tag was required, change pool rule to account for the required tag already being picked
    u32 tagsToEliminate = 0;
    for (u32 currTag = 0; currTag < POOL_NUM_TAGS; currTag++)
    {
        if (chosenTags & (1u << currTag)
         && rules->tagMaxMembers[currTag] != POOL_MEMBER_COUNT_UNLIMITED)
        {
            if (rules->tagMaxMembers[currTag] == 1)
                rules->tagMaxMembers[currTag] = POOL_MEMBER_COUNT_NONE;
            else
                rules->tagMaxMembers[currTag]--;
        }
        if (chosenTags & (1u << currTag))
            rules->tagRequired[currTag] = FALSE;
        if (rules->tagMaxMembers[currTag] == POOL_MEMBER_COUNT_NONE)
            tagsToEliminate |= 1u << currTag;
    }
    //  If species clause, remove picked species from pool
    //  If item clause, remove all mons with same held item from pool
    //  If matching a tag that's been exhausted, remove from pool
    for (u32 currIndex = 0; currIndex < trainer->poolSize; currIndex++)
    {
        if (poolIndexArray[currIndex] != POOL_SLOT_DISABLED)
        {
            u32 currentTags = trainer->party[poolIndexArray[currIndex]].tags;
            u16 currentSpecies = trainer->party[poolIndexArray[currIndex]].species;
            u16 currentItem = trainer->party[poolIndexArray[currIndex]].heldItem;
            enum NationalDexOrder currentNatDex = gSpeciesInfo[currentSpecies].natDexNum;
            if (currentTags & tagsToEliminate)
            {
                poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
            }
            if (rules->speciesClause && chosenSpecies == currentSpecies)
                poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
            if (!rules->excludeForms && chosenNatDex == currentNatDex)
                poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
            if (rules->itemClause && currentItem != ITEM_NONE)
            {
                if (rules->itemClauseExclusions)
                {
                    bool32 isExcluded = FALSE;
                    for (u32 i = 0; i < ARRAY_COUNT(poolItemClauseExclusions); i++)
                    {
                        if (chosenItem == poolItemClauseExclusions[i])
                        {
                            isExcluded = TRUE;
                            break;
                        }
                    }
                    if (!isExcluded)
                        poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
                }
                else if (chosenItem == currentItem)
                {
                    poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
                }
            }
            if (rules->megaStoneClause && gItemsInfo[currentItem].sortType == ITEM_TYPE_MEGA_STONE && gItemsInfo[chosenItem].sortType == ITEM_TYPE_MEGA_STONE)
                poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
            if (rules->zCrystalClause && gItemsInfo[currentItem].sortType == ITEM_TYPE_Z_CRYSTAL && gItemsInfo[chosenItem].sortType == ITEM_TYPE_Z_CRYSTAL)
                poolIndexArray[currIndex] = POOL_SLOT_DISABLED;
        }
    }
    return monIndex;
}

static u32 GetPoolSeed(const struct Trainer *trainer)
{
    u32 seed;
    if (B_POOL_SETTING_USE_FIXED_SEED)
        seed = B_POOL_SETTING_FIXED_SEED;
    else
        seed = READ_OTID_FROM_SAVE;
    seed ^= (u32)trainer;
    return seed;
}

static void RandomizePoolIndices(const struct Trainer *trainer, u8 *poolIndexArray)
{
    //  Basically the modern (Durstenfield's) Fisher-Yates shuffle
    //  Reducing the amount of calls to random needed by only using as many bits as needed per shuffle
    u32 poolSize = trainer->poolSize;
    for (u32 i = 0; i < poolSize; i++)
        poolIndexArray[i] = i;
    u32 rnd;
    rng_value_t localRngState;
    if (B_POOL_SETTING_CONSISTENT_RNG)
    {
        u32 seed = GetPoolSeed(trainer);
        localRngState = LocalRandomSeed(seed);
        //  Replace the LocalRandom with LocalRandom32 when implemented
        rnd = LocalRandom32(&localRngState);
    }
    else
    {
        rnd = Random32();
    }
    u32 usedBits = 0;
    for (u32 i = 0; i < poolSize - 1; i++)
    {
        u32 numBits = 1;
        if (poolSize - i > 127)
            numBits = 8;
        else if (poolSize - i > 63)
            numBits = 7;
        else if (poolSize - i > 31)
            numBits = 6;
        else if (poolSize - i > 15)
            numBits = 5;
        else if (poolSize - i > 7)
            numBits = 4;
        else if (poolSize - i > 3)
            numBits = 3;
        else if (poolSize - i > 1)
            numBits = 2;
        if (usedBits + numBits > 32)
        {
            if (B_POOL_SETTING_CONSISTENT_RNG)
                rnd = LocalRandom32(&localRngState);
            else
                rnd = Random32();
            usedBits = 0;
        }
        u32 currIndex = (rnd & ((1u << numBits) - 1)) % (poolSize - i);
        rnd = rnd >> numBits;
        usedBits += numBits;
        u32 tempValue = poolIndexArray[poolSize - 1 - i];
        poolIndexArray[poolSize - 1 - i] = poolIndexArray[currIndex];
        poolIndexArray[currIndex] = tempValue;
    }
}

static struct PickFunctions GetPickFunctions(const struct Trainer *trainer)
{
    struct PickFunctions pickFunctions;
    switch (trainer->poolPickIndex)
    {
        //  Repeats, but better to have the safety
        case POOL_PICK_DEFAULT:
            pickFunctions.LeadFunction = &DefaultLeadPickFunction;
            pickFunctions.AceFunction = &DefaultAcePickFunction;
            pickFunctions.OtherFunction = &DefaultOtherPickFunction;
            break;
        case POOL_PICK_LOWEST:
            pickFunctions.LeadFunction = &PickLowest;
            pickFunctions.AceFunction = &PickLowest;
            pickFunctions.OtherFunction = &PickLowest;
            break;
        case POOL_PICK_RIVAL:
            pickFunctions.LeadFunction = &DefaultLeadPickFunction;
            pickFunctions.AceFunction = &RivalAcePickFunction;
            pickFunctions.OtherFunction = &DefaultOtherPickFunction;
            break;
        default:
            pickFunctions.LeadFunction = &DefaultLeadPickFunction;
            pickFunctions.AceFunction = &DefaultAcePickFunction;
            pickFunctions.OtherFunction = &DefaultOtherPickFunction;
            break;
    }
    return pickFunctions;
}

static void TestPrune(const struct Trainer *trainer, u8 *poolIndexArray, const struct PoolRules *rules)
{
    //  Test function to demonstrate pruning
    for (u32 i = 0; i < trainer->poolSize; i++)
        if (trainer->party[poolIndexArray[i]].species == SPECIES_WOBBUFFET)
            poolIndexArray[i] = POOL_SLOT_DISABLED;
}

static void RivalPrune(const struct Trainer *trainer, u8 *poolIndexArray, const struct PoolRules *rules)
{
    u32 starter = VarGet(VAR_RIVAL_STARTER);
    for (u32 i = 0; i < trainer->poolSize; i++)
    {
        u16 currentSpecies = trainer->party[poolIndexArray[i]].species;
        if (starter == SPECIES_TREECKO)
        {
            if (currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
             || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
             || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
             || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
             || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
             || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
             || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
             || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
             || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
             || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
             || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
             || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
             || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
             || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
             || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
             || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
             || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
             || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
             || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
             || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }
        if (starter == SPECIES_TORCHIC)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
             || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
             || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
             || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
             || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
             || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
             || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
             || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
             || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
             || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
             || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
             || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
             || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
             || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
             || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
             || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
             || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
             || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
             || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
             || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        } 
        if (starter == SPECIES_MUDKIP)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_NIDORAN_F)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_POLIWAG)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_ABRA)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_RHYHORN)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_DRATINI)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_CHIKORITA)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_MAREEP)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_SWINUB)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_WHISMUR)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_BUDEW)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_TRAPINCH)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_DUSKULL)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_SPHEAL)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_SHINX)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_FLETCHLING)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_MAGBY)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_ELEKID)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_GOOMY || currentSpecies == SPECIES_SLIGGOO || currentSpecies == SPECIES_GOODRA_HISUI)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }if (starter == SPECIES_GOOMY)
        {
            if (currentSpecies == SPECIES_TREECKO || currentSpecies == SPECIES_GROVYLE || currentSpecies == SPECIES_SCEPTILE
                || currentSpecies == SPECIES_TORCHIC || currentSpecies == SPECIES_COMBUSKEN || currentSpecies == SPECIES_BLAZIKEN
                || currentSpecies == SPECIES_MUDKIP || currentSpecies == SPECIES_MARSHTOMP || currentSpecies == SPECIES_SWAMPERT
                || currentSpecies == SPECIES_NIDORAN_F || currentSpecies == SPECIES_NIDORINA || currentSpecies == SPECIES_NIDOQUEEN
                || currentSpecies == SPECIES_POLIWAG || currentSpecies == SPECIES_POLIWHIRL || currentSpecies == SPECIES_POLITOED
                || currentSpecies == SPECIES_ABRA || currentSpecies == SPECIES_KADABRA || currentSpecies == SPECIES_ALAKAZAM
                || currentSpecies == SPECIES_RHYHORN || currentSpecies == SPECIES_RHYDON || currentSpecies == SPECIES_RHYPERIOR
                || currentSpecies == SPECIES_DRATINI || currentSpecies == SPECIES_DRAGONAIR || currentSpecies == SPECIES_DRAGONITE
                || currentSpecies == SPECIES_CHIKORITA || currentSpecies == SPECIES_BAYLEEF || currentSpecies == SPECIES_MEGANIUM
                || currentSpecies == SPECIES_MAREEP || currentSpecies == SPECIES_FLAAFFY || currentSpecies == SPECIES_AMPHAROS
                || currentSpecies == SPECIES_SWINUB || currentSpecies == SPECIES_PILOSWINE || currentSpecies == SPECIES_MAMOSWINE
                || currentSpecies == SPECIES_WHISMUR || currentSpecies == SPECIES_LOUDRED || currentSpecies == SPECIES_EXPLOUD
                || currentSpecies == SPECIES_BUDEW || currentSpecies == SPECIES_ROSELIA || currentSpecies == SPECIES_ROSERADE
                || currentSpecies == SPECIES_TRAPINCH || currentSpecies == SPECIES_VIBRAVA || currentSpecies == SPECIES_FLYGON
                || currentSpecies == SPECIES_DUSKULL || currentSpecies == SPECIES_DUSCLOPS || currentSpecies == SPECIES_DUSKNOIR
                || currentSpecies == SPECIES_SPHEAL || currentSpecies == SPECIES_SEALEO || currentSpecies == SPECIES_WALREIN
                || currentSpecies == SPECIES_SHINX || currentSpecies == SPECIES_LUXIO || currentSpecies == SPECIES_LUXRAY
                || currentSpecies == SPECIES_FLETCHLING || currentSpecies == SPECIES_FLETCHINDER || currentSpecies == SPECIES_TALONFLAME
                || currentSpecies == SPECIES_MAGBY || currentSpecies == SPECIES_MAGMAR || currentSpecies == SPECIES_MAGMORTAR
                || currentSpecies == SPECIES_ELEKID || currentSpecies == SPECIES_ELECTABUZZ || currentSpecies == SPECIES_ELECTIVIRE)
            {
                poolIndexArray[i] = POOL_SLOT_DISABLED;
            }
        }    
    }
}

static void LatiPrune(const struct Trainer *trainer, u8 *poolIndexArray, const struct PoolRules *rules)
{
    //  Test function to demonstrate pruning
    for (u32 i = 0; i < trainer->poolSize; i++)
        if (trainer->party[poolIndexArray[i]].species == SPECIES_LATIAS && VarGet(VAR_ROAMER_POKEMON) == 0){
            poolIndexArray[i] = POOL_SLOT_DISABLED;
        }
        else if (trainer->party[poolIndexArray[i]].species == SPECIES_LATIOS && VarGet(VAR_ROAMER_POKEMON) == 1){
            poolIndexArray[i] = POOL_SLOT_DISABLED;
        }
}

static void RandomTagPrune(const struct Trainer *trainer, u8 *poolIndexArray, const struct PoolRules *rules)
{
    u32 tagToUse = trainer->party[poolIndexArray[0]].tags;
    for (u32 i = 0; i < trainer->poolSize; i++)
        if (!(trainer->party[poolIndexArray[i]].tags & tagToUse))
            poolIndexArray[i] = POOL_SLOT_DISABLED;
}

static void PrunePool(const struct Trainer *trainer, u8 *poolIndexArray, const struct PoolRules *rules)
{
    //  Use defined pruning functions go here
    switch (trainer->poolPruneIndex)
    {
        case POOL_PRUNE_NONE:
            break;
        case POOL_PRUNE_TEST:
            TestPrune(trainer, poolIndexArray, rules);
            break;
        case POOL_PRUNE_RIVAL:
            RivalPrune(trainer, poolIndexArray, rules);
            break;
        case POOL_PRUNE_LATI:
            LatiPrune(trainer, poolIndexArray, rules);
            break;
        case POOL_PRUNE_RANDOM_TAG:
            RandomTagPrune(trainer, poolIndexArray, rules);
            break;
        default:
            break;
    }
}

void DoTrainerPartyPool(const struct Trainer *trainer, u32 *monIndices, u8 monsCount, u32 battleTypeFlags)
{
        bool32 usingPool = FALSE;
        struct PoolRules rules = defaultPoolRules;
        struct Trainer tempTrainer;
        if (trainer->poolSize == 0 && (trainer->aiFlags & AI_FLAG_RANDOMIZE_PARTY_INDICES))
        {
            tempTrainer = *trainer;
            tempTrainer.poolSize = tempTrainer.partySize;
            trainer = &tempTrainer;
        }

        if (trainer->poolSize != 0)
        {
            usingPool = TRUE;
            rules = gPoolRulesetsList[trainer->poolRuleIndex];
            u8 *poolIndexArray = Alloc(trainer->poolSize);
            RandomizePoolIndices(trainer, poolIndexArray);

            struct PickFunctions pickFunctions = GetPickFunctions(trainer);

            PrunePool(trainer, poolIndexArray, &rules);

            for (u32 i = 0; i < monsCount; i++)
            {
                monIndices[i] = PickMonFromPool(trainer, poolIndexArray, i, monsCount, battleTypeFlags, &rules, pickFunctions);
                //  If the slot doesn't have a proper value, the pool creation failed, fall back to normal mon pick process
                if (monIndices[i] == POOL_SLOT_DISABLED)
                {
                    usingPool = FALSE;
                    break;
                }
            }
            Free(poolIndexArray);
        }

        if (!usingPool)
            for (u32 i = 0; i < monsCount; i++)
                monIndices[i] = i;
}
