# 1 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 2 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_MapScripts::
# 3 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
# 4 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
# 5 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
# 6 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.byte 0
# 7 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 8 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnTransition:
# 9 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_SetupChampionGfxId
# 10 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 12 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 13 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_SetupChampionGfxId::
# 14 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_ChampionsRoom_EventScript_ShowChampionSteven
# 15 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_ChampionsRoom_EventScript_ShowChampionWallace
# 16 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 17 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 18 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ShowChampionSteven::
# 19 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_STEVEN
# 20 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 21 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 22 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ShowChampionWallace::
# 23 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_WALLACE
# 24 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 25 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 26 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnWarp:
# 27 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
# 28 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 29 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 30 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
# 31 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 32 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 33 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 34 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnFrame:
# 35 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
# 36 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 37 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 38 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
# 39 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	lockall
# 40 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
# 41 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 42 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 43 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachChampion
# 44 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 45 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 46 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_HOF_COUNTER, 0, EverGrandeCity_ChampionsRoom_EventScript_Steven1
# 47 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_ge VAR_HOF_COUNTER, 1, EverGrandeCity_ChampionsRoom_EventScript_Wallace1
# 48 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 49 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 50 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 51 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerApproachChampion:
# 52 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 53 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 54 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 55 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 56 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Steven1::
# 57 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 58 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 59 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_STEVEN, EverGrandeCity_ChampionsRoom_Text_Defeat
# 60 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Steven1_Defeated
# 61 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 62 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 63 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Steven1_Defeated::
# 64 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 65 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 66 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 67 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 68 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 69 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 70 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 71 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 72 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 73 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 74 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
# 75 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 76 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 77 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 78 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 79 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 80 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 81 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace1::
# 82 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 83 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceIntroSpeech, MSGBOX_DEFAULT
# 84 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_WALLACE, EverGrandeCity_ChampionsRoom_Text_WallaceDefeat
# 85 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace1_Defeated
# 86 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 87 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 88 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace1_Defeated::
# 89 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 90 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 91 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 92 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 93 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallacePostBattleSpeech, MSGBOX_DEFAULT
# 94 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 95 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 96 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 97 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 98 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, Common_Movement_WalkInPlaceFasterDown
# 99 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 100 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 101 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 102 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 103 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart
# 104 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 105 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ waitmovement 0
# 106 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ delay 20
# 107 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 108 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	@ waitmovement 0
# 109 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExit2
# 110 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit2
# 111 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 112 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 113 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 114 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 115 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 116 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 117 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 118 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 119 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 120 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 121 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 122 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 123 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 124 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 125 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 126 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 127 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 128 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 129 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 130 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 131 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 132 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 133 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 134 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 135 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 136 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 137 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 138 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 139 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 140 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 141 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 142 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 143 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 144 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 145 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 146 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 147 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 148 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 149 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 150 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 151 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 152 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 153 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 154 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
# 155 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 156 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 157 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 158 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 159 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 160 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 161 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 162 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, Common_Movement_WalkInPlaceFasterUp
# 163 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 164 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 165 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, Common_Movement_WalkInPlaceFasterDown
# 166 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 167 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_Steven1ComeWithMe, MSGBOX_DEFAULT
# 168 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 169 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 170 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart
# 171 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 172 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 173 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 174 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 175 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 176 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 177 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 178 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_Steven1WaitOutside, MSGBOX_DEFAULT
# 179 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 180 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 181 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 182 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 183 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_CHAMPION, EverGrandeCity_ChampionsRoom_Movement_ChampionExit
# 184 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 185 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 186 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 187 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 188 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 189 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 190 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 191 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 192 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 193 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 194 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 195 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 196 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 197 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 198 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 199 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 200 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 201 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 202 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 203 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 204 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 205 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 206 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 207 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 208 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 209 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 210 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 211 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 212 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 213 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 214 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 215 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 216 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 217 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 218 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 219 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 220 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 221 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 222 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 223 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 224 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 225 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit2:
# 226 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 227 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 228 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 229 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 230 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 231 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 232 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 233 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 234 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 235 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 236 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 237 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 238 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 239 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 240 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 241 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 242 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 243 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 244 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 245 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 246 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 247 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 248 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 249 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 250 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 251 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 252 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 253 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 254 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 255 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 256 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 257 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 258 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 259 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 260 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 261 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 262 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExitStart:
# 263 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 264 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 265 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 266 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 267 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 268 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExit:
# 269 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 270 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 271 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 272 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 273 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 274 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ChampionExit2:
# 275 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 276 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 277 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 278 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 279 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 280 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 281 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 282 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 283 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 284 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 285 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 286 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 287 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 288 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 289 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 290 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 291 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 292 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 293 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 294 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: Welcome, {PLAYER}{KUN}.\p"
# 295 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I was looking forward to seeing you\n"
# 296 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "here one day.\p"
# 297 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did you learn on your\n"
# 298 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "journey with POKéMON?\p"
# 299 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What has awoken in you?\n"
# 300 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I want you to hit me with it all!\p"
# 301 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, bring it!$"
# 302 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 303 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 304 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 305 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 306 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 307 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 308 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 309 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 310 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: You were able to grasp\n"
# 311 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "victory today.\p"
# 312 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are rightfully the HOENN region's\n"
# 313 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "new . . .$"
# 314 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 315 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 316 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 317 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 318 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 319 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 320 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 321 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 322 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 323 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 324 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 325 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 326 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 327 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 328 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 329 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 330 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 331 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 332 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 333 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 334 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 335 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 336 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 337 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 338 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 339 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 340 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 341 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 342 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 343 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 344 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 345 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 346 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 347 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 348 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 349 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 350 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 351 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 352 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 353 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 354 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 355 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 356 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 357 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 358 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Steven1ComeWithMe:
# 359 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}…\p"
# 360 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 361 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 362 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 363 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 364 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Steven1WaitOutside:
# 365 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN: I'm sorry, but…\p"
# 366 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 367 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 368 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 369 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 370 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 371 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 372 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 373 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 374 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 375 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 376 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 377 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 378 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 379 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 380 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 381 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 382 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 383 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 384 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 385 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"
# 386 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 387 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceIntroSpeech:
# 388 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
# 389 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "STEVEN left to better himself after\n"
# 390 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "his defeat at your hands.\p"
# 391 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I've taken over as acting CHAMPION\n"
# 392 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "in his stead, so I will assess your\l"
# 393 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "abilities today.\p"
# 394 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 395 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 396 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis.\p"
# 397 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 398 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 399 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 400 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 401 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.\p"
# 402 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
# 403 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Who can most elegantly dance with\n"
# 404 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "their POKéMON in HOENN?\p"
# 405 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Show me right here and now!$"
# 406 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 407 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceDefeat:
# 408 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 409 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 410 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 411 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 412 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 413 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 414 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 415 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 416 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallacePostBattleSpeech:
# 417 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 418 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 419 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 420 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 421 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 422 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 423 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 424 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 425 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 426 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 427 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 428 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I hereby reaffirm you as the HOENN\n"
# 429 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "region's true reigning CHAMPION.$"
# 430 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 431 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 432 "data//maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now come with me.$"
