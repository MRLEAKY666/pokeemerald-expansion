# 1 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 2 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_MapScripts::
# 3 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_BattleTentBattleRoom_OnTransition
# 4 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentBattleRoom_OnWarp
# 5 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentBattleRoom_OnFrame
# 6 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 7 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 8 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ On this map the player (LOCALID_PLAYER) is hidden
# 9 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_SLATEPORT_TENT_BATTLE_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1
# 10 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 11 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnTransition:
# 12 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	call SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 13 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 14 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 15 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx::
# 16 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 17 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 18 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 19 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 20 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 21 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale::
# 22 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 23 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 24 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 25 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale::
# 26 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 27 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 28 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 29 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnWarp:
# 30 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects
# 31 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 32 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 33 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects::
# 34 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 36 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_SLATEPORT_TENT_BATTLE_OPPONENT, MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
# 37 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 38 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 39 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnFrame:
# 40 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom
# 41 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 42 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 43 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom::
# 44 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_SLATEPORT_TENT_BATTLE_PLAYER, SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter
# 45 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 46 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	factory_setopponentgfx
# 47 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_TENT_BATTLE_OPPONENT, 5, 1
# 48 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_SLATEPORT_TENT_BATTLE_OPPONENT
# 49 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	delay 1
# 50 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_SLATEPORT_TENT_BATTLE_OPPONENT
# 51 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_SLATEPORT_TENT_BATTLE_OPPONENT, SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter
# 52 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 54 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	lockall
# 55 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 56 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 57 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	closemessage
# 58 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 59 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	dofacilitytrainerbattle FACILITY_BATTLE_FACTORY
# 60 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 61 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 62 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 1, SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 63 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTent_EventScript_WarpToLobbyLost::
# 64 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 65 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 66 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 6, 6
# 67 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 68 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 69 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 70 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent::
# 71 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 72 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 73 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 74 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 75 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 3, SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 76 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 77 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 2, 3
# 78 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 79 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 80 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 81 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon::
# 82 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 83 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 84 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 6, 6
# 85 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 86 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 87 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 88 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter:
# 89 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 90 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 91 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 92 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_right
# 93 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
# 94 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 95 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter:
# 96 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 97 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 98 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 99 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 100 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_faster_left
# 101 "data//maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
