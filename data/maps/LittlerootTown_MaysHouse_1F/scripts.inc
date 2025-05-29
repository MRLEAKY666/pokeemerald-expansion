# 1 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 2 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_MapScripts::
# 3 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
# 4 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
# 5 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
# 6 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.byte 0
# 7 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 8 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnLoad:
# 9 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
# 10 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
# 11 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 12 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 13 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes::
# 14 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 15 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
# 16 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 17 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 18 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 19 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkplayergender
# 20 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
# 21 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 22 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 23 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual::
# 24 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
# 25 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 26 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 27 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnTransition:
# 28 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
# 29 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
# 30 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
# 31 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 32 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 33 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs::
# 34 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 2, 4
# 35 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 36 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 37 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 38 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV::
# 39 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
# 40 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 41 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 42 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 43 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor::
# 44 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 1, 8
# 45 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 46 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 47 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 48 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 49 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnFrame:
# 50 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
# 51 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
# 52 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
# 53 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
# 54 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 55 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.2byte 0
# 56 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 57 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock::
# 58 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 59 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 60 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 61 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 62 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 63 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 64 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 1, 1
# 65 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 66 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 67 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 68 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 69 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 70 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 71 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 72 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 73 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn::
# 74 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 75 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
# 76 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 77 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 78 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 79 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 80 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport::
# 81 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 82 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, FEMALE
# 83 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
# 84 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
# 85 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 86 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 87 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor::
# 88 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 89 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 90 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
# 91 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 92 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
# 93 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 94 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 95 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 96 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 97 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 98 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 99 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
# 100 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 101 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 102 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 103 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 104 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 105 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 106 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 107 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 108 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 109 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 110 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 111 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 112 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalMom::
# 113 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 114 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 115 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 116 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 117 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, RivalsHouse_1F_EventScript_RivalTooBusy
# 118 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 119 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 120 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 121 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 122 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 123 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalTooBusy::
# 124 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 125 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 126 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 127 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 128 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 129 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 130 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 131 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 132 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 133 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 134 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 135 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 136 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 137 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 138 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalSibling::
# 139 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 140 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 141 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 142 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
# 143 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 144 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 145 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 146 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 147 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 148 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
# 149 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 150 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 151 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 152 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 153 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 154 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 155 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
# 156 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 157 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 158 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 159 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 160 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 161 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
# 162 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 163 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 164 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 165 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 166 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 167 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
# 168 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 169 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 170 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 171 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 172 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 173 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
# 174 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 175 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 10
# 176 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
# 177 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 178 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 179 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
# 180 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 181 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
# 182 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 183 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_ne VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
# 184 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 185 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
# 186 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
# 187 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
# 188 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 189 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 190 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
# 191 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
# 192 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
# 193 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 194 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
# 195 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 196 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 197 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 198 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 199 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 200 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 201 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 202 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadedefaultbgm
# 203 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 204 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 205 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 206 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
# 207 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 208 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 209 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 210 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 211 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0::
# 212 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
# 213 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 214 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 215 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 216 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1::
# 217 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
# 218 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 219 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 220 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 221 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2::
# 222 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
# 223 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 224 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 225 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 226 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
# 227 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 228 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 229 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 230 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 231 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 232 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 233 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 234 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 235 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 236 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
# 237 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 238 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 239 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 240 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 241 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 242 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
# 243 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 244 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 245 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 246 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 247 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 248 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 249 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 250 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 251 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 252 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
# 253 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
# 254 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
# 255 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 256 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 257 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 258 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
# 259 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
# 260 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
# 261 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 262 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 263 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 264 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
# 265 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
# 266 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
# 267 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 268 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 269 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 270 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
# 271 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 272 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 273 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 274 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 275 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 276 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
# 277 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 278 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 279 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 280 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 281 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 282 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 283 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 284 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 285 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
# 286 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 287 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 288 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 289 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 290 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 291 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
# 292 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 293 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 294 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 295 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 296 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 297 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 298 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 299 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
# 300 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 301 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 302 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 303 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 304 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 305 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 306 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 307 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 308 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 309 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 310 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 311 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
# 312 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 313 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 314 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 315 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 316 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 317 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 318 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 319 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_OhYoureTheNewNeighbor:
# 320 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, you're the new neighbor?\p"
# 321 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string ". . . . . .\n"
# 322 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string ". . . . . .\p"
# 323 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Well just don't break anything!$"
# 324 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 325 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_LikeChildLikeFather:
# 326 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like child, like father.\p"
# 327 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "My husband is as wild about POKéMON\n"
# 328 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "as our child.\p"
# 329 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "If he's not at his LAB, he's likely\n"
# 330 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "scrabbling about in grassy places.$"
# 331 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 332 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_TooBusyToNoticeVisit:
# 333 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
# 334 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I guess our child is too busy with\n"
# 335 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "POKéMON to notice that you came\l"
# 336 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to visit, {PLAYER}{KUN}.$"
# 337 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 338 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_WentOutToRoute103:
# 339 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
# 340 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "just a little while ago.\p"
# 341 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like father, like child.\n"
# 342 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{RIVAL} can't stay quietly at home.$"
# 343 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 344 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_ShouldGoHomeEverySoOften:
# 345 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
# 346 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "travel with POKéMON.\p"
# 347 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "But you should go home every so often\n"
# 348 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to let your mother know you're okay.\p"
# 349 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "She might not say it, but I'm sure she\n"
# 350 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "worries about you, {PLAYER}{KUN}.$"
# 351 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 352 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_MayWhoAreYou:
# 353 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Huh?\n"
# 354 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Who… Who are you?\p"
# 355 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Get out of my room!$"
# 356 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 357 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_BrendanWhoAreYou:
# 358 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hey!\n"
# 359 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "This is my room!\p"
# 360 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "You should leave.$"
# 361 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 362 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_DoYouHavePokemon:
# 363 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hi, neighbor!\p"
# 364 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Do you have your\n"
# 365 "data//maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "own POKéMON?$"
