# 1 "data//maps/Route119/scripts.pory"

# 2 "data//maps/Route119/scripts.pory"
Route119_MapScripts::
# 3 "data//maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
# 4 "data//maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
# 5 "data//maps/Route119/scripts.pory"
	.byte 0
# 6 "data//maps/Route119/scripts.pory"

# 7 "data//maps/Route119/scripts.pory"
Route119_OnResume:
# 8 "data//maps/Route119/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
# 9 "data//maps/Route119/scripts.pory"
	end
# 10 "data//maps/Route119/scripts.pory"

# 11 "data//maps/Route119/scripts.pory"
Route119_EventScript_TryRemoveKecleon::
# 12 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data//maps/Route119/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data//maps/Route119/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data//maps/Route119/scripts.pory"
	return
# 16 "data//maps/Route119/scripts.pory"

# 17 "data//maps/Route119/scripts.pory"
Route119_OnTransition:
# 18 "data//maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 19 "data//maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 20 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
# 21 "data//maps/Route119/scripts.pory"
	special SetRoute119Weather
# 22 "data//maps/Route119/scripts.pory"
	end
# 23 "data//maps/Route119/scripts.pory"

# 24 "data//maps/Route119/scripts.pory"
Route119_EventScript_MoveInstituteWorkersDownstairs::
# 25 "data//maps/Route119/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 26 "data//maps/Route119/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
# 27 "data//maps/Route119/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
# 28 "data//maps/Route119/scripts.pory"
	return
# 29 "data//maps/Route119/scripts.pory"

# 30 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger1::
# 31 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 1
# 32 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 33 "data//maps/Route119/scripts.pory"
	end
# 34 "data//maps/Route119/scripts.pory"

# 35 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger2::
# 36 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 2
# 37 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 38 "data//maps/Route119/scripts.pory"
	end
# 39 "data//maps/Route119/scripts.pory"

# 40 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEncounter::
# 41 "data//maps/Route119/scripts.pory"
	lockall
# 42 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 43 "data//maps/Route119/scripts.pory"
	checkplayergender
# 44 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
# 45 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
# 46 "data//maps/Route119/scripts.pory"
	delay 65
# 47 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
# 48 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
# 49 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 50 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 51 "data//maps/Route119/scripts.pory"
	delay 30
# 52 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 53 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 54 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 55 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL
# 56 "data//maps/Route119/scripts.pory"
	delay 30
# 57 "data//maps/Route119/scripts.pory"
	checkplayergender
# 58 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
# 59 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
# 60 "data//maps/Route119/scripts.pory"
	releaseall
# 61 "data//maps/Route119/scripts.pory"
	end
# 62 "data//maps/Route119/scripts.pory"

# 63 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayMayMusic::
# 64 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 65 "data//maps/Route119/scripts.pory"
	return
# 66 "data//maps/Route119/scripts.pory"

# 67 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayBrendanMusic::
# 68 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 69 "data//maps/Route119/scripts.pory"
	return
# 70 "data//maps/Route119/scripts.pory"

# 71 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMay::
# 72 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
# 73 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 74 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartMayBattle
# 75 "data//maps/Route119/scripts.pory"
	end
# 76 "data//maps/Route119/scripts.pory"

# 77 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartMayBattle::
# 78 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_A, Route119_Text_MayDefeat
# 79 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 80 "data//maps/Route119/scripts.pory"
	end
# 81 "data//maps/Route119/scripts.pory"

# 82 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 83 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 84 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 85 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 86 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 87 "data//maps/Route119/scripts.pory"
	end
# 88 "data//maps/Route119/scripts.pory"

# 89 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 90 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 91 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 92 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartBrendanBattle
# 93 "data//maps/Route119/scripts.pory"
	end
# 94 "data//maps/Route119/scripts.pory"

# 95 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartBrendanBattle::
# 96 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_A, Route119_Text_BrendanDefeat
# 97 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 98 "data//maps/Route119/scripts.pory"
	end
