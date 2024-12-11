# 1 "data//maps/Route104/scripts.pory"

# 2 "data//maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 3 "data//maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data//maps/Route104/scripts.pory"
.set LOCALID_RIVAL, 34
# 5 "data//maps/Route104/scripts.pory"

# 6 "data//maps/Route104/scripts.pory"
Route104_MapScripts::
# 7 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 8 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 9 "data//maps/Route104/scripts.pory"
	.byte 0
# 10 "data//maps/Route104/scripts.pory"

# 11 "data//maps/Route104/scripts.pory"
Route104_OnFrame:
# 12 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 13 "data//maps/Route104/scripts.pory"
	.2byte 0
# 14 "data//maps/Route104/scripts.pory"

# 15 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 16 "data//maps/Route104/scripts.pory"
	lockall
# 17 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 18 "data//maps/Route104/scripts.pory"
	end
# 19 "data//maps/Route104/scripts.pory"

# 20 "data//maps/Route104/scripts.pory"
Route104_OnTransition:
# 21 "data//maps/Route104/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 22 "data//maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 23 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 24 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 25 "data//maps/Route104/scripts.pory"
	end
# 26 "data//maps/Route104/scripts.pory"

# 27 "data//maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 28 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 29 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 30 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 31 "data//maps/Route104/scripts.pory"
	return
# 32 "data//maps/Route104/scripts.pory"

# 33 "data//maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 34 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 35 "data//maps/Route104/scripts.pory"
	return
# 36 "data//maps/Route104/scripts.pory"

# 37 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 38 "data//maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 39 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 40 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 41 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 17, 52
# 42 "data//maps/Route104/scripts.pory"
	return
# 43 "data//maps/Route104/scripts.pory"

# 44 "data//maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 45 "data//maps/Route104/scripts.pory"
	return
# 46 "data//maps/Route104/scripts.pory"

# 47 "data//maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 48 "data//maps/Route104/scripts.pory"
	lockall
# 49 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 50 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 51 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 52 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 53 "data//maps/Route104/scripts.pory"

# 54 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 55 "data//maps/Route104/scripts.pory"
	lockall
# 56 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 57 "data//maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 58 "data//maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 59 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 60 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 61 "data//maps/Route104/scripts.pory"
	delay 10
# 62 "data//maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL
# 63 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 64 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 65 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 66 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 67 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 68 "data//maps/Route104/scripts.pory"
	delay 20
# 69 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 70 "data//maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 71 "data//maps/Route104/scripts.pory"
	playse SE_PIN
# 72 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 73 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 74 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 75 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 76 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 77 "data//maps/Route104/scripts.pory"

# 78 "data//maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 79 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 80 "data//maps/Route104/scripts.pory"
	checkplayergender
# 81 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 82 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 83 "data//maps/Route104/scripts.pory"
	return
# 84 "data//maps/Route104/scripts.pory"

# 85 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 86 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 87 "data//maps/Route104/scripts.pory"
	return
# 88 "data//maps/Route104/scripts.pory"

# 89 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 90 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 91 "data//maps/Route104/scripts.pory"
	return
# 92 "data//maps/Route104/scripts.pory"

# 93 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 94 "data//maps/Route104/scripts.pory"
	checkplayergender
# 95 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 96 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 97 "data//maps/Route104/scripts.pory"
	end
# 98 "data//maps/Route104/scripts.pory"

# 99 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 100 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 101 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 102 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 103 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 104 "data//maps/Route104/scripts.pory"
	closemessage
# 105 "data//maps/Route104/scripts.pory"
	delay 30
# 106 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 107 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 108 "data//maps/Route104/scripts.pory"
	waitfanfare
# 109 "data//maps/Route104/scripts.pory"
	closemessage
# 110 "data//maps/Route104/scripts.pory"
	delay 30
# 111 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 112 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 113 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 114 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 115 "data//maps/Route104/scripts.pory"
	closemessage
# 116 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 117 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 118 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 119 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 120 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 121 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 122 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 123 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 124 "data//maps/Route104/scripts.pory"
	releaseall
# 125 "data//maps/Route104/scripts.pory"
	end
# 126 "data//maps/Route104/scripts.pory"

# 127 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 128 "data//maps/Route104/scripts.pory"
	walk_slow_left
# 129 "data//maps/Route104/scripts.pory"
	step_end
# 130 "data//maps/Route104/scripts.pory"

