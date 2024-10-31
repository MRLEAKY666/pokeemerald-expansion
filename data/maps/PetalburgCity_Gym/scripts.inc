# 1 "data//maps/PetalburgCity_Gym/scripts.pory"

# 2 "data//maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_NORMAN, 1
# 3 "data//maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLY, 10
# 4 "data//maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLYS_DAD, 11
# 5 "data//maps/PetalburgCity_Gym/scripts.pory"

# 6 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_MapScripts::
# 7 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
# 8 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
# 9 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
# 10 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
# 11 "data//maps/PetalburgCity_Gym/scripts.pory"
	.byte 0
# 12 "data//maps/PetalburgCity_Gym/scripts.pory"

# 13 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnLoad:
# 14 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
# 15 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
# 16 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 17 "data//maps/PetalburgCity_Gym/scripts.pory"

# 18 "data//maps/PetalburgCity_Gym/scripts.pory"
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
# 19 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
# 20 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 21 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 22 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 23 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 24 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 25 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 26 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 27 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 28 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 29 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 30 "data//maps/PetalburgCity_Gym/scripts.pory"

# 31 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockAllDoors::
# 32 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 33 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 34 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 35 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 36 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 37 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 38 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 39 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 40 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 41 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 42 "data//maps/PetalburgCity_Gym/scripts.pory"

# 43 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnTransition:
# 44 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
# 45 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
# 46 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
# 47 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 48 "data//maps/PetalburgCity_Gym/scripts.pory"

# 49 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
# 50 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_WALLY, 5, 108
# 51 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 52 "data//maps/PetalburgCity_Gym/scripts.pory"

# 53 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
# 54 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 55 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 56 "data//maps/PetalburgCity_Gym/scripts.pory"

# 57 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_CheckNormanForRematch::
# 58 "data//maps/PetalburgCity_Gym/scripts.pory"
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
# 59 "data//maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 60 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 61 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 62 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 63 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 64 "data//maps/PetalburgCity_Gym/scripts.pory"

# 65 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
# 66 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 8
# 67 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 68 "data//maps/PetalburgCity_Gym/scripts.pory"

# 69 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnWarp:
# 70 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
# 71 "data//maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 72 "data//maps/PetalburgCity_Gym/scripts.pory"

# 73 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_TurnPlayerNorth::
# 74 "data//maps/PetalburgCity_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 75 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 76 "data//maps/PetalburgCity_Gym/scripts.pory"

# 77 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnFrame:
# 78 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
# 79 "data//maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 80 "data//maps/PetalburgCity_Gym/scripts.pory"

# 81 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
# 82 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
# 83 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 84 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 85 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 86 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 87 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
# 88 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 89 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 90 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
# 91 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 92 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_EXIT
# 93 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 94 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 95 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 96 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 97 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 98 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
# 99 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 2
# 100 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 101 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 102 "data//maps/PetalburgCity_Gym/scripts.pory"

# 103 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitGym:
# 104 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 105 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 106 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 107 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 108 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 109 "data//maps/PetalburgCity_Gym/scripts.pory"

# 110 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Norman::
# 111 "data//maps/PetalburgCity_Gym/scripts.pory"
	lock
# 112 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 113 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 114 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
# 115 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
# 116 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
# 117 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
# 118 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
# 119 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
# 120 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
# 121 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 122 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 123 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 124 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
# 125 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
# 126 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
# 127 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
# 128 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 129 "data//maps/PetalburgCity_Gym/scripts.pory"

# 130 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
# 131 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 132 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 133 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 134 "data//maps/PetalburgCity_Gym/scripts.pory"

# 135 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
# 136 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 137 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 138 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 139 "data//maps/PetalburgCity_Gym/scripts.pory"

# 140 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
# 141 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 142 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 143 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 144 "data//maps/PetalburgCity_Gym/scripts.pory"

# 145 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
# 146 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 147 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 148 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 149 "data//maps/PetalburgCity_Gym/scripts.pory"