# 99 "data//maps/Route119/scripts.pory"

# 100 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 101 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 102 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 103 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 104 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 105 "data//maps/Route119/scripts.pory"
	end
# 106 "data//maps/Route119/scripts.pory"

# 107 "data//maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 108 "data//maps/Route119/scripts.pory"
	giveitem ITEM_HM_FLY
# 109 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 110 "data//maps/Route119/scripts.pory"
	return
# 111 "data//maps/Route119/scripts.pory"

# 112 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 113 "data//maps/Route119/scripts.pory"
	closemessage
# 114 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 115 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 116 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL
# 117 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 118 "data//maps/Route119/scripts.pory"
	delay 30
# 119 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 120 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 121 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 122 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 123 "data//maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 124 "data//maps/Route119/scripts.pory"
	fadedefaultbgm
# 125 "data//maps/Route119/scripts.pory"
	delay 60
# 126 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 127 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 128 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_SCOTT
# 129 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
# 130 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 131 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 132 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 133 "data//maps/Route119/scripts.pory"
	closemessage
# 134 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 135 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 136 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_SCOTT
# 137 "data//maps/Route119/scripts.pory"
	releaseall
# 138 "data//maps/Route119/scripts.pory"
	end
# 139 "data//maps/Route119/scripts.pory"

# 140 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 141 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
# 142 "data//maps/Route119/scripts.pory"
	return
# 143 "data//maps/Route119/scripts.pory"

# 144 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 145 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
# 146 "data//maps/Route119/scripts.pory"
	return
# 147 "data//maps/Route119/scripts.pory"

# 148 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 149 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
# 150 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 151 "data//maps/Route119/scripts.pory"
	return
# 152 "data//maps/Route119/scripts.pory"

# 153 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 154 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
# 155 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 156 "data//maps/Route119/scripts.pory"
	return
# 157 "data//maps/Route119/scripts.pory"

# 158 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 159 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 160 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 161 "data//maps/Route119/scripts.pory"
	return
# 162 "data//maps/Route119/scripts.pory"

# 163 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 164 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 165 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 166 "data//maps/Route119/scripts.pory"
	return
# 167 "data//maps/Route119/scripts.pory"

# 168 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 169 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 170 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 171 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 172 "data//maps/Route119/scripts.pory"
	return
# 173 "data//maps/Route119/scripts.pory"

# 174 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 175 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 176 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 177 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 178 "data//maps/Route119/scripts.pory"
	return
# 179 "data//maps/Route119/scripts.pory"

# 180 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 181 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
# 182 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
# 183 "data//maps/Route119/scripts.pory"
	return
# 184 "data//maps/Route119/scripts.pory"

# 185 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 186 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
# 187 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
# 188 "data//maps/Route119/scripts.pory"
	return
# 189 "data//maps/Route119/scripts.pory"

# 190 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 191 "data//maps/Route119/scripts.pory"
	delay_16
# 192 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 193 "data//maps/Route119/scripts.pory"
	delay_8
# 194 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 195 "data//maps/Route119/scripts.pory"
	step_end
# 196 "data//maps/Route119/scripts.pory"

# 197 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 198 "data//maps/Route119/scripts.pory"
	delay_16
# 199 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 200 "data//maps/Route119/scripts.pory"
	delay_8
# 201 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 202 "data//maps/Route119/scripts.pory"
	step_end
# 203 "data//maps/Route119/scripts.pory"

# 204 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
# 205 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 206 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 207 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 208 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 209 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 210 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 211 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 212 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 213 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 214 "data//maps/Route119/scripts.pory"
	step_end
# 215 "data//maps/Route119/scripts.pory"

# 216 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 217 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 218 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 219 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 220 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 221 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 222 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 223 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 224 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 225 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 226 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 227 "data//maps/Route119/scripts.pory"
	step_end
# 228 "data//maps/Route119/scripts.pory"

