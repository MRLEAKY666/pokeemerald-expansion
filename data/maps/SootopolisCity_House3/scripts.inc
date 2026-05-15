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
# 51 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_5
# 295 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 296 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_16
# 301 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_17
# 307 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_18
# 314 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 315 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_32, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_2:
# 44 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_0, MSGBOX_DEFAULT
# 48 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_WallaceCheckBeasts_4:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_5:
# 52 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 53 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_10
# 57 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_11
# 62 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_12
# 68 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 69 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_8:
# 72 "data//maps/SootopolisCity_House3/scripts.pory"
	getcaughtmon VAR_BEAST_SPECIES
# 73 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_20
# 226 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_33
# 244 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 245 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 246 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 247 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 249 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 250 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 252 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 253 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 254 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 255 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_49
# 258 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_50
# 261 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_51
# 265 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 266 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_32:
# 270 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_NO_ACTIVE_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_40
# 288 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_39:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_10:
# 54 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_11:
# 58 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_12:
# 63 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_3, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_8

SootopolisCity_House3_EventScript_WallaceCheckBeasts_14:
# 319 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 320 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 321 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 322 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 323 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17
# 324 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 325 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 326 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 328 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 329 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_24
SootopolisCity_House3_EventScript_WallaceCheckBeasts_23:
# 333 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_4

SootopolisCity_House3_EventScript_WallaceCheckBeasts_16:
# 297 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_17:
# 302 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_18:
# 308 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_31, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_14

SootopolisCity_House3_EventScript_WallaceCheckBeasts_20:
# 74 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 75 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 77 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 78 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 79 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 80 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 81 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 82 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 83 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 85 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_28
# 91 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_29
# 96 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_30
# 102 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 103 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_26:
# 107 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceCheckBeasts_37
# 175 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 176 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 177 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 178 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 179 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 180 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 181 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 182 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 183 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_55
# 186 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_56
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_57
SootopolisCity_House3_EventScript_WallaceCheckBeasts_53:
# 194 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 195 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_73
SootopolisCity_House3_EventScript_WallaceCheckBeasts_72:
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_77
SootopolisCity_House3_EventScript_WallaceCheckBeasts_76:
# 197 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_80
SootopolisCity_House3_EventScript_WallaceCheckBeasts_71:
# 202 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_69:
# 206 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 207 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 208 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 209 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 210 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 211 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 212 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 214 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 215 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 217 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 218 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_88
SootopolisCity_House3_EventScript_WallaceCheckBeasts_87:
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_24:
# 330 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_23

SootopolisCity_House3_EventScript_WallaceCheckBeasts_28:
# 86 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_29:
# 92 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_30:
# 97 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_26

SootopolisCity_House3_EventScript_WallaceCheckBeasts_33:
# 227 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 228 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_44
# 231 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_45
# 234 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_46
# 238 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_37:
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 109 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 110 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 111 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5
# 112 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 113 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 114 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 115 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10, MSGBOX_DEFAULT
# 123 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 124 "data//maps/SootopolisCity_House3/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 125 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_RESULT
# 126 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_NORTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_60
# 128 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_SOUTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_61
# 130 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_EAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_62
# 132 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_WEST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_63
SootopolisCity_House3_EventScript_WallaceCheckBeasts_58:
# 136 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 137 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 20
# 138 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_House3_EventScript_WallaceCheckBeasts_84
# 156 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 157 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_93
# 165 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 166 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 167 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_83:
# 172 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_WallaceCheckBeasts_40:
# 271 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 272 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 273 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_66
# 275 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_67
# 277 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_68
SootopolisCity_House3_EventScript_WallaceCheckBeasts_64:
# 282 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 283 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 284 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_39

SootopolisCity_House3_EventScript_WallaceCheckBeasts_44:
# 229 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_45:
# 232 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_46:
# 235 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_49:
# 256 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_50:
# 259 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_51:
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_32

SootopolisCity_House3_EventScript_WallaceCheckBeasts_55:
# 184 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 185 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_56:
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_57:
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 191 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_53

SootopolisCity_House3_EventScript_WallaceCheckBeasts_60:
# 127 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_61:
# 129 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_62:
# 131 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_63:
# 133 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_58

SootopolisCity_House3_EventScript_WallaceCheckBeasts_66:
# 274 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_67:
# 276 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_68:
# 278 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_64

SootopolisCity_House3_EventScript_WallaceCheckBeasts_70:
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_69

