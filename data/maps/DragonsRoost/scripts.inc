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
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsRoost_EventScript_TryRemoveZapdos
# 19 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsRoost_EventScript_TryRemoveWildMon
# 20 "data//maps/DragonsRoost/scripts.pory"
	end
# 21 "data//maps/DragonsRoost/scripts.pory"
	end
# 22 "data//maps/DragonsRoost/scripts.pory"

# 23 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveWildMon::
# 24 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 25 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 26 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 27 "data//maps/DragonsRoost/scripts.pory"
	return
# 28 "data//maps/DragonsRoost/scripts.pory"

# 29 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnTransition:
# 30 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_DRAGONS_ROOST_METEORITE, DragonsRoost_EventScript_PrepRepeatSparkle
# 31 "data//maps/DragonsRoost/scripts.pory"
	call_if_le VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1, DragonsRoost_EventScript_PrepRayquazaCry
# 32 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, DragonsRoost_EventScript_HideZapdos
# 33 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, DragonsRoost_EventScript_TryShowZapdos
# 34 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_DRAGONS_ROOST_CLONE, DragonsRoost_EventScript_HideClone
# 35 "data//maps/DragonsRoost/scripts.pory"
	call DragonsRoost_EventScript_SetupPlayerCloneGfxId
# 36 "data//maps/DragonsRoost/scripts.pory"
	call DragonsRoost_EventScript_RandomiseOvrWrldMonPos
# 37 "data//maps/DragonsRoost/scripts.pory"
	end
# 38 "data//maps/DragonsRoost/scripts.pory"

# 39 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRayquazaCry::
# 40 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 1
# 41 "data//maps/DragonsRoost/scripts.pory"
	return
# 42 "data//maps/DragonsRoost/scripts.pory"

# 43 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRepeatSparkle::
# 44 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 1
# 45 "data//maps/DragonsRoost/scripts.pory"
	return
# 46 "data//maps/DragonsRoost/scripts.pory"

# 47 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideClone::
# 48 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 49 "data//maps/DragonsRoost/scripts.pory"
	return
# 50 "data//maps/DragonsRoost/scripts.pory"

# 51 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_SetupPlayerCloneGfxId::
# 52 "data//maps/DragonsRoost/scripts.pory"
	checkplayergender
# 53 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, DragonsRoost_EventScript_PlayerCloneMale
# 54 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, DragonsRoost_EventScript_PlayerCloneFemale
# 55 "data//maps/DragonsRoost/scripts.pory"
	end
# 56 "data//maps/DragonsRoost/scripts.pory"

# 57 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneMale::
# 58 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 59 "data//maps/DragonsRoost/scripts.pory"
	return
# 60 "data//maps/DragonsRoost/scripts.pory"

# 61 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneFemale::
# 62 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 63 "data//maps/DragonsRoost/scripts.pory"
	return
# 64 "data//maps/DragonsRoost/scripts.pory"

# 65 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideZapdos::
# 66 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 67 "data//maps/DragonsRoost/scripts.pory"
	return
# 68 "data//maps/DragonsRoost/scripts.pory"

# 69 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryShowZapdos::
# 70 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 71 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 72 "data//maps/DragonsRoost/scripts.pory"
	return
# 73 "data//maps/DragonsRoost/scripts.pory"

# 74 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Rayquaza::
# 75 "data//maps/DragonsRoost/scripts.pory"
	lock
# 76 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 77 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 78 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 79 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 80 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 81 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 82 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 83 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 84 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 85 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 86 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 87 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 88 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 89 "data//maps/DragonsRoost/scripts.pory"
	setweather WEATHER_SUNNY
# 90 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 91 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 92 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 93 "data//maps/DragonsRoost/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 94 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 95 "data//maps/DragonsRoost/scripts.pory"
	setobjectxy LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 96 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_CLONE
# 97 "data//maps/DragonsRoost/scripts.pory"
	addobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 98 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE, Common_Movement_FaceUp
# 99 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 100 "data//maps/DragonsRoost/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 101 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 102 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 103 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanUpI
# 104 "data//maps/DragonsRoost/scripts.pory"
	hidefollower
# 105 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 106 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 107 "data//maps/DragonsRoost/scripts.pory"
	release 
# 108 "data//maps/DragonsRoost/scripts.pory"
	end 
