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
	lock
# 110 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 111 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 112 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
# 113 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
# 114 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
# 115 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
# 116 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
# 117 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
# 118 "data//maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
# 119 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 120 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 121 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 122 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
# 123 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
# 124 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
# 125 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
# 126 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 127 "data//maps/PetalburgCity_Gym/scripts.pory"

# 128 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
# 129 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 130 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 131 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 132 "data//maps/PetalburgCity_Gym/scripts.pory"

# 133 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
# 134 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 135 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 136 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 137 "data//maps/PetalburgCity_Gym/scripts.pory"

# 138 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
# 139 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 140 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 141 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 142 "data//maps/PetalburgCity_Gym/scripts.pory"

# 143 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
# 144 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 145 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SkipWallyTutorial
# 146 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 147 "data//maps/PetalburgCity_Gym/scripts.pory"

# 148 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial::
# 149 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLY
# 150 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 151 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 152 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 153 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 154 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 155 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 156 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 157 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 158 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 159 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 160 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 161 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 162 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 163 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 164 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 165 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 166 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 167 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 168 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 169 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 170 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 171 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 172 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 173 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 174 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 175 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 176 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 177 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 178 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 179 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 180 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 181 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 182 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 183 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 184 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 185 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 186 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 187 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLY
# 188 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 189 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 190 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 191 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 192 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 193 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 194 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 195 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 196 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 197 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 198 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 199 "data//maps/PetalburgCity_Gym/scripts.pory"

# 200 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SkipWallyTutorial::
# 201 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLY
# 202 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 203 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 204 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 205 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 206 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 207 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 208 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 209 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 210 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 211 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 212 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_SkipWallyTutorial, MSGBOX_DEFAULT
# 213 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 214 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 215 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 3
# 216 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 217 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 218 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 219 "data//maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 220 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 221 "data//maps/PetalburgCity_Gym/scripts.pory"

# 222 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth::
# 223 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 224 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 225 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 226 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 227 "data//maps/PetalburgCity_Gym/scripts.pory"

# 228 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth::
# 229 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 230 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 231 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 232 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 233 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 234 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 235 "data//maps/PetalburgCity_Gym/scripts.pory"

# 236 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast::
# 237 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 238 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 239 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 240 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 241 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 242 "data//maps/PetalburgCity_Gym/scripts.pory"

# 243 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
# 244 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 245 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 246 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 247 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 248 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 249 "data//maps/PetalburgCity_Gym/scripts.pory"

# 250 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
# 251 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 252 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 253 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 254 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 255 "data//maps/PetalburgCity_Gym/scripts.pory"

# 256 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
# 257 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 258 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 259 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 260 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 261 "data//maps/PetalburgCity_Gym/scripts.pory"

# 262 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
# 263 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 264 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 265 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 266 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 267 "data//maps/PetalburgCity_Gym/scripts.pory"

# 268 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
# 269 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
# 270 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 271 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 272 "data//maps/PetalburgCity_Gym/scripts.pory"

# 273 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
# 274 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 275 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 276 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 277 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 278 "data//maps/PetalburgCity_Gym/scripts.pory"

# 279 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
# 280 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 281 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 282 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 283 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 284 "data//maps/PetalburgCity_Gym/scripts.pory"

# 285 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
# 286 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 287 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 288 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 289 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 290 "data//maps/PetalburgCity_Gym/scripts.pory"

# 291 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
# 292 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 293 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 294 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 295 "data//maps/PetalburgCity_Gym/scripts.pory"

# 296 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
# 297 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 298 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 299 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 300 "data//maps/PetalburgCity_Gym/scripts.pory"

# 301 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
# 302 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 303 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 304 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 305 "data//maps/PetalburgCity_Gym/scripts.pory"

# 306 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
# 307 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 308 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 309 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 310 "data//maps/PetalburgCity_Gym/scripts.pory"

# 311 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer::
# 312 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
# 313 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 314 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 315 "data//maps/PetalburgCity_Gym/scripts.pory"

# 316 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown::
# 317 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
# 318 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 319 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 320 "data//maps/PetalburgCity_Gym/scripts.pory"

# 321 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanNoBadges::
# 322 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 323 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 324 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 325 "data//maps/PetalburgCity_Gym/scripts.pory"

