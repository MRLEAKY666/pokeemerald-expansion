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
	special InitRoamer
# 64 "data//maps/MtChimney/scripts.pory"
	setseenmon SPECIES_MOLTRES
# 65 "data//maps/MtChimney/scripts.pory"
	releaseall
# 66 "data//maps/MtChimney/scripts.pory"
	end
# 67 "data//maps/MtChimney/scripts.pory"

# 68 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 69 "data//maps/MtChimney/scripts.pory"
	lock
# 70 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 71 "data//maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 72 "data//maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 73 "data//maps/MtChimney/scripts.pory"
	closemessage
# 74 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 75 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 76 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 77 "data//maps/MtChimney/scripts.pory"
	release
# 78 "data//maps/MtChimney/scripts.pory"
	end
# 79 "data//maps/MtChimney/scripts.pory"

# 80 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 81 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 82 "data//maps/MtChimney/scripts.pory"
	return
# 83 "data//maps/MtChimney/scripts.pory"

# 84 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 85 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 86 "data//maps/MtChimney/scripts.pory"
	return
# 87 "data//maps/MtChimney/scripts.pory"

# 88 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 89 "data//maps/MtChimney/scripts.pory"
	lockall
# 90 "data//maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 91 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 92 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 93 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 94 "data//maps/MtChimney/scripts.pory"
	playse SE_PIN
# 95 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 96 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 97 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 98 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 99 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 100 "data//maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 101 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 102 "data//maps/MtChimney/scripts.pory"
	closemessage
# 103 "data//maps/MtChimney/scripts.pory"
	delay 30
# 104 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 105 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 106 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 107 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 108 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 109 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 110 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 111 "data//maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 112 "data//maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 113 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 114 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 115 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 116 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 117 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 118 "data//maps/MtChimney/scripts.pory"
	closemessage
# 119 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 120 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 121 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 122 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 123 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 124 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 125 "data//maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 126 "data//maps/MtChimney/scripts.pory"
	releaseall
# 127 "data//maps/MtChimney/scripts.pory"
	end
# 128 "data//maps/MtChimney/scripts.pory"

# 129 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 130 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 131 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 132 "data//maps/MtChimney/scripts.pory"
	return
# 133 "data//maps/MtChimney/scripts.pory"

# 134 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 135 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 136 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 137 "data//maps/MtChimney/scripts.pory"
	return
# 138 "data//maps/MtChimney/scripts.pory"

# 139 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 140 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 141 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 142 "data//maps/MtChimney/scripts.pory"
	return
# 143 "data//maps/MtChimney/scripts.pory"

# 144 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 145 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 146 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 147 "data//maps/MtChimney/scripts.pory"
	return
# 148 "data//maps/MtChimney/scripts.pory"

# 149 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 150 "data//maps/MtChimney/scripts.pory"
	lock
# 151 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 152 "data//maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 153 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 154 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 155 "data//maps/MtChimney/scripts.pory"
	checkmoney 200
# 156 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 157 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 158 "data//maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 159 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 160 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 161 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 162 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 163 "data//maps/MtChimney/scripts.pory"
	release
# 164 "data//maps/MtChimney/scripts.pory"
	end
# 165 "data//maps/MtChimney/scripts.pory"

# 166 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 167 "data//maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 168 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 169 "data//maps/MtChimney/scripts.pory"
	release
# 170 "data//maps/MtChimney/scripts.pory"
	end
# 171 "data//maps/MtChimney/scripts.pory"

# 172 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 173 "data//maps/MtChimney/scripts.pory"
	removemoney 200
# 174 "data//maps/MtChimney/scripts.pory"
	updatemoneybox
# 175 "data//maps/MtChimney/scripts.pory"
	return
# 176 "data//maps/MtChimney/scripts.pory"

# 177 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 178 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 179 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 180 "data//maps/MtChimney/scripts.pory"
	release
# 181 "data//maps/MtChimney/scripts.pory"
	end
# 182 "data//maps/MtChimney/scripts.pory"

# 183 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 184 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 185 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 186 "data//maps/MtChimney/scripts.pory"
	release
