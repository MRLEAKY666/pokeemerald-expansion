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
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 65 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 66 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 67 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 68 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 69 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 70 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 71 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 72 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 73 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 74 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 75 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 76 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 77 "data//maps/DragonsRoost/scripts.pory"
	setweather WEATHER_SUNNY
# 78 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 79 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 80 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 81 "data//maps/DragonsRoost/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 82 "data//maps/DragonsRoost/scripts.pory"
	setobjectxyperm LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 83 "data//maps/DragonsRoost/scripts.pory"
	setobjectxy LOCALID_DRAGONS_ROOST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 84 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_CLONE
# 85 "data//maps/DragonsRoost/scripts.pory"
	addobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 86 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE, Common_Movement_FaceUp
# 87 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 88 "data//maps/DragonsRoost/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 89 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_DRAGONS_ROOST_PLAYER_CLONE, MAP_DRAGONS_ROOST
# 90 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 91 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanUpI
# 92 "data//maps/DragonsRoost/scripts.pory"
	hidefollower
# 93 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 94 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 95 "data//maps/DragonsRoost/scripts.pory"
	release 
# 96 "data//maps/DragonsRoost/scripts.pory"
	end 
# 97 "data//maps/DragonsRoost/scripts.pory"

# 98 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 99 "data//maps/DragonsRoost/scripts.pory"

# 100 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 101 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 102 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 103 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 104 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 105 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 106 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 107 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 108 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 109 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 110 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 111 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 112 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 113 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 114 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 115 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 116 "data//maps/DragonsRoost/scripts.pory"

# 117 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 118 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 119 "data//maps/DragonsRoost/scripts.pory"

# 120 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 121 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 122 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 123 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 124 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 125 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 126 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 127 "data//maps/DragonsRoost/scripts.pory"

# 128 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 129 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 130 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 131 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 132 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 133 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 134 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 135 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 136 "data//maps/DragonsRoost/scripts.pory"

# 137 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, DragonsRoost_Movement_CameraPanDownII
# 138 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 139 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_PLAYER_CLONE
# 140 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 141 "data//maps/DragonsRoost/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGONS_ROOST
# 142 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_PLAYER
# 143 "data//maps/DragonsRoost/scripts.pory"

# 144 "data//maps/DragonsRoost/scripts.pory"
	resetweather
# 145 "data//maps/DragonsRoost/scripts.pory"
	doweather
# 146 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 147 "data//maps/DragonsRoost/scripts.pory"
	release
# 148 "data//maps/DragonsRoost/scripts.pory"
	end
# 149 "data//maps/DragonsRoost/scripts.pory"

# 150 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 151 "data//maps/DragonsRoost/scripts.pory"
	lock
# 152 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 153 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 154 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 155 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 156 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 157 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 158 "data//maps/DragonsRoost/scripts.pory"
	@ waitmovement 0
# 159 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 160 "data//maps/DragonsRoost/scripts.pory"
	waitse
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
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 169 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 170 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 171 "data//maps/DragonsRoost/scripts.pory"
	release
# 172 "data//maps/DragonsRoost/scripts.pory"
	end
# 173 "data//maps/DragonsRoost/scripts.pory"

# 174 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 175 "data//maps/DragonsRoost/scripts.pory"
	lock
# 176 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 177 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 178 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 179 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 180 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 181 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 182 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 183 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 184 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 185 "data//maps/DragonsRoost/scripts.pory"
	release
# 186 "data//maps/DragonsRoost/scripts.pory"
	end
# 187 "data//maps/DragonsRoost/scripts.pory"

# 188 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Clone::
# 189 "data//maps/DragonsRoost/scripts.pory"
	lock
# 190 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_Clone, MSGBOX_DEFAULT 
# 191 "data//maps/DragonsRoost/scripts.pory"
	release
# 192 "data//maps/DragonsRoost/scripts.pory"
	end
# 193 "data//maps/DragonsRoost/scripts.pory"

# 194 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 195 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 196 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 197 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 198 "data//maps/DragonsRoost/scripts.pory"
	return
# 199 "data//maps/DragonsRoost/scripts.pory"

# 200 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 201 "data//maps/DragonsRoost/scripts.pory"
	lock
# 202 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 203 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 204 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 205 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 206 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 207 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 208 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 209 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 210 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 211 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 212 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 213 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 214 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 215 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 216 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 217 "data//maps/DragonsRoost/scripts.pory"
	release
