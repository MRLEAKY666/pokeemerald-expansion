Common_EventScript_FindItem::
	callnative GetItemBallIdAndAmountFromTemplate
	finditem VAR_RESULT VAR_0x8009
	end

Common_EventScript_FindMysteryItem::
	call GenerateRandomItem
	finditem VAR_RESULT 1
	end

GenerateRandomItem::
	random 5
	goto_if_eq VAR_RESULT, 0, GenerateMysteryConsumableItem
	goto_if_eq VAR_RESULT, 1, GenerateMysteryTreasure
	goto_if_eq VAR_RESULT, 2, GenerateMysteryHeldItem
	goto_if_eq VAR_RESULT, 3, GenerateMysteryMint
	goto_if_eq VAR_RESULT, 4, GenerateRandomTM
	goto_if_eq VAR_RESULT, 5, GenerateMysteryConsumableItem
	return

GenerateMysteryConsumableItem::
	random 9
	goto_if_eq VAR_RESULT, 0, MysteryConsumableI
	goto_if_eq VAR_RESULT, 1, MysteryConsumableII
	goto_if_eq VAR_RESULT, 2, MysteryConsumableIII
	goto_if_eq VAR_RESULT, 3, MysteryConsumableIV
	goto_if_eq VAR_RESULT, 4, MysteryConsumableV
	goto_if_eq VAR_RESULT, 5, MysteryConsumableVI
	goto_if_eq VAR_RESULT, 6, MysteryConsumableI
	goto_if_eq VAR_RESULT, 7, MysteryConsumableIV
	goto_if_eq VAR_RESULT, 8, MysteryConsumableV
	return

MysteryConsumableI::
	setvar VAR_RESULT, ITEM_ETHER
	return

MysteryConsumableII::
	setvar VAR_RESULT, ITEM_ABILITY_CAPSULE
	return

MysteryConsumableIII::
	setvar VAR_RESULT, ITEM_ABILITY_PATCH
	return

MysteryConsumableIV::
	setvar VAR_RESULT, ITEM_RARE_CANDY
	return

MysteryConsumableV::
	setvar VAR_RESULT, ITEM_EXP_CANDY_L
	return

MysteryConsumableVI::
	setvar VAR_RESULT, ITEM_EXP_CANDY_XL
	return

GenerateMysteryTreasure::
	random 3
	goto_if_eq VAR_RESULT, 0, MysteryTreasureI
	goto_if_eq VAR_RESULT, 1, MysteryTreasureII
	goto_if_eq VAR_RESULT, 2, MysteryTreasureIII
	return

MysteryTreasureI::
	setvar VAR_RESULT, ITEM_BOTTLE_CAP
	return

MysteryTreasureII::
	setvar VAR_RESULT, ITEM_NUGGET
	return

MysteryTreasureIII::
	setvar VAR_RESULT, ITEM_HEART_SCALE
	return

GenerateMysteryHeldItem::
	random 39
	goto_if_eq VAR_RESULT, 0, MysteryHeldI
	goto_if_eq VAR_RESULT, 1, MysteryHeldII
	goto_if_eq VAR_RESULT, 2, MysteryHeldIII
	goto_if_eq VAR_RESULT, 3, MysteryHeldIV
	goto_if_eq VAR_RESULT, 4, MysteryHeldV
	goto_if_eq VAR_RESULT, 5, MysteryHeldVI
	goto_if_eq VAR_RESULT, 6, MysteryHeldVII
	goto_if_eq VAR_RESULT, 7, MysteryHeldVIII
	goto_if_eq VAR_RESULT, 8, MysteryHeldIX
	goto_if_eq VAR_RESULT, 9, MysteryHeldX
	goto_if_eq VAR_RESULT, 10, MysteryHeldXI
	goto_if_eq VAR_RESULT, 11, MysteryHeldXII
	goto_if_eq VAR_RESULT, 12, MysteryHeldXIII
	goto_if_eq VAR_RESULT, 13, MysteryHeldXIV
	goto_if_eq VAR_RESULT, 14, MysteryHeldXV
	goto_if_eq VAR_RESULT, 15, MysteryHeldXVI
	goto_if_eq VAR_RESULT, 16, MysteryHeldXVII
	goto_if_eq VAR_RESULT, 17, MysteryHeldXVIII
	goto_if_eq VAR_RESULT, 18, MysteryHeldXIX
	goto_if_eq VAR_RESULT, 19, MysteryHeldXX
	goto_if_eq VAR_RESULT, 20, MysteryHeldXXI
	goto_if_eq VAR_RESULT, 21, MysteryHeldXXII
	goto_if_eq VAR_RESULT, 22, MysteryHeldXXIII
	goto_if_eq VAR_RESULT, 23, MysteryHeldXXIV
	goto_if_eq VAR_RESULT, 24, MysteryHeldXXV
	goto_if_eq VAR_RESULT, 25, MysteryHeldXXVI
	goto_if_eq VAR_RESULT, 26, MysteryHeldXXVII
	goto_if_eq VAR_RESULT, 27, MysteryHeldXXVIII
	goto_if_eq VAR_RESULT, 28, MysteryHeldXXIX
	goto_if_eq VAR_RESULT, 29, MysteryHeldXXX
	goto_if_eq VAR_RESULT, 30, MysteryHeldXXXI
	goto_if_eq VAR_RESULT, 31, MysteryHeldXXXII
	goto_if_eq VAR_RESULT, 32, MysteryHeldXXXIII
	goto_if_eq VAR_RESULT, 33, MysteryHeldXXXIV
	goto_if_eq VAR_RESULT, 34, MysteryHeldXXXV
	goto_if_eq VAR_RESULT, 35, MysteryHeldXXXVI
	goto_if_eq VAR_RESULT, 36, MysteryHeldXXXVII
	goto_if_eq VAR_RESULT, 37, MysteryHeldXXXVIII
	goto_if_eq VAR_RESULT, 38, MysteryHeldXXXIX
	return

