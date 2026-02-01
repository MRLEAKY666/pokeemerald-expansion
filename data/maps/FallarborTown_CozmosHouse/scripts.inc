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
	@ goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
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
	goto_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
# 17 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call FallarborTown_CozmosHouse_EventScript_AskForMeteorite
# 18 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	waitmessage
# 19 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 20 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 21 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_TM_RETURN, 2
# 22 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 23 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 24 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 25 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_RETURN
# 26 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 27 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AlsoTakeThis, MSGBOX_DEFAULT
# 28 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 29 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 30 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 31 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AuroraTicket, MSGBOX_DEFAULT
# 32 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 33 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 34 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 35 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
# 36 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 37 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
# 38 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	waitmessage
# 39 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 40 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 41 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_TM_RETURN, 2
# 42 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 43 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 44 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 45 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_RETURN
# 46 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 47 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AlsoTakeThis, MSGBOX_DEFAULT
# 48 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 49 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 50 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 51 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_AuroraTicket, MSGBOX_DEFAULT
# 52 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 53 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 54 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 55 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
# 56 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
# 57 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 58 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 59 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
# 60 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 61 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
# 62 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 63 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 64 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 65 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
# 66 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 67 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 68 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 69 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 70 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmosWife::
# 71 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 72 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 73 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
# 74 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
# 75 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
# 76 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 77 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 78 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 79 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
# 80 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
# 81 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 82 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 83 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 84 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
# 85 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
# 86 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 87 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 88 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 89 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
# 90 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh…\n"
# 91 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I never should have let myself be\l"
# 92 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "conned into telling TEAM MAGMA where\l"
# 93 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "you can find METEORITES…\p"
# 94 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That METEORITE from METEOR FALLS…\n"
# 95 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It's never going to be mine now…$"
# 96 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 97 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
# 98 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh!\n"
# 99 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hah?\p"
# 100 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That item…\p"
# 101 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Could it be?\p"
# 102 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Is it the METEORITE that TEAM MAGMA\n"
# 103 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "took from METEOR FALLS?\p"
# 104 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please, may I have it?\p"
# 105 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 106 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 107 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 108 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
# 109 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: This TM, it represents\n"
# 110 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "my feeling of gratitude.\l"
# 111 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please use it!$"
# 112 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 113 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
# 114 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, I can't believe it.\n"
# 115 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really, really great!\p"
# 116 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really going to help my research!$"
# 117 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 118 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_AlsoTakeThis:
# 119 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "You should also take this.$"
# 120 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 121 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_AuroraTicket:
# 122 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That ticket will allow you to sail\n"
# 123 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "to an island where we found\l" 
# 124 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "another strange METEORITE.\p"
# 125 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "The METEORITE that formed METEOR FALLS\n"
# 126 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "and the one on that island . . .\p"
# 127 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Are they are somehow related?$"
# 128 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 129 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
# 130 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, but…\n"
# 131 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm crushed with disappointment…$"
# 132 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 133 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
# 134 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Please, may I have that\n"
# 135 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "METEORITE?\p"
# 136 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 137 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 138 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 139 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
# 140 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO went off to METEOR FALLS\n"
# 141 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "on ROUTE 114 with some people from\l"
# 142 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "TEAM MAGMA.$"
# 143 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 144 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
# 145 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Poor PROF. COZMO…\n"
# 146 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so depressed… I feel sorry for him.$"
# 147 "data//maps/FallarborTown_CozmosHouse/scripts.pory"

# 148 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
# 149 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look at PROF. COZMO…\n"
# 150 "data//maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so happy! I think it's cute.$"
