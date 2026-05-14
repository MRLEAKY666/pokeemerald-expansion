# 1 "data//maps/SootopolisCity_House3/scripts.pory"

# 2 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_MapScripts::
# 3 "data//maps/SootopolisCity_House3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_House3_OnTransition
# 4 "data//maps/SootopolisCity_House3/scripts.pory"
	.byte 0

SootopolisCity_House3_OnTransition::
# 9 "data//maps/SootopolisCity_House3/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_SOOTOPOLIS_CITY_HOUSE3
# 10 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_OnTransition_1
# 14 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_TEMP_A
	return

SootopolisCity_House3_OnTransition_1:
# 11 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	return


SootopolisCity_House3_EventScript_Wallace::
# 19 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 20 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 21 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, SootopolisCity_House3_EventScript_Wallace_2
# 26 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 31 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE
SootopolisCity_House3_EventScript_Wallace_1:
# 33 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 34 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 15
# 37 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_Wallace_2:
# 22 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 23 "data//maps/SootopolisCity_House3/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto SootopolisCity_House3_EventScript_Wallace_1


SootopolisCity_House3_EventScript_WallaceCheckBeasts::
# 42 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon VAR_BEAST_SPECIES
# 43 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_BEAST_SPECIES, SPECIES_HO_OH
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_2
# 52 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_5
# 296 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 297 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_16
# 302 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_17
# 308 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_18
# 315 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 316 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_32, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_2:
# 44 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_0, MSGBOX_DEFAULT
# 49 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_WallaceCheckBeasts_4:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_5:
# 53 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 54 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_10
# 58 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_11
# 63 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_12
# 69 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 70 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_8:
# 73 "data//maps/SootopolisCity_House3/scripts.pory"
	getcaughtmon VAR_BEAST_SPECIES
# 74 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_20
# 227 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_33
# 245 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 246 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 247 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 249 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 250 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 252 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 253 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 254 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 255 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 256 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_49
# 259 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_50
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_51
# 266 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 267 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_32:
# 271 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_NO_ACTIVE_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_40
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_39:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_10:
# 55 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_11:
# 59 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_12:
# 64 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_3, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_14:
# 320 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 321 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 322 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 323 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 324 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17
# 325 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 326 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 327 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 329 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 330 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_24
SootopolisCity_House3_EventScript_WallaceCheckBeasts_23:
# 334 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_4

SootopolisCity_House3_EventScript_WallaceCheckBeasts_16:
# 298 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_17:
# 303 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_18:
# 309 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_31, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_20:
# 75 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 77 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 78 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 79 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 80 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 81 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 82 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 83 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 85 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 86 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_28
# 92 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_29
# 97 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_30
# 103 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 104 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_26:
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceCheckBeasts_37
# 176 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 177 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 178 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 179 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 180 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 181 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 182 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 183 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 184 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_55
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_56
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_57
SootopolisCity_House3_EventScript_WallaceCheckBeasts_53:
# 195 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_73
SootopolisCity_House3_EventScript_WallaceCheckBeasts_72:
# 197 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_77
SootopolisCity_House3_EventScript_WallaceCheckBeasts_76:
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_80
SootopolisCity_House3_EventScript_WallaceCheckBeasts_71:
# 203 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_69:
# 207 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 208 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 209 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 210 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 211 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 212 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17
# 214 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 215 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 216 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 218 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 219 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_88
SootopolisCity_House3_EventScript_WallaceCheckBeasts_87:
# 222 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_24:
# 331 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_23

SootopolisCity_House3_EventScript_WallaceCheckBeasts_28:
# 87 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_29:
# 93 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_30:
# 98 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_33:
# 228 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 229 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_44
# 232 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_45
# 235 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_46
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 240 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_37:
# 109 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 110 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 111 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 112 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 113 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 114 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 115 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 117 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10, MSGBOX_DEFAULT
# 124 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 125 "data//maps/SootopolisCity_House3/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 126 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_RESULT
# 127 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_NORTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_60
# 129 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_SOUTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_61
# 131 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_EAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_62
# 133 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_WEST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_63
SootopolisCity_House3_EventScript_WallaceCheckBeasts_58:
# 137 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 138 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 20
# 139 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_House3_EventScript_WallaceCheckBeasts_84
# 157 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 158 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_93
# 166 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 167 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 169 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_83:
# 173 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_WallaceCheckBeasts_40:
# 272 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 273 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 274 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_66
# 276 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_67
# 278 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_68
SootopolisCity_House3_EventScript_WallaceCheckBeasts_64:
# 283 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 284 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 285 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_39

