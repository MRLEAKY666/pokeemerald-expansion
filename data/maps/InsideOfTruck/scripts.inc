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
	setflag FLAG_SYS_SAVE_GET
# 12 "data//maps/InsideOfTruck/scripts.pory"
	end
# 13 "data//maps/InsideOfTruck/scripts.pory"

# 14 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_OnResume:
# 15 "data//maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
# 16 "data//maps/InsideOfTruck/scripts.pory"
	end
# 17 "data//maps/InsideOfTruck/scripts.pory"

# 18 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlags::
# 19 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 20 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 21 "data//maps/InsideOfTruck/scripts.pory"
	checkplayergender
# 22 "data//maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
# 23 "data//maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
# 24 "data//maps/InsideOfTruck/scripts.pory"
	end
# 25 "data//maps/InsideOfTruck/scripts.pory"

# 26 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsMale::
# 27 "data//maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 28 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 29 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
# 30 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 31 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
# 32 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
# 33 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 34 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
# 35 "data//maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 36 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 37 "data//maps/InsideOfTruck/scripts.pory"
	end
# 38 "data//maps/InsideOfTruck/scripts.pory"

# 39 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsFemale::
# 40 "data//maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 41 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 42 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
# 43 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 44 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
# 45 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
# 46 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 47 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
# 48 "data//maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 49 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 50 "data//maps/InsideOfTruck/scripts.pory"
	end
# 51 "data//maps/InsideOfTruck/scripts.pory"

# 52 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_DontLeave::
# 53 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 54 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_DontLeave, MSGBOX_DEFAULT
# 55 "data//maps/InsideOfTruck/scripts.pory"
	closemessage
# 56 "data//maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PreventExit
# 57 "data//maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 58 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
# 59 "data//maps/InsideOfTruck/scripts.pory"
	end
# 60 "data//maps/InsideOfTruck/scripts.pory"

# 61 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_MovingBox::
# 62 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
# 63 "data//maps/InsideOfTruck/scripts.pory"
	end
# 64 "data//maps/InsideOfTruck/scripts.pory"

# 65 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_PreventExit:
# 66 "data//maps/InsideOfTruck/scripts.pory"
	walk_left
# 67 "data//maps/InsideOfTruck/scripts.pory"
	step_end
# 68 "data//maps/InsideOfTruck/scripts.pory"

# 69 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_BoxPrintedWithMonLogo:
# 70 "data//maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
# 71 "data//maps/InsideOfTruck/scripts.pory"
	.string "It's a POKéMON brand moving and\n"
# 72 "data//maps/InsideOfTruck/scripts.pory"
	.string "delivery service.$"
# 73 "data//maps/InsideOfTruck/scripts.pory"

# 74 "data//maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_DontLeave:
# 75 "data//maps/InsideOfTruck/scripts.pory"
	.string "Don't forget your POKéMON!$"

InsideOfTruck_EventScript_Starterball::
# 81 "data//maps/InsideOfTruck/scripts.pory"
	lockall
# 82 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_0, MSGBOX_YESNO
# 83 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_Starterball_2
# 164 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_NotChosen
InsideOfTruck_EventScript_Starterball_1:
# 166 "data//maps/InsideOfTruck/scripts.pory"
	waitmessage
# 167 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_Starterball_2:
# 84 "data//maps/InsideOfTruck/scripts.pory"
	call GenerateStarter
# 85 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 86 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_6
# 90 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 91 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 92 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
InsideOfTruck_EventScript_Starterball_5:
# 95 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 96 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_10
# 100 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 101 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 102 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
InsideOfTruck_EventScript_Starterball_9:
# 104 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 105 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_14
# 109 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 110 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 111 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
InsideOfTruck_EventScript_Starterball_13:
# 113 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 114 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_18
# 118 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 119 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 120 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
InsideOfTruck_EventScript_Starterball_17:
# 122 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 123 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_22
# 127 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 128 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 129 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
InsideOfTruck_EventScript_Starterball_21:
# 131 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 132 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq InsideOfTruck_EventScript_Starterball_26
# 136 "data//maps/InsideOfTruck/scripts.pory"
	random 16
# 137 "data//maps/InsideOfTruck/scripts.pory"
	addvar VAR_RESULT, 15
