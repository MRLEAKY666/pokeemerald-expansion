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
	case SPECIES_TREECKO, Route119_EventScript_BattleMayA
# 80 "data//maps/Route119/scripts.pory"
	case SPECIES_TORCHIC, Route119_EventScript_BattleMayB
# 81 "data//maps/Route119/scripts.pory"
	case SPECIES_MUDKIP, Route119_EventScript_BattleMayC
# 82 "data//maps/Route119/scripts.pory"
	case SPECIES_CASTFORM, Route119_EventScript_BattleMayA
# 83 "data//maps/Route119/scripts.pory"
	case SPECIES_PIPLUP, Route119_EventScript_BattleMayC
# 84 "data//maps/Route119/scripts.pory"
	case SPECIES_EEVEE, Route119_EventScript_BattleMayA
# 85 "data//maps/Route119/scripts.pory"
	case SPECIES_PICHU, Route119_EventScript_BattleMayB
# 86 "data//maps/Route119/scripts.pory"
	case SPECIES_TOGEPI, Route119_EventScript_BattleMayC
# 87 "data//maps/Route119/scripts.pory"
	case SPECIES_PORYGON, Route119_EventScript_BattleMayA
# 88 "data//maps/Route119/scripts.pory"
	case SPECIES_SNIVY, Route119_EventScript_BattleMayA
# 89 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA_HISUI, Route119_EventScript_BattleMayA
# 90 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA, Route119_EventScript_BattleMayA
# 91 "data//maps/Route119/scripts.pory"
	case SPECIES_GOTHITA, Route119_EventScript_BattleMayB
# 92 "data//maps/Route119/scripts.pory"
	case SPECIES_SOLOSIS, Route119_EventScript_BattleMayB
# 93 "data//maps/Route119/scripts.pory"
	case SPECIES_AXEW, Route119_EventScript_BattleMayC
# 94 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVESTA, Route119_EventScript_BattleMayB
# 95 "data//maps/Route119/scripts.pory"
	case SPECIES_GOOMY, Route119_EventScript_BattleMayC
# 96 "data//maps/Route119/scripts.pory"
	case SPECIES_ROWLET, Route119_EventScript_BattleMayA
# 97 "data//maps/Route119/scripts.pory"
	case SPECIES_APPLIN, Route119_EventScript_BattleMayA
# 98 "data//maps/Route119/scripts.pory"
	case SPECIES_MIME_JR, Route119_EventScript_BattleMayB
# 99 "data//maps/Route119/scripts.pory"
	case SPECIES_MAGBY, Route119_EventScript_BattleMayB
# 100 "data//maps/Route119/scripts.pory"
	case SPECIES_ELEKID, Route119_EventScript_BattleMayB
# 101 "data//maps/Route119/scripts.pory"
	case SPECIES_MANKEY, Route119_EventScript_BattleMayA
# 102 "data//maps/Route119/scripts.pory"
	case SPECIES_SWINUB, Route119_EventScript_BattleMayC
# 103 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVITAR, Route119_EventScript_BattleMayA
# 104 "data//maps/Route119/scripts.pory"
	case SPECIES_TURTWIG, Route119_EventScript_BattleMayA
# 105 "data//maps/Route119/scripts.pory"
	case SPECIES_CHARMANDER, Route119_EventScript_BattleMayB
# 106 "data//maps/Route119/scripts.pory"
	case SPECIES_SQUIRTLE, Route119_EventScript_BattleMayC
# 107 "data//maps/Route119/scripts.pory"
	case SPECIES_BULBASAUR, Route119_EventScript_BattleMayA
# 108 "data//maps/Route119/scripts.pory"
	case SPECIES_OSHAWOTT, Route119_EventScript_BattleMayC
# 109 "data//maps/Route119/scripts.pory"
	case SPECIES_CYNDAQUIL, Route119_EventScript_BattleMayB
# 110 "data//maps/Route119/scripts.pory"
	case SPECIES_BUDEW, Route119_EventScript_BattleMayA