# 229 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 230 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 231 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 232 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 233 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 234 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 235 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 236 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 237 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 238 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 239 "data//maps/Route119/scripts.pory"
	step_end
# 240 "data//maps/Route119/scripts.pory"

# 241 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 242 "data//maps/Route119/scripts.pory"
	walk_fast_left
# 243 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 244 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 245 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 246 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 247 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 248 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 249 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 250 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 251 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 252 "data//maps/Route119/scripts.pory"
	step_end
# 253 "data//maps/Route119/scripts.pory"

# 254 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 255 "data//maps/Route119/scripts.pory"
	walk_down
# 256 "data//maps/Route119/scripts.pory"
	walk_down
# 257 "data//maps/Route119/scripts.pory"
	walk_down
# 258 "data//maps/Route119/scripts.pory"
	walk_down
# 259 "data//maps/Route119/scripts.pory"
	walk_left
# 260 "data//maps/Route119/scripts.pory"
	walk_left
# 261 "data//maps/Route119/scripts.pory"
	walk_down
# 262 "data//maps/Route119/scripts.pory"
	step_end
# 263 "data//maps/Route119/scripts.pory"

# 264 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 265 "data//maps/Route119/scripts.pory"
	walk_up
# 266 "data//maps/Route119/scripts.pory"
	walk_right
# 267 "data//maps/Route119/scripts.pory"
	walk_right
# 268 "data//maps/Route119/scripts.pory"
	walk_up
# 269 "data//maps/Route119/scripts.pory"
	walk_up
# 270 "data//maps/Route119/scripts.pory"
	walk_up
# 271 "data//maps/Route119/scripts.pory"
	walk_up
# 272 "data//maps/Route119/scripts.pory"
	walk_up
# 273 "data//maps/Route119/scripts.pory"
	step_end
# 274 "data//maps/Route119/scripts.pory"

# 275 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 276 "data//maps/Route119/scripts.pory"
	walk_up
# 277 "data//maps/Route119/scripts.pory"
	walk_right
# 278 "data//maps/Route119/scripts.pory"
	walk_up
# 279 "data//maps/Route119/scripts.pory"
	walk_up
# 280 "data//maps/Route119/scripts.pory"
	walk_up
# 281 "data//maps/Route119/scripts.pory"
	walk_up
# 282 "data//maps/Route119/scripts.pory"
	walk_up
# 283 "data//maps/Route119/scripts.pory"
	step_end
# 284 "data//maps/Route119/scripts.pory"

# 285 "data//maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 286 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 287 "data//maps/Route119/scripts.pory"
	end
# 288 "data//maps/Route119/scripts.pory"

# 289 "data//maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 290 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 291 "data//maps/Route119/scripts.pory"
	end
# 292 "data//maps/Route119/scripts.pory"

# 293 "data//maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 294 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 295 "data//maps/Route119/scripts.pory"
	end
# 296 "data//maps/Route119/scripts.pory"

# 297 "data//maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 298 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 299 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 300 "data//maps/Route119/scripts.pory"
	end
# 301 "data//maps/Route119/scripts.pory"

# 302 "data//maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 303 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 304 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 305 "data//maps/Route119/scripts.pory"
	end
# 306 "data//maps/Route119/scripts.pory"

# 307 "data//maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 308 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 309 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 310 "data//maps/Route119/scripts.pory"
	end
# 311 "data//maps/Route119/scripts.pory"

# 312 "data//maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 313 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 314 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 315 "data//maps/Route119/scripts.pory"
	end
# 316 "data//maps/Route119/scripts.pory"

# 317 "data//maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 318 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 319 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 320 "data//maps/Route119/scripts.pory"
	end
# 321 "data//maps/Route119/scripts.pory"

# 322 "data//maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 323 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 324 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 325 "data//maps/Route119/scripts.pory"
	end
# 326 "data//maps/Route119/scripts.pory"

# 327 "data//maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 328 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 329 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 330 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 331 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 332 "data//maps/Route119/scripts.pory"
	release
