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
	call_if_set FLAG_START_LUGIA_QUEST, NavelRock_Entrance_EventScript_TryShowOak
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
NavelRock_Entrance_EventScript_TryShowOak::
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
	msgbox NavelRock_Entance_Text_OakDidYouBringThem, MSGBOX_YESNO
# 24 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NavelRock_Entrance_EventScript_OakBringTheBirds
# 25 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBirds
# 26 "data//maps/NavelRock_Entrance/scripts.pory"
	@ msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 27 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 28 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 29 "data//maps/NavelRock_Entrance/scripts.pory"

# 30 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_OakBringTheBirds::
# 31 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 32 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 33 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 34 "data//maps/NavelRock_Entrance/scripts.pory"

# 35 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_Wallace::
# 36 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 37 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 38 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 39 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 40 "data//maps/NavelRock_Entrance/scripts.pory"

# 41 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOakFindLugia::
# 42 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_DEFEATED_LUGIA, NavelRock_Entrance_EventScript_WaitForLugia
# 43 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakFindLugia, MSGBOX_DEFAULT
# 44 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 45 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 46 "data//maps/NavelRock_Entrance/scripts.pory"

# 47 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakDidYouBringThem:
# 48 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "PROF. OAK: Ah, {PLAYER}!\n"
# 49 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Welcome to NAVEL ROCK.\p"
# 50 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you bring the legendary POKéMON\n"
# 51 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES?$"
# 52 "data//maps/NavelRock_Entrance/scripts.pory"

# 53 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakBringTheBirds:
# 54 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "That's too bad…\p"
# 55 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Come back here with those\n"
# 56 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON.\p"
# 57 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd like to see if their presence\n"
# 58 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "might draw LUGIA back to this place.$"
# 59 "data//maps/NavelRock_Entrance/scripts.pory"

# 60 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_Text_OakPrepareForBattle:
# 61 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "If you want to help me attract\n"
# 62 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA to NAVEL ROCK, I'll need\l"
# 63 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to draw out the full potential of\l" 
# 64 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "your LEGEDARY BIRD POKéMON.\p"
# 65 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You should be prepared for a\n"
# 66 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "tough battle.$"
# 67 "data//maps/NavelRock_Entrance/scripts.pory"

# 68 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakExplain:
# 69 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You did!\p"
# 70 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Now {PLAYER}, this is NAVEL ROCK.\p"
# 71 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Some very rare and powerful POKéMON\n"
# 72 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "are known to roost here.\p"
# 73 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "One such POKéMON, LUGIA, is said\n"
# 74 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to have a connection to your\l"
# 75 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LEGENDARY BIRD POKéMON.\p"
# 76 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I theorize that by allowing your\n"
# 77 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON to demonstrate their full\l"
# 78 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "power in this place, we can summon LUGIA.$"
# 79 "data//maps/NavelRock_Entrance/scripts.pory"

# 80 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakAskToBattle:
# 81 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\l"
# 82 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Will you battle me here?$"
# 83 "data//maps/NavelRock_Entrance/scripts.pory"

# 84 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakStartBattle:
# 85 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Okay, {PLAYER}, prepare yourself!\p"
# 86 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Despite their old age, my POKéMON\n"
# 87 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "have more than enough experience\l"
# 88 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to be considered a threat!$"
# 89 "data//maps/NavelRock_Entrance/scripts.pory"

# 90 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakEndBattle:
# 91 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Thank you, {PLAYER}!$"
# 92 "data//maps/NavelRock_Entrance/scripts.pory"

# 93 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakPostBattle:
# 94 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
# 95 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I think LUGIA is here on the\n"
# 96 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "island!\p"
# 97 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 98 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 99 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 100 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 101 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 102 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"
# 103 "data//maps/NavelRock_Entrance/scripts.pory"

# 104 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakFindLugia:
# 105 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 106 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 107 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 108 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 109 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 110 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"

NavelRock_Entrance_EventScript_WaitForLugia::
# 115 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WaitForLugia_Text_0, MSGBOX_DEFAULT
# 120 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_CheckForBirds::
# 125 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ARTICUNO, NO_PARTY_SCREEN
# 126 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 127 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ZAPDOS, NO_PARTY_SCREEN
# 128 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 129 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_MOLTRES, NO_PARTY_SCREEN
# 130 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_4
NavelRock_Entrance_EventScript_CheckForBirds_1:
# 166 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBirds_Text_0, MSGBOX_DEFAULT
# 170 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	return

NavelRock_Entrance_EventScript_CheckForBirds_2:
# 132 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakExplain
# 133 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakAskToBattle, MSGBOX_YESNO
# 134 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBirds_8
# 161 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_Text_OakPrepareForBattle
# 162 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBirds_3:
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_C, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_2
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_4:
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_3
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_8:
# 135 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakStartBattle
# 136 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_OAK_NAVEL_ROCK, NavelRock_Entance_Text_OakEndBattle
# 137 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 138 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 139 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 140 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 141 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 142 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 143 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 144 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 145 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 146 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 147 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 148 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 149 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 150 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 151 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 152 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 153 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 154 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 155 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 156 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakPostBattle
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_WaitForLugia_Text_0:
# 115 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "What's that?\lYou saw LUGIA?\p"
	.string "But you think you killed it??\p"
	.string "Don't worry, {PLAYER}, A LEGENDARY POKéMON\nlike LUGIA Can't be killed\p"
	.string "Not permanently, at least!\p"
	.string "It's a minor setback to be sure, but I'm\ncertain if we give it time that LUGIA\lwill be back to roost here.$"

NavelRock_Entrance_EventScript_CheckForBirds_Text_0:
# 166 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Hmm?\p"
	.string "Come on, {PLAYER}, we're on the cusp\n"
	.string "of a breakthrough.\p"
	.string "This is no time to be joking around!\p"
	.string "Meet me here with ARTICUNO, ZAPDOS, and\n"
	.string "MOLTRES in your party so we can get on\l"
	.string "with the research.$"
