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
	goto_if_set FLAG_BADGE08_GET, Route119_EventScript_TrySetupStevenScene
# 23 "data//maps/Route119/scripts.pory"
	end
# 24 "data//maps/Route119/scripts.pory"

# 25 "data//maps/Route119/scripts.pory"
Route119_EventScript_MoveInstituteWorkersDownstairs::
# 26 "data//maps/Route119/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 27 "data//maps/Route119/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
# 28 "data//maps/Route119/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
# 29 "data//maps/Route119/scripts.pory"
	return
# 30 "data//maps/Route119/scripts.pory"

# 31 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrySetupStevenScene::
# 32 "data//maps/Route119/scripts.pory"
	goto_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route119_EventScript_SetupStevenScene
# 33 "data//maps/Route119/scripts.pory"
	return
# 34 "data//maps/Route119/scripts.pory"

# 35 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetupStevenScene::
# 36 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 2
# 37 "data//maps/Route119/scripts.pory"
	return
# 38 "data//maps/Route119/scripts.pory"

# 39 "data//maps/Route119/scripts.pory"
Route119_EventScript_StevenScene1::
# 40 "data//maps/Route119/scripts.pory"
	lock
# 41 "data//maps/Route119/scripts.pory"
	showobjectat LOCALID_ROUTE119_STEVEN, MAP_ROUTE119
# 42 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Route119_Movement_StevenApproach1
# 43 "data//maps/Route119/scripts.pory"
	delay 40
# 44 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 45 "data//maps/Route119/scripts.pory"
	waitmovement
# 46 "data//maps/Route119/scripts.pory"
	delay 60
# 47 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven1, MSGBOX_DEFAULT
# 48 "data//maps/Route119/scripts.pory"
	closemessage
# 49 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_WalkInPlaceDown
# 50 "data//maps/Route119/scripts.pory"
	waitmovement
# 51 "data//maps/Route119/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 52 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 53 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven2, MSGBOX_DEFAULT
# 54 "data//maps/Route119/scripts.pory"
	closemessage
# 55 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_FaceUp
# 56 "data//maps/Route119/scripts.pory"
	waitmovement
# 57 "data//maps/Route119/scripts.pory"
	delay 45
# 58 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_FacePlayer
# 59 "data//maps/Route119/scripts.pory"
	waitmovement
# 60 "data//maps/Route119/scripts.pory"
	delay 20
# 61 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven3, MSGBOX_DEFAULT
# 62 "data//maps/Route119/scripts.pory"
	closemessage
# 63 "data//maps/Route119/scripts.pory"
	delay 30
# 64 "data//maps/Route119/scripts.pory"
	setfieldeffectargument 0, 1
# 65 "data//maps/Route119/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 66 "data//maps/Route119/scripts.pory"
	delay 15
# 67 "data//maps/Route119/scripts.pory"
	setobjectxy LOCALID_ROUTE119_STEVEN, 26, 21
# 68 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_STEVEN, 26, 21
# 69 "data//maps/Route119/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 70 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 3
# 71 "data//maps/Route119/scripts.pory"
	setflag FLAG_MISTCLAD_COVE_RIVAL
# 72 "data//maps/Route119/scripts.pory"
	release
# 73 "data//maps/Route119/scripts.pory"
	end
# 74 "data//maps/Route119/scripts.pory"

# 75 "data//maps/Route119/scripts.pory"
Route119_EventScript_StevenScene2::
# 76 "data//maps/Route119/scripts.pory"
	lock
# 77 "data//maps/Route119/scripts.pory"
	showobjectat LOCALID_ROUTE119_STEVEN, MAP_ROUTE119
# 78 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Route119_Movement_StevenApproach2
# 79 "data//maps/Route119/scripts.pory"
	delay 55
# 80 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 81 "data//maps/Route119/scripts.pory"
	waitmovement
# 82 "data//maps/Route119/scripts.pory"
	delay 60
