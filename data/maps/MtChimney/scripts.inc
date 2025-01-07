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
	clearflag FLAG_SYS_SAVE_GET
# 18 "data//maps/MtChimney/scripts.pory"
	end
# 19 "data//maps/MtChimney/scripts.pory"

# 20 "data//maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 21 "data//maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 22 "data//maps/MtChimney/scripts.pory"
	@ setstepcallback STEP_CB_ASH
# 23 "data//maps/MtChimney/scripts.pory"
	end
# 24 "data//maps/MtChimney/scripts.pory"

# 25 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Moltres::
# 26 "data//maps/MtChimney/scripts.pory"
	@ lock
# 27 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 28 "data//maps/MtChimney/scripts.pory"
	setobjectmovementtype LOCALID_MOLTRES, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN
# 29 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 30 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 31 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MtChimney_Movement_CameraPanUp
# 32 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 33 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 34 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 35 "data//maps/MtChimney/scripts.pory"
	waitse
# 36 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 37 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 38 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 39 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 40 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 41 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 42 "data//maps/MtChimney/scripts.pory"
	waitstate
# 43 "data//maps/MtChimney/scripts.pory"
	waitse
# 44 "data//maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 45 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 46 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 47 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 48 "data//maps/MtChimney/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 49 "data//maps/MtChimney/scripts.pory"
	special ShakeCamera
# 50 "data//maps/MtChimney/scripts.pory"
	waitstate
# 51 "data//maps/MtChimney/scripts.pory"
	waitmoncry
# 52 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MOLTRES, MtChimney_Movement_MoltresFlyOff
# 53 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 54 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MOLTRES
# 55 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MoltresFlewOff, MSGBOX_DEFAULT
# 56 "data//maps/MtChimney/scripts.pory"
	closemessage
# 57 "data//maps/MtChimney/scripts.pory"
	delay 20
# 58 "data//maps/MtChimney/scripts.pory"
	special SpawnCameraObject
# 59 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MtChimney_Movement_CameraPanDown
# 60 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 61 "data//maps/MtChimney/scripts.pory"
	special RemoveCameraObject
# 62 "data//maps/MtChimney/scripts.pory"
	setvar VAR_UNUSED_0x8014, 3
# 63 "data//maps/MtChimney/scripts.pory"
	@ goto_if_set FLAG_MET_MOLTRES, MtChimney_EventScript_ReAwakenMoltres
# 64 "data//maps/MtChimney/scripts.pory"
	special InitRoamer
# 65 "data//maps/MtChimney/scripts.pory"
	setseenmon SPECIES_MOLTRES
# 66 "data//maps/MtChimney/scripts.pory"
	@ setflag FLAG_MET_MOLTRES
# 67 "data//maps/MtChimney/scripts.pory"
	releaseall
# 68 "data//maps/MtChimney/scripts.pory"
	end
# 69 "data//maps/MtChimney/scripts.pory"

# 70 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ReAwakenMoltres::
# 71 "data//maps/MtChimney/scripts.pory"
	special ActivateRoamer
# 72 "data//maps/MtChimney/scripts.pory"
	releaseall
# 73 "data//maps/MtChimney/scripts.pory"
	end
# 74 "data//maps/MtChimney/scripts.pory"

# 75 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 76 "data//maps/MtChimney/scripts.pory"
	lock
# 77 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 78 "data//maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 79 "data//maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 80 "data//maps/MtChimney/scripts.pory"
	closemessage
# 81 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 82 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 83 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 84 "data//maps/MtChimney/scripts.pory"
	release
# 85 "data//maps/MtChimney/scripts.pory"
	end
# 86 "data//maps/MtChimney/scripts.pory"

# 87 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 88 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 89 "data//maps/MtChimney/scripts.pory"
	return
# 90 "data//maps/MtChimney/scripts.pory"

# 91 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 92 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 93 "data//maps/MtChimney/scripts.pory"
	return
# 94 "data//maps/MtChimney/scripts.pory"

# 95 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 96 "data//maps/MtChimney/scripts.pory"
	lockall
# 97 "data//maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 98 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 99 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 100 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 101 "data//maps/MtChimney/scripts.pory"
	playse SE_PIN
# 102 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 103 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 104 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 105 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 106 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 107 "data//maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 108 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 109 "data//maps/MtChimney/scripts.pory"
	closemessage
