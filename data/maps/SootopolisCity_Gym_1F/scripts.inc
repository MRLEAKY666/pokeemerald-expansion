# 1 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 2 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_MapScripts::
# 3 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
# 4 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
# 5 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
# 6 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
# 7 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.byte 0
# 8 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 9 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnTransition:
# 10 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_0x8008, 8
# 11 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 12 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 13 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 14 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnResume:
# 15 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
# 16 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 17 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 18 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnLoad:
# 19 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 20 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	special SetSootopolisGymCrackedIceMetatiles
# 21 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 22 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 23 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
# 24 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
# 25 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
# 26 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
# 27 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
# 28 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
# 29 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
# 30 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
# 31 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
# 32 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
# 33 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
# 34 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
# 35 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
# 36 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	return
# 37 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 38 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnFrame:
# 39 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
# 40 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
# 41 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
# 42 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
# 43 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.2byte 0
# 44 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 45 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
# 46 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 47 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 48 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 49 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 50 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 51 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 52 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 53 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
# 54 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 55 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 56 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 57 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 58 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 59 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 60 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 61 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
# 62 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 63 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 64 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 65 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 66 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 67 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 68 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 69 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_FallThroughIce::
# 70 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 71 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 20
# 72 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
# 73 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	waitmovement 0
# 74 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_FALL
# 75 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 60
# 76 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
# 77 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	waitstate
# 78 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 79 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 80 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Movement_FallThroughIce:
# 81 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	set_invisible
# 82 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	step_end
# 83 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 84 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_Juan::
# 85 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
# 86 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 87 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
# 88 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
# 89 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
# 90 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
# 91 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 92 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 93 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 94 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanDefeated::
# 95 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
# 96 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	waitmessage
# 97 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 98 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
# 99 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 100 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_BADGE08_GET
# 101 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 102 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
# 103 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_FORTREE_CLIFFS_WINONA
# 104 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 105 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
# 106 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 107 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_0x8008, 8
# 108 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 109 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
# 110 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 111 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 112 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 113 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
# 114 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	waitfanfare
# 115 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 116 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 117 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
# 118 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 119 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 120 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 121 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
# 122 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	giveitem ITEM_TM_WATER_PULSE, 5
# 123 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 124 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
# 125 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM_WATER_PULSE
# 126 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	return
# 127 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 128 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
# 129 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	giveitem ITEM_TM_WATER_PULSE, 5
# 130 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 131 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
# 132 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM_WATER_PULSE
# 133 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 134 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 135 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 136 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
# 137 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
# 138 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 139 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 140 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 141 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanRematch::
# 142 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
# 143 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
# 144 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 145 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 146 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymGuide::
# 147 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	lock
# 148 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	faceplayer
# 149 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
# 150 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 151 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 152 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 153 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 154 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
# 155 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 156 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 157 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 158 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 159 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
# 160 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 161 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
# 162 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
# 163 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 164 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 165 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_RightGymStatue::
# 166 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 167 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
# 168 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
# 169 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 170 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 171 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
# 172 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
# 173 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 174 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 175 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 176 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymStatue::
# 177 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
# 178 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 179 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 180 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 181 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymGuideAdvice:
# 182 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Yo! How's it going, CHAMPION-\n"
# 183 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "bound {PLAYER}?\p"
# 184 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "SOOTOPOLIS's GYM LEADER JUAN is\n"
# 185 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "a master of WATER-type POKéMON.\p"
# 186 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And, to get to JUAN, an icy floor\n"
# 187 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "will hamper your progress…\p"
# 188 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Listen, I'm sorry, but that's all the\n"
# 189 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "advice that I have for you.\p"
# 190 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The rest of the way, you have to\n"
# 191 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "go for it yourself!$"
# 192 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 193 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
# 194 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Yow! You've beaten even JUAN, who\n"
# 195 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "was supposedly the best in all HOENN!\p"
# 196 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Okay! Check out your TRAINER CARD.\p"
# 197 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "If you've gotten all the BADGES, you're\n"
# 198 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "set for the POKéMON LEAGUE challenge!$"
# 199 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 200 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanIntro:
# 201 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Let me ask you.\n"
# 202 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Did you know?\l"
# 203 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ah, I should not be so coy.\p"
# 204 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "It was I who taught WALLACE everything\n"
# 205 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "there is to know about POKéMON.\p"
# 206 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Once, I had given up my position as\n"
# 207 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the GYM LEADER.\p"
# 208 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "In my place, I had entrusted WALLACE\n"
# 209 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "with the GYM.\p"
# 210 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "However, a compelling reason arose for\n"
# 211 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "me to make a comeback.\p"
# 212 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ah, but enough chatter.\n"
# 213 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Let us begin our match, shall we?\p"
# 214 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Please, you shall bear witness to\n"
# 215 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "our artistry.\p"
# 216 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "A grand illusion of water sculpted\n"
# 217 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "by POKéMON and myself!$"
# 218 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 219 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
# 220 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
# 221 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
# 222 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
@ the existence of that unused array of ints.
# 223 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanDefeat:
# 224 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ahahaha, excellent!\n"
# 225 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Very well, you are the winner.\p"
# 226 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "From you, I sense the brilliant shine\n"
# 227 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of skill that will overcome all.\p"
# 228 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "However, compared with me or even\n"
# 229 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "WALLACE, you are lacking in elegance.\p"
# 230 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Perhaps I should make you a loan\n"
# 231 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of my outfit?\p"
# 232 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …\n"
# 233 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …\p"
# 234 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Hahaha, I merely jest!\p"
# 235 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Rather than my clothes, I shall reward\n"
# 236 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "you with this, the RAIN BADGE!$"
# 237 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 238 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
# 239 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "{PLAYER} received the RAIN BADGE\n"
# 240 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "from JUAN.$"
# 241 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 242 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
# 243 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The RAIN BADGE allows the use\n"
# 244 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of the HM move WATERFALL to scale\l"
# 245 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "walls of cascading water.\p"
# 246 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And, so that you never forget the\n"
# 247 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "battle we shared, take this…$"
# 248 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 249 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
# 250 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The TECHNICAL MACHINE I handed you\n"
# 251 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "contains WATER PULSE.\p"
# 252 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "In use, it will occasionally confuse\n"
# 253 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the target with ultrasonic waves.\p"
# 254 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …$"
# 255 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 256 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_RegisteredJuan:
# 257 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Registered GYM LEADER JUAN\n"
# 258 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "in the POKéNAV.$"
# 259 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 260 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPostBattle:
# 261 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The TRAINERS who have gathered all\n"
# 262 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the GYM BADGES of HOENN should make\l"
# 263 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "way to the ultimate destination.\p"
# 264 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The POKéMON LEAGUE.\p"
# 265 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Travel to the easternmost reaches\n"
# 266 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of HOENN, to the island EVER GRANDE.\p"
# 267 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "There, you shall find the POKéMON\n"
# 268 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "LEAGUE.$"
# 269 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 270 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
# 271 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "There remains but one BADGE to\n"
# 272 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "obtain in HOENN.\p"
# 273 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "If you wish to challenge the POKéMON\n"
# 274 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "LEAGUE, you must obtain the last\l"
# 275 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "BADGE from the GYM in FORTREE.$"
# 276 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 277 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymStatue:
# 278 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM$"
# 279 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 280 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymStatueCertified:
# 281 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
# 282 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "JUAN'S CERTIFIED TRAINERS:\n"
# 283 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "{PLAYER}$"
# 284 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 285 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPreRematch:
# 286 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "JUAN: Ah, this GYM had returned to its\n"
# 287 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "usual state of serenity…\p"
# 288 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "But our young typhoon has returned\n"
# 289 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to put us to the test again!\p"
# 290 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Well, my friend, most certainly!\p"
# 291 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I shall be delighted to dance with you\n"
# 292 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "as often as you wish!$"
# 293 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 294 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
# 295 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ahahaha, you are the winner!\n"
# 296 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "You have defeated me again!$"
# 297 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 298 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPostRematch:
# 299 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "JUAN: If I told you to become my\n"
# 300 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "apprentice, you will refuse, I am sure.\p"
# 301 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I would like to make a gift of my coat\n"
# 302 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to you.\p"
# 303 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "But again, you will refuse.\n"
# 304 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I imagine that to be so.\p"
# 305 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And that, my friend, is a certain sign\n"
# 306 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of nobility!$"
# 307 "data//maps/SootopolisCity_Gym_1F/scripts.pory"

# 308 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
# 309 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "JUAN: Ah, this GYM had returned to its\n"
# 310 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "usual state of serenity…\p"
# 311 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "But our young typhoon has returned\n"
# 312 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to put us to the test again!\p"
# 313 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Well, my friend, most certainly!\n"
# 314 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I shall be delighted to dance with you…\p"
# 315 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ah, no, no, no.\n"
# 316 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "You have with you but one POKéMON.\p"
# 317 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I wish that you would return with\n"
# 318 "data//maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "two, perhaps more, POKéMON, please.$"