# 326 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanOneBadge::
# 327 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 328 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 329 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 330 "data//maps/PetalburgCity_Gym/scripts.pory"

# 331 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanTwoBadges::
# 332 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 333 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 334 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 335 "data//maps/PetalburgCity_Gym/scripts.pory"

# 336 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanThreeBadges::
# 337 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 338 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 339 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 340 "data//maps/PetalburgCity_Gym/scripts.pory"

# 341 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
# 342 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 343 "data//maps/PetalburgCity_Gym/scripts.pory"

# 344 "data//maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 345 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
# 346 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 347 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 348 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 349 "data//maps/PetalburgCity_Gym/scripts.pory"

# 350 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
# 351 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 352 "data//maps/PetalburgCity_Gym/scripts.pory"

# 353 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
# 354 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 355 "data//maps/PetalburgCity_Gym/scripts.pory"

# 356 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanPostBattle::
# 357 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
# 358 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
# 359 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
# 360 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
# 361 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 362 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 363 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 364 "data//maps/PetalburgCity_Gym/scripts.pory"

# 365 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2::
# 366 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 367 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 368 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 369 "data//maps/PetalburgCity_Gym/scripts.pory"

# 370 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanRematch::
# 371 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
# 372 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 373 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 374 "data//maps/PetalburgCity_Gym/scripts.pory"

# 375 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
# 376 "data//maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 377 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 378 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY_E_READER
# 379 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 380 "data//maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
# 381 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 382 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 383 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 384 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 385 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 386 "data//maps/PetalburgCity_Gym/scripts.pory"

# 387 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
# 388 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 389 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 390 "data//maps/PetalburgCity_Gym/scripts.pory"

# 391 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
# 392 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY_E_READER
# 393 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 394 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 395 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 396 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 397 "data//maps/PetalburgCity_Gym/scripts.pory"

# 398 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 399 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 400 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 401 "data//maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 402 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 403 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 404 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 405 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 406 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 407 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 408 "data//maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 409 "data//maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 410 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 411 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 412 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 413 "data//maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 414 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 415 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 416 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 417 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 418 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 419 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 420 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 421 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 422 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 423 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 424 "data//maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 425 "data//maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 426 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 427 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 428 "data//maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 429 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 430 "data//maps/PetalburgCity_Gym/scripts.pory"

# 431 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade::
# 432 "data//maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_TM_FACADE, 5
# 433 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 434 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_FACADE
# 435 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
# 436 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 437 "data//maps/PetalburgCity_Gym/scripts.pory"

# 438 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
# 439 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 440 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 441 "data//maps/PetalburgCity_Gym/scripts.pory"

# 442 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
# 443 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 444 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 445 "data//maps/PetalburgCity_Gym/scripts.pory"

# 446 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
# 447 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 448 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 449 "data//maps/PetalburgCity_Gym/scripts.pory"

# 450 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives::
# 451 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 452 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 453 "data//maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 454 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
# 455 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 456 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
# 457 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 458 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 459 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 460 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 461 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 462 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 463 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 464 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 465 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 466 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 467 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 468 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 469 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 470 "data//maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 471 "data//maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 472 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 473 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 474 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 475 "data//maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
# 476 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 477 "data//maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 478 "data//maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 479 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 480 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 481 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 482 "data//maps/PetalburgCity_Gym/scripts.pory"

# 483 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
# 484 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
# 485 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 486 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 487 "data//maps/PetalburgCity_Gym/scripts.pory"

# 488 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
# 489 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
# 490 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 491 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 492 "data//maps/PetalburgCity_Gym/scripts.pory"

# 493 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
# 494 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
# 495 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 496 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 497 "data//maps/PetalburgCity_Gym/scripts.pory"

# 498 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
# 499 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 500 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 501 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 502 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 503 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 504 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 505 "data//maps/PetalburgCity_Gym/scripts.pory"

# 506 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
# 507 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 508 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 509 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 510 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 511 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 512 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 513 "data//maps/PetalburgCity_Gym/scripts.pory"

# 514 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
# 515 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 516 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 517 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 518 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 519 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 520 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 521 "data//maps/PetalburgCity_Gym/scripts.pory"

# 522 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
# 523 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 524 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 525 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 526 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 527 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 528 "data//maps/PetalburgCity_Gym/scripts.pory"