SootopolisCity_House3_EventScript_WallaceCheckBeasts_44:
# 230 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_45:
# 233 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_46:
# 236 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_49:
# 257 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_50:
# 260 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_51:
# 263 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_55:
# 185 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 186 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_56:
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_57:
# 191 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 192 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_60:
# 128 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_61:
# 130 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_62:
# 132 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_63:
# 134 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_66:
# 275 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_67:
# 277 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_68:
# 279 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_70:
# 199 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_69

SootopolisCity_House3_EventScript_WallaceCheckBeasts_73:
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_72

SootopolisCity_House3_EventScript_WallaceCheckBeasts_77:
# 197 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_76

SootopolisCity_House3_EventScript_WallaceCheckBeasts_80:
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_71

SootopolisCity_House3_EventScript_WallaceCheckBeasts_84:
# 140 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 141 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_90
# 149 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 150 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 152 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83

SootopolisCity_House3_EventScript_WallaceCheckBeasts_88:
# 220 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_87

SootopolisCity_House3_EventScript_WallaceCheckBeasts_90:
# 142 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 144 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_11, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83

SootopolisCity_House3_EventScript_WallaceCheckBeasts_93:
# 159 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 161 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83


# 340 "data//maps/SootopolisCity_House3/scripts.pory"

# 341 "data//maps/SootopolisCity_House3/scripts.pory"

# 342 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceOld::
# 343 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 344 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 345 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock
# 346 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_unset FLAG_MET_WALLACE, SootopolisCity_House3_EventScript_WallaceThanks
# 347 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceSearchingBeasts, MSGBOX_DEFAULT
# 348 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 349 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_ENTEI, SootopolisCity_House3_EventScript_EnteiSpeech
# 350 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_SUICUNE, SootopolisCity_House3_EventScript_SuicuneSpeech
# 351 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_RAIKOU, SootopolisCity_House3_EventScript_RaikouSpeech
# 352 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 353 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 354 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 355 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 356 "data//maps/SootopolisCity_House3/scripts.pory"

# 357 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceThanks::
# 358 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThanks, MSGBOX_DEFAULT
# 359 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 360 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE
# 361 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 362 "data//maps/SootopolisCity_House3/scripts.pory"

# 363 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_EnteiSpeech::
# 364 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_EnteiSpeech, MSGBOX_DEFAULT
# 365 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 366 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_ENTEI
# 367 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenEntei
# 368 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 369 "data//maps/SootopolisCity_House3/scripts.pory"

# 370 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenEntei::
# 371 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenEntei, MSGBOX_DEFAULT
# 372 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 373 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_CaughtEntei
# 374 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 375 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 376 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewEntei
# 377 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 378 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 379 "data//maps/SootopolisCity_House3/scripts.pory"

# 380 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtEntei::
# 381 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtEntei, MSGBOX_DEFAULT
# 382 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 383 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 384 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowEntei
# 385 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 386 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 387 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 388 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 389 "data//maps/SootopolisCity_House3/scripts.pory"

# 390 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowEntei::
# 391 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_ENTEI, OPEN_PARTY_SCREEN
# 392 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketEntei
# 393 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstSuicune
# 394 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 395 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 396 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 397 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 398 "data//maps/SootopolisCity_House3/scripts.pory"

# 399 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstEntei::
# 400 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 401 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 402 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 403 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 404 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 405 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsRaikou, MSGBOX_DEFAULT
# 406 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 407 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
# 408 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_ENTEI, 0, 0
# 409 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_ENTEI
# 410 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroEntei, MSGBOX_DEFAULT
# 411 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 412 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 413 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 414 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 415 "data//maps/SootopolisCity_House3/scripts.pory"

# 416 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewEntei::
# 417 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 418 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 419 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 420 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 421 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 422 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 423 "data//maps/SootopolisCity_House3/scripts.pory"

# 424 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SuicuneSpeech::
# 425 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SuicuneSpeech, MSGBOX_DEFAULT
# 426 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 427 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_SUICUNE
# 428 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenSuicune
# 429 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 430 "data//maps/SootopolisCity_House3/scripts.pory"

