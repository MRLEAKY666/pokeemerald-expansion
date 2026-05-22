# 1 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 2 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_MapScripts::
# 3 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
# 4 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
# 5 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
# 6 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_2F_OnTransition
# 7 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.byte 0

OldaleTown_PokemonCenter_2F_OnTransition::
# 12 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC
# 13 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC
# 14 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC
	end


OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_3
# 26 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_SCIENTIST_2
	goto OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_3:
# 23 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_SCIENTIST, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BREEDER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_HIKER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_RANGER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5
# 45 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 33 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 36 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 39 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 42 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
# 70 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 55 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 58 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 64 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 67 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 76 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return


OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_A
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_WALLACE, OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_3
# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_2, OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_4
OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_3:
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace
	goto OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_4:
# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_AfterWhiteoutTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_Wallace::
# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, OldaleTown_PokemonCenter_2F_EventScript_Wallace_2
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
OldaleTown_PokemonCenter_2F_EventScript_Wallace_1:
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_Wallace_2:
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace_1


# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 307 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 308 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 309 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 310 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 311 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 312 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 313 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 314 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 315 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 316 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 317 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 318 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 319 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 320 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 321 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 322 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 323 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 324 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 325 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 326 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 327 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 328 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 329 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 330 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 331 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 332 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 333 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 334 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 335 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 336 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 337 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 338 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 339 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 340 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 341 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 342 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 343 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 344 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 345 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 346 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 347 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 348 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 349 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 350 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 351 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 352 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 353 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 354 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 355 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 356 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 357 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 358 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 359 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 360 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 361 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 362 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 363 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 364 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 365 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 366 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 367 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 368 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 369 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 370 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 371 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 372 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 373 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 374 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 375 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 376 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 377 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 378 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 379 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 380 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 381 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 382 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 383 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 384 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 385 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 386 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 387 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 388 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 389 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 390 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 391 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 392 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 393 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 394 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 395 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 396 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 397 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 398 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 399 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 400 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 401 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 402 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 403 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 404 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 405 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 406 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 407 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 408 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 409 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 410 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 411 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 412 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 413 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 414 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 415 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 416 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 417 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 418 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 419 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 420 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 421 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 422 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 423 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 424 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 425 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 426 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 427 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 428 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 429 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 430 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