# 529 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
# 530 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 531 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 532 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 533 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 534 "data//maps/PetalburgCity_Gym/scripts.pory"

# 535 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
# 536 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 537 "data//maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 538 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 539 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 540 "data//maps/PetalburgCity_Gym/scripts.pory"

# 541 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth:
# 542 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 543 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 544 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 545 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 546 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 547 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 548 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 549 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 550 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 551 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 552 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 553 "data//maps/PetalburgCity_Gym/scripts.pory"

# 554 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast:
# 555 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 556 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 557 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 558 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 559 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 560 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 561 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 562 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 563 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 564 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 565 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 566 "data//maps/PetalburgCity_Gym/scripts.pory"

# 567 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest:
# 568 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 569 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 570 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 571 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 572 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 573 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 574 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 575 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 576 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 577 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 578 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 579 "data//maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 580 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 581 "data//maps/PetalburgCity_Gym/scripts.pory"

# 582 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
# 583 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 584 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 585 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 586 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 587 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 588 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 589 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 590 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 591 "data//maps/PetalburgCity_Gym/scripts.pory"

# 592 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
# 593 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 594 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 595 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 596 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 597 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 598 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 599 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 600 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 601 "data//maps/PetalburgCity_Gym/scripts.pory"

# 602 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
# 603 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 604 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 605 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 606 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 607 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 608 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 609 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 610 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 611 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 612 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 613 "data//maps/PetalburgCity_Gym/scripts.pory"

# 614 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym:
# 615 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 616 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 617 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 618 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 619 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 620 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 621 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 622 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 623 "data//maps/PetalburgCity_Gym/scripts.pory"

# 624 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
# 625 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 626 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 627 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 628 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 629 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 630 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 631 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 632 "data//maps/PetalburgCity_Gym/scripts.pory"

# 633 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
# 634 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 635 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 636 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 637 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 638 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 639 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 640 "data//maps/PetalburgCity_Gym/scripts.pory"

# 641 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
# 642 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 643 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 644 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 645 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 646 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 647 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 648 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 649 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 650 "data//maps/PetalburgCity_Gym/scripts.pory"

# 651 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused:
# 652 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 653 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 654 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 655 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 656 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 657 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 658 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 659 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 660 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 661 "data//maps/PetalburgCity_Gym/scripts.pory"

# 662 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth:
# 663 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 664 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 665 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 666 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 667 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 668 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 669 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 670 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 671 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 672 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 673 "data//maps/PetalburgCity_Gym/scripts.pory"

# 674 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive:
# 675 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 676 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 677 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 678 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 679 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 680 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 681 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 682 "data//maps/PetalburgCity_Gym/scripts.pory"

# 683 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth:
# 684 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 685 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 686 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 687 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 688 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 689 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 690 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 691 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 692 "data//maps/PetalburgCity_Gym/scripts.pory"

# 693 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast:
# 694 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 695 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 696 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 697 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 698 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 699 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 700 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 701 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 702 "data//maps/PetalburgCity_Gym/scripts.pory"

# 703 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest:
# 704 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 705 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 706 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 707 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 708 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 709 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 710 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 711 "data//maps/PetalburgCity_Gym/scripts.pory"

# 712 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
# 713 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 714 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 715 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 716 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 717 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 718 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 719 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 720 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 721 "data//maps/PetalburgCity_Gym/scripts.pory"

# 722 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
# 723 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 724 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 725 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 726 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 727 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 728 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 729 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 730 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 731 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 732 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 733 "data//maps/PetalburgCity_Gym/scripts.pory"

# 734 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
# 735 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 736 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 737 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 738 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 739 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 740 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 741 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 742 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 743 "data//maps/PetalburgCity_Gym/scripts.pory"

# 744 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
# 745 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 746 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 747 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 748 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 749 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 750 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 751 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 752 "data//maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 753 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 754 "data//maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 755 "data//maps/PetalburgCity_Gym/scripts.pory"

# 756 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
# 757 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
# 758 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 759 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 760 "data//maps/PetalburgCity_Gym/scripts.pory"

# 761 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor::
# 762 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 763 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 764 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 765 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 766 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 767 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 768 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 769 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 770 "data//maps/PetalburgCity_Gym/scripts.pory"

