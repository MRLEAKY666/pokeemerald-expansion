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
# 9 "data//maps/FortreeWoods/scripts.pory"

# 10 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_Zapdos::
# 11 "data//maps/FortreeWoods/scripts.pory"
	@ lock
# 12 "data//maps/FortreeWoods/scripts.pory"
	faceplayer
# 13 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 14 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 15 "data//maps/FortreeWoods/scripts.pory"
	delay 40
# 16 "data//maps/FortreeWoods/scripts.pory"
	waitmoncry
# 17 "data//maps/FortreeWoods/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 18 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 19 "data//maps/FortreeWoods/scripts.pory"
	special StartRegiBattle
# 20 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 21 "data//maps/FortreeWoods/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data//maps/FortreeWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeWoods_EventScript_DefeatedZapdos
# 24 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeWoods_EventScript_RanFromZapdos
# 25 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeWoods_EventScript_RanFromZapdos
# 26 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 27 "data//maps/FortreeWoods/scripts.pory"
	release
# 28 "data//maps/FortreeWoods/scripts.pory"
	end
# 29 "data//maps/FortreeWoods/scripts.pory"

# 30 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_DefeatedZapdos::
# 31 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 32 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 33 "data//maps/FortreeWoods/scripts.pory"
	end
# 34 "data//maps/FortreeWoods/scripts.pory"

# 35 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_RanFromZapdos::
# 36 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 37 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 38 "data//maps/FortreeWoods/scripts.pory"
	end
