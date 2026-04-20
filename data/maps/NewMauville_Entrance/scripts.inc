# 1 "data//maps/NewMauville_Entrance/scripts.pory"

# 2 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_MapScripts::
# 3 "data//maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
# 4 "data//maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
# 5 "data//maps/NewMauville_Entrance/scripts.pory"
	.byte 0
# 6 "data//maps/NewMauville_Entrance/scripts.pory"

# 7 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_OnLoad:
# 8 "data//maps/NewMauville_Entrance/scripts.pory"
	@ call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
# 9 "data//maps/NewMauville_Entrance/scripts.pory"
	end
# 10 "data//maps/NewMauville_Entrance/scripts.pory"

# 11 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_CloseDoor::
# 12 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
# 13 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
# 14 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
# 15 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
# 16 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
# 17 "data//maps/NewMauville_Entrance/scripts.pory"
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
# 18 "data//maps/NewMauville_Entrance/scripts.pory"
	return
# 19 "data//maps/NewMauville_Entrance/scripts.pory"

# 20 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_OnTransition:
# 21 "data//maps/NewMauville_Entrance/scripts.pory"
	setflag FLAG_LANDMARK_NEW_MAUVILLE
# 22 "data//maps/NewMauville_Entrance/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 1
# 23 "data//maps/NewMauville_Entrance/scripts.pory"
	end
# 24 "data//maps/NewMauville_Entrance/scripts.pory"

# 25 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_Door::
# 26 "data//maps/NewMauville_Entrance/scripts.pory"
	@ lockall
# 27 "data//maps/NewMauville_Entrance/scripts.pory"
	@ applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 28 "data//maps/NewMauville_Entrance/scripts.pory"
	@ waitmovement 0
# 29 "data//maps/NewMauville_Entrance/scripts.pory"
	@ msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
# 30 "data//maps/NewMauville_Entrance/scripts.pory"
	@ checkitem ITEM_BASEMENT_KEY
# 31 "data//maps/NewMauville_Entrance/scripts.pory"
	@ goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
# 32 "data//maps/NewMauville_Entrance/scripts.pory"
	@ msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
# 33 "data//maps/NewMauville_Entrance/scripts.pory"
	@ goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
# 34 "data//maps/NewMauville_Entrance/scripts.pory"
	@ msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
# 35 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
# 36 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
# 37 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
# 38 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
# 39 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
# 40 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
# 41 "data//maps/NewMauville_Entrance/scripts.pory"
	@ special DrawWholeMapView
# 42 "data//maps/NewMauville_Entrance/scripts.pory"
	@ playse SE_BANG
# 43 "data//maps/NewMauville_Entrance/scripts.pory"
	@ setvar VAR_NEW_MAUVILLE_STATE, 1
# 44 "data//maps/NewMauville_Entrance/scripts.pory"
	@ releaseall
# 45 "data//maps/NewMauville_Entrance/scripts.pory"
	end
# 46 "data//maps/NewMauville_Entrance/scripts.pory"

# 47 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_DontOpenDoor::
# 48 "data//maps/NewMauville_Entrance/scripts.pory"
	releaseall
# 49 "data//maps/NewMauville_Entrance/scripts.pory"
	end
# 50 "data//maps/NewMauville_Entrance/scripts.pory"

# 51 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_EventScript_Mick::
# 52 "data//maps/NewMauville_Entrance/scripts.pory"
	trainerbattle_single TRAINER_MICK, NewMauville_Entrance_Text_MickIntro, NewMauville_Entrance_Text_MickDefeat
# 53 "data//maps/NewMauville_Entrance/scripts.pory"
	msgbox NewMauville_Entrance_Text_MickPostBattle, MSGBOX_AUTOCLOSE
# 54 "data//maps/NewMauville_Entrance/scripts.pory"
	end
# 55 "data//maps/NewMauville_Entrance/scripts.pory"

# 56 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_MickIntro:
# 57 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "I have a strong hunch this\n"
# 58 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "generator's built on an important\l"
# 59 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "archeological site!\p"
# 60 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "But I need to find it first!$"
# 61 "data//maps/NewMauville_Entrance/scripts.pory"

# 62 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_MickDefeat:
# 63 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "You're right…\p"
# 64 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "There's all kinds of dangerous\n"
# 65 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "POKéMON through there…\p"
# 66 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "I'm not cut out for it.$"
# 67 "data//maps/NewMauville_Entrance/scripts.pory"

# 68 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_MickPostBattle:
# 69 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "HOENN makes most of its power\n"
# 70 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "right here in NEW MAUVILLE…\p"
# 71 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "But according to my research,\n"
# 72 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "NEW MAUVILLE might actually be\l"
# 73 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "built atop an ancient burial site…\p"
# 74 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "I wonder what that has to do with\n"
# 75 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "generating electricity?$"
# 76 "data//maps/NewMauville_Entrance/scripts.pory"

# 77 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_DoorIsLocked:
# 78 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "The door is locked.$"
# 79 "data//maps/NewMauville_Entrance/scripts.pory"

# 80 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_UseBasementKey:
# 81 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "Use the BASEMENT KEY?$"
# 82 "data//maps/NewMauville_Entrance/scripts.pory"

# 83 "data//maps/NewMauville_Entrance/scripts.pory"
NewMauville_Entrance_Text_UsedBasementKey:
# 84 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "{PLAYER} used the BASEMENT KEY.\p"
# 85 "data//maps/NewMauville_Entrance/scripts.pory"
	.string "The door opened!$"
