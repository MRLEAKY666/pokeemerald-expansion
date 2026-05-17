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
# 30 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 18 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 21 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 24 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 27 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto SootopolisCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 36 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 37 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 38 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 40 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 42 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 44 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 47 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 48 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 49 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	release
	return

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 39 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 41 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 43 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 45 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto SootopolisCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


# 53 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 54 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 55 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 56 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_Colosseum::
# 57 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 58 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
# 59 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 60 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_TradeCenter::
# 61 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 62 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
# 63 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"

# 64 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
SootopolisCity_PokemonCenter_2F_EventScript_RecordCorner::
# 65 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 66 "data//maps/SootopolisCity_PokemonCenter_2F/scripts.pory"
	end