# 150 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial::
# 151 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLY
# 152 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 153 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 154 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 155 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 156 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 157 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 158 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 159 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 160 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 161 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 162 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 163 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 164 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 165 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 166 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 167 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 168 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 169 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 170 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 171 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 172 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 173 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 174 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 175 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 176 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 177 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 178 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 179 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 180 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 181 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 182 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 183 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 184 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 185 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 186 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 187 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 188 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 189 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 190 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 191 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 192 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 193 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 194 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 195 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 196 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 197 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 198 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 199 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 200 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 201 "data//maps/PetalburgCity_Gym/scripts.pory"

# 202 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SkipWallyTutorial::
# 203 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLY
# 204 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 205 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 206 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 207 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 208 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 209 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 210 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 211 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 212 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 213 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 214 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_SkipWallyTutorial, MSGBOX_DEFAULT
# 215 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 216 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 217 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 218 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 219 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 220 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 221 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 222 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 223 "data//maps/PetalburgCity_Gym/scripts.pory"

# 224 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth::
# 225 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 226 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 227 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 228 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 229 "data//maps/PetalburgCity_Gym/scripts.pory"

# 230 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth::
# 231 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 232 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 233 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 234 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 235 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 236 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 237 "data//maps/PetalburgCity_Gym/scripts.pory"

# 238 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast::
# 239 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 240 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 241 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 242 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 243 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 244 "data//maps/PetalburgCity_Gym/scripts.pory"

# 245 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
# 246 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 247 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 248 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 249 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 250 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 251 "data//maps/PetalburgCity_Gym/scripts.pory"

# 252 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
# 253 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 254 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 255 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 256 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 257 "data//maps/PetalburgCity_Gym/scripts.pory"

# 258 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
# 259 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 260 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 261 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 262 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 263 "data//maps/PetalburgCity_Gym/scripts.pory"

# 264 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
# 265 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 266 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 267 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 268 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 269 "data//maps/PetalburgCity_Gym/scripts.pory"

# 270 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
# 271 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterUp
# 272 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 273 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 274 "data//maps/PetalburgCity_Gym/scripts.pory"

# 275 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
# 276 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 277 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 278 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 279 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 280 "data//maps/PetalburgCity_Gym/scripts.pory"

# 281 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
# 282 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 283 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 284 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 285 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 286 "data//maps/PetalburgCity_Gym/scripts.pory"

# 287 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
# 288 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 289 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 290 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 291 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 292 "data//maps/PetalburgCity_Gym/scripts.pory"

# 293 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
# 294 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 295 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 296 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 297 "data//maps/PetalburgCity_Gym/scripts.pory"

# 298 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
# 299 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 300 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 301 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 302 "data//maps/PetalburgCity_Gym/scripts.pory"

# 303 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
# 304 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 305 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 306 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 307 "data//maps/PetalburgCity_Gym/scripts.pory"

# 308 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
# 309 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 310 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 311 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 312 "data//maps/PetalburgCity_Gym/scripts.pory"

# 313 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer::
# 314 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 315 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 316 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 317 "data//maps/PetalburgCity_Gym/scripts.pory"

# 318 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown::
# 319 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterDown
# 320 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 321 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 322 "data//maps/PetalburgCity_Gym/scripts.pory"

# 323 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanNoBadges::
# 324 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 325 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 326 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 327 "data//maps/PetalburgCity_Gym/scripts.pory"

# 328 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanOneBadge::
# 329 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 330 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 331 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 332 "data//maps/PetalburgCity_Gym/scripts.pory"

# 333 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanTwoBadges::
# 334 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 335 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 336 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 337 "data//maps/PetalburgCity_Gym/scripts.pory"

# 338 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanThreeBadges::
# 339 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 340 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 341 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 342 "data//maps/PetalburgCity_Gym/scripts.pory"

# 343 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
# 344 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 345 "data//maps/PetalburgCity_Gym/scripts.pory"

# 346 "data//maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 347 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
# 348 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 349 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 350 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 351 "data//maps/PetalburgCity_Gym/scripts.pory"

# 352 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
# 353 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 354 "data//maps/PetalburgCity_Gym/scripts.pory"

