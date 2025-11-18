# 1 "data//maps/MtChimney/scripts.pory"

# 2 "data//maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 3 "data//maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 4 "data//maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 5 "data//maps/MtChimney/scripts.pory"
	.byte 0
# 6 "data//maps/MtChimney/scripts.pory"

# 7 "data//maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 8 "data//maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 9 "data//maps/MtChimney/scripts.pory"
	end
# 10 "data//maps/MtChimney/scripts.pory"

# 11 "data//maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 12 "data//maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 13 "data//maps/MtChimney/scripts.pory"
	@ setstepcallback STEP_CB_ASH
# 14 "data//maps/MtChimney/scripts.pory"
	end
# 15 "data//maps/MtChimney/scripts.pory"

# 16 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Moltres::
# 17 "data//maps/MtChimney/scripts.pory"
	@ lock
# 18 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 19 "data//maps/MtChimney/scripts.pory"
	setobjectmovementtype LOCALID_MT_CHIMNEY_MOLTRES, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN
# 20 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 21 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 22 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_CAMERA, MtChimney_Movement_CameraPanUp
# 23 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 24 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 25 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 26 "data//maps/MtChimney/scripts.pory"
	waitse
# 27 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 28 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 29 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 30 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 31 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 32 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 33 "data//maps/MtChimney/scripts.pory"
	waitstate
# 34 "data//maps/MtChimney/scripts.pory"
	waitse
# 35 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 36 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 37 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 38 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 39 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 40 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 41 "data//maps/MtChimney/scripts.pory"
	waitstate
# 42 "data//maps/MtChimney/scripts.pory"
	waitmoncry
# 43 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MOLTRES, MtChimney_Movement_MoltresFlyOff
# 44 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 45 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MOLTRES
# 46 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MoltresFlewOff, MSGBOX_DEFAULT
# 47 "data//maps/MtChimney/scripts.pory"
	closemessage
# 48 "data//maps/MtChimney/scripts.pory"
	delay 20
# 49 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 50 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_CAMERA, MtChimney_Movement_CameraPanDown
# 51 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 52 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 53 "data//maps/MtChimney/scripts.pory"
	setvar VAR_UNUSED_0x8014, 3
# 54 "data//maps/MtChimney/scripts.pory"
	@ goto_if_set FLAG_MET_MOLTRES, MtChimney_EventScript_ReAwakenMoltres
# 55 "data//maps/MtChimney/scripts.pory"
	special InitRoamer
# 56 "data//maps/MtChimney/scripts.pory"
	setseenmon SPECIES_MOLTRES
# 57 "data//maps/MtChimney/scripts.pory"
	@ setflag FLAG_MET_MOLTRES
# 58 "data//maps/MtChimney/scripts.pory"
	releaseall
# 59 "data//maps/MtChimney/scripts.pory"
	end
# 60 "data//maps/MtChimney/scripts.pory"

# 61 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ReAwakenMoltres::
# 62 "data//maps/MtChimney/scripts.pory"
	special ActivateRoamer
# 63 "data//maps/MtChimney/scripts.pory"
	releaseall
# 64 "data//maps/MtChimney/scripts.pory"
	end
# 65 "data//maps/MtChimney/scripts.pory"

# 66 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 67 "data//maps/MtChimney/scripts.pory"
	lock
# 68 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 69 "data//maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 70 "data//maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 71 "data//maps/MtChimney/scripts.pory"
	closemessage
# 72 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
# 73 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 74 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 75 "data//maps/MtChimney/scripts.pory"
	release
# 76 "data//maps/MtChimney/scripts.pory"
	end
# 77 "data//maps/MtChimney/scripts.pory"

# 78 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 79 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 80 "data//maps/MtChimney/scripts.pory"
	return
# 81 "data//maps/MtChimney/scripts.pory"

# 82 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 83 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 84 "data//maps/MtChimney/scripts.pory"
	return
# 85 "data//maps/MtChimney/scripts.pory"

# 86 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 87 "data//maps/MtChimney/scripts.pory"
	lockall
# 88 "data//maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 89 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 90 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
# 91 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 92 "data//maps/MtChimney/scripts.pory"
	playse SE_PIN
# 93 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
# 94 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 95 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
# 96 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 97 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 98 "data//maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 99 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 100 "data//maps/MtChimney/scripts.pory"
	closemessage
# 101 "data//maps/MtChimney/scripts.pory"
	delay 30
# 102 "data//maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 103 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAXIE
# 104 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
# 105 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_TABITHA
# 106 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
# 107 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 108 "data//maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 109 "data//maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 33
# 110 "data//maps/MtChimney/scripts.pory"
	addobject LOCALID_MT_CHIMNEY_ARCHIE
