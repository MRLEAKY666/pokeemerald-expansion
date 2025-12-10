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
	goto_if_eq LavaridgeTown_PokemonCenter_2F_OnTransition_1
	return

LavaridgeTown_PokemonCenter_2F_OnTransition_1:
# 13 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_LAVARIDGE_BREAK_NURSE
	return


LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak::
# 18 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	lock
# 19 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 20 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0, MSGBOX_YESNO
# 21 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2
# 27 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_2, MSGBOX_DEFAULT
LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1:
# 29 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 30 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 31 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK, Common_Movement_FaceOriginalDirection
# 32 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	waitmovement LOCALID_LAVARIDGE_PKMNCNTR_NURSE_ON_BREAK
# 33 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	release
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_2:
# 22 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	msgbox LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1, MSGBOX_DEFAULT
	goto LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_1


# 37 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 38 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 39 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 40 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_Colosseum::
# 41 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 42 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 43 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 44 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_TradeCenter::
# 45 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 46 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end
# 47 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"

# 48 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
LavaridgeTown_PokemonCenter_2F_EventScript_RecordCorner::
# 49 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 50 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	end

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_0:
# 20 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Oh, hey.\p"
	.string "Did you want to hear about the\n"
	.string "LAVARBOR TUNNEL again?$"

LavaridgeTown_PokemonCenter_2F_EventScript_NurseOnBreak_Text_1:
# 22 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
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
# 27 "data//maps/LavaridgeTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, you're right, it's pretty boring…$"
