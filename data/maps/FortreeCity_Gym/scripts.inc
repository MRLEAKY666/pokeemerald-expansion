# 1 "data//maps/FortreeCity_Gym/scripts.pory"

# 2 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_MapScripts::
# 3 "data//maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
# 4 "data//maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
# 5 "data//maps/FortreeCity_Gym/scripts.pory"
	.byte 0
# 6 "data//maps/FortreeCity_Gym/scripts.pory"

# 7 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnTransition:
# 8 "data//maps/FortreeCity_Gym/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 9 "data//maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzle
# 10 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
# 11 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 12 "data//maps/FortreeCity_Gym/scripts.pory"

# 13 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnWarp:
# 14 "data//maps/FortreeCity_Gym/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
# 15 "data//maps/FortreeCity_Gym/scripts.pory"
	.2byte 0
# 16 "data//maps/FortreeCity_Gym/scripts.pory"

# 17 "data//maps/FortreeCity_Gym/scripts.pory"
@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
# 18 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_InitRotatingGates::
# 19 "data//maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 20 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 21 "data//maps/FortreeCity_Gym/scripts.pory"

# 22 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Winona::
# 23 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
# 24 "data//maps/FortreeCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 25 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
# 26 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
# 27 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
# 28 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 29 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 30 "data//maps/FortreeCity_Gym/scripts.pory"

# 31 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaDefeated::
# 32 "data//maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
# 33 "data//maps/FortreeCity_Gym/scripts.pory"
	waitmessage
# 34 "data//maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 35 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
# 36 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 37 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_BADGE06_GET
# 38 "data//maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_0x8008, 6
# 39 "data//maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 40 "data//maps/FortreeCity_Gym/scripts.pory"
	call FortreeCity_Gym_EventScript_GiveAerialAce
# 41 "data//maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 42 "data//maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 43 "data//maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 44 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
# 45 "data//maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 46 "data//maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 47 "data//maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 48 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
# 49 "data//maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
# 50 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
# 51 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 52 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 53 "data//maps/FortreeCity_Gym/scripts.pory"

# 54 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce2::
# 55 "data//maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE
# 56 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 57 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 58 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 59 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 60 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 61 "data//maps/FortreeCity_Gym/scripts.pory"

# 62 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce::
# 63 "data//maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE
# 64 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 65 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 66 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 67 "data//maps/FortreeCity_Gym/scripts.pory"
	return
# 68 "data//maps/FortreeCity_Gym/scripts.pory"

# 69 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaRematch::
# 70 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
# 71 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
# 72 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 73 "data//maps/FortreeCity_Gym/scripts.pory"

# 74 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Jared::
# 75 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
# 76 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
# 77 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 78 "data//maps/FortreeCity_Gym/scripts.pory"

# 79 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Edwardo::
# 80 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
# 81 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
# 82 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 83 "data//maps/FortreeCity_Gym/scripts.pory"

# 84 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Flint::
# 85 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
# 86 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
# 87 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 88 "data//maps/FortreeCity_Gym/scripts.pory"

# 89 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Ashley::
# 90 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
# 91 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
# 92 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 93 "data//maps/FortreeCity_Gym/scripts.pory"

# 94 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Humberto::
# 95 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
# 96 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
# 97 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 98 "data//maps/FortreeCity_Gym/scripts.pory"

# 99 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Darius::
# 100 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
# 101 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
# 102 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 103 "data//maps/FortreeCity_Gym/scripts.pory"

# 104 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuide::
# 105 "data//maps/FortreeCity_Gym/scripts.pory"
	lock
# 106 "data//maps/FortreeCity_Gym/scripts.pory"
	faceplayer
# 107 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
# 108 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 109 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 110 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 111 "data//maps/FortreeCity_Gym/scripts.pory"

# 112 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuidePostVictory::
# 113 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 114 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 115 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 116 "data//maps/FortreeCity_Gym/scripts.pory"

# 117 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_LeftGymStatue::
# 118 "data//maps/FortreeCity_Gym/scripts.pory"
	lockall
# 119 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 120 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 121 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 122 "data//maps/FortreeCity_Gym/scripts.pory"

# 123 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_RightGymStatue::
# 124 "data//maps/FortreeCity_Gym/scripts.pory"
	lockall
# 125 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 126 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 127 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 128 "data//maps/FortreeCity_Gym/scripts.pory"

# 129 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatueCertified::
# 130 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 131 "data//maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 132 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 133 "data//maps/FortreeCity_Gym/scripts.pory"