MysteryHeldI::
	setvar VAR_RESULT, ITEM_SILK_SCARF
	return

MysteryHeldII::
	setvar VAR_RESULT, ITEM_CHARCOAL
	return

MysteryHeldIII::
	setvar VAR_RESULT, ITEM_MYSTIC_WATER
	return

MysteryHeldIV::
	setvar VAR_RESULT, ITEM_MAGNET
	return

MysteryHeldV::
	setvar VAR_RESULT, ITEM_MIRACLE_SEED
	return

MysteryHeldVI::
	setvar VAR_RESULT, ITEM_NEVER_MELT_ICE
	return

MysteryHeldVII::
	setvar VAR_RESULT, ITEM_BLACK_BELT
	return

MysteryHeldVIII::
	setvar VAR_RESULT, ITEM_POISON_BARB
	return

MysteryHeldIX::
	setvar VAR_RESULT, ITEM_SOFT_SAND
	return

MysteryHeldX::
	setvar VAR_RESULT, ITEM_SHARP_BEAK
	return

MysteryHeldXI::
	setvar VAR_RESULT, ITEM_TWISTED_SPOON
	return

MysteryHeldXII::
	setvar VAR_RESULT, ITEM_SILVER_POWDER
	return

MysteryHeldXIII::
	setvar VAR_RESULT, ITEM_HARD_STONE
	return

MysteryHeldXIV::
	setvar VAR_RESULT, ITEM_SPELL_TAG
	return

MysteryHeldXV::
	setvar VAR_RESULT, ITEM_DRAGON_FANG
	return

MysteryHeldXVI::
	setvar VAR_RESULT, ITEM_BLACK_GLASSES
	return

MysteryHeldXVII::
	setvar VAR_RESULT, ITEM_METAL_COAT
	return

MysteryHeldXVIII::
	setvar VAR_RESULT, ITEM_CHOICE_BAND
	return

MysteryHeldXIX::
	setvar VAR_RESULT, ITEM_CHOICE_SCARF
	return

MysteryHeldXX::
	setvar VAR_RESULT, ITEM_CHOICE_SPECS
	return

MysteryHeldXXI::
	setvar VAR_RESULT, ITEM_CELL_BATTERY
	return

MysteryHeldXXII::
	setvar VAR_RESULT, ITEM_BRIGHT_POWDER
	return

MysteryHeldXXIII::
	setvar VAR_RESULT, ITEM_QUICK_CLAW
	return

MysteryHeldXXIV::
	setvar VAR_RESULT, ITEM_KINGS_ROCK
	return

MysteryHeldXXV::
	setvar VAR_RESULT, ITEM_AMULET_COIN
	return

MysteryHeldXXVI::
	setvar VAR_RESULT, ITEM_SCOPE_LENS
	return

MysteryHeldXXVII::
	setvar VAR_RESULT, ITEM_WIDE_LENS
	return

MysteryHeldXXVIII::
	setvar VAR_RESULT, ITEM_LIGHT_CLAY
	return

