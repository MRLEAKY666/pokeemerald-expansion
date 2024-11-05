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
	case SPECIES_TREECKO, Route119_EventScript_BattleMayTreecko
# 80 "data//maps/Route119/scripts.pory"
	case SPECIES_TORCHIC, Route119_EventScript_BattleMayTorchic
# 81 "data//maps/Route119/scripts.pory"
	case SPECIES_MUDKIP, Route119_EventScript_BattleMayMudkip
# 82 "data//maps/Route119/scripts.pory"
	case SPECIES_CASTFORM, Route119_EventScript_BattleMayTreecko
# 83 "data//maps/Route119/scripts.pory"
	case SPECIES_PIPLUP, Route119_EventScript_BattleMayTorchic
# 84 "data//maps/Route119/scripts.pory"
	case SPECIES_EEVEE, Route119_EventScript_BattleMayMudkip
# 85 "data//maps/Route119/scripts.pory"
	case SPECIES_PICHU, Route119_EventScript_BattleMayTreecko
# 86 "data//maps/Route119/scripts.pory"
	case SPECIES_TOGEPI, Route119_EventScript_BattleMayTorchic
# 87 "data//maps/Route119/scripts.pory"
	case SPECIES_PORYGON, Route119_EventScript_BattleMayMudkip
# 88 "data//maps/Route119/scripts.pory"
	case SPECIES_SNIVY, Route119_EventScript_BattleMayTreecko
# 89 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, Route119_EventScript_BattleMayTorchic
# 90 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA, Route119_EventScript_BattleMayMudkip
# 91 "data//maps/Route119/scripts.pory"
	case SPECIES_GOTHITA, Route119_EventScript_BattleMayTreecko
# 92 "data//maps/Route119/scripts.pory"
	case SPECIES_SOLOSIS, Route119_EventScript_BattleMayTorchic
# 93 "data//maps/Route119/scripts.pory"
	case SPECIES_AXEW, Route119_EventScript_BattleMayMudkip
# 94 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVESTA, Route119_EventScript_BattleMayTreecko
# 95 "data//maps/Route119/scripts.pory"
	case SPECIES_GOOMY, Route119_EventScript_BattleMayTorchic
# 96 "data//maps/Route119/scripts.pory"
	case SPECIES_ROWLET, Route119_EventScript_BattleMayMudkip
# 97 "data//maps/Route119/scripts.pory"
	case SPECIES_APPLIN, Route119_EventScript_BattleMayTreecko
# 98 "data//maps/Route119/scripts.pory"
	case SPECIES_MIME_JR, Route119_EventScript_BattleMayTorchic
# 99 "data//maps/Route119/scripts.pory"
	case SPECIES_MAGBY, Route119_EventScript_BattleMayMudkip
# 100 "data//maps/Route119/scripts.pory"
	case SPECIES_ELEKID, Route119_EventScript_BattleMayTreecko
# 101 "data//maps/Route119/scripts.pory"
	case SPECIES_MANKEY, Route119_EventScript_BattleMayTorchic
# 102 "data//maps/Route119/scripts.pory"
	case SPECIES_SWINUB, Route119_EventScript_BattleMayMudkip
# 103 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVITAR, Route119_EventScript_BattleMayTreecko
# 104 "data//maps/Route119/scripts.pory"
	end
# 105 "data//maps/Route119/scripts.pory"

# 106 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayTreecko::
# 107 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
# 108 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 109 "data//maps/Route119/scripts.pory"
	end
# 110 "data//maps/Route119/scripts.pory"

# 111 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayTorchic::
# 112 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
# 113 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 114 "data//maps/Route119/scripts.pory"
	end
# 115 "data//maps/Route119/scripts.pory"

# 116 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayMudkip::
# 117 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
# 118 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 119 "data//maps/Route119/scripts.pory"
	end
# 120 "data//maps/Route119/scripts.pory"

# 121 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 122 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 123 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 124 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 125 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 126 "data//maps/Route119/scripts.pory"
	end
# 127 "data//maps/Route119/scripts.pory"

