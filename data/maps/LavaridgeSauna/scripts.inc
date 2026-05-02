LavaridgeSauna_MapScripts::
# 3 "data//maps/LavaridgeSauna/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 4 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_lt LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 9 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_2, 11
LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 11 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
	return

LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 5 "data//maps/LavaridgeSauna/scripts.pory"
	random 11
# 6 "data//maps/LavaridgeSauna/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
	goto LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


LavaridgeSauna_OnResume::
# 26 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_OnResume_1
	return

LavaridgeSauna_OnResume_1:
# 28 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_OnResume_Text_0, MSGBOX_DEFAULT
# 30 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 31 "data//maps/LavaridgeSauna/scripts.pory"
	warpcontinuescript MAP_LAVARIDGE_TOWN, 10, 7, LavaridgeTown_EventScript_KickedOutOfSauna
	return


LavaridgeSauna_EventScript_OldMan1::
# 36 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 37 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 38 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 0
# 39 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan2::
# 43 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 44 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 45 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 1
# 46 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan3::
# 50 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 51 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 52 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 2
# 53 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan4::
# 57 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 58 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 59 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 3
# 60 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan5::
# 64 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 65 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 66 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 4
# 67 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan6::
# 71 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 72 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 73 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 5
# 74 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan7::
# 78 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 79 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 80 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 6
# 81 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan8::
# 85 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 86 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 87 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 7
# 88 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan9::
# 92 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 93 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 94 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 8
# 95 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan10::
# 99 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 100 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 101 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 9
# 102 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan11::
# 106 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 10
# 107 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_FindTunnelManiac::
# 111 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_2, LavaridgeSauna_EventScript_FindTunnelManiac_2
# 297 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_32, MSGBOX_DEFAULT
# 298 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 299 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 300 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 301 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 302 "data//maps/LavaridgeSauna/scripts.pory"
	random 3
# 303 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_RESULT
# 304 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_6
# 306 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_7
# 308 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_8
LavaridgeSauna_EventScript_FindTunnelManiac_4:
# 311 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_2, VAR_TEMP_3
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_18
# 341 "data//maps/LavaridgeSauna/scripts.pory"
	random 3
# 342 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_RESULT
# 343 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_33
# 345 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_34
# 347 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_35
LavaridgeSauna_EventScript_FindTunnelManiac_31:
# 350 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_4, 1
# 351 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 352 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_TO_BLACK
# 353 "data//maps/LavaridgeSauna/scripts.pory"
	removeobject VAR_LAST_TALKED
# 354 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_44
LavaridgeSauna_EventScript_FindTunnelManiac_43:
# 393 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_EXIT
# 394 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 395 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 396 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_49
LavaridgeSauna_EventScript_FindTunnelManiac_17:
# 409 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 410 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 411 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_2:
# 112 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_gt LavaridgeSauna_EventScript_FindTunnelManiac_14
LavaridgeSauna_EventScript_FindTunnelManiac_13:
# 286 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_11
# 290 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_31, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_FindTunnelManiac_9:
# 292 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 293 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 294 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_6:
# 305 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_33, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_7:
# 307 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_34, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_8:
# 309 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_35, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_10:
# 113 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_3, LavaridgeSauna_EventScript_FindTunnelManiac_22
# 118 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_1, MSGBOX_YESNO
LavaridgeSauna_EventScript_FindTunnelManiac_21:
# 121 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_36
# 282 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_30, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_11:
# 287 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_14:
# 112 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_10
	goto LavaridgeSauna_EventScript_FindTunnelManiac_13

LavaridgeSauna_EventScript_FindTunnelManiac_18:
# 312 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_26
# 315 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_27
# 319 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacMetDefeated
# 320 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_2
# 321 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
LavaridgeSauna_EventScript_FindTunnelManiac_25:
# 323 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_40
# 336 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_31, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_FindTunnelManiac_39:
# 338 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_17

