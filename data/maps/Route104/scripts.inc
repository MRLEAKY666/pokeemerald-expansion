# 1 "data//maps/Route104/scripts.pory"

# 2 "data//maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 3 "data//maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data//maps/Route104/scripts.pory"
.set LOCALID_RIVAL, 34
# 5 "data//maps/Route104/scripts.pory"

# 6 "data//maps/Route104/scripts.pory"
Route104_MapScripts::
# 7 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route104_OnWarp
# 8 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 9 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 10 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route104_OnResume
# 11 "data//maps/Route104/scripts.pory"
	.byte 0
# 12 "data//maps/Route104/scripts.pory"

# 13 "data//maps/Route104/scripts.pory"
Route104_OnFrame:
# 14 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 15 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, Route104_EventScript_MrBrineyArrivesA
# 16 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 4, Route104_EventScript_MrBrineyArrivesB
# 17 "data//maps/Route104/scripts.pory"
	.2byte 0
# 18 "data//maps/Route104/scripts.pory"

# 19 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 20 "data//maps/Route104/scripts.pory"
	lockall
# 21 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 22 "data//maps/Route104/scripts.pory"
	end
# 23 "data//maps/Route104/scripts.pory"

# 24 "data//maps/Route104/scripts.pory"
Route104_OnTransition:
# 25 "data//maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 26 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 27 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 28 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_BRINEY_LOCATION, 4, Route104_EventScript_SetupPlayerClone
# 29 "data//maps/Route104/scripts.pory"
	end
# 30 "data//maps/Route104/scripts.pory"

# 31 "data//maps/Route104/scripts.pory"
Route104_OnWarp:
# 32 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 4, Route104_EventScript_SetupBrineyReturnScene
# 33 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 5, Route104_EventScript_FinishBrineyReturnScene
# 34 "data//maps/Route104/scripts.pory"
	.2byte 0
# 35 "data//maps/Route104/scripts.pory"

# 36 "data//maps/Route104/scripts.pory"
Route104_OnResume:
# 37 "data//maps/Route104/scripts.pory"
	call_if_set FLAG_TEMP_9, Route104_EventScript_SummonMrBriney
# 38 "data//maps/Route104/scripts.pory"
	end 
# 39 "data//maps/Route104/scripts.pory"
	
# 40 "data//maps/Route104/scripts.pory"
Route104_EventScript_SummonMrBriney::
# 41 "data//maps/Route104/scripts.pory"
	setvar VAR_TEMP_0, 1
# 42 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 1
# 43 "data//maps/Route104/scripts.pory"
	call EventScript_ResetMrBriney
# 44 "data//maps/Route104/scripts.pory"
	clearflag FLAG_TEMP_9
# 45 "data//maps/Route104/scripts.pory"
	return
# 46 "data//maps/Route104/scripts.pory"

# 47 "data//maps/Route104/scripts.pory"
Route104_EventScript_SetupBrineyReturnScene::
# 48 "data//maps/Route104/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE104
# 49 "data//maps/Route104/scripts.pory"
	setobjectxy LOCALID_ROUTE104_BOAT, 12, 60
# 50 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_ROUTE104_BOAT, 12, 60
# 51 "data//maps/Route104/scripts.pory"
	return

Route104_EventScript_SetupPlayerClone::
# 55 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8004, VAR_0x8005
# 56 "data//maps/Route104/scripts.pory"
	setobjectxy LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8004, VAR_0x8005
# 57 "data//maps/Route104/scripts.pory"
	checkplayergender
# 58 "data//maps/Route104/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Route104_EventScript_SetupPlayerClone_2
# 62 "data//maps/Route104/scripts.pory"
	setvar VAR_OBJ_GFX_ID_9, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
Route104_EventScript_SetupPlayerClone_1:
# 64 "data//maps/Route104/scripts.pory"
	switch VAR_0x8006
# 65 "data//maps/Route104/scripts.pory"
	case DIR_NORTH, Route104_EventScript_SetupPlayerClone_7
# 67 "data//maps/Route104/scripts.pory"
	case DIR_SOUTH, Route104_EventScript_SetupPlayerClone_8
# 69 "data//maps/Route104/scripts.pory"
	case DIR_EAST, Route104_EventScript_SetupPlayerClone_9
# 71 "data//maps/Route104/scripts.pory"
	case DIR_WEST, Route104_EventScript_SetupPlayerClone_10
Route104_EventScript_SetupPlayerClone_5:
# 74 "data//maps/Route104/scripts.pory"
	addobject LOCALID_ROUTE104_DUMMY_GUY
	return

Route104_EventScript_SetupPlayerClone_2:
# 59 "data//maps/Route104/scripts.pory"
	setvar VAR_OBJ_GFX_ID_9, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto Route104_EventScript_SetupPlayerClone_1

Route104_EventScript_SetupPlayerClone_7:
# 66 "data//maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE104_DUMMY_GUY, MOVEMENT_TYPE_FACE_UP
	goto Route104_EventScript_SetupPlayerClone_5

Route104_EventScript_SetupPlayerClone_8:
# 68 "data//maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE104_DUMMY_GUY, MOVEMENT_TYPE_FACE_DOWN
	goto Route104_EventScript_SetupPlayerClone_5

Route104_EventScript_SetupPlayerClone_9:
# 70 "data//maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE104_DUMMY_GUY, MOVEMENT_TYPE_FACE_RIGHT
	goto Route104_EventScript_SetupPlayerClone_5

Route104_EventScript_SetupPlayerClone_10:
# 72 "data//maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE104_DUMMY_GUY, MOVEMENT_TYPE_FACE_LEFT
	goto Route104_EventScript_SetupPlayerClone_5


Route104_EventScript_FinishBrineyReturnScene::
# 79 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 1
# 80 "data//maps/Route104/scripts.pory"
	switch VAR_0x8006