SootopolisCity_House3_EventScript_WallaceCheckBeasts_73:
# 195 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_72

SootopolisCity_House3_EventScript_WallaceCheckBeasts_77:
# 196 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_76

SootopolisCity_House3_EventScript_WallaceCheckBeasts_80:
# 197 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_71

SootopolisCity_House3_EventScript_WallaceCheckBeasts_84:
# 139 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 140 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_90
# 148 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 149 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 150 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83

SootopolisCity_House3_EventScript_WallaceCheckBeasts_88:
# 219 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_87

SootopolisCity_House3_EventScript_WallaceCheckBeasts_90:
# 141 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 142 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_11, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83

SootopolisCity_House3_EventScript_WallaceCheckBeasts_93:
# 158 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 159 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_83


# 339 "data//maps/SootopolisCity_House3/scripts.pory"

# 340 "data//maps/SootopolisCity_House3/scripts.pory"

# 341 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceOld::
# 342 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 343 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 344 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock
# 345 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_unset FLAG_MET_WALLACE, SootopolisCity_House3_EventScript_WallaceThanks
# 346 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceSearchingBeasts, MSGBOX_DEFAULT
# 347 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 348 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_ENTEI, SootopolisCity_House3_EventScript_EnteiSpeech
# 349 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_SUICUNE, SootopolisCity_House3_EventScript_SuicuneSpeech
# 350 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_RAIKOU, SootopolisCity_House3_EventScript_RaikouSpeech
# 351 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 352 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 353 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 354 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 355 "data//maps/SootopolisCity_House3/scripts.pory"

# 356 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceThanks::
# 357 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThanks, MSGBOX_DEFAULT
# 358 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 359 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE
# 360 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 361 "data//maps/SootopolisCity_House3/scripts.pory"

# 362 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_EnteiSpeech::
# 363 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_EnteiSpeech, MSGBOX_DEFAULT
# 364 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 365 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_ENTEI
# 366 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenEntei
# 367 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 368 "data//maps/SootopolisCity_House3/scripts.pory"

# 369 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenEntei::
# 370 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenEntei, MSGBOX_DEFAULT
# 371 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 372 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_CaughtEntei
# 373 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 374 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 375 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewEntei
# 376 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 377 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 378 "data//maps/SootopolisCity_House3/scripts.pory"

# 379 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtEntei::
# 380 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtEntei, MSGBOX_DEFAULT
# 381 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 382 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 383 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowEntei
# 384 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 385 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 386 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 387 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 388 "data//maps/SootopolisCity_House3/scripts.pory"

# 389 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowEntei::
# 390 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_ENTEI, OPEN_PARTY_SCREEN
# 391 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketEntei
# 392 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstSuicune
# 393 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 394 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 395 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 396 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 397 "data//maps/SootopolisCity_House3/scripts.pory"

# 398 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstEntei::
# 399 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 400 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 401 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 402 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 403 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 404 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsRaikou, MSGBOX_DEFAULT
# 405 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 406 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
# 407 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_ENTEI, 0, 0
# 408 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_ENTEI
# 409 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroEntei, MSGBOX_DEFAULT
# 410 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 411 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 412 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 413 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 414 "data//maps/SootopolisCity_House3/scripts.pory"

# 415 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewEntei::
# 416 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 417 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 418 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 419 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 420 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 421 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 422 "data//maps/SootopolisCity_House3/scripts.pory"

# 423 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SuicuneSpeech::
# 424 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SuicuneSpeech, MSGBOX_DEFAULT
# 425 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 426 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_SUICUNE
# 427 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenSuicune
# 428 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 429 "data//maps/SootopolisCity_House3/scripts.pory"

# 430 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenSuicune::
# 431 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenSuicune, MSGBOX_DEFAULT
# 432 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 433 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_CaughtSuicune
# 434 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 435 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 436 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewSuicune
# 437 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 438 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 439 "data//maps/SootopolisCity_House3/scripts.pory"

# 440 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtSuicune::
# 441 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtSuicune, MSGBOX_DEFAULT
# 442 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 443 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 444 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowSuicune
# 445 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 446 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 447 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 448 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 449 "data//maps/SootopolisCity_House3/scripts.pory"

# 450 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowSuicune::
# 451 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_SUICUNE, OPEN_PARTY_SCREEN
# 452 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune
# 453 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstRaikou
# 454 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 455 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 456 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 457 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 458 "data//maps/SootopolisCity_House3/scripts.pory"

