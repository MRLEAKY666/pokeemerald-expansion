# 1 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.byte 0

LavaridgeTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavaridgeTown_PokemonCenter_2F_OnTransition_2
LavaridgeTown_PokemonCenter_2F_OnTransition_1:
# 15 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 16 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 17 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	return

LavaridgeTown_PokemonCenter_2F_OnTransition_2:
# 13 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_LAVARIDGE_BREAK_NURSE
	goto LavaridgeTown_PokemonCenter_2F_OnTransition_1


LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak::
# 21 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	lock
# 22 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 23 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0, MSGBOX_YESNO
# 24 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2
# 30 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_2, MSGBOX_DEFAULT
LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1:
# 32 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 33 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 34 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK, Common_Movement_FaceOriginalDirection
# 35 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK
# 36 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2:
# 25 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1, MSGBOX_DEFAULT
	goto LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1


LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 41 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 42 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 46 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 43 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 52 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 53 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace
	return


LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 71 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 59 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 62 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 65 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 68 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 77 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 99 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 78 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 81 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 84 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 87 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 90 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 93 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 96 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 105 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 106 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 107 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 109 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 111 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 113 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 118 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	return

LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 108 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 110 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 112 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 114 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto LavaridgeTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


LavaridgeTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 122 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 123 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 124 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	return


LavaridgeTown_PokemonCenter_2F_EventScript_Wallace::
# 128 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 129 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 130 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_2
# 135 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 140 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_1:
# 142 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 143 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 144 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 145 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 146 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_2:
# 131 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 132 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_1


# 150 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 151 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 152 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 153 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum::
# 154 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 155 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 156 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 157 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter::
# 158 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 159 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 160 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 161 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner::
# 162 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 163 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0:
# 23 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Oh, hey.\p"
	.string "Did you want to hear about the\n"
	.string "LAVARBOR TUNNEL again?$"

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1:
# 25 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Well, there were plans for a tunnel from\n"
	.string "here to FALLARBOR TOWN,\l"
	.string "but the project was cancelled…\p"
	.string "They never made much progress…\p"
	.string "Apparently the project leader spent\n"
	.string "too much time at the sauna instead of\l"
	.string "directing the dig.\p"
	.string "He's still there almost all the time!\n"
	.string "After they cancelled the project,\l"
	.string "he retired here to LAVARIDGE.$"

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_2:
# 30 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, you're right, it's pretty boring…$"

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 131 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 135 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
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