# 110 "data//maps/MtChimney/scripts.pory"
	delay 30
# 111 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 112 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 113 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 114 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 115 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 116 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 117 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 118 "data//maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 119 "data//maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 120 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 121 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 122 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 123 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 124 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 125 "data//maps/MtChimney/scripts.pory"
	closemessage
# 126 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 127 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 128 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 129 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 130 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 131 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 132 "data//maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 133 "data//maps/MtChimney/scripts.pory"
	releaseall
# 134 "data//maps/MtChimney/scripts.pory"
	end
# 135 "data//maps/MtChimney/scripts.pory"

# 136 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 137 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 138 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 139 "data//maps/MtChimney/scripts.pory"
	return
# 140 "data//maps/MtChimney/scripts.pory"

# 141 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 142 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 143 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 144 "data//maps/MtChimney/scripts.pory"
	return
# 145 "data//maps/MtChimney/scripts.pory"

# 146 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 147 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 148 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 149 "data//maps/MtChimney/scripts.pory"
	return
# 150 "data//maps/MtChimney/scripts.pory"

# 151 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 152 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 153 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 154 "data//maps/MtChimney/scripts.pory"
	return
# 155 "data//maps/MtChimney/scripts.pory"

# 156 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 157 "data//maps/MtChimney/scripts.pory"
	lock
# 158 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 159 "data//maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 160 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 161 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 162 "data//maps/MtChimney/scripts.pory"
	checkmoney 200
# 163 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 164 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 165 "data//maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 166 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 167 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 168 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 169 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 170 "data//maps/MtChimney/scripts.pory"
	release
# 171 "data//maps/MtChimney/scripts.pory"
	end
# 172 "data//maps/MtChimney/scripts.pory"

# 173 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 174 "data//maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 175 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 176 "data//maps/MtChimney/scripts.pory"
	release
# 177 "data//maps/MtChimney/scripts.pory"
	end
# 178 "data//maps/MtChimney/scripts.pory"

# 179 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 180 "data//maps/MtChimney/scripts.pory"
	removemoney 200
# 181 "data//maps/MtChimney/scripts.pory"
	updatemoneybox
# 182 "data//maps/MtChimney/scripts.pory"
	return
# 183 "data//maps/MtChimney/scripts.pory"

# 184 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 185 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 186 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 187 "data//maps/MtChimney/scripts.pory"
	release
# 188 "data//maps/MtChimney/scripts.pory"
	end
# 189 "data//maps/MtChimney/scripts.pory"

# 190 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 191 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 192 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 193 "data//maps/MtChimney/scripts.pory"
	release
# 194 "data//maps/MtChimney/scripts.pory"
	end
# 195 "data//maps/MtChimney/scripts.pory"

# 196 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_MoltresFlyOff:
# 197 "data//maps/MtChimney/scripts.pory"
	delay_16
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
	slide_up
# 204 "data//maps/MtChimney/scripts.pory"
	step_end
# 205 "data//maps/MtChimney/scripts.pory"

# 206 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanUp:
# 207 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 208 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 209 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 210 "data//maps/MtChimney/scripts.pory"
	step_end
# 211 "data//maps/MtChimney/scripts.pory"

# 212 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanDown:
# 213 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 214 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 215 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 216 "data//maps/MtChimney/scripts.pory"
	step_end
# 217 "data//maps/MtChimney/scripts.pory"

# 218 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
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
	walk_up
# 225 "data//maps/MtChimney/scripts.pory"
	walk_right
# 226 "data//maps/MtChimney/scripts.pory"
	step_end
# 227 "data//maps/MtChimney/scripts.pory"

# 228 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 229 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 237 "data//maps/MtChimney/scripts.pory"
	step_end
# 238 "data//maps/MtChimney/scripts.pory"

# 239 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 240 "data//maps/MtChimney/scripts.pory"
	walk_up
# 241 "data//maps/MtChimney/scripts.pory"
	walk_up
# 242 "data//maps/MtChimney/scripts.pory"
	walk_up
# 243 "data//maps/MtChimney/scripts.pory"
	walk_up
# 244 "data//maps/MtChimney/scripts.pory"
	walk_up
# 245 "data//maps/MtChimney/scripts.pory"
	walk_right
