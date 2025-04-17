# 1 "data//maps/MtChimney/scripts.pory"

# 2 "data//maps/MtChimney/scripts.pory"
.set LOCALID_ARCHIE, 1
# 3 "data//maps/MtChimney/scripts.pory"
.set LOCALID_MAXIE, 2
# 4 "data//maps/MtChimney/scripts.pory"
.set LOCALID_TABITHA, 3
# 5 "data//maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 22
# 6 "data//maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 29
# 7 "data//maps/MtChimney/scripts.pory"
.set LOCALID_MOLTRES, 31 
# 8 "data//maps/MtChimney/scripts.pory"

# 9 "data//maps/MtChimney/scripts.pory"

# 10 "data//maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 11 "data//maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 12 "data//maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 13 "data//maps/MtChimney/scripts.pory"
	.byte 0
# 14 "data//maps/MtChimney/scripts.pory"

# 15 "data//maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 16 "data//maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 17 "data//maps/MtChimney/scripts.pory"
	end
# 18 "data//maps/MtChimney/scripts.pory"

# 19 "data//maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 20 "data//maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 21 "data//maps/MtChimney/scripts.pory"
	@ setstepcallback STEP_CB_ASH
# 22 "data//maps/MtChimney/scripts.pory"
	end
# 23 "data//maps/MtChimney/scripts.pory"

# 24 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Moltres::
# 25 "data//maps/MtChimney/scripts.pory"
	@ lock
# 26 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 27 "data//maps/MtChimney/scripts.pory"
	setobjectmovementtype LOCALID_MOLTRES, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN
# 28 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 29 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 30 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MtChimney_Movement_CameraPanUp
# 31 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 32 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 33 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 34 "data//maps/MtChimney/scripts.pory"
	waitse
# 35 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 36 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 37 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 38 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 39 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 40 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 41 "data//maps/MtChimney/scripts.pory"
	waitstate
# 42 "data//maps/MtChimney/scripts.pory"
	waitse
# 43 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 44 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 45 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 46 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 47 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 48 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 49 "data//maps/MtChimney/scripts.pory"
	waitstate
# 50 "data//maps/MtChimney/scripts.pory"
	waitmoncry
# 51 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MOLTRES, MtChimney_Movement_MoltresFlyOff
# 52 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 53 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MOLTRES
# 54 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MoltresFlewOff, MSGBOX_DEFAULT
# 55 "data//maps/MtChimney/scripts.pory"
	closemessage
# 56 "data//maps/MtChimney/scripts.pory"
	delay 20
# 57 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 58 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MtChimney_Movement_CameraPanDown
# 59 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 60 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 61 "data//maps/MtChimney/scripts.pory"
	setvar VAR_UNUSED_0x8014, 3
# 62 "data//maps/MtChimney/scripts.pory"
	@ goto_if_set FLAG_MET_MOLTRES, MtChimney_EventScript_ReAwakenMoltres
# 63 "data//maps/MtChimney/scripts.pory"
	special InitRoamer
# 64 "data//maps/MtChimney/scripts.pory"
	setseenmon SPECIES_MOLTRES
# 65 "data//maps/MtChimney/scripts.pory"
	@ setflag FLAG_MET_MOLTRES
# 66 "data//maps/MtChimney/scripts.pory"
	releaseall
# 67 "data//maps/MtChimney/scripts.pory"
	end
# 68 "data//maps/MtChimney/scripts.pory"

# 69 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ReAwakenMoltres::
# 70 "data//maps/MtChimney/scripts.pory"
	special ActivateRoamer
# 71 "data//maps/MtChimney/scripts.pory"
	releaseall
# 72 "data//maps/MtChimney/scripts.pory"
	end
# 73 "data//maps/MtChimney/scripts.pory"

# 74 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 75 "data//maps/MtChimney/scripts.pory"
	lock
# 76 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 77 "data//maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 78 "data//maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 79 "data//maps/MtChimney/scripts.pory"
	closemessage
# 80 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 81 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 82 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 83 "data//maps/MtChimney/scripts.pory"
	release
# 84 "data//maps/MtChimney/scripts.pory"
	end
# 85 "data//maps/MtChimney/scripts.pory"

# 86 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 87 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 88 "data//maps/MtChimney/scripts.pory"
	return
# 89 "data//maps/MtChimney/scripts.pory"

# 90 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 91 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 92 "data//maps/MtChimney/scripts.pory"
	return
# 93 "data//maps/MtChimney/scripts.pory"

# 94 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 95 "data//maps/MtChimney/scripts.pory"
	lockall
# 96 "data//maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 97 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 98 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 99 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 100 "data//maps/MtChimney/scripts.pory"
	playse SE_PIN