LavaridgeSauna_EventScript_FindTunnelManiac_22:
# 114 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_0, MSGBOX_YESNO
	goto LavaridgeSauna_EventScript_FindTunnelManiac_21

LavaridgeSauna_EventScript_FindTunnelManiac_26:
# 313 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacDefeated
	goto LavaridgeSauna_EventScript_FindTunnelManiac_25

LavaridgeSauna_EventScript_FindTunnelManiac_27:
# 316 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacTunnelDefeated
	goto LavaridgeSauna_EventScript_FindTunnelManiac_25

LavaridgeSauna_EventScript_FindTunnelManiac_33:
# 344 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated1
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_34:
# 346 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_35:
# 348 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated3
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_36:
# 122 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_3, LavaridgeSauna_EventScript_FindTunnelManiac_47
LavaridgeSauna_EventScript_FindTunnelManiac_46:
# 125 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 126 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_66
# 139 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 140 "data//maps/LavaridgeSauna/scripts.pory"
	special ChoosePartyMon
# 141 "data//maps/LavaridgeSauna/scripts.pory"
	waitstate
# 142 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 143 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGLETT
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 143 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DUGTRIO
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 144 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_BUNNELBY
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 144 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGGERSBY
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 145 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DRILBUR
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 145 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_EXCADRILL
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 268 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_69
# 274 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_29, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_40:
# 324 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_36, MSGBOX_DEFAULT
# 333 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_39

LavaridgeSauna_EventScript_FindTunnelManiac_44:
# 355 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 356 "data//maps/LavaridgeSauna/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 357 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 358 "data//maps/LavaridgeSauna/scripts.pory"
	addobject LOCALID_SAUNA_SAUNAATTENDANT
# 359 "data//maps/LavaridgeSauna/scripts.pory"
	showobjectat LOCALID_SAUNA_SAUNAATTENDANT, MAP_LAVARIDGE_SAUNA
# 360 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_62
LavaridgeSauna_EventScript_FindTunnelManiac_60:
# 368 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_59
LavaridgeSauna_EventScript_FindTunnelManiac_57:
# 376 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_53
# 376 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_53
# 384 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_54
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_47:
# 123 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_FindTunnelManiac_46

LavaridgeSauna_EventScript_FindTunnelManiac_49:
# 397 "data//maps/LavaridgeSauna/scripts.pory"
	delay 40
# 398 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_37, MSGBOX_DEFAULT
# 401 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 402 "data//maps/LavaridgeSauna/scripts.pory"
	delay 15
# 403 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_TO_BLACK
# 404 "data//maps/LavaridgeSauna/scripts.pory"
	delay 15
# 405 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_EXIT
# 406 "data//maps/LavaridgeSauna/scripts.pory"
	warp MAP_LAVARIDGE_TOWN, 9, 7
	goto LavaridgeSauna_EventScript_FindTunnelManiac_17

LavaridgeSauna_EventScript_FindTunnelManiac_51:
# 361 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, 1
# 363 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 364 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceLeft
# 365 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 366 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_52:
# 369 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, -1
# 371 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 372 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceRight
# 373 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 374 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_53:
# 377 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_F, 1
# 379 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 380 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceUp
# 381 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 382 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_54:
# 385 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, 1
# 387 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 388 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceLeft
# 389 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 390 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_59:
# 368 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_gt LavaridgeSauna_EventScript_FindTunnelManiac_52
	goto LavaridgeSauna_EventScript_FindTunnelManiac_57

LavaridgeSauna_EventScript_FindTunnelManiac_62:
# 360 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_lt LavaridgeSauna_EventScript_FindTunnelManiac_51
	goto LavaridgeSauna_EventScript_FindTunnelManiac_60

LavaridgeSauna_EventScript_FindTunnelManiac_66:
# 127 "data//maps/LavaridgeSauna/scripts.pory"
	delay 30
