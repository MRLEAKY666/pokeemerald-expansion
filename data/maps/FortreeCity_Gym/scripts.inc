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
	setvar VAR_0x8008, 6
# 9 "data//maps/FortreeCity_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_FORTREE_GYM, Common_EventScript_ResetGymTrainers
# 10 "data//maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzle
# 11 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
# 12 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 13 "data//maps/FortreeCity_Gym/scripts.pory"

# 14 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnWarp:
# 15 "data//maps/FortreeCity_Gym/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
# 16 "data//maps/FortreeCity_Gym/scripts.pory"
	.2byte 0
# 17 "data//maps/FortreeCity_Gym/scripts.pory"

# 18 "data//maps/FortreeCity_Gym/scripts.pory"
@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
# 19 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_InitRotatingGates::
# 20 "data//maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 21 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 22 "data//maps/FortreeCity_Gym/scripts.pory"

# 23 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Winona::
# 24 "data//maps/FortreeCity_Gym/scripts.pory"
	lock
# 25 "data//maps/FortreeCity_Gym/scripts.pory"
	faceplayer
# 26 "data//maps/FortreeCity_Gym/scripts.pory"
	call_if_unset FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_WinonaBadgeOrder
# 27 "data//maps/FortreeCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 28 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
# 29 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
# 30 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
# 31 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 32 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 33 "data//maps/FortreeCity_Gym/scripts.pory"

# 34 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaDefeated::
# 35 "data//maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
# 36 "data//maps/FortreeCity_Gym/scripts.pory"
	waitmessage
# 37 "data//maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 38 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
# 39 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 40 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_BADGE06_GET
# 41 "data//maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_0x8008, 6
# 42 "data//maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 43 "data//maps/FortreeCity_Gym/scripts.pory"
	call FortreeCity_Gym_EventScript_GiveAerialAce
# 44 "data//maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 45 "data//maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 46 "data//maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 47 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
# 48 "data//maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 49 "data//maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 50 "data//maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 51 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
# 52 "data//maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
# 53 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
# 54 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 55 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 56 "data//maps/FortreeCity_Gym/scripts.pory"

# 57 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce2::
# 58 "data//maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE, 5
# 59 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 60 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 61 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 62 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 63 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 64 "data//maps/FortreeCity_Gym/scripts.pory"

# 65 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GiveAerialAce::
# 66 "data//maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TM_AERIAL_ACE, 5
# 67 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 68 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
# 69 "data//maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
# 70 "data//maps/FortreeCity_Gym/scripts.pory"
	return
# 71 "data//maps/FortreeCity_Gym/scripts.pory"

# 72 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaRematch::
# 73 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
# 74 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
# 75 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 76 "data//maps/FortreeCity_Gym/scripts.pory"

# 77 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Jared::
# 78 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
# 79 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
# 80 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 81 "data//maps/FortreeCity_Gym/scripts.pory"

# 82 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Edwardo::
# 83 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
# 84 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
# 85 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 86 "data//maps/FortreeCity_Gym/scripts.pory"

# 87 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Flint::
# 88 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
# 89 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
# 90 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 91 "data//maps/FortreeCity_Gym/scripts.pory"

# 92 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Ashley::
# 93 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
# 94 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
# 95 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 96 "data//maps/FortreeCity_Gym/scripts.pory"

# 97 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Humberto::
# 98 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
# 99 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
# 100 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 101 "data//maps/FortreeCity_Gym/scripts.pory"

# 102 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Darius::
# 103 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
# 104 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
# 105 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 106 "data//maps/FortreeCity_Gym/scripts.pory"

# 107 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuide::
# 108 "data//maps/FortreeCity_Gym/scripts.pory"
	lock
# 109 "data//maps/FortreeCity_Gym/scripts.pory"
	faceplayer
# 110 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
# 111 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 112 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 113 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 114 "data//maps/FortreeCity_Gym/scripts.pory"

# 115 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuidePostVictory::
# 116 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 117 "data//maps/FortreeCity_Gym/scripts.pory"
	release