# 431 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenSuicune::
# 432 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenSuicune, MSGBOX_DEFAULT
# 433 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 434 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_CaughtSuicune
# 435 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 436 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 437 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewSuicune
# 438 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 439 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 440 "data//maps/SootopolisCity_House3/scripts.pory"

# 441 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtSuicune::
# 442 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtSuicune, MSGBOX_DEFAULT
# 443 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 444 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 445 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowSuicune
# 446 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 447 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 448 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 449 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 450 "data//maps/SootopolisCity_House3/scripts.pory"

# 451 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowSuicune::
# 452 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_SUICUNE, OPEN_PARTY_SCREEN
# 453 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune
# 454 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstRaikou
# 455 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 456 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 457 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 458 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 459 "data//maps/SootopolisCity_House3/scripts.pory"

# 460 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstSuicune::
# 461 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 462 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 463 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 464 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 465 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 466 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsEntei, MSGBOX_DEFAULT
# 467 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 468 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 469 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_SUICUNE, 0, 0
# 470 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_SUICUNE
# 471 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroSuicune, MSGBOX_DEFAULT
# 472 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 473 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 474 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 475 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 476 "data//maps/SootopolisCity_House3/scripts.pory"

# 477 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewSuicune::
# 478 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 479 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 480 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 481 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 482 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 483 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 484 "data//maps/SootopolisCity_House3/scripts.pory"

# 485 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_RaikouSpeech::
# 486 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_RaikouSpeech, MSGBOX_DEFAULT
# 487 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 488 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_RAIKOU
# 489 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenRaikou
# 490 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 491 "data//maps/SootopolisCity_House3/scripts.pory"

# 492 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenRaikou::
# 493 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenRaikou, MSGBOX_DEFAULT
# 494 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 495 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_CaughtRaikou
# 496 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 497 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 498 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewRaikou
# 499 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 500 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 501 "data//maps/SootopolisCity_House3/scripts.pory"

# 502 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtRaikou::
# 503 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtRaikou, MSGBOX_DEFAULT
# 504 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 505 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 506 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowRaikou
# 507 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 508 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 509 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 510 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 511 "data//maps/SootopolisCity_House3/scripts.pory"

# 512 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowRaikou::
# 513 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_RAIKOU, OPEN_PARTY_SCREEN
# 514 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou
# 515 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstEntei
# 516 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 517 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 518 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 519 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 520 "data//maps/SootopolisCity_House3/scripts.pory"

# 521 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstRaikou::
# 522 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 523 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 524 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 525 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 526 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 527 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsSuicune, MSGBOX_DEFAULT
# 528 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 529 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
# 530 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_RAIKOU, 0, 0
# 531 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_RAIKOU
# 532 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroRaikou, MSGBOX_DEFAULT
# 533 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 534 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 535 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 536 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 537 "data//maps/SootopolisCity_House3/scripts.pory"

# 538 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewRaikou::
# 539 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 540 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 541 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 542 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 543 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 544 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 545 "data//maps/SootopolisCity_House3/scripts.pory"

# 546 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 547 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 548 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 549 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 550 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 551 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 552 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 553 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 554 "data//maps/SootopolisCity_House3/scripts.pory"

# 555 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 556 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 557 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 558 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 559 "data//maps/SootopolisCity_House3/scripts.pory"

# 560 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 561 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 562 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 563 "data//maps/SootopolisCity_House3/scripts.pory"

# 564 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketEntei::
# 565 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastEntei, MSGBOX_DEFAULT
# 566 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 567 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 568 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 569 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 570 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 571 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 572 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 573 "data//maps/SootopolisCity_House3/scripts.pory"

# 574 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune::
# 575 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastSuicune, MSGBOX_DEFAULT
# 576 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 577 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 578 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 579 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 580 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 581 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 582 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 583 "data//maps/SootopolisCity_House3/scripts.pory"

# 584 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou::
# 585 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastRaikou, MSGBOX_DEFAULT
# 586 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 587 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 588 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 589 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 590 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 591 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 592 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 593 "data//maps/SootopolisCity_House3/scripts.pory"

# 594 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicket::
# 595 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThreeBeasts, MSGBOX_DEFAULT
# 596 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 597 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 598 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 599 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 600 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 601 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 602 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 603 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 604 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 605 "data//maps/SootopolisCity_House3/scripts.pory"

