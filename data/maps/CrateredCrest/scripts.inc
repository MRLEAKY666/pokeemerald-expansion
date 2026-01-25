# 1 "data//maps/CrateredCrest/scripts.pory"

# 2 "data//maps/CrateredCrest/scripts.pory"

# 3 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_MapScripts::
# 4 "data//maps/CrateredCrest/scripts.pory"
    map_script MAP_SCRIPT_ON_LOAD, CrateredCrest_OnLoad
# 5 "data//maps/CrateredCrest/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CrateredCrest_OnResume
# 6 "data//maps/CrateredCrest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrateredCrest_OnTransition
# 7 "data//maps/CrateredCrest/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CrateredCrest_OnFrame
# 8 "data//maps/CrateredCrest/scripts.pory"
	.byte 0
# 9 "data//maps/CrateredCrest/scripts.pory"

# 10 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_OnLoad:
# 11 "data//maps/CrateredCrest/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, CrateredCrest_CloseRegiEntrance
# 12 "data//maps/CrateredCrest/scripts.pory"
    end
# 13 "data//maps/CrateredCrest/scripts.pory"

# 14 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_CloseRegiEntrance::
# 15 "data//maps/CrateredCrest/scripts.pory"
	setmetatile 41, 65, METATILE_Fallarbor_BrownRockWall, TRUE
# 16 "data//maps/CrateredCrest/scripts.pory"
	setmetatile 41, 66, METATILE_Fallarbor_BrownRockWall_GrassBase, TRUE
# 17 "data//maps/CrateredCrest/scripts.pory"
	return
# 18 "data//maps/CrateredCrest/scripts.pory"

# 19 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_OnFrame:
# 20 "data//maps/CrateredCrest/scripts.pory"
	@ map_script_2 VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 0, CrateredCrest_EventScript_DoRayquazaCry
# 21 "data//maps/CrateredCrest/scripts.pory"
	@ map_script_2 VAR_TEMP_1, 1, CrateredCrest_EventScript_DoRayquazaCry
# 22 "data//maps/CrateredCrest/scripts.pory"
	map_script_2 VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 2, CrateredCrest_EventScript_ContinueRayquazaScene
# 23 "data//maps/CrateredCrest/scripts.pory"
	map_script_2 VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3, CrateredCrest_EventScript_DoMeteoriteSparkle
# 24 "data//maps/CrateredCrest/scripts.pory"
	.2byte 0
# 25 "data//maps/CrateredCrest/scripts.pory"

# 26 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_OnResume:
# 27 "data//maps/CrateredCrest/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CrateredCrest_EventScript_TryRemoveWildMon
# 28 "data//maps/CrateredCrest/scripts.pory"
	end
# 29 "data//maps/CrateredCrest/scripts.pory"

# 30 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_TryRemoveWildMon::
# 31 "data//maps/CrateredCrest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 32 "data//maps/CrateredCrest/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 33 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 34 "data//maps/CrateredCrest/scripts.pory"
	return
# 35 "data//maps/CrateredCrest/scripts.pory"

# 36 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_OnTransition:
# 37 "data//maps/CrateredCrest/scripts.pory"
	call_if_unset FLAG_CRATERED_CREST_METEORITE, CrateredCrest_EventScript_PrepRepeatSparkle
# 38 "data//maps/CrateredCrest/scripts.pory"
	call_if_le VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 1, CrateredCrest_EventScript_PrepRayquazaCry
# 39 "data//maps/CrateredCrest/scripts.pory"
	call_if_unset FLAG_CRATERED_CREST_CLONE, CrateredCrest_EventScript_HideClone
# 40 "data//maps/CrateredCrest/scripts.pory"
	call CrateredCrest_EventScript_SetupPlayerCloneGfxId
# 41 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_PrepRayquazaCry::
# 45 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_1, 1
	return


# 49 "data//maps/CrateredCrest/scripts.pory"

# 50 "data//maps/CrateredCrest/scripts.pory"

# 51 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PrepRepeatSparkle::
# 52 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_2, 1
# 53 "data//maps/CrateredCrest/scripts.pory"
	return
# 54 "data//maps/CrateredCrest/scripts.pory"

# 55 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HideClone::
# 56 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_PLAYER_CLONE
# 57 "data//maps/CrateredCrest/scripts.pory"
	return
