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

NavelRock_Entrance_EventScript_ShowWallace::
# 13 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_HIDE_NAVEL_ROCK_WALLACE, NavelRock_Entrance_EventScript_ShowWallace_2
NavelRock_Entrance_EventScript_ShowWallace_1:
	return

NavelRock_Entrance_EventScript_ShowWallace_2:
# 14 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_WALLACE
	goto NavelRock_Entrance_EventScript_ShowWallace_1


# 19 "data//maps/NavelRock_Entrance/scripts.pory"

# 20 "data//maps/NavelRock_Entrance/scripts.pory"

# 21 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_TryShowOak::
# 22 "data//maps/NavelRock_Entrance/scripts.pory"
	clearflag FLAG_HIDE_NAVEL_ROCK_OAK
# 23 "data//maps/NavelRock_Entrance/scripts.pory"
	return
# 24 "data//maps/NavelRock_Entrance/scripts.pory"

# 25 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_ProfOak::
# 26 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 27 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 28 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_defeated TRAINER_OAK_NAVEL_ROCK, NavelRock_Entrance_EventScript_ProfOakFindLugia
# 29 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakDidYouBringThem, MSGBOX_YESNO
# 30 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, NavelRock_Entrance_EventScript_OakBringTheBirds
# 31 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBirds
# 32 "data//maps/NavelRock_Entrance/scripts.pory"
	@ msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
# 33 "data//maps/NavelRock_Entrance/scripts.pory"
	release
# 34 "data//maps/NavelRock_Entrance/scripts.pory"
	end
# 35 "data//maps/NavelRock_Entrance/scripts.pory"

# 36 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entrance_EventScript_OakBringTheBirds::
# 37 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakBringTheBirds, MSGBOX_DEFAULT
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
NavelRock_Entance_Text_WallaceEndBattle:
# 94 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\lHow spectacular…$"
# 95 "data//maps/NavelRock_Entrance/scripts.pory"

# 96 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakPostBattle:
# 97 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Did you hear that?\p"
# 98 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I think LUGIA is here on the\n"
# 99 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "island!\p"
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
# 106 "data//maps/NavelRock_Entrance/scripts.pory"

# 107 "data//maps/NavelRock_Entrance/scripts.pory"
NavelRock_Entance_Text_OakFindLugia:
# 108 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "LUGIA probably roosts deep under\n"
# 109 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "NAVEL ROCK, close to the water.\p"
# 110 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}, will you go find LUGIA?\p"
# 111 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "I'd very much appreciate the\n"
# 112 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "opportunity to study its POKéDEX\l"
# 113 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "data.$"

NavelRock_Entrance_EventScript_Wallace::
# 118 "data//maps/NavelRock_Entrance/scripts.pory"
	lock
# 119 "data//maps/NavelRock_Entrance/scripts.pory"
	faceplayer
# 120 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_defeated TRAINER_WALLACE_NAVEL_ROCK, NavelRock_Entrance_EventScript_WallaceFindHooh
# 121 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_Wallace_Text_0, MSGBOX_YESNO
# 123 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq NavelRock_Entrance_EventScript_Wallace_2
# 129 "data//maps/NavelRock_Entrance/scripts.pory"
	call NavelRock_Entrance_EventScript_CheckForBeasts
# 130 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	return

NavelRock_Entrance_EventScript_Wallace_2:
# 124 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_Wallace_Text_1, MSGBOX_DEFAULT
# 126 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_WallaceFindHooh::
# 134 "data//maps/NavelRock_Entrance/scripts.pory"
	goto_if_set FLAG_DEFEATED_HO_OH, NavelRock_Entrance_EventScript_WallaceFindHooh_2
# 142 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WallaceFindHooh_Text_1, MSGBOX_DEFAULT
# 145 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_WallaceFindHooh_2:
# 135 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WallaceFindHooh_Text_0, MSGBOX_DEFAULT
# 139 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_CheckForBeasts::
# 150 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_RAIKOU, NO_PARTY_SCREEN
# 151 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 152 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ENTEI, NO_PARTY_SCREEN
# 153 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 154 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_SUICUNE, NO_PARTY_SCREEN
# 155 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 156 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_4
NavelRock_Entrance_EventScript_CheckForBeasts_1:
# 207 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_5, MSGBOX_DEFAULT
# 209 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBeasts_2:
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_0, MSGBOX_DEFAULT
# 166 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_1, MSGBOX_YESNO
# 167 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBeasts_8
# 200 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_4, MSGBOX_DEFAULT
# 203 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBeasts_3:
# 156 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_C, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_2
	goto NavelRock_Entrance_EventScript_CheckForBeasts_1

NavelRock_Entrance_EventScript_CheckForBeasts_4:
# 156 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBeasts_3
	goto NavelRock_Entrance_EventScript_CheckForBeasts_1

NavelRock_Entrance_EventScript_CheckForBeasts_8:
# 168 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_2, MSGBOX_DEFAULT
# 170 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE_NAVEL_ROCK, NavelRock_Entance_Text_WallaceEndBattle
# 171 "data//maps/NavelRock_Entrance/scripts.pory"
	closemessage
# 172 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 60
# 173 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 174 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 175 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 176 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 177 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 178 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 179 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 180 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 181 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 182 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 183 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 184 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 185 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 186 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 187 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 188 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 189 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
# 190 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 191 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 192 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBeasts_Text_3, MSGBOX_DEFAULT
# 196 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_WaitForLugia::
# 214 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_WaitForLugia_Text_0, MSGBOX_DEFAULT
# 219 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_CheckForBirds::
# 224 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ARTICUNO, NO_PARTY_SCREEN
# 225 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_A, VAR_RESULT
# 226 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_ZAPDOS, NO_PARTY_SCREEN
# 227 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 228 "data//maps/NavelRock_Entrance/scripts.pory"
	checkspecies SPECIES_MOLTRES, NO_PARTY_SCREEN