# 101 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 102 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 103 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 104 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 105 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 106 "data//maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 107 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 108 "data//maps/MtChimney/scripts.pory"
	closemessage
# 109 "data//maps/MtChimney/scripts.pory"
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MAXIE
# 112 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 113 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 114 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 115 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
# 119 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 120 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 121 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 122 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 123 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 124 "data//maps/MtChimney/scripts.pory"
	closemessage
# 125 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 126 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 127 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 128 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 129 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 130 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 131 "data//maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 132 "data//maps/MtChimney/scripts.pory"
	releaseall
# 133 "data//maps/MtChimney/scripts.pory"
	end
# 134 "data//maps/MtChimney/scripts.pory"

# 135 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 136 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 137 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 138 "data//maps/MtChimney/scripts.pory"
	return
# 139 "data//maps/MtChimney/scripts.pory"

# 140 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 141 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 142 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 143 "data//maps/MtChimney/scripts.pory"
	return
# 144 "data//maps/MtChimney/scripts.pory"

# 145 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 146 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 147 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 148 "data//maps/MtChimney/scripts.pory"
	return
# 149 "data//maps/MtChimney/scripts.pory"

# 150 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 151 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 152 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 153 "data//maps/MtChimney/scripts.pory"
	return
# 154 "data//maps/MtChimney/scripts.pory"

# 155 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 156 "data//maps/MtChimney/scripts.pory"
	lock
# 157 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 158 "data//maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 159 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 160 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 161 "data//maps/MtChimney/scripts.pory"
	checkmoney 200
# 162 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 163 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 164 "data//maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 165 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 166 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 167 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 168 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 169 "data//maps/MtChimney/scripts.pory"
	release
# 170 "data//maps/MtChimney/scripts.pory"
	end
# 171 "data//maps/MtChimney/scripts.pory"

# 172 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 173 "data//maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 174 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 175 "data//maps/MtChimney/scripts.pory"
	release
# 176 "data//maps/MtChimney/scripts.pory"
	end
# 177 "data//maps/MtChimney/scripts.pory"

# 178 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 179 "data//maps/MtChimney/scripts.pory"
	removemoney 200
# 180 "data//maps/MtChimney/scripts.pory"
	updatemoneybox
# 181 "data//maps/MtChimney/scripts.pory"
	return
# 182 "data//maps/MtChimney/scripts.pory"

# 183 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 184 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 185 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 186 "data//maps/MtChimney/scripts.pory"
	release
# 187 "data//maps/MtChimney/scripts.pory"
	end
# 188 "data//maps/MtChimney/scripts.pory"

# 189 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 190 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 191 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 192 "data//maps/MtChimney/scripts.pory"
	release
# 193 "data//maps/MtChimney/scripts.pory"
	end
# 194 "data//maps/MtChimney/scripts.pory"

# 195 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_MoltresFlyOff:
# 196 "data//maps/MtChimney/scripts.pory"
	delay_16
# 197 "data//maps/MtChimney/scripts.pory"
	slide_up
# 198 "data//maps/MtChimney/scripts.pory"
	slide_up
# 199 "data//maps/MtChimney/scripts.pory"
	slide_up
# 200 "data//maps/MtChimney/scripts.pory"
	slide_up
# 201 "data//maps/MtChimney/scripts.pory"
	slide_up
# 202 "data//maps/MtChimney/scripts.pory"
	slide_up
# 203 "data//maps/MtChimney/scripts.pory"
	step_end
# 204 "data//maps/MtChimney/scripts.pory"

# 205 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanUp:
# 206 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 207 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 208 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 209 "data//maps/MtChimney/scripts.pory"
	step_end
# 210 "data//maps/MtChimney/scripts.pory"

# 211 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanDown:
# 212 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 213 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 214 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 215 "data//maps/MtChimney/scripts.pory"
	step_end
# 216 "data//maps/MtChimney/scripts.pory"

# 217 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 218 "data//maps/MtChimney/scripts.pory"
	walk_up
# 219 "data//maps/MtChimney/scripts.pory"
	walk_up
# 220 "data//maps/MtChimney/scripts.pory"
	walk_up
# 221 "data//maps/MtChimney/scripts.pory"
	walk_up
# 222 "data//maps/MtChimney/scripts.pory"
	walk_up
# 223 "data//maps/MtChimney/scripts.pory"
	walk_up
# 224 "data//maps/MtChimney/scripts.pory"
	walk_right
# 225 "data//maps/MtChimney/scripts.pory"
	step_end
# 226 "data//maps/MtChimney/scripts.pory"

# 227 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 228 "data//maps/MtChimney/scripts.pory"
	walk_left
# 229 "data//maps/MtChimney/scripts.pory"
	walk_down