# 83 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven1, MSGBOX_DEFAULT
# 84 "data//maps/Route119/scripts.pory"
	closemessage
# 85 "data//maps/Route119/scripts.pory"
	delay 15
# 86 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_WalkInPlaceDown
# 87 "data//maps/Route119/scripts.pory"
	waitmovement
# 88 "data//maps/Route119/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 89 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 90 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven2, MSGBOX_DEFAULT
# 91 "data//maps/Route119/scripts.pory"
	closemessage
# 92 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_FaceUp
# 93 "data//maps/Route119/scripts.pory"
	waitmovement
# 94 "data//maps/Route119/scripts.pory"
	delay 45
# 95 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_STEVEN, Common_Movement_FacePlayer
# 96 "data//maps/Route119/scripts.pory"
	waitmovement
# 97 "data//maps/Route119/scripts.pory"
	delay 20
# 98 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_Steven3, MSGBOX_DEFAULT
# 99 "data//maps/Route119/scripts.pory"
	closemessage
# 100 "data//maps/Route119/scripts.pory"
	delay 30
# 101 "data//maps/Route119/scripts.pory"
	setfieldeffectargument 0, 1
# 102 "data//maps/Route119/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 103 "data//maps/Route119/scripts.pory"
	delay 15
# 104 "data//maps/Route119/scripts.pory"
	setobjectxy LOCALID_ROUTE119_STEVEN, 26, 21
# 105 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_STEVEN, 26, 21
# 106 "data//maps/Route119/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 107 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 3
# 108 "data//maps/Route119/scripts.pory"
	setflag FLAG_MISTCLAD_COVE_RIVAL
# 109 "data//maps/Route119/scripts.pory"
	release
# 110 "data//maps/Route119/scripts.pory"
	end
# 111 "data//maps/Route119/scripts.pory"

# 112 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger1::
# 113 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 1
# 114 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 115 "data//maps/Route119/scripts.pory"
	end
# 116 "data//maps/Route119/scripts.pory"

# 117 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger2::
# 118 "data//maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 2
# 119 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 120 "data//maps/Route119/scripts.pory"
	end
# 121 "data//maps/Route119/scripts.pory"

# 122 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEncounter::
# 123 "data//maps/Route119/scripts.pory"
	lockall
# 124 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 125 "data//maps/Route119/scripts.pory"
	checkplayergender
# 126 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
# 127 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
# 128 "data//maps/Route119/scripts.pory"
	delay 65
# 129 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
# 130 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
# 131 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 132 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 133 "data//maps/Route119/scripts.pory"
	delay 30
# 134 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 135 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 136 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 137 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL
# 138 "data//maps/Route119/scripts.pory"
	delay 30
# 139 "data//maps/Route119/scripts.pory"
	checkplayergender
# 140 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
# 141 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
# 142 "data//maps/Route119/scripts.pory"
	releaseall
# 143 "data//maps/Route119/scripts.pory"
	end
# 144 "data//maps/Route119/scripts.pory"

# 145 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayMayMusic::
# 146 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 147 "data//maps/Route119/scripts.pory"
	return
# 148 "data//maps/Route119/scripts.pory"

# 149 "data//maps/Route119/scripts.pory"
Route119_EventScript_PlayBrendanMusic::
# 150 "data//maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 151 "data//maps/Route119/scripts.pory"
	return
# 152 "data//maps/Route119/scripts.pory"

# 153 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMay::
# 154 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
# 155 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 156 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartMayBattle
# 157 "data//maps/Route119/scripts.pory"
	end
# 158 "data//maps/Route119/scripts.pory"

# 159 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartMayBattle::
# 160 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_A, Route119_Text_MayDefeat
# 161 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 162 "data//maps/Route119/scripts.pory"
	end
# 163 "data//maps/Route119/scripts.pory"

# 164 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 165 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 166 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 167 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 168 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 169 "data//maps/Route119/scripts.pory"
	end
