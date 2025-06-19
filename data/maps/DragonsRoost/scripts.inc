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
	map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 0, DragonsRoost_EventScript_DoRayquazaCry
# 11 "data//maps/DragonsRoost/scripts.pory"
	map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2, DragonsRoost_EventScript_ContinueRayquazaScene
# 12 "data//maps/DragonsRoost/scripts.pory"
	map_script_2 VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3, DragonsRoost_EventScript_DoMeteoriteSparkle
# 13 "data//maps/DragonsRoost/scripts.pory"
	.2byte 0
# 14 "data//maps/DragonsRoost/scripts.pory"

# 15 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnResume:
# 16 "data//maps/DragonsRoost/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 17 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsRoost_EventScript_TryRemoveZapdos
# 18 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsRoost_EventScript_TryRemoveWildMon
# 19 "data//maps/DragonsRoost/scripts.pory"
	end
# 20 "data//maps/DragonsRoost/scripts.pory"
	end
# 21 "data//maps/DragonsRoost/scripts.pory"

# 22 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveWildMon::
# 23 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 25 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data//maps/DragonsRoost/scripts.pory"
	return
# 27 "data//maps/DragonsRoost/scripts.pory"

# 28 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_OnTransition:
# 29 "data//maps/DragonsRoost/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, DragonsRoost_EventScript_HideZapdos
# 30 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, DragonsRoost_EventScript_TryShowZapdos
# 31 "data//maps/DragonsRoost/scripts.pory"
	call_if_unset FLAG_DRAGONS_ROOST_CLONE, DragonsRoost_EventScript_HideClone
# 32 "data//maps/DragonsRoost/scripts.pory"
	call DragonsRoost_EventScript_SetupPlayerCloneGfxId
# 33 "data//maps/DragonsRoost/scripts.pory"
	end
# 34 "data//maps/DragonsRoost/scripts.pory"

# 35 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideClone::
# 36 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 37 "data//maps/DragonsRoost/scripts.pory"
	return
# 38 "data//maps/DragonsRoost/scripts.pory"

# 39 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_SetupPlayerCloneGfxId::
# 40 "data//maps/DragonsRoost/scripts.pory"
	checkplayergender
# 41 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, DragonsRoost_EventScript_PlayerCloneMale
# 42 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, DragonsRoost_EventScript_PlayerCloneFemale
# 43 "data//maps/DragonsRoost/scripts.pory"
	end
# 44 "data//maps/DragonsRoost/scripts.pory"

# 45 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneMale::
# 46 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 47 "data//maps/DragonsRoost/scripts.pory"
	return
# 48 "data//maps/DragonsRoost/scripts.pory"

# 49 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_PlayerCloneFemale::
# 50 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 51 "data//maps/DragonsRoost/scripts.pory"
	return
# 52 "data//maps/DragonsRoost/scripts.pory"

# 53 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideZapdos::
# 54 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 55 "data//maps/DragonsRoost/scripts.pory"
	return
# 56 "data//maps/DragonsRoost/scripts.pory"

# 57 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryShowZapdos::
# 58 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 59 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 60 "data//maps/DragonsRoost/scripts.pory"
	return
# 61 "data//maps/DragonsRoost/scripts.pory"

# 62 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Rayquaza::
# 63 "data//maps/DragonsRoost/scripts.pory"
	lock
# 64 "data//maps/DragonsRoost/scripts.pory"

# 65 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 66 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 67 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 68 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 69 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 70 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 71 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 72 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 73 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 74 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 75 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 76 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 77 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 78 "data//maps/DragonsRoost/scripts.pory"

# 79 "data//maps/DragonsRoost/scripts.pory"
	setweather WEATHER_SUNNY
# 80 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 81 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 82 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 83 "data//maps/DragonsRoost/scripts.pory"

# 84 "data//maps/DragonsRoost/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 85 "data//maps/DragonsRoost/scripts.pory"

# 86 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 87 "data//maps/DragonsRoost/scripts.pory"
	setobjectxy LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 88 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_CLONE
