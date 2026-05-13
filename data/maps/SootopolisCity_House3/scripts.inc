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


SootopolisCity_PokemonCenter_2F_EventScript_Wallace::
# 19 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 20 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 21 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, SootopolisCity_PokemonCenter_2F_EventScript_Wallace_2
# 26 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 31 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE
SootopolisCity_PokemonCenter_2F_EventScript_Wallace_1:
# 33 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 34 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 15
# 37 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Wallace_2:
# 22 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 23 "data//maps/SootopolisCity_House3/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto SootopolisCity_PokemonCenter_2F_EventScript_Wallace_1


SootopolisCity_House3_EventScript_WallaceCheckBeasts::
# 42 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon VAR_BEAST_SPECIES
# 43 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_2
# 287 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 288 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_13
# 293 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_14
# 299 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_15
# 306 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 307 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_31, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_1:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_2:
# 44 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 45 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_7
# 49 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_8
# 54 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_9
# 60 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 61 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_3, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_5:
# 64 "data//maps/SootopolisCity_House3/scripts.pory"
	getcaughtmon VAR_BEAST_SPECIES
# 65 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_17
# 218 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_30
# 236 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 237 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 238 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4
# 239 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 240 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 241 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 242 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 243 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 244 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 245 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 246 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 247 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_46
# 250 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_47
# 253 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_48
# 257 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 258 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_29:
# 262 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_NO_ACTIVE_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_37
# 280 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_36:
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_7:
# 46 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_0, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_5

SootopolisCity_House3_EventScript_WallaceCheckBeasts_8:
# 50 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_5

SootopolisCity_House3_EventScript_WallaceCheckBeasts_9:
# 55 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_5

SootopolisCity_House3_EventScript_WallaceCheckBeasts_11:
# 311 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 312 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 313 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 314 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 315 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16
# 316 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 317 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 318 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 320 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 321 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_21
SootopolisCity_House3_EventScript_WallaceCheckBeasts_20:
# 325 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_1

SootopolisCity_House3_EventScript_WallaceCheckBeasts_13:
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_11

SootopolisCity_House3_EventScript_WallaceCheckBeasts_14:
# 294 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_11

SootopolisCity_House3_EventScript_WallaceCheckBeasts_15:
# 300 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_11

SootopolisCity_House3_EventScript_WallaceCheckBeasts_17:
# 66 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 67 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 68 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4
# 69 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 70 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 71 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 72 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 73 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 74 "data//maps/SootopolisCity_House3/scripts.pory"
	playse SE_PIN
# 75 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 76 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 77 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_25
# 83 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_26
# 88 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_27
# 94 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 95 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_23:
# 99 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceCheckBeasts_34
# 167 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 168 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 169 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4
# 170 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 171 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 172 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 173 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 174 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 175 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_52
# 178 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_53
# 181 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_54
SootopolisCity_House3_EventScript_WallaceCheckBeasts_50:
# 186 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_70
SootopolisCity_House3_EventScript_WallaceCheckBeasts_69:
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_74
SootopolisCity_House3_EventScript_WallaceCheckBeasts_73:
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_77
SootopolisCity_House3_EventScript_WallaceCheckBeasts_68:
# 194 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_66:
# 198 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 199 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 200 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 201 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 202 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic VAR_BEAST_SPECIES, 10, 3
# 203 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry VAR_BEAST_SPECIES, CRY_MODE_NORMAL
# 204 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16
# 205 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 206 "data//maps/SootopolisCity_House3/scripts.pory"
	waitbuttonpress
# 207 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 209 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon VAR_BEAST_SPECIES
# 210 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_WALLACE_SHOWED_BEAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_85
SootopolisCity_House3_EventScript_WallaceCheckBeasts_84:
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17, MSGBOX_DEFAULT
	return

SootopolisCity_House3_EventScript_WallaceCheckBeasts_21:
# 322 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_20

SootopolisCity_House3_EventScript_WallaceCheckBeasts_25:
# 78 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_23

SootopolisCity_House3_EventScript_WallaceCheckBeasts_26:
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_23

