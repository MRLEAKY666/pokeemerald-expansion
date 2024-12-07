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
# 107 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_NotChosen
InsideOfTruck_EventScript_Starterball_1:
# 109 "data//maps/InsideOfTruck/scripts.pory"
	waitmessage
# 110 "data//maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_Starterball_2:
# 83 "data//maps/InsideOfTruck/scripts.pory"
	call GenerateStarter
# 84 "data//maps/InsideOfTruck/scripts.pory"
	givemon VAR_STARTER_MON, 5, ITEM_NONE
# 85 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq InsideOfTruck_EventScript_Starterball_6
# 93 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq InsideOfTruck_EventScript_Starterball_7
# 102 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_2
InsideOfTruck_EventScript_Starterball_5:
# 104 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	goto InsideOfTruck_EventScript_Starterball_1

InsideOfTruck_EventScript_Starterball_6:
# 86 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 87 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 88 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 89 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 90 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 91 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_5

InsideOfTruck_EventScript_Starterball_7:
# 94 "data//maps/InsideOfTruck/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 95 "data//maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_Starterball_Text_1
# 96 "data//maps/InsideOfTruck/scripts.pory"
	removeobject 4
# 97 "data//maps/InsideOfTruck/scripts.pory"
	setflag FLAG_UNUSED_0x493
# 98 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_TEMP_0, 1
# 99 "data//maps/InsideOfTruck/scripts.pory"
	call NicknamePartyMon
	goto InsideOfTruck_EventScript_Starterball_5


NicknamePartyMon::
# 116 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 117 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 118 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 123 "data//maps/InsideOfTruck/scripts.pory"
	msgbox NicknamePartyMon_Text_0
# 124 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 125 "data//maps/InsideOfTruck/scripts.pory"
	call Common_EventScript_TransferredToPC
	return


GenerateStarter::
# 130 "data//maps/InsideOfTruck/scripts.pory"
	random 25
# 131 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GenerateStarter_2
GenerateStarter_1:
# 134 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GenerateStarter_5
GenerateStarter_4:
# 137 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq GenerateStarter_8
GenerateStarter_7:
# 140 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq GenerateStarter_11
GenerateStarter_10:
# 143 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq GenerateStarter_14
GenerateStarter_13:
# 146 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq GenerateStarter_17
GenerateStarter_16:
# 149 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq GenerateStarter_20
GenerateStarter_19:
# 152 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq GenerateStarter_23
GenerateStarter_22:
# 155 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq GenerateStarter_26
GenerateStarter_25:
# 158 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq GenerateStarter_29
GenerateStarter_28:
# 161 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq GenerateStarter_32
GenerateStarter_31:
# 164 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq GenerateStarter_35
GenerateStarter_34:
# 167 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 12
	goto_if_eq GenerateStarter_38
GenerateStarter_37:
# 170 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 13
	goto_if_eq GenerateStarter_41
GenerateStarter_40:
# 173 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_eq GenerateStarter_44
GenerateStarter_43:
# 176 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 15
	goto_if_eq GenerateStarter_47
GenerateStarter_46:
# 179 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 16
	goto_if_eq GenerateStarter_50
GenerateStarter_49:
# 182 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 17
	goto_if_eq GenerateStarter_53
GenerateStarter_52:
# 185 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 18
	goto_if_eq GenerateStarter_56
GenerateStarter_55:
# 188 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 19
	goto_if_eq GenerateStarter_59
GenerateStarter_58:
# 191 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_eq GenerateStarter_62
GenerateStarter_61:
# 194 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 21
	goto_if_eq GenerateStarter_65
GenerateStarter_64:
# 197 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 22
	goto_if_eq GenerateStarter_68
GenerateStarter_67:
# 200 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 23
	goto_if_eq GenerateStarter_71
GenerateStarter_70:
# 203 "data//maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 24
	goto_if_eq GenerateStarter_73
	return

GenerateStarter_2:
# 132 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TREECKO
	goto GenerateStarter_1

GenerateStarter_5:
# 135 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TORCHIC
	goto GenerateStarter_4

GenerateStarter_8:
# 138 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MUDKIP
	goto GenerateStarter_7

GenerateStarter_11:
# 141 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CASTFORM
	goto GenerateStarter_10

GenerateStarter_14:
# 144 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PIPLUP
	goto GenerateStarter_13

GenerateStarter_17:
# 147 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_EEVEE
	goto GenerateStarter_16

GenerateStarter_20:
# 150 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PICHU
	goto GenerateStarter_19

GenerateStarter_23:
# 153 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TOGEPI
	goto GenerateStarter_22

GenerateStarter_26:
# 156 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_PORYGON
	goto GenerateStarter_25

GenerateStarter_29:
# 159 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
	goto GenerateStarter_28

GenerateStarter_32:
# 162 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA_HISUIAN
	goto GenerateStarter_31

GenerateStarter_35:
# 165 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ZORUA
	goto GenerateStarter_34

GenerateStarter_38:
# 168 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOTHITA
	goto GenerateStarter_37

GenerateStarter_41:
# 171 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SOLOSIS
	goto GenerateStarter_40

GenerateStarter_44:
# 174 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_AXEW
	goto GenerateStarter_43

GenerateStarter_47:
# 177 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVESTA
	goto GenerateStarter_46

GenerateStarter_50:
# 180 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_GOOMY
	goto GenerateStarter_49

GenerateStarter_53:
# 183 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ROWLET
	goto GenerateStarter_52

GenerateStarter_56:
# 186 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_APPLIN
	goto GenerateStarter_55

GenerateStarter_59:
# 189 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MIME_JR
	goto GenerateStarter_58

GenerateStarter_62:
# 192 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MAGBY
	goto GenerateStarter_61

GenerateStarter_65:
# 195 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ELEKID
	goto GenerateStarter_64

GenerateStarter_68:
# 198 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_MANKEY
	goto GenerateStarter_67

GenerateStarter_71:
# 201 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SWINUB
	goto GenerateStarter_70

GenerateStarter_73:
# 204 "data//maps/InsideOfTruck/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_LARVITAR
	return


InsideOfTruck_EventScript_Starterball_Text_0:
# 81 "data//maps/InsideOfTruck/scripts.pory"
	.string "Take your Pokémon?$"

InsideOfTruck_EventScript_Starterball_Text_1:
# 87 "data//maps/InsideOfTruck/scripts.pory"
	.string "Wouldn't want to leave it behind!$"

InsideOfTruck_EventScript_Starterball_Text_2:
# 102 "data//maps/InsideOfTruck/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 116 "data//maps/InsideOfTruck/scripts.pory"
	.string "And what is its name?$"

InsideOfTruck_NotChosen::
# 208 "data//maps/InsideOfTruck/scripts.pory"
	.string "Make sure to grab it before you leave!$"
