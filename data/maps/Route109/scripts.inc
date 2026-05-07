# 1 "data//maps/Route109/scripts.pory"

# 2 "data//maps/Route109/scripts.pory"
@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map.
# 3 "data//maps/Route109/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data//maps/Route109/scripts.pory"

# 5 "data//maps/Route109/scripts.pory"
Route109_MapScripts::
# 6 "data//maps/Route109/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route109_OnWarp
# 7 "data//maps/Route109/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route109_OnFrame
# 8 "data//maps/Route109/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_OnTransition
# 9 "data//maps/Route109/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route109_OnResume
# 10 "data//maps/Route109/scripts.pory"
	.byte 0

Route109_OnTransition::
# 17 "data//maps/Route109/scripts.pory"
	call_if_eq VAR_BRINEY_LOCATION, 4, Route109_EventScript_SetupPlayerClone
# 18 "data//maps/Route109/scripts.pory"
	setflag FLAG_TEMP_1E
# 19 "data//maps/Route109/scripts.pory"
	goto_if_set FLAG_SHOW_SHADY_TRUCK, Route109_OnTransition_2
	return

Route109_OnTransition_1:
# 20 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_SLATEPORT_SHADY_ALAKAZAM, Common_Movement_SetInvisible, MAP_ROUTE109
# 21 "data//maps/Route109/scripts.pory"
	waitmovement
# 24 "data//maps/Route109/scripts.pory"
	removeobject LOCALID_SLATEPORT_SHADY_ALAKAZAM, MAP_SLATEPORT_CITY
# 25 "data//maps/Route109/scripts.pory"
	clearflag FLAG_TEMP_1E
	return

Route109_OnTransition_2:
# 19 "data//maps/Route109/scripts.pory"
	compare VAR_SHADY_TRUCK_LOCATION, 1
	goto_if_eq Route109_OnTransition_1
	return


# 29 "data//maps/Route109/scripts.pory"

# 30 "data//maps/Route109/scripts.pory"

# 31 "data//maps/Route109/scripts.pory"
Route109_OnWarp:
# 32 "data//maps/Route109/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 4, Route109_EventScript_SetupBrineyReturnScene
# 33 "data//maps/Route109/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 5, Route109_EventScript_FinishBrineyReturnScene
# 34 "data//maps/Route109/scripts.pory"
	.2byte 0
# 35 "data//maps/Route109/scripts.pory"

# 36 "data//maps/Route109/scripts.pory"
Route109_OnFrame:
# 37 "data//maps/Route109/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, Route109_EventScript_MrBrineyArrivesA
# 38 "data//maps/Route109/scripts.pory"
	map_script_2 VAR_BRINEY_LOCATION, 4, Route109_EventScript_MrBrineyArrivesB
# 39 "data//maps/Route109/scripts.pory"
	.2byte 0
# 40 "data//maps/Route109/scripts.pory"

# 41 "data//maps/Route109/scripts.pory"
Route109_OnResume:
# 42 "data//maps/Route109/scripts.pory"
	call_if_set FLAG_TEMP_9, Route109_EventScript_SummonMrBriney
# 43 "data//maps/Route109/scripts.pory"
	end
# 44 "data//maps/Route109/scripts.pory"

# 45 "data//maps/Route109/scripts.pory"
Route109_EventScript_SummonMrBriney::
# 46 "data//maps/Route109/scripts.pory"
	setvar VAR_TEMP_0, 1
# 47 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 3
# 48 "data//maps/Route109/scripts.pory"
	call EventScript_ResetMrBriney
# 49 "data//maps/Route109/scripts.pory"
	clearflag FLAG_TEMP_9
# 50 "data//maps/Route109/scripts.pory"
	return
# 51 "data//maps/Route109/scripts.pory"

# 52 "data//maps/Route109/scripts.pory"
Route109_EventScript_SetupBrineyReturnScene::
# 53 "data//maps/Route109/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE109
# 54 "data//maps/Route109/scripts.pory"
	hideobjectat LOCALID_ROUTE109_BRINEY, MAP_ROUTE109
# 55 "data//maps/Route109/scripts.pory"
	setobjectxy LOCALID_ROUTE109_BOAT, 21, 31
# 56 "data//maps/Route109/scripts.pory"
	setobjectxyperm LOCALID_ROUTE109_BOAT, 21, 31
# 57 "data//maps/Route109/scripts.pory"
	return

Route109_EventScript_FinishBrineyReturnScene::
# 62 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 3
# 63 "data//maps/Route109/scripts.pory"
	switch VAR_0x8006
# 64 "data//maps/Route109/scripts.pory"
	case DIR_NORTH, Route109_EventScript_FinishBrineyReturnScene_3
# 66 "data//maps/Route109/scripts.pory"
	case DIR_SOUTH, Route109_EventScript_FinishBrineyReturnScene_4
# 68 "data//maps/Route109/scripts.pory"
	case DIR_EAST, Route109_EventScript_FinishBrineyReturnScene_5
# 70 "data//maps/Route109/scripts.pory"
	case DIR_WEST, Route109_EventScript_FinishBrineyReturnScene_6
Route109_EventScript_FinishBrineyReturnScene_1:
	return

Route109_EventScript_FinishBrineyReturnScene_3:
# 65 "data//maps/Route109/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto Route109_EventScript_FinishBrineyReturnScene_1

