# 1 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 2 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_MapScripts::
# 3 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	.byte 0

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
# 8 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 9 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
# 11 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_BrailleBackWall_2
# 15 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	specialvar VAR_RESULT, CheckRelicanthWailord
# 17 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SealedChamber_InnerRoom_EventScript_BrailleBackWall_5
# 21 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	fadeoutbgm 0
# 22 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_TRUCK_MOVE
# 23 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 24 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 25 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 26 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 27 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 28 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 29 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 30 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 31 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 32 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 33 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 34 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
# 35 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	closemessage
# 36 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	fadeinbgm 0
# 37 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_REGI_DOORS_OPENED
# 38 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	goto_if_set FLAG_HIDE_MAUVILLE_CITY_WATTSON, SealedChamber_InnerRoom_EventScript_BrailleBackWall_8
SealedChamber_InnerRoom_EventScript_BrailleBackWall_7:
# 42 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
	return

SealedChamber_InnerRoom_EventScript_BrailleBackWall_2:
# 12 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleBackWall_5:
# 18 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleBackWall_8:
# 39 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 40 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	goto SealedChamber_InnerRoom_EventScript_BrailleBackWall_7


# 45 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 46 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 47 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_NoEffect::
# 48 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 49 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 50 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 51 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
# 52 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 53 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
# 54 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 55 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 56 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 57 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
# 58 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 59 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
# 60 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 61 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 62 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 63 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
# 64 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 65 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
# 66 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 67 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 68 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 69 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
# 70 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 71 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
# 72 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 73 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 74 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 75 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
# 76 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 77 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
# 78 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 79 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 80 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 81 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
# 82 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 83 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
# 84 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 85 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
