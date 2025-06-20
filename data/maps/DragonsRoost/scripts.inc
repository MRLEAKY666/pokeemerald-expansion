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
	waitmoncry
# 181 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 182 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 183 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 184 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 185 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 0
# 186 "data//maps/DragonsRoost/scripts.pory"
	release
# 187 "data//maps/DragonsRoost/scripts.pory"
	end
# 188 "data//maps/DragonsRoost/scripts.pory"

# 189 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 190 "data//maps/DragonsRoost/scripts.pory"
	lock
# 191 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 192 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 193 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 194 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 195 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 196 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 197 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 198 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 199 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 200 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 0
# 201 "data//maps/DragonsRoost/scripts.pory"
	release
# 202 "data//maps/DragonsRoost/scripts.pory"
	end
# 203 "data//maps/DragonsRoost/scripts.pory"

# 204 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 205 "data//maps/DragonsRoost/scripts.pory"
	lock
# 206 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 207 "data//maps/DragonsRoost/scripts.pory"
	release
# 208 "data//maps/DragonsRoost/scripts.pory"
	end
# 209 "data//maps/DragonsRoost/scripts.pory"

# 210 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 211 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 212 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 213 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 214 "data//maps/DragonsRoost/scripts.pory"
	return
# 215 "data//maps/DragonsRoost/scripts.pory"

# 216 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 217 "data//maps/DragonsRoost/scripts.pory"
	lock
# 218 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 219 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 220 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 221 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 222 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 223 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 224 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 225 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 226 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 227 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 228 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 229 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 230 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 231 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 232 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 233 "data//maps/DragonsRoost/scripts.pory"
	release
# 234 "data//maps/DragonsRoost/scripts.pory"
	end
# 235 "data//maps/DragonsRoost/scripts.pory"

# 236 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 237 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 238 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 239 "data//maps/DragonsRoost/scripts.pory"
	release
# 240 "data//maps/DragonsRoost/scripts.pory"
	end
# 241 "data//maps/DragonsRoost/scripts.pory"

# 242 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 243 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 244 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 245 "data//maps/DragonsRoost/scripts.pory"
	release
# 246 "data//maps/DragonsRoost/scripts.pory"
	end
# 247 "data//maps/DragonsRoost/scripts.pory"

# 248 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 249 "data//maps/DragonsRoost/scripts.pory"
	lock
# 250 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 251 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 252 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 253 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 254 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 255 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 256 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 257 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 258 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 259 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 260 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 261 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 262 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 263 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 264 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 265 "data//maps/DragonsRoost/scripts.pory"
	release
# 266 "data//maps/DragonsRoost/scripts.pory"
	end
# 267 "data//maps/DragonsRoost/scripts.pory"

# 268 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 269 "data//maps/DragonsRoost/scripts.pory"
	lock
# 270 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 271 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 272 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 273 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 274 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 275 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 276 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 277 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 278 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 279 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 280 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 281 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 282 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 283 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 284 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 285 "data//maps/DragonsRoost/scripts.pory"
	release
# 286 "data//maps/DragonsRoost/scripts.pory"
	end
# 287 "data//maps/DragonsRoost/scripts.pory"

# 288 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 289 "data//maps/DragonsRoost/scripts.pory"
	lock
# 290 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 291 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 292 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 293 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 294 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 295 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 296 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 297 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 298 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 299 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 300 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 301 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 302 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 303 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 304 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 305 "data//maps/DragonsRoost/scripts.pory"
	release
# 306 "data//maps/DragonsRoost/scripts.pory"
	end
# 307 "data//maps/DragonsRoost/scripts.pory"

# 308 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 309 "data//maps/DragonsRoost/scripts.pory"
	lock
# 310 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 311 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 312 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 313 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 314 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 315 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 316 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 317 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 318 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 319 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 320 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 321 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 322 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 323 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 324 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 325 "data//maps/DragonsRoost/scripts.pory"
	release
# 326 "data//maps/DragonsRoost/scripts.pory"
	end