Route109_EventScript_FinishBrineyReturnScene_4:
# 67 "data//maps/Route109/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto Route109_EventScript_FinishBrineyReturnScene_1

Route109_EventScript_FinishBrineyReturnScene_5:
# 69 "data//maps/Route109/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto Route109_EventScript_FinishBrineyReturnScene_1

Route109_EventScript_FinishBrineyReturnScene_6:
# 71 "data//maps/Route109/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto Route109_EventScript_FinishBrineyReturnScene_1


# 76 "data//maps/Route109/scripts.pory"

# 77 "data//maps/Route109/scripts.pory"

# 78 "data//maps/Route109/scripts.pory"
Route109_EventScript_MrBrineyArrivesA::
# 79 "data//maps/Route109/scripts.pory"
	hidefollower
# 80 "data//maps/Route109/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 81 "data//maps/Route109/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_0x8006
# 82 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 4                                       @ arriving alone 
# 83 "data//maps/Route109/scripts.pory"
	delay 30
# 84 "data//maps/Route109/scripts.pory"
	warpsilent MAP_ROUTE109, 20, 24

Route109_EventScript_SetupPlayerClone::
# 88 "data//maps/Route109/scripts.pory"
	setobjectxyperm LOCALID_ROUTE109_DUMMY_GUY, VAR_0x8004, VAR_0x8005
# 89 "data//maps/Route109/scripts.pory"
	setobjectxy LOCALID_ROUTE109_DUMMY_GUY, VAR_0x8004, VAR_0x8005
# 90 "data//maps/Route109/scripts.pory"
	checkplayergender
# 91 "data//maps/Route109/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Route109_EventScript_SetupPlayerClone_2
# 95 "data//maps/Route109/scripts.pory"
	setvar VAR_OBJ_GFX_ID_9, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
Route109_EventScript_SetupPlayerClone_1:
# 97 "data//maps/Route109/scripts.pory"
	switch VAR_0x8006
# 98 "data//maps/Route109/scripts.pory"
	case DIR_NORTH, Route109_EventScript_SetupPlayerClone_7
# 100 "data//maps/Route109/scripts.pory"
	case DIR_SOUTH, Route109_EventScript_SetupPlayerClone_8
# 102 "data//maps/Route109/scripts.pory"
	case DIR_EAST, Route109_EventScript_SetupPlayerClone_9
# 104 "data//maps/Route109/scripts.pory"
	case DIR_WEST, Route109_EventScript_SetupPlayerClone_10
Route109_EventScript_SetupPlayerClone_5:
# 107 "data//maps/Route109/scripts.pory"
	addobject LOCALID_ROUTE109_DUMMY_GUY
	return

Route109_EventScript_SetupPlayerClone_2:
# 92 "data//maps/Route109/scripts.pory"
	setvar VAR_OBJ_GFX_ID_9, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto Route109_EventScript_SetupPlayerClone_1

Route109_EventScript_SetupPlayerClone_7:
# 99 "data//maps/Route109/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE109_DUMMY_GUY, MOVEMENT_TYPE_FACE_UP
	goto Route109_EventScript_SetupPlayerClone_5

Route109_EventScript_SetupPlayerClone_8:
# 101 "data//maps/Route109/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE109_DUMMY_GUY, MOVEMENT_TYPE_FACE_DOWN
	goto Route109_EventScript_SetupPlayerClone_5

Route109_EventScript_SetupPlayerClone_9:
# 103 "data//maps/Route109/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE109_DUMMY_GUY, MOVEMENT_TYPE_FACE_RIGHT
	goto Route109_EventScript_SetupPlayerClone_5

Route109_EventScript_SetupPlayerClone_10:
# 105 "data//maps/Route109/scripts.pory"
	setobjectmovementtype LOCALID_ROUTE109_DUMMY_GUY, MOVEMENT_TYPE_FACE_LEFT
	goto Route109_EventScript_SetupPlayerClone_5


Route109_EventScript_MrBrineyArrivesB::
# 112 "data//maps/Route109/scripts.pory"
	delay 30
# 113 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 3
# 114 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_BOAT, Route109_Movement_MrBrineyArrives
# 115 "data//maps/Route109/scripts.pory"
	waitmovement
# 116 "data//maps/Route109/scripts.pory"
	delay 15
# 117 "data//maps/Route109/scripts.pory"
	getobjectxy LOCALID_ROUTE109_DUMMY_GUY, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 118 "data//maps/Route109/scripts.pory"
	compare VAR_TEMP_E, 21
	goto_if_eq Route109_EventScript_MrBrineyArrivesB_3
Route109_EventScript_MrBrineyArrivesB_1:
# 124 "data//maps/Route109/scripts.pory"
	setobjectxyperm LOCALID_ROUTE109_BRINEY, 21, 25
# 125 "data//maps/Route109/scripts.pory"
	setobjectxy LOCALID_ROUTE109_BRINEY, 21, 25
# 126 "data//maps/Route109/scripts.pory"
	delay 15
# 127 "data//maps/Route109/scripts.pory"
	addobject LOCALID_ROUTE109_BRINEY
# 128 "data//maps/Route109/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109, 0
# 129 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_BRINEY, ROUTE109_Movement_MrBrineyDisembark
# 130 "data//maps/Route109/scripts.pory"
	waitmovement