# 333 "data//maps/Route119/scripts.pory"
	end
# 334 "data//maps/Route119/scripts.pory"

# 335 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 336 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 337 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 338 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 339 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 340 "data//maps/Route119/scripts.pory"
	release
# 341 "data//maps/Route119/scripts.pory"
	end
# 342 "data//maps/Route119/scripts.pory"

# 343 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 344 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 345 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 346 "data//maps/Route119/scripts.pory"
	end
# 347 "data//maps/Route119/scripts.pory"

# 348 "data//maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 349 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 350 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 351 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 352 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 353 "data//maps/Route119/scripts.pory"
	release
# 354 "data//maps/Route119/scripts.pory"
	end
# 355 "data//maps/Route119/scripts.pory"

# 356 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 357 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 358 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 359 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 360 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 361 "data//maps/Route119/scripts.pory"
	release
# 362 "data//maps/Route119/scripts.pory"
	end
# 363 "data//maps/Route119/scripts.pory"

# 364 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 365 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 366 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 367 "data//maps/Route119/scripts.pory"
	end
# 368 "data//maps/Route119/scripts.pory"

# 369 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 370 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 371 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 372 "data//maps/Route119/scripts.pory"
	end
# 373 "data//maps/Route119/scripts.pory"

# 374 "data//maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 375 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 376 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 377 "data//maps/Route119/scripts.pory"
	end
# 378 "data//maps/Route119/scripts.pory"

# 379 "data//maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 380 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 381 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 382 "data//maps/Route119/scripts.pory"
	end
# 383 "data//maps/Route119/scripts.pory"

# 384 "data//maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 385 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 386 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 387 "data//maps/Route119/scripts.pory"
	end
# 388 "data//maps/Route119/scripts.pory"

# 389 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 390 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 391 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 392 "data//maps/Route119/scripts.pory"
	end
# 393 "data//maps/Route119/scripts.pory"

# 394 "data//maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 395 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 396 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 397 "data//maps/Route119/scripts.pory"
	end
# 398 "data//maps/Route119/scripts.pory"

# 399 "data//maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 400 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 401 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 402 "data//maps/Route119/scripts.pory"
	end
# 403 "data//maps/Route119/scripts.pory"

# 404 "data//maps/Route119/scripts.pory"
Route119_EventScript_Daemon::
# 405 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAEMON, Route119_Text_DaemonIntro, Route119_Text_DaemonDefeat
# 406 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaemonPostBattle, MSGBOX_AUTOCLOSE
# 407 "data//maps/Route119/scripts.pory"
	end
# 408 "data//maps/Route119/scripts.pory"

# 409 "data//maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 410 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 411 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 412 "data//maps/Route119/scripts.pory"
	end
# 413 "data//maps/Route119/scripts.pory"

# 414 "data//maps/Route119/scripts.pory"
Route119_EventScript_Rachel::
# 415 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
# 416 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
# 417 "data//maps/Route119/scripts.pory"
	end
# 418 "data//maps/Route119/scripts.pory"

# 419 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 420 "data//maps/Route119/scripts.pory"
	lock
# 421 "data//maps/Route119/scripts.pory"
	faceplayer
# 422 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 423 "data//maps/Route119/scripts.pory"
	closemessage
# 424 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 425 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 426 "data//maps/Route119/scripts.pory"
	release
# 427 "data//maps/Route119/scripts.pory"
	end
# 428 "data//maps/Route119/scripts.pory"

# 429 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 430 "data//maps/Route119/scripts.pory"
	lock
# 431 "data//maps/Route119/scripts.pory"
	faceplayer
# 432 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 433 "data//maps/Route119/scripts.pory"
	closemessage
# 434 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 435 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 436 "data//maps/Route119/scripts.pory"
	release
# 437 "data//maps/Route119/scripts.pory"
	end
# 438 "data//maps/Route119/scripts.pory"

# 439 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 440 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 441 "data//maps/Route119/scripts.pory"
	end