# 230 "data//maps/MtChimney/scripts.pory"
	walk_down
# 231 "data//maps/MtChimney/scripts.pory"
	walk_down
# 232 "data//maps/MtChimney/scripts.pory"
	walk_down
# 233 "data//maps/MtChimney/scripts.pory"
	walk_down
# 234 "data//maps/MtChimney/scripts.pory"
	walk_down
# 235 "data//maps/MtChimney/scripts.pory"
	walk_down
# 236 "data//maps/MtChimney/scripts.pory"
	step_end
# 237 "data//maps/MtChimney/scripts.pory"

# 238 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 239 "data//maps/MtChimney/scripts.pory"
	walk_up
# 240 "data//maps/MtChimney/scripts.pory"
	walk_up
# 241 "data//maps/MtChimney/scripts.pory"
	walk_up
# 242 "data//maps/MtChimney/scripts.pory"
	walk_up
# 243 "data//maps/MtChimney/scripts.pory"
	walk_up
# 244 "data//maps/MtChimney/scripts.pory"
	walk_right
# 245 "data//maps/MtChimney/scripts.pory"
	walk_right
# 246 "data//maps/MtChimney/scripts.pory"
	step_end
# 247 "data//maps/MtChimney/scripts.pory"

# 248 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 249 "data//maps/MtChimney/scripts.pory"
	walk_left
# 250 "data//maps/MtChimney/scripts.pory"
	walk_left
# 251 "data//maps/MtChimney/scripts.pory"
	walk_down
# 252 "data//maps/MtChimney/scripts.pory"
	walk_down
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
	step_end
# 259 "data//maps/MtChimney/scripts.pory"

# 260 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 261 "data//maps/MtChimney/scripts.pory"
	walk_down
# 262 "data//maps/MtChimney/scripts.pory"
	walk_down
# 263 "data//maps/MtChimney/scripts.pory"
	walk_down
# 264 "data//maps/MtChimney/scripts.pory"
	walk_down
# 265 "data//maps/MtChimney/scripts.pory"
	walk_down
# 266 "data//maps/MtChimney/scripts.pory"
	walk_left
# 267 "data//maps/MtChimney/scripts.pory"
	walk_left
# 268 "data//maps/MtChimney/scripts.pory"
	walk_down
# 269 "data//maps/MtChimney/scripts.pory"
	walk_down
# 270 "data//maps/MtChimney/scripts.pory"
	walk_down
# 271 "data//maps/MtChimney/scripts.pory"
	walk_down
# 272 "data//maps/MtChimney/scripts.pory"
	walk_left
# 273 "data//maps/MtChimney/scripts.pory"
	walk_left
# 274 "data//maps/MtChimney/scripts.pory"
	walk_left
# 275 "data//maps/MtChimney/scripts.pory"
	walk_left
# 276 "data//maps/MtChimney/scripts.pory"
	walk_left
# 277 "data//maps/MtChimney/scripts.pory"
	walk_down
# 278 "data//maps/MtChimney/scripts.pory"
	step_end
# 279 "data//maps/MtChimney/scripts.pory"

# 280 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 281 "data//maps/MtChimney/scripts.pory"
	walk_down
# 282 "data//maps/MtChimney/scripts.pory"
	walk_down
# 283 "data//maps/MtChimney/scripts.pory"
	walk_down
# 284 "data//maps/MtChimney/scripts.pory"
	walk_down
# 285 "data//maps/MtChimney/scripts.pory"
	walk_left
# 286 "data//maps/MtChimney/scripts.pory"
	walk_left
# 287 "data//maps/MtChimney/scripts.pory"
	walk_left
# 288 "data//maps/MtChimney/scripts.pory"
	walk_down
# 289 "data//maps/MtChimney/scripts.pory"
	step_end
# 290 "data//maps/MtChimney/scripts.pory"

# 291 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 292 "data//maps/MtChimney/scripts.pory"
	walk_right
# 293 "data//maps/MtChimney/scripts.pory"
	walk_down
# 294 "data//maps/MtChimney/scripts.pory"
	walk_down
# 295 "data//maps/MtChimney/scripts.pory"
	walk_down
# 296 "data//maps/MtChimney/scripts.pory"
	walk_down
# 297 "data//maps/MtChimney/scripts.pory"
	walk_left
# 298 "data//maps/MtChimney/scripts.pory"
	walk_left
# 299 "data//maps/MtChimney/scripts.pory"
	walk_left
# 300 "data//maps/MtChimney/scripts.pory"
	walk_left
# 301 "data//maps/MtChimney/scripts.pory"
	walk_left
# 302 "data//maps/MtChimney/scripts.pory"
	walk_down
# 303 "data//maps/MtChimney/scripts.pory"
	walk_down
