# 1 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 2 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_MapScripts::
# 3 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
# 4 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
# 5 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.byte 0
# 6 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 7 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_OnTransition:
# 8 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 9 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	special RotatingGate_InitPuzzle
# 10 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 11 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 12 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_OnWarp:
# 13 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
# 14 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.2byte 0
# 15 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 16 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
# 17 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
# 18 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 19 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 20 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 21 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Scroll::
# 22 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	lockall
# 23 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
# 24 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 25 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 26 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 27 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_FoundScroll::
# 28 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
# 29 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 30 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 31 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 32 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Sophia::
# 33 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
# 34 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
# 35 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 36 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 37 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Benny::
# 38 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
# 39 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
# 40 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 41 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 42 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Sebastian::
# 43 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
# 44 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
# 45 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 46 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 47 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
# 48 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 49 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "on the door.\p"
# 50 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "“TRICK MASTER is my life.”\n"
# 51 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "… … … … … … … …\p"
# 52 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "The lock clicked open!$"
# 53 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 54 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaIntro:
# 55 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "When I heard there was a strange\n"
# 56 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "house, I had to check it out.$"
# 57 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 58 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaDefeat:
# 59 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I've discovered a tough TRAINER!$"
# 60 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 61 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
# 62 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I'm sure having a good time checking\n"
# 63 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "this place out.\p"
# 64 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "It's a challenge I've found worth\n"
# 65 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "repeating!$"
# 66 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 67 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyIntro:
# 68 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Maybe I could get my BIRD POKéMON\n"
# 69 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "to fly over the wall…$"
# 70 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 71 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyDefeat:
# 72 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Gwaaah! I blew it!$"
# 73 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 74 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyPostBattle:
# 75 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Ehehehe… I guess I lost because\n"
# 76 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I was trying to cheat.$"
# 77 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 78 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianIntro:
# 79 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I'm getting dizzy from these rotating\n"
# 80 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "doors…$"
# 81 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 82 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianDefeat:
# 83 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Everything's spinning around and\n"
# 84 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "around. I can't take this anymore…$"
# 85 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"

# 86 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
# 87 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "You don't seem to be affected at all.\n"
# 88 "data//maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Or do you have your poker face on?$"