# 131 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 132 "data//maps/Route104/scripts.pory"
	walk_down
# 133 "data//maps/Route104/scripts.pory"
	face_right
# 134 "data//maps/Route104/scripts.pory"
	step_end
# 135 "data//maps/Route104/scripts.pory"

# 136 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 137 "data//maps/Route104/scripts.pory"
	delay_4
# 138 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 139 "data//maps/Route104/scripts.pory"
	step_end
# 140 "data//maps/Route104/scripts.pory"

# 141 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 142 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 143 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 144 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 145 "data//maps/Route104/scripts.pory"
	releaseall
# 146 "data//maps/Route104/scripts.pory"
	end
# 147 "data//maps/Route104/scripts.pory"

# 148 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 149 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 150 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 151 "data//maps/Route104/scripts.pory"
	case SPECIES_TREECKO, Route104_EventScript_BattleMayTreecko
# 152 "data//maps/Route104/scripts.pory"
	case SPECIES_TORCHIC, Route104_EventScript_BattleMayTorchic
# 153 "data//maps/Route104/scripts.pory"
	case SPECIES_MUDKIP, Route104_EventScript_BattleMayMudkip
# 154 "data//maps/Route104/scripts.pory"
	case SPECIES_CASTFORM, Route104_EventScript_BattleMayTreecko
# 155 "data//maps/Route104/scripts.pory"
	case SPECIES_PIPLUP, Route104_EventScript_BattleMayTorchic
# 156 "data//maps/Route104/scripts.pory"
	case SPECIES_EEVEE, Route104_EventScript_BattleMayMudkip
# 157 "data//maps/Route104/scripts.pory"
	case SPECIES_PICHU, Route104_EventScript_BattleMayTreecko
# 158 "data//maps/Route104/scripts.pory"
	case SPECIES_TOGEPI, Route104_EventScript_BattleMayTorchic
# 159 "data//maps/Route104/scripts.pory"
	case SPECIES_PORYGON, Route104_EventScript_BattleMayMudkip
# 160 "data//maps/Route104/scripts.pory"
	case SPECIES_SNIVY, Route104_EventScript_BattleMayTreecko
# 161 "data//maps/Route104/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, Route104_EventScript_BattleMayTorchic
# 162 "data//maps/Route104/scripts.pory"
	case SPECIES_ZORUA, Route104_EventScript_BattleMayMudkip
# 163 "data//maps/Route104/scripts.pory"
	case SPECIES_GOTHITA, Route104_EventScript_BattleMayTreecko
# 164 "data//maps/Route104/scripts.pory"
	case SPECIES_SOLOSIS, Route104_EventScript_BattleMayTorchic
# 165 "data//maps/Route104/scripts.pory"
	case SPECIES_AXEW, Route104_EventScript_BattleMayMudkip
# 166 "data//maps/Route104/scripts.pory"
	case SPECIES_LARVESTA, Route104_EventScript_BattleMayTreecko
# 167 "data//maps/Route104/scripts.pory"
	case SPECIES_GOOMY, Route104_EventScript_BattleMayTorchic
# 168 "data//maps/Route104/scripts.pory"
	case SPECIES_ROWLET, Route104_EventScript_BattleMayMudkip
# 169 "data//maps/Route104/scripts.pory"
	case SPECIES_APPLIN, Route104_EventScript_BattleMayTreecko
# 170 "data//maps/Route104/scripts.pory"
	case SPECIES_MIME_JR, Route104_EventScript_BattleMayTorchic
# 171 "data//maps/Route104/scripts.pory"
	case SPECIES_MAGBY, Route104_EventScript_BattleMayMudkip
# 172 "data//maps/Route104/scripts.pory"
	case SPECIES_ELEKID, Route104_EventScript_BattleMayTreecko
# 173 "data//maps/Route104/scripts.pory"
	case SPECIES_MANKEY, Route104_EventScript_BattleMayTorchic
# 174 "data//maps/Route104/scripts.pory"
	case SPECIES_SWINUB, Route104_EventScript_BattleMayMudkip
# 175 "data//maps/Route104/scripts.pory"
	case SPECIES_LARVITAR, Route104_EventScript_BattleMayTreecko
# 176 "data//maps/Route104/scripts.pory"
	case SPECIES_TURTWIG, Route104_EventScript_BattleMayTorchic
# 177 "data//maps/Route104/scripts.pory"
	case SPECIES_CHARMANDER, Route104_EventScript_BattleMayMudkip
