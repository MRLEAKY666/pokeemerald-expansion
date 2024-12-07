# 1 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 2 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_MapScripts::
# 3 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.byte 0
# 4 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 5 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_Clerk::
# 6 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	lock
# 7 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	faceplayer
# 8 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
# 9 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	waitmessage
# 10 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	pokemart LavaridgeTown_HerbShop_Pokemart
# 11 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 13 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 14 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 15 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.align 2
# 16 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Pokemart:
# 17 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_ENERGY_POWDER
# 18 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_ENERGY_ROOT
# 19 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_HEAL_POWDER
# 20 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 21 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_TART_APPLE
# 22 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 23 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_PEAT_BLOCK
# 24 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_BLACK_AUGURITE
# 25 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 26 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 27 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_MOON_STONE
# 28 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_SUN_STONE
# 29 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 30 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 31 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 32 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_ICE_STONE
# 33 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 34 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_NONE
# 35 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 36 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 37 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 38 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_ExpertM::
# 39 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
# 40 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 41 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 42 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_OldMan::
# 43 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	lock
# 44 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	faceplayer
# 45 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
# 46 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
# 47 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	giveitem ITEM_CHARCOAL
# 48 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 49 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	setflag FLAG_RECEIVED_CHARCOAL
# 50 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 51 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 52 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 53 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
# 54 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
# 55 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 56 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 57 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 58 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
# 59 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "Welcome to the HERB SHOP, home of\n"
# 60 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "effective and inexpensive medicine!$"
# 61 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 62 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
# 63 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "You've come to look at herbal medicine\n"
# 64 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "in LAVARIDGE?\p"
# 65 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "That's rather commendable.\p"
# 66 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "I like you! Take this!$"
# 67 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 68 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_ExplainCharcoal:
# 69 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "That CHARCOAL I gave you, it's used\n"
# 70 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "for making herbal medicine.\p"
# 71 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It also does wonders when held by\n"
# 72 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "a POKéMON.\p"
# 73 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It intensifies the power of FIRE-type\n"
# 74 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "moves.$"
# 75 "data//maps/LavaridgeTown_HerbShop/scripts.pory"

# 76 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
# 77 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "Herbal medicine works impressively well.\n"
# 78 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "But your POKéMON will dislike you for it.\l"
# 79 "data//maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It must be horribly bitter!$"
