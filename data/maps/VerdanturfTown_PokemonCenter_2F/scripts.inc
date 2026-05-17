# 1 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	.byte 0

VerdanturfTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	return


VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 17 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 18 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 22 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 19 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 28 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 29 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto VerdanturfTown_PokemonCenter_2F_EventScript_Wallace
	return


VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 47 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 35 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 38 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 41 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 44 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 53 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 54 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 55 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 57 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 59 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 61 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 64 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 65 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 66 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	return

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 56 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 58 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 60 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 62 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_Wallace::
# 70 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 71 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 72 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2
# 77 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 82 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1:
# 84 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 85 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 88 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2:
# 73 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 74 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1


# 92 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 93 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 95 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum::
# 96 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 97 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 98 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 99 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter::
# 100 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 101 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 102 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 103 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner::
# 104 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 105 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 73 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 77 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
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
