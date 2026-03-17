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
	waitstate
# 25 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 26 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 27 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 28 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 29 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 30 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 31 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 32 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 33 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 34 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 35 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	waitstate
# 36 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	playse SE_DOOR
# 37 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	delay 40
# 38 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
# 39 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	closemessage
# 40 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	fadeinbgm 0
# 41 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	setflag FLAG_REGI_DOORS_OPENED
# 46 "data//maps/SealedChamber_InnerRoom/scripts.pory"
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


# 49 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 50 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 51 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_NoEffect::
# 52 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 53 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 54 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 55 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
# 56 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 57 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
# 58 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 59 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 60 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 61 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
# 62 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 63 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
# 64 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 65 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 66 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 67 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
# 68 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 69 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
# 70 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 71 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 72 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 73 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
# 74 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 75 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
# 76 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 77 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 78 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 79 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
# 80 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 81 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
# 82 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 83 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
# 84 "data//maps/SealedChamber_InnerRoom/scripts.pory"

# 85 "data//maps/SealedChamber_InnerRoom/scripts.pory"
SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
# 86 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	lockall
# 87 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
# 88 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	releaseall
# 89 "data//maps/SealedChamber_InnerRoom/scripts.pory"
	end