# 134 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatue::
# 135 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 136 "data//maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 137 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 138 "data//maps/FortreeCity_Gym/scripts.pory"

# 139 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuideAdvice:
# 140 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Yo, how's it going, CHAMPION-\n"
# 141 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 142 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE GYM LEADER WINONA is\n"
# 143 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "a master of FLYING-type POKéMON.\p"
# 144 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting at the back of this GYM,\n"
# 145 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "behind the rotating doors.\p"
# 146 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting for new challengers\n"
# 147 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "who are trying to take wing!\p"
# 148 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Okay, go for it!$"
# 149 "data//maps/FortreeCity_Gym/scripts.pory"

# 150 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuidePostVictory:
# 151 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You did it!\n"
# 152 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You've achieved liftoff!$"
# 153 "data//maps/FortreeCity_Gym/scripts.pory"

# 154 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredIntro:
# 155 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Behold the elegant battle style of\n"
# 156 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "BIRD POKéMON!$"
# 157 "data//maps/FortreeCity_Gym/scripts.pory"

# 158 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredDefeat:
# 159 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You…\n"
# 160 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You're strong…$"
# 161 "data//maps/FortreeCity_Gym/scripts.pory"

# 162 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredPostBattle:
# 163 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "A TRAINER has to be smart to keep\n"
# 164 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "up with unexpected turns of events.\p"
# 165 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Do you have the smarts to get to\n"
# 166 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "our LEADER?$"
# 167 "data//maps/FortreeCity_Gym/scripts.pory"

# 168 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoIntro:
# 169 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "The lovers of BIRD POKéMON aspire\n"
# 170 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "to join this GYM.\p"
# 171 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "As a member of the FORTREE GYM,\n"
# 172 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not allowed to lose!$"
# 173 "data//maps/FortreeCity_Gym/scripts.pory"

# 174 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoDefeat:
# 175 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "It was too much of a load for me\n"
# 176 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "to bear…$"
# 177 "data//maps/FortreeCity_Gym/scripts.pory"

# 178 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoPostBattle:
# 179 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "The world is huge, and there are\n"
# 180 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "countless tough TRAINERS.\p"
# 181 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm going to keep training and make\n"
# 182 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "myself even stronger.$"
# 183 "data//maps/FortreeCity_Gym/scripts.pory"

# 184 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintIntro:
# 185 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "There's no need for WINONA, our GYM\n"
# 186 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "LEADER, to deal with you!\p"
# 187 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm plenty good enough for you!$"
# 188 "data//maps/FortreeCity_Gym/scripts.pory"

# 189 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintDefeat:
# 190 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA, I…\n"
# 191 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I lost!$"
# 192 "data//maps/FortreeCity_Gym/scripts.pory"

# 193 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintPostBattle:
# 194 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA is cute and she's strong.\n"
# 195 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's the ultimate LEADER!\p"
# 196 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Blush…$"
# 197 "data//maps/FortreeCity_Gym/scripts.pory"

# 198 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyIntro:
# 199 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA taught me personally!\n"
# 200 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You can't beat me easily!$"
# 201 "data//maps/FortreeCity_Gym/scripts.pory"

# 202 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyDefeat:
# 203 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I was beaten…$"
# 204 "data//maps/FortreeCity_Gym/scripts.pory"

# 205 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyPostBattle:
# 206 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Thanks to WINONA, the people of\n"
# 207 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE can live without fear.$"
# 208 "data//maps/FortreeCity_Gym/scripts.pory"

# 209 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoIntro:
# 210 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "When WINONA takes to battle, her face\n"
# 211 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "shines with beautiful determination…\p"
# 212 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not letting you witness that\n"
# 213 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "lovely sight!$"
# 214 "data//maps/FortreeCity_Gym/scripts.pory"

# 215 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoDefeat:
# 216 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Urk!\n"
# 217 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I couldn't stop you.$"
# 218 "data//maps/FortreeCity_Gym/scripts.pory"

# 219 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoPostBattle:
# 220 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better watch it!\n"
# 221 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Don't get distracted staring at WINONA\l"
# 222 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "or you'll go crashing down in a heap!$"
# 223 "data//maps/FortreeCity_Gym/scripts.pory"

# 224 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusIntro:
# 225 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better know that there are all\n"
# 226 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "sorts of FLYING-type POKéMON.\p"
# 227 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You do know that, right?$"
# 228 "data//maps/FortreeCity_Gym/scripts.pory"