# 187 "data//maps/MtChimney/scripts.pory"
	end
# 188 "data//maps/MtChimney/scripts.pory"

# 189 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_MoltresFlyOff:
# 190 "data//maps/MtChimney/scripts.pory"
	delay_16
# 191 "data//maps/MtChimney/scripts.pory"
	slide_up
# 192 "data//maps/MtChimney/scripts.pory"
	slide_up
# 193 "data//maps/MtChimney/scripts.pory"
	slide_up
# 194 "data//maps/MtChimney/scripts.pory"
	slide_up
# 195 "data//maps/MtChimney/scripts.pory"
	slide_up
# 196 "data//maps/MtChimney/scripts.pory"
	slide_up
# 197 "data//maps/MtChimney/scripts.pory"
	step_end
# 198 "data//maps/MtChimney/scripts.pory"

# 199 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanUp:
# 200 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 201 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 202 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 203 "data//maps/MtChimney/scripts.pory"
	step_end
# 204 "data//maps/MtChimney/scripts.pory"

# 205 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanDown:
# 206 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 207 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 208 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 209 "data//maps/MtChimney/scripts.pory"
	step_end
# 210 "data//maps/MtChimney/scripts.pory"

# 211 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 212 "data//maps/MtChimney/scripts.pory"
	walk_up
# 213 "data//maps/MtChimney/scripts.pory"
	walk_up
# 214 "data//maps/MtChimney/scripts.pory"
	walk_up
# 215 "data//maps/MtChimney/scripts.pory"
	walk_up
# 216 "data//maps/MtChimney/scripts.pory"
	walk_up
# 217 "data//maps/MtChimney/scripts.pory"
	walk_up
# 218 "data//maps/MtChimney/scripts.pory"
	walk_right
# 219 "data//maps/MtChimney/scripts.pory"
	step_end
# 220 "data//maps/MtChimney/scripts.pory"

# 221 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 222 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 229 "data//maps/MtChimney/scripts.pory"
	walk_down
# 230 "data//maps/MtChimney/scripts.pory"
	step_end
# 231 "data//maps/MtChimney/scripts.pory"

# 232 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 233 "data//maps/MtChimney/scripts.pory"
	walk_up
# 234 "data//maps/MtChimney/scripts.pory"
	walk_up
# 235 "data//maps/MtChimney/scripts.pory"
	walk_up
# 236 "data//maps/MtChimney/scripts.pory"
	walk_up
# 237 "data//maps/MtChimney/scripts.pory"
	walk_up
# 238 "data//maps/MtChimney/scripts.pory"
	walk_right
# 239 "data//maps/MtChimney/scripts.pory"
	walk_right
# 240 "data//maps/MtChimney/scripts.pory"
	step_end
# 241 "data//maps/MtChimney/scripts.pory"

# 242 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 243 "data//maps/MtChimney/scripts.pory"
	walk_left
# 244 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 251 "data//maps/MtChimney/scripts.pory"
	walk_down
# 252 "data//maps/MtChimney/scripts.pory"
	step_end
# 253 "data//maps/MtChimney/scripts.pory"

# 254 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 255 "data//maps/MtChimney/scripts.pory"
	walk_down
# 256 "data//maps/MtChimney/scripts.pory"
	walk_down
# 257 "data//maps/MtChimney/scripts.pory"
	walk_down
# 258 "data//maps/MtChimney/scripts.pory"
	walk_down
# 259 "data//maps/MtChimney/scripts.pory"
	walk_down
# 260 "data//maps/MtChimney/scripts.pory"
	walk_left
# 261 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_left
# 269 "data//maps/MtChimney/scripts.pory"
	walk_left
# 270 "data//maps/MtChimney/scripts.pory"
	walk_left
# 271 "data//maps/MtChimney/scripts.pory"
	walk_down
# 272 "data//maps/MtChimney/scripts.pory"
	step_end
# 273 "data//maps/MtChimney/scripts.pory"

# 274 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 275 "data//maps/MtChimney/scripts.pory"
	walk_down
# 276 "data//maps/MtChimney/scripts.pory"
	walk_down
# 277 "data//maps/MtChimney/scripts.pory"
	walk_down
