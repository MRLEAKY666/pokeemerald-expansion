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
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
# 278 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 279 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 280 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 281 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_restorehelditems
# 282 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 283 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_resetsketch
# 284 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 285 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 286 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnWarp:
# 287 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
# 288 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 289 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 290 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects::
# 291 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PALACE_BATTLE_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 292 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 293 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 294 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 295 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_PALACE_BATTLE_OPPONENT
# 296 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 297 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PALACE_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 298 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 299 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 300 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent::
# 301 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 302 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 303 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 304 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 305 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent::
# 306 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 307 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 308 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 309 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 310 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent::
# 311 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
# 312 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 313 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 314 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 315 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent::
# 316 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
# 317 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 318 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 319 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 320 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent::
# 321 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
# 322 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 323 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 324 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 325 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent::
# 326 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
# 327 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 328 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 329 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 330 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible:
# 331 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_invisible
# 332 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 333 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 334 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom:
# 335 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 336 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 337 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 338 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 339 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 340 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight:
# 341 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_right
# 342 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 343 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 344 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp:
# 345 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_up
# 346 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 347 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 348 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge:
# 349 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 350 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 351 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 352 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 353 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 354 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 355 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 356 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter:
# 357 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 358 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 359 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 360 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 361 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 362 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 363 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 364 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit:
# 365 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 366 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 367 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 368 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 369 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 370 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 371 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown:
# 372 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_down
# 373 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 374 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 375 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1:
# 376 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 377 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 378 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 379 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 380 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 381 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 382 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2:
# 383 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 384 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 385 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 386 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 387 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3:
# 388 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 389 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 390 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 391 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 392 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 393 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 394 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby::
# 395 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 396 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
# 397 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 5, 7
# 398 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 399 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 400 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 401 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles::
# 402 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 19, 7
# 403 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 404 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 405 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 406 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter:
# 407 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 408 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 409 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 410 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 411 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_right
# 412 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 413 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 414 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 415 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 416 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter:
# 417 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 418 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 419 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_right
# 420 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 421 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 422 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 423 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 424 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 425 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 426 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 427 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 428 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 429 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter:
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
	delay_16
# 436 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 437 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 438 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 439 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 440 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 441 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 442 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 443 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 444 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 445 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons:
# 446 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Excellent…\n"
# 447 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let me restore your POKéMON.$"
# 448 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 449 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent:
# 450 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 2nd opponent is next.\n"
# 451 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 452 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 453 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent:
# 454 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 3rd opponent is next.\n"
# 455 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 456 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 457 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent:
# 458 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 4th opponent is next.\n"
# 459 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 460 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 461 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent:
# 462 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 5th opponent is next.\n"
# 463 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 464 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 465 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent:
# 466 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 6th opponent is next.\n"
# 467 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 468 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 469 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent:
# 470 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 7th opponent is next.\n"
# 471 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 472 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 473 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame:
# 474 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 475 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the game?$"
# 476 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 477 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge:
# 478 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to quit your challenge?$"
# 479 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 480 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SavingData:
# 481 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Saving the data.\n"
# 482 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Have patience…$"
# 483 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 484 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch:
# 485 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to record your latest\n"
# 486 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 487 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 488 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven:
# 489 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "And now…\p"
# 490 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "By winning consistently, you have\n"
# 491 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "earned the privilege of challenging\l"
# 492 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "our master, the PALACE MAVEN…$"
# 493 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 494 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven:
# 495 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I shall send for the PALACE MAVEN.\n"
# 496 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 497 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 498 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser:
# 499 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let great fanfare announce the arrival\n"
# 500 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "of the PALACE MAVEN, SPENSER!$"
# 501 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 502 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro:
# 503 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: My physical being is with\n"
# 504 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 505 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My heart beats as one with\n"
# 506 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "POKéMON always!\p"
# 507 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Young one of a TRAINER!\n"
# 508 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you believe in your POKéMON?\p"
# 509 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Can you believe them through\n"
# 510 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "and through?\p"
# 511 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "If your bonds of trust are frail,\n"
# 512 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "you will never beat my brethren!$"
# 513 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 514 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons:
# 515 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The bond you share with your POKéMON!\n"
# 516 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prove it to me here!$"
# 517 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 518 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle:
# 519 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 520 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hah, you never fell for my bluster!\n"
# 521 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Sorry for trying that stunt!\p"
# 522 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 523 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me the thing!$"
# 524 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 525 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass:
# 526 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain that\n"
# 527 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "facade of distinguished authority…\p"
# 528 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 529 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 530 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 531 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol:
# 532 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol was embossed on\n"
# 533 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 534 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 535 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime:
# 536 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Your POKéMON's eyes are \n"
# 537 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "truly clear and unclouded.\p"
# 538 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I will eagerly await the next\n"
# 539 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "opportunity to see you.$"
# 540 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 541 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack:
# 542 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\n"
# 543 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You've battled your way up again?\p"
# 544 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You must have developed a truly\n"
# 545 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "formidable bond with your POKéMON.\p"
# 546 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "So be it!\p"
# 547 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, I won't bluster or hold back.\n"
# 548 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, there's no fooling around.\p"
# 549 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Ready now?\n"
# 550 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prepare to lose!$"
# 551 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 552 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah:
# 553 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "… … …Kaaah!$"
# 554 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 555 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable:
# 556 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Well, that was some display!\n"
# 557 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Even fully unleashed, my brethren\l"
# 558 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "could not overpower you.\p"
# 559 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Your team spirit is truly admirable!\p"
# 560 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 561 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me that thing, will you?$"
# 562 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 563 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass:
# 564 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain\n"
# 565 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a certain level of decorum…\p"
# 566 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Gaaah, here!\n"
# 567 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hurry with that FRONTIER PASS, you!$"
# 568 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 569 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine:
# 570 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol took on\n"
# 571 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 572 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 573 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain:
# 574 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 575 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Come see me time and again!\n"
# 576 "data//maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My brethren and I will be waiting!$"
