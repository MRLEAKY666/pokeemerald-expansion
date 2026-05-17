# 1 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_MapScripts::
# 3 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_2F_OnTransition
# 7 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	.byte 0

BattleFrontier_PokemonCenter_2F_OnTransition::
# 12 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	end


BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 30 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 18 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 21 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 24 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 27 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 36 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	faceplayer
# 37 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 38 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 40 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 42 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 44 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_6
BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 49 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	release
	return

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 39 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 41 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 43 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 45 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1


# 52 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 53 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 54 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 55 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_Colosseum::
# 56 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 57 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
# 58 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 59 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_TradeCenter::
# 60 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 61 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
# 62 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 63 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_RecordCorner::
# 64 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 65 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