# 128 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 129 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 130 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 131 "data//maps/Route119/scripts.pory"
	case 0, Route119_EventScript_BattleBrendanTreecko
# 132 "data//maps/Route119/scripts.pory"
	case 1, Route119_EventScript_BattleBrendanTorchic
# 133 "data//maps/Route119/scripts.pory"
	case 2, Route119_EventScript_BattleBrendanMudkip
# 134 "data//maps/Route119/scripts.pory"
	end
# 135 "data//maps/Route119/scripts.pory"

# 136 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanTreecko::
# 137 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
# 138 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 139 "data//maps/Route119/scripts.pory"
	end
# 140 "data//maps/Route119/scripts.pory"

# 141 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanTorchic::
# 142 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
# 143 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 144 "data//maps/Route119/scripts.pory"
	end
# 145 "data//maps/Route119/scripts.pory"

# 146 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanMudkip::
# 147 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
# 148 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 149 "data//maps/Route119/scripts.pory"
	end
# 150 "data//maps/Route119/scripts.pory"

# 151 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 152 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 153 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 154 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 155 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 156 "data//maps/Route119/scripts.pory"
	end
# 157 "data//maps/Route119/scripts.pory"

# 158 "data//maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 159 "data//maps/Route119/scripts.pory"
	giveitem ITEM_HM_FLY
# 160 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 161 "data//maps/Route119/scripts.pory"
	return
# 162 "data//maps/Route119/scripts.pory"

# 163 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 164 "data//maps/Route119/scripts.pory"
	closemessage
# 165 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 166 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 167 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL
# 168 "data//maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 169 "data//maps/Route119/scripts.pory"
	delay 30
# 170 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 171 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 172 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 173 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 174 "data//maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 175 "data//maps/Route119/scripts.pory"
	fadedefaultbgm
# 176 "data//maps/Route119/scripts.pory"
	delay 60
# 177 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 178 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 179 "data//maps/Route119/scripts.pory"
	addobject LOCALID_SCOTT
# 180 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
# 181 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 182 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 183 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 184 "data//maps/Route119/scripts.pory"
	closemessage
# 185 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 186 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 187 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_SCOTT
# 188 "data//maps/Route119/scripts.pory"
	releaseall
# 189 "data//maps/Route119/scripts.pory"
	end
# 190 "data//maps/Route119/scripts.pory"

# 191 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 192 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 27, 25
# 193 "data//maps/Route119/scripts.pory"
	return
# 194 "data//maps/Route119/scripts.pory"

# 195 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 196 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 28, 25
# 197 "data//maps/Route119/scripts.pory"
	return
# 198 "data//maps/Route119/scripts.pory"

# 199 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 200 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
# 201 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 202 "data//maps/Route119/scripts.pory"
	return
# 203 "data//maps/Route119/scripts.pory"

# 204 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 205 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
# 206 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 207 "data//maps/Route119/scripts.pory"
	return
# 208 "data//maps/Route119/scripts.pory"

# 209 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 210 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 211 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 212 "data//maps/Route119/scripts.pory"
	return
# 213 "data//maps/Route119/scripts.pory"

# 214 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 215 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 216 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 217 "data//maps/Route119/scripts.pory"
	return
# 218 "data//maps/Route119/scripts.pory"

# 219 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 220 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 221 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 222 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 223 "data//maps/Route119/scripts.pory"
	return
# 224 "data//maps/Route119/scripts.pory"

# 225 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 226 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 227 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 228 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 229 "data//maps/Route119/scripts.pory"
	return
# 230 "data//maps/Route119/scripts.pory"

# 231 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 232 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 25, 32
# 233 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
# 234 "data//maps/Route119/scripts.pory"
	return
# 235 "data//maps/Route119/scripts.pory"

# 236 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 237 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 26, 32
# 238 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
# 239 "data//maps/Route119/scripts.pory"
	return
# 240 "data//maps/Route119/scripts.pory"

# 241 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 242 "data//maps/Route119/scripts.pory"
	delay_16
# 243 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 244 "data//maps/Route119/scripts.pory"
	delay_8
# 245 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 246 "data//maps/Route119/scripts.pory"
	step_end