# 111 "data//maps/Route119/scripts.pory"
	case SPECIES_SPHEAL, Route119_EventScript_BattleMayA
# 112 "data//maps/Route119/scripts.pory"
	case SPECIES_SHINX, Route119_EventScript_BattleMayB
# 113 "data//maps/Route119/scripts.pory"
	case SPECIES_SANDILE, Route119_EventScript_BattleMayC
# 114 "data//maps/Route119/scripts.pory"
	case SPECIES_PAWNIARD, Route119_EventScript_BattleMayA
# 115 "data//maps/Route119/scripts.pory"
	case SPECIES_JANGMO_O, Route119_EventScript_BattleMayA
# 116 "data//maps/Route119/scripts.pory"
	end
# 117 "data//maps/Route119/scripts.pory"

# 118 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayA::
# 119 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_A, Route119_Text_MayDefeat
# 120 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 121 "data//maps/Route119/scripts.pory"
	end
# 122 "data//maps/Route119/scripts.pory"

# 123 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayB::
# 124 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_B, Route119_Text_MayDefeat
# 125 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 126 "data//maps/Route119/scripts.pory"
	end
# 127 "data//maps/Route119/scripts.pory"

# 128 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleMayC::
# 129 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_C, Route119_Text_MayDefeat
# 130 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 131 "data//maps/Route119/scripts.pory"
	end
# 132 "data//maps/Route119/scripts.pory"

# 133 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 134 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 135 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 136 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 137 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 138 "data//maps/Route119/scripts.pory"
	end
# 139 "data//maps/Route119/scripts.pory"

# 140 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 141 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 142 "data//maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 143 "data//maps/Route119/scripts.pory"
	case SPECIES_TREECKO, Route119_EventScript_BattleBrendanA
# 144 "data//maps/Route119/scripts.pory"
	case SPECIES_TORCHIC, Route119_EventScript_BattleBrendanB
# 145 "data//maps/Route119/scripts.pory"
	case SPECIES_MUDKIP, Route119_EventScript_BattleBrendanC
# 146 "data//maps/Route119/scripts.pory"
	case SPECIES_CASTFORM, Route119_EventScript_BattleBrendanA
# 147 "data//maps/Route119/scripts.pory"
	case SPECIES_PIPLUP, Route119_EventScript_BattleBrendanC
# 148 "data//maps/Route119/scripts.pory"
	case SPECIES_EEVEE, Route119_EventScript_BattleBrendanA
# 149 "data//maps/Route119/scripts.pory"
	case SPECIES_PICHU, Route119_EventScript_BattleBrendanB
# 150 "data//maps/Route119/scripts.pory"
	case SPECIES_TOGEPI, Route119_EventScript_BattleBrendanC
# 151 "data//maps/Route119/scripts.pory"
	case SPECIES_PORYGON, Route119_EventScript_BattleBrendanA
# 152 "data//maps/Route119/scripts.pory"
	case SPECIES_SNIVY, Route119_EventScript_BattleBrendanA
# 153 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA_HISUI, Route119_EventScript_BattleBrendanA
# 154 "data//maps/Route119/scripts.pory"
	case SPECIES_ZORUA, Route119_EventScript_BattleBrendanA
# 155 "data//maps/Route119/scripts.pory"
	case SPECIES_GOTHITA, Route119_EventScript_BattleBrendanB
# 156 "data//maps/Route119/scripts.pory"
	case SPECIES_SOLOSIS, Route119_EventScript_BattleBrendanB
# 157 "data//maps/Route119/scripts.pory"
	case SPECIES_AXEW, Route119_EventScript_BattleBrendanC
# 158 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVESTA, Route119_EventScript_BattleBrendanB
# 159 "data//maps/Route119/scripts.pory"
	case SPECIES_GOOMY, Route119_EventScript_BattleBrendanC
# 160 "data//maps/Route119/scripts.pory"
	case SPECIES_ROWLET, Route119_EventScript_BattleBrendanA