# 246 "data//maps/MtChimney/scripts.pory"
	walk_right
# 247 "data//maps/MtChimney/scripts.pory"
	step_end
# 248 "data//maps/MtChimney/scripts.pory"

# 249 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 250 "data//maps/MtChimney/scripts.pory"
	walk_left
# 251 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 259 "data//maps/MtChimney/scripts.pory"
	step_end
# 260 "data//maps/MtChimney/scripts.pory"

# 261 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 262 "data//maps/MtChimney/scripts.pory"
	walk_down
# 263 "data//maps/MtChimney/scripts.pory"
	walk_down
# 264 "data//maps/MtChimney/scripts.pory"
	walk_down
# 265 "data//maps/MtChimney/scripts.pory"
	walk_down
# 266 "data//maps/MtChimney/scripts.pory"
	walk_down
# 267 "data//maps/MtChimney/scripts.pory"
	walk_left
# 268 "data//maps/MtChimney/scripts.pory"
	walk_left
# 269 "data//maps/MtChimney/scripts.pory"
	walk_down
# 270 "data//maps/MtChimney/scripts.pory"
	walk_down
# 271 "data//maps/MtChimney/scripts.pory"
	walk_down
# 272 "data//maps/MtChimney/scripts.pory"
	walk_down
# 273 "data//maps/MtChimney/scripts.pory"
	walk_left
# 274 "data//maps/MtChimney/scripts.pory"
	walk_left
# 275 "data//maps/MtChimney/scripts.pory"
	walk_left
# 276 "data//maps/MtChimney/scripts.pory"
	walk_left
# 277 "data//maps/MtChimney/scripts.pory"
	walk_left
# 278 "data//maps/MtChimney/scripts.pory"
	walk_down
# 279 "data//maps/MtChimney/scripts.pory"
	step_end
# 280 "data//maps/MtChimney/scripts.pory"

# 281 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 282 "data//maps/MtChimney/scripts.pory"
	walk_down
# 283 "data//maps/MtChimney/scripts.pory"
	walk_down
# 284 "data//maps/MtChimney/scripts.pory"
	walk_down
# 285 "data//maps/MtChimney/scripts.pory"
	walk_down
# 286 "data//maps/MtChimney/scripts.pory"
	walk_left
# 287 "data//maps/MtChimney/scripts.pory"
	walk_left
# 288 "data//maps/MtChimney/scripts.pory"
	walk_left
# 289 "data//maps/MtChimney/scripts.pory"
	walk_down
# 290 "data//maps/MtChimney/scripts.pory"
	step_end
# 291 "data//maps/MtChimney/scripts.pory"

# 292 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 293 "data//maps/MtChimney/scripts.pory"
	walk_right
# 294 "data//maps/MtChimney/scripts.pory"
	walk_down
# 295 "data//maps/MtChimney/scripts.pory"
	walk_down
# 296 "data//maps/MtChimney/scripts.pory"
	walk_down
# 297 "data//maps/MtChimney/scripts.pory"
	walk_down
# 298 "data//maps/MtChimney/scripts.pory"
	walk_left
# 299 "data//maps/MtChimney/scripts.pory"
	walk_left
# 300 "data//maps/MtChimney/scripts.pory"
	walk_left
# 301 "data//maps/MtChimney/scripts.pory"
	walk_left
# 302 "data//maps/MtChimney/scripts.pory"
	walk_left
# 303 "data//maps/MtChimney/scripts.pory"
	walk_down
# 304 "data//maps/MtChimney/scripts.pory"
	walk_down
# 305 "data//maps/MtChimney/scripts.pory"
	walk_down
# 306 "data//maps/MtChimney/scripts.pory"
	walk_down
# 307 "data//maps/MtChimney/scripts.pory"
	step_end
# 308 "data//maps/MtChimney/scripts.pory"

# 309 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
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
	walk_fast_down
# 319 "data//maps/MtChimney/scripts.pory"
	walk_left
# 320 "data//maps/MtChimney/scripts.pory"
	walk_left
# 321 "data//maps/MtChimney/scripts.pory"
	walk_down
# 322 "data//maps/MtChimney/scripts.pory"
	walk_down
# 323 "data//maps/MtChimney/scripts.pory"
	walk_down
# 324 "data//maps/MtChimney/scripts.pory"
	walk_left
