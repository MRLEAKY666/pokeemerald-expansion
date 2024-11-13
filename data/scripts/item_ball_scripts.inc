Common_EventScript_FindItem::
	callnative GetItemBallIdAndAmountFromTemplate
	finditem VAR_RESULT VAR_0x8009
	end

Common_EventScript_FindMysteryItem::
	call GenerateRandomItem
	finditem VAR_RESULT 1
	end

GenerateRandomItem::
	random 61
	goto_if_eq VAR_RESULT, 0, ItemZero
	goto_if_eq VAR_RESULT, 1, ItemZero
	goto_if_eq VAR_RESULT, 2, ItemOne
	goto_if_eq VAR_RESULT, 3, ItemTwo
	goto_if_eq VAR_RESULT, 4, ItemThree
	
	goto_if_eq VAR_RESULT, 5, GenerateMysteryMint

	goto_if_eq VAR_RESULT, 6, ItemTwentyFour
	goto_if_eq VAR_RESULT, 7, ItemTwentyFour
	goto_if_eq VAR_RESULT, 8, ItemTwentyFive
	goto_if_eq VAR_RESULT, 9, ItemTwentyFive
	goto_if_eq VAR_RESULT, 10, ItemTwentySix
	goto_if_eq VAR_RESULT, 11, ItemTwentySix
	goto_if_eq VAR_RESULT, 12, ItemTwentySeven
	goto_if_eq VAR_RESULT, 13, ItemTwentySeven
	goto_if_eq VAR_RESULT, 14, ItemTwentyEight
	goto_if_eq VAR_RESULT, 15, ItemTwentyNine
	goto_if_eq VAR_RESULT, 16, ItemThirty
	goto_if_eq VAR_RESULT, 17, ItemThirtyOne
	goto_if_eq VAR_RESULT, 18, ItemThirtyTwo
	goto_if_eq VAR_RESULT, 19, ItemThirtyThree
	goto_if_eq VAR_RESULT, 20, ItemThirtyFour
	goto_if_eq VAR_RESULT, 21, ItemThirtyFive
	goto_if_eq VAR_RESULT, 22, ItemThirtySix
	goto_if_eq VAR_RESULT, 23, ItemThirtySeven
	goto_if_eq VAR_RESULT, 24, ItemThirtyEight
	goto_if_eq VAR_RESULT, 25, ItemThirtyNine
	goto_if_eq VAR_RESULT, 26, ItemFourty
	goto_if_eq VAR_RESULT, 27, ItemFourtyOne
	goto_if_eq VAR_RESULT, 28, ItemFourtyTwo
	goto_if_eq VAR_RESULT, 29, ItemFourtyThree
	goto_if_eq VAR_RESULT, 30, ItemFourtyFour
	goto_if_eq VAR_RESULT, 31, ItemFourtyFive
	goto_if_eq VAR_RESULT, 32, ItemFourtySix
	goto_if_eq VAR_RESULT, 33, ItemFourtySeven
	goto_if_eq VAR_RESULT, 34, ItemFourtyEight
	goto_if_eq VAR_RESULT, 35, ItemFourtyNine
	goto_if_eq VAR_RESULT, 36, ItemFifty
	goto_if_eq VAR_RESULT, 37, ItemFiftyOne
	goto_if_eq VAR_RESULT, 38, ItemFiftyTwo
	goto_if_eq VAR_RESULT, 39, ItemFiftyThree
	goto_if_eq VAR_RESULT, 40, ItemFiftyFour
	goto_if_eq VAR_RESULT, 41, ItemFiftyFive
	goto_if_eq VAR_RESULT, 42, ItemFiftySix
	goto_if_eq VAR_RESULT, 43, ItemFiftySeven
	goto_if_eq VAR_RESULT, 44, ItemFiftyEight
	goto_if_eq VAR_RESULT, 45, ItemFiftyNine
	goto_if_eq VAR_RESULT, 46, ItemSixty
	goto_if_eq VAR_RESULT, 47, ItemSixtyOne
	goto_if_eq VAR_RESULT, 48, ItemSixtyTwo
	goto_if_eq VAR_RESULT, 49, ItemSixtyThree
	goto_if_eq VAR_RESULT, 50, ItemSixtyFour
	goto_if_eq VAR_RESULT, 51, ItemSixtyFive
	goto_if_eq VAR_RESULT, 52, ItemSixtySix
	goto_if_eq VAR_RESULT, 53, ItemSixtySeven
	goto_if_eq VAR_RESULT, 54, ItemSixtyEight
	goto_if_eq VAR_RESULT, 55, ItemSixtyNine
	goto_if_eq VAR_RESULT, 56, ItemSeventy
	goto_if_eq VAR_RESULT, 57, ItemSeventyOne
	goto_if_eq VAR_RESULT, 58, ItemSeventyTwo
	goto_if_eq VAR_RESULT, 59, ItemSeventyNine
	goto_if_eq VAR_RESULT, 60, ItemEighty
	return

