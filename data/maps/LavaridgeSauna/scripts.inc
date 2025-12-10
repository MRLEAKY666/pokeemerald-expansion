LavaridgeSauna_MapScripts::
# 3 "data//maps/LavaridgeSauna/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 4 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_lt LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_2, 11
	return

LavaridgeSauna_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data//maps/LavaridgeSauna/scripts.pory"
	random 11
# 6 "data//maps/LavaridgeSauna/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
	return


LavaridgeSauna_OnResume::
# 25 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_OnResume_1
	return

LavaridgeSauna_OnResume_1:
# 27 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_OnResume_Text_0, MSGBOX_DEFAULT
# 29 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 30 "data//maps/LavaridgeSauna/scripts.pory"
	warpcontinuescript MAP_LAVARIDGE_TOWN, 9, 7, LavaridgeTown_EventScript_KickedOutOfSauna
	return


LavaridgeSauna_EventScript_OldMan1::
# 35 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 36 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 37 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 0
# 38 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan2::
# 42 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 43 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 44 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 1
# 45 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan3::
# 49 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 50 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 51 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 2
# 52 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan4::
# 56 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 57 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 58 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 3
# 59 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan5::
# 63 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 64 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 65 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 4
# 66 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan6::
# 70 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 71 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 72 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 5
# 73 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan7::
# 77 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 78 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 79 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 6
# 80 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan8::
# 84 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 85 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 86 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 7
# 87 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan9::
# 91 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 92 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 93 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 8
# 94 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan10::
# 98 "data//maps/LavaridgeSauna/scripts.pory"
	lock
# 99 "data//maps/LavaridgeSauna/scripts.pory"
	faceplayer
# 100 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 9
# 101 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_OldMan11::
# 105 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_TEMP_3, 10
# 106 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
	return


LavaridgeSauna_EventScript_FindTunnelManiac::
# 110 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_2, LavaridgeSauna_EventScript_FindTunnelManiac_2
# 296 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_32, MSGBOX_DEFAULT
# 297 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 298 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 299 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 300 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 301 "data//maps/LavaridgeSauna/scripts.pory"
	random 3
# 302 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_RESULT
# 303 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_6
# 305 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_7
# 307 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_8
LavaridgeSauna_EventScript_FindTunnelManiac_4:
# 310 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_2, VAR_TEMP_3
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_18
# 340 "data//maps/LavaridgeSauna/scripts.pory"
	random 3
# 341 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_RESULT
# 342 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_33
# 344 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_34
# 346 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_35
LavaridgeSauna_EventScript_FindTunnelManiac_31:
# 349 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_4, 1
# 350 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 351 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_TO_BLACK
# 352 "data//maps/LavaridgeSauna/scripts.pory"
	removeobject VAR_LAST_TALKED
# 353 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_44
LavaridgeSauna_EventScript_FindTunnelManiac_43:
# 392 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_EXIT
# 393 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 394 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 395 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_49
LavaridgeSauna_EventScript_FindTunnelManiac_17:
# 408 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 409 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 410 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_2:
# 111 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_gt LavaridgeSauna_EventScript_FindTunnelManiac_14
LavaridgeSauna_EventScript_FindTunnelManiac_13:
# 285 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_11
# 289 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_31, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_FindTunnelManiac_9:
# 291 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 292 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 293 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_6:
# 304 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_33, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_7:
# 306 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_34, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_8:
# 308 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_35, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_4

LavaridgeSauna_EventScript_FindTunnelManiac_10:
# 112 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_3, LavaridgeSauna_EventScript_FindTunnelManiac_22
# 117 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_1, MSGBOX_YESNO
LavaridgeSauna_EventScript_FindTunnelManiac_21:
# 120 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_36
# 281 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_30, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_11:
# 286 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_14:
# 111 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_10
	goto LavaridgeSauna_EventScript_FindTunnelManiac_13

LavaridgeSauna_EventScript_FindTunnelManiac_18:
# 311 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_26
# 314 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_27
# 318 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacMetDefeated
# 319 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_2
# 320 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_FindTunnelManiac
LavaridgeSauna_EventScript_FindTunnelManiac_25:
# 322 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_40
# 335 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_31, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_FindTunnelManiac_39:
# 337 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_17