# 178 "data//maps/Route104/scripts.pory"
	case SPECIES_SQUIRTLE, Route104_EventScript_BattleMayTreecko
# 179 "data//maps/Route104/scripts.pory"
	case SPECIES_BULBASAUR, Route104_EventScript_BattleMayTorchic
# 180 "data//maps/Route104/scripts.pory"
	case SPECIES_OSHAWOTT, Route104_EventScript_BattleMayMudkip
# 181 "data//maps/Route104/scripts.pory"
	case SPECIES_CYNDAQUIL, Route104_EventScript_BattleMayTreecko
# 182 "data//maps/Route104/scripts.pory"
	case SPECIES_BUDEW, Route104_EventScript_BattleMayTorchic
# 183 "data//maps/Route104/scripts.pory"
	case SPECIES_SPHEAL, Route104_EventScript_BattleMayMudkip
# 184 "data//maps/Route104/scripts.pory"
	case SPECIES_SHINX, Route104_EventScript_BattleMayTreecko
# 185 "data//maps/Route104/scripts.pory"
	case SPECIES_SANDILE, Route104_EventScript_BattleMayTreecko
# 186 "data//maps/Route104/scripts.pory"
	case SPECIES_PAWNIARD, Route104_EventScript_BattleMayTorchic
# 187 "data//maps/Route104/scripts.pory"
	case SPECIES_JANGMO_O, Route104_EventScript_BattleMayMudkip
# 188 "data//maps/Route104/scripts.pory"
	end
# 189 "data//maps/Route104/scripts.pory"

# 190 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 191 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 192 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 193 "data//maps/Route104/scripts.pory"
	releaseall
# 194 "data//maps/Route104/scripts.pory"
	end
# 195 "data//maps/Route104/scripts.pory"

# 196 "data//maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 197 "data//maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 198 "data//maps/Route104/scripts.pory"
	fadedefaultbgm
# 199 "data//maps/Route104/scripts.pory"
	return
# 200 "data//maps/Route104/scripts.pory"

# 201 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTreecko::
# 202 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
# 203 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 204 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 205 "data//maps/Route104/scripts.pory"
	end
# 206 "data//maps/Route104/scripts.pory"

# 207 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTorchic::
# 208 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
# 209 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 210 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 211 "data//maps/Route104/scripts.pory"
	end
# 212 "data//maps/Route104/scripts.pory"

# 213 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMayMudkip::
# 214 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
# 215 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 216 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 217 "data//maps/Route104/scripts.pory"
	end
# 218 "data//maps/Route104/scripts.pory"

# 219 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 220 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 221 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 222 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 223 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 224 "data//maps/Route104/scripts.pory"
	closemessage
# 225 "data//maps/Route104/scripts.pory"
	delay 30
# 226 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 227 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 228 "data//maps/Route104/scripts.pory"
	waitfanfare
# 229 "data//maps/Route104/scripts.pory"
	closemessage
# 230 "data//maps/Route104/scripts.pory"
	delay 30
# 231 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 232 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 233 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 234 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 235 "data//maps/Route104/scripts.pory"
	closemessage
# 236 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 237 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 238 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 239 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 240 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 241 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 242 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 243 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 244 "data//maps/Route104/scripts.pory"
	releaseall
# 245 "data//maps/Route104/scripts.pory"
	end
# 246 "data//maps/Route104/scripts.pory"

# 247 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 248 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 249 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 250 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 251 "data//maps/Route104/scripts.pory"
	releaseall
# 252 "data//maps/Route104/scripts.pory"
	end
# 253 "data//maps/Route104/scripts.pory"

# 254 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 255 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 256 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 257 "data//maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleBrendanTreecko
# 258 "data//maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleBrendanTorchic
# 259 "data//maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleBrendanMudkip
# 260 "data//maps/Route104/scripts.pory"
	end
# 261 "data//maps/Route104/scripts.pory"

# 262 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 263 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 264 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 265 "data//maps/Route104/scripts.pory"
	releaseall
# 266 "data//maps/Route104/scripts.pory"
	end
# 267 "data//maps/Route104/scripts.pory"

# 268 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTreecko::
# 269 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
# 270 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 271 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 272 "data//maps/Route104/scripts.pory"
	end
# 273 "data//maps/Route104/scripts.pory"

# 274 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTorchic::
# 275 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
# 276 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 277 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 278 "data//maps/Route104/scripts.pory"
	end
# 279 "data//maps/Route104/scripts.pory"