# 109 "data//maps/DragonsRoost/scripts.pory"

# 110 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 111 "data//maps/DragonsRoost/scripts.pory"

# 112 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 113 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 114 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 115 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 116 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 117 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 118 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 119 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 120 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 121 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 122 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 123 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 124 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 125 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 126 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 127 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 128 "data//maps/DragonsRoost/scripts.pory"

# 129 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 130 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 131 "data//maps/DragonsRoost/scripts.pory"

# 132 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 133 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 134 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 135 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 136 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 137 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 138 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 139 "data//maps/DragonsRoost/scripts.pory"

# 140 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 141 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 142 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 143 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 144 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 145 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 146 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 147 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 148 "data//maps/DragonsRoost/scripts.pory"

# 149 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanDownII
# 150 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 151 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 152 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 153 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 154 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 155 "data//maps/DragonsRoost/scripts.pory"

# 156 "data//maps/DragonsRoost/scripts.pory"
	resetweather
# 157 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 158 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 159 "data//maps/DragonsRoost/scripts.pory"
	release
# 160 "data//maps/DragonsRoost/scripts.pory"
	end
# 161 "data//maps/DragonsRoost/scripts.pory"

# 162 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 163 "data//maps/DragonsRoost/scripts.pory"
	lock
# 164 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 165 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 166 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 167 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 168 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 169 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 170 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 171 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 172 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 173 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 174 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 175 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 176 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 177 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 178 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 179 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 180 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 181 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 182 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 183 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 0
# 184 "data//maps/DragonsRoost/scripts.pory"
	release
# 185 "data//maps/DragonsRoost/scripts.pory"
	end
# 186 "data//maps/DragonsRoost/scripts.pory"

# 187 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 188 "data//maps/DragonsRoost/scripts.pory"
	lock
# 189 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 190 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 191 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 192 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 193 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 194 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 195 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 196 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 197 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 198 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 0
# 199 "data//maps/DragonsRoost/scripts.pory"
	release
# 200 "data//maps/DragonsRoost/scripts.pory"
	end
# 201 "data//maps/DragonsRoost/scripts.pory"

# 202 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 203 "data//maps/DragonsRoost/scripts.pory"
	lock
# 204 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 205 "data//maps/DragonsRoost/scripts.pory"
	release
# 206 "data//maps/DragonsRoost/scripts.pory"
	end
# 207 "data//maps/DragonsRoost/scripts.pory"

# 208 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 209 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 210 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 211 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 212 "data//maps/DragonsRoost/scripts.pory"
	return
# 213 "data//maps/DragonsRoost/scripts.pory"

# 214 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 215 "data//maps/DragonsRoost/scripts.pory"
	lock
# 216 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 217 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 218 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 219 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 220 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 221 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 222 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 223 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 224 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 225 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 226 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 227 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 228 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 229 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 230 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 231 "data//maps/DragonsRoost/scripts.pory"
	release
# 232 "data//maps/DragonsRoost/scripts.pory"
	end
# 233 "data//maps/DragonsRoost/scripts.pory"

# 234 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 235 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 236 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 237 "data//maps/DragonsRoost/scripts.pory"
	release
# 238 "data//maps/DragonsRoost/scripts.pory"
	end
# 239 "data//maps/DragonsRoost/scripts.pory"

# 240 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 241 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 242 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 243 "data//maps/DragonsRoost/scripts.pory"
	release
# 244 "data//maps/DragonsRoost/scripts.pory"
	end
# 245 "data//maps/DragonsRoost/scripts.pory"

# 246 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 247 "data//maps/DragonsRoost/scripts.pory"
	lock
# 248 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 249 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 250 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 251 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 252 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 253 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 254 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 255 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 256 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 257 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 258 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 259 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 260 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 261 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 262 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 263 "data//maps/DragonsRoost/scripts.pory"
	release
# 264 "data//maps/DragonsRoost/scripts.pory"
	end
# 265 "data//maps/DragonsRoost/scripts.pory"

# 266 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 267 "data//maps/DragonsRoost/scripts.pory"
	lock
# 268 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 269 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 270 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 271 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 272 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 273 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 274 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 275 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 276 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 277 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 278 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 279 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 280 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 281 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 282 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 283 "data//maps/DragonsRoost/scripts.pory"
	release
# 284 "data//maps/DragonsRoost/scripts.pory"
	end