LavaridgeSauna_EventScript_FindTunnelManiac_22:
# 113 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_0, MSGBOX_YESNO
	goto LavaridgeSauna_EventScript_FindTunnelManiac_21

LavaridgeSauna_EventScript_FindTunnelManiac_26:
# 312 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacDefeated
	goto LavaridgeSauna_EventScript_FindTunnelManiac_25

LavaridgeSauna_EventScript_FindTunnelManiac_27:
# 315 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_TUNNEL_MANIAC, LavaridgeSauna_Text_TunnelManiacTunnelDefeated
	goto LavaridgeSauna_EventScript_FindTunnelManiac_25

LavaridgeSauna_EventScript_FindTunnelManiac_33:
# 343 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated1
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_34:
# 345 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_35:
# 347 "data//maps/LavaridgeSauna/scripts.pory"
	trainerbattle_no_intro TRAINER_RANDOM_SAUNA_OLD_MAN, LavaridgeSauna_Text_RandomSaunaOldManDefeated3
	goto LavaridgeSauna_EventScript_FindTunnelManiac_31

LavaridgeSauna_EventScript_FindTunnelManiac_36:
# 121 "data//maps/LavaridgeSauna/scripts.pory"
	goto_if_set FLAG_TEMP_3, LavaridgeSauna_EventScript_FindTunnelManiac_47
LavaridgeSauna_EventScript_FindTunnelManiac_46:
# 124 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 125 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_66
# 138 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 139 "data//maps/LavaridgeSauna/scripts.pory"
	special ChoosePartyMon
# 140 "data//maps/LavaridgeSauna/scripts.pory"
	waitstate
# 141 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 142 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGLETT
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 142 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DUGTRIO
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 143 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_BUNNELBY
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 143 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGGERSBY
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 144 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DRILBUR
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 144 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_EXCADRILL
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_68
# 267 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_69
# 273 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_29, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_40:
# 323 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_36, MSGBOX_DEFAULT
# 332 "data//maps/LavaridgeSauna/scripts.pory"
	setvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 2
	goto LavaridgeSauna_EventScript_FindTunnelManiac_39

LavaridgeSauna_EventScript_FindTunnelManiac_44:
# 354 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 355 "data//maps/LavaridgeSauna/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 356 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 357 "data//maps/LavaridgeSauna/scripts.pory"
	addobject LOCALID_SAUNA_SAUNAATTENDANT
# 358 "data//maps/LavaridgeSauna/scripts.pory"
	showobjectat LOCALID_SAUNA_SAUNAATTENDANT, MAP_LAVARIDGE_SAUNA
# 359 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_62
LavaridgeSauna_EventScript_FindTunnelManiac_60:
# 367 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_59
LavaridgeSauna_EventScript_FindTunnelManiac_57:
# 375 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_53
# 375 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_53
# 383 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_54
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_47:
# 122 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_FindTunnelManiac_46

LavaridgeSauna_EventScript_FindTunnelManiac_49:
# 396 "data//maps/LavaridgeSauna/scripts.pory"
	delay 40
# 397 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_37, MSGBOX_DEFAULT
# 400 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 401 "data//maps/LavaridgeSauna/scripts.pory"
	delay 15
# 402 "data//maps/LavaridgeSauna/scripts.pory"
	fadescreen FADE_TO_BLACK
# 403 "data//maps/LavaridgeSauna/scripts.pory"
	delay 15
# 404 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_EXIT
# 405 "data//maps/LavaridgeSauna/scripts.pory"
	warp MAP_LAVARIDGE_TOWN, 9, 7
	goto LavaridgeSauna_EventScript_FindTunnelManiac_17

LavaridgeSauna_EventScript_FindTunnelManiac_51:
# 360 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, 1
# 362 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 363 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceLeft
# 364 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 365 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_52:
# 368 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, -1
# 370 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 371 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceRight
# 372 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 373 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_53:
# 376 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_F, 1
# 378 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 379 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceUp
# 380 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 381 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_54:
# 384 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_TEMP_E, 1
# 386 "data//maps/LavaridgeSauna/scripts.pory"
	setobjectxy LOCALID_SAUNA_SAUNAATTENDANT, VAR_TEMP_E, VAR_TEMP_F
# 387 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_SAUNA_SAUNAATTENDANT, Common_Movement_WalkInPlaceLeft
# 388 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 389 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_43