# 325 "data//maps/MtChimney/scripts.pory"
	walk_left
# 326 "data//maps/MtChimney/scripts.pory"
	walk_down
# 327 "data//maps/MtChimney/scripts.pory"
	walk_down
# 328 "data//maps/MtChimney/scripts.pory"
	walk_left
# 329 "data//maps/MtChimney/scripts.pory"
	walk_left
# 330 "data//maps/MtChimney/scripts.pory"
	walk_left
# 331 "data//maps/MtChimney/scripts.pory"
	walk_left
# 332 "data//maps/MtChimney/scripts.pory"
	walk_left
# 333 "data//maps/MtChimney/scripts.pory"
	walk_down
# 334 "data//maps/MtChimney/scripts.pory"
	step_end
# 335 "data//maps/MtChimney/scripts.pory"

# 336 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 337 "data//maps/MtChimney/scripts.pory"
	delay_16
# 338 "data//maps/MtChimney/scripts.pory"
	delay_16
# 339 "data//maps/MtChimney/scripts.pory"
	delay_16
# 340 "data//maps/MtChimney/scripts.pory"
	walk_down
# 341 "data//maps/MtChimney/scripts.pory"
	walk_down
# 342 "data//maps/MtChimney/scripts.pory"
	walk_down
# 343 "data//maps/MtChimney/scripts.pory"
	walk_left
# 344 "data//maps/MtChimney/scripts.pory"
	walk_left
# 345 "data//maps/MtChimney/scripts.pory"
	walk_left
# 346 "data//maps/MtChimney/scripts.pory"
	walk_down
# 347 "data//maps/MtChimney/scripts.pory"
	step_end
# 348 "data//maps/MtChimney/scripts.pory"

# 349 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 350 "data//maps/MtChimney/scripts.pory"
	delay_16
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
	walk_left
# 357 "data//maps/MtChimney/scripts.pory"
	walk_left
# 358 "data//maps/MtChimney/scripts.pory"
	walk_left
# 359 "data//maps/MtChimney/scripts.pory"
	walk_left
# 360 "data//maps/MtChimney/scripts.pory"
	walk_left
# 361 "data//maps/MtChimney/scripts.pory"
	walk_down
# 362 "data//maps/MtChimney/scripts.pory"
	walk_down
# 363 "data//maps/MtChimney/scripts.pory"
	walk_down
# 364 "data//maps/MtChimney/scripts.pory"
	walk_down
# 365 "data//maps/MtChimney/scripts.pory"
	step_end
# 366 "data//maps/MtChimney/scripts.pory"

# 367 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 368 "data//maps/MtChimney/scripts.pory"
	delay_16
# 369 "data//maps/MtChimney/scripts.pory"
	walk_left
# 370 "data//maps/MtChimney/scripts.pory"
	walk_left
# 371 "data//maps/MtChimney/scripts.pory"
	walk_down
# 372 "data//maps/MtChimney/scripts.pory"
	walk_down
# 373 "data//maps/MtChimney/scripts.pory"
	walk_down
# 374 "data//maps/MtChimney/scripts.pory"
	walk_left
# 375 "data//maps/MtChimney/scripts.pory"
	walk_left
# 376 "data//maps/MtChimney/scripts.pory"
	walk_down
# 377 "data//maps/MtChimney/scripts.pory"
	walk_down
# 378 "data//maps/MtChimney/scripts.pory"
	walk_left
# 379 "data//maps/MtChimney/scripts.pory"
	walk_left
# 380 "data//maps/MtChimney/scripts.pory"
	walk_left
# 381 "data//maps/MtChimney/scripts.pory"
	walk_left
# 382 "data//maps/MtChimney/scripts.pory"
	walk_left
# 383 "data//maps/MtChimney/scripts.pory"
	walk_down
# 384 "data//maps/MtChimney/scripts.pory"
	step_end
# 385 "data//maps/MtChimney/scripts.pory"

# 386 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 387 "data//maps/MtChimney/scripts.pory"
	delay_16
# 388 "data//maps/MtChimney/scripts.pory"
	walk_down
# 389 "data//maps/MtChimney/scripts.pory"
	walk_left
# 390 "data//maps/MtChimney/scripts.pory"
	walk_left
# 391 "data//maps/MtChimney/scripts.pory"
	walk_left