# 128 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 129 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 130 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 131 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_2, MSGBOX_DEFAULT
# 134 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 135 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 136 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_68:
# 146 "data//maps/LavaridgeSauna/scripts.pory"
	special BufferMonNickname
# 147 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_3, MSGBOX_YESNO
# 153 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_83
# 264 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_27, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_69:
# 269 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_28
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_83:
# 154 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 155 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 156 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_87
LavaridgeSauna_EventScript_FindTunnelManiac_86:
# 159 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_90
LavaridgeSauna_EventScript_FindTunnelManiac_89:
# 162 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_93
LavaridgeSauna_EventScript_FindTunnelManiac_92:
# 165 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_96
LavaridgeSauna_EventScript_FindTunnelManiac_95:
# 168 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 169 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_4
# 171 "data//maps/LavaridgeSauna/scripts.pory"
	playfanfare MUS_TOO_BAD
# 172 "data//maps/LavaridgeSauna/scripts.pory"
	waitfanfare
# 173 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_3
# 174 "data//maps/LavaridgeSauna/scripts.pory"
	callnative DeleteMonFromParty
# 175 "data//maps/LavaridgeSauna/scripts.pory"
	updatefollowingmon
# 176 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_99
LavaridgeSauna_EventScript_FindTunnelManiac_98:
# 231 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_101
# 250 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_24, MSGBOX_DEFAULT
# 254 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_25, MSGBOX_YESNO
# 255 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_123
# 259 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_26, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_87:
# 157 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto LavaridgeSauna_EventScript_FindTunnelManiac_86

LavaridgeSauna_EventScript_FindTunnelManiac_90:
# 160 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_FindTunnelManiac_89

LavaridgeSauna_EventScript_FindTunnelManiac_93:
# 163 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_92

LavaridgeSauna_EventScript_FindTunnelManiac_96:
# 166 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_FindTunnelManiac_95

LavaridgeSauna_EventScript_FindTunnelManiac_99:
# 177 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 178 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_LAVARBOR_TUNNEL_QUEST_STATE
# 179 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_105
# 181 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_106
# 183 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_107
# 185 "data//maps/LavaridgeSauna/scripts.pory"
	case 3, LavaridgeSauna_EventScript_FindTunnelManiac_108
# 188 "data//maps/LavaridgeSauna/scripts.pory"
	case 4, LavaridgeSauna_EventScript_FindTunnelManiac_109
# 191 "data//maps/LavaridgeSauna/scripts.pory"
	case 5, LavaridgeSauna_EventScript_FindTunnelManiac_110
# 194 "data//maps/LavaridgeSauna/scripts.pory"
	case 6, LavaridgeSauna_EventScript_FindTunnelManiac_111
# 197 "data//maps/LavaridgeSauna/scripts.pory"
	case 7, LavaridgeSauna_EventScript_FindTunnelManiac_112
# 200 "data//maps/LavaridgeSauna/scripts.pory"
	case 8, LavaridgeSauna_EventScript_FindTunnelManiac_113
# 203 "data//maps/LavaridgeSauna/scripts.pory"
	case 9, LavaridgeSauna_EventScript_FindTunnelManiac_114
# 206 "data//maps/LavaridgeSauna/scripts.pory"
	case 10, LavaridgeSauna_EventScript_FindTunnelManiac_115
# 209 "data//maps/LavaridgeSauna/scripts.pory"
	case 11, LavaridgeSauna_EventScript_FindTunnelManiac_116
# 212 "data//maps/LavaridgeSauna/scripts.pory"
	case 12, LavaridgeSauna_EventScript_FindTunnelManiac_117
# 215 "data//maps/LavaridgeSauna/scripts.pory"
	case 13, LavaridgeSauna_EventScript_FindTunnelManiac_118
# 218 "data//maps/LavaridgeSauna/scripts.pory"
	case 14, LavaridgeSauna_EventScript_FindTunnelManiac_119
# 221 "data//maps/LavaridgeSauna/scripts.pory"
	case 15, LavaridgeSauna_EventScript_FindTunnelManiac_120
