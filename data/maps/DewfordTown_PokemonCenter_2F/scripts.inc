# 1 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	.byte 0

DewfordTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	end


DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 19 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 42 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 30 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 33 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 36 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 39 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 48 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 49 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 50 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 52 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 54 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 56 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 59 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 60 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 61 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 51 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 53 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 55 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 57 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 65 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 66 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace
	return


DewfordTown_PokemonCenter_2F_EventScript_Wallace::
# 71 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 72 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 73 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, DewfordTown_PokemonCenter_2F_EventScript_Wallace_2
# 78 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 83 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
DewfordTown_PokemonCenter_2F_EventScript_Wallace_1:
# 85 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 86 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 89 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_2:
# 74 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 75 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace_1


# 93 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 95 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_Colosseum::
# 96 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 97 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 98 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 99 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_TradeCenter::
# 100 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 101 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 102 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 103 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_RecordCorner::
# 104 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 105 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 74 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 78 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
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
