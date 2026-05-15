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
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 10 "data//maps/NavelRock_Entrance/scripts.pory"
	end

NavelRock_Entrance_EventScript_ShowWallace::
# 14 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_HIDE_NAVEL_ROCK_WALLACE, NavelRock_Entrance_EventScript_ShowWallace_2
NavelRock_Entrance_EventScript_ShowWallace_1:
	return

NavelRock_Entrance_EventScript_ShowWallace_2:
# 15 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_WALLACE
	goto NavelRock_Entrance_EventScript_ShowWallace_1


# 20 "data//maps/NavelRock_Entrance/scripts.pory"

# 21 "data//maps/NavelRock_Entrance/scripts.pory"

# 22 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_TryShowOak::
# 23 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_OAK
# 24 "data//maps/NavelRock_Entrance/scripts.pory"
	return
# 25 "data//maps/NavelRock_Entrance/scripts.pory"

# 26 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOak::
# 27 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 28 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 29 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_defeated TRAINER_OAK_NAVEL_ROCK, NavelRock_Entrance_EventScript_ProfOakFindLugia
# 30 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakDidYouBringThem, MSGBOX_YESNO
# 31 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NavelRock_Entrance_EventScript_OakBringTheBirds
# 32 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBirds
# 33 "data//maps/NavelRock_Entrance/scripts.pory"
	@ msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 34 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 35 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 36 "data//maps/NavelRock_Entrance/scripts.pory"

# 37 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_OakBringTheBirds::
# 38 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 39 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 40 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 41 "data//maps/NavelRock_Entrance/scripts.pory"

# 42 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOakFindLugia::
# 43 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_DEFEATED_LUGIA, NavelRock_Entrance_EventScript_WaitForLugia
# 44 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakFindLugia, MSGBOX_DEFAULT
# 45 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 46 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 47 "data//maps/NavelRock_Entrance/scripts.pory"

# 48 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakDidYouBringThem:
# 49 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "PROF. OAK: Ah, {PLAYER}!\n"
# 50 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Welcome to NAVEL ROCK.\p"
# 51 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you bring the legendary POKéMON\n"
# 52 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES?$"
# 53 "data//maps/NavelRock_Entrance/scripts.pory"

# 54 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakBringTheBirds:
# 55 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "That's too bad…\p"
# 56 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Come back here with those\n"
# 57 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON.\p"
# 58 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd like to see if their presence\n"
# 59 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "might draw LUGIA back to this place.$"
# 60 "data//maps/NavelRock_Entrance/scripts.pory"

# 61 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_Text_OakPrepareForBattle:
# 62 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "If you want to help me attract\n"
# 63 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA to NAVEL ROCK, I'll need\l"
# 64 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to draw out the full potential of\l" 
# 65 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "your LEGEDARY BIRD POKéMON.\p"
# 66 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You should be prepared for a\n"
# 67 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "tough battle.$"
# 68 "data//maps/NavelRock_Entrance/scripts.pory"

# 69 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakExplain:
# 70 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "You did!\p"
# 71 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Now {PLAYER}, this is NAVEL ROCK.\p"
# 72 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Some very rare and powerful POKéMON\n"
# 73 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "are known to roost here.\p"
# 74 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "One such POKéMON, LUGIA, is said\n"
# 75 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to have a connection to your\l"
# 76 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LEGENDARY BIRD POKéMON.\p"
# 77 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I theorize that by allowing your\n"
# 78 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "POKéMON to demonstrate their full\l"
# 79 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "power in this place, we can summon LUGIA.$"
# 80 "data//maps/NavelRock_Entrance/scripts.pory"

# 81 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakAskToBattle:
# 82 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\l"
# 83 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Will you battle me here?$"
# 84 "data//maps/NavelRock_Entrance/scripts.pory"

# 85 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakStartBattle:
# 86 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Okay, {PLAYER}, prepare yourself!\p"
# 87 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Despite their old age, my POKéMON\n"
# 88 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "have more than enough experience\l"
# 89 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "to be considered a threat!$"
# 90 "data//maps/NavelRock_Entrance/scripts.pory"

