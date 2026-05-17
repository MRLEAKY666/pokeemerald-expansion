# 1 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	.byte 0

FortreeCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	end


FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 19 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 42 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 30 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 33 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 36 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 39 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 48 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 49 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 50 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 52 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 54 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 56 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 59 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 60 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 61 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	release
	return

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 51 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 53 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 55 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 57 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 65 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 66 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace
	return


FortreeCity_PokemonCenter_2F_EventScript_Wallace::
# 71 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 72 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 73 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, FortreeCity_PokemonCenter_2F_EventScript_Wallace_2
# 78 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 83 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
FortreeCity_PokemonCenter_2F_EventScript_Wallace_1:
# 85 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 86 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 87 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 88 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 89 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_Wallace_2:
# 74 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 75 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace_1


# 93 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 95 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 96 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_Colosseum::
# 97 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 98 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_TradeCenter::
# 101 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 102 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end
# 103 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 104 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_RecordCorner::
# 105 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 106 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end

FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 74 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 78 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
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