# 327 "data//maps/DragonsRoost/scripts.pory"

# 328 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine2::
# 329 "data//maps/DragonsRoost/scripts.pory"
	lock
# 330 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 331 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 332 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 333 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 334 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 335 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 336 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 337 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 338 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 339 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 340 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 341 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 342 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 343 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 344 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 345 "data//maps/DragonsRoost/scripts.pory"
	release
# 346 "data//maps/DragonsRoost/scripts.pory"
	end
# 347 "data//maps/DragonsRoost/scripts.pory"

# 348 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 349 "data//maps/DragonsRoost/scripts.pory"
	lock
# 350 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 351 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 352 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 353 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 354 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 355 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 356 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 357 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 358 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 359 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 360 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 361 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 362 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 363 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 364 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 365 "data//maps/DragonsRoost/scripts.pory"
	release
# 366 "data//maps/DragonsRoost/scripts.pory"
	end
# 367 "data//maps/DragonsRoost/scripts.pory"

# 368 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 369 "data//maps/DragonsRoost/scripts.pory"
	release
# 370 "data//maps/DragonsRoost/scripts.pory"
	end
# 371 "data//maps/DragonsRoost/scripts.pory"

# 372 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 373 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 374 "data//maps/DragonsRoost/scripts.pory"
	lock
# 375 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 376 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 377 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 378 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 379 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 380 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 381 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 382 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 383 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 384 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 385 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 386 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 387 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 388 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 389 "data//maps/DragonsRoost/scripts.pory"
	end
# 390 "data//maps/DragonsRoost/scripts.pory"

# 391 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 392 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 393 "data//maps/DragonsRoost/scripts.pory"
	lock
# 394 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 395 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 396 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 397 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 398 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 399 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 400 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 401 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 402 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 403 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 404 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 405 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 406 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 407 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 408 "data//maps/DragonsRoost/scripts.pory"
	end
# 409 "data//maps/DragonsRoost/scripts.pory"

# 410 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 411 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 412 "data//maps/DragonsRoost/scripts.pory"
	lock
# 413 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 414 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 415 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 416 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 417 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 418 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 419 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 420 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 421 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 422 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 423 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 424 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 425 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 426 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 427 "data//maps/DragonsRoost/scripts.pory"
	end
# 428 "data//maps/DragonsRoost/scripts.pory"

# 429 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 430 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 431 "data//maps/DragonsRoost/scripts.pory"
	lock
# 432 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 433 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 434 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 435 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 436 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 437 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 438 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 439 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 440 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 441 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 442 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 443 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 444 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 445 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 446 "data//maps/DragonsRoost/scripts.pory"
	end
# 447 "data//maps/DragonsRoost/scripts.pory"

# 448 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 449 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 450 "data//maps/DragonsRoost/scripts.pory"
	lock
# 451 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 452 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 453 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 454 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 455 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 456 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 457 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 458 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 459 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 460 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 461 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 462 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 463 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 464 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 465 "data//maps/DragonsRoost/scripts.pory"
	end
# 466 "data//maps/DragonsRoost/scripts.pory"

# 467 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 468 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 469 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 470 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 471 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 472 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 473 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 474 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 475 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 476 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 477 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 478 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 479 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 480 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 481 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 482 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 483 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 484 "data//maps/DragonsRoost/scripts.pory"
	release
# 485 "data//maps/DragonsRoost/scripts.pory"
	end
# 486 "data//maps/DragonsRoost/scripts.pory"

# 487 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 488 "data//maps/DragonsRoost/scripts.pory"
	lock
# 489 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 490 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 491 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 492 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 493 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 494 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 495 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 496 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 497 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 498 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 499 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 500 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 501 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 502 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 503 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 504 "data//maps/DragonsRoost/scripts.pory"
	release
# 505 "data//maps/DragonsRoost/scripts.pory"
	end
# 506 "data//maps/DragonsRoost/scripts.pory"

