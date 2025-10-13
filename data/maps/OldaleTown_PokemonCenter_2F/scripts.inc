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
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
# 7 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.byte 0
# 8 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 9 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
@ The below 3 are unused and leftover from RS
# 10 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_Colosseum::
# 11 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_Colosseum
# 12 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 13 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 14 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_TradeCenter::
# 15 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_TradeCenter
# 16 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 17 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 18 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_RecordCorner::
# 19 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call CableClub_EventScript_RecordCorner
# 20 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 21 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 22 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_BugLass::
# 23 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	lock
# 24 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	faceplayer
# 25 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 26 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_ge VAR_OLDALE_BUG_KILLING, 2, OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling
# 27 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 1, OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling
# 28 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	call_if_eq VAR_OLDALE_BUG_KILLING, 0, OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling
# 29 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 30 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 31 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 32 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 33 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 34 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_SucceededForBugKilling::
# 35 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling, MSGBOX_DEFAULT
# 36 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 37 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	
# 38 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 39 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 40 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 41 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth
# 42 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest
# 43 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth
# 44 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 45 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 46 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 47 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneySouth::
# 48 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 51 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 53 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 54 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 55 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 56 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 57 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 58 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 59 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 60 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 62 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyWest::
# 63 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest
# 64 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 66 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 67 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 68 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 69 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 70 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 72 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 73 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 75 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 76 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_CountMoneyNorth::
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 87 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 88 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 90 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 91 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 92 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 97 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 98 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest
# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneySouth::
# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 105 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 111 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 115 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 116 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyWest::
# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 119 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMoneyNorth::
# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	getobjectfacingdirection LOCALID_OLDALE_PKMNCENTER_BUGLASS, VAR_RESULT
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	switch VAR_RESULT
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_SOUTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth
# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_WEST, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	case DIR_NORTH, OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneySouth::
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 163 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 164 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 165 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 166 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 167 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 168 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 169 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 170 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 171 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyWest::
# 172 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest
# 173 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 174 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 175 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 176 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 177 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 178 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 179 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 180 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 181 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 182 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 183 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 184 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_GiveMaxMoneyNorth::
# 185 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth
# 186 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 187 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 188 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 189 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 190 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 191 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 192 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 193 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 194 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 195 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 196 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 197 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 198 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 199 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 200 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 201 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 202 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 203 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 204 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 205 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 206 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 207 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 208 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 209 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 210 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyWest:
# 211 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 212 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 213 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 214 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 215 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 216 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 217 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 218 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_right
# 219 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 220 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 221 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 222 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 223 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoneyNorth:
# 224 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 225 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 226 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 227 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 228 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 229 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 230 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 231 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_down
# 232 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 233 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 234 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 235 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 236 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneySouth:
# 237 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 238 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 239 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 240 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyWest:
# 241 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_left
# 242 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 243 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 244 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoneyNorth:
# 245 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_up
# 246 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 247 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 248 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 249 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 250 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 251 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 252 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 253 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 254 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 255 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 256 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 257 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 258 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 259 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 260 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 261 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 262 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 263 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 264 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 265 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 266 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 267 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 268 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 269 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 270 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 271 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 272 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 273 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 274 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 275 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 276 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 277 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 278 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 279 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 280 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 281 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 282 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 283 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 284 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 285 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 286 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 287 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 288 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 289 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 290 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 291 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 292 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 293 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 294 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 295 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 296 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 297 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 298 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 299 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 300 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 301 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 302 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 303 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 304 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 305 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 306 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"