# 111 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 112 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 113 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 114 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 115 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 116 "data//maps/MtChimney/scripts.pory"
	closemessage
# 117 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 118 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 119 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
# 120 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 121 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 122 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 123 "data//maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 124 "data//maps/MtChimney/scripts.pory"
	releaseall
# 125 "data//maps/MtChimney/scripts.pory"
	end
# 126 "data//maps/MtChimney/scripts.pory"

# 127 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 128 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 129 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 130 "data//maps/MtChimney/scripts.pory"
	return
# 131 "data//maps/MtChimney/scripts.pory"

# 132 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 133 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 134 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 135 "data//maps/MtChimney/scripts.pory"
	return
# 136 "data//maps/MtChimney/scripts.pory"

# 137 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 138 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
# 139 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 140 "data//maps/MtChimney/scripts.pory"
	return
# 141 "data//maps/MtChimney/scripts.pory"

# 142 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 143 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 144 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 145 "data//maps/MtChimney/scripts.pory"
	return
# 146 "data//maps/MtChimney/scripts.pory"

# 147 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 148 "data//maps/MtChimney/scripts.pory"
	lock
# 149 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 150 "data//maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 151 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 152 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 153 "data//maps/MtChimney/scripts.pory"
	checkmoney 200
# 154 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 155 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 156 "data//maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 157 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 158 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 159 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 160 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 161 "data//maps/MtChimney/scripts.pory"
	release
# 162 "data//maps/MtChimney/scripts.pory"
	end
# 163 "data//maps/MtChimney/scripts.pory"

# 164 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 165 "data//maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 166 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 167 "data//maps/MtChimney/scripts.pory"
	release
# 168 "data//maps/MtChimney/scripts.pory"
	end
# 169 "data//maps/MtChimney/scripts.pory"

# 170 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 171 "data//maps/MtChimney/scripts.pory"
	removemoney 200
# 172 "data//maps/MtChimney/scripts.pory"
	updatemoneybox
# 173 "data//maps/MtChimney/scripts.pory"
	return
# 174 "data//maps/MtChimney/scripts.pory"

# 175 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 176 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 177 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 178 "data//maps/MtChimney/scripts.pory"
	release
# 179 "data//maps/MtChimney/scripts.pory"
	end
# 180 "data//maps/MtChimney/scripts.pory"

# 181 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 182 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 183 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 184 "data//maps/MtChimney/scripts.pory"
	release
# 185 "data//maps/MtChimney/scripts.pory"
	end
# 186 "data//maps/MtChimney/scripts.pory"

# 187 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_MoltresFlyOff:
# 188 "data//maps/MtChimney/scripts.pory"
	delay_16
# 189 "data//maps/MtChimney/scripts.pory"
	slide_up
# 190 "data//maps/MtChimney/scripts.pory"
	slide_up
# 191 "data//maps/MtChimney/scripts.pory"
	slide_up
# 192 "data//maps/MtChimney/scripts.pory"
	slide_up
# 193 "data//maps/MtChimney/scripts.pory"
	slide_up
# 194 "data//maps/MtChimney/scripts.pory"
	slide_up
# 195 "data//maps/MtChimney/scripts.pory"
	step_end
# 196 "data//maps/MtChimney/scripts.pory"

# 197 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanUp:
# 198 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 199 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 200 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 201 "data//maps/MtChimney/scripts.pory"
	step_end
# 202 "data//maps/MtChimney/scripts.pory"

# 203 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanDown:
# 204 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 205 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 206 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 207 "data//maps/MtChimney/scripts.pory"
	step_end
# 208 "data//maps/MtChimney/scripts.pory"

# 209 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 210 "data//maps/MtChimney/scripts.pory"
	walk_up
# 211 "data//maps/MtChimney/scripts.pory"
	walk_up
# 212 "data//maps/MtChimney/scripts.pory"
	walk_up
# 213 "data//maps/MtChimney/scripts.pory"
	walk_up
# 214 "data//maps/MtChimney/scripts.pory"
	walk_up
# 215 "data//maps/MtChimney/scripts.pory"
	walk_up
# 216 "data//maps/MtChimney/scripts.pory"
	walk_right
# 217 "data//maps/MtChimney/scripts.pory"
	step_end
# 218 "data//maps/MtChimney/scripts.pory"

# 219 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 220 "data//maps/MtChimney/scripts.pory"
	walk_left
# 221 "data//maps/MtChimney/scripts.pory"
	walk_down
# 222 "data//maps/MtChimney/scripts.pory"
	walk_down
# 223 "data//maps/MtChimney/scripts.pory"
	walk_down
# 224 "data//maps/MtChimney/scripts.pory"
	walk_down
# 225 "data//maps/MtChimney/scripts.pory"
	walk_down
