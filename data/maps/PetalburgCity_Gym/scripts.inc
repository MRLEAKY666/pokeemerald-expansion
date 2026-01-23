# 1 "data//maps/PetalburgCity_Gym/scripts.pory"

# 2 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_MapScripts::
# 3 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
# 4 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
# 5 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
# 6 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
# 7 "data//maps/PetalburgCity_Gym/scripts.pory"
	.byte 0
# 8 "data//maps/PetalburgCity_Gym/scripts.pory"

# 9 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnLoad:
# 10 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
# 11 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
# 12 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 13 "data//maps/PetalburgCity_Gym/scripts.pory"

# 14 "data//maps/PetalburgCity_Gym/scripts.pory"
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
# 15 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
# 16 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 17 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 18 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 19 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 20 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 21 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 22 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 23 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 24 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 25 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 26 "data//maps/PetalburgCity_Gym/scripts.pory"

# 27 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockAllDoors::
# 28 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 29 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 30 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 31 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 32 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 33 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 34 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 35 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 36 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 37 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 38 "data//maps/PetalburgCity_Gym/scripts.pory"

# 39 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnTransition:
# 40 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 41 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_ResetGymTrainers
# 42 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
# 43 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
# 44 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
# 45 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 46 "data//maps/PetalburgCity_Gym/scripts.pory"

# 47 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
# 48 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_WALLY, 5, 108
# 49 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 50 "data//maps/PetalburgCity_Gym/scripts.pory"

# 51 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
# 52 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
# 53 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 54 "data//maps/PetalburgCity_Gym/scripts.pory"

# 55 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_CheckNormanForRematch::
# 56 "data//maps/PetalburgCity_Gym/scripts.pory"
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
# 57 "data//maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 58 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 59 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 60 "data//maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
# 61 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 62 "data//maps/PetalburgCity_Gym/scripts.pory"

# 63 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
# 64 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 8
# 65 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 66 "data//maps/PetalburgCity_Gym/scripts.pory"

# 67 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnWarp:
# 68 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
# 69 "data//maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 70 "data//maps/PetalburgCity_Gym/scripts.pory"

# 71 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_TurnPlayerNorth::
# 72 "data//maps/PetalburgCity_Gym/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 73 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 74 "data//maps/PetalburgCity_Gym/scripts.pory"

# 75 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnFrame:
# 76 "data//maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
# 77 "data//maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 78 "data//maps/PetalburgCity_Gym/scripts.pory"

# 79 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
# 80 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
# 81 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 82 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 83 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 84 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 85 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
# 86 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 87 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 88 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
# 89 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 90 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_EXIT
# 91 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLY
# 92 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 93 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 94 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 95 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 96 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
# 97 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 2
# 98 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 99 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 100 "data//maps/PetalburgCity_Gym/scripts.pory"

# 101 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitGym:
# 102 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 103 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 104 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 105 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 106 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 107 "data//maps/PetalburgCity_Gym/scripts.pory"

# 108 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Norman::
# 109 "data//maps/PetalburgCity_Gym/scripts.pory"
	vsseeker_rematchid TRAINER_NORMAN_1
# 110 "data//maps/PetalburgCity_Gym/scripts.pory"
	lock
# 111 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 112 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 113 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
# 114 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
# 115 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
# 116 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
# 117 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
# 118 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
# 119 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
# 120 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 121 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 122 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 123 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
# 124 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
# 125 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
# 126 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
# 127 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 128 "data//maps/PetalburgCity_Gym/scripts.pory"

# 129 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
# 130 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 131 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 132 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 133 "data//maps/PetalburgCity_Gym/scripts.pory"

# 134 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
# 135 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 136 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 137 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 138 "data//maps/PetalburgCity_Gym/scripts.pory"

# 139 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
# 140 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 141 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 142 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 143 "data//maps/PetalburgCity_Gym/scripts.pory"

# 144 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
# 145 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 146 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 147 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 148 "data//maps/PetalburgCity_Gym/scripts.pory"