LavaridgeSauna_EventScript_FindTunnelManiac_59:
# 367 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_gt LavaridgeSauna_EventScript_FindTunnelManiac_52
	goto LavaridgeSauna_EventScript_FindTunnelManiac_57

LavaridgeSauna_EventScript_FindTunnelManiac_62:
# 359 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_lt LavaridgeSauna_EventScript_FindTunnelManiac_51
	goto LavaridgeSauna_EventScript_FindTunnelManiac_60

LavaridgeSauna_EventScript_FindTunnelManiac_66:
# 126 "data//maps/LavaridgeSauna/scripts.pory"
	delay 30
# 127 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 128 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 129 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 130 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_2, MSGBOX_DEFAULT
# 133 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 134 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 135 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_FindTunnelManiac_68:
# 145 "data//maps/LavaridgeSauna/scripts.pory"
	special BufferMonNickname
# 146 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_3, MSGBOX_YESNO
# 152 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_83
# 263 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_27, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_69:
# 268 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_28
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_83:
# 153 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 154 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 155 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_87
LavaridgeSauna_EventScript_FindTunnelManiac_86:
# 158 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_90
LavaridgeSauna_EventScript_FindTunnelManiac_89:
# 161 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_93
LavaridgeSauna_EventScript_FindTunnelManiac_92:
# 164 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_96
LavaridgeSauna_EventScript_FindTunnelManiac_95:
# 167 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 168 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_4
# 170 "data//maps/LavaridgeSauna/scripts.pory"
	playfanfare MUS_TOO_BAD
# 171 "data//maps/LavaridgeSauna/scripts.pory"
	waitfanfare
# 172 "data//maps/LavaridgeSauna/scripts.pory"
	setflag FLAG_TEMP_3
# 173 "data//maps/LavaridgeSauna/scripts.pory"
	callnative DeleteMonFromParty
# 174 "data//maps/LavaridgeSauna/scripts.pory"
	updatefollowingmon
# 175 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_FindTunnelManiac_99
LavaridgeSauna_EventScript_FindTunnelManiac_98:
# 230 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_101
# 249 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_24, MSGBOX_DEFAULT
# 253 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_25, MSGBOX_YESNO
# 254 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_FindTunnelManiac_123
# 258 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_26, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_87:
# 156 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto LavaridgeSauna_EventScript_FindTunnelManiac_86

LavaridgeSauna_EventScript_FindTunnelManiac_90:
# 159 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_FindTunnelManiac_89

LavaridgeSauna_EventScript_FindTunnelManiac_93:
# 162 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_FindTunnelManiac_92

LavaridgeSauna_EventScript_FindTunnelManiac_96:
# 165 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_FindTunnelManiac_95

LavaridgeSauna_EventScript_FindTunnelManiac_99:
# 176 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 177 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_LAVARBOR_TUNNEL_QUEST_STATE
# 178 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_FindTunnelManiac_105
# 180 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_FindTunnelManiac_106
# 182 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_FindTunnelManiac_107
# 184 "data//maps/LavaridgeSauna/scripts.pory"
	case 3, LavaridgeSauna_EventScript_FindTunnelManiac_108
# 187 "data//maps/LavaridgeSauna/scripts.pory"
	case 4, LavaridgeSauna_EventScript_FindTunnelManiac_109
# 190 "data//maps/LavaridgeSauna/scripts.pory"
	case 5, LavaridgeSauna_EventScript_FindTunnelManiac_110
# 193 "data//maps/LavaridgeSauna/scripts.pory"
	case 6, LavaridgeSauna_EventScript_FindTunnelManiac_111
# 196 "data//maps/LavaridgeSauna/scripts.pory"
	case 7, LavaridgeSauna_EventScript_FindTunnelManiac_112
# 199 "data//maps/LavaridgeSauna/scripts.pory"
	case 8, LavaridgeSauna_EventScript_FindTunnelManiac_113
# 202 "data//maps/LavaridgeSauna/scripts.pory"
	case 9, LavaridgeSauna_EventScript_FindTunnelManiac_114
# 205 "data//maps/LavaridgeSauna/scripts.pory"
	case 10, LavaridgeSauna_EventScript_FindTunnelManiac_115
# 208 "data//maps/LavaridgeSauna/scripts.pory"
	case 11, LavaridgeSauna_EventScript_FindTunnelManiac_116
