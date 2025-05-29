# 1 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 2 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_MapScripts::
# 3 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
# 4 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
# 5 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_HallOfFame_OnTransition
# 6 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.byte 0
# 7 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 8 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnTransition:
# 9 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_HallOfFame_EventScript_ShowChampionSteven
# 10 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_HallOfFame_EventScript_ShowChampionWallace
# 11 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 12 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 13 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_ShowChampionSteven::
# 14 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_STEVEN
# 15 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	return
# 16 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 17 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_ShowChampionWallace::
# 18 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_WALLACE
# 19 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	return
# 20 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 21 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnWarp:
# 22 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
# 23 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 24 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 25 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth::
# 26 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 27 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 28 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 29 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnFrame:
# 30 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
# 31 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 32 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 33 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame::
# 34 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameFirst
# 35 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameSubsequent
# 36 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 37 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 38 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameFirst::
# 39 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	lockall
# 40 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 41 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 42 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 43 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 44 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 45 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 46 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
# 47 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 48 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 49 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 50 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 51 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 52 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 53 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 54 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 55 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
# 56 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 57 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 58 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 59 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 60 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 61 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 62 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 63 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 40
# 64 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 65 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
# 66 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	checkplayergender
# 67 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
# 68 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
# 69 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 70 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 71 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 72 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameSubsequent::
# 73 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	lockall
# 74 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 75 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 76 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 77 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 78 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 79 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 80 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_WelcomeBackHoF, MSGBOX_DEFAULT
# 81 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 82 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 83 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 84 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 85 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 86 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 87 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 88 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 89 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_RecordNewHoF, MSGBOX_DEFAULT
# 90 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 91 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_HALL_OF_FAME_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 92 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 93 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 94 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 95 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 96 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 97 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 40
# 98 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 99 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
# 100 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	checkplayergender
# 101 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
# 102 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
# 103 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 104 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 105 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearMale::
# 106 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 107 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 108 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 109 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 110 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 111 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 112 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 113 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearFemale::
# 114 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 115 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 116 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 117 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 118 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 119 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 120 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 121 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
# 122 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 123 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 124 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 125 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 126 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 127 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 128 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 129 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 130 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
# 131 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 132 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 133 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 134 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 135 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 136 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 137 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 138 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions:
# 139 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "STEVEN: This room…\p"
# 140 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "This is where we keep records of\n"
# 141 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "POKéMON that prevailed through\l"
# 142 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "harsh battles.\p"
# 143 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "It is here that the LEAGUE CHAMPIONS\n"
# 144 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "are honored.$"
# 145 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 146 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_WelcomeBackHoF:
# 147 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: Welcome back, {PLAYER}.\p"
# 148 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "This is where we keep records of\n"
# 149 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "POKéMON that prevailed through\l"
# 150 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "harsh battles.\p"
# 151 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "It is here that the LEAGUE CHAMPIONS\n"
# 152 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "are honored.$"
# 153 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 154 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames:
# 155 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "STEVEN: Come on, let's record your\n"
# 156 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "name as a TRAINER who triumphed over\l"
# 157 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the POKéMON LEAGUE, and the names of\l"
# 158 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the partners who battled with you.$"
# 159 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 160 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_RecordNewHoF:
# 161 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: Let's commemorate your\n"
# 162 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "achievements once again, {PLAYER},\l"
# 163 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "by recording the names of the\l"
# 164 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "partners who battled with you.$"
