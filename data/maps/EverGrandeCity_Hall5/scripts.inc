# 1 "data//maps/EverGrandeCity_Hall5/scripts.pory"

# 2 "data//maps/EverGrandeCity_Hall5/scripts.pory"
EverGrandeCity_Hall5_MapScripts::
# 3 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_OnWarp
# 4 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_Hall5_OnTransition
# 5 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	.byte 0
# 6 "data//maps/EverGrandeCity_Hall5/scripts.pory"

# 7 "data//maps/EverGrandeCity_Hall5/scripts.pory"
EverGrandeCity_Hall5_OnWarp:
# 8 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_TurnPlayerNorth
# 9 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	.2byte 0
# 10 "data//maps/EverGrandeCity_Hall5/scripts.pory"

# 11 "data//maps/EverGrandeCity_Hall5/scripts.pory"
EverGrandeCity_Hall5_OnTransition:
# 12 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 13 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	end
# 14 "data//maps/EverGrandeCity_Hall5/scripts.pory"

# 15 "data//maps/EverGrandeCity_Hall5/scripts.pory"
EverGrandeCity_Hall5_EventScript_TurnPlayerNorth::
# 16 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 17 "data//maps/EverGrandeCity_Hall5/scripts.pory"
	end