# 247 "data//maps/Route119/scripts.pory"

# 248 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 249 "data//maps/Route119/scripts.pory"
	delay_16
# 250 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 251 "data//maps/Route119/scripts.pory"
	delay_8
# 252 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 253 "data//maps/Route119/scripts.pory"
	step_end
# 254 "data//maps/Route119/scripts.pory"

# 255 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
# 256 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 257 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 258 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 259 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 260 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 261 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 262 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 263 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 264 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 265 "data//maps/Route119/scripts.pory"
	step_end
# 266 "data//maps/Route119/scripts.pory"

# 267 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 268 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 269 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 270 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 271 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 272 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 273 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 274 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 275 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 276 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 277 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 278 "data//maps/Route119/scripts.pory"
	step_end
# 279 "data//maps/Route119/scripts.pory"

# 280 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 281 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 282 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 283 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 284 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 285 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 286 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 287 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 288 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 289 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 290 "data//maps/Route119/scripts.pory"
	step_end
# 291 "data//maps/Route119/scripts.pory"

# 292 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 293 "data//maps/Route119/scripts.pory"
	walk_fast_left
# 294 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 295 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 296 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 297 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 298 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 299 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 300 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 301 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 302 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 303 "data//maps/Route119/scripts.pory"
	step_end
# 304 "data//maps/Route119/scripts.pory"

# 305 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 306 "data//maps/Route119/scripts.pory"
	walk_down
# 307 "data//maps/Route119/scripts.pory"
	walk_down
# 308 "data//maps/Route119/scripts.pory"
	walk_down
# 309 "data//maps/Route119/scripts.pory"
	walk_down
# 310 "data//maps/Route119/scripts.pory"
	walk_left
# 311 "data//maps/Route119/scripts.pory"
	walk_left
# 312 "data//maps/Route119/scripts.pory"
	walk_down
# 313 "data//maps/Route119/scripts.pory"
	step_end
# 314 "data//maps/Route119/scripts.pory"

# 315 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 316 "data//maps/Route119/scripts.pory"
	walk_up
# 317 "data//maps/Route119/scripts.pory"
	walk_right
# 318 "data//maps/Route119/scripts.pory"
	walk_right
# 319 "data//maps/Route119/scripts.pory"
	walk_up
# 320 "data//maps/Route119/scripts.pory"
	walk_up
# 321 "data//maps/Route119/scripts.pory"
	walk_up
# 322 "data//maps/Route119/scripts.pory"
	walk_up
# 323 "data//maps/Route119/scripts.pory"
	walk_up
# 324 "data//maps/Route119/scripts.pory"
	step_end
# 325 "data//maps/Route119/scripts.pory"

# 326 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 327 "data//maps/Route119/scripts.pory"
	walk_up
# 328 "data//maps/Route119/scripts.pory"
	walk_right
# 329 "data//maps/Route119/scripts.pory"
	walk_up
# 330 "data//maps/Route119/scripts.pory"
	walk_up
# 331 "data//maps/Route119/scripts.pory"
	walk_up
# 332 "data//maps/Route119/scripts.pory"
	walk_up
# 333 "data//maps/Route119/scripts.pory"
	walk_up
# 334 "data//maps/Route119/scripts.pory"
	step_end
# 335 "data//maps/Route119/scripts.pory"

# 336 "data//maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 337 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 338 "data//maps/Route119/scripts.pory"
	end
# 339 "data//maps/Route119/scripts.pory"

# 340 "data//maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 341 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 342 "data//maps/Route119/scripts.pory"
	end
# 343 "data//maps/Route119/scripts.pory"

# 344 "data//maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 345 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 346 "data//maps/Route119/scripts.pory"
	end
# 347 "data//maps/Route119/scripts.pory"

# 348 "data//maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 349 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 350 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 351 "data//maps/Route119/scripts.pory"
	end
# 352 "data//maps/Route119/scripts.pory"

# 353 "data//maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 354 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 355 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 356 "data//maps/Route119/scripts.pory"
	end
# 357 "data//maps/Route119/scripts.pory"