# 606 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock::
# 607 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 608 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 609 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 610 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 611 "data//maps/SootopolisCity_House3/scripts.pory"

# 612 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeEntei:
# 613 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me ENTEI, I'll be\n"
# 614 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 615 "data//maps/SootopolisCity_House3/scripts.pory"

# 616 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeSuicune:
# 617 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me SUICUNE, I'll be\n"
# 618 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 619 "data//maps/SootopolisCity_House3/scripts.pory"

# 620 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeRaikou:
# 621 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me RAIKOU, I'll be\n"
# 622 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 623 "data//maps/SootopolisCity_House3/scripts.pory"

# 624 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtEntei:
# 625 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 626 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 627 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 628 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 629 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured ENTEI?!$"
# 630 "data//maps/SootopolisCity_House3/scripts.pory"

# 631 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtSuicune:
# 632 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 633 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 634 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 635 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 636 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured SUICUNE?!$"
# 637 "data//maps/SootopolisCity_House3/scripts.pory"

# 638 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtRaikou:
# 639 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 640 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 641 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 642 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 643 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured RAIKOU?!$"
# 644 "data//maps/SootopolisCity_House3/scripts.pory"

# 645 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenEntei:
# 646 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 647 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 648 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen ENTEI?$"
# 649 "data//maps/SootopolisCity_House3/scripts.pory"

# 650 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenSuicune:
# 651 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 652 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 653 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen SUICUNE?$"
# 654 "data//maps/SootopolisCity_House3/scripts.pory"

# 655 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenRaikou:
# 656 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 657 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 658 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen RAIKOU?$"
# 659 "data//maps/SootopolisCity_House3/scripts.pory"

# 660 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_EnteiSpeech:
# 661 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 662 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 663 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON ENTEI has been\n"
# 664 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 665 "data//maps/SootopolisCity_House3/scripts.pory"

# 666 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SuicuneSpeech:
# 667 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 668 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 669 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON SUICUNE has been\n"
# 670 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 671 "data//maps/SootopolisCity_House3/scripts.pory"

# 672 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_RaikouSpeech:
# 673 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 674 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 675 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON RAIKOU has been\n"
# 676 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 677 "data//maps/SootopolisCity_House3/scripts.pory"

# 678 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsEntei:
# 679 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 680 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 681 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 682 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 683 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 684 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 685 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard news of SUICUNE\n"
# 686 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "roaming around HOENN as well...$"
# 687 "data//maps/SootopolisCity_House3/scripts.pory"

# 688 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroSuicune:
# 689 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE is the Aurora POKéMON.\p"
# 690 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture SUICUNE and show it\n" 
# 691 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 692 "data//maps/SootopolisCity_House3/scripts.pory"

# 693 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsSuicune:
# 694 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 695 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 696 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 697 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 698 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 699 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 700 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that RAIKOU\n"
# 701 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 702 "data//maps/SootopolisCity_House3/scripts.pory"

# 703 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroRaikou:
# 704 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAIKOU is the Thunder POKéMON.\p"
# 705 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture RAIKOU and show it\n" 
# 706 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 707 "data//maps/SootopolisCity_House3/scripts.pory"

# 708 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsRaikou:
# 709 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 710 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 711 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 712 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 713 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 714 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 715 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that ENTEI\n"
# 716 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 717 "data//maps/SootopolisCity_House3/scripts.pory"

# 718 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroEntei:
# 719 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "ENTEI is the Volcano POKéMON.\p"
# 720 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture ENTEI and show it\n" 
# 721 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 722 "data//maps/SootopolisCity_House3/scripts.pory"

# 723 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThanks:
# 724 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Thanks for your help with\n"
# 725 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "that incident. Your help finding\l"
# 726 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAYQUAZA was invaluable.$"
# 727 "data//maps/SootopolisCity_House3/scripts.pory"

# 728 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceSearchingBeasts:
# 729 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: I'm considered an expert\n"
# 730 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "on the mythology of super-ancient\l"
# 731 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON because I've spent my life\l"
# 732 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "researching a POKéMON called SUICUNE.\p"
# 733 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Through my research and my travels,\n"
# 734 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've learned quite a bit about the\l"
# 735 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "myths surrounding the super-ancient\l"
# 736 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON called the legendary beasts.$"
# 737 "data//maps/SootopolisCity_House3/scripts.pory"

