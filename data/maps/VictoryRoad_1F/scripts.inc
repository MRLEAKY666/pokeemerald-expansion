# 1 "data//maps/VictoryRoad_1F/scripts.pory"

# 2 "data//maps/VictoryRoad_1F/scripts.pory"
.set LOCALID_WALLY_ENTRANCE, 4
# 3 "data//maps/VictoryRoad_1F/scripts.pory"

# 4 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_MapScripts::
# 5 "data//maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
# 6 "data//maps/VictoryRoad_1F/scripts.pory"
	.byte 0
# 7 "data//maps/VictoryRoad_1F/scripts.pory"

# 8 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnTransition:
# 9 "data//maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 10 "data//maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
# 11 "data//maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
# 12 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 13 "data//maps/VictoryRoad_1F/scripts.pory"

# 14 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
# 15 "data//maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
# 16 "data//maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 17 "data//maps/VictoryRoad_1F/scripts.pory"
	return
# 18 "data//maps/VictoryRoad_1F/scripts.pory"

# 19 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
# 20 "data//maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
# 21 "data//maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 22 "data//maps/VictoryRoad_1F/scripts.pory"
	return
# 23 "data//maps/VictoryRoad_1F/scripts.pory"

# 24 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger1::
# 25 "data//maps/VictoryRoad_1F/scripts.pory"
	lockall
# 26 "data//maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 27 "data//maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 28 "data//maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
# 29 "data//maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 30 "data//maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 31 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 32 "data//maps/VictoryRoad_1F/scripts.pory"

# 33 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger2::
# 34 "data//maps/VictoryRoad_1F/scripts.pory"
	lockall
# 35 "data//maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 36 "data//maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 37 "data//maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
# 38 "data//maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 39 "data//maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 40 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 41 "data//maps/VictoryRoad_1F/scripts.pory"

# 42 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyEntranceBattle::
# 43 "data//maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 44 "data//maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 45 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
# 46 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
# 47 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
# 48 "data//maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 49 "data//maps/VictoryRoad_1F/scripts.pory"
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
# 50 "data//maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
# 51 "data//maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
# 52 "data//maps/VictoryRoad_1F/scripts.pory"
	releaseall
# 53 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 54 "data//maps/VictoryRoad_1F/scripts.pory"

# 55 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer1:
# 56 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 57 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 58 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 59 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 60 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 61 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 62 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 63 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 64 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 65 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 66 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 67 "data//maps/VictoryRoad_1F/scripts.pory"
	step_end
# 68 "data//maps/VictoryRoad_1F/scripts.pory"

# 69 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer2:
# 70 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 71 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 72 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 73 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 74 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 75 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 76 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 77 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 78 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 79 "data//maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 80 "data//maps/VictoryRoad_1F/scripts.pory"
	step_end
# 81 "data//maps/VictoryRoad_1F/scripts.pory"

# 82 "data//maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
# 83 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_EntranceWally::
# 84 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
# 85 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 86 "data//maps/VictoryRoad_1F/scripts.pory"

# 87 "data//maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears and remains at the exit after the Hall of Fame is entered
# 88 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_ExitWally::
# 89 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 90 "data//maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 91 "data//maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
# 92 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 93 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 94 "data//maps/VictoryRoad_1F/scripts.pory"

# 95 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RematchWally::
# 96 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 97 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 98 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 99 "data//maps/VictoryRoad_1F/scripts.pory"

# 100 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Edgar::
# 101 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
# 102 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
# 103 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 104 "data//maps/VictoryRoad_1F/scripts.pory"

# 105 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Albert::
# 106 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
# 107 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
# 108 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 109 "data//maps/VictoryRoad_1F/scripts.pory"

# 110 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Hope::
# 111 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
# 112 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
# 113 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 114 "data//maps/VictoryRoad_1F/scripts.pory"

# 115 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Quincy::
# 116 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
# 117 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
# 118 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 119 "data//maps/VictoryRoad_1F/scripts.pory"

# 120 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Katelynn::
# 121 "data//maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
# 122 "data//maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
# 123 "data//maps/VictoryRoad_1F/scripts.pory"
	end
# 124 "data//maps/VictoryRoad_1F/scripts.pory"