MysteryHeldXXIX::
	setvar VAR_RESULT, ITEM_FOCUS_SASH
	return

MysteryHeldXXX::
	setvar VAR_RESULT, ITEM_ZOOM_LENS
	return

MysteryHeldXXXI::
	setvar VAR_RESULT, ITEM_EVIOLITE
	return

MysteryHeldXXXII::
	setvar VAR_RESULT, ITEM_ROCKY_HELMET
	return

MysteryHeldXXXIII::
	setvar VAR_RESULT, ITEM_AIR_BALLOON
	return

MysteryHeldXXXIV::
	setvar VAR_RESULT, ITEM_ASSAULT_VEST
	return

MysteryHeldXXXV::
	setvar VAR_RESULT, ITEM_SAFETY_GOGGLES
	return

MysteryHeldXXXVI::
	setvar VAR_RESULT, ITEM_HEAVY_DUTY_BOOTS
	return

MysteryHeldXXXVII::
	setvar VAR_RESULT, ITEM_LOADED_DICE
	return

MysteryHeldXXXVIII::
	setvar VAR_RESULT, ITEM_TOXIC_ORB
	return

MysteryHeldXXXIX::
	setvar VAR_RESULT, ITEM_FLAME_ORB
	return

GenerateMysteryMint::
	random 21
	goto_if_eq VAR_RESULT, 0, MintI
	goto_if_eq VAR_RESULT, 1, MintII
	goto_if_eq VAR_RESULT, 2, MintIII
	goto_if_eq VAR_RESULT, 3, MintIV
	goto_if_eq VAR_RESULT, 4, MintV
	goto_if_eq VAR_RESULT, 5, MintVI
	goto_if_eq VAR_RESULT, 6, MintVII
	goto_if_eq VAR_RESULT, 7, MintVIII
	goto_if_eq VAR_RESULT, 8, MintIX
	goto_if_eq VAR_RESULT, 9, MintX
	goto_if_eq VAR_RESULT, 10, MintXI
	goto_if_eq VAR_RESULT, 11, MintXII
	goto_if_eq VAR_RESULT, 12, MintXIII
	goto_if_eq VAR_RESULT, 13, MintXIV
	goto_if_eq VAR_RESULT, 14, MintXV
	goto_if_eq VAR_RESULT, 15, MintXVI
	goto_if_eq VAR_RESULT, 16, MintXVII
	goto_if_eq VAR_RESULT, 17, MintXVIII
	goto_if_eq VAR_RESULT, 18, MintXIX
	goto_if_eq VAR_RESULT, 19, MintXX
	goto_if_eq VAR_RESULT, 20, MintXXI
	goto_if_eq VAR_RESULT, 20, MintXXII
	return

MintI::
	setvar VAR_RESULT, ITEM_LONELY_MINT
	return

MintII::
	setvar VAR_RESULT, ITEM_ADAMANT_MINT
	return

MintIII::
	setvar VAR_RESULT, ITEM_NAUGHTY_MINT
	return

MintIV::
	setvar VAR_RESULT, ITEM_BOLD_MINT
	return

MintV::
	setvar VAR_RESULT, ITEM_IMPISH_MINT
	return

MintVI::
	setvar VAR_RESULT, ITEM_LAX_MINT
	return

MintVII::
	setvar VAR_RESULT, ITEM_RELAXED_MINT
	return

MintVIII::
	setvar VAR_RESULT, ITEM_MODEST_MINT
	return

MintIX::
	setvar VAR_RESULT, ITEM_MILD_MINT
	return

MintX::
	setvar VAR_RESULT, ITEM_RASH_MINT
	return

MintXI::
	setvar VAR_RESULT, ITEM_QUIET_MINT
	return

MintXII::
	setvar VAR_RESULT, ITEM_CALM_MINT
	return

MintXIII::
	setvar VAR_RESULT, ITEM_GENTLE_MINT
	return

MintXIV::
	setvar VAR_RESULT, ITEM_CAREFUL_MINT
	return

MintXV::
	setvar VAR_RESULT, ITEM_SASSY_MINT
	return

MintXVI::
	setvar VAR_RESULT, ITEM_TIMID_MINT
	return

MintXVII::
	setvar VAR_RESULT, ITEM_HASTY_MINT
	return

MintXVIII::
	setvar VAR_RESULT, ITEM_JOLLY_MINT
	return