# 81 "data//maps/Route104/scripts.pory"
	case DIR_NORTH, Route104_EventScript_FinishBrineyReturnScene_3
# 83 "data//maps/Route104/scripts.pory"
	case DIR_SOUTH, Route104_EventScript_FinishBrineyReturnScene_4
# 85 "data//maps/Route104/scripts.pory"
	case DIR_EAST, Route104_EventScript_FinishBrineyReturnScene_5
# 87 "data//maps/Route104/scripts.pory"
	case DIR_WEST, Route104_EventScript_FinishBrineyReturnScene_6
Route104_EventScript_FinishBrineyReturnScene_1:
	return

Route104_EventScript_FinishBrineyReturnScene_3:
# 82 "data//maps/Route104/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto Route104_EventScript_FinishBrineyReturnScene_1

Route104_EventScript_FinishBrineyReturnScene_4:
# 84 "data//maps/Route104/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto Route104_EventScript_FinishBrineyReturnScene_1

Route104_EventScript_FinishBrineyReturnScene_5:
# 86 "data//maps/Route104/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto Route104_EventScript_FinishBrineyReturnScene_1

Route104_EventScript_FinishBrineyReturnScene_6:
# 88 "data//maps/Route104/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto Route104_EventScript_FinishBrineyReturnScene_1


# 93 "data//maps/Route104/scripts.pory"

# 94 "data//maps/Route104/scripts.pory"

# 95 "data//maps/Route104/scripts.pory"
Route104_EventScript_MrBrineyArrivesA::
# 96 "data//maps/Route104/scripts.pory"
	hidefollower
# 97 "data//maps/Route104/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 98 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_0x8006
# 99 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 4                                       @ arriving alone to house
# 100 "data//maps/Route104/scripts.pory"
	delay 30
# 101 "data//maps/Route104/scripts.pory"
	warpsilent MAP_ROUTE104, 16, 52

Route104_EventScript_MrBrineyArrivesB::
# 106 "data//maps/Route104/scripts.pory"
	delay 30
# 107 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 1
# 108 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_MrBrineyArrives
# 109 "data//maps/Route104/scripts.pory"
	waitmovement
# 110 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 111 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_27
Route104_EventScript_MrBrineyArrivesB_25:
# 117 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 12
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_24
Route104_EventScript_MrBrineyArrivesB_22:
# 123 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 13
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_21
Route104_EventScript_MrBrineyArrivesB_19:
# 129 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 14
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_18
Route104_EventScript_MrBrineyArrivesB_16:
# 135 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 15
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_15
Route104_EventScript_MrBrineyArrivesB_13:
# 141 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 16
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_12
Route104_EventScript_MrBrineyArrivesB_10:
# 147 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_E, 17
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_9
Route104_EventScript_MrBrineyArrivesB_1:
# 153 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_ROUTE104_BRINEY, 12, 53
# 154 "data//maps/Route104/scripts.pory"
	delay 15
# 155 "data//maps/Route104/scripts.pory"
	addobject LOCALID_ROUTE104_BRINEY
# 156 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE104_BRINEY, MAP_ROUTE104, 0
# 157 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BRINEY, Route104_Movement_MrBrineyDisembark
# 158 "data//maps/Route104/scripts.pory"
	waitmovement
# 159 "data//maps/Route104/scripts.pory"
	addobject LOCALID_ROUTE104_PEEKO
# 160 "data//maps/Route104/scripts.pory"
	setobjectxy LOCALID_ROUTE104_PEEKO, 12, 53
# 161 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_ROUTE104_PEEKO, 12, 53
# 162 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE104_PEEKO, MAP_ROUTE104, 0
# 163 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_PEEKO, Route104_Movement_PeekoDisembark
# 164 "data//maps/Route104/scripts.pory"
	waitmovement
# 165 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BRINEY, Route104_Movement_MrBrineyWalkHome
# 166 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_PEEKO, Route104_Movement_PeekoWalkHome
# 167 "data//maps/Route104/scripts.pory"
	waitmovement LOCALID_ROUTE104_BRINEY
# 168 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BRINEY, Route104_Movement_MrBrineyGoInside
# 169 "data//maps/Route104/scripts.pory"
	playse SE_EXIT
# 170 "data//maps/Route104/scripts.pory"
	waitmovement
# 171 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_PEEKO, Route104_Movement_PeekoGoInside
# 172 "data//maps/Route104/scripts.pory"
	playse SE_EXIT
# 173 "data//maps/Route104/scripts.pory"
	waitmovement
# 174 "data//maps/Route104/scripts.pory"
	delay 60
# 175 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 5
# 176 "data//maps/Route104/scripts.pory"
	warpsilent MAP_ROUTE104, VAR_0x8004, VAR_0x8005
	end

Route104_EventScript_MrBrineyArrivesB_2:
# 112 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionA
# 113 "data//maps/Route104/scripts.pory"
	waitmovement
# 114 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 115 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_3:
# 118 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionB
# 119 "data//maps/Route104/scripts.pory"
	waitmovement
# 120 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 121 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_4:
# 124 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionC
# 125 "data//maps/Route104/scripts.pory"
	waitmovement
# 126 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 127 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_5:
# 130 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionC
# 131 "data//maps/Route104/scripts.pory"
	waitmovement
# 132 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 133 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_6:
# 136 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionC
# 137 "data//maps/Route104/scripts.pory"
	waitmovement
# 138 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 139 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_7:
# 142 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionC
# 143 "data//maps/Route104/scripts.pory"
	waitmovement
# 144 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 145 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_8:
# 148 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_DUMMY_GUY, Route104_Movement_AvoidPlayerCollisionC
# 149 "data//maps/Route104/scripts.pory"
	waitmovement
# 150 "data//maps/Route104/scripts.pory"
	getobjectxy LOCALID_ROUTE104_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 151 "data//maps/Route104/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE104_DUMMY_GUY, VAR_0x8006
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_9:
# 147 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_8
	goto Route104_EventScript_MrBrineyArrivesB_1

