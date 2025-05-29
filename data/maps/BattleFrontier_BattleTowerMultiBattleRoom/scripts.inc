# 1 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_MapScripts::
# 3 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_OnTransition
# 4 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnWarp
# 5 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnFrame
# 6 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 8 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ On this map the player (LOCALID_PLAYER) is hidden
# 9 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_TOWER_MULTI_BATTLE_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_F
# 10 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The multi partner is represented by LOCALID_TOWER_MULTI_BATTLE_PARTNER, which has the gfx id VAR_OBJ_GFX_ID_E
# 11 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 12 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnTransition:
# 13 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx
# 14 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx
# 15 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 16 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 17 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx::
# 18 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setpartnergfx
# 19 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	checkplayergender
# 20 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale
# 21 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 22 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 23 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale::
# 25 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 26 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 27 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 28 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx::
# 29 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 30 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 31 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 32 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnWarp:
# 33 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj
# 34 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 35 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj::
# 37 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM
# 38 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 39 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 40 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnFrame:
# 41 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom
# 42 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 43 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 44 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom::
# 45 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 46 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom
# 47 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom
# 48 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 49 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 50 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 51 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 52 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 53 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 54 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 55 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 56 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 57 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 58 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 59 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 60 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter::
# 61 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setopponent
# 62 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
# 63 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
# 64 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter
# 65 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter
# 66 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 67 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink
# 68 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 69 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 70 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 71 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 72 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 73 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 74 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 75 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 76 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 77 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 78 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 79 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle
# 80 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 81 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink::
# 82 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 83 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 84 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 85 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 86 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 87 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 88 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 89 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 90 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 91 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 92 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 93 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 94 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 95 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle::
# 96 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 97 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 98 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents
# 99 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost::
# 100 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 101 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 102 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 103 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 104 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 105 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 106 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents::
# 107 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 108 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setbattlewon
# 109 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 110 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon
# 111 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit
# 112 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit
# 113 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 114 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
# 115 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
# 116 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 117 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 118 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 119 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 120 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 121 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 122 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink
# 123 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 124 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty
# 125 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 126 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink::
# 127 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
# 128 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 129 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 130 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty::
# 131 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LoadPlayerParty
# 132 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE
# 133 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink
# 134 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 135 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitfanfare
# 136 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special HealPlayerParty
# 137 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents::
# 138 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 139 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet
# 140 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 141 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 142 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord
# 143 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 144 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 145 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 146 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle
# 147 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 148 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 149 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 150 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 151 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord::
# 152 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 153 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 154 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 155 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 156 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 157 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 158 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 159 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle::
# 160 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 161 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 162 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 163 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 164 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 165 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle
# 166 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 167 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 168 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle::
# 169 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 170 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 171 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 172 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge::
# 173 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 174 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 175 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 176 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge
# 177 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 178 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 179 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge::
# 180 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 181 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 182 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 183 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 184 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 185 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 186 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 187 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 188 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge::
# 189 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	closemessage
# 190 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 191 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 192 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 193 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 194 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 195 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 196 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 197 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 198 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 199 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 200 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon::
# 201 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 202 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 203 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 204 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 205 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 206 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 207 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge::
# 208 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 209 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 210 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 211 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playse SE_SAVE
# 212 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitse
# 213 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	fadescreen 1
# 214 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_reset
# 215 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 216 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 217 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet::
# 218 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink
# 219 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 220 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 221 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet
# 222 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet
# 223 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet
# 224 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet
# 225 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet
# 226 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet
# 227 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 228 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet::
# 229 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 230 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 231 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 232 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 233 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet::
# 234 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 235 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 236 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 237 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 238 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet::
# 239 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 240 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 241 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 242 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 243 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet::
# 244 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 245 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 246 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 247 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 248 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet::
# 249 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 250 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 251 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 252 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 253 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet::
# 254 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 255 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 256 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 257 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 258 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink::
# 259 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 260 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 261 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink
# 262 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink
# 263 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink
# 264 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink
# 265 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink
# 266 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink
# 267 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 268 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink::
# 269 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 270 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 271 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 272 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 273 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 274 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink::
# 275 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 276 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 277 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 278 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 279 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 280 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink::
# 281 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 282 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 283 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 284 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 285 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 286 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink::
# 287 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 288 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 289 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 290 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 291 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 292 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink::
# 293 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 294 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 295 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 296 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 297 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 298 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink::
# 299 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 300 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 301 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 302 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 303 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 304 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg::
# 305 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 306 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 307 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 308 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 309 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink::
# 310 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord
# 311 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 6, MULTI_GO_ON_RECORD_RETIRE, TRUE
# 312 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 313 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 314 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink
# 315 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 316 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 317 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 318 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 319 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord::
# 320 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 8, MULTI_GO_ON_RETIRE, TRUE
# 321 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 322 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 323 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 324 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 325 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 326 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 327 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink::
# 328 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
# 329 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 330 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 331 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 332 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 333 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 334 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 335 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg
# 336 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 337 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 338 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink::
# 339 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 340 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 341 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 342 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 343 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 344 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 345 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 346 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 347 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 348 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 349 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 350 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink::
# 351 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 352 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 353 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 354 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink
# 355 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 356 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 357 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 358 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink::
# 359 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
# 360 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 361 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 362 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 363 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 364 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 365 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 366 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 367 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 368 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink::
# 369 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special BattleTowerReconnectLink
# 370 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 371 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 372 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom:
# 373 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 374 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 375 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 376 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 377 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 378 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 379 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 380 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom:
# 381 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 382 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 383 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 384 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 385 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 386 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 387 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 388 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant:
# 389 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 390 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 391 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 392 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle:
# 393 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 394 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 395 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 396 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter:
# 397 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 398 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 399 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 400 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 401 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 402 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 403 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 404 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter:
# 405 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 406 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 407 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 408 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 409 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 410 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 411 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 412 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit:
# 413 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 414 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 415 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 416 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	set_invisible
# 417 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 418 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 419 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit:
# 420 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 421 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 422 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 423 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 424 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 425 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 426 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer:
# 427 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 428 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 429 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 430 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 431 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos:
# 432 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 433 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 434 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 435 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 436 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 437 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft:
# 438 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_left
# 439 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 440 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 441 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet:
# 442 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 443 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 444 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 445 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet:
# 446 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 447 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 448 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 449 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet:
# 450 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 451 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 452 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 453 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet:
# 454 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 455 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 456 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 457 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet:
# 458 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 459 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 460 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 461 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet:
# 462 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 463 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 464 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 465 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 466 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext:
# 467 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 468 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 469 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 470 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 471 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext:
# 472 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 473 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 474 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 475 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 476 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext:
# 477 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 478 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 479 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 480 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 481 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext:
# 482 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 483 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 484 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 485 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 486 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext:
# 487 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 488 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 489 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 490 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 491 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext:
# 492 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 493 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 494 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 495 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_LinkStandby3::
# 496 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Link standby…$"
# 497 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 498 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_YourPartnerHasRetired::
# 499 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your partner has retired.\p"
# 500 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your BATTLE ROOM challenge\n"
# 501 "data//maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "will be canceled.$"