# 280 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanMudkip::
# 281 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
# 282 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 283 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 284 "data//maps/Route104/scripts.pory"
	end
# 285 "data//maps/Route104/scripts.pory"

# 286 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 287 "data//maps/Route104/scripts.pory"
	lock_facing_direction
# 288 "data//maps/Route104/scripts.pory"
	walk_down
# 289 "data//maps/Route104/scripts.pory"
	unlock_facing_direction
# 290 "data//maps/Route104/scripts.pory"
	step_end
# 291 "data//maps/Route104/scripts.pory"

# 292 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 293 "data//maps/Route104/scripts.pory"
	walk_down
# 294 "data//maps/Route104/scripts.pory"
	step_end
# 295 "data//maps/Route104/scripts.pory"

# 296 "data//maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 297 "data//maps/Route104/scripts.pory"
	lock
# 298 "data//maps/Route104/scripts.pory"
	faceplayer
# 299 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 300 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 301 "data//maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 302 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 303 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 304 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 305 "data//maps/Route104/scripts.pory"
	release
# 306 "data//maps/Route104/scripts.pory"
	end
# 307 "data//maps/Route104/scripts.pory"

# 308 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 309 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 310 "data//maps/Route104/scripts.pory"
	release
# 311 "data//maps/Route104/scripts.pory"
	end
# 312 "data//maps/Route104/scripts.pory"

# 313 "data//maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 314 "data//maps/Route104/scripts.pory"
	lock
# 315 "data//maps/Route104/scripts.pory"
	faceplayer
# 316 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 317 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 318 "data//maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 319 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 320 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 321 "data//maps/Route104/scripts.pory"
	release
# 322 "data//maps/Route104/scripts.pory"
	end
# 323 "data//maps/Route104/scripts.pory"

# 324 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 325 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 326 "data//maps/Route104/scripts.pory"
	release
# 327 "data//maps/Route104/scripts.pory"
	end
# 328 "data//maps/Route104/scripts.pory"

# 329 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 330 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 331 "data//maps/Route104/scripts.pory"
	end
# 332 "data//maps/Route104/scripts.pory"

# 333 "data//maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 334 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 335 "data//maps/Route104/scripts.pory"
	end
# 336 "data//maps/Route104/scripts.pory"

# 337 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 338 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 339 "data//maps/Route104/scripts.pory"
	end
# 340 "data//maps/Route104/scripts.pory"

# 341 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 342 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 343 "data//maps/Route104/scripts.pory"
	end
# 344 "data//maps/Route104/scripts.pory"

# 345 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 346 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 347 "data//maps/Route104/scripts.pory"
	end
# 348 "data//maps/Route104/scripts.pory"

# 349 "data//maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 350 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 351 "data//maps/Route104/scripts.pory"
	end
# 352 "data//maps/Route104/scripts.pory"

# 353 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 354 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 355 "data//maps/Route104/scripts.pory"
	end
# 356 "data//maps/Route104/scripts.pory"

# 357 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 358 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 359 "data//maps/Route104/scripts.pory"
	end
# 360 "data//maps/Route104/scripts.pory"

# 361 "data//maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 362 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 363 "data//maps/Route104/scripts.pory"
	end
# 364 "data//maps/Route104/scripts.pory"

# 365 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 366 "data//maps/Route104/scripts.pory"
	lock
# 367 "data//maps/Route104/scripts.pory"
	faceplayer
# 368 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 369 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 370 "data//maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED, 2
# 371 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 372 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 373 "data//maps/Route104/scripts.pory"
	release
# 374 "data//maps/Route104/scripts.pory"
	end
# 375 "data//maps/Route104/scripts.pory"

# 376 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 377 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 378 "data//maps/Route104/scripts.pory"
	release
# 379 "data//maps/Route104/scripts.pory"
	end
# 380 "data//maps/Route104/scripts.pory"

# 381 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 382 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 383 "data//maps/Route104/scripts.pory"
	end
# 384 "data//maps/Route104/scripts.pory"

# 385 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 386 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 387 "data//maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 388 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
# 389 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 390 "data//maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 391 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 392 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 393 "data//maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 394 "data//maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 395 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 396 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 397 "data//maps/Route104/scripts.pory"
	end
# 398 "data//maps/Route104/scripts.pory"

# 399 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 400 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
# 401 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 402 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 403 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 404 "data//maps/Route104/scripts.pory"

