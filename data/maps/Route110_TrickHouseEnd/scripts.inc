# 1 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 2 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_MapScripts::
# 3 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
# 4 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
# 5 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
# 6 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
# 7 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.byte 0
# 8 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 9 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnResume:
# 10 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 11 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 12 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 13 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnTransition:
# 14 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 0
# 15 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 0
# 16 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	special SetTrickHouseNuggetFlag
# 17 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 18 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 19 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnWarp:
# 20 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
# 21 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 22 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 23 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
# 24 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	addobject LOCALID_TRICK_MASTER_END
# 25 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
# 26 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
# 27 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 28 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 29 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnFrame:
# 30 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
# 31 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 32 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 33 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CloseDoor::
# 34 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 36 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	special DrawWholeMapView
# 37 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 38 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 39 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
# 40 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
# 41 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 42 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 43 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMaster::
# 44 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	lock
# 45 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	faceplayer
# 46 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
# 47 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 1
# 48 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 49 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
# 50 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
# 51 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
# 52 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
# 53 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
# 54 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
# 55 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
# 56 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
# 57 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 58 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 59 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
# 60 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
# 61 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 62 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 63 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 64 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 65 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 66 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 67 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 68 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 69 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 70 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 71 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
# 72 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
# 73 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 74 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 75 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	unlockoutfit OUTFIT_UNUSUAL_RED
# 76 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	bufferoutfitname STR_VAR_1, OUTFIT_UNUSUAL_RED 
# 77 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call EventScript_ObtainedOutfit
# 78 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 79 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 80 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 81 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 82 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 83 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 84 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
# 85 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
# 86 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 87 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 88 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_TM_TAUNT, 2
# 89 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 90 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 91 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 92 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 93 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 94 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 95 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 96 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
# 97 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
# 98 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 99 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 100 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	giveitem ITEM_PP_MAX
# 101 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
# 102 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 103 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 104 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 105 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 106 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 107 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 108 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
# 109 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
# 110 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 111 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 112 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	unlockoutfit OUTFIT_GENDER_SWAPPED_STANDARD
# 113 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	bufferoutfitname STR_VAR_1, OUTFIT_GENDER_SWAPPED_STANDARD 
# 114 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call EventScript_ObtainedOutfit
# 115 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 116 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 117 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 118 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 119 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 120 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 121 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
# 122 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
# 123 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 124 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 125 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	unlockoutfit OUTFIT_OLD_MAN
# 126 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	bufferoutfitname STR_VAR_1, OUTFIT_OLD_MAN 
# 127 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call EventScript_ObtainedOutfit
# 128 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 129 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 130 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 131 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 132 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 133 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 134 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
# 135 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
# 136 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 137 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 138 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	unlockoutfit OUTFIT_GENDER_SWAPPED_RED
# 139 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	bufferoutfitname STR_VAR_1, OUTFIT_GENDER_SWAPPED_RED
# 140 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call EventScript_ObtainedOutfit
# 141 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 142 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 143 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 144 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 145 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 146 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 147 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
# 148 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
# 149 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 150 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
# 151 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
# 152 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
# 153 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
# 154 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 155 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
# 156 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 157 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
# 158 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 159 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 160 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
# 161 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 162 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_ChooseTent
# 163 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
# 164 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
# 165 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 166 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	special ResetTrickHouseNuggetFlag
# 167 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 168 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 169 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 170 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_ChooseTent::
# 171 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 172 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_RESULT
# 173 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
# 174 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent
# 175 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 176 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveRedTent::
# 177 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_RED_TENT
# 178 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 179 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 180 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveBlueTent::
# 181 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 182 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 183 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 184 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExit::
# 185 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
# 186 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 187 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 188 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 189 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 190 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	removeobject LOCALID_TRICK_MASTER_END
# 191 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	addvar VAR_TRICK_HOUSE_LEVEL, 1
# 192 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 193 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 194 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_BagFull::
# 195 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_BagIsFull
# 196 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
# 197 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 198 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 199 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 200 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_NoRoomForTent::
# 201 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 202 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
# 203 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 204 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 205 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 206 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
# 207 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
# 208 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 209 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 210 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 211 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
# 212 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
# 213 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 214 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 215 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 216 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
# 217 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
# 218 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 219 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 220 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 221 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
# 222 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
# 223 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 224 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 225 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 226 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
# 227 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	lockall
# 228 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
# 229 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_PIN
# 230 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
# 231 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 232 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	delay 20
# 233 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
# 234 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 235 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 236 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 237 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 238 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
# 239 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 240 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
# 241 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 242 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	delay 4
# 243 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
# 244 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	releaseall
# 245 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 246 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 247 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
# 248 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	walk_down
# 249 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 250 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 251 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
# 252 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	jump_in_place_left
# 253 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 254 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 255 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouveMadeItToMe:
# 256 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Aak!\n"
# 257 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You've made it to me?\l"
# 258 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Hmmm… You're sharp!$"
# 259 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 260 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
# 261 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to plant all those\n"
# 262 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "trees…\p"
# 263 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're above me in greatness!\n"
# 264 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Possibly…$"
# 265 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 266 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
# 267 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make the maze…\p"
# 268 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 269 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five places!$"
# 270 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 271 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
# 272 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to prepare\n"
# 273 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the wall panels…\p"
# 274 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 275 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four places!$"
# 276 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 277 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
# 278 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to shove in those\n"
# 279 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "boulders…\p"
# 280 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 281 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three places!$"
# 282 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 283 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
# 284 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make MECHADOLLS\n"
# 285 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and another to think up the quiz…\p"
# 286 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 287 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two places!$"
# 288 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 289 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
# 290 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to install\n"
# 291 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the doors…\p"
# 292 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness!$"
# 293 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 294 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
# 295 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night setting up arrows…\p"
# 296 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're my equal in greatness!$"
# 297 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 298 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
# 299 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night polishing floors…\p"
# 300 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 301 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five, six places!$"
# 302 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 303 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
# 304 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Wh-what should I do?\n"
# 305 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "My fountain of ideas for tricks has\l"
# 306 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "run dry…\p"
# 307 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Perhaps it is time I toured the country\n"
# 308 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "on a quest to devise new tricks…$"
# 309 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 310 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
# 311 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I hate to admit defeat, but you have\n"
# 312 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "bested me!\p"
# 313 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Still, you must have been reeled in by\n"
# 314 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "my charisma for you to visit me again\l"
# 315 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and again. Yes, you must have!\p"
# 316 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But that has nothing to do with my\n"
# 317 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "losing!\p"
# 318 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "In recognition of the friendship\n"
# 319 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "between you, the driven, and the genius\l"
# 320 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "that is myself, I demand that you take\l"
# 321 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "this keepsake!\p"
# 322 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Actually there are two--\n"
# 323 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "a RED TENT and a BLUE TENT.\l"
# 324 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Which do you prefer?$"
# 325 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 326 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomInPC:
# 327 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? No room in your PC?\n"
# 328 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What am I to make of that?\p"
# 329 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish I could say that, but I am much\n"
# 330 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "too kind and caring, so come back later!$"
# 331 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 332 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_LeavingOnJourney:
# 333 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "… … … … … …\p"
# 334 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I am leaving on a journey of discovery.\n"
# 335 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "A quest in search of new tricks.\p"
# 336 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish that you will one day visit and\n"
# 337 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "entertain me again.\p"
# 338 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "And now, farewell!$"
# 339 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 340 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
# 341 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Fine!\n"
# 342 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You have earned this reward!$"
# 343 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 344 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomForThis:
# 345 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? Have you no room for this?\n"
# 346 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What manner of items do you carry?\p"
# 347 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But fine, since you've reached me,\n"
# 348 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "your reward will be with me till later.$"
# 349 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 350 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
# 351 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Scrub that smug smirk from your face!\n"
# 352 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It's much too early to think you've won!\p"
# 353 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I'll make new tricks to stump you, I will.\n"
# 354 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You may mock me only when you're done.\p"
# 355 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Come back for the next exciting\n"
# 356 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "installment!$"
# 357 "data//maps/Route110_TrickHouseEnd/scripts.pory"

# 358 "data//maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YoureIgnoringMe:
# 359 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now, now! You're ignoring me now?\n"
# 360 "data//maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now that, I consider heartbreaking!$"
