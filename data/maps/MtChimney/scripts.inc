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
	lockall
# 27 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
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
	special InitRoamer
# 63 "data//maps/MtChimney/scripts.pory"
	setseenmon SPECIES_MOLTRES
# 64 "data//maps/MtChimney/scripts.pory"
	releaseall
# 65 "data//maps/MtChimney/scripts.pory"
	end
# 66 "data//maps/MtChimney/scripts.pory"

# 67 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 68 "data//maps/MtChimney/scripts.pory"
	lock
# 69 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 70 "data//maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 71 "data//maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 72 "data//maps/MtChimney/scripts.pory"
	closemessage
# 73 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 74 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 75 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 76 "data//maps/MtChimney/scripts.pory"
	release
# 77 "data//maps/MtChimney/scripts.pory"
	end
# 78 "data//maps/MtChimney/scripts.pory"

# 79 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 80 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 81 "data//maps/MtChimney/scripts.pory"
	return
# 82 "data//maps/MtChimney/scripts.pory"

# 83 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 84 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 85 "data//maps/MtChimney/scripts.pory"
	return
# 86 "data//maps/MtChimney/scripts.pory"

# 87 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 88 "data//maps/MtChimney/scripts.pory"
	lockall
# 89 "data//maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 90 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 91 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 92 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 93 "data//maps/MtChimney/scripts.pory"
	playse SE_PIN
# 94 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 95 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 96 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 97 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 98 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 99 "data//maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 100 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 101 "data//maps/MtChimney/scripts.pory"
	closemessage
# 102 "data//maps/MtChimney/scripts.pory"
	delay 30
# 103 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 104 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 105 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 106 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 107 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 108 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 109 "data//maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 110 "data//maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 111 "data//maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 112 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 113 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 114 "data//maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 115 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 116 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 117 "data//maps/MtChimney/scripts.pory"
	closemessage
# 118 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 119 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 120 "data//maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 121 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 122 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 123 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 124 "data//maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 125 "data//maps/MtChimney/scripts.pory"
	releaseall
# 126 "data//maps/MtChimney/scripts.pory"
	end
# 127 "data//maps/MtChimney/scripts.pory"

# 128 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 129 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 130 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 131 "data//maps/MtChimney/scripts.pory"
	return
# 132 "data//maps/MtChimney/scripts.pory"

# 133 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 134 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 135 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 136 "data//maps/MtChimney/scripts.pory"
	return
# 137 "data//maps/MtChimney/scripts.pory"

# 138 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 139 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 140 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 141 "data//maps/MtChimney/scripts.pory"
	return
# 142 "data//maps/MtChimney/scripts.pory"

# 143 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 144 "data//maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 145 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 146 "data//maps/MtChimney/scripts.pory"
	return
# 147 "data//maps/MtChimney/scripts.pory"

# 148 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 149 "data//maps/MtChimney/scripts.pory"
	lock
# 150 "data//maps/MtChimney/scripts.pory"
	faceplayer
# 151 "data//maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 152 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 153 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 154 "data//maps/MtChimney/scripts.pory"
	checkmoney 200
# 155 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 156 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 157 "data//maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 158 "data//maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 159 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 160 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 161 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 162 "data//maps/MtChimney/scripts.pory"
	release
# 163 "data//maps/MtChimney/scripts.pory"
	end
# 164 "data//maps/MtChimney/scripts.pory"

# 165 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 166 "data//maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 167 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 168 "data//maps/MtChimney/scripts.pory"
	release
# 169 "data//maps/MtChimney/scripts.pory"
	end
# 170 "data//maps/MtChimney/scripts.pory"

# 171 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 172 "data//maps/MtChimney/scripts.pory"
	removemoney 200
# 173 "data//maps/MtChimney/scripts.pory"
	updatemoneybox
# 174 "data//maps/MtChimney/scripts.pory"
	return
# 175 "data//maps/MtChimney/scripts.pory"

# 176 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 177 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 178 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 179 "data//maps/MtChimney/scripts.pory"
	release
# 180 "data//maps/MtChimney/scripts.pory"
	end
# 181 "data//maps/MtChimney/scripts.pory"

# 182 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 183 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 184 "data//maps/MtChimney/scripts.pory"
	hidemoneybox
# 185 "data//maps/MtChimney/scripts.pory"
	release
# 186 "data//maps/MtChimney/scripts.pory"
	end
# 187 "data//maps/MtChimney/scripts.pory"

# 188 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_MoltresFlyOff:
# 189 "data//maps/MtChimney/scripts.pory"
	delay_16
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
	slide_up