# 405 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 406 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
# 407 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 408 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 409 "data//maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 410 "data//maps/Route104/scripts.pory"
	waitmessage
# 411 "data//maps/Route104/scripts.pory"
	delay 30
# 412 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 413 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 414 "data//maps/Route104/scripts.pory"
	waitfanfare
# 415 "data//maps/Route104/scripts.pory"
	closemessage
# 416 "data//maps/Route104/scripts.pory"
	delay 30
# 417 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 418 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 419 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 420 "data//maps/Route104/scripts.pory"
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
# 421 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 422 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 423 "data//maps/Route104/scripts.pory"

# 424 "data//maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 425 "data//maps/Route104/scripts.pory"
	delay 50
# 426 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 427 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 428 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 429 "data//maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 430 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 431 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 432 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 433 "data//maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 434 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 435 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 436 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 437 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 438 "data//maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 439 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 440 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 441 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 442 "data//maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 443 "data//maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 444 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 445 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 446 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 447 "data//maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 448 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 449 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 450 "data//maps/Route104/scripts.pory"
	end
# 451 "data//maps/Route104/scripts.pory"

# 452 "data//maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 453 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 454 "data//maps/Route104/scripts.pory"
	releaseall
# 455 "data//maps/Route104/scripts.pory"
	end
# 456 "data//maps/Route104/scripts.pory"

# 457 "data//maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 458 "data//maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 459 "data//maps/Route104/scripts.pory"
	releaseall
# 460 "data//maps/Route104/scripts.pory"
	end
# 461 "data//maps/Route104/scripts.pory"

# 462 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 463 "data//maps/Route104/scripts.pory"
	walk_down
# 464 "data//maps/Route104/scripts.pory"
	walk_down
# 465 "data//maps/Route104/scripts.pory"
	walk_down
# 466 "data//maps/Route104/scripts.pory"
	walk_down
# 467 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 468 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 469 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 470 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 471 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 472 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 473 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 474 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 475 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 476 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 477 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 478 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 479 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 480 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 481 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 482 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 483 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 484 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 485 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 486 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 487 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 488 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 489 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 490 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 491 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 492 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 493 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 494 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 495 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 496 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 497 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 498 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 499 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 500 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 501 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 502 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 503 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 504 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 505 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 506 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 507 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 508 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 509 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 510 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 511 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 512 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 513 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 514 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 515 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 516 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 517 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 518 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 519 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 520 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 521 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 522 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 523 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 524 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 525 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 526 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 527 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 528 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 529 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 530 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 531 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 532 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 533 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 534 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 535 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 536 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 537 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 538 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 539 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 540 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 541 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 542 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 543 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 544 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 545 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 546 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 547 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 548 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 549 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 550 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 551 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 552 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 553 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 554 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 555 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 556 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 557 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 558 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 559 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 560 "data//maps/Route104/scripts.pory"
	step_end
# 561 "data//maps/Route104/scripts.pory"

# 562 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 563 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 564 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 565 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 566 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 567 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 568 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 569 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 570 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 571 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 572 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 573 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 574 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 575 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 576 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 577 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 578 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 579 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 580 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 581 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 582 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 583 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 584 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 585 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 586 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 587 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 588 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 589 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 590 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 591 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 592 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 593 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 594 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 595 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 596 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 597 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 598 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 599 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 600 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 601 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 602 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 603 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 604 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 605 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 606 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 607 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 608 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 609 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 610 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 611 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 612 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 613 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 614 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 615 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 616 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 617 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 618 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 619 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 620 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 621 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 622 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 623 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 624 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 625 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 626 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 627 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 628 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 629 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 630 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 631 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 632 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 633 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 634 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 635 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 636 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 637 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 638 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 639 "data//maps/Route104/scripts.pory"
	walk_right
# 640 "data//maps/Route104/scripts.pory"
	walk_right
# 641 "data//maps/Route104/scripts.pory"
	walk_down
# 642 "data//maps/Route104/scripts.pory"
	walk_down
# 643 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 644 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 645 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 646 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 647 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 648 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 649 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 650 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 651 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 652 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 653 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 655 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 656 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 657 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 658 "data//maps/Route104/scripts.pory"
	walk_down
# 659 "data//maps/Route104/scripts.pory"
	walk_down
# 660 "data//maps/Route104/scripts.pory"
	step_end
# 661 "data//maps/Route104/scripts.pory"

# 662 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 663 "data//maps/Route104/scripts.pory"
	walk_down