# 392 "data//maps/MtChimney/scripts.pory"
	walk_left
# 393 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 394 "data//maps/MtChimney/scripts.pory"
	step_end
# 395 "data//maps/MtChimney/scripts.pory"

# 396 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 397 "data//maps/MtChimney/scripts.pory"
	walk_down
# 398 "data//maps/MtChimney/scripts.pory"
	walk_down
# 399 "data//maps/MtChimney/scripts.pory"
	walk_down
# 400 "data//maps/MtChimney/scripts.pory"
	walk_down
# 401 "data//maps/MtChimney/scripts.pory"
	walk_left
# 402 "data//maps/MtChimney/scripts.pory"
	walk_left
# 403 "data//maps/MtChimney/scripts.pory"
	walk_left
# 404 "data//maps/MtChimney/scripts.pory"
	walk_left
# 405 "data//maps/MtChimney/scripts.pory"
	walk_left
# 406 "data//maps/MtChimney/scripts.pory"
	walk_down
# 407 "data//maps/MtChimney/scripts.pory"
	walk_down
# 408 "data//maps/MtChimney/scripts.pory"
	walk_down
# 409 "data//maps/MtChimney/scripts.pory"
	walk_down
# 410 "data//maps/MtChimney/scripts.pory"
	step_end
# 411 "data//maps/MtChimney/scripts.pory"

# 412 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 413 "data//maps/MtChimney/scripts.pory"
	walk_down
# 414 "data//maps/MtChimney/scripts.pory"
	step_end
# 415 "data//maps/MtChimney/scripts.pory"

# 416 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
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
	walk_down
# 424 "data//maps/MtChimney/scripts.pory"
	step_end
# 425 "data//maps/MtChimney/scripts.pory"

# 426 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 427 "data//maps/MtChimney/scripts.pory"
	delay_16
# 428 "data//maps/MtChimney/scripts.pory"
	delay_16
# 429 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 430 "data//maps/MtChimney/scripts.pory"
	delay_16
# 431 "data//maps/MtChimney/scripts.pory"
	walk_down
# 432 "data//maps/MtChimney/scripts.pory"
	walk_down
# 433 "data//maps/MtChimney/scripts.pory"
	walk_down
# 434 "data//maps/MtChimney/scripts.pory"
	walk_down
# 435 "data//maps/MtChimney/scripts.pory"
	walk_down
# 436 "data//maps/MtChimney/scripts.pory"
	step_end
# 437 "data//maps/MtChimney/scripts.pory"

# 438 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
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
	delay_16
# 445 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 446 "data//maps/MtChimney/scripts.pory"
	delay_16
# 447 "data//maps/MtChimney/scripts.pory"
	walk_down
# 448 "data//maps/MtChimney/scripts.pory"
	walk_down
# 449 "data//maps/MtChimney/scripts.pory"
	step_end
# 450 "data//maps/MtChimney/scripts.pory"

# 451 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 452 "data//maps/MtChimney/scripts.pory"
	lock_facing_direction
# 453 "data//maps/MtChimney/scripts.pory"
	walk_fast_left
# 454 "data//maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 455 "data//maps/MtChimney/scripts.pory"
	face_right
# 456 "data//maps/MtChimney/scripts.pory"
	step_end
# 457 "data//maps/MtChimney/scripts.pory"

# 458 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 459 "data//maps/MtChimney/scripts.pory"
	walk_left
# 460 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 461 "data//maps/MtChimney/scripts.pory"
	delay_16
# 462 "data//maps/MtChimney/scripts.pory"
	step_end
# 463 "data//maps/MtChimney/scripts.pory"

# 464 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 465 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 466 "data//maps/MtChimney/scripts.pory"
	end
# 467 "data//maps/MtChimney/scripts.pory"

# 468 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 469 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 470 "data//maps/MtChimney/scripts.pory"
	end
# 471 "data//maps/MtChimney/scripts.pory"

# 472 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 473 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 474 "data//maps/MtChimney/scripts.pory"
	end
# 475 "data//maps/MtChimney/scripts.pory"

# 476 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 477 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 478 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 479 "data//maps/MtChimney/scripts.pory"
	end
# 480 "data//maps/MtChimney/scripts.pory"

# 481 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 482 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 483 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 484 "data//maps/MtChimney/scripts.pory"
	end
