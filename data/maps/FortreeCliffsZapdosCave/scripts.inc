# 1 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 2 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 3 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_MapScripts::
# 4 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffsZapdosCave_OnResume
# 5 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffsZapdosCave_OnTransition
# 6 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	.byte 0
# 7 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 8 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_OnResume:
# 9 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffsZapdosCave_EventScript_TryRemoveZapdos
# 10 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	@ setstepcallback STEP_CB_BOULDER_HOLE
# 11 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 12 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 13 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_OnTransition:
# 14 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, FortreeCliffsZapdosCave_EventScript_HideZapdos
# 15 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, FortreeCliffsZapdosCave_EventScript_TryShowZapdos
# 16 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
    end
# 17 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 18 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_HideZapdos::
# 19 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 20 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 21 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 22 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_TryShowZapdos::
# 23 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 24 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 25 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 26 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 27 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_Zapdos::
# 28 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	lock
# 29 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	faceplayer
# 30 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitse
# 31 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 32 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	delay 40
# 33 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitmoncry
# 34 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 35 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 36 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	special StartRegiBattle
# 37 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	waitstate
# 38 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsZapdosCave_EventScript_DefeatedZapdos
# 41 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsZapdosCave_EventScript_RanFromZapdos
# 42 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsZapdosCave_EventScript_RanFromZapdos
# 43 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 44 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 45 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 46 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 47 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_TryRemoveZapdos::
# 48 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 49 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 50 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 51 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	return
# 52 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 53 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_DefeatedZapdos::
# 54 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 55 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 56 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 57 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
# 58 "data//maps/FortreeCliffsZapdosCave/scripts.pory"

# 59 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
FortreeCliffsZapdosCave_EventScript_RanFromZapdos::
# 60 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 61 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 62 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	release
# 63 "data//maps/FortreeCliffsZapdosCave/scripts.pory"
	end