# 161 "data//maps/Route119/scripts.pory"
	case SPECIES_APPLIN, Route119_EventScript_BattleBrendanA
# 162 "data//maps/Route119/scripts.pory"
	case SPECIES_MIME_JR, Route119_EventScript_BattleBrendanB
# 163 "data//maps/Route119/scripts.pory"
	case SPECIES_MAGBY, Route119_EventScript_BattleBrendanB
# 164 "data//maps/Route119/scripts.pory"
	case SPECIES_ELEKID, Route119_EventScript_BattleBrendanB
# 165 "data//maps/Route119/scripts.pory"
	case SPECIES_MANKEY, Route119_EventScript_BattleBrendanA
# 166 "data//maps/Route119/scripts.pory"
	case SPECIES_SWINUB, Route119_EventScript_BattleBrendanC
# 167 "data//maps/Route119/scripts.pory"
	case SPECIES_LARVITAR, Route119_EventScript_BattleBrendanA
# 168 "data//maps/Route119/scripts.pory"
	case SPECIES_TURTWIG, Route119_EventScript_BattleBrendanA
# 169 "data//maps/Route119/scripts.pory"
	case SPECIES_CHARMANDER, Route119_EventScript_BattleBrendanB
# 170 "data//maps/Route119/scripts.pory"
	case SPECIES_SQUIRTLE, Route119_EventScript_BattleBrendanC
# 171 "data//maps/Route119/scripts.pory"
	case SPECIES_BULBASAUR, Route119_EventScript_BattleBrendanA
# 172 "data//maps/Route119/scripts.pory"
	case SPECIES_OSHAWOTT, Route119_EventScript_BattleBrendanC
# 173 "data//maps/Route119/scripts.pory"
	case SPECIES_CYNDAQUIL, Route119_EventScript_BattleBrendanB
# 174 "data//maps/Route119/scripts.pory"
	case SPECIES_BUDEW, Route119_EventScript_BattleBrendanA
# 175 "data//maps/Route119/scripts.pory"
	case SPECIES_SPHEAL, Route119_EventScript_BattleBrendanA
# 176 "data//maps/Route119/scripts.pory"
	case SPECIES_SHINX, Route119_EventScript_BattleBrendanB
# 177 "data//maps/Route119/scripts.pory"
	case SPECIES_SANDILE, Route119_EventScript_BattleBrendanC
# 178 "data//maps/Route119/scripts.pory"
	case SPECIES_PAWNIARD, Route119_EventScript_BattleBrendanA
# 179 "data//maps/Route119/scripts.pory"
	case SPECIES_JANGMO_O, Route119_EventScript_BattleBrendanA
# 180 "data//maps/Route119/scripts.pory"
	end
# 181 "data//maps/Route119/scripts.pory"

# 182 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanA::
# 183 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_A, Route119_Text_BrendanDefeat
# 184 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 185 "data//maps/Route119/scripts.pory"
	end
# 186 "data//maps/Route119/scripts.pory"

# 187 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanB::
# 188 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_B, Route119_Text_BrendanDefeat
# 189 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 190 "data//maps/Route119/scripts.pory"
	end
# 191 "data//maps/Route119/scripts.pory"

# 192 "data//maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanC::
# 193 "data//maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_C, Route119_Text_BrendanDefeat
# 194 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 195 "data//maps/Route119/scripts.pory"
	end
# 196 "data//maps/Route119/scripts.pory"

# 197 "data//maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 198 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 199 "data//maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 200 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 201 "data//maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 202 "data//maps/Route119/scripts.pory"
	end
# 203 "data//maps/Route119/scripts.pory"

# 204 "data//maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 205 "data//maps/Route119/scripts.pory"
	giveitem ITEM_HM_FLY
# 206 "data//maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 207 "data//maps/Route119/scripts.pory"
	return
# 208 "data//maps/Route119/scripts.pory"

# 209 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 210 "data//maps/Route119/scripts.pory"
	closemessage
# 211 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 212 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 213 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL
# 214 "data//maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 215 "data//maps/Route119/scripts.pory"
	delay 30