# 226 "data//maps/MtChimney/scripts.pory"
	walk_down
# 227 "data//maps/MtChimney/scripts.pory"
	walk_down
# 228 "data//maps/MtChimney/scripts.pory"
	step_end
# 229 "data//maps/MtChimney/scripts.pory"

# 230 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 231 "data//maps/MtChimney/scripts.pory"
	walk_up
# 232 "data//maps/MtChimney/scripts.pory"
	walk_up
# 233 "data//maps/MtChimney/scripts.pory"
	walk_up
# 234 "data//maps/MtChimney/scripts.pory"
	walk_up
# 235 "data//maps/MtChimney/scripts.pory"
	walk_up
# 236 "data//maps/MtChimney/scripts.pory"
	walk_right
# 237 "data//maps/MtChimney/scripts.pory"
	walk_right
# 238 "data//maps/MtChimney/scripts.pory"
	step_end
# 239 "data//maps/MtChimney/scripts.pory"

# 240 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 241 "data//maps/MtChimney/scripts.pory"
	walk_left
# 242 "data//maps/MtChimney/scripts.pory"
	walk_left
# 243 "data//maps/MtChimney/scripts.pory"
	walk_down
# 244 "data//maps/MtChimney/scripts.pory"
	walk_down
# 245 "data//maps/MtChimney/scripts.pory"
	walk_down
# 246 "data//maps/MtChimney/scripts.pory"
	walk_down
# 247 "data//maps/MtChimney/scripts.pory"
	walk_down
# 248 "data//maps/MtChimney/scripts.pory"
	walk_down
# 249 "data//maps/MtChimney/scripts.pory"
	walk_down
# 250 "data//maps/MtChimney/scripts.pory"
	step_end
# 251 "data//maps/MtChimney/scripts.pory"

# 252 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 253 "data//maps/MtChimney/scripts.pory"
	walk_down
# 254 "data//maps/MtChimney/scripts.pory"
	walk_down
# 255 "data//maps/MtChimney/scripts.pory"
	walk_down
# 256 "data//maps/MtChimney/scripts.pory"
	walk_down
# 257 "data//maps/MtChimney/scripts.pory"
	walk_down
# 258 "data//maps/MtChimney/scripts.pory"
	walk_left
# 259 "data//maps/MtChimney/scripts.pory"
	walk_left
# 260 "data//maps/MtChimney/scripts.pory"
	walk_down
# 261 "data//maps/MtChimney/scripts.pory"
	walk_down
# 262 "data//maps/MtChimney/scripts.pory"
	walk_down
# 263 "data//maps/MtChimney/scripts.pory"
	walk_down
# 264 "data//maps/MtChimney/scripts.pory"
	walk_left
# 265 "data//maps/MtChimney/scripts.pory"
	walk_left
# 266 "data//maps/MtChimney/scripts.pory"
	walk_left
# 267 "data//maps/MtChimney/scripts.pory"
	walk_left
# 268 "data//maps/MtChimney/scripts.pory"
	walk_left
# 269 "data//maps/MtChimney/scripts.pory"
	walk_down
# 270 "data//maps/MtChimney/scripts.pory"
	step_end
# 271 "data//maps/MtChimney/scripts.pory"

# 272 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 273 "data//maps/MtChimney/scripts.pory"
	walk_down
# 274 "data//maps/MtChimney/scripts.pory"
	walk_down
# 275 "data//maps/MtChimney/scripts.pory"
	walk_down
# 276 "data//maps/MtChimney/scripts.pory"
	walk_down
# 277 "data//maps/MtChimney/scripts.pory"
	walk_left
# 278 "data//maps/MtChimney/scripts.pory"
	walk_left
# 279 "data//maps/MtChimney/scripts.pory"
	walk_left
# 280 "data//maps/MtChimney/scripts.pory"
	walk_down
# 281 "data//maps/MtChimney/scripts.pory"
	step_end
# 282 "data//maps/MtChimney/scripts.pory"

# 283 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 284 "data//maps/MtChimney/scripts.pory"
	walk_right
# 285 "data//maps/MtChimney/scripts.pory"
	walk_down
# 286 "data//maps/MtChimney/scripts.pory"
	walk_down
# 287 "data//maps/MtChimney/scripts.pory"
	walk_down
# 288 "data//maps/MtChimney/scripts.pory"
	walk_down
# 289 "data//maps/MtChimney/scripts.pory"
	walk_left
# 290 "data//maps/MtChimney/scripts.pory"
	walk_left
# 291 "data//maps/MtChimney/scripts.pory"
	walk_left
# 292 "data//maps/MtChimney/scripts.pory"
	walk_left
# 293 "data//maps/MtChimney/scripts.pory"
	walk_left
# 294 "data//maps/MtChimney/scripts.pory"
	walk_down