# 131 "data//maps/Route109/scripts.pory"
	delay 60
# 132 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 5
# 133 "data//maps/Route109/scripts.pory"
	warpsilent MAP_ROUTE109, VAR_0x8004, VAR_0x8005
	end

Route109_EventScript_MrBrineyArrivesB_2:
# 119 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_DUMMY_GUY, ROUTE109_Movement_AvoidPlayerCollision
# 120 "data//maps/Route109/scripts.pory"
	waitmovement
# 121 "data//maps/Route109/scripts.pory"
	getobjectxy LOCALID_ROUTE109_DUMMY_GUY, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
# 122 "data//maps/Route109/scripts.pory"
	getobjectfacingdirection LOCALID_ROUTE109_DUMMY_GUY, VAR_0x8006
	goto Route109_EventScript_MrBrineyArrivesB_1

Route109_EventScript_MrBrineyArrivesB_3:
# 118 "data//maps/Route109/scripts.pory"
	compare VAR_TEMP_F, 24
	goto_if_eq Route109_EventScript_MrBrineyArrivesB_2
	goto Route109_EventScript_MrBrineyArrivesB_1


# 137 "data//maps/Route109/scripts.pory"
ROUTE109_Movement_AvoidPlayerCollision:
# 138 "data//maps/Route109/scripts.pory"
	walk_left
# 139 "data//maps/Route109/scripts.pory"
	walk_in_place_faster_right
# 140 "data//maps/Route109/scripts.pory"
	step_end

# 143 "data//maps/Route109/scripts.pory"

# 144 "data//maps/Route109/scripts.pory"

# 145 "data//maps/Route109/scripts.pory"
Route109_Movement_MrBrineyArrives:
# 146 "data//maps/Route109/scripts.pory"
	@ walk_fast_up
# 147 "data//maps/Route109/scripts.pory"
	walk_fast_up
# 148 "data//maps/Route109/scripts.pory"
	walk_fast_up
# 149 "data//maps/Route109/scripts.pory"
	walk_fast_up
# 150 "data//maps/Route109/scripts.pory"
	walk_fast_up
# 151 "data//maps/Route109/scripts.pory"
	walk_fast_up
# 152 "data//maps/Route109/scripts.pory"
	step_end
# 153 "data//maps/Route109/scripts.pory"

# 154 "data//maps/Route109/scripts.pory"
ROUTE109_Movement_MrBrineyDisembark:
# 155 "data//maps/Route109/scripts.pory"
	set_visible
# 156 "data//maps/Route109/scripts.pory"
	walk_up
# 157 "data//maps/Route109/scripts.pory"
	step_end
# 158 "data//maps/Route109/scripts.pory"

# 159 "data//maps/Route109/scripts.pory"
Route109_EventScript_StartDepartForDewford::
# 160 "data//maps/Route109/scripts.pory"
	checkfollowernpc
# 161 "data//maps/Route109/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, Route109_EventScript_HideFollowerNPC
# 162 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 163 "data//maps/Route109/scripts.pory"
	@ call EventScript_BackupMrBrineyLocation
# 164 "data//maps/Route109/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_ROUTE109, 0
# 165 "data//maps/Route109/scripts.pory"
	setobjectsubpriority LOCALID_PLAYER, MAP_ROUTE109, 0
# 166 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_BRINEY, Route109_Movement_BrineyEnterBoat
# 167 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 168 "data//maps/Route109/scripts.pory"
	removeobject LOCALID_ROUTE109_BRINEY
# 169 "data//maps/Route109/scripts.pory"
	switch VAR_FACING
# 170 "data//maps/Route109/scripts.pory"
	case DIR_SOUTH, Route109_EventScript_EnterBoatSouth
# 171 "data//maps/Route109/scripts.pory"
	case DIR_WEST, Route109_EventScript_EnterBoatWest
# 172 "data//maps/Route109/scripts.pory"
	case DIR_EAST, Route109_EventScript_EnterBoatEast
# 173 "data//maps/Route109/scripts.pory"
	end
# 174 "data//maps/Route109/scripts.pory"

# 175 "data//maps/Route109/scripts.pory"
Route109_EventScript_HideFollowerNPC::
# 176 "data//maps/Route109/scripts.pory"
	hidefollowernpc
# 177 "data//maps/Route109/scripts.pory"
	return
# 178 "data//maps/Route109/scripts.pory"

# 179 "data//maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatSouth::
# 180 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatSouth
# 181 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 182 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 183 "data//maps/Route109/scripts.pory"
	end
# 184 "data//maps/Route109/scripts.pory"

# 185 "data//maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatEast::
# 186 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatEast
# 187 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 188 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 189 "data//maps/Route109/scripts.pory"
	end
# 190 "data//maps/Route109/scripts.pory"

# 191 "data//maps/Route109/scripts.pory"
Route109_EventScript_EnterBoatWest::
# 192 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerEnterBoatWest
# 193 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 194 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_DoSailToDewford
# 195 "data//maps/Route109/scripts.pory"
	end
# 196 "data//maps/Route109/scripts.pory"

# 197 "data//maps/Route109/scripts.pory"
Route109_EventScript_DoSailToDewford::
# 198 "data//maps/Route109/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE109
# 199 "data//maps/Route109/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 200 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_BOAT, Route109_Movement_SailToDewford
# 201 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_PLAYER, Route109_Movement_SailToDewford
# 202 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 203 "data//maps/Route109/scripts.pory"
	delay 50