# 91 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakEndBattle:
# 92 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Thank you, {PLAYER}!$"
# 93 "data//maps/NavelRock_Entrance/scripts.pory"

# 94 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_WallaceEndBattle:
# 95 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\lHow spectacular…$"
# 96 "data//maps/NavelRock_Entrance/scripts.pory"

# 97 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakPostBattle:
# 98 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
# 99 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I think LUGIA is here on the\n"
# 100 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "island!\p"
# 101 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 102 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 103 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 104 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 105 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 106 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"
# 107 "data//maps/NavelRock_Entrance/scripts.pory"

# 108 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakFindLugia:
# 109 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 110 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 111 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 112 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 113 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 114 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"

NavelRock_Entrance_EventScript_Wallace::
# 119 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 120 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 121 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_defeated TRAINER_WALLACE_NAVEL_ROCK, NavelRock_Entrance_EventScript_WallaceFindHooh
# 122 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_Wallace_Text_0, MSGBOX_YESNO
# 124 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NavelRock_Entrance_EventScript_Wallace_2
# 130 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBeasts
# 131 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	return

NavelRock_Entrance_EventScript_Wallace_2:
# 125 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 127 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_WallaceFindHooh::
# 135 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_DEFEATED_HO_OH, NavelRock_Entrance_EventScript_WallaceFindHooh_2
# 143 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WallaceFindHooh_Text_1, MSGBOX_DEFAULT
# 146 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_WallaceFindHooh_2:
# 136 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WallaceFindHooh_Text_0, MSGBOX_DEFAULT
# 140 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_CheckForBeasts::
# 151 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 152 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 153 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 154 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 155 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 156 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_4
NavelRock_Entrance_EventScript_CheckForBeasts_1:
# 208 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_5, MSGBOX_DEFAULT
# 210 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBeasts_2:
# 158 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_0, MSGBOX_DEFAULT
# 167 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_1, MSGBOX_YESNO
# 168 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBeasts_8
# 201 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_4, MSGBOX_DEFAULT
# 204 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBeasts_3:
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_C, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_2
	goto NavelRock_Entrance_EventScript_CheckForBeasts_1

NavelRock_Entrance_EventScript_CheckForBeasts_4:
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_3
	goto NavelRock_Entrance_EventScript_CheckForBeasts_1

NavelRock_Entrance_EventScript_CheckForBeasts_8:
# 169 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_2, MSGBOX_DEFAULT
# 171 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE_NAVEL_ROCK, NavelRock_Entance_Text_WallaceEndBattle
# 172 "data//maps/NavelRock_Entrance/scripts.pory"
	closemessage
# 173 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 60
# 174 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 175 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 176 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 177 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 178 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 179 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 180 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 181 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 182 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 183 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 184 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 185 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 186 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 187 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 188 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 189 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 190 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 191 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 192 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 193 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_3, MSGBOX_DEFAULT
# 197 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_WaitForLugia::
# 215 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WaitForLugia_Text_0, MSGBOX_DEFAULT
# 220 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_CheckForBirds::
# 225 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ARTICUNO, NO_PARTY_SCREEN
# 226 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 227 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ZAPDOS, NO_PARTY_SCREEN
# 228 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 229 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_MOLTRES, NO_PARTY_SCREEN
# 230 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 231 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_4
NavelRock_Entrance_EventScript_CheckForBirds_1:
# 266 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBirds_Text_0, MSGBOX_DEFAULT
# 270 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	return

NavelRock_Entrance_EventScript_CheckForBirds_2:
# 232 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakExplain
# 233 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakAskToBattle, MSGBOX_YESNO
# 234 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBirds_8
# 261 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_Text_OakPrepareForBattle
# 262 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBirds_3:
# 231 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_C, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_2
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_4:
# 231 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_3
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_8:
# 235 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakStartBattle
# 236 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_OAK_NAVEL_ROCK, NavelRock_Entance_Text_OakEndBattle
# 237 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 238 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 239 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 240 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 241 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 242 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 243 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 244 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 245 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 246 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 247 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 248 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 249 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 250 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 251 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 252 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 253 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 254 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 255 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 256 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakPostBattle
# 257 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_Wallace_Text_0:
# 122 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "WALLACE: {PLAYER},\n"
	.string "you made it.\p"
	.string "Did you bring the LEGENDARY BEAST\n"
	.string "POKéMON?$"

