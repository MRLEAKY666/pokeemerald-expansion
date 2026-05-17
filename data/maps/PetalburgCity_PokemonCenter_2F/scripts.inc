# 1 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
PetalburgCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	.byte 0

PetalburgCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	end


PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
# 19 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto PetalburgCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


PetalburgCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 29 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

PetalburgCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 30 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	goto PetalburgCity_PokemonCenter_2F_EventScript_Wallace
	return


PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
# 0 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
# 0 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
# 0 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
# 0 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 48 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 36 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 39 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 42 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 45 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto PetalburgCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 54 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 55 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 56 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 58 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 60 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 62 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 65 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 66 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 67 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	release
	return

PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 57 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 59 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 61 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 63 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto PetalburgCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


PetalburgCity_PokemonCenter_2F_EventScript_Wallace::
# 71 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 72 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 73 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, PetalburgCity_PokemonCenter_2F_EventScript_Wallace_2
# 78 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 83 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
PetalburgCity_PokemonCenter_2F_EventScript_Wallace_1:
# 85 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 86 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 89 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	release
	end

PetalburgCity_PokemonCenter_2F_EventScript_Wallace_2:
# 74 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 75 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto PetalburgCity_PokemonCenter_2F_EventScript_Wallace_1


# 93 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"

# 95 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 96 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
PetalburgCity_PokemonCenter_2F_EventScript_Colosseum::
# 97 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 98 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
PetalburgCity_PokemonCenter_2F_EventScript_TradeCenter::
# 101 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 102 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	end
# 103 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"

# 104 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
PetalburgCity_PokemonCenter_2F_EventScript_RecordCorner::
# 105 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 106 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	end

PetalburgCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 74 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

PetalburgCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 78 "data//maps/PetalburgCity_PokemonCenter_2F/scripts.pory"
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