# 204 "data//maps/Route109/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 205 "data//maps/Route109/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
# 206 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_PLAYER, Route109_Movement_PlayerExitBoat
# 207 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 208 "data//maps/Route109/scripts.pory"
	addobject LOCALID_DEWFORD_BOAT
# 209 "data//maps/Route109/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 210 "data//maps/Route109/scripts.pory"
	setobjectxyperm LOCALID_ROUTE109_BRINEY, 12, 8
# 211 "data//maps/Route109/scripts.pory"
	addobject LOCALID_ROUTE109_BRINEY
# 212 "data//maps/Route109/scripts.pory"
	setobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_DEWFORD_TOWN, 0
# 213 "data//maps/Route109/scripts.pory"
	applymovement LOCALID_ROUTE109_BRINEY, Route109_Movement_BrineyExitBoat
# 214 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 215 "data//maps/Route109/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 216 "data//maps/Route109/scripts.pory"
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
# 217 "data//maps/Route109/scripts.pory"
	hideobjectat LOCALID_ROUTE109_BOAT, MAP_ROUTE109
# 218 "data//maps/Route109/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 219 "data//maps/Route109/scripts.pory"
	closemessage
# 220 "data//maps/Route109/scripts.pory"
	@ copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 221 "data//maps/Route109/scripts.pory"
	setvar VAR_BRINEY_LOCATION, 2
# 222 "data//maps/Route109/scripts.pory"
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
# 223 "data//maps/Route109/scripts.pory"
	resetobjectsubpriority LOCALID_PLAYER, MAP_ROUTE109
# 224 "data//maps/Route109/scripts.pory"
	resetobjectsubpriority LOCALID_ROUTE109_BRINEY, MAP_DEWFORD_TOWN
# 225 "data//maps/Route109/scripts.pory"
	copyobjectxytoperm LOCALID_ROUTE109_BRINEY
# 226 "data//maps/Route109/scripts.pory"
	release
# 227 "data//maps/Route109/scripts.pory"
	end
# 228 "data//maps/Route109/scripts.pory"

# 229 "data//maps/Route109/scripts.pory"
Route109_Movement_SailToDewford:
# 230 "data//maps/Route109/scripts.pory"
	walk_in_place_faster_down
# 231 "data//maps/Route109/scripts.pory"
	walk_down
# 232 "data//maps/Route109/scripts.pory"
	walk_down
# 233 "data//maps/Route109/scripts.pory"
	walk_fast_down
# 234 "data//maps/Route109/scripts.pory"
	walk_fast_down
# 235 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 236 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 237 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 238 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 239 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 240 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 241 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 242 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 243 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 244 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 245 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 246 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 247 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 248 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 249 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 250 "data//maps/Route109/scripts.pory"
	walk_faster_down
# 251 "data//maps/Route109/scripts.pory"
	walk_fast_down
# 252 "data//maps/Route109/scripts.pory"
	walk_fast_down
# 253 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 254 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 255 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 256 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 257 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 258 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 259 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 260 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 261 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 262 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 263 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 264 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 265 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 266 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 267 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 268 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 269 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 270 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 271 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 272 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 273 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 274 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 275 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 276 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 277 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 278 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 279 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 280 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 281 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 282 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 283 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 284 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 285 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 286 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 287 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 288 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 289 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 290 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 291 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 292 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 293 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 294 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 295 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 296 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 297 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 298 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 299 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 300 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 301 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 302 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 303 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 304 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 305 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 306 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 307 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 308 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 309 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 310 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 311 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 312 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 313 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 314 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 315 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 316 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 317 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 318 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 319 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 320 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 321 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 322 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 323 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 324 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 325 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 326 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 327 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 328 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 329 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 330 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 331 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 332 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 333 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 334 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 335 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 336 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 337 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 338 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 339 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 340 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 341 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 342 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 343 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 344 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 345 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 346 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 347 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 348 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 349 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 350 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 351 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 352 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 353 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 354 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 355 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 356 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 357 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 358 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 359 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 360 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 361 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 362 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 363 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 364 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 365 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 366 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 367 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 368 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 369 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 370 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 371 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 372 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 373 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 374 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 375 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 376 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 377 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 378 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 379 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 380 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 381 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 382 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 383 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 384 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 385 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 386 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 387 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 388 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 389 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 390 "data//maps/Route109/scripts.pory"
	walk_faster_left
# 391 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 392 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 393 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 394 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 395 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 396 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 397 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 398 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 399 "data//maps/Route109/scripts.pory"
	walk_fast_left
# 400 "data//maps/Route109/scripts.pory"
	walk_left
# 401 "data//maps/Route109/scripts.pory"
	walk_left
# 402 "data//maps/Route109/scripts.pory"
	walk_in_place_faster_down
# 403 "data//maps/Route109/scripts.pory"
	step_end
# 404 "data//maps/Route109/scripts.pory"

# 405 "data//maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatSouth:
# 406 "data//maps/Route109/scripts.pory"
	walk_down
# 407 "data//maps/Route109/scripts.pory"
	walk_down
# 408 "data//maps/Route109/scripts.pory"
	step_end
# 409 "data//maps/Route109/scripts.pory"