# 58 "data//maps/CrateredCrest/scripts.pory"

# 59 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_SetupPlayerCloneGfxId::
# 60 "data//maps/CrateredCrest/scripts.pory"
	checkplayergender
# 61 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, CrateredCrest_EventScript_PlayerCloneMale
# 62 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, CrateredCrest_EventScript_PlayerCloneFemale
# 63 "data//maps/CrateredCrest/scripts.pory"
	end
# 64 "data//maps/CrateredCrest/scripts.pory"

# 65 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PlayerCloneMale::
# 66 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 67 "data//maps/CrateredCrest/scripts.pory"
	return
# 68 "data//maps/CrateredCrest/scripts.pory"

# 69 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PlayerCloneFemale::
# 70 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 71 "data//maps/CrateredCrest/scripts.pory"
	return
# 72 "data//maps/CrateredCrest/scripts.pory"

# 73 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Rayquaza::
# 74 "data//maps/CrateredCrest/scripts.pory"
	lock
# 75 "data//maps/CrateredCrest/scripts.pory"
    delay 20
# 76 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 77 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 78 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 79 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 80 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 81 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 82 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 83 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 84 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 85 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 86 "data//maps/CrateredCrest/scripts.pory"
    waitmovement LOCALID_PLAYER
# 87 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 88 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 89 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 90 "data//maps/CrateredCrest/scripts.pory"
	@ setweather WEATHER_SUNNY
# 91 "data//maps/CrateredCrest/scripts.pory"
	@ doweather
# 92 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 93 "data//maps/CrateredCrest/scripts.pory"
	fadeoutbgm 1
# 94 "data//maps/CrateredCrest/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 95 "data//maps/CrateredCrest/scripts.pory"
	setobjectxyperm LOCALID_CRATERED_CREST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 96 "data//maps/CrateredCrest/scripts.pory"
	setobjectxy LOCALID_CRATERED_CREST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 97 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_CRATERED_CREST_CLONE
# 98 "data//maps/CrateredCrest/scripts.pory"
	addobject LOCALID_CRATERED_CREST_PLAYER_CLONE, MAP_CRATERED_CREST
# 99 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_PLAYER_CLONE, Common_Movement_FaceUp
# 100 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_PLAYER_CLONE
# 101 "data//maps/CrateredCrest/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_CRATERED_CREST
# 102 "data//maps/CrateredCrest/scripts.pory"
	showobjectat LOCALID_CRATERED_CREST_PLAYER_CLONE, MAP_CRATERED_CREST
# 103 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_RAYQUAZA, CrateredCrest_Movement_RayquazaFlyDown
# 104 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_CameraPanUpI
# 105 "data//maps/CrateredCrest/scripts.pory"
	hidefollower
# 106 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_RAYQUAZA
# 107 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 2
# 108 "data//maps/CrateredCrest/scripts.pory"
	release 
# 109 "data//maps/CrateredCrest/scripts.pory"
	end 
# 110 "data//maps/CrateredCrest/scripts.pory"

# 111 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_ContinueRayquazaScene::
# 112 "data//maps/CrateredCrest/scripts.pory"

# 113 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 114 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 115 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 116 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 117 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 118 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 119 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 120 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 121 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 122 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 123 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 124 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 125 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 126 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 127 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 128 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 129 "data//maps/CrateredCrest/scripts.pory"

# 130 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 131 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 132 "data//maps/CrateredCrest/scripts.pory"

# 133 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 134 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 135 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 136 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 137 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 138 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 139 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 140 "data//maps/CrateredCrest/scripts.pory"

# 141 "data//maps/CrateredCrest/scripts.pory"
	delay 45
# 142 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_RAYQUAZA, CrateredCrest_Movement_RayquazaFlyOff
# 143 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_RAYQUAZA
# 144 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_RAYQUAZA
# 145 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 146 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 147 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 148 "data//maps/CrateredCrest/scripts.pory"
	fadeinbgm 2
# 149 "data//maps/CrateredCrest/scripts.pory"

# 150 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_CameraPanDownII
# 151 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 152 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_PLAYER_CLONE
# 153 "data//maps/CrateredCrest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 154 "data//maps/CrateredCrest/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_CRATERED_CREST
# 155 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 156 "data//maps/CrateredCrest/scripts.pory"

# 157 "data//maps/CrateredCrest/scripts.pory"
	resetweather