# 170 "data//maps/Route119/scripts.pory"

# 171 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 172 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 173 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 174 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_StartBrendanBattle
# 175 "data//maps/Route119/scripts.pory"
	end
# 176 "data//maps/Route119/scripts.pory"

# 177 "data//maps/Route119/scripts.pory"
Route119_EventScript_StartBrendanBattle::
# 178 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_A, Route119_Text_BrendanDefeat
# 179 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 180 "data//maps/Route119/scripts.pory"
	end
# 181 "data//maps/Route119/scripts.pory"

# 182 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 183 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 184 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 185 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 186 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 187 "data//maps/Route119/scripts.pory"
	end
# 188 "data//maps/Route119/scripts.pory"

# 189 "data//maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 190 "data//maps/Route119/scripts.pory"
	giveitem ITEM_HM_FLY
# 191 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 192 "data//maps/Route119/scripts.pory"
	return
# 193 "data//maps/Route119/scripts.pory"

# 194 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 195 "data//maps/Route119/scripts.pory"
	closemessage
# 196 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 197 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 198 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL
# 199 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 200 "data//maps/Route119/scripts.pory"
	delay 30
# 201 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 202 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 203 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
# 204 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 205 "data//maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 206 "data//maps/Route119/scripts.pory"
	fadedefaultbgm
# 207 "data//maps/Route119/scripts.pory"
	delay 60
# 208 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 209 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 210 "data//maps/Route119/scripts.pory"
	addobject LOCALID_ROUTE119_SCOTT
# 211 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
# 212 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 213 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 214 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 215 "data//maps/Route119/scripts.pory"
	closemessage
# 216 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 217 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 218 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_ROUTE119_SCOTT
# 219 "data//maps/Route119/scripts.pory"
	releaseall
# 220 "data//maps/Route119/scripts.pory"
	end
# 221 "data//maps/Route119/scripts.pory"

# 222 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 223 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
# 224 "data//maps/Route119/scripts.pory"
	return
# 225 "data//maps/Route119/scripts.pory"

# 226 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 227 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
# 228 "data//maps/Route119/scripts.pory"
	return
# 229 "data//maps/Route119/scripts.pory"

# 230 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 231 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
# 232 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 233 "data//maps/Route119/scripts.pory"
	return
# 234 "data//maps/Route119/scripts.pory"

# 235 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 236 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
# 237 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 238 "data//maps/Route119/scripts.pory"
	return
# 239 "data//maps/Route119/scripts.pory"

# 240 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 241 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 242 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 243 "data//maps/Route119/scripts.pory"
	return
# 244 "data//maps/Route119/scripts.pory"

# 245 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 246 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 247 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 248 "data//maps/Route119/scripts.pory"
	return
# 249 "data//maps/Route119/scripts.pory"

# 250 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 251 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 252 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 253 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 254 "data//maps/Route119/scripts.pory"
	return
# 255 "data//maps/Route119/scripts.pory"

# 256 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 257 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 258 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 259 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 260 "data//maps/Route119/scripts.pory"
	return
# 261 "data//maps/Route119/scripts.pory"

# 262 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 263 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
# 264 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
# 265 "data//maps/Route119/scripts.pory"
	return
# 266 "data//maps/Route119/scripts.pory"

# 267 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 268 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
# 269 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
# 270 "data//maps/Route119/scripts.pory"
	return
# 271 "data//maps/Route119/scripts.pory"

# 272 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 273 "data//maps/Route119/scripts.pory"
	delay_16
# 274 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 275 "data//maps/Route119/scripts.pory"
	delay_8
# 276 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 277 "data//maps/Route119/scripts.pory"
	step_end
# 278 "data//maps/Route119/scripts.pory"

# 279 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 280 "data//maps/Route119/scripts.pory"
	delay_16
# 281 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 282 "data//maps/Route119/scripts.pory"
	delay_8
# 283 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 284 "data//maps/Route119/scripts.pory"
	step_end
