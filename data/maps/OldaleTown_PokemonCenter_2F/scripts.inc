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
	end


OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_ROAMING_WALLACE, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 23 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 20 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
# 42 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_B
OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_2:
# 30 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SCIENTIST_1
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_3:
# 33 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_MAN_4
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_4:
# 36 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_HIKER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_5:
# 39 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_CAMPER
	goto OldaleTown_PokemonCenter_2F_EventScript_SetTrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 48 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_OBJ_GFX_ID_B
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_SCIENTIST_1, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_MAN_4, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4
# 54 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_HIKER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5
# 56 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case OBJ_EVENT_GFX_CAMPER, OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6
OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1:
# 59 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 60 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_3:
# 51 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_TMTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_4:
# 53 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_BallTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_5:
# 55 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_SurvivalItemTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1

OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_6:
# 57 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call RoamingTraders_EventScript_HerbTrader
	goto OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 66 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace
	return


OldaleTown_PokemonCenter_2F_EventScript_Wallace::
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 72 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 73 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, OldaleTown_PokemonCenter_2F_EventScript_Wallace_2
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
OldaleTown_PokemonCenter_2F_EventScript_Wallace_1:
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 87 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 88 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_Wallace_2:
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 75 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace_1


# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 97 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 98 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 105 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 111 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 115 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 116 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 119 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 307 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 308 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 309 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 310 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 311 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 312 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 313 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 314 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 315 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 316 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 317 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 318 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 319 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 320 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 321 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 322 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 323 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 324 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 325 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 326 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 327 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 328 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 329 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 330 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 331 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 332 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 333 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 334 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 335 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 336 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 337 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 338 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 339 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 340 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 341 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 342 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 343 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 344 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 345 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 346 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 347 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 348 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 349 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 350 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 351 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 352 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 353 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 354 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 355 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 356 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 357 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 358 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 359 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 360 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 361 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 362 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 363 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 364 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 365 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 366 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 367 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 368 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 369 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 370 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 371 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 372 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 373 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 374 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 375 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 376 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 377 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 378 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 379 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 380 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 381 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 382 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 383 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 384 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 385 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 386 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 387 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 388 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 389 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 390 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 391 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 392 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
