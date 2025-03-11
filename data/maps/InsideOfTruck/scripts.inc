# 1 "data//maps/InsideOfTruck/scripts.pory"

# 2 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_MapScripts::
# 3 "data//maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 4 "data//maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
# 5 "data//maps/InsideOfTruck/scripts.pory"
	.byte 0
# 6 "data//maps/InsideOfTruck/scripts.pory"

# 7 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_OnLoad:
# 8 "data//maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 9 "data//maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 10 "data//maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
# 11 "data//maps/InsideOfTruck/scripts.pory"
	end
# 12 "data//maps/InsideOfTruck/scripts.pory"

# 13 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_OnResume:
# 14 "data//maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
# 15 "data//maps/InsideOfTruck/scripts.pory"
	end
# 16 "data//maps/InsideOfTruck/scripts.pory"

# 17 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlags::
# 18 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 19 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 20 "data//maps/InsideOfTruck/scripts.pory"
	checkplayergender
# 21 "data//maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
# 22 "data//maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
# 23 "data//maps/InsideOfTruck/scripts.pory"
	end
# 24 "data//maps/InsideOfTruck/scripts.pory"

# 25 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsMale::
# 26 "data//maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 27 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 28 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
# 29 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 30 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
# 31 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
# 32 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 33 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
# 34 "data//maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 35 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 36 "data//maps/InsideOfTruck/scripts.pory"
	end
# 37 "data//maps/InsideOfTruck/scripts.pory"

# 38 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsFemale::
# 39 "data//maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 40 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 41 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
# 42 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 43 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
# 44 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
# 45 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 46 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
# 47 "data//maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 48 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 49 "data//maps/InsideOfTruck/scripts.pory"
	end
# 50 "data//maps/InsideOfTruck/scripts.pory"

# 51 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_DontLeave::
# 52 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 53 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_DontLeave, MSGBOX_DEFAULT
# 54 "data//maps/InsideOfTruck/scripts.pory"
	closemessage
# 55 "data//maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PreventExit
# 56 "data//maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 57 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 58 "data//maps/InsideOfTruck/scripts.pory"
	end
# 59 "data//maps/InsideOfTruck/scripts.pory"

# 60 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_MovingBox::
# 61 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
# 62 "data//maps/InsideOfTruck/scripts.pory"
	end
# 63 "data//maps/InsideOfTruck/scripts.pory"

# 64 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_PreventExit:
# 65 "data//maps/InsideOfTruck/scripts.pory"
	walk_left
# 66 "data//maps/InsideOfTruck/scripts.pory"
	step_end
# 67 "data//maps/InsideOfTruck/scripts.pory"

# 68 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_BoxPrintedWithMonLogo:
# 69 "data//maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
# 70 "data//maps/InsideOfTruck/scripts.pory"
	.string "It's a POKéMON brand moving and\n"
# 71 "data//maps/InsideOfTruck/scripts.pory"
	.string "delivery service.$"
# 72 "data//maps/InsideOfTruck/scripts.pory"

# 73 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_DontLeave:
# 74 "data//maps/InsideOfTruck/scripts.pory"
	.string "Don't forget your POKéMON!$"

InsideOfTruck_EventScript_Starterball::
# 80 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 81 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_0, MSGBOX_YESNO
# 82 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_Starterball_2
# 167 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_NotChosen
InsideOfTruck_EventScript_Starterball_1:
# 169 "data//maps/InsideOfTruck/scripts.pory"
	waitmessage
# 170 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_Starterball_2:
# 83 "data//maps/InsideOfTruck/scripts.pory"
	call GenerateStarter
# 84 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 85 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_6
# 89 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 90 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 91 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
InsideOfTruck_EventScript_Starterball_5:
# 94 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 95 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_10
# 99 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 100 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 101 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
InsideOfTruck_EventScript_Starterball_9:
# 103 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 104 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_14
# 108 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 109 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 110 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
InsideOfTruck_EventScript_Starterball_13:
# 112 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 113 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_18
# 117 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 118 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 119 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
InsideOfTruck_EventScript_Starterball_17:
# 121 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 122 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_22
# 126 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 127 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 128 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
InsideOfTruck_EventScript_Starterball_21:
# 130 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 131 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_26
# 135 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 136 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 137 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
InsideOfTruck_EventScript_Starterball_25:
# 139 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 25
# 140 "data//maps/InsideOfTruck/scripts.pory"
	givemon VAR_STARTER_MON, 5, item = ITEM_NONE, ball = ITEM_LUXURY_BALL, hpIv = VAR_TEMP_1, atkIv = VAR_TEMP_2, defIv = VAR_TEMP_3, speedIv = VAR_TEMP_4, spAtkIv = VAR_TEMP_5, spDefIv = VAR_TEMP_6, isShiny = VAR_RESULT