# 304 "data//maps/MtChimney/scripts.pory"
	walk_down
# 305 "data//maps/MtChimney/scripts.pory"
	walk_down
# 306 "data//maps/MtChimney/scripts.pory"
	step_end
# 307 "data//maps/MtChimney/scripts.pory"

# 308 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 309 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 310 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 311 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 312 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 313 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 314 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 315 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 316 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 317 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 318 "data//maps/MtChimney/scripts.pory"
	walk_left
# 319 "data//maps/MtChimney/scripts.pory"
	walk_left
# 320 "data//maps/MtChimney/scripts.pory"
	walk_down
# 321 "data//maps/MtChimney/scripts.pory"
	walk_down
# 322 "data//maps/MtChimney/scripts.pory"
	walk_down
# 323 "data//maps/MtChimney/scripts.pory"
	walk_left
# 324 "data//maps/MtChimney/scripts.pory"
	walk_left
# 325 "data//maps/MtChimney/scripts.pory"
	walk_down
# 326 "data//maps/MtChimney/scripts.pory"
	walk_down
# 327 "data//maps/MtChimney/scripts.pory"
	walk_left
# 328 "data//maps/MtChimney/scripts.pory"
	walk_left
# 329 "data//maps/MtChimney/scripts.pory"
	walk_left
# 330 "data//maps/MtChimney/scripts.pory"
	walk_left
# 331 "data//maps/MtChimney/scripts.pory"
	walk_left
# 332 "data//maps/MtChimney/scripts.pory"
	walk_down
# 333 "data//maps/MtChimney/scripts.pory"
	step_end
# 334 "data//maps/MtChimney/scripts.pory"

# 335 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 336 "data//maps/MtChimney/scripts.pory"
	delay_16
# 337 "data//maps/MtChimney/scripts.pory"
	delay_16
# 338 "data//maps/MtChimney/scripts.pory"
	delay_16
# 339 "data//maps/MtChimney/scripts.pory"
	walk_down
# 340 "data//maps/MtChimney/scripts.pory"
	walk_down
# 341 "data//maps/MtChimney/scripts.pory"
	walk_down
# 342 "data//maps/MtChimney/scripts.pory"
	walk_left
# 343 "data//maps/MtChimney/scripts.pory"
	walk_left
# 344 "data//maps/MtChimney/scripts.pory"
	walk_left
# 345 "data//maps/MtChimney/scripts.pory"
	walk_down
# 346 "data//maps/MtChimney/scripts.pory"
	step_end
# 347 "data//maps/MtChimney/scripts.pory"

# 348 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 349 "data//maps/MtChimney/scripts.pory"
	delay_16
# 350 "data//maps/MtChimney/scripts.pory"
	walk_left
# 351 "data//maps/MtChimney/scripts.pory"
	walk_down
# 352 "data//maps/MtChimney/scripts.pory"
	walk_down
# 353 "data//maps/MtChimney/scripts.pory"
	walk_down
# 354 "data//maps/MtChimney/scripts.pory"
	walk_down
# 355 "data//maps/MtChimney/scripts.pory"
	walk_left
# 356 "data//maps/MtChimney/scripts.pory"
	walk_left
# 357 "data//maps/MtChimney/scripts.pory"
	walk_left
# 358 "data//maps/MtChimney/scripts.pory"
	walk_left
# 359 "data//maps/MtChimney/scripts.pory"
	walk_left
# 360 "data//maps/MtChimney/scripts.pory"
	walk_down
# 361 "data//maps/MtChimney/scripts.pory"
	walk_down
# 362 "data//maps/MtChimney/scripts.pory"
	walk_down
# 363 "data//maps/MtChimney/scripts.pory"
	walk_down
# 364 "data//maps/MtChimney/scripts.pory"
	step_end
# 365 "data//maps/MtChimney/scripts.pory"

# 366 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 367 "data//maps/MtChimney/scripts.pory"
	delay_16
# 368 "data//maps/MtChimney/scripts.pory"
	walk_left
# 369 "data//maps/MtChimney/scripts.pory"
	walk_left
# 370 "data//maps/MtChimney/scripts.pory"
	walk_down
# 371 "data//maps/MtChimney/scripts.pory"
	walk_down
# 372 "data//maps/MtChimney/scripts.pory"
	walk_down
# 373 "data//maps/MtChimney/scripts.pory"
	walk_left
# 374 "data//maps/MtChimney/scripts.pory"
	walk_left
# 375 "data//maps/MtChimney/scripts.pory"
	walk_down
# 376 "data//maps/MtChimney/scripts.pory"
	walk_down
# 377 "data//maps/MtChimney/scripts.pory"
	walk_left
# 378 "data//maps/MtChimney/scripts.pory"
	walk_left