# 149 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial::
# 150 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLY
# 151 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 152 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 153 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 154 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 155 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 156 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 157 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 158 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 159 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 160 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 161 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 162 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 163 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 164 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 165 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 166 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 167 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 168 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 169 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 170 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 171 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 172 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 173 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 174 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 175 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 176 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 177 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 178 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 179 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 180 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 181 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 182 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 183 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 184 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 185 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 186 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 187 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 188 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLY
# 189 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 190 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 191 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 192 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 193 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 194 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 195 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 196 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 197 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 198 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 199 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 200 "data//maps/PetalburgCity_Gym/scripts.pory"

# 201 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SkipWallyTutorial::
# 202 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLY
# 203 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 204 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 205 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 206 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 207 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 208 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 209 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 210 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 211 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 212 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 213 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_SkipWallyTutorial, MSGBOX_DEFAULT
# 214 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 215 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 216 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 217 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 218 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 219 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 220 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 221 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 222 "data//maps/PetalburgCity_Gym/scripts.pory"

# 223 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth::
# 224 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 225 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 226 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 227 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 228 "data//maps/PetalburgCity_Gym/scripts.pory"

# 229 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth::
# 230 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 231 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 232 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 233 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 234 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 235 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 236 "data//maps/PetalburgCity_Gym/scripts.pory"

# 237 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast::
# 238 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 239 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 240 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 241 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 242 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 243 "data//maps/PetalburgCity_Gym/scripts.pory"

# 244 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
# 245 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 246 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 247 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 248 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 249 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 250 "data//maps/PetalburgCity_Gym/scripts.pory"

# 251 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
# 252 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 253 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 254 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 255 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 256 "data//maps/PetalburgCity_Gym/scripts.pory"

# 257 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
# 258 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 259 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 260 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 261 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 262 "data//maps/PetalburgCity_Gym/scripts.pory"

# 263 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
# 264 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 265 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 266 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 267 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 268 "data//maps/PetalburgCity_Gym/scripts.pory"

# 269 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
# 270 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
# 271 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 272 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 273 "data//maps/PetalburgCity_Gym/scripts.pory"

# 274 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
# 275 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 276 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 277 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 278 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 279 "data//maps/PetalburgCity_Gym/scripts.pory"

# 280 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
# 281 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 282 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 283 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 284 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 285 "data//maps/PetalburgCity_Gym/scripts.pory"

# 286 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
# 287 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 288 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 289 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 290 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 291 "data//maps/PetalburgCity_Gym/scripts.pory"

# 292 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
# 293 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 294 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 295 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 296 "data//maps/PetalburgCity_Gym/scripts.pory"

# 297 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
# 298 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 299 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 300 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 301 "data//maps/PetalburgCity_Gym/scripts.pory"

# 302 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
# 303 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 304 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 305 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 306 "data//maps/PetalburgCity_Gym/scripts.pory"

# 307 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
# 308 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 309 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 310 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 311 "data//maps/PetalburgCity_Gym/scripts.pory"

# 312 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer::
# 313 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
# 314 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 315 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 316 "data//maps/PetalburgCity_Gym/scripts.pory"

# 317 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown::
# 318 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
# 319 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 320 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 321 "data//maps/PetalburgCity_Gym/scripts.pory"

# 322 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanNoBadges::
# 323 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 324 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 325 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 326 "data//maps/PetalburgCity_Gym/scripts.pory"

# 327 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanOneBadge::
# 328 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 329 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 330 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 331 "data//maps/PetalburgCity_Gym/scripts.pory"

# 332 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanTwoBadges::
# 333 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 334 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 335 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 336 "data//maps/PetalburgCity_Gym/scripts.pory"

# 337 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanThreeBadges::
# 338 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 339 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 340 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 341 "data//maps/PetalburgCity_Gym/scripts.pory"

# 342 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
# 343 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 344 "data//maps/PetalburgCity_Gym/scripts.pory"

# 345 "data//maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 346 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
# 347 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 348 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 349 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 350 "data//maps/PetalburgCity_Gym/scripts.pory"

