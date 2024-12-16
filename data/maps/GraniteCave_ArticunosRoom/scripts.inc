.set LOCALID_ARTICUNO, 1

GraniteCave_ArticunosRoom_MapScripts::
	.byte 0

GraniteCave_ArticunosRoom_EventScript_Articuno::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_ArticunosRoom_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	waitmovement 0
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement LOCALID_ARTICUNO, GraniteCave_ArticunosRoom_Movement_ArticunoFlyOff
	waitmovement 0
	removeobject LOCALID_ARTICUNO
	msgbox GraniteCave_ArticunosRoom_Text_ArticunoFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_ArticunosRoom_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_UNUSED_0x8014, 1
	special InitRoamer
	releaseall
	end

GraniteCave_ArticunosRoom_Movement_ArticunoFlyOff:
	delay_16
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

GraniteCave_ArticunosRoom_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

GraniteCave_ArticunosRoom_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

GraniteCave_ArticunosRoom_Text_ArticunoFlewOff:
	.string "Articuno woke up and flew\n"
	.string "off somewhere . . .$"
