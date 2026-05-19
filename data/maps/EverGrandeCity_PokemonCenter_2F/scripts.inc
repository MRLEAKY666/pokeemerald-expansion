# 1 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	.byte 0

EverGrandeCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 13 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 31 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 19 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 22 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 25 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 28 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 37 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 59 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 38 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 41 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 44 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 47 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 50 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 53 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 56 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 65 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 66 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 67 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 69 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 71 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 73 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 78 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	release
	return

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 68 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 70 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 72 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 74 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


EverGrandeCity_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 82 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 83 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 84 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 85 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 86 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	release
	return


# 89 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 90 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 91 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 92 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_Colosseum::
# 93 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 94 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
# 95 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 96 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_TradeCenter::
# 97 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 98 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_RecordCorner::
# 101 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 102 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