# 138 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_6, VAR_RESULT
InsideOfTruck_EventScript_Starterball_25:
# 140 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 25
# 141 "data//maps/InsideOfTruck/scripts.pory"
	givemon VAR_STARTER_MON, 5, item = ITEM_NONE, ball = ITEM_LUXURY_BALL, hpIv = VAR_TEMP_1, atkIv = VAR_TEMP_2, defIv = VAR_TEMP_3, speedIv = VAR_TEMP_4, spAtkIv = VAR_TEMP_5, spDefIv = VAR_TEMP_6, isShiny = VAR_RESULT
# 142 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq InsideOfTruck_EventScript_Starterball_30
# 150 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq InsideOfTruck_EventScript_Starterball_31
# 159 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_2
InsideOfTruck_EventScript_Starterball_29:
# 161 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto InsideOfTruck_EventScript_Starterball_1

InsideOfTruck_EventScript_Starterball_6:
# 87 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_1, 31
	goto InsideOfTruck_EventScript_Starterball_5

InsideOfTruck_EventScript_Starterball_10:
# 97 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_2, 31
	goto InsideOfTruck_EventScript_Starterball_9

InsideOfTruck_EventScript_Starterball_14:
# 106 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_3, 31
	goto InsideOfTruck_EventScript_Starterball_13

InsideOfTruck_EventScript_Starterball_18:
# 115 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_4, 31
	goto InsideOfTruck_EventScript_Starterball_17

InsideOfTruck_EventScript_Starterball_22:
# 124 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_5, 31
	goto InsideOfTruck_EventScript_Starterball_21

InsideOfTruck_EventScript_Starterball_26:
# 133 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_6, 31
	goto InsideOfTruck_EventScript_Starterball_25

InsideOfTruck_EventScript_Starterball_30:
# 143 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 144 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 145 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 146 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 147 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 148 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29

InsideOfTruck_EventScript_Starterball_31:
# 151 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 152 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 153 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 154 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 155 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 156 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29


NicknamePartyMon::
# 173 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 174 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 175 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 180 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 181 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 182 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_TransferredToPC
	return


GenerateStarter::
# 187 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 188 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GenerateStarter_2
GenerateStarter_1:
# 201 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq GenerateStarter_4
	return

GenerateStarter_2:
# 189 "data//maps/InsideOfTruck/scripts.pory"
	random 3
# 190 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_7
GenerateStarter_6:
# 193 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_13
GenerateStarter_12:
# 196 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_18
	goto GenerateStarter_1

GenerateStarter_4:
# 202 "data//maps/InsideOfTruck/scripts.pory"
	random 33
# 203 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_10
GenerateStarter_9:
# 206 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_16
GenerateStarter_15:
# 209 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_21
GenerateStarter_20:
# 212 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq GenerateStarter_24
GenerateStarter_23:
# 215 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq GenerateStarter_27
GenerateStarter_26:
# 218 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq GenerateStarter_30
GenerateStarter_29:
# 221 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq GenerateStarter_33
GenerateStarter_32:
# 224 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq GenerateStarter_36
GenerateStarter_35:
# 227 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq GenerateStarter_39
GenerateStarter_38:
# 230 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq GenerateStarter_42
GenerateStarter_41:
# 233 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq GenerateStarter_45
GenerateStarter_44:
# 236 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq GenerateStarter_48
GenerateStarter_47:
# 239 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq GenerateStarter_51
GenerateStarter_50:
# 242 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq GenerateStarter_54
GenerateStarter_53:
# 245 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq GenerateStarter_57
GenerateStarter_56:
# 248 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq GenerateStarter_60
GenerateStarter_59:
# 251 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq GenerateStarter_63
GenerateStarter_62:
# 254 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq GenerateStarter_66
GenerateStarter_65:
# 257 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq GenerateStarter_69
GenerateStarter_68:
# 260 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq GenerateStarter_72
GenerateStarter_71:
# 263 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq GenerateStarter_75
GenerateStarter_74:
# 266 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq GenerateStarter_78
GenerateStarter_77:
# 269 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq GenerateStarter_81
GenerateStarter_80:
# 272 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq GenerateStarter_84
GenerateStarter_83:
# 275 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq GenerateStarter_87
GenerateStarter_86:
# 278 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_eq GenerateStarter_90
GenerateStarter_89:
# 281 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 26
	goto_if_eq GenerateStarter_93
GenerateStarter_92:
# 284 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 27
	goto_if_eq GenerateStarter_96