# 442 "data//maps/Route119/scripts.pory"

# 443 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 444 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 445 "data//maps/Route119/scripts.pory"
	end
# 446 "data//maps/Route119/scripts.pory"

# 447 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 448 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 449 "data//maps/Route119/scripts.pory"
	end
# 450 "data//maps/Route119/scripts.pory"

# 451 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 452 "data//maps/Route119/scripts.pory"
	lockall
# 453 "data//maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 454 "data//maps/Route119/scripts.pory"
	waitmessage
# 455 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 456 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 457 "data//maps/Route119/scripts.pory"
	releaseall
# 458 "data//maps/Route119/scripts.pory"
	end
# 459 "data//maps/Route119/scripts.pory"

# 460 "data//maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 461 "data//maps/Route119/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 462 "data//maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 463 "data//maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 464 "data//maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 465 "data//maps/Route119/scripts.pory"
	.string "Ready with your POKéMON?\n"
# 466 "data//maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 467 "data//maps/Route119/scripts.pory"

# 468 "data//maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 469 "data//maps/Route119/scripts.pory"
	.string "Achah!\n"
# 470 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 471 "data//maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 472 "data//maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 473 "data//maps/Route119/scripts.pory"

# 474 "data//maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 475 "data//maps/Route119/scripts.pory"
	.string "MAY: But I had absolutely nothing to\n"
# 476 "data//maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 477 "data//maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 478 "data//maps/Route119/scripts.pory"

# 479 "data//maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 480 "data//maps/Route119/scripts.pory"
	.string "MAY: Use FLY, and your POKéMON will\n"
# 481 "data//maps/Route119/scripts.pory"
	.string "instantly carry you to any town you've\l"
# 482 "data//maps/Route119/scripts.pory"
	.string "already visited.\p"
# 483 "data//maps/Route119/scripts.pory"
	.string "But, to use FLY, you have to get\n"
# 484 "data//maps/Route119/scripts.pory"
	.string "the GYM BADGE from FORTREE CITY.\l"
# 485 "data//maps/Route119/scripts.pory"
	.string "That's important, so don't forget.\p"
# 486 "data//maps/Route119/scripts.pory"
	.string "You should FLY home and visit\n"
# 487 "data//maps/Route119/scripts.pory"
	.string "LITTLEROOT for a change.\p"
# 488 "data//maps/Route119/scripts.pory"
	.string "I bet your mom's worried about you,\n"
# 489 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 490 "data//maps/Route119/scripts.pory"
	.string "Well, let's meet again somewhere!$"
# 491 "data//maps/Route119/scripts.pory"

# 492 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 493 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: {PLAYER}! So this is where\n"
# 494 "data//maps/Route119/scripts.pory"
	.string "you've been looking for POKéMON?\p"
# 495 "data//maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 496 "data//maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 497 "data//maps/Route119/scripts.pory"
	.string "Now!\n"
# 498 "data//maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 499 "data//maps/Route119/scripts.pory"

# 500 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 501 "data//maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 502 "data//maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 503 "data//maps/Route119/scripts.pory"

# 504 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 505 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: I'd say you're good enough\n"
# 506 "data//maps/Route119/scripts.pory"
	.string "to search for POKéMON anywhere.\p"
# 507 "data//maps/Route119/scripts.pory"
	.string "Here, I'll give you this.\n"
# 508 "data//maps/Route119/scripts.pory"
	.string "Try it out.$"
# 509 "data//maps/Route119/scripts.pory"

# 510 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 511 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: Use FLY, and your POKéMON\n"
# 512 "data//maps/Route119/scripts.pory"
	.string "instantly carries you to any town\l"
# 513 "data//maps/Route119/scripts.pory"
	.string "you've already visited.\p"
# 514 "data//maps/Route119/scripts.pory"
	.string "But you need the FORTREE GYM BADGE \n"
# 515 "data//maps/Route119/scripts.pory"
	.string "to do that.\p"