# 158 "data//maps/CrateredCrest/scripts.pory"
	doweather
# 159 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3
# 160 "data//maps/CrateredCrest/scripts.pory"
	release
# 161 "data//maps/CrateredCrest/scripts.pory"
	end
# 162 "data//maps/CrateredCrest/scripts.pory"

# 163 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DoRayquazaCry::
# 164 "data//maps/CrateredCrest/scripts.pory"
	lock
# 165 "data//maps/CrateredCrest/scripts.pory"
    delay 20
# 166 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 167 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 168 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 169 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 170 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 171 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 172 "data//maps/CrateredCrest/scripts.pory"
	@ waitmovement 0
# 173 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 174 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 175 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 176 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 177 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 178 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 179 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 180 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 181 "data//maps/CrateredCrest/scripts.pory"
	@ waitmovement 0
# 182 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 183 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 184 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 185 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 186 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 1
# 187 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_1, 0
# 188 "data//maps/CrateredCrest/scripts.pory"
	release
# 189 "data//maps/CrateredCrest/scripts.pory"
	end
# 190 "data//maps/CrateredCrest/scripts.pory"

# 191 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DoMeteoriteSparkle::
# 192 "data//maps/CrateredCrest/scripts.pory"
	lock
# 193 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 194 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 195 "data//maps/CrateredCrest/scripts.pory"
	delay 45
# 196 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 197 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 198 "data//maps/CrateredCrest/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 199 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 200 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_CRATERED_CREST_METEORITE
# 201 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 4
# 202 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_2, 0
# 203 "data//maps/CrateredCrest/scripts.pory"
	release
# 204 "data//maps/CrateredCrest/scripts.pory"
	end
# 205 "data//maps/CrateredCrest/scripts.pory"

# 206 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Clone::
# 207 "data//maps/CrateredCrest/scripts.pory"
	lock
# 208 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_Clone, MSGBOX_DEFAULT 
# 209 "data//maps/CrateredCrest/scripts.pory"
	release
# 210 "data//maps/CrateredCrest/scripts.pory"
	end
# 211 "data//maps/CrateredCrest/scripts.pory"

# 212 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Croconaw::
# 213 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 214 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 215 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 216 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 217 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 218 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 219 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 220 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 221 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 222 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 223 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 224 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 225 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 226 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 227 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 228 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 229 "data//maps/CrateredCrest/scripts.pory"
	release
# 230 "data//maps/CrateredCrest/scripts.pory"
	end
# 231 "data//maps/CrateredCrest/scripts.pory"

# 232 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Aurorus::
# 233 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 234 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 235 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 236 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 237 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 238 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 239 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 240 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 241 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 242 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 243 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 244 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 245 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 246 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 247 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 248 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 249 "data//maps/CrateredCrest/scripts.pory"
	release
# 250 "data//maps/CrateredCrest/scripts.pory"
	end
# 251 "data//maps/CrateredCrest/scripts.pory"

# 252 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Dragonair::
# 253 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 254 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 255 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 256 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 257 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 258 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 259 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 260 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 261 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 262 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 263 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 264 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 265 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 266 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 267 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 268 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 269 "data//maps/CrateredCrest/scripts.pory"
	release
# 270 "data//maps/CrateredCrest/scripts.pory"
	end
# 271 "data//maps/CrateredCrest/scripts.pory"

# 272 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine1::
# 273 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 274 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 275 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 276 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 277 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 278 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 279 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 280 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 281 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 282 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 283 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 284 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 285 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 286 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 287 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 288 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 289 "data//maps/CrateredCrest/scripts.pory"
	release
# 290 "data//maps/CrateredCrest/scripts.pory"
	end
# 291 "data//maps/CrateredCrest/scripts.pory"

# 292 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine2::
# 293 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 294 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 295 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 296 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 297 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 298 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 299 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 300 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 301 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 302 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 303 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 304 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 305 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 306 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 307 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 308 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 309 "data//maps/CrateredCrest/scripts.pory"
	release
# 310 "data//maps/CrateredCrest/scripts.pory"
	end
# 311 "data//maps/CrateredCrest/scripts.pory"

# 312 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Gyarados::
# 313 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 314 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 315 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 316 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 317 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 318 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 319 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 320 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 321 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 322 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 323 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 324 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 325 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 326 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 327 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 328 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 329 "data//maps/CrateredCrest/scripts.pory"
	release