# 358 "data//maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 359 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 360 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 361 "data//maps/Route119/scripts.pory"
	end
# 362 "data//maps/Route119/scripts.pory"

# 363 "data//maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 364 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 365 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 366 "data//maps/Route119/scripts.pory"
	end
# 367 "data//maps/Route119/scripts.pory"

# 368 "data//maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 369 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 370 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 371 "data//maps/Route119/scripts.pory"
	end
# 372 "data//maps/Route119/scripts.pory"

# 373 "data//maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 374 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 375 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 376 "data//maps/Route119/scripts.pory"
	end
# 377 "data//maps/Route119/scripts.pory"

# 378 "data//maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 379 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 380 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 381 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 382 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 383 "data//maps/Route119/scripts.pory"
	release
# 384 "data//maps/Route119/scripts.pory"
	end
# 385 "data//maps/Route119/scripts.pory"

# 386 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 387 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 388 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 389 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 390 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 391 "data//maps/Route119/scripts.pory"
	release
# 392 "data//maps/Route119/scripts.pory"
	end
# 393 "data//maps/Route119/scripts.pory"

# 394 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 395 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 396 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 397 "data//maps/Route119/scripts.pory"
	end
# 398 "data//maps/Route119/scripts.pory"

# 399 "data//maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 400 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 401 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 402 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 403 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 404 "data//maps/Route119/scripts.pory"
	release
# 405 "data//maps/Route119/scripts.pory"
	end
# 406 "data//maps/Route119/scripts.pory"

# 407 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 408 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 409 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 410 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 411 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 412 "data//maps/Route119/scripts.pory"
	release
# 413 "data//maps/Route119/scripts.pory"
	end
# 414 "data//maps/Route119/scripts.pory"

# 415 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 416 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 417 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 418 "data//maps/Route119/scripts.pory"
	end
# 419 "data//maps/Route119/scripts.pory"

# 420 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 421 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 422 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 423 "data//maps/Route119/scripts.pory"
	end
# 424 "data//maps/Route119/scripts.pory"

# 425 "data//maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 426 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 427 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 428 "data//maps/Route119/scripts.pory"
	end
# 429 "data//maps/Route119/scripts.pory"

# 430 "data//maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 431 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 432 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 433 "data//maps/Route119/scripts.pory"
	end
# 434 "data//maps/Route119/scripts.pory"

# 435 "data//maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 436 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 437 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 438 "data//maps/Route119/scripts.pory"
	end
# 439 "data//maps/Route119/scripts.pory"

# 440 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 441 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 442 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 443 "data//maps/Route119/scripts.pory"
	end
# 444 "data//maps/Route119/scripts.pory"

# 445 "data//maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 446 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 447 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 448 "data//maps/Route119/scripts.pory"
	end
# 449 "data//maps/Route119/scripts.pory"

# 450 "data//maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 451 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 452 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 453 "data//maps/Route119/scripts.pory"
	end
# 454 "data//maps/Route119/scripts.pory"

# 455 "data//maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 456 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 457 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 458 "data//maps/Route119/scripts.pory"
	end
# 459 "data//maps/Route119/scripts.pory"

# 460 "data//maps/Route119/scripts.pory"
Route119_EventScript_Rachel::
# 461 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
# 462 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
# 463 "data//maps/Route119/scripts.pory"
	end
# 464 "data//maps/Route119/scripts.pory"

# 465 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 466 "data//maps/Route119/scripts.pory"
	lock
# 467 "data//maps/Route119/scripts.pory"
	faceplayer
# 468 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 469 "data//maps/Route119/scripts.pory"
	closemessage
# 470 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 471 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 472 "data//maps/Route119/scripts.pory"
	release
# 473 "data//maps/Route119/scripts.pory"
	end
# 474 "data//maps/Route119/scripts.pory"

# 475 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 476 "data//maps/Route119/scripts.pory"
	lock
# 477 "data//maps/Route119/scripts.pory"
	faceplayer
# 478 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 479 "data//maps/Route119/scripts.pory"
	closemessage