# 459 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstSuicune::
# 460 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 461 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 462 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 463 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 464 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 465 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsEntei, MSGBOX_DEFAULT
# 466 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 467 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 468 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_SUICUNE, 0, 0
# 469 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_SUICUNE
# 470 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroSuicune, MSGBOX_DEFAULT
# 471 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 472 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 473 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 474 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 475 "data//maps/SootopolisCity_House3/scripts.pory"

# 476 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewSuicune::
# 477 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 478 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 479 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 480 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 481 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 482 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 483 "data//maps/SootopolisCity_House3/scripts.pory"

# 484 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_RaikouSpeech::
# 485 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_RaikouSpeech, MSGBOX_DEFAULT
# 486 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 487 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_RAIKOU
# 488 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenRaikou
# 489 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 490 "data//maps/SootopolisCity_House3/scripts.pory"

# 491 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenRaikou::
# 492 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenRaikou, MSGBOX_DEFAULT
# 493 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 494 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_CaughtRaikou
# 495 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 496 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 497 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewRaikou
# 498 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 499 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 500 "data//maps/SootopolisCity_House3/scripts.pory"

# 501 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtRaikou::
# 502 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtRaikou, MSGBOX_DEFAULT
# 503 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 504 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 505 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowRaikou
# 506 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 507 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 508 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 509 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 510 "data//maps/SootopolisCity_House3/scripts.pory"

# 511 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowRaikou::
# 512 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_RAIKOU, OPEN_PARTY_SCREEN
# 513 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou
# 514 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstEntei
# 515 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 516 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 517 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 518 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 519 "data//maps/SootopolisCity_House3/scripts.pory"

# 520 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstRaikou::
# 521 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 522 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 523 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 524 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 525 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 526 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsSuicune, MSGBOX_DEFAULT
# 527 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 528 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
# 529 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_RAIKOU, 0, 0
# 530 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_RAIKOU
# 531 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroRaikou, MSGBOX_DEFAULT
# 532 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 533 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 534 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 535 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 536 "data//maps/SootopolisCity_House3/scripts.pory"

# 537 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewRaikou::
# 538 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 539 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 540 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 541 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 542 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 543 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 544 "data//maps/SootopolisCity_House3/scripts.pory"

# 545 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 546 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 547 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 548 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 549 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 550 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 551 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 552 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 553 "data//maps/SootopolisCity_House3/scripts.pory"

# 554 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 555 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 556 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 557 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 558 "data//maps/SootopolisCity_House3/scripts.pory"

# 559 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 560 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 561 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 562 "data//maps/SootopolisCity_House3/scripts.pory"

# 563 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketEntei::
# 564 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastEntei, MSGBOX_DEFAULT
# 565 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 566 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 567 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 568 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 569 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 570 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 571 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 572 "data//maps/SootopolisCity_House3/scripts.pory"

# 573 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune::
# 574 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastSuicune, MSGBOX_DEFAULT
# 575 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 576 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 577 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 578 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 579 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 580 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 581 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 582 "data//maps/SootopolisCity_House3/scripts.pory"

# 583 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou::
# 584 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastRaikou, MSGBOX_DEFAULT
# 585 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 586 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 587 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 588 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 589 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 590 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 591 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 592 "data//maps/SootopolisCity_House3/scripts.pory"

# 593 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicket::
# 594 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThreeBeasts, MSGBOX_DEFAULT
# 595 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 596 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 597 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 598 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 599 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 600 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 601 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 602 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 603 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 604 "data//maps/SootopolisCity_House3/scripts.pory"

# 605 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock::
# 606 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 607 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 608 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 609 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 610 "data//maps/SootopolisCity_House3/scripts.pory"

# 611 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeEntei:
# 612 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me ENTEI, I'll be\n"
# 613 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 614 "data//maps/SootopolisCity_House3/scripts.pory"

# 615 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeSuicune:
# 616 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me SUICUNE, I'll be\n"
# 617 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 618 "data//maps/SootopolisCity_House3/scripts.pory"

# 619 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeRaikou:
# 620 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me RAIKOU, I'll be\n"
# 621 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 622 "data//maps/SootopolisCity_House3/scripts.pory"

# 623 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtEntei:
# 624 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 625 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 626 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 627 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 628 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured ENTEI?!$"
# 629 "data//maps/SootopolisCity_House3/scripts.pory"

# 630 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtSuicune:
# 631 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 632 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 633 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 634 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 635 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured SUICUNE?!$"
# 636 "data//maps/SootopolisCity_House3/scripts.pory"

