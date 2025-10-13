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
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_CountMoney
# 38 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 39 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 40 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 41 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 42 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_FU_ZAKU
# 43 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 44 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 45 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	showmoneybox 0, 0
# 46 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	calcbugmoney
# 47 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_le VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal
# 48 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	goto_if_gt VAR_OLDALE_BUG_KILLING, 1000, OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax
# 49 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 50 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 51 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingNormal::
# 52 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKilling, MSGBOX_DEFAULT
# 53 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 54 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 55 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoney
# 56 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 57 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 58 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 59 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 60 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKilling, MSGBOX_DEFAULT
# 61 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 62 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 63 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 64 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 65 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 66 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 67 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_PayBugKillingMax::
# 68 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 69 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_ExclamationMark
# 70 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_PIN
# 71 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax, MSGBOX_DEFAULT
# 72 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 73 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	playse SE_SHOP
# 74 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	updatemoneybox
# 75 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, OldaleTown_PokemonCenter_2F_Movement_GiveMoney
# 76 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement
# 77 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 20
# 78 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitse
# 79 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	hidemoneybox
# 80 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax, MSGBOX_DEFAULT
# 81 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 82 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	applymovement LOCALID_OLDALE_PKMNCENTER_BUGLASS, Common_Movement_FaceOriginalDirection
# 83 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	waitmovement 0
# 84 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	release
# 85 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	end
# 86 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 87 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_CountMoney:
# 88 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_away_player
# 89 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 90 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 91 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 92 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 93 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 94 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 95 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_faster_up
# 96 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay_16
# 97 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	face_player
# 98 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 99 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 100 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Movement_GiveMoney:
# 101 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	walk_in_place_down
# 102 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	step_end
# 103 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 104 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_ContinueBugKilling::
# 105 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling, MSGBOX_DEFAULT
# 106 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 107 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 108 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 109 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 110 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_EventScript_StartBugKilling::
# 111 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	msgbox OldaleTown_PokemonCenter_2F_Text_StartBugKilling, MSGBOX_DEFAULT
# 112 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	closemessage
# 113 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	setvar VAR_OLDALE_BUG_KILLING, 1
# 114 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	delay 5
# 115 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	return
# 116 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 117 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKilling:
# 118 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 119 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 120 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 121 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_KeepBugKillingMax:
# 122 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "It's hard to believe, but I bet\n"
# 123 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "there are still lots of BUGS out there.\p"
# 124 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "If you kill more wild BUG POKéMON,\n"
# 125 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "come back and let me know!$"
# 126 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 127 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKilling:
# 128 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You killed {STR_VAR_1} BUG POKéMON…\n"
# 129 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "So that comes out to ¥{STR_VAR_2}, right?\p"
# 130 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh don't worry, I've got a lot!\n"
# 131 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Here you go!$"
# 132 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 133 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_PayBugKillingMax:
# 134 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "WOW!!\p"
# 135 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "You really killed a TON of\n" 
# 136 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "BUG POKéMON!!\p"
# 137 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Look, I have a lot of money, and I'm\n"
# 138 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "actually SO grateful…\p"
# 139 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But the most I can give you is\n"
# 140 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "¥75,000.$"
# 141 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 142 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_SucceededBugKilling:
# 143 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Oh! You really killed some BUG\n"
# 144 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "POKéMON for me?\p"
# 145 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Thank you so much!!\l"
# 146 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "But I guess you were really just\n"
# 147 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "after the reward I promised, right?$"
# 148 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 149 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_ContinueBugKilling:
# 150 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I'll pay you ¥40 for every wild BUG you\n"
# 151 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "kill on ROUTE 101, 102, or 103!\p"
# 152 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Please help!$"
# 153 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"

# 154 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
OldaleTown_PokemonCenter_2F_Text_StartBugKilling:
# 155 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "I can't stand all the BUG POKéMON\n"
# 156 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "out here in the country!\p"
# 157 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Are you just starting out traveling?\l"
# 158 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "Tell you what- I'll give you ¥40 for\n"
# 159 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "each wild BUG you kill around here.\p"
# 160 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "That way you'll have a little more\n"
# 161 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "for supplies, and hopefully I'll see\l"
# 162 "data//maps/OldaleTown_PokemonCenter_2F/scripts.pory"
	.string "less of these awful BUGS!$"