# 295 "data//maps/MtChimney/scripts.pory"
	walk_down
# 296 "data//maps/MtChimney/scripts.pory"
	walk_down
# 297 "data//maps/MtChimney/scripts.pory"
	walk_down
# 298 "data//maps/MtChimney/scripts.pory"
	step_end
# 299 "data//maps/MtChimney/scripts.pory"

# 300 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 301 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 302 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 303 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 304 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 305 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 306 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 307 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 308 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 309 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 310 "data//maps/MtChimney/scripts.pory"
	walk_left
# 311 "data//maps/MtChimney/scripts.pory"
	walk_left
# 312 "data//maps/MtChimney/scripts.pory"
	walk_down
# 313 "data//maps/MtChimney/scripts.pory"
	walk_down
# 314 "data//maps/MtChimney/scripts.pory"
	walk_down
# 315 "data//maps/MtChimney/scripts.pory"
	walk_left
# 316 "data//maps/MtChimney/scripts.pory"
	walk_left
# 317 "data//maps/MtChimney/scripts.pory"
	walk_down
# 318 "data//maps/MtChimney/scripts.pory"
	walk_down
# 319 "data//maps/MtChimney/scripts.pory"
	walk_left
# 320 "data//maps/MtChimney/scripts.pory"
	walk_left
# 321 "data//maps/MtChimney/scripts.pory"
	walk_left
# 322 "data//maps/MtChimney/scripts.pory"
	walk_left
# 323 "data//maps/MtChimney/scripts.pory"
	walk_left
# 324 "data//maps/MtChimney/scripts.pory"
	walk_down
# 325 "data//maps/MtChimney/scripts.pory"
	step_end
# 326 "data//maps/MtChimney/scripts.pory"

# 327 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 328 "data//maps/MtChimney/scripts.pory"
	delay_16
# 329 "data//maps/MtChimney/scripts.pory"
	delay_16
# 330 "data//maps/MtChimney/scripts.pory"
	delay_16
# 331 "data//maps/MtChimney/scripts.pory"
	walk_down
# 332 "data//maps/MtChimney/scripts.pory"
	walk_down
# 333 "data//maps/MtChimney/scripts.pory"
	walk_down
# 334 "data//maps/MtChimney/scripts.pory"
	walk_left
# 335 "data//maps/MtChimney/scripts.pory"
	walk_left
# 336 "data//maps/MtChimney/scripts.pory"
	walk_left
# 337 "data//maps/MtChimney/scripts.pory"
	walk_down
# 338 "data//maps/MtChimney/scripts.pory"
	step_end
# 339 "data//maps/MtChimney/scripts.pory"

# 340 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 341 "data//maps/MtChimney/scripts.pory"
	delay_16
# 342 "data//maps/MtChimney/scripts.pory"
	walk_left
# 343 "data//maps/MtChimney/scripts.pory"
	walk_down
# 344 "data//maps/MtChimney/scripts.pory"
	walk_down
# 345 "data//maps/MtChimney/scripts.pory"
	walk_down
# 346 "data//maps/MtChimney/scripts.pory"
	walk_down
# 347 "data//maps/MtChimney/scripts.pory"
	walk_left
# 348 "data//maps/MtChimney/scripts.pory"
	walk_left
# 349 "data//maps/MtChimney/scripts.pory"
	walk_left
# 350 "data//maps/MtChimney/scripts.pory"
	walk_left
# 351 "data//maps/MtChimney/scripts.pory"
	walk_left
# 352 "data//maps/MtChimney/scripts.pory"
	walk_down
# 353 "data//maps/MtChimney/scripts.pory"
	walk_down
# 354 "data//maps/MtChimney/scripts.pory"
	walk_down
# 355 "data//maps/MtChimney/scripts.pory"
	walk_down
# 356 "data//maps/MtChimney/scripts.pory"
	step_end
# 357 "data//maps/MtChimney/scripts.pory"

# 358 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 359 "data//maps/MtChimney/scripts.pory"
	delay_16
# 360 "data//maps/MtChimney/scripts.pory"
	walk_left
# 361 "data//maps/MtChimney/scripts.pory"
	walk_left
# 362 "data//maps/MtChimney/scripts.pory"
	walk_down
# 363 "data//maps/MtChimney/scripts.pory"
	walk_down
# 364 "data//maps/MtChimney/scripts.pory"
	walk_down
# 365 "data//maps/MtChimney/scripts.pory"
	walk_left
# 366 "data//maps/MtChimney/scripts.pory"
	walk_left
# 367 "data//maps/MtChimney/scripts.pory"
	walk_down
# 368 "data//maps/MtChimney/scripts.pory"
	walk_down
# 369 "data//maps/MtChimney/scripts.pory"
	walk_left
