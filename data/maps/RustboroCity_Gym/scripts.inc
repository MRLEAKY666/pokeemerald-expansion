# 1 "data//maps/RustboroCity_Gym/scripts.pory"

# 2 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts::
# 3 "data//maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 4 "data//maps/RustboroCity_Gym/scripts.pory"

# 5 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_OnTransition:
# 6 "data//maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 7 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 8 "data//maps/RustboroCity_Gym/scripts.pory"

# 9 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Roxanne::
# 10 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
# 11 "data//maps/RustboroCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 12 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
# 13 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
# 14 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 15 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 16 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 17 "data//maps/RustboroCity_Gym/scripts.pory"

# 18 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated::
# 19 "data//maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 20 "data//maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 21 "data//maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 22 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 23 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 24 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 25 "data//maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 26 "data//maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 27 "data//maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 28 "data//maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 29 "data//maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 30 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 31 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 32 "data//maps/RustboroCity_Gym/scripts.pory"

# 33 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GiveRockTomb::
# 34 "data//maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB
# 35 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 36 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 37 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
# 38 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 39 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 40 "data//maps/RustboroCity_Gym/scripts.pory"

# 41 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 42 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 43 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 44 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 45 "data//maps/RustboroCity_Gym/scripts.pory"

# 46 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 47 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 48 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 49 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 50 "data//maps/RustboroCity_Gym/scripts.pory"

# 51 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 52 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 53 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 54 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 55 "data//maps/RustboroCity_Gym/scripts.pory"

# 56 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 57 "data//maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 58 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 59 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 60 "data//maps/RustboroCity_Gym/scripts.pory"

# 61 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 62 "data//maps/RustboroCity_Gym/scripts.pory"
	lock
# 63 "data//maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 64 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 65 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 66 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 67 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 68 "data//maps/RustboroCity_Gym/scripts.pory"

# 69 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 70 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 71 "data//maps/RustboroCity_Gym/scripts.pory"
	release
# 72 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 73 "data//maps/RustboroCity_Gym/scripts.pory"

# 74 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 75 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 76 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 77 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 78 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 79 "data//maps/RustboroCity_Gym/scripts.pory"

# 80 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 81 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 82 "data//maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 83 "data//maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 84 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 85 "data//maps/RustboroCity_Gym/scripts.pory"

# 86 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified::
# 87 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 88 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 89 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 90 "data//maps/RustboroCity_Gym/scripts.pory"

# 91 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 92 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 93 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 94 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 95 "data//maps/RustboroCity_Gym/scripts.pory"

# 96 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 97 "data//maps/RustboroCity_Gym/scripts.pory"
	lockall
# 98 "data//maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 99 "data//maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 100 "data//maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 101 "data//maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 102 "data//maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 103 "data//maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 104 "data//maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 105 "data//maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 106 "data//maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 107 "data//maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 108 "data//maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 109 "data//maps/RustboroCity_Gym/scripts.pory"
	end
# 110 "data//maps/RustboroCity_Gym/scripts.pory"

# 111 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 112 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 113 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 114 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 115 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 116 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 117 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 118 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 119 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 120 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 121 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 122 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 123 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 124 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 125 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 126 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 127 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 128 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 129 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 130 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 131 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 132 "data//maps/RustboroCity_Gym/scripts.pory"

# 133 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 134 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 135 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 136 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 137 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 138 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 139 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 140 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 141 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 142 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 143 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 144 "data//maps/RustboroCity_Gym/scripts.pory"

# 145 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 146 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 147 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 148 "data//maps/RustboroCity_Gym/scripts.pory"

# 149 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 150 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 151 "data//maps/RustboroCity_Gym/scripts.pory"

# 152 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 153 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 154 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 155 "data//maps/RustboroCity_Gym/scripts.pory"

# 156 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 157 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 158 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 159 "data//maps/RustboroCity_Gym/scripts.pory"

# 160 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 161 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 162 "data//maps/RustboroCity_Gym/scripts.pory"

# 163 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 164 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 165 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 166 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 167 "data//maps/RustboroCity_Gym/scripts.pory"

# 168 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 169 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 170 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 171 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 172 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 173 "data//maps/RustboroCity_Gym/scripts.pory"

# 174 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 175 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 176 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 177 "data//maps/RustboroCity_Gym/scripts.pory"

# 178 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 179 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 180 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 181 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 182 "data//maps/RustboroCity_Gym/scripts.pory"

# 183 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 184 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 185 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 186 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 187 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 188 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 189 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 190 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 191 "data//maps/RustboroCity_Gym/scripts.pory"

# 192 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 193 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 194 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 195 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 196 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 197 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 198 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 199 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 200 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 201 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 202 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 203 "data//maps/RustboroCity_Gym/scripts.pory"

# 204 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 205 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 206 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 207 "data//maps/RustboroCity_Gym/scripts.pory"

# 208 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 209 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE heightens the ATTACK\n"
# 210 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "power of your POKéMON.\p"
# 211 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 212 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 213 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 214 "data//maps/RustboroCity_Gym/scripts.pory"

# 215 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 216 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 217 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 218 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 219 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.\p"
# 220 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 221 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a POKéMON.\p"
# 222 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Remember, a TM can be used only once,\n"
# 223 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 224 "data//maps/RustboroCity_Gym/scripts.pory"

# 225 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 226 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 227 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 228 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 229 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 230 "data//maps/RustboroCity_Gym/scripts.pory"

# 231 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 232 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 233 "data//maps/RustboroCity_Gym/scripts.pory"

# 234 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified:
# 235 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 236 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 237 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 238 "data//maps/RustboroCity_Gym/scripts.pory"

# 239 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 240 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 241 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 242 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 243 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 244 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 245 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 246 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 247 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 248 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 249 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 250 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 251 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 252 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 253 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 254 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 255 "data//maps/RustboroCity_Gym/scripts.pory"

# 256 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 257 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 258 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 259 "data//maps/RustboroCity_Gym/scripts.pory"

# 260 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 261 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 262 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 263 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 264 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 265 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 266 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 267 "data//maps/RustboroCity_Gym/scripts.pory"

# 268 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 269 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 270 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 271 "data//maps/RustboroCity_Gym/scripts.pory"

# 272 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 273 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 274 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 275 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 276 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 277 "data//maps/RustboroCity_Gym/scripts.pory"

# 278 "data//maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 279 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 280 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 281 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 282 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 283 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 284 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 285 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 286 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 287 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 288 "data//maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"