# 196 "data//maps/MtChimney/scripts.pory"
	step_end
# 197 "data//maps/MtChimney/scripts.pory"

# 198 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanUp:
# 199 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 200 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 201 "data//maps/MtChimney/scripts.pory"
	walk_slow_up
# 202 "data//maps/MtChimney/scripts.pory"
	step_end
# 203 "data//maps/MtChimney/scripts.pory"

# 204 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_CameraPanDown:
# 205 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 206 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 207 "data//maps/MtChimney/scripts.pory"
	walk_slow_down
# 208 "data//maps/MtChimney/scripts.pory"
	step_end
# 209 "data//maps/MtChimney/scripts.pory"

# 210 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
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
	walk_up
# 217 "data//maps/MtChimney/scripts.pory"
	walk_right
# 218 "data//maps/MtChimney/scripts.pory"
	step_end
# 219 "data//maps/MtChimney/scripts.pory"

# 220 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 221 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 229 "data//maps/MtChimney/scripts.pory"
	step_end
# 230 "data//maps/MtChimney/scripts.pory"

# 231 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 232 "data//maps/MtChimney/scripts.pory"
	walk_up
# 233 "data//maps/MtChimney/scripts.pory"
	walk_up
# 234 "data//maps/MtChimney/scripts.pory"
	walk_up
# 235 "data//maps/MtChimney/scripts.pory"
	walk_up
# 236 "data//maps/MtChimney/scripts.pory"
	walk_up
# 237 "data//maps/MtChimney/scripts.pory"
	walk_right
# 238 "data//maps/MtChimney/scripts.pory"
	walk_right
# 239 "data//maps/MtChimney/scripts.pory"
	step_end
# 240 "data//maps/MtChimney/scripts.pory"

# 241 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 242 "data//maps/MtChimney/scripts.pory"
	walk_left
# 243 "data//maps/MtChimney/scripts.pory"
	walk_left
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
	walk_down
# 251 "data//maps/MtChimney/scripts.pory"
	step_end
# 252 "data//maps/MtChimney/scripts.pory"

# 253 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
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
	walk_left
# 260 "data//maps/MtChimney/scripts.pory"
	walk_left
# 261 "data//maps/MtChimney/scripts.pory"
	walk_down
# 262 "data//maps/MtChimney/scripts.pory"
	walk_down
# 263 "data//maps/MtChimney/scripts.pory"
	walk_down
# 264 "data//maps/MtChimney/scripts.pory"
	walk_down
# 265 "data//maps/MtChimney/scripts.pory"
	walk_left
# 266 "data//maps/MtChimney/scripts.pory"
	walk_left
# 267 "data//maps/MtChimney/scripts.pory"
	walk_left
# 268 "data//maps/MtChimney/scripts.pory"
	walk_left
# 269 "data//maps/MtChimney/scripts.pory"
	walk_left
# 270 "data//maps/MtChimney/scripts.pory"
	walk_down
# 271 "data//maps/MtChimney/scripts.pory"
	step_end
# 272 "data//maps/MtChimney/scripts.pory"

# 273 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 274 "data//maps/MtChimney/scripts.pory"
	walk_down
# 275 "data//maps/MtChimney/scripts.pory"
	walk_down
# 276 "data//maps/MtChimney/scripts.pory"
	walk_down
# 277 "data//maps/MtChimney/scripts.pory"
	walk_down
# 278 "data//maps/MtChimney/scripts.pory"
	walk_left
# 279 "data//maps/MtChimney/scripts.pory"
	walk_left
# 280 "data//maps/MtChimney/scripts.pory"
	walk_left
# 281 "data//maps/MtChimney/scripts.pory"
	walk_down
# 282 "data//maps/MtChimney/scripts.pory"
	step_end
# 283 "data//maps/MtChimney/scripts.pory"

# 284 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 285 "data//maps/MtChimney/scripts.pory"
	walk_right
# 286 "data//maps/MtChimney/scripts.pory"
	walk_down
# 287 "data//maps/MtChimney/scripts.pory"
	walk_down
# 288 "data//maps/MtChimney/scripts.pory"
	walk_down
# 289 "data//maps/MtChimney/scripts.pory"
	walk_down
# 290 "data//maps/MtChimney/scripts.pory"
	walk_left
# 291 "data//maps/MtChimney/scripts.pory"
	walk_left
# 292 "data//maps/MtChimney/scripts.pory"
	walk_left
# 293 "data//maps/MtChimney/scripts.pory"
	walk_left
# 294 "data//maps/MtChimney/scripts.pory"
	walk_left
# 295 "data//maps/MtChimney/scripts.pory"
	walk_down
