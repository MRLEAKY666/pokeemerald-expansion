# 1 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
PacifidlogTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	.byte 0

PacifidlogTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 14 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 20 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


PacifidlogTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 30 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

PacifidlogTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 31 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	goto PacifidlogTown_PokemonCenter_2F_EventScript_Wallace
	return


PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 49 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 37 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 40 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 43 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 46 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 55 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 77 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 56 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 59 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 62 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 65 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 68 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 71 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 74 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto PacifidlogTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 83 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 84 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 85 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 87 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 89 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 91 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 94 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 95 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 96 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	release
	return

PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 86 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 88 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 90 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 92 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto PacifidlogTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


PacifidlogTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 100 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 101 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 102 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 103 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 104 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	release
	return


PacifidlogTown_PokemonCenter_2F_EventScript_Wallace::
# 108 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 109 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 110 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_2
# 115 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 120 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_1:
# 122 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 123 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 126 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_2:
# 111 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 112 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_1


# 130 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"

# 131 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"

# 132 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 133 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
PacifidlogTown_PokemonCenter_2F_EventScript_Colosseum::
# 134 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 135 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	end
# 136 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"

# 137 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
PacifidlogTown_PokemonCenter_2F_EventScript_TradeCenter::
# 138 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 139 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	end
# 140 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"

# 141 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
PacifidlogTown_PokemonCenter_2F_EventScript_RecordCorner::
# 142 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 143 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 111 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

PacifidlogTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 115 "data//maps/PacifidlogTown_PokemonCenter_2F/scripts.pory"
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