# 285 "data//maps/DragonsRoost/scripts.pory"

# 286 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 287 "data//maps/DragonsRoost/scripts.pory"
	lock
# 288 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 289 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 290 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 291 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 292 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 293 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 294 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 295 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 296 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 297 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 298 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 299 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 300 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 301 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 302 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 303 "data//maps/DragonsRoost/scripts.pory"
	release
# 304 "data//maps/DragonsRoost/scripts.pory"
	end
# 305 "data//maps/DragonsRoost/scripts.pory"

# 306 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 307 "data//maps/DragonsRoost/scripts.pory"
	lock
# 308 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 309 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 310 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 311 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 312 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 313 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 314 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 315 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 316 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 317 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 318 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 319 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 320 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 321 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 322 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 323 "data//maps/DragonsRoost/scripts.pory"
	release
# 324 "data//maps/DragonsRoost/scripts.pory"
	end
# 325 "data//maps/DragonsRoost/scripts.pory"

# 326 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine2::
# 327 "data//maps/DragonsRoost/scripts.pory"
	lock
# 328 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 329 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 330 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 331 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 332 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 333 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 334 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 335 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 336 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 337 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 338 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 339 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 340 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 341 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 342 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 343 "data//maps/DragonsRoost/scripts.pory"
	release
# 344 "data//maps/DragonsRoost/scripts.pory"
	end
# 345 "data//maps/DragonsRoost/scripts.pory"

# 346 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 347 "data//maps/DragonsRoost/scripts.pory"
	lock
# 348 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 349 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 350 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 351 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 352 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 353 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 354 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 355 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 356 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 357 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 358 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 359 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 360 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 361 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 362 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 363 "data//maps/DragonsRoost/scripts.pory"
	release
# 364 "data//maps/DragonsRoost/scripts.pory"
	end
# 365 "data//maps/DragonsRoost/scripts.pory"

# 366 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 367 "data//maps/DragonsRoost/scripts.pory"
	release
# 368 "data//maps/DragonsRoost/scripts.pory"
	end
# 369 "data//maps/DragonsRoost/scripts.pory"

# 370 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 371 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 372 "data//maps/DragonsRoost/scripts.pory"
	lock
# 373 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 374 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 375 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 376 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 377 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 378 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 379 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 380 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 381 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 382 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 383 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 384 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 385 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 386 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 387 "data//maps/DragonsRoost/scripts.pory"
	end
# 388 "data//maps/DragonsRoost/scripts.pory"

# 389 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 390 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 391 "data//maps/DragonsRoost/scripts.pory"
	lock
# 392 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 393 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 394 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 395 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 396 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 397 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 398 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 399 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 400 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 401 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 402 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 403 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 404 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 405 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 406 "data//maps/DragonsRoost/scripts.pory"
	end
# 407 "data//maps/DragonsRoost/scripts.pory"

# 408 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 409 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 410 "data//maps/DragonsRoost/scripts.pory"
	lock
# 411 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 412 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 413 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 414 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 415 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 416 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 417 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 418 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 419 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 420 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 421 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 422 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 423 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 424 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 425 "data//maps/DragonsRoost/scripts.pory"
	end
# 426 "data//maps/DragonsRoost/scripts.pory"

# 427 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 428 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 429 "data//maps/DragonsRoost/scripts.pory"
	lock
# 430 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 431 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 432 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 433 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 434 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 435 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 436 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 437 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 438 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 439 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 440 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 441 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 442 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 443 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 444 "data//maps/DragonsRoost/scripts.pory"
	end
# 445 "data//maps/DragonsRoost/scripts.pory"

# 446 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 447 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 448 "data//maps/DragonsRoost/scripts.pory"
	lock
# 449 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 450 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 451 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 452 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 453 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 454 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 455 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 456 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 457 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 458 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 459 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 460 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 461 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 462 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 463 "data//maps/DragonsRoost/scripts.pory"
	end
# 464 "data//maps/DragonsRoost/scripts.pory"

# 465 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 466 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 467 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 468 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 469 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 470 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 471 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 472 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 473 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 474 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 475 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 476 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 477 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 478 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 479 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 480 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 481 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 482 "data//maps/DragonsRoost/scripts.pory"
	release
# 483 "data//maps/DragonsRoost/scripts.pory"
	end