# 330 "data//maps/CrateredCrest/scripts.pory"
	end
# 331 "data//maps/CrateredCrest/scripts.pory"

# 332 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusNothing::
# 333 "data//maps/CrateredCrest/scripts.pory"
	release
# 334 "data//maps/CrateredCrest/scripts.pory"
	end
# 335 "data//maps/CrateredCrest/scripts.pory"

# 336 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusA::
# 337 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 338 "data//maps/CrateredCrest/scripts.pory"
	lock
# 339 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 340 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 341 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 342 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 343 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 344 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 345 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 346 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 347 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusA
# 348 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 349 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 350 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 351 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 352 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 353 "data//maps/CrateredCrest/scripts.pory"
	end
# 354 "data//maps/CrateredCrest/scripts.pory"

# 355 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusB::
# 356 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 357 "data//maps/CrateredCrest/scripts.pory"
	lock
# 358 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 359 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 360 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 361 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 362 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 363 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 364 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 365 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 366 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusB
# 367 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 368 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 369 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 370 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 371 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 372 "data//maps/CrateredCrest/scripts.pory"
	end
# 373 "data//maps/CrateredCrest/scripts.pory"

# 374 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusC::
# 375 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 376 "data//maps/CrateredCrest/scripts.pory"
	lock
# 377 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 378 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 379 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 380 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 381 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 382 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 383 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 384 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 385 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusC
# 386 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 387 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 388 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 389 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 390 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 391 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_Haxorus::
# 396 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 397 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 398 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 399 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 400 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_CRATERED_CREST_HAXORUS
# 401 "data//maps/CrateredCrest/scripts.pory"
	setwildbossmon 1
# 402 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 403 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 404 "data//maps/CrateredCrest/scripts.pory"
	special StartRegiBattle
# 405 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 406 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 407 "data//maps/CrateredCrest/scripts.pory"
	endwildbossmon
# 408 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_DEFEATED_CRATERED_CREST_HAXORUS
# 409 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS
# 410 "data//maps/CrateredCrest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 411 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CrateredCrest_EventScript_Haxorus_2
# 416 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CrateredCrest_EventScript_Haxorus_3
CrateredCrest_EventScript_Haxorus_1:
# 423 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusDefeated, MSGBOX_DEFAULT
# 424 "data//maps/CrateredCrest/scripts.pory"
	release
	return

CrateredCrest_EventScript_Haxorus_2:
# 412 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 413 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 414 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto CrateredCrest_EventScript_Haxorus_1

CrateredCrest_EventScript_Haxorus_3:
# 417 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 418 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 419 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 420 "data//maps/CrateredCrest/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 421 "data//maps/CrateredCrest/scripts.pory"
	msgbox gText_WildMonFled, MSGBOX_DEFAULT
	goto CrateredCrest_EventScript_Haxorus_1


# 427 "data//maps/CrateredCrest/scripts.pory"

# 428 "data//maps/CrateredCrest/scripts.pory"

# 429 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusDefeated:
# 430 "data//maps/CrateredCrest/scripts.pory"
    .string "The corpse of the wild HAXORUS\n"
# 431 "data//maps/CrateredCrest/scripts.pory"
    .string "collapsed into the marshy soil.$"
# 432 "data//maps/CrateredCrest/scripts.pory"

# 433 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Tyrantrum::
# 434 "data//maps/CrateredCrest/scripts.pory"
	lock
# 435 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 436 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 437 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 438 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 439 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 440 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 441 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 442 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 443 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 444 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 445 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 446 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 447 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 448 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 449 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 450 "data//maps/CrateredCrest/scripts.pory"
	release
# 451 "data//maps/CrateredCrest/scripts.pory"
	end
# 452 "data//maps/CrateredCrest/scripts.pory"

# 453 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DefeatedWildMon::
# 454 "data//maps/CrateredCrest/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 455 "data//maps/CrateredCrest/scripts.pory"
	release
# 456 "data//maps/CrateredCrest/scripts.pory"
	end
# 457 "data//maps/CrateredCrest/scripts.pory"

# 458 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_RanWildMon::
# 459 "data//maps/CrateredCrest/scripts.pory"
	goto Common_EventScript_WildMonFled
# 460 "data//maps/CrateredCrest/scripts.pory"
	release
