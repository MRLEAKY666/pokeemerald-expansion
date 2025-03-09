# 1 "data//maps/Route119/scripts.pory"

# 2 "data//maps/Route119/scripts.pory"
.set LOCALID_RIVAL, 16
# 3 "data//maps/Route119/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 25
# 4 "data//maps/Route119/scripts.pory"
.set LOCALID_SCOTT, 43
# 5 "data//maps/Route119/scripts.pory"

# 6 "data//maps/Route119/scripts.pory"
Route119_MapScripts::
# 7 "data//maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
# 8 "data//maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
# 9 "data//maps/Route119/scripts.pory"
	.byte 0
# 10 "data//maps/Route119/scripts.pory"

# 11 "data//maps/Route119/scripts.pory"
Route119_OnResume:
# 12 "data//maps/Route119/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
# 13 "data//maps/Route119/scripts.pory"
	end
# 14 "data//maps/Route119/scripts.pory"

# 15 "data//maps/Route119/scripts.pory"
Route119_EventScript_TryRemoveKecleon::
# 16 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data//maps/Route119/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 18 "data//maps/Route119/scripts.pory"
	removeobject VAR_LAST_TALKED
# 19 "data//maps/Route119/scripts.pory"
	return
# 20 "data//maps/Route119/scripts.pory"

# 21 "data//maps/Route119/scripts.pory"
Route119_OnTransition:
# 22 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 23 "data//maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 24 "data//maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 25 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
# 26 "data//maps/Route119/scripts.pory"
	special SetRoute119Weather
# 27 "data//maps/Route119/scripts.pory"
	end
# 28 "data//maps/Route119/scripts.pory"

# 29 "data//maps/Route119/scripts.pory"
Route119_EventScript_MoveInstituteWorkersDownstairs::
# 30 "data//maps/Route119/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 31 "data//maps/Route119/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
# 32 "data//maps/Route119/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
# 33 "data//maps/Route119/scripts.pory"
	return
# 34 "data//maps/Route119/scripts.pory"

# 35 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger1::
# 36 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 1
# 37 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 38 "data//maps/Route119/scripts.pory"
	end
# 39 "data//maps/Route119/scripts.pory"

# 40 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger2::
# 41 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 2
# 42 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 43 "data//maps/Route119/scripts.pory"
	end
# 44 "data//maps/Route119/scripts.pory"

# 45 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEncounter::
# 46 "data//maps/Route119/scripts.pory"
	lockall
# 47 "data//maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 48 "data//maps/Route119/scripts.pory"
	checkplayergender
# 49 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
# 50 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
# 51 "data//maps/Route119/scripts.pory"
	delay 65
# 52 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
# 53 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
# 54 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 55 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 56 "data//maps/Route119/scripts.pory"
	delay 30
# 57 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 58 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 59 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 60 "data//maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL
# 61 "data//maps/Route119/scripts.pory"
	delay 30
# 62 "data//maps/Route119/scripts.pory"
	checkplayergender
# 63 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
# 64 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
# 65 "data//maps/Route119/scripts.pory"
	releaseall
# 66 "data//maps/Route119/scripts.pory"
	end
# 67 "data//maps/Route119/scripts.pory"

# 68 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayMayMusic::
# 69 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 70 "data//maps/Route119/scripts.pory"
	return
# 71 "data//maps/Route119/scripts.pory"

# 72 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayBrendanMusic::
# 73 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 74 "data//maps/Route119/scripts.pory"
	return
# 75 "data//maps/Route119/scripts.pory"

# 76 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMay::
# 77 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
# 78 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 79 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartMayBattle
# 80 "data//maps/Route119/scripts.pory"
	end
# 81 "data//maps/Route119/scripts.pory"

# 82 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartMayBattle::
# 83 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_A, Route119_Text_MayDefeat
# 84 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 85 "data//maps/Route119/scripts.pory"
	end
# 86 "data//maps/Route119/scripts.pory"

# 87 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 88 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 89 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 90 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 91 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 92 "data//maps/Route119/scripts.pory"
	end
