# 1 "data//maps/DragonsRoost/scripts.pory"

# 2 "data//maps/DragonsRoost/scripts.pory"

# 3 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_MapScripts::
# 4 "data//maps/DragonsRoost/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DragonsRoost_OnResume
# 5 "data//maps/DragonsRoost/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DragonsRoost_OnTransition
# 6 "data//maps/DragonsRoost/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsRoost_OnFrame
# 7 "data//maps/DragonsRoost/scripts.pory"
	.byte 0
# 8 "data//maps/DragonsRoost/scripts.pory"

# 9 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnFrame:
# 10 "data//maps/DragonsRoost/scripts.pory"
	@ map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 0, DragonsRoost_EventScript_DoRayquazaCry
# 11 "data//maps/DragonsRoost/scripts.pory"
	@ map_script_2 VAR_TEMP_1, 1, DragonsRoost_EventScript_DoRayquazaCry
# 12 "data//maps/DragonsRoost/scripts.pory"
	map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2, DragonsRoost_EventScript_ContinueRayquazaScene
# 13 "data//maps/DragonsRoost/scripts.pory"
	map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3, DragonsRoost_EventScript_DoMeteoriteSparkle
# 14 "data//maps/DragonsRoost/scripts.pory"
	.2byte 0
# 15 "data//maps/DragonsRoost/scripts.pory"

# 16 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnResume:
# 17 "data//maps/DragonsRoost/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 18 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsRoost_EventScript_TryRemoveWildMon
# 19 "data//maps/DragonsRoost/scripts.pory"
	end
# 20 "data//maps/DragonsRoost/scripts.pory"

# 21 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveWildMon::
# 22 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 24 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 25 "data//maps/DragonsRoost/scripts.pory"
	return
# 26 "data//maps/DragonsRoost/scripts.pory"

# 27 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnTransition:
# 28 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_DRAGONS_ROOST_METEORITE, DragonsRoost_EventScript_PrepRepeatSparkle
# 29 "data//maps/DragonsRoost/scripts.pory"
	call_if_le VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1, DragonsRoost_EventScript_PrepRayquazaCry
# 30 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_DRAGONS_ROOST_CLONE, DragonsRoost_EventScript_HideClone
# 31 "data//maps/DragonsRoost/scripts.pory"
	call DragonsRoost_EventScript_SetupPlayerCloneGfxId
# 32 "data//maps/DragonsRoost/scripts.pory"
	call DragonsRoost_EventScript_RandomiseOvrWrldMonPos
# 33 "data//maps/DragonsRoost/scripts.pory"
	end
# 34 "data//maps/DragonsRoost/scripts.pory"

# 35 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRayquazaCry::
# 36 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 1
# 37 "data//maps/DragonsRoost/scripts.pory"
	return
# 38 "data//maps/DragonsRoost/scripts.pory"

# 39 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRepeatSparkle::
# 40 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 1
# 41 "data//maps/DragonsRoost/scripts.pory"
	return
# 42 "data//maps/DragonsRoost/scripts.pory"

# 43 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideClone::
# 44 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 45 "data//maps/DragonsRoost/scripts.pory"
	return
# 46 "data//maps/DragonsRoost/scripts.pory"

# 47 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_SetupPlayerCloneGfxId::
# 48 "data//maps/DragonsRoost/scripts.pory"
	checkplayergender
# 49 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, DragonsRoost_EventScript_PlayerCloneMale
# 50 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, DragonsRoost_EventScript_PlayerCloneFemale
# 51 "data//maps/DragonsRoost/scripts.pory"
	end
# 52 "data//maps/DragonsRoost/scripts.pory"

# 53 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneMale::
# 54 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 55 "data//maps/DragonsRoost/scripts.pory"
	return
# 56 "data//maps/DragonsRoost/scripts.pory"

# 57 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneFemale::
# 58 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 59 "data//maps/DragonsRoost/scripts.pory"
	return
# 60 "data//maps/DragonsRoost/scripts.pory"

# 61 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Rayquaza::
# 62 "data//maps/DragonsRoost/scripts.pory"
	lock