# 285 "data//maps/Route119/scripts.pory"

# 286 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
# 287 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 288 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 289 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 290 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 291 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 292 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 293 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 294 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 295 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 296 "data//maps/Route119/scripts.pory"
	step_end
# 297 "data//maps/Route119/scripts.pory"

# 298 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 299 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 300 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 301 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 302 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 303 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 304 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 305 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 306 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 307 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 308 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 309 "data//maps/Route119/scripts.pory"
	step_end
# 310 "data//maps/Route119/scripts.pory"

# 311 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 312 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 313 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 314 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 315 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 316 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 317 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 318 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 319 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 320 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 321 "data//maps/Route119/scripts.pory"
	step_end
# 322 "data//maps/Route119/scripts.pory"

# 323 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 324 "data//maps/Route119/scripts.pory"
	walk_fast_left
# 325 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 326 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 327 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 328 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 329 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 330 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 331 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 332 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 333 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 334 "data//maps/Route119/scripts.pory"
	step_end
# 335 "data//maps/Route119/scripts.pory"

# 336 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 337 "data//maps/Route119/scripts.pory"
	walk_down
# 338 "data//maps/Route119/scripts.pory"
	walk_down
# 339 "data//maps/Route119/scripts.pory"
	walk_down
# 340 "data//maps/Route119/scripts.pory"
	walk_down
# 341 "data//maps/Route119/scripts.pory"
	walk_left
# 342 "data//maps/Route119/scripts.pory"
	walk_left
# 343 "data//maps/Route119/scripts.pory"
	walk_down
# 344 "data//maps/Route119/scripts.pory"
	step_end
# 345 "data//maps/Route119/scripts.pory"

# 346 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 347 "data//maps/Route119/scripts.pory"
	walk_up
# 348 "data//maps/Route119/scripts.pory"
	walk_right
# 349 "data//maps/Route119/scripts.pory"
	walk_right
# 350 "data//maps/Route119/scripts.pory"
	walk_up
# 351 "data//maps/Route119/scripts.pory"
	walk_up
# 352 "data//maps/Route119/scripts.pory"
	walk_up
# 353 "data//maps/Route119/scripts.pory"
	walk_up
# 354 "data//maps/Route119/scripts.pory"
	walk_up
# 355 "data//maps/Route119/scripts.pory"
	step_end
# 356 "data//maps/Route119/scripts.pory"

# 357 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 358 "data//maps/Route119/scripts.pory"
	walk_up
# 359 "data//maps/Route119/scripts.pory"
	walk_right
# 360 "data//maps/Route119/scripts.pory"
	walk_up
# 361 "data//maps/Route119/scripts.pory"
	walk_up
# 362 "data//maps/Route119/scripts.pory"
	walk_up
# 363 "data//maps/Route119/scripts.pory"
	walk_up
# 364 "data//maps/Route119/scripts.pory"
	walk_up
# 365 "data//maps/Route119/scripts.pory"
	step_end
# 366 "data//maps/Route119/scripts.pory"

# 367 "data//maps/Route119/scripts.pory"
Route119_Movement_StevenApproach1:
# 368 "data//maps/Route119/scripts.pory"
	walk_right
# 369 "data//maps/Route119/scripts.pory"
	walk_down
# 370 "data//maps/Route119/scripts.pory"
	walk_down
# 371 "data//maps/Route119/scripts.pory"
	walk_down
# 372 "data//maps/Route119/scripts.pory"
	walk_down
# 373 "data//maps/Route119/scripts.pory"
	walk_down
# 374 "data//maps/Route119/scripts.pory"
	step_end
# 375 "data//maps/Route119/scripts.pory"

# 376 "data//maps/Route119/scripts.pory"
Route119_Movement_StevenApproach2:
# 377 "data//maps/Route119/scripts.pory"
	walk_right
# 378 "data//maps/Route119/scripts.pory"
	walk_right