Route104_EventScript_MrBrineyArrivesB_12:
# 141 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_7
	goto Route104_EventScript_MrBrineyArrivesB_10

Route104_EventScript_MrBrineyArrivesB_15:
# 135 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_6
	goto Route104_EventScript_MrBrineyArrivesB_13

Route104_EventScript_MrBrineyArrivesB_18:
# 129 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_5
	goto Route104_EventScript_MrBrineyArrivesB_16

Route104_EventScript_MrBrineyArrivesB_21:
# 123 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_4
	goto Route104_EventScript_MrBrineyArrivesB_19

Route104_EventScript_MrBrineyArrivesB_24:
# 117 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 51
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_3
	goto Route104_EventScript_MrBrineyArrivesB_22

Route104_EventScript_MrBrineyArrivesB_27:
# 111 "data//maps/Route104/scripts.pory"
	compare VAR_TEMP_F, 52
	goto_if_eq Route104_EventScript_MrBrineyArrivesB_2
	goto Route104_EventScript_MrBrineyArrivesB_25


# 180 "data//maps/Route104/scripts.pory"
Route104_Movement_AvoidPlayerCollisionA:
# 181 "data//maps/Route104/scripts.pory"
	walk_right
# 182 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 183 "data//maps/Route104/scripts.pory"
	step_end

# 186 "data//maps/Route104/scripts.pory"
Route104_Movement_AvoidPlayerCollisionB:
# 187 "data//maps/Route104/scripts.pory"
	walk_right
# 188 "data//maps/Route104/scripts.pory"
	walk_down
# 189 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 190 "data//maps/Route104/scripts.pory"
	step_end

# 193 "data//maps/Route104/scripts.pory"
Route104_Movement_AvoidPlayerCollisionC:
# 194 "data//maps/Route104/scripts.pory"
	walk_down
# 195 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 196 "data//maps/Route104/scripts.pory"
	step_end

# 199 "data//maps/Route104/scripts.pory"

# 200 "data//maps/Route104/scripts.pory"
	
# 201 "data//maps/Route104/scripts.pory"
Route104_Movement_MrBrineyArrives:
# 202 "data//maps/Route104/scripts.pory"
	walk_fast_up
# 203 "data//maps/Route104/scripts.pory"
	walk_fast_up
# 204 "data//maps/Route104/scripts.pory"
	walk_up
# 205 "data//maps/Route104/scripts.pory"
	walk_up
# 206 "data//maps/Route104/scripts.pory"
	walk_up
# 207 "data//maps/Route104/scripts.pory"
	walk_up
# 208 "data//maps/Route104/scripts.pory"
	step_end
# 209 "data//maps/Route104/scripts.pory"

# 210 "data//maps/Route104/scripts.pory"
Route104_Movement_MrBrineyDisembark:
# 211 "data//maps/Route104/scripts.pory"
	walk_up
# 212 "data//maps/Route104/scripts.pory"
	walk_up
# 213 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_down
# 214 "data//maps/Route104/scripts.pory"
	step_end
# 215 "data//maps/Route104/scripts.pory"

# 216 "data//maps/Route104/scripts.pory"
Route104_Movement_PeekoDisembark:
# 217 "data//maps/Route104/scripts.pory"
	set_visible
# 218 "data//maps/Route104/scripts.pory"
	walk_up
# 219 "data//maps/Route104/scripts.pory"
	step_end	
# 220 "data//maps/Route104/scripts.pory"

# 221 "data//maps/Route104/scripts.pory"
Route104_Movement_MrBrineyWalkHome:
# 222 "data//maps/Route104/scripts.pory"
	walk_right
# 223 "data//maps/Route104/scripts.pory"
	walk_right
# 224 "data//maps/Route104/scripts.pory"
	walk_right
# 225 "data//maps/Route104/scripts.pory"
	walk_right
# 226 "data//maps/Route104/scripts.pory"
	walk_right
# 227 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_up
# 228 "data//maps/Route104/scripts.pory"
	step_end
# 229 "data//maps/Route104/scripts.pory"

# 230 "data//maps/Route104/scripts.pory"
Route104_Movement_PeekoWalkHome:
# 231 "data//maps/Route104/scripts.pory"
	walk_up
# 232 "data//maps/Route104/scripts.pory"
	walk_right
# 233 "data//maps/Route104/scripts.pory"
	walk_right
# 234 "data//maps/Route104/scripts.pory"
	walk_right
# 235 "data//maps/Route104/scripts.pory"
	walk_right
# 236 "data//maps/Route104/scripts.pory"
	step_end
# 237 "data//maps/Route104/scripts.pory"

# 238 "data//maps/Route104/scripts.pory"
Route104_Movement_MrBrineyGoInside:
# 239 "data//maps/Route104/scripts.pory"
	walk_up
# 240 "data//maps/Route104/scripts.pory"
	set_invisible
# 241 "data//maps/Route104/scripts.pory"
	step_end
# 242 "data//maps/Route104/scripts.pory"
	
# 243 "data//maps/Route104/scripts.pory"
Route104_Movement_PeekoGoInside:
# 244 "data//maps/Route104/scripts.pory"
	walk_right
# 245 "data//maps/Route104/scripts.pory"
	walk_up
# 246 "data//maps/Route104/scripts.pory"
	set_invisible
# 247 "data//maps/Route104/scripts.pory"
	step_end
# 248 "data//maps/Route104/scripts.pory"

# 249 "data//maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 250 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 251 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 252 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 253 "data//maps/Route104/scripts.pory"
	return
# 254 "data//maps/Route104/scripts.pory"

# 255 "data//maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 256 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 257 "data//maps/Route104/scripts.pory"
	return
# 258 "data//maps/Route104/scripts.pory"

