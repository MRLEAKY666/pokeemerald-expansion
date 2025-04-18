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
# 168 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_NotChosen
InsideOfTruck_EventScript_Starterball_1:
# 170 "data//maps/InsideOfTruck/scripts.pory"
	waitmessage
# 171 "data//maps/InsideOfTruck/scripts.pory"
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
# 165 "data//maps/InsideOfTruck/scripts.pory"
	call GenerateRivalStarter
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
# 177 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 178 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 179 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 184 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 185 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 186 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_TransferredToPC
	return


GenerateStarter::
# 191 "data//maps/InsideOfTruck/scripts.pory"
	randompercentage 50
# 192 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GenerateStarter_2
GenerateStarter_1:
# 208 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq GenerateStarter_4
	return

GenerateStarter_2:
# 193 "data//maps/InsideOfTruck/scripts.pory"
	random 3
# 194 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_7
GenerateStarter_6:
# 198 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_13
GenerateStarter_12:
# 202 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_18
	goto GenerateStarter_1

GenerateStarter_4:
# 209 "data//maps/InsideOfTruck/scripts.pory"
	random 24
# 210 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_10
GenerateStarter_9:
# 214 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_16
GenerateStarter_15:
# 218 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_21
GenerateStarter_20:
# 222 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq GenerateStarter_24
GenerateStarter_23:
# 226 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq GenerateStarter_27
GenerateStarter_26:
# 230 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq GenerateStarter_30
GenerateStarter_29:
# 234 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq GenerateStarter_33
GenerateStarter_32:
# 238 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq GenerateStarter_36
GenerateStarter_35:
# 242 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq GenerateStarter_39
GenerateStarter_38:
# 246 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq GenerateStarter_42
GenerateStarter_41:
# 250 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq GenerateStarter_45
GenerateStarter_44:
# 254 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq GenerateStarter_48
GenerateStarter_47:
# 258 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq GenerateStarter_51
GenerateStarter_50:
# 262 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq GenerateStarter_54
GenerateStarter_53:
# 266 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq GenerateStarter_57
GenerateStarter_56:
# 270 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq GenerateStarter_60
GenerateStarter_59:
# 274 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq GenerateStarter_63
GenerateStarter_62:
# 278 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq GenerateStarter_66
GenerateStarter_65:
# 282 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq GenerateStarter_69
GenerateStarter_68:
# 286 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq GenerateStarter_72
GenerateStarter_71:
# 290 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq GenerateStarter_75
GenerateStarter_74:
# 294 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq GenerateStarter_78
GenerateStarter_77:
# 298 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq GenerateStarter_81
GenerateStarter_80:
# 302 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq GenerateStarter_83
	return

GenerateStarter_7:
# 195 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TORCHIC
# 196 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_6

GenerateStarter_10:
# 211 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PIPLUP
# 212 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_9

GenerateStarter_13:
# 199 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MUDKIP
# 200 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_12

GenerateStarter_16:
# 215 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_EEVEE
# 216 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_15

GenerateStarter_18:
# 203 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TREECKO
# 204 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_1

GenerateStarter_21:
# 219 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PICHU
# 220 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_20

GenerateStarter_24:
# 223 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TOGEPI
# 224 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_23

GenerateStarter_27:
# 227 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
# 228 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_26

GenerateStarter_30:
# 231 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOTHITA
# 232 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_29

GenerateStarter_33:
# 235 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SOLOSIS
# 236 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_32

GenerateStarter_36:
# 239 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_AXEW
# 240 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_35

GenerateStarter_39:
# 243 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOOMY
# 244 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_38

GenerateStarter_42:
# 247 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ROWLET
# 248 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_41

GenerateStarter_45:
# 251 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_APPLIN
# 252 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_44

GenerateStarter_48:
# 255 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MAGBY
# 256 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_47

GenerateStarter_51:
# 259 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ELEKID
# 260 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_50

GenerateStarter_54:
# 263 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SWINUB
# 264 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_53

GenerateStarter_57:
# 267 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVITAR
# 268 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_56

GenerateStarter_60:
# 271 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TURTWIG
# 272 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_59

GenerateStarter_63:
# 275 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CHARMANDER
# 276 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_62

GenerateStarter_66:
# 279 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BULBASAUR
# 280 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_65

GenerateStarter_69:
# 283 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SQUIRTLE
# 284 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_68

