# 1 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 2 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
.set LOCALID_MOM, 1
# 3 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
.set LOCALID_RIVAL_MOM, 4
# 4 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 6 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_MapScripts::
# 7 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
# 8 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
# 9 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
# 10 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.byte 0
# 11 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 12 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnLoad:
# 13 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
# 14 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
# 15 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 16 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 17 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes::
# 18 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 19 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
# 20 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 21 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 22 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 23 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkplayergender
# 24 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
# 25 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 26 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 27 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual::
# 28 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
# 29 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 30 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 31 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnTransition:
# 32 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
# 33 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
# 34 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
# 35 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 36 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 37 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs::
# 38 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 2, 4
# 39 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 40 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 41 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 42 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV::
# 43 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 6, 5
# 44 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 45 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 46 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 47 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor::
# 48 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 1, 8
# 49 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 50 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 51 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 52 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 53 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnFrame:
# 54 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
# 55 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
# 56 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
# 57 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
# 58 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 59 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.2byte 0
# 60 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 61 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock::
# 62 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 63 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 64 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 65 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 66 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 67 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 68 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 1, 1
# 69 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 70 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 71 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 72 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 73 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 74 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 75 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 76 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 77 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn::
# 78 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 79 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 80 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 81 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 82 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 83 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 84 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport::
# 85 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 86 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, FEMALE
# 87 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_MOM
# 88 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
# 89 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 90 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 91 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor::
# 92 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 93 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 94 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
# 95 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 96 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
# 97 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 98 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 100 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 101 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 102 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 103 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
# 104 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 105 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 106 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 107 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 108 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 109 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 110 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 111 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 112 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 113 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 114 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 115 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 116 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalMom::
# 117 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 118 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 119 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 120 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 121 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, RivalsHouse_1F_EventScript_RivalTooBusy
# 122 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 123 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 124 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 125 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 126 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 127 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalTooBusy::
# 128 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 129 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 130 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 131 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 132 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 133 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 134 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 135 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 136 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 137 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 138 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 139 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 140 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 141 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 142 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalSibling::
# 143 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 144 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 145 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 146 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
# 147 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 148 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 149 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 150 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 151 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 152 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 153 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 154 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 155 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 156 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 157 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 158 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 159 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
# 160 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 161 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 162 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 163 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 164 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 165 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
# 166 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 167 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 168 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 169 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 170 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 171 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
# 172 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 173 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 174 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 175 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 176 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 177 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
# 178 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 179 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 10
# 180 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	addobject LOCALID_RIVAL
# 181 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 182 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 183 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 184 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 185 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 186 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 187 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_ne VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
# 188 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 189 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
# 190 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
# 191 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
# 192 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 193 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 194 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
# 195 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
# 196 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
# 197 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 198 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	removeobject LOCALID_RIVAL
# 199 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 200 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 201 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 202 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 203 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 204 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 205 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 206 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadedefaultbgm
# 207 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 208 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 209 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 210 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
# 211 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 212 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 213 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 214 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 215 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0::
# 216 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
# 217 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 218 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 219 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 220 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1::
# 221 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
# 222 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 223 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 224 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 225 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2::
# 226 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
# 227 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 228 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 229 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 230 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
# 231 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 232 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 233 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 234 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 235 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 236 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 237 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 238 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 239 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 240 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
# 241 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 242 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 243 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 244 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 245 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 246 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
# 247 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 248 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 249 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 250 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 251 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 252 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 253 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 254 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 255 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 256 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
# 257 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
# 258 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
# 259 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 260 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 261 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 262 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
# 263 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
# 264 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
# 265 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 266 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 267 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 268 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
# 269 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
# 270 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
# 271 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 272 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 273 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 274 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
# 275 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 276 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 277 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 278 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 279 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 280 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
# 281 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 282 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 283 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 284 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 285 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 286 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 287 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 288 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 289 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
# 290 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 291 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 292 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 293 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 294 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 295 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
# 296 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 297 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 298 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 299 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 300 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 301 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 302 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 303 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
# 304 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 305 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 306 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 307 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 308 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 309 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 310 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 311 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 312 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 313 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 314 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 315 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
# 316 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 317 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 318 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 319 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 320 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 321 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 322 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 323 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_OhYoureTheNewNeighbor:
# 324 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, you're the new neighbor?\p"
# 325 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string ". . . . . .\n"
# 326 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string ". . . . . .\p"
# 327 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Well just don't break anything!$"
# 328 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 329 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_LikeChildLikeFather:
# 330 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like child, like father.\p"
# 331 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "My husband is as wild about POKéMON\n"
# 332 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "as our child.\p"
# 333 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "If he's not at his LAB, he's likely\n"
# 334 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "scrabbling about in grassy places.$"
# 335 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 336 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_TooBusyToNoticeVisit:
# 337 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
# 338 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I guess our child is too busy with\n"
# 339 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "POKéMON to notice that you came\l"
# 340 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to visit, {PLAYER}{KUN}.$"
# 341 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 342 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_WentOutToRoute103:
# 343 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
# 344 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "just a little while ago.\p"
# 345 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like father, like child.\n"
# 346 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{RIVAL} can't stay quietly at home.$"
# 347 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 348 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_ShouldGoHomeEverySoOften:
# 349 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
# 350 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "travel with POKéMON.\p"
# 351 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "But you should go home every so often\n"
# 352 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to let your mother know you're okay.\p"
# 353 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "She might not say it, but I'm sure she\n"
# 354 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "worries about you, {PLAYER}{KUN}.$"
# 355 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 356 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_MayWhoAreYou:
# 357 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Huh?\n"
# 358 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Who… Who are you?\p"
# 359 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Get out of my room!$"
# 360 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 361 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_BrendanWhoAreYou:
# 362 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hey!\n"
# 363 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "This is my room!\p"
# 364 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "You should leave.$"
# 365 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 366 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_DoYouHavePokemon:
# 367 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hi, neighbor!\p"
# 368 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Do you have your\n"
# 369 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "own POKéMON?$"
