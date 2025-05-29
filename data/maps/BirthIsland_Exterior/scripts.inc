# 1 "data//maps/BirthIsland_Exterior/scripts.pory"

# 2 "data//maps/BirthIsland_Exterior/scripts.pory"
@ Note: LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK is a local id for this map used elsewhere. It's defined in event_objects.h
# 3 "data//maps/BirthIsland_Exterior/scripts.pory"

# 4 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_MapScripts::
# 5 "data//maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
# 6 "data//maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
# 7 "data//maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
# 8 "data//maps/BirthIsland_Exterior/scripts.pory"
	.byte 0
# 9 "data//maps/BirthIsland_Exterior/scripts.pory"

# 10 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnReturnToField:
# 11 "data//maps/BirthIsland_Exterior/scripts.pory"
	special SetDeoxysRockPalette
# 12 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 13 "data//maps/BirthIsland_Exterior/scripts.pory"

# 14 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnTransition:
# 15 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
# 16 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 17 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
# 18 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
# 19 "data//maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
# 20 "data//maps/BirthIsland_Exterior/scripts.pory"
	call_if_unset FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
# 21 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 22 "data//maps/BirthIsland_Exterior/scripts.pory"

# 23 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle::
# 24 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_DEOXYS
# 25 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
# 26 "data//maps/BirthIsland_Exterior/scripts.pory"
	return
# 27 "data//maps/BirthIsland_Exterior/scripts.pory"

# 28 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle::
# 29 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
# 30 "data//maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
# 31 "data//maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
# 32 "data//maps/BirthIsland_Exterior/scripts.pory"
	return
# 33 "data//maps/BirthIsland_Exterior/scripts.pory"

# 34 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnResume:
# 35 "data//maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
# 36 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 37 "data//maps/BirthIsland_Exterior/scripts.pory"

# 38 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryRemoveDeoxys::
# 39 "data//maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 41 "data//maps/BirthIsland_Exterior/scripts.pory"
	removeobject LOCALID_BIRTH_ISLAND_DEOXYS
# 42 "data//maps/BirthIsland_Exterior/scripts.pory"
	return
# 43 "data//maps/BirthIsland_Exterior/scripts.pory"

# 44 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Triangle::
# 45 "data//maps/BirthIsland_Exterior/scripts.pory"
	lock
# 46 "data//maps/BirthIsland_Exterior/scripts.pory"
	faceplayer
# 47 "data//maps/BirthIsland_Exterior/scripts.pory"
	special DoDeoxysRockInteraction
# 48 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 49 "data//maps/BirthIsland_Exterior/scripts.pory"
	switch VAR_RESULT
# 50 "data//maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_FAILED,     BirthIsland_Exterior_EventScript_Failed
# 51 "data//maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_PROGRESSED, BirthIsland_Exterior_EventScript_Progressed
# 52 "data//maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_SOLVED,     BirthIsland_Exterior_EventScript_Deoxys
# 53 "data//maps/BirthIsland_Exterior/scripts.pory"
	case DEOXYS_ROCK_COMPLETE,   BirthIsland_Exterior_EventScript_Complete
# 54 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 55 "data//maps/BirthIsland_Exterior/scripts.pory"

# 56 "data//maps/BirthIsland_Exterior/scripts.pory"
@ The actual rock triangle movement is handled by DoDeoxysRockInteraction.
# 57 "data//maps/BirthIsland_Exterior/scripts.pory"
@ Unless the player has solved the puzzle and needs to encounter Deoxys,
# 58 "data//maps/BirthIsland_Exterior/scripts.pory"
@ there's nothing else the script needs to do.
# 59 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Failed::
# 60 "data//maps/BirthIsland_Exterior/scripts.pory"
	release
# 61 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 62 "data//maps/BirthIsland_Exterior/scripts.pory"

# 63 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Progressed::
# 64 "data//maps/BirthIsland_Exterior/scripts.pory"
	release
# 65 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 66 "data//maps/BirthIsland_Exterior/scripts.pory"

# 67 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Complete::
# 68 "data//maps/BirthIsland_Exterior/scripts.pory"
	release
# 69 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 70 "data//maps/BirthIsland_Exterior/scripts.pory"

# 71 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Deoxys::
# 72 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 73 "data//maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
# 74 "data//maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 1, MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)
# 75 "data//maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 2, MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)
# 76 "data//maps/BirthIsland_Exterior/scripts.pory"
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 77 "data//maps/BirthIsland_Exterior/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
# 78 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 79 "data//maps/BirthIsland_Exterior/scripts.pory"
	addobject LOCALID_BIRTH_ISLAND_DEOXYS
# 80 "data//maps/BirthIsland_Exterior/scripts.pory"
	applymovement LOCALID_BIRTH_ISLAND_DEOXYS, BirthIsland_Exterior_Movement_DeoxysApproach
# 81 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitmovement 0
# 82 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 83 "data//maps/BirthIsland_Exterior/scripts.pory"
	playmoncry SPECIES_DEOXYS_NORMAL, CRY_MODE_ENCOUNTER
# 84 "data//maps/BirthIsland_Exterior/scripts.pory"
	delay 40
# 85 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitmoncry
# 86 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_BIRTH_ISLAND_DEOXYS
# 87 "data//maps/BirthIsland_Exterior/scripts.pory"
	seteventmon SPECIES_DEOXYS_NORMAL, 30
# 88 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 89 "data//maps/BirthIsland_Exterior/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 90 "data//maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 91 "data//maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 92 "data//maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 93 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BirthIsland_Exterior_EventScript_DefeatedDeoxys
# 94 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 95 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 96 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_BATTLED_DEOXYS
# 97 "data//maps/BirthIsland_Exterior/scripts.pory"
	release
# 98 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 99 "data//maps/BirthIsland_Exterior/scripts.pory"

# 100 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_DefeatedDeoxys::
# 101 "data//maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_DEFEATED_DEOXYS
# 102 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
# 103 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 104 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 105 "data//maps/BirthIsland_Exterior/scripts.pory"

# 106 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_RanFromDeoxys::
# 107 "data//maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
# 108 "data//maps/BirthIsland_Exterior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 109 "data//maps/BirthIsland_Exterior/scripts.pory"
	end
# 110 "data//maps/BirthIsland_Exterior/scripts.pory"

# 111 "data//maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_Movement_DeoxysApproach:
# 112 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 113 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 114 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 115 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 116 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 117 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 118 "data//maps/BirthIsland_Exterior/scripts.pory"
	walk_slow_down
# 119 "data//maps/BirthIsland_Exterior/scripts.pory"
	step_end
