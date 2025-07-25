# 1 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 2 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_MapScripts::
# 3 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
# 4 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.byte 0
# 5 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 6 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_OnFrame:
# 7 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
# 8 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.2byte 0
# 9 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 10 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
# 11 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	lockall
# 12 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
# 14 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
# 15 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 16 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	opendoor 2, 1
# 17 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 18 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
# 19 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
# 20 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 21 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	closedoor 2, 1
# 22 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitdooranim
# 23 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 24 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
# 25 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	waitstate
# 26 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	releaseall
# 27 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	end
# 28 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 29 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
# 30 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 31 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 32 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 33 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 34 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	step_end
# 35 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 36 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
# 37 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 38 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
# 39 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	walk_up
# 40 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	set_invisible
# 41 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	step_end
# 42 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 43 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Leftover text from when this was a Contest Hall in R/S
# 44 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 45 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
# 46 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "We do all right in the preliminary round,\n"
# 47 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "but we can never win the appeals…\p"
# 48 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "Maybe it means I have to watch what\n"
# 49 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "other contestants are doing…$"
# 50 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 51 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 52 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
# 53 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "See!\n"
# 54 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "My POKéMON won all these RIBBONS!\p"
# 55 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "Have your POKéMON earned any RIBBONS?\n"
# 56 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "You can check them on your POKéNAV.$"
# 57 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 58 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 59 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_CantWinEverywhere:
# 60 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I can't beat GYM LEADERS…\p"
# 61 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I can't win any CONTESTS…\p"
# 62 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "I've been here, there, and everywhere,\n"
# 63 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "and it's all for naught…$"
# 64 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"

# 65 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
@ Unused
# 66 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
FallarborTown_ContestHall_Text_SuperRankStage:
# 67 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "POKéMON CONTESTS\n"
# 68 "data//maps/FallarborTown_BattleTentCorridor/scripts.pory"
	.string "SUPER RANK STAGE!$"
