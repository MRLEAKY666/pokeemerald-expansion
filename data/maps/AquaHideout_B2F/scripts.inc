# 1 "data//maps/AquaHideout_B2F/scripts.pory"

# 2 "data//maps/AquaHideout_B2F/scripts.pory"

# 3 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_MapScripts::
# 4 "data//maps/AquaHideout_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
# 5 "data//maps/AquaHideout_B2F/scripts.pory"
	.byte 0
# 6 "data//maps/AquaHideout_B2F/scripts.pory"

# 7 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_OnTransition:
# 8 "data//maps/AquaHideout_B2F/scripts.pory"
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
# 9 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 10 "data//maps/AquaHideout_B2F/scripts.pory"

# 11 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_PreventMattNoticing::
# 12 "data//maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data//maps/AquaHideout_B2F/scripts.pory"
	return
# 14 "data//maps/AquaHideout_B2F/scripts.pory"

# 15 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_MattNoticePlayer::
# 16 "data//maps/AquaHideout_B2F/scripts.pory"
	lockall
# 17 "data//maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
# 18 "data//maps/AquaHideout_B2F/scripts.pory"
	playse SE_PIN
# 19 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 20 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 21 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 22 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 23 "data//maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data//maps/AquaHideout_B2F/scripts.pory"
	releaseall
# 25 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 26 "data//maps/AquaHideout_B2F/scripts.pory"

# 27 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Matt::
# 28 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
# 29 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
# 30 "data//maps/AquaHideout_B2F/scripts.pory"
	release
# 31 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 32 "data//maps/AquaHideout_B2F/scripts.pory"

# 33 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_SubmarineEscape::
# 34 "data//maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
# 35 "data//maps/AquaHideout_B2F/scripts.pory"
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
# 36 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
# 37 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 38 "data//maps/AquaHideout_B2F/scripts.pory"
	delay 20
# 39 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 40 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 41 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
# 42 "data//maps/AquaHideout_B2F/scripts.pory"
	closemessage
# 43 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
# 44 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
# 45 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 46 "data//maps/AquaHideout_B2F/scripts.pory"
	removeobject VAR_0x8009
# 47 "data//maps/AquaHideout_B2F/scripts.pory"
	delay 20
# 48 "data//maps/AquaHideout_B2F/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FacePlayer
# 49 "data//maps/AquaHideout_B2F/scripts.pory"
	waitmovement 0
# 50 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
# 51 "data//maps/AquaHideout_B2F/scripts.pory"
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
# 52 "data//maps/AquaHideout_B2F/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
# 53 "data//maps/AquaHideout_B2F/scripts.pory"
	release
# 54 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 55 "data//maps/AquaHideout_B2F/scripts.pory"

# 56 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartLeft:
# 57 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 58 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 59 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 60 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 61 "data//maps/AquaHideout_B2F/scripts.pory"
	step_end
# 62 "data//maps/AquaHideout_B2F/scripts.pory"

# 63 "data//maps/AquaHideout_B2F/scripts.pory"
@ Unused
# 64 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartRight:
# 65 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 66 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 67 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 68 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 69 "data//maps/AquaHideout_B2F/scripts.pory"
	step_end
# 70 "data//maps/AquaHideout_B2F/scripts.pory"

# 71 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4::
# 72 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
# 73 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 74 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 75 "data//maps/AquaHideout_B2F/scripts.pory"

# 76 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4Defeated::
# 77 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
# 78 "data//maps/AquaHideout_B2F/scripts.pory"
	release
# 79 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 80 "data//maps/AquaHideout_B2F/scripts.pory"

# 81 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt6::
# 82 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
# 83 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
# 84 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 85 "data//maps/AquaHideout_B2F/scripts.pory"

# 86 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt8::
# 87 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
# 88 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
# 89 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 90 "data//maps/AquaHideout_B2F/scripts.pory"

# 91 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattIntro:
# 92 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe…\p"
# 93 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Got here already, did you?\n"
# 94 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "We underestimated you!\p"
# 95 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "But this is it!\p"
# 96 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm a cut above the GRUNTS you've seen\n"
# 97 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "so far.\p"
# 98 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm not stalling for time.\n"
# 99 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm going to pulverize you!$"
# 100 "data//maps/AquaHideout_B2F/scripts.pory"

# 101 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattDefeat:
# 102 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe…\n"
# 103 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "So, I lost, too…$"
# 104 "data//maps/AquaHideout_B2F/scripts.pory"

# 105 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
# 106 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!\p"
# 107 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "While I was toying with you, our BOSS\n"
# 108 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "got through his preparations!$"
# 109 "data//maps/AquaHideout_B2F/scripts.pory"

# 110 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattPostBattle:
# 111 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!\p"
# 112 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Our BOSS has already gone on his way to\n"
# 113 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "some cave under the sea!\p"
# 114 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "If you're going to give chase, you'd\n"
# 115 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "better search the big, wide sea beyond\l"
# 116 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "LILYCOVE.\p"
# 117 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "But will you find it then?\n"
# 118 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!$"
# 119 "data//maps/AquaHideout_B2F/scripts.pory"

# 120 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Intro:
# 121 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Wahahah, I grew weary of waiting!\n"
# 122 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You owe me a battle, too!$"
# 123 "data//maps/AquaHideout_B2F/scripts.pory"

# 124 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Defeat:
# 125 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Tired of waiting…\n"
# 126 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Lost and dazed…$"
# 127 "data//maps/AquaHideout_B2F/scripts.pory"

# 128 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4PostBattle:
# 129 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "BOSS…\n"
# 130 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Is this good enough?$"
# 131 "data//maps/AquaHideout_B2F/scripts.pory"

# 132 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Intro:
# 133 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Warp panels, the HIDEOUT's pride\n"
# 134 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "and joy!\p"
# 135 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You're clueless about where you are,\n"
# 136 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "aren't you?\p"
# 137 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Fluster and tire out the enemy, then\n"
# 138 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "lower the boom! That's our plan!$"
# 139 "data//maps/AquaHideout_B2F/scripts.pory"

# 140 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Defeat:
# 141 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "What's wrong with you?\n"
# 142 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You're not tired at all!$"
# 143 "data//maps/AquaHideout_B2F/scripts.pory"

# 144 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6PostBattle:
# 145 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "That reminds me… I can't remember\n"
# 146 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "where I put the MASTER BALL.\p"
# 147 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "If I fail to guard it, our BOSS will\n"
# 148 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "chew me out…$"
# 149 "data//maps/AquaHideout_B2F/scripts.pory"

# 150 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Intro:
# 151 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "When I joined TEAM AQUA, the first\n"
# 152 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "thing I had to learn was how these\l"
# 153 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "warp panels connected.$"
# 154 "data//maps/AquaHideout_B2F/scripts.pory"

# 155 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Defeat:
# 156 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I was too occupied thinking about\n"
# 157 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "the warp panels…$"
# 158 "data//maps/AquaHideout_B2F/scripts.pory"

# 159 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8PostBattle:
# 160 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'll have to learn about how I can\n"
# 161 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "battle more effectively…$"