# 211 "data//maps/LavaridgeSauna/scripts.pory"
	case 12, LavaridgeSauna_EventScript_FindTunnelManiac_117
# 214 "data//maps/LavaridgeSauna/scripts.pory"
	case 13, LavaridgeSauna_EventScript_FindTunnelManiac_118
# 217 "data//maps/LavaridgeSauna/scripts.pory"
	case 14, LavaridgeSauna_EventScript_FindTunnelManiac_119
# 220 "data//maps/LavaridgeSauna/scripts.pory"
	case 15, LavaridgeSauna_EventScript_FindTunnelManiac_120
# 223 "data//maps/LavaridgeSauna/scripts.pory"
	case 16, LavaridgeSauna_EventScript_FindTunnelManiac_121
# 226 "data//maps/LavaridgeSauna/scripts.pory"
	case 17, LavaridgeSauna_EventScript_FindTunnelManiac_122
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_101:
# 231 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 232 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 233 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 234 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_21, MSGBOX_DEFAULT
# 238 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 239 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 240 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_22
# 241 "data//maps/LavaridgeSauna/scripts.pory"
	waitmessage
# 242 "data//maps/LavaridgeSauna/scripts.pory"
	delay 45
# 243 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 244 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 245 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9

LavaridgeSauna_EventScript_FindTunnelManiac_105:
# 179 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_106:
# 181 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_107:
# 183 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_108:
# 185 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
# 186 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_109:
# 188 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
# 189 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_110:
# 191 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
# 192 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_111:
# 194 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
# 195 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_112:
# 197 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
# 198 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_113:
# 200 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
# 201 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_114:
# 203 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
# 204 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_115:
# 206 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
# 207 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_116:
# 209 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
# 210 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_117:
# 212 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
# 213 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_118:
# 215 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
# 216 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_119:
# 218 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
# 219 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_120:
# 221 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
# 222 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_121:
# 224 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
# 225 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_122:
# 227 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_20
	goto LavaridgeSauna_EventScript_FindTunnelManiac_98

LavaridgeSauna_EventScript_FindTunnelManiac_123:
# 255 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_FindTunnelManiac_9


LavaridgeSauna_EventScript_GiveAnotherDiggingMon::
# 415 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 416 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_le LavaridgeSauna_EventScript_GiveAnotherDiggingMon_2
# 429 "data//maps/LavaridgeSauna/scripts.pory"
	hidefollower
# 430 "data//maps/LavaridgeSauna/scripts.pory"
	special ChoosePartyMon
# 431 "data//maps/LavaridgeSauna/scripts.pory"
	waitstate
# 432 "data//maps/LavaridgeSauna/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 433 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGLETT
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 433 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DUGTRIO
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 434 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_BUNNELBY
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 434 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DIGGERSBY
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 435 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_DRILBUR
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 435 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, SPECIES_EXCADRILL
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5
# 553 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_6
# 559 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_29, MSGBOX_DEFAULT
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4:
# 564 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 565 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 566 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_2:
# 417 "data//maps/LavaridgeSauna/scripts.pory"
	delay 30
# 418 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 419 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 420 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 421 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_2, MSGBOX_DEFAULT
# 424 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 425 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 426 "data//maps/LavaridgeSauna/scripts.pory"
	release
	end

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_5:
# 436 "data//maps/LavaridgeSauna/scripts.pory"
	special BufferMonNickname
# 437 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_0, MSGBOX_YESNO
# 440 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_20
# 549 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_27, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_6:
# 554 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_28
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_20:
# 441 "data//maps/LavaridgeSauna/scripts.pory"
	delay 10
# 442 "data//maps/LavaridgeSauna/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 443 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_24
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_23:
# 446 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_27
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_26:
# 449 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_30
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_29:
# 452 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_33
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_32:
# 455 "data//maps/LavaridgeSauna/scripts.pory"
	waitmovement
# 456 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_4
# 458 "data//maps/LavaridgeSauna/scripts.pory"
	playfanfare MUS_TOO_BAD
# 459 "data//maps/LavaridgeSauna/scripts.pory"
	waitfanfare
# 460 "data//maps/LavaridgeSauna/scripts.pory"
	callnative DeleteMonFromParty
# 461 "data//maps/LavaridgeSauna/scripts.pory"
	updatefollowingmon