# 296 "data//maps/MtChimney/scripts.pory"
	walk_down
# 297 "data//maps/MtChimney/scripts.pory"
	walk_down
# 298 "data//maps/MtChimney/scripts.pory"
	walk_down
# 299 "data//maps/MtChimney/scripts.pory"
	step_end
# 300 "data//maps/MtChimney/scripts.pory"

# 301 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
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
	walk_fast_down
# 311 "data//maps/MtChimney/scripts.pory"
	walk_left
# 312 "data//maps/MtChimney/scripts.pory"
	walk_left
# 313 "data//maps/MtChimney/scripts.pory"
	walk_down
# 314 "data//maps/MtChimney/scripts.pory"
	walk_down
# 315 "data//maps/MtChimney/scripts.pory"
	walk_down
# 316 "data//maps/MtChimney/scripts.pory"
	walk_left
# 317 "data//maps/MtChimney/scripts.pory"
	walk_left
# 318 "data//maps/MtChimney/scripts.pory"
	walk_down
# 319 "data//maps/MtChimney/scripts.pory"
	walk_down
# 320 "data//maps/MtChimney/scripts.pory"
	walk_left
# 321 "data//maps/MtChimney/scripts.pory"
	walk_left
# 322 "data//maps/MtChimney/scripts.pory"
	walk_left
# 323 "data//maps/MtChimney/scripts.pory"
	walk_left
# 324 "data//maps/MtChimney/scripts.pory"
	walk_left
# 325 "data//maps/MtChimney/scripts.pory"
	walk_down
# 326 "data//maps/MtChimney/scripts.pory"
	step_end
# 327 "data//maps/MtChimney/scripts.pory"

# 328 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 329 "data//maps/MtChimney/scripts.pory"
	delay_16
# 330 "data//maps/MtChimney/scripts.pory"
	delay_16
# 331 "data//maps/MtChimney/scripts.pory"
	delay_16
# 332 "data//maps/MtChimney/scripts.pory"
	walk_down
# 333 "data//maps/MtChimney/scripts.pory"
	walk_down
# 334 "data//maps/MtChimney/scripts.pory"
	walk_down
# 335 "data//maps/MtChimney/scripts.pory"
	walk_left
# 336 "data//maps/MtChimney/scripts.pory"
	walk_left
# 337 "data//maps/MtChimney/scripts.pory"
	walk_left
# 338 "data//maps/MtChimney/scripts.pory"
	walk_down
# 339 "data//maps/MtChimney/scripts.pory"
	step_end
# 340 "data//maps/MtChimney/scripts.pory"

# 341 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 342 "data//maps/MtChimney/scripts.pory"
	delay_16
# 343 "data//maps/MtChimney/scripts.pory"
	walk_left
# 344 "data//maps/MtChimney/scripts.pory"
	walk_down
# 345 "data//maps/MtChimney/scripts.pory"
	walk_down
# 346 "data//maps/MtChimney/scripts.pory"
	walk_down
# 347 "data//maps/MtChimney/scripts.pory"
	walk_down
# 348 "data//maps/MtChimney/scripts.pory"
	walk_left
# 349 "data//maps/MtChimney/scripts.pory"
	walk_left
# 350 "data//maps/MtChimney/scripts.pory"
	walk_left
# 351 "data//maps/MtChimney/scripts.pory"
	walk_left
# 352 "data//maps/MtChimney/scripts.pory"
	walk_left
# 353 "data//maps/MtChimney/scripts.pory"
	walk_down
# 354 "data//maps/MtChimney/scripts.pory"
	walk_down
# 355 "data//maps/MtChimney/scripts.pory"
	walk_down
# 356 "data//maps/MtChimney/scripts.pory"
	walk_down
# 357 "data//maps/MtChimney/scripts.pory"
	step_end
# 358 "data//maps/MtChimney/scripts.pory"

# 359 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 360 "data//maps/MtChimney/scripts.pory"
	delay_16
# 361 "data//maps/MtChimney/scripts.pory"
	walk_left
# 362 "data//maps/MtChimney/scripts.pory"
	walk_left
# 363 "data//maps/MtChimney/scripts.pory"
	walk_down
# 364 "data//maps/MtChimney/scripts.pory"
	walk_down
# 365 "data//maps/MtChimney/scripts.pory"
	walk_down
# 366 "data//maps/MtChimney/scripts.pory"
	walk_left
# 367 "data//maps/MtChimney/scripts.pory"
	walk_left
# 368 "data//maps/MtChimney/scripts.pory"
	walk_down
# 369 "data//maps/MtChimney/scripts.pory"
	walk_down
