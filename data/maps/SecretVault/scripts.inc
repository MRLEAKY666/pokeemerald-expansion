# 1 "data//maps/SecretVault/scripts.pory"

# 2 "data//maps/SecretVault/scripts.pory"

# 3 "data//maps/SecretVault/scripts.pory"
SecretVault_MapScripts::
# 4 "data//maps/SecretVault/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SecretVault_OnResume
# 5 "data//maps/SecretVault/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SecretVault_OnLoad
# 6 "data//maps/SecretVault/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SecretVault_OnTransition
# 7 "data//maps/SecretVault/scripts.pory"
	.byte 0
# 8 "data//maps/SecretVault/scripts.pory"

# 9 "data//maps/SecretVault/scripts.pory"
SecretVault_OnResume:
# 10 "data//maps/SecretVault/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SecretVault_EventScript_TryRemoveRegieleki
# 11 "data//maps/SecretVault/scripts.pory"
	end
# 12 "data//maps/SecretVault/scripts.pory"

# 13 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_TryRemoveRegieleki::
# 14 "data//maps/SecretVault/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data//maps/SecretVault/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data//maps/SecretVault/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data//maps/SecretVault/scripts.pory"
	return
# 18 "data//maps/SecretVault/scripts.pory"

# 19 "data//maps/SecretVault/scripts.pory"
SecretVault_OnLoad:
# 20 "data//maps/SecretVault/scripts.pory"
	@ call_if_unset FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecretVault_EventScript_HideRegiEntrance
# 21 "data//maps/SecretVault/scripts.pory"
	end
# 22 "data//maps/SecretVault/scripts.pory"

# 23 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_HideRegiEntrance::
# 24 "data//maps/SecretVault/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 25 "data//maps/SecretVault/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 26 "data//maps/SecretVault/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 27 "data//maps/SecretVault/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data//maps/SecretVault/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 29 "data//maps/SecretVault/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 30 "data//maps/SecretVault/scripts.pory"
	return
# 31 "data//maps/SecretVault/scripts.pory"

# 32 "data//maps/SecretVault/scripts.pory"
SecretVault_OnTransition:
# 33 "data//maps/SecretVault/scripts.pory"
	setflag FLAG_LANDMARK_IMPACTED_GROTTO
# 34 "data//maps/SecretVault/scripts.pory"
	call SecretVault_EventScript_ClearSteps
# 35 "data//maps/SecretVault/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIELEKI, SecretVault_EventScript_ShowRegieleki
# 36 "data//maps/SecretVault/scripts.pory"
	end
# 37 "data//maps/SecretVault/scripts.pory"

# 38 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_ShowRegieleki::
# 39 "data//maps/SecretVault/scripts.pory"
	clearflag FLAG_HIDE_REGIELEKI
# 40 "data//maps/SecretVault/scripts.pory"
	return
# 41 "data//maps/SecretVault/scripts.pory"

# 42 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_OpenRegiEntrance::
# 43 "data//maps/SecretVault/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
# 44 "data//maps/SecretVault/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
# 45 "data//maps/SecretVault/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
# 46 "data//maps/SecretVault/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
# 47 "data//maps/SecretVault/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
# 48 "data//maps/SecretVault/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
# 49 "data//maps/SecretVault/scripts.pory"
	special DrawWholeMapView
# 50 "data//maps/SecretVault/scripts.pory"
	playse SE_BANG
# 51 "data//maps/SecretVault/scripts.pory"
	@ setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
# 52 "data//maps/SecretVault/scripts.pory"
	end
# 53 "data//maps/SecretVault/scripts.pory"

# 54 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_CaveEntranceMiddle::
# 55 "data//maps/SecretVault/scripts.pory"
	lockall
# 56 "data//maps/SecretVault/scripts.pory"
	@ call_if_set FLAG_TEMP_REGIELEKI_PUZZLE_FAILED, SecretVault_EventScript_ClearSteps
# 57 "data//maps/SecretVault/scripts.pory"
	@ goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecretVault_EventScript_BigHoleInWall
# 58 "data//maps/SecretVault/scripts.pory"
	@ braillemessage SecretVault_Braille_RunLapAroundWall
# 59 "data//maps/SecretVault/scripts.pory"
	@ setflag FLAG_TEMP_REGIELEKI_PUZZLE_STARTED
# 60 "data//maps/SecretVault/scripts.pory"
	@ special ShouldDoBrailleRegielekiPuzzle
# 61 "data//maps/SecretVault/scripts.pory"
	@ goto SecretVault_EventScript_CloseBrailleMsg
# 62 "data//maps/SecretVault/scripts.pory"
	end
# 63 "data//maps/SecretVault/scripts.pory"

# 64 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_BigHoleInWall::
# 65 "data//maps/SecretVault/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 66 "data//maps/SecretVault/scripts.pory"
	releaseall
# 67 "data//maps/SecretVault/scripts.pory"
	end
# 68 "data//maps/SecretVault/scripts.pory"

# 69 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_CaveEntranceSide::
# 70 "data//maps/SecretVault/scripts.pory"
	lockall
# 71 "data//maps/SecretVault/scripts.pory"
	@ call_if_set FLAG_TEMP_REGIELEKI_PUZZLE_FAILED, SecretVault_EventScript_ClearSteps
# 72 "data//maps/SecretVault/scripts.pory"
	@ braillemessage SecretVault_Braille_RunLapAroundWall
# 73 "data//maps/SecretVault/scripts.pory"
	@ goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, SecretVault_EventScript_CloseBrailleMsg
# 74 "data//maps/SecretVault/scripts.pory"
	@ setflag FLAG_TEMP_REGIELEKI_PUZZLE_STARTED
# 75 "data//maps/SecretVault/scripts.pory"
	@ special ShouldDoBrailleRegielekiPuzzle
