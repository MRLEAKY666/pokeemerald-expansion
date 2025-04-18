# 1 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 2 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_MOM, 1
# 3 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL_MOM, 4
# 4 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 6 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_MapScripts::
# 7 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
# 8 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
# 9 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
# 10 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.byte 0
# 11 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 12 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnLoad:
# 13 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
# 14 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
# 15 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 16 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 17 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
# 18 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 19 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
# 20 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 21 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 22 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
# 23 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	checkplayergender
# 24 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
# 25 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 26 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 27 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
# 28 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
# 29 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 30 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 31 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnTransition:
# 32 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
# 33 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
# 34 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
# 35 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 36 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 37 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
# 38 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 8, 4
# 39 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 40 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 41 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 42 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
# 43 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 4, 5
# 44 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 45 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 46 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 47 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
# 48 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 9, 8
# 49 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 50 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 51 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 52 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 53 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
# 54 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnFrame:
# 55 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
# 56 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
# 57 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
# 58 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
# 59 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 60 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.2byte 0
# 61 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 62 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
# 63 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 64 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 65 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 66 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 67 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 68 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 69 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
# 70 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 71 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 72 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 73 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 74 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
# 75 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 76 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 77 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 78 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
# 79 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 80 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 81 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 82 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 83 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 84 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 85 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
# 86 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 87 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, MALE
# 88 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_MOM
# 89 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
# 90 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 91 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 92 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
# 93 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 94 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 95 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
# 96 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 97 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
# 98 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 99 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 100 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 101 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 102 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 103 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 104 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
# 105 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 106 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 107 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 108 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
# 109 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 110 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 111 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 112 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 113 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 114 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 115 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 116 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 117 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
# 118 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 119 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 120 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 121 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 122 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 123 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 124 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 125 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 126 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
# 127 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 128 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 129 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 130 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 131 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 132 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
# 133 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 134 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 135 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 136 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 137 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 138 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
# 139 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 140 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 141 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 142 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 143 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 144 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
# 145 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 146 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 147 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	addobject LOCALID_RIVAL
# 148 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 149 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 150 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 151 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 152 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 153 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 154 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
# 155 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 156 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
# 157 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
# 158 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
# 159 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 160 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 161 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
# 162 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
# 163 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
# 164 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 165 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	removeobject LOCALID_RIVAL
# 166 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
# 167 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 168 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 169 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 170 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 171 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 172 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 173 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadedefaultbgm
# 174 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 175 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 176 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 177 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
# 178 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 179 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 180 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 181 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 182 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
# 183 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
# 184 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 185 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 186 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 187 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
# 188 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
# 189 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 190 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 191 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 192 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
# 193 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
# 194 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 195 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 196 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 197 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
# 198 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 199 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 200 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 201 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 202 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 203 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 204 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 205 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 206 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 207 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
# 208 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 209 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 210 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 211 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 212 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 213 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
# 214 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 215 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 216 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 217 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 218 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 219 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 220 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 221 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 222 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 223 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
# 224 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
# 225 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
# 226 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 227 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 228 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 229 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
# 230 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
# 231 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
# 232 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 233 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 234 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 235 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
# 236 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
# 237 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
# 238 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 239 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 240 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 241 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
# 242 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 243 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 244 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 245 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 246 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 247 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
# 248 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 249 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 250 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 251 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 252 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 253 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 254 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 255 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 256 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
# 257 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 258 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 259 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 260 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 261 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 262 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
# 263 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 264 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 265 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 266 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 267 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 268 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 269 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 270 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
# 271 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 272 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 273 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 274 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 275 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 276 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 277 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 278 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 279 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 280 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 281 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 282 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
# 283 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 284 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 285 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 286 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 287 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 288 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 289 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 290 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsntItNiceInHere:
# 291 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See, {PLAYER}?\n"
# 292 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Isn't it nice in here, too?$"
# 293 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 294 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MoversPokemonGoSetClock:
# 295 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The agency's POKéMON do all the work\n"
# 296 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "of moving us in and cleaning up after.\p"
# 297 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "{PLAYER}, your room is upstairs.$"
# 298 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 299 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ArentYouInterestedInRoom:
# 300 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, {PLAYER}?\p"
# 301 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Aren't you interested in seeing your\n"
# 302 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "room?$"
# 303 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 304 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoSetTheClock:
# 305 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}.\p"
# 306 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go set the clock in your room.$"
# 307 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 308 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_OhComeQuickly:
# 309 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
# 310 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Quick! Come quickly!$"
# 311 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 312 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MaybeDadWillBeOn:
# 313 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Look! It's PETALBURG GYM!\n"
# 314 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Maybe DAD will be on!$"
# 315 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 316 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ItsOverWeMissedHim:
# 317 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh… It's over.\p"
# 318 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think DAD was on, but we missed him.\n"
# 319 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Too bad.$"
# 320 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 321 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
# 322 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes.\n"
# 323 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "One of DAD's friends lives in town.\p"
# 324 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH is his name.\p"
# 325 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He lives right next door, so you should\n"
# 326 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "go over and introduce yourself.$"
# 327 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 328 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_SeeYouHoney:
# 329 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See you, honey!$"
# 330 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 331 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DidYouMeetProfBirch:
# 332 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Did you introduce yourself to\n"
# 333 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH?$"
# 334 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 335 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_YouShouldRestABit:
# 336 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: How are you doing, {PLAYER}?\n"
# 337 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You look a little tired.\p"
# 338 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think you should rest a bit.$"
# 339 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 340 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TakeCareHoney:
# 341 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Take care, honey!$"
# 342 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 343 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
# 344 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
# 345 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Then here's something from your MOM!$"
# 346 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 347 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DontPushYourselfTooHard:
# 348 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't push yourself too hard, dear.\n"
# 349 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You can always come home.\p"
# 350 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go for it, honey!$"
# 351 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 352 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatAPokenav:
# 353 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: What is that, honey? A POKéNAV?\n"
# 354 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Someone from DEVON gave it to you?\p"
# 355 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Well, honey, how about registering\n"
# 356 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "your mom?\p"
# 357 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "… … …$"
# 358 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 359 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RegisteredMom:
# 360 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered MOM\n"
# 361 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "in the POKéNAV.$"
# 362 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 363 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth1:
# 364 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Fugiiiiih!$"
# 365 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 366 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth2:
# 367 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Huggoh, uggo uggo…$"
# 368 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 369 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ReportFromPetalburgGym:
# 370 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "INTERVIEWER: …We brought you this\n"
# 371 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "report from in front of PETALBURG GYM.$"
# 372 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 373 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TheresAMovieOnTV:
# 374 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There is a movie on TV.\p"
# 375 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Two men are dancing on a big piano\n"
# 376 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "keyboard.\p"
# 377 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Better get going!$"
# 378 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 379 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RunningShoesManual:
# 380 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's the instruction booklet for the\n"
# 381 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "RUNNING SHOES.\p"
# 382 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Press the B Button to run while\n"
# 383 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "wearing your RUNNING SHOES.\p"
# 384 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Lace up your RUNNING SHOES and hit\n"
# 385 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "the road running!”$"
# 386 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 387 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
# 388 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm?\p"
# 389 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 390 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's been a while since I saw you,\n"
# 391 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "but you look…stronger, somehow.\p"
# 392 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "That's the impression I get.\n"
# 393 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "But your old man hasn't given up yet!\p"
# 394 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes, I have something for you.\n"
# 395 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This came to you from someone named\l"
# 396 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MR. BRINEY.$"
# 397 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 398 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_PortsInSlateportLilycove:
# 399 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm, a TICKET for a ferry?\p"
# 400 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "If I recall, there are ferry ports in\n"
# 401 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "SLATEPORT and LILYCOVE.$"
# 402 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 403 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_BetterGetBackToGym:
# 404 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I'd better get back to PETALBURG GYM.\p"
# 405 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM, thanks for looking after the house\n"
# 406 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while I'm away.$"
# 407 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 408 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DadShouldStayLonger:
# 409 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: That DAD of yours…\p"
# 410 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He comes home for the first time in a\n"
# 411 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while, but all he talks about is POKéMON.\p"
# 412 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He should relax and stay a little longer.$"
# 413 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 414 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatABreakingStory:
# 415 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Is that a breaking news story?$"
# 416 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 417 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
# 418 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We bring you this emergency\n"
# 419 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "news flash!\p"
# 420 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "In various HOENN locales, there have\n"
# 421 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "been reports of a BZZT…colored\l"
# 422 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "POKéMON in flight.\p"
# 423 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The identity of this POKéMON is\n"
# 424 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "currently unknown.\p"
# 425 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We now return you to the regular\n"
# 426 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "movie program.$"
# 427 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 428 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_WhatColorDidTheySay:
# 429 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}, did you catch that?\p"
# 430 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "What color did the announcer say\n"
# 431 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "that POKéMON was?$"
# 432 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 433 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_StillUnknownPokemon:
# 434 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, isn't that something!\n"
# 435 "data//maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There are still unknown POKéMON.$"