# 370 "data//maps/MtChimney/scripts.pory"
	walk_left
# 371 "data//maps/MtChimney/scripts.pory"
	walk_left
# 372 "data//maps/MtChimney/scripts.pory"
	walk_left
# 373 "data//maps/MtChimney/scripts.pory"
	walk_left
# 374 "data//maps/MtChimney/scripts.pory"
	walk_left
# 375 "data//maps/MtChimney/scripts.pory"
	walk_down
# 376 "data//maps/MtChimney/scripts.pory"
	step_end
# 377 "data//maps/MtChimney/scripts.pory"

# 378 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 379 "data//maps/MtChimney/scripts.pory"
	delay_16
# 380 "data//maps/MtChimney/scripts.pory"
	walk_down
# 381 "data//maps/MtChimney/scripts.pory"
	walk_left
# 382 "data//maps/MtChimney/scripts.pory"
	walk_left
# 383 "data//maps/MtChimney/scripts.pory"
	walk_left
# 384 "data//maps/MtChimney/scripts.pory"
	walk_left
# 385 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 386 "data//maps/MtChimney/scripts.pory"
	step_end
# 387 "data//maps/MtChimney/scripts.pory"

# 388 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 389 "data//maps/MtChimney/scripts.pory"
	walk_down
# 390 "data//maps/MtChimney/scripts.pory"
	walk_down
# 391 "data//maps/MtChimney/scripts.pory"
	walk_down
# 392 "data//maps/MtChimney/scripts.pory"
	walk_down
# 393 "data//maps/MtChimney/scripts.pory"
	walk_left
# 394 "data//maps/MtChimney/scripts.pory"
	walk_left
# 395 "data//maps/MtChimney/scripts.pory"
	walk_left
# 396 "data//maps/MtChimney/scripts.pory"
	walk_left
# 397 "data//maps/MtChimney/scripts.pory"
	walk_left
# 398 "data//maps/MtChimney/scripts.pory"
	walk_down
# 399 "data//maps/MtChimney/scripts.pory"
	walk_down
# 400 "data//maps/MtChimney/scripts.pory"
	walk_down
# 401 "data//maps/MtChimney/scripts.pory"
	walk_down
# 402 "data//maps/MtChimney/scripts.pory"
	step_end
# 403 "data//maps/MtChimney/scripts.pory"

# 404 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 405 "data//maps/MtChimney/scripts.pory"
	walk_down
# 406 "data//maps/MtChimney/scripts.pory"
	step_end
# 407 "data//maps/MtChimney/scripts.pory"

# 408 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
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
	walk_down
# 416 "data//maps/MtChimney/scripts.pory"
	step_end
# 417 "data//maps/MtChimney/scripts.pory"

# 418 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 419 "data//maps/MtChimney/scripts.pory"
	delay_16
# 420 "data//maps/MtChimney/scripts.pory"
	delay_16
# 421 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 422 "data//maps/MtChimney/scripts.pory"
	delay_16
# 423 "data//maps/MtChimney/scripts.pory"
	walk_down
# 424 "data//maps/MtChimney/scripts.pory"
	walk_down
# 425 "data//maps/MtChimney/scripts.pory"
	walk_down
# 426 "data//maps/MtChimney/scripts.pory"
	walk_down
# 427 "data//maps/MtChimney/scripts.pory"
	walk_down
# 428 "data//maps/MtChimney/scripts.pory"
	step_end
# 429 "data//maps/MtChimney/scripts.pory"

# 430 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
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
	delay_16
# 437 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 438 "data//maps/MtChimney/scripts.pory"
	delay_16
# 439 "data//maps/MtChimney/scripts.pory"
	walk_down
# 440 "data//maps/MtChimney/scripts.pory"
	walk_down
# 441 "data//maps/MtChimney/scripts.pory"
	step_end
# 442 "data//maps/MtChimney/scripts.pory"

# 443 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 444 "data//maps/MtChimney/scripts.pory"
	lock_facing_direction
# 445 "data//maps/MtChimney/scripts.pory"
	walk_fast_left
# 446 "data//maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 447 "data//maps/MtChimney/scripts.pory"
	face_right
# 448 "data//maps/MtChimney/scripts.pory"
	step_end
# 449 "data//maps/MtChimney/scripts.pory"

# 450 "data//maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 451 "data//maps/MtChimney/scripts.pory"
	walk_left
# 452 "data//maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 453 "data//maps/MtChimney/scripts.pory"
	delay_16
# 454 "data//maps/MtChimney/scripts.pory"
	step_end
# 455 "data//maps/MtChimney/scripts.pory"

# 456 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 457 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 458 "data//maps/MtChimney/scripts.pory"
	end
