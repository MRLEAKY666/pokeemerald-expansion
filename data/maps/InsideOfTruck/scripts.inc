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
# 163 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_NotChosen
InsideOfTruck_EventScript_Starterball_1:
# 165 "data//maps/InsideOfTruck/scripts.pory"
	waitmessage
# 166 "data//maps/InsideOfTruck/scripts.pory"
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
# 149 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq InsideOfTruck_EventScript_Starterball_31
# 158 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_2
InsideOfTruck_EventScript_Starterball_29:
# 160 "data//maps/InsideOfTruck/scripts.pory"
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
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29

InsideOfTruck_EventScript_Starterball_31:
# 150 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 151 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 152 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 153 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 154 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 155 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_29


NicknamePartyMon::
# 172 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 173 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 174 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 179 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 180 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 181 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_TransferredToPC
	return


GenerateStarter::
# 186 "data//maps/InsideOfTruck/scripts.pory"
	random 36
# 187 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_2
GenerateStarter_1:
# 190 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_5
GenerateStarter_4:
# 193 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_8
GenerateStarter_7:
# 196 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq GenerateStarter_11
GenerateStarter_10:
# 199 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq GenerateStarter_14
GenerateStarter_13:
# 202 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq GenerateStarter_17
GenerateStarter_16:
# 205 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq GenerateStarter_20
GenerateStarter_19:
# 208 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq GenerateStarter_23
GenerateStarter_22:
# 211 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq GenerateStarter_26
GenerateStarter_25:
# 214 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq GenerateStarter_29
GenerateStarter_28:
# 217 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq GenerateStarter_32
GenerateStarter_31:
# 220 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq GenerateStarter_35
GenerateStarter_34:
# 223 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq GenerateStarter_38
GenerateStarter_37:
# 226 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq GenerateStarter_41
GenerateStarter_40:
# 229 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq GenerateStarter_44
GenerateStarter_43:
# 232 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq GenerateStarter_47
GenerateStarter_46:
# 235 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq GenerateStarter_50
GenerateStarter_49:
# 238 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq GenerateStarter_53
GenerateStarter_52:
# 241 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq GenerateStarter_56
GenerateStarter_55:
# 244 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq GenerateStarter_59
GenerateStarter_58:
# 247 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq GenerateStarter_62
GenerateStarter_61:
# 250 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq GenerateStarter_65
GenerateStarter_64:
# 253 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq GenerateStarter_68
GenerateStarter_67:
# 256 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq GenerateStarter_71
GenerateStarter_70:
# 259 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq GenerateStarter_74
GenerateStarter_73:
# 262 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 25
	goto_if_eq GenerateStarter_77
GenerateStarter_76:
# 265 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 26
	goto_if_eq GenerateStarter_80
GenerateStarter_79:
# 268 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 27
	goto_if_eq GenerateStarter_83
GenerateStarter_82:
# 271 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 28
	goto_if_eq GenerateStarter_86
GenerateStarter_85:
# 274 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 29
	goto_if_eq GenerateStarter_89
GenerateStarter_88:
# 277 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_eq GenerateStarter_92
GenerateStarter_91:
# 280 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 31
	goto_if_eq GenerateStarter_95
GenerateStarter_94:
# 283 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 32
	goto_if_eq GenerateStarter_98
GenerateStarter_97:
# 286 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 33
	goto_if_eq GenerateStarter_101
GenerateStarter_100:
# 289 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 34
	goto_if_eq GenerateStarter_104
GenerateStarter_103:
# 292 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 35
	goto_if_eq GenerateStarter_106
	return

GenerateStarter_2:
# 188 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TREECKO
	goto GenerateStarter_1

GenerateStarter_5:
# 191 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TORCHIC
	goto GenerateStarter_4

GenerateStarter_8:
# 194 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MUDKIP
	goto GenerateStarter_7

GenerateStarter_11:
# 197 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PIPLUP
	goto GenerateStarter_10

GenerateStarter_14:
# 200 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_EEVEE
	goto GenerateStarter_13

GenerateStarter_17:
# 203 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PICHU
	goto GenerateStarter_16

GenerateStarter_20:
# 206 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TOGEPI
	goto GenerateStarter_19

GenerateStarter_23:
# 209 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
	goto GenerateStarter_22

GenerateStarter_26:
# 212 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA_HISUIAN
	goto GenerateStarter_25

GenerateStarter_29:
# 215 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA
	goto GenerateStarter_28

GenerateStarter_32:
# 218 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOTHITA
	goto GenerateStarter_31

GenerateStarter_35:
# 221 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SOLOSIS
	goto GenerateStarter_34

GenerateStarter_38:
# 224 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_AXEW
	goto GenerateStarter_37

GenerateStarter_41:
# 227 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVESTA
	goto GenerateStarter_40

GenerateStarter_44:
# 230 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOOMY
	goto GenerateStarter_43

GenerateStarter_47:
# 233 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ROWLET
	goto GenerateStarter_46

GenerateStarter_50:
# 236 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_APPLIN
	goto GenerateStarter_49

GenerateStarter_53:
# 239 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MIME_JR
	goto GenerateStarter_52

GenerateStarter_56:
# 242 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MAGBY
	goto GenerateStarter_55

GenerateStarter_59:
# 245 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ELEKID
	goto GenerateStarter_58

GenerateStarter_62:
# 248 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MANKEY
	goto GenerateStarter_61

GenerateStarter_65:
# 251 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SWINUB
	goto GenerateStarter_64

GenerateStarter_68:
# 254 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVITAR
	goto GenerateStarter_67

GenerateStarter_71:
# 257 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TURTWIG
	goto GenerateStarter_70

GenerateStarter_74:
# 260 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CHARMANDER
	goto GenerateStarter_73

GenerateStarter_77:
# 263 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SQUIRTLE
	goto GenerateStarter_76

GenerateStarter_80:
# 266 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BULBASAUR
	goto GenerateStarter_79

GenerateStarter_83:
# 269 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_OSHAWOTT
	goto GenerateStarter_82

GenerateStarter_86:
# 272 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
	goto GenerateStarter_85

GenerateStarter_89:
# 275 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_BUDEW
	goto GenerateStarter_88

GenerateStarter_92:
# 278 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SPHEAL
	goto GenerateStarter_91

GenerateStarter_95:
# 281 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SHINX
	goto GenerateStarter_94

GenerateStarter_98:
# 284 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SANDILE
	goto GenerateStarter_97

GenerateStarter_101:
# 287 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PAWNIARD
	goto GenerateStarter_100

GenerateStarter_104:
# 290 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_JANGMO_O
	goto GenerateStarter_103

GenerateStarter_106:
# 293 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CASTFORM
	return


InsideOfTruck_EventScript_Starterball_Text_0:
# 81 "data//maps/InsideOfTruck/scripts.pory"
	.string "Take your Pokémon?$"

InsideOfTruck_EventScript_Starterball_Text_1:
# 143 "data//maps/InsideOfTruck/scripts.pory"
	.string "Wouldn't want to leave it behind!$"

InsideOfTruck_EventScript_Starterball_Text_2:
# 158 "data//maps/InsideOfTruck/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 172 "data//maps/InsideOfTruck/scripts.pory"
	.string "And what is its name?$"

InsideOfTruck_NotChosen::
# 297 "data//maps/InsideOfTruck/scripts.pory"
	.string "Make sure to grab it before you leave!$"
