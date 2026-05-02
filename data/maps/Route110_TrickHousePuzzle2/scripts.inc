# 1 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 2 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_MapScripts::
# 3 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
# 4 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
# 5 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.byte 0
# 6 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 7 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_OnResume:
# 8 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle2_EventScript_PressButton1
# 9 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle2_EventScript_PressButton2
# 10 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq VAR_TEMP_3, 1, Route110_TrickHousePuzzle2_EventScript_PressButton3
# 11 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq VAR_TEMP_4, 1, Route110_TrickHousePuzzle2_EventScript_PressButton4
# 12 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 13 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 14 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_OnTransition:
# 15 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 16 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_1, 0
# 17 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_2, 0
# 18 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_3, 0
# 19 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_4, 0
# 20 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 21 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 22 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Scroll::
# 23 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 24 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle2_EventScript_FoundScroll
# 25 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 26 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 27 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 28 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_FoundScroll::
# 29 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
# 30 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 31 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 32 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 33 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button1::
# 34 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 35 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_1, 1
# 36 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 37 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
# 38 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 39 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 40 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 41 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 42 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button2::
# 43 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 44 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_2, 1
# 45 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 46 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
# 47 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 48 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 49 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 50 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 51 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button3::
# 52 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 53 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_3, 1
# 54 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 55 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
# 56 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 57 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 58 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 59 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 60 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button4::
# 61 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 62 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_4, 1
# 63 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 64 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
# 65 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 66 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 67 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 68 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 69 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton1::
# 70 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 71 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
# 72 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 73 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 74 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton2::
# 75 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 76 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
# 77 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 78 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 79 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton3::
# 80 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 81 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
# 82 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 83 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 84 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton4::
# 85 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 86 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
# 87 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 88 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 89 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Ted::
# 90 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
# 91 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
# 92 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 93 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 94 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Paul::
# 95 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
# 96 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
# 97 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 98 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 99 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Georgia::
# 100 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
# 101 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
# 102 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 103 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 104 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
# 105 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 106 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "on the door.\p"
# 107 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "“TRICK MASTER is smart.”\n"
# 108 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "… … … … … … … …\p"
# 109 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "The lock clicked open!$"
# 110 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 111 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedIntro:
# 112 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Which switch closes which hole?$"
# 113 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 114 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedDefeat:
# 115 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "After that battle, I'm even more\n"
# 116 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "confused!$"
# 117 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 118 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedPostBattle:
# 119 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Can I get you to push all the buttons\n"
# 120 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "for me?$"
# 121 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 122 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulIntro:
# 123 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Oh! You're on your second TRICK HOUSE\n"
# 124 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "challenge!$"
# 125 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 126 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulDefeat:
# 127 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "You're good at battling too?$"
# 128 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 129 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulPostBattle:
# 130 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "The TRICK MASTER rigged all the tricks\n"
# 131 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "in this house all by himself.$"
# 132 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 133 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaIntro:
# 134 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "I want to make my own GYM one day.\n"
# 135 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "So, I'm studying how to set traps.$"
# 136 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 137 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaDefeat:
# 138 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "I didn't study battling enough!$"
# 139 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"

# 140 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle:
# 141 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "You're strong, aren't you?\n"
# 142 "data//maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Maybe even enough to be a GYM LEADER!$"