# 229 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusDefeat:
# 230 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You seem to know your stuff!$"
# 231 "data//maps/FortreeCity_Gym/scripts.pory"

# 232 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusPostBattle:
# 233 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Sure, you beat me all right.\n"
# 234 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "But you'd better watch it! Our LEADER\l"
# 235 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA's POKéMON are all business.$"
# 236 "data//maps/FortreeCity_Gym/scripts.pory"

# 237 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaIntro:
# 238 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I am WINONA. I am the LEADER of\n"
# 239 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the FORTREE POKéMON GYM.\p"
# 240 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I have become one with BIRD POKéMON\n"
# 241 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "and have soared the skies…\p"
# 242 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "However grueling the battle, we have\n"
# 243 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "triumphed with grace…\p"
# 244 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Witness the elegant choreography\n"
# 245 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "of BIRD POKéMON and I!$"
# 246 "data//maps/FortreeCity_Gym/scripts.pory"

# 247 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaDefeat:
# 248 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Never before have I seen a TRAINER\n"
# 249 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "command POKéMON with more grace\l"
# 250 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "than I…\p"
# 251 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "In recognition of your prowess,\n"
# 252 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I present to you this GYM BADGE.$"
# 253 "data//maps/FortreeCity_Gym/scripts.pory"

# 254 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ReceivedFeatherBadge:
# 255 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER} received the FEATHER BADGE\n"
# 256 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "from WINONA.$"
# 257 "data//maps/FortreeCity_Gym/scripts.pory"

# 258 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
# 259 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "With the FEATHER BADGE, all POKéMON up\n"
# 260 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "to LV 70, even those received through\l"
# 261 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "trades, will obey your every command.\p"
# 262 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You will also be able to use\n"
# 263 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the HM move FLY outside of battle.\p"
# 264 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "And this…\n"
# 265 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "This is a gift from me.$"
# 266 "data//maps/FortreeCity_Gym/scripts.pory"

# 267 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainAerialAce:
# 268 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "TM40 contains AERIAL ACE.\p"
# 269 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Its speed…\n"
# 270 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "No POKéMON should be able to avoid it.\p"
# 271 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 272 "data//maps/FortreeCity_Gym/scripts.pory"

# 273 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_RegisteredWinona:
# 274 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Registered GYM LEADER WINONA\n"
# 275 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 276 "data//maps/FortreeCity_Gym/scripts.pory"

# 277 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostBattle:
# 278 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Though I fell to you, I will remain\n"
# 279 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "devoted to BIRD POKéMON.$"
# 280 "data//maps/FortreeCity_Gym/scripts.pory"

# 281 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatue:
# 282 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE CITY POKéMON GYM$"
# 283 "data//maps/FortreeCity_Gym/scripts.pory"

# 284 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatueCertified:
# 285 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE CITY POKéMON GYM\p"
# 286 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
# 287 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 288 "data//maps/FortreeCity_Gym/scripts.pory"

# 289 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPreRematch:
# 290 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: We humans can never escape\n"
# 291 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "gravity's pull on the ground.\p"
# 292 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "But by striving for excellence,\n"
# 293 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "we have the power to soar!\p"
# 294 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You have scaled the pinnacle as\n"
# 295 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the reigning CHAMPION.\p"
# 296 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Please, allow me to see your power\n"
# 297 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "at full flight!$"
# 298 "data//maps/FortreeCity_Gym/scripts.pory"

# 299 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchDefeat:
# 300 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I failed to reach your height again…$"
# 301 "data//maps/FortreeCity_Gym/scripts.pory"

# 302 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostRematch:
# 303 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: Even though I have lost,\n"
# 304 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the wings of my heart remain unbroken.\p"
# 305 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I can rise and soar again and\n"
# 306 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "yet again.\p"
# 307 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I am convinced of it!$"
# 308 "data//maps/FortreeCity_Gym/scripts.pory"

# 309 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
# 310 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA: We humans can never escape\n"
# 311 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "gravity's pull on the ground.\p"
# 312 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "But by striving for excellence,\n"
# 313 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "we have the power to soar!\p"
# 314 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You have scaled the pinnacle as\n"
# 315 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the reigning CHAMPION.\p"
# 316 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Please, allow me to see your power\n"
# 317 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "at full flight!\p"
# 318 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Oh, no… Do you have but one\n"
# 319 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "POKéMON with you?\p"
# 320 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Please return with two POKéMON\n"
# 321 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "at the very least.$"
