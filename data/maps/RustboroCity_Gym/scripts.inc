# 1 "data//maps/RustboroCity_Gym/scripts.pory"

# 2 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts::
# 3 "data//maps/RustboroCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Gym_OnTransition
# 4 "data//maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 5 "data//maps/RustboroCity_Gym/scripts.pory"

# 6 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_OnTransition:
# 7 "data//maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 8 "data//maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 9 "data//maps/RustboroCity_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_RUSTBORO_GYM, Common_EventScript_ResetGymTrainers
# 10 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 11 "data//maps/RustboroCity_Gym/scripts.pory"

# 12 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Roxanne::
# 13 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
# 14 "data//maps/RustboroCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 15 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
# 16 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
# 17 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 18 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 19 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 20 "data//maps/RustboroCity_Gym/scripts.pory"

# 21 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated::
# 22 "data//maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 23 "data//maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 24 "data//maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 25 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 26 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 27 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 28 "data//maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 29 "data//maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 30 "data//maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 31 "data//maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 32 "data//maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 33 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 34 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 35 "data//maps/RustboroCity_Gym/scripts.pory"

# 36 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GiveRockTomb::
# 37 "data//maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB, 5
# 38 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 39 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 40 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
# 41 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 42 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 43 "data//maps/RustboroCity_Gym/scripts.pory"

# 44 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 45 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 46 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 47 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 48 "data//maps/RustboroCity_Gym/scripts.pory"

# 49 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 50 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 51 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 52 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 53 "data//maps/RustboroCity_Gym/scripts.pory"

# 54 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 55 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 56 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 57 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 58 "data//maps/RustboroCity_Gym/scripts.pory"

# 59 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 60 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 61 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 62 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 63 "data//maps/RustboroCity_Gym/scripts.pory"

# 64 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 65 "data//maps/RustboroCity_Gym/scripts.pory"
	lock
# 66 "data//maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 67 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 68 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 69 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 70 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 71 "data//maps/RustboroCity_Gym/scripts.pory"

# 72 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 73 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 74 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 75 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 76 "data//maps/RustboroCity_Gym/scripts.pory"

# 77 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 78 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 79 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 80 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 81 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 82 "data//maps/RustboroCity_Gym/scripts.pory"

# 83 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 84 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 85 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 86 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 87 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 88 "data//maps/RustboroCity_Gym/scripts.pory"

# 89 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified::
# 90 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 91 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 92 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 93 "data//maps/RustboroCity_Gym/scripts.pory"

# 94 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 95 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 96 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 97 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 98 "data//maps/RustboroCity_Gym/scripts.pory"

# 99 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 100 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 101 "data//maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 102 "data//maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 103 "data//maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 104 "data//maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 105 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 106 "data//maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 107 "data//maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 108 "data//maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 109 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 110 "data//maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 111 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 112 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 113 "data//maps/RustboroCity_Gym/scripts.pory"

# 114 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 115 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 116 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 117 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 118 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 119 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 120 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 121 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 122 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 123 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 124 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 125 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 126 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 127 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 128 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 129 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 130 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 131 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 132 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 133 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 134 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 135 "data//maps/RustboroCity_Gym/scripts.pory"

# 136 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 137 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 138 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 139 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 140 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 141 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 142 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 143 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 144 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 145 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 146 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 147 "data//maps/RustboroCity_Gym/scripts.pory"

# 148 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 149 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 150 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 151 "data//maps/RustboroCity_Gym/scripts.pory"

# 152 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 153 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 154 "data//maps/RustboroCity_Gym/scripts.pory"

# 155 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 156 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 157 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 158 "data//maps/RustboroCity_Gym/scripts.pory"

# 159 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 160 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 161 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 162 "data//maps/RustboroCity_Gym/scripts.pory"

# 163 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 164 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 165 "data//maps/RustboroCity_Gym/scripts.pory"

# 166 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 167 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 168 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 169 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 170 "data//maps/RustboroCity_Gym/scripts.pory"

# 171 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 172 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 173 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 174 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 175 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 176 "data//maps/RustboroCity_Gym/scripts.pory"

# 177 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 178 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 179 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 180 "data//maps/RustboroCity_Gym/scripts.pory"

# 181 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 182 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 183 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 184 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 185 "data//maps/RustboroCity_Gym/scripts.pory"

# 186 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 187 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 188 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 189 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 190 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 191 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 192 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 193 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 194 "data//maps/RustboroCity_Gym/scripts.pory"

# 195 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 196 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 197 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 198 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 199 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 200 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 201 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 202 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 203 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 204 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 205 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 206 "data//maps/RustboroCity_Gym/scripts.pory"

# 207 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 208 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 209 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 210 "data//maps/RustboroCity_Gym/scripts.pory"

# 211 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 212 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE heightens the ATTACK\n"
# 213 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "power of your POKéMON.\p"
# 214 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 215 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 216 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 217 "data//maps/RustboroCity_Gym/scripts.pory"

# 218 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 219 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 220 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 221 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 222 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.\p"
# 223 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 224 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a POKéMON.\p"
# 225 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Remember, a TM can be used only once,\n"
# 226 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 227 "data//maps/RustboroCity_Gym/scripts.pory"

# 228 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 229 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 230 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 231 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 232 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 233 "data//maps/RustboroCity_Gym/scripts.pory"

# 234 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 235 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 236 "data//maps/RustboroCity_Gym/scripts.pory"

# 237 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified:
# 238 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 239 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 240 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 241 "data//maps/RustboroCity_Gym/scripts.pory"

# 242 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 243 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 244 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 245 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 246 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 247 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 248 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 249 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 250 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 251 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 252 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 253 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 254 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 255 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 256 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 257 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 258 "data//maps/RustboroCity_Gym/scripts.pory"

# 259 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 260 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 261 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 262 "data//maps/RustboroCity_Gym/scripts.pory"

# 263 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 264 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 265 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 266 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 267 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 268 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 269 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 270 "data//maps/RustboroCity_Gym/scripts.pory"

# 271 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 272 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 273 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 274 "data//maps/RustboroCity_Gym/scripts.pory"

# 275 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 276 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 277 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 278 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 279 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 280 "data//maps/RustboroCity_Gym/scripts.pory"

# 281 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 282 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 283 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 284 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 285 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 286 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 287 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 288 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 289 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 290 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 291 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"