# 370 "data//maps/MtChimney/scripts.pory"
	walk_left
# 371 "data//maps/MtChimney/scripts.pory"
	walk_left
# 372 "data//maps/MtChimney/scripts.pory"
	walk_left
# 373 "data//maps/MtChimney/scripts.pory"
	walk_left
# 374 "data//maps/MtChimney/scripts.pory"
	walk_down
# 375 "data//maps/MtChimney/scripts.pory"
	step_end
# 376 "data//maps/MtChimney/scripts.pory"

# 377 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 378 "data//maps/MtChimney/scripts.pory"
	delay_16
# 379 "data//maps/MtChimney/scripts.pory"
	walk_down
# 380 "data//maps/MtChimney/scripts.pory"
	walk_left
# 381 "data//maps/MtChimney/scripts.pory"
	walk_left
# 382 "data//maps/MtChimney/scripts.pory"
	walk_left
# 383 "data//maps/MtChimney/scripts.pory"
	walk_left
# 384 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 385 "data//maps/MtChimney/scripts.pory"
	step_end
# 386 "data//maps/MtChimney/scripts.pory"

# 387 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 388 "data//maps/MtChimney/scripts.pory"
	walk_down
# 389 "data//maps/MtChimney/scripts.pory"
	walk_down
# 390 "data//maps/MtChimney/scripts.pory"
	walk_down
# 391 "data//maps/MtChimney/scripts.pory"
	walk_down
# 392 "data//maps/MtChimney/scripts.pory"
	walk_left
# 393 "data//maps/MtChimney/scripts.pory"
	walk_left
# 394 "data//maps/MtChimney/scripts.pory"
	walk_left
# 395 "data//maps/MtChimney/scripts.pory"
	walk_left
# 396 "data//maps/MtChimney/scripts.pory"
	walk_left
# 397 "data//maps/MtChimney/scripts.pory"
	walk_down
# 398 "data//maps/MtChimney/scripts.pory"
	walk_down
# 399 "data//maps/MtChimney/scripts.pory"
	walk_down
# 400 "data//maps/MtChimney/scripts.pory"
	walk_down
# 401 "data//maps/MtChimney/scripts.pory"
	step_end
# 402 "data//maps/MtChimney/scripts.pory"

# 403 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 404 "data//maps/MtChimney/scripts.pory"
	walk_down
# 405 "data//maps/MtChimney/scripts.pory"
	step_end
# 406 "data//maps/MtChimney/scripts.pory"

# 407 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 408 "data//maps/MtChimney/scripts.pory"
	walk_down
# 409 "data//maps/MtChimney/scripts.pory"
	walk_down
# 410 "data//maps/MtChimney/scripts.pory"
	walk_down
# 411 "data//maps/MtChimney/scripts.pory"
	walk_down
# 412 "data//maps/MtChimney/scripts.pory"
	walk_down
# 413 "data//maps/MtChimney/scripts.pory"
	walk_down
# 414 "data//maps/MtChimney/scripts.pory"
	walk_down
# 415 "data//maps/MtChimney/scripts.pory"
	step_end
# 416 "data//maps/MtChimney/scripts.pory"

# 417 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 418 "data//maps/MtChimney/scripts.pory"
	delay_16
# 419 "data//maps/MtChimney/scripts.pory"
	delay_16
# 420 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 421 "data//maps/MtChimney/scripts.pory"
	delay_16
# 422 "data//maps/MtChimney/scripts.pory"
	walk_down
# 423 "data//maps/MtChimney/scripts.pory"
	walk_down
# 424 "data//maps/MtChimney/scripts.pory"
	walk_down
# 425 "data//maps/MtChimney/scripts.pory"
	walk_down
# 426 "data//maps/MtChimney/scripts.pory"
	walk_down
# 427 "data//maps/MtChimney/scripts.pory"
	step_end
# 428 "data//maps/MtChimney/scripts.pory"

# 429 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 430 "data//maps/MtChimney/scripts.pory"
	delay_16
# 431 "data//maps/MtChimney/scripts.pory"
	delay_16
# 432 "data//maps/MtChimney/scripts.pory"
	delay_16
# 433 "data//maps/MtChimney/scripts.pory"
	delay_16
# 434 "data//maps/MtChimney/scripts.pory"
	delay_16
# 435 "data//maps/MtChimney/scripts.pory"
	delay_16
# 436 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 437 "data//maps/MtChimney/scripts.pory"
	delay_16
# 438 "data//maps/MtChimney/scripts.pory"
	walk_down
# 439 "data//maps/MtChimney/scripts.pory"
	walk_down
# 440 "data//maps/MtChimney/scripts.pory"
	step_end
# 441 "data//maps/MtChimney/scripts.pory"