# 63 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 64 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 65 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 66 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 67 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 68 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 69 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 70 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 71 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 72 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 73 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 74 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 75 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 76 "data//maps/DragonsRoost/scripts.pory"
	setweather WEATHER_SUNNY
# 77 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 78 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 79 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 80 "data//maps/DragonsRoost/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 81 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 82 "data//maps/DragonsRoost/scripts.pory"
	setobjectxy LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 83 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_CLONE
# 84 "data//maps/DragonsRoost/scripts.pory"
	addobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 85 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE, Common_Movement_FaceUp
# 86 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 87 "data//maps/DragonsRoost/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 88 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 89 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 90 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanUpI
# 91 "data//maps/DragonsRoost/scripts.pory"
	hidefollower
# 92 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 93 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 94 "data//maps/DragonsRoost/scripts.pory"
	release 
# 95 "data//maps/DragonsRoost/scripts.pory"
	end 
# 96 "data//maps/DragonsRoost/scripts.pory"

# 97 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 98 "data//maps/DragonsRoost/scripts.pory"

# 99 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 100 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 101 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 102 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 103 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 104 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 105 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 106 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 107 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 108 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 109 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 110 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 111 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 112 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 113 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 114 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 115 "data//maps/DragonsRoost/scripts.pory"

# 116 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 117 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 118 "data//maps/DragonsRoost/scripts.pory"

# 119 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 120 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 121 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 122 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 123 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 124 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 125 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 126 "data//maps/DragonsRoost/scripts.pory"

# 127 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 128 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 129 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 130 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 131 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 132 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 133 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 134 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 135 "data//maps/DragonsRoost/scripts.pory"

# 136 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanDownII
# 137 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 138 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 139 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 140 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 141 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 142 "data//maps/DragonsRoost/scripts.pory"

# 143 "data//maps/DragonsRoost/scripts.pory"
	resetweather
# 144 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 145 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 146 "data//maps/DragonsRoost/scripts.pory"
	release
# 147 "data//maps/DragonsRoost/scripts.pory"
	end
# 148 "data//maps/DragonsRoost/scripts.pory"

# 149 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 150 "data//maps/DragonsRoost/scripts.pory"
	lock
# 151 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 152 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 153 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 154 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 155 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 156 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 157 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 158 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 159 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 160 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 161 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 162 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 163 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 164 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 165 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 166 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 167 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 168 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 169 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 170 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 171 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 172 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 0
# 173 "data//maps/DragonsRoost/scripts.pory"
	release
# 174 "data//maps/DragonsRoost/scripts.pory"
	end
# 175 "data//maps/DragonsRoost/scripts.pory"

# 176 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 177 "data//maps/DragonsRoost/scripts.pory"
	lock
# 178 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 179 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 180 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 181 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 182 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 183 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 184 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 185 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 186 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 187 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 0
# 188 "data//maps/DragonsRoost/scripts.pory"
	release
# 189 "data//maps/DragonsRoost/scripts.pory"
	end
# 190 "data//maps/DragonsRoost/scripts.pory"

# 191 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 192 "data//maps/DragonsRoost/scripts.pory"
	lock
# 193 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 194 "data//maps/DragonsRoost/scripts.pory"
	release
# 195 "data//maps/DragonsRoost/scripts.pory"
	end
# 196 "data//maps/DragonsRoost/scripts.pory"

# 197 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 198 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 199 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 200 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 201 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 202 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 203 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 204 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 205 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 206 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 207 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 208 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 209 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 210 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 211 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 212 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 213 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 214 "data//maps/DragonsRoost/scripts.pory"
	release
# 215 "data//maps/DragonsRoost/scripts.pory"
	end
# 216 "data//maps/DragonsRoost/scripts.pory"

# 217 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 218 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 219 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 220 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 221 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 222 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 223 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 224 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 225 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 226 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 227 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 228 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 229 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 230 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 231 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 232 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 233 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 234 "data//maps/DragonsRoost/scripts.pory"
	release
# 235 "data//maps/DragonsRoost/scripts.pory"
	end
# 236 "data//maps/DragonsRoost/scripts.pory"

