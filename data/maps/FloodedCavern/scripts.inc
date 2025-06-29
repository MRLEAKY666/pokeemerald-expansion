# 1 "data//maps/FloodedCavern/scripts.pory"

# 2 "data//maps/FloodedCavern/scripts.pory"

# 3 "data//maps/FloodedCavern/scripts.pory"
FloodedCavern_MapScripts::
# 4 "data//maps/FloodedCavern/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, FloodedCavern_OnTransition
# 5 "data//maps/FloodedCavern/scripts.pory"
    .byte 0
# 6 "data//maps/FloodedCavern/scripts.pory"

# 7 "data//maps/FloodedCavern/scripts.pory"
FloodedCavern_OnTransition::
# 8 "data//maps/FloodedCavern/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 9 "data//maps/FloodedCavern/scripts.pory"
	call_if_ge VAR_TEMP_F, 14, FloodedCavern_EventScript_SetFog
# 10 "data//maps/FloodedCavern/scripts.pory"
	return
# 11 "data//maps/FloodedCavern/scripts.pory"

# 12 "data//maps/FloodedCavern/scripts.pory"
FloodedCavern_EventScript_SetFog::
# 13 "data//maps/FloodedCavern/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 14 "data//maps/FloodedCavern/scripts.pory"
	doweather
# 15 "data//maps/FloodedCavern/scripts.pory"
	return