# 351 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
# 352 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 353 "data//maps/PetalburgCity_Gym/scripts.pory"

# 354 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
# 355 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 356 "data//maps/PetalburgCity_Gym/scripts.pory"

# 357 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanPostBattle::
# 358 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
# 359 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
# 360 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
# 361 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
# 362 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 363 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 364 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 365 "data//maps/PetalburgCity_Gym/scripts.pory"

# 366 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2::
# 367 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 368 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 369 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 370 "data//maps/PetalburgCity_Gym/scripts.pory"

# 371 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanRematch::
# 372 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
# 373 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 374 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 375 "data//maps/PetalburgCity_Gym/scripts.pory"

# 376 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
# 377 "data//maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 378 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 379 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY_E_READER
# 380 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 381 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
# 382 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 383 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 384 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 385 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 386 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 387 "data//maps/PetalburgCity_Gym/scripts.pory"

# 388 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
# 389 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 390 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 391 "data//maps/PetalburgCity_Gym/scripts.pory"

# 392 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
# 393 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY_E_READER
# 394 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 395 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 396 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 397 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 398 "data//maps/PetalburgCity_Gym/scripts.pory"

# 399 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 400 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 401 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 402 "data//maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 403 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 404 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 405 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 406 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 407 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 408 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 409 "data//maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 410 "data//maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 411 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 412 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 413 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 414 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 415 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 416 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 417 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 418 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 419 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 420 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 421 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 422 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 423 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 424 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 425 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 426 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 427 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 428 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 429 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 430 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 431 "data//maps/PetalburgCity_Gym/scripts.pory"

# 432 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade::
# 433 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_TM_FACADE, 5
# 434 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 435 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_FACADE
# 436 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
# 437 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 438 "data//maps/PetalburgCity_Gym/scripts.pory"

# 439 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
# 440 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 441 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 442 "data//maps/PetalburgCity_Gym/scripts.pory"

# 443 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
# 444 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 445 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 446 "data//maps/PetalburgCity_Gym/scripts.pory"

# 447 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
# 448 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 449 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 450 "data//maps/PetalburgCity_Gym/scripts.pory"

# 451 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives::
# 452 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 453 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 454 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 455 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
# 456 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 457 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
# 458 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 459 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 460 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 461 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 462 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 463 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 464 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 465 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 466 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 467 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 468 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 469 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 470 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 471 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 472 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 473 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 474 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 475 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 476 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 477 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 478 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 479 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 480 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 481 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 482 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 483 "data//maps/PetalburgCity_Gym/scripts.pory"

# 484 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
# 485 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
# 486 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 487 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 488 "data//maps/PetalburgCity_Gym/scripts.pory"

# 489 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
# 490 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
# 491 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 492 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 493 "data//maps/PetalburgCity_Gym/scripts.pory"

# 494 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
# 495 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
# 496 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 497 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 498 "data//maps/PetalburgCity_Gym/scripts.pory"

# 499 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
# 500 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 501 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 502 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 503 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 504 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 505 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 506 "data//maps/PetalburgCity_Gym/scripts.pory"

# 507 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
# 508 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 509 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 510 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 511 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 512 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 513 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 514 "data//maps/PetalburgCity_Gym/scripts.pory"

# 515 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
# 516 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 517 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 518 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 519 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 520 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 521 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 522 "data//maps/PetalburgCity_Gym/scripts.pory"

# 523 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
# 524 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 525 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 526 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 527 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 528 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 529 "data//maps/PetalburgCity_Gym/scripts.pory"

# 530 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
# 531 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 532 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 533 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 534 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 535 "data//maps/PetalburgCity_Gym/scripts.pory"

# 536 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
# 537 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 538 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 539 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 540 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 541 "data//maps/PetalburgCity_Gym/scripts.pory"

# 542 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth:
# 543 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 544 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 545 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 546 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 547 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 548 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 549 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 550 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 551 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 552 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 553 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 554 "data//maps/PetalburgCity_Gym/scripts.pory"