# 379 "data//maps/Route119/scripts.pory"
	walk_down
# 380 "data//maps/Route119/scripts.pory"
	walk_down
# 381 "data//maps/Route119/scripts.pory"
	walk_down
# 382 "data//maps/Route119/scripts.pory"
	walk_down
# 383 "data//maps/Route119/scripts.pory"
	walk_down
# 384 "data//maps/Route119/scripts.pory"
	step_end
# 385 "data//maps/Route119/scripts.pory"

# 386 "data//maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 387 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 388 "data//maps/Route119/scripts.pory"
	end
# 389 "data//maps/Route119/scripts.pory"

# 390 "data//maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 391 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 392 "data//maps/Route119/scripts.pory"
	end
# 393 "data//maps/Route119/scripts.pory"

# 394 "data//maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 395 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 396 "data//maps/Route119/scripts.pory"
	end
# 397 "data//maps/Route119/scripts.pory"

# 398 "data//maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 399 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 400 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 401 "data//maps/Route119/scripts.pory"
	end
# 402 "data//maps/Route119/scripts.pory"

# 403 "data//maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 404 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 405 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 406 "data//maps/Route119/scripts.pory"
	end
# 407 "data//maps/Route119/scripts.pory"

# 408 "data//maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 409 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 410 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 411 "data//maps/Route119/scripts.pory"
	end
# 412 "data//maps/Route119/scripts.pory"

# 413 "data//maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 414 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 415 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 416 "data//maps/Route119/scripts.pory"
	end
# 417 "data//maps/Route119/scripts.pory"

# 418 "data//maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 419 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 420 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 421 "data//maps/Route119/scripts.pory"
	end
# 422 "data//maps/Route119/scripts.pory"

# 423 "data//maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 424 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 425 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 426 "data//maps/Route119/scripts.pory"
	end
# 427 "data//maps/Route119/scripts.pory"

# 428 "data//maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 429 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 430 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 431 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 432 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 433 "data//maps/Route119/scripts.pory"
	release
# 434 "data//maps/Route119/scripts.pory"
	end
# 435 "data//maps/Route119/scripts.pory"

# 436 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 437 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 438 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 439 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 440 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 441 "data//maps/Route119/scripts.pory"
	release
# 442 "data//maps/Route119/scripts.pory"
	end
# 443 "data//maps/Route119/scripts.pory"

# 444 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 445 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 446 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 447 "data//maps/Route119/scripts.pory"
	end
# 448 "data//maps/Route119/scripts.pory"

# 449 "data//maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 450 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 451 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 452 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 453 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 454 "data//maps/Route119/scripts.pory"
	release
# 455 "data//maps/Route119/scripts.pory"
	end
# 456 "data//maps/Route119/scripts.pory"

# 457 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 458 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 459 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 460 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 461 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 462 "data//maps/Route119/scripts.pory"
	release
# 463 "data//maps/Route119/scripts.pory"
	end
# 464 "data//maps/Route119/scripts.pory"

# 465 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 466 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 467 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 468 "data//maps/Route119/scripts.pory"
	end
# 469 "data//maps/Route119/scripts.pory"

# 470 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 471 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 472 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 473 "data//maps/Route119/scripts.pory"
	end
# 474 "data//maps/Route119/scripts.pory"

# 475 "data//maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 476 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 477 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 478 "data//maps/Route119/scripts.pory"
	end
# 479 "data//maps/Route119/scripts.pory"

# 480 "data//maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 481 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 482 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 483 "data//maps/Route119/scripts.pory"
	end
# 484 "data//maps/Route119/scripts.pory"

# 485 "data//maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 486 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 487 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 488 "data//maps/Route119/scripts.pory"
	end
# 489 "data//maps/Route119/scripts.pory"

# 490 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 491 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 492 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 493 "data//maps/Route119/scripts.pory"
	end
# 494 "data//maps/Route119/scripts.pory"