# 485 "data//maps/MtChimney/scripts.pory"

# 486 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 487 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 488 "data//maps/MtChimney/scripts.pory"
	end
# 489 "data//maps/MtChimney/scripts.pory"

# 490 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 491 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 492 "data//maps/MtChimney/scripts.pory"
	end
# 493 "data//maps/MtChimney/scripts.pory"

# 494 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 495 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 496 "data//maps/MtChimney/scripts.pory"
	end
# 497 "data//maps/MtChimney/scripts.pory"

# 498 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 499 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 500 "data//maps/MtChimney/scripts.pory"
	end
# 501 "data//maps/MtChimney/scripts.pory"

# 502 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 503 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 504 "data//maps/MtChimney/scripts.pory"
	end
# 505 "data//maps/MtChimney/scripts.pory"

# 506 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 507 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 508 "data//maps/MtChimney/scripts.pory"
	end
# 509 "data//maps/MtChimney/scripts.pory"

# 510 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 511 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 512 "data//maps/MtChimney/scripts.pory"
	end
# 513 "data//maps/MtChimney/scripts.pory"

# 514 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 515 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 516 "data//maps/MtChimney/scripts.pory"
	end
# 517 "data//maps/MtChimney/scripts.pory"

# 518 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 519 "data//maps/MtChimney/scripts.pory"
	lockall
# 520 "data//maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 521 "data//maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 522 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 523 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 524 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 525 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 526 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 527 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 528 "data//maps/MtChimney/scripts.pory"
	releaseall
# 529 "data//maps/MtChimney/scripts.pory"
	end
# 530 "data//maps/MtChimney/scripts.pory"

# 531 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 532 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 533 "data//maps/MtChimney/scripts.pory"
	releaseall
# 534 "data//maps/MtChimney/scripts.pory"
	end
# 535 "data//maps/MtChimney/scripts.pory"

# 536 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 537 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 538 "data//maps/MtChimney/scripts.pory"
	releaseall
# 539 "data//maps/MtChimney/scripts.pory"
	end
# 540 "data//maps/MtChimney/scripts.pory"

# 541 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 542 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 543 "data//maps/MtChimney/scripts.pory"
	releaseall
# 544 "data//maps/MtChimney/scripts.pory"
	end
# 545 "data//maps/MtChimney/scripts.pory"

# 546 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 547 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 548 "data//maps/MtChimney/scripts.pory"
	end
# 549 "data//maps/MtChimney/scripts.pory"

# 550 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 551 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 552 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 553 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 554 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 555 "data//maps/MtChimney/scripts.pory"
	release
# 556 "data//maps/MtChimney/scripts.pory"
	end
# 557 "data//maps/MtChimney/scripts.pory"

# 558 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 559 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 560 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 561 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 562 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 563 "data//maps/MtChimney/scripts.pory"
	release
# 564 "data//maps/MtChimney/scripts.pory"
	end
# 565 "data//maps/MtChimney/scripts.pory"

# 566 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 567 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 568 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 569 "data//maps/MtChimney/scripts.pory"
	end
# 570 "data//maps/MtChimney/scripts.pory"

# 571 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 572 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 573 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 574 "data//maps/MtChimney/scripts.pory"
	end
# 575 "data//maps/MtChimney/scripts.pory"

# 576 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 577 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 578 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 579 "data//maps/MtChimney/scripts.pory"
	end
# 580 "data//maps/MtChimney/scripts.pory"

# 581 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 582 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 583 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 584 "data//maps/MtChimney/scripts.pory"
	end
# 585 "data//maps/MtChimney/scripts.pory"

# 586 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 587 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 588 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 589 "data//maps/MtChimney/scripts.pory"
	end
# 590 "data//maps/MtChimney/scripts.pory"

# 591 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 592 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 593 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 594 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 595 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 596 "data//maps/MtChimney/scripts.pory"
	release
# 597 "data//maps/MtChimney/scripts.pory"
	end
# 598 "data//maps/MtChimney/scripts.pory"

# 599 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 600 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 601 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 602 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 603 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 604 "data//maps/MtChimney/scripts.pory"
	release
# 605 "data//maps/MtChimney/scripts.pory"
	end
# 606 "data//maps/MtChimney/scripts.pory"

# 607 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 608 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 609 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 610 "data//maps/MtChimney/scripts.pory"
	end