GenerateStarter_95:
# 287 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 28
	goto_if_eq GenerateStarter_99
GenerateStarter_98:
# 290 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 29
	goto_if_eq GenerateStarter_102
GenerateStarter_101:
# 293 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_eq GenerateStarter_105
GenerateStarter_104:
# 296 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 31
	goto_if_eq GenerateStarter_108
GenerateStarter_107:
# 299 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_eq GenerateStarter_110
	return

GenerateStarter_7:
# 191 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TREECKO
	goto GenerateStarter_6

GenerateStarter_10:
# 204 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PIPLUP
	goto GenerateStarter_9

GenerateStarter_13:
# 194 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TORCHIC
	goto GenerateStarter_12

GenerateStarter_16:
# 207 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_EEVEE
	goto GenerateStarter_15

GenerateStarter_18:
# 197 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MUDKIP
	goto GenerateStarter_1

GenerateStarter_21:
# 210 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PICHU
	goto GenerateStarter_20

GenerateStarter_24:
# 213 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TOGEPI
	goto GenerateStarter_23

GenerateStarter_27:
# 216 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
	goto GenerateStarter_26

GenerateStarter_30:
# 219 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA_HISUIAN
	goto GenerateStarter_29

GenerateStarter_33:
# 222 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA
	goto GenerateStarter_32

GenerateStarter_36:
# 225 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOTHITA
	goto GenerateStarter_35

GenerateStarter_39:
# 228 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SOLOSIS
	goto GenerateStarter_38

GenerateStarter_42:
# 231 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_AXEW
	goto GenerateStarter_41

GenerateStarter_45:
# 234 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVESTA
	goto GenerateStarter_44

GenerateStarter_48:
# 237 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOOMY
	goto GenerateStarter_47

GenerateStarter_51:
# 240 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ROWLET
	goto GenerateStarter_50

GenerateStarter_54:
# 243 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_APPLIN
	goto GenerateStarter_53

GenerateStarter_57:
# 246 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MIME_JR
	goto GenerateStarter_56

GenerateStarter_60:
# 249 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MAGBY
	goto GenerateStarter_59

GenerateStarter_63:
# 252 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ELEKID
	goto GenerateStarter_62

GenerateStarter_66:
# 255 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MANKEY
	goto GenerateStarter_65

GenerateStarter_69:
# 258 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SWINUB
	goto GenerateStarter_68

GenerateStarter_72:
# 261 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVITAR
	goto GenerateStarter_71

GenerateStarter_75:
# 264 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TURTWIG
	goto GenerateStarter_74

GenerateStarter_78:
# 267 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CHARMANDER
	goto GenerateStarter_77

GenerateStarter_81:
# 270 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SQUIRTLE
	goto GenerateStarter_80

GenerateStarter_84:
# 273 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BULBASAUR
	goto GenerateStarter_83

GenerateStarter_87:
# 276 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_OSHAWOTT
	goto GenerateStarter_86

GenerateStarter_90:
# 279 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
	goto GenerateStarter_89

GenerateStarter_93:
# 282 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BUDEW
	goto GenerateStarter_92

GenerateStarter_96:
# 285 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SPHEAL
	goto GenerateStarter_95

GenerateStarter_99:
# 288 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SHINX
	goto GenerateStarter_98

GenerateStarter_102:
# 291 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SANDILE
	goto GenerateStarter_101

GenerateStarter_105:
# 294 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PAWNIARD
	goto GenerateStarter_104

GenerateStarter_108:
# 297 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_JANGMO_O
	goto GenerateStarter_107

GenerateStarter_110:
# 300 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CASTFORM
	return


InsideOfTruck_EventScript_Starterball_Text_0:
# 82 "data//maps/InsideOfTruck/scripts.pory"
	.string "Take your Pokémon?$"

InsideOfTruck_EventScript_Starterball_Text_1:
# 144 "data//maps/InsideOfTruck/scripts.pory"
	.string "Wouldn't want to leave it behind!$"

InsideOfTruck_EventScript_Starterball_Text_2:
# 159 "data//maps/InsideOfTruck/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 173 "data//maps/InsideOfTruck/scripts.pory"
	.string "And what is its name?$"

InsideOfTruck_NotChosen::
# 305 "data//maps/InsideOfTruck/scripts.pory"
	.string "Make sure to grab it before you leave!$"