# 555 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast:
# 556 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 557 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 558 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 559 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 560 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 561 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 562 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 563 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 564 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 565 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 566 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 567 "data//maps/PetalburgCity_Gym/scripts.pory"

# 568 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest:
# 569 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 570 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 571 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 572 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 573 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 574 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 575 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 576 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 577 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 578 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 579 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 580 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 581 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 582 "data//maps/PetalburgCity_Gym/scripts.pory"

# 583 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
# 584 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 585 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 586 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 587 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 588 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 589 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 590 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 591 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 592 "data//maps/PetalburgCity_Gym/scripts.pory"

# 593 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
# 594 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 595 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 596 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 597 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 598 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 599 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 600 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 601 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 602 "data//maps/PetalburgCity_Gym/scripts.pory"

# 603 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
# 604 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 605 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 606 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 607 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 608 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 609 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 610 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 611 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 612 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 613 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 614 "data//maps/PetalburgCity_Gym/scripts.pory"

# 615 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym:
# 616 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 617 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 618 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 619 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 620 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 621 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 622 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 623 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 624 "data//maps/PetalburgCity_Gym/scripts.pory"

# 625 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
# 626 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 627 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 628 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 629 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 630 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 631 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 632 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 633 "data//maps/PetalburgCity_Gym/scripts.pory"

# 634 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
# 635 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 636 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 637 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 638 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 639 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 640 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 641 "data//maps/PetalburgCity_Gym/scripts.pory"

# 642 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
# 643 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 644 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 645 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 646 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 647 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 648 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 649 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 650 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 651 "data//maps/PetalburgCity_Gym/scripts.pory"

# 652 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused:
# 653 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 654 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 655 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 656 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 657 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 658 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 659 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 660 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 661 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 662 "data//maps/PetalburgCity_Gym/scripts.pory"

# 663 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth:
# 664 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 665 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 666 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 667 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 668 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 669 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 670 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 671 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 672 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 673 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 674 "data//maps/PetalburgCity_Gym/scripts.pory"

# 675 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive:
# 676 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 677 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 678 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 679 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 680 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 681 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 682 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 683 "data//maps/PetalburgCity_Gym/scripts.pory"

# 684 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth:
# 685 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 686 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 687 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 688 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 689 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 690 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 691 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 692 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 693 "data//maps/PetalburgCity_Gym/scripts.pory"

# 694 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast:
# 695 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 696 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 697 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 698 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 699 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 700 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 701 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 702 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 703 "data//maps/PetalburgCity_Gym/scripts.pory"

# 704 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest:
# 705 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 706 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 707 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 708 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 709 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 710 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 711 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 712 "data//maps/PetalburgCity_Gym/scripts.pory"

# 713 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
# 714 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 715 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 716 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 717 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 718 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 719 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 720 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 721 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 722 "data//maps/PetalburgCity_Gym/scripts.pory"

# 723 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
# 724 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 725 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 726 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 727 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 728 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 729 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 730 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 731 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 732 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 733 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 734 "data//maps/PetalburgCity_Gym/scripts.pory"

# 735 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
# 736 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 737 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 738 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 739 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 740 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 741 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 742 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 743 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 744 "data//maps/PetalburgCity_Gym/scripts.pory"

# 745 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
# 746 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 747 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 748 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 749 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 750 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 751 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 752 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 753 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 754 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 755 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 756 "data//maps/PetalburgCity_Gym/scripts.pory"

# 757 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
# 758 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
# 759 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 760 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 761 "data//maps/PetalburgCity_Gym/scripts.pory"

# 762 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor::
# 763 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 764 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 765 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 766 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 767 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 768 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 769 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 770 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 771 "data//maps/PetalburgCity_Gym/scripts.pory"

# 772 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom::
# 773 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 774 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 775 "data//maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
# 776 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 777 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 778 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 779 "data//maps/PetalburgCity_Gym/scripts.pory"

# 780 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom::
# 781 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 782 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 783 "data//maps/PetalburgCity_Gym/scripts.pory"

# 784 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked::
# 785 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 786 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 787 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 788 "data//maps/PetalburgCity_Gym/scripts.pory"