GenerateStarter_72:
# 287 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_OSHAWOTT
# 288 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 2
	goto GenerateStarter_71

GenerateStarter_75:
# 291 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
# 292 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	goto GenerateStarter_74

GenerateStarter_78:
# 295 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BUDEW
# 296 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_77

GenerateStarter_81:
# 299 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SPHEAL
# 300 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 0
	goto GenerateStarter_80

GenerateStarter_83:
# 303 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SHINX
# 304 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_0x8004, 1
	return


GenerateRivalStarter::
# 310 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 311 "data//maps/InsideOfTruck/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 312 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_STARTER_MON
# 313 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_TORCHIC, GenerateRivalStarter_2
# 328 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_MUDKIP, GenerateRivalStarter_3
# 343 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_TREECKO, GenerateRivalStarter_4
# 358 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_PIPLUP, GenerateRivalStarter_5
# 373 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_EEVEE, GenerateRivalStarter_6
# 388 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_PICHU, GenerateRivalStarter_7
# 403 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_TOGEPI, GenerateRivalStarter_8
# 418 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SNIVY, GenerateRivalStarter_9
# 433 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_GOTHITA, GenerateRivalStarter_10
# 448 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SOLOSIS, GenerateRivalStarter_11
# 463 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_AXEW, GenerateRivalStarter_12
# 478 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_GOOMY, GenerateRivalStarter_13
# 493 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_ROWLET, GenerateRivalStarter_14
# 508 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_APPLIN, GenerateRivalStarter_15
# 523 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_MAGBY, GenerateRivalStarter_16
# 538 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_ELEKID, GenerateRivalStarter_17
# 553 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SWINUB, GenerateRivalStarter_18
# 568 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_LARVITAR, GenerateRivalStarter_19
# 583 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_TURTWIG, GenerateRivalStarter_20
# 598 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_CHARMANDER, GenerateRivalStarter_21
# 613 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_BULBASAUR, GenerateRivalStarter_22
# 628 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SQUIRTLE, GenerateRivalStarter_23
# 643 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_OSHAWOTT, GenerateRivalStarter_24
# 658 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_CYNDAQUIL, GenerateRivalStarter_25
# 673 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_BUDEW, GenerateRivalStarter_26
# 688 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SPHEAL, GenerateRivalStarter_27
# 703 "data//maps/InsideOfTruck/scripts.pory"
	case SPECIES_SHINX, GenerateRivalStarter_28
	return

GenerateRivalStarter_2:
# 314 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 315 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 316 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_30
# 318 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_31
# 320 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_32
# 322 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_33
# 324 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_34
	return

GenerateRivalStarter_3:
# 329 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 330 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 331 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_36
# 333 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_37
# 335 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_38
# 337 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_39
# 339 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_40
	return

GenerateRivalStarter_4:
# 344 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 345 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 346 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_42
# 348 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_43
# 350 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_44
# 352 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_45
# 354 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_46
	return

GenerateRivalStarter_5:
# 359 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 360 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 361 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_48
# 363 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_49
# 365 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_50
# 367 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_51
# 369 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_52
	return

GenerateRivalStarter_6:
# 374 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 375 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 376 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_54
# 378 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_55
# 380 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_56
# 382 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_57
# 384 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_58
	return

GenerateRivalStarter_7:
# 389 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 390 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 391 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_60
# 393 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_61
# 395 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_62
# 397 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_63
# 399 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_64
	return

GenerateRivalStarter_8:
# 404 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 405 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 406 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_66
# 408 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_67
# 410 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_68
# 412 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_69
# 414 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_70
	return

GenerateRivalStarter_9:
# 419 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 420 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 421 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_72
# 423 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_73
# 425 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_74
# 427 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_75
# 429 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_76
	return

GenerateRivalStarter_10:
# 434 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 435 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 436 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_78
# 438 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_79
# 440 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_80
# 442 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_81
# 444 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_82
	return

GenerateRivalStarter_11:
# 449 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 450 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 451 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_84
# 453 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_85
# 455 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_86
# 457 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_87
# 459 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_88
	return

GenerateRivalStarter_12:
# 464 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 465 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 466 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_90
# 468 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_91
# 470 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_92
# 472 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_93
# 474 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_94
	return