# 355 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
# 356 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 357 "data//maps/PetalburgCity_Gym/scripts.pory"

# 358 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanPostBattle::
# 359 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
# 360 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
# 361 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
# 362 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
# 363 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 364 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 365 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 366 "data//maps/PetalburgCity_Gym/scripts.pory"

# 367 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2::
# 368 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 369 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 370 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 371 "data//maps/PetalburgCity_Gym/scripts.pory"

# 372 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanRematch::
# 373 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
# 374 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 375 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 376 "data//maps/PetalburgCity_Gym/scripts.pory"

# 377 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
# 378 "data//maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 379 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 380 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY_E_READER
# 381 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 382 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
# 383 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 384 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 385 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 386 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 387 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 388 "data//maps/PetalburgCity_Gym/scripts.pory"

# 389 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
# 390 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 391 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 392 "data//maps/PetalburgCity_Gym/scripts.pory"

# 393 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
# 394 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY_E_READER
# 395 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 396 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 397 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 398 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 399 "data//maps/PetalburgCity_Gym/scripts.pory"

# 400 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 401 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 402 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 403 "data//maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 404 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 405 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 406 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 407 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 408 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 409 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 410 "data//maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 411 "data//maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 412 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 413 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 414 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 415 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 416 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 417 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 418 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 419 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 420 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 421 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 422 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 423 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 424 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 425 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 426 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLYS_DAD
# 427 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 428 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 429 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 430 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 431 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 432 "data//maps/PetalburgCity_Gym/scripts.pory"

# 433 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade::
# 434 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_TM_FACADE
# 435 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 436 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_FACADE
# 437 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
# 438 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 439 "data//maps/PetalburgCity_Gym/scripts.pory"

# 440 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
# 441 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 442 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 443 "data//maps/PetalburgCity_Gym/scripts.pory"

# 444 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
# 445 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 446 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 447 "data//maps/PetalburgCity_Gym/scripts.pory"

# 448 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
# 449 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 450 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 451 "data//maps/PetalburgCity_Gym/scripts.pory"

# 452 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives::
# 453 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 454 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 455 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 456 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
# 457 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 458 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
# 459 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 460 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 461 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 462 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 463 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 464 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 465 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 466 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 467 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 468 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 469 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 470 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 471 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 472 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 473 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 474 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 475 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 476 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 477 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLYS_DAD
# 478 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 479 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 480 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 481 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 482 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 483 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 484 "data//maps/PetalburgCity_Gym/scripts.pory"

# 485 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
# 486 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
# 487 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 488 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 489 "data//maps/PetalburgCity_Gym/scripts.pory"

# 490 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
# 491 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
# 492 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 493 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 494 "data//maps/PetalburgCity_Gym/scripts.pory"

# 495 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
# 496 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
# 497 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 498 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 499 "data//maps/PetalburgCity_Gym/scripts.pory"

# 500 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
# 501 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 502 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 503 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 504 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 505 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 506 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 507 "data//maps/PetalburgCity_Gym/scripts.pory"

# 508 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
# 509 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 510 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 511 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 512 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 513 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 514 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 515 "data//maps/PetalburgCity_Gym/scripts.pory"

# 516 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
# 517 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 518 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 519 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 520 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 521 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 522 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 523 "data//maps/PetalburgCity_Gym/scripts.pory"

# 524 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
# 525 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 526 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 527 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 528 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 529 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 530 "data//maps/PetalburgCity_Gym/scripts.pory"

# 531 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
# 532 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 533 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 534 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 535 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 536 "data//maps/PetalburgCity_Gym/scripts.pory"

# 537 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
# 538 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 539 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 540 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 541 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 542 "data//maps/PetalburgCity_Gym/scripts.pory"

# 543 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth:
# 544 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 545 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 546 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 547 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 548 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 549 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 550 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 551 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 552 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 553 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 554 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 555 "data//maps/PetalburgCity_Gym/scripts.pory"