# 771 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom::
# 772 "data//maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 773 "data//maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 774 "data//maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
# 775 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 776 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 777 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 778 "data//maps/PetalburgCity_Gym/scripts.pory"

# 779 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom::
# 780 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 781 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 782 "data//maps/PetalburgCity_Gym/scripts.pory"

# 783 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked::
# 784 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 785 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 786 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 787 "data//maps/PetalburgCity_Gym/scripts.pory"

# 788 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 789 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
# 790 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 791 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 792 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 793 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 794 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 795 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 796 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 797 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 798 "data//maps/PetalburgCity_Gym/scripts.pory"

# 799 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
# 800 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 801 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 802 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 803 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 804 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 805 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 806 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 807 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 808 "data//maps/PetalburgCity_Gym/scripts.pory"

# 809 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
# 810 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 811 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 812 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 813 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 814 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 815 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 816 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 817 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 818 "data//maps/PetalburgCity_Gym/scripts.pory"

# 819 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
# 820 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 821 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 822 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 823 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 824 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 825 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 826 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 827 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 828 "data//maps/PetalburgCity_Gym/scripts.pory"

# 829 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
# 830 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 831 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 832 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 833 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 834 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 835 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 836 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 837 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 838 "data//maps/PetalburgCity_Gym/scripts.pory"

# 839 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
# 840 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 841 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 842 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 843 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 844 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 845 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 846 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 847 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 848 "data//maps/PetalburgCity_Gym/scripts.pory"

# 849 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
# 850 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 851 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 852 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 853 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 854 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 855 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 856 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 857 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 858 "data//maps/PetalburgCity_Gym/scripts.pory"

# 859 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
# 860 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 861 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 862 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 863 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 864 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 865 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 866 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 867 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 868 "data//maps/PetalburgCity_Gym/scripts.pory"

# 869 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
# 870 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 871 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 872 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 873 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 874 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 875 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 876 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 877 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 878 "data//maps/PetalburgCity_Gym/scripts.pory"

# 879 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
# 880 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 881 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 882 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 883 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 884 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 885 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 886 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 887 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 888 "data//maps/PetalburgCity_Gym/scripts.pory"

# 889 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
# 890 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 891 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 892 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 893 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 894 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 895 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 896 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 897 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 898 "data//maps/PetalburgCity_Gym/scripts.pory"

# 899 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall::
# 900 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 901 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 902 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 903 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 904 "data//maps/PetalburgCity_Gym/scripts.pory"

# 905 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
# 906 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 907 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 908 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 909 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 910 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 911 "data//maps/PetalburgCity_Gym/scripts.pory"

# 912 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge::
# 913 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 914 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 915 "data//maps/PetalburgCity_Gym/scripts.pory"

# 916 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker::
# 917 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 918 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 919 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 920 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 921 "data//maps/PetalburgCity_Gym/scripts.pory"

# 922 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
# 923 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 924 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 925 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 926 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 927 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 928 "data//maps/PetalburgCity_Gym/scripts.pory"

# 929 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge::
# 930 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 931 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 932 "data//maps/PetalburgCity_Gym/scripts.pory"

# 933 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George::
# 934 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 935 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 936 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 937 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 938 "data//maps/PetalburgCity_Gym/scripts.pory"

# 939 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
# 940 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 941 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 942 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 943 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 944 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 945 "data//maps/PetalburgCity_Gym/scripts.pory"

# 946 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge::
# 947 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 948 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 949 "data//maps/PetalburgCity_Gym/scripts.pory"

# 950 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke::
# 951 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 952 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 953 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 954 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 955 "data//maps/PetalburgCity_Gym/scripts.pory"

# 956 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
# 957 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 958 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 959 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 960 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 961 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 962 "data//maps/PetalburgCity_Gym/scripts.pory"

# 963 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge::
# 964 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 965 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 966 "data//maps/PetalburgCity_Gym/scripts.pory"

# 967 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary::
# 968 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 969 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 970 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 971 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 972 "data//maps/PetalburgCity_Gym/scripts.pory"

# 973 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
# 974 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 975 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 976 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 977 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 978 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 979 "data//maps/PetalburgCity_Gym/scripts.pory"

# 980 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge::
# 981 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 982 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 983 "data//maps/PetalburgCity_Gym/scripts.pory"