# 379 "data//maps/MtChimney/scripts.pory"
	walk_left
# 380 "data//maps/MtChimney/scripts.pory"
	walk_left
# 381 "data//maps/MtChimney/scripts.pory"
	walk_left
# 382 "data//maps/MtChimney/scripts.pory"
	walk_down
# 383 "data//maps/MtChimney/scripts.pory"
	step_end
# 384 "data//maps/MtChimney/scripts.pory"

# 385 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 386 "data//maps/MtChimney/scripts.pory"
	delay_16
# 387 "data//maps/MtChimney/scripts.pory"
	walk_down
# 388 "data//maps/MtChimney/scripts.pory"
	walk_left
# 389 "data//maps/MtChimney/scripts.pory"
	walk_left
# 390 "data//maps/MtChimney/scripts.pory"
	walk_left
# 391 "data//maps/MtChimney/scripts.pory"
	walk_left
# 392 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 393 "data//maps/MtChimney/scripts.pory"
	step_end
# 394 "data//maps/MtChimney/scripts.pory"

# 395 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 396 "data//maps/MtChimney/scripts.pory"
	walk_down
# 397 "data//maps/MtChimney/scripts.pory"
	walk_down
# 398 "data//maps/MtChimney/scripts.pory"
	walk_down
# 399 "data//maps/MtChimney/scripts.pory"
	walk_down
# 400 "data//maps/MtChimney/scripts.pory"
	walk_left
# 401 "data//maps/MtChimney/scripts.pory"
	walk_left
# 402 "data//maps/MtChimney/scripts.pory"
	walk_left
# 403 "data//maps/MtChimney/scripts.pory"
	walk_left
# 404 "data//maps/MtChimney/scripts.pory"
	walk_left
# 405 "data//maps/MtChimney/scripts.pory"
	walk_down
# 406 "data//maps/MtChimney/scripts.pory"
	walk_down
# 407 "data//maps/MtChimney/scripts.pory"
	walk_down
# 408 "data//maps/MtChimney/scripts.pory"
	walk_down
# 409 "data//maps/MtChimney/scripts.pory"
	step_end
# 410 "data//maps/MtChimney/scripts.pory"

# 411 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 412 "data//maps/MtChimney/scripts.pory"
	walk_down
# 413 "data//maps/MtChimney/scripts.pory"
	step_end
# 414 "data//maps/MtChimney/scripts.pory"

# 415 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 416 "data//maps/MtChimney/scripts.pory"
	walk_down
# 417 "data//maps/MtChimney/scripts.pory"
	walk_down
# 418 "data//maps/MtChimney/scripts.pory"
	walk_down
# 419 "data//maps/MtChimney/scripts.pory"
	walk_down
# 420 "data//maps/MtChimney/scripts.pory"
	walk_down
# 421 "data//maps/MtChimney/scripts.pory"
	walk_down
# 422 "data//maps/MtChimney/scripts.pory"
	walk_down
# 423 "data//maps/MtChimney/scripts.pory"
	step_end
# 424 "data//maps/MtChimney/scripts.pory"

# 425 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 426 "data//maps/MtChimney/scripts.pory"
	delay_16
# 427 "data//maps/MtChimney/scripts.pory"
	delay_16
# 428 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 429 "data//maps/MtChimney/scripts.pory"
	delay_16
# 430 "data//maps/MtChimney/scripts.pory"
	walk_down
# 431 "data//maps/MtChimney/scripts.pory"
	walk_down
# 432 "data//maps/MtChimney/scripts.pory"
	walk_down
# 433 "data//maps/MtChimney/scripts.pory"
	walk_down
# 434 "data//maps/MtChimney/scripts.pory"
	walk_down
# 435 "data//maps/MtChimney/scripts.pory"
	step_end
# 436 "data//maps/MtChimney/scripts.pory"

# 437 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 438 "data//maps/MtChimney/scripts.pory"
	delay_16
# 439 "data//maps/MtChimney/scripts.pory"
	delay_16
# 440 "data//maps/MtChimney/scripts.pory"
	delay_16
# 441 "data//maps/MtChimney/scripts.pory"
	delay_16
# 442 "data//maps/MtChimney/scripts.pory"
	delay_16
# 443 "data//maps/MtChimney/scripts.pory"
	delay_16
# 444 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 445 "data//maps/MtChimney/scripts.pory"
	delay_16
# 446 "data//maps/MtChimney/scripts.pory"
	walk_down
# 447 "data//maps/MtChimney/scripts.pory"
	walk_down
# 448 "data//maps/MtChimney/scripts.pory"
	step_end
# 449 "data//maps/MtChimney/scripts.pory"

# 450 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 451 "data//maps/MtChimney/scripts.pory"
	lock_facing_direction