# 89 "data//maps/DragonsRoost/scripts.pory"
	addobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 90 "data//maps/DragonsRoost/scripts.pory"

# 91 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE, Common_Movement_FaceUp
# 92 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 93 "data//maps/DragonsRoost/scripts.pory"

# 94 "data//maps/DragonsRoost/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 95 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 96 "data//maps/DragonsRoost/scripts.pory"
	
# 97 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 98 "data//maps/DragonsRoost/scripts.pory"

# 99 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanUpI
# 100 "data//maps/DragonsRoost/scripts.pory"
	hidefollower
# 101 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 102 "data//maps/DragonsRoost/scripts.pory"

# 103 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 104 "data//maps/DragonsRoost/scripts.pory"
	release 
# 105 "data//maps/DragonsRoost/scripts.pory"
	end 
# 106 "data//maps/DragonsRoost/scripts.pory"

# 107 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 108 "data//maps/DragonsRoost/scripts.pory"

# 109 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 110 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 111 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 112 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 113 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 114 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 115 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 116 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 117 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 118 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 119 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 120 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 121 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 122 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 123 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 124 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 125 "data//maps/DragonsRoost/scripts.pory"

# 126 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 127 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 128 "data//maps/DragonsRoost/scripts.pory"

# 129 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 130 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 131 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 132 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 133 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 134 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 135 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 136 "data//maps/DragonsRoost/scripts.pory"

# 137 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 138 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 139 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 140 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 141 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 142 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 143 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 144 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 145 "data//maps/DragonsRoost/scripts.pory"

# 146 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanDownII
# 147 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 148 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 149 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 150 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 151 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 152 "data//maps/DragonsRoost/scripts.pory"

# 153 "data//maps/DragonsRoost/scripts.pory"
	resetweather
# 154 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 155 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 156 "data//maps/DragonsRoost/scripts.pory"
	release
# 157 "data//maps/DragonsRoost/scripts.pory"
	end
# 158 "data//maps/DragonsRoost/scripts.pory"

# 159 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 160 "data//maps/DragonsRoost/scripts.pory"
	lock
# 161 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 162 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 163 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 164 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 165 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 166 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 167 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 168 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 169 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 170 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 171 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 172 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 173 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 174 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 175 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 176 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 177 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 178 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 179 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 180 "data//maps/DragonsRoost/scripts.pory"
	release
# 181 "data//maps/DragonsRoost/scripts.pory"
	end
# 182 "data//maps/DragonsRoost/scripts.pory"

# 183 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 184 "data//maps/DragonsRoost/scripts.pory"
	lock
# 185 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 186 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 187 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 188 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 189 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 190 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 191 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 192 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 193 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 194 "data//maps/DragonsRoost/scripts.pory"
	release
# 195 "data//maps/DragonsRoost/scripts.pory"
	end
# 196 "data//maps/DragonsRoost/scripts.pory"

# 197 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 198 "data//maps/DragonsRoost/scripts.pory"
	lock
# 199 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 200 "data//maps/DragonsRoost/scripts.pory"
	release
# 201 "data//maps/DragonsRoost/scripts.pory"
	end
# 202 "data//maps/DragonsRoost/scripts.pory"

# 203 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 204 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 205 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 206 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 207 "data//maps/DragonsRoost/scripts.pory"
	return
# 208 "data//maps/DragonsRoost/scripts.pory"

# 209 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 210 "data//maps/DragonsRoost/scripts.pory"
	lock
# 211 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 212 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 213 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 214 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 215 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 216 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 217 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 218 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 219 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 220 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 221 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 222 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 223 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 224 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 225 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 226 "data//maps/DragonsRoost/scripts.pory"
	release
# 227 "data//maps/DragonsRoost/scripts.pory"
	end
# 228 "data//maps/DragonsRoost/scripts.pory"

# 229 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 230 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 231 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 232 "data//maps/DragonsRoost/scripts.pory"
	release
# 233 "data//maps/DragonsRoost/scripts.pory"
	end
