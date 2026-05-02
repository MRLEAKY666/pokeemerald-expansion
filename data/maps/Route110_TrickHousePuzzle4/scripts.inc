# 1 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 2 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_MapScripts::
# 3 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle4_OnTransition 
# 4 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.byte 0
# 5 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 6 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_OnTransition:
# 7 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 8 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 9 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 10 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Scroll::
# 11 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	lockall
# 12 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
# 13 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 14 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 15 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 16 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_FoundScroll::
# 17 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
# 18 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 19 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 20 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 21 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Cora::
# 22 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
# 23 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
# 24 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 25 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 26 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Yuji::
# 27 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
# 28 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
# 29 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 30 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 31 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Paula::
# 32 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
# 33 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
# 34 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 35 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 36 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
# 37 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 38 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "on the door.\p"
# 39 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "“TRICK MASTER is cool.”\n"
# 40 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "… … … … … … … …\p"
# 41 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The lock clicked open!$"
# 42 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 43 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraIntro:
# 44 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's too much bother to think this out.\n"
# 45 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I only wanted to battle!$"
# 46 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 47 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraDefeat:
# 48 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Even though I lost, I still like battling\n"
# 49 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the best!$"
# 50 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 51 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraPostBattle:
# 52 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Wouldn't you agree? You would go\n"
# 53 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "anywhere if TRAINERS were there.$"
# 54 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 55 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiIntro:
# 56 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Heh! Boulders like this, I can brush\n"
# 57 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "aside with one finger!$"
# 58 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 59 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiDefeat:
# 60 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I can push boulders, but I can't solve\n"
# 61 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the puzzle…$"
# 62 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 63 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiPostBattle:
# 64 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's not good enough to be brawny…\n"
# 65 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "You have to use your head. Be brainy!$"
# 66 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 67 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaIntro:
# 68 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The TRICK HOUSE is getting trickier,\n"
# 69 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "isn't it?$"
# 70 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 71 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaDefeat:
# 72 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Aaak!$"
# 73 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"

# 74 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
# 75 "data//maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Has anyone made it to the end?$"