# 452 "data//maps/MtChimney/scripts.pory"
	walk_fast_left
# 453 "data//maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 454 "data//maps/MtChimney/scripts.pory"
	face_right
# 455 "data//maps/MtChimney/scripts.pory"
	step_end
# 456 "data//maps/MtChimney/scripts.pory"

# 457 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 458 "data//maps/MtChimney/scripts.pory"
	walk_left
# 459 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 460 "data//maps/MtChimney/scripts.pory"
	delay_16
# 461 "data//maps/MtChimney/scripts.pory"
	step_end
# 462 "data//maps/MtChimney/scripts.pory"

# 463 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 464 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 465 "data//maps/MtChimney/scripts.pory"
	end
# 466 "data//maps/MtChimney/scripts.pory"

# 467 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 468 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 469 "data//maps/MtChimney/scripts.pory"
	end
# 470 "data//maps/MtChimney/scripts.pory"

# 471 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 472 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 473 "data//maps/MtChimney/scripts.pory"
	end
# 474 "data//maps/MtChimney/scripts.pory"

# 475 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 476 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 477 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 478 "data//maps/MtChimney/scripts.pory"
	end
# 479 "data//maps/MtChimney/scripts.pory"

# 480 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 481 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 482 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 483 "data//maps/MtChimney/scripts.pory"
	end
# 484 "data//maps/MtChimney/scripts.pory"

# 485 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 486 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 487 "data//maps/MtChimney/scripts.pory"
	end
# 488 "data//maps/MtChimney/scripts.pory"

# 489 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 490 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 491 "data//maps/MtChimney/scripts.pory"
	end
# 492 "data//maps/MtChimney/scripts.pory"

# 493 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 494 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 495 "data//maps/MtChimney/scripts.pory"
	end
# 496 "data//maps/MtChimney/scripts.pory"

# 497 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 498 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 499 "data//maps/MtChimney/scripts.pory"
	end
# 500 "data//maps/MtChimney/scripts.pory"

# 501 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 502 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 503 "data//maps/MtChimney/scripts.pory"
	end
# 504 "data//maps/MtChimney/scripts.pory"

# 505 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 506 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 507 "data//maps/MtChimney/scripts.pory"
	end
# 508 "data//maps/MtChimney/scripts.pory"

# 509 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 510 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 511 "data//maps/MtChimney/scripts.pory"
	end
# 512 "data//maps/MtChimney/scripts.pory"

# 513 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 514 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 515 "data//maps/MtChimney/scripts.pory"
	end
# 516 "data//maps/MtChimney/scripts.pory"

# 517 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 518 "data//maps/MtChimney/scripts.pory"
	lockall
# 519 "data//maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 520 "data//maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 521 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 522 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 523 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 524 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 525 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 526 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 527 "data//maps/MtChimney/scripts.pory"
	releaseall
# 528 "data//maps/MtChimney/scripts.pory"
	end
# 529 "data//maps/MtChimney/scripts.pory"

# 530 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 531 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 532 "data//maps/MtChimney/scripts.pory"
	releaseall
# 533 "data//maps/MtChimney/scripts.pory"
	end
# 534 "data//maps/MtChimney/scripts.pory"

# 535 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 536 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 537 "data//maps/MtChimney/scripts.pory"
	releaseall
# 538 "data//maps/MtChimney/scripts.pory"
	end
# 539 "data//maps/MtChimney/scripts.pory"

# 540 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 541 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 542 "data//maps/MtChimney/scripts.pory"
	releaseall
# 543 "data//maps/MtChimney/scripts.pory"
	end
# 544 "data//maps/MtChimney/scripts.pory"

# 545 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 546 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 547 "data//maps/MtChimney/scripts.pory"
	end
# 548 "data//maps/MtChimney/scripts.pory"

# 549 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 550 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 551 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 552 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 553 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 554 "data//maps/MtChimney/scripts.pory"
	release
# 555 "data//maps/MtChimney/scripts.pory"
	end
# 556 "data//maps/MtChimney/scripts.pory"

# 557 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 558 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 559 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 560 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 561 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 562 "data//maps/MtChimney/scripts.pory"
	release
# 563 "data//maps/MtChimney/scripts.pory"
	end
# 564 "data//maps/MtChimney/scripts.pory"

# 565 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 566 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 567 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 568 "data//maps/MtChimney/scripts.pory"
	end
# 569 "data//maps/MtChimney/scripts.pory"

# 570 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 571 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 572 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 573 "data//maps/MtChimney/scripts.pory"
	end
# 574 "data//maps/MtChimney/scripts.pory"

# 575 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 576 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 577 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 578 "data//maps/MtChimney/scripts.pory"
	end
# 579 "data//maps/MtChimney/scripts.pory"