# 738 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 739 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 740 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 741 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 742 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 743 "data//maps/SootopolisCity_House3/scripts.pory"

# 744 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 745 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 746 "data//maps/SootopolisCity_House3/scripts.pory"

# 747 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 748 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 749 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 750 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 751 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 752 "data//maps/SootopolisCity_House3/scripts.pory"

# 753 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 754 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 755 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 756 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 757 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
# 758 "data//maps/SootopolisCity_House3/scripts.pory"

# 759 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_AlwaysHunting:
# 760 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm always hunting for more information\n"
# 761 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "regarding the legendary beasts ENTEI,\l"
# 762 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE, and RAIKOU.\p"
# 763 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you see one, please come back and\n"
# 764 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "let me know.$"
# 765 "data//maps/SootopolisCity_House3/scripts.pory"

# 766 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastEntei:
# 767 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 768 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 769 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 770 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 771 "data//maps/SootopolisCity_House3/scripts.pory"

# 772 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastSuicune:
# 773 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 774 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 775 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 776 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 777 "data//maps/SootopolisCity_House3/scripts.pory"

# 778 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastRaikou:
# 779 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 780 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 781 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 782 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 783 "data//maps/SootopolisCity_House3/scripts.pory"

# 784 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThreeBeasts:
# 785 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 786 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 787 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 788 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Thanks to you, I've been able to fulfill\n"
# 789 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "my life's dream of seeing all three of\l"
# 790 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the legendary beast POKéMON . . .\p"
# 791 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 792 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 793 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ultimately, though I dedicated my life\n"
# 794 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to finding SUICUNE, it was you alone,\l"
# 795 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 796 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, I, WALLACE, had nothing to do with\n"
# 797 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "your dazzling discovery . . .\p"
# 798 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER},\n"
# 799 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'd like you to take this.$"
# 800 "data//maps/SootopolisCity_House3/scripts.pory"

# 801 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest:
# 802 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "With the MYSTIC TICKET\n"
# 803 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "you can travel to NAVEL ROCK.\p"
# 804 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me there with the\n"
# 805 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "three legendary beast POKéMON you've\l"
# 806 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "caught.\p"
# 807 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Once there, I'll ask you to demonstrate\n"
# 808 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "their legendary strength by engaging me\l"
# 809 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "in an all-out POKéMON battle!$" 
# 810 "data//maps/SootopolisCity_House3/scripts.pory"

# 811 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest2:
# 812 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 813 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me at NAVEL ROCK with\n"
# 814 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the three legendary beast POKéMON.\p"
# 815 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 816 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$"

SootopolisCity_House3_EventScript_Wallace_Text_0:
# 22 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

SootopolisCity_House3_EventScript_Wallace_Text_1:
# 26 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, a young TRAINER…\p"
	.string "Yes, I can tell you're one to watch.\p"
	.string "But how rude of me,\n"
	.string "my name is WALLACE, former GYM LEADER\l"
	.string "of SOOTOPOLIS CITY.\p"
	.string "As many trainer's final obstacle before\n"
	.string "challenging the POKéMON LEAGUE,\l"
	.string "I've honed an eye for spotting\l"
	.string "promising TRAINERS.\p"
	.string "I can tell you'll make it there one day\n"
	.string "too.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_0:
# 44 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "With the MYSTIC TICKET you can travel\n"
	.string "to NAVEL ROCK.\p"
	.string "I want you to meet me there with the\n"
	.string "three BEAST POKéMON you've caught.\p"
	.string "Once there, I'll ask you to demonstrate\n"
	.string "their legendary strength by engaging\l"
	.string "me\l"
	.string "in an all-out POKéMON battle!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1:
# 55 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2:
# 59 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON RAIKOU.\p"
	.string "RAIKOU is one of a trio of BEAST\n"
	.string "POKéMON that have fascinated me all my\l"
	.string "life.\p"
	.string "It's stealthy and lightning fast, yet\n"
	.string "strikes with a supercharged\l"
	.string "destructive force.\p"
	.string "I have reason to believe RAIKOU has\n"
	.string "been roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_3:
# 64 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON ENTEI.\p"
	.string "ENTEI is one of a trio of BEAST POKéMON\n"
	.string "that have fascinated me all my life.\p"
	.string "It commands respect with its regal\n"
	.string "prescence, yet is capable of unrivaled\l"
	.string "intensity in battle.\p"
	.string "I have reason to believe ENTEI has been\n"
	.string "roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4:
# 70 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "I have reason to believe\n"
	.string "{STR_VAR_1} has been roaming the\l"
	.string "region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5:
# 77 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6:
# 87 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming SUICUNE??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "So nonchalant…\p"
	.string "You're still caught in the carefree\n"
	.string "currents of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as elusive as SUICUNE\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7:
# 93 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming RAIKOU??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "Incredible…\p"
	.string "You're still caught in the carefree\n"
	.string "clouds of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as relentless as RAIKOU\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8:
# 98 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming ENTEI??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "How terrifying…\p"
	.string "You embody the wild flame of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as commanding as ENTEI\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9:
# 104 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming\n"
	.string "{STR_VAR_1}??\p"
	.string "How impressive that you managed to\n"
	.string "best a LEGENDARY POKéMON like\l"
	.string "{STR_VAR_1} seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10:
# 117 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER}, this means you've caught\n"
	.string "all three LEGENDARY BEAST POKéMON…\p"
	.string "I'm amazed…\p"
	.string "Now I have no choice but to ask of you a\n"
	.string "true favor…\p"
	.string "{PLAYER}…\p"
	.string "I need you to demonstrate the power of\n"
	.string "these three POKéMON.\p"
	.string "{PAUSE 20}Yes,{PAUSE 20}{PAUSE 20}\n"
	.string "{PLAYER}…{PAUSE 20}{PAUSE 20} I need you to battle me\l"
	.string "using RAIKOU, ENTEI, and SUICUNE.\p"
	.string "But the battle needs to take place in a\n"
	.string "special location.\p"
	.string "I'll explain when you arrive.\n"
	.string "For now, take this ticket.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_11:
# 144 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well show it when boarding the S.S.\n"
	.string "TIDAL to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12:
# 152 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Show that when boarding the S.S. TIDAL\n"
	.string "to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13:
# 161 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well when the S.S. TIDAL opens, use it to\n"
	.string "travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14:
# 169 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "When the S.S. TIDAL opens, use that\n"
	.string "ticket to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15:
# 199 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is yet a third species of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16:
# 203 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is not one, but three of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17:
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "This is the BEAST POKéMON\n"
	.string "{STR_VAR_1}.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18:
# 222 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's out there, {PLAYER}.\p"
	.string "If you learn anything about\n"
	.string "{STR_VAR_1}, please let me know!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19:
# 230 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming SUICUNE?\p"
	.string "Such a beautiful POKéMON…\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20:
# 233 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming RAIKOU?\p"
	.string "Such a striking POKéMON…\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21:
# 236 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming ENTEI?\p"
	.string "Such an intense POKéMON…\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22:
# 240 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming\n"
	.string "{STR_VAR_1}?\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23:
# 257 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming SUICUNE??\p"
	.string "Isn't it beautiful?\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24:
# 260 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming RAIKOU??\p"
	.string "Isn't it striking?\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25:
# 263 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming ENTEI??\p"
	.string "Isn't it intense?\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26:
# 267 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming {STR_VAR_1}??\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27:
# 285 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's still out there, {PLAYER}.\p"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28:
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29:
# 298 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.\p"
	.string "I aspire to glimpse it with my own eyes…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30:
# 303 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON RAIKOU.\p"
	.string "RAIKOU is one of a trio of BEAST\n"
	.string "POKéMON that have fascinated me all my\l"
	.string "life.\p"
	.string "It's stealthy and lightning fast, yet\n"
	.string "strikes with a supercharged\l"
	.string "destructive force.\p"
	.string "I have reason to believe RAIKOU has\n"
	.string "been roaming the region as of late.\p"
	.string "I aspire to glimpse it with my own eyes…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_31:
# 309 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON ENTEI.\p"
	.string "ENTEI is one of a trio of BEAST POKéMON\n"
	.string "that have fascinated me all my life.\p"
	.string "It commands respect with its regal\n"
	.string "prescence, yet is capable of unrivaled\l"
	.string "intensity in battle.\p"
	.string "I have reason to believe ENTEI has been\n"
	.string "roaming the region as of late.\p"
	.string "I aspire to glimpse it with my own eyes…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_32:
# 316 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "{PLAYER}, if you encounter\n"
	.string "{STR_VAR_1}, please inform me!$"
