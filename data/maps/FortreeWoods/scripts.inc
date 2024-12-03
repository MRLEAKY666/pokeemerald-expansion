# 1 "data//maps/FortreeWoods/scripts.pory"

# 2 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_MapScripts::
# 3 "data//maps/FortreeWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeWoods_OnResume
# 4 "data//maps/FortreeWoods/scripts.pory"
	.byte 0
# 5 "data//maps/FortreeWoods/scripts.pory"

# 6 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_OnResume:
# 7 "data//maps/FortreeWoods/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 8 "data//maps/FortreeWoods/scripts.pory"
	end