# 556 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast:
# 557 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 558 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 559 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 560 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 561 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 562 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 563 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 564 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 565 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 566 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 567 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 568 "data//maps/PetalburgCity_Gym/scripts.pory"

# 569 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest:
# 570 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 571 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 572 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 573 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 574 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 575 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 576 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 577 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 578 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 579 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 580 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 581 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 582 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 583 "data//maps/PetalburgCity_Gym/scripts.pory"

# 584 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
# 585 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 586 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 587 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 588 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 589 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 590 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 591 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 592 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 593 "data//maps/PetalburgCity_Gym/scripts.pory"

# 594 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
# 595 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 596 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 597 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 598 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 599 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 600 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 601 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 602 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 603 "data//maps/PetalburgCity_Gym/scripts.pory"

# 604 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
# 605 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 606 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 607 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 608 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 609 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 610 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 611 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 612 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 613 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 614 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 615 "data//maps/PetalburgCity_Gym/scripts.pory"

# 616 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym:
# 617 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 618 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 619 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 620 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 621 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 622 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 623 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 624 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 625 "data//maps/PetalburgCity_Gym/scripts.pory"

# 626 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
# 627 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 628 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 629 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 630 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 631 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 632 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 633 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 634 "data//maps/PetalburgCity_Gym/scripts.pory"

# 635 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
# 636 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 637 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 638 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 639 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 640 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 641 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 642 "data//maps/PetalburgCity_Gym/scripts.pory"

# 643 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
# 644 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 645 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 646 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 647 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 648 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 649 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 650 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 651 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 652 "data//maps/PetalburgCity_Gym/scripts.pory"

# 653 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused:
# 654 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 655 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 656 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 657 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 658 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 659 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 660 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 661 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 662 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 663 "data//maps/PetalburgCity_Gym/scripts.pory"

# 664 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth:
# 665 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 666 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 667 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 668 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 669 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 670 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 671 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 672 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 673 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 674 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 675 "data//maps/PetalburgCity_Gym/scripts.pory"

# 676 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive:
# 677 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 678 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 679 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 680 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 681 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 682 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 683 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 684 "data//maps/PetalburgCity_Gym/scripts.pory"

# 685 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth:
# 686 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 687 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 688 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 689 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 690 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 691 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 692 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 693 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 694 "data//maps/PetalburgCity_Gym/scripts.pory"

# 695 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast:
# 696 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 697 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 698 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 699 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 700 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 701 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 702 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 703 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 704 "data//maps/PetalburgCity_Gym/scripts.pory"

# 705 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest:
# 706 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 707 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 708 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 709 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 710 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 711 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 712 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 713 "data//maps/PetalburgCity_Gym/scripts.pory"

# 714 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
# 715 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 716 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 717 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 718 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 719 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 720 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 721 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 722 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 723 "data//maps/PetalburgCity_Gym/scripts.pory"

# 724 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
# 725 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 726 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 727 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 728 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 729 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 730 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 731 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 732 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 733 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 734 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 735 "data//maps/PetalburgCity_Gym/scripts.pory"

# 736 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
# 737 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 738 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 739 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 740 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 741 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 742 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 743 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 744 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 745 "data//maps/PetalburgCity_Gym/scripts.pory"

# 746 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
# 747 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 748 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 749 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 750 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 751 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 752 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 753 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 754 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 755 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 756 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 757 "data//maps/PetalburgCity_Gym/scripts.pory"

# 758 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
# 759 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
# 760 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 761 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 762 "data//maps/PetalburgCity_Gym/scripts.pory"

# 763 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor::
# 764 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 765 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 766 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 767 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 768 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 769 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 770 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 771 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 772 "data//maps/PetalburgCity_Gym/scripts.pory"

# 773 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom::
# 774 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 775 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 776 "data//maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
# 777 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 778 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 779 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 780 "data//maps/PetalburgCity_Gym/scripts.pory"

# 781 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom::
# 782 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 783 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 784 "data//maps/PetalburgCity_Gym/scripts.pory"

# 785 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked::
# 786 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 787 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 788 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 789 "data//maps/PetalburgCity_Gym/scripts.pory"

