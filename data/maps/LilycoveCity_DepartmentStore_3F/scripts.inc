# 1 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 2 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts::
# 3 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 4 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 5 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
# 6 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 7 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 8 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 10 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 11 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 13 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 14 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 15 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 16 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
# 17 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 18 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 19 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 20 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 21 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 22 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 23 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PP_UP
# 24 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NONE
# 25 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 26 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 27 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 28 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
# 29 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 30 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 31 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 32 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 33 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_EvoItems
# 34 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 35 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 36 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 37 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 38 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 39 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_EvoItems:
# 40 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 41 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 42 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_METAL_COAT
# 43 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTECTOR
# 44 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 45 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 46 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 47 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_UPGRADE
# 48 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 49 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 50 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NONE
# 51 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 52 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 53 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 54 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
# 55 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 56 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 57 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 58 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
# 59 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 60 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 61 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 62 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman::
# 63 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 64 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 65 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 66 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
# 67 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up POKéMON,\n"
# 68 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 69 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "PROTEIN boosts ATTACK,\n"
# 70 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and CALCIUM raises SP. ATK.$"
# 71 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 72 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
# 73 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my POKéMON to have more\n"
# 74 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 75 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 76 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"
# 77 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 78 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
# 79 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a CARBOS to my POKéMON,\n"
# 80 "data//maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its SPEED went up.$"