# 278 "data//maps/MtChimney/scripts.pory"
	walk_down
# 279 "data//maps/MtChimney/scripts.pory"
	walk_left
# 280 "data//maps/MtChimney/scripts.pory"
	walk_left
# 281 "data//maps/MtChimney/scripts.pory"
	walk_left
# 282 "data//maps/MtChimney/scripts.pory"
	walk_down
# 283 "data//maps/MtChimney/scripts.pory"
	step_end
# 284 "data//maps/MtChimney/scripts.pory"

# 285 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 286 "data//maps/MtChimney/scripts.pory"
	walk_right
# 287 "data//maps/MtChimney/scripts.pory"
	walk_down
# 288 "data//maps/MtChimney/scripts.pory"
	walk_down
# 289 "data//maps/MtChimney/scripts.pory"
	walk_down
# 290 "data//maps/MtChimney/scripts.pory"
	walk_down
# 291 "data//maps/MtChimney/scripts.pory"
	walk_left
# 292 "data//maps/MtChimney/scripts.pory"
	walk_left
# 293 "data//maps/MtChimney/scripts.pory"
	walk_left
# 294 "data//maps/MtChimney/scripts.pory"
	walk_left
# 295 "data//maps/MtChimney/scripts.pory"
	walk_left
# 296 "data//maps/MtChimney/scripts.pory"
	walk_down
# 297 "data//maps/MtChimney/scripts.pory"
	walk_down
# 298 "data//maps/MtChimney/scripts.pory"
	walk_down
# 299 "data//maps/MtChimney/scripts.pory"
	walk_down
# 300 "data//maps/MtChimney/scripts.pory"
	step_end
# 301 "data//maps/MtChimney/scripts.pory"

# 302 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
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
	walk_fast_down
# 311 "data//maps/MtChimney/scripts.pory"
	walk_fast_down
# 312 "data//maps/MtChimney/scripts.pory"
	walk_left
# 313 "data//maps/MtChimney/scripts.pory"
	walk_left
# 314 "data//maps/MtChimney/scripts.pory"
	walk_down
# 315 "data//maps/MtChimney/scripts.pory"
	walk_down
# 316 "data//maps/MtChimney/scripts.pory"
	walk_down
# 317 "data//maps/MtChimney/scripts.pory"
	walk_left
# 318 "data//maps/MtChimney/scripts.pory"
	walk_left
# 319 "data//maps/MtChimney/scripts.pory"
	walk_down
# 320 "data//maps/MtChimney/scripts.pory"
	walk_down
# 321 "data//maps/MtChimney/scripts.pory"
	walk_left
# 322 "data//maps/MtChimney/scripts.pory"
	walk_left
# 323 "data//maps/MtChimney/scripts.pory"
	walk_left
# 324 "data//maps/MtChimney/scripts.pory"
	walk_left
# 325 "data//maps/MtChimney/scripts.pory"
	walk_left
# 326 "data//maps/MtChimney/scripts.pory"
	walk_down
# 327 "data//maps/MtChimney/scripts.pory"
	step_end
# 328 "data//maps/MtChimney/scripts.pory"

# 329 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 330 "data//maps/MtChimney/scripts.pory"
	delay_16
# 331 "data//maps/MtChimney/scripts.pory"
	delay_16
# 332 "data//maps/MtChimney/scripts.pory"
	delay_16
# 333 "data//maps/MtChimney/scripts.pory"
	walk_down
# 334 "data//maps/MtChimney/scripts.pory"
	walk_down
# 335 "data//maps/MtChimney/scripts.pory"
	walk_down
# 336 "data//maps/MtChimney/scripts.pory"
	walk_left
# 337 "data//maps/MtChimney/scripts.pory"
	walk_left
# 338 "data//maps/MtChimney/scripts.pory"
	walk_left
# 339 "data//maps/MtChimney/scripts.pory"
	walk_down
# 340 "data//maps/MtChimney/scripts.pory"
	step_end
# 341 "data//maps/MtChimney/scripts.pory"

# 342 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 343 "data//maps/MtChimney/scripts.pory"
	delay_16
