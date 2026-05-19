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
# 14 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 20 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

FortreeCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
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
# 43 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 31 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 34 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 37 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 40 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 49 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_FORTREE_CITY_POKEMON_CENTER_2F
# 0 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 71 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 50 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 53 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 56 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 59 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 62 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 65 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 68 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto FortreeCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 77 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 78 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 79 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 81 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 83 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 85 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 88 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 89 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 90 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	release
	return

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 80 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 82 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 84 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 86 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto FortreeCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


FortreeCity_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 94 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 95 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 96 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	release
	return


FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 100 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

FortreeCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 101 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace
	return


FortreeCity_PokemonCenter_2F_EventScript_Wallace::
# 106 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 107 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 108 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, FortreeCity_PokemonCenter_2F_EventScript_Wallace_2
# 113 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 118 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
FortreeCity_PokemonCenter_2F_EventScript_Wallace_1:
# 120 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 121 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 122 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 123 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 124 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	release
	end

FortreeCity_PokemonCenter_2F_EventScript_Wallace_2:
# 109 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	msgbox FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 110 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace_1


# 128 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 129 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 130 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 131 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_Colosseum::
# 132 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 133 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end
# 134 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 135 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_TradeCenter::
# 136 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 137 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end
# 138 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"

# 139 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
FortreeCity_PokemonCenter_2F_EventScript_RecordCorner::
# 140 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 141 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	end

FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 109 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

FortreeCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 113 "data//maps/FortreeCity_PokemonCenter_2F/scripts.pory"
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