# 507 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 508 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 509 "data//maps/DragonsRoost/scripts.pory"
	release
# 510 "data//maps/DragonsRoost/scripts.pory"
	end
# 511 "data//maps/DragonsRoost/scripts.pory"

# 512 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 513 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 514 "data//maps/DragonsRoost/scripts.pory"
	release
# 515 "data//maps/DragonsRoost/scripts.pory"
	end
# 516 "data//maps/DragonsRoost/scripts.pory"

# 517 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 518 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 519 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 520 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 521 "data//maps/DragonsRoost/scripts.pory"

# 522 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 523 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 524 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 525 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 526 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 527 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 528 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 529 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 530 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 531 "data//maps/DragonsRoost/scripts.pory"

# 532 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
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
	walk_slow_up
# 539 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 540 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 541 "data//maps/DragonsRoost/scripts.pory"

# 542 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
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
	walk_slow_down
# 549 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 550 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 551 "data//maps/DragonsRoost/scripts.pory"

# 552 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 553 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 554 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 557 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 558 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 559 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 560 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 561 "data//maps/DragonsRoost/scripts.pory"

# 562 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 563 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 564 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 565 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 566 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 567 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 568 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 569 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 570 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 571 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 572 "data//maps/DragonsRoost/scripts.pory"

# 573 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 574 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 575 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 576 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 577 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 578 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 579 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 580 "data//maps/DragonsRoost/scripts.pory"

# 581 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 582 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 583 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 584 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 585 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 586 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 587 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 588 "data//maps/DragonsRoost/scripts.pory"

# 589 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 590 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 591 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 592 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 593 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 594 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 595 "data//maps/DragonsRoost/scripts.pory"

# 596 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 597 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 598 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 599 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 600 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 601 "data//maps/DragonsRoost/scripts.pory"

# 602 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 603 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 604 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 605 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 606 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 607 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 608 "data//maps/DragonsRoost/scripts.pory"

# 609 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 610 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 611 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 612 "data//maps/DragonsRoost/scripts.pory"

# 613 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 614 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 615 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 616 "data//maps/DragonsRoost/scripts.pory"

# 617 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 618 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 619 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 620 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 621 "data//maps/DragonsRoost/scripts.pory"

# 622 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 623 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 624 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 625 "data//maps/DragonsRoost/scripts.pory"

# 626 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 627 "data//maps/DragonsRoost/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 628 "data//maps/DragonsRoost/scripts.pory"

# 629 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 630 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 631 "data//maps/DragonsRoost/scripts.pory"

# 632 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 633 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"

DragonsRoost_EventScript_RandomiseOvrWrldMonPos::
# 638 "data//maps/DragonsRoost/scripts.pory"
	compare VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1
# 650 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_1:
# 639 "data//maps/DragonsRoost/scripts.pory"
	random 3
# 640 "data//maps/DragonsRoost/scripts.pory"
	switch VAR_RESULT
# 641 "data//maps/DragonsRoost/scripts.pory"
	case 0, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5
# 643 "data//maps/DragonsRoost/scripts.pory"
	case 1, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6
# 645 "data//maps/DragonsRoost/scripts.pory"
	case 2, DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_5:
# 642 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosA
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_6:
# 644 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosB
	return

DragonsRoost_EventScript_RandomiseOvrWrldMonPos_7:
# 646 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_OvrWrldMonPosC
	return


DragonsRoost_EventScript_OvrWrldMonPosA::
# 655 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 656 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 59, 24
# 657 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 73, 39
# 658 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 115, 42
	return


DragonsRoost_EventScript_OvrWrldMonPosB::
# 663 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 59, 24
# 664 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 20, 41
# 665 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 90, 45
# 666 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 74, 28
	return


DragonsRoost_EventScript_OvrWrldMonPosC::
# 671 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_AURORUS, 20, 41
# 672 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_CROCONAW, 47, 25
# 673 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_GYARADOS, 83, 34
# 674 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_DRAGONAIR, 73, 39
	return