ItemZero::
	setvar VAR_RESULT, ITEM_ETHER
	return

ItemOne::
	setvar VAR_RESULT, ITEM_REVIVAL_HERB
	return

ItemTwo::
	setvar VAR_RESULT, ITEM_ABILITY_CAPSULE
	return

ItemThree::
	setvar VAR_RESULT, ITEM_ABILITY_PATCH
	return

ItemTwentyFour::
	setvar VAR_RESULT, ITEM_RARE_CANDY
	return

ItemTwentyFive::
	setvar VAR_RESULT, ITEM_EXP_CANDY_L
	return

ItemTwentySix::
	setvar VAR_RESULT, ITEM_EXP_CANDY_XL
	return

ItemTwentySeven::
	setvar VAR_RESULT, ITEM_BOTTLE_CAP
	return

ItemTwentyEight::
	setvar VAR_RESULT, ITEM_SILK_SCARF
	return

ItemTwentyNine::
	setvar VAR_RESULT, ITEM_CHARCOAL
	return

ItemThirty::
	setvar VAR_RESULT, ITEM_MYSTIC_WATER
	return

ItemThirtyOne::
	setvar VAR_RESULT, ITEM_MAGNET
	return

ItemThirtyTwo::
	setvar VAR_RESULT, ITEM_MIRACLE_SEED
	return

ItemThirtyThree::
	setvar VAR_RESULT, ITEM_NEVER_MELT_ICE
	return

ItemThirtyFour::
	setvar VAR_RESULT, ITEM_BLACK_BELT
	return

ItemThirtyFive::
	setvar VAR_RESULT, ITEM_POISON_BARB
	return

ItemThirtySix::
	setvar VAR_RESULT, ITEM_SOFT_SAND
	return

ItemThirtySeven::
	setvar VAR_RESULT, ITEM_SHARP_BEAK
	return

ItemThirtyEight::
	setvar VAR_RESULT, ITEM_TWISTED_SPOON
	return

ItemThirtyNine::
	setvar VAR_RESULT, ITEM_SILVER_POWDER
	return

ItemFourty::
	setvar VAR_RESULT, ITEM_HARD_STONE
	return

ItemFourtyOne::
	setvar VAR_RESULT, ITEM_SPELL_TAG
	return

ItemFourtyTwo::
	setvar VAR_RESULT, ITEM_DRAGON_FANG
	return

ItemFourtyThree::
	setvar VAR_RESULT, ITEM_BLACK_GLASSES
	return

ItemFourtyFour::
	setvar VAR_RESULT, ITEM_METAL_COAT
	return

ItemFourtyFive::
	setvar VAR_RESULT, ITEM_CHOICE_BAND
	return

ItemFourtySix::
	setvar VAR_RESULT, ITEM_CHOICE_SCARF
	return

ItemFourtySeven::
	setvar VAR_RESULT, ITEM_CHOICE_SPECS
	return

ItemFourtyEight::
	setvar VAR_RESULT, ITEM_ABSORB_BULB
	return

ItemFourtyNine::
	setvar VAR_RESULT, ITEM_CELL_BATTERY
	return

ItemFifty::
	setvar VAR_RESULT, ITEM_LUMINOUS_MOSS
	return

ItemFiftyOne::
	setvar VAR_RESULT, ITEM_SNOWBALL
	return

ItemFiftyTwo::
	setvar VAR_RESULT, ITEM_BRIGHT_POWDER
	return

ItemFiftyThree::
	setvar VAR_RESULT, ITEM_WHITE_HERB
	return

ItemFiftyFour::
	setvar VAR_RESULT, ITEM_QUICK_CLAW
	return

ItemFiftyFive::
	setvar VAR_RESULT, ITEM_KINGS_ROCK
	return

ItemFiftySix::
	setvar VAR_RESULT, ITEM_AMULET_COIN
	return

ItemFiftySeven::
	setvar VAR_RESULT, ITEM_SCOPE_LENS
	return

ItemFiftyEight::
	setvar VAR_RESULT, ITEM_WIDE_LENS
	return

ItemFiftyNine::
	setvar VAR_RESULT, ITEM_EXPERT_BELT
	return

ItemSixty::
	setvar VAR_RESULT, ITEM_LIGHT_CLAY
	return

ItemSixtyOne::
	setvar VAR_RESULT, ITEM_POWER_HERB
	return

ItemSixtyTwo::
	setvar VAR_RESULT, ITEM_FOCUS_SASH
	return