# 611 "data//maps/MtChimney/scripts.pory"

# 612 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MoltresFlewOff:
# 613 "data//maps/MtChimney/scripts.pory"
	.string "MOLTRES woke up and flew\n"
# 614 "data//maps/MtChimney/scripts.pory"
	.string "off somewhere . . .$"
# 615 "data//maps/MtChimney/scripts.pory"

# 616 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 617 "data//maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 618 "data//maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 619 "data//maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 620 "data//maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 621 "data//maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 622 "data//maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 623 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 624 "data//maps/MtChimney/scripts.pory"

# 625 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 626 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 627 "data//maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 628 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 629 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 630 "data//maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 631 "data//maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 632 "data//maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 633 "data//maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 634 "data//maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 635 "data//maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 636 "data//maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 637 "data//maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 638 "data//maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 639 "data//maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 640 "data//maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 641 "data//maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 642 "data//maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 643 "data//maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 644 "data//maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 645 "data//maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 646 "data//maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 647 "data//maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 648 "data//maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 649 "data//maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 650 "data//maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 651 "data//maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 652 "data//maps/MtChimney/scripts.pory"

# 653 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 654 "data//maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 655 "data//maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 656 "data//maps/MtChimney/scripts.pory"

# 657 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 658 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 659 "data//maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 660 "data//maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 661 "data//maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 662 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 663 "data//maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 664 "data//maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 665 "data//maps/MtChimney/scripts.pory"

# 666 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 667 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 668 "data//maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 669 "data//maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 670 "data//maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 671 "data//maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 672 "data//maps/MtChimney/scripts.pory"

# 673 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 674 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 675 "data//maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 676 "data//maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 677 "data//maps/MtChimney/scripts.pory"

# 678 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 679 "data//maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 680 "data//maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 681 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 682 "data//maps/MtChimney/scripts.pory"

# 683 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 684 "data//maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 685 "data//maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 686 "data//maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 687 "data//maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 688 "data//maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 689 "data//maps/MtChimney/scripts.pory"

# 690 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 691 "data//maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 692 "data//maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 693 "data//maps/MtChimney/scripts.pory"

# 694 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 695 "data//maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 696 "data//maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 697 "data//maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 698 "data//maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 699 "data//maps/MtChimney/scripts.pory"

# 700 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 701 "data//maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 702 "data//maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 703 "data//maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 704 "data//maps/MtChimney/scripts.pory"

# 705 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 706 "data//maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 707 "data//maps/MtChimney/scripts.pory"

# 708 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 709 "data//maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 710 "data//maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 711 "data//maps/MtChimney/scripts.pory"

# 712 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 713 "data//maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 714 "data//maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 715 "data//maps/MtChimney/scripts.pory"

# 716 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 717 "data//maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 718 "data//maps/MtChimney/scripts.pory"

# 719 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 720 "data//maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 721 "data//maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 722 "data//maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 723 "data//maps/MtChimney/scripts.pory"

# 724 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 725 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 726 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 727 "data//maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 728 "data//maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 729 "data//maps/MtChimney/scripts.pory"

# 730 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 731 "data//maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 732 "data//maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 733 "data//maps/MtChimney/scripts.pory"

# 734 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 735 "data//maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 736 "data//maps/MtChimney/scripts.pory"

# 737 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 738 "data//maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 739 "data//maps/MtChimney/scripts.pory"

# 740 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 741 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 742 "data//maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 743 "data//maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 744 "data//maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 745 "data//maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 746 "data//maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 747 "data//maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 748 "data//maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 749 "data//maps/MtChimney/scripts.pory"

# 750 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 751 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 752 "data//maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 753 "data//maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 754 "data//maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 755 "data//maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 756 "data//maps/MtChimney/scripts.pory"

# 757 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 758 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 759 "data//maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 760 "data//maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 761 "data//maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 762 "data//maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 763 "data//maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 764 "data//maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 765 "data//maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 766 "data//maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 767 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 768 "data//maps/MtChimney/scripts.pory"

