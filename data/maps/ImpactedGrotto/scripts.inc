# 1 "data//maps/ImpactedGrotto/scripts.pory"

# 2 "data//maps/ImpactedGrotto/scripts.pory"

# 3 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_MapScripts::
# 4 "data//maps/ImpactedGrotto/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, ImpactedGrotto_OnResume
# 5 "data//maps/ImpactedGrotto/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ImpactedGrotto_OnLoad
# 6 "data//maps/ImpactedGrotto/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ImpactedGrotto_OnTransition
# 7 "data//maps/ImpactedGrotto/scripts.pory"
	.byte 0
# 8 "data//maps/ImpactedGrotto/scripts.pory"

# 9 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_OnResume:
# 10 "data//maps/ImpactedGrotto/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ImpactedGrotto_EventScript_TryRemoveRegidrago
# 11 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 12 "data//maps/ImpactedGrotto/scripts.pory"

# 13 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_TryRemoveRegidrago::
# 14 "data//maps/ImpactedGrotto/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data//maps/ImpactedGrotto/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data//maps/ImpactedGrotto/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data//maps/ImpactedGrotto/scripts.pory"
	return
# 18 "data//maps/ImpactedGrotto/scripts.pory"

# 19 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_OnLoad:
# 20 "data//maps/ImpactedGrotto/scripts.pory"
	@ call_if_unset FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, ImpactedGrotto_EventScript_HideRegiEntrance
# 21 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 22 "data//maps/ImpactedGrotto/scripts.pory"

# 23 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_HideRegiEntrance::
# 24 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 25 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 26 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 27 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 29 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 30 "data//maps/ImpactedGrotto/scripts.pory"
	return
# 31 "data//maps/ImpactedGrotto/scripts.pory"

# 32 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_OnTransition:
# 33 "data//maps/ImpactedGrotto/scripts.pory"
	setflag FLAG_LANDMARK_IMPACTED_GROTTO
# 34 "data//maps/ImpactedGrotto/scripts.pory"
	call ImpactedGrotto_EventScript_ClearSteps
# 35 "data//maps/ImpactedGrotto/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIDRAGO, ImpactedGrotto_EventScript_ShowRegidrago
# 36 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 37 "data//maps/ImpactedGrotto/scripts.pory"

# 38 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_ShowRegidrago::
# 39 "data//maps/ImpactedGrotto/scripts.pory"
	clearflag FLAG_HIDE_REGIDRAGO
# 40 "data//maps/ImpactedGrotto/scripts.pory"
	return
# 41 "data//maps/ImpactedGrotto/scripts.pory"

# 42 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_OpenRegiEntrance::
# 43 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
# 44 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 45 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
# 46 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
# 47 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
# 48 "data//maps/ImpactedGrotto/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
# 49 "data//maps/ImpactedGrotto/scripts.pory"
	special DrawWholeMapView
# 50 "data//maps/ImpactedGrotto/scripts.pory"
	playse SE_BANG
# 51 "data//maps/ImpactedGrotto/scripts.pory"
	@ setflag FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED
# 52 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 53 "data//maps/ImpactedGrotto/scripts.pory"

# 54 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_CaveEntranceMiddle::
# 55 "data//maps/ImpactedGrotto/scripts.pory"
	lockall
# 56 "data//maps/ImpactedGrotto/scripts.pory"
	@ call_if_set FLAG_TEMP_REGIDRAGO_PUZZLE_FAILED, ImpactedGrotto_EventScript_ClearSteps
# 57 "data//maps/ImpactedGrotto/scripts.pory"
	@ goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, ImpactedGrotto_EventScript_BigHoleInWall
# 58 "data//maps/ImpactedGrotto/scripts.pory"
	@ braillemessage ImpactedGrotto_Braille_RunLapAroundWall
# 59 "data//maps/ImpactedGrotto/scripts.pory"
	@ setflag FLAG_TEMP_REGIDRAGO_PUZZLE_STARTED
# 60 "data//maps/ImpactedGrotto/scripts.pory"
	@ special ShouldDoBrailleRegidragoPuzzle
# 61 "data//maps/ImpactedGrotto/scripts.pory"
	@ goto ImpactedGrotto_EventScript_CloseBrailleMsg
# 62 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 63 "data//maps/ImpactedGrotto/scripts.pory"

# 64 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_BigHoleInWall::
# 65 "data//maps/ImpactedGrotto/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 66 "data//maps/ImpactedGrotto/scripts.pory"
	releaseall
# 67 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 68 "data//maps/ImpactedGrotto/scripts.pory"

# 69 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_CaveEntranceSide::
# 70 "data//maps/ImpactedGrotto/scripts.pory"
	lockall