# 93 "data//maps/Route119/scripts.pory"

# 94 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 95 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 96 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 97 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartBrendanBattle
# 98 "data//maps/Route119/scripts.pory"
	end
# 99 "data//maps/Route119/scripts.pory"

# 100 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartBrendanBattle::
# 101 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_A, Route119_Text_BrendanDefeat
# 102 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 103 "data//maps/Route119/scripts.pory"
	end
# 104 "data//maps/Route119/scripts.pory"

# 105 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 106 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 107 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 108 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 109 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 110 "data//maps/Route119/scripts.pory"
	end
# 111 "data//maps/Route119/scripts.pory"

# 112 "data//maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 113 "data//maps/Route119/scripts.pory"
	giveitem ITEM_HM_FLY
# 114 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 115 "data//maps/Route119/scripts.pory"
	return
# 116 "data//maps/Route119/scripts.pory"

# 117 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 118 "data//maps/Route119/scripts.pory"
	closemessage
# 119 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 120 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 121 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL
# 122 "data//maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 123 "data//maps/Route119/scripts.pory"
	delay 30
# 124 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 125 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 126 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 127 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 128 "data//maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 129 "data//maps/Route119/scripts.pory"
	fadedefaultbgm
# 130 "data//maps/Route119/scripts.pory"
	delay 60
# 131 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 132 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 133 "data//maps/Route119/scripts.pory"
	addobject LOCALID_SCOTT
# 134 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
# 135 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 136 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 137 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 138 "data//maps/Route119/scripts.pory"
	closemessage
# 139 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 140 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 141 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_SCOTT
# 142 "data//maps/Route119/scripts.pory"
	releaseall
# 143 "data//maps/Route119/scripts.pory"
	end
# 144 "data//maps/Route119/scripts.pory"

# 145 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 146 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 27, 25
# 147 "data//maps/Route119/scripts.pory"
	return
# 148 "data//maps/Route119/scripts.pory"

# 149 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 150 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 28, 25
# 151 "data//maps/Route119/scripts.pory"
	return
# 152 "data//maps/Route119/scripts.pory"

# 153 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 154 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
# 155 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 156 "data//maps/Route119/scripts.pory"
	return
# 157 "data//maps/Route119/scripts.pory"

# 158 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 159 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
# 160 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 161 "data//maps/Route119/scripts.pory"
	return
# 162 "data//maps/Route119/scripts.pory"

# 163 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 164 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 165 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 166 "data//maps/Route119/scripts.pory"
	return
# 167 "data//maps/Route119/scripts.pory"

# 168 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 169 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 170 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 171 "data//maps/Route119/scripts.pory"
	return
# 172 "data//maps/Route119/scripts.pory"

# 173 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 174 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 175 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 176 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 177 "data//maps/Route119/scripts.pory"
	return
# 178 "data//maps/Route119/scripts.pory"

# 179 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 180 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 181 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 182 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 183 "data//maps/Route119/scripts.pory"
	return
# 184 "data//maps/Route119/scripts.pory"

# 185 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 186 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 25, 32
# 187 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
# 188 "data//maps/Route119/scripts.pory"
	return
# 189 "data//maps/Route119/scripts.pory"

# 190 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 191 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 26, 32
# 192 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
# 193 "data//maps/Route119/scripts.pory"
	return
# 194 "data//maps/Route119/scripts.pory"

# 195 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 196 "data//maps/Route119/scripts.pory"
	delay_16
# 197 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 198 "data//maps/Route119/scripts.pory"
	delay_8
# 199 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 200 "data//maps/Route119/scripts.pory"
	step_end
# 201 "data//maps/Route119/scripts.pory"

# 202 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 203 "data//maps/Route119/scripts.pory"
	delay_16
# 204 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 205 "data//maps/Route119/scripts.pory"
	delay_8
# 206 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 207 "data//maps/Route119/scripts.pory"
	step_end
# 208 "data//maps/Route119/scripts.pory"

# 209 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
# 210 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 211 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 212 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 213 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 214 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 215 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 216 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 217 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 218 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 219 "data//maps/Route119/scripts.pory"
	step_end
