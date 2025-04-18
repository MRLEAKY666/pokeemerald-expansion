# 1 "data//maps/NavelRock_Entrance/scripts.pory"

# 2 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_MapScripts::
# 3 "data//maps/NavelRock_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Entrance_OnTransition
# 4 "data//maps/NavelRock_Entrance/scripts.pory"
	.byte 0
# 5 "data//maps/NavelRock_Entrance/scripts.pory"

# 6 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_OnTransition::
# 7 "data//maps/NavelRock_Entrance/scripts.pory"
	call_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, NavelRock_Entrance_EventScript_ShowWallace
# 8 "data//maps/NavelRock_Entrance/scripts.pory"
	call_if_set FLAG_START_LUGIA_QUEST, NavelRock_Entrance_EventScript_ShowOak
# 9 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 10 "data//maps/NavelRock_Entrance/scripts.pory"

# 11 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ShowWallace::
# 12 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_WALLACE
# 13 "data//maps/NavelRock_Entrance/scripts.pory"
	return
# 14 "data//maps/NavelRock_Entrance/scripts.pory"

# 15 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ShowOak::
# 16 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_OAK
# 17 "data//maps/NavelRock_Entrance/scripts.pory"
	return
# 18 "data//maps/NavelRock_Entrance/scripts.pory"

# 19 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOak::
# 20 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 21 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 22 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_defeated TRAINER_OAK_NAVEL_ROCK, NavelRock_Entrance_EventScript_ProfOakFindLugia
# 23 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakDidYouBringThem, MSGBOX_DEFAULT
# 24 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBirds
# 25 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 26 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 27 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 28 "data//maps/NavelRock_Entrance/scripts.pory"

# 29 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_Wallace::
# 30 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 31 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 32 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 33 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 34 "data//maps/NavelRock_Entrance/scripts.pory"

# 35 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOakFindLugia::
# 36 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakFindLugia, MSGBOX_DEFAULT
# 37 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 38 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 39 "data//maps/NavelRock_Entrance/scripts.pory"

# 40 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakDidYouBringThem:
# 41 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "PROF. OAK: Ah, {PLAYER}!\n"
# 42 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Welcome to NAVEL ROCK.\p"
# 43 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you bring the legendary POKéMON\n"
# 44 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES?$"
# 45 "data//maps/NavelRock_Entrance/scripts.pory"

# 46 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakBringTheBirds:
# 47 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "That's too bad . . .\p"
# 48 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Come back here with those\n"
# 49 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON.\p"
# 50 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd like to see if their presence\n"
# 51 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "might attract another rare POKéMON\l"
# 52 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to this place.$"
# 53 "data//maps/NavelRock_Entrance/scripts.pory"

# 54 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_Text_OakPrepareForBattle:
# 55 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "If you want to help me attract\n"
# 56 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA to NAVEL ROCK, prepare for a\l"
# 57 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "tough battle.$"
# 58 "data//maps/NavelRock_Entrance/scripts.pory"

# 59 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakExplain:
# 60 "data//maps/NavelRock_Entrance/scripts.pory"
	.string ". . .\n"
# 61 "data//maps/NavelRock_Entrance/scripts.pory"
	.string ". . .\p"
# 62 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You did!\p"
# 63 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Now {PLAYER}, this place is called\n"
# 64 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK . . .\p"
# 65 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Some very rare and powerful\n"
# 66 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON are known to roost here.\p"
# 67 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "One such POKéMON, LUGIA, is said\n"
# 68 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to have a connection to the\l"
# 69 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "legendary birds.\p"
# 70 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I theorize that by allowing your\n"
# 71 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON to demonstrate their full\l"
# 72 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "power in this place, we can\l"
# 73 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "summon LUGIA.$"
# 74 "data//maps/NavelRock_Entrance/scripts.pory"

# 75 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakAskToBattle:
# 76 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER} . . .\p"
# 77 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Will you battle me here?$"
# 78 "data//maps/NavelRock_Entrance/scripts.pory"

# 79 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakStartBattle:
# 80 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Okay, {PLAYER}, prepare yourself!\p"
# 81 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Despite their old age, my POKéMON\n"
# 82 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "have more than enough experience\l"
# 83 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to be considered a threat!$"
# 84 "data//maps/NavelRock_Entrance/scripts.pory"

# 85 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakEndBattle:
# 86 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Thank you, {PLAYER}!$"
# 87 "data//maps/NavelRock_Entrance/scripts.pory"

# 88 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakPostBattle:
# 89 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
# 90 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I think LUGIA is here on the\n"
# 91 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "island!\p"
# 92 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 93 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 94 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 95 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 96 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 97 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"
# 98 "data//maps/NavelRock_Entrance/scripts.pory"

# 99 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakFindLugia:
# 100 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 101 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 102 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 103 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 104 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 105 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"

NavelRock_Entrance_EventScript_CheckForBirds::
# 110 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ARTICUNO, NO_PARTY_SCREEN
# 111 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_2
NavelRock_Entrance_EventScript_CheckForBirds_1:
	return

NavelRock_Entrance_EventScript_CheckForBirds_2:
# 112 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ZAPDOS, NO_PARTY_SCREEN
# 113 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_4
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_4:
# 114 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_MOLTRES, NO_PARTY_SCREEN
# 115 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_6
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_6:
# 116 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakExplain
# 117 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakAskToBattle, MSGBOX_YESNO
# 118 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBirds_8
# 145 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_Text_OakPrepareForBattle
# 146 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBirds_8:
# 119 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakStartBattle
# 120 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_OAK_NAVEL_ROCK, NavelRock_Entance_Text_OakEndBattle
# 121 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 122 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 123 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 124 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 125 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 126 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 127 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 128 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 129 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 130 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 132 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 133 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 134 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 135 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 136 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 137 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 138 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 139 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 140 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakPostBattle
# 141 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