NavelRock_Entrance_EventScript_Wallace_Text_1:
# 125 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Meet me at this location with your\n"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "At that time, we'll conduct a fierce\n"
	.string "POKéMON battle.\p"
	.string "$"

NavelRock_Entrance_EventScript_WallaceFindHooh_Text_0:
# 136 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Hm?\l"
	.string "You think you defeated HO-OH?\p"
	.string "HO-OH is like a force of nature,\n"
	.string "{PLAYER}.\p"
	.string "It may subside temporarily, but not\n"
	.string "forever.\p"
	.string "I'm sure HO-OH will return to roost\n"
	.string "soon.$"

NavelRock_Entrance_EventScript_WallaceFindHooh_Text_1:
# 143 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "HO-OH probably roosts high atop\n"
	.string "NAVEL ROCK\p"
	.string "{PLAYER}, will you go find HO-OH?\p"
	.string "Surely it is your destiny as the gifted\n"
	.string "TRAINER who tamed all three LEGENDARY\l"
	.string "BEASTS…\p"
	.string "Yes,\n"
	.string "I truly believe you can even tame\l"
	.string "HO-OH.$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_0:
# 158 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Good, you did indeed.\pNow {PLAYER}, this is NAVEL ROCK.\p"
	.string "Some very rare and powerful POKéMON\n"
	.string "are known to roost here.\p"
	.string "One such POKéMON, HO-OH, is said\n"
	.string "to have a connection to your\l"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "It's my hope that by invoking your\n"
	.string "POKéMON's full power through fierce combat,\l"
	.string "we can summon HO-OH.$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_1:
# 167 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\lWill you battle me here?$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_2:
# 169 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Then brace yourself.\p"
	.string "Our torrential assault won't be\n"
	.string "restrained as in official League\l"
	.string "battles.\p"
	.string "No, {PLAYER}\l"
	.string "This is our full power!$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_3:
# 193 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
	.string "That must have been HO-OH!\p"
	.string "HO-OH probably roosts high atop\n"
	.string "NAVEL ROCK\p"
	.string "{PLAYER}, will you go find HO-OH?\p"
	.string "Surely it is your destiny as the gifted\n"
	.string "TRAINER who tamed all three LEGENDARY\l"
	.string "BEASTS…\p"
	.string "Yes,\n"
	.string "I truly believe you can even tame\l"
	.string "HO-OH.$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_4:
# 201 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "If we're going to summon HO-OH, we'll\n"
	.string "need to battle with our full strength.\p"
	.string "No, this won't be like the regulated\n"
	.string "battles under the League's purview…\p"
	.string "You'll need to be ready for a torrential\n"
	.string "assault.$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_5:
# 208 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Don't bluff me, {PLAYER}.\p"
	.string "Meet me here with the three LEGENDARY\n"
	.string "BEAST POKéMON so we can engage in\l"
	.string "unrestrained combat!$"

NavelRock_Entrance_EventScript_WaitForLugia_Text_0:
# 215 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "What's that?\lYou saw LUGIA?\p"
	.string "But you think you killed it??\p"
	.string "Don't worry, {PLAYER}, A LEGENDARY POKéMON\nlike LUGIA Can't be killed\p"
	.string "Not permanently, at least!\p"
	.string "It's a minor setback to be sure, but I'm\ncertain if we give it time that LUGIA\lwill be back to roost here.$"

NavelRock_Entrance_EventScript_CheckForBirds_Text_0:
# 266 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Hmm?\p"
	.string "Come on, {PLAYER}, we're on the cusp\n"
	.string "of a breakthrough.\p"
	.string "This is no time to be joking around!\p"
	.string "Meet me here with ARTICUNO, ZAPDOS, and\n"
	.string "MOLTRES in your party so we can get on\l"
	.string "with the research.$"