# 459 "data//maps/MtChimney/scripts.pory"

# 460 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 461 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 462 "data//maps/MtChimney/scripts.pory"
	end
# 463 "data//maps/MtChimney/scripts.pory"

# 464 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 465 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 466 "data//maps/MtChimney/scripts.pory"
	end
# 467 "data//maps/MtChimney/scripts.pory"

# 468 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 469 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 470 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 471 "data//maps/MtChimney/scripts.pory"
	end
# 472 "data//maps/MtChimney/scripts.pory"

# 473 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 474 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 475 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 476 "data//maps/MtChimney/scripts.pory"
	end
# 477 "data//maps/MtChimney/scripts.pory"

# 478 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 479 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 480 "data//maps/MtChimney/scripts.pory"
	end
# 481 "data//maps/MtChimney/scripts.pory"

# 482 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 483 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 484 "data//maps/MtChimney/scripts.pory"
	end
# 485 "data//maps/MtChimney/scripts.pory"

# 486 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 487 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 488 "data//maps/MtChimney/scripts.pory"
	end
# 489 "data//maps/MtChimney/scripts.pory"

# 490 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 491 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 492 "data//maps/MtChimney/scripts.pory"
	end
# 493 "data//maps/MtChimney/scripts.pory"

# 494 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 495 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 496 "data//maps/MtChimney/scripts.pory"
	end
# 497 "data//maps/MtChimney/scripts.pory"

# 498 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 499 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 500 "data//maps/MtChimney/scripts.pory"
	end
# 501 "data//maps/MtChimney/scripts.pory"

# 502 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 503 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 504 "data//maps/MtChimney/scripts.pory"
	end
# 505 "data//maps/MtChimney/scripts.pory"

# 506 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 507 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 508 "data//maps/MtChimney/scripts.pory"
	end
# 509 "data//maps/MtChimney/scripts.pory"

# 510 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 511 "data//maps/MtChimney/scripts.pory"
	lockall
# 512 "data//maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 513 "data//maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 514 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 515 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 516 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 517 "data//maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 518 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 519 "data//maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 520 "data//maps/MtChimney/scripts.pory"
	releaseall
# 521 "data//maps/MtChimney/scripts.pory"
	end
# 522 "data//maps/MtChimney/scripts.pory"

# 523 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 524 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 525 "data//maps/MtChimney/scripts.pory"
	releaseall
# 526 "data//maps/MtChimney/scripts.pory"
	end
# 527 "data//maps/MtChimney/scripts.pory"

# 528 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 529 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 530 "data//maps/MtChimney/scripts.pory"
	releaseall
# 531 "data//maps/MtChimney/scripts.pory"
	end
# 532 "data//maps/MtChimney/scripts.pory"

# 533 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 534 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 535 "data//maps/MtChimney/scripts.pory"
	releaseall
# 536 "data//maps/MtChimney/scripts.pory"
	end
# 537 "data//maps/MtChimney/scripts.pory"

# 538 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 539 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 540 "data//maps/MtChimney/scripts.pory"
	end
# 541 "data//maps/MtChimney/scripts.pory"

# 542 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 543 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 544 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 545 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 546 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 547 "data//maps/MtChimney/scripts.pory"
	release
# 548 "data//maps/MtChimney/scripts.pory"
	end
# 549 "data//maps/MtChimney/scripts.pory"

# 550 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 551 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 552 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 553 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 554 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 555 "data//maps/MtChimney/scripts.pory"
	release
# 556 "data//maps/MtChimney/scripts.pory"
	end
# 557 "data//maps/MtChimney/scripts.pory"

# 558 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 559 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 560 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 561 "data//maps/MtChimney/scripts.pory"
	end
# 562 "data//maps/MtChimney/scripts.pory"

# 563 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 564 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 565 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 566 "data//maps/MtChimney/scripts.pory"
	end
# 567 "data//maps/MtChimney/scripts.pory"

# 568 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 569 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 570 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 571 "data//maps/MtChimney/scripts.pory"
	end
# 572 "data//maps/MtChimney/scripts.pory"

# 573 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 574 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 575 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 576 "data//maps/MtChimney/scripts.pory"
	end
# 577 "data//maps/MtChimney/scripts.pory"

# 578 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 579 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 580 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 581 "data//maps/MtChimney/scripts.pory"
	end
# 582 "data//maps/MtChimney/scripts.pory"

# 583 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 584 "data//maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 585 "data//maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 586 "data//maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 587 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 588 "data//maps/MtChimney/scripts.pory"
	release
# 589 "data//maps/MtChimney/scripts.pory"
	end