# 495 "data//maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 496 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 497 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 498 "data//maps/Route119/scripts.pory"
	end
# 499 "data//maps/Route119/scripts.pory"

# 500 "data//maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 501 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 502 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 503 "data//maps/Route119/scripts.pory"
	end
# 504 "data//maps/Route119/scripts.pory"

# 505 "data//maps/Route119/scripts.pory"
Route119_EventScript_Daemon::
# 506 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAEMON, Route119_Text_DaemonIntro, Route119_Text_DaemonDefeat
# 507 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaemonPostBattle, MSGBOX_AUTOCLOSE
# 508 "data//maps/Route119/scripts.pory"
	end
# 509 "data//maps/Route119/scripts.pory"

# 510 "data//maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 511 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 512 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 513 "data//maps/Route119/scripts.pory"
	end
# 514 "data//maps/Route119/scripts.pory"

# 515 "data//maps/Route119/scripts.pory"
Route119_EventScript_Rachel::
# 516 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
# 517 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
# 518 "data//maps/Route119/scripts.pory"
	end
# 519 "data//maps/Route119/scripts.pory"

# 520 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 521 "data//maps/Route119/scripts.pory"
	lock
# 522 "data//maps/Route119/scripts.pory"
	faceplayer
# 523 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 524 "data//maps/Route119/scripts.pory"
	closemessage
# 525 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 526 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 527 "data//maps/Route119/scripts.pory"
	release
# 528 "data//maps/Route119/scripts.pory"
	end
# 529 "data//maps/Route119/scripts.pory"

# 530 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 531 "data//maps/Route119/scripts.pory"
	lock
# 532 "data//maps/Route119/scripts.pory"
	faceplayer
# 533 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 534 "data//maps/Route119/scripts.pory"
	closemessage
# 535 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 536 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 537 "data//maps/Route119/scripts.pory"
	release
# 538 "data//maps/Route119/scripts.pory"
	end
# 539 "data//maps/Route119/scripts.pory"

# 540 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 541 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 542 "data//maps/Route119/scripts.pory"
	end
# 543 "data//maps/Route119/scripts.pory"

# 544 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 545 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 546 "data//maps/Route119/scripts.pory"
	end
# 547 "data//maps/Route119/scripts.pory"

# 548 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 549 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 550 "data//maps/Route119/scripts.pory"
	end
# 551 "data//maps/Route119/scripts.pory"

# 552 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 553 "data//maps/Route119/scripts.pory"
	lockall
# 554 "data//maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 555 "data//maps/Route119/scripts.pory"
	waitmessage
# 556 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 557 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 558 "data//maps/Route119/scripts.pory"
	releaseall
# 559 "data//maps/Route119/scripts.pory"
	end
# 560 "data//maps/Route119/scripts.pory"

# 561 "data//maps/Route119/scripts.pory"
Route119_Text_Steven1:
# 562 "data//maps/Route119/scripts.pory"
	.string "STEVEN: {PLAYER}!\n"
# 563 "data//maps/Route119/scripts.pory"
	.string "I thought you might be around here!\p"
# 564 "data//maps/Route119/scripts.pory"
	.string "I saw RAYQUAZA fly this way after\n"
# 565 "data//maps/Route119/scripts.pory"
	.string "the events in SOOTOPOLIS.\p"
# 566 "data//maps/Route119/scripts.pory"
	.string "Oh! But I guess you must be on your way\n"
# 567 "data//maps/Route119/scripts.pory"
	.string "to complete your BADGE collection.\p"
# 568 "data//maps/Route119/scripts.pory"
	.string "WINONA can be hard to track down\n"
# 569 "data//maps/Route119/scripts.pory"
	.string "sometimes, so this may come in handy.$"
# 570 "data//maps/Route119/scripts.pory"

# 571 "data//maps/Route119/scripts.pory"
Route119_Text_Steven2:
# 572 "data//maps/Route119/scripts.pory"
	.string "That's something the old man's company\n"