# 220 "data//maps/Route119/scripts.pory"

# 221 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 222 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 223 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 224 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 225 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 226 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 227 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 228 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 229 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 230 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 231 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 232 "data//maps/Route119/scripts.pory"
	step_end
# 233 "data//maps/Route119/scripts.pory"

# 234 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 235 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 236 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 237 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 238 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 239 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 240 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 241 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 242 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 243 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 244 "data//maps/Route119/scripts.pory"
	step_end
# 245 "data//maps/Route119/scripts.pory"

# 246 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 247 "data//maps/Route119/scripts.pory"
	walk_fast_left
# 248 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 249 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 250 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 251 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 252 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 253 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 254 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 255 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 256 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 257 "data//maps/Route119/scripts.pory"
	step_end
# 258 "data//maps/Route119/scripts.pory"

# 259 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 260 "data//maps/Route119/scripts.pory"
	walk_down
# 261 "data//maps/Route119/scripts.pory"
	walk_down
# 262 "data//maps/Route119/scripts.pory"
	walk_down
# 263 "data//maps/Route119/scripts.pory"
	walk_down
# 264 "data//maps/Route119/scripts.pory"
	walk_left
# 265 "data//maps/Route119/scripts.pory"
	walk_left
# 266 "data//maps/Route119/scripts.pory"
	walk_down
# 267 "data//maps/Route119/scripts.pory"
	step_end
# 268 "data//maps/Route119/scripts.pory"

# 269 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 270 "data//maps/Route119/scripts.pory"
	walk_up
# 271 "data//maps/Route119/scripts.pory"
	walk_right
# 272 "data//maps/Route119/scripts.pory"
	walk_right
# 273 "data//maps/Route119/scripts.pory"
	walk_up
# 274 "data//maps/Route119/scripts.pory"
	walk_up
# 275 "data//maps/Route119/scripts.pory"
	walk_up
# 276 "data//maps/Route119/scripts.pory"
	walk_up
# 277 "data//maps/Route119/scripts.pory"
	walk_up
# 278 "data//maps/Route119/scripts.pory"
	step_end
# 279 "data//maps/Route119/scripts.pory"

# 280 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 281 "data//maps/Route119/scripts.pory"
	walk_up
# 282 "data//maps/Route119/scripts.pory"
	walk_right
# 283 "data//maps/Route119/scripts.pory"
	walk_up
# 284 "data//maps/Route119/scripts.pory"
	walk_up
# 285 "data//maps/Route119/scripts.pory"
	walk_up
# 286 "data//maps/Route119/scripts.pory"
	walk_up
# 287 "data//maps/Route119/scripts.pory"
	walk_up
# 288 "data//maps/Route119/scripts.pory"
	step_end
# 289 "data//maps/Route119/scripts.pory"

# 290 "data//maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 291 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 292 "data//maps/Route119/scripts.pory"
	end
# 293 "data//maps/Route119/scripts.pory"

# 294 "data//maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 295 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 296 "data//maps/Route119/scripts.pory"
	end
# 297 "data//maps/Route119/scripts.pory"

# 298 "data//maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 299 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 300 "data//maps/Route119/scripts.pory"
	end
# 301 "data//maps/Route119/scripts.pory"

# 302 "data//maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 303 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 304 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 305 "data//maps/Route119/scripts.pory"
	end
# 306 "data//maps/Route119/scripts.pory"

# 307 "data//maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 308 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 309 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 310 "data//maps/Route119/scripts.pory"
	end
# 311 "data//maps/Route119/scripts.pory"

# 312 "data//maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 313 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 314 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 315 "data//maps/Route119/scripts.pory"
	end
# 316 "data//maps/Route119/scripts.pory"

# 317 "data//maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 318 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 319 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 320 "data//maps/Route119/scripts.pory"
	end
# 321 "data//maps/Route119/scripts.pory"

# 322 "data//maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 323 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 324 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 325 "data//maps/Route119/scripts.pory"
	end