# 259 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 260 "data//maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 261 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 262 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 263 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 17, 52
# 264 "data//maps/Route104/scripts.pory"
	return
# 265 "data//maps/Route104/scripts.pory"

# 266 "data//maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 267 "data//maps/Route104/scripts.pory"
	return
# 268 "data//maps/Route104/scripts.pory"

# 269 "data//maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 270 "data//maps/Route104/scripts.pory"
	lockall
# 271 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 272 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 273 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 274 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 275 "data//maps/Route104/scripts.pory"

# 276 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 277 "data//maps/Route104/scripts.pory"
	lockall
# 278 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 279 "data//maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 280 "data//maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 281 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 282 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 283 "data//maps/Route104/scripts.pory"
	delay 10
# 284 "data//maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL
# 285 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 286 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 287 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 288 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 289 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 290 "data//maps/Route104/scripts.pory"
	delay 20
# 291 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 292 "data//maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 293 "data//maps/Route104/scripts.pory"
	playse SE_PIN
# 294 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 295 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 296 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 297 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 298 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 299 "data//maps/Route104/scripts.pory"

# 300 "data//maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 301 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 302 "data//maps/Route104/scripts.pory"
	checkplayergender
# 303 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 304 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 305 "data//maps/Route104/scripts.pory"
	return
# 306 "data//maps/Route104/scripts.pory"

# 307 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 308 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 309 "data//maps/Route104/scripts.pory"
	return
# 310 "data//maps/Route104/scripts.pory"

# 311 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 312 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 313 "data//maps/Route104/scripts.pory"
	return
# 314 "data//maps/Route104/scripts.pory"

# 315 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 316 "data//maps/Route104/scripts.pory"
	checkplayergender
# 317 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 318 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 319 "data//maps/Route104/scripts.pory"
	end
# 320 "data//maps/Route104/scripts.pory"

# 321 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 322 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 323 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 324 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 325 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 326 "data//maps/Route104/scripts.pory"
	closemessage
# 327 "data//maps/Route104/scripts.pory"
	delay 30
# 328 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 329 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 330 "data//maps/Route104/scripts.pory"
	waitfanfare
# 331 "data//maps/Route104/scripts.pory"
	closemessage
# 332 "data//maps/Route104/scripts.pory"
	delay 30
# 333 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 334 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 335 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 336 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 337 "data//maps/Route104/scripts.pory"
	closemessage
# 338 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 339 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 340 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 341 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 342 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 343 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 344 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 345 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 346 "data//maps/Route104/scripts.pory"
	releaseall
# 347 "data//maps/Route104/scripts.pory"
	end
# 348 "data//maps/Route104/scripts.pory"

# 349 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 350 "data//maps/Route104/scripts.pory"
	walk_slow_left
# 351 "data//maps/Route104/scripts.pory"
	step_end
# 352 "data//maps/Route104/scripts.pory"

# 353 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 354 "data//maps/Route104/scripts.pory"
	walk_down
# 355 "data//maps/Route104/scripts.pory"
	face_right
# 356 "data//maps/Route104/scripts.pory"
	step_end
# 357 "data//maps/Route104/scripts.pory"

# 358 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 359 "data//maps/Route104/scripts.pory"
	delay_4
# 360 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 361 "data//maps/Route104/scripts.pory"
	step_end
# 362 "data//maps/Route104/scripts.pory"

# 363 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 364 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 365 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 366 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 367 "data//maps/Route104/scripts.pory"
	releaseall
# 368 "data//maps/Route104/scripts.pory"
	end
# 369 "data//maps/Route104/scripts.pory"

# 370 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 371 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 372 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 373 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_StartMayBattle
# 374 "data//maps/Route104/scripts.pory"
	end
# 375 "data//maps/Route104/scripts.pory"

# 376 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 377 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 378 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 379 "data//maps/Route104/scripts.pory"
	releaseall
# 380 "data//maps/Route104/scripts.pory"
	end
# 381 "data//maps/Route104/scripts.pory"

# 382 "data//maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 383 "data//maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 384 "data//maps/Route104/scripts.pory"
	fadedefaultbgm
# 385 "data//maps/Route104/scripts.pory"
	return
# 386 "data//maps/Route104/scripts.pory"

# 387 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartMayBattle::
# 388 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, Route104_Text_MayDefeat
# 389 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 390 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 391 "data//maps/Route104/scripts.pory"
	end
# 392 "data//maps/Route104/scripts.pory"

# 393 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 394 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 395 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 396 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 397 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 398 "data//maps/Route104/scripts.pory"
	closemessage
# 399 "data//maps/Route104/scripts.pory"
	delay 30
# 400 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 401 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 402 "data//maps/Route104/scripts.pory"
	waitfanfare
# 403 "data//maps/Route104/scripts.pory"
	closemessage
# 404 "data//maps/Route104/scripts.pory"
	delay 30
# 405 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 406 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 407 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 408 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 409 "data//maps/Route104/scripts.pory"
	closemessage
# 410 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 411 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 412 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 413 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 414 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 415 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 416 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 417 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 418 "data//maps/Route104/scripts.pory"
	releaseall
# 419 "data//maps/Route104/scripts.pory"
	end
# 420 "data//maps/Route104/scripts.pory"

# 421 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 422 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 423 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 424 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 425 "data//maps/Route104/scripts.pory"
	releaseall
# 426 "data//maps/Route104/scripts.pory"
	end
# 427 "data//maps/Route104/scripts.pory"

# 428 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 429 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 430 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 431 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_StartBrendanBattle
# 432 "data//maps/Route104/scripts.pory"
	end
# 433 "data//maps/Route104/scripts.pory"

# 434 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 435 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 436 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 437 "data//maps/Route104/scripts.pory"
	releaseall
# 438 "data//maps/Route104/scripts.pory"
	end
# 439 "data//maps/Route104/scripts.pory"