# 216 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 217 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 218 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 219 "data//maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 220 "data//maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 221 "data//maps/Route119/scripts.pory"
	fadedefaultbgm
# 222 "data//maps/Route119/scripts.pory"
	delay 60
# 223 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 224 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 225 "data//maps/Route119/scripts.pory"
	addobject LOCALID_SCOTT
# 226 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
# 227 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 228 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 229 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 230 "data//maps/Route119/scripts.pory"
	closemessage
# 231 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 232 "data//maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 233 "data//maps/Route119/scripts.pory"
	removeobject LOCALID_SCOTT
# 234 "data//maps/Route119/scripts.pory"
	releaseall
# 235 "data//maps/Route119/scripts.pory"
	end
# 236 "data//maps/Route119/scripts.pory"

# 237 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 238 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 27, 25
# 239 "data//maps/Route119/scripts.pory"
	return
# 240 "data//maps/Route119/scripts.pory"

# 241 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 242 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 28, 25
# 243 "data//maps/Route119/scripts.pory"
	return
# 244 "data//maps/Route119/scripts.pory"

# 245 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 246 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
# 247 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 248 "data//maps/Route119/scripts.pory"
	return
# 249 "data//maps/Route119/scripts.pory"

# 250 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 251 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
# 252 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 253 "data//maps/Route119/scripts.pory"
	return
# 254 "data//maps/Route119/scripts.pory"

# 255 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 256 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 257 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 258 "data//maps/Route119/scripts.pory"
	return
# 259 "data//maps/Route119/scripts.pory"

# 260 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 261 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 262 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 263 "data//maps/Route119/scripts.pory"
	return
# 264 "data//maps/Route119/scripts.pory"

# 265 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 266 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 267 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 268 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 269 "data//maps/Route119/scripts.pory"
	return
# 270 "data//maps/Route119/scripts.pory"

# 271 "data//maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 272 "data//maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 273 "data//maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 274 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 275 "data//maps/Route119/scripts.pory"
	return
# 276 "data//maps/Route119/scripts.pory"

# 277 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 278 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 25, 32
# 279 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
# 280 "data//maps/Route119/scripts.pory"
	return
# 281 "data//maps/Route119/scripts.pory"

# 282 "data//maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 283 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 26, 32
# 284 "data//maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
# 285 "data//maps/Route119/scripts.pory"
	return
# 286 "data//maps/Route119/scripts.pory"

# 287 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 288 "data//maps/Route119/scripts.pory"
	delay_16
# 289 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 290 "data//maps/Route119/scripts.pory"
	delay_8
# 291 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 292 "data//maps/Route119/scripts.pory"
	step_end
# 293 "data//maps/Route119/scripts.pory"

# 294 "data//maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 295 "data//maps/Route119/scripts.pory"
	delay_16
# 296 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 297 "data//maps/Route119/scripts.pory"
	delay_8
# 298 "data//maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 299 "data//maps/Route119/scripts.pory"
	step_end
# 300 "data//maps/Route119/scripts.pory"

# 301 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
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
	walk_fast_right
# 309 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 310 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 311 "data//maps/Route119/scripts.pory"
	step_end
# 312 "data//maps/Route119/scripts.pory"

# 313 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 314 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 315 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 316 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 317 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 318 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 319 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 320 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 321 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 322 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 323 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 324 "data//maps/Route119/scripts.pory"
	step_end
# 325 "data//maps/Route119/scripts.pory"

# 326 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 327 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 328 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 329 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 330 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 331 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 332 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 333 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 334 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 335 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 336 "data//maps/Route119/scripts.pory"
	step_end
# 337 "data//maps/Route119/scripts.pory"

# 338 "data//maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 339 "data//maps/Route119/scripts.pory"
	walk_fast_left
# 340 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 341 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 342 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 343 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 344 "data//maps/Route119/scripts.pory"
	walk_fast_right
# 345 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 346 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 347 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 348 "data//maps/Route119/scripts.pory"
	walk_fast_up