# 326 "data//maps/Route119/scripts.pory"

# 327 "data//maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 328 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 329 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 330 "data//maps/Route119/scripts.pory"
	end
# 331 "data//maps/Route119/scripts.pory"

# 332 "data//maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 333 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 334 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 335 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 336 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 337 "data//maps/Route119/scripts.pory"
	release
# 338 "data//maps/Route119/scripts.pory"
	end
# 339 "data//maps/Route119/scripts.pory"

# 340 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 341 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 342 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 343 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 344 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 345 "data//maps/Route119/scripts.pory"
	release
# 346 "data//maps/Route119/scripts.pory"
	end
# 347 "data//maps/Route119/scripts.pory"

# 348 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 349 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 350 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 351 "data//maps/Route119/scripts.pory"
	end
# 352 "data//maps/Route119/scripts.pory"

# 353 "data//maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 354 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 355 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 356 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 357 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 358 "data//maps/Route119/scripts.pory"
	release
# 359 "data//maps/Route119/scripts.pory"
	end
# 360 "data//maps/Route119/scripts.pory"

# 361 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 362 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 363 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 364 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 365 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 366 "data//maps/Route119/scripts.pory"
	release
# 367 "data//maps/Route119/scripts.pory"
	end
# 368 "data//maps/Route119/scripts.pory"

# 369 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 370 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 371 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 372 "data//maps/Route119/scripts.pory"
	end
# 373 "data//maps/Route119/scripts.pory"

# 374 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 375 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 376 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 377 "data//maps/Route119/scripts.pory"
	end
# 378 "data//maps/Route119/scripts.pory"

# 379 "data//maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 380 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 381 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 382 "data//maps/Route119/scripts.pory"
	end
# 383 "data//maps/Route119/scripts.pory"

# 384 "data//maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 385 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 386 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 387 "data//maps/Route119/scripts.pory"
	end
# 388 "data//maps/Route119/scripts.pory"

# 389 "data//maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 390 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 391 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 392 "data//maps/Route119/scripts.pory"
	end
# 393 "data//maps/Route119/scripts.pory"

# 394 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 395 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 396 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 397 "data//maps/Route119/scripts.pory"
	end
# 398 "data//maps/Route119/scripts.pory"

# 399 "data//maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 400 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 401 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 402 "data//maps/Route119/scripts.pory"
	end
# 403 "data//maps/Route119/scripts.pory"

# 404 "data//maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 405 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 406 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 407 "data//maps/Route119/scripts.pory"
	end
# 408 "data//maps/Route119/scripts.pory"

# 409 "data//maps/Route119/scripts.pory"
Route119_EventScript_Daemon::
# 410 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAEMON, Route119_Text_DaemonIntro, Route119_Text_DaemonDefeat
# 411 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaemonPostBattle, MSGBOX_AUTOCLOSE
# 412 "data//maps/Route119/scripts.pory"
	end
# 413 "data//maps/Route119/scripts.pory"

# 414 "data//maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 415 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 416 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 417 "data//maps/Route119/scripts.pory"
	end
# 418 "data//maps/Route119/scripts.pory"

# 419 "data//maps/Route119/scripts.pory"
Route119_EventScript_Rachel::
# 420 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
# 421 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
# 422 "data//maps/Route119/scripts.pory"
	end
# 423 "data//maps/Route119/scripts.pory"

# 424 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 425 "data//maps/Route119/scripts.pory"
	lock
# 426 "data//maps/Route119/scripts.pory"
	faceplayer
# 427 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 428 "data//maps/Route119/scripts.pory"
	closemessage
# 429 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 430 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 431 "data//maps/Route119/scripts.pory"
	release
# 432 "data//maps/Route119/scripts.pory"
	end
# 433 "data//maps/Route119/scripts.pory"

# 434 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 435 "data//maps/Route119/scripts.pory"
	lock
# 436 "data//maps/Route119/scripts.pory"
	faceplayer
# 437 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 438 "data//maps/Route119/scripts.pory"
	closemessage
# 439 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 440 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 441 "data//maps/Route119/scripts.pory"
	release
