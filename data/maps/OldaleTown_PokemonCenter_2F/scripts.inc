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
	call OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1
	end


OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1::
# 17 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	checkroamingnpcatlocation FLAG_PKMN_CNTR_WALLACE, MAP_OLDALE_TOWN_POKEMON_CENTER_2F
# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1_2
# 22 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setflag FLAG_TEMP_A
OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1_1:
	return

OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1_2:
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_WALLACE
	goto OldaleTown_PokemonCenter_2F_EventScript_SetRoamingNPC1_1


# 27 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 28 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 29 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 30 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 31 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 32 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 33 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 34 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 35 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 36 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 37 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 38 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 39 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 40 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 41 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 42 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 43 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 44 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 45 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 46 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 47 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 48 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 51 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 53 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 54 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 55 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 56 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 57 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 58 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 59 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 60 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 62 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 63 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 64 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 66 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 67 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 68 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 69 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 70 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 72 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 73 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 75 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 76 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 87 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 88 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 90 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 91 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 92 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 97 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 98 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 105 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 111 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 115 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 116 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 119 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 307 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 308 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 309 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 310 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 311 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 312 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 313 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 314 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 315 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 316 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 317 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 318 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 319 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 320 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 321 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 322 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 323 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 324 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 325 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 326 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"