# 71 "data//maps/ImpactedGrotto/scripts.pory"
	@ call_if_set FLAG_TEMP_REGIDRAGO_PUZZLE_FAILED, ImpactedGrotto_EventScript_ClearSteps
# 72 "data//maps/ImpactedGrotto/scripts.pory"
	@ braillemessage ImpactedGrotto_Braille_RunLapAroundWall
# 73 "data//maps/ImpactedGrotto/scripts.pory"
	@ goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, ImpactedGrotto_EventScript_CloseBrailleMsg
# 74 "data//maps/ImpactedGrotto/scripts.pory"
	@ setflag FLAG_TEMP_REGIDRAGO_PUZZLE_STARTED
# 75 "data//maps/ImpactedGrotto/scripts.pory"
	@ special ShouldDoBrailleRegidragoPuzzle
# 76 "data//maps/ImpactedGrotto/scripts.pory"
	@ goto ImpactedGrotto_EventScript_CloseBrailleMsg
# 77 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 78 "data//maps/ImpactedGrotto/scripts.pory"

# 79 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_CloseBrailleMsg::
# 80 "data//maps/ImpactedGrotto/scripts.pory"
	waitbuttonpress
# 81 "data//maps/ImpactedGrotto/scripts.pory"
	closebraillemessage
# 82 "data//maps/ImpactedGrotto/scripts.pory"
	releaseall
# 83 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 84 "data//maps/ImpactedGrotto/scripts.pory"

# 85 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_ClearSteps::
# 86 "data//maps/ImpactedGrotto/scripts.pory"
	@ setvar VAR_REGIDRAGO_STEPS_1, 0
# 87 "data//maps/ImpactedGrotto/scripts.pory"
	@ setvar VAR_REGIDRAGO_STEPS_2, 0
# 88 "data//maps/ImpactedGrotto/scripts.pory"
	@ setvar VAR_REGIDRAGO_STEPS_3, 0
# 89 "data//maps/ImpactedGrotto/scripts.pory"
	@ clearflag FLAG_TEMP_REGIDRAGO_PUZZLE_FAILED
# 90 "data//maps/ImpactedGrotto/scripts.pory"
	return
# 91 "data//maps/ImpactedGrotto/scripts.pory"

# 92 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_Regidrago::
# 93 "data//maps/ImpactedGrotto/scripts.pory"
	lock
# 94 "data//maps/ImpactedGrotto/scripts.pory"
	faceplayer
# 95 "data//maps/ImpactedGrotto/scripts.pory"
	waitse
# 96 "data//maps/ImpactedGrotto/scripts.pory"
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
# 97 "data//maps/ImpactedGrotto/scripts.pory"
	delay 40
# 98 "data//maps/ImpactedGrotto/scripts.pory"
	waitmoncry
# 99 "data//maps/ImpactedGrotto/scripts.pory"
	setwildbattle SPECIES_REGIDRAGO, 40
# 100 "data//maps/ImpactedGrotto/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 101 "data//maps/ImpactedGrotto/scripts.pory"
	special StartRegiBattle
# 102 "data//maps/ImpactedGrotto/scripts.pory"
	waitstate
# 103 "data//maps/ImpactedGrotto/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 104 "data//maps/ImpactedGrotto/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 105 "data//maps/ImpactedGrotto/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ImpactedGrotto_EventScript_DefeatedRegidrago
# 106 "data//maps/ImpactedGrotto/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ImpactedGrotto_EventScript_RanFromRegidrago
# 107 "data//maps/ImpactedGrotto/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ImpactedGrotto_EventScript_RanFromRegidrago
# 108 "data//maps/ImpactedGrotto/scripts.pory"
	setflag FLAG_DEFEATED_REGIDRAGO
# 109 "data//maps/ImpactedGrotto/scripts.pory"
	release
# 110 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 111 "data//maps/ImpactedGrotto/scripts.pory"

# 112 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_DefeatedRegidrago::
# 113 "data//maps/ImpactedGrotto/scripts.pory"
	setflag FLAG_DEFEATED_REGIDRAGO
# 114 "data//maps/ImpactedGrotto/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 115 "data//maps/ImpactedGrotto/scripts.pory"
	end
# 116 "data//maps/ImpactedGrotto/scripts.pory"

# 117 "data//maps/ImpactedGrotto/scripts.pory"
ImpactedGrotto_EventScript_RanFromRegidrago::
# 118 "data//maps/ImpactedGrotto/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIDRAGO
# 119 "data//maps/ImpactedGrotto/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 120 "data//maps/ImpactedGrotto/scripts.pory"
	end