# 218 "data//maps/DragonsRoost/scripts.pory"
	end
# 219 "data//maps/DragonsRoost/scripts.pory"

# 220 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 221 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 222 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 223 "data//maps/DragonsRoost/scripts.pory"
	release
# 224 "data//maps/DragonsRoost/scripts.pory"
	end
# 225 "data//maps/DragonsRoost/scripts.pory"

# 226 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 227 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 228 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 229 "data//maps/DragonsRoost/scripts.pory"
	release
# 230 "data//maps/DragonsRoost/scripts.pory"
	end
# 231 "data//maps/DragonsRoost/scripts.pory"

# 232 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 233 "data//maps/DragonsRoost/scripts.pory"
	lock
# 234 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 235 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 236 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 237 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 238 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 239 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 240 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 241 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 242 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 243 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 244 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 245 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 246 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 247 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 248 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 249 "data//maps/DragonsRoost/scripts.pory"
	release
# 250 "data//maps/DragonsRoost/scripts.pory"
	end
# 251 "data//maps/DragonsRoost/scripts.pory"

# 252 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 253 "data//maps/DragonsRoost/scripts.pory"
	lock
# 254 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 255 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 256 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 257 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 258 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 259 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 260 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 261 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 262 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 263 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 264 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 265 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 266 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 267 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 268 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 269 "data//maps/DragonsRoost/scripts.pory"
	release
# 270 "data//maps/DragonsRoost/scripts.pory"
	end
# 271 "data//maps/DragonsRoost/scripts.pory"

# 272 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 273 "data//maps/DragonsRoost/scripts.pory"
	lock
# 274 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 275 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 276 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 277 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 278 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 279 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 280 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 281 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 282 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 283 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 284 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 285 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 286 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 287 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 288 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 289 "data//maps/DragonsRoost/scripts.pory"
	release
# 290 "data//maps/DragonsRoost/scripts.pory"
	end
# 291 "data//maps/DragonsRoost/scripts.pory"

# 292 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 293 "data//maps/DragonsRoost/scripts.pory"
	lock
# 294 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 295 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 296 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 297 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 298 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 299 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 300 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 301 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 302 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 303 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 304 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 305 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 306 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 307 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 308 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 309 "data//maps/DragonsRoost/scripts.pory"
	release
# 310 "data//maps/DragonsRoost/scripts.pory"
	end
# 311 "data//maps/DragonsRoost/scripts.pory"

# 312 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 313 "data//maps/DragonsRoost/scripts.pory"
	lock
# 314 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 315 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 316 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 317 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 318 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 319 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 320 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 321 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 322 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 323 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 324 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 325 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 326 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 327 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 328 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 329 "data//maps/DragonsRoost/scripts.pory"
	release
# 330 "data//maps/DragonsRoost/scripts.pory"
	end
# 331 "data//maps/DragonsRoost/scripts.pory"

# 332 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 333 "data//maps/DragonsRoost/scripts.pory"
	release
# 334 "data//maps/DragonsRoost/scripts.pory"
	end
# 335 "data//maps/DragonsRoost/scripts.pory"

# 336 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 337 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 338 "data//maps/DragonsRoost/scripts.pory"
	lock
# 339 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 340 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 341 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 342 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 343 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 344 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 345 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 346 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 347 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 348 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 349 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 350 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 351 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 352 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 353 "data//maps/DragonsRoost/scripts.pory"
	end
# 354 "data//maps/DragonsRoost/scripts.pory"

# 355 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 356 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 357 "data//maps/DragonsRoost/scripts.pory"
	lock
# 358 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 359 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 360 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 361 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 362 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 363 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 364 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 365 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 366 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 367 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 368 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 369 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 370 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 371 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 372 "data//maps/DragonsRoost/scripts.pory"
	end
# 373 "data//maps/DragonsRoost/scripts.pory"

# 374 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 375 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 376 "data//maps/DragonsRoost/scripts.pory"
	lock
# 377 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 378 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 379 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 380 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 381 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 382 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 383 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 384 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 385 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 386 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 387 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 388 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 389 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 390 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 391 "data//maps/DragonsRoost/scripts.pory"
	end
# 392 "data//maps/DragonsRoost/scripts.pory"

