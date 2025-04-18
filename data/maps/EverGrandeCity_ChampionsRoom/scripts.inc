# 1 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 2 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_CHAMPION, 1
# 3 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_RIVAL, 2
# 4 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
.set LOCALID_BIRCH, 3
# 5 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 6 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_MapScripts::
# 7 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
# 8 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
# 9 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
# 10 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.byte 0
# 11 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 12 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnTransition:
# 13 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_SetupChampionGfxId
# 14 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 15 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 16 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 17 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_SetupChampionGfxId::
# 18 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_ChampionsRoom_EventScript_ShowChampionSteven
# 19 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_ChampionsRoom_EventScript_ShowChampionWallace
# 20 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 21 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 22 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ShowChampionSteven::
# 23 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_STEVEN
# 24 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 25 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 26 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ShowChampionWallace::
# 27 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_WALLACE
# 28 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 29 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 30 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnWarp:
# 31 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
# 32 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 33 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 34 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
# 35 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 36 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 37 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 38 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnFrame:
# 39 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
# 40 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 41 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 42 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
# 43 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	lockall
# 44 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 45 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 46 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 47 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachChampion
# 48 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 49 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 50 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_ChampionsRoom_EventScript_Steven1
# 51 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_ChampionsRoom_EventScript_Wallace1
# 52 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 53 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 54 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 55 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerApproachChampion:
# 56 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 57 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 58 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 59 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 60 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Steven1::
# 61 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 62 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 63 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_STEVEN, EverGrandeCity_ChampionsRoom_Text_Defeat
# 64 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Steven1_Defeated
# 65 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 66 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 67 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Steven1_Defeated::
# 68 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 69 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 70 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 71 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 72 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 73 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 74 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 75 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 76 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 77 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 78 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_RIVAL
# 79 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 80 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 81 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 82 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 83 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 84 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 85 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace1::
# 86 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 87 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceIntroSpeech, MSGBOX_DEFAULT
# 88 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_WALLACE, EverGrandeCity_ChampionsRoom_Text_WallaceDefeat
# 89 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace1_Defeated
# 90 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 91 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 92 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace1_Defeated::
# 93 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 94 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 95 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 96 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 97 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallacePostBattleSpeech, MSGBOX_DEFAULT
# 98 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 99 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 100 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 101 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 102 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterDown
# 103 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 104 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 105 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 106 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 107 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement LOCALID_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart
# 108 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 109 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ waitmovement 0
# 110 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ delay 20
# 111 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 112 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ waitmovement 0
# 113 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExit2
# 114 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit2
# 115 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 116 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 117 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 118 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 119 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 120 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 121 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 122 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 123 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 124 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 125 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 126 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 127 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 128 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 129 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 130 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 131 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 132 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 133 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 134 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 135 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 136 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 137 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 138 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 139 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 140 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 141 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 142 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 143 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 144 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 145 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 146 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 147 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 148 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 149 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 150 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 151 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 152 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 153 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 154 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 155 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 156 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 157 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 158 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_BIRCH
# 159 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 160 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 161 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 162 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 163 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 164 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 165 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 166 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 167 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 168 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 169 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, Common_Movement_WalkInPlaceFasterDown
# 170 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 171 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_Steven1ComeWithMe, MSGBOX_DEFAULT
# 172 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 173 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 174 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart
# 175 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 176 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 177 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 178 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 179 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 180 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 181 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 182 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_Steven1WaitOutside, MSGBOX_DEFAULT
# 183 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 184 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 185 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 186 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 187 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExit
# 188 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 189 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 190 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 191 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 192 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 193 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 194 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 195 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 196 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 197 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 198 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 199 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 200 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 201 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 202 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 203 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 204 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 205 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 206 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 207 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 208 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 209 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 210 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 211 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 212 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 213 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 214 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 215 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 216 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 217 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 218 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 219 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 220 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 221 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 222 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 223 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 224 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 225 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 226 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 227 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 228 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 229 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit2:
# 230 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 231 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 232 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 233 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 234 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 235 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 236 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 237 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 238 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 239 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 240 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 241 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 242 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 243 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 244 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 245 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 246 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 247 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 248 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 249 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 250 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 251 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 252 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 253 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 254 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 255 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 256 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 257 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 258 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 259 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 260 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 261 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 262 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 263 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 264 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 265 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 266 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart:
# 267 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 268 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 269 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 270 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 271 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 272 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExit:
# 273 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 274 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 275 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 276 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 277 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 278 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExit2:
# 279 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 280 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 281 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 282 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 283 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 284 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 285 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 286 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 287 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 288 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 289 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 290 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 291 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 292 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 293 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 294 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 295 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 296 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 297 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 298 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: Welcome, {PLAYER}{KUN}.\p"
# 299 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I was looking forward to seeing you\n"
# 300 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "here one day.\p"
# 301 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did you learn on your\n"
# 302 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "journey with POKéMON?\p"
# 303 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What has awoken in you?\n"
# 304 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I want you to hit me with it all!\p"
# 305 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, bring it!$"
# 306 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 307 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 308 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 309 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 310 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 311 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 312 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 313 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 314 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: You were able to grasp\n"
# 315 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "victory today.\p"
# 316 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are rightfully the HOENN region's\n"
# 317 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "new . . .$"
# 318 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 319 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 320 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 321 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 322 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 323 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 324 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 325 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 326 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 327 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 328 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 329 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 330 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 331 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 332 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 333 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 334 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 335 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 336 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 337 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 338 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 339 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 340 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 341 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 342 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 343 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 344 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 345 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 346 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 347 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 348 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 349 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 350 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 351 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 352 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 353 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 354 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 355 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 356 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 357 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 358 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 359 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 360 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 361 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 362 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Steven1ComeWithMe:
# 363 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}…\p"
# 364 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 365 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 366 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 367 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 368 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Steven1WaitOutside:
# 369 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: I'm sorry, but…\p"
# 370 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 371 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 372 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 373 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 374 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 375 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 376 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 377 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 378 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 379 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 380 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 381 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 382 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 383 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 384 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 385 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 386 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 387 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 388 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 389 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"
# 390 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 391 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceIntroSpeech:
# 392 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
# 393 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN left to better himself after\n"
# 394 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "his defeat at your hands.\p"
# 395 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I've taken over as acting CHAMPION\n"
# 396 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "in his stead, so I will assess your\l"
# 397 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "abilities today.\p"
# 398 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 399 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 400 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis.\p"
# 401 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 402 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 403 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 404 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 405 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.\p"
# 406 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
# 407 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Who can most elegantly dance with\n"
# 408 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "their POKéMON in HOENN?\p"
# 409 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Show me right here and now!$"
# 410 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 411 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceDefeat:
# 412 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 413 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 414 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 415 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 416 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 417 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 418 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 419 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 420 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallacePostBattleSpeech:
# 421 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 422 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 423 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 424 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 425 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 426 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 427 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 428 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 429 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 430 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 431 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 432 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I hereby reaffirm you as the HOENN\n"
# 433 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "region's true reigning CHAMPION.$"
# 434 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 435 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 436 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now come with me.$"