# 76 "data//maps/SecretVault/scripts.pory"
	@ goto SecretVault_EventScript_CloseBrailleMsg
# 77 "data//maps/SecretVault/scripts.pory"
	end
# 78 "data//maps/SecretVault/scripts.pory"

# 79 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_CloseBrailleMsg::
# 80 "data//maps/SecretVault/scripts.pory"
	waitbuttonpress
# 81 "data//maps/SecretVault/scripts.pory"
	closebraillemessage
# 82 "data//maps/SecretVault/scripts.pory"
	releaseall
# 83 "data//maps/SecretVault/scripts.pory"
	end
# 84 "data//maps/SecretVault/scripts.pory"

# 85 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_ClearSteps::
# 86 "data//maps/SecretVault/scripts.pory"
	@ setvar VAR_REGIELEKI_STEPS_1, 0
# 87 "data//maps/SecretVault/scripts.pory"
	@ setvar VAR_REGIELEKI_STEPS_2, 0
# 88 "data//maps/SecretVault/scripts.pory"
	@ setvar VAR_REGIELEKI_STEPS_3, 0
# 89 "data//maps/SecretVault/scripts.pory"
	@ clearflag FLAG_TEMP_REGIELEKI_PUZZLE_FAILED
# 90 "data//maps/SecretVault/scripts.pory"
	return

SecretVault_EventScript_Regieleki::
# 95 "data//maps/SecretVault/scripts.pory"
	lock
# 96 "data//maps/SecretVault/scripts.pory"
	faceplayer
# 97 "data//maps/SecretVault/scripts.pory"
	waitse
# 98 "data//maps/SecretVault/scripts.pory"
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
# 99 "data//maps/SecretVault/scripts.pory"
	delay 40
# 100 "data//maps/SecretVault/scripts.pory"
	waitmoncry
# 101 "data//maps/SecretVault/scripts.pory"
	setwildbattle SPECIES_REGIELEKI, 40
# 102 "data//maps/SecretVault/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 103 "data//maps/SecretVault/scripts.pory"
	special StartRegiBattle
# 104 "data//maps/SecretVault/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 105 "data//maps/SecretVault/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 107 "data//maps/SecretVault/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SecretVault_EventScript_Regieleki_2
# 122 "data//maps/SecretVault/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SecretVault_EventScript_Regieleki_5
# 122 "data//maps/SecretVault/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SecretVault_EventScript_Regieleki_5
# 137 "data//maps/SecretVault/scripts.pory"
	setflag FLAG_DEFEATED_REGIELEKI
# 138 "data//maps/SecretVault/scripts.pory"
	release
	end

SecretVault_EventScript_Regieleki_2:
# 108 "data//maps/SecretVault/scripts.pory"
	setflag FLAG_DEFEATED_REGIELEKI
# 109 "data//maps/SecretVault/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 110 "data//maps/SecretVault/scripts.pory"
	removeobject VAR_LAST_TALKED
# 111 "data//maps/SecretVault/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 112 "data//maps/SecretVault/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_lt SecretVault_EventScript_Regieleki_10
SecretVault_EventScript_Regieleki_9:
# 117 "data//maps/SecretVault/scripts.pory"
	release
	end

SecretVault_EventScript_Regieleki_5:
# 123 "data//maps/SecretVault/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIELEKI
# 124 "data//maps/SecretVault/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 125 "data//maps/SecretVault/scripts.pory"
	removeobject VAR_LAST_TALKED
# 126 "data//maps/SecretVault/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 127 "data//maps/SecretVault/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 128 "data//maps/SecretVault/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
# 129 "data//maps/SecretVault/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_lt SecretVault_EventScript_Regieleki_13
SecretVault_EventScript_Regieleki_12:
# 134 "data//maps/SecretVault/scripts.pory"
	release
	end

SecretVault_EventScript_Regieleki_10:
# 113 "data//maps/SecretVault/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 2
# 114 "data//maps/SecretVault/scripts.pory"
	msgbox SecretVault_EventScript_Regieleki_Text_0, MSGBOX_DEFAULT
	goto SecretVault_EventScript_Regieleki_9

SecretVault_EventScript_Regieleki_13:
# 130 "data//maps/SecretVault/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 2
# 131 "data//maps/SecretVault/scripts.pory"
	msgbox SecretVault_EventScript_Regieleki_Text_1, MSGBOX_DEFAULT
	goto SecretVault_EventScript_Regieleki_12


# 142 "data//maps/SecretVault/scripts.pory"

# 143 "data//maps/SecretVault/scripts.pory"

# 144 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_DefeatedRegieleki::
# 145 "data//maps/SecretVault/scripts.pory"
	setflag FLAG_DEFEATED_REGIELEKI
# 146 "data//maps/SecretVault/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 147 "data//maps/SecretVault/scripts.pory"
	end
# 148 "data//maps/SecretVault/scripts.pory"

# 149 "data//maps/SecretVault/scripts.pory"
SecretVault_EventScript_RanFromRegieleki::
# 150 "data//maps/SecretVault/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIELEKI
# 151 "data//maps/SecretVault/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 152 "data//maps/SecretVault/scripts.pory"
	end

SecretVault_EventScript_Regieleki_Text_0:
# 114 "data//maps/SecretVault/scripts.pory"
	.string "With REGIELEKI's passing, the rampant\n"
	.string "electric field subsided.\p"
	.string "The GENERATOR should be able to\n"
	.string "function normally now.$"

SecretVault_EventScript_Regieleki_Text_1:
# 131 "data//maps/SecretVault/scripts.pory"
	.string "With REGIELEKI gone, the rampant\n"
	.string "electric field subsided.\p"
	.string "The GENERATOR should be able to\n"
	.string "function normally now.$"
