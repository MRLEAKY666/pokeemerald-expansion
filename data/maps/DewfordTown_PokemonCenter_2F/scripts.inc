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
# 14 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 20 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
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
# 43 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 31 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 34 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 37 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 40 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 49 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 71 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 50 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 53 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 56 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 59 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 62 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 65 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 68 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto DewfordTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 77 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 78 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 79 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 81 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 83 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 85 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 88 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 89 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 90 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	return

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 80 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 82 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 84 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 86 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto DewfordTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 94 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 95 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 96 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	return


DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 100 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 101 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace
	return


DewfordTown_PokemonCenter_2F_EventScript_Wallace::
# 106 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 107 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 108 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, DewfordTown_PokemonCenter_2F_EventScript_Wallace_2
# 113 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 118 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
DewfordTown_PokemonCenter_2F_EventScript_Wallace_1:
# 120 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 121 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 124 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_2:
# 109 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 110 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace_1


# 128 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 129 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 130 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_Colosseum::
# 131 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 132 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 133 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 134 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_TradeCenter::
# 135 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 136 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 137 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 138 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_RecordCorner::
# 139 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 140 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 109 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 113 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
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