# 442 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 443 "data//maps/MtChimney/scripts.pory"
	lock_facing_direction
# 444 "data//maps/MtChimney/scripts.pory"
	walk_fast_left
# 445 "data//maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 446 "data//maps/MtChimney/scripts.pory"
	face_right
# 447 "data//maps/MtChimney/scripts.pory"
	step_end
# 448 "data//maps/MtChimney/scripts.pory"

# 449 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 450 "data//maps/MtChimney/scripts.pory"
	walk_left
# 451 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 452 "data//maps/MtChimney/scripts.pory"
	delay_16
# 453 "data//maps/MtChimney/scripts.pory"
	step_end
# 454 "data//maps/MtChimney/scripts.pory"

# 455 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 456 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 457 "data//maps/MtChimney/scripts.pory"
	end
# 458 "data//maps/MtChimney/scripts.pory"

# 459 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 460 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 461 "data//maps/MtChimney/scripts.pory"
	end
# 462 "data//maps/MtChimney/scripts.pory"

# 463 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 464 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 465 "data//maps/MtChimney/scripts.pory"
	end
# 466 "data//maps/MtChimney/scripts.pory"

# 467 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 468 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 469 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 470 "data//maps/MtChimney/scripts.pory"
	end
# 471 "data//maps/MtChimney/scripts.pory"

# 472 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 473 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 474 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 475 "data//maps/MtChimney/scripts.pory"
	end
# 476 "data//maps/MtChimney/scripts.pory"

# 477 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 478 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 479 "data//maps/MtChimney/scripts.pory"
	end
# 480 "data//maps/MtChimney/scripts.pory"

# 481 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 482 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 483 "data//maps/MtChimney/scripts.pory"
	end
# 484 "data//maps/MtChimney/scripts.pory"

# 485 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 486 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 487 "data//maps/MtChimney/scripts.pory"
	end
# 488 "data//maps/MtChimney/scripts.pory"

# 489 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 490 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 491 "data//maps/MtChimney/scripts.pory"
	end
# 492 "data//maps/MtChimney/scripts.pory"

# 493 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 494 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 495 "data//maps/MtChimney/scripts.pory"
	end
# 496 "data//maps/MtChimney/scripts.pory"

# 497 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 498 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 499 "data//maps/MtChimney/scripts.pory"
	end
# 500 "data//maps/MtChimney/scripts.pory"

# 501 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 502 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 503 "data//maps/MtChimney/scripts.pory"
	end
# 504 "data//maps/MtChimney/scripts.pory"

# 505 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 506 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 507 "data//maps/MtChimney/scripts.pory"
	end
# 508 "data//maps/MtChimney/scripts.pory"

# 509 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 510 "data//maps/MtChimney/scripts.pory"
	lockall
# 511 "data//maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 512 "data//maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 513 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 514 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 515 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 516 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 517 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 518 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 519 "data//maps/MtChimney/scripts.pory"
	releaseall
# 520 "data//maps/MtChimney/scripts.pory"
	end
# 521 "data//maps/MtChimney/scripts.pory"

# 522 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 523 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 524 "data//maps/MtChimney/scripts.pory"
	releaseall
# 525 "data//maps/MtChimney/scripts.pory"
	end
# 526 "data//maps/MtChimney/scripts.pory"

# 527 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 528 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 529 "data//maps/MtChimney/scripts.pory"
	releaseall
# 530 "data//maps/MtChimney/scripts.pory"
	end
# 531 "data//maps/MtChimney/scripts.pory"

# 532 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 533 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 534 "data//maps/MtChimney/scripts.pory"
	releaseall
# 535 "data//maps/MtChimney/scripts.pory"
	end
# 536 "data//maps/MtChimney/scripts.pory"

# 537 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 538 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 539 "data//maps/MtChimney/scripts.pory"
	end
# 540 "data//maps/MtChimney/scripts.pory"

# 541 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 542 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 543 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 544 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 545 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 546 "data//maps/MtChimney/scripts.pory"
	release
# 547 "data//maps/MtChimney/scripts.pory"
	end
# 548 "data//maps/MtChimney/scripts.pory"

# 549 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 550 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 551 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 552 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 553 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 554 "data//maps/MtChimney/scripts.pory"
	release
# 555 "data//maps/MtChimney/scripts.pory"
	end
# 556 "data//maps/MtChimney/scripts.pory"

# 557 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 558 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 559 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 560 "data//maps/MtChimney/scripts.pory"
	end
# 561 "data//maps/MtChimney/scripts.pory"

# 562 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 563 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 564 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 565 "data//maps/MtChimney/scripts.pory"
	end
# 566 "data//maps/MtChimney/scripts.pory"

# 567 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 568 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 569 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 570 "data//maps/MtChimney/scripts.pory"
	end
