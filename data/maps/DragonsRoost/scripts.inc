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
	end
# 37 "data//maps/DragonsRoost/scripts.pory"

# 38 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRayquazaCry::
# 39 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 1
# 40 "data//maps/DragonsRoost/scripts.pory"
	return
# 41 "data//maps/DragonsRoost/scripts.pory"

# 42 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PrepRepeatSparkle::
# 43 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 1
# 44 "data//maps/DragonsRoost/scripts.pory"
	return
# 45 "data//maps/DragonsRoost/scripts.pory"

# 46 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideClone::
# 47 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 48 "data//maps/DragonsRoost/scripts.pory"
	return
# 49 "data//maps/DragonsRoost/scripts.pory"

# 50 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_SetupPlayerCloneGfxId::
# 51 "data//maps/DragonsRoost/scripts.pory"
	checkplayergender
# 52 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, DragonsRoost_EventScript_PlayerCloneMale
# 53 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, DragonsRoost_EventScript_PlayerCloneFemale
# 54 "data//maps/DragonsRoost/scripts.pory"
	end
# 55 "data//maps/DragonsRoost/scripts.pory"

# 56 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneMale::
# 57 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 58 "data//maps/DragonsRoost/scripts.pory"
	return
# 59 "data//maps/DragonsRoost/scripts.pory"

# 60 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneFemale::
# 61 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 62 "data//maps/DragonsRoost/scripts.pory"
	return
# 63 "data//maps/DragonsRoost/scripts.pory"

# 64 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideZapdos::
# 65 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 66 "data//maps/DragonsRoost/scripts.pory"
	return
# 67 "data//maps/DragonsRoost/scripts.pory"

# 68 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryShowZapdos::
# 69 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 70 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 71 "data//maps/DragonsRoost/scripts.pory"
	return
# 72 "data//maps/DragonsRoost/scripts.pory"

# 73 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Rayquaza::
# 74 "data//maps/DragonsRoost/scripts.pory"
	lock
# 75 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 76 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 77 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 78 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 79 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 80 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 81 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 82 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 83 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 84 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 85 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 86 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 87 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 88 "data//maps/DragonsRoost/scripts.pory"
	setweather WEATHER_SUNNY
# 89 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 90 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 91 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 92 "data//maps/DragonsRoost/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 93 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 94 "data//maps/DragonsRoost/scripts.pory"
	setobjectxy LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 95 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_CLONE
# 96 "data//maps/DragonsRoost/scripts.pory"
	addobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 97 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE, Common_Movement_FaceUp
# 98 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 99 "data//maps/DragonsRoost/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 100 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 101 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 102 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanUpI
# 103 "data//maps/DragonsRoost/scripts.pory"
	hidefollower
# 104 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 105 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 106 "data//maps/DragonsRoost/scripts.pory"
	release 
# 107 "data//maps/DragonsRoost/scripts.pory"
	end 
# 108 "data//maps/DragonsRoost/scripts.pory"

# 109 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 110 "data//maps/DragonsRoost/scripts.pory"

# 111 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 112 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 113 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 114 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 115 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 116 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 117 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 118 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 119 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 120 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 121 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 122 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 123 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 124 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 125 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 126 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 127 "data//maps/DragonsRoost/scripts.pory"

# 128 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 129 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 130 "data//maps/DragonsRoost/scripts.pory"

# 131 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 132 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 133 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 134 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 135 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 136 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 137 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 138 "data//maps/DragonsRoost/scripts.pory"

# 139 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 140 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 141 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 142 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 143 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 144 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 145 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 146 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 147 "data//maps/DragonsRoost/scripts.pory"

# 148 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanDownII
# 149 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 150 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 151 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 152 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 153 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 154 "data//maps/DragonsRoost/scripts.pory"

# 155 "data//maps/DragonsRoost/scripts.pory"
	resetweather
# 156 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 157 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 158 "data//maps/DragonsRoost/scripts.pory"
	release
# 159 "data//maps/DragonsRoost/scripts.pory"
	end
# 160 "data//maps/DragonsRoost/scripts.pory"

# 161 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 162 "data//maps/DragonsRoost/scripts.pory"
	lock
# 163 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 164 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 165 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 166 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 167 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 168 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 169 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 170 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 171 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 172 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 173 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 174 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 175 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 176 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 177 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 178 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 179 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 180 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 181 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 182 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_1, 0
# 183 "data//maps/DragonsRoost/scripts.pory"
	release
# 184 "data//maps/DragonsRoost/scripts.pory"
	end
# 185 "data//maps/DragonsRoost/scripts.pory"

# 186 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 187 "data//maps/DragonsRoost/scripts.pory"
	lock