# 393 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 394 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 395 "data//maps/DragonsRoost/scripts.pory"
	lock
# 396 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 397 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 398 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 399 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 400 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 401 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 402 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 403 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 404 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 405 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 406 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 407 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 408 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 409 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 410 "data//maps/DragonsRoost/scripts.pory"
	end
# 411 "data//maps/DragonsRoost/scripts.pory"

# 412 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 413 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 414 "data//maps/DragonsRoost/scripts.pory"
	lock
# 415 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 416 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 417 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 418 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 419 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 420 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 421 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 422 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 423 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 424 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 425 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 426 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 427 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 428 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 429 "data//maps/DragonsRoost/scripts.pory"
	end
# 430 "data//maps/DragonsRoost/scripts.pory"

# 431 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 432 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 433 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 434 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 435 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 436 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 437 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 438 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 439 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 440 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 441 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 442 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 443 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 444 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 445 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 446 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 447 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 448 "data//maps/DragonsRoost/scripts.pory"
	release
# 449 "data//maps/DragonsRoost/scripts.pory"
	end
# 450 "data//maps/DragonsRoost/scripts.pory"

# 451 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 452 "data//maps/DragonsRoost/scripts.pory"
	lock
# 453 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 454 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 455 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 456 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 457 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 458 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 459 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 460 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 461 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 462 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 463 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 464 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 465 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 466 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 467 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 468 "data//maps/DragonsRoost/scripts.pory"
	release
# 469 "data//maps/DragonsRoost/scripts.pory"
	end
# 470 "data//maps/DragonsRoost/scripts.pory"

# 471 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 472 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 473 "data//maps/DragonsRoost/scripts.pory"
	release
# 474 "data//maps/DragonsRoost/scripts.pory"
	end
# 475 "data//maps/DragonsRoost/scripts.pory"

# 476 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 477 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 478 "data//maps/DragonsRoost/scripts.pory"
	release
# 479 "data//maps/DragonsRoost/scripts.pory"
	end
# 480 "data//maps/DragonsRoost/scripts.pory"

# 481 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 482 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 483 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 484 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 485 "data//maps/DragonsRoost/scripts.pory"

# 486 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 487 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 488 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 489 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 490 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 491 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 492 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 493 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 494 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 495 "data//maps/DragonsRoost/scripts.pory"

# 496 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 497 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 498 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 499 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 500 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 501 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 502 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 503 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 504 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 505 "data//maps/DragonsRoost/scripts.pory"

# 506 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 507 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 508 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 509 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 510 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 511 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 512 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 513 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 514 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 515 "data//maps/DragonsRoost/scripts.pory"

# 516 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 517 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 518 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 519 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 520 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 521 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 522 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 523 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 524 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 525 "data//maps/DragonsRoost/scripts.pory"

# 526 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 527 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 528 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 529 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 530 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 531 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 532 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 533 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 534 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 535 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 536 "data//maps/DragonsRoost/scripts.pory"

# 537 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 538 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 539 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 540 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 541 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 542 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 543 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 544 "data//maps/DragonsRoost/scripts.pory"

# 545 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 546 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 547 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 548 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 549 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 550 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 551 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 552 "data//maps/DragonsRoost/scripts.pory"

# 553 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 554 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 555 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 556 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 557 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 558 "data//maps/DragonsRoost/scripts.pory"

# 559 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 560 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 561 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 562 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 563 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 564 "data//maps/DragonsRoost/scripts.pory"

# 565 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 566 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 567 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 568 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 569 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 570 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 571 "data//maps/DragonsRoost/scripts.pory"

# 572 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 573 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 574 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 575 "data//maps/DragonsRoost/scripts.pory"

# 576 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 577 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 578 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 579 "data//maps/DragonsRoost/scripts.pory"

# 580 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 581 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 582 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 583 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 584 "data//maps/DragonsRoost/scripts.pory"

# 585 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 586 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 587 "data//maps/DragonsRoost/scripts.pory"
	.string "cliff's edge!$"
# 588 "data//maps/DragonsRoost/scripts.pory"

# 589 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 590 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA roared nearby!$"
# 591 "data//maps/DragonsRoost/scripts.pory"

# 592 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 593 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 594 "data//maps/DragonsRoost/scripts.pory"

# 595 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_Clone:
# 596 "data//maps/DragonsRoost/scripts.pory"
	.string "Where am I?$"