# 769 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 770 "data//maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 771 "data//maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 772 "data//maps/MtChimney/scripts.pory"

# 773 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 774 "data//maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 775 "data//maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 776 "data//maps/MtChimney/scripts.pory"

# 777 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 778 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 779 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 780 "data//maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 781 "data//maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 782 "data//maps/MtChimney/scripts.pory"

# 783 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 784 "data//maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 785 "data//maps/MtChimney/scripts.pory"

# 786 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 787 "data//maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 788 "data//maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 789 "data//maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 790 "data//maps/MtChimney/scripts.pory"

# 791 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 792 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 793 "data//maps/MtChimney/scripts.pory"

# 794 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 795 "data//maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 796 "data//maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 797 "data//maps/MtChimney/scripts.pory"

# 798 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 799 "data//maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 800 "data//maps/MtChimney/scripts.pory"

# 801 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 802 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 803 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 804 "data//maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 805 "data//maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 806 "data//maps/MtChimney/scripts.pory"

# 807 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 808 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 809 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 810 "data//maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 811 "data//maps/MtChimney/scripts.pory"

# 812 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 813 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 814 "data//maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 815 "data//maps/MtChimney/scripts.pory"

# 816 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 817 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 818 "data//maps/MtChimney/scripts.pory"
	.string "it was.$"
# 819 "data//maps/MtChimney/scripts.pory"

# 820 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 821 "data//maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 822 "data//maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 823 "data//maps/MtChimney/scripts.pory"

# 824 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 825 "data//maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 826 "data//maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 827 "data//maps/MtChimney/scripts.pory"

# 828 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 829 "data//maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 830 "data//maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 831 "data//maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 832 "data//maps/MtChimney/scripts.pory"

# 833 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 834 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 835 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 836 "data//maps/MtChimney/scripts.pory"

# 837 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 838 "data//maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 839 "data//maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 840 "data//maps/MtChimney/scripts.pory"

# 841 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 842 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 843 "data//maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 844 "data//maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 845 "data//maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 846 "data//maps/MtChimney/scripts.pory"

# 847 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 848 "data//maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 849 "data//maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 850 "data//maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 851 "data//maps/MtChimney/scripts.pory"

# 852 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 853 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 854 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 855 "data//maps/MtChimney/scripts.pory"

# 856 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 857 "data//maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 858 "data//maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 859 "data//maps/MtChimney/scripts.pory"

# 860 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 861 "data//maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 862 "data//maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 863 "data//maps/MtChimney/scripts.pory"

# 864 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 865 "data//maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 866 "data//maps/MtChimney/scripts.pory"

# 867 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 868 "data//maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 869 "data//maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 870 "data//maps/MtChimney/scripts.pory"

# 871 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 872 "data//maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 873 "data//maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 874 "data//maps/MtChimney/scripts.pory"

# 875 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 876 "data//maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 877 "data//maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 878 "data//maps/MtChimney/scripts.pory"

# 879 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 880 "data//maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 881 "data//maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 882 "data//maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 883 "data//maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 884 "data//maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 885 "data//maps/MtChimney/scripts.pory"

# 886 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 887 "data//maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 888 "data//maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 889 "data//maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 890 "data//maps/MtChimney/scripts.pory"

# 891 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 892 "data//maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 893 "data//maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 894 "data//maps/MtChimney/scripts.pory"

# 895 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 896 "data//maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 897 "data//maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 898 "data//maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 899 "data//maps/MtChimney/scripts.pory"

# 900 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 901 "data//maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 902 "data//maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 903 "data//maps/MtChimney/scripts.pory"

# 904 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 905 "data//maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 906 "data//maps/MtChimney/scripts.pory"

# 907 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 908 "data//maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 909 "data//maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 910 "data//maps/MtChimney/scripts.pory"

# 911 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 912 "data//maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 913 "data//maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 914 "data//maps/MtChimney/scripts.pory"

# 915 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 916 "data//maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 917 "data//maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 918 "data//maps/MtChimney/scripts.pory"

# 919 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 920 "data//maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 921 "data//maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 922 "data//maps/MtChimney/scripts.pory"

# 923 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 924 "data//maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 925 "data//maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