# 590 "data//maps/MtChimney/scripts.pory"

# 591 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 592 "data//maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 593 "data//maps/MtChimney/scripts.pory"
	waitmovement 0
# 594 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 595 "data//maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 596 "data//maps/MtChimney/scripts.pory"
	release
# 597 "data//maps/MtChimney/scripts.pory"
	end
# 598 "data//maps/MtChimney/scripts.pory"

# 599 "data//maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 600 "data//maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 601 "data//maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 602 "data//maps/MtChimney/scripts.pory"
	end
# 603 "data//maps/MtChimney/scripts.pory"

# 604 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MoltresFlewOff:
# 605 "data//maps/MtChimney/scripts.pory"
	.string "Moltres woke up and flew\n"
# 606 "data//maps/MtChimney/scripts.pory"
	.string "off somewhere . . .$"
# 607 "data//maps/MtChimney/scripts.pory"

# 608 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 609 "data//maps/MtChimney/scripts.pory"
	.string "The power contained in the METEORITE…\p"
# 610 "data//maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 611 "data//maps/MtChimney/scripts.pory"
	.string "machine, MT. CHIMNEY's volcanic\l"
# 612 "data//maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 613 "data//maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 614 "data//maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 615 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 616 "data//maps/MtChimney/scripts.pory"

# 617 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 618 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: Hm?\n"
# 619 "data//maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 620 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 621 "data//maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 622 "data//maps/MtChimney/scripts.pory"
	.string "I'd heard ARCHIE bemoaning a child\n"
# 623 "data//maps/MtChimney/scripts.pory"
	.string "who's been meddling in TEAM AQUA's\l"
# 624 "data//maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 625 "data//maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 626 "data//maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 627 "data//maps/MtChimney/scripts.pory"
	.string "interfering with us, TEAM MAGMA?\p"
# 628 "data//maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 629 "data//maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 630 "data//maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 631 "data//maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 632 "data//maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 633 "data//maps/MtChimney/scripts.pory"
	.string "That is why TEAM MAGMA is dedicated\n"
# 634 "data//maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 635 "data//maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 636 "data//maps/MtChimney/scripts.pory"
	.string "humankind and POKéMON!\p"
# 637 "data//maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 638 "data//maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 639 "data//maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 640 "data//maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 641 "data//maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 642 "data//maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 643 "data//maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 644 "data//maps/MtChimney/scripts.pory"

# 645 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 646 "data//maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 647 "data//maps/MtChimney/scripts.pory"
	.string "I, MAXIE, was caught off guard?!$"
# 648 "data//maps/MtChimney/scripts.pory"

# 649 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 650 "data//maps/MtChimney/scripts.pory"
	.string "MAXIE: But, enough.\n"
# 651 "data//maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 652 "data//maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 653 "data//maps/MtChimney/scripts.pory"
	.string "you've seen of TEAM MAGMA.\p"
# 654 "data//maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 655 "data//maps/MtChimney/scripts.pory"
	.string "Even without the METEORITE, if we\n"
# 656 "data//maps/MtChimney/scripts.pory"
	.string "obtain that ORB… Fufufu…$"
# 657 "data//maps/MtChimney/scripts.pory"

# 658 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 659 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 660 "data//maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 661 "data//maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 662 "data//maps/MtChimney/scripts.pory"
	.string "I've already delivered the METEORITE\l"
# 663 "data//maps/MtChimney/scripts.pory"
	.string "from METEOR FALLS to the BOSS!$"
# 664 "data//maps/MtChimney/scripts.pory"

# 665 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 666 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 667 "data//maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 668 "data//maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 669 "data//maps/MtChimney/scripts.pory"

# 670 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 671 "data//maps/MtChimney/scripts.pory"
	.string "BOSS, hurry!\n"
# 672 "data//maps/MtChimney/scripts.pory"
	.string "Give it the METEORITE's energy!\p"
# 673 "data//maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 674 "data//maps/MtChimney/scripts.pory"

# 675 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 676 "data//maps/MtChimney/scripts.pory"
	.string "We of TEAM MAGMA are working hard for\n"
# 677 "data//maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 678 "data//maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 679 "data//maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 680 "data//maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 681 "data//maps/MtChimney/scripts.pory"

# 682 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 683 "data//maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 684 "data//maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 685 "data//maps/MtChimney/scripts.pory"

# 686 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 687 "data//maps/MtChimney/scripts.pory"
	.string "Our BOSS says, “It will make everyone\n"