# 344 "data//maps/MtChimney/scripts.pory"
	walk_left
# 345 "data//maps/MtChimney/scripts.pory"
	walk_down
# 346 "data//maps/MtChimney/scripts.pory"
	walk_down
# 347 "data//maps/MtChimney/scripts.pory"
	walk_down
# 348 "data//maps/MtChimney/scripts.pory"
	walk_down
# 349 "data//maps/MtChimney/scripts.pory"
	walk_left
# 350 "data//maps/MtChimney/scripts.pory"
	walk_left
# 351 "data//maps/MtChimney/scripts.pory"
	walk_left
# 352 "data//maps/MtChimney/scripts.pory"
	walk_left
# 353 "data//maps/MtChimney/scripts.pory"
	walk_left
# 354 "data//maps/MtChimney/scripts.pory"
	walk_down
# 355 "data//maps/MtChimney/scripts.pory"
	walk_down
# 356 "data//maps/MtChimney/scripts.pory"
	walk_down
# 357 "data//maps/MtChimney/scripts.pory"
	walk_down
# 358 "data//maps/MtChimney/scripts.pory"
	step_end
# 359 "data//maps/MtChimney/scripts.pory"

# 360 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 361 "data//maps/MtChimney/scripts.pory"
	delay_16
# 362 "data//maps/MtChimney/scripts.pory"
	walk_left
# 363 "data//maps/MtChimney/scripts.pory"
	walk_left
# 364 "data//maps/MtChimney/scripts.pory"
	walk_down
# 365 "data//maps/MtChimney/scripts.pory"
	walk_down
# 366 "data//maps/MtChimney/scripts.pory"
	walk_down
# 367 "data//maps/MtChimney/scripts.pory"
	walk_left
# 368 "data//maps/MtChimney/scripts.pory"
	walk_left
# 369 "data//maps/MtChimney/scripts.pory"
	walk_down
# 370 "data//maps/MtChimney/scripts.pory"
	walk_down
# 371 "data//maps/MtChimney/scripts.pory"
	walk_left
# 372 "data//maps/MtChimney/scripts.pory"
	walk_left
# 373 "data//maps/MtChimney/scripts.pory"
	walk_left
# 374 "data//maps/MtChimney/scripts.pory"
	walk_left
# 375 "data//maps/MtChimney/scripts.pory"
	walk_left
# 376 "data//maps/MtChimney/scripts.pory"
	walk_down
# 377 "data//maps/MtChimney/scripts.pory"
	step_end
# 378 "data//maps/MtChimney/scripts.pory"

# 379 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 380 "data//maps/MtChimney/scripts.pory"
	delay_16
# 381 "data//maps/MtChimney/scripts.pory"
	walk_down
# 382 "data//maps/MtChimney/scripts.pory"
	walk_left
# 383 "data//maps/MtChimney/scripts.pory"
	walk_left
# 384 "data//maps/MtChimney/scripts.pory"
	walk_left
# 385 "data//maps/MtChimney/scripts.pory"
	walk_left
# 386 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 387 "data//maps/MtChimney/scripts.pory"
	step_end
# 388 "data//maps/MtChimney/scripts.pory"

# 389 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 390 "data//maps/MtChimney/scripts.pory"
	walk_down
# 391 "data//maps/MtChimney/scripts.pory"
	walk_down
# 392 "data//maps/MtChimney/scripts.pory"
	walk_down
# 393 "data//maps/MtChimney/scripts.pory"
	walk_down
# 394 "data//maps/MtChimney/scripts.pory"
	walk_left
# 395 "data//maps/MtChimney/scripts.pory"
	walk_left
# 396 "data//maps/MtChimney/scripts.pory"
	walk_left
# 397 "data//maps/MtChimney/scripts.pory"
	walk_left
# 398 "data//maps/MtChimney/scripts.pory"
	walk_left
# 399 "data//maps/MtChimney/scripts.pory"
	walk_down
# 400 "data//maps/MtChimney/scripts.pory"
	walk_down
# 401 "data//maps/MtChimney/scripts.pory"
	walk_down
# 402 "data//maps/MtChimney/scripts.pory"
	walk_down
