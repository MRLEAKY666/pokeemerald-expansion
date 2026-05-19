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
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 20 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 24 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 21 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
# 43 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 31 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 34 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 37 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 40 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC::
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_POST_WHITEOUT, OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2
	checkroamingnpcatlocation FLAG_ROAMING_PSYCHIC, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3
	checkroamingnpcatlocation FLAG_ROAMING_BUG_CATCHER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4
	checkroamingnpcatlocation FLAG_ROAMING_YOUNGSTER, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5
	checkroamingnpcatlocation FLAG_ROAMING_HEX_MANIAC, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_F, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7
	checkroamingnpcatlocation FLAG_ROAMING_TRIATHLETE_M, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 0 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_C
OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_2:
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_3:
# 53 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_LASS
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_4:
# 56 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_BUG_CATCHER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_5:
# 59 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_YOUNGSTER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_6:
# 62 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_HEX_MANIAC
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_7:
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_8:
# 68 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	goto OldaleTown_PokemonCenter_2F_EventScript_SetPkmnTrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 90 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_PkmnTrRoamingNPC::
# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_RoamingMonTrader
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return


OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace
	return


OldaleTown_PokemonCenter_2F_EventScript_Wallace::
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, OldaleTown_PokemonCenter_2F_EventScript_Wallace_2
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
OldaleTown_PokemonCenter_2F_EventScript_Wallace_1:
# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_Wallace_2:
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace_1


# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 307 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 308 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 309 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 310 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 311 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 312 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 313 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 314 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 315 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 316 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 317 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 318 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 319 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 320 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 321 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 322 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 323 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 324 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 325 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 326 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 327 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 328 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 329 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 330 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 331 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 332 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 333 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 334 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 335 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 336 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 337 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 338 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 339 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 340 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 341 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 342 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 343 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 344 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 345 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 346 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 347 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 348 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 349 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 350 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 351 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 352 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 353 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 354 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 355 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 356 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 357 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 358 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 359 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 360 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 361 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 362 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 363 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 364 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 365 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 366 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 367 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 368 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 369 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 370 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 371 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 372 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 373 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 374 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 375 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 376 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 377 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 378 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 379 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 380 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 381 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 382 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 383 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 384 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 385 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 386 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 387 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 388 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 389 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 390 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 391 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 392 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 393 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 394 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 395 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 396 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 397 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 398 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 399 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 400 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 401 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 402 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 403 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 404 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 405 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 406 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 407 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 408 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 409 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 410 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 411 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 412 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 413 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 414 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 415 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 416 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 417 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 418 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 419 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 420 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 421 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 422 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 423 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 424 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 425 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 426 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 427 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