MintXIX::
	setvar VAR_RESULT, ITEM_NAIVE_MINT
	return

MintXX::
	setvar VAR_RESULT, ITEM_SERIOUS_MINT
	return

MintXXI::
	setvar VAR_RESULT, ITEM_BRAVE_MINT
	return

MintXXII::
	setvar VAR_RESULT, ITEM_REVIVAL_HERB
	return

Common_EventScript_FindMysteryTM::
	call GenerateRandomTM
	finditem VAR_RESULT 1
	end

GenerateRandomTM::
	random 69
	goto_if_eq VAR_RESULT, 0, MysteryTMI
	goto_if_eq VAR_RESULT, 1, MysteryTMII
	goto_if_eq VAR_RESULT, 2, MysteryTMIII
	goto_if_eq VAR_RESULT, 3, MysteryTMIV
	goto_if_eq VAR_RESULT, 4, MysteryTMV
	goto_if_eq VAR_RESULT, 5, MysteryTMVI
	goto_if_eq VAR_RESULT, 6, MysteryTMVII
	goto_if_eq VAR_RESULT, 7, MysteryTMVIII
	goto_if_eq VAR_RESULT, 8, MysteryTMIX
	goto_if_eq VAR_RESULT, 9, MysteryTMX
	goto_if_eq VAR_RESULT, 10, MysteryTMXI
	goto_if_eq VAR_RESULT, 11, MysteryTMXII
	goto_if_eq VAR_RESULT, 12, MysteryTMXIII
	goto_if_eq VAR_RESULT, 13, MysteryTMXIV
	goto_if_eq VAR_RESULT, 14, MysteryTMXV
	goto_if_eq VAR_RESULT, 15, MysteryTMXVI
	goto_if_eq VAR_RESULT, 16, MysteryTMXVII
	goto_if_eq VAR_RESULT, 17, MysteryTMXVIII
	goto_if_eq VAR_RESULT, 18, MysteryTMXIX
	goto_if_eq VAR_RESULT, 19, MysteryTMXX
	goto_if_eq VAR_RESULT, 20, MysteryTMXXI
	goto_if_eq VAR_RESULT, 21, MysteryTMXXII
	goto_if_eq VAR_RESULT, 22, MysteryTMXXIII
	goto_if_eq VAR_RESULT, 23, MysteryTMXXIV
	goto_if_eq VAR_RESULT, 24, MysteryTMXXV
	goto_if_eq VAR_RESULT, 25, MysteryTMXXVI
	goto_if_eq VAR_RESULT, 26, MysteryTMXXVII
	goto_if_eq VAR_RESULT, 27, MysteryTMXXVIII
	goto_if_eq VAR_RESULT, 28, MysteryTMXXIX
	goto_if_eq VAR_RESULT, 29, MysteryTMXXX
	goto_if_eq VAR_RESULT, 30, MysteryTMXXXI
	goto_if_eq VAR_RESULT, 31, MysteryTMXXXII
	goto_if_eq VAR_RESULT, 32, MysteryTMXXXIII
	goto_if_eq VAR_RESULT, 33, MysteryTMXXXIV
	goto_if_eq VAR_RESULT, 34, MysteryTMXXXV
	goto_if_eq VAR_RESULT, 35, MysteryTMXXXVI
	goto_if_eq VAR_RESULT, 36, MysteryTMXXXVII
	goto_if_eq VAR_RESULT, 37, MysteryTMXXXVIII
	goto_if_eq VAR_RESULT, 38, MysteryTMXXXIX
	goto_if_eq VAR_RESULT, 39, MysteryTMXL
	goto_if_eq VAR_RESULT, 40, MysteryTMXLI
	goto_if_eq VAR_RESULT, 41, MysteryTMXLII
	goto_if_eq VAR_RESULT, 42, MysteryTMXLIII
	goto_if_eq VAR_RESULT, 43, MysteryTMXLIV
	goto_if_eq VAR_RESULT, 44, MysteryTMXLV
	goto_if_eq VAR_RESULT, 45, MysteryTMXLVI
	goto_if_eq VAR_RESULT, 46, MysteryTMXLVII
	goto_if_eq VAR_RESULT, 47, MysteryTMXLVIII
	goto_if_eq VAR_RESULT, 48, MysteryTMXLIX
	goto_if_eq VAR_RESULT, 49, MysteryTML
	goto_if_eq VAR_RESULT, 50, MysteryTMLI
	goto_if_eq VAR_RESULT, 51, MysteryTMLII
	goto_if_eq VAR_RESULT, 52, MysteryTMLIII
	goto_if_eq VAR_RESULT, 53, MysteryTMLIV
	goto_if_eq VAR_RESULT, 54, MysteryTMLV
	goto_if_eq VAR_RESULT, 55, MysteryTMLVI
	goto_if_eq VAR_RESULT, 56, MysteryTMLVII
	goto_if_eq VAR_RESULT, 57, MysteryTMLVIII
	goto_if_eq VAR_RESULT, 58, MysteryTMLIX
	goto_if_eq VAR_RESULT, 59, MysteryTMLX
	goto_if_eq VAR_RESULT, 60, MysteryTMLXI
	goto_if_eq VAR_RESULT, 61, MysteryTMLXII
	goto_if_eq VAR_RESULT, 62, MysteryTMLXIII
	goto_if_eq VAR_RESULT, 63, MysteryTMLXIV
	goto_if_eq VAR_RESULT, 64, MysteryTMLXV
	goto_if_eq VAR_RESULT, 65, MysteryTMLXVI
	goto_if_eq VAR_RESULT, 66, MysteryTMLXVII
	goto_if_eq VAR_RESULT, 67, MysteryTMLXVIII
	goto_if_eq VAR_RESULT, 68, MysteryTMLXIX