# 664 "data//maps/Route104/scripts.pory"
	walk_down
# 665 "data//maps/Route104/scripts.pory"
	walk_down
# 666 "data//maps/Route104/scripts.pory"
	walk_down
# 667 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 668 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 669 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 670 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 671 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 672 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 673 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 674 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 675 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 676 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 677 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 678 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 679 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 680 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 681 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 682 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 683 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 684 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 685 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 686 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 687 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 688 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 689 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 690 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 691 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 692 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 693 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 694 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 695 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 696 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 697 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 698 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 699 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 700 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 701 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 723 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 724 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 725 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 726 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 727 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 728 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 729 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 730 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 731 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 732 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 733 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 734 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 735 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 736 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 737 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 738 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 739 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 740 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 741 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 742 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 743 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 744 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 745 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 746 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 747 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 748 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 749 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 750 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 751 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 752 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 753 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 754 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 755 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 756 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 757 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 758 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 759 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 760 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 761 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 762 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 763 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 764 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 765 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 766 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 767 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 768 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 769 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 770 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 771 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 772 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 773 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 774 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 775 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 776 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 777 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 778 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 779 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 780 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 781 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 782 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 783 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 784 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 785 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 786 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 787 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 788 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 789 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 790 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 791 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 792 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 793 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 794 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 795 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 796 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 797 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 798 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 799 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 800 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 801 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 802 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 803 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 804 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 805 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 806 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 807 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 808 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 809 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 810 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 811 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 812 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 813 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 814 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 815 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 816 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 817 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 818 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 819 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 820 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 821 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 822 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 823 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 824 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 825 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 826 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 827 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 828 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 829 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 830 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 831 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 832 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 833 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 834 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 835 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 836 "data//maps/Route104/scripts.pory"
	walk_right
# 837 "data//maps/Route104/scripts.pory"
	walk_right
# 838 "data//maps/Route104/scripts.pory"
	walk_down
# 839 "data//maps/Route104/scripts.pory"
	walk_down
# 840 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 841 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 842 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 843 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 844 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 845 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 846 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 847 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 848 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 849 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 850 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 851 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 852 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 853 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 854 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 855 "data//maps/Route104/scripts.pory"
	walk_down
# 856 "data//maps/Route104/scripts.pory"
	walk_down
# 857 "data//maps/Route104/scripts.pory"
	step_end
# 858 "data//maps/Route104/scripts.pory"

# 859 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 860 "data//maps/Route104/scripts.pory"
	walk_left
# 861 "data//maps/Route104/scripts.pory"
	walk_down
# 862 "data//maps/Route104/scripts.pory"
	walk_down
# 863 "data//maps/Route104/scripts.pory"
	step_end
# 864 "data//maps/Route104/scripts.pory"

# 865 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 866 "data//maps/Route104/scripts.pory"
	walk_down
# 867 "data//maps/Route104/scripts.pory"
	step_end
# 868 "data//maps/Route104/scripts.pory"

# 869 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 870 "data//maps/Route104/scripts.pory"
	walk_down
# 871 "data//maps/Route104/scripts.pory"
	walk_left
# 872 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 873 "data//maps/Route104/scripts.pory"
	step_end
# 874 "data//maps/Route104/scripts.pory"

# 875 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 876 "data//maps/Route104/scripts.pory"
	walk_down
# 877 "data//maps/Route104/scripts.pory"
	walk_down
# 878 "data//maps/Route104/scripts.pory"
	step_end
# 879 "data//maps/Route104/scripts.pory"

# 880 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 881 "data//maps/Route104/scripts.pory"
	walk_down
# 882 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 883 "data//maps/Route104/scripts.pory"
	step_end
# 884 "data//maps/Route104/scripts.pory"

# 885 "data//maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 886 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 887 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 888 "data//maps/Route104/scripts.pory"
	end
# 889 "data//maps/Route104/scripts.pory"

# 890 "data//maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 891 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 892 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 893 "data//maps/Route104/scripts.pory"
	end
# 894 "data//maps/Route104/scripts.pory"

# 895 "data//maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 896 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 897 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 898 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 899 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 900 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 901 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 902 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 903 "data//maps/Route104/scripts.pory"
	release
# 904 "data//maps/Route104/scripts.pory"
	end
# 905 "data//maps/Route104/scripts.pory"

# 906 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 907 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 908 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 909 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 910 "data//maps/Route104/scripts.pory"
	release
# 911 "data//maps/Route104/scripts.pory"
	end