SootopolisCity_House3_EventScript_WallaceCheckBeasts_27:
# 89 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_23

SootopolisCity_House3_EventScript_WallaceCheckBeasts_30:
# 219 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 220 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_41
# 223 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_42
# 226 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_43
# 230 "data//maps/SootopolisCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_BEAST_SPECIES
# 231 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_34:
# 100 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 101 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 102 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 60
# 103 "data//maps/SootopolisCity_House3/scripts.pory"
	message SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4
# 104 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 105 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 106 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 107 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 30
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9, MSGBOX_DEFAULT
# 115 "data//maps/SootopolisCity_House3/scripts.pory"
	closemessage
# 116 "data//maps/SootopolisCity_House3/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 117 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_RESULT
# 118 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_NORTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_57
# 120 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_SOUTH, SootopolisCity_House3_EventScript_WallaceCheckBeasts_58
# 122 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_EAST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_59
# 124 "data//maps/SootopolisCity_House3/scripts.pory"
	case DIR_WEST, SootopolisCity_House3_EventScript_WallaceCheckBeasts_60
SootopolisCity_House3_EventScript_WallaceCheckBeasts_55:
# 128 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 129 "data//maps/SootopolisCity_House3/scripts.pory"
	delay 20
# 130 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_House3_EventScript_WallaceCheckBeasts_81
# 148 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 149 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_90
# 157 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 158 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 159 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13, MSGBOX_DEFAULT
SootopolisCity_House3_EventScript_WallaceCheckBeasts_80:
# 164 "data//maps/SootopolisCity_House3/scripts.pory"
	release
	end

SootopolisCity_House3_EventScript_WallaceCheckBeasts_37:
# 263 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 264 "data//maps/SootopolisCity_House3/scripts.pory"
	switch VAR_BEAST_SPECIES
# 265 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_63
# 267 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_RAIKOU, SootopolisCity_House3_EventScript_WallaceCheckBeasts_64
# 269 "data//maps/SootopolisCity_House3/scripts.pory"
	case SPECIES_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_65
SootopolisCity_House3_EventScript_WallaceCheckBeasts_61:
# 274 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 275 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 276 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_36

SootopolisCity_House3_EventScript_WallaceCheckBeasts_41:
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_42:
# 224 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_43:
# 227 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_46:
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_47:
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_48:
# 254 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_29

SootopolisCity_House3_EventScript_WallaceCheckBeasts_52:
# 176 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 177 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_50

SootopolisCity_House3_EventScript_WallaceCheckBeasts_53:
# 179 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 180 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_50

SootopolisCity_House3_EventScript_WallaceCheckBeasts_54:
# 182 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 183 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_50

SootopolisCity_House3_EventScript_WallaceCheckBeasts_57:
# 119 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_55

SootopolisCity_House3_EventScript_WallaceCheckBeasts_58:
# 121 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_55

SootopolisCity_House3_EventScript_WallaceCheckBeasts_59:
# 123 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_55

SootopolisCity_House3_EventScript_WallaceCheckBeasts_60:
# 125 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_55

SootopolisCity_House3_EventScript_WallaceCheckBeasts_63:
# 266 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_61

SootopolisCity_House3_EventScript_WallaceCheckBeasts_64:
# 268 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_61

SootopolisCity_House3_EventScript_WallaceCheckBeasts_65:
# 270 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_61

SootopolisCity_House3_EventScript_WallaceCheckBeasts_67:
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_66

SootopolisCity_House3_EventScript_WallaceCheckBeasts_70:
# 187 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_WallaceCheckBeasts_67
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_69

SootopolisCity_House3_EventScript_WallaceCheckBeasts_74:
# 188 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_67
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_73

SootopolisCity_House3_EventScript_WallaceCheckBeasts_77:
# 189 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_WallaceCheckBeasts_67
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_68

SootopolisCity_House3_EventScript_WallaceCheckBeasts_81:
# 131 "data//maps/SootopolisCity_House3/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 132 "data//maps/SootopolisCity_House3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_House3_EventScript_WallaceCheckBeasts_87
# 140 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 141 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 142 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_11, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_80