# 349 "data//maps/Route119/scripts.pory"
	step_end
# 350 "data//maps/Route119/scripts.pory"

# 351 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 352 "data//maps/Route119/scripts.pory"
	walk_down
# 353 "data//maps/Route119/scripts.pory"
	walk_down
# 354 "data//maps/Route119/scripts.pory"
	walk_down
# 355 "data//maps/Route119/scripts.pory"
	walk_down
# 356 "data//maps/Route119/scripts.pory"
	walk_left
# 357 "data//maps/Route119/scripts.pory"
	walk_left
# 358 "data//maps/Route119/scripts.pory"
	walk_down
# 359 "data//maps/Route119/scripts.pory"
	step_end
# 360 "data//maps/Route119/scripts.pory"

# 361 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 362 "data//maps/Route119/scripts.pory"
	walk_up
# 363 "data//maps/Route119/scripts.pory"
	walk_right
# 364 "data//maps/Route119/scripts.pory"
	walk_right
# 365 "data//maps/Route119/scripts.pory"
	walk_up
# 366 "data//maps/Route119/scripts.pory"
	walk_up
# 367 "data//maps/Route119/scripts.pory"
	walk_up
# 368 "data//maps/Route119/scripts.pory"
	walk_up
# 369 "data//maps/Route119/scripts.pory"
	walk_up
# 370 "data//maps/Route119/scripts.pory"
	step_end
# 371 "data//maps/Route119/scripts.pory"

# 372 "data//maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 373 "data//maps/Route119/scripts.pory"
	walk_up
# 374 "data//maps/Route119/scripts.pory"
	walk_right
# 375 "data//maps/Route119/scripts.pory"
	walk_up
# 376 "data//maps/Route119/scripts.pory"
	walk_up
# 377 "data//maps/Route119/scripts.pory"
	walk_up
# 378 "data//maps/Route119/scripts.pory"
	walk_up
# 379 "data//maps/Route119/scripts.pory"
	walk_up
# 380 "data//maps/Route119/scripts.pory"
	step_end
# 381 "data//maps/Route119/scripts.pory"

# 382 "data//maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 383 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 384 "data//maps/Route119/scripts.pory"
	end
# 385 "data//maps/Route119/scripts.pory"

# 386 "data//maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 387 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 388 "data//maps/Route119/scripts.pory"
	end
# 389 "data//maps/Route119/scripts.pory"

# 390 "data//maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 391 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 392 "data//maps/Route119/scripts.pory"
	end
# 393 "data//maps/Route119/scripts.pory"

# 394 "data//maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 395 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 396 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 397 "data//maps/Route119/scripts.pory"
	end
# 398 "data//maps/Route119/scripts.pory"

# 399 "data//maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 400 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 401 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 402 "data//maps/Route119/scripts.pory"
	end
# 403 "data//maps/Route119/scripts.pory"

# 404 "data//maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 405 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 406 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 407 "data//maps/Route119/scripts.pory"
	end
# 408 "data//maps/Route119/scripts.pory"

# 409 "data//maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 410 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 411 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 412 "data//maps/Route119/scripts.pory"
	end
# 413 "data//maps/Route119/scripts.pory"

# 414 "data//maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 415 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 416 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 417 "data//maps/Route119/scripts.pory"
	end
# 418 "data//maps/Route119/scripts.pory"

# 419 "data//maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 420 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 421 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 422 "data//maps/Route119/scripts.pory"
	end
# 423 "data//maps/Route119/scripts.pory"

# 424 "data//maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 425 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 426 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 427 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 428 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 429 "data//maps/Route119/scripts.pory"
	release
# 430 "data//maps/Route119/scripts.pory"
	end
# 431 "data//maps/Route119/scripts.pory"

# 432 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 433 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 434 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 435 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 436 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 437 "data//maps/Route119/scripts.pory"
	release
# 438 "data//maps/Route119/scripts.pory"
	end