# 912 "data//maps/Route104/scripts.pory"

# 913 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 914 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 915 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 916 "data//maps/Route104/scripts.pory"
	release
# 917 "data//maps/Route104/scripts.pory"
	end
# 918 "data//maps/Route104/scripts.pory"

# 919 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 920 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 921 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 922 "data//maps/Route104/scripts.pory"
	release
# 923 "data//maps/Route104/scripts.pory"
	end
# 924 "data//maps/Route104/scripts.pory"

# 925 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 926 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 927 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 928 "data//maps/Route104/scripts.pory"
	release
# 929 "data//maps/Route104/scripts.pory"
	end
# 930 "data//maps/Route104/scripts.pory"

# 931 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 932 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 933 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 934 "data//maps/Route104/scripts.pory"
	end
# 935 "data//maps/Route104/scripts.pory"

# 936 "data//maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 937 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 938 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 939 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 940 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 941 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 942 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 943 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 944 "data//maps/Route104/scripts.pory"
	release
# 945 "data//maps/Route104/scripts.pory"
	end
# 946 "data//maps/Route104/scripts.pory"

# 947 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 948 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 949 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 950 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 951 "data//maps/Route104/scripts.pory"
	release
# 952 "data//maps/Route104/scripts.pory"
	end
# 953 "data//maps/Route104/scripts.pory"

# 954 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 955 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 956 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 957 "data//maps/Route104/scripts.pory"
	release
# 958 "data//maps/Route104/scripts.pory"
	end
# 959 "data//maps/Route104/scripts.pory"

# 960 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 961 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 962 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 963 "data//maps/Route104/scripts.pory"
	release
# 964 "data//maps/Route104/scripts.pory"
	end
# 965 "data//maps/Route104/scripts.pory"

# 966 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 967 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 968 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 969 "data//maps/Route104/scripts.pory"
	release
# 970 "data//maps/Route104/scripts.pory"
	end
# 971 "data//maps/Route104/scripts.pory"

# 972 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 973 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 974 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 975 "data//maps/Route104/scripts.pory"
	end
# 976 "data//maps/Route104/scripts.pory"

# 977 "data//maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 978 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
# 979 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 980 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 981 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 982 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 983 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 984 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 985 "data//maps/Route104/scripts.pory"
	release
# 986 "data//maps/Route104/scripts.pory"
	end
# 987 "data//maps/Route104/scripts.pory"

# 988 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 989 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 990 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 991 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 992 "data//maps/Route104/scripts.pory"
	release
# 993 "data//maps/Route104/scripts.pory"
	end
# 994 "data//maps/Route104/scripts.pory"

# 995 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 996 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 997 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 998 "data//maps/Route104/scripts.pory"
	release
# 999 "data//maps/Route104/scripts.pory"
	end
# 1000 "data//maps/Route104/scripts.pory"

# 1001 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 1002 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 1003 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1004 "data//maps/Route104/scripts.pory"
	release
# 1005 "data//maps/Route104/scripts.pory"
	end
# 1006 "data//maps/Route104/scripts.pory"

# 1007 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 1008 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 1009 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1010 "data//maps/Route104/scripts.pory"
	release
# 1011 "data//maps/Route104/scripts.pory"
	end
# 1012 "data//maps/Route104/scripts.pory"

# 1013 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 1014 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 1015 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 1016 "data//maps/Route104/scripts.pory"
	end
# 1017 "data//maps/Route104/scripts.pory"

# 1018 "data//maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 1019 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 1020 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1021 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 1022 "data//maps/Route104/scripts.pory"
	release
# 1023 "data//maps/Route104/scripts.pory"
	end
# 1024 "data//maps/Route104/scripts.pory"

# 1025 "data//maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 1026 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 1027 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1028 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 1029 "data//maps/Route104/scripts.pory"
	release
# 1030 "data//maps/Route104/scripts.pory"
	end
# 1031 "data//maps/Route104/scripts.pory"

# 1032 "data//maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 1033 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 1034 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 1035 "data//maps/Route104/scripts.pory"
	end
# 1036 "data//maps/Route104/scripts.pory"

# 1037 "data//maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 1038 "data//maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 1039 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 1040 "data//maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 1041 "data//maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 1042 "data//maps/Route104/scripts.pory"

# 1043 "data//maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 1044 "data//maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 1045 "data//maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 1046 "data//maps/Route104/scripts.pory"
	.string "of the sea?$"