SootopolisCity_House3_EventScript_WallaceCheckBeasts_85:
# 211 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_WALLACE_SHOWED_BEAST
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_84

SootopolisCity_House3_EventScript_WallaceCheckBeasts_87:
# 133 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 134 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 135 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_80

SootopolisCity_House3_EventScript_WallaceCheckBeasts_90:
# 150 "data//maps/SootopolisCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 151 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmovement
# 152 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12, MSGBOX_DEFAULT
	goto SootopolisCity_House3_EventScript_WallaceCheckBeasts_80


# 331 "data//maps/SootopolisCity_House3/scripts.pory"

# 332 "data//maps/SootopolisCity_House3/scripts.pory"

# 333 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Wallace::
# 334 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 335 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 336 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock
# 337 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_unset FLAG_MET_WALLACE, SootopolisCity_House3_EventScript_WallaceThanks
# 338 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceSearchingBeasts, MSGBOX_DEFAULT
# 339 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 340 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_ENTEI, SootopolisCity_House3_EventScript_EnteiSpeech
# 341 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_SUICUNE, SootopolisCity_House3_EventScript_SuicuneSpeech
# 342 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_RAIKOU, SootopolisCity_House3_EventScript_RaikouSpeech
# 343 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 344 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 345 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 346 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 347 "data//maps/SootopolisCity_House3/scripts.pory"

# 348 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceThanks::
# 349 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThanks, MSGBOX_DEFAULT
# 350 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 351 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_MET_WALLACE
# 352 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 353 "data//maps/SootopolisCity_House3/scripts.pory"

# 354 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_EnteiSpeech::
# 355 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_EnteiSpeech, MSGBOX_DEFAULT
# 356 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 357 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_ENTEI
# 358 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenEntei
# 359 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 360 "data//maps/SootopolisCity_House3/scripts.pory"

# 361 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenEntei::
# 362 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenEntei, MSGBOX_DEFAULT
# 363 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 364 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_ENTEI, SootopolisCity_House3_EventScript_CaughtEntei
# 365 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 366 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 367 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewEntei
# 368 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 369 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 370 "data//maps/SootopolisCity_House3/scripts.pory"

# 371 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtEntei::
# 372 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtEntei, MSGBOX_DEFAULT
# 373 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 374 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 375 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowEntei
# 376 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeEntei, MSGBOX_DEFAULT
# 377 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 378 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 379 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 380 "data//maps/SootopolisCity_House3/scripts.pory"

# 381 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowEntei::
# 382 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_ENTEI, OPEN_PARTY_SCREEN
# 383 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketEntei
# 384 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstSuicune
# 385 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 386 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 387 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 388 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 389 "data//maps/SootopolisCity_House3/scripts.pory"

# 390 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstEntei::
# 391 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 392 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 393 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 394 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 395 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 396 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsRaikou, MSGBOX_DEFAULT
# 397 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 398 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
# 399 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_ENTEI, 0, 0
# 400 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_ENTEI
# 401 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroEntei, MSGBOX_DEFAULT
# 402 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 403 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 404 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 405 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 406 "data//maps/SootopolisCity_House3/scripts.pory"

# 407 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewEntei::
# 408 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 0
# 409 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 410 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 411 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 412 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_ENTEI
# 413 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 414 "data//maps/SootopolisCity_House3/scripts.pory"

# 415 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SuicuneSpeech::
# 416 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SuicuneSpeech, MSGBOX_DEFAULT
# 417 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 418 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_SUICUNE
# 419 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenSuicune
# 420 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 421 "data//maps/SootopolisCity_House3/scripts.pory"

# 422 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenSuicune::
# 423 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenSuicune, MSGBOX_DEFAULT
# 424 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 425 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_SUICUNE, SootopolisCity_House3_EventScript_CaughtSuicune
# 426 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 427 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 428 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewSuicune
# 429 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 430 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 431 "data//maps/SootopolisCity_House3/scripts.pory"