# 580 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 581 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 582 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 583 "data//maps/MtChimney/scripts.pory"
	end
# 584 "data//maps/MtChimney/scripts.pory"

# 585 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 586 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 587 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 588 "data//maps/MtChimney/scripts.pory"
	end
# 589 "data//maps/MtChimney/scripts.pory"

# 590 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 591 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 592 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 593 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 594 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 595 "data//maps/MtChimney/scripts.pory"
	release
# 596 "data//maps/MtChimney/scripts.pory"
	end
# 597 "data//maps/MtChimney/scripts.pory"

# 598 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 599 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 600 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 601 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 602 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 603 "data//maps/MtChimney/scripts.pory"
	release
# 604 "data//maps/MtChimney/scripts.pory"
	end
# 605 "data//maps/MtChimney/scripts.pory"

# 606 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 607 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 608 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 609 "data//maps/MtChimney/scripts.pory"
	end
# 610 "data//maps/MtChimney/scripts.pory"

# 611 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MoltresFlewOff:
# 612 "data//maps/MtChimney/scripts.pory"
	.string "MOLTRES woke up and flew\n"
# 613 "data//maps/MtChimney/scripts.pory"
	.string "off somewhere . . .$"
# 614 "data//maps/MtChimney/scripts.pory"

# 615 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 616 "data//maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 617 "data//maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 618 "data//maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 619 "data//maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 620 "data//maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 621 "data//maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 622 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 623 "data//maps/MtChimney/scripts.pory"

# 624 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 625 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 626 "data//maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 627 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 628 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 629 "data//maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 630 "data//maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 631 "data//maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 632 "data//maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 633 "data//maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 634 "data//maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 635 "data//maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 636 "data//maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 637 "data//maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 638 "data//maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 639 "data//maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 640 "data//maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 641 "data//maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 642 "data//maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 643 "data//maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 644 "data//maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 645 "data//maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 646 "data//maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 647 "data//maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 648 "data//maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 649 "data//maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 650 "data//maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 651 "data//maps/MtChimney/scripts.pory"

# 652 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 653 "data//maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 654 "data//maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 655 "data//maps/MtChimney/scripts.pory"

# 656 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 657 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 658 "data//maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 659 "data//maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 660 "data//maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 661 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 662 "data//maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 663 "data//maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 664 "data//maps/MtChimney/scripts.pory"

# 665 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 666 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 667 "data//maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 668 "data//maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 669 "data//maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 670 "data//maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 671 "data//maps/MtChimney/scripts.pory"

# 672 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 673 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 674 "data//maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 675 "data//maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 676 "data//maps/MtChimney/scripts.pory"

# 677 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 678 "data//maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 679 "data//maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 680 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 681 "data//maps/MtChimney/scripts.pory"

# 682 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 683 "data//maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 684 "data//maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 685 "data//maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 686 "data//maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 687 "data//maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 688 "data//maps/MtChimney/scripts.pory"

# 689 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 690 "data//maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 691 "data//maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 692 "data//maps/MtChimney/scripts.pory"

# 693 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 694 "data//maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 695 "data//maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 696 "data//maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 697 "data//maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 698 "data//maps/MtChimney/scripts.pory"

# 699 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 700 "data//maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 701 "data//maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 702 "data//maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 703 "data//maps/MtChimney/scripts.pory"

# 704 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 705 "data//maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 706 "data//maps/MtChimney/scripts.pory"

# 707 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 708 "data//maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 709 "data//maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 710 "data//maps/MtChimney/scripts.pory"

# 711 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 712 "data//maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 713 "data//maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 714 "data//maps/MtChimney/scripts.pory"

# 715 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 716 "data//maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 717 "data//maps/MtChimney/scripts.pory"

# 718 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 719 "data//maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 720 "data//maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 721 "data//maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 722 "data//maps/MtChimney/scripts.pory"

# 723 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 724 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 725 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 726 "data//maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 727 "data//maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 728 "data//maps/MtChimney/scripts.pory"

# 729 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 730 "data//maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 731 "data//maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 732 "data//maps/MtChimney/scripts.pory"

# 733 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 734 "data//maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 735 "data//maps/MtChimney/scripts.pory"

# 736 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 737 "data//maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 738 "data//maps/MtChimney/scripts.pory"

# 739 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 740 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 741 "data//maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 742 "data//maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 743 "data//maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 744 "data//maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 745 "data//maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 746 "data//maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 747 "data//maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 748 "data//maps/MtChimney/scripts.pory"