GenerateRivalStarter_13:
# 479 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 480 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 481 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_96
# 483 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_97
# 485 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_98
# 487 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_99
# 489 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_100
	return

GenerateRivalStarter_14:
# 494 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 495 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 496 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_102
# 498 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_103
# 500 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_104
# 502 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_105
# 504 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_106
	return

GenerateRivalStarter_15:
# 509 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 510 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 511 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_108
# 513 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_109
# 515 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_110
# 517 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_111
# 519 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_112
	return

GenerateRivalStarter_16:
# 524 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 525 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 526 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_114
# 528 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_115
# 530 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_116
# 532 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_117
# 534 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_118
	return

GenerateRivalStarter_17:
# 539 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 540 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 541 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_120
# 543 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_121
# 545 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_122
# 547 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_123
# 549 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_124
	return

GenerateRivalStarter_18:
# 554 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 555 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 556 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_126
# 558 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_127
# 560 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_128
# 562 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_129
# 564 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_130
	return

GenerateRivalStarter_19:
# 569 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 570 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 571 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_132
# 573 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_133
# 575 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_134
# 577 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_135
# 579 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_136
	return

GenerateRivalStarter_20:
# 584 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 585 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 586 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_138
# 588 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_139
# 590 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_140
# 592 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_141
# 594 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_142
	return

GenerateRivalStarter_21:
# 599 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 600 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 601 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_144
# 603 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_145
# 605 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_146
# 607 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_147
# 609 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_148
	return

GenerateRivalStarter_22:
# 614 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 615 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 616 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_150
# 618 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_151
# 620 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_152
# 622 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_153
# 624 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_154
	return

GenerateRivalStarter_23:
# 629 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 630 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 631 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_156
# 633 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_157
# 635 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_158
# 637 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_159
# 639 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_160
	return

GenerateRivalStarter_24:
# 644 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 645 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 646 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_162
# 648 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_163
# 650 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_164
# 652 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_165
# 654 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_166
	return

GenerateRivalStarter_25:
# 659 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 660 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 661 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_168
# 663 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_169
# 665 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_170
# 667 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_171
# 669 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_172
	return

GenerateRivalStarter_26:
# 674 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 675 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 676 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_174
# 678 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_175
# 680 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_176
# 682 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_177
# 684 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_178
	return

GenerateRivalStarter_27:
# 689 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 690 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 691 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_180
# 693 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_181
# 695 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_182
# 697 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_183
# 699 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_184
	return

GenerateRivalStarter_28:
# 704 "data//maps/InsideOfTruck/scripts.pory"
	random 5
# 705 "data//maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 706 "data//maps/InsideOfTruck/scripts.pory"
	case 0, GenerateRivalStarter_186
# 708 "data//maps/InsideOfTruck/scripts.pory"
	case 1, GenerateRivalStarter_187
# 710 "data//maps/InsideOfTruck/scripts.pory"
	case 2, GenerateRivalStarter_188
# 712 "data//maps/InsideOfTruck/scripts.pory"
	case 3, GenerateRivalStarter_189
# 714 "data//maps/InsideOfTruck/scripts.pory"
	case 4, GenerateRivalStarter_190
	return

GenerateRivalStarter_30:
# 317 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_31:
# 319 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ABRA
	return

GenerateRivalStarter_32:
# 321 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_33:
# 323 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_34:
# 325 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_36:
# 332 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TREECKO
	return

GenerateRivalStarter_37:
# 334 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_38:
# 336 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_39:
# 338 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_CHIKORITA
	return

GenerateRivalStarter_40:
# 340 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_42:
# 347 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_43:
# 349 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_44:
# 351 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_45:
# 353 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_46:
# 355 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_48:
# 362 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TREECKO
	return

GenerateRivalStarter_49:
# 364 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_50:
# 366 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAREEP
	return

GenerateRivalStarter_51:
# 368 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SHINX
	return

GenerateRivalStarter_52:
# 370 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ELEKID
	return

GenerateRivalStarter_54:
# 377 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_55:
# 379 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_56:
# 381 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_57:
# 383 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_58:
# 385 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_60:
# 392 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_61:
# 394 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_62:
# 396 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_63:
# 398 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_64:
# 400 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_66:
# 407 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_67:
# 409 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_68:
# 411 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAREEP
	return