# 984 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia::
# 985 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 986 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 987 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 988 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 989 "data//maps/PetalburgCity_Gym/scripts.pory"

# 990 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
# 991 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 992 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 993 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 994 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 995 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 996 "data//maps/PetalburgCity_Gym/scripts.pory"

# 997 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge::
# 998 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 999 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1000 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1001 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody::
# 1002 "data//maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 1003 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 1004 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 1005 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1006 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1007 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
# 1008 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1009 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 1010 "data//maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1011 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1012 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1013 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1014 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge::
# 1015 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 1016 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1017 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1018 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 1019 "data//maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 1020 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
# 1021 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 1022 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1023 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1024 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1025 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1026 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1027 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
# 1028 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1029 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1030 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1031 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1032 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1033 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1034 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
# 1035 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1036 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1037 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1038 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1039 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1040 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1041 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
# 1042 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1043 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1044 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1045 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1046 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1047 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1048 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
# 1049 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1050 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1051 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1052 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1053 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1054 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1055 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
# 1056 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1057 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1058 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1059 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1060 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1061 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1062 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
# 1063 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1064 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1065 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1066 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1067 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1068 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1069 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
# 1070 "data//maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1071 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1072 "data//maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1073 "data//maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1074 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1075 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1076 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
# 1077 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1078 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1079 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1080 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1081 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1082 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1083 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
# 1084 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1085 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1086 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1087 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1088 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1089 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1090 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
# 1091 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1092 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1093 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1094 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1095 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1096 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1097 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
# 1098 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1099 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1100 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1101 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1102 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
# 1103 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1104 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1105 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1106 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1107 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1108 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1109 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
# 1110 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1111 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1112 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1113 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1114 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
# 1115 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1116 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1117 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1118 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1119 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
# 1120 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1121 "data//maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1122 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1123 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1124 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
# 1125 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1126 "data//maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1127 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1128 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1129 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors::
# 1130 "data//maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1131 "data//maps/PetalburgCity_Gym/scripts.pory"
	return
# 1132 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1133 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide::
# 1134 "data//maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1135 "data//maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1136 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1137 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 1138 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1139 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1140 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1141 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory::
# 1142 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1143 "data//maps/PetalburgCity_Gym/scripts.pory"
	release
# 1144 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1145 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1146 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue::
# 1147 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1148 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1149 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1150 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1151 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1152 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue::
# 1153 "data//maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1154 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1155 "data//maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1156 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1157 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1158 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified::
# 1159 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1160 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1161 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1162 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1163 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue::
# 1164 "data//maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1165 "data//maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1166 "data//maps/PetalburgCity_Gym/scripts.pory"
	end
