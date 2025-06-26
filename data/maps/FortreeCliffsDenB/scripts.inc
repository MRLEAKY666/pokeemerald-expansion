FortreeCliffsDenB_MapScripts::
# 2 "data//maps/FortreeCliffsDenB/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffsDenB_OnResume
# 3 "data//maps/FortreeCliffsDenB/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffsDenB_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FortreeCliffsDenB_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 4 "data//maps/FortreeCliffsDenB/scripts.pory"
	compare VAR_FORTREE_CLIFFS_DEN_B_MON, SPECIES_SNORLAX
	goto_if_eq FortreeCliffsDenB_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data//maps/FortreeCliffsDenB/scripts.pory"
	setvar VAR_TEMP_5, OBJ_EVENT_GFX_SPECIES ( MUNCHLAX )
# 10 "data//maps/FortreeCliffsDenB/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_5
	return

FortreeCliffsDenB_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data//maps/FortreeCliffsDenB/scripts.pory"
	setvar VAR_TEMP_5, OBJ_EVENT_GFX_SPECIES ( SNORLAX )
# 6 "data//maps/FortreeCliffsDenB/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_5
	return


# 16 "data//maps/FortreeCliffsDenB/scripts.pory"

# 17 "data//maps/FortreeCliffsDenB/scripts.pory"

# 18 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_OnResume:
# 19 "data//maps/FortreeCliffsDenB/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffsDenB_EventScript_TryRemoveWildMon
# 20 "data//maps/FortreeCliffsDenB/scripts.pory"
	end
# 21 "data//maps/FortreeCliffsDenB/scripts.pory"

# 22 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_EventScript_TryRemoveWildMon::
# 23 "data//maps/FortreeCliffsDenB/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data//maps/FortreeCliffsDenB/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 25 "data//maps/FortreeCliffsDenB/scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data//maps/FortreeCliffsDenB/scripts.pory"
	return
# 27 "data//maps/FortreeCliffsDenB/scripts.pory"

# 28 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_EventScript_Mon::
# 29 "data//maps/FortreeCliffsDenB/scripts.pory"
    lockall
# 30 "data//maps/FortreeCliffsDenB/scripts.pory"
	faceplayer
# 31 "data//maps/FortreeCliffsDenB/scripts.pory"
	waitse
# 32 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto_if_eq VAR_FORTREE_CLIFFS_DEN_B_MON, SPECIES_SNORLAX, FortreeCliffsDenB_EventScript_Snorlax
# 33 "data//maps/FortreeCliffsDenB/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 34 "data//maps/FortreeCliffsDenB/scripts.pory"
	waitmoncry
# 35 "data//maps/FortreeCliffsDenB/scripts.pory"
	delay 10
# 36 "data//maps/FortreeCliffsDenB/scripts.pory"
	createmon 1, 0, SPECIES_MUNCHLAX, 40
# 37 "data//maps/FortreeCliffsDenB/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 38 "data//maps/FortreeCliffsDenB/scripts.pory"
	dowildbattle
# 39 "data//maps/FortreeCliffsDenB/scripts.pory"
	@ waitstate
# 40 "data//maps/FortreeCliffsDenB/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data//maps/FortreeCliffsDenB/scripts.pory"
	setvar VAR_0x8004, SPECIES_MUNCHLAX
# 42 "data//maps/FortreeCliffsDenB/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 43 "data//maps/FortreeCliffsDenB/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsDenB_EventScript_DefeatedWildMon
# 44 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsDenB_EventScript_RanWildMon
# 45 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsDenB_EventScript_RanWildMon
# 46 "data//maps/FortreeCliffsDenB/scripts.pory"
	release
# 47 "data//maps/FortreeCliffsDenB/scripts.pory"
    end
# 48 "data//maps/FortreeCliffsDenB/scripts.pory"

# 49 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_EventScript_Snorlax::
# 50 "data//maps/FortreeCliffsDenB/scripts.pory"
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
# 51 "data//maps/FortreeCliffsDenB/scripts.pory"
	waitmoncry
# 52 "data//maps/FortreeCliffsDenB/scripts.pory"
	delay 10
# 53 "data//maps/FortreeCliffsDenB/scripts.pory"
    setwildbossmon 1
# 54 "data//maps/FortreeCliffsDenB/scripts.pory"
	createmon 1, 0, SPECIES_SNORLAX, 50
# 55 "data//maps/FortreeCliffsDenB/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 56 "data//maps/FortreeCliffsDenB/scripts.pory"
	dowildbattle
# 57 "data//maps/FortreeCliffsDenB/scripts.pory"
	@ waitstate
# 58 "data//maps/FortreeCliffsDenB/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 59 "data//maps/FortreeCliffsDenB/scripts.pory"
    endwildbossmon
# 60 "data//maps/FortreeCliffsDenB/scripts.pory"
	setvar VAR_0x8004, SPECIES_SNORLAX
# 61 "data//maps/FortreeCliffsDenB/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 62 "data//maps/FortreeCliffsDenB/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsDenB_EventScript_DefeatedWildMon
# 63 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsDenB_EventScript_RanWildMon
# 64 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsDenB_EventScript_RanWildMon
# 65 "data//maps/FortreeCliffsDenB/scripts.pory"
	release
# 66 "data//maps/FortreeCliffsDenB/scripts.pory"
	end
# 67 "data//maps/FortreeCliffsDenB/scripts.pory"

# 68 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_EventScript_DefeatedWildMon::
# 69 "data//maps/FortreeCliffsDenB/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 70 "data//maps/FortreeCliffsDenB/scripts.pory"
	release
# 71 "data//maps/FortreeCliffsDenB/scripts.pory"
	end
# 72 "data//maps/FortreeCliffsDenB/scripts.pory"

# 73 "data//maps/FortreeCliffsDenB/scripts.pory"
FortreeCliffsDenB_EventScript_RanWildMon::
# 74 "data//maps/FortreeCliffsDenB/scripts.pory"
	goto Common_EventScript_WildMonFled
# 75 "data//maps/FortreeCliffsDenB/scripts.pory"
	release
# 76 "data//maps/FortreeCliffsDenB/scripts.pory"
	end
