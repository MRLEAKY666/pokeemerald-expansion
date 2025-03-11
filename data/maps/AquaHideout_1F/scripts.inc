# 1 "data//maps/AquaHideout_1F/scripts.pory"

# 2 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_MapScripts::
# 3 "data//maps/AquaHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_1F_OnTransition
# 4 "data//maps/AquaHideout_1F/scripts.pory"
	.byte 0
# 5 "data//maps/AquaHideout_1F/scripts.pory"

# 6 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_OnTransition:
# 7 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 8 "data//maps/AquaHideout_1F/scripts.pory"

# 9 "data//maps/AquaHideout_1F/scripts.pory"
@ The below two entrance guards give hints about what to do to progress the story
# 10 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
# 11 "data//maps/AquaHideout_1F/scripts.pory"
	lock
# 12 "data//maps/AquaHideout_1F/scripts.pory"
	faceplayer
# 13 "data//maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
# 14 "data//maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
# 15 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
# 16 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 17 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 18 "data//maps/AquaHideout_1F/scripts.pory"

# 19 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_MagmaHideoutHint1::
# 20 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
# 21 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 22 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 23 "data//maps/AquaHideout_1F/scripts.pory"

# 24 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_SlateportHint1::
# 25 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
# 26 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 27 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 28 "data//maps/AquaHideout_1F/scripts.pory"

# 29 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
# 30 "data//maps/AquaHideout_1F/scripts.pory"
	lock
# 31 "data//maps/AquaHideout_1F/scripts.pory"
	faceplayer
# 32 "data//maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
# 33 "data//maps/AquaHideout_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
# 34 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
# 35 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 36 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 37 "data//maps/AquaHideout_1F/scripts.pory"

# 38 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_MagmaHideoutHint2::
# 39 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
# 40 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 41 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 42 "data//maps/AquaHideout_1F/scripts.pory"

# 43 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_SlateportHint2::
# 44 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
# 45 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 46 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 47 "data//maps/AquaHideout_1F/scripts.pory"

# 48 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_Grunt1::
# 49 "data//maps/AquaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
# 50 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 51 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 52 "data//maps/AquaHideout_1F/scripts.pory"

# 53 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_EventScript_Grunt1Defeated::
# 54 "data//maps/AquaHideout_1F/scripts.pory"
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
# 55 "data//maps/AquaHideout_1F/scripts.pory"
	release
# 56 "data//maps/AquaHideout_1F/scripts.pory"
	end
# 57 "data//maps/AquaHideout_1F/scripts.pory"

# 58 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_OurBossIsSnatchingSomething:
# 59 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 60 "data//maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 61 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here! He's gone off to\n"
# 62 "data//maps/AquaHideout_1F/scripts.pory"
	.string "snatch something important!\p"
# 63 "data//maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 64 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Where did he go?\p"
# 65 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 66 "data//maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 67 "data//maps/AquaHideout_1F/scripts.pory"

# 68 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
# 69 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What?\n"
# 70 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Are you a TEAM MAGMA grunt?\p"
# 71 "data//maps/AquaHideout_1F/scripts.pory"
	.string "I hear that TEAM MAGMA is trying to\n"
# 72 "data//maps/AquaHideout_1F/scripts.pory"
	.string "awaken an awesome POKéMON at their\l"
# 73 "data//maps/AquaHideout_1F/scripts.pory"
	.string "HIDEOUT.\p"
# 74 "data//maps/AquaHideout_1F/scripts.pory"
	.string "But where might their HIDEOUT be?$"
# 75 "data//maps/AquaHideout_1F/scripts.pory"

# 76 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossWentToJackASubmarine:
# 77 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 78 "data//maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 79 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here!\n"
# 80 "data//maps/AquaHideout_1F/scripts.pory"
	.string "He's gone off to jack a submarine!\p"
# 81 "data//maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 82 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Where did he go?\p"
# 83 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 84 "data//maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 85 "data//maps/AquaHideout_1F/scripts.pory"

# 86 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossIsOnRoute122:
# 87 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with \n"
# 88 "data//maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 89 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here! He's on his way to\n"
# 90 "data//maps/AquaHideout_1F/scripts.pory"
	.string "MT. PYRE on ROUTE 122!\p"
# 91 "data//maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 92 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Why did he go?\p"
# 93 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 94 "data//maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 95 "data//maps/AquaHideout_1F/scripts.pory"

# 96 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_TeamMagmaAtMtChimney:
# 97 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What?\n"
# 98 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Are you a TEAM MAGMA grunt?\p"
# 99 "data//maps/AquaHideout_1F/scripts.pory"
	.string "I hear that TEAM MAGMA is after\n"
# 100 "data//maps/AquaHideout_1F/scripts.pory"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
# 101 "data//maps/AquaHideout_1F/scripts.pory"
	.string "But what is that POKéMON like?$"
# 102 "data//maps/AquaHideout_1F/scripts.pory"

# 103 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_BossIsInSlateportCity:
# 104 "data//maps/AquaHideout_1F/scripts.pory"
	.string "What? What? What do you want with\n"
# 105 "data//maps/AquaHideout_1F/scripts.pory"
	.string "TEAM AQUA?\p"
# 106 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Our BOSS isn't here!\n"
# 107 "data//maps/AquaHideout_1F/scripts.pory"
	.string "He's on his way to SLATEPORT CITY!\p"
# 108 "data//maps/AquaHideout_1F/scripts.pory"
	.string "… …\n"
# 109 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Why did he go?\p"
# 110 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Wahaha! Do you really think I'd tell\n"
# 111 "data//maps/AquaHideout_1F/scripts.pory"
	.string "you something that crucial?$"
# 112 "data//maps/AquaHideout_1F/scripts.pory"

# 113 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1Intro:
# 114 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Ayiyiyi!\n"
# 115 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Suspicious character spotted!$"
# 116 "data//maps/AquaHideout_1F/scripts.pory"

# 117 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1Defeat:
# 118 "data//maps/AquaHideout_1F/scripts.pory"
	.string "Grrrrr…\n"
# 119 "data//maps/AquaHideout_1F/scripts.pory"
	.string "I lost it!$"
# 120 "data//maps/AquaHideout_1F/scripts.pory"

# 121 "data//maps/AquaHideout_1F/scripts.pory"
AquaHideout_1F_Text_Grunt1PostBattle:
# 122 "data//maps/AquaHideout_1F/scripts.pory"
	.string "I took the loss for the TEAM,\n"
# 123 "data//maps/AquaHideout_1F/scripts.pory"
	.string "but I did my job…$"