# 410 "data//maps/Route109/scripts.pory"
Route109_Movement_PlayerExitBoat:
# 411 "data//maps/Route109/scripts.pory"
	walk_down
# 412 "data//maps/Route109/scripts.pory"
	walk_down
# 413 "data//maps/Route109/scripts.pory"
	walk_left
# 414 "data//maps/Route109/scripts.pory"
	walk_in_place_faster_right
# 415 "data//maps/Route109/scripts.pory"
	step_end
# 416 "data//maps/Route109/scripts.pory"

# 417 "data//maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatEast:
# 418 "data//maps/Route109/scripts.pory"
	walk_right
# 419 "data//maps/Route109/scripts.pory"
	walk_down
# 420 "data//maps/Route109/scripts.pory"
	step_end
# 421 "data//maps/Route109/scripts.pory"

# 422 "data//maps/Route109/scripts.pory"
Route109_Movement_PlayerEnterBoatWest:
# 423 "data//maps/Route109/scripts.pory"
	walk_left
# 424 "data//maps/Route109/scripts.pory"
	walk_down
# 425 "data//maps/Route109/scripts.pory"
	step_end
# 426 "data//maps/Route109/scripts.pory"

# 427 "data//maps/Route109/scripts.pory"
Route109_Movement_BrineyEnterBoat:
# 428 "data//maps/Route109/scripts.pory"
	walk_down
# 429 "data//maps/Route109/scripts.pory"
	step_end
# 430 "data//maps/Route109/scripts.pory"

# 431 "data//maps/Route109/scripts.pory"
Route109_Movement_BrineyExitBoat:
# 432 "data//maps/Route109/scripts.pory"
	walk_down
# 433 "data//maps/Route109/scripts.pory"
	walk_in_place_faster_left
# 434 "data//maps/Route109/scripts.pory"
	step_end
# 435 "data//maps/Route109/scripts.pory"

# 436 "data//maps/Route109/scripts.pory"
Route109_EventScript_MrBriney::
# 437 "data//maps/Route109/scripts.pory"
	lock
# 438 "data//maps/Route109/scripts.pory"
	faceplayer
# 439 "data//maps/Route109/scripts.pory"
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_HaveNotDeliveredDevonGood
# 440 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_DeliveredDevonGoods
# 441 "data//maps/Route109/scripts.pory"
	end
# 442 "data//maps/Route109/scripts.pory"

# 443 "data//maps/Route109/scripts.pory"
Route109_EventScript_HaveNotDeliveredDevonGood::
# 444 "data//maps/Route109/scripts.pory"
	message Route109_Text_BrineySailToDewfordQuestion
# 445 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineySailToDewfordQuestion, MSGBOX_YESNO
# 446 "data//maps/Route109/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route109_EventScript_StayHere
# 447 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_SailToDewford
# 448 "data//maps/Route109/scripts.pory"
	end
# 449 "data//maps/Route109/scripts.pory"

# 450 "data//maps/Route109/scripts.pory"
Route109_EventScript_DeliveredDevonGoods::
# 451 "data//maps/Route109/scripts.pory"
	message Route109_Text_BrineyWhereAreWeBound
# 452 "data//maps/Route109/scripts.pory"
	waitmessage
# 453 "data//maps/Route109/scripts.pory"
	multichoicedefault 21, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
# 454 "data//maps/Route109/scripts.pory"
	switch VAR_RESULT
# 455 "data//maps/Route109/scripts.pory"
	case 0, Route109_EventScript_SailToDewford
# 456 "data//maps/Route109/scripts.pory"
	case 1, Route109_EventScript_ChoseNotToSail
# 457 "data//maps/Route109/scripts.pory"
	case MULTI_B_PRESSED, Route109_EventScript_ChoseNotToSail
# 458 "data//maps/Route109/scripts.pory"
	end
# 459 "data//maps/Route109/scripts.pory"

# 460 "data//maps/Route109/scripts.pory"
Route109_EventScript_SailToDewford::
# 461 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
# 462 "data//maps/Route109/scripts.pory"
	closemessage
# 463 "data//maps/Route109/scripts.pory"
	goto Route109_EventScript_StartDepartForDewford
# 464 "data//maps/Route109/scripts.pory"
	end
# 465 "data//maps/Route109/scripts.pory"

# 466 "data//maps/Route109/scripts.pory"
Route109_EventScript_StayHere::
# 467 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
# 468 "data//maps/Route109/scripts.pory"
	release
# 469 "data//maps/Route109/scripts.pory"
	end
# 470 "data//maps/Route109/scripts.pory"

# 471 "data//maps/Route109/scripts.pory"
Route109_EventScript_ChoseNotToSail::
# 472 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
# 473 "data//maps/Route109/scripts.pory"
	release
# 474 "data//maps/Route109/scripts.pory"
	end
# 475 "data//maps/Route109/scripts.pory"

# 476 "data//maps/Route109/scripts.pory"
Route109_EventScript_SeashoreHouseGirl::
# 477 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
# 478 "data//maps/Route109/scripts.pory"
	end
# 479 "data//maps/Route109/scripts.pory"

# 480 "data//maps/Route109/scripts.pory"
Route109_EventScript_SandCastleBoy::
# 481 "data//maps/Route109/scripts.pory"
	lock
# 482 "data//maps/Route109/scripts.pory"
	faceplayer
# 483 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
# 484 "data//maps/Route109/scripts.pory"
	closemessage