# 224 "data//maps/LavaridgeSauna/scripts.pory"
	case 16, LavaridgeSauna_EventScript_FindTunnelManiac_121
# 227 "data//maps/LavaridgeSauna/scripts.pory"
	case 17, LavaridgeSauna_EventScript_FindTunnelManiac_122
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_101:
# 232 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 233 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 234 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 235 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_21, MSGBOX_DEFAULT
# 239 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 240 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 241 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_22
# 242 "data//maps/LavaridgeSauna/scripts.pory"
	waitmessage
# 243 "data//maps/LavaridgeSauna/scripts.pory"
	delay 45
# 244 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 245 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 246 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_105:
# 180 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_106:
# 182 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_107:
# 184 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_108:
# 186 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
# 187 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_109:
# 189 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
# 190 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_110:
# 192 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
# 193 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_111:
# 195 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
# 196 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_112:
# 198 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
# 199 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_113:
# 201 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
# 202 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_114:
# 204 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
# 205 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_115:
# 207 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
# 208 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_116:
# 210 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
# 211 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_117:
# 213 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
# 214 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_118:
# 216 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
# 217 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_119:
# 219 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
# 220 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_120:
# 222 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
# 223 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_121:
# 225 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
# 226 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_122:
# 228 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_20
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_123:
# 256 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9


LavaridgeSauna_EventScript_GiveAnotherDiggingMon::
# 416 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 417 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_le LavaridgeSauna_EventScript_GiveAnotherDiggingMon_2
# 430 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 431 "data//maps/LavaridgeSauna/scripts.pory"
	special ChoosePartyMon
# 432 "data//maps/LavaridgeSauna/scripts.pory"
	waitstate
# 433 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 434 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGLETT
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 434 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DUGTRIO
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 435 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_BUNNELBY
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 435 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGGERSBY
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 436 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DRILBUR
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 436 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_EXCADRILL
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 554 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_6
# 560 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_29, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4:
# 565 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 566 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 567 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_2:
# 418 "data//maps/LavaridgeSauna/scripts.pory"
	delay 30
# 419 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 420 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 421 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 422 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_2, MSGBOX_DEFAULT
# 425 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 426 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 427 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5:
# 437 "data//maps/LavaridgeSauna/scripts.pory"
	special BufferMonNickname
# 438 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_0, MSGBOX_YESNO
# 441 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_20
# 550 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_27, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_6:
# 555 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_28
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_20:
# 442 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 443 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 444 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_24
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_23:
# 447 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_27
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_26:
# 450 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_30
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_29:
# 453 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_33
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_32:
# 456 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 457 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_4
# 459 "data//maps/LavaridgeSauna/scripts.pory"
	playfanfare MUS_TOO_BAD
# 460 "data//maps/LavaridgeSauna/scripts.pory"
	waitfanfare
# 461 "data//maps/LavaridgeSauna/scripts.pory"
	callnative DeleteMonFromParty
# 462 "data//maps/LavaridgeSauna/scripts.pory"
	updatefollowingmon
# 463 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_GiveAnotherDiggingMon_36
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35:
# 518 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_38
# 537 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_1, MSGBOX_DEFAULT
# 540 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_25, MSGBOX_YESNO
# 541 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_60
# 545 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_26, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_24:
# 445 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_23

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_27:
# 448 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_26

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_30:
# 451 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_29

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_33:
# 454 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_32

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_36:
# 464 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 465 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_LAVARBOR_TUNNEL_QUEST_STATE
# 466 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_42
# 468 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_43
# 470 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_44
# 472 "data//maps/LavaridgeSauna/scripts.pory"
	case 3, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_45
# 475 "data//maps/LavaridgeSauna/scripts.pory"
	case 4, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_46
# 478 "data//maps/LavaridgeSauna/scripts.pory"
	case 5, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_47
# 481 "data//maps/LavaridgeSauna/scripts.pory"
	case 6, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_48