MysteryTMI::
	setvar VAR_RESULT, ITEM_TM_FOCUS_PUNCH
	return

MysteryTMII::
	setvar VAR_RESULT, ITEM_TM_DRAGON_CLAW
	return

MysteryTMIII::
	setvar VAR_RESULT, ITEM_TM_WATER_PULSE
	return

MysteryTMIV::
	setvar VAR_RESULT, ITEM_TM_CALM_MIND
	return

MysteryTMV::
	setvar VAR_RESULT, ITEM_TM_ROAR
	return

MysteryTMVI::
	setvar VAR_RESULT, ITEM_TM_TOXIC
	return

MysteryTMVII::
	setvar VAR_RESULT, ITEM_TM_HAIL
	return

MysteryTMVIII::
	setvar VAR_RESULT, ITEM_TM_BULK_UP
	return

MysteryTMIX::
	setvar VAR_RESULT, ITEM_TM_BULLET_SEED
	return

MysteryTMX::
	setvar VAR_RESULT, ITEM_TM_HIDDEN_POWER
	return

MysteryTMXI::
	setvar VAR_RESULT, ITEM_TM_SUNNY_DAY
	return

MysteryTMXII::
	setvar VAR_RESULT, ITEM_TM_TAUNT
	return

MysteryTMXIII::
	setvar VAR_RESULT, ITEM_TM_ICE_BEAM
	return

MysteryTMXIV::
	setvar VAR_RESULT, ITEM_TM_BLIZZARD
	return

MysteryTMXV::
	setvar VAR_RESULT, ITEM_TM_HYPER_BEAM
	return

MysteryTMXVI::
	setvar VAR_RESULT, ITEM_TM_LIGHT_SCREEN
	return

MysteryTMXVII::
	setvar VAR_RESULT, ITEM_TM_PROTECT
	return

MysteryTMXVIII::
	setvar VAR_RESULT, ITEM_TM_RAIN_DANCE
	return

MysteryTMXIX::
	setvar VAR_RESULT, ITEM_TM_GIGA_DRAIN
	return

MysteryTMXX::
	setvar VAR_RESULT, ITEM_TM_SAFEGUARD
	return

MysteryTMXXI::
	setvar VAR_RESULT, ITEM_TM_FRUSTRATION
	return

MysteryTMXXII::
	setvar VAR_RESULT, ITEM_TM_SOLAR_BEAM
	return

MysteryTMXXIII::
	setvar VAR_RESULT, ITEM_TM_IRON_TAIL
	return

MysteryTMXXIV::
	setvar VAR_RESULT, ITEM_TM_THUNDERBOLT
	return

MysteryTMXXV::
	setvar VAR_RESULT, ITEM_TM_THUNDER
	return

MysteryTMXXVI::
	setvar VAR_RESULT, ITEM_TM_EARTHQUAKE
	return

MysteryTMXXVII::
	setvar VAR_RESULT, ITEM_TM_RETURN
	return

MysteryTMXXVIII::
	setvar VAR_RESULT, ITEM_TM_DIG
	return

MysteryTMXXIX::
	setvar VAR_RESULT, ITEM_TM_PSYCHIC
	return

