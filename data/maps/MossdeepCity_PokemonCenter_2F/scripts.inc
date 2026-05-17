# 1 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_MapScripts::
# 3 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_2F_OnTransition
# 7 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.byte 0

MossdeepCity_PokemonCenter_2F_OnTransition::
# 12 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	end


MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
# 19 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto MossdeepCity_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


MossdeepCity_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 29 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

MossdeepCity_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 30 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	goto MossdeepCity_PokemonCenter_2F_EventScript_Wallace
	return


MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
# 0 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
# 0 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
# 0 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
# 0 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 48 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 36 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 39 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 42 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 45 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto MossdeepCity_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 54 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	faceplayer
# 55 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 56 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 58 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 60 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 62 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6
MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 65 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 66 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 67 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	release
	return

MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 57 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 59 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 61 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1

MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 63 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto MossdeepCity_PokemonCenter_2F_EventScript_TrRoamingNPC_1


MossdeepCity_PokemonCenter_2F_EventScript_Wallace::
# 71 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 72 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 73 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, MossdeepCity_PokemonCenter_2F_EventScript_Wallace_2
# 78 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 83 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
MossdeepCity_PokemonCenter_2F_EventScript_Wallace_1:
# 85 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	closemessage
# 86 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	delay 15
# 87 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 88 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	waitmovement
# 89 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_Wallace_2:
# 74 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 75 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto MossdeepCity_PokemonCenter_2F_EventScript_Wallace_1


# 93 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 95 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 96 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_Colosseum::
# 97 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 98 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_TradeCenter::
# 101 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 102 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 103 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 104 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_RecordCorner::
# 105 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 106 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 107 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 108 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_EventScript_Woman5::
# 109 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	msgbox MossdeepCity_PokemonCenter_2F_Text_Woman5, MSGBOX_NPC
# 110 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	end
# 111 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"

# 112 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
MossdeepCity_PokemonCenter_2F_Text_Woman5:
# 113 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "If I win a whole lot of link battles\n"
# 114 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "and show everyone how good I am,\l"
# 115 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "I might get a fan following!$"

MossdeepCity_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 74 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

MossdeepCity_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 78 "data//maps/MossdeepCity_PokemonCenter_2F/scripts.pory"
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