# 237 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 238 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 239 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 240 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 241 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 242 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 243 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 244 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 245 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 246 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 247 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 248 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 249 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 250 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 251 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 252 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 253 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 254 "data//maps/DragonsRoost/scripts.pory"
	release
# 255 "data//maps/DragonsRoost/scripts.pory"
	end
# 256 "data//maps/DragonsRoost/scripts.pory"

# 257 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 258 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 259 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 260 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 261 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 262 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 263 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 264 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 265 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 266 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 267 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 268 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 269 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 270 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 271 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 272 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 273 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 274 "data//maps/DragonsRoost/scripts.pory"
	release
# 275 "data//maps/DragonsRoost/scripts.pory"
	end
# 276 "data//maps/DragonsRoost/scripts.pory"

# 277 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine2::
# 278 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 279 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 280 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 281 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 282 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 283 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 284 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 285 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 286 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 287 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 288 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 289 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 290 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 291 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 292 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 293 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 294 "data//maps/DragonsRoost/scripts.pory"
	release
# 295 "data//maps/DragonsRoost/scripts.pory"
	end
# 296 "data//maps/DragonsRoost/scripts.pory"

# 297 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 298 "data//maps/DragonsRoost/scripts.pory"
	lockall
# 299 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 300 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 301 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 302 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 303 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 304 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 305 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 306 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 307 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 308 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 309 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 310 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 311 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 312 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 313 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 314 "data//maps/DragonsRoost/scripts.pory"
	release
# 315 "data//maps/DragonsRoost/scripts.pory"
	end
# 316 "data//maps/DragonsRoost/scripts.pory"

# 317 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 318 "data//maps/DragonsRoost/scripts.pory"
	release
# 319 "data//maps/DragonsRoost/scripts.pory"
	end
# 320 "data//maps/DragonsRoost/scripts.pory"

# 321 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 322 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 323 "data//maps/DragonsRoost/scripts.pory"
	lock
# 324 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 325 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 326 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 327 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 328 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 329 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 330 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 331 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 332 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 333 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 334 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 335 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 336 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 337 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 338 "data//maps/DragonsRoost/scripts.pory"
	end
# 339 "data//maps/DragonsRoost/scripts.pory"

# 340 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 341 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 342 "data//maps/DragonsRoost/scripts.pory"
	lock
# 343 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 344 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 345 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 346 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 347 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 348 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 349 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 350 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 351 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 352 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 353 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 354 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 355 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 356 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 357 "data//maps/DragonsRoost/scripts.pory"
	end
# 358 "data//maps/DragonsRoost/scripts.pory"

# 359 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 360 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 361 "data//maps/DragonsRoost/scripts.pory"
	lock
# 362 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 363 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 364 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 365 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 366 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 367 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 368 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 369 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 370 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 371 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 372 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 373 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 374 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 375 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 376 "data//maps/DragonsRoost/scripts.pory"
	end
# 377 "data//maps/DragonsRoost/scripts.pory"

# 378 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 379 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 380 "data//maps/DragonsRoost/scripts.pory"
	lock
# 381 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 382 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 383 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 384 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 385 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 386 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 387 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 388 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 389 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 390 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 391 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 392 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 393 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 394 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 395 "data//maps/DragonsRoost/scripts.pory"
	end
# 396 "data//maps/DragonsRoost/scripts.pory"

# 397 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 398 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 399 "data//maps/DragonsRoost/scripts.pory"
	lock
# 400 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 401 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 402 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 403 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 404 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 405 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 406 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 407 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 408 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 409 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 410 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 411 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 412 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 413 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 414 "data//maps/DragonsRoost/scripts.pory"
	end
# 415 "data//maps/DragonsRoost/scripts.pory"

# 416 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 417 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 418 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 419 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 420 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 421 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 422 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 423 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 424 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 425 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 426 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 427 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 428 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 429 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 430 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 431 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 432 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 433 "data//maps/DragonsRoost/scripts.pory"
	release
# 434 "data//maps/DragonsRoost/scripts.pory"
	end
# 435 "data//maps/DragonsRoost/scripts.pory"

# 436 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 437 "data//maps/DragonsRoost/scripts.pory"
	lock
