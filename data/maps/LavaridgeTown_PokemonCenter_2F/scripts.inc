# 1 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.byte 0

LavaridgeTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavaridgeTown_PokemonCenter_2F_OnTransition_2
LavaridgeTown_PokemonCenter_2F_OnTransition_1:
# 15 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
	return

LavaridgeTown_PokemonCenter_2F_OnTransition_2:
# 13 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_LAVARIDGE_BREAK_NURSE
	goto LavaridgeTown_PokemonCenter_2F_OnTransition_1


LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak::
# 19 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	lock
# 20 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 21 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0, MSGBOX_YESNO
# 22 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2
# 28 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_2, MSGBOX_DEFAULT
LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1:
# 30 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 31 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 32 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK, Common_Movement_FaceOriginalDirection
# 33 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK
# 34 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2:
# 23 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1, MSGBOX_DEFAULT
	goto LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1


LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 39 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F
# 40 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 44 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 41 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto LavaridgeTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 50 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

LavaridgeTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 51 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	goto FortreeCity_PokemonCenter_2F_EventScript_Wallace
	return


LavaridgeTown_PokemonCenter_2F_EventScript_Wallace::
# 56 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 57 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 58 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_2
# 63 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 68 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_1:
# 70 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 71 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 72 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 73 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 74 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_2:
# 59 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 60 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_1


# 78 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 79 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 80 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 81 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum::
# 82 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 83 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 84 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 85 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter::
# 86 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 87 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 88 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 89 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner::
# 90 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 91 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0:
# 21 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Oh, hey.\p"
	.string "Did you want to hear about the\n"
	.string "LAVARBOR TUNNEL again?$"

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1:
# 23 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Well, there were plans for a tunnel from\n"
	.string "here to FALLARBOR TOWN,\l"
	.string "but the project was cancelled…\p"
	.string "They never made much progress…\p"
	.string "Apparently the project leader spent\n"
	.string "too much time at the sauna instead of\l"
	.string "directing the dig.\p"
	.string "He's still there almost all the time!\n"
	.string "After they cancelled the project,\l"
	.string "he retired here to LAVARIDGE.$"

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_2:
# 28 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, you're right, it's pretty boring…$"

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 59 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

LavaridgeTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 63 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
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
