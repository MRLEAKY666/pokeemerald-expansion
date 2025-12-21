# 1 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FallarborTown_PokemonCenter_2F_OnLoad
# 6 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.byte 0

FallarborTown_PokemonCenter_2F_OnLoad::
# 14 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt FallarborTown_PokemonCenter_2F_OnLoad_2
	return

FallarborTown_PokemonCenter_2F_OnLoad_1:
# 15 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 2, 0, METATILE_PokemonCenter_Normal_Wall_Top, TRUE
# 16 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 3, 0, METATILE_PokemonCenter_Normal_Wall_Top, TRUE
# 17 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 4, 0, METATILE_PokemonCenter_Normal_Wall_Top, TRUE
# 18 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 2, 1, METATILE_PokemonCenter_Bookshelf_Top_L, TRUE
# 19 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 3, 1, METATILE_PokemonCenter_Bookshelf_Top_R, TRUE
# 20 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 4, 1, METATILE_PokemonCenter_Normal_Wall_Mid, TRUE
# 21 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 2, 2, METATILE_PokemonCenter_Bookshelf_Bottom_L, FALSE
# 22 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setmetatile 3, 2, METATILE_PokemonCenter_Bookshelf_Bottom_R, FALSE
	return

FallarborTown_PokemonCenter_2F_OnLoad_2:
# 14 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, FallarborTown_PokemonCenter_2F_OnLoad_1
	return


FallarborTown_PokemonCenter_2F_OnTransition::
# 27 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac
	return


FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac::
# 31 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ge FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1
# 34 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4
FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3:
# 38 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1:
# 32 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2:
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4:
# 34 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2
	goto FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3


FallarborTown_PokemonCenter_2F_EventScript_FossilManiac::
# 44 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	lock
# 45 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 46 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0, MSGBOX_DEFAULT
# 47 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 48 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 45
# 49 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	message FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1
# 50 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmessage
# 51 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 30
# 52 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2, MSGBOX_DEFAULT
# 53 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 54 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 55 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	end


# 59 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 60 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 61 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 62 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_Colosseum::
# 63 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 64 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 65 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 66 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_TradeCenter::
# 67 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 68 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 69 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 70 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_RecordCorner::
# 71 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 72 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0:
# 46 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "FOSSIL MANIAC: I'm going to be opening\n"
	.string "up a hole in the wall here.$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1:
# 49 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "What?$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2:
# 52 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, yeah,\l"
	.string "I cleared it with the staff…$"