# 516 "data//maps/Route119/scripts.pory"
	.string "Anyway, I have to move along.$"
# 517 "data//maps/Route119/scripts.pory"

# 518 "data//maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 519 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hahahah!\n"
# 520 "data//maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 521 "data//maps/Route119/scripts.pory"
	.string "I just passed by a TRAINER riding\n"
# 522 "data//maps/Route119/scripts.pory"
	.string "a BIKE.\p"
# 523 "data//maps/Route119/scripts.pory"
	.string "You just beat that TRAINER, didn't you?\n"
# 524 "data//maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 525 "data//maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 526 "data//maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 527 "data//maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 528 "data//maps/Route119/scripts.pory"
	.string "Are you off to FORTREE GYM next?\p"
# 529 "data//maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the GYM.\n"
# 530 "data//maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 531 "data//maps/Route119/scripts.pory"

# 532 "data//maps/Route119/scripts.pory"

# 533 "data//maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 534 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 535 "data//maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 536 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
# 537 "data//maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 538 "data//maps/Route119/scripts.pory"
	.string "the FORTREE GYM.\p"
# 539 "data//maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 540 "data//maps/Route119/scripts.pory"
	.string "Perhaps you really are the TRAINER\l"
# 541 "data//maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 542 "data//maps/Route119/scripts.pory"
	.string "Remember, you have a fan in me.\n"
# 543 "data//maps/Route119/scripts.pory"
	.string "I'll be cheering from the sidelines.\l"
# 544 "data//maps/Route119/scripts.pory"
	.string "Keep up the great work!\p"
# 545 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 546 "data//maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 547 "data//maps/Route119/scripts.pory"

# 548 "data//maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 549 "data//maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 550 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the WEATHER\n"
# 551 "data//maps/Route119/scripts.pory"
	.string "INSTITUTE. It's not safe.$"
# 552 "data//maps/Route119/scripts.pory"

# 553 "data//maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 554 "data//maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 555 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 556 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE.$"
# 557 "data//maps/Route119/scripts.pory"

# 558 "data//maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 559 "data//maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 560 "data//maps/Route119/scripts.pory"
	.string "flock of BIRD POKéMON, and then\l"
# 561 "data//maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 562 "data//maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 563 "data//maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 564 "data//maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 565 "data//maps/Route119/scripts.pory"
	.string "time ago…$"
# 566 "data//maps/Route119/scripts.pory"

# 567 "data//maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 568 "data//maps/Route119/scripts.pory"
	.string "Tch…\n"
# 569 "data//maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 570 "data//maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 571 "data//maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 572 "data//maps/Route119/scripts.pory"

# 573 "data//maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 574 "data//maps/Route119/scripts.pory"
	.string "Can your POKéMON use its SECRET POWER\n"
# 575 "data//maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 576 "data//maps/Route119/scripts.pory"
	.string "SECRET BASE?$"
# 577 "data//maps/Route119/scripts.pory"

# 578 "data//maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 579 "data//maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 580 "data//maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 581 "data//maps/Route119/scripts.pory"

# 582 "data//maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 583 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 584 "data//maps/Route119/scripts.pory"

# 585 "data//maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 586 "data//maps/Route119/scripts.pory"
	.string "TRAINER TIPS\p"
# 587 "data//maps/Route119/scripts.pory"
	.string "Up to sixteen decorations and\n"
# 588 "data//maps/Route119/scripts.pory"
	.string "furniture items can be placed in\l"
# 589 "data//maps/Route119/scripts.pory"
	.string "a SECRET BASE.\p"
# 590 "data//maps/Route119/scripts.pory"
	.string "Pick your favorite items and create\n"
# 591 "data//maps/Route119/scripts.pory"
	.string "your very own SECRET BASE exactly the\l"
# 592 "data//maps/Route119/scripts.pory"
	.string "way you want.$"