# 432 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtSuicune::
# 433 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtSuicune, MSGBOX_DEFAULT
# 434 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 435 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 436 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowSuicune
# 437 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeSuicune, MSGBOX_DEFAULT
# 438 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 439 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 440 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 441 "data//maps/SootopolisCity_House3/scripts.pory"

# 442 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowSuicune::
# 443 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_SUICUNE, OPEN_PARTY_SCREEN
# 444 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune
# 445 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstRaikou
# 446 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 447 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 448 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 449 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 450 "data//maps/SootopolisCity_House3/scripts.pory"

# 451 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstSuicune::
# 452 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 453 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 454 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 455 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 456 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 457 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsEntei, MSGBOX_DEFAULT
# 458 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 459 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
# 460 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_SUICUNE, 0, 0
# 461 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_SUICUNE
# 462 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroSuicune, MSGBOX_DEFAULT
# 463 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 464 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 465 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 466 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 467 "data//maps/SootopolisCity_House3/scripts.pory"

# 468 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewSuicune::
# 469 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 1
# 470 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 471 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 472 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 473 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_SUICUNE
# 474 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 475 "data//maps/SootopolisCity_House3/scripts.pory"

# 476 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_RaikouSpeech::
# 477 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_RaikouSpeech, MSGBOX_DEFAULT
# 478 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 479 "data//maps/SootopolisCity_House3/scripts.pory"
	getseenmon SPECIES_RAIKOU
# 480 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SeenRaikou
# 481 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 482 "data//maps/SootopolisCity_House3/scripts.pory"

# 483 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SeenRaikou::
# 484 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_SeenRaikou, MSGBOX_DEFAULT
# 485 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 486 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_CAUGHT_ROAMING_RAIKOU, SootopolisCity_House3_EventScript_CaughtRaikou
# 487 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 488 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 489 "data//maps/SootopolisCity_House3/scripts.pory"
	call_if_set FLAG_NO_ACTIVE_BEAST SootopolisCity_House3_EventScript_SpawnNewRaikou
# 490 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 491 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 492 "data//maps/SootopolisCity_House3/scripts.pory"

# 493 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_CaughtRaikou::
# 494 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_CaughtRaikou, MSGBOX_DEFAULT
# 495 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 496 "data//maps/SootopolisCity_House3/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 497 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_ShowRaikou
# 498 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ShowMeRaikou, MSGBOX_DEFAULT
# 499 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 500 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 501 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 502 "data//maps/SootopolisCity_House3/scripts.pory"

# 503 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_ShowRaikou::
# 504 "data//maps/SootopolisCity_House3/scripts.pory"
	@ checkspecies SPECIES_RAIKOU, OPEN_PARTY_SCREEN
# 505 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_set FLAG_ROAMING_BEASTS_CAUGHT, SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou
# 506 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_House3_EventScript_SpawnFirstEntei
# 507 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_AlwaysHunting, MSGBOX_DEFAULT
# 508 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 509 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 510 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 511 "data//maps/SootopolisCity_House3/scripts.pory"

# 512 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnFirstRaikou::
# 513 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 514 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 515 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 516 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 517 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 518 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_ThatsSuicune, MSGBOX_DEFAULT
# 519 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 520 "data//maps/SootopolisCity_House3/scripts.pory"
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
# 521 "data//maps/SootopolisCity_House3/scripts.pory"
	showmonpic SPECIES_RAIKOU, 0, 0
# 522 "data//maps/SootopolisCity_House3/scripts.pory"
	setseenmon SPECIES_RAIKOU
# 523 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_IntroRaikou, MSGBOX_DEFAULT
# 524 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 525 "data//maps/SootopolisCity_House3/scripts.pory"
	hidemonpic
# 526 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 527 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 528 "data//maps/SootopolisCity_House3/scripts.pory"

# 529 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_SpawnNewRaikou::
# 530 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_0x8004, 2
# 531 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 532 "data//maps/SootopolisCity_House3/scripts.pory"
	special InitRoamer
# 533 "data//maps/SootopolisCity_House3/scripts.pory"
	clearflag FLAG_NO_ACTIVE_BEAST