# 571 "data//maps/MtChimney/scripts.pory"

# 572 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 573 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 574 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 575 "data//maps/MtChimney/scripts.pory"
	end
# 576 "data//maps/MtChimney/scripts.pory"

# 577 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 578 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 579 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 580 "data//maps/MtChimney/scripts.pory"
	end
# 581 "data//maps/MtChimney/scripts.pory"

# 582 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 583 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 584 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 585 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 586 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 587 "data//maps/MtChimney/scripts.pory"
	release
# 588 "data//maps/MtChimney/scripts.pory"
	end
# 589 "data//maps/MtChimney/scripts.pory"

# 590 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 591 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 592 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 593 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 594 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 595 "data//maps/MtChimney/scripts.pory"
	release
# 596 "data//maps/MtChimney/scripts.pory"
	end
# 597 "data//maps/MtChimney/scripts.pory"

# 598 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 599 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 600 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 601 "data//maps/MtChimney/scripts.pory"
	end
# 602 "data//maps/MtChimney/scripts.pory"

# 603 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MoltresFlewOff:
# 604 "data//maps/MtChimney/scripts.pory"
	.string "MOLTRES woke up and flew\n"
# 605 "data//maps/MtChimney/scripts.pory"
	.string "off somewhere . . .$"
# 606 "data//maps/MtChimney/scripts.pory"

# 607 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 608 "data//maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 609 "data//maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 610 "data//maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 611 "data//maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 612 "data//maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 613 "data//maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 614 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 615 "data//maps/MtChimney/scripts.pory"

# 616 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 617 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 618 "data//maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 619 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 620 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 621 "data//maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 622 "data//maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 623 "data//maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 624 "data//maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 625 "data//maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 626 "data//maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 627 "data//maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 628 "data//maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 629 "data//maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 630 "data//maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 631 "data//maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 632 "data//maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 633 "data//maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 634 "data//maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 635 "data//maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 636 "data//maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 637 "data//maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 638 "data//maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 639 "data//maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 640 "data//maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 641 "data//maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 642 "data//maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 643 "data//maps/MtChimney/scripts.pory"

# 644 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 645 "data//maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 646 "data//maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 647 "data//maps/MtChimney/scripts.pory"

# 648 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 649 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 650 "data//maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 651 "data//maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 652 "data//maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 653 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 654 "data//maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 655 "data//maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 656 "data//maps/MtChimney/scripts.pory"

# 657 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 658 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 659 "data//maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 660 "data//maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 661 "data//maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 662 "data//maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 663 "data//maps/MtChimney/scripts.pory"

# 664 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 665 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 666 "data//maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 667 "data//maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 668 "data//maps/MtChimney/scripts.pory"

# 669 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 670 "data//maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 671 "data//maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 672 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 673 "data//maps/MtChimney/scripts.pory"

# 674 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 675 "data//maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 676 "data//maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 677 "data//maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 678 "data//maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 679 "data//maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 680 "data//maps/MtChimney/scripts.pory"

# 681 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 682 "data//maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 683 "data//maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 684 "data//maps/MtChimney/scripts.pory"

# 685 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 686 "data//maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 687 "data//maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 688 "data//maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 689 "data//maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 690 "data//maps/MtChimney/scripts.pory"

# 691 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 692 "data//maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 693 "data//maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 694 "data//maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 695 "data//maps/MtChimney/scripts.pory"

# 696 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 697 "data//maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 698 "data//maps/MtChimney/scripts.pory"

# 699 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 700 "data//maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 701 "data//maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 702 "data//maps/MtChimney/scripts.pory"

# 703 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 704 "data//maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 705 "data//maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 706 "data//maps/MtChimney/scripts.pory"

# 707 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 708 "data//maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 709 "data//maps/MtChimney/scripts.pory"

# 710 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 711 "data//maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 712 "data//maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 713 "data//maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 714 "data//maps/MtChimney/scripts.pory"

# 715 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 716 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 717 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 718 "data//maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 719 "data//maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 720 "data//maps/MtChimney/scripts.pory"

# 721 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 722 "data//maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 723 "data//maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 724 "data//maps/MtChimney/scripts.pory"

# 725 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 726 "data//maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 727 "data//maps/MtChimney/scripts.pory"

# 728 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 729 "data//maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 730 "data//maps/MtChimney/scripts.pory"

# 731 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 732 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 733 "data//maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 734 "data//maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 735 "data//maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 736 "data//maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 737 "data//maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 738 "data//maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 739 "data//maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 740 "data//maps/MtChimney/scripts.pory"