# 439 "data//maps/Route119/scripts.pory"

# 440 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 441 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 442 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 443 "data//maps/Route119/scripts.pory"
	end
# 444 "data//maps/Route119/scripts.pory"

# 445 "data//maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 446 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 447 "data//maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 448 "data//maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 449 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 450 "data//maps/Route119/scripts.pory"
	release
# 451 "data//maps/Route119/scripts.pory"
	end
# 452 "data//maps/Route119/scripts.pory"

# 453 "data//maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 454 "data//maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 455 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 456 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 457 "data//maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 458 "data//maps/Route119/scripts.pory"
	release
# 459 "data//maps/Route119/scripts.pory"
	end
# 460 "data//maps/Route119/scripts.pory"

# 461 "data//maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 462 "data//maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 463 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 464 "data//maps/Route119/scripts.pory"
	end
# 465 "data//maps/Route119/scripts.pory"

# 466 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 467 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 468 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 469 "data//maps/Route119/scripts.pory"
	end
# 470 "data//maps/Route119/scripts.pory"

# 471 "data//maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 472 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 473 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 474 "data//maps/Route119/scripts.pory"
	end
# 475 "data//maps/Route119/scripts.pory"

# 476 "data//maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 477 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 478 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 479 "data//maps/Route119/scripts.pory"
	end
# 480 "data//maps/Route119/scripts.pory"

# 481 "data//maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 482 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 483 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 484 "data//maps/Route119/scripts.pory"
	end
# 485 "data//maps/Route119/scripts.pory"

# 486 "data//maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 487 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 488 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 489 "data//maps/Route119/scripts.pory"
	end
# 490 "data//maps/Route119/scripts.pory"

# 491 "data//maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 492 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 493 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 494 "data//maps/Route119/scripts.pory"
	end
# 495 "data//maps/Route119/scripts.pory"

# 496 "data//maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 497 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 498 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 499 "data//maps/Route119/scripts.pory"
	end
# 500 "data//maps/Route119/scripts.pory"

# 501 "data//maps/Route119/scripts.pory"
Route119_EventScript_Daemon::
# 502 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAEMON, Route119_Text_DaemonIntro, Route119_Text_DaemonDefeat
# 503 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaemonPostBattle, MSGBOX_AUTOCLOSE
# 504 "data//maps/Route119/scripts.pory"
	end
# 505 "data//maps/Route119/scripts.pory"

# 506 "data//maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 507 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 508 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 509 "data//maps/Route119/scripts.pory"
	end
# 510 "data//maps/Route119/scripts.pory"

# 511 "data//maps/Route119/scripts.pory"
Route119_EventScript_Rachel::
# 512 "data//maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
# 513 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
# 514 "data//maps/Route119/scripts.pory"
	end
# 515 "data//maps/Route119/scripts.pory"

# 516 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 517 "data//maps/Route119/scripts.pory"
	lock
# 518 "data//maps/Route119/scripts.pory"
	faceplayer
# 519 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 520 "data//maps/Route119/scripts.pory"
	closemessage
# 521 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 522 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 523 "data//maps/Route119/scripts.pory"
	release
# 524 "data//maps/Route119/scripts.pory"
	end
# 525 "data//maps/Route119/scripts.pory"

# 526 "data//maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 527 "data//maps/Route119/scripts.pory"
	lock
# 528 "data//maps/Route119/scripts.pory"
	faceplayer
# 529 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 530 "data//maps/Route119/scripts.pory"
	closemessage
# 531 "data//maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 532 "data//maps/Route119/scripts.pory"
	waitmovement 0
# 533 "data//maps/Route119/scripts.pory"
	release
# 534 "data//maps/Route119/scripts.pory"
	end
# 535 "data//maps/Route119/scripts.pory"

# 536 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 537 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 538 "data//maps/Route119/scripts.pory"
	end
# 539 "data//maps/Route119/scripts.pory"

# 540 "data//maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 541 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 542 "data//maps/Route119/scripts.pory"
	end
