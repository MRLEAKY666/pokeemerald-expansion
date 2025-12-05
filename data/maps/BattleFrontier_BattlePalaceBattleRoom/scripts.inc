# 1 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_MapScripts::
# 3 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
# 4 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
# 5 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
# 6 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 8 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ On this map the player (LOCALID_PLAYER) is hidden
# 9 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PALACE_BATTLE_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
# 10 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The opponent is represented by LOCALID_PALACE_BATTLE_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1
# 11 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 12 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnTransition:
# 13 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_settrainers
# 14 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 15 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 16 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 17 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx::
# 18 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	checkplayergender
# 19 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
# 20 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
# 21 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 22 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 23 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The opponent's gfx are set to the players by default
# 24 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale::
# 25 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 26 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 27 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 28 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 29 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale::
# 30 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 31 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 32 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 33 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 34 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnFrame:
# 35 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
# 36 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 37 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 38 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom::
# 39 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	showobjectat LOCALID_PALACE_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 40 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 41 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
# 42 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
# 43 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 44 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 45 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 46 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 47 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 48 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 49 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge::
# 50 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
# 51 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 52 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter::
# 53 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	tower_setopponent
# 54 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_PALACE_BATTLE_OPPONENT
# 55 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
# 56 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 57 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_getopponentintro
# 58 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 59 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 60 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 61 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 62 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
# 63 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost::
# 64 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 65 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 66 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 67 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent::
# 68 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 69 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 70 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 71 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 72 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 73 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 74 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
# 75 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 76 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_PALACE_BATTLE_OPPONENT
# 77 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 78 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 79 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 80 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 81 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special LoadPlayerParty
# 82 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special SavePlayerParty
# 83 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 84 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 85 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 86 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 87 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent::
# 88 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 89 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 90 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
# 91 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 92 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
# 93 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
# 94 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
# 95 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
# 96 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
# 97 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
# 98 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 99 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 100 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 101 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 102 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 103 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 104 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 105 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 106 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 107 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 108 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 109 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 110 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 111 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 112 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 113 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 114 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 115 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 116 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle::
# 117 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
# 118 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 119 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 120 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 121 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 122 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
# 123 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 124 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 125 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle::
# 126 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 127 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 128 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 129 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge::
# 130 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 131 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 132 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 133 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
# 134 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 135 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 136 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge::
# 137 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 138 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 139 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 140 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 141 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 142 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 143 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 144 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 145 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge::
# 146 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 147 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 148 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 149 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter
# 150 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 151 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon::
# 152 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 153 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 154 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 155 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge::
# 156 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 157 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 158 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_save CHALLENGE_STATUS_PAUSED
# 159 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playse SE_SAVE
# 160 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitse
# 161 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 162 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_reset
# 163 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 164 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 165 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext::
# 166 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 167 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
# 168 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 169 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven::
# 170 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
# 171 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 172 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 173 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
# 174 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 175 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 176 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 177 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 178 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 179 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 180 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 181 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 182 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord::
# 183 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 184 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 185 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 186 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 187 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 188 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 189 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 190 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser::
# 191 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 192 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
# 193 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 194 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 195 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 196 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_PALACE_BATTLE_OPPONENT, 15, 1
# 197 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_PALACE_BATTLE_OPPONENT
# 198 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PALACE_BATTLE_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 199 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxy LOCALID_PALACE_BATTLE_OPPONENT, 13, 1
# 200 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_PALACE_BATTLE_OPPONENT, 13, 1
# 201 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
# 202 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
# 203 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
# 204 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 205 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 206 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
# 207 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 208 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 209 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 210 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 211 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
# 212 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 213 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver::
# 214 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
# 215 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 216 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
# 217 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 218 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 219 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver::
# 220 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 221 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 222 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 223 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
# 224 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 225 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 226 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
# 227 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 228 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
# 229 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 230 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 231 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 232 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, Common_Movement_WalkInPlaceLeft
# 233 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 234 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 235 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 236 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 237 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
# 238 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 239 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 240 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold::
# 241 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 242 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 243 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
# 244 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 245 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold::
# 246 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
# 247 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 248 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
# 249 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 250 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 251 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold::
# 252 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 253 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 254 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 255 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
# 256 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 257 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 258 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
# 259 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 260 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
# 261 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 262 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 263 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 264 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_OPPONENT, Common_Movement_WalkInPlaceLeft
# 265 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 266 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 267 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 268 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 269 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
# 270 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 271 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 272 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle::
# 273 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 274 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 275 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 276 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 277 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_PALACE
# 278 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 279 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_restorehelditems
# 280 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 281 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_resetsketch
# 282 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 283 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 284 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnWarp:
# 285 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
# 286 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 287 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 288 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
# 289 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PALACE_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 290 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 291 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 292 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 293 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_PALACE_BATTLE_OPPONENT
# 294 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 295 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 296 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 297 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 298 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
# 299 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 300 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 301 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 302 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 303 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
# 304 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 305 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 306 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 307 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 308 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
# 309 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
# 310 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 311 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 312 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 313 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
# 314 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
# 315 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 316 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 317 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 318 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
# 319 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
# 320 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 321 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 322 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 323 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
# 324 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
# 325 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 326 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 327 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 328 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
# 329 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_invisible
# 330 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 331 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 332 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
# 333 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 334 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 335 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 336 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 337 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 338 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
# 339 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_right
# 340 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 341 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 342 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
# 343 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_up
# 344 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 345 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 346 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
# 347 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 348 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 349 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 350 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 351 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 352 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 353 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 354 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
# 355 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 356 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 357 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 358 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 359 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 360 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 361 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 362 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
# 363 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 364 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 365 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 366 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 367 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 368 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 369 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
# 370 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_down
# 371 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 372 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 373 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
# 374 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 375 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 376 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 377 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 378 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 379 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 380 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
# 381 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 382 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 383 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 384 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 385 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
# 386 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 387 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 388 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 389 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 390 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 391 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 392 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
# 393 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 394 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
# 395 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
# 396 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 397 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 398 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 399 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
# 400 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
# 401 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 402 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 403 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 404 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
# 405 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 406 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 407 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 408 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 409 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_right
# 410 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 411 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 412 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 413 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 414 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
# 415 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 416 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 417 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_right
# 418 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 419 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 420 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 421 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 422 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 423 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 424 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 425 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 426 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 427 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
# 428 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 429 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 430 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 431 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 432 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 433 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 434 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 435 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 436 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 437 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 438 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 439 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 440 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 441 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 442 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 443 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
# 444 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Excellent…\n"
# 445 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let me restore your POKéMON.$"
# 446 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 447 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
# 448 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 2nd opponent is next.\n"
# 449 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 450 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 451 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
# 452 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 3rd opponent is next.\n"
# 453 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 454 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 455 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
# 456 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 4th opponent is next.\n"
# 457 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 458 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 459 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
# 460 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 5th opponent is next.\n"
# 461 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 462 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 463 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
# 464 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 6th opponent is next.\n"
# 465 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 466 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 467 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
# 468 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 7th opponent is next.\n"
# 469 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 470 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 471 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
# 472 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 473 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the game?$"
# 474 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 475 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
# 476 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to quit your challenge?$"
# 477 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 478 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
# 479 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Saving the data.\n"
# 480 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Have patience…$"
# 481 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 482 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
# 483 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to record your latest\n"
# 484 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 485 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 486 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
# 487 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "And now…\p"
# 488 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "By winning consistently, you have\n"
# 489 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "earned the privilege of challenging\l"
# 490 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "our master, the PALACE MAVEN…$"
# 491 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 492 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
# 493 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I shall send for the PALACE MAVEN.\n"
# 494 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 495 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 496 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
# 497 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let great fanfare announce the arrival\n"
# 498 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "of the PALACE MAVEN, SPENSER!$"
# 499 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 500 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
# 501 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: My physical being is with\n"
# 502 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 503 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My heart beats as one with\n"
# 504 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 505 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Young one of a TRAINER!\n"
# 506 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you believe in your POKéMON?\p"
# 507 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Can you believe them through\n"
# 508 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "and through?\p"
# 509 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "If your bonds of trust are frail,\n"
# 510 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "you will never beat my brethren!$"
# 511 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 512 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
# 513 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The bond you share with your POKéMON!\n"
# 514 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prove it to me here!$"
# 515 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 516 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
# 517 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 518 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hah, you never fell for my bluster!\n"
# 519 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Sorry for trying that stunt!\p"
# 520 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 521 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me the thing!$"
# 522 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 523 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
# 524 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain that\n"
# 525 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "facade of distinguished authority…\p"
# 526 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 527 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 528 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 529 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
# 530 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol was embossed on\n"
# 531 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 532 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 533 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
# 534 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Your POKéMON's eyes are \n"
# 535 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "truly clear and unclouded.\p"
# 536 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I will eagerly await the next\n"
# 537 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "opportunity to see you.$"
# 538 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 539 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
# 540 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\n"
# 541 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You've battled your way up again?\p"
# 542 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You must have developed a truly\n"
# 543 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "formidable bond with your POKéMON.\p"
# 544 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "So be it!\p"
# 545 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, I won't bluster or hold back.\n"
# 546 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, there's no fooling around.\p"
# 547 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Ready now?\n"
# 548 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prepare to lose!$"
# 549 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 550 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
# 551 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "… … …Kaaah!$"
# 552 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 553 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
# 554 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Well, that was some display!\n"
# 555 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Even fully unleashed, my brethren\l"
# 556 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "could not overpower you.\p"
# 557 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Your team spirit is truly admirable!\p"
# 558 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 559 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me that thing, will you?$"
# 560 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 561 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
# 562 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain\n"
# 563 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a certain level of decorum…\p"
# 564 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Gaaah, here!\n"
# 565 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hurry with that FRONTIER PASS, you!$"
# 566 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 567 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
# 568 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol took on\n"
# 569 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 570 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 571 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
# 572 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 573 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Come see me time and again!\n"
# 574 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My brethren and I will be waiting!$"