# 789 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 790 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
# 791 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 792 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 793 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 794 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 795 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 796 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 797 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 798 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 799 "data//maps/PetalburgCity_Gym/scripts.pory"

# 800 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
# 801 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 802 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 803 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 804 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 805 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 806 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 807 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 808 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 809 "data//maps/PetalburgCity_Gym/scripts.pory"

# 810 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
# 811 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 812 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 813 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 814 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 815 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 816 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 817 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 818 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 819 "data//maps/PetalburgCity_Gym/scripts.pory"

# 820 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
# 821 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 822 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 823 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 824 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 825 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 826 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 827 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 828 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 829 "data//maps/PetalburgCity_Gym/scripts.pory"

# 830 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
# 831 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 832 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 833 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 834 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 835 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 836 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 837 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 838 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 839 "data//maps/PetalburgCity_Gym/scripts.pory"

# 840 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
# 841 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 842 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 843 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 844 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 845 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 846 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 847 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 848 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 849 "data//maps/PetalburgCity_Gym/scripts.pory"

# 850 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
# 851 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 852 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 853 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 854 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 855 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 856 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 857 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 858 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 859 "data//maps/PetalburgCity_Gym/scripts.pory"

# 860 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
# 861 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 862 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 863 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 864 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 865 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 866 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 867 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 868 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 869 "data//maps/PetalburgCity_Gym/scripts.pory"

# 870 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
# 871 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 872 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 873 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 874 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 875 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 876 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 877 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 878 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 879 "data//maps/PetalburgCity_Gym/scripts.pory"

# 880 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
# 881 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 882 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 883 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 884 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 885 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 886 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 887 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 888 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 889 "data//maps/PetalburgCity_Gym/scripts.pory"

# 890 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
# 891 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 892 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 893 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 894 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 895 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 896 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 897 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 898 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 899 "data//maps/PetalburgCity_Gym/scripts.pory"

# 900 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall::
# 901 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 902 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 903 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 904 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 905 "data//maps/PetalburgCity_Gym/scripts.pory"

# 906 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
# 907 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 908 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 909 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 910 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 911 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 912 "data//maps/PetalburgCity_Gym/scripts.pory"

# 913 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge::
# 914 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 915 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 916 "data//maps/PetalburgCity_Gym/scripts.pory"

# 917 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker::
# 918 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 919 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 920 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 921 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 922 "data//maps/PetalburgCity_Gym/scripts.pory"

# 923 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
# 924 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 925 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 926 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 927 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 928 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 929 "data//maps/PetalburgCity_Gym/scripts.pory"

# 930 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge::
# 931 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 932 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 933 "data//maps/PetalburgCity_Gym/scripts.pory"

# 934 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George::
# 935 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 936 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 937 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 938 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 939 "data//maps/PetalburgCity_Gym/scripts.pory"

# 940 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
# 941 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 942 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 943 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 944 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 945 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 946 "data//maps/PetalburgCity_Gym/scripts.pory"

# 947 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge::
# 948 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 949 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 950 "data//maps/PetalburgCity_Gym/scripts.pory"

# 951 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke::
# 952 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 953 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 954 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 955 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 956 "data//maps/PetalburgCity_Gym/scripts.pory"

# 957 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
# 958 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 959 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 960 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 961 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 962 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 963 "data//maps/PetalburgCity_Gym/scripts.pory"

# 964 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge::
# 965 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 966 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 967 "data//maps/PetalburgCity_Gym/scripts.pory"

# 968 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary::
# 969 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 970 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 971 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 972 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 973 "data//maps/PetalburgCity_Gym/scripts.pory"

# 974 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
# 975 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 976 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 977 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 978 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 979 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 980 "data//maps/PetalburgCity_Gym/scripts.pory"

# 981 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge::
# 982 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 983 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 984 "data//maps/PetalburgCity_Gym/scripts.pory"

# 985 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia::
# 986 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 987 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 988 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 989 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 990 "data//maps/PetalburgCity_Gym/scripts.pory"