# 462 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 16
	goto_if_le LavaridgeSauna_EventScript_GiveAnotherDiggingMon_36
LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35:
# 517 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 17
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_38
# 536 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_1, MSGBOX_DEFAULT
# 539 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_25, MSGBOX_YESNO
# 540 "data//maps/LavaridgeSauna/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeSauna_EventScript_GiveAnotherDiggingMon_60
# 544 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_26, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_24:
# 444 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_23

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_27:
# 447 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_26

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_30:
# 450 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_29

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_33:
# 453 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_32

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_36:
# 463 "data//maps/LavaridgeSauna/scripts.pory"
	addvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 464 "data//maps/LavaridgeSauna/scripts.pory"
	switch VAR_LAVARBOR_TUNNEL_QUEST_STATE
# 465 "data//maps/LavaridgeSauna/scripts.pory"
	case 0, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_42
# 467 "data//maps/LavaridgeSauna/scripts.pory"
	case 1, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_43
# 469 "data//maps/LavaridgeSauna/scripts.pory"
	case 2, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_44
# 471 "data//maps/LavaridgeSauna/scripts.pory"
	case 3, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_45
# 474 "data//maps/LavaridgeSauna/scripts.pory"
	case 4, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_46
# 477 "data//maps/LavaridgeSauna/scripts.pory"
	case 5, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_47
# 480 "data//maps/LavaridgeSauna/scripts.pory"
	case 6, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_48
# 483 "data//maps/LavaridgeSauna/scripts.pory"
	case 7, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_49
# 486 "data//maps/LavaridgeSauna/scripts.pory"
	case 8, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_50
# 489 "data//maps/LavaridgeSauna/scripts.pory"
	case 9, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_51
# 492 "data//maps/LavaridgeSauna/scripts.pory"
	case 10, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_52
# 495 "data//maps/LavaridgeSauna/scripts.pory"
	case 11, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_53
# 498 "data//maps/LavaridgeSauna/scripts.pory"
	case 12, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_54
# 501 "data//maps/LavaridgeSauna/scripts.pory"
	case 13, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_55
# 504 "data//maps/LavaridgeSauna/scripts.pory"
	case 14, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_56
# 507 "data//maps/LavaridgeSauna/scripts.pory"
	case 15, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_57
# 510 "data//maps/LavaridgeSauna/scripts.pory"
	case 16, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_58
# 513 "data//maps/LavaridgeSauna/scripts.pory"
	case 17, LavaridgeSauna_EventScript_GiveAnotherDiggingMon_59
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_38:
# 518 "data//maps/LavaridgeSauna/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 519 "data//maps/LavaridgeSauna/scripts.pory"
	playse SE_PIN
# 520 "data//maps/LavaridgeSauna/scripts.pory"
	waitse
# 521 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_21, MSGBOX_DEFAULT
# 525 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 526 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 527 "data//maps/LavaridgeSauna/scripts.pory"
	message LavaridgeSauna_EventScript_FindTunnelManiac_Text_22
# 528 "data//maps/LavaridgeSauna/scripts.pory"
	waitmessage
# 529 "data//maps/LavaridgeSauna/scripts.pory"
	delay 45
# 530 "data//maps/LavaridgeSauna/scripts.pory"
	closemessage
# 531 "data//maps/LavaridgeSauna/scripts.pory"
	delay 60
# 532 "data//maps/LavaridgeSauna/scripts.pory"
	msgbox LavaridgeSauna_EventScript_FindTunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_42:
# 466 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_43:
# 468 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_44:
# 470 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_5
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_45:
# 472 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
# 473 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_46:
# 475 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
# 476 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_47:
# 478 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
# 479 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_48:
# 481 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
# 482 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_49:
# 484 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
# 485 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_50:
# 487 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
# 488 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_51:
# 490 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
# 491 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_52:
# 493 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_19
# 494 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_18
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_53:
# 496 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_17
# 497 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_16
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_54:
# 499 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_15
# 500 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_14
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_55:
# 502 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_13
# 503 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_12
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_56:
# 505 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_11
# 506 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_10
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_57:
# 508 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_9
# 509 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_8
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_58:
# 511 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_7
# 512 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_3, LavaridgeSauna_EventScript_FindTunnelManiac_Text_6
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_59:
# 514 "data//maps/LavaridgeSauna/scripts.pory"
	bufferstring STR_VAR_2, LavaridgeSauna_EventScript_FindTunnelManiac_Text_20
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_35

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_60:
# 541 "data//maps/LavaridgeSauna/scripts.pory"
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon
	goto LavaridgeSauna_EventScript_GiveAnotherDiggingMon_4


