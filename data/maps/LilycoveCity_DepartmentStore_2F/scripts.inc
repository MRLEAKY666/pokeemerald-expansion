# 1 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 2 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_MapScripts::
# 3 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.byte 0
# 4 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 5 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Cook::
# 6 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
# 7 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 8 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 9 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
# 10 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
# 11 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 12 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 13 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
# 14 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
# 15 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 16 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 17 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
# 18 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 19 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 20 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 21 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 22 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
# 23 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 24 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 25 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 26 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 27 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 28 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart1:
# 29 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 30 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 31 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 32 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 33 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NET_BALL
# 34 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 35 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 36 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 37 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 38 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 39 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 40 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 41 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 42 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 43 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 44 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 45 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
# 46 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 47 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 48 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 49 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 50 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
# 51 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 52 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 53 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 54 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 55 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 56 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart2:
# 57 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POTION
# 58 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 59 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 60 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 61 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 62 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 63 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 64 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 65 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 66 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AWAKENING
# 67 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 68 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEL
# 69 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 70 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 71 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 72 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 73 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 74 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 75 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 76 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
# 77 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Learn to use items properly.\n"
# 78 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "That's basic, really.$"
# 79 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 80 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
# 81 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "My husband is waiting at home.\n"
# 82 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "What would make a good gift for him?$"
# 83 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 84 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
# 85 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I'm leaving on a long journey soon.\n"
# 86 "data//maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I need to stock up on items.$"