# 141 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq InsideOfTruck_EventScript_Starterball_30
# 151 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq InsideOfTruck_EventScript_Starterball_31
# 162 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_2
InsideOfTruck_EventScript_Starterball_29:
# 164 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto InsideOfTruck_EventScript_Starterball_1

InsideOfTruck_EventScript_Starterball_6:
# 86 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_1, 31
	goto InsideOfTruck_EventScript_Starterball_5

InsideOfTruck_EventScript_Starterball_10:
# 96 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_2, 31
	goto InsideOfTruck_EventScript_Starterball_9

InsideOfTruck_EventScript_Starterball_14:
# 105 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_3, 31
	goto InsideOfTruck_EventScript_Starterball_13

InsideOfTruck_EventScript_Starterball_18:
# 114 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_4, 31
	goto InsideOfTruck_EventScript_Starterball_17

InsideOfTruck_EventScript_Starterball_22:
# 123 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_5, 31
	goto InsideOfTruck_EventScript_Starterball_21

InsideOfTruck_EventScript_Starterball_26:
# 132 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_6, 31
	goto InsideOfTruck_EventScript_Starterball_25

InsideOfTruck_EventScript_Starterball_30:
# 142 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 143 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 144 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 145 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 146 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 147 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 148 "data//maps/InsideOfTruck/scripts.pory"
	special InitRoamer
# 149 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29

InsideOfTruck_EventScript_Starterball_31:
# 152 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 153 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 154 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 155 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 156 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 157 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_UNUSED_0x8014, 0
# 158 "data//maps/InsideOfTruck/scripts.pory"
	special InitRoamer
# 159 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29


NicknamePartyMon::
# 176 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 177 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 178 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 183 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 184 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 185 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_TransferredToPC
	return


GenerateStarter::
# 190 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 191 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GenerateStarter_2
GenerateStarter_1:
# 207 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq GenerateStarter_4
	return

GenerateStarter_2:
# 192 "data//maps/InsideOfTruck/scripts.pory"
	random 3
# 193 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_7
GenerateStarter_6:
# 197 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_13
GenerateStarter_12:
# 201 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_18
	goto GenerateStarter_1

GenerateStarter_4:
# 208 "data//maps/InsideOfTruck/scripts.pory"
	random 32
# 209 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_10
GenerateStarter_9:
# 213 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_16
GenerateStarter_15:
# 217 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_21
GenerateStarter_20:
# 221 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq GenerateStarter_24
GenerateStarter_23:
# 225 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq GenerateStarter_27
GenerateStarter_26:
# 229 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq GenerateStarter_30
GenerateStarter_29:
# 233 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq GenerateStarter_33
GenerateStarter_32:
# 237 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq GenerateStarter_36
GenerateStarter_35:
# 241 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq GenerateStarter_39
GenerateStarter_38:
# 245 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq GenerateStarter_42
GenerateStarter_41:
# 249 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq GenerateStarter_45
GenerateStarter_44:
# 253 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq GenerateStarter_48
GenerateStarter_47:
# 257 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq GenerateStarter_51
GenerateStarter_50:
# 261 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq GenerateStarter_54
GenerateStarter_53:
# 265 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq GenerateStarter_57
GenerateStarter_56:
# 269 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq GenerateStarter_60
GenerateStarter_59:
# 273 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq GenerateStarter_63
GenerateStarter_62:
# 277 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq GenerateStarter_66
GenerateStarter_65:
# 281 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq GenerateStarter_69
GenerateStarter_68:
# 285 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq GenerateStarter_72
GenerateStarter_71:
# 289 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq GenerateStarter_75
GenerateStarter_74:
# 293 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq GenerateStarter_78
GenerateStarter_77:
# 297 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq GenerateStarter_81
GenerateStarter_80:
# 301 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq GenerateStarter_84
GenerateStarter_83:
# 305 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq GenerateStarter_87
GenerateStarter_86:
# 309 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_eq GenerateStarter_90
GenerateStarter_89:
# 313 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 26
	goto_if_eq GenerateStarter_93
