# 1 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 2 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_MapScripts::
# 3 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_OnTransition
# 4 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnWarp
# 5 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnFrame
# 6 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.byte 0
# 7 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 8 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ On this map the player (LOCALID_PLAYER) is hidden
# 9 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ The player is represented instead by LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, and has the gfx id VAR_OBJ_GFX_ID_F
# 10 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ The multi partner is represented by LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, and has the gfx id VAR_OBJ_GFX_ID_E
# 11 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 12 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnTransition:
# 13 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx
# 14 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx
# 15 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 16 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 17 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx::
# 18 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	tower_setpartnergfx
# 19 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	checkplayergender
# 20 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale
# 21 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 22 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 23 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 24 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale::
# 25 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 26 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 27 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 28 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx::
# 29 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 30 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 31 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 32 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnWarp:
# 33 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects
# 34 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 35 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 36 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects::
# 37 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 38 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 39 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 40 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special OffsetCameraForBattle
# 41 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 42 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 43 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnFrame:
# 44 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor
# 45 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 46 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 47 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor::
# 48 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	lockall
# 49 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 50 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 51 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 52 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 1, 1
# 53 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 54 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 55 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 56 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 57 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 58 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 59 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 60 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 61 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 62 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 63 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 1, 1
# 64 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 65 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 66 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor
# 67 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor
# 68 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor
# 69 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor
# 70 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 71 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 40
# 72 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, Common_Movement_WalkInPlaceFasterUp
# 73 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, Common_Movement_WalkInPlaceFasterUp
# 74 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 75 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 7, 1
# 76 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 77 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 78 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 79 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 80 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_TOWER_MULTI_CORRIDOR_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 81 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 82 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 7, 1
# 83 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 84 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 30
# 85 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 86 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom
# 87 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	releaseall
# 88 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 89 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 90 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom::
# 91 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 92 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 93 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom
# 94 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom
# 95 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 96 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 97 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom::
# 98 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
# 99 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 100 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 101 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 102 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom::
# 103 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 4, 5
# 104 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 105 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 106 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 107 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ Unnecessary duplicate of the above
# 108 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom::
# 109 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 4, 5
# 110 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 111 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 112 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 113 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor:
# 114 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 115 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 116 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 117 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 118 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 119 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 120 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 121 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 122 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 123 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor:
# 124 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 125 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 126 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 127 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 128 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 130 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 131 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 132 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 133 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor:
# 134 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 135 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 136 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 137 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 138 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 139 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 140 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 141 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_right
# 142 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 143 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 144 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor:
# 145 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 146 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 147 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 148 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 149 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 150 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 151 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 152 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_left
# 153 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 154 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 155 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor:
# 156 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay_16
# 157 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 158 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 159 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 160 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 161 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 162 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor:
# 163 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 164 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 165 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 166 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 167 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator:
# 168 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 169 "data//maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