# 461 "data//maps/CrateredCrest/scripts.pory"
	end
# 462 "data//maps/CrateredCrest/scripts.pory"

# 463 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyOff:
# 464 "data//maps/CrateredCrest/scripts.pory"
	delay_16
# 465 "data//maps/CrateredCrest/scripts.pory"
	fly_up
# 466 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 467 "data//maps/CrateredCrest/scripts.pory"

# 468 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpI:
# 469 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 470 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 471 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 472 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 473 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 474 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 475 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 476 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 477 "data//maps/CrateredCrest/scripts.pory"

# 478 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpII:
# 479 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 480 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 481 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 482 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 483 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 484 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 485 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 486 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 487 "data//maps/CrateredCrest/scripts.pory"

# 488 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownI:
# 489 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 490 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 491 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 492 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 493 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 494 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 495 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 496 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 497 "data//maps/CrateredCrest/scripts.pory"

# 498 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownII:
# 499 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 500 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 501 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 502 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 503 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 504 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 505 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 506 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 507 "data//maps/CrateredCrest/scripts.pory"

# 508 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyDown:
# 509 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 510 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 511 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 512 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 513 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 514 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 515 "data//maps/CrateredCrest/scripts.pory"
	walk_faster_down
# 516 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 517 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 518 "data//maps/CrateredCrest/scripts.pory"

# 519 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_HaxorusApproach:
# 520 "data//maps/CrateredCrest/scripts.pory"
    walk_down
# 521 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 522 "data//maps/CrateredCrest/scripts.pory"

# 523 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusA:
# 524 "data//maps/CrateredCrest/scripts.pory"
    walk_right
# 525 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 526 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 527 "data//maps/CrateredCrest/scripts.pory"

# 528 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusB:
# 529 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 530 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 531 "data//maps/CrateredCrest/scripts.pory"

# 532 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusC:
# 533 "data//maps/CrateredCrest/scripts.pory"
    walk_left
# 534 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 535 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 536 "data//maps/CrateredCrest/scripts.pory"

# 537 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetInvisible:
# 538 "data//maps/CrateredCrest/scripts.pory"
	set_invisible
# 539 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 540 "data//maps/CrateredCrest/scripts.pory"

# 541 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetVisible:
# 542 "data//maps/CrateredCrest/scripts.pory"
	set_visible
# 543 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 544 "data//maps/CrateredCrest/scripts.pory"

# 545 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaFlewOff:
# 546 "data//maps/CrateredCrest/scripts.pory"
	.string "But it flew off…\p"
# 547 "data//maps/CrateredCrest/scripts.pory"
	.string "It seemed like it was headed back\n"
# 548 "data//maps/CrateredCrest/scripts.pory"
	.string "towards SKY PILLAR!$"
# 549 "data//maps/CrateredCrest/scripts.pory"

# 550 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaAppeared:
# 551 "data//maps/CrateredCrest/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 552 "data//maps/CrateredCrest/scripts.pory"
	.string "cliff's edge!$"
# 553 "data//maps/CrateredCrest/scripts.pory"

# 554 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaIsHere:
# 555 "data//maps/CrateredCrest/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 556 "data//maps/CrateredCrest/scripts.pory"

# 557 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusAttacked:
# 558 "data//maps/CrateredCrest/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 559 "data//maps/CrateredCrest/scripts.pory"

# 560 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_Clone:
# 561 "data//maps/CrateredCrest/scripts.pory"
	.string "Where am I?$"

CrateredCrest_EventScript_RandomiseOvrWrldMonPos::
# 566 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1
# 578 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1:
# 567 "data//maps/CrateredCrest/scripts.pory"
	random 3
# 568 "data//maps/CrateredCrest/scripts.pory"
	switch VAR_RESULT
# 569 "data//maps/CrateredCrest/scripts.pory"
	case 0, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5
# 571 "data//maps/CrateredCrest/scripts.pory"
	case 1, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6
# 573 "data//maps/CrateredCrest/scripts.pory"
	case 2, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5:
# 570 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6:
# 572 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosB
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7:
# 574 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosC
	return


CrateredCrest_EventScript_OvrWrldMonPosA::
	return


CrateredCrest_EventScript_OvrWrldMonPosB::
	return


CrateredCrest_EventScript_OvrWrldMonPosC::
	return

