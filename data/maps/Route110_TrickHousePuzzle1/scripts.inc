# 1 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 2 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_MapScripts::
# 3 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
# 4 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.byte 0
# 5 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 6 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_OnLoad:
# 7 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
# 8 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 9 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 10 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 11 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_OpenDoor::
# 12 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 13 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 14 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 15 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Scroll::
# 16 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	lockall
# 17 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
# 18 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 19 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 20 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 21 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_FoundScroll::
# 22 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
# 23 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 24 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 25 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 26 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Sally::
# 27 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
# 28 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
# 29 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 30 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 31 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Eddie::
# 32 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
# 33 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
# 34 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 35 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 36 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Robin::
# 37 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
# 38 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
# 39 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 40 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 41 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
# 42 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 43 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "on the door.\p"
# 44 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "“TRICK MASTER is fabulous.”\n"
# 45 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "… … … … … … … …\p"
# 46 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "The lock clicked open!$"
# 47 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 48 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyIntro:
# 49 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I'll hack and slash my way to victory\n"
# 50 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "with the CUT we just learned!$"
# 51 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 52 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyDefeat:
# 53 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Why are you so serious?$"
# 54 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 55 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyPostBattle:
# 56 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I never get tired of hacking\n"
# 57 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "and slashing!$"
# 58 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 59 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieIntro:
# 60 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I wandered into this weird house\n"
# 61 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "by accident…$"
# 62 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 63 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieDefeat:
# 64 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "And now I've lost…$"
# 65 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 66 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddiePostBattle:
# 67 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost my way, I lost a battle, and I'm\n"
# 68 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "now even more lost… I can't get out…$"
# 69 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 70 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinIntro:
# 71 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who is the TRICK MASTER?$"
# 72 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 73 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinDefeat:
# 74 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost while I was lost in thought!$"
# 75 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"

# 76 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinPostBattle:
# 77 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "You're strong!\n"
# 78 "data//maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who are you?$"