# 790 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 791 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
# 792 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 793 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 794 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 795 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 796 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 797 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 798 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 799 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 800 "data//maps/PetalburgCity_Gym/scripts.pory"

# 801 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
# 802 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 803 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 804 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 805 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 806 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 807 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 808 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 809 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 810 "data//maps/PetalburgCity_Gym/scripts.pory"

# 811 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
# 812 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 813 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 814 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 815 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 816 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 817 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 818 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 819 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 820 "data//maps/PetalburgCity_Gym/scripts.pory"

# 821 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
# 822 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 823 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 824 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 825 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 826 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 827 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 828 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 829 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 830 "data//maps/PetalburgCity_Gym/scripts.pory"

# 831 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
# 832 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 833 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 834 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 835 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 836 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 837 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 838 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 839 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 840 "data//maps/PetalburgCity_Gym/scripts.pory"

# 841 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
# 842 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 843 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 844 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 845 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 846 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 847 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 848 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 849 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 850 "data//maps/PetalburgCity_Gym/scripts.pory"

# 851 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
# 852 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 853 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 854 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 855 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 856 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 857 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 858 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 859 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 860 "data//maps/PetalburgCity_Gym/scripts.pory"

# 861 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
# 862 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 863 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 864 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 865 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 866 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 867 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 868 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 869 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 870 "data//maps/PetalburgCity_Gym/scripts.pory"

# 871 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
# 872 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 873 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 874 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 875 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 876 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 877 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 878 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 879 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 880 "data//maps/PetalburgCity_Gym/scripts.pory"

# 881 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
# 882 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 883 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 884 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 885 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 886 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 887 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 888 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 889 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 890 "data//maps/PetalburgCity_Gym/scripts.pory"

# 891 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
# 892 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 893 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 894 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 895 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 896 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 897 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 898 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 899 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 900 "data//maps/PetalburgCity_Gym/scripts.pory"

# 901 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall::
# 902 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 903 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 904 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 905 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 906 "data//maps/PetalburgCity_Gym/scripts.pory"

# 907 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
# 908 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 909 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 910 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 911 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 912 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 913 "data//maps/PetalburgCity_Gym/scripts.pory"

# 914 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge::
# 915 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 916 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 917 "data//maps/PetalburgCity_Gym/scripts.pory"

# 918 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker::
# 919 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 920 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 921 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 922 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 923 "data//maps/PetalburgCity_Gym/scripts.pory"

# 924 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
# 925 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 926 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 927 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 928 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 929 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 930 "data//maps/PetalburgCity_Gym/scripts.pory"

# 931 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge::
# 932 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 933 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 934 "data//maps/PetalburgCity_Gym/scripts.pory"

# 935 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George::
# 936 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 937 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 938 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 939 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 940 "data//maps/PetalburgCity_Gym/scripts.pory"

# 941 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
# 942 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 943 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 944 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 945 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 946 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 947 "data//maps/PetalburgCity_Gym/scripts.pory"

# 948 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge::
# 949 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 950 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 951 "data//maps/PetalburgCity_Gym/scripts.pory"

# 952 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke::
# 953 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 954 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 955 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 956 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 957 "data//maps/PetalburgCity_Gym/scripts.pory"

# 958 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
# 959 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 960 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 961 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 962 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 963 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 964 "data//maps/PetalburgCity_Gym/scripts.pory"

# 965 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge::
# 966 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 967 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 968 "data//maps/PetalburgCity_Gym/scripts.pory"

# 969 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary::
# 970 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 971 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 972 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 973 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 974 "data//maps/PetalburgCity_Gym/scripts.pory"

# 975 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
# 976 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 977 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 978 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 979 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 980 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 981 "data//maps/PetalburgCity_Gym/scripts.pory"

# 982 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge::
# 983 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 984 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 985 "data//maps/PetalburgCity_Gym/scripts.pory"

# 986 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia::
# 987 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 988 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 989 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 990 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 991 "data//maps/PetalburgCity_Gym/scripts.pory"

