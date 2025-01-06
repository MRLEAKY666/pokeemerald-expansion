GraniteCove_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, GraniteCove_OnTransition
	.byte 0

GraniteCove_OnTransition:
    special UpdateShoalTideFlag
    goto_if_set FLAG_SYS_SHOAL_TIDE, GraniteCove_EventScript_SetHighTide
    goto GraniteCove_EventScript_SetLowTide

GraniteCove_EventScript_SetHighTide::
    setmaplayoutindex LAYOUT_GRANITE_COVE
    end

GraniteCove_EventScript_SetLowTide::
    setmaplayoutindex LAYOUT_GRANITE_CAVE_LOW_TIDE
    end

GraniteCove_EventScript_CoveSign::
    msgbox GraniteCove_Text_CoveSign, MSGBOX_SIGN
    end

GraniteCove_Text_CoveSign:
	.string "GRANITE COVE\n"
	.string "Beware of tide.$"
