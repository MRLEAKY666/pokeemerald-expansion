#include "constants/global.h"
#include "constants/event_objects.h"

#if MODERN == 0
static const u8 sText_OutfitName_UsualGreen[] = _("USUAL GREEN");
static const u8 sText_OutfitDesc_UsualGreen[] = _(
    "The usual, but basic OUTFIT.");

static const u8 sText_OutfitName_UnusualRed[] = _("UNUSUAL RED");
static const u8 sText_OutfitDesc_UnusualRed[] = _(
    "Rather unusual, but still basic\nOUTFIT.");
#endif

static const u16 sRegionMapPlayerIcon_BrendanGfx[] = INCBIN_U16("graphics/pokenav/region_map/brendan_icon.4bpp");

static const u16 sRegionMapPlayerIcon_RSBrendanGfx[] = INCBIN_U16("graphics/pokenav/region_map/rs_brendan_icon.4bpp");

static const u16 sRegionMapPlayerIcon_MayGfx[] = INCBIN_U16("graphics/pokenav/region_map/may_icon.4bpp");

static const u16 sRegionMapPlayerIcon_RSMayGfx[] = INCBIN_U16("graphics/pokenav/region_map/rs_may_icon.4bpp");

static const u16 sRegionMapPlayerIcon_OldManDisguiseGfx[] = INCBIN_U16("graphics/pokenav/region_map/old_man_disguise_icon.4bpp");

//! TODO: Should the gfx here be seperated?

static const u8 sFrontierPassPlayerIcons_BrendanMay_Gfx[] = INCBIN_U8("graphics/frontier_pass/map_heads.4bpp");

static const u8 sFrontierPassPlayerIcons_MayBrendan_Gfx[] = INCBIN_U8("graphics/frontier_pass/map_heads_swapped.4bpp");

static const u8 sFrontierPassPlayerIcons_RSBrendanMay_Gfx[] = INCBIN_U8("graphics/frontier_pass/rs_map_heads.4bpp");

static const u8 sFrontierPassPlayerIcons_RSMayBrendan_Gfx[] = INCBIN_U8("graphics/frontier_pass/rs_map_heads_swapped.4bpp");

static const u8 sFrontierPassPlayerIcons_OldManDisguise_Gfx[] = INCBIN_U8("graphics/frontier_pass/old_man_disguise_heads.4bpp");

#define REGION_MAP_GFX(m, f) { sRegionMapPlayerIcon_ ## m ## Gfx, sRegionMapPlayerIcon_ ## f ## Gfx }

// bandaids to avoid adding unnecessary merge conflicts
// remove these if you have them added/renamed yourself.
/* 
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_NORMAL     OBJ_EVENT_GFX_LINK_RS_BRENDAN
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_ACRO_BIKE  OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_SURFING    OBJ_EVENT_GFX_BRENDAN_SURFING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_UNDERWATER OBJ_EVENT_GFX_BRENDAN_UNDERWATER
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FIELD_MOVE OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FISHING    OBJ_EVENT_GFX_BRENDAN_FISHING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_WATERING   OBJ_EVENT_GFX_BRENDAN_WATERING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_DECORATING OBJ_EVENT_GFX_BRENDAN_DECORATING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FIELD_MOVE OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE

#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_NORMAL     OBJ_EVENT_GFX_LINK_RS_MAY
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_ACRO_BIKE  OBJ_EVENT_GFX_MAY_ACRO_BIKE
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_SURFING    OBJ_EVENT_GFX_MAY_SURFING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_UNDERWATER OBJ_EVENT_GFX_MAY_UNDERWATER
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FIELD_MOVE OBJ_EVENT_GFX_MAY_FIELD_MOVE
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FISHING    OBJ_EVENT_GFX_MAY_FISHING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_WATERING   OBJ_EVENT_GFX_MAY_WATERING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_DECORATING OBJ_EVENT_GFX_MAY_DECORATING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FIELD_MOVE OBJ_EVENT_GFX_MAY_FIELD_MOVE 
*/