# 403 "data//maps/MtChimney/scripts.pory"
	step_end
# 404 "data//maps/MtChimney/scripts.pory"

# 405 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 406 "data//maps/MtChimney/scripts.pory"
	walk_down
# 407 "data//maps/MtChimney/scripts.pory"
	step_end
# 408 "data//maps/MtChimney/scripts.pory"

# 409 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
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
	walk_down
# 416 "data//maps/MtChimney/scripts.pory"
	walk_down
# 417 "data//maps/MtChimney/scripts.pory"
	step_end
# 418 "data//maps/MtChimney/scripts.pory"

# 419 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 420 "data//maps/MtChimney/scripts.pory"
	delay_16
# 421 "data//maps/MtChimney/scripts.pory"
	delay_16
# 422 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 423 "data//maps/MtChimney/scripts.pory"
	delay_16
# 424 "data//maps/MtChimney/scripts.pory"
	walk_down
# 425 "data//maps/MtChimney/scripts.pory"
	walk_down
# 426 "data//maps/MtChimney/scripts.pory"
	walk_down
# 427 "data//maps/MtChimney/scripts.pory"
	walk_down
# 428 "data//maps/MtChimney/scripts.pory"
	walk_down
# 429 "data//maps/MtChimney/scripts.pory"
	step_end
# 430 "data//maps/MtChimney/scripts.pory"

# 431 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 432 "data//maps/MtChimney/scripts.pory"
	delay_16
# 433 "data//maps/MtChimney/scripts.pory"
	delay_16
# 434 "data//maps/MtChimney/scripts.pory"
	delay_16
# 435 "data//maps/MtChimney/scripts.pory"
	delay_16
# 436 "data//maps/MtChimney/scripts.pory"
	delay_16
# 437 "data//maps/MtChimney/scripts.pory"
	delay_16
# 438 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 439 "data//maps/MtChimney/scripts.pory"
	delay_16
# 440 "data//maps/MtChimney/scripts.pory"
	walk_down
# 441 "data//maps/MtChimney/scripts.pory"
	walk_down
# 442 "data//maps/MtChimney/scripts.pory"
	step_end
# 443 "data//maps/MtChimney/scripts.pory"

# 444 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 445 "data//maps/MtChimney/scripts.pory"
	lock_facing_direction
# 446 "data//maps/MtChimney/scripts.pory"
	walk_fast_left
# 447 "data//maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 448 "data//maps/MtChimney/scripts.pory"
	face_right
# 449 "data//maps/MtChimney/scripts.pory"
	step_end
# 450 "data//maps/MtChimney/scripts.pory"

# 451 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 452 "data//maps/MtChimney/scripts.pory"
	walk_left
# 453 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 454 "data//maps/MtChimney/scripts.pory"
	delay_16
# 455 "data//maps/MtChimney/scripts.pory"
	step_end
# 456 "data//maps/MtChimney/scripts.pory"

# 457 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 458 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 459 "data//maps/MtChimney/scripts.pory"
	end
# 460 "data//maps/MtChimney/scripts.pory"

# 461 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 462 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 463 "data//maps/MtChimney/scripts.pory"
	end
# 464 "data//maps/MtChimney/scripts.pory"

# 465 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 466 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 467 "data//maps/MtChimney/scripts.pory"
	end
# 468 "data//maps/MtChimney/scripts.pory"

# 469 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 470 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 471 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 472 "data//maps/MtChimney/scripts.pory"
	end
# 473 "data//maps/MtChimney/scripts.pory"

# 474 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 475 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 476 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 477 "data//maps/MtChimney/scripts.pory"
	end
# 478 "data//maps/MtChimney/scripts.pory"

# 479 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 480 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 481 "data//maps/MtChimney/scripts.pory"
	end
# 482 "data//maps/MtChimney/scripts.pory"

# 483 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 484 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 485 "data//maps/MtChimney/scripts.pory"
	end
# 486 "data//maps/MtChimney/scripts.pory"

# 487 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 488 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 489 "data//maps/MtChimney/scripts.pory"
	end
# 490 "data//maps/MtChimney/scripts.pory"