# 229 "data//maps/NavelRock_Entrance/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 230 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_4
NavelRock_Entrance_EventScript_CheckForBirds_1:
# 265 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_EventScript_CheckForBirds_Text_0, MSGBOX_DEFAULT
# 269 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	return

NavelRock_Entrance_EventScript_CheckForBirds_2:
# 231 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakExplain
# 232 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakAskToBattle, MSGBOX_YESNO
# 233 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NavelRock_Entrance_EventScript_CheckForBirds_8
# 260 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entrance_Text_OakPrepareForBattle
# 261 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end

NavelRock_Entrance_EventScript_CheckForBirds_3:
# 230 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_C, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_2
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_4:
# 230 "data//maps/NavelRock_Entrance/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_ne NavelRock_Entrance_EventScript_CheckForBirds_3
	goto NavelRock_Entrance_EventScript_CheckForBirds_1

NavelRock_Entrance_EventScript_CheckForBirds_8:
# 234 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakStartBattle
# 235 "data//maps/NavelRock_Entrance/scripts.pory"
	trainerbattle_no_intro TRAINER_OAK_NAVEL_ROCK, NavelRock_Entance_Text_OakEndBattle
# 236 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 237 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 238 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 239 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 240 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 241 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 242 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 243 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 244 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8004, 0
# 245 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8005, 3
# 246 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8006, 4
# 247 "data//maps/NavelRock_Entrance/scripts.pory"
	setvar VAR_0x8007, 2
# 248 "data//maps/NavelRock_Entrance/scripts.pory"
	special ShakeCamera
# 249 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 30
# 250 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 50
# 251 "data//maps/NavelRock_Entrance/scripts.pory"
	waitse
# 252 "data//maps/NavelRock_Entrance/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 253 "data//maps/NavelRock_Entrance/scripts.pory"
	waitmoncry
# 254 "data//maps/NavelRock_Entrance/scripts.pory"
	delay 20
# 255 "data//maps/NavelRock_Entrance/scripts.pory"
	msgbox NavelRock_Entance_Text_OakPostBattle
# 256 "data//maps/NavelRock_Entrance/scripts.pory"
	release
	end


NavelRock_Entrance_EventScript_Wallace_Text_0:
# 121 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "WALLACE: {PLAYER},\n"
	.string "you made it.\p"
	.string "Did you bring the LEGENDARY BEAST\n"
	.string "POKéMON?$"

NavelRock_Entrance_EventScript_Wallace_Text_1:
# 124 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Meet me at this location with your\n"
	.string "LEGENDARY BEAST POKéMON.\p"
	.string "At that time, we'll conduct a fierce\n"
	.string "POKéMON battle.\p"
	.string "$"

NavelRock_Entrance_EventScript_WallaceFindHooh_Text_0:
# 135 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Hm?\l"
	.string "You think you defeated HO-OH?\p"
	.string "HO-OH is like a force of nature,\n"
	.string "{PLAYER}\p"
	.string "It may subside temporarily, but not\n"
	.string "forever.\p"
	.string "I'm sure HO-OH will return to roost\n"
	.string "soon.$"

NavelRock_Entrance_EventScript_WallaceFindHooh_Text_1:
# 142 "data//maps/NavelRock_Entrance/scripts.pory"
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
# 157 "data//maps/NavelRock_Entrance/scripts.pory"
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
# 166 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "{PLAYER}…\lWill you battle me here?$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_2:
# 168 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Then brace yourself.\p"
	.string "Our torrential assault won't be\n"
	.string "restrained as in official League\l"
	.string "battles.\p"
	.string "No, {PLAYER}\l"
	.string "This is our full power!$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_3:
# 192 "data//maps/NavelRock_Entrance/scripts.pory"
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
# 200 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "If we're going to summon HO-OH, we'll\n"
	.string "need to battle with our full strength.\p"
	.string "No, this won't be like the regulated\n"
	.string "battles under the League's purview…\p"
	.string "You'll need to be ready for a torrential\n"
	.string "assault.$"

NavelRock_Entrance_EventScript_CheckForBeasts_Text_5:
# 207 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Don't bluff me, {PLAYER}.\p"
	.string "Meet me here with the three LEGENDARY\n"
	.string "BEAST POKéMON so we can engage in\l"
	.string "unrestrained combat!$"

NavelRock_Entrance_EventScript_WaitForLugia_Text_0:
# 214 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "What's that?\lYou saw LUGIA?\p"
	.string "But you think you killed it??\p"
	.string "Don't worry, {PLAYER}, A LEGENDARY POKéMON\nlike LUGIA Can't be killed\p"
	.string "Not permanently, at least!\p"
	.string "It's a minor setback to be sure, but I'm\ncertain if we give it time that LUGIA\lwill be back to roost here.$"

NavelRock_Entrance_EventScript_CheckForBirds_Text_0:
# 265 "data//maps/NavelRock_Entrance/scripts.pory"
	.string "Hmm?\p"
	.string "Come on, {PLAYER}, we're on the cusp\n"
	.string "of a breakthrough.\p"
	.string "This is no time to be joking around!\p"
	.string "Meet me here with ARTICUNO, ZAPDOS, and\n"
	.string "MOLTRES in your party so we can get on\l"
	.string "with the research.$"
