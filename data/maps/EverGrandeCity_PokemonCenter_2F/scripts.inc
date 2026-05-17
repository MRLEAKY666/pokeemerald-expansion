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
# 30 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 18 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 21 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 24 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 27 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto EverGrandeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 36 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 37 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 38 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 40 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 42 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 44 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 49 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	release
	return

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 39 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 41 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 43 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 45 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto EverGrandeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


# 52 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 53 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 54 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 55 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_Colosseum::
# 56 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 57 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
# 58 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 59 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_TradeCenter::
# 60 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 61 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
# 62 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"

# 63 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
EverGrandeCity_PokemonCenter_2F_EventScript_RecordCorner::
# 64 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 65 "data//maps/EverGrandeCity_PokemonCenter_2F/scripts.pory"
	end
