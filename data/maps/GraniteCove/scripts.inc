.set LOCALID_SNOVER, 5

GraniteCove_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, GraniteCove_OnTransition
	.byte 0

GraniteCove_OnTransition:
    special UpdateShoalTideFlag
    goto_if_set FLAG_SYS_SHOAL_TIDE, GraniteCove_EventScript_SetHighTide
    goto GraniteCove_EventScript_SetLowTide

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
	setwildbattle SPECIES_ABOMASNOW, 40
	dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCove_EventScript_DefeatedWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, GraniteCove_EventScript_DefeatedWildMon
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
    playse SE_FLEE
    waitse
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

GraniteCove_EventScript_Snover::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNOVER, CRY_MODE_ENCOUNTER
	msgbox GraniteCove_Text_Snover, MSGBOX_DEFAULT
	delay 10
	waitmoncry
	setwildbattle SPECIES_SNOVER, 25
	dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCove_EventScript_DefeatedWildMon
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, GraniteCove_EventScript_DefeatedWildMon
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
    playse SE_FLEE
    waitse
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

GraniteCove_EventScript_DefeatedWildMon::
    fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

GraniteCove_Text_CoveSign:
	.string "GRANITE COVE\n"
	.string "Beware of Tide.$"

GraniteCove_Text_Abomasnow:
    .string "TIIIIIIIIIDE!$"

GraniteCove_Text_Snover:
    .string "Wubbawub!$"
