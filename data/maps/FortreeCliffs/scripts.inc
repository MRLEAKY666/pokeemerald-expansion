# 1 "data//maps/FortreeCliffs/scripts.pory"

# 2 "data//maps/FortreeCliffs/scripts.pory"

# 3 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_MapScripts::
# 4 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffs_OnResume
# 5 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffs_OnTransition
# 6 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 7 "data//maps/FortreeCliffs/scripts.pory"

# 8 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 9 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 10 "data//maps/FortreeCliffs/scripts.pory"
	end
# 11 "data//maps/FortreeCliffs/scripts.pory"

# 12 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 13 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data//maps/FortreeCliffs/scripts.pory"
	return
# 17 "data//maps/FortreeCliffs/scripts.pory"

# 18 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 19 "data//maps/FortreeCliffs/scripts.pory"
	@ call FortreeCliffs_EventScript_ResetWildMons
# 20 "data//maps/FortreeCliffs/scripts.pory"
	end
# 21 "data//maps/FortreeCliffs/scripts.pory"

# 22 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 23 "data//maps/FortreeCliffs/scripts.pory"
	end
# 24 "data//maps/FortreeCliffs/scripts.pory"

# 25 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 26 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 27 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 28 "data//maps/FortreeCliffs/scripts.pory"
	release
# 29 "data//maps/FortreeCliffs/scripts.pory"
	end
# 30 "data//maps/FortreeCliffs/scripts.pory"

# 31 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 32 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