# 485 "data//maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 486 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 487 "data//maps/Route109/scripts.pory"
	release
# 488 "data//maps/Route109/scripts.pory"
	end
# 489 "data//maps/Route109/scripts.pory"

# 490 "data//maps/Route109/scripts.pory"
Route109_EventScript_SoftSandGirl::
# 491 "data//maps/Route109/scripts.pory"
	lock
# 492 "data//maps/Route109/scripts.pory"
	faceplayer
# 493 "data//maps/Route109/scripts.pory"
	special GetPlayerBigGuyGirlString
# 494 "data//maps/Route109/scripts.pory"
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
# 495 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 496 "data//maps/Route109/scripts.pory"
	giveitem ITEM_SOFT_SAND
# 497 "data//maps/Route109/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 498 "data//maps/Route109/scripts.pory"
	closemessage
# 499 "data//maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 500 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 501 "data//maps/Route109/scripts.pory"
	setflag FLAG_RECEIVED_SOFT_SAND
# 502 "data//maps/Route109/scripts.pory"
	release
# 503 "data//maps/Route109/scripts.pory"
	end
# 504 "data//maps/Route109/scripts.pory"

# 505 "data//maps/Route109/scripts.pory"
Route109_EventScript_AlreadyReceivedSoftSand::
# 506 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
# 507 "data//maps/Route109/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 508 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 509 "data//maps/Route109/scripts.pory"
	release
# 510 "data//maps/Route109/scripts.pory"
	end
# 511 "data//maps/Route109/scripts.pory"

# 512 "data//maps/Route109/scripts.pory"
Route109_EventScript_Woman::
# 513 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
# 514 "data//maps/Route109/scripts.pory"
	end
# 515 "data//maps/Route109/scripts.pory"

# 516 "data//maps/Route109/scripts.pory"
Route109_EventScript_OldMan::
# 517 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
# 518 "data//maps/Route109/scripts.pory"
	end
# 519 "data//maps/Route109/scripts.pory"

# 520 "data//maps/Route109/scripts.pory"
Route109_EventScript_Zigzagoon::
# 521 "data//maps/Route109/scripts.pory"
	lock
# 522 "data//maps/Route109/scripts.pory"
	faceplayer
# 523 "data//maps/Route109/scripts.pory"
	waitse
# 524 "data//maps/Route109/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 525 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
# 526 "data//maps/Route109/scripts.pory"
	waitmoncry
# 527 "data//maps/Route109/scripts.pory"
	release
# 528 "data//maps/Route109/scripts.pory"
	end
# 529 "data//maps/Route109/scripts.pory"

# 530 "data//maps/Route109/scripts.pory"
Route109_EventScript_SeashoreHouseSign::
# 531 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
# 532 "data//maps/Route109/scripts.pory"
	end
# 533 "data//maps/Route109/scripts.pory"

# 534 "data//maps/Route109/scripts.pory"
Route109_EventScript_TrainerTipsSign::
# 535 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
# 536 "data//maps/Route109/scripts.pory"
	end
# 537 "data//maps/Route109/scripts.pory"

# 538 "data//maps/Route109/scripts.pory"
Route109_EventScript_David::
# 539 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
# 540 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
# 541 "data//maps/Route109/scripts.pory"
	end
# 542 "data//maps/Route109/scripts.pory"

# 543 "data//maps/Route109/scripts.pory"
Route109_EventScript_Alice::
# 544 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
# 545 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
# 546 "data//maps/Route109/scripts.pory"
	end
# 547 "data//maps/Route109/scripts.pory"

# 548 "data//maps/Route109/scripts.pory"
Route109_EventScript_Huey::
# 549 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
# 550 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
# 551 "data//maps/Route109/scripts.pory"
	end
# 552 "data//maps/Route109/scripts.pory"

# 553 "data//maps/Route109/scripts.pory"
Route109_EventScript_Edmond::
# 554 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
# 555 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
# 556 "data//maps/Route109/scripts.pory"
	end
# 557 "data//maps/Route109/scripts.pory"

# 558 "data//maps/Route109/scripts.pory"
Route109_EventScript_Ricky::
# 559 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
# 560 "data//maps/Route109/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 561 "data//maps/Route109/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_RickyRematch
# 562 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
# 563 "data//maps/Route109/scripts.pory"
	release
# 564 "data//maps/Route109/scripts.pory"
	end
# 565 "data//maps/Route109/scripts.pory"

# 566 "data//maps/Route109/scripts.pory"
Route109_EventScript_RickyRegisterMatchCallAfterBattle::
# 567 "data//maps/Route109/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 568 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 569 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
# 570 "data//maps/Route109/scripts.pory"
	register_matchcall TRAINER_RICKY_1
# 571 "data//maps/Route109/scripts.pory"
	release
# 572 "data//maps/Route109/scripts.pory"
	end
# 573 "data//maps/Route109/scripts.pory"

# 574 "data//maps/Route109/scripts.pory"
Route109_EventScript_RickyRematch::
# 575 "data//maps/Route109/scripts.pory"
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
# 576 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
# 577 "data//maps/Route109/scripts.pory"
	end
# 578 "data//maps/Route109/scripts.pory"

# 579 "data//maps/Route109/scripts.pory"
Route109_EventScript_Lola::
# 580 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
# 581 "data//maps/Route109/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 582 "data//maps/Route109/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_LolaRematch
# 583 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
# 584 "data//maps/Route109/scripts.pory"
	release