# 188 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 189 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 190 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 191 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 192 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 193 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 194 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 195 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 196 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 197 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_TEMP_2, 0
# 198 "data//maps/DragonsRoost/scripts.pory"
	release
# 199 "data//maps/DragonsRoost/scripts.pory"
	end
# 200 "data//maps/DragonsRoost/scripts.pory"

# 201 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 202 "data//maps/DragonsRoost/scripts.pory"
	lock
# 203 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 204 "data//maps/DragonsRoost/scripts.pory"
	release
# 205 "data//maps/DragonsRoost/scripts.pory"
	end
# 206 "data//maps/DragonsRoost/scripts.pory"

# 207 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 208 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 209 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 210 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 211 "data//maps/DragonsRoost/scripts.pory"
	return
# 212 "data//maps/DragonsRoost/scripts.pory"

# 213 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 214 "data//maps/DragonsRoost/scripts.pory"
	lock
# 215 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 216 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 217 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 218 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 219 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 220 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 221 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 222 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 223 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 224 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 225 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 226 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 227 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 228 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 229 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 230 "data//maps/DragonsRoost/scripts.pory"
	release
# 231 "data//maps/DragonsRoost/scripts.pory"
	end
# 232 "data//maps/DragonsRoost/scripts.pory"

# 233 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 234 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 235 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 236 "data//maps/DragonsRoost/scripts.pory"
	release
# 237 "data//maps/DragonsRoost/scripts.pory"
	end
# 238 "data//maps/DragonsRoost/scripts.pory"

# 239 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 240 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 241 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 242 "data//maps/DragonsRoost/scripts.pory"
	release
# 243 "data//maps/DragonsRoost/scripts.pory"
	end
# 244 "data//maps/DragonsRoost/scripts.pory"

# 245 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 246 "data//maps/DragonsRoost/scripts.pory"
	lock
# 247 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 248 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 249 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 250 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 251 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 252 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 253 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 254 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 255 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 256 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 257 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 258 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 259 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 260 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 261 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 262 "data//maps/DragonsRoost/scripts.pory"
	release
# 263 "data//maps/DragonsRoost/scripts.pory"
	end
# 264 "data//maps/DragonsRoost/scripts.pory"

# 265 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 266 "data//maps/DragonsRoost/scripts.pory"
	lock
# 267 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 268 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 269 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 270 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 271 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 272 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 273 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 274 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 275 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 276 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 277 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 278 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 279 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 280 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 281 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 282 "data//maps/DragonsRoost/scripts.pory"
	release
# 283 "data//maps/DragonsRoost/scripts.pory"
	end
# 284 "data//maps/DragonsRoost/scripts.pory"

# 285 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 286 "data//maps/DragonsRoost/scripts.pory"
	lock
# 287 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 288 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 289 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 290 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 291 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 292 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 293 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 294 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 295 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 296 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 297 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 298 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 299 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 300 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 301 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 302 "data//maps/DragonsRoost/scripts.pory"
	release
# 303 "data//maps/DragonsRoost/scripts.pory"
	end
# 304 "data//maps/DragonsRoost/scripts.pory"

# 305 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 306 "data//maps/DragonsRoost/scripts.pory"
	lock
# 307 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 308 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 309 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 310 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 311 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 312 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 313 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 314 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 315 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 316 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 317 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 318 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 319 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 320 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 321 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 322 "data//maps/DragonsRoost/scripts.pory"
	release
# 323 "data//maps/DragonsRoost/scripts.pory"
	end
# 324 "data//maps/DragonsRoost/scripts.pory"

# 325 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 326 "data//maps/DragonsRoost/scripts.pory"
	lock
# 327 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 328 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 329 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 330 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 331 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 332 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 333 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 334 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 335 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 336 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 337 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 338 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 339 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 340 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 341 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 342 "data//maps/DragonsRoost/scripts.pory"
	release
# 343 "data//maps/DragonsRoost/scripts.pory"
	end
# 344 "data//maps/DragonsRoost/scripts.pory"

# 345 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 346 "data//maps/DragonsRoost/scripts.pory"
	release
# 347 "data//maps/DragonsRoost/scripts.pory"
	end
# 348 "data//maps/DragonsRoost/scripts.pory"

# 349 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 350 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 351 "data//maps/DragonsRoost/scripts.pory"
	lock
# 352 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 353 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 354 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 355 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 356 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 357 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 358 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 359 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 360 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 361 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 362 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 363 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 364 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 365 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 366 "data//maps/DragonsRoost/scripts.pory"
	end
# 367 "data//maps/DragonsRoost/scripts.pory"

# 368 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 369 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 370 "data//maps/DragonsRoost/scripts.pory"
	lock
# 371 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 372 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 373 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 374 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 375 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 376 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 377 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 378 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 379 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 380 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 381 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 382 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 383 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 384 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 385 "data//maps/DragonsRoost/scripts.pory"
	end