# 234 "data//maps/DragonsRoost/scripts.pory"

# 235 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 236 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 237 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 238 "data//maps/DragonsRoost/scripts.pory"
	release
# 239 "data//maps/DragonsRoost/scripts.pory"
	end
# 240 "data//maps/DragonsRoost/scripts.pory"

# 241 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 242 "data//maps/DragonsRoost/scripts.pory"
	lock
# 243 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 244 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 245 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 246 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 247 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 248 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 249 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 250 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 251 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 252 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 253 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 254 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 255 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 256 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 257 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 258 "data//maps/DragonsRoost/scripts.pory"
	release
# 259 "data//maps/DragonsRoost/scripts.pory"
	end
# 260 "data//maps/DragonsRoost/scripts.pory"

# 261 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 262 "data//maps/DragonsRoost/scripts.pory"
	lock
# 263 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 264 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 265 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 266 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 267 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 268 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 269 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 270 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 271 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 272 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 273 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 274 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 275 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 276 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 277 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 278 "data//maps/DragonsRoost/scripts.pory"
	release
# 279 "data//maps/DragonsRoost/scripts.pory"
	end
# 280 "data//maps/DragonsRoost/scripts.pory"

# 281 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 282 "data//maps/DragonsRoost/scripts.pory"
	lock
# 283 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 284 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 285 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 286 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 287 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 288 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 289 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 290 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 291 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 292 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 293 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 294 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 295 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 296 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 297 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 298 "data//maps/DragonsRoost/scripts.pory"
	release
# 299 "data//maps/DragonsRoost/scripts.pory"
	end
# 300 "data//maps/DragonsRoost/scripts.pory"

# 301 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 302 "data//maps/DragonsRoost/scripts.pory"
	lock
# 303 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 304 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 305 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 306 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 307 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 308 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 309 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 310 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 311 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 312 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 313 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 314 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 315 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 316 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 317 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 318 "data//maps/DragonsRoost/scripts.pory"
	release
# 319 "data//maps/DragonsRoost/scripts.pory"
	end
# 320 "data//maps/DragonsRoost/scripts.pory"

# 321 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 322 "data//maps/DragonsRoost/scripts.pory"
	lock
# 323 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 324 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 325 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 326 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 327 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 328 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 329 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 330 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 331 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 332 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 333 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 334 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 335 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 336 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 337 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 338 "data//maps/DragonsRoost/scripts.pory"
	release
# 339 "data//maps/DragonsRoost/scripts.pory"
	end
# 340 "data//maps/DragonsRoost/scripts.pory"

# 341 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 342 "data//maps/DragonsRoost/scripts.pory"
	release
# 343 "data//maps/DragonsRoost/scripts.pory"
	end
# 344 "data//maps/DragonsRoost/scripts.pory"

# 345 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 346 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 347 "data//maps/DragonsRoost/scripts.pory"
	lock
# 348 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 349 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 350 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 351 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 352 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 353 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 354 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 355 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 356 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 357 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 358 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 359 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 360 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 361 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 362 "data//maps/DragonsRoost/scripts.pory"
	end
# 363 "data//maps/DragonsRoost/scripts.pory"

# 364 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 365 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 366 "data//maps/DragonsRoost/scripts.pory"
	lock
# 367 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 368 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 369 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 370 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 371 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 372 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 373 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 374 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 375 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 376 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 377 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 378 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 379 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 380 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 381 "data//maps/DragonsRoost/scripts.pory"
	end
# 382 "data//maps/DragonsRoost/scripts.pory"

# 383 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 384 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 385 "data//maps/DragonsRoost/scripts.pory"
	lock
# 386 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 387 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 388 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 389 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 390 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 391 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 392 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 393 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 394 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 395 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 396 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 397 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 398 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 399 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 400 "data//maps/DragonsRoost/scripts.pory"
	end
# 401 "data//maps/DragonsRoost/scripts.pory"

# 402 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 403 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 404 "data//maps/DragonsRoost/scripts.pory"
	lock
