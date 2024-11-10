Common_EventScript_FindItem::
	callnative GetItemBallIdAndAmountFromTemplate
	finditem VAR_RESULT VAR_0x8009
	end

Common_EventScript_FindMysteryItem::
	call GenerateRandomItem
	finditem VAR_RESULT 1
	end

GenerateRandomItem::
	random 79
	goto_if_eq VAR_RESULT, 0, ItemZero
	goto_if_eq VAR_RESULT, 74, ItemZero
	goto_if_eq VAR_RESULT, 1, ItemOne
	goto_if_eq VAR_RESULT, 2, ItemTwo
	goto_if_eq VAR_RESULT, 3, ItemThree
	goto_if_eq VAR_RESULT, 4, ItemFour
	goto_if_eq VAR_RESULT, 5, ItemFive
	goto_if_eq VAR_RESULT, 6, ItemSix
	goto_if_eq VAR_RESULT, 7, ItemSeven
	goto_if_eq VAR_RESULT, 8, ItemEight
	goto_if_eq VAR_RESULT, 9, ItemNine
	goto_if_eq VAR_RESULT, 10, ItemTen
	goto_if_eq VAR_RESULT, 11, ItemEleven
	goto_if_eq VAR_RESULT, 12, ItemTwelve
	goto_if_eq VAR_RESULT, 13, ItemThirteen
	goto_if_eq VAR_RESULT, 14, ItemFourteen
	goto_if_eq VAR_RESULT, 15, ItemFifteen
	goto_if_eq VAR_RESULT, 16, ItemSixteen
	goto_if_eq VAR_RESULT, 17, ItemSeventeen
	goto_if_eq VAR_RESULT, 18, ItemEighteen
	goto_if_eq VAR_RESULT, 19, ItemNineteen
	goto_if_eq VAR_RESULT, 20, ItemTwenty
	goto_if_eq VAR_RESULT, 21, ItemTwentyOne
	goto_if_eq VAR_RESULT, 22, ItemTwentyTwo
	goto_if_eq VAR_RESULT, 23, ItemTwentyThree
	goto_if_eq VAR_RESULT, 24, ItemTwentyFour
	goto_if_eq VAR_RESULT, 75, ItemTwentyFour
	goto_if_eq VAR_RESULT, 25, ItemTwentyFive
	goto_if_eq VAR_RESULT, 76, ItemTwentyFive
	goto_if_eq VAR_RESULT, 26, ItemTwentySix
	goto_if_eq VAR_RESULT, 77, ItemTwentySix
	goto_if_eq VAR_RESULT, 27, ItemTwentySeven
	goto_if_eq VAR_RESULT, 78, ItemTwentySeven
	goto_if_eq VAR_RESULT, 28, ItemTwentyEight
	goto_if_eq VAR_RESULT, 29, ItemTwentyNine
	goto_if_eq VAR_RESULT, 30, ItemThirty
	goto_if_eq VAR_RESULT, 31, ItemThirtyOne
	goto_if_eq VAR_RESULT, 32, ItemThirtyTwo
	goto_if_eq VAR_RESULT, 33, ItemThirtyThree
	goto_if_eq VAR_RESULT, 34, ItemThirtyFour
	goto_if_eq VAR_RESULT, 35, ItemThirtyFive
	goto_if_eq VAR_RESULT, 36, ItemThirtySix
	goto_if_eq VAR_RESULT, 37, ItemThirtySeven
	goto_if_eq VAR_RESULT, 38, ItemThirtyEight
	goto_if_eq VAR_RESULT, 39, ItemThirtyNine
	goto_if_eq VAR_RESULT, 40, ItemFourty
	goto_if_eq VAR_RESULT, 41, ItemFourtyOne
	goto_if_eq VAR_RESULT, 42, ItemFourtyTwo
	goto_if_eq VAR_RESULT, 43, ItemFourtyThree
	goto_if_eq VAR_RESULT, 44, ItemFourtyFour
	goto_if_eq VAR_RESULT, 45, ItemFourtyFive
	goto_if_eq VAR_RESULT, 46, ItemFourtySix
	goto_if_eq VAR_RESULT, 47, ItemFourtySeven
	goto_if_eq VAR_RESULT, 48, ItemFourtyEight
	goto_if_eq VAR_RESULT, 49, ItemFourtyNine
	goto_if_eq VAR_RESULT, 50, ItemFifty
	goto_if_eq VAR_RESULT, 51, ItemFiftyOne
	goto_if_eq VAR_RESULT, 52, ItemFiftyTwo
	goto_if_eq VAR_RESULT, 53, ItemFiftyThree
	goto_if_eq VAR_RESULT, 54, ItemFiftyFour
	goto_if_eq VAR_RESULT, 55, ItemFiftyFive
	goto_if_eq VAR_RESULT, 56, ItemFiftySix
	goto_if_eq VAR_RESULT, 57, ItemFiftySeven
	goto_if_eq VAR_RESULT, 58, ItemFiftyEight
	goto_if_eq VAR_RESULT, 59, ItemFiftyNine
	goto_if_eq VAR_RESULT, 60, ItemSixty
	goto_if_eq VAR_RESULT, 61, ItemSixtyOne
	goto_if_eq VAR_RESULT, 62, ItemSixtyTwo
	goto_if_eq VAR_RESULT, 63, ItemSixtyThree
	goto_if_eq VAR_RESULT, 64, ItemSixtyFour
	goto_if_eq VAR_RESULT, 65, ItemSixtyFive
	goto_if_eq VAR_RESULT, 66, ItemSixtySix
	goto_if_eq VAR_RESULT, 67, ItemSixtySeven
	goto_if_eq VAR_RESULT, 68, ItemSixtyEight
	goto_if_eq VAR_RESULT, 69, ItemSixtyNine
	goto_if_eq VAR_RESULT, 70, ItemSeventy
	goto_if_eq VAR_RESULT, 71, ItemSeventyOne
	goto_if_eq VAR_RESULT, 72, ItemSeventyTwo
	goto_if_eq VAR_RESULT, 73, ItemSeventyThree
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