# 585 "data//maps/Route109/scripts.pory"
	end
# 586 "data//maps/Route109/scripts.pory"

# 587 "data//maps/Route109/scripts.pory"
Route109_EventScript_LolaRegisterMatchCallAfterBattle::
# 588 "data//maps/Route109/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 589 "data//maps/Route109/scripts.pory"
	waitmovement 0
# 590 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
# 591 "data//maps/Route109/scripts.pory"
	register_matchcall TRAINER_LOLA_1
# 592 "data//maps/Route109/scripts.pory"
	release
# 593 "data//maps/Route109/scripts.pory"
	end
# 594 "data//maps/Route109/scripts.pory"

# 595 "data//maps/Route109/scripts.pory"
Route109_EventScript_LolaRematch::
# 596 "data//maps/Route109/scripts.pory"
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
# 597 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
# 598 "data//maps/Route109/scripts.pory"
	end
# 599 "data//maps/Route109/scripts.pory"

# 600 "data//maps/Route109/scripts.pory"
Route109_EventScript_Austina::
# 601 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
# 602 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
# 603 "data//maps/Route109/scripts.pory"
	end
# 604 "data//maps/Route109/scripts.pory"

# 605 "data//maps/Route109/scripts.pory"
Route109_EventScript_Gwen::
# 606 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
# 607 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
# 608 "data//maps/Route109/scripts.pory"
	end
# 609 "data//maps/Route109/scripts.pory"

# 610 "data//maps/Route109/scripts.pory"
Route109_EventScript_Carter::
# 611 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
# 612 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
# 613 "data//maps/Route109/scripts.pory"
	end
# 614 "data//maps/Route109/scripts.pory"

# 615 "data//maps/Route109/scripts.pory"
Route109_EventScript_Paul::
# 616 "data//maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
# 617 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
# 618 "data//maps/Route109/scripts.pory"
	end
# 619 "data//maps/Route109/scripts.pory"

# 620 "data//maps/Route109/scripts.pory"
Route109_EventScript_Mel::
# 621 "data//maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
# 622 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
# 623 "data//maps/Route109/scripts.pory"
	end
# 624 "data//maps/Route109/scripts.pory"

# 625 "data//maps/Route109/scripts.pory"
Route109_EventScript_Chandler::
# 626 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
# 627 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
# 628 "data//maps/Route109/scripts.pory"
	end
# 629 "data//maps/Route109/scripts.pory"

# 630 "data//maps/Route109/scripts.pory"
Route109_EventScript_Hailey::
# 631 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
# 632 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
# 633 "data//maps/Route109/scripts.pory"
	end
# 634 "data//maps/Route109/scripts.pory"

# 635 "data//maps/Route109/scripts.pory"
Route109_EventScript_Elijah::
# 636 "data//maps/Route109/scripts.pory"
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
# 637 "data//maps/Route109/scripts.pory"
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
# 638 "data//maps/Route109/scripts.pory"
	end
# 639 "data//maps/Route109/scripts.pory"

# 640 "data//maps/Route109/scripts.pory"
DewfordTown_Text_BrineyLandedInSlateportDeliverGoods:
# 641 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 642 "data//maps/Route109/scripts.pory"
	.string "We've made land in SLATEPORT!\p"
# 643 "data//maps/Route109/scripts.pory"
	.string "I suppose you're going to visit CAPT.\n"
# 644 "data//maps/Route109/scripts.pory"
	.string "STERN and deliver the DEVON GOODS?$"
# 645 "data//maps/Route109/scripts.pory"

# 646 "data//maps/Route109/scripts.pory"
Route109_Text_BrineySailToDewfordQuestion:
# 647 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: I thought you're supposed\n"
# 648 "data//maps/Route109/scripts.pory"
	.string "to deliver the DEVON GOODS.\p"
# 649 "data//maps/Route109/scripts.pory"
	.string "Would you like to sail back to\n"
# 650 "data//maps/Route109/scripts.pory"
	.string "DEWFORD, then?$"
# 651 "data//maps/Route109/scripts.pory"

# 652 "data//maps/Route109/scripts.pory"
Route109_Text_BrineyDewfordItIs:
# 653 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: DEWFORD it is, then!\p"
# 654 "data//maps/Route109/scripts.pory"
	.string "Anchors aweigh!\n"
# 655 "data//maps/Route109/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 656 "data//maps/Route109/scripts.pory"

# 657 "data//maps/Route109/scripts.pory"
Route109_Text_BrineyDeliverDevonGoods:
# 658 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: Then you go on and deliver\n"
# 659 "data//maps/Route109/scripts.pory"
	.string "the DEVON GOODS. I'll be waiting.$"
# 660 "data//maps/Route109/scripts.pory"

# 661 "data//maps/Route109/scripts.pory"
DewfordTown_Text_BrineyLandedInSlateport:
# 662 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: Ahoy! We've made land in\n"
# 663 "data//maps/Route109/scripts.pory"
	.string "SLATEPORT!\p"
# 664 "data//maps/Route109/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 665 "data//maps/Route109/scripts.pory"
	.string "you want to set sail again!$"
# 666 "data//maps/Route109/scripts.pory"

