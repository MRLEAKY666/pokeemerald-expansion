# 1 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 2 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_MapScripts::
# 3 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
# 4 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_OnFrame
# 5 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_OnWarp
# 6 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.byte 0
# 7 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 8 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
# 9 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 0: Trick Master is hiding
# 10 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 1: Trick Master has left at start of challenge
# 11 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
# 12 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 3: Trick Master still making next puzzle
# 13 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 4: Finished final puzzle
# 14 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 5: Completed previous challenge
# 15 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)
# 16 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 17 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnTransition:
# 18 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setflag FLAG_LANDMARK_TRICK_HOUSE
# 19 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1, Route110_TrickHouseEntrance_EventScript_EnterFromCorridor
# 20 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PRIZE_PICKUP, 1, Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward
# 21 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
# 22 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 23 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 24 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 25 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 26 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
# 27 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1
# 28 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2
# 29 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3
# 30 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 31 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 32 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward::
# 33 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 34 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward
# 35 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
# 36 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 37 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 38 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward::
# 39 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
# 40 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 41 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 42 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterFromCorridor::
# 43 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
# 44 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
# 45 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 46 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 47 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 48 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle::
# 49 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
# 50 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
# 51 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
# 52 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
# 53 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
# 54 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
# 55 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
# 56 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
# 57 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_FinishedPuzzles
# 58 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 59 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 60 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2::
# 61 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 62 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 3, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 63 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 64 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 65 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3::
# 66 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 67 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 4, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 68 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 69 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 70 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4::
# 71 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 72 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 5, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 73 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 74 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 75 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5::
# 76 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 77 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 6, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 78 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 79 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 80 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6::
# 81 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 82 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 7, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 83 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 84 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 85 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7::
# 86 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	@ call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 87 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_lt VAR_BADGE_COUNT, 8, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 88 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 89 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 90 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8::
# 91 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 92 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 93 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 94 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FinishedPuzzles::
# 95 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
# 96 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 97 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 98 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle::
# 99 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
# 100 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 101 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 102 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor::
# 103 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
# 104 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 105 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 106 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger::
# 107 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
# 108 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 109 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 110 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1::
# 111 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 112 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 113 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 114 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2::
# 115 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 116 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 117 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 118 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3::
# 119 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 120 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 121 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 122 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnWarp:
# 123 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_TrickMasterFound
# 124 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
# 125 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 126 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
# 127 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
# 128 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 129 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 130 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
# 131 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.2byte 0
# 132 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 133 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMasterFound::
# 134 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 135 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
# 136 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 137 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 138 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 139 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 140 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot::
# 141 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 142 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	hideobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
# 143 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 144 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
# 145 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
# 146 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
# 147 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
# 148 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
# 149 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
# 150 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
# 151 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
# 152 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 153 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 154 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1::
# 155 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
# 156 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 157 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 158 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2::
# 159 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
# 160 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 161 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 162 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3::
# 163 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
# 164 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 165 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 166 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4::
# 167 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
# 168 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 169 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 170 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5::
# 171 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
# 172 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 173 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 174 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6::
# 175 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
# 176 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 177 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 178 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7::
# 179 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
# 180 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 181 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 182 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8::
# 183 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
# 184 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 185 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 186 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster::
# 187 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 188 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 189 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 190 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor::
# 191 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 192 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
# 193 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
# 194 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 195 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 196 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor::
# 197 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 198 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
# 199 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
# 200 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 201 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 202 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnFrame:
# 203 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_BeginChallenge
# 204 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.2byte 0
# 205 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 206 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_BeginChallenge::
# 207 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 208 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 209 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_MeetTrickMaster
# 210 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
# 211 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 212 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 213 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 214 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 215 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_M_EXPLOSION
# 216 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 217 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 218 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 219 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
# 220 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
# 221 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 222 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 223 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 224 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_UnusedRelease::
# 225 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 226 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 227 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 228 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMaster::
# 229 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 230 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 231 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_FoundTrickMaster
# 232 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_GiveReward
# 233 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle
# 234 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_MechadollReward
# 235 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 236 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 237 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundTrickMaster::
# 238 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 239 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 240 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 241 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
# 242 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 243 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk
# 244 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_FoundBehindTree
# 245 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_FoundInDresser
# 246 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow
# 247 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_FoundInPlanter
# 248 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_FoundInCupboard
# 249 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_FoundBehindWindow
# 250 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion
# 251 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 252 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
# 253 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 6, 2
# 254 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 255 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 256 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 257 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 258 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk::
# 259 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
# 260 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 261 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 262 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBehindTree::
# 263 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
# 264 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 265 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 266 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInDresser::
# 267 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
# 268 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 269 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 270 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow::
# 271 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
# 272 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 273 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 274 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInPlanter::
# 275 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
# 276 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 277 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 278 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInCupboard::
# 279 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
# 280 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 281 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 282 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBehindWindow::
# 283 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
# 284 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 285 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 286 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion::
# 287 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
# 288 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 289 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 290 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouse_Movement_TrickMasterSpin:
# 291 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	face_up
# 292 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 293 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	face_left
# 294 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 295 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	face_down
# 296 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 297 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	face_right
# 298 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 299 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 300 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 301 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouse_Movement_TrickMasterJumpAway:
# 302 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	face_up
# 303 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	disable_anim
# 304 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 305 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 306 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 307 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 308 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 309 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 310 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 311 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 312 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MeetTrickMaster::
# 313 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
# 314 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 315 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 316 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle::
# 317 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
# 318 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 319 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 320 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 321 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 322 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
# 323 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 324 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
# 325 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 326 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
# 327 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
# 328 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 329 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 330 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 331 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 332 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveReward::
# 333 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 334 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 335 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
# 336 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward
# 337 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward
# 338 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward
# 339 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward
# 340 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward
# 341 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward
# 342 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward
# 343 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 344 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 345 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward::
# 346 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 347 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 348 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 349 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 350 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 351 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 352 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 353 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward::
# 354 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_TIMER_BALL
# 355 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 356 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 357 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 358 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 359 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 360 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 361 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward::
# 362 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_HARD_STONE
# 363 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 364 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 365 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 366 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 367 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 368 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 369 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward::
# 370 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_SMOKE_BALL
# 371 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 372 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 373 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 374 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 375 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 376 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 377 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward::
# 378 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_TM_TAUNT, 2
# 379 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 380 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 381 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 382 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 383 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 384 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 385 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward::
# 386 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_MAGNET
# 387 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 388 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 389 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 390 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 391 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 392 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 393 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward::
# 394 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_PP_MAX
# 395 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
# 396 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 397 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 398 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 399 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 400 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 401 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GotReward::
# 402 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 403 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
# 404 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
# 405 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 406 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 407 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 408 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 409 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MechadollReward::
# 410 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 411 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 412 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
# 413 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_ChooseTent
# 414 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_ReceivedTent
# 415 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_NoRoomForDecor
# 416 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
# 417 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 418 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 419 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 420 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ChooseTent::
# 421 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 422 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_RESULT
# 423 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_GiveRedTent
# 424 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto Route110_TrickHouseEntrance_EventScript_GiveBlueTent
# 425 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 426 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveRedTent::
# 427 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	givedecoration DECOR_RED_TENT
# 428 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 429 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 430 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveBlueTent::
# 431 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 432 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 433 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 434 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReceivedTent::
# 435 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
# 436 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 437 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 438 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 439 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 440 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 441 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_M_EXPLOSION
# 442 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 443 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 444 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 445 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 446 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
# 447 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 448 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 449 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 450 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_Door::
# 451 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 452 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 453 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_ItsAScroll
# 454 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_GoInHolePrompt
# 455 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote
# 456 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage
# 457 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 458 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 459 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ItsAScroll::
# 460 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
# 461 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 462 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 463 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 464 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GoInHolePrompt::
# 465 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
# 466 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 467 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom
# 468 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 469 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 470 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 471 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom::
# 472 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, FALSE
# 473 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 474 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 475 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
# 476 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 477 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, Route110_TrickHouseEntrance_Movement_EnterRoom
# 478 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 479 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 480 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8
# 481 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2
# 482 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3
# 483 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4
# 484 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5
# 485 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6
# 486 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7
# 487 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1
# 488 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 489 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 490 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Movement_EnterRoom:
# 491 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	set_invisible
# 492 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 493 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 494 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1::
# 495 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 0, 21
# 496 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 497 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 498 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 499 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 500 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2::
# 501 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 0, 21
# 502 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 503 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 504 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 505 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 506 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3::
# 507 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 0, 21
# 508 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 509 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 510 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 511 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 512 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4::
# 513 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 0, 21
# 514 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 515 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 516 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 517 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 518 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5::
# 519 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
# 520 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 521 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 522 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 523 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 524 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6::
# 525 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 0, 21
# 526 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 527 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 528 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 529 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 530 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7::
# 531 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 0, 21
# 532 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 533 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 534 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 535 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 536 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8::
# 537 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 0, 21
# 538 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 539 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 540 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 541 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 542 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote::
# 543 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
# 544 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 545 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 546 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 547 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage::
# 548 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2
# 549 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
# 550 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 551 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 552 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 553 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2::
# 554 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
# 555 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 556 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 557 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 558 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_Door::
# 559 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 560 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 561 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHousePuzzle1_EventScript_Door
# 562 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHousePuzzle2_EventScript_Door
# 563 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHousePuzzle3_EventScript_Door
# 564 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHousePuzzle4_EventScript_Door
# 565 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHousePuzzle5_EventScript_Door
# 566 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHousePuzzle6_EventScript_Door
# 567 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHousePuzzle7_EventScript_Door
# 568 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHousePuzzle8_EventScript_Door
# 569 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 570 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 571 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Door::
# 572 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 573 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 574 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 575 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
# 576 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 577 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 578 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 579 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 580 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 581 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Door::
# 582 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 583 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 584 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 585 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
# 586 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 587 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 588 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 589 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 590 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 591 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Door::
# 592 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 593 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 594 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 595 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
# 596 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 597 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 598 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 599 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 600 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 601 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Door::
# 602 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 603 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 604 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 605 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
# 606 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 607 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 608 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 609 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 610 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 611 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Door::
# 612 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 613 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 614 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 615 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
# 616 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 617 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 618 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 619 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 620 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 621 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Door::
# 622 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 623 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 624 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 625 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
# 626 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 627 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 628 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 629 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 630 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 631 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Door::
# 632 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 633 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 634 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 635 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
# 636 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 637 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 638 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 639 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 640 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 641 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Door::
# 642 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
# 643 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 644 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 645 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
# 646 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
# 647 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 648 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 649 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 650 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 651 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_DoorLocked::
# 652 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
# 653 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 654 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 655 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 656 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_ReadScrollAgain::
# 657 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
# 658 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 659 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 660 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 661 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_FoundScroll::
# 662 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 663 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	message Route110_TrickHousePuzzle_Text_FoundAScroll
# 664 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitfanfare
# 665 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle_Text_MemorizedSecretCode, MSGBOX_DEFAULT
# 666 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 667 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 668 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 669 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMasterHiding::
# 670 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 671 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
# 672 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 673 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
# 674 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
# 675 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
# 676 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 677 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 678 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 679 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1::
# 680 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 6  @ x
# 681 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 3  @ y
# 682 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 683 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 684 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 685 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2::
# 686 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 11  @ x
# 687 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 5   @ y
# 688 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 689 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 690 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 691 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3::
# 692 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 9  @ x
# 693 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 2  @ y
# 694 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 695 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 696 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 697 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle::
# 698 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8006, 0
# 699 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
# 700 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 701 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 10
# 702 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 703 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 704 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_YoureBeingWatched:
# 705 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You're being watched…$"
# 706 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 707 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk:
# 708 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 709 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 710 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beneath this desk? You're sharp!$"
# 711 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 712 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBehindTree:
# 713 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 714 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 715 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "behind this tree? You're sharp!$"
# 716 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 717 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInDresser:
# 718 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 719 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 720 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this dresser? You're sharp!$"
# 721 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 722 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConealedBeyondWindow:
# 723 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 724 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 725 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beyond this window? You're sharp!$"
# 726 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 727 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInPlanter:
# 728 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 729 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 730 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this planter? You're sharp!$"
# 731 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 732 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInCupboard:
# 733 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 734 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 735 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this cupboard? You're sharp!$"
# 736 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 737 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBehindWindow:
# 738 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 739 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 740 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "behind this window? You're sharp!$"
# 741 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 742 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion:
# 743 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 744 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 745 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beneath this cushion? You're sharp!$"
# 746 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 747 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster:
# 748 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Behold!\p"
# 749 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "For I am the greatest living mystery\n"
# 750 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "of a man in all of HOENN!\l"
# 751 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "They call me…\p"
# 752 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "The TRICK MASTER!\n"
# 753 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Wahahaha! Glad to meet you!$"
# 754 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 755 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse:
# 756 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You, you've come to challenge\n"
# 757 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "my TRICK HOUSE, haven't you?\p"
# 758 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "That's why you're here, isn't it?\n"
# 759 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Yes, it is!\p"
# 760 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Consider your challenge accepted!\p"
# 761 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Enter through the scroll there,\n"
# 762 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "and let your challenge commence!\p"
# 763 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I shall be waiting in the back!$"
# 764 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 765 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ItsAScroll:
# 766 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "It's a scroll.$"
# 767 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 768 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll:
# 769 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "There is a big hole behind the scroll!\p"
# 770 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Want to go in?$"
# 771 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 772 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote:
# 773 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "There is a note affixed to the scroll…\p"
# 774 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "“I am leaving on a journey.\n"
# 775 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Don't look for me. TRICK MASTER”$"
# 776 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 777 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick:
# 778 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "For the next time, I'll use this trick,\n"
# 779 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "and that scheme, and those ruses…\p"
# 780 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Mufufufu… If I may say so, it's\n"
# 781 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "brilliantly difficult, even for me!$"
# 782 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 783 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges:
# 784 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? What?!\n"
# 785 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Oh, it's you!\p"
# 786 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I'm in the midst of devising new tricky\n"
# 787 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "challenges!\p"
# 788 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "It's not too much to ask for a bit more\n"
# 789 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "time for me to think, is it now?\l"
# 790 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You wouldn't begrudge me that?\l"
# 791 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Come back in a little while!$"
# 792 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 793 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward:
# 794 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Ah, it's you! You're here to accept the\n"
# 795 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "reward from before, isn't that right?\l"
# 796 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Yes, right I am!\p"
# 797 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Here!\n"
# 798 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I'll give it to you now!$"
# 799 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 800 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward:
# 801 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah?\n"
# 802 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Did you not come to claim your reward?$"
# 803 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 804 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_MechadollWhichTent:
# 805 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "MECHADOLL 5 I AM!\n"
# 806 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "IF REWARD IS NOT TAKEN BY YOU,\l"
# 807 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "THEN TRICK MASTER YOU CANNOT FOLLOW.\p"
# 808 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "RED TENT OR BLUE TENT,\n"
# 809 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "WHICH DO YOU PREFER?$"
# 810 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 811 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ThenFarewell:
# 812 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "THEN FAREWELL.$"
# 813 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 814 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_PCFullAgain:
# 815 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "YOUR PC STATUS: FULL AGAIN.\n"
# 816 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "MEAN, YOU ARE.$"
# 817 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 818 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_FoundAScroll:
# 819 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "{PLAYER} found a scroll.$"
# 820 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 821 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_MemorizedSecretCode:
# 822 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "{PLAYER} memorized the secret code\n"
# 823 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "written on the scroll.$"
# 824 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 825 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt:
# 826 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "A secret code is written on it.$"
# 827 "data//maps/Route110_TrickHouseEntrance/scripts.pory"

# 828 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere:
# 829 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "The door is locked.\p"
# 830 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "…On closer inspection, this is written\n"
# 831 "data//maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "on it: “Write the secret code here.”$"