# 118 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 119 "data//maps/FortreeCity_Gym/scripts.pory"

# 120 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_LeftGymStatue::
# 121 "data//maps/FortreeCity_Gym/scripts.pory"
	lockall
# 122 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 123 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 124 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 125 "data//maps/FortreeCity_Gym/scripts.pory"

# 126 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_RightGymStatue::
# 127 "data//maps/FortreeCity_Gym/scripts.pory"
	lockall
# 128 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 129 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 130 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 131 "data//maps/FortreeCity_Gym/scripts.pory"

# 132 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatueCertified::
# 133 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 134 "data//maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 135 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 136 "data//maps/FortreeCity_Gym/scripts.pory"

# 137 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatue::
# 138 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 139 "data//maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 140 "data//maps/FortreeCity_Gym/scripts.pory"
	end
# 141 "data//maps/FortreeCity_Gym/scripts.pory"

# 142 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuideAdvice:
# 143 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Yo, how's it going, CHAMPION-\n"
# 144 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 145 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE GYM LEADER WINONA is\n"
# 146 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "a master of FLYING-type POKéMON.\p"
# 147 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting at the back of this GYM,\n"
# 148 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "behind the rotating doors.\p"
# 149 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting for new challengers\n"
# 150 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "who are trying to take wing!\p"
# 151 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Okay, go for it!$"
# 152 "data//maps/FortreeCity_Gym/scripts.pory"

# 153 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuidePostVictory:
# 154 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You did it!\n"
# 155 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You've achieved liftoff!$"
# 156 "data//maps/FortreeCity_Gym/scripts.pory"

# 157 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredIntro:
# 158 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Behold the elegant battle style of\n"
# 159 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "BIRD POKéMON!$"
# 160 "data//maps/FortreeCity_Gym/scripts.pory"

# 161 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredDefeat:
# 162 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You…\n"
# 163 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You're strong…$"
# 164 "data//maps/FortreeCity_Gym/scripts.pory"

# 165 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredPostBattle:
# 166 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "A TRAINER has to be smart to keep\n"
# 167 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "up with unexpected turns of events.\p"
# 168 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Do you have the smarts to get to\n"
# 169 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "our LEADER?$"
# 170 "data//maps/FortreeCity_Gym/scripts.pory"

# 171 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoIntro:
# 172 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "The lovers of BIRD POKéMON aspire\n"
# 173 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "to join this GYM.\p"
# 174 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "As a member of the FORTREE GYM,\n"
# 175 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not allowed to lose!$"
# 176 "data//maps/FortreeCity_Gym/scripts.pory"

# 177 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoDefeat:
# 178 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "It was too much of a load for me\n"
# 179 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "to bear…$"
# 180 "data//maps/FortreeCity_Gym/scripts.pory"

# 181 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoPostBattle:
# 182 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "The world is huge, and there are\n"
# 183 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "countless tough TRAINERS.\p"
# 184 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm going to keep training and make\n"
# 185 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "myself even stronger.$"
# 186 "data//maps/FortreeCity_Gym/scripts.pory"

# 187 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintIntro:
# 188 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "There's no need for WINONA, our GYM\n"
# 189 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "LEADER, to deal with you!\p"
# 190 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm plenty good enough for you!$"
# 191 "data//maps/FortreeCity_Gym/scripts.pory"

# 192 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintDefeat:
# 193 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA, I…\n"
# 194 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I lost!$"
# 195 "data//maps/FortreeCity_Gym/scripts.pory"

# 196 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintPostBattle:
# 197 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA is cute and she's strong.\n"
# 198 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "She's the ultimate LEADER!\p"
# 199 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Blush…$"
# 200 "data//maps/FortreeCity_Gym/scripts.pory"

# 201 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyIntro:
# 202 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA taught me personally!\n"
# 203 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You can't beat me easily!$"
# 204 "data//maps/FortreeCity_Gym/scripts.pory"

# 205 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyDefeat:
# 206 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I was beaten…$"
# 207 "data//maps/FortreeCity_Gym/scripts.pory"