# 440 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartBrendanBattle::
# 441 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, Route104_Text_BrendanDefeat
# 442 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 443 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 444 "data//maps/Route104/scripts.pory"
	end
# 445 "data//maps/Route104/scripts.pory"

# 446 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 447 "data//maps/Route104/scripts.pory"
	lock_facing_direction
# 448 "data//maps/Route104/scripts.pory"
	walk_down
# 449 "data//maps/Route104/scripts.pory"
	unlock_facing_direction
# 450 "data//maps/Route104/scripts.pory"
	step_end
# 451 "data//maps/Route104/scripts.pory"

# 452 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 453 "data//maps/Route104/scripts.pory"
	walk_down
# 454 "data//maps/Route104/scripts.pory"
	step_end
# 455 "data//maps/Route104/scripts.pory"

# 456 "data//maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 457 "data//maps/Route104/scripts.pory"
	lock
# 458 "data//maps/Route104/scripts.pory"
	faceplayer
# 459 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 460 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 461 "data//maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 462 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 463 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 464 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 465 "data//maps/Route104/scripts.pory"
	release
# 466 "data//maps/Route104/scripts.pory"
	end
# 467 "data//maps/Route104/scripts.pory"

# 468 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 469 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 470 "data//maps/Route104/scripts.pory"
	release
# 471 "data//maps/Route104/scripts.pory"
	end
# 472 "data//maps/Route104/scripts.pory"

# 473 "data//maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 474 "data//maps/Route104/scripts.pory"
	lock
# 475 "data//maps/Route104/scripts.pory"
	faceplayer
# 476 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 477 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 478 "data//maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 479 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 480 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 481 "data//maps/Route104/scripts.pory"
	release
# 482 "data//maps/Route104/scripts.pory"
	end
# 483 "data//maps/Route104/scripts.pory"

# 484 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 485 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 486 "data//maps/Route104/scripts.pory"
	release
# 487 "data//maps/Route104/scripts.pory"
	end
# 488 "data//maps/Route104/scripts.pory"

# 489 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 490 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 491 "data//maps/Route104/scripts.pory"
	end
# 492 "data//maps/Route104/scripts.pory"

# 493 "data//maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 494 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 495 "data//maps/Route104/scripts.pory"
	end
# 496 "data//maps/Route104/scripts.pory"

# 497 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 498 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 499 "data//maps/Route104/scripts.pory"
	end
# 500 "data//maps/Route104/scripts.pory"

# 501 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 502 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 503 "data//maps/Route104/scripts.pory"
	end
# 504 "data//maps/Route104/scripts.pory"

# 505 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 506 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 507 "data//maps/Route104/scripts.pory"
	end
# 508 "data//maps/Route104/scripts.pory"

# 509 "data//maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 510 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 511 "data//maps/Route104/scripts.pory"
	end
# 512 "data//maps/Route104/scripts.pory"

# 513 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 514 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 515 "data//maps/Route104/scripts.pory"
	end
# 516 "data//maps/Route104/scripts.pory"

# 517 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 518 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 519 "data//maps/Route104/scripts.pory"
	end
# 520 "data//maps/Route104/scripts.pory"

# 521 "data//maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 522 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 523 "data//maps/Route104/scripts.pory"
	end
# 524 "data//maps/Route104/scripts.pory"

# 525 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 526 "data//maps/Route104/scripts.pory"
	lock
# 527 "data//maps/Route104/scripts.pory"
	faceplayer
# 528 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 529 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 530 "data//maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED, 2
# 531 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 532 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 533 "data//maps/Route104/scripts.pory"
	release
# 534 "data//maps/Route104/scripts.pory"
	end
# 535 "data//maps/Route104/scripts.pory"

# 536 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 537 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 538 "data//maps/Route104/scripts.pory"
	release
# 539 "data//maps/Route104/scripts.pory"
	end
# 540 "data//maps/Route104/scripts.pory"

# 541 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 542 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 543 "data//maps/Route104/scripts.pory"
	end
# 544 "data//maps/Route104/scripts.pory"

# 545 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 546 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE104_BRINEY, MAP_ROUTE104, 0
# 547 "data//maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 548 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BRINEY, Route104_Movement_BrineyBoardBoat
# 549 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 550 "data//maps/Route104/scripts.pory"
	removeobject LOCALID_ROUTE104_BRINEY
# 551 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 552 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 553 "data//maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 554 "data//maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 555 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 556 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 557 "data//maps/Route104/scripts.pory"
	end
# 558 "data//maps/Route104/scripts.pory"

# 559 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 560 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewford
# 561 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 562 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 563 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 564 "data//maps/Route104/scripts.pory"

# 565 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 566 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewfordBeforeDadCalls
# 567 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 568 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 569 "data//maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 570 "data//maps/Route104/scripts.pory"
	waitmessage
# 571 "data//maps/Route104/scripts.pory"
	delay 30
# 572 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 573 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 574 "data//maps/Route104/scripts.pory"
	waitfanfare
# 575 "data//maps/Route104/scripts.pory"
	closemessage
# 576 "data//maps/Route104/scripts.pory"
	delay 30
# 577 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 578 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 579 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 580 "data//maps/Route104/scripts.pory"
	waitmovement LOCALID_ROUTE104_BOAT, MAP_ROUTE104
# 581 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 582 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 583 "data//maps/Route104/scripts.pory"

# 584 "data//maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 585 "data//maps/Route104/scripts.pory"
	delay 50
# 586 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 587 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 588 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 589 "data//maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 590 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 591 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 592 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 12, 8
# 593 "data//maps/Route104/scripts.pory"
	addobject LOCALID_DEWFORD_BRINEY
# 594 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
# 595 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 596 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_DEWFORD_BRINEY, Route104_Movement_BrineyExitBoat
# 597 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 598 "data//maps/Route104/scripts.pory"
	addobject LOCALID_DEWFORD_BOAT