# 741 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 742 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 743 "data//maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 744 "data//maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 745 "data//maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 746 "data//maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 747 "data//maps/MtChimney/scripts.pory"

# 748 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 749 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 750 "data//maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 751 "data//maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 752 "data//maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 753 "data//maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 754 "data//maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 755 "data//maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 756 "data//maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 757 "data//maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 758 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 759 "data//maps/MtChimney/scripts.pory"

# 760 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 761 "data//maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 762 "data//maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 763 "data//maps/MtChimney/scripts.pory"

# 764 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 765 "data//maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 766 "data//maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 767 "data//maps/MtChimney/scripts.pory"

# 768 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 769 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 770 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 771 "data//maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 772 "data//maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 773 "data//maps/MtChimney/scripts.pory"

# 774 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 775 "data//maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 776 "data//maps/MtChimney/scripts.pory"

# 777 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 778 "data//maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 779 "data//maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 780 "data//maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 781 "data//maps/MtChimney/scripts.pory"

# 782 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 783 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 784 "data//maps/MtChimney/scripts.pory"

# 785 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 786 "data//maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 787 "data//maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 788 "data//maps/MtChimney/scripts.pory"

# 789 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 790 "data//maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 791 "data//maps/MtChimney/scripts.pory"

# 792 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 793 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 794 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 795 "data//maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 796 "data//maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 797 "data//maps/MtChimney/scripts.pory"

# 798 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 799 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 800 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 801 "data//maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 802 "data//maps/MtChimney/scripts.pory"

# 803 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 804 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 805 "data//maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 806 "data//maps/MtChimney/scripts.pory"

# 807 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 808 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 809 "data//maps/MtChimney/scripts.pory"
	.string "it was.$"
# 810 "data//maps/MtChimney/scripts.pory"

# 811 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 812 "data//maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 813 "data//maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 814 "data//maps/MtChimney/scripts.pory"

# 815 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 816 "data//maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 817 "data//maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 818 "data//maps/MtChimney/scripts.pory"

# 819 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 820 "data//maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 821 "data//maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 822 "data//maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 823 "data//maps/MtChimney/scripts.pory"

# 824 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 825 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 826 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 827 "data//maps/MtChimney/scripts.pory"

# 828 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 829 "data//maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 830 "data//maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 831 "data//maps/MtChimney/scripts.pory"

# 832 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 833 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 834 "data//maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 835 "data//maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 836 "data//maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 837 "data//maps/MtChimney/scripts.pory"

# 838 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 839 "data//maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 840 "data//maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 841 "data//maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 842 "data//maps/MtChimney/scripts.pory"

# 843 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 844 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 845 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 846 "data//maps/MtChimney/scripts.pory"

# 847 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 848 "data//maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 849 "data//maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 850 "data//maps/MtChimney/scripts.pory"

# 851 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 852 "data//maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 853 "data//maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 854 "data//maps/MtChimney/scripts.pory"

# 855 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 856 "data//maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 857 "data//maps/MtChimney/scripts.pory"

# 858 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 859 "data//maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 860 "data//maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 861 "data//maps/MtChimney/scripts.pory"

# 862 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 863 "data//maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 864 "data//maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 865 "data//maps/MtChimney/scripts.pory"

# 866 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 867 "data//maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 868 "data//maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 869 "data//maps/MtChimney/scripts.pory"

# 870 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 871 "data//maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 872 "data//maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 873 "data//maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 874 "data//maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 875 "data//maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 876 "data//maps/MtChimney/scripts.pory"

# 877 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 878 "data//maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 879 "data//maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 880 "data//maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 881 "data//maps/MtChimney/scripts.pory"

# 882 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 883 "data//maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 884 "data//maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 885 "data//maps/MtChimney/scripts.pory"

# 886 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 887 "data//maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 888 "data//maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 889 "data//maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 890 "data//maps/MtChimney/scripts.pory"

# 891 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 892 "data//maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 893 "data//maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 894 "data//maps/MtChimney/scripts.pory"

# 895 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 896 "data//maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 897 "data//maps/MtChimney/scripts.pory"

# 898 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 899 "data//maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 900 "data//maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 901 "data//maps/MtChimney/scripts.pory"

# 902 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 903 "data//maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 904 "data//maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 905 "data//maps/MtChimney/scripts.pory"

# 906 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 907 "data//maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 908 "data//maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 909 "data//maps/MtChimney/scripts.pory"

# 910 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 911 "data//maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 912 "data//maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 913 "data//maps/MtChimney/scripts.pory"

# 914 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 915 "data//maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 916 "data//maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
