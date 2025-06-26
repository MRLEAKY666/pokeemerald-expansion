FortreeCliffsDenA_MapScripts::
# 2 "data//maps/FortreeCliffsDenA/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffsDenA_OnResume
# 3 "data//maps/FortreeCliffsDenA/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffsDenA_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FortreeCliffsDenA_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 4 "data//maps/FortreeCliffsDenA/scripts.pory"
	compare VAR_FORTREE_CLIFFS_DEN_A_MON, SPECIES_SNORLAX
	goto_if_eq FortreeCliffsDenA_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data//maps/FortreeCliffsDenA/scripts.pory"
	setvar VAR_TEMP_5, OBJ_EVENT_GFX_SPECIES ( MUNCHLAX )
# 10 "data//maps/FortreeCliffsDenA/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_5
	return

FortreeCliffsDenA_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data//maps/FortreeCliffsDenA/scripts.pory"
	setvar VAR_TEMP_5, OBJ_EVENT_GFX_SPECIES ( SNORLAX )
# 6 "data//maps/FortreeCliffsDenA/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_5
	return


# 16 "data//maps/FortreeCliffsDenA/scripts.pory"

# 17 "data//maps/FortreeCliffsDenA/scripts.pory"

# 18 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_OnResume:
# 19 "data//maps/FortreeCliffsDenA/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffsDenA_EventScript_TryRemoveWildMon
# 20 "data//maps/FortreeCliffsDenA/scripts.pory"
	end
# 21 "data//maps/FortreeCliffsDenA/scripts.pory"

# 22 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_EventScript_TryRemoveWildMon::
# 23 "data//maps/FortreeCliffsDenA/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data//maps/FortreeCliffsDenA/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 25 "data//maps/FortreeCliffsDenA/scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data//maps/FortreeCliffsDenA/scripts.pory"
	return
# 27 "data//maps/FortreeCliffsDenA/scripts.pory"

# 28 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_EventScript_Mon::
# 29 "data//maps/FortreeCliffsDenA/scripts.pory"
    lock
# 30 "data//maps/FortreeCliffsDenA/scripts.pory"
	faceplayer
# 31 "data//maps/FortreeCliffsDenA/scripts.pory"
	waitse
# 32 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto_if_eq VAR_FORTREE_CLIFFS_DEN_A_MON, SPECIES_SNORLAX, FortreeCliffsDenA_EventScript_Snorlax
# 33 "data//maps/FortreeCliffsDenA/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_ENCOUNTER
# 34 "data//maps/FortreeCliffsDenA/scripts.pory"
	waitmoncry
# 35 "data//maps/FortreeCliffsDenA/scripts.pory"
	delay 10
# 36 "data//maps/FortreeCliffsDenA/scripts.pory"
	createmon 1, 0, SPECIES_MUNCHLAX, 40
# 37 "data//maps/FortreeCliffsDenA/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 38 "data//maps/FortreeCliffsDenA/scripts.pory"
	dowildbattle
# 39 "data//maps/FortreeCliffsDenA/scripts.pory"
	@ waitstate
# 40 "data//maps/FortreeCliffsDenA/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data//maps/FortreeCliffsDenA/scripts.pory"
	setvar VAR_0x8004, SPECIES_MUNCHLAX
# 42 "data//maps/FortreeCliffsDenA/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 43 "data//maps/FortreeCliffsDenA/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsDenA_EventScript_DefeatedWildMon
# 44 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsDenA_EventScript_RanWildMon
# 45 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsDenA_EventScript_RanWildMon
# 46 "data//maps/FortreeCliffsDenA/scripts.pory"
	release
# 47 "data//maps/FortreeCliffsDenA/scripts.pory"
    end
# 48 "data//maps/FortreeCliffsDenA/scripts.pory"

# 49 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_EventScript_Snorlax::
# 50 "data//maps/FortreeCliffsDenA/scripts.pory"
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
# 51 "data//maps/FortreeCliffsDenA/scripts.pory"
	waitmoncry
# 52 "data//maps/FortreeCliffsDenA/scripts.pory"
	delay 10
# 53 "data//maps/FortreeCliffsDenA/scripts.pory"
    setwildbossmon 1
# 54 "data//maps/FortreeCliffsDenA/scripts.pory"
	createmon 1, 0, SPECIES_SNORLAX, 50
# 55 "data//maps/FortreeCliffsDenA/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 56 "data//maps/FortreeCliffsDenA/scripts.pory"
	dowildbattle
# 57 "data//maps/FortreeCliffsDenA/scripts.pory"
	@ waitstate
# 58 "data//maps/FortreeCliffsDenA/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 59 "data//maps/FortreeCliffsDenA/scripts.pory"
    endwildbossmon
# 60 "data//maps/FortreeCliffsDenA/scripts.pory"
	setvar VAR_0x8004, SPECIES_SNORLAX
# 61 "data//maps/FortreeCliffsDenA/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 62 "data//maps/FortreeCliffsDenA/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeCliffsDenA_EventScript_DefeatedWildMon
# 63 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeCliffsDenA_EventScript_RanWildMon
# 64 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeCliffsDenA_EventScript_RanWildMon
# 65 "data//maps/FortreeCliffsDenA/scripts.pory"
	release
# 66 "data//maps/FortreeCliffsDenA/scripts.pory"
	end
# 67 "data//maps/FortreeCliffsDenA/scripts.pory"

# 68 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_EventScript_DefeatedWildMon::
# 69 "data//maps/FortreeCliffsDenA/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 70 "data//maps/FortreeCliffsDenA/scripts.pory"
	release
# 71 "data//maps/FortreeCliffsDenA/scripts.pory"
	end
# 72 "data//maps/FortreeCliffsDenA/scripts.pory"

# 73 "data//maps/FortreeCliffsDenA/scripts.pory"
FortreeCliffsDenA_EventScript_RanWildMon::
# 74 "data//maps/FortreeCliffsDenA/scripts.pory"
	goto Common_EventScript_WildMonFled
# 75 "data//maps/FortreeCliffsDenA/scripts.pory"
	release
# 76 "data//maps/FortreeCliffsDenA/scripts.pory"
	end