# 491 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 492 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 493 "data//maps/MtChimney/scripts.pory"
	end
# 494 "data//maps/MtChimney/scripts.pory"

# 495 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 496 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 497 "data//maps/MtChimney/scripts.pory"
	end
# 498 "data//maps/MtChimney/scripts.pory"

# 499 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 500 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 501 "data//maps/MtChimney/scripts.pory"
	end
# 502 "data//maps/MtChimney/scripts.pory"

# 503 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 504 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 505 "data//maps/MtChimney/scripts.pory"
	end
# 506 "data//maps/MtChimney/scripts.pory"

# 507 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 508 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 509 "data//maps/MtChimney/scripts.pory"
	end
# 510 "data//maps/MtChimney/scripts.pory"

# 511 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 512 "data//maps/MtChimney/scripts.pory"
	lockall
# 513 "data//maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 514 "data//maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 515 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 516 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 517 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 518 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 519 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 520 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 521 "data//maps/MtChimney/scripts.pory"
	releaseall
# 522 "data//maps/MtChimney/scripts.pory"
	end
# 523 "data//maps/MtChimney/scripts.pory"

# 524 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 525 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 526 "data//maps/MtChimney/scripts.pory"
	releaseall
# 527 "data//maps/MtChimney/scripts.pory"
	end
# 528 "data//maps/MtChimney/scripts.pory"

# 529 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 530 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 531 "data//maps/MtChimney/scripts.pory"
	releaseall
# 532 "data//maps/MtChimney/scripts.pory"
	end
# 533 "data//maps/MtChimney/scripts.pory"

# 534 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 535 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 536 "data//maps/MtChimney/scripts.pory"
	releaseall
# 537 "data//maps/MtChimney/scripts.pory"
	end
# 538 "data//maps/MtChimney/scripts.pory"

# 539 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 540 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 541 "data//maps/MtChimney/scripts.pory"
	end
# 542 "data//maps/MtChimney/scripts.pory"

# 543 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 544 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 545 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 546 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 547 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 548 "data//maps/MtChimney/scripts.pory"
	release
# 549 "data//maps/MtChimney/scripts.pory"
	end
# 550 "data//maps/MtChimney/scripts.pory"

# 551 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 552 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 553 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 554 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 555 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 556 "data//maps/MtChimney/scripts.pory"
	release
# 557 "data//maps/MtChimney/scripts.pory"
	end
# 558 "data//maps/MtChimney/scripts.pory"

# 559 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 560 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 561 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 562 "data//maps/MtChimney/scripts.pory"
	end
# 563 "data//maps/MtChimney/scripts.pory"

# 564 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 565 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 566 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 567 "data//maps/MtChimney/scripts.pory"
	end
# 568 "data//maps/MtChimney/scripts.pory"

# 569 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 570 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 571 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 572 "data//maps/MtChimney/scripts.pory"
	end
# 573 "data//maps/MtChimney/scripts.pory"

# 574 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 575 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 576 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 577 "data//maps/MtChimney/scripts.pory"
	end
# 578 "data//maps/MtChimney/scripts.pory"

# 579 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 580 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 581 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 582 "data//maps/MtChimney/scripts.pory"
	end
# 583 "data//maps/MtChimney/scripts.pory"

# 584 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 585 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 586 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 587 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 588 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 589 "data//maps/MtChimney/scripts.pory"
	release
# 590 "data//maps/MtChimney/scripts.pory"
	end
# 591 "data//maps/MtChimney/scripts.pory"

# 592 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 593 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 594 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 595 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 596 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 597 "data//maps/MtChimney/scripts.pory"
	release
# 598 "data//maps/MtChimney/scripts.pory"
	end
# 599 "data//maps/MtChimney/scripts.pory"

# 600 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 601 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 602 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 603 "data//maps/MtChimney/scripts.pory"
	end
# 604 "data//maps/MtChimney/scripts.pory"

# 605 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MoltresFlewOff:
# 606 "data//maps/MtChimney/scripts.pory"
	.string "Moltres woke up and flew\n"
# 607 "data//maps/MtChimney/scripts.pory"
	.string "off somewhere . . .$"