GenerateRivalStarter_69:
# 413 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_70:
# 415 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_72:
# 422 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_73:
# 424 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_74:
# 426 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_75:
# 428 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_76:
# 430 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAGBY
	return

GenerateRivalStarter_78:
# 437 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_79:
# 439 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_80:
# 441 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_81:
# 443 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_82:
# 445 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_84:
# 452 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_85:
# 454 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_86:
# 456 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_87:
# 458 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_88:
# 460 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_90:
# 467 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_91:
# 469 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_92:
# 471 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_93:
# 473 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SPHEAL
	return

GenerateRivalStarter_94:
# 475 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_96:
# 482 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_97:
# 484 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_98:
# 486 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_99:
# 488 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_100:
# 490 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SPHEAL
	return

GenerateRivalStarter_102:
# 497 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_103:
# 499 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_104:
# 501 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ABRA
	return

GenerateRivalStarter_105:
# 503 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_106:
# 505 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_108:
# 512 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_109:
# 514 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_110:
# 516 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_111:
# 518 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_112:
# 520 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_114:
# 527 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_115:
# 529 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_116:
# 531 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_117:
# 533 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_118:
# 535 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ELEKID
	return

GenerateRivalStarter_120:
# 542 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_121:
# 544 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_122:
# 546 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_123:
# 548 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_124:
# 550 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAGBY
	return

GenerateRivalStarter_126:
# 557 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_127:
# 559 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_128:
# 561 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_129:
# 563 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DUSKULL
	return

GenerateRivalStarter_130:
# 565 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SPHEAL
	return

GenerateRivalStarter_132:
# 572 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_133:
# 574 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_134:
# 576 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_135:
# 578 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SPHEAL
	return

GenerateRivalStarter_136:
# 580 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_138:
# 587 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_139:
# 589 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_140:
# 591 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_141:
# 593 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAGBY
	return

GenerateRivalStarter_142:
# 595 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_GOOMY
	return

GenerateRivalStarter_144:
# 602 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_145:
# 604 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_146:
# 606 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_147:
# 608 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_148:
# 610 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SPHEAL
	return

GenerateRivalStarter_150:
# 617 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_151:
# 619 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_152:
# 621 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_153:
# 623 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_154:
# 625 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_156:
# 632 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TREECKO
	return

GenerateRivalStarter_157:
# 634 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_CHIKORITA
	return

GenerateRivalStarter_158:
# 636 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAREEP
	return

GenerateRivalStarter_159:
# 638 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_160:
# 640 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SHINX
	return

GenerateRivalStarter_162:
# 647 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TREECKO
	return

GenerateRivalStarter_163:
# 649 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_CHIKORITA
	return

GenerateRivalStarter_164:
# 651 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MAREEP
	return

GenerateRivalStarter_165:
# 653 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_166:
# 655 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ELEKID
	return

GenerateRivalStarter_168:
# 662 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_MUDKIP
	return

GenerateRivalStarter_169:
# 664 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_170:
# 666 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_171:
# 668 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_172:
# 670 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
	return

GenerateRivalStarter_174:
# 677 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TORCHIC
	return

GenerateRivalStarter_175:
# 679 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_NIDORAN_F
	return

GenerateRivalStarter_176:
# 681 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_DRATINI
	return

GenerateRivalStarter_177:
# 683 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_178:
# 685 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_FLETCHLING
	return

GenerateRivalStarter_180:
# 692 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TREECKO
	return

GenerateRivalStarter_181:
# 694 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_POLIWAG
	return

GenerateRivalStarter_182:
# 696 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_WHISMUR
	return

GenerateRivalStarter_183:
# 698 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SHINX
	return

GenerateRivalStarter_184:
# 700 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_ELEKID
	return

GenerateRivalStarter_186:
# 707 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_RHYHORN
	return

GenerateRivalStarter_187:
# 709 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_CHIKORITA
	return

GenerateRivalStarter_188:
# 711 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_SWINUB
	return

GenerateRivalStarter_189:
# 713 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_BUDEW
	return

GenerateRivalStarter_190:
# 715 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_RIVAL_STARTER, SPECIES_TRAPINCH
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
# 177 "data//maps/InsideOfTruck/scripts.pory"
	.string "And what is its name?$"

InsideOfTruck_NotChosen::
# 722 "data//maps/InsideOfTruck/scripts.pory"
	.string "Make sure to grab it before you leave!$"