# 534 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_RAIKOU
# 535 "data//maps/SootopolisCity_House3/scripts.pory"
	return
# 536 "data//maps/SootopolisCity_House3/scripts.pory"

# 537 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Woman::
# 538 "data//maps/SootopolisCity_House3/scripts.pory"
	lock
# 539 "data//maps/SootopolisCity_House3/scripts.pory"
	faceplayer
# 540 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
# 541 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
# 542 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
# 543 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 544 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 545 "data//maps/SootopolisCity_House3/scripts.pory"

# 546 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_HaveFans::
# 547 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
# 548 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 549 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 550 "data//maps/SootopolisCity_House3/scripts.pory"

# 551 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_Girl::
# 552 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
# 553 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 554 "data//maps/SootopolisCity_House3/scripts.pory"

# 555 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketEntei::
# 556 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastEntei, MSGBOX_DEFAULT
# 557 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 558 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 559 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 560 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 561 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 562 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 563 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 564 "data//maps/SootopolisCity_House3/scripts.pory"

# 565 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketSuicune::
# 566 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastSuicune, MSGBOX_DEFAULT
# 567 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 568 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 569 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 570 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 571 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 572 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 573 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 574 "data//maps/SootopolisCity_House3/scripts.pory"

# 575 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicketRaikou::
# 576 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceFinalBeastRaikou, MSGBOX_DEFAULT
# 577 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 578 "data//maps/SootopolisCity_House3/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, SootopolisCity_House3_EventScript_WallaceGiveTicket
# 579 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest2 MSGBOX_DEFAULT
# 580 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 581 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 582 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 583 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 584 "data//maps/SootopolisCity_House3/scripts.pory"

# 585 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceGiveTicket::
# 586 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceThreeBeasts, MSGBOX_DEFAULT
# 587 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 588 "data//maps/SootopolisCity_House3/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 589 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 590 "data//maps/SootopolisCity_House3/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 591 "data//maps/SootopolisCity_House3/scripts.pory"
	setvar VAR_BEAST_SPECIES, SPECIES_HO_OH
# 592 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 593 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 594 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 595 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 596 "data//maps/SootopolisCity_House3/scripts.pory"

# 597 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_EventScript_WallaceMeetAtNavelRock::
# 598 "data//maps/SootopolisCity_House3/scripts.pory"
	msgbox SootopolisCity_House3_Text_WallaceGiveHoohQuest MSGBOX_DEFAULT
# 599 "data//maps/SootopolisCity_House3/scripts.pory"
	waitmessage
# 600 "data//maps/SootopolisCity_House3/scripts.pory"
	release
# 601 "data//maps/SootopolisCity_House3/scripts.pory"
	end
# 602 "data//maps/SootopolisCity_House3/scripts.pory"

# 603 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeEntei:
# 604 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me ENTEI, I'll be\n"
# 605 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 606 "data//maps/SootopolisCity_House3/scripts.pory"

# 607 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeSuicune:
# 608 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me SUICUNE, I'll be\n"
# 609 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 610 "data//maps/SootopolisCity_House3/scripts.pory"

# 611 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ShowMeRaikou:
# 612 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can show me RAIKOU, I'll be\n"
# 613 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "indebted to you once more, {PLAYER}.$"
# 614 "data//maps/SootopolisCity_House3/scripts.pory"

# 615 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtEntei:
# 616 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 617 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 618 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 619 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 620 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured ENTEI?!$"
# 621 "data//maps/SootopolisCity_House3/scripts.pory"

# 622 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtSuicune:
# 623 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 624 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 625 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 626 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 627 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured SUICUNE?!$"
# 628 "data//maps/SootopolisCity_House3/scripts.pory"

# 629 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_CaughtRaikou:
# 630 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 631 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 632 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 633 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 634 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You've captured RAIKOU?!$"
# 635 "data//maps/SootopolisCity_House3/scripts.pory"

# 636 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenEntei:
# 637 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 638 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 639 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen ENTEI?$"
# 640 "data//maps/SootopolisCity_House3/scripts.pory"