# 480 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 481 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 482 "data//maps/Route119/scripts.pory"
	release
# 483 "data//maps/Route119/scripts.pory"
	end
# 484 "data//maps/Route119/scripts.pory"

# 485 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 486 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 487 "data//maps/Route119/scripts.pory"
	end
# 488 "data//maps/Route119/scripts.pory"

# 489 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 490 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 491 "data//maps/Route119/scripts.pory"
	end
# 492 "data//maps/Route119/scripts.pory"

# 493 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 494 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 495 "data//maps/Route119/scripts.pory"
	end
# 496 "data//maps/Route119/scripts.pory"

# 497 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 498 "data//maps/Route119/scripts.pory"
	lockall
# 499 "data//maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 500 "data//maps/Route119/scripts.pory"
	waitmessage
# 501 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 502 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 503 "data//maps/Route119/scripts.pory"
	releaseall
# 504 "data//maps/Route119/scripts.pory"
	end
# 505 "data//maps/Route119/scripts.pory"

# 506 "data//maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 507 "data//maps/Route119/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 508 "data//maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 509 "data//maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 510 "data//maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 511 "data//maps/Route119/scripts.pory"
	.string "Ready with your POKéMON?\n"
# 512 "data//maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 513 "data//maps/Route119/scripts.pory"

# 514 "data//maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 515 "data//maps/Route119/scripts.pory"
	.string "Achah!\n"
# 516 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 517 "data//maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 518 "data//maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 519 "data//maps/Route119/scripts.pory"

# 520 "data//maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 521 "data//maps/Route119/scripts.pory"
	.string "MAY: But I had absolutely nothing to\n"
# 522 "data//maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 523 "data//maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 524 "data//maps/Route119/scripts.pory"

# 525 "data//maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 526 "data//maps/Route119/scripts.pory"
	.string "MAY: Use FLY, and your POKéMON will\n"
# 527 "data//maps/Route119/scripts.pory"
	.string "instantly carry you to any town you've\l"
# 528 "data//maps/Route119/scripts.pory"
	.string "already visited.\p"
# 529 "data//maps/Route119/scripts.pory"
	.string "But, to use FLY, you have to get\n"
# 530 "data//maps/Route119/scripts.pory"
	.string "the GYM BADGE from FORTREE CITY.\l"
# 531 "data//maps/Route119/scripts.pory"
	.string "That's important, so don't forget.\p"
# 532 "data//maps/Route119/scripts.pory"
	.string "You should FLY home and visit\n"
# 533 "data//maps/Route119/scripts.pory"
	.string "LITTLEROOT for a change.\p"
# 534 "data//maps/Route119/scripts.pory"
	.string "I bet your mom's worried about you,\n"
# 535 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 536 "data//maps/Route119/scripts.pory"
	.string "Well, let's meet again somewhere!$"
# 537 "data//maps/Route119/scripts.pory"

# 538 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 539 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: {PLAYER}! So this is where\n"
# 540 "data//maps/Route119/scripts.pory"
	.string "you've been looking for POKéMON?\p"
# 541 "data//maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 542 "data//maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 543 "data//maps/Route119/scripts.pory"
	.string "Now!\n"
# 544 "data//maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 545 "data//maps/Route119/scripts.pory"

# 546 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 547 "data//maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 548 "data//maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 549 "data//maps/Route119/scripts.pory"

# 550 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 551 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: I'd say you're good enough\n"
# 552 "data//maps/Route119/scripts.pory"
	.string "to search for POKéMON anywhere.\p"
# 553 "data//maps/Route119/scripts.pory"
	.string "Here, I'll give you this.\n"
# 554 "data//maps/Route119/scripts.pory"
	.string "Try it out.$"
# 555 "data//maps/Route119/scripts.pory"

# 556 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 557 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: Use FLY, and your POKéMON\n"
# 558 "data//maps/Route119/scripts.pory"
	.string "instantly carries you to any town\l"
# 559 "data//maps/Route119/scripts.pory"
	.string "you've already visited.\p"