# 573 "data//maps/Route119/scripts.pory"
	.string "cooked up to deal with all the pesky\l"
# 574 "data//maps/Route119/scripts.pory"
	.string "KECLEON who live around here.$"
# 575 "data//maps/Route119/scripts.pory"

# 576 "data//maps/Route119/scripts.pory"
Route119_Text_Steven3:
# 577 "data//maps/Route119/scripts.pory"
	.string "Good luck, {PLAYER}.\p"
# 578 "data//maps/Route119/scripts.pory"
	.string "I'm sure I'll see you again very soon…$"
# 579 "data//maps/Route119/scripts.pory"

# 580 "data//maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 581 "data//maps/Route119/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 582 "data//maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 583 "data//maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 584 "data//maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 585 "data//maps/Route119/scripts.pory"
	.string "Ready with your POKéMON?\n"
# 586 "data//maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 587 "data//maps/Route119/scripts.pory"

# 588 "data//maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 589 "data//maps/Route119/scripts.pory"
	.string "Achah!\n"
# 590 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 591 "data//maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 592 "data//maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 593 "data//maps/Route119/scripts.pory"

# 594 "data//maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 595 "data//maps/Route119/scripts.pory"
	.string "MAY: But I had absolutely nothing to\n"
# 596 "data//maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 597 "data//maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 598 "data//maps/Route119/scripts.pory"

# 599 "data//maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 600 "data//maps/Route119/scripts.pory"
	.string "MAY: Use FLY, and your POKéMON will\n"
# 601 "data//maps/Route119/scripts.pory"
	.string "instantly carry you to any town you've\l"
# 602 "data//maps/Route119/scripts.pory"
	.string "already visited.\p"
# 603 "data//maps/Route119/scripts.pory"
	.string "But, to use FLY, you have to get\n"
# 604 "data//maps/Route119/scripts.pory"
	.string "the GYM BADGE from FORTREE CITY.\l"
# 605 "data//maps/Route119/scripts.pory"
	.string "That's important, so don't forget.\p"
# 606 "data//maps/Route119/scripts.pory"
	.string "You should FLY home and visit\n"
# 607 "data//maps/Route119/scripts.pory"
	.string "LITTLEROOT for a change.\p"
# 608 "data//maps/Route119/scripts.pory"
	.string "I bet your mom's worried about you,\n"
# 609 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 610 "data//maps/Route119/scripts.pory"
	.string "Well, let's meet again somewhere!$"
# 611 "data//maps/Route119/scripts.pory"

# 612 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 613 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: {PLAYER}! So this is where\n"
# 614 "data//maps/Route119/scripts.pory"
	.string "you've been looking for POKéMON?\p"
# 615 "data//maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 616 "data//maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 617 "data//maps/Route119/scripts.pory"
	.string "Now!\n"
# 618 "data//maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 619 "data//maps/Route119/scripts.pory"

# 620 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 621 "data//maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 622 "data//maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 623 "data//maps/Route119/scripts.pory"

# 624 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 625 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: I'd say you're good enough\n"
# 626 "data//maps/Route119/scripts.pory"
	.string "to search for POKéMON anywhere.\p"
# 627 "data//maps/Route119/scripts.pory"
	.string "Here, I'll give you this.\n"
# 628 "data//maps/Route119/scripts.pory"
	.string "Try it out.$"
# 629 "data//maps/Route119/scripts.pory"

# 630 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 631 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: Use FLY, and your POKéMON\n"
# 632 "data//maps/Route119/scripts.pory"
	.string "instantly carries you to any town\l"
# 633 "data//maps/Route119/scripts.pory"
	.string "you've already visited.\p"
# 634 "data//maps/Route119/scripts.pory"
	.string "But you need the FORTREE GYM BADGE \n"
# 635 "data//maps/Route119/scripts.pory"
	.string "to do that.\p"