# 637 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtRaikou:
# 638 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 639 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 640 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 641 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 642 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured RAIKOU?!$"
# 643 "data//maps/SootopolisCity_House3/scripts.pory"

# 644 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenEntei:
# 645 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 646 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 647 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen ENTEI?$"
# 648 "data//maps/SootopolisCity_House3/scripts.pory"

# 649 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenSuicune:
# 650 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 651 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 652 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen SUICUNE?$"
# 653 "data//maps/SootopolisCity_House3/scripts.pory"

# 654 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenRaikou:
# 655 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 656 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 657 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen RAIKOU?$"
# 658 "data//maps/SootopolisCity_House3/scripts.pory"

# 659 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_EnteiSpeech:
# 660 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 661 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 662 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON ENTEI has been\n"
# 663 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 664 "data//maps/SootopolisCity_House3/scripts.pory"

# 665 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SuicuneSpeech:
# 666 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 667 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 668 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON SUICUNE has been\n"
# 669 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 670 "data//maps/SootopolisCity_House3/scripts.pory"

# 671 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_RaikouSpeech:
# 672 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 673 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 674 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON RAIKOU has been\n"
# 675 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 676 "data//maps/SootopolisCity_House3/scripts.pory"

# 677 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsEntei:
# 678 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 679 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 680 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 681 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 682 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 683 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 684 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard news of SUICUNE\n"
# 685 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "roaming around HOENN as well...$"
# 686 "data//maps/SootopolisCity_House3/scripts.pory"

# 687 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroSuicune:
# 688 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE is the Aurora POKéMON.\p"
# 689 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture SUICUNE and show it\n" 
# 690 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 691 "data//maps/SootopolisCity_House3/scripts.pory"

# 692 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsSuicune:
# 693 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 694 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 695 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 696 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 697 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 698 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 699 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that RAIKOU\n"
# 700 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 701 "data//maps/SootopolisCity_House3/scripts.pory"

# 702 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroRaikou:
# 703 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAIKOU is the Thunder POKéMON.\p"
# 704 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture RAIKOU and show it\n" 
# 705 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 706 "data//maps/SootopolisCity_House3/scripts.pory"

# 707 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsRaikou:
# 708 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 709 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 710 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 711 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 712 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 713 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 714 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that ENTEI\n"
# 715 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 716 "data//maps/SootopolisCity_House3/scripts.pory"

# 717 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroEntei:
# 718 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "ENTEI is the Volcano POKéMON.\p"
# 719 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture ENTEI and show it\n" 
# 720 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 721 "data//maps/SootopolisCity_House3/scripts.pory"

# 722 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThanks:
# 723 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Thanks for your help with\n"
# 724 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "that incident. Your help finding\l"
# 725 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAYQUAZA was invaluable.$"
# 726 "data//maps/SootopolisCity_House3/scripts.pory"

# 727 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceSearchingBeasts:
# 728 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: I'm considered an expert\n"
# 729 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "on the mythology of super-ancient\l"
# 730 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON because I've spent my life\l"
# 731 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "researching a POKéMON called SUICUNE.\p"
# 732 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Through my research and my travels,\n"
# 733 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've learned quite a bit about the\l"
# 734 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "myths surrounding the super-ancient\l"
# 735 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON called the legendary beasts.$"
# 736 "data//maps/SootopolisCity_House3/scripts.pory"

# 737 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 738 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 739 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 740 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 741 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 742 "data//maps/SootopolisCity_House3/scripts.pory"

# 743 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 744 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 745 "data//maps/SootopolisCity_House3/scripts.pory"

# 746 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 747 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 748 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 749 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 750 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 751 "data//maps/SootopolisCity_House3/scripts.pory"

# 752 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 753 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 754 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 755 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 756 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
# 757 "data//maps/SootopolisCity_House3/scripts.pory"

# 758 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_AlwaysHunting:
# 759 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm always hunting for more information\n"
# 760 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "regarding the legendary beasts ENTEI,\l"
# 761 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE, and RAIKOU.\p"
# 762 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you see one, please come back and\n"
# 763 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "let me know.$"
# 764 "data//maps/SootopolisCity_House3/scripts.pory"

# 765 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastEntei:
# 766 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 767 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 768 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 769 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 770 "data//maps/SootopolisCity_House3/scripts.pory"

