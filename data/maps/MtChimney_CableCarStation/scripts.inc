# 1 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 2 "data//maps/MtChimney_CableCarStation/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 4 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_MapScripts::
# 5 "data//maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
# 6 "data//maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_OnFrame
# 7 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.byte 0
# 8 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 9 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnTransition:
# 10 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 11 "data//maps/MtChimney_CableCarStation/scripts.pory"
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_MoveAttendantAside
# 12 "data//maps/MtChimney_CableCarStation/scripts.pory"
	end
# 13 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 14 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_MoveAttendantAside::
# 15 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 5, 4
# 16 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
# 17 "data//maps/MtChimney_CableCarStation/scripts.pory"
	return
# 18 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 19 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnFrame:
# 20 "data//maps/MtChimney_CableCarStation/scripts.pory"
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_ExitCableCar
# 21 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.2byte 0
# 22 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 23 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_ExitCableCar::
# 24 "data//maps/MtChimney_CableCarStation/scripts.pory"
	lockall
# 25 "data//maps/MtChimney_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_ExitCableCar
# 26 "data//maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar
# 27 "data//maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 28 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 0
# 29 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
# 30 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
# 31 "data//maps/MtChimney_CableCarStation/scripts.pory"
	releaseall
# 32 "data//maps/MtChimney_CableCarStation/scripts.pory"
	end
# 33 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 34 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_Attendant::
# 35 "data//maps/MtChimney_CableCarStation/scripts.pory"
	lock
# 36 "data//maps/MtChimney_CableCarStation/scripts.pory"
	faceplayer
# 37 "data//maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
# 38 "data//maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MtChimney_CableCarStation_EventScript_RideCableCar
# 39 "data//maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_CableCarStation_EventScript_DeclineRide
# 40 "data//maps/MtChimney_CableCarStation/scripts.pory"
	end
# 41 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 42 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_RideCableCar::
# 43 "data//maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
# 44 "data//maps/MtChimney_CableCarStation/scripts.pory"
	closemessage
# 45 "data//maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_LeadPlayerToCableCar
# 46 "data//maps/MtChimney_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_BoardCableCar
# 47 "data//maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 48 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_0x8004, TRUE  @ Going down
# 49 "data//maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 2
# 50 "data//maps/MtChimney_CableCarStation/scripts.pory"
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
# 51 "data//maps/MtChimney_CableCarStation/scripts.pory"
	special CableCarWarp
# 52 "data//maps/MtChimney_CableCarStation/scripts.pory"
	special CableCar
# 53 "data//maps/MtChimney_CableCarStation/scripts.pory"
	waitstate
# 54 "data//maps/MtChimney_CableCarStation/scripts.pory"
	release
# 55 "data//maps/MtChimney_CableCarStation/scripts.pory"
	end
# 56 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 57 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_DeclineRide::
# 58 "data//maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
# 59 "data//maps/MtChimney_CableCarStation/scripts.pory"
	release
# 60 "data//maps/MtChimney_CableCarStation/scripts.pory"
	end
# 61 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 62 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_LeadPlayerToCableCar:
# 63 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 64 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 65 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_left
# 66 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_in_place_faster_right
# 67 "data//maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 68 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 69 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar:
# 70 "data//maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 71 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_right
# 72 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 73 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 74 "data//maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 75 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 76 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_BoardCableCar:
# 77 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 78 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 79 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 80 "data//maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 81 "data//maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 82 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 83 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_ExitCableCar:
# 84 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 85 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 86 "data//maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 87 "data//maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 88 "data//maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 89 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 90 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_CableCarReadyGetOn:
# 91 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.string "The CABLE CAR is ready to go down.\n"
# 92 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.string "Would you like to be on it?$"
# 93 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 94 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_StepThisWay:
# 95 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please step this way.$"
# 96 "data//maps/MtChimney_CableCarStation/scripts.pory"

# 97 "data//maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_RideAnotherTime:
# 98 "data//maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
