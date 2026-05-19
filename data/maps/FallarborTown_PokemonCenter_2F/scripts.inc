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
# 30 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	return


FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac::
# 34 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ge FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1
# 37 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4
FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3:
# 41 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_1:
# 35 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_5
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2:
	return

FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_4:
# 37 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_2
	goto FallarborTown_PokemonCenter_2F_EventScript_ShowHideFossilManiac_3


FallarborTown_PokemonCenter_2F_EventScript_FossilManiac::
# 47 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	lock
# 48 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 49 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0, MSGBOX_DEFAULT
# 50 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 51 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 45
# 52 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	message FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1
# 53 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmessage
# 54 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 30
# 55 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2, MSGBOX_DEFAULT
# 56 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 57 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 58 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	end


FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 63 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 64 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 68 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 65 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto FallarborTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 74 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

FallarborTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 75 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
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
# 93 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 81 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 84 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 87 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 90 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 99 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 121 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 100 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 103 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 106 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 109 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 112 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 115 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 118 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto FallarborTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 127 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 128 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 129 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 131 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 133 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 135 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 140 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	return

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 130 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 132 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 134 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 136 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto FallarborTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


FallarborTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 144 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 145 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 146 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	return


FallarborTown_PokemonCenter_2F_EventScript_Wallace::
# 150 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 151 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 152 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, FallarborTown_PokemonCenter_2F_EventScript_Wallace_2
# 157 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 162 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
FallarborTown_PokemonCenter_2F_EventScript_Wallace_1:
# 164 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 165 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 166 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 167 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 168 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	release
	end

FallarborTown_PokemonCenter_2F_EventScript_Wallace_2:
# 153 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 154 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto FallarborTown_PokemonCenter_2F_EventScript_Wallace_1


# 172 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 173 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 174 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 175 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_Colosseum::
# 176 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 177 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 178 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 179 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_TradeCenter::
# 180 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 181 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end
# 182 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"

# 183 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
FallarborTown_PokemonCenter_2F_EventScript_RecordCorner::
# 184 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 185 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	end

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_0:
# 49 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "FOSSIL MANIAC: I'm going to be opening\n"
	.string "up a hole in the wall here.$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_1:
# 52 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "What?$"

FallarborTown_PokemonCenter_2F_EventScript_FossilManiac_Text_2:
# 55 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "Yeah, yeah,\l"
	.string "I cleared it with the staff…$"

FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 153 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

FallarborTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 157 "data//maps/FallarborTown_PokemonCenter_2F/scripts.pory"
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