# 749 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 750 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 751 "data//maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 752 "data//maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 753 "data//maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 754 "data//maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 755 "data//maps/MtChimney/scripts.pory"

# 756 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 757 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 758 "data//maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 759 "data//maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 760 "data//maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 761 "data//maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 762 "data//maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 763 "data//maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 764 "data//maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 765 "data//maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 766 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 767 "data//maps/MtChimney/scripts.pory"

# 768 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 769 "data//maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 770 "data//maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 771 "data//maps/MtChimney/scripts.pory"

# 772 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 773 "data//maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 774 "data//maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 775 "data//maps/MtChimney/scripts.pory"

# 776 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 777 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 778 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 779 "data//maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 780 "data//maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 781 "data//maps/MtChimney/scripts.pory"

# 782 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 783 "data//maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 784 "data//maps/MtChimney/scripts.pory"

# 785 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 786 "data//maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 787 "data//maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 788 "data//maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 789 "data//maps/MtChimney/scripts.pory"

# 790 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 791 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 792 "data//maps/MtChimney/scripts.pory"

# 793 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 794 "data//maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 795 "data//maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 796 "data//maps/MtChimney/scripts.pory"

# 797 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 798 "data//maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 799 "data//maps/MtChimney/scripts.pory"

# 800 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 801 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 802 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 803 "data//maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 804 "data//maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 805 "data//maps/MtChimney/scripts.pory"

# 806 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 807 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 808 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 809 "data//maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 810 "data//maps/MtChimney/scripts.pory"

# 811 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 812 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 813 "data//maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 814 "data//maps/MtChimney/scripts.pory"

# 815 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 816 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 817 "data//maps/MtChimney/scripts.pory"
	.string "it was.$"
# 818 "data//maps/MtChimney/scripts.pory"

# 819 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 820 "data//maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 821 "data//maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 822 "data//maps/MtChimney/scripts.pory"

# 823 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 824 "data//maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 825 "data//maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 826 "data//maps/MtChimney/scripts.pory"

# 827 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 828 "data//maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 829 "data//maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 830 "data//maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 831 "data//maps/MtChimney/scripts.pory"

# 832 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 833 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 834 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 835 "data//maps/MtChimney/scripts.pory"

# 836 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 837 "data//maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 838 "data//maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 839 "data//maps/MtChimney/scripts.pory"

# 840 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 841 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 842 "data//maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 843 "data//maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 844 "data//maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 845 "data//maps/MtChimney/scripts.pory"

# 846 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 847 "data//maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 848 "data//maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 849 "data//maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 850 "data//maps/MtChimney/scripts.pory"

# 851 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 852 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 853 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 854 "data//maps/MtChimney/scripts.pory"

# 855 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 856 "data//maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 857 "data//maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 858 "data//maps/MtChimney/scripts.pory"

# 859 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 860 "data//maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 861 "data//maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 862 "data//maps/MtChimney/scripts.pory"

# 863 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 864 "data//maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 865 "data//maps/MtChimney/scripts.pory"

# 866 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 867 "data//maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 868 "data//maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 869 "data//maps/MtChimney/scripts.pory"

# 870 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 871 "data//maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 872 "data//maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 873 "data//maps/MtChimney/scripts.pory"

# 874 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 875 "data//maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 876 "data//maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 877 "data//maps/MtChimney/scripts.pory"

# 878 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 879 "data//maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 880 "data//maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 881 "data//maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 882 "data//maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 883 "data//maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 884 "data//maps/MtChimney/scripts.pory"

# 885 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 886 "data//maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 887 "data//maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 888 "data//maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 889 "data//maps/MtChimney/scripts.pory"

# 890 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 891 "data//maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 892 "data//maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 893 "data//maps/MtChimney/scripts.pory"

# 894 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 895 "data//maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 896 "data//maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 897 "data//maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 898 "data//maps/MtChimney/scripts.pory"

# 899 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 900 "data//maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 901 "data//maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 902 "data//maps/MtChimney/scripts.pory"

# 903 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 904 "data//maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 905 "data//maps/MtChimney/scripts.pory"

# 906 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 907 "data//maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 908 "data//maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 909 "data//maps/MtChimney/scripts.pory"

# 910 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 911 "data//maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 912 "data//maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 913 "data//maps/MtChimney/scripts.pory"

# 914 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 915 "data//maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 916 "data//maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 917 "data//maps/MtChimney/scripts.pory"

# 918 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 919 "data//maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 920 "data//maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 921 "data//maps/MtChimney/scripts.pory"

# 922 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 923 "data//maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 924 "data//maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