# 599 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 600 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 601 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 602 "data//maps/Route104/scripts.pory"
	hideobjectat LOCALID_ROUTE104_BOAT, MAP_ROUTE104
# 603 "data//maps/Route104/scripts.pory"
	@ copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 604 "data//maps/Route104/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 2
# 605 "data//maps/Route104/scripts.pory"
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
# 606 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 607 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN
# 608 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_DEWFORD_BRINEY
# 609 "data//maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 610 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 611 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 612 "data//maps/Route104/scripts.pory"
	end
# 613 "data//maps/Route104/scripts.pory"

# 614 "data//maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 615 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 616 "data//maps/Route104/scripts.pory"
	releaseall
# 617 "data//maps/Route104/scripts.pory"
	end
# 618 "data//maps/Route104/scripts.pory"

# 619 "data//maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 620 "data//maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 621 "data//maps/Route104/scripts.pory"
	releaseall
# 622 "data//maps/Route104/scripts.pory"
	end
# 623 "data//maps/Route104/scripts.pory"

# 624 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 625 "data//maps/Route104/scripts.pory"
	walk_down
# 626 "data//maps/Route104/scripts.pory"
	walk_down
# 627 "data//maps/Route104/scripts.pory"
	walk_down
# 628 "data//maps/Route104/scripts.pory"
	walk_down
# 629 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 630 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 631 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 632 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 633 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 634 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 635 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 636 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 637 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 638 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 639 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 640 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 641 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 642 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 643 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 644 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 645 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 646 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 647 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 648 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 649 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 650 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 651 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 652 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 653 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 654 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 655 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 656 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 657 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 658 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 659 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 660 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 661 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 662 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 663 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 664 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 665 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 666 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 667 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 668 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 669 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 670 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 671 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 672 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 673 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 674 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 675 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 676 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 677 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 678 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 679 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 680 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 681 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 682 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 683 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 684 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 685 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 686 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 687 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 688 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 689 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 690 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 691 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 692 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 693 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 694 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 695 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 696 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 697 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 698 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 699 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 700 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 701 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data//maps/Route104/scripts.pory"
	step_end
# 723 "data//maps/Route104/scripts.pory"

# 724 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 725 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 726 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 727 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 728 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 729 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 730 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 731 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 732 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 733 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 734 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 735 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 736 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 737 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 738 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 739 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 740 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 741 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 742 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 743 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 744 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 745 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 746 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 747 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 748 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 749 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 750 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 751 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 752 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 753 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 754 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 755 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 756 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 757 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 758 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 759 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 760 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 761 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 762 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 763 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 764 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 765 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 766 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 767 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 768 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 769 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 770 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 771 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 772 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 773 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 774 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 775 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 776 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 777 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 778 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 779 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 780 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 781 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 782 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 783 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 784 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 785 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 786 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 787 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 788 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 789 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 790 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 791 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 792 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 793 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 794 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 795 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 796 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 797 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 798 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 799 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 800 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 801 "data//maps/Route104/scripts.pory"
	walk_right
# 802 "data//maps/Route104/scripts.pory"
	walk_right
# 803 "data//maps/Route104/scripts.pory"
	walk_down
# 804 "data//maps/Route104/scripts.pory"
	walk_down
# 805 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 806 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 807 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 808 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 809 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 810 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 811 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 812 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 813 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 814 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 815 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 816 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 817 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 818 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 819 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 820 "data//maps/Route104/scripts.pory"
	walk_down
# 821 "data//maps/Route104/scripts.pory"
	walk_down
# 822 "data//maps/Route104/scripts.pory"
	step_end
# 823 "data//maps/Route104/scripts.pory"

# 824 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 825 "data//maps/Route104/scripts.pory"
	walk_down
# 826 "data//maps/Route104/scripts.pory"
	walk_down
# 827 "data//maps/Route104/scripts.pory"
	walk_down
# 828 "data//maps/Route104/scripts.pory"
	walk_down
# 829 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 830 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 831 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 832 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 833 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 834 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 835 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 836 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 837 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 838 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 839 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 840 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 841 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 842 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 843 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 844 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 845 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 846 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 847 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 848 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 849 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 850 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 851 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 852 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 853 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 854 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 855 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 856 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 857 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 858 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 859 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 860 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 861 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 862 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 863 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 864 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 865 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 866 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 867 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 868 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 869 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 870 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 871 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 872 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 873 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 874 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 875 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 876 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 877 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 878 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 879 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 880 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 881 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 882 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 883 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 884 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 885 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 886 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 887 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 888 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 889 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 890 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 891 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 892 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 893 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 894 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 895 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 896 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 897 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 898 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 899 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 900 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 901 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 902 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 903 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 904 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 905 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 906 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 907 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 908 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 909 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 910 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 911 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 912 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 913 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 914 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 915 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 916 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 917 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 918 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 919 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 920 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 921 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 922 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 923 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 924 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 925 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 926 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 927 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 928 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 929 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 930 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 931 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 932 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 933 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 934 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 935 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 936 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 937 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 938 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 939 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 940 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 941 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 942 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 943 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 944 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 945 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 946 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 947 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 948 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 949 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 950 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 951 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 952 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 953 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 954 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 955 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 956 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 957 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 958 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 959 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 960 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 961 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 962 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 963 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 964 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 965 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 966 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 967 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 968 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 969 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 970 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 971 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 972 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 973 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 974 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 975 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 976 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 977 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 978 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 979 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 980 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 981 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 982 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 983 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 984 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 985 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 986 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 987 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 988 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 989 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 990 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 991 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 992 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 993 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 994 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 995 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 996 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 997 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 998 "data//maps/Route104/scripts.pory"
	walk_right
# 999 "data//maps/Route104/scripts.pory"
	walk_right
# 1000 "data//maps/Route104/scripts.pory"
	walk_down