ItemSixtyThree::
	setvar VAR_RESULT, ITEM_ZOOM_LENS
	return

ItemSixtyFour::
	setvar VAR_RESULT, ITEM_BLACK_SLUDGE
	return

ItemSixtyFive::
	setvar VAR_RESULT, ITEM_BIG_ROOT
	return

ItemSixtySix::
	setvar VAR_RESULT, ITEM_EVIOLITE
	return

ItemSixtySeven::
	setvar VAR_RESULT, ITEM_ROCKY_HELMET
	return

ItemSixtyEight::
	setvar VAR_RESULT, ITEM_AIR_BALLOON
	return

ItemSixtyNine::
	setvar VAR_RESULT, ITEM_ASSAULT_VEST
	return

ItemSeventy::
	setvar VAR_RESULT, ITEM_SAFETY_GOGGLES
	return

ItemSeventyOne::
	setvar VAR_RESULT, ITEM_HEAVY_DUTY_BOOTS
	return

ItemSeventyTwo::
	setvar VAR_RESULT, ITEM_LOADED_DICE
	return

ItemSeventyNine::
	setvar VAR_RESULT, ITEM_TOXIC_ORB
	return

ItemEighty::
	setvar VAR_RESULT, ITEM_FLAME_ORB
	return

GenerateMysteryMint::
	random 21
	goto_if_eq VAR_RESULT, 0, MintOne
	goto_if_eq VAR_RESULT, 1, MintTwo
	goto_if_eq VAR_RESULT, 2, MintThree
	goto_if_eq VAR_RESULT, 3, MintFour
	goto_if_eq VAR_RESULT, 4, MintFive
	goto_if_eq VAR_RESULT, 5, MintSix
	goto_if_eq VAR_RESULT, 6, MintSeven
	goto_if_eq VAR_RESULT, 7, MintEight
	goto_if_eq VAR_RESULT, 8, MintNine
	goto_if_eq VAR_RESULT, 9, MintTen
	goto_if_eq VAR_RESULT, 10, MintEleven
	goto_if_eq VAR_RESULT, 11, MintTwelve
	goto_if_eq VAR_RESULT, 12, MintThirteen
	goto_if_eq VAR_RESULT, 13, MintFourteen
	goto_if_eq VAR_RESULT, 14, MintFifteen
	goto_if_eq VAR_RESULT, 15, MintSixteen
	goto_if_eq VAR_RESULT, 16, MintSeventeen
	goto_if_eq VAR_RESULT, 17, MintEighteen
	goto_if_eq VAR_RESULT, 18, MintNineteen
	goto_if_eq VAR_RESULT, 19, MintTwenty
	goto_if_eq VAR_RESULT, 20, MintTwentyOne
	return

MintOne::
	setvar VAR_RESULT, ITEM_LONELY_MINT
	return

MintTwo::
	setvar VAR_RESULT, ITEM_ADAMANT_MINT
	return

MintThree::
	setvar VAR_RESULT, ITEM_NAUGHTY_MINT
	return

MintFour::
	setvar VAR_RESULT, ITEM_BOLD_MINT
	return

MintFive::
	setvar VAR_RESULT, ITEM_IMPISH_MINT
	return

MintSix::
	setvar VAR_RESULT, ITEM_LAX_MINT
	return

MintSeven::
	setvar VAR_RESULT, ITEM_RELAXED_MINT
	return

MintEight::
	setvar VAR_RESULT, ITEM_MODEST_MINT
	return

MintNine::
	setvar VAR_RESULT, ITEM_MILD_MINT
	return

MintTen::
	setvar VAR_RESULT, ITEM_RASH_MINT
	return

MintEleven::
	setvar VAR_RESULT, ITEM_QUIET_MINT
	return

MintTwelve::
	setvar VAR_RESULT, ITEM_CALM_MINT
	return

MintThirteen::
	setvar VAR_RESULT, ITEM_GENTLE_MINT
	return

MintFourteen::
	setvar VAR_RESULT, ITEM_CAREFUL_MINT
	return

MintFifteen::
	setvar VAR_RESULT, ITEM_SASSY_MINT
	return

MintSixteen::
	setvar VAR_RESULT, ITEM_TIMID_MINT
	return

MintSeventeen::
	setvar VAR_RESULT, ITEM_HASTY_MINT
	return

MintEighteen::
	setvar VAR_RESULT, ITEM_JOLLY_MINT
	return

MintNineteen::
	setvar VAR_RESULT, ITEM_NAIVE_MINT
	return

MintTwenty::
	setvar VAR_RESULT, ITEM_SERIOUS_MINT
	return

MintTwentyOne::
	setvar VAR_RESULT, ITEM_BRAVE_MINT
	return