# 405 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 406 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 407 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 408 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 409 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 410 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 411 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 412 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 413 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 414 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 415 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 416 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 417 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 418 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 419 "data//maps/DragonsRoost/scripts.pory"
	end
# 420 "data//maps/DragonsRoost/scripts.pory"

# 421 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 422 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 423 "data//maps/DragonsRoost/scripts.pory"
	lock
# 424 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 425 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 426 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 427 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 428 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 429 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 430 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 431 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 432 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 433 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 434 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 435 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 436 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 437 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 438 "data//maps/DragonsRoost/scripts.pory"
	end
# 439 "data//maps/DragonsRoost/scripts.pory"

# 440 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 441 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 442 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 443 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 444 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 445 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 446 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 447 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 448 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 449 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 450 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 451 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 452 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 453 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 454 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 455 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 456 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 457 "data//maps/DragonsRoost/scripts.pory"
	release
# 458 "data//maps/DragonsRoost/scripts.pory"
	end
# 459 "data//maps/DragonsRoost/scripts.pory"

# 460 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 461 "data//maps/DragonsRoost/scripts.pory"
	lock
# 462 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 463 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 464 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 465 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 466 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 467 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 468 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 469 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 470 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 471 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 472 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 473 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 474 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 475 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 476 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 477 "data//maps/DragonsRoost/scripts.pory"
	release
# 478 "data//maps/DragonsRoost/scripts.pory"
	end
# 479 "data//maps/DragonsRoost/scripts.pory"

# 480 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 481 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 482 "data//maps/DragonsRoost/scripts.pory"
	release
# 483 "data//maps/DragonsRoost/scripts.pory"
	end
# 484 "data//maps/DragonsRoost/scripts.pory"

# 485 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 486 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 487 "data//maps/DragonsRoost/scripts.pory"
	release
# 488 "data//maps/DragonsRoost/scripts.pory"
	end
# 489 "data//maps/DragonsRoost/scripts.pory"

# 490 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 491 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 492 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 493 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 494 "data//maps/DragonsRoost/scripts.pory"

# 495 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 496 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 497 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 498 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 499 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 500 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 501 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 502 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 503 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 504 "data//maps/DragonsRoost/scripts.pory"

# 505 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 506 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 507 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 508 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 509 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 510 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 511 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 512 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 513 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 514 "data//maps/DragonsRoost/scripts.pory"

# 515 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 516 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 517 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 518 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 519 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 520 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 521 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 522 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 523 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 524 "data//maps/DragonsRoost/scripts.pory"

# 525 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 526 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 527 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 528 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 529 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 530 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 531 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 532 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 533 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 534 "data//maps/DragonsRoost/scripts.pory"

# 535 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 536 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 537 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 538 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 539 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 540 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 541 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 542 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 543 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 544 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 545 "data//maps/DragonsRoost/scripts.pory"

# 546 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 547 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 548 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 549 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 550 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 551 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 552 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 553 "data//maps/DragonsRoost/scripts.pory"

# 554 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 557 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 558 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 559 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 560 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 561 "data//maps/DragonsRoost/scripts.pory"

# 562 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 563 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 564 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 565 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 566 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 567 "data//maps/DragonsRoost/scripts.pory"

# 568 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 569 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 570 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 571 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 572 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 573 "data//maps/DragonsRoost/scripts.pory"

# 574 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 575 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 576 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 577 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 578 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 579 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 580 "data//maps/DragonsRoost/scripts.pory"

# 581 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 582 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 583 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 584 "data//maps/DragonsRoost/scripts.pory"

# 585 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 586 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 587 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 588 "data//maps/DragonsRoost/scripts.pory"

# 589 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 590 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 591 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 592 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 593 "data//maps/DragonsRoost/scripts.pory"

# 594 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 595 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 596 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 597 "data//maps/DragonsRoost/scripts.pory"

# 598 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 599 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA roared nearby!$"
# 600 "data//maps/DragonsRoost/scripts.pory"

# 601 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 602 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 603 "data//maps/DragonsRoost/scripts.pory"

# 604 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 605 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"