# 1001 "data//maps/Route104/scripts.pory"
	walk_down
# 1002 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1003 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1004 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1005 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1006 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1007 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1008 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1009 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1010 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1011 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1012 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1013 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1014 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1015 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1016 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 1017 "data//maps/Route104/scripts.pory"
	walk_down
# 1018 "data//maps/Route104/scripts.pory"
	walk_down
# 1019 "data//maps/Route104/scripts.pory"
	step_end
# 1020 "data//maps/Route104/scripts.pory"

# 1021 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 1022 "data//maps/Route104/scripts.pory"
	walk_left
# 1023 "data//maps/Route104/scripts.pory"
	walk_down
# 1024 "data//maps/Route104/scripts.pory"
	walk_down
# 1025 "data//maps/Route104/scripts.pory"
	step_end
# 1026 "data//maps/Route104/scripts.pory"

# 1027 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 1028 "data//maps/Route104/scripts.pory"
	walk_down
# 1029 "data//maps/Route104/scripts.pory"
	step_end
# 1030 "data//maps/Route104/scripts.pory"

# 1031 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 1032 "data//maps/Route104/scripts.pory"
	walk_down
# 1033 "data//maps/Route104/scripts.pory"
	walk_left
# 1034 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 1035 "data//maps/Route104/scripts.pory"
	step_end
# 1036 "data//maps/Route104/scripts.pory"

# 1037 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 1038 "data//maps/Route104/scripts.pory"
	walk_down
# 1039 "data//maps/Route104/scripts.pory"
	walk_down
# 1040 "data//maps/Route104/scripts.pory"
	step_end
# 1041 "data//maps/Route104/scripts.pory"

# 1042 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 1043 "data//maps/Route104/scripts.pory"
	walk_down
# 1044 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 1045 "data//maps/Route104/scripts.pory"
	step_end
# 1046 "data//maps/Route104/scripts.pory"

# 1047 "data//maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 1048 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 1049 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 1050 "data//maps/Route104/scripts.pory"
	end
# 1051 "data//maps/Route104/scripts.pory"

# 1052 "data//maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 1053 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 1054 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 1055 "data//maps/Route104/scripts.pory"
	end
# 1056 "data//maps/Route104/scripts.pory"

# 1057 "data//maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 1058 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 1059 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1060 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 1061 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 1062 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1063 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 1064 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 1065 "data//maps/Route104/scripts.pory"
	release
# 1066 "data//maps/Route104/scripts.pory"
	end
# 1067 "data//maps/Route104/scripts.pory"

# 1068 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 1069 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1070 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 1071 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 1072 "data//maps/Route104/scripts.pory"
	release
# 1073 "data//maps/Route104/scripts.pory"
	end
# 1074 "data//maps/Route104/scripts.pory"

# 1075 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 1076 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 1077 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 1078 "data//maps/Route104/scripts.pory"
	release
# 1079 "data//maps/Route104/scripts.pory"
	end
# 1080 "data//maps/Route104/scripts.pory"

# 1081 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 1082 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 1083 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 1084 "data//maps/Route104/scripts.pory"
	release
# 1085 "data//maps/Route104/scripts.pory"
	end
# 1086 "data//maps/Route104/scripts.pory"

# 1087 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 1088 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 1089 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 1090 "data//maps/Route104/scripts.pory"
	release
# 1091 "data//maps/Route104/scripts.pory"
	end
# 1092 "data//maps/Route104/scripts.pory"

# 1093 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 1094 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 1095 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 1096 "data//maps/Route104/scripts.pory"
	end
# 1097 "data//maps/Route104/scripts.pory"

# 1098 "data//maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 1099 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 1100 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1101 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 1102 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 1103 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1104 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 1105 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 1106 "data//maps/Route104/scripts.pory"
	release
# 1107 "data//maps/Route104/scripts.pory"
	end
# 1108 "data//maps/Route104/scripts.pory"

# 1109 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 1110 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1111 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 1112 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 1113 "data//maps/Route104/scripts.pory"
	release
# 1114 "data//maps/Route104/scripts.pory"
	end
# 1115 "data//maps/Route104/scripts.pory"

# 1116 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 1117 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 1118 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1119 "data//maps/Route104/scripts.pory"
	release
# 1120 "data//maps/Route104/scripts.pory"
	end
# 1121 "data//maps/Route104/scripts.pory"

# 1122 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 1123 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 1124 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 1125 "data//maps/Route104/scripts.pory"
	release
# 1126 "data//maps/Route104/scripts.pory"
	end
# 1127 "data//maps/Route104/scripts.pory"

# 1128 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 1129 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 1130 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1131 "data//maps/Route104/scripts.pory"
	release
# 1132 "data//maps/Route104/scripts.pory"
	end
# 1133 "data//maps/Route104/scripts.pory"

# 1134 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 1135 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 1136 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 1137 "data//maps/Route104/scripts.pory"
	end
# 1138 "data//maps/Route104/scripts.pory"

# 1139 "data//maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 1140 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
# 1141 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1142 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 1143 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 1144 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1145 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 1146 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1147 "data//maps/Route104/scripts.pory"
	release
# 1148 "data//maps/Route104/scripts.pory"
	end
# 1149 "data//maps/Route104/scripts.pory"

# 1150 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 1151 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1152 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 1153 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 1154 "data//maps/Route104/scripts.pory"
	release
# 1155 "data//maps/Route104/scripts.pory"
	end
# 1156 "data//maps/Route104/scripts.pory"

# 1157 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 1158 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 1159 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1160 "data//maps/Route104/scripts.pory"
	release
# 1161 "data//maps/Route104/scripts.pory"
	end
# 1162 "data//maps/Route104/scripts.pory"

# 1163 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 1164 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 1165 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1166 "data//maps/Route104/scripts.pory"
	release
# 1167 "data//maps/Route104/scripts.pory"
	end