# 386 "data//maps/DragonsRoost/scripts.pory"

# 387 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 388 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 389 "data//maps/DragonsRoost/scripts.pory"
	lock
# 390 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 391 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 392 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 393 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 394 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 395 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 396 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 397 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 398 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 399 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 400 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 401 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 402 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 403 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 404 "data//maps/DragonsRoost/scripts.pory"
	end
# 405 "data//maps/DragonsRoost/scripts.pory"

# 406 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 407 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 408 "data//maps/DragonsRoost/scripts.pory"
	lock
# 409 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 410 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 411 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 412 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 413 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 414 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 415 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 416 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 417 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 418 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 419 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 420 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 421 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 422 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 423 "data//maps/DragonsRoost/scripts.pory"
	end
# 424 "data//maps/DragonsRoost/scripts.pory"

# 425 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 426 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 427 "data//maps/DragonsRoost/scripts.pory"
	lock
# 428 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 429 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 430 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 431 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 432 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 433 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 434 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 435 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 436 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 437 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 438 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 439 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 440 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 441 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 442 "data//maps/DragonsRoost/scripts.pory"
	end
# 443 "data//maps/DragonsRoost/scripts.pory"

# 444 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 445 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 446 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 447 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 448 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 449 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 450 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 451 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 452 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 453 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 454 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 455 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 456 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 457 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 458 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 459 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 460 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 461 "data//maps/DragonsRoost/scripts.pory"
	release
# 462 "data//maps/DragonsRoost/scripts.pory"
	end
# 463 "data//maps/DragonsRoost/scripts.pory"

# 464 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 465 "data//maps/DragonsRoost/scripts.pory"
	lock
# 466 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 467 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 468 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 469 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 470 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 471 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 472 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 473 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 474 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 475 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 476 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 477 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 478 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 479 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 480 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 481 "data//maps/DragonsRoost/scripts.pory"
	release
# 482 "data//maps/DragonsRoost/scripts.pory"
	end
# 483 "data//maps/DragonsRoost/scripts.pory"

# 484 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 485 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 486 "data//maps/DragonsRoost/scripts.pory"
	release
# 487 "data//maps/DragonsRoost/scripts.pory"
	end
# 488 "data//maps/DragonsRoost/scripts.pory"

# 489 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 490 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 491 "data//maps/DragonsRoost/scripts.pory"
	release
# 492 "data//maps/DragonsRoost/scripts.pory"
	end
# 493 "data//maps/DragonsRoost/scripts.pory"

# 494 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 495 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 496 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 497 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 498 "data//maps/DragonsRoost/scripts.pory"

# 499 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 500 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 501 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 502 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 503 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 504 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 505 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 506 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 507 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 508 "data//maps/DragonsRoost/scripts.pory"

# 509 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 510 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 511 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 512 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 513 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 514 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 515 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 516 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 517 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 518 "data//maps/DragonsRoost/scripts.pory"

# 519 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 520 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 521 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 522 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 523 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 524 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 525 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 526 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 527 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 528 "data//maps/DragonsRoost/scripts.pory"

# 529 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 530 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 531 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 532 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 533 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 534 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 535 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 536 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 537 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 538 "data//maps/DragonsRoost/scripts.pory"

# 539 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 540 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 541 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 542 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 543 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 544 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 545 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 546 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 547 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 548 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 549 "data//maps/DragonsRoost/scripts.pory"

# 550 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 551 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 552 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 553 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 554 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 557 "data//maps/DragonsRoost/scripts.pory"

# 558 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 559 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 560 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 561 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 562 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 563 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 564 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 565 "data//maps/DragonsRoost/scripts.pory"

# 566 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 567 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 568 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 569 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 570 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 571 "data//maps/DragonsRoost/scripts.pory"

# 572 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 573 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 574 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 575 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 576 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 577 "data//maps/DragonsRoost/scripts.pory"

# 578 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 579 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 580 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 581 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 582 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 583 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 584 "data//maps/DragonsRoost/scripts.pory"

# 585 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 586 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 587 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 588 "data//maps/DragonsRoost/scripts.pory"

# 589 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 590 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 591 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 592 "data//maps/DragonsRoost/scripts.pory"

# 593 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 594 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 595 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 596 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 597 "data//maps/DragonsRoost/scripts.pory"

# 598 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 599 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 600 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 601 "data//maps/DragonsRoost/scripts.pory"

# 602 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 603 "data//maps/DragonsRoost/scripts.pory"
	.string "it sounds like RAYQUAZA is nearby!$"
# 604 "data//maps/DragonsRoost/scripts.pory"

# 605 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 606 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 607 "data//maps/DragonsRoost/scripts.pory"

# 608 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 609 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"
