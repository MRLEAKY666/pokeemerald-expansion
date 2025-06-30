# 1 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 2 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 3 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_MapScripts::
# 4 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffsZapdosCave_OnResume
# 5 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffsZapdosCave_OnTransition
# 6 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeCliffsZapdosCave_OnFrame
# 7 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	.byte 0
# 8 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 9 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_OnFrame::
# 10 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    map_script_2 VAR_TEMP_CHECK_BOULDER_HOLE, 1, FortreeCliffsZapdosCave_EventScript_SinkBoulder
# 11 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	.2byte 0
# 12 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 13 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_SinkBoulder::
# 14 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    waitmovement VAR_BOULDER_TO_BE_HOLED
# 15 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    getobjectxy VAR_BOULDER_TO_BE_HOLED, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 16 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    setmetatile VAR_TEMP_E, VAR_TEMP_F, METATILE_Cave_BoulderHole_Filled, FALSE
# 17 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    delay 6
# 18 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    applymovement VAR_BOULDER_TO_BE_HOLED, FortreeCliffsZapdosCave_Movement_SinkBoulder
# 19 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 20 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8005, 0  @ horizontal pan
# 21 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8006, 3  @ num shakes
# 22 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 23 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	special ShakeCamera
# 24 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    playse SE_M_STRENGTH
# 25 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	special DrawWholeMapView
# 26 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    waitse
# 27 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    removeobject VAR_BOULDER_TO_BE_HOLED
# 28 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    setvar VAR_TEMP_CHECK_BOULDER_HOLE, 0
# 29 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    end
# 30 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 31 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_Movement_SinkBoulder::
# 32 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    set_invisible
# 33 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    jump_in_place_down
# 34 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    step_end
# 35 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 36 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_OnResume:
# 37 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffsZapdosCave_EventScript_TryRemoveZapdos
# 38 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	@ setstepcallback STEP_CB_BOULDER_HOLE
# 39 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 40 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 41 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_OnTransition:
# 42 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, FortreeCliffsZapdosCave_EventScript_HideZapdos
# 43 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, FortreeCliffsZapdosCave_EventScript_TryShowZapdos
# 44 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    end
# 45 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 46 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_HideZapdos::
# 47 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 48 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 49 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 50 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_TryShowZapdos::
# 51 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 52 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 53 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 54 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 55 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_Zapdos::
# 56 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	lock
# 57 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	faceplayer
# 58 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitse
# 59 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 60 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	delay 40
# 61 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitmoncry
# 62 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 63 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	special StartRegiBattle
# 65 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitstate
# 66 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 68 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsZapdosCave_EventScript_DefeatedZapdos
# 69 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsZapdosCave_EventScript_RanFromZapdos
# 70 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsZapdosCave_EventScript_RanFromZapdos
# 71 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 72 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 73 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 74 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 75 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_TryRemoveZapdos::
# 76 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 77 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 78 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 79 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 80 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 81 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_DefeatedZapdos::
# 82 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 83 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 84 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 85 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 86 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 87 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_RanFromZapdos::
# 88 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 89 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 90 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 91 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