# 641 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenSuicune:
# 642 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 643 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 644 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen SUICUNE?$"
# 645 "data//maps/SootopolisCity_House3/scripts.pory"

# 646 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SeenRaikou:
# 647 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 648 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 649 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh! You've seen RAIKOU?$"
# 650 "data//maps/SootopolisCity_House3/scripts.pory"

# 651 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_EnteiSpeech:
# 652 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 653 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 654 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON ENTEI has been\n"
# 655 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 656 "data//maps/SootopolisCity_House3/scripts.pory"

# 657 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_SuicuneSpeech:
# 658 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 659 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 660 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON SUICUNE has been\n"
# 661 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 662 "data//maps/SootopolisCity_House3/scripts.pory"

# 663 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_RaikouSpeech:
# 664 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Lately there have been rumors of\n"
# 665 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "sightings of one such POKéMON.\p"
# 666 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, the POKéMON RAIKOU has been\n"
# 667 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "seen recently around the HOENN region.$"
# 668 "data//maps/SootopolisCity_House3/scripts.pory"

# 669 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsEntei:
# 670 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 671 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 672 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 673 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 674 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 675 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 676 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard news of SUICUNE\n"
# 677 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "roaming around HOENN as well...$"
# 678 "data//maps/SootopolisCity_House3/scripts.pory"

# 679 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroSuicune:
# 680 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE is the Aurora POKéMON.\p"
# 681 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture SUICUNE and show it\n" 
# 682 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 683 "data//maps/SootopolisCity_House3/scripts.pory"

# 684 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsSuicune:
# 685 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 686 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 687 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 688 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 689 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 690 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 691 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that RAIKOU\n"
# 692 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 693 "data//maps/SootopolisCity_House3/scripts.pory"

# 694 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroRaikou:
# 695 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAIKOU is the Thunder POKéMON.\p"
# 696 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture RAIKOU and show it\n" 
# 697 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 698 "data//maps/SootopolisCity_House3/scripts.pory"

# 699 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_ThatsRaikou:
# 700 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 701 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 702 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 703 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.\p"
# 704 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Maybe someday I will be able to see\n"
# 705 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the other legendary beasts as well.\p"
# 706 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've recently heard reports that ENTEI\n"
# 707 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "has been spotted around HOENN as well...$"
# 708 "data//maps/SootopolisCity_House3/scripts.pory"

# 709 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_IntroEntei:
# 710 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "ENTEI is the Volcano POKéMON.\p"
# 711 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you can capture ENTEI and show it\n" 
# 712 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to me, I'll be indebted to you once more.$"
# 713 "data//maps/SootopolisCity_House3/scripts.pory"

# 714 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThanks:
# 715 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Thanks for your help with\n"
# 716 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "that incident. Your help finding\l"
# 717 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "RAYQUAZA was invaluable.$"
# 718 "data//maps/SootopolisCity_House3/scripts.pory"

# 719 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceSearchingBeasts:
# 720 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: I'm considered an expert\n"
# 721 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "on the mythology of super-ancient\l"
# 722 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON because I've spent my life\l"
# 723 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "researching a POKéMON called SUICUNE.\p"
# 724 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Through my research and my travels,\n"
# 725 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I've learned quite a bit about the\l"
# 726 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "myths surrounding the super-ancient\l"
# 727 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "POKéMON called the legendary beasts.$"
# 728 "data//maps/SootopolisCity_House3/scripts.pory"

# 729 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_JuanHasManyFansDoYou:
# 730 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\p"
# 731 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SOOTOPOLIS's JUAN has many fans.\n"
# 732 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Even more than his student WALLACE!\p"
# 733 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Do you have any?$"
# 734 "data//maps/SootopolisCity_House3/scripts.pory"

# 735 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_YouMustBePrettyStrong:
# 736 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, then you must be pretty strong.$"
# 737 "data//maps/SootopolisCity_House3/scripts.pory"