# 608 "data//maps/MtChimney/scripts.pory"

# 609 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 610 "data//maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 611 "data//maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 612 "data//maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 613 "data//maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 614 "data//maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 615 "data//maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 616 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 617 "data//maps/MtChimney/scripts.pory"

# 618 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 619 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 620 "data//maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 621 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 622 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 623 "data//maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 624 "data//maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 625 "data//maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 626 "data//maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 627 "data//maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 628 "data//maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 629 "data//maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 630 "data//maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 631 "data//maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 632 "data//maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 633 "data//maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 634 "data//maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 635 "data//maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 636 "data//maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 637 "data//maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 638 "data//maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 639 "data//maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 640 "data//maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 641 "data//maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 642 "data//maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 643 "data//maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 644 "data//maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 645 "data//maps/MtChimney/scripts.pory"

# 646 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 647 "data//maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 648 "data//maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 649 "data//maps/MtChimney/scripts.pory"

# 650 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 651 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 652 "data//maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 653 "data//maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 654 "data//maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 655 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 656 "data//maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 657 "data//maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 658 "data//maps/MtChimney/scripts.pory"

# 659 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 660 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 661 "data//maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 662 "data//maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 663 "data//maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 664 "data//maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 665 "data//maps/MtChimney/scripts.pory"

# 666 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 667 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 668 "data//maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 669 "data//maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 670 "data//maps/MtChimney/scripts.pory"

# 671 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 672 "data//maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 673 "data//maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 674 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 675 "data//maps/MtChimney/scripts.pory"

# 676 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 677 "data//maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 678 "data//maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 679 "data//maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 680 "data//maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 681 "data//maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 682 "data//maps/MtChimney/scripts.pory"

# 683 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 684 "data//maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 685 "data//maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 686 "data//maps/MtChimney/scripts.pory"

# 687 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 688 "data//maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 689 "data//maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 690 "data//maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 691 "data//maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 692 "data//maps/MtChimney/scripts.pory"

# 693 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 694 "data//maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 695 "data//maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 696 "data//maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 697 "data//maps/MtChimney/scripts.pory"

# 698 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 699 "data//maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 700 "data//maps/MtChimney/scripts.pory"

# 701 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 702 "data//maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 703 "data//maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 704 "data//maps/MtChimney/scripts.pory"

# 705 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 706 "data//maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 707 "data//maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 708 "data//maps/MtChimney/scripts.pory"

# 709 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 710 "data//maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 711 "data//maps/MtChimney/scripts.pory"

# 712 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 713 "data//maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 714 "data//maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 715 "data//maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 716 "data//maps/MtChimney/scripts.pory"

# 717 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 718 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 719 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 720 "data//maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 721 "data//maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 722 "data//maps/MtChimney/scripts.pory"

# 723 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 724 "data//maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 725 "data//maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 726 "data//maps/MtChimney/scripts.pory"

# 727 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 728 "data//maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 729 "data//maps/MtChimney/scripts.pory"

# 730 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 731 "data//maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 732 "data//maps/MtChimney/scripts.pory"

# 733 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 734 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 735 "data//maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 736 "data//maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 737 "data//maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 738 "data//maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 739 "data//maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 740 "data//maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 741 "data//maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 742 "data//maps/MtChimney/scripts.pory"

# 743 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 744 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 745 "data//maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 746 "data//maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 747 "data//maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 748 "data//maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 749 "data//maps/MtChimney/scripts.pory"

# 750 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 751 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 752 "data//maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 753 "data//maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 754 "data//maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 755 "data//maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 756 "data//maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 757 "data//maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 758 "data//maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 759 "data//maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 760 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 761 "data//maps/MtChimney/scripts.pory"

# 762 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 763 "data//maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 764 "data//maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 765 "data//maps/MtChimney/scripts.pory"

# 766 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 767 "data//maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 768 "data//maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 769 "data//maps/MtChimney/scripts.pory"

