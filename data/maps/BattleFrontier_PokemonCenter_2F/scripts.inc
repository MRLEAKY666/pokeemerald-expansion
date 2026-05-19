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
# 13 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 31 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 19 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 22 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 25 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 28 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 37 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F
# 0 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 59 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 38 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 41 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 44 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 47 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 50 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 53 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 56 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto BattleFrontier_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 65 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	faceplayer
# 66 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 67 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 69 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 71 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 73 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_6
BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 78 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	release
	return

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 68 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 70 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 72 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1

BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 74 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto BattleFrontier_PokemonCenter_2F_EventScript_TrRoamingNPC_1


BattleFrontier_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 82 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	faceplayer
# 83 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 84 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 85 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	waitmovement
# 86 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	release
	return


# 89 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 90 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 91 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 92 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_Colosseum::
# 93 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 94 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
# 95 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 96 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_TradeCenter::
# 97 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 98 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
BattleFrontier_PokemonCenter_2F_EventScript_RecordCorner::
# 101 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 102 "data//maps/BattleFrontier_PokemonCenter_2F/scripts.pory"
	end