# 738 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
# 739 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Oh, dear…\n"
# 740 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's a little lonesome.\p"
# 741 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Try working a little harder to get\n"
# 742 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "a fan following.$"
# 743 "data//maps/SootopolisCity_House3/scripts.pory"

# 744 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_TrainerFanClubWasWild:
# 745 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Dedicated fans come over from even\n"
# 746 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "outside of HOENN.\p"
# 747 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It was really wild when I went to the\n"
# 748 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "TRAINER FAN CLUB in LILYCOVE.$"
# 749 "data//maps/SootopolisCity_House3/scripts.pory"

# 750 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_AlwaysHunting:
# 751 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm always hunting for more information\n"
# 752 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "regarding the legendary beasts ENTEI,\l"
# 753 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "SUICUNE, and RAIKOU.\p"
# 754 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "If you see one, please come back and\n"
# 755 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "let me know.$"
# 756 "data//maps/SootopolisCity_House3/scripts.pory"

# 757 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastEntei:
# 758 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 759 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's ENTEI!\p"
# 760 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 761 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 762 "data//maps/SootopolisCity_House3/scripts.pory"

# 763 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastSuicune:
# 764 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 765 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's SUICUNE!\p"
# 766 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 767 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 768 "data//maps/SootopolisCity_House3/scripts.pory"

# 769 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceFinalBeastRaikou:
# 770 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That POKéMON . . .\p"
# 771 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "That's RAIKOU!\p"
# 772 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "It's incredible to see a POKéMON as\n"
# 773 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "magnificent as this up close.$"
# 774 "data//maps/SootopolisCity_House3/scripts.pory"

# 775 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceThreeBeasts:
# 776 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 777 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 778 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 779 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Thanks to you, I've been able to fulfill\n"
# 780 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "my life's dream of seeing all three of\l"
# 781 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the legendary beast POKéMON . . .\p"
# 782 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\n"
# 783 "data//maps/SootopolisCity_House3/scripts.pory"
	.string ". . .\p"
# 784 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ultimately, though I dedicated my life\n"
# 785 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "to finding SUICUNE, it was you alone,\l"
# 786 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 787 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Yes, I, WALLACE, had nothing to do with\n"
# 788 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "your dazzling discovery . . .\p"
# 789 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER},\n"
# 790 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'd like you to take this.$"
# 791 "data//maps/SootopolisCity_House3/scripts.pory"

# 792 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest:
# 793 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: With the MYSTIC TICKET\n"
# 794 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "you can travel to NAVEL ROCK.\p"
# 795 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me there with the\n"
# 796 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "three legendary beast POKéMON you've\l"
# 797 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "caught.\p"
# 798 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 799 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$" 
# 800 "data//maps/SootopolisCity_House3/scripts.pory"

# 801 "data//maps/SootopolisCity_House3/scripts.pory"
SootopolisCity_House3_Text_WallaceGiveHoohQuest2:
# 802 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "{PLAYER} . . .\p"
# 803 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I want you to meet me at NAVEL ROCK with\n"
# 804 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "the three legendary beast POKéMON.\p"
# 805 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "By assembling them all in that place...\n"
# 806 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Can we summon HO-OH?$"

SootopolisCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 22 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

SootopolisCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
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
# 46 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_1:
# 50 "data//maps/SootopolisCity_House3/scripts.pory"
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

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_2:
# 55 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON ENTEI.\p"
	.string "ENTEI is one of a trio of BEAST POKéMON\n"
	.string "that have fascinated me all my life.\p"
	.string "It commands respect with its regal\n"
	.string "prescence, yet is capable of unrivaled\l"
	.string "intensity in battle.\p"
	.string "I have reason to believe ENTEI has been\n"
	.string "roaming the region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_3:
# 61 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "I have reason to believe\n"
	.string "{STR_VAR_1} has been roaming the\l"
	.string "region as of late.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_4:
# 68 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_5:
# 78 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming SUICUNE??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "So nonchalant…\p"
	.string "You're still caught in the carefree\n"
	.string "currents of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as elusive as SUICUNE\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_6:
# 84 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming RAIKOU??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "Incredible…\p"
	.string "You're still caught in the carefree\n"
	.string "clouds of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as relentless as RAIKOU\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_7:
# 89 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming ENTEI??\p"
	.string "{PLAYER}…{PAUSE 20}\l"
	.string "How terrifying…\p"
	.string "You embody the wild flame of youth,\p"
	.string "yet you managed to best a LEGENDARY\n"
	.string "POKéMON as commanding as ENTEI\l"
	.string "seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_8:
# 95 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You caught the roaming\n"
	.string "{STR_VAR_1}??\p"
	.string "How impressive that you managed to\n"
	.string "best a LEGENDARY POKéMON like\l"
	.string "{STR_VAR_1} seemingly with ease…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_9:
# 108 "data//maps/SootopolisCity_House3/scripts.pory"
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

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_10:
# 135 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well show it when boarding the S.S.\n"
	.string "TIDAL to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_11:
# 143 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Show that when boarding the S.S. TIDAL\n"
	.string "to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_12:
# 152 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Ah, it seems you already have a MYSTIC\n"
	.string "TICKET.\p"
	.string "Well when the S.S. TIDAL opens, use it to\n"
	.string "travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_13:
# 160 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "When the S.S. TIDAL opens, use that\n"
	.string "ticket to travel to NAVEL ROCK.\p"
	.string "There, we'll witness the relentless\n"
	.string "force of your BEAST POKéMON in action!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_14:
# 190 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is yet a third species of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_15:
# 194 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You know, {PLAYER}…\n"
	.string "There is not one, but three of these\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "I've also heard rumors of a roaming\n"
	.string "{STR_VAR_1} having recently been\l"
	.string "seen across HOENN.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_16:
# 204 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "This is the BEAST POKéMON\n"
	.string "{STR_VAR_1}.$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_17:
# 213 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's out there, {PLAYER}.\p"
	.string "If you learn anything about\n"
	.string "{STR_VAR_1}, please let me know!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_18:
# 221 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming SUICUNE?\p"
	.string "Such a beautiful POKéMON…\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_19:
# 224 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming RAIKOU?\p"
	.string "Such a striking POKéMON…\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_20:
# 227 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming ENTEI?\p"
	.string "Such an intense POKéMON…\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_21:
# 231 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Have you seen the roaming\n"
	.string "{STR_VAR_1}?\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_22:
# 248 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming SUICUNE??\p"
	.string "Isn't it beautiful?\p"
	.string "Oh how I yearn to see that elegant\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_23:
# 251 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming RAIKOU??\p"
	.string "Isn't it striking?\p"
	.string "Oh how I yearn to see that terrifying\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_24:
# 254 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming ENTEI??\p"
	.string "Isn't it intense?\p"
	.string "Oh how I yearn to see that majestic\n"
	.string "beast for myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_25:
# 258 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "You saw the roaming {STR_VAR_1}??\p"
	.string "Oh how I yearn to see that beast for\n"
	.string "myself someday…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_26:
# 276 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I know it's still out there, {PLAYER}.\p"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_27:
# 280 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "Please let me know if you learn anything\n"
	.string "more!$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_28:
# 289 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON SUICUNE.\p"
	.string "My swift and elegant, yet unbreakable\n"
	.string "battle style is based partly on legends\l"
	.string "of SUICUNE's might.\p"
	.string "I have reason to believe SUICUNE has\n"
	.string "been roaming the region as of late.\p"
	.string "I aspire to glimpse it with my own eyes…$"

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_29:
# 294 "data//maps/SootopolisCity_House3/scripts.pory"
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

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_30:
# 300 "data//maps/SootopolisCity_House3/scripts.pory"
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

SootopolisCity_House3_EventScript_WallaceCheckBeasts_Text_31:
# 307 "data//maps/SootopolisCity_House3/scripts.pory"
	.string "I'm traveling HOENN right now in search\n"
	.string "of the POKéMON {STR_VAR_1}.\p"
	.string "{PLAYER}, if you encounter\n"
	.string "{STR_VAR_1}, please inform me!$"
