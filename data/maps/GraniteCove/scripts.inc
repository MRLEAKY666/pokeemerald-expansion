.set LOCALID_SNOVER, 5
.set LOCALID_BRAWLY, 6

GraniteCove_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, GraniteCove_OnTransition
    map_script MAP_SCRIPT_ON_LOAD, GraniteCove_OnLoad
    map_script MAP_SCRIPT_ON_RESUME, GraniteCove_OnResume
	.byte 0

GraniteCove_OnTransition:
    special UpdateShoalTideFlag
    goto_if_set FLAG_SYS_SHOAL_TIDE, GraniteCove_EventScript_SetHighTide
    goto GraniteCove_EventScript_SetLowTide
	end

GraniteCove_OnLoad:
	call_if_eq VAR_BRAWLY_LOCATION, 1, GraniteCove_EventScript_HideBrawly
	end

GraniteCove_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCove_EventScript_TryRemoveWildMon
	end

GraniteCove_EventScript_TryRemoveWildMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

GraniteCove_EventScript_HideBrawly::
	setflag FLAG_HIDE_GRANITE_COVE_BRAWLY
	end

GraniteCove_EventScript_SetHighTide::
    setobjectxyperm LOCALID_SNOVER, 0, 31
    setobjectmovementtype LOCALID_SNOVER, MOVEMENT_TYPE_INVISIBLE
    setmaplayoutindex LAYOUT_GRANITE_COVE
    end

GraniteCove_EventScript_SetLowTide::
    setmaplayoutindex LAYOUT_GRANITE_CAVE_LOW_TIDE
    end

GraniteCove_EventScript_CoveSign::
    msgbox GraniteCove_Text_CoveSign, MSGBOX_SIGN
    end

GraniteCove_EventScript_Abomasnow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABOMASNOW, CRY_MODE_ENCOUNTER
	msgbox GraniteCove_Text_Abomasnow, MSGBOX_DEFAULT
	delay 10
	waitmoncry
	closemessage
	setwildbossmon 1
	setwildbattle SPECIES_ABOMASNOW, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	endwildbossmon
	setvar VAR_0x8004, SPECIES_ABOMASNOW
    specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCove_EventScript_DefeatedWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCove_EventScript_RanWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCove_EventScript_RanWildMon
	release
	end

GraniteCove_EventScript_Snover::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNOVER, CRY_MODE_ENCOUNTER
	delay 10
	waitmoncry
	setwildbattle SPECIES_SNOVER, 25
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@ waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, SPECIES_SNOVER
    specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCove_EventScript_DefeatedWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCove_EventScript_RanWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCove_EventScript_RanWildMon
	release
	end

GraniteCove_EventScript_Brawly::
	lock
	faceplayer
	msgbox GraniteCove_Text_Brawly, MSGBOX_DEFAULT
	giveitem ITEM_EXPERT_BELT, 1
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox GraniteCove_Text_Brawly_SeeYouLater, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BRAWLY_LOCATION, 1
	switch VAR_FACING
	case DIR_SOUTH, GraniteCove_EventScript_BrawlyExitSouth
	case DIR_WEST, GraniteCove_EventScript_BrawlyExitNormal
	case DIR_NORTH, GraniteCove_EventScript_BrawlyExitNormal
	case DIR_EAST, GraniteCove_EventScript_BrawlyExitNormal
	release
	end

GraniteCove_EventScript_BrawlyExitSouth::
	applymovement LOCALID_BRAWLY, GraniteCove_Movement_BrawlyExitSouth
	waitmovement 0
	removeobject LOCALID_BRAWLY
	return

GraniteCove_EventScript_BrawlyExitNormal::
	applymovement LOCALID_BRAWLY, GraniteCove_Movement_BrawlyExitNormal
	waitmovement 0
	removeobject LOCALID_BRAWLY
	return

GraniteCove_Movement_BrawlyExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCove_Movement_BrawlyExitNormal:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCove_EventScript_DefeatedWildMon::
    goto Common_EventScript_RemoveStaticPokemon
	release
	end

GraniteCove_EventScript_RanWildMon::
	goto Common_EventScript_WildMonFled
	release
	end

GraniteCove_Text_CoveSign:
	.string "GRANITE COVE\n"
	.string "Beware of Tide.$"

GraniteCove_Text_Abomasnow:
    .string "TIIIIIIIIIDE!$"

GraniteCove_Text_Brawly:
	.string "BRAWLY: Oh? You came all the way\n" 
	.string "out here just to challenge me?\p"
	.string "You must want the KNUCKLE BADGE\n"
	.string "pretty bad, huh?\p"
	.string "Fine, meet me back at the GYM…\p"
	.string "And you can have this for going so far\n"
	.string "out of your way to find me.$"

GraniteCove_Text_Brawly_SeeYouLater:
	.string "See ya later…$"
	