GenerateStarter_92:
# 317 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 27
	goto_if_eq GenerateStarter_96
GenerateStarter_95:
# 321 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 28
	goto_if_eq GenerateStarter_99
GenerateStarter_98:
# 325 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 29
	goto_if_eq GenerateStarter_102
GenerateStarter_101:
# 328 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_eq GenerateStarter_105
GenerateStarter_104:
# 332 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 31
	goto_if_eq GenerateStarter_107
	return

GenerateStarter_7:
# 194 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TREECKO
# 195 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_6

GenerateStarter_10:
# 210 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PIPLUP
# 211 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_9

GenerateStarter_13:
# 198 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TORCHIC
# 199 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_12

GenerateStarter_16:
# 214 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_EEVEE
# 215 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_15

GenerateStarter_18:
# 202 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MUDKIP
# 203 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_1

GenerateStarter_21:
# 218 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PICHU
# 219 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_20

GenerateStarter_24:
# 222 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TOGEPI
# 223 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_23

GenerateStarter_27:
# 226 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
# 227 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_26

GenerateStarter_30:
# 230 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA_HISUI
# 231 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_29

GenerateStarter_33:
# 234 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA
# 235 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_32

GenerateStarter_36:
# 238 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOTHITA
# 239 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_35

GenerateStarter_39:
# 242 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SOLOSIS
# 243 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_38

GenerateStarter_42:
# 246 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_AXEW
# 247 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_41

GenerateStarter_45:
# 250 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVESTA
# 251 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_44

GenerateStarter_48:
# 254 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOOMY
# 255 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_47

GenerateStarter_51:
# 258 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ROWLET
# 259 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_50

GenerateStarter_54:
# 262 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_APPLIN
# 263 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_53

GenerateStarter_57:
# 266 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MIME_JR
# 267 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_56

GenerateStarter_60:
# 270 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MAGBY
# 271 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_59

GenerateStarter_63:
# 274 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ELEKID
# 275 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_62

GenerateStarter_66:
# 278 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MANKEY
# 279 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_65

GenerateStarter_69:
# 282 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SWINUB
# 283 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_68

GenerateStarter_72:
# 286 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVITAR
# 287 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_71

GenerateStarter_75:
# 290 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TURTWIG
# 291 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_74

GenerateStarter_78:
# 294 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CHARMANDER
# 295 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_77

GenerateStarter_81:
# 298 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SQUIRTLE
# 299 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_80

GenerateStarter_84:
# 302 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BULBASAUR
# 303 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_83

GenerateStarter_87:
# 306 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_OSHAWOTT
# 307 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_86

GenerateStarter_90:
# 310 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
# 311 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_89

GenerateStarter_93:
# 314 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BUDEW
# 315 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_92

GenerateStarter_96:
# 318 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SPHEAL
# 319 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_95

GenerateStarter_99:
# 322 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SHINX
# 323 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_98

GenerateStarter_102:
# 326 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SANDILE
	goto GenerateStarter_101

GenerateStarter_105:
# 329 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PAWNIARD
# 330 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_104

GenerateStarter_107:
# 333 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CASTFORM
# 334 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	return


InsideOfTruck_EventScript_Starterball_Text_0:
# 81 "data//maps/InsideOfTruck/scripts.pory"
	.string "Take your Pokémon?$"

InsideOfTruck_EventScript_Starterball_Text_1:
# 143 "data//maps/InsideOfTruck/scripts.pory"
	.string "Wouldn't want to leave it behind!$"

InsideOfTruck_EventScript_Starterball_Text_2:
# 162 "data//maps/InsideOfTruck/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 176 "data//maps/InsideOfTruck/scripts.pory"
	.string "And what is its name?$"

InsideOfTruck_NotChosen::
# 339 "data//maps/InsideOfTruck/scripts.pory"
	.string "Make sure to grab it before you leave!$"
