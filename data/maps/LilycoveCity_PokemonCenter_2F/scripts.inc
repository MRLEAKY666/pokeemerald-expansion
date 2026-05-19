# 1 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
LilycoveCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	.byte 0

LilycoveCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 14 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 20 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


LilycoveCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 30 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

LilycoveCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 31 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	goto LilycoveCity_PokemonCenter_2F_EventScript_Wallace
	return


LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 49 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 37 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 40 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 43 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 46 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 55 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 77 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 56 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 59 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 62 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 65 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 68 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 71 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 74 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto LilycoveCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 83 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 84 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 85 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 87 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 89 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 91 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 96 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	release
	return

LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 86 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 88 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 90 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 92 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto LilycoveCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


LilycoveCity_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 100 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 101 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 102 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 103 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 104 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	release
	return


LilycoveCity_PokemonCenter_2F_EventScript_Wallace::
# 108 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 109 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 110 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, LilycoveCity_PokemonCenter_2F_EventScript_Wallace_2
# 115 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 120 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
LilycoveCity_PokemonCenter_2F_EventScript_Wallace_1:
# 122 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 123 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 124 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 125 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 126 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_Wallace_2:
# 111 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 112 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto LilycoveCity_PokemonCenter_2F_EventScript_Wallace_1


# 130 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"

# 131 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"

# 132 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 133 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
LilycoveCity_PokemonCenter_2F_EventScript_Colosseum::
# 134 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 135 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	end
# 136 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"

# 137 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
LilycoveCity_PokemonCenter_2F_EventScript_TradeCenter::
# 138 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 139 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	end
# 140 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"

# 141 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
LilycoveCity_PokemonCenter_2F_EventScript_RecordCorner::
# 142 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 143 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	end

LilycoveCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 111 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

LilycoveCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 115 "data//maps/LilycoveCity_PokemonCenter_2F/scripts.pory"
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
