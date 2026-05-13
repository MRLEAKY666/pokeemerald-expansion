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
	return


VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 16 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F
# 17 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 21 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 18 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto VerdanturfTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 27 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

VerdanturfTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 28 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto VerdanturfTown_PokemonCenter_2F_EventScript_Wallace
	return


VerdanturfTown_PokemonCenter_2F_EventScript_Wallace::
# 33 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 34 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 35 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2
# 40 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 45 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1:
# 47 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 48 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 51 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_2:
# 36 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 37 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_1


VerdanturfTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 56 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	release
	end


# 60 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 61 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 62 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 63 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_Colosseum::
# 64 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 65 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 66 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 67 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_TradeCenter::
# 68 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 69 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end
# 70 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"

# 71 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
VerdanturfTown_PokemonCenter_2F_EventScript_RecordCorner::
# 72 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 73 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	end

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 36 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

VerdanturfTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 40 "data//maps/VerdanturfTown_PokemonCenter_2F/scripts.pory"
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
