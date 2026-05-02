# 1 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 2 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_MapScripts::
# 3 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle8_OnTransition
# 4 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.byte 0
# 5 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 6 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_OnTransition:
# 7 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 8 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 9 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 10 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Scroll::
# 11 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	lockall
# 12 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
# 13 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 14 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 15 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 16 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_FoundScroll::
# 17 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
# 18 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 19 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 20 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 21 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Vincent::
# 22 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
# 23 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
# 24 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 25 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 26 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Keira::
# 27 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
# 28 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
# 29 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 30 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 31 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Leroy::
# 32 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
# 33 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
# 34 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 35 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 36 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
# 37 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 38 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "on the door.\p"
# 39 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "“TRICK MASTER I love.”\n"
# 40 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "… … … … … … … …\p"
# 41 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "The lock clicked open!$"
# 42 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 43 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentIntro:
# 44 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Not many TRAINERS have made it\n"
# 45 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "this far.$"
# 46 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 47 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentDefeat:
# 48 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "That must mean you're tough, too…$"
# 49 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 50 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentPostBattle:
# 51 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've beaten the POKéMON LEAGUE\n"
# 52 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "CHAMPION? That's too much!$"
# 53 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 54 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraIntro:
# 55 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Consider yourself lucky to be\n"
# 56 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "battling me!$"
# 57 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 58 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraDefeat:
# 59 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "This isn't right!\n"
# 60 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I can't lose!$"
# 61 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 62 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
# 63 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "It's a miracle that you beat me.\n"
# 64 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You can brag about it.$"
# 65 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 66 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyIntro:
# 67 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've been slugging through the TRICK\n"
# 68 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "HOUSE challenge, too.$"
# 69 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 70 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyDefeat:
# 71 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I see…\n"
# 72 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You possess an extraordinary style.$"
# 73 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"

# 74 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
# 75 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Seeing someone like you should please\n"
# 76 "data//maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "the TRICK MASTER.$"