# 484 "data//maps/DragonsRoost/scripts.pory"

# 485 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 486 "data//maps/DragonsRoost/scripts.pory"
	lock
# 487 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 488 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 489 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 490 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 491 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 492 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 493 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 494 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 495 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 496 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 497 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 498 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 499 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 500 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 501 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 502 "data//maps/DragonsRoost/scripts.pory"
	release
# 503 "data//maps/DragonsRoost/scripts.pory"
	end
# 504 "data//maps/DragonsRoost/scripts.pory"

# 505 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 506 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 507 "data//maps/DragonsRoost/scripts.pory"
	release
# 508 "data//maps/DragonsRoost/scripts.pory"
	end
# 509 "data//maps/DragonsRoost/scripts.pory"

# 510 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 511 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 512 "data//maps/DragonsRoost/scripts.pory"
	release
# 513 "data//maps/DragonsRoost/scripts.pory"
	end
# 514 "data//maps/DragonsRoost/scripts.pory"

# 515 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 516 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 517 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 518 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 519 "data//maps/DragonsRoost/scripts.pory"

# 520 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 521 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 522 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 523 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 524 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 525 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 526 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 527 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 528 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 529 "data//maps/DragonsRoost/scripts.pory"

# 530 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 531 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 532 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 533 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 534 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 535 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 536 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 537 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 538 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 539 "data//maps/DragonsRoost/scripts.pory"

# 540 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 541 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 542 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 543 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 544 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 545 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 546 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 547 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 548 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 549 "data//maps/DragonsRoost/scripts.pory"

# 550 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 551 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 552 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 553 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 554 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 557 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 558 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 559 "data//maps/DragonsRoost/scripts.pory"

# 560 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 561 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 562 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 563 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 564 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 565 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 566 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 567 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 568 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 569 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 570 "data//maps/DragonsRoost/scripts.pory"

# 571 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 572 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 573 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 574 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 575 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 576 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 577 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 578 "data//maps/DragonsRoost/scripts.pory"

# 579 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 580 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 581 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 582 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 583 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 584 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 585 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 586 "data//maps/DragonsRoost/scripts.pory"

# 587 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 588 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 589 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 590 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 591 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 592 "data//maps/DragonsRoost/scripts.pory"

# 593 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 594 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 595 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 596 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 597 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 598 "data//maps/DragonsRoost/scripts.pory"

# 599 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 600 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 601 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 602 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 603 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 604 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 605 "data//maps/DragonsRoost/scripts.pory"

# 606 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 607 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 608 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 609 "data//maps/DragonsRoost/scripts.pory"

# 610 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 611 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 612 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 613 "data//maps/DragonsRoost/scripts.pory"

# 614 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 615 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 616 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 617 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 618 "data//maps/DragonsRoost/scripts.pory"

# 619 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 620 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 621 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 622 "data//maps/DragonsRoost/scripts.pory"

# 623 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 624 "data//maps/DragonsRoost/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 625 "data//maps/DragonsRoost/scripts.pory"

# 626 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 627 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 628 "data//maps/DragonsRoost/scripts.pory"

# 629 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 630 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"

DragonsRoost_EventScript_RandomiseOvrWrldMonPos::
# 635 "data//maps/DragonsRoost/scripts.pory"
	compare VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1
# 647 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1:
# 636 "data//maps/DragonsRoost/scripts.pory"
	random 3
# 637 "data//maps/DragonsRoost/scripts.pory"
	switch VAR_RESULT
# 638 "data//maps/DragonsRoost/scripts.pory"
	case 0, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5
# 640 "data//maps/DragonsRoost/scripts.pory"
	case 1, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6
# 642 "data//maps/DragonsRoost/scripts.pory"
	case 2, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5:
# 639 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6:
# 641 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosB
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7:
# 643 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosC
	return


DragonsRoost_EventScript_OvrWrldMonPosA::
# 652 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 653 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 59, 24
# 654 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 73, 39
# 655 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 115, 42
	return


DragonsRoost_EventScript_OvrWrldMonPosB::
# 660 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 59, 24
# 661 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 20, 41
# 662 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 90, 45
# 663 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 74, 28
	return


DragonsRoost_EventScript_OvrWrldMonPosC::
# 668 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 669 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 47, 25
# 670 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 83, 34
# 671 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 73, 39
	return