# 770 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 771 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 772 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 773 "data//maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 774 "data//maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 775 "data//maps/MtChimney/scripts.pory"

# 776 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 777 "data//maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 778 "data//maps/MtChimney/scripts.pory"

# 779 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 780 "data//maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 781 "data//maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 782 "data//maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 783 "data//maps/MtChimney/scripts.pory"

# 784 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 785 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 786 "data//maps/MtChimney/scripts.pory"

# 787 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 788 "data//maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 789 "data//maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 790 "data//maps/MtChimney/scripts.pory"

# 791 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 792 "data//maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 793 "data//maps/MtChimney/scripts.pory"

# 794 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 795 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 796 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 797 "data//maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 798 "data//maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 799 "data//maps/MtChimney/scripts.pory"

# 800 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 801 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 802 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 803 "data//maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 804 "data//maps/MtChimney/scripts.pory"

# 805 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 806 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 807 "data//maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 808 "data//maps/MtChimney/scripts.pory"

# 809 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 810 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 811 "data//maps/MtChimney/scripts.pory"
	.string "it was.$"
# 812 "data//maps/MtChimney/scripts.pory"

# 813 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 814 "data//maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 815 "data//maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 816 "data//maps/MtChimney/scripts.pory"

# 817 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 818 "data//maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 819 "data//maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 820 "data//maps/MtChimney/scripts.pory"

# 821 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 822 "data//maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 823 "data//maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 824 "data//maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 825 "data//maps/MtChimney/scripts.pory"

# 826 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 827 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 828 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 829 "data//maps/MtChimney/scripts.pory"

# 830 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 831 "data//maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 832 "data//maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 833 "data//maps/MtChimney/scripts.pory"

# 834 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 835 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 836 "data//maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 837 "data//maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 838 "data//maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 839 "data//maps/MtChimney/scripts.pory"

# 840 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 841 "data//maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 842 "data//maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 843 "data//maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 844 "data//maps/MtChimney/scripts.pory"

# 845 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 846 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 847 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 848 "data//maps/MtChimney/scripts.pory"

# 849 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 850 "data//maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 851 "data//maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 852 "data//maps/MtChimney/scripts.pory"

# 853 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 854 "data//maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 855 "data//maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 856 "data//maps/MtChimney/scripts.pory"

# 857 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 858 "data//maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 859 "data//maps/MtChimney/scripts.pory"

# 860 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 861 "data//maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 862 "data//maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 863 "data//maps/MtChimney/scripts.pory"

# 864 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 865 "data//maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 866 "data//maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 867 "data//maps/MtChimney/scripts.pory"

# 868 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 869 "data//maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 870 "data//maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 871 "data//maps/MtChimney/scripts.pory"

# 872 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 873 "data//maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 874 "data//maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 875 "data//maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 876 "data//maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 877 "data//maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 878 "data//maps/MtChimney/scripts.pory"

# 879 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 880 "data//maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 881 "data//maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 882 "data//maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 883 "data//maps/MtChimney/scripts.pory"

# 884 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 885 "data//maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 886 "data//maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 887 "data//maps/MtChimney/scripts.pory"

# 888 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 889 "data//maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 890 "data//maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 891 "data//maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 892 "data//maps/MtChimney/scripts.pory"

# 893 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 894 "data//maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 895 "data//maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 896 "data//maps/MtChimney/scripts.pory"

# 897 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 898 "data//maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 899 "data//maps/MtChimney/scripts.pory"

# 900 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 901 "data//maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 902 "data//maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 903 "data//maps/MtChimney/scripts.pory"

# 904 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 905 "data//maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 906 "data//maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 907 "data//maps/MtChimney/scripts.pory"

# 908 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 909 "data//maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 910 "data//maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 911 "data//maps/MtChimney/scripts.pory"

# 912 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 913 "data//maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 914 "data//maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 915 "data//maps/MtChimney/scripts.pory"

# 916 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 917 "data//maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 918 "data//maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