# 1047 "data//maps/Route104/scripts.pory"

# 1048 "data//maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 1049 "data//maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 1050 "data//maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 1051 "data//maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 1052 "data//maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 1053 "data//maps/Route104/scripts.pory"

# 1054 "data//maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 1055 "data//maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 1056 "data//maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 1057 "data//maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 1058 "data//maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 1059 "data//maps/Route104/scripts.pory"

# 1060 "data//maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 1061 "data//maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1062 "data//maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1063 "data//maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1064 "data//maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1065 "data//maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1066 "data//maps/Route104/scripts.pory"

# 1067 "data//maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1068 "data//maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1069 "data//maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1070 "data//maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1071 "data//maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1072 "data//maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1073 "data//maps/Route104/scripts.pory"

# 1074 "data//maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1075 "data//maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1076 "data//maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1077 "data//maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1078 "data//maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1079 "data//maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1080 "data//maps/Route104/scripts.pory"

# 1081 "data//maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1082 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1083 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1084 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1085 "data//maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1086 "data//maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1087 "data//maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1088 "data//maps/Route104/scripts.pory"

# 1089 "data//maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1090 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1091 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1092 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1093 "data//maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1094 "data//maps/Route104/scripts.pory"

# 1095 "data//maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1096 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1097 "data//maps/Route104/scripts.pory"

# 1098 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1099 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1100 "data//maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1101 "data//maps/Route104/scripts.pory"

# 1102 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1103 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1104 "data//maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1105 "data//maps/Route104/scripts.pory"

# 1106 "data//maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1107 "data//maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1108 "data//maps/Route104/scripts.pory"

# 1109 "data//maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1110 "data//maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1111 "data//maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1112 "data//maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1113 "data//maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1114 "data//maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1115 "data//maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1116 "data//maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1117 "data//maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1118 "data//maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1119 "data//maps/Route104/scripts.pory"

# 1120 "data//maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1121 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1122 "data//maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1123 "data//maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1124 "data//maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1125 "data//maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1126 "data//maps/Route104/scripts.pory"

# 1127 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1128 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1129 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1130 "data//maps/Route104/scripts.pory"

# 1131 "data//maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1132 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1133 "data//maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1134 "data//maps/Route104/scripts.pory"

# 1135 "data//maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1136 "data//maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1137 "data//maps/Route104/scripts.pory"
	.string "So…\l"
# 1138 "data//maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1139 "data//maps/Route104/scripts.pory"

# 1140 "data//maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1141 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1142 "data//maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1143 "data//maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1144 "data//maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1145 "data//maps/Route104/scripts.pory"

# 1146 "data//maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1147 "data//maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1148 "data//maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1149 "data//maps/Route104/scripts.pory"

# 1150 "data//maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1151 "data//maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1152 "data//maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1153 "data//maps/Route104/scripts.pory"

# 1154 "data//maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1155 "data//maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1156 "data//maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1157 "data//maps/Route104/scripts.pory"

# 1158 "data//maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1159 "data//maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1160 "data//maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1161 "data//maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1162 "data//maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1163 "data//maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1164 "data//maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1165 "data//maps/Route104/scripts.pory"

# 1166 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1167 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1168 "data//maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1169 "data//maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1170 "data//maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1171 "data//maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1172 "data//maps/Route104/scripts.pory"

# 1173 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1174 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1175 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1176 "data//maps/Route104/scripts.pory"

# 1177 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1178 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1179 "data//maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1180 "data//maps/Route104/scripts.pory"

# 1181 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1182 "data//maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1183 "data//maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1184 "data//maps/Route104/scripts.pory"
	.string "a battle?$"
# 1185 "data//maps/Route104/scripts.pory"

# 1186 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1187 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1188 "data//maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1189 "data//maps/Route104/scripts.pory"

# 1190 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1191 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1192 "data//maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1193 "data//maps/Route104/scripts.pory"

# 1194 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1195 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1196 "data//maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1197 "data//maps/Route104/scripts.pory"

# 1198 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1199 "data//maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1200 "data//maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1201 "data//maps/Route104/scripts.pory"

# 1202 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1203 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1204 "data//maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1205 "data//maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1206 "data//maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1207 "data//maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1208 "data//maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"