const struct Outfit gOutfits[OUTFIT_COUNT] =
{
    [OUTFIT_NONE] = {
        .isHidden = TRUE
    },
    [OUTFIT_USUAL_GREEN] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,

        //! DESC: prices for purchasing them.
        .prices = { 0, 0 },

        //! agbcc doesnt like COMPOUND_STRING on my end
        //! DESC: outfit's name
        #if MODERN == 1
        .name = COMPOUND_STRING("NORMAL OUTFIT"),
        #else
        .name = sText_OutfitName_UsualGreen,
        #endif

        //! DESC: outfit's description
        #if MODERN == 1
        .desc = COMPOUND_STRING("The usual, but basic\nOUTFIT."),
        #else
        .desc = sText_OutfitDesc_UsualGreen,
        #endif

        //! DESC: trainer front & back pic index
        //! (see include/constants/trainers.h)
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_BRENDAN, TRAINER_BACK_PIC_BRENDAN, },
            [FEMALE] = { TRAINER_PIC_MAY, TRAINER_BACK_PIC_MAY, },
        },

        //! DESC: overworld avatars, consisting of: walking, cycling,
        //! surfing, and underwater. (see include/constants/event_object.h)
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_BRENDAN_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_BRENDAN_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_MAY_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_MAY_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_MAY_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_MAY_UNDERWATER
           },
        },

        //! DESC: overworld anims, consisting of: field move, fishing,
        //! water, and decorating. (see include/constants/event_object.h)
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_BRENDAN_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_MAY_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_MAY_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_MAY_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_MAY_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_MAY_FIELD_MOVE
            },
        },

        //! DESC: head icons gfx&pal for region map
        .iconsRM = { sRegionMapPlayerIcon_BrendanGfx, sRegionMapPlayerIcon_MayGfx },

        //! DESC: head icons gfx&pal for frontier pass
        //! note that frontier pass needs to be in one sprite instead of two,
        //! unlike region map. (probably should split them tbh)
        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_UNUSUAL_RED] = {
        .isHidden = TRUE,
        .prices = { 200, 500 },
        #if MODERN == 1
        .name = COMPOUND_STRING("CLASSIC OUTFIT"),
        .desc = COMPOUND_STRING("A style from a few\nyears ago."),
        #else
        .name = sText_OutfitName_UnusualRed,
        .desc = sText_OutfitDesc_UnusualRed,
        #endif
        .trainerPics = {
            [MALE]   = {TRAINER_PIC_RS_BRENDAN, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN},
            [FEMALE] = {TRAINER_PIC_RS_MAY, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY}
        },
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_BRENDAN_RS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_BRENDAN_RS_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_BRENDAN_RS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_RS_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_MAY_RS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_MAY_RS_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_MAY_RS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_MAY_RS_UNDERWATER
           },
        },
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_BRENDAN_RS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_BRENDAN_RS_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_RS_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_RS_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_BRENDAN_RS_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_MAY_RS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_MAY_RS_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_MAY_RS_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_MAY_RS_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_MAY_RS_FIELD_MOVE
            },
        },
        .iconsRM = { sRegionMapPlayerIcon_RSBrendanGfx, sRegionMapPlayerIcon_RSMayGfx },
        .iconsFP = sFrontierPassPlayerIcons_RSBrendanMay_Gfx,
    },
    [OUTFIT_GENDER_SWAPPED_STANDARD] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = TRUE,

        //! DESC: prices for purchasing them.
        .prices = { 0, 0 },

        //! agbcc doesnt like COMPOUND_STRING on my end
        //! DESC: outfit's name
        #if MODERN == 1
        .name = COMPOUND_STRING("RIVAL DISGUISE"),
        #else
        .name = sText_OutfitName_UsualGreen,
        #endif

        //! DESC: outfit's description
        #if MODERN == 1
        .desc = COMPOUND_STRING("A convincing disguise\nof your rival."),
        #else
        .desc = sText_OutfitDesc_UsualGreen,
        #endif

        //! DESC: trainer front & back pic index
        //! (see include/constants/trainers.h)
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_MAY, TRAINER_BACK_PIC_MAY, },
            [FEMALE] = { TRAINER_PIC_BRENDAN, TRAINER_BACK_PIC_BRENDAN, },
        },

        //! DESC: overworld avatars, consisting of: walking, cycling,
        //! surfing, and underwater. (see include/constants/event_object.h)
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_MAY_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_MAY_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_MAY_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_MAY_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_BRENDAN_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_BRENDAN_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_UNDERWATER
           },
        },

        //! DESC: overworld anims, consisting of: field move, fishing,
        //! water, and decorating. (see include/constants/event_object.h)
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_MAY_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_MAY_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_MAY_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_MAY_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_MAY_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_BRENDAN_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE
            },
        },

        //! DESC: head icons gfx&pal for region map
        .iconsRM = { sRegionMapPlayerIcon_MayGfx, sRegionMapPlayerIcon_BrendanGfx },

        //! DESC: head icons gfx&pal for frontier pass
        //! note that frontier pass needs to be in one sprite instead of two,
        //! unlike region map. (probably should split them tbh)
        .iconsFP = sFrontierPassPlayerIcons_MayBrendan_Gfx,
    },
    [OUTFIT_GENDER_SWAPPED_RED] = {
        .isHidden = TRUE,
        .prices = { 200, 500 },
        #if MODERN == 1
        .name = COMPOUND_STRING("RIVAL DISGUISE 2"),
        .desc = COMPOUND_STRING("A disguise of your\nrival wearing red."),
        #else
        .name = sText_OutfitName_UnusualRed,
        .desc = sText_OutfitDesc_UnusualRed,
        #endif
        .trainerPics = {
            [MALE]   = {TRAINER_PIC_RS_MAY, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY},
            [FEMALE] = {TRAINER_PIC_RS_BRENDAN, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN}
        },
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_MAY_RS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_MAY_RS_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_MAY_RS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_MAY_RS_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_BRENDAN_RS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_BRENDAN_RS_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_BRENDAN_RS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_RS_UNDERWATER
           },
        },
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_MAY_RS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_MAY_RS_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_MAY_RS_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_MAY_RS_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_MAY_RS_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_BRENDAN_RS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_BRENDAN_RS_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_RS_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_RS_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_BRENDAN_RS_FIELD_MOVE
            },
        },
        .iconsRM = { sRegionMapPlayerIcon_RSMayGfx, sRegionMapPlayerIcon_RSBrendanGfx },
        .iconsFP = sFrontierPassPlayerIcons_RSMayBrendan_Gfx,
    },
    [OUTFIT_OLD_MAN] = {
        .isHidden = TRUE,
        .prices = { 200, 500 },
        #if MODERN == 1
        .name = COMPOUND_STRING("OLD MAN DISGUISE"),
        .desc = COMPOUND_STRING("A very convincing old man\nDISGUISE."),
        #else
        .name = sText_OutfitName_UnusualRed,
        .desc = sText_OutfitDesc_UnusualRed,
        #endif
        .trainerPics = {
            [MALE]   = {TRAINER_PIC_OLD_MAN_DISGUISE, TRAINER_BACK_PIC_OLD_MAN_DISGUISE},
            [FEMALE] = {TRAINER_PIC_OLD_MAN_DISGUISE, TRAINER_BACK_PIC_OLD_MAN_DISGUISE}
        },
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_OLD_MAN_DISGUISE_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_OLD_MAN_DISGUISE_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_OLD_MAN_DISGUISE_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_OLD_MAN_DISGUISE_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_OLD_MAN_DISGUISE_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_OLD_MAN_DISGUISE_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_UNDERWATER
           },
        },
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_OLD_MAN_DISGUISE_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_OLD_MAN_DISGUISE_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_OLD_MAN_DISGUISE_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_OLD_MAN_DISGUISE_FIELD_MOVE
            },
        },
        .iconsRM = { sRegionMapPlayerIcon_OldManDisguiseGfx, sRegionMapPlayerIcon_OldManDisguiseGfx },
        .iconsFP = sFrontierPassPlayerIcons_OldManDisguise_Gfx,
    },
};