# 543 "data//maps/Route119/scripts.pory"

# 544 "data//maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 545 "data//maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 546 "data//maps/Route119/scripts.pory"
	end
# 547 "data//maps/Route119/scripts.pory"

# 548 "data//maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 549 "data//maps/Route119/scripts.pory"
	lockall
# 550 "data//maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 551 "data//maps/Route119/scripts.pory"
	waitmessage
# 552 "data//maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 553 "data//maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 554 "data//maps/Route119/scripts.pory"
	releaseall
# 555 "data//maps/Route119/scripts.pory"
	end
# 556 "data//maps/Route119/scripts.pory"

# 557 "data//maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 558 "data//maps/Route119/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 559 "data//maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 560 "data//maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 561 "data//maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 562 "data//maps/Route119/scripts.pory"
	.string "Ready with your POKéMON?\n"
# 563 "data//maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 564 "data//maps/Route119/scripts.pory"

# 565 "data//maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 566 "data//maps/Route119/scripts.pory"
	.string "Achah!\n"
# 567 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 568 "data//maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 569 "data//maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 570 "data//maps/Route119/scripts.pory"

# 571 "data//maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 572 "data//maps/Route119/scripts.pory"
	.string "MAY: But I had absolutely nothing to\n"
# 573 "data//maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 574 "data//maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 575 "data//maps/Route119/scripts.pory"

# 576 "data//maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 577 "data//maps/Route119/scripts.pory"
	.string "MAY: Use FLY, and your POKéMON will\n"
# 578 "data//maps/Route119/scripts.pory"
	.string "instantly carry you to any town you've\l"
# 579 "data//maps/Route119/scripts.pory"
	.string "already visited.\p"
# 580 "data//maps/Route119/scripts.pory"
	.string "But, to use FLY, you have to get\n"
# 581 "data//maps/Route119/scripts.pory"
	.string "the GYM BADGE from FORTREE CITY.\l"
# 582 "data//maps/Route119/scripts.pory"
	.string "That's important, so don't forget.\p"
# 583 "data//maps/Route119/scripts.pory"
	.string "You should FLY home and visit\n"
# 584 "data//maps/Route119/scripts.pory"
	.string "LITTLEROOT for a change.\p"
# 585 "data//maps/Route119/scripts.pory"
	.string "I bet your mom's worried about you,\n"
# 586 "data//maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 587 "data//maps/Route119/scripts.pory"
	.string "Well, let's meet again somewhere!$"
# 588 "data//maps/Route119/scripts.pory"

# 589 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 590 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: {PLAYER}! So this is where\n"
# 591 "data//maps/Route119/scripts.pory"
	.string "you've been looking for POKéMON?\p"
# 592 "data//maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 593 "data//maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 594 "data//maps/Route119/scripts.pory"
	.string "Now!\n"
# 595 "data//maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 596 "data//maps/Route119/scripts.pory"

# 597 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 598 "data//maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 599 "data//maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 600 "data//maps/Route119/scripts.pory"

# 601 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 602 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: I'd say you're good enough\n"
# 603 "data//maps/Route119/scripts.pory"
	.string "to search for POKéMON anywhere.\p"
# 604 "data//maps/Route119/scripts.pory"
	.string "Here, I'll give you this.\n"
# 605 "data//maps/Route119/scripts.pory"
	.string "Try it out.$"
# 606 "data//maps/Route119/scripts.pory"

# 607 "data//maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 608 "data//maps/Route119/scripts.pory"
	.string "BRENDAN: Use FLY, and your POKéMON\n"
# 609 "data//maps/Route119/scripts.pory"
	.string "instantly carries you to any town\l"
# 610 "data//maps/Route119/scripts.pory"
	.string "you've already visited.\p"
# 611 "data//maps/Route119/scripts.pory"
	.string "But you need the FORTREE GYM BADGE \n"
# 612 "data//maps/Route119/scripts.pory"
	.string "to do that.\p"
