# 1 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 2 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_MapScripts::
# 3 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.byte 0
# 4 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 5 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ProfCozmo::
# 6 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 7 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 8 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
# 9 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	checkitem ITEM_METEORITE
# 10 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
# 11 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 12 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 13 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 14 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 15 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
# 16 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
# 17 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
# 18 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 19 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 20 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_TM_RETURN, 2
# 21 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 22 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 23 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 24 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_RETURN
# 25 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 26 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AlsoTakeThis, MSGBOX_DEFAULT
# 27 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 28 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 29 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 30 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AuroraTicket, MSGBOX_DEFAULT
# 31 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 32 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 33 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 34 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
# 35 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 36 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
# 37 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 38 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 39 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
# 40 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
# 41 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 42 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 43 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
# 44 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 45 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
# 46 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 47 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 48 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 49 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
# 50 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 51 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 52 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 53 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 54 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmosWife::
# 55 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 56 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 57 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
# 58 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
# 59 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
# 60 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 61 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 62 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 63 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
# 64 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
# 65 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 66 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 67 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 68 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
# 69 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
# 70 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 71 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 72 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 73 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
# 74 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh…\n"
# 75 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I never should have let myself be\l"
# 76 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "conned into telling TEAM MAGMA where\l"
# 77 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "you can find METEORITES…\p"
# 78 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That METEORITE from METEOR FALLS…\n"
# 79 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It's never going to be mine now…$"
# 80 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 81 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
# 82 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh!\n"
# 83 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hah?\p"
# 84 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That item…\p"
# 85 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Could it be?\p"
# 86 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Is it the METEORITE that TEAM MAGMA\n"
# 87 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "took from METEOR FALLS?\p"
# 88 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please, may I have it?\p"
# 89 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 90 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 91 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 92 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
# 93 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: This TM, it represents\n"
# 94 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "my feeling of gratitude.\l"
# 95 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please use it!$"
# 96 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 97 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
# 98 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, I can't believe it.\n"
# 99 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really, really great!\p"
# 100 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really going to help my research!$"
# 101 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 102 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_AlsoTakeThis:
# 103 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "You should also take this.$"
# 104 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 105 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_AuroraTicket:
# 106 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That ticket will allow you to sail to\n"
# 107 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "the island where we found that METEORITE\p"
# 108 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "The METEORITE is a sample from a larger\n"
# 109 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "specimen that crashed and which exhibits\l"
# 110 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "indecipherable properties . . . \p"
# 111 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 112 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
# 113 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, but…\n"
# 114 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm crushed with disappointment…$"
# 115 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 116 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
# 117 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Please, may I have that\n"
# 118 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "METEORITE?\p"
# 119 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 120 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 121 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 122 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
# 123 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO went off to METEOR FALLS\n"
# 124 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "on ROUTE 114 with some people from\l"
# 125 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "TEAM MAGMA.$"
# 126 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 127 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
# 128 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Poor PROF. COZMO…\n"
# 129 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so depressed… I feel sorry for him.$"
# 130 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 131 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
# 132 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look at PROF. COZMO…\n"
# 133 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so happy! I think it's cute.$"
