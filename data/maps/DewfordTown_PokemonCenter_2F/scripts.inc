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
	end


DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 17 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_DEWFORD_TOWN_POKEMON_CENTER_2F
# 18 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 22 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 19 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto DewfordTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 28 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

DewfordTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 29 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace
	return


DewfordTown_PokemonCenter_2F_EventScript_Wallace::
# 34 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 35 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 36 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, DewfordTown_PokemonCenter_2F_EventScript_Wallace_2
# 41 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 46 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
DewfordTown_PokemonCenter_2F_EventScript_Wallace_1:
# 48 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 49 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 52 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	release
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_2:
# 37 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	msgbox DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 38 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto DewfordTown_PokemonCenter_2F_EventScript_Wallace_1


# 56 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 57 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 58 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_Colosseum::
# 59 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 60 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 61 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 62 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_TradeCenter::
# 63 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 64 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end
# 65 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"

# 66 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
DewfordTown_PokemonCenter_2F_EventScript_RecordCorner::
# 67 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 68 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	end

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 37 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

DewfordTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 41 "data//maps/DewfordTown_PokemonCenter_2F/scripts.pory"
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