# 442 "data//maps/Route119/scripts.pory"
	end
# 443 "data//maps/Route119/scripts.pory"

# 444 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 445 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 446 "data//maps/Route119/scripts.pory"
	end
# 447 "data//maps/Route119/scripts.pory"

# 448 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 449 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 450 "data//maps/Route119/scripts.pory"
	end
# 451 "data//maps/Route119/scripts.pory"

# 452 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 453 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 454 "data//maps/Route119/scripts.pory"
	end
# 455 "data//maps/Route119/scripts.pory"

# 456 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 457 "data//maps/Route119/scripts.pory"
	lockall
# 458 "data//maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 459 "data//maps/Route119/scripts.pory"
	waitmessage
# 460 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 461 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 462 "data//maps/Route119/scripts.pory"
	releaseall
# 463 "data//maps/Route119/scripts.pory"
	end
# 464 "data//maps/Route119/scripts.pory"

# 465 "data//maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 466 "data//maps/Route119/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 467 "data//maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 468 "data//maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 469 "data//maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 470 "data//maps/Route119/scripts.pory"
	.string "Ready with your POKéMON?\n"
# 471 "data//maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 472 "data//maps/Route119/scripts.pory"

# 473 "data//maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 474 "data//maps/Route119/scripts.pory"
	.string "Achah!\n"
# 475 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 476 "data//maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 477 "data//maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 478 "data//maps/Route119/scripts.pory"

# 479 "data//maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 480 "data//maps/Route119/scripts.pory"
	.string "MAY: But I had absolutely nothing to\n"
# 481 "data//maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 482 "data//maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 483 "data//maps/Route119/scripts.pory"

# 484 "data//maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 485 "data//maps/Route119/scripts.pory"
	.string "MAY: Use FLY, and your POKéMON will\n"
# 486 "data//maps/Route119/scripts.pory"
	.string "instantly carry you to any town you've\l"
# 487 "data//maps/Route119/scripts.pory"
	.string "already visited.\p"
# 488 "data//maps/Route119/scripts.pory"
	.string "But, to use FLY, you have to get\n"
# 489 "data//maps/Route119/scripts.pory"
	.string "the GYM BADGE from FORTREE CITY.\l"
# 490 "data//maps/Route119/scripts.pory"
	.string "That's important, so don't forget.\p"
# 491 "data//maps/Route119/scripts.pory"
	.string "You should FLY home and visit\n"
# 492 "data//maps/Route119/scripts.pory"
	.string "LITTLEROOT for a change.\p"
# 493 "data//maps/Route119/scripts.pory"
	.string "I bet your mom's worried about you,\n"
# 494 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 495 "data//maps/Route119/scripts.pory"
	.string "Well, let's meet again somewhere!$"
# 496 "data//maps/Route119/scripts.pory"

# 497 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 498 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: {PLAYER}! So this is where\n"
# 499 "data//maps/Route119/scripts.pory"
	.string "you've been looking for POKéMON?\p"
# 500 "data//maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 501 "data//maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 502 "data//maps/Route119/scripts.pory"
	.string "Now!\n"
# 503 "data//maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 504 "data//maps/Route119/scripts.pory"

# 505 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 506 "data//maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 507 "data//maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 508 "data//maps/Route119/scripts.pory"

# 509 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 510 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: I'd say you're good enough\n"
# 511 "data//maps/Route119/scripts.pory"
	.string "to search for POKéMON anywhere.\p"
# 512 "data//maps/Route119/scripts.pory"
	.string "Here, I'll give you this.\n"
# 513 "data//maps/Route119/scripts.pory"
	.string "Try it out.$"
# 514 "data//maps/Route119/scripts.pory"

# 515 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 516 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: Use FLY, and your POKéMON\n"
# 517 "data//maps/Route119/scripts.pory"
	.string "instantly carries you to any town\l"
# 518 "data//maps/Route119/scripts.pory"
	.string "you've already visited.\p"
# 519 "data//maps/Route119/scripts.pory"
	.string "But you need the FORTREE GYM BADGE \n"