# 771 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastSuicune:
# 772 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 773 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 774 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 775 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 776 "data//maps/SootopolisCity_House3/scripts.pory"

# 777 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastRaikou:
# 778 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 779 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 780 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 781 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 782 "data//maps/SootopolisCity_House3/scripts.pory"

# 783 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThreeBeasts:
# 784 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 785 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 786 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 787 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Thanks to you, I've been able to fulfill\n"
# 788 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "my life's dream of seeing all three of\l"
# 789 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the legendary beast POKéMON . . .\p"
# 790 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 791 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 792 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ultimately, though I dedicated my life\n"
# 793 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to finding SUICUNE, it was you alone,\l"
# 794 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 795 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, I, WALLACE, had nothing to do with\n"
# 796 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "your dazzling discovery . . .\p"
# 797 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER},\n"
# 798 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'd like you to take this.$"
# 799 "data//maps/SootopolisCity_House3/scripts.pory"

# 800 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest:
# 801 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "With the MYSTIC TICKET\n"
# 802 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "you can travel to NAVEL ROCK.\p"
# 803 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me there with the\n"
# 804 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "three legendary beast POKéMON you've\l"
# 805 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "caught.\p"
# 806 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Once there, I'll ask you to demonstrate\n"
# 807 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "their legendary strength by engaging me\l"
# 808 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "in an all-out POKéMON battle!$" 
# 809 "data//maps/SootopolisCity_House3/scripts.pory"

# 810 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest2:
# 811 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 812 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me at NAVEL ROCK with\n"
# 813 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the three legendary beast POKéMON.\p"
# 814 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 815 "data//maps/SootopolisCity_House3/scripts.pory"
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
	.string "me in an all-out POKéMON battle!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1:
# 54 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2:
# 58 "data//maps/SootopolisCity_House3/scripts.pory"
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
# 63 "data//maps/SootopolisCity_House3/scripts.pory"
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
# 69 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "I have reason to believe\n"
	.string "{STR_VAR_1} has been roaming the\l"
	.string "region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5:
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6:
# 86 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming SUICUNE??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "So nonchalant…\p"
	.string "You're still caught in the carefree\n"
	.string "currents of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as elusive as SUICUNE\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7:
# 92 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming RAIKOU??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "Incredible…\p"
	.string "You're still caught in the carefree\n"
	.string "clouds of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as relentless as RAIKOU\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8:
# 97 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming ENTEI??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "How terrifying…\p"
	.string "You embody the wild flame of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as commanding as ENTEI\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9:
# 103 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming\n"
	.string "{STR_VAR_1}??\p"
	.string "How impressive that you managed to\n"
	.string "best a LEGENDARY POKéMON like\l"
	.string "{STR_VAR_1} seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10:
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
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
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well show it when boarding the S.S.\n"
	.string "TIDAL to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12:
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Show that when boarding the S.S. TIDAL\n"
	.string "to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13:
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well when the S.S. TIDAL opens, use it to\n"
	.string "travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14:
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "When the S.S. TIDAL opens, use that\n"
	.string "ticket to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15:
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is yet a third species of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16:
# 202 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is not one, but three of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17:
# 212 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "This is the BEAST POKéMON\n"
	.string "{STR_VAR_1}.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18:
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's out there, {PLAYER}.\p"
	.string "If you learn anything about\n"
	.string "{STR_VAR_1}, please let me know!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19:
# 229 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming SUICUNE?\p"
	.string "Such a beautiful POKéMON…\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20:
# 232 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming RAIKOU?\p"
	.string "Such a striking POKéMON…\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21:
# 235 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming ENTEI?\p"
	.string "Such an intense POKéMON…\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22:
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming\n"
	.string "{STR_VAR_1}?\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23:
# 256 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming SUICUNE??\p"
	.string "Isn't it beautiful?\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24:
# 259 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming RAIKOU??\p"
	.string "Isn't it striking?\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25:
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming ENTEI??\p"
	.string "Isn't it intense?\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26:
# 266 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming {STR_VAR_1}??\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27:
# 284 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's still out there, {PLAYER}.\p"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28:
# 288 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29:
# 297 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.\p"
	.string "I aspire to glimpse it with my own eyes…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30:
# 302 "data//maps/SootopolisCity_House3/scripts.pory"
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
# 308 "data//maps/SootopolisCity_House3/scripts.pory"
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
# 315 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "{PLAYER}, if you encounter\n"
	.string "{STR_VAR_1}, please inform me!$"