# 688 "data//maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 689 "data//maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 690 "data//maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 691 "data//maps/MtChimney/scripts.pory"

# 692 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 693 "data//maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 694 "data//maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 695 "data//maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 696 "data//maps/MtChimney/scripts.pory"

# 697 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 698 "data//maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 699 "data//maps/MtChimney/scripts.pory"

# 700 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 701 "data//maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 702 "data//maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 703 "data//maps/MtChimney/scripts.pory"

# 704 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 705 "data//maps/MtChimney/scripts.pory"
	.string "That annoying TEAM AQUA…\n"
# 706 "data//maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 707 "data//maps/MtChimney/scripts.pory"

# 708 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 709 "data//maps/MtChimney/scripts.pory"
	.string "METEORITES pack amazing power!$"
# 710 "data//maps/MtChimney/scripts.pory"

# 711 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 712 "data//maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 713 "data//maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 714 "data//maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 715 "data//maps/MtChimney/scripts.pory"

# 716 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 717 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM MAGMA!\p"
# 718 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM AQUA!\p"
# 719 "data//maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 720 "data//maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 721 "data//maps/MtChimney/scripts.pory"

# 722 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 723 "data//maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 724 "data//maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 725 "data//maps/MtChimney/scripts.pory"

# 726 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 727 "data//maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 728 "data//maps/MtChimney/scripts.pory"

# 729 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 730 "data//maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 731 "data//maps/MtChimney/scripts.pory"

# 732 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 733 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grr, {PLAYER}!\n"
# 734 "data//maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 735 "data//maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 736 "data//maps/MtChimney/scripts.pory"
	.string "of TEAM MAGMA are up to!\p"
# 737 "data//maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 738 "data//maps/MtChimney/scripts.pory"
	.string "METEORITE's power into the volcano!\p"
# 739 "data//maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 740 "data//maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 741 "data//maps/MtChimney/scripts.pory"

# 742 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 743 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: Grrr…\p"
# 744 "data//maps/MtChimney/scripts.pory"
	.string "I want to stop that MAXIE,\n"
# 745 "data//maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 746 "data//maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 747 "data//maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 748 "data//maps/MtChimney/scripts.pory"

# 749 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 750 "data//maps/MtChimney/scripts.pory"
	.string "ARCHIE: {PLAYER}!\n"
# 751 "data//maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 752 "data//maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted TEAM\n"
# 753 "data//maps/MtChimney/scripts.pory"
	.string "MAGMA's destructive plan!\p"
# 754 "data//maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 755 "data//maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 756 "data//maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 757 "data//maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 758 "data//maps/MtChimney/scripts.pory"
	.string "our pursuit of TEAM MAGMA.\p"
# 759 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 760 "data//maps/MtChimney/scripts.pory"

# 761 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 762 "data//maps/MtChimney/scripts.pory"
	.string "Darn… TEAM MAGMA outnumbers us!\n"
# 763 "data//maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 764 "data//maps/MtChimney/scripts.pory"

# 765 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 766 "data//maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 767 "data//maps/MtChimney/scripts.pory"
	.string "less habitats for WATER POKéMON!$"
# 768 "data//maps/MtChimney/scripts.pory"

# 769 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 770 "data//maps/MtChimney/scripts.pory"
	.string "We're TEAM AQUA!\p"
# 771 "data//maps/MtChimney/scripts.pory"
	.string "They're TEAM MAGMA!\p"
# 772 "data//maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 773 "data//maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 774 "data//maps/MtChimney/scripts.pory"

# 775 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 776 "data//maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 777 "data//maps/MtChimney/scripts.pory"

# 778 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 779 "data//maps/MtChimney/scripts.pory"
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
# 780 "data//maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 781 "data//maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 782 "data//maps/MtChimney/scripts.pory"

# 783 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 784 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 785 "data//maps/MtChimney/scripts.pory"

# 786 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 787 "data//maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 788 "data//maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 789 "data//maps/MtChimney/scripts.pory"

# 790 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 791 "data//maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 792 "data//maps/MtChimney/scripts.pory"

# 793 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine:
# 794 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 795 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 796 "data//maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 797 "data//maps/MtChimney/scripts.pory"
	.string "energy in the METEORITE.$"
# 798 "data//maps/MtChimney/scripts.pory"

# 799 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 800 "data//maps/MtChimney/scripts.pory"
	.string "A METEORITE is fitted on a mysterious\n"
# 801 "data//maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 802 "data//maps/MtChimney/scripts.pory"
	.string "Do you want to remove the METEORITE?$"
