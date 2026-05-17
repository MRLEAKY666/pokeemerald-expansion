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
# 28 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 29 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
	return


FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac::
# 33 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ge FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1
# 36 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4
FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3:
# 40 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1:
# 34 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2:
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4:
# 36 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2
	goto FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3


FallarborTown_PokemonCenter_2F_EventScript_FossilManiac::
# 46 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	lock
# 47 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 48 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0, MSGBOX_DEFAULT
# 49 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 50 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 45
# 51 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	message FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1
# 52 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmessage
# 53 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 30
# 54 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2, MSGBOX_DEFAULT
# 55 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 56 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 57 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	end


FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 62 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 63 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 67 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 64 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 73 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 74 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto FallarborTown_PokemonCenter_2F_EventScript_Wallace
	return


FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 92 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 80 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 83 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 86 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 89 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 98 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 99 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 100 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 102 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 104 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 106 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 111 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	return

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 101 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 103 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 105 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 107 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_Wallace::
# 115 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 116 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 117 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, FallarborTown_PokemonCenter_2F_EventScript_Wallace_2
# 122 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 127 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
FallarborTown_PokemonCenter_2F_EventScript_Wallace_1:
# 129 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 130 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 131 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 132 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 133 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_Wallace_2:
# 118 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 119 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto FallarborTown_PokemonCenter_2F_EventScript_Wallace_1


# 137 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 138 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 139 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 140 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_Colosseum::
# 141 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 142 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 143 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 144 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_TradeCenter::
# 145 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 146 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 147 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 148 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_RecordCorner::
# 149 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 150 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0:
# 48 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "FOSSIL MANIAC: I'm going to be opening\n"
	.string "up a hole in the wall here.$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1:
# 51 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "What?$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2:
# 54 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, yeah,\l"
	.string "I cleared it with the staff…$"

FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 118 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 122 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
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