MysteryTMXXX::
	setvar VAR_RESULT, ITEM_TM_SHADOW_BALL
	return

MysteryTMXXXI::
	setvar VAR_RESULT, ITEM_TM_BRICK_BREAK
	return

MysteryTMXXXII::
	setvar VAR_RESULT, ITEM_TM_DOUBLE_TEAM
	return

MysteryTMXXXIII::
	setvar VAR_RESULT, ITEM_TM_REFLECT
	return

MysteryTMXXXIV::
	setvar VAR_RESULT, ITEM_TM_SHOCK_WAVE
	return

MysteryTMXXXV::
	setvar VAR_RESULT, ITEM_TM_FLAMETHROWER
	return

MysteryTMXXXVI::
	setvar VAR_RESULT, ITEM_TM_SLUDGE_BOMB
	return

MysteryTMXXXVII::
	setvar VAR_RESULT, ITEM_TM_SANDSTORM
	return

MysteryTMXXXVIII::
	setvar VAR_RESULT, ITEM_TM_FIRE_BLAST
	return

MysteryTMXXXIX::
	setvar VAR_RESULT, ITEM_TM_ROCK_TOMB
	return

MysteryTMXL::
	setvar VAR_RESULT, ITEM_TM_AERIAL_ACE
	return

MysteryTMXLI::
	setvar VAR_RESULT, ITEM_TM_TORMENT
	return

MysteryTMXLII::
	setvar VAR_RESULT, ITEM_TM_FACADE
	return

MysteryTMXLIII::
	setvar VAR_RESULT, ITEM_TM_SECRET_POWER
	return

MysteryTMXLIV::
	setvar VAR_RESULT, ITEM_TM_REST
	return

MysteryTMXLV::
	setvar VAR_RESULT, ITEM_TM_ATTRACT
	return

MysteryTMXLVI::
	setvar VAR_RESULT, ITEM_TM_THIEF
	return

MysteryTMXLVII::
	setvar VAR_RESULT, ITEM_TM_STEEL_WING
	return

MysteryTMXLVIII::
	setvar VAR_RESULT, ITEM_TM_SKILL_SWAP
	return

MysteryTMXLIX::
	setvar VAR_RESULT, ITEM_TM_SNATCH
	return

MysteryTML::
	setvar VAR_RESULT, ITEM_TM_OVERHEAT
	return

MysteryTMLI::
	setvar VAR_RESULT, ITEM_TM_PSYSHOCK
	return

MysteryTMLII::
	setvar VAR_RESULT, ITEM_TM_SMACK_DOWN
	return

MysteryTMLIII::
	setvar VAR_RESULT, ITEM_TM_FLAME_CHARGE
	return

MysteryTMLIV::
	setvar VAR_RESULT, ITEM_TM_ENERGY_BALL
	return

MysteryTMLV::
	setvar VAR_RESULT, ITEM_TM_FALSE_SWIPE
	return

MysteryTMLVI::
	setvar VAR_RESULT, ITEM_TM_SCALD
	return

MysteryTMLVII::
	setvar VAR_RESULT, ITEM_TM_CHARGE_BEAM
	return

MysteryTMLVIII::
	setvar VAR_RESULT, ITEM_TM_WILL_O_WISP
	return

MysteryTMLIX::
	setvar VAR_RESULT, ITEM_TM_ACROBATICS
	return

MysteryTMLX::
	setvar VAR_RESULT, ITEM_TM_SHADOW_CLAW
	return

MysteryTMLXI::
	setvar VAR_RESULT, ITEM_TM_ROCK_POLISH
	return

MysteryTMLXII::
	setvar VAR_RESULT, ITEM_TM_VOLT_SWITCH
	return

MysteryTMLXIII::
	setvar VAR_RESULT, ITEM_TM_U_TURN
	return

MysteryTMLXIV::
	setvar VAR_RESULT, ITEM_TM_THUNDER_WAVE
	return

MysteryTMLXV::
	setvar VAR_RESULT, ITEM_TM_DRAGON_TAIL
	return

MysteryTMLXVI::
	setvar VAR_RESULT, ITEM_TM_GRASS_KNOT
	return

MysteryTMLXVII::
	setvar VAR_RESULT, ITEM_TM_FLASH_CANNON
	return

MysteryTMLXVIII::
	setvar VAR_RESULT, ITEM_TM_TRICK_ROOM
	return

MysteryTMLXIX::
	setvar VAR_RESULT, ITEM_TM_WILD_CHARGE
	return