# 667 "data//maps/Route109/scripts.pory"
Route109_Text_BrineyWhereAreWeBound:
# 668 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 669 "data//maps/Route109/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 670 "data//maps/Route109/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 671 "data//maps/Route109/scripts.pory"

# 672 "data//maps/Route109/scripts.pory"
Route109_Text_BrineyTellMeWhenYouNeedToSail:
# 673 "data//maps/Route109/scripts.pory"
	.string "MR. BRINEY: You just tell me whenever\n"
# 674 "data//maps/Route109/scripts.pory"
	.string "you need to set sail again!$"
# 675 "data//maps/Route109/scripts.pory"

# 676 "data//maps/Route109/scripts.pory"
Route109_Text_ChillAtMyPapasSpot:
# 677 "data//maps/Route109/scripts.pory"
	.string "Yo, TRAINERS!\n"
# 678 "data//maps/Route109/scripts.pory"
	.string "Whether you're hot to trot,\l"
# 679 "data//maps/Route109/scripts.pory"
	.string "or cool cat not,\l"
# 680 "data//maps/Route109/scripts.pory"
	.string "chill at my papa's spot!$"
# 681 "data//maps/Route109/scripts.pory"

# 682 "data//maps/Route109/scripts.pory"
Route109_Text_LittleKidsDartAround:
# 683 "data//maps/Route109/scripts.pory"
	.string "Little kids can dart around so quickly…\p"
# 684 "data//maps/Route109/scripts.pory"
	.string "You don't dare take your eyes off them\n"
# 685 "data//maps/Route109/scripts.pory"
	.string "for an instant. It's very taxing.\p"
# 686 "data//maps/Route109/scripts.pory"
	.string "Mine are with my POKéMON, so they\n"
# 687 "data//maps/Route109/scripts.pory"
	.string "should be okay, but…$"
# 688 "data//maps/Route109/scripts.pory"

# 689 "data//maps/Route109/scripts.pory"
Route109_Text_SandCastleTakingLongTime:
# 690 "data//maps/Route109/scripts.pory"
	.string "Our sand castle's taking a long time\n"
# 691 "data//maps/Route109/scripts.pory"
	.string "to make.$"
# 692 "data//maps/Route109/scripts.pory"

# 693 "data//maps/Route109/scripts.pory"
Route109_Text_YouCanHaveThis:
# 694 "data//maps/Route109/scripts.pory"
	.string "You can have this!$"
# 695 "data//maps/Route109/scripts.pory"

# 696 "data//maps/Route109/scripts.pory"
Route109_Text_WereGoingToMakeBigCastle:
# 697 "data//maps/Route109/scripts.pory"
	.string "We're going to get all the sand from\n"
# 698 "data//maps/Route109/scripts.pory"
	.string "the beach and make a big castle!\p"
# 699 "data//maps/Route109/scripts.pory"
	.string "And then we're going to be a king and\n"
# 700 "data//maps/Route109/scripts.pory"
	.string "queen.\p"
# 701 "data//maps/Route109/scripts.pory"
	.string "We'll let you be a servant.$"
# 702 "data//maps/Route109/scripts.pory"

# 703 "data//maps/Route109/scripts.pory"
Route109_Text_ZigzagoonPicksUpLitter:
# 704 "data//maps/Route109/scripts.pory"
	.string "The water around these parts is clean.\p"
# 705 "data//maps/Route109/scripts.pory"
	.string "But, I get my ZIGZAGOON to pick up\n"
# 706 "data//maps/Route109/scripts.pory"
	.string "litter from the shoreline at times.\p"
# 707 "data//maps/Route109/scripts.pory"
	.string "Dirty water becomes rain and joins our\n"
# 708 "data//maps/Route109/scripts.pory"
	.string "rivers, which we drink from…\p"
# 709 "data//maps/Route109/scripts.pory"
	.string "If we pollute the sea, it all comes\n"
# 710 "data//maps/Route109/scripts.pory"
	.string "back to haunt us eventually.$"
# 711 "data//maps/Route109/scripts.pory"

# 712 "data//maps/Route109/scripts.pory"
Route109_Text_ZigzagoonCry:
# 713 "data//maps/Route109/scripts.pory"
	.string "ZIGZAGOON: Guguu?$"
# 714 "data//maps/Route109/scripts.pory"

# 715 "data//maps/Route109/scripts.pory"
Route109_Text_SeashoreHouseSign:
# 716 "data//maps/Route109/scripts.pory"
	.string "SEASHORE HOUSE\p"
# 717 "data//maps/Route109/scripts.pory"
	.string "“May hot battles rage on hot sands!\n"
# 718 "data//maps/Route109/scripts.pory"
	.string "The place for hot TRAINERS!”$"
# 719 "data//maps/Route109/scripts.pory"

# 720 "data//maps/Route109/scripts.pory"
Route109_Text_TrainerTipsSign:
# 721 "data//maps/Route109/scripts.pory"
	.string "TRAINER TIPS\p"
# 722 "data//maps/Route109/scripts.pory"
	.string "POKéMON at the same level may not\n"
# 723 "data//maps/Route109/scripts.pory"
	.string "always have identical stats.\p"
# 724 "data//maps/Route109/scripts.pory"
	.string "POKéMON raised by TRAINERS are said\n"
# 725 "data//maps/Route109/scripts.pory"
	.string "to grow stronger than wild POKéMON.$"