# 560 "data//maps/Route119/scripts.pory"
	.string "But you need the FORTREE GYM BADGE \n"
# 561 "data//maps/Route119/scripts.pory"
	.string "to do that.\p"
# 562 "data//maps/Route119/scripts.pory"
	.string "Anyway, I have to move along.$"
# 563 "data//maps/Route119/scripts.pory"

# 564 "data//maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 565 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hahahah!\n"
# 566 "data//maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 567 "data//maps/Route119/scripts.pory"
	.string "I just passed by a TRAINER riding\n"
# 568 "data//maps/Route119/scripts.pory"
	.string "a BIKE.\p"
# 569 "data//maps/Route119/scripts.pory"
	.string "You just beat that TRAINER, didn't you?\n"
# 570 "data//maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 571 "data//maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 572 "data//maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 573 "data//maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 574 "data//maps/Route119/scripts.pory"
	.string "Are you off to FORTREE GYM next?\p"
# 575 "data//maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the GYM.\n"
# 576 "data//maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 577 "data//maps/Route119/scripts.pory"

# 578 "data//maps/Route119/scripts.pory"

# 579 "data//maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 580 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 581 "data//maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 582 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
# 583 "data//maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 584 "data//maps/Route119/scripts.pory"
	.string "the FORTREE GYM.\p"
# 585 "data//maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 586 "data//maps/Route119/scripts.pory"
	.string "Perhaps you really are the TRAINER\l"
# 587 "data//maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 588 "data//maps/Route119/scripts.pory"
	.string "Remember, you have a fan in me.\n"
# 589 "data//maps/Route119/scripts.pory"
	.string "I'll be cheering from the sidelines.\l"
# 590 "data//maps/Route119/scripts.pory"
	.string "Keep up the great work!\p"
# 591 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 592 "data//maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 593 "data//maps/Route119/scripts.pory"

# 594 "data//maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 595 "data//maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 596 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the WEATHER\n"
# 597 "data//maps/Route119/scripts.pory"
	.string "INSTITUTE. It's not safe.$"
# 598 "data//maps/Route119/scripts.pory"

# 599 "data//maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 600 "data//maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 601 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 602 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE.$"
# 603 "data//maps/Route119/scripts.pory"

# 604 "data//maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 605 "data//maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 606 "data//maps/Route119/scripts.pory"
	.string "flock of BIRD POKéMON, and then\l"
# 607 "data//maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 608 "data//maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 609 "data//maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 610 "data//maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 611 "data//maps/Route119/scripts.pory"
	.string "time ago…$"
# 612 "data//maps/Route119/scripts.pory"

# 613 "data//maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 614 "data//maps/Route119/scripts.pory"
	.string "Tch…\n"
# 615 "data//maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 616 "data//maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 617 "data//maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 618 "data//maps/Route119/scripts.pory"

# 619 "data//maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 620 "data//maps/Route119/scripts.pory"
	.string "Can your POKéMON use its SECRET POWER\n"
# 621 "data//maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 622 "data//maps/Route119/scripts.pory"
	.string "SECRET BASE?$"
# 623 "data//maps/Route119/scripts.pory"

# 624 "data//maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 625 "data//maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 626 "data//maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 627 "data//maps/Route119/scripts.pory"

# 628 "data//maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 629 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 630 "data//maps/Route119/scripts.pory"

# 631 "data//maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 632 "data//maps/Route119/scripts.pory"
	.string "TRAINER TIPS\p"
# 633 "data//maps/Route119/scripts.pory"
	.string "Up to sixteen decorations and\n"
# 634 "data//maps/Route119/scripts.pory"
	.string "furniture items can be placed in\l"
# 635 "data//maps/Route119/scripts.pory"
	.string "a SECRET BASE.\p"
# 636 "data//maps/Route119/scripts.pory"
	.string "Pick your favorite items and create\n"
# 637 "data//maps/Route119/scripts.pory"
	.string "your very own SECRET BASE exactly the\l"
# 638 "data//maps/Route119/scripts.pory"
	.string "way you want.$"