# 991 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
# 992 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 993 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 994 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 995 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 996 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 997 "data//maps/PetalburgCity_Gym/scripts.pory"

# 998 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge::
# 999 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 1000 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1001 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1002 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody::
# 1003 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 1004 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 1005 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 1006 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1007 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1008 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
# 1009 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1010 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 1011 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1012 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1013 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1014 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1015 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge::
# 1016 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 1017 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1018 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1019 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 1020 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 1021 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
# 1022 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 1023 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1024 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1025 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1026 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1027 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1028 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
# 1029 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1030 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1031 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1032 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1033 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1034 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1035 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
# 1036 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1037 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1038 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1039 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1040 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1041 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1042 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
# 1043 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1044 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1045 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1046 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1047 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1048 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1049 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
# 1050 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1051 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1052 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1053 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1054 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1055 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1056 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
# 1057 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1058 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1059 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1060 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1061 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1062 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1063 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
# 1064 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1065 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1066 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1067 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1068 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1069 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1070 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
# 1071 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1072 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1073 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1074 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1075 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1076 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1077 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
# 1078 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1079 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1080 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1081 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1082 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1083 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1084 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
# 1085 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1086 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1087 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1088 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1089 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1090 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1091 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
# 1092 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1093 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1094 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1095 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1096 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1097 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1098 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
# 1099 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1100 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1101 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1102 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1103 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
# 1104 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1105 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1106 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1107 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1108 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1109 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1110 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
# 1111 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1112 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1113 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1114 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1115 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
# 1116 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1117 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1118 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1119 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1120 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
# 1121 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1122 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1123 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1124 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1125 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
# 1126 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1127 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1128 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1129 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1130 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors::
# 1131 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1132 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1133 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1134 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide::
# 1135 "data//maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1136 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1137 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1138 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 1139 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1140 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1141 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1142 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory::
# 1143 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1144 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1145 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1146 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1147 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue::
# 1148 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1149 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1150 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1151 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1152 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1153 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue::
# 1154 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1155 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1156 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1157 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1158 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1159 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified::
# 1160 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1161 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1162 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1163 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1164 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue::
# 1165 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1166 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1167 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1168 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1169 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
# 1170 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm?\p"
# 1171 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1172 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1173 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1174 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.$"
# 1175 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1176 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
# 1177 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1178 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a POKéMON, please…$"
# 1179 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1180 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight:
# 1181 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
# 1182 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're WALLY, right?$"
# 1183 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1184 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
# 1185 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: I'm going to go stay with my\n"
# 1186 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in VERDANTURF TOWN.\p"
# 1187 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1188 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a POKéMON along.\p"
# 1189 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a POKéMON before.\n"
# 1190 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1191 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1192 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee:
# 1193 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hmm . . . \p"
# 1194 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I see . . . $"
# 1195 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1196 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally:
# 1197 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you heard that,\n"
# 1198 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1199 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with WALLY and make sure that he\n"
# 1200 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a POKéMON.$"
# 1201 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1202 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
# 1203 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY, here, I'll loan you my POKéMON.\p"
# 1204 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a ZIGZAGOON!$"
# 1205 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1206 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
# 1207 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1208 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "A POKéMON!\p"
# 1209 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
# 1210 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1211 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a POKé BALL!$"
# 1212 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1213 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou:
# 1214 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1215 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1216 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1217 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
# 1218 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1219 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1220 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1221 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut:
# 1222 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Watch out for each other\n"
# 1223 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "if you're travelling$"
# 1224 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1225 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye:
# 1226 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: . . .\n"
# 1227 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have to go . . .\p"
# 1228 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "See you around, {PLAYER}.$"
# 1229 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1230 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges:
# 1231 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for RUSTBORO CITY beyond this\n"
# 1232 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1233 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1234 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER, ROXANNE.\p"
# 1235 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm a GYM LEADER, too.\n"
# 1236 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER} . . .\p"
# 1237 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Only after you become stronger.$"
# 1238 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1239 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro:
# 1240 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? Aren't you going to the\n"
# 1241 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
# 1242 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1243 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn TRAINER.\p"
# 1244 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1245 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1246 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1247 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four GYM BADGES, okay?$"
# 1248 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1249 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford:
# 1250 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: I see… So, you've beaten\n"
# 1251 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
# 1252 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more TRAINERS\n"
# 1253 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1254 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in DEWFORD TOWN is a\n"
# 1255 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER named BRAWLY.\p"
# 1256 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1257 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1258 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger:
# 1259 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
# 1260 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1261 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of BADGES\n"
# 1262 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1263 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1264 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro:
# 1265 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm…\n"
# 1266 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four GYM BADGES.\p"
# 1267 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1268 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON battle.\p"
# 1269 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1270 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1271 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1272 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1273 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1274 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a GYM LEADER to win.\p"
# 1275 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1276 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1277 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1278 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat:
# 1279 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1280 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1281 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1282 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1283 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1284 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1285 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1286 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge:
# 1287 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the BALANCE BADGE\n"
# 1288 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from DAD!$"
# 1289 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1290 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
# 1291 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON that know the HM move SURF\n"
# 1292 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "will now be able to travel over water.\p"
# 1293 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1294 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1295 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1296 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade:
# 1297 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: TM42 contains FACADE.\p"
# 1298 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles the power of moves if\n"
# 1299 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the POKéMON is poisoned, paralyzed,\l"
# 1300 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "or burned.\p"
# 1301 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1302 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1303 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1304 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad:
# 1305 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: As the GYM LEADER, I can't\n"
# 1306 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1307 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1308 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1309 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1310 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe:
# 1311 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1312 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1313 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1314 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1315 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer:
# 1316 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN, you don't mind, do you?\p"
# 1317 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1318 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1319 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1320 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining:
# 1321 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you should go visit\n"
# 1322 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1323 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1324 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1325 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a TRAINER to\n"
# 1326 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1327 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1328 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
# 1329 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, how are things going?\p"
# 1330 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of POKéMON is deep.\p"
# 1331 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1332 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1333 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1334 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice:
# 1335 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 1336 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 1337 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this GYM open when you\n"
# 1338 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting TRAINERS.\p"
# 1339 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1340 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1341 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The TRAINERS of PETALBURG GYM\n"
# 1342 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "use all kinds of items.\p"
# 1343 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1344 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the SPEED ROOM.\p"
# 1345 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1346 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ACCURACY ROOM.\p"
# 1347 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1348 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1349 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1350 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!$"
# 1351 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1352 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory:
# 1353 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1354 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1355 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1356 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1357 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1358 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro:
# 1359 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1360 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1361 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1362 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1363 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1364 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat:
# 1365 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1366 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1367 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle:
# 1368 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1369 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1370 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the CONFUSION ROOM.\p"
# 1371 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the DEFENSE\n"
# 1372 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "ROOM.$"
# 1373 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1374 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge:
# 1375 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1376 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1377 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your POKéMON.\p"
# 1378 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1379 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER is all about.$"
# 1380 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1381 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro:
# 1382 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the CONFUSION ROOM.\p"
# 1383 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1384 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with your POKéMON!$"
# 1385 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1386 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat:
# 1387 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1388 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1389 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1390 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle:
# 1391 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the STRENGTH ROOM.\n"
# 1392 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1393 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1394 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge:
# 1395 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our LEADER, the\n"
# 1396 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1397 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1398 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro:
# 1399 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1400 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1401 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1402 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1403 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1404 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1405 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1406 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat:
# 1407 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1408 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What ATTACK power…$"
# 1409 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1410 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle:
# 1411 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1412 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "our LEADER's kid.\p"
# 1413 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A TRAINER's abilities are\n"
# 1414 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1415 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1416 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1417 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
# 1418 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1419 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge:
# 1420 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at GYMS.\n"
# 1421 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a LEADER.$"
# 1422 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1423 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro:
# 1424 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1425 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our LEADER's kid.\p"
# 1426 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1427 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON to take a critical hit!$"
# 1428 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1429 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat:
# 1430 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1431 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1432 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1433 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle:
# 1434 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1435 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a TRAINER worth my respect.\p"
# 1436 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1437 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1438 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1439 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1440 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1441 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge:
# 1442 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the LEADER,\n"
# 1443 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the TRAINERS of PETALBURG CITY have\l"
# 1444 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1445 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1446 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro:
# 1447 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1448 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the ACCURACY ROOM.\p"
# 1449 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1450 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1451 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1452 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat:
# 1453 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1454 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1455 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle:
# 1456 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1457 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "TRAINERS waiting for you.\p"
# 1458 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the DEFENSE ROOM, and\n"
# 1459 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the RECOVERY ROOM.\p"
# 1460 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your POKéMON's ATTACK power will be\n"
# 1461 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1462 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1463 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge:
# 1464 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1465 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as TRAINERS?\p"
# 1466 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1467 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with our POKéMON.$"
# 1468 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1469 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro:
# 1470 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the DEFENSE, the more\n"
# 1471 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1472 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1473 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat:
# 1474 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1475 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1476 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle:
# 1477 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1478 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1479 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1480 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the STRENGTH ROOM.\p"
# 1481 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1482 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ONE-HIT KO ROOM.\p"
# 1483 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have TRAINERS who are\n"
# 1484 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1485 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1486 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge:
# 1487 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using SURF?$"
# 1488 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1489 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro:
# 1490 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our GYM LEADER told us to go all out\n"
# 1491 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1492 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1493 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "LEADER's kid!$"
# 1494 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1495 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat:
# 1496 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1497 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1498 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle:
# 1499 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your POKéMON…\n"
# 1500 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1501 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The GYM LEADER, your\n"
# 1502 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1503 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1504 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge:
# 1505 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your POKéMON\n"
# 1506 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1507 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1508 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings TRAINERS have\n"
# 1509 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "for their POKéMON.$"
# 1510 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1511 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked:
# 1512 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1513 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1514 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1515 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom:
# 1516 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“SPEED ROOM,” the sign says.\p"
# 1517 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1518 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1519 "data//maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1520 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2:
# 1521 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1522 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1523 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1524 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom:
# 1525 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ACCURACY ROOM,” the sign says.\p"
# 1526 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1527 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1528 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom:
# 1529 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“CONFUSION ROOM,” the sign says.\p"
# 1530 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1531 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1532 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom:
# 1533 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“DEFENSE ROOM,” the sign says.\p"
# 1534 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1535 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1536 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom:
# 1537 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“RECOVERY ROOM,” the sign says.\p"
# 1538 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1539 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1540 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom:
# 1541 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“STRENGTH ROOM,” the sign says.\p"
# 1542 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1543 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1544 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom:
# 1545 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
# 1546 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1547 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1548 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom:
# 1549 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“GYM LEADER'S ROOM\p"
# 1550 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“See for yourself what POKéMON await\n"
# 1551 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "you!” the sign says.\p"
# 1552 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1553 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1554 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue:
# 1555 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM$"
# 1556 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1557 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified:
# 1558 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\p"
# 1559 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
# 1560 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1561 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1562 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch:
# 1563 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1564 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1565 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1566 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1567 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1568 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1569 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1570 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…No, because we are parent and child,\n"
# 1571 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1572 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1573 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1574 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat:
# 1575 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1576 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1577 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1578 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch:
# 1579 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1580 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1581 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1582 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1583 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1584 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1585 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
# 1586 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1587 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1588 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1589 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1590 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1591 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1592 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1593 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm? Wait a second, {PLAYER}.\p"
# 1594 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one POKéMON that is\n"
# 1595 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1596 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1597 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two POKéMON.$"
# 1598 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1599 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_SkipWallyTutorial:
# 1600 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: This is Wally . . .\p"
# 1601 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He is a dumbass . . . \n"
# 1602 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "but he recently caught a Ralts.$"
