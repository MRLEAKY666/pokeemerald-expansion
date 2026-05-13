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
	end


OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC::
# 17 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2
# 22 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_2:
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto OldaleTown_PokemonCenter_2F_EventScript_SetSpRoamingNPC_1


OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC::
# 28 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1
	return

OldaleTown_PokemonCenter_2F_EventScript_SpRoamingNPC_1:
# 29 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace
	return


OldaleTown_PokemonCenter_2F_EventScript_Wallace::
# 34 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 35 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 36 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_set FLAG_MET_WALLACE, OldaleTown_PokemonCenter_2F_EventScript_Wallace_2
# 41 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 46 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_MET_WALLACE
OldaleTown_PokemonCenter_2F_EventScript_Wallace_1:
# 48 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 15
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
# 51 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_Wallace_2:
# 37 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0, MSGBOX_DEFAULT
# 38 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call SootopolisCity_House3_EventScript_WallaceCheckBeasts
	goto OldaleTown_PokemonCenter_2F_EventScript_Wallace_1


OldaleTown_PokemonCenter_2F_EventScript_TrRoamingNPC::
# 57 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
	end


# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 62 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 63 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 64 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 66 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 67 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 68 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 69 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 70 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 72 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 73 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 75 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 76 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 87 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 88 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 90 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 91 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 92 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 97 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 98 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 105 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 111 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 115 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 116 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 119 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 307 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 308 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 309 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 310 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 311 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 312 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 313 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 314 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 315 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 316 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 317 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 318 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 319 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 320 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 321 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 322 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 323 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 324 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 325 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 326 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 327 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 328 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 329 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 330 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 331 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 332 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 333 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 334 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 335 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 336 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 337 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 338 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 339 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 340 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 341 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 342 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 343 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 344 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 345 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 346 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 347 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 348 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 349 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 350 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 351 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 352 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 353 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 354 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 355 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 356 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 357 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 358 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 359 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 360 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_0:
# 37 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WALLACE: Good to see you again,\n"
	.string "{PLAYER}.$"

OldaleTown_PokemonCenter_2F_EventScript_Wallace_Text_1:
# 41 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
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