# 636 "data//maps/Route119/scripts.pory"
	.string "Anyway, I have to move along.$"
# 637 "data//maps/Route119/scripts.pory"

# 638 "data//maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 639 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hahahah!\n"
# 640 "data//maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 641 "data//maps/Route119/scripts.pory"
	.string "I just passed by a TRAINER riding\n"
# 642 "data//maps/Route119/scripts.pory"
	.string "a BIKE.\p"
# 643 "data//maps/Route119/scripts.pory"
	.string "You just beat that TRAINER, didn't you?\n"
# 644 "data//maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 645 "data//maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 646 "data//maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 647 "data//maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 648 "data//maps/Route119/scripts.pory"
	.string "Are you off to FORTREE GYM next?\p"
# 649 "data//maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the GYM.\n"
# 650 "data//maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 651 "data//maps/Route119/scripts.pory"

# 652 "data//maps/Route119/scripts.pory"

# 653 "data//maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 654 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 655 "data//maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 656 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
# 657 "data//maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 658 "data//maps/Route119/scripts.pory"
	.string "the FORTREE GYM.\p"
# 659 "data//maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 660 "data//maps/Route119/scripts.pory"
	.string "Perhaps you really are the TRAINER\l"
# 661 "data//maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 662 "data//maps/Route119/scripts.pory"
	.string "Remember, you have a fan in me.\n"
# 663 "data//maps/Route119/scripts.pory"
	.string "I'll be cheering from the sidelines.\l"
# 664 "data//maps/Route119/scripts.pory"
	.string "Keep up the great work!\p"
# 665 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 666 "data//maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 667 "data//maps/Route119/scripts.pory"

# 668 "data//maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 669 "data//maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 670 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the WEATHER\n"
# 671 "data//maps/Route119/scripts.pory"
	.string "INSTITUTE. It's not safe.$"
# 672 "data//maps/Route119/scripts.pory"

# 673 "data//maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 674 "data//maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 675 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 676 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE.$"
# 677 "data//maps/Route119/scripts.pory"

# 678 "data//maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 679 "data//maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 680 "data//maps/Route119/scripts.pory"
	.string "flock of BIRD POKéMON, and then\l"
# 681 "data//maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 682 "data//maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 683 "data//maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 684 "data//maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 685 "data//maps/Route119/scripts.pory"
	.string "time ago…$"
# 686 "data//maps/Route119/scripts.pory"

# 687 "data//maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 688 "data//maps/Route119/scripts.pory"
	.string "Tch…\n"
# 689 "data//maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 690 "data//maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 691 "data//maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 692 "data//maps/Route119/scripts.pory"

# 693 "data//maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 694 "data//maps/Route119/scripts.pory"
	.string "Can your POKéMON use its SECRET POWER\n"
# 695 "data//maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 696 "data//maps/Route119/scripts.pory"
	.string "SECRET BASE?$"
# 697 "data//maps/Route119/scripts.pory"

# 698 "data//maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 699 "data//maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 700 "data//maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 701 "data//maps/Route119/scripts.pory"

# 702 "data//maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 703 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 704 "data//maps/Route119/scripts.pory"

# 705 "data//maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 706 "data//maps/Route119/scripts.pory"
	.string "TRAINER TIPS\p"
# 707 "data//maps/Route119/scripts.pory"
	.string "Up to sixteen decorations and\n"
# 708 "data//maps/Route119/scripts.pory"
	.string "furniture items can be placed in\l"
# 709 "data//maps/Route119/scripts.pory"
	.string "a SECRET BASE.\p"
# 710 "data//maps/Route119/scripts.pory"
	.string "Pick your favorite items and create\n"
# 711 "data//maps/Route119/scripts.pory"
	.string "your very own SECRET BASE exactly the\l"
# 712 "data//maps/Route119/scripts.pory"
	.string "way you want.$"