# 484 "data//maps/LavaridgeSauna/scripts.pory"
	case 7, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_49
# 487 "data//maps/LavaridgeSauna/scripts.pory"
	case 8, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_50
# 490 "data//maps/LavaridgeSauna/scripts.pory"
	case 9, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_51
# 493 "data//maps/LavaridgeSauna/scripts.pory"
	case 10, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_52
# 496 "data//maps/LavaridgeSauna/scripts.pory"
	case 11, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_53
# 499 "data//maps/LavaridgeSauna/scripts.pory"
	case 12, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_54
# 502 "data//maps/LavaridgeSauna/scripts.pory"
	case 13, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_55
# 505 "data//maps/LavaridgeSauna/scripts.pory"
	case 14, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_56
# 508 "data//maps/LavaridgeSauna/scripts.pory"
	case 15, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_57
# 511 "data//maps/LavaridgeSauna/scripts.pory"
	case 16, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_58
# 514 "data//maps/LavaridgeSauna/scripts.pory"
	case 17, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_59
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_38:
# 519 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 520 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 521 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 522 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_21, MSGBOX_DEFAULT
# 526 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 527 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 528 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_22
# 529 "data//maps/LavaridgeSauna/scripts.pory"
	waitmessage
# 530 "data//maps/LavaridgeSauna/scripts.pory"
	delay 45
# 531 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 532 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 533 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_42:
# 467 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_43:
# 469 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_44:
# 471 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_45:
# 473 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
# 474 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_46:
# 476 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
# 477 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_47:
# 479 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
# 480 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_48:
# 482 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
# 483 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_49:
# 485 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
# 486 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_50:
# 488 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
# 489 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_51:
# 491 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
# 492 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_52:
# 494 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
# 495 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_53:
# 497 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
# 498 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_54:
# 500 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
# 501 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_55:
# 503 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
# 504 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_56:
# 506 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
# 507 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_57:
# 509 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
# 510 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_58:
# 512 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
# 513 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_59:
# 515 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_20
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_60:
# 542 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4


# 571 "data//maps/LavaridgeSauna/scripts.pory"

# 572 "data//maps/LavaridgeSauna/scripts.pory"

# 573 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated1:
# 574 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Look what you've done!\p"
# 575 "data//maps/LavaridgeSauna/scripts.pory"
    .string "All that commotion from your POKéMON\n"
# 576 "data//maps/LavaridgeSauna/scripts.pory"
    .string "made the steam disperse!$"
# 577 "data//maps/LavaridgeSauna/scripts.pory"

# 578 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated2:
# 579 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Grrr…\p"
# 580 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Let me relax in peace!$"
# 581 "data//maps/LavaridgeSauna/scripts.pory"

# 582 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated3:
# 583 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Why are you in here causing a ruckus?!$"
# 584 "data//maps/LavaridgeSauna/scripts.pory"

# 585 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacDefeated:
# 586 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Just let me retire in peace!$"
# 587 "data//maps/LavaridgeSauna/scripts.pory"

# 588 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacTunnelDefeated:
# 589 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Wait a second…\l"
# 590 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Did you say something about a tunnel?$"
# 591 "data//maps/LavaridgeSauna/scripts.pory"

# 592 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacMetDefeated:
# 593 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Oh,\l"
# 594 "data//maps/LavaridgeSauna/scripts.pory"
    .string "It's you again.$"

LavaridgeSauna_OnResume_Text_0:
# 28 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Excuse me, but I've gotten several\n"
	.string "reports that you're disturbing other\l"
	.string "guests.\p"
	.string "I'm going to have to ask you to leave\n"
	.string "now.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_0:
# 114 "data//maps/LavaridgeSauna/scripts.pory"
	.string "TUNNEL MANIAC: Ah, you're back.\p"
	.string "Did you bring any digging POKéMON to\n"
	.string "help dig the tunnel?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_1:
# 118 "data//maps/LavaridgeSauna/scripts.pory"
	.string "TUNNEL MANIAC: I think I can complete\n"
	.string "the LAVARBOR TUNNEL if I have a\l"
	.string "reliable crew.\p"
	.string "Did you bring any digging POKéMON to\n"
	.string "help dig the tunnel?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_2:
# 131 "data//maps/LavaridgeSauna/scripts.pory"
	.string "That's your last POKéMON…\p"
	.string "If this POKéMON joins the tunnel crew\n"
	.string "right now, you'll be defenseless!\p"
	.string "But I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "Well, it's fine with me!\n"
	.string "I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_3:
# 147 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hmm…\l"
	.string "This is a digging POKéMON!\p"
	.string "But it will be hard work…\p"
	.string "I doubt your {STR_VAR_1} will\n"
	.string "survive.\p"
	.string "Even if it does, the grueling labor will\n"
	.string "change it for good…\p"
	.string "It won't ever want to come back.\p"
	.string "Are you sure you want {STR_VAR_1}\n"
	.string "to work on the LAVARBOR TUNNEL?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_4:
# 169 "data//maps/LavaridgeSauna/scripts.pory"
	.string "{PLAYER} handed over {STR_VAR_1}\nto the TUNNEL MANIAC.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_5:
# 180 "data//maps/LavaridgeSauna/scripts.pory"
	.string "no$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_6:
# 186 "data//maps/LavaridgeSauna/scripts.pory"
	.string "one$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_7:
# 187 "data//maps/LavaridgeSauna/scripts.pory"
	.string "14$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_8:
# 189 "data//maps/LavaridgeSauna/scripts.pory"
	.string "two$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_9:
# 190 "data//maps/LavaridgeSauna/scripts.pory"
	.string "13$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_10:
# 192 "data//maps/LavaridgeSauna/scripts.pory"
	.string "three$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_11:
# 193 "data//maps/LavaridgeSauna/scripts.pory"
	.string "12$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_12:
# 195 "data//maps/LavaridgeSauna/scripts.pory"
	.string "four$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_13:
# 196 "data//maps/LavaridgeSauna/scripts.pory"
	.string "11$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_14:
# 198 "data//maps/LavaridgeSauna/scripts.pory"
	.string "five$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_15:
# 199 "data//maps/LavaridgeSauna/scripts.pory"
	.string "10$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_16:
# 201 "data//maps/LavaridgeSauna/scripts.pory"
	.string "six$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_17:
# 202 "data//maps/LavaridgeSauna/scripts.pory"
	.string "nine$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_18:
# 204 "data//maps/LavaridgeSauna/scripts.pory"
	.string "seven$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_19:
# 205 "data//maps/LavaridgeSauna/scripts.pory"
	.string "eight$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_20:
# 228 "data//maps/LavaridgeSauna/scripts.pory"
	.string "15$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_21:
# 235 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Ah!\l"
	.string "This is excellent!\p"
	.string "To be completely honest, I didn't really\n"
	.string "expect to have to go back to work.\p"
	.string "But you've brought me 15 digging\n"
	.string "POKéMON!\p"
	.string "That means we can start work on\n"
	.string "finishing the LAVARBOR TUNNEL.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_22:
# 241 "data//maps/LavaridgeSauna/scripts.pory"
	.string "… … … … … … … … … … …$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_23:
# 246 "data//maps/LavaridgeSauna/scripts.pory"
	.string "What?\p"
	.string "I can't start immediately,\l"
	.string "I have to finish my sauna session!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_24:
# 250 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Ah yes, it will be difficult, but\n"
	.string "{STR_VAR_1}'s help will surely speed\l"
	.string "things up.\p"
	.string "In total, you've volunteered\n"
	.string "{STR_VAR_2} digging POKéMON for the\l"
	.string "tunnel crew.\p"
	.string "That means we still need\n"
	.string "{STR_VAR_3} more to join the team\l"
	.string "before we can start working.\p"
	.string "But you seem reliable and motivated!\l"
	.string "Unlike my boys…\p"
	.string "So I'm sure you'll be back with more\n"
	.string "POKéMON soon enough.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_25:
# 254 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Do you have any more POKéMON to\n"
	.string "volunteer for the crew right now?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_26:
# 259 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Well when you do, you know where to find\n"
	.string "me!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_27:
# 264 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Right, then.\n"
	.string "I don't blame you.\p"
	.string "Digging that tunnel will be very\n"
	.string "grueling work.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_28:
# 269 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Oh, you don't want to volunteer any\n"
	.string "POKéMON for the tunnel crew right now?\p"
	.string "Well, I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "So I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_29:
# 274 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hmm…\l"
	.string "This is not a digging POKéMON…\p"
	.string "Digging POKéMON are the only POKéMON\n"
	.string "I use, because they're so hardy!\p"
	.string "Completing the LAVARBOR TUNNEL will be\n"
	.string "brutal work…\p"
	.string "To dig this tunnel, we'll need none but\n"
	.string "the best digging POKéMON.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_30:
# 282 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Well, I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "It's fine with me!\n"
	.string "I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_31:
# 290 "data//maps/LavaridgeSauna/scripts.pory"
	.string "They used to call me the\n"
	.string "TUNNEL MANIAC.\p"
	.string "But these days I've left the tunneling\n"
	.string "to my two boys in FALLARBOR.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_32:
# 297 "data//maps/LavaridgeSauna/scripts.pory"
	.string "… … … … … … … …$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_33:
# 305 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hey! You're blocking the warm air!\p"
	.string "It's creating a cold pocket!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_34:
# 307 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Huh?\n"
	.string "Some kid?\p"
	.string "You're blocking the warm air!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_35:
# 309 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Get outta my way!\p"
	.string "You're bringing in a draft!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_36:
# 324 "data//maps/LavaridgeSauna/scripts.pory"
	.string "You say you're here looking for someone\n"
	.string "who can complete the LAVARBOR TUNNEL?\p"
	.string "Well, they used to call me the TUNNEL\n"
	.string "MANIAC.\p"
	.string "I was originally supposed to lead the\n"
	.string "project, but our funding fell through.\p"
	.string "Then it came time for me to retire, so\n"
	.string "I left the digging to my two sons in\l"
	.string "FALLARBOR…\p"
	.string "Though they seem more interested in\n"
	.string "digging for fossils…\p"
	.string "… … … … … … … …\p"
	.string "If I could visit them more often, maybe\n"
	.string "I could inspire them to use their\l"
	.string "talents for something more productive…\p"
	.string "But since we can't rely on outside\n"
	.string "funding to complete the tunnel,\l"
	.string "I'll need quite a bit of help.\p"
	.string "If you bring me 15 digging POKéMON, and\n"
	.string "give us enough time, I think I may be\l"
	.string "able to make some progress.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_37:
# 398 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Excuse me…\p"
	.string "I've gotten several reports that you're\n"
	.string "disturbing other guests.\p"
	.string "I'm going to have to ask you to leave\n"
	.string "the sauna now.$"

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_0:
# 438 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hmm…\l"
	.string "This is a digging POKéMON!\p"
	.string "But once it's immersed in the tunnel\n"
	.string "lifestyle, it won't ever come back.\p"
	.string "Are you sure you want {STR_VAR_1}\n"
	.string "to work on the LAVARBOR TUNNEL?$"

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_1:
# 537 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Ah yes, it will be tough, but\n"
	.string "{STR_VAR_1}'s help will surely speed\l"
	.string "things up.\p"
	.string "In total, you've volunteered\n"
	.string "{STR_VAR_2} digging POKéMON for the\l"
	.string "tunnel crew.\p"
	.string "That means we still need\n"
	.string "{STR_VAR_3} more to join the team\l"
	.string "before we can start working.$"
