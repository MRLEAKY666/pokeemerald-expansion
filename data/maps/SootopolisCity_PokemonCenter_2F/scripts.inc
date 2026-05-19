# 1 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	.byte 0

SootopolisCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 13 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 31 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 19 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 22 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 25 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 28 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 37 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 59 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 38 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 41 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 44 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 47 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 50 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 53 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 56 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 65 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 66 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 67 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 69 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 71 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 73 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 76 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 77 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 78 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	release
	return

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 68 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 70 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 72 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 74 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


SootopolisCity_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 82 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 83 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 84 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 85 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 86 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	release
	return


# 90 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 91 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 92 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 93 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_Colosseum::
# 94 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 95 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
# 96 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 97 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_TradeCenter::
# 98 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 99 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
# 100 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 101 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_RecordCorner::
# 102 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 103 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
