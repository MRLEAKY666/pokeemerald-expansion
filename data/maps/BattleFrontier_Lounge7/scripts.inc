# 1 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 2 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_MapScripts::
# 3 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.byte 0
# 4 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 5 "data//maps/BattleFrontier_Lounge7/scripts.pory"
@special ChooseMonForMoveTutor
# 6 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
# 7 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 8 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 9 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 10 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
# 11 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
# 12 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
# 13 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 14 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 15 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 16 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
# 17 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
# 18 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 19 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 20 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 21 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
# 22 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 23 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 24 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowBattlePointsWindow
# 25 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 26 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 27 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 28 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 29 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 30 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 31 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 32 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 33 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 34 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 35 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 36 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 37 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 38 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 39 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 40 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 41 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 42 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 43 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 44 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 45 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 46 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
# 47 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 48 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 49 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
# 50 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 51 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 52 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 53 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 54 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 55 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 56 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 57 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 58 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 59 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 60 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 61 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 62 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 63 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 64 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 65 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 66 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 67 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 68 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 69 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 70 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Softboiled::
# 71 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 72 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SOFT_BOILED
# 73 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 74 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 75 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 76 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SeismicToss::
# 77 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 78 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
# 79 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 80 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 81 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 82 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DreamEater::
# 83 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 84 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_DREAM_EATER
# 85 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 86 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 87 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 88 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaPunch::
# 89 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 90 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
# 91 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 92 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 93 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 94 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaKick::
# 95 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 96 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MEGA_KICK
# 97 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 98 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 99 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 100 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_BodySlam::
# 101 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 102 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_BODY_SLAM
# 103 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 104 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 105 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 106 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RockSlide::
# 107 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 108 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
# 109 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 110 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 111 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 112 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Counter::
# 113 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 114 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_COUNTER
# 115 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 116 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 117 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 118 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderWave::
# 119 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 120 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
# 121 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 122 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 123 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 124 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SwordsDance::
# 125 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 126 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
# 127 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 128 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 129 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 130 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RightMoveTutor::
# 131 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 132 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 133 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 134 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
# 135 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
# 136 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
# 137 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
# 138 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 139 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 140 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
# 141 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
# 142 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
# 143 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 144 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 145 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
# 146 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 147 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 148 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowBattlePointsWindow
# 149 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 150 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 151 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 152 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 153 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 154 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 155 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 156 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
# 157 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_Snore
# 158 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
# 159 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_Swift
# 160 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
# 161 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_Endure
# 162 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
# 163 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
# 164 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
# 165 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
# 166 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 167 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 168 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 169 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 170 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
# 171 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 172 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 173 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
# 174 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
# 175 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 176 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 177 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 178 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
# 179 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 180 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
# 181 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_Snore
# 182 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
# 183 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_Swift
# 184 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
# 185 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_Endure
# 186 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
# 187 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
# 188 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
# 189 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
# 190 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 191 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 192 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 193 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 194 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DefenseCurl::
# 195 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 196 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
# 197 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 198 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 199 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 200 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Snore::
# 201 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 202 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SNORE
# 203 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 204 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 205 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 206 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MudSlap::
# 207 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 208 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_MUD_SLAP
# 209 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 210 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 211 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 212 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Swift::
# 213 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 214 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_SWIFT
# 215 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 216 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 217 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 218 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcyWind::
# 219 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 220 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ICY_WIND
# 221 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 222 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 223 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 224 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Endure::
# 225 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 226 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ENDURE
# 227 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 228 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 229 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 230 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_PsychUp::
# 231 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 232 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_PSYCH_UP
# 233 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 234 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 235 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 236 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcePunch::
# 237 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 238 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_ICE_PUNCH
# 239 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 240 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 241 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 242 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderPunch::
# 243 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 244 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
# 245 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 246 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 247 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 248 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_FirePunch::
# 249 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 250 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
# 251 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 252 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 253 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 254 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
# 255 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 256 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 257 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 258 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 259 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 260 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 261 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_CancelChooseMon::
# 262 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 263 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 264 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 265 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 266 "data//maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_0x8008 is the price
# 267 "data//maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_C is the scroll multichoice ID
# 268 "data//maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
# 269 "data//maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
# 270 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
# 271 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special BufferBattleFrontierTutorMoveName
# 272 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8008
# 273 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
# 274 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
# 275 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 276 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
# 277 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
# 278 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
# 279 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 280 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 281 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_TeachTutorMove::
# 282 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
# 283 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	fadescreen FADE_TO_BLACK
# 284 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 285 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 286 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special ChooseMonForMoveTutor
# 287 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 288 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
# 289 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
# 290 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 291 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	special TakeFrontierBattlePoints
# 292 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 293 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 294 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 295 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewMove::
# 296 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
# 297 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
# 298 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 299 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 300 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Sailor::
# 301 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
# 302 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 303 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 304 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Gentleman::
# 305 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
# 306 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 307 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 308 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorIntro:
# 309 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 310 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You couldn't tell it from looking now,\n"
# 311 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but I used to be one tough TRAINER.\p"
# 312 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the toughest\n"
# 313 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "BEAUTY around, I tell you!\p"
# 314 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 315 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What is it now?\n"
# 316 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 317 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that blowhard woman over\n"
# 318 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually talented!\p"
# 319 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Let me prove it to you.\n"
# 320 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your POKéMON special and\l"
# 321 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute moves.\p"
# 322 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 323 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 324 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 325 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 326 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
# 327 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 328 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Are you back to learn special and\n"
# 329 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute POKéMON moves?$"
# 330 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 331 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachWhichMove:
# 332 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, look here!\n"
# 333 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Which move should I teach?$"
# 334 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 335 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
# 336 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "The move {STR_VAR_1}, is it?\n"
# 337 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"
# 338 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 339 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
# 340 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, now pick the POKéMON\n"
# 341 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I should teach the move to.$"
# 342 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 343 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
# 344 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What the…\n"
# 345 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You haven't got enough Battle Points!$"
# 346 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 347 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
# 348 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Do you see how skilled I am now?\n"
# 349 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'll take your Battle Points, thanks!$"
# 350 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 351 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_YouDontWantTo:
# 352 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's that?\n"
# 353 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't want to…\p"
# 354 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "If you want to see how skilled I am,\n"
# 355 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "you come see me anytime!$"
# 356 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 357 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorIntro:
# 358 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 359 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I know it's hard to see now, but I used\n"
# 360 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to be one fantastic TRAINER.\p"
# 361 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the most\n"
# 362 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "invincible SWIMMER around, I tell you!\p"
# 363 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 364 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's wrong?\n"
# 365 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 366 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that buffoonish woman over\n"
# 367 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually experienced!\p"
# 368 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can prove it to you.\n"
# 369 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your POKéMON hard and\l"
# 370 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty moves.\p"
# 371 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 372 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 373 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 374 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 375 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
# 376 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 377 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Have you come to learn hard and\n"
# 378 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty POKéMON moves?$"
# 379 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 380 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
# 381 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Those ladies, the way they bad-mouth\n"
# 382 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "each other, you probably think that\l"
# 383 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "they don't get along.\p"
# 384 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But if that were true, they wouldn't\n"
# 385 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "stay out here together, would they?$"
# 386 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 387 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
# 388 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "When I was just a wee YOUNGSTER,\n"
# 389 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "those ladies were strong and beautiful.\p"
# 390 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "They were idols among us TRAINERS.\p"
# 391 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Even now, age hasn't dulled their\n"
# 392 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "abilities.\p"
# 393 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "In fact, their POKéMON moves have\n"
# 394 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "grown even more polished.\p"
# 395 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But… For some reason, I can't help\n"
# 396 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but feel this…\p"
# 397 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Time is so cruel…$"
# 398 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 399 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SoftboiledDesc::
# 400 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers up to\n"
# 401 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half the user's\n"
# 402 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "maximum HP.$"
# 403 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 404 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SeismicTossDesc::
# 405 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts damage\n"
# 406 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "identical to the\n"
# 407 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's level.$"
# 408 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 409 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DreamEaterDesc::
# 410 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers half the\n"
# 411 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "damage inflicted\n"
# 412 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "on a sleeping foe.$"
# 413 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 414 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaPunchDesc::
# 415 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A strong punch\n"
# 416 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "thrown with\n"
# 417 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "incredible power.$"
# 418 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 419 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaKickDesc::
# 420 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An extremely\n"
# 421 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "powerful kick with\n"
# 422 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "intense force.$"
# 423 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 424 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_BodySlamDesc::
# 425 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A full-body slam\n"
# 426 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may cause\n"
# 427 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralysis.$"
# 428 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 429 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RockSlideDesc::
# 430 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Large boulders\n"
# 431 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "are hurled. May\n"
# 432 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause flinching.$"
# 433 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 434 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_CounterDesc::
# 435 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Retaliates any\n"
# 436 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "physical hit with\n"
# 437 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "double the power.$"
# 438 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 439 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderWaveDesc::
# 440 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A weak jolt of\n"
# 441 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "electricity that\n"
# 442 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyzes the foe.$"
# 443 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 444 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwordsDanceDesc::
# 445 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fighting dance\n"
# 446 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that sharply\n"
# 447 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raises ATTACK.$"
# 448 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 449 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DefenseCurlDesc::
# 450 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Curls up to con-\n"
# 451 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ceal weak spots\n"
# 452 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and raise DEFENSE.$"
# 453 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 454 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SnoreDesc::
# 455 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A loud attack\n"
# 456 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that can be used\n"
# 457 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "only while asleep.$"
# 458 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 459 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MudSlapDesc::
# 460 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls mud in the\n"
# 461 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's face to re-\n"
# 462 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "duce its accuracy.$"
# 463 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 464 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwiftDesc::
# 465 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sprays star-\n"
# 466 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shaped rays\n"
# 467 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that never miss.$"
# 468 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 469 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcyWindDesc::
# 470 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A chilling attack\n"
# 471 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that lowers the\n"
# 472 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's SPEED.$"
# 473 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 474 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_EndureDesc::
# 475 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Endures any at-\n"
# 476 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "tack for 1 turn,\n"
# 477 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "leaving 1HP.$"
# 478 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 479 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_PsychUpDesc::
# 480 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Copies the foe's\n"
# 481 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effect(s) and\n"
# 482 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "gives to the user.$"
# 483 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 484 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcePunchDesc::
# 485 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An icy punch\n"
# 486 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may\n"
# 487 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "freeze the foe.$"
# 488 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 489 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderPunchDesc::
# 490 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electrified\n"
# 491 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "punch that may\n"
# 492 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyze the foe.$"
# 493 "data//maps/BattleFrontier_Lounge7/scripts.pory"

# 494 "data//maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_FirePunchDesc::
# 495 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fiery punch\n"
# 496 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may burn\n"
# 497 "data//maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe.$"
