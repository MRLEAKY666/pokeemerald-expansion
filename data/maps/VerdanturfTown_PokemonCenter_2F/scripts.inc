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
# 14 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	return


VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 19 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 29 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 30 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
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
# 48 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 36 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 39 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 42 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 45 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 54 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 76 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 55 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 58 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 61 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 64 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 67 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 70 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 73 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 82 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 83 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 84 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 86 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 88 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 90 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 93 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 94 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 95 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	return

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 85 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 87 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 89 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 91 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 99 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 100 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 101 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 102 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 103 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	return


VerdanturfTown_PokemonCenter_2F_EventScript_Wallace::
# 107 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 108 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 109 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2
# 114 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 119 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1:
# 121 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 122 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 125 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2:
# 110 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 111 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1


# 129 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 130 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 131 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 132 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum::
# 133 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 134 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 135 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 136 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter::
# 137 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 138 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 139 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 140 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner::
# 141 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 142 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 110 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 114 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
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