# 208 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyPostBattle:
# 209 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Thanks to WINONA, the people of\n"
# 210 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "FORTREE can live without fear.$"
# 211 "data//maps/FortreeCity_Gym/scripts.pory"

# 212 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoIntro:
# 213 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "When WINONA takes to battle, her face\n"
# 214 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "shines with beautiful determination…\p"
# 215 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not letting you witness that\n"
# 216 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "lovely sight!$"
# 217 "data//maps/FortreeCity_Gym/scripts.pory"

# 218 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoDefeat:
# 219 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Urk!\n"
# 220 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I couldn't stop you.$"
# 221 "data//maps/FortreeCity_Gym/scripts.pory"

# 222 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoPostBattle:
# 223 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better watch it!\n"
# 224 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Don't get distracted staring at WINONA\l"
# 225 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "or you'll go crashing down in a heap!$"
# 226 "data//maps/FortreeCity_Gym/scripts.pory"

# 227 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusIntro:
# 228 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better know that there are all\n"
# 229 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "sorts of FLYING-type POKéMON.\p"
# 230 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You do know that, right?$"
# 231 "data//maps/FortreeCity_Gym/scripts.pory"

# 232 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusDefeat:
# 233 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You seem to know your stuff!$"
# 234 "data//maps/FortreeCity_Gym/scripts.pory"

# 235 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusPostBattle:
# 236 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Sure, you beat me all right.\n"
# 237 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "But you'd better watch it! Our LEADER\l"
# 238 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "WINONA's POKéMON are all business.$"
# 239 "data//maps/FortreeCity_Gym/scripts.pory"

# 240 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaIntro:
# 241 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I am WINONA. I am the LEADER of\n"
# 242 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "the FORTREE POKéMON GYM.\p"
# 243 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I have become one with BIRD POKéMON\n"
# 244 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "and have soared the skies…\p"
# 245 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "However grueling the battle, we have\n"
# 246 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "triumphed with grace…\p"
# 247 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Witness the elegant choreography\n"
# 248 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "of BIRD POKéMON and I!$"
# 249 "data//maps/FortreeCity_Gym/scripts.pory"

# 250 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaDefeat:
# 251 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "Never before have I seen a TRAINER\n"
# 252 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "command POKéMON with more grace\l"
# 253 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "than I…\p"
# 254 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "In recognition of your prowess,\n"
# 255 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "I present to you this GYM BADGE.$"
# 256 "data//maps/FortreeCity_Gym/scripts.pory"

# 257 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ReceivedFeatherBadge:
# 258 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER} received the FEATHER BADGE\n"
# 259 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "from WINONA.$"
# 260 "data//maps/FortreeCity_Gym/scripts.pory"

# 261 "data//maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
# 262 "data//maps/FortreeCity_Gym/scripts.pory"
	.string "You will now be able to use\n"
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

FortreeCity_Gym_EventScript_WinonaBadgeOrder::
# 324 "data//maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaIntro
# 325 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, FortreeCity_Gym_EventScript_WinonaBadgeOrder_2
# 331 "data//maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, FortreeCity_Gym_EventScript_WinonaBadgeOrder_3
# 338 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1B, FortreeCity_Gym_Text_WinonaDefeat
# 339 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1
# 340 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1B
# 341 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_WinonaDefeated
FortreeCity_Gym_EventScript_WinonaBadgeOrder_1:
	return

FortreeCity_Gym_EventScript_WinonaBadgeOrder_2:
# 326 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1B, FortreeCity_Gym_Text_WinonaDefeat
# 327 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1
# 328 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1C
# 329 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_WinonaDefeated
	goto FortreeCity_Gym_EventScript_WinonaBadgeOrder_1

FortreeCity_Gym_EventScript_WinonaBadgeOrder_3:
# 332 "data//maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1B, FortreeCity_Gym_Text_WinonaDefeat
# 333 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1C
# 334 "data//maps/FortreeCity_Gym/scripts.pory"
	settrainerflag TRAINER_WINONA_1B
# 335 "data//maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_WinonaDefeated
	goto FortreeCity_Gym_EventScript_WinonaBadgeOrder_1