# 1167 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1168 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
# 1169 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm?\p"
# 1170 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1171 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1172 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1173 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.$"
# 1174 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1175 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
# 1176 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1177 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a POKéMON, please…$"
# 1178 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1179 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight:
# 1180 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
# 1181 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're WALLY, right?$"
# 1182 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1183 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
# 1184 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: I'm going to go stay with my\n"
# 1185 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in VERDANTURF TOWN.\p"
# 1186 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1187 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a POKéMON along.\p"
# 1188 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a POKéMON before.\n"
# 1189 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1190 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1191 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee:
# 1192 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hmm . . . \p"
# 1193 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I see . . . $"
# 1194 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1195 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally:
# 1196 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you heard that,\n"
# 1197 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1198 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with WALLY and make sure that he\n"
# 1199 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a POKéMON.$"
# 1200 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1201 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
# 1202 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY, here, I'll loan you my POKéMON.\p"
# 1203 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a ZIGZAGOON!$"
# 1204 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1205 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
# 1206 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1207 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "A POKéMON!\p"
# 1208 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
# 1209 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1210 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a POKé BALL!$"
# 1211 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1212 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou:
# 1213 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1214 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1215 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1216 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
# 1217 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1218 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1219 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1220 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut:
# 1221 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Watch out for each other\n"
# 1222 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "if you're travelling$"
# 1223 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1224 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye:
# 1225 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: . . .\n"
# 1226 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have to go . . .\p"
# 1227 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "See you around, {PLAYER}.$"
# 1228 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1229 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges:
# 1230 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for RUSTBORO CITY beyond this\n"
# 1231 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1232 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1233 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER, ROXANNE.\p"
# 1234 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm a GYM LEADER, too.\n"
# 1235 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER} . . .\p"
# 1236 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Only after you become stronger.$"
# 1237 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1238 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro:
# 1239 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? Aren't you going to the\n"
# 1240 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
# 1241 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1242 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn TRAINER.\p"
# 1243 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1244 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1245 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1246 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four GYM BADGES, okay?$"
# 1247 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1248 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford:
# 1249 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: I see… So, you've beaten\n"
# 1250 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
# 1251 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more TRAINERS\n"
# 1252 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1253 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in DEWFORD TOWN is a\n"
# 1254 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER named BRAWLY.\p"
# 1255 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1256 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1257 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger:
# 1258 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
# 1259 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1260 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of BADGES\n"
# 1261 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1262 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1263 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro:
# 1264 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm…\n"
# 1265 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four GYM BADGES.\p"
# 1266 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1267 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON battle.\p"
# 1268 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1269 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1270 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1271 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1272 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1273 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a GYM LEADER to win.\p"
# 1274 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1275 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1276 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1277 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat:
# 1278 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1279 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1280 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1281 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1282 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1283 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1284 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1285 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge:
# 1286 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the BALANCE BADGE\n"
# 1287 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from DAD!$"
# 1288 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1289 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
# 1290 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON that know the HM move SURF\n"
# 1291 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "will now be able to travel over water.\p"
# 1292 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1293 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1294 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1295 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade:
# 1296 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: TM42 contains FACADE.\p"
# 1297 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles the power of moves if\n"
# 1298 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the POKéMON is poisoned, paralyzed,\l"
# 1299 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "or burned.\p"
# 1300 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1301 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1302 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1303 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad:
# 1304 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: As the GYM LEADER, I can't\n"
# 1305 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1306 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1307 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1308 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1309 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe:
# 1310 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1311 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1312 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1313 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1314 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer:
# 1315 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN, you don't mind, do you?\p"
# 1316 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1317 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1318 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1319 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining:
# 1320 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you should go visit\n"
# 1321 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1322 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1323 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1324 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a TRAINER to\n"
# 1325 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1326 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1327 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
# 1328 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, how are things going?\p"
# 1329 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of POKéMON is deep.\p"
# 1330 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1331 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1332 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1333 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice:
# 1334 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 1335 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 1336 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this GYM open when you\n"
# 1337 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting TRAINERS.\p"
# 1338 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1339 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1340 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The TRAINERS of PETALBURG GYM\n"
# 1341 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "use all kinds of items.\p"
# 1342 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1343 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the SPEED ROOM.\p"
# 1344 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1345 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ACCURACY ROOM.\p"
# 1346 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1347 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1348 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1349 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!$"
# 1350 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1351 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory:
# 1352 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1353 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1354 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1355 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1356 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1357 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro:
# 1358 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1359 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1360 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1361 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1362 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1363 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat:
# 1364 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1365 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1366 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle:
# 1367 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1368 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1369 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the CONFUSION ROOM.\p"
# 1370 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the DEFENSE\n"
# 1371 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "ROOM.$"
# 1372 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1373 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge:
# 1374 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1375 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1376 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your POKéMON.\p"
# 1377 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1378 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER is all about.$"
# 1379 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1380 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro:
# 1381 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the CONFUSION ROOM.\p"
# 1382 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1383 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with your POKéMON!$"
# 1384 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1385 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat:
# 1386 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1387 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1388 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1389 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle:
# 1390 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the STRENGTH ROOM.\n"
# 1391 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1392 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1393 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge:
# 1394 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our LEADER, the\n"
# 1395 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1396 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1397 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro:
# 1398 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1399 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1400 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1401 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1402 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1403 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1404 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1405 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat:
# 1406 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1407 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What ATTACK power…$"
# 1408 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1409 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle:
# 1410 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1411 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "our LEADER's kid.\p"
# 1412 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A TRAINER's abilities are\n"
# 1413 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1414 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1415 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1416 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
# 1417 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1418 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge:
# 1419 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at GYMS.\n"
# 1420 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a LEADER.$"
# 1421 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1422 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro:
# 1423 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1424 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our LEADER's kid.\p"
# 1425 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1426 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON to take a critical hit!$"
# 1427 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1428 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat:
# 1429 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1430 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1431 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1432 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle:
# 1433 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1434 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a TRAINER worth my respect.\p"
# 1435 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1436 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1437 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1438 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1439 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1440 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge:
# 1441 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the LEADER,\n"
# 1442 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the TRAINERS of PETALBURG CITY have\l"
# 1443 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1444 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1445 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro:
# 1446 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1447 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the ACCURACY ROOM.\p"
# 1448 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1449 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1450 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1451 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat:
# 1452 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1453 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1454 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle:
# 1455 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1456 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "TRAINERS waiting for you.\p"
# 1457 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the DEFENSE ROOM, and\n"
# 1458 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the RECOVERY ROOM.\p"
# 1459 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Your POKéMON's ATTACK power will be\n"
# 1460 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1461 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1462 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge:
# 1463 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1464 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as TRAINERS?\p"
# 1465 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1466 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with our POKéMON.$"
# 1467 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1468 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro:
# 1469 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the DEFENSE, the more\n"
# 1470 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1471 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1472 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat:
# 1473 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1474 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1475 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle:
# 1476 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1477 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1478 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1479 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the STRENGTH ROOM.\p"
# 1480 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1481 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "the ONE-HIT KO ROOM.\p"
# 1482 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have TRAINERS who are\n"
# 1483 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1484 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1485 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge:
# 1486 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using SURF?$"
# 1487 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1488 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro:
# 1489 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Our GYM LEADER told us to go all out\n"
# 1490 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1491 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1492 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "LEADER's kid!$"
# 1493 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1494 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat:
# 1495 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1496 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1497 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle:
# 1498 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your POKéMON…\n"
# 1499 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1500 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The GYM LEADER, your\n"
# 1501 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1502 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1503 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge:
# 1504 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your POKéMON\n"
# 1505 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1506 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1507 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings TRAINERS have\n"
# 1508 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "for their POKéMON.$"
# 1509 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1510 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked:
# 1511 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1512 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1513 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1514 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom:
# 1515 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“SPEED ROOM,” the sign says.\p"
# 1516 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1517 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1518 "data//maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1519 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2:
# 1520 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1521 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1522 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1523 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom:
# 1524 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ACCURACY ROOM,” the sign says.\p"
# 1525 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1526 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1527 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom:
# 1528 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“CONFUSION ROOM,” the sign says.\p"
# 1529 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1530 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1531 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom:
# 1532 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“DEFENSE ROOM,” the sign says.\p"
# 1533 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1534 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1535 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom:
# 1536 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“RECOVERY ROOM,” the sign says.\p"
# 1537 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1538 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1539 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom:
# 1540 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“STRENGTH ROOM,” the sign says.\p"
# 1541 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1542 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1543 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom:
# 1544 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
# 1545 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1546 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1547 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom:
# 1548 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“GYM LEADER'S ROOM\p"
# 1549 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "“See for yourself what POKéMON await\n"
# 1550 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "you!” the sign says.\p"
# 1551 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1552 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1553 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue:
# 1554 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM$"
# 1555 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1556 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified:
# 1557 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\p"
# 1558 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
# 1559 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1560 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1561 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch:
# 1562 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1563 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1564 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1565 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1566 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1567 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1568 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1569 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "…No, because we are parent and child,\n"
# 1570 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1571 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1572 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1573 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat:
# 1574 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1575 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1576 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1577 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch:
# 1578 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1579 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1580 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1581 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1582 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1583 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1584 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
# 1585 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1586 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1587 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1588 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1589 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1590 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1591 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1592 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm? Wait a second, {PLAYER}.\p"
# 1593 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one POKéMON that is\n"
# 1594 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1595 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1596 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two POKéMON.$"
# 1597 "data//maps/PetalburgCity_Gym/scripts.pory"

# 1598 "data//maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_SkipWallyTutorial:
# 1599 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: This is Wally . . .\p"
# 1600 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "He is a dumbass . . . \n"
# 1601 "data//maps/PetalburgCity_Gym/scripts.pory"
	.string "but he recently caught a Ralts.$"
