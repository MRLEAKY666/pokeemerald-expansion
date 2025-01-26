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
NavelRock_Entrance_EventScript_ProfOakFindLugia::
# 30 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakFindLugia, MSGBOX_DEFAULT
# 31 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 32 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 33 "data//maps/NavelRock_Entrance/scripts.pory"

# 34 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakDidYouBringThem:
# 35 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "PROF. OAK: Ah, {PLAYER}!\n"
# 36 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Welcome to NAVEL ROCK.\p"
# 37 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you bring the legendary POKéMON\n"
# 38 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES?$"
# 39 "data//maps/NavelRock_Entrance/scripts.pory"

# 40 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakBringTheBirds:
# 41 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "That's too bad . . .\p"
# 42 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Come back here with those\n"
# 43 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON.\p"
# 44 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd like to see if their presence\n"
# 45 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "might attract another rare POKéMON\l"
# 46 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to this place.$"
# 47 "data//maps/NavelRock_Entrance/scripts.pory"

# 48 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakExplain:
# 49 "data//maps/NavelRock_Entrance/scripts.pory"
	.string ". . .\n"
# 50 "data//maps/NavelRock_Entrance/scripts.pory"
	.string ". . .\p"
# 51 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You did!\p"
# 52 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Now {PLAYER}, this place is called\n"
# 53 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK . . .\p"
# 54 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Some very rare and powerful\n"
# 55 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON are known to roost here.\p"
# 56 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "One such POKéMON, LUGIA, is said\n"
# 57 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to have a connection to the\l"
# 58 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "legendary birds.\p"
# 59 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I theorize that by allowing your\n"
# 60 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON to demonstrate their full\l"
# 61 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "power in this place, we can\l"
# 62 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "summon LUGIA.\p"
# 63 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "My battling days are long past,\n"
# 64 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "but for this experiment I think\l"
# 65 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'll make a serviceable partner.$"
# 66 "data//maps/NavelRock_Entrance/scripts.pory"

# 67 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakAskToBattle:
# 68 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER} . . .\p"
# 69 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Will you battle me here?$"
# 70 "data//maps/NavelRock_Entrance/scripts.pory"

# 71 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakStartBattle:
# 72 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Okay, {PLAYER}, prepare yourself!\p"
# 73 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Despite their old age, my POKéMON\n"
# 74 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "have more than enough experience\l"
# 75 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to be considered a threat!$"
# 76 "data//maps/NavelRock_Entrance/scripts.pory"

# 77 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakEndBattle:
# 78 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Thank you, {PLAYER}!$"
# 79 "data//maps/NavelRock_Entrance/scripts.pory"

# 80 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakPostBattle:
# 81 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
# 82 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I think LUGIA is here on the\n"
# 83 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "island!\p"
# 84 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 85 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 86 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 87 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 88 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 89 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"
# 90 "data//maps/NavelRock_Entrance/scripts.pory"

# 91 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakFindLugia:
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

NavelRock_Entrance_EventScript_CheckForBirds::
# 102 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ARTICUNO, NO_PARTY_SCREEN
# 103 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_2
NavelRock_Entrance_EventScript_CheckForBirds_1:
	return

NavelRock_Entrance_EventScript_CheckForBirds_2:
# 104 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ZAPDOS, NO_PARTY_SCREEN
# 105 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_4
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_4:
# 106 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_MOLTRES, NO_PARTY_SCREEN
# 107 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_6
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_6:
# 108 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakExplain
# 109 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakAskToBattle, MSGBOX_YESNO
# 110 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBirds_8
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_8:
# 111 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakStartBattle
# 112 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_OAK_NAVEL_ROCK, NavelRock_Entance_Text_OakEndBattle
# 113 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 114 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 115 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 116 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 117 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 118 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 119 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 120 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 121 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 122 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 123 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 124 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 125 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 126 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 127 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 128 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 129 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 130 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 132 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakPostBattle
# 133 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

