# 1 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set NO_DRAW,       0
# 3 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TRAINER,  1
# 4 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set DRAW_TUCKER,   2
# 5 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 6 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_MapScripts::
# 7 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
# 8 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
# 9 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
# 10 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
# 11 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.byte 0
# 12 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 13 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnTransition:
# 14 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 15 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_setopponentgfx
# 16 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 17 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 18 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
# 19 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 20 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 21 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 22 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx::
# 23 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	checkplayergender
# 24 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
# 25 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
# 26 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 27 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 28 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale::
# 29 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 30 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 31 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 32 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale::
# 33 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 34 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 35 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnFrame:
# 37 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
# 38 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 39 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 40 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom::
# 41 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lockall
# 42 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 43 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
# 44 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 45 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 46 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
# 47 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
# 48 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 49 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	showobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 50 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
# 51 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
# 52 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter::
# 53 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
# 54 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer
# 55 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 56 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker::
# 57 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
# 58 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer::
# 59 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 60 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 61 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 62 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
# 63 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
# 64 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent::
# 65 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 66 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
# 67 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 68 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
# 69 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
# 70 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 71 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 72 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 73 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 74 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_initopponentparty
# 75 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 76 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, NO_DRAW
# 77 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 78 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 79 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 80 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 81 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TRAINER
# 82 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw::
# 83 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
# 84 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 85 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 86 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 87 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 88 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
# 89 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 90 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
# 91 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 92 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 180
# 93 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
# 94 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 95 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent @ Tucker always wins on a draw
# 96 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_compareseeds
# 97 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 98 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 99 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent::
# 100 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 101 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 102 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 103 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
# 104 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
# 105 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TUCKER, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
# 106 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 107 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 108 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 109 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney::
# 110 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
# 111 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost::
# 112 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 113 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 114 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 115 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon::
# 116 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_2
# 117 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
# 118 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 119 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 120 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 121 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw::
# 122 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername STR_VAR_1
# 123 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
# 124 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 125 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 126 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 127 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw::
# 128 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
# 129 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 130 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 131 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 132 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent::
# 133 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 134 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 135 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, NO_DRAW, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
# 136 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_2, DRAW_TRAINER, BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
# 137 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 138 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 139 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 140 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getroundtext
# 141 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 142 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 143 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 144 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 145 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 146 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 147 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 148 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 3
# 149 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 150 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 151 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney::
# 152 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
# 153 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 154 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 155 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 156 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
# 157 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
# 158 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin
# 159 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 160 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney::
# 161 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
# 162 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin::
# 163 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoDomeConfetti
# 164 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 165 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 166 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 167 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 168 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 169 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 170 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon::
# 171 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
# 172 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 173 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 174 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw::
# 175 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
# 176 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 177 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 178 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer::
# 179 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
# 180 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
# 181 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_HAS_WON_CHALLENGE
# 182 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
# 183 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
# 184 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
# 185 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
# 186 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 187 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 188 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt::
# 189 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 190 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
# 192 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
# 193 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
# 194 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
# 195 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 196 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 197 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1::
# 198 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
# 199 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 200 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 201 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 202 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2::
# 203 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
# 204 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 205 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 206 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 207 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal::
# 208 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
# 209 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 210 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 211 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 212 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal::
# 213 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
# 214 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 215 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 216 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 217 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon::
# 218 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 219 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 220 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
# 221 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
# 222 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
# 223 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
# 224 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 225 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 226 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1::
# 227 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
# 228 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 229 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 230 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 231 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2::
# 232 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
# 233 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 234 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 235 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 236 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal::
# 237 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
# 238 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 239 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 240 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 241 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal::
# 242 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
# 243 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 244 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 245 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 246 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion::
# 247 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
# 248 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 249 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 250 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 251 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 252 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 253 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker::
# 254 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 255 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 256 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
# 257 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
# 258 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
# 259 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
# 260 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 261 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 262 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1::
# 263 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
# 264 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 265 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 266 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 267 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2::
# 268 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
# 269 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 270 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 271 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 272 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal::
# 273 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
# 274 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 275 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 276 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 277 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal::
# 278 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
# 279 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 280 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 281 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 282 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver::
# 283 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
# 284 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 285 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 286 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold::
# 287 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
# 288 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 289 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 290 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak::
# 291 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 292 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 293 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
# 294 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
# 295 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
# 296 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
# 297 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 298 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 299 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1::
# 300 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
# 301 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 302 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 303 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 304 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2::
# 305 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
# 306 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 307 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 308 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 309 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal::
# 310 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
# 311 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 312 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 313 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 314 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal::
# 315 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
# 316 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 317 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 318 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 319 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum::
# 320 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 321 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 322 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 323 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker::
# 324 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 325 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 326 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 327 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 328 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 329 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 330 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver::
# 331 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
# 332 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter
# 333 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 334 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold::
# 335 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
# 336 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter::
# 337 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 338 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
# 339 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
# 340 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
# 341 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 342 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 343 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 344 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 345 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 346 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 347 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 348 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 349 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 350 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 351 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 352 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 353 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 354 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 355 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 356 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 357 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
# 358 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 359 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 360 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 361 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 362 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 363 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
# 364 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 365 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 366 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 367 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 368 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
# 369 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 370 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver::
# 371 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
# 372 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 373 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 374 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 375 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 376 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 377 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 378 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 379 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 380 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 381 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 382 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 383 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 384 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
# 385 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 386 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
# 387 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 388 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 389 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 390 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
# 391 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 392 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 393 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro::
# 394 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 395 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 396 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
# 397 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 398 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold::
# 399 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
# 400 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 401 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 402 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 403 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 404 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 405 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 406 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 407 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 408 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 409 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 410 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 411 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 412 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
# 413 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 414 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
# 415 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 416 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 417 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 418 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
# 419 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 420 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 421 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle::
# 422 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
# 423 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 424 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
# 425 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
# 426 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 427 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 428 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 429 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 430 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker::
# 431 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
# 432 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 433 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 434 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 435 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney
# 436 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 437 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw::
# 438 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TUCKER
# 439 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw
# 440 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 441 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle::
# 442 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 443 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 444 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 1
# 445 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_DOME
# 446 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 447 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 0
# 448 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_restorehelditems
# 449 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 450 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resetsketch
# 451 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 452 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 453 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnWarp:
# 454 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
# 455 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 456 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 457 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects::
# 458 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	hideobjectat LOCALID_DOME_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 459 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 460 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 461 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 462 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 463 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 464 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 465 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 466 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 467 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 468 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 469 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_OPPONENT, 13, 9
# 470 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	removeobject LOCALID_DOME_OPPONENT
# 471 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 1
# 472 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addobject LOCALID_DOME_OPPONENT
# 473 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
# 474 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects::
# 475 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 476 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 477 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnResume:
# 478 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
# 479 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 480 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 481 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience::
# 482 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 483 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 484 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 485 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Add audience members to supplement the permanent object event audience
# 486 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience::
# 487 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
# 488 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
# 489 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
# 490 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq VAR_TEMP_F, DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
# 491 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 492 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 493 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience::
# 494 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 495 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 496 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience::
# 497 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 498 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 499 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 500 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 501 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 502 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 503 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 504 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 505 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 506 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 507 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 508 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 509 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 510 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience::
# 511 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 512 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 513 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 514 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 515 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 516 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 517 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 518 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0
# 519 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 520 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 521 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 522 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 523 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 524 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 525 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 526 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 527 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 528 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 529 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 530 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 531 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 532 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 533 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 534 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience::
# 535 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0
# 536 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
# 537 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0
# 538 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0
# 539 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0
# 540 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0
# 541 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
# 542 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0
# 543 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0
# 544 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
# 545 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0
# 546 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
# 547 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0
# 548 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2
# 549 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2
# 550 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1
# 551 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1
# 552 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
# 553 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1
# 554 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
# 555 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1
# 556 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1
# 557 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
# 558 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1
# 559 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1
# 560 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
# 561 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2
# 562 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2
# 563 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2
# 564 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1
# 565 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2
# 566 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2
# 567 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 568 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 569 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible:
# 570 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 571 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 572 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 573 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter:
# 574 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 575 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 576 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 577 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 578 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 579 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 580 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward:
# 581 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 582 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 583 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 584 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience:
# 585 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 586 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 587 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 588 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Identical to Movement_PlayerEnter
# 589 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker:
# 590 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 591 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 592 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 593 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 594 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 595 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 596 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 597 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 598 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 599 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2:
# 600 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 601 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 602 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 603 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward:
# 604 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 605 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 606 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 607 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp:
# 608 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 609 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 610 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 611 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 612 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance:
# 613 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 614 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 615 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 616 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 617 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 618 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 619 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 620 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 621 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 622 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 623 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 624 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 625 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 626 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 627 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 628 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 629 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 630 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 631 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 632 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 633 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 634 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 635 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 636 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 637 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 638 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 639 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 640 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 641 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 642 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 643 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 644 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 645 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 646 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 647 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 648 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 649 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 650 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 651 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 652 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 653 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 654 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 655 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 656 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 657 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 658 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 659 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 660 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 661 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 662 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 663 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 664 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 665 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 666 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 667 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 668 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 669 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 670 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 671 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 672 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 673 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 674 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 675 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 676 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 677 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 678 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 679 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 680 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 681 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 682 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 683 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 684 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 685 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 686 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 687 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 688 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 689 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 690 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 691 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 692 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 693 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 694 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 695 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 696 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 697 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 698 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 699 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 700 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 701 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 702 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 703 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 704 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 705 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 706 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 707 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 708 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 709 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 710 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 711 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 712 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 713 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 714 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 715 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 716 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 717 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 718 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 719 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 720 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 721 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance:
# 722 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 723 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 724 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 725 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 726 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 727 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 728 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 729 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 730 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 731 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 732 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 733 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 734 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 735 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 736 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 737 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 738 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 739 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 740 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 741 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 742 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 743 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 744 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 745 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 746 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 747 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 748 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 749 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 750 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 751 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 752 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 753 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 754 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 755 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 756 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 757 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 758 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 759 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 760 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 761 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 762 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 763 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 764 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 765 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 766 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 767 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 768 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 769 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 770 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 771 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward:
# 772 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 773 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 774 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 775 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer:
# 776 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 777 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 778 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 779 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 780 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround::
# 781 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_EAST
# 782 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_EAST
# 783 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_EAST
# 784 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_EAST
# 785 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_EAST
# 786 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_WEST
# 787 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_WEST
# 788 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_WEST
# 789 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_WEST
# 790 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_WEST
# 791 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_EAST
# 792 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_EAST
# 793 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_EAST
# 794 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_EAST
# 795 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_EAST
# 796 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_EAST
# 797 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 798 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_SOUTH
# 799 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_SOUTH
# 800 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_SOUTH
# 801 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_SOUTH
# 802 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_SOUTH
# 803 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_SOUTH
# 804 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_SOUTH
# 805 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_SOUTH
# 806 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_SOUTH
# 807 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_SOUTH
# 808 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_SOUTH
# 809 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_SOUTH
# 810 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_SOUTH
# 811 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_SOUTH
# 812 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_SOUTH
# 813 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_SOUTH
# 814 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 815 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_EAST
# 816 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_EAST
# 817 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_EAST
# 818 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_EAST
# 819 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_EAST
# 820 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_WEST
# 821 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_WEST
# 822 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_WEST
# 823 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_WEST
# 824 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_WEST
# 825 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_EAST
# 826 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_EAST
# 827 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_EAST
# 828 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_WEST
# 829 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_WEST
# 830 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 831 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_SOUTH
# 832 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_SOUTH
# 833 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_SOUTH
# 834 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_SOUTH
# 835 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_SOUTH
# 836 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_SOUTH
# 837 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_SOUTH
# 838 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_SOUTH
# 839 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_SOUTH
# 840 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_SOUTH
# 841 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_SOUTH
# 842 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_SOUTH
# 843 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_SOUTH
# 844 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_SOUTH
# 845 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_SOUTH
# 846 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 847 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 848 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 849 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby::
# 850 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 851 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
# 852 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 5, 11
# 853 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 854 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 855 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 856 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles::
# 857 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 17, 11
# 858 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 859 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 860 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 861 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
# 862 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos::
# 863 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	random 2
# 864 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 865 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 866 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_DOME_AUDIENCE_WALKING, 2, 0
# 867 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectmovementtype LOCALID_DOME_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
# 868 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 869 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 870 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat::
# 871 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_D, 0, Common_EventScript_NopReturn
# 872 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_DOME_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
# 873 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 874 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 875 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump:
# 876 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 877 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 878 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 879 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 880 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 881 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 882 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 883 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 884 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 885 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 886 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 887 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 888 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 889 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 890 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 891 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 892 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 893 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	enable_jump_landing_ground_effect
# 894 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 895 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 896 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat:
# 897 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 898 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 899 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 900 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 901 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_down
# 902 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 903 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 904 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter:
# 905 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 906 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 907 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 908 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 909 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 910 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 911 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft:
# 912 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 913 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 914 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 915 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit:
# 916 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 917 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 918 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 919 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 920 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 921 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 922 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome:
# 923 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the BATTLE DOME!$"
# 924 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 925 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer:
# 926 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_1}\n"
# 927 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "match!\p"
# 928 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
# 929 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 930 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 931 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner:
# 932 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the winner!\n"
# 933 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 934 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 935 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner:
# 936 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_2} is the winner!\n"
# 937 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 938 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 939 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ:
# 940 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 941 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 942 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 943 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 944 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp:
# 945 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 946 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 947 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 948 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 949 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait:
# 950 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "What an unbelievable finish!\n"
# 951 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "We have a double knockout!\p"
# 952 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In this event, the Battle Tournament\n"
# 953 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "rules call for a REFEREE'S decision.\p"
# 954 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Please wait while the judging\n"
# 955 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "is under way.$"
# 956 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 957 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer:
# 958 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 959 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 960 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 961 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 962 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {STR_VAR_1}!\l"
# 963 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 964 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 965 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer:
# 966 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 967 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 968 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 969 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 970 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!\l"
# 971 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 972 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 973 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope:
# 974 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The bright new hope!\p"
# 975 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 976 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 977 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RisingStar:
# 978 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The rising star!\p"
# 979 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 980 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 981 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship:
# 982 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER race to\n"
# 983 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the championship?\p"
# 984 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 985 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 986 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry:
# 987 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the feat of a championship\n"
# 988 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "on the first try be achieved?\p"
# 989 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 990 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 991 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged:
# 992 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the loss of the last match\n"
# 993 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "be avenged?\p"
# 994 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 995 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 996 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship:
# 997 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The TRAINER is on fire for\n"
# 998 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the first championship try!\p"
# 999 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1000 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1001 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal:
# 1002 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "A win here means this TRAINER\n"
# 1003 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "advances to the final!\p"
# 1004 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1005 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1006 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue:
# 1007 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the long-held dream of\n"
# 1008 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a championship finally come true?\p"
# 1009 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1010 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1011 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion:
# 1012 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The invincible champion!\p"
# 1013 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1014 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1015 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer:
# 1016 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can anyone hope to beat this\n"
# 1017 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TRAINER?\p"
# 1018 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1019 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1020 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer:
# 1021 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do battles exist solely for\n"
# 1022 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "this TRAINER?\p"
# 1023 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1024 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1025 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle:
# 1026 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The current champion aiming to\n"
# 1027 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "retain the title!\p"
# 1028 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1029 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1030 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned:
# 1031 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former champion has returned!\p"
# 1032 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1033 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1034 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned:
# 1035 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former toughness has returned!\p"
# 1036 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1037 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1038 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals:
# 1039 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this TRAINER do as expected\n"
# 1040 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "and advance to the finals?\p"
# 1041 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1042 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1043 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory:
# 1044 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the former champ regain\n"
# 1045 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "lost glory?\p"
# 1046 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1047 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1048 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster:
# 1049 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Feel the glow of a true master!$"
# 1050 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1051 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker:
# 1052 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "And now… The TRAINER standing in\n"
# 1053 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER}'s record-setting path…\p"
# 1054 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes! The one and only!\n"
# 1055 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The BATTLE DOME COMMISSIONER!\l"
# 1056 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1057 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Make way for TUCKER!$"
# 1058 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1059 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant:
# 1060 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Spectators: TUCKER! TUCKER!\n"
# 1061 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER! TUCKER! TUCKER!$"
# 1062 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1063 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro:
# 1064 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ahahah!\p"
# 1065 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do you hear it? This crowd!\n"
# 1066 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "They're all itching to see our match!\p"
# 1067 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ahahah!\p"
# 1068 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I bet you're twitching all over from\n"
# 1069 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the tension of getting to battle me!\p"
# 1070 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "But don't you worry about a thing!\p"
# 1071 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
# 1072 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
# 1073 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "in my brilliant glow!$"
# 1074 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1075 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy:
# 1076 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your strategy!\n"
# 1077 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's see it!$"
# 1078 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1079 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer:
# 1080 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Unbelievable! It's incredible!\n"
# 1081 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The victor is {PLAYER}!$"
# 1082 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1083 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker:
# 1084 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is TUCKER!\n"
# 1085 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The DOME ACE has prevailed!\p"
# 1086 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations, TUCKER!$"
# 1087 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1088 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass:
# 1089 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Rules are rules!\n"
# 1090 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let me see your FRONTIER PASS.$"
# 1091 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1092 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol:
# 1093 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol was embossed on\n"
# 1094 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 1095 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1096 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime:
# 1097 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 1098 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I sorely underestimated you. I won't\n"
# 1099 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "make the same mistake next time…$"
# 1100 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1101 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched:
# 1102 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the win streak be stretched?\n"
# 1103 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The confidence is there!$"
# 1104 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1105 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker:
# 1106 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ladies and gentlemen!\n"
# 1107 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Boys, girls, and POKéMON!\p"
# 1108 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally!\n"
# 1109 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally, the legend has returned!\p"
# 1110 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, the name of that legend!\n"
# 1111 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1112 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's none other than TUCKER!$"
# 1113 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1114 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro:
# 1115 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ah…\n"
# 1116 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The pummeling roar of the crowd…\l"
# 1117 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Their furnace-like heat of excitement…\l"
# 1118 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "This is a wonderful place…\p"
# 1119 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "To the crowd, I am the DOME ACE…\n"
# 1120 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I represent their hopes and dreams…\l"
# 1121 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must never fade from their sight…\p"
# 1122 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must burn!\n"
# 1123 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Brighter and more brilliant!\l"
# 1124 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must light all that gather here!$"
# 1125 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1126 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess:
# 1127 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will unleash all the power that\n"
# 1128 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I possess! Right here and now!$"
# 1129 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1130 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed:
# 1131 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: You're genuinely fantastic!\p"
# 1132 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Never before! I haven't ever lost in the\n"
# 1133 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "times I've had to unleash my power.\p"
# 1134 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, quite fantastic!\n"
# 1135 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please?$"
# 1136 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1137 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine:
# 1138 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol took on\n"
# 1139 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 1140 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1141 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter:
# 1142 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "You're strong, but above all,\n"
# 1143 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "you have a unique charm!\p"
# 1144 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In you, I see a definite potential for\n"
# 1145 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a superstar like me.\p"
# 1146 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will very much look forward to\n"
# 1147 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "our next encounter!$"
# 1148 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1149 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1150 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2:
# 1151 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 1152 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1153 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1154 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1155 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1156 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2:
# 1157 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 1158 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1159 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1160 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1161 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker:
# 1162 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The final match!\p"
# 1163 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
# 1164 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 1165 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1166 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker:
# 1167 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1168 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1169 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1170 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1171 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is our very own DOME ACE!\l"
# 1172 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's TUCKER!\p"
# 1173 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations! And thank you!\n"
# 1174 "data//maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
