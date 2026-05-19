# 1 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
SlateportCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	.byte 0

SlateportCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 14 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 20 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto SlateportCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


SlateportCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 30 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

SlateportCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 31 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	goto SlateportCity_PokemonCenter_2F_EventScript_Wallace
	return


SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 49 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 37 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 40 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 43 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 46 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto SlateportCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 55 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
# 0 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 77 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 56 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 59 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 62 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 65 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 68 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 71 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 74 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto SlateportCity_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 83 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 84 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 85 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 87 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 89 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 91 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 96 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	release
	return

SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 86 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 88 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 90 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 92 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto SlateportCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


SlateportCity_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 100 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 101 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 102 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	release
	return


SlateportCity_PokemonCenter_2F_EventScript_Wallace::
# 106 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 107 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 108 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, SlateportCity_PokemonCenter_2F_EventScript_Wallace_2
# 113 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	msgbox SlateportCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 118 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
SlateportCity_PokemonCenter_2F_EventScript_Wallace_1:
# 120 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 121 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 122 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 123 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 124 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	release
	end

SlateportCity_PokemonCenter_2F_EventScript_Wallace_2:
# 109 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	msgbox SlateportCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 110 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto SlateportCity_PokemonCenter_2F_EventScript_Wallace_1


# 128 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"

# 129 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"

# 130 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 131 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
SlateportCity_PokemonCenter_2F_EventScript_Colosseum::
# 132 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 133 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	end
# 134 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"

# 135 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
SlateportCity_PokemonCenter_2F_EventScript_TradeCenter::
# 136 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 137 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	end
# 138 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"

# 139 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
SlateportCity_PokemonCenter_2F_EventScript_RecordCorner::
# 140 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 141 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	end

SlateportCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 109 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

SlateportCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 113 "data//maps/SlateportCity_PokemonCenter_2F/scripts.pory"
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
