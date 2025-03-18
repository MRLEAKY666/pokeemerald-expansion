# 1 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 2 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
.set LOCALID_CHAMPION, 1
# 3 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 4 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_MapScripts::
# 5 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_OnFrame
# 6 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_OnWarp
# 7 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_HallOfFame_OnTransition
# 8 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.byte 0
# 9 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 10 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnTransition:
# 11 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_HallOfFame_EventScript_ShowChampionSteven
# 12 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_HallOfFame_EventScript_ShowChampionWallace
# 13 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 14 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 15 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_ShowChampionSteven::
# 16 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_STEVEN
# 17 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	return
# 18 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 19 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_ShowChampionWallace::
# 20 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_WALLACE
# 21 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	return
# 22 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 23 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnWarp:
# 24 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth
# 25 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 26 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 27 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_TurnPlayerNorth::
# 28 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 29 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 30 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 31 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_OnFrame:
# 32 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame
# 33 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.2byte 0
# 34 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 35 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame::
# 36 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameFirst
# 37 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameSubsequent
# 38 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 39 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 40 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameFirst::
# 41 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	lockall
# 42 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 43 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 44 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 45 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 46 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 47 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 48 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions, MSGBOX_DEFAULT
# 49 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 50 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 51 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 52 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 53 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 54 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 55 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 56 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 57 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames, MSGBOX_DEFAULT
# 58 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 59 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 60 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 61 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 62 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 63 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 64 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 65 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 40
# 66 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 67 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
# 68 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	checkplayergender
# 69 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
# 70 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
# 71 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 72 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 73 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 74 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_EnterHallOfFameSubsequent::
# 75 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	lockall
# 76 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 77 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
# 78 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 79 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 80 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 81 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 82 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_WelcomeBackHoF, MSGBOX_DEFAULT
# 83 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 84 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 85 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2
# 86 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 87 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 88 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterRight
# 89 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 90 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 91 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	msgbox EverGrandeCity_HallOfFame_Text_RecordNewHoF, MSGBOX_DEFAULT
# 92 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	closemessage
# 93 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 94 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 95 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitmovement 0
# 96 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 20
# 97 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 98 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 99 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	delay 40
# 100 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 101 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
# 102 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	checkplayergender
# 103 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_HallOfFame_EventScript_GameClearMale
# 104 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_HallOfFame_EventScript_GameClearFemale
# 105 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 106 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 107 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearMale::
# 108 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 109 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 110 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 111 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 112 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 113 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 114 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 115 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_EventScript_GameClearFemale::
# 116 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 117 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 118 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	special GameClear
# 119 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	waitstate
# 120 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	releaseall
# 121 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	end
# 122 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 123 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1:
# 124 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 125 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 126 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 127 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 128 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 129 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 130 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 131 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 132 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame2:
# 133 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 134 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 135 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 136 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 137 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	walk_up
# 138 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	step_end
# 139 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 140 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_HereWeHonorLeagueChampions:
# 141 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "STEVEN: This room…\p"
# 142 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "This is where we keep records of\n"
# 143 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "POKéMON that prevailed through\l"
# 144 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "harsh battles.\p"
# 145 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "It is here that the LEAGUE CHAMPIONS\n"
# 146 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "are honored.$"
# 147 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 148 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_WelcomeBackHoF:
# 149 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: Welcome back, {PLAYER}.\p"
# 150 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "This is where we keep records of\n"
# 151 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "POKéMON that prevailed through\l"
# 152 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "harsh battles.\p"
# 153 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "It is here that the LEAGUE CHAMPIONS\n"
# 154 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "are honored.$"
# 155 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 156 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_LetsRecordYouAndYourPartnersNames:
# 157 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "STEVEN: Come on, let's record your\n"
# 158 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "name as a TRAINER who triumphed over\l"
# 159 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the POKéMON LEAGUE, and the names of\l"
# 160 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "the partners who battled with you.$"
# 161 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"

# 162 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
EverGrandeCity_HallOfFame_Text_RecordNewHoF:
# 163 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "WALLACE: Let's commemorate your\n"
# 164 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "achievements once again, {PLAYER},\l"
# 165 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "by recording the names of the\l"
# 166 "data//maps/EverGrandeCity_HallOfFame/scripts.pory"
	.string "partners who battled with you.$"
