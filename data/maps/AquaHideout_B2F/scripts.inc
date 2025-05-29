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
	setvar VAR_WINONA_LOCATION, 1
# 54 "data//maps/AquaHideout_B2F/scripts.pory"
	release
# 55 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 56 "data//maps/AquaHideout_B2F/scripts.pory"

# 57 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartLeft:
# 58 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 59 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 60 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 61 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_left
# 62 "data//maps/AquaHideout_B2F/scripts.pory"
	step_end
# 63 "data//maps/AquaHideout_B2F/scripts.pory"

# 64 "data//maps/AquaHideout_B2F/scripts.pory"
@ Unused
# 65 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Movement_SumbarineDepartRight:
# 66 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 67 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 68 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 69 "data//maps/AquaHideout_B2F/scripts.pory"
	walk_right
# 70 "data//maps/AquaHideout_B2F/scripts.pory"
	step_end
# 71 "data//maps/AquaHideout_B2F/scripts.pory"

# 72 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4::
# 73 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
# 74 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 75 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 76 "data//maps/AquaHideout_B2F/scripts.pory"

# 77 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt4Defeated::
# 78 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
# 79 "data//maps/AquaHideout_B2F/scripts.pory"
	release
# 80 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 81 "data//maps/AquaHideout_B2F/scripts.pory"

# 82 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt6::
# 83 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
# 84 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
# 85 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 86 "data//maps/AquaHideout_B2F/scripts.pory"

# 87 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_EventScript_Grunt8::
# 88 "data//maps/AquaHideout_B2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
# 89 "data//maps/AquaHideout_B2F/scripts.pory"
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
# 90 "data//maps/AquaHideout_B2F/scripts.pory"
	end
# 91 "data//maps/AquaHideout_B2F/scripts.pory"

# 92 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattIntro:
# 93 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe…\p"
# 94 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Got here already, did you?\n"
# 95 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "We underestimated you!\p"
# 96 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "But this is it!\p"
# 97 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm a cut above the GRUNTS you've seen\n"
# 98 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "so far.\p"
# 99 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm not stalling for time.\n"
# 100 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'm going to pulverize you!$"
# 101 "data//maps/AquaHideout_B2F/scripts.pory"

# 102 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattDefeat:
# 103 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe…\n"
# 104 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "So, I lost, too…$"
# 105 "data//maps/AquaHideout_B2F/scripts.pory"

# 106 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
# 107 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!\p"
# 108 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "While I was toying with you, our BOSS\n"
# 109 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "got through his preparations!$"
# 110 "data//maps/AquaHideout_B2F/scripts.pory"

# 111 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_MattPostBattle:
# 112 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!\p"
# 113 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Our BOSS has already gone on his way to\n"
# 114 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "some cave under the sea!\p"
# 115 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "If you're going to give chase, you'd\n"
# 116 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "better search the big, wide sea beyond\l"
# 117 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "LILYCOVE.\p"
# 118 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "But will you find it then?\n"
# 119 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Hehehe!$"
# 120 "data//maps/AquaHideout_B2F/scripts.pory"

# 121 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Intro:
# 122 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Wahahah, I grew weary of waiting!\n"
# 123 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You owe me a battle, too!$"
# 124 "data//maps/AquaHideout_B2F/scripts.pory"

# 125 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4Defeat:
# 126 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Tired of waiting…\n"
# 127 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Lost and dazed…$"
# 128 "data//maps/AquaHideout_B2F/scripts.pory"

# 129 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt4PostBattle:
# 130 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "BOSS…\n"
# 131 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Is this good enough?$"
# 132 "data//maps/AquaHideout_B2F/scripts.pory"

# 133 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Intro:
# 134 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Warp panels, the HIDEOUT's pride\n"
# 135 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "and joy!\p"
# 136 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You're clueless about where you are,\n"
# 137 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "aren't you?\p"
# 138 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "Fluster and tire out the enemy, then\n"
# 139 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "lower the boom! That's our plan!$"
# 140 "data//maps/AquaHideout_B2F/scripts.pory"

# 141 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6Defeat:
# 142 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "What's wrong with you?\n"
# 143 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "You're not tired at all!$"
# 144 "data//maps/AquaHideout_B2F/scripts.pory"

# 145 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt6PostBattle:
# 146 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "That reminds me… I can't remember\n"
# 147 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "where I put the MASTER BALL.\p"
# 148 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "If I fail to guard it, our BOSS will\n"
# 149 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "chew me out…$"
# 150 "data//maps/AquaHideout_B2F/scripts.pory"

# 151 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Intro:
# 152 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "When I joined TEAM AQUA, the first\n"
# 153 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "thing I had to learn was how these\l"
# 154 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "warp panels connected.$"
# 155 "data//maps/AquaHideout_B2F/scripts.pory"

# 156 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8Defeat:
# 157 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I was too occupied thinking about\n"
# 158 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "the warp panels…$"
# 159 "data//maps/AquaHideout_B2F/scripts.pory"

# 160 "data//maps/AquaHideout_B2F/scripts.pory"
AquaHideout_B2F_Text_Grunt8PostBattle:
# 161 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "I'll have to learn about how I can\n"
# 162 "data//maps/AquaHideout_B2F/scripts.pory"
	.string "battle more effectively…$"