# 992 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
# 993 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 994 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 995 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 996 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 997 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 998 "data//maps/PetalburgCity_Gym/scripts.pory"

# 999 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge::
# 1000 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 1001 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1002 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1003 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody::
# 1004 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 1005 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 1006 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 1007 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1008 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1009 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
# 1010 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1011 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 1012 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1013 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1014 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1015 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1016 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge::
# 1017 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 1018 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1019 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1020 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 1021 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 1022 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
# 1023 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 1024 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1025 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1026 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1027 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1028 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1029 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
# 1030 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1031 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1032 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1033 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1034 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1035 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1036 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
# 1037 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1038 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1039 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1040 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1041 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1042 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1043 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
# 1044 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1045 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1046 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1047 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1048 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1049 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1050 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
# 1051 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1052 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1053 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1054 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1055 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1056 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1057 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
# 1058 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1059 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1060 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1061 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1062 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1063 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1064 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
# 1065 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1066 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1067 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1068 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1069 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1070 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1071 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
# 1072 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1073 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1074 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1075 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1076 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1077 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1078 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
# 1079 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1080 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1081 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1082 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1083 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1084 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1085 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
# 1086 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1087 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1088 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1089 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1090 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1091 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1092 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
# 1093 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1094 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1095 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1096 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1097 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1098 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1099 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
# 1100 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1101 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1102 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1103 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1104 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
# 1105 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1106 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1107 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1108 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1109 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1110 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1111 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
# 1112 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1113 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1114 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1115 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1116 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
# 1117 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1118 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1119 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1120 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1121 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
# 1122 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1123 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1124 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1125 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1126 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
# 1127 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1128 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1129 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1130 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1131 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors::
# 1132 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1133 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1134 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1135 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide::
# 1136 "data//maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1137 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1138 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1139 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 1140 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1141 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1142 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1143 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory::
# 1144 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1145 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1146 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1147 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1148 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue::
# 1149 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1150 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1151 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1152 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1153 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1154 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue::
# 1155 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1156 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1157 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1158 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1159 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1160 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified::
# 1161 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1162 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1163 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1164 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1165 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue::
# 1166 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1167 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1168 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1169 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1170 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
# 1171 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm?\p"
# 1172 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1173 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1174 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1175 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.$"
# 1176 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1177 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
# 1178 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1179 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a POKéMON, please…$"
# 1180 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1181 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight:
# 1182 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
# 1183 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're WALLY, right?$"
# 1184 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1185 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
# 1186 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: I'm going to go stay with my\n"
# 1187 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in VERDANTURF TOWN.\p"
# 1188 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1189 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a POKéMON along.\p"
# 1190 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a POKéMON before.\n"
# 1191 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1192 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1193 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee:
# 1194 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hmm . . . \p"
# 1195 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I see . . . $"
# 1196 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1197 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally:
# 1198 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you heard that,\n"
# 1199 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1200 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with WALLY and make sure that he\n"
# 1201 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a POKéMON.$"
# 1202 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1203 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
# 1204 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY, here, I'll loan you my POKéMON.\p"
# 1205 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a ZIGZAGOON!$"
# 1206 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1207 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
# 1208 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1209 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "A POKéMON!\p"
# 1210 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
# 1211 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1212 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a POKé BALL!$"
# 1213 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1214 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou:
# 1215 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1216 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1217 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1218 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
# 1219 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1220 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1221 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1222 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut:
# 1223 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Watch out for each other\n"
# 1224 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "if you're travelling$"
# 1225 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1226 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye:
# 1227 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: . . .\n"
# 1228 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have to go . . .\p"
# 1229 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "See you around, {PLAYER}.$"
# 1230 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1231 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges:
# 1232 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for RUSTBORO CITY beyond this\n"
# 1233 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1234 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1235 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER, ROXANNE.\p"
# 1236 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm a GYM LEADER, too.\n"
# 1237 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER} . . .\p"
# 1238 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Only after you become stronger.$"
# 1239 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1240 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro:
# 1241 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? Aren't you going to the\n"
# 1242 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
# 1243 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1244 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn TRAINER.\p"
# 1245 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1246 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1247 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1248 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four GYM BADGES, okay?$"
# 1249 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1250 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford:
# 1251 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: I see… So, you've beaten\n"
# 1252 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
# 1253 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more TRAINERS\n"
# 1254 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1255 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in DEWFORD TOWN is a\n"
# 1256 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER named BRAWLY.\p"
# 1257 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1258 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1259 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger:
# 1260 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
# 1261 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1262 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of BADGES\n"
# 1263 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1264 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1265 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro:
# 1266 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm…\n"
# 1267 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four GYM BADGES.\p"
# 1268 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1269 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON battle.\p"
# 1270 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1271 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1272 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1273 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1274 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1275 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a GYM LEADER to win.\p"
# 1276 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1277 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1278 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1279 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat:
# 1280 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1281 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1282 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1283 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1284 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1285 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1286 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1287 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge:
# 1288 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the BALANCE BADGE\n"
# 1289 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from DAD!$"
# 1290 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1291 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
# 1292 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: With that BADGE, the DEFENSE\n"
# 1293 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "of all your POKéMON will increase.\p"
# 1294 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON that know the HM move SURF\n"
# 1295 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "will be able to travel over water.\p"
# 1296 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1297 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1298 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1299 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade:
# 1300 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: TM42 contains FACADE.\p"
# 1301 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles the power of moves if\n"
# 1302 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the POKéMON is poisoned, paralyzed,\l"
# 1303 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "or burned.\p"
# 1304 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1305 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1306 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1307 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad:
# 1308 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: As the GYM LEADER, I can't\n"
# 1309 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1310 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1311 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1312 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1313 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe:
# 1314 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1315 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1316 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1317 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1318 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer:
# 1319 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN, you don't mind, do you?\p"
# 1320 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1321 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1322 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1323 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining:
# 1324 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you should go visit\n"
# 1325 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1326 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1327 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1328 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a TRAINER to\n"
# 1329 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1330 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1331 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
# 1332 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, how are things going?\p"
# 1333 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of POKéMON is deep.\p"
# 1334 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1335 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1336 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1337 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice:
# 1338 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 1339 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 1340 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this GYM open when you\n"
# 1341 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting TRAINERS.\p"
# 1342 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1343 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1344 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The TRAINERS of PETALBURG GYM\n"
# 1345 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "use all kinds of items.\p"
# 1346 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1347 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the SPEED ROOM.\p"
# 1348 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1349 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ACCURACY ROOM.\p"
# 1350 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1351 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1352 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1353 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!$"
# 1354 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1355 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory:
# 1356 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1357 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1358 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1359 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1360 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1361 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro:
# 1362 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1363 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1364 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1365 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1366 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1367 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat:
# 1368 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1369 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1370 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle:
# 1371 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1372 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1373 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the CONFUSION ROOM.\p"
# 1374 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the DEFENSE\n"
# 1375 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "ROOM.$"
# 1376 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1377 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge:
# 1378 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1379 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1380 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your POKéMON.\p"
# 1381 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1382 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER is all about.$"
# 1383 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1384 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro:
# 1385 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the CONFUSION ROOM.\p"
# 1386 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1387 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with your POKéMON!$"
# 1388 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1389 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat:
# 1390 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1391 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1392 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1393 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle:
# 1394 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the STRENGTH ROOM.\n"
# 1395 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1396 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1397 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge:
# 1398 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our LEADER, the\n"
# 1399 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1400 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1401 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro:
# 1402 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1403 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1404 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1405 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1406 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1407 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1408 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1409 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat:
# 1410 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1411 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What ATTACK power…$"
# 1412 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1413 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle:
# 1414 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1415 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "our LEADER's kid.\p"
# 1416 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A TRAINER's abilities are\n"
# 1417 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1418 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1419 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1420 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
# 1421 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1422 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge:
# 1423 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at GYMS.\n"
# 1424 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a LEADER.$"
# 1425 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1426 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro:
# 1427 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1428 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our LEADER's kid.\p"
# 1429 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1430 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON to take a critical hit!$"
# 1431 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1432 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat:
# 1433 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1434 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1435 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1436 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle:
# 1437 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1438 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a TRAINER worth my respect.\p"
# 1439 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1440 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1441 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1442 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1443 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1444 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge:
# 1445 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the LEADER,\n"
# 1446 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the TRAINERS of PETALBURG CITY have\l"
# 1447 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1448 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1449 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro:
# 1450 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1451 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the ACCURACY ROOM.\p"
# 1452 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1453 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1454 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1455 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat:
# 1456 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1457 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1458 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle:
# 1459 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1460 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "TRAINERS waiting for you.\p"
# 1461 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the DEFENSE ROOM, and\n"
# 1462 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the RECOVERY ROOM.\p"
# 1463 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your POKéMON's ATTACK power will be\n"
# 1464 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1465 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1466 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge:
# 1467 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1468 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as TRAINERS?\p"
# 1469 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1470 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with our POKéMON.$"
# 1471 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1472 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro:
# 1473 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the DEFENSE, the more\n"
# 1474 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1475 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1476 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat:
# 1477 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1478 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1479 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle:
# 1480 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1481 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1482 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1483 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the STRENGTH ROOM.\p"
# 1484 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1485 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ONE-HIT KO ROOM.\p"
# 1486 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have TRAINERS who are\n"
# 1487 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1488 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1489 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge:
# 1490 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using SURF?$"
# 1491 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1492 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro:
# 1493 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our GYM LEADER told us to go all out\n"
# 1494 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1495 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1496 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "LEADER's kid!$"
# 1497 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1498 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat:
# 1499 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1500 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1501 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle:
# 1502 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your POKéMON…\n"
# 1503 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1504 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The GYM LEADER, your\n"
# 1505 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1506 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1507 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge:
# 1508 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your POKéMON\n"
# 1509 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1510 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1511 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings TRAINERS have\n"
# 1512 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "for their POKéMON.$"
# 1513 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1514 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked:
# 1515 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1516 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1517 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1518 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom:
# 1519 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“SPEED ROOM,” the sign says.\p"
# 1520 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1521 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1522 "data//maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1523 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2:
# 1524 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1525 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1526 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1527 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom:
# 1528 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ACCURACY ROOM,” the sign says.\p"
# 1529 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1530 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1531 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom:
# 1532 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“CONFUSION ROOM,” the sign says.\p"
# 1533 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1534 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1535 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom:
# 1536 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“DEFENSE ROOM,” the sign says.\p"
# 1537 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1538 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1539 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom:
# 1540 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“RECOVERY ROOM,” the sign says.\p"
# 1541 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1542 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1543 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom:
# 1544 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“STRENGTH ROOM,” the sign says.\p"
# 1545 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1546 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1547 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom:
# 1548 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
# 1549 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1550 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1551 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom:
# 1552 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“GYM LEADER'S ROOM\p"
# 1553 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“See for yourself what POKéMON await\n"
# 1554 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "you!” the sign says.\p"
# 1555 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1556 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1557 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue:
# 1558 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM$"
# 1559 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1560 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified:
# 1561 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\p"
# 1562 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
# 1563 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1564 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1565 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch:
# 1566 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1567 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1568 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1569 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1570 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1571 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1572 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1573 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…No, because we are parent and child,\n"
# 1574 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1575 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1576 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1577 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat:
# 1578 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1579 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1580 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1581 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch:
# 1582 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1583 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1584 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1585 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1586 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1587 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1588 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
# 1589 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1590 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1591 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1592 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1593 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1594 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1595 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1596 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm? Wait a second, {PLAYER}.\p"
# 1597 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one POKéMON that is\n"
# 1598 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1599 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1600 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two POKéMON.$"
# 1601 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1602 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_SkipWallyTutorial:
# 1603 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: This is Wally . . .\p"
# 1604 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He is a dumbass . . . \n"
# 1605 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "but he recently caught a Ralts.$"