# 570 "data//maps/LavaridgeSauna/scripts.pory"

# 571 "data//maps/LavaridgeSauna/scripts.pory"

# 572 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated1:
# 573 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Look what you've done!\p"
# 574 "data//maps/LavaridgeSauna/scripts.pory"
    .string "All that commotion from your POKéMON\n"
# 575 "data//maps/LavaridgeSauna/scripts.pory"
    .string "made the steam disperse!$"
# 576 "data//maps/LavaridgeSauna/scripts.pory"

# 577 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated2:
# 578 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Grrr…\p"
# 579 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Let me relax in peace!$"
# 580 "data//maps/LavaridgeSauna/scripts.pory"

# 581 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_RandomSaunaOldManDefeated3:
# 582 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Why are you in here causing a ruckus?!$"
# 583 "data//maps/LavaridgeSauna/scripts.pory"

# 584 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacDefeated:
# 585 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Just let me retire in peace!$"
# 586 "data//maps/LavaridgeSauna/scripts.pory"

# 587 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacTunnelDefeated:
# 588 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Wait a second…\l"
# 589 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Did you say something about a tunnel?$"
# 590 "data//maps/LavaridgeSauna/scripts.pory"

# 591 "data//maps/LavaridgeSauna/scripts.pory"
LavaridgeSauna_Text_TunnelManiacMetDefeated:
# 592 "data//maps/LavaridgeSauna/scripts.pory"
    .string "Oh,\l"
# 593 "data//maps/LavaridgeSauna/scripts.pory"
    .string "It's you again.$"

LavaridgeSauna_OnResume_Text_0:
# 27 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Excuse me, but I've gotten several\n"
	.string "reports that you're disturbing other\l"
	.string "guests.\p"
	.string "I'm going to have to ask you to leave\n"
	.string "now.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_0:
# 113 "data//maps/LavaridgeSauna/scripts.pory"
	.string "TUNNEL MANIAC: Ah, you're back.\p"
	.string "Did you bring any digging POKéMON to\n"
	.string "help dig the tunnel?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_1:
# 117 "data//maps/LavaridgeSauna/scripts.pory"
	.string "TUNNEL MANIAC: I think I can complete\n"
	.string "the LAVARBOR TUNNEL if I have a\l"
	.string "reliable crew.\p"
	.string "Did you bring any digging POKéMON to\n"
	.string "help dig the tunnel?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_2:
# 130 "data//maps/LavaridgeSauna/scripts.pory"
	.string "That's your last POKéMON…\p"
	.string "If this POKéMON joins the tunnel crew\n"
	.string "right now, you'll be defenseless!\p"
	.string "But I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "Well, it's fine with me!\n"
	.string "I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_3:
# 146 "data//maps/LavaridgeSauna/scripts.pory"
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
# 168 "data//maps/LavaridgeSauna/scripts.pory"
	.string "{PLAYER} handed over {STR_VAR_1}\nto the TUNNEL MANIAC.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_5:
# 179 "data//maps/LavaridgeSauna/scripts.pory"
	.string "no$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_6:
# 185 "data//maps/LavaridgeSauna/scripts.pory"
	.string "one$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_7:
# 186 "data//maps/LavaridgeSauna/scripts.pory"
	.string "14$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_8:
# 188 "data//maps/LavaridgeSauna/scripts.pory"
	.string "two$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_9:
# 189 "data//maps/LavaridgeSauna/scripts.pory"
	.string "13$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_10:
# 191 "data//maps/LavaridgeSauna/scripts.pory"
	.string "three$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_11:
# 192 "data//maps/LavaridgeSauna/scripts.pory"
	.string "12$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_12:
# 194 "data//maps/LavaridgeSauna/scripts.pory"
	.string "four$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_13:
# 195 "data//maps/LavaridgeSauna/scripts.pory"
	.string "11$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_14:
# 197 "data//maps/LavaridgeSauna/scripts.pory"
	.string "five$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_15:
# 198 "data//maps/LavaridgeSauna/scripts.pory"
	.string "10$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_16:
# 200 "data//maps/LavaridgeSauna/scripts.pory"
	.string "six$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_17:
# 201 "data//maps/LavaridgeSauna/scripts.pory"
	.string "nine$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_18:
# 203 "data//maps/LavaridgeSauna/scripts.pory"
	.string "seven$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_19:
# 204 "data//maps/LavaridgeSauna/scripts.pory"
	.string "eight$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_20:
# 227 "data//maps/LavaridgeSauna/scripts.pory"
	.string "15$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_21:
# 234 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Ah!\l"
	.string "This is excellent!\p"
	.string "To be completely honest, I didn't really\n"
	.string "expect to have to go back to work.\p"
	.string "But you've brought me 15 digging\n"
	.string "POKéMON!\p"
	.string "That means we can start work on\n"
	.string "finishing the LAVARBOR TUNNEL.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_22:
# 240 "data//maps/LavaridgeSauna/scripts.pory"
	.string "… … … … … … … … … … …$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_23:
# 245 "data//maps/LavaridgeSauna/scripts.pory"
	.string "What?\p"
	.string "I can't start immediately,\l"
	.string "I have to finish my sauna session!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_24:
# 249 "data//maps/LavaridgeSauna/scripts.pory"
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
# 253 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Do you have any more POKéMON to\n"
	.string "volunteer for the crew right now?$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_26:
# 258 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Well when you do, you know where to find\n"
	.string "me!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_27:
# 263 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Right, then.\n"
	.string "I don't blame you.\p"
	.string "Digging that tunnel will be very\n"
	.string "grueling work.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_28:
# 268 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Oh, you don't want to volunteer any\n"
	.string "POKéMON for the tunnel crew right now?\p"
	.string "Well, I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "So I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_29:
# 273 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hmm…\l"
	.string "This is not a digging POKéMON…\p"
	.string "Digging POKéMON are the only POKéMON\n"
	.string "I use, because they're so hardy!\p"
	.string "Completing the LAVARBOR TUNNEL will be\n"
	.string "brutal work…\p"
	.string "To dig this tunnel, we'll need none but\n"
	.string "the best digging POKéMON.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_30:
# 281 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Well, I won't be able to work on the\n"
	.string "tunnel without POKéMON…\p"
	.string "It's fine with me!\n"
	.string "I'll just keep enjoying the sauna!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_31:
# 289 "data//maps/LavaridgeSauna/scripts.pory"
	.string "They used to call me the\n"
	.string "TUNNEL MANIAC.\p"
	.string "But these days I've left the tunneling\n"
	.string "to my two boys in FALLARBOR.$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_32:
# 296 "data//maps/LavaridgeSauna/scripts.pory"
	.string "… … … … … … … …$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_33:
# 304 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hey! You're blocking the warm air!\p"
	.string "It's creating a cold pocket!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_34:
# 306 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Huh?\n"
	.string "Some kid?\p"
	.string "You're blocking the warm air!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_35:
# 308 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Get outta my way!\p"
	.string "You're bringing in a draft!$"

LavaridgeSauna_EventScript_FindTunnelManiac_Text_36:
# 323 "data//maps/LavaridgeSauna/scripts.pory"
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
# 397 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Excuse me…\p"
	.string "I've gotten several reports that you're\n"
	.string "disturbing other guests.\p"
	.string "I'm going to have to ask you to leave\n"
	.string "the sauna now.$"

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_0:
# 437 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Hmm…\l"
	.string "This is a digging POKéMON!\p"
	.string "But once it's immersed in the tunnel\n"
	.string "lifestyle, it won't ever come back.\p"
	.string "Are you sure you want {STR_VAR_1}\n"
	.string "to work on the LAVARBOR TUNNEL?$"

LavaridgeSauna_EventScript_GiveAnotherDiggingMon_Text_1:
# 536 "data//maps/LavaridgeSauna/scripts.pory"
	.string "Ah yes, it will be tough, but\n"
	.string "{STR_VAR_1}'s help will surely speed\l"
	.string "things up.\p"
	.string "In total, you've volunteered\n"
	.string "{STR_VAR_2} digging POKéMON for the\l"
	.string "tunnel crew.\p"
	.string "That means we still need\n"
	.string "{STR_VAR_3} more to join the team\l"
	.string "before we can start working.$"