# 520 "data//maps/Route119/scripts.pory"
	.string "to do that.\p"
# 521 "data//maps/Route119/scripts.pory"
	.string "Anyway, I have to move along.$"
# 522 "data//maps/Route119/scripts.pory"

# 523 "data//maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 524 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hahahah!\n"
# 525 "data//maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 526 "data//maps/Route119/scripts.pory"
	.string "I just passed by a TRAINER riding\n"
# 527 "data//maps/Route119/scripts.pory"
	.string "a BIKE.\p"
# 528 "data//maps/Route119/scripts.pory"
	.string "You just beat that TRAINER, didn't you?\n"
# 529 "data//maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 530 "data//maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 531 "data//maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 532 "data//maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 533 "data//maps/Route119/scripts.pory"
	.string "Are you off to FORTREE GYM next?\p"
# 534 "data//maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the GYM.\n"
# 535 "data//maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 536 "data//maps/Route119/scripts.pory"

# 537 "data//maps/Route119/scripts.pory"

# 538 "data//maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 539 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 540 "data//maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 541 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
# 542 "data//maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 543 "data//maps/Route119/scripts.pory"
	.string "the FORTREE GYM.\p"
# 544 "data//maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 545 "data//maps/Route119/scripts.pory"
	.string "Perhaps you really are the TRAINER\l"
# 546 "data//maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 547 "data//maps/Route119/scripts.pory"
	.string "Remember, you have a fan in me.\n"
# 548 "data//maps/Route119/scripts.pory"
	.string "I'll be cheering from the sidelines.\l"
# 549 "data//maps/Route119/scripts.pory"
	.string "Keep up the great work!\p"
# 550 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 551 "data//maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 552 "data//maps/Route119/scripts.pory"

# 553 "data//maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 554 "data//maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 555 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the WEATHER\n"
# 556 "data//maps/Route119/scripts.pory"
	.string "INSTITUTE. It's not safe.$"
# 557 "data//maps/Route119/scripts.pory"

# 558 "data//maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 559 "data//maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 560 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 561 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE.$"
# 562 "data//maps/Route119/scripts.pory"

# 563 "data//maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 564 "data//maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 565 "data//maps/Route119/scripts.pory"
	.string "flock of BIRD POKéMON, and then\l"
# 566 "data//maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 567 "data//maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 568 "data//maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 569 "data//maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 570 "data//maps/Route119/scripts.pory"
	.string "time ago…$"
# 571 "data//maps/Route119/scripts.pory"

# 572 "data//maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 573 "data//maps/Route119/scripts.pory"
	.string "Tch…\n"
# 574 "data//maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 575 "data//maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 576 "data//maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 577 "data//maps/Route119/scripts.pory"

# 578 "data//maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 579 "data//maps/Route119/scripts.pory"
	.string "Can your POKéMON use its SECRET POWER\n"
# 580 "data//maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 581 "data//maps/Route119/scripts.pory"
	.string "SECRET BASE?$"
# 582 "data//maps/Route119/scripts.pory"

# 583 "data//maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 584 "data//maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 585 "data//maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 586 "data//maps/Route119/scripts.pory"

# 587 "data//maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 588 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 589 "data//maps/Route119/scripts.pory"

# 590 "data//maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 591 "data//maps/Route119/scripts.pory"
	.string "TRAINER TIPS\p"
# 592 "data//maps/Route119/scripts.pory"
	.string "Up to sixteen decorations and\n"
# 593 "data//maps/Route119/scripts.pory"
	.string "furniture items can be placed in\l"
# 594 "data//maps/Route119/scripts.pory"
	.string "a SECRET BASE.\p"
# 595 "data//maps/Route119/scripts.pory"
	.string "Pick your favorite items and create\n"
# 596 "data//maps/Route119/scripts.pory"
	.string "your very own SECRET BASE exactly the\l"
# 597 "data//maps/Route119/scripts.pory"
	.string "way you want.$"
