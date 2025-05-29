# 1 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 2 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 3 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
# 4 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_VERDANTURF_TENT_BATTLE_PLAYER).
# 5 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_1.
# 6 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
@ The graphics of the opponent are represented with VAR_OBJ_GFX_ID_0, which will ultimately be set by tower_setopponent.
# 7 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 8 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_MapScripts::
# 9 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentBattleRoom_OnTransition
# 10 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentBattleRoom_OnFrame
# 11 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentBattleRoom_OnWarp
# 12 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 13 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 14 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnTransition:
# 15 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 16 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 17 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 18 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 19 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 20 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 21 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 22 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 23 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 24 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 25 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 26 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 27 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 28 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 29 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 30 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 31 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 32 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 33 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 34 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnFrame:
# 35 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom
# 36 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 37 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 38 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom::
# 39 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 40 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter
# 41 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 42 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 43 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 44 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter::
# 45 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 46 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 47 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter
# 48 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 49 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 50 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 51 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 52 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 53 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 54 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 55 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost::
# 56 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 57 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 58 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 59 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 60 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 61 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 62 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 63 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 64 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 65 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 66 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 3, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 67 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit
# 68 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 69 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 70 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
# 71 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 72 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 73 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 74 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 75 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 76 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 77 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 78 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 79 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 80 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 81 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge::
# 82 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 83 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 84 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 85 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 86 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 87 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 88 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 89 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 2, VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 90 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 91 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge::
# 92 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 93 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 94 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case NO, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 95 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case YES, VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 96 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 97 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 98 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge::
# 99 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 100 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 101 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 102 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 103 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 104 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 105 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 106 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 107 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge::
# 108 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_ATTENDANT, Common_Movement_WalkInPlaceFasterRight
# 109 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 110 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 111 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 112 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 113 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 114 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 115 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 116 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 117 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 6, 6
# 118 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 119 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 120 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge::
# 121 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 122 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 123 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	verdanturftent_save CHALLENGE_STATUS_PAUSED
# 124 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 125 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 126 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 127 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 128 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 129 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 130 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnWarp:
# 131 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 132 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 133 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 134 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects::
# 135 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_VERDANTURF_TENT_BATTLE_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 136 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 137 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 138 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible
# 139 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_VERDANTURF_TENT_BATTLE_OPPONENT
# 140 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 141 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 142 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent::
# 143 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 144 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 145 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 146 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 147 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent::
# 148 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 149 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 150 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 151 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 152 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible:
# 153 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_invisible
# 154 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 155 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 156 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter:
# 157 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_visible
# 158 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 159 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 160 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 161 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_right
# 162 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 163 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 164 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter:
# 165 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 166 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 167 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 168 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 169 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_left
# 170 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 171 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 172 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit:
# 173 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 174 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 175 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 176 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 177 "data//maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