# 125 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
# 126 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: Hi! {PLAYER}!\p"
# 127 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I bet you're surprised to see me here!\p"
# 128 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I made it all the way here, and it's\n"
# 129 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "all thanks to you!\p"
# 130 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, losing to you that time\n"
# 131 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "made me stronger!\p"
# 132 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "But I'm not going to lose anymore!\p"
# 133 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to win! For the POKéMON who\n"
# 134 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "gave me courage and strength!\p"
# 135 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 136 "data//maps/VictoryRoad_1F/scripts.pory"

# 137 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyEntranceDefeat:
# 138 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 139 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 140 "data//maps/VictoryRoad_1F/scripts.pory"

# 141 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostEntranceBattle:
# 142 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: I couldn't beat you today,\n"
# 143 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, but one of these days, I'll\l"
# 144 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "catch up to you!$"
# 145 "data//maps/VictoryRoad_1F/scripts.pory"

# 146 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyIntro:
# 147 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: Hi! {PLAYER}!\p"
# 148 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I've gotten stronger since that last\n"
# 149 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "time! I wanted to show you, {PLAYER}!\p"
# 150 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 151 "data//maps/VictoryRoad_1F/scripts.pory"

# 152 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyDefeat:
# 153 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 154 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 155 "data//maps/VictoryRoad_1F/scripts.pory"

# 156 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostBattle:
# 157 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "WALLY: I couldn't beat you this time,\n"
# 158 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "too… But one of these days, {PLAYER},\l"
# 159 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to catch up to you…\p"
# 160 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "And challenge the POKéMON LEAGUE!$"
# 161 "data//maps/VictoryRoad_1F/scripts.pory"

# 162 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarIntro:
# 163 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I've made it this far a couple times,\n"
# 164 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "but the last stretch is so long…$"
# 165 "data//maps/VictoryRoad_1F/scripts.pory"

# 166 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarDefeat:
# 167 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "My dream ends here again…$"
# 168 "data//maps/VictoryRoad_1F/scripts.pory"

# 169 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarPostBattle:
# 170 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "You've made it this far. Keep the\n"
# 171 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "momentum going and become the\l"
# 172 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "CHAMPION! If anyone can, it's you!$"
# 173 "data//maps/VictoryRoad_1F/scripts.pory"

# 174 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertIntro:
# 175 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I didn't come all this way to lose now.\n"
# 176 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "That possibility doesn't exist!$"
# 177 "data//maps/VictoryRoad_1F/scripts.pory"

# 178 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertDefeat:
# 179 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Impossible…\n"
# 180 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I lost?$"
# 181 "data//maps/VictoryRoad_1F/scripts.pory"

# 182 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertPostBattle:
# 183 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I lost here…\p"
# 184 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "That means I lack the qualifications\n"
# 185 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "to become the CHAMPION…$"
# 186 "data//maps/VictoryRoad_1F/scripts.pory"

# 187 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeIntro:
# 188 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "This seemingly infinite and harsh road\n"
# 189 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "lives up to its name of VICTORY.$"
# 190 "data//maps/VictoryRoad_1F/scripts.pory"

# 191 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeDefeat:
# 192 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Your battle style is fantastic…$"
# 193 "data//maps/VictoryRoad_1F/scripts.pory"

# 194 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopePostBattle:
# 195 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "You seem to have the potential for\n"
# 196 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "becoming the CHAMPION.$"
# 197 "data//maps/VictoryRoad_1F/scripts.pory"

# 198 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyIntro:
# 199 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "What is the VICTORY ROAD?\n"
# 200 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I'll tell you if you win!$"
# 201 "data//maps/VictoryRoad_1F/scripts.pory"

# 202 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyDefeat:
# 203 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Okay!\n"
# 204 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Well done!$"
# 205 "data//maps/VictoryRoad_1F/scripts.pory"

# 206 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyPostBattle:
# 207 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Getting through here safely--that's\n"
# 208 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "the final test for any TRAINER aiming\l"
# 209 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "to become the POKéMON CHAMPION.\p"
# 210 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "That's why it's called the VICTORY\n"
# 211 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "ROAD.$"
# 212 "data//maps/VictoryRoad_1F/scripts.pory"

# 213 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnIntro:
# 214 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "I have nothing to say to anyone\n"
# 215 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "that's come this far. Come on!$"
# 216 "data//maps/VictoryRoad_1F/scripts.pory"

# 217 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnDefeat:
# 218 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "This is a disgrace…$"
# 219 "data//maps/VictoryRoad_1F/scripts.pory"

# 220 "data//maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnPostBattle:
# 221 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "Humph, go right on ahead.\n"
# 222 "data//maps/VictoryRoad_1F/scripts.pory"
	.string "See if I care.$"
