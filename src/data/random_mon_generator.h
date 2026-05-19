// Pool settings for random mon generation via scripts. For more info on options, check out
// struct RandomSpeciesGeneratorOptions and struct RandomItemGeneratorOptions in src/random_mon_generation.c.

#include "constants/random_mon_generation.h"

static const enum Species sRandomSpeciesMomAfterWhiteOut[] =
{
    SPECIES_ZIGZAGOON,
    SPECIES_ZIGZAGOON,
    SPECIES_ZIGZAGOON,
    SPECIES_SLAKOTH,
    SPECIES_ZANGOOSE,
    SPECIES_TAILLOW,
    SPECIES_SKITTY,
    SPECIES_MEOWTH,
    SPECIES_TAILLOW,
    SPECIES_ZIGZAGOON,
};

static const enum Item sRandomItemTMTraderPool[] =
{
    ITEM_TM_SKILL_SWAP,
    ITEM_TM_SHADOW_BALL,
    ITEM_TM_SLUDGE_BOMB,
    ITEM_TM_IRON_TAIL,
    ITEM_TM_RETURN,
    ITEM_TM_SANDSTORM,
    ITEM_TM_RAIN_DANCE,
    ITEM_TM_SUNNY_DAY,
    ITEM_TM_DRAGON_CLAW,
    ITEM_TM_PSYSHOCK,
    ITEM_TM_SMACK_DOWN,
    ITEM_TM_AERIAL_ACE,
    ITEM_TM_FLAME_CHARGE,
    ITEM_TM_THIEF,
    ITEM_TM_ENERGY_BALL,
    ITEM_TM_FALSE_SWIPE,
    ITEM_TM_SCALD,
    ITEM_TM_CHARGE_BEAM,
    ITEM_TM_WILL_O_WISP,
    ITEM_TM_ACROBATICS,
    ITEM_TM_SHADOW_CLAW,
    ITEM_TM_ROCK_POLISH,
    ITEM_TM_VOLT_SWITCH,
    ITEM_TM_THUNDER_WAVE,
    ITEM_TM_DRAGON_TAIL,
    ITEM_TM_GRASS_KNOT,
    ITEM_TM_U_TURN,
    ITEM_TM_FLASH_CANNON,
    ITEM_TM_TRICK_ROOM,
    ITEM_TM_WILD_CHARGE,
    ITEM_TM_STEEL_WING,
    ITEM_BLANK_DISC,
};

static const enum Item sRandomItemBallTraderPool[] =
{
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_FAST_BALL,
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_HEAVY_BALL,
    ITEM_LOVE_BALL,
    ITEM_FRIEND_BALL,
    ITEM_MOON_BALL,
    ITEM_SPORT_BALL,
    ITEM_NET_BALL,
    ITEM_NEST_BALL,
    ITEM_REPEAT_BALL,
    ITEM_TIMER_BALL,
    ITEM_LUXURY_BALL,
    ITEM_PREMIER_BALL,
    ITEM_DIVE_BALL,
    ITEM_DUSK_BALL,
    ITEM_HEAL_BALL,
    ITEM_QUICK_BALL,
    ITEM_CHERISH_BALL,
    ITEM_DREAM_BALL,
    ITEM_STRANGE_BALL,
};

static const enum Item sRandomItemMintTraderPool[] =
{
    ITEM_LONELY_MINT,
    ITEM_ADAMANT_MINT,
    ITEM_NAUGHTY_MINT,
    ITEM_BRAVE_MINT,
    ITEM_BOLD_MINT,
    ITEM_IMPISH_MINT,
    ITEM_LAX_MINT,
    ITEM_RELAXED_MINT,
    ITEM_MODEST_MINT,
    ITEM_MILD_MINT,
    ITEM_RASH_MINT,
    ITEM_QUIET_MINT,
    ITEM_CALM_MINT,
    ITEM_GENTLE_MINT,
    ITEM_CAREFUL_MINT,
    ITEM_SASSY_MINT,
    ITEM_TIMID_MINT,
    ITEM_HASTY_MINT,
    ITEM_JOLLY_MINT,
    ITEM_NAIVE_MINT,
    ITEM_SERIOUS_MINT,
};

static const enum Item sRandomItemHeldItemTraderPool[] =
{
    ITEM_ABSORB_BULB,
    ITEM_AIR_BALLOON,
    ITEM_CELL_BATTERY,
    ITEM_FOCUS_SASH,
    ITEM_MIRROR_HERB,
    ITEM_POWER_HERB,
    ITEM_THROAT_SPRAY,
    ITEM_WHITE_HERB,
    ITEM_LAVA_COOKIE,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[RANDOM_SPECIES_OPTIONS_COUNT] =
{
    [SPECIES_GENERATOR_MOM_AFTER_WHITEOUT] =
    {
        .speciesPool = sRandomSpeciesMomAfterWhiteOut,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesMomAfterWhiteOut),
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = FALSE,
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[RANDOM_ITEM_OPTIONS_COUNT] =
{
    [ITEM_GENERATOR_TM_TRADER] =
    {
        .heldItemPool = sRandomItemTMTraderPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemTMTraderPool),
    },
    [ITEM_GENERATOR_BALL_TRADER] =
    {
        .heldItemPool = sRandomItemBallTraderPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemBallTraderPool),
    },
    [ITEM_GENERATOR_MINT_TRADER] =
    {
        .heldItemPool = sRandomItemMintTraderPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemMintTraderPool),
    },
    [ITEM_GENERATOR_HELD_TRADER] =
    {
        .heldItemPool = sRandomItemHeldItemTraderPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemHeldItemTraderPool),
    },
};