# 1168 "data//maps/Route104/scripts.pory"

# 1169 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 1170 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 1171 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1172 "data//maps/Route104/scripts.pory"
	release
# 1173 "data//maps/Route104/scripts.pory"
	end
# 1174 "data//maps/Route104/scripts.pory"

# 1175 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 1176 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 1177 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 1178 "data//maps/Route104/scripts.pory"
	end
# 1179 "data//maps/Route104/scripts.pory"

# 1180 "data//maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 1181 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 1182 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1183 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 1184 "data//maps/Route104/scripts.pory"
	release
# 1185 "data//maps/Route104/scripts.pory"
	end
# 1186 "data//maps/Route104/scripts.pory"

# 1187 "data//maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 1188 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 1189 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1190 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 1191 "data//maps/Route104/scripts.pory"
	release
# 1192 "data//maps/Route104/scripts.pory"
	end
# 1193 "data//maps/Route104/scripts.pory"

# 1194 "data//maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 1195 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 1196 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 1197 "data//maps/Route104/scripts.pory"
	end
# 1198 "data//maps/Route104/scripts.pory"

# 1199 "data//maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 1200 "data//maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 1201 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 1202 "data//maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 1203 "data//maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 1204 "data//maps/Route104/scripts.pory"

# 1205 "data//maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 1206 "data//maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 1207 "data//maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 1208 "data//maps/Route104/scripts.pory"
	.string "of the sea?$"
# 1209 "data//maps/Route104/scripts.pory"

# 1210 "data//maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 1211 "data//maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 1212 "data//maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 1213 "data//maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 1214 "data//maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 1215 "data//maps/Route104/scripts.pory"

# 1216 "data//maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 1217 "data//maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 1218 "data//maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 1219 "data//maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 1220 "data//maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 1221 "data//maps/Route104/scripts.pory"

# 1222 "data//maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 1223 "data//maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1224 "data//maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1225 "data//maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1226 "data//maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1227 "data//maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1228 "data//maps/Route104/scripts.pory"

# 1229 "data//maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1230 "data//maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1231 "data//maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1232 "data//maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1233 "data//maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1234 "data//maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1235 "data//maps/Route104/scripts.pory"

# 1236 "data//maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1237 "data//maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1238 "data//maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1239 "data//maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1240 "data//maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1241 "data//maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1242 "data//maps/Route104/scripts.pory"

# 1243 "data//maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1244 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1245 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1246 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1247 "data//maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1248 "data//maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1249 "data//maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1250 "data//maps/Route104/scripts.pory"

# 1251 "data//maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1252 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1253 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1254 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1255 "data//maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1256 "data//maps/Route104/scripts.pory"

# 1257 "data//maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1258 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1259 "data//maps/Route104/scripts.pory"

# 1260 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1261 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1262 "data//maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1263 "data//maps/Route104/scripts.pory"

# 1264 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1265 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1266 "data//maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1267 "data//maps/Route104/scripts.pory"

# 1268 "data//maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1269 "data//maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1270 "data//maps/Route104/scripts.pory"

# 1271 "data//maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1272 "data//maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1273 "data//maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1274 "data//maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1275 "data//maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1276 "data//maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1277 "data//maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1278 "data//maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1279 "data//maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1280 "data//maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1281 "data//maps/Route104/scripts.pory"

# 1282 "data//maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1283 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1284 "data//maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1285 "data//maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1286 "data//maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1287 "data//maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1288 "data//maps/Route104/scripts.pory"

# 1289 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1290 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1291 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1292 "data//maps/Route104/scripts.pory"

# 1293 "data//maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1294 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1295 "data//maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1296 "data//maps/Route104/scripts.pory"

# 1297 "data//maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1298 "data//maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1299 "data//maps/Route104/scripts.pory"
	.string "So…\l"
# 1300 "data//maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1301 "data//maps/Route104/scripts.pory"

# 1302 "data//maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1303 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1304 "data//maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1305 "data//maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1306 "data//maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1307 "data//maps/Route104/scripts.pory"

# 1308 "data//maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1309 "data//maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1310 "data//maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1311 "data//maps/Route104/scripts.pory"

# 1312 "data//maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1313 "data//maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1314 "data//maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1315 "data//maps/Route104/scripts.pory"

# 1316 "data//maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1317 "data//maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1318 "data//maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1319 "data//maps/Route104/scripts.pory"

# 1320 "data//maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1321 "data//maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1322 "data//maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1323 "data//maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1324 "data//maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1325 "data//maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1326 "data//maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1327 "data//maps/Route104/scripts.pory"

# 1328 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1329 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1330 "data//maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1331 "data//maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1332 "data//maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1333 "data//maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1334 "data//maps/Route104/scripts.pory"

# 1335 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1336 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1337 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1338 "data//maps/Route104/scripts.pory"

# 1339 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1340 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1341 "data//maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1342 "data//maps/Route104/scripts.pory"

# 1343 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1344 "data//maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1345 "data//maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1346 "data//maps/Route104/scripts.pory"
	.string "a battle?$"
# 1347 "data//maps/Route104/scripts.pory"

# 1348 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1349 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1350 "data//maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1351 "data//maps/Route104/scripts.pory"

# 1352 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1353 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1354 "data//maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1355 "data//maps/Route104/scripts.pory"

# 1356 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1357 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1358 "data//maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1359 "data//maps/Route104/scripts.pory"

# 1360 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1361 "data//maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1362 "data//maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1363 "data//maps/Route104/scripts.pory"

# 1364 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1365 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1366 "data//maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1367 "data//maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1368 "data//maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1369 "data//maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1370 "data//maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"