# 613 "data//maps/Route119/scripts.pory"
	.string "Anyway, I have to move along.$"
# 614 "data//maps/Route119/scripts.pory"

# 615 "data//maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 616 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hahahah!\n"
# 617 "data//maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 618 "data//maps/Route119/scripts.pory"
	.string "I just passed by a TRAINER riding\n"
# 619 "data//maps/Route119/scripts.pory"
	.string "a BIKE.\p"
# 620 "data//maps/Route119/scripts.pory"
	.string "You just beat that TRAINER, didn't you?\n"
# 621 "data//maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 622 "data//maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 623 "data//maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 624 "data//maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 625 "data//maps/Route119/scripts.pory"
	.string "Are you off to FORTREE GYM next?\p"
# 626 "data//maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the GYM.\n"
# 627 "data//maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 628 "data//maps/Route119/scripts.pory"

# 629 "data//maps/Route119/scripts.pory"

# 630 "data//maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 631 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 632 "data//maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 633 "data//maps/Route119/scripts.pory"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
# 634 "data//maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 635 "data//maps/Route119/scripts.pory"
	.string "the FORTREE GYM.\p"
# 636 "data//maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 637 "data//maps/Route119/scripts.pory"
	.string "Perhaps you really are the TRAINER\l"
# 638 "data//maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 639 "data//maps/Route119/scripts.pory"
	.string "Remember, you have a fan in me.\n"
# 640 "data//maps/Route119/scripts.pory"
	.string "I'll be cheering from the sidelines.\l"
# 641 "data//maps/Route119/scripts.pory"
	.string "Keep up the great work!\p"
# 642 "data//maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 643 "data//maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 644 "data//maps/Route119/scripts.pory"

# 645 "data//maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 646 "data//maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 647 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the WEATHER\n"
# 648 "data//maps/Route119/scripts.pory"
	.string "INSTITUTE. It's not safe.$"
# 649 "data//maps/Route119/scripts.pory"

# 650 "data//maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 651 "data//maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 652 "data//maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 653 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE.$"
# 654 "data//maps/Route119/scripts.pory"

# 655 "data//maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 656 "data//maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 657 "data//maps/Route119/scripts.pory"
	.string "flock of BIRD POKéMON, and then\l"
# 658 "data//maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 659 "data//maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 660 "data//maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 661 "data//maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 662 "data//maps/Route119/scripts.pory"
	.string "time ago…$"
# 663 "data//maps/Route119/scripts.pory"

# 664 "data//maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 665 "data//maps/Route119/scripts.pory"
	.string "Tch…\n"
# 666 "data//maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 667 "data//maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 668 "data//maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 669 "data//maps/Route119/scripts.pory"

# 670 "data//maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 671 "data//maps/Route119/scripts.pory"
	.string "Can your POKéMON use its SECRET POWER\n"
# 672 "data//maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 673 "data//maps/Route119/scripts.pory"
	.string "SECRET BASE?$"
# 674 "data//maps/Route119/scripts.pory"

# 675 "data//maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 676 "data//maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 677 "data//maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 678 "data//maps/Route119/scripts.pory"

# 679 "data//maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 680 "data//maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 681 "data//maps/Route119/scripts.pory"

# 682 "data//maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 683 "data//maps/Route119/scripts.pory"
	.string "TRAINER TIPS\p"
# 684 "data//maps/Route119/scripts.pory"
	.string "Up to sixteen decorations and\n"
# 685 "data//maps/Route119/scripts.pory"
	.string "furniture items can be placed in\l"
# 686 "data//maps/Route119/scripts.pory"
	.string "a SECRET BASE.\p"
# 687 "data//maps/Route119/scripts.pory"
	.string "Pick your favorite items and create\n"
# 688 "data//maps/Route119/scripts.pory"
	.string "your very own SECRET BASE exactly the\l"
# 689 "data//maps/Route119/scripts.pory"
	.string "way you want.$"