ItemFour::
	setvar VAR_RESULT, ITEM_LONELY_MINT
	return

ItemFive::
	setvar VAR_RESULT, ITEM_ADAMANT_MINT
	return

ItemSix::
	setvar VAR_RESULT, ITEM_NAUGHTY_MINT
	return

ItemSeven::
	setvar VAR_RESULT, ITEM_BOLD_MINT
	return

ItemEight::
	setvar VAR_RESULT, ITEM_IMPISH_MINT
	return

ItemNine::
	setvar VAR_RESULT, ITEM_LAX_MINT
	return

ItemTen::
	setvar VAR_RESULT, ITEM_RELAXED_MINT
	return

ItemEleven::
	setvar VAR_RESULT, ITEM_MODEST_MINT
	return

ItemTwelve::
	setvar VAR_RESULT, ITEM_MILD_MINT
	return

ItemThirteen::
	setvar VAR_RESULT, ITEM_RASH_MINT
	return

ItemFourteen::
	setvar VAR_RESULT, ITEM_QUIET_MINT
	return

ItemFifteen::
	setvar VAR_RESULT, ITEM_CALM_MINT
	return

ItemSixteen::
	setvar VAR_RESULT, ITEM_GENTLE_MINT
	return

ItemSeventeen::
	setvar VAR_RESULT, ITEM_CAREFUL_MINT
	return

ItemEighteen::
	setvar VAR_RESULT, ITEM_SASSY_MINT
	return

ItemNineteen::
	setvar VAR_RESULT, ITEM_TIMID_MINT
	return

ItemTwenty::
	setvar VAR_RESULT, ITEM_HASTY_MINT
	return

ItemTwentyOne::
	setvar VAR_RESULT, ITEM_JOLLY_MINT
	return

ItemTwentyTwo::
	setvar VAR_RESULT, ITEM_NAIVE_MINT
	return

ItemTwentyThree::
	setvar VAR_RESULT, ITEM_SERIOUS_MINT
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

ItemSeventyThree::
	setvar VAR_RESULT, ITEM_BRAVE_MINT
	return