# 803 "data//maps/MtChimney/scripts.pory"

# 804 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 805 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the METEORITE from\n"
# 806 "data//maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 807 "data//maps/MtChimney/scripts.pory"

# 808 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 809 "data//maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the METEORITE where\n"
# 810 "data//maps/MtChimney/scripts.pory"
	.string "it was.$"
# 811 "data//maps/MtChimney/scripts.pory"

# 812 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 813 "data//maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 814 "data//maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 815 "data//maps/MtChimney/scripts.pory"

# 816 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 817 "data//maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} JAGGED PATH\n"
# 818 "data//maps/MtChimney/scripts.pory"
	.string "LAVARIDGE TOWN AHEAD$"
# 819 "data//maps/MtChimney/scripts.pory"

# 820 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 821 "data//maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 822 "data//maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 823 "data//maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 824 "data//maps/MtChimney/scripts.pory"

# 825 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 826 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 827 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 828 "data//maps/MtChimney/scripts.pory"

# 829 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 830 "data//maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 831 "data//maps/MtChimney/scripts.pory"
	.string "myself an EXPERT now, can I?$"
# 832 "data//maps/MtChimney/scripts.pory"

# 833 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 834 "data//maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 835 "data//maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 836 "data//maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 837 "data//maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 838 "data//maps/MtChimney/scripts.pory"

# 839 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 840 "data//maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 841 "data//maps/MtChimney/scripts.pory"
	.string "of your POKéMON, why, you should be\l"
# 842 "data//maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 843 "data//maps/MtChimney/scripts.pory"

# 844 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 845 "data//maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 846 "data//maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 847 "data//maps/MtChimney/scripts.pory"

# 848 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 849 "data//maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 850 "data//maps/MtChimney/scripts.pory"
	.string "with the hearts of your POKéMON.$"
# 851 "data//maps/MtChimney/scripts.pory"

# 852 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 853 "data//maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 854 "data//maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 855 "data//maps/MtChimney/scripts.pory"

# 856 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 857 "data//maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 858 "data//maps/MtChimney/scripts.pory"

# 859 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 860 "data//maps/MtChimney/scripts.pory"
	.string "The heat of MT. CHIMNEY warms\n"
# 861 "data//maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 862 "data//maps/MtChimney/scripts.pory"

# 863 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 864 "data//maps/MtChimney/scripts.pory"
	.string "I've finally made it to MT. CHIMNEY.\n"
# 865 "data//maps/MtChimney/scripts.pory"
	.string "I want to make my POKéMON battle!$"
# 866 "data//maps/MtChimney/scripts.pory"

# 867 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 868 "data//maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 869 "data//maps/MtChimney/scripts.pory"
	.string "It's like a MT. CHIMNEY eruption!$"
# 870 "data//maps/MtChimney/scripts.pory"

# 871 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 872 "data//maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 873 "data//maps/MtChimney/scripts.pory"
	.string "MT. CHIMNEY. It would be a shame if\l"
# 874 "data//maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 875 "data//maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 876 "data//maps/MtChimney/scripts.pory"
	.string "COOKIES as souvenirs.$"
# 877 "data//maps/MtChimney/scripts.pory"

# 878 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 879 "data//maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 880 "data//maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 881 "data//maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 882 "data//maps/MtChimney/scripts.pory"

# 883 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 884 "data//maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 885 "data//maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 886 "data//maps/MtChimney/scripts.pory"

# 887 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 888 "data//maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 889 "data//maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 890 "data//maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 891 "data//maps/MtChimney/scripts.pory"

# 892 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 893 "data//maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 894 "data//maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 895 "data//maps/MtChimney/scripts.pory"

# 896 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 897 "data//maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 898 "data//maps/MtChimney/scripts.pory"

# 899 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 900 "data//maps/MtChimney/scripts.pory"
	.string "I think I need a dip in LAVARIDGE\n"
# 901 "data//maps/MtChimney/scripts.pory"
	.string "HOT SPRING with the locals!$"
# 902 "data//maps/MtChimney/scripts.pory"

# 903 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 904 "data//maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 905 "data//maps/MtChimney/scripts.pory"
	.string "Let me register you in my POKéNAV.$"
# 906 "data//maps/MtChimney/scripts.pory"

# 907 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 908 "data//maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 909 "data//maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 910 "data//maps/MtChimney/scripts.pory"

# 911 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 912 "data//maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 913 "data//maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 914 "data//maps/MtChimney/scripts.pory"

# 915 "data//maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 916 "data//maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 917 "data//maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