# 438 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 439 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 440 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 441 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 442 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 443 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 444 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 445 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 446 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 447 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 448 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 449 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 450 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 451 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 452 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 453 "data//maps/DragonsRoost/scripts.pory"
	release
# 454 "data//maps/DragonsRoost/scripts.pory"
	end
# 455 "data//maps/DragonsRoost/scripts.pory"

# 456 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 457 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 458 "data//maps/DragonsRoost/scripts.pory"
	release
# 459 "data//maps/DragonsRoost/scripts.pory"
	end
# 460 "data//maps/DragonsRoost/scripts.pory"

# 461 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 462 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 463 "data//maps/DragonsRoost/scripts.pory"
	release
# 464 "data//maps/DragonsRoost/scripts.pory"
	end
# 465 "data//maps/DragonsRoost/scripts.pory"

# 466 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 467 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 468 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 469 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 470 "data//maps/DragonsRoost/scripts.pory"

# 471 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 472 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 473 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 474 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 475 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 476 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 477 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 478 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 479 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 480 "data//maps/DragonsRoost/scripts.pory"

# 481 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 482 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 483 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 484 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 485 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 486 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 487 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 488 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 489 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 490 "data//maps/DragonsRoost/scripts.pory"

# 491 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 492 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 493 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 494 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 495 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 496 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 497 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 498 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 499 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 500 "data//maps/DragonsRoost/scripts.pory"

# 501 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 502 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 503 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 504 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 505 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 506 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 507 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 508 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 509 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 510 "data//maps/DragonsRoost/scripts.pory"

# 511 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 512 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 513 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 514 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 515 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 516 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 517 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 518 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 519 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 520 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 521 "data//maps/DragonsRoost/scripts.pory"

# 522 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 523 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 524 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 525 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 526 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 527 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 528 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 529 "data//maps/DragonsRoost/scripts.pory"

# 530 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 531 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 532 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 533 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 534 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 535 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 536 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 537 "data//maps/DragonsRoost/scripts.pory"

# 538 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 539 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 540 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 541 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 542 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 543 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 544 "data//maps/DragonsRoost/scripts.pory"

# 545 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 546 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 547 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 548 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 549 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 550 "data//maps/DragonsRoost/scripts.pory"

# 551 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 552 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 553 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 554 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 557 "data//maps/DragonsRoost/scripts.pory"

# 558 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 559 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 560 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 561 "data//maps/DragonsRoost/scripts.pory"

# 562 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 563 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 564 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 565 "data//maps/DragonsRoost/scripts.pory"

# 566 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 567 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 568 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 569 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 570 "data//maps/DragonsRoost/scripts.pory"

# 571 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 572 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 573 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 574 "data//maps/DragonsRoost/scripts.pory"

# 575 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 576 "data//maps/DragonsRoost/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 577 "data//maps/DragonsRoost/scripts.pory"

# 578 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 579 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 580 "data//maps/DragonsRoost/scripts.pory"

# 581 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 582 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"

DragonsRoost_EventScript_RandomiseOvrWrldMonPos::
# 587 "data//maps/DragonsRoost/scripts.pory"
	compare VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1
# 599 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1:
# 588 "data//maps/DragonsRoost/scripts.pory"
	random 3
# 589 "data//maps/DragonsRoost/scripts.pory"
	switch VAR_RESULT
# 590 "data//maps/DragonsRoost/scripts.pory"
	case 0, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5
# 592 "data//maps/DragonsRoost/scripts.pory"
	case 1, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6
# 594 "data//maps/DragonsRoost/scripts.pory"
	case 2, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5:
# 591 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6:
# 593 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosB
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7:
# 595 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosC
	return


DragonsRoost_EventScript_OvrWrldMonPosA::
# 604 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 605 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 59, 24
# 606 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 73, 39
# 607 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 115, 42
	return


DragonsRoost_EventScript_OvrWrldMonPosB::
# 612 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 59, 24
# 613 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 20, 41
# 614 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 90, 45
# 615 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 74, 28
	return


DragonsRoost_EventScript_OvrWrldMonPosC::
# 620 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 621 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 47, 25
# 622 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 83, 34
# 623 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 73, 39
	return

