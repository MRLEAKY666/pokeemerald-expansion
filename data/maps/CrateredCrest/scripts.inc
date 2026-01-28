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
	setmetatile 41, 63, METATILE_Fallarbor_BrownRockWall, TRUE
# 16 "data//maps/CrateredCrest/scripts.pory"
	setmetatile 41, 64, METATILE_Fallarbor_BrownRockWall_GrassBase, TRUE
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
    applymovement LOCALID_CRATERED_CREST_PHIL, CrateredCrest_Movement_SurprisedPhil
# 183 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 184 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 185 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 186 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 187 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 1
# 188 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_1, 0
# 189 "data//maps/CrateredCrest/scripts.pory"
	release
# 190 "data//maps/CrateredCrest/scripts.pory"
	end
# 191 "data//maps/CrateredCrest/scripts.pory"

# 192 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SurprisedPhil:
# 193 "data//maps/CrateredCrest/scripts.pory"
    emote_exclamation_mark
# 194 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 195 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_left
# 196 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 197 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_right
# 198 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 199 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_up
# 200 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 201 "data//maps/CrateredCrest/scripts.pory"
    step_end
# 202 "data//maps/CrateredCrest/scripts.pory"

# 203 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DoMeteoriteSparkle::
# 204 "data//maps/CrateredCrest/scripts.pory"
	lock
# 205 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 206 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 207 "data//maps/CrateredCrest/scripts.pory"
	delay 45
# 208 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 209 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 210 "data//maps/CrateredCrest/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 211 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 212 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_CRATERED_CREST_METEORITE
# 213 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 4
# 214 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_2, 0
# 215 "data//maps/CrateredCrest/scripts.pory"
	release
# 216 "data//maps/CrateredCrest/scripts.pory"
	end
# 217 "data//maps/CrateredCrest/scripts.pory"

# 218 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Clone::
# 219 "data//maps/CrateredCrest/scripts.pory"
	lock
# 220 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_Clone, MSGBOX_DEFAULT 
# 221 "data//maps/CrateredCrest/scripts.pory"
	release
# 222 "data//maps/CrateredCrest/scripts.pory"
	end
# 223 "data//maps/CrateredCrest/scripts.pory"

# 224 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Croconaw::
# 225 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 226 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 227 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 228 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 229 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 230 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 231 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 232 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 233 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 234 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 235 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 236 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 237 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 238 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 239 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 240 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 241 "data//maps/CrateredCrest/scripts.pory"
	release
# 242 "data//maps/CrateredCrest/scripts.pory"
	end
# 243 "data//maps/CrateredCrest/scripts.pory"

# 244 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Aurorus::
# 245 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 246 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 247 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 248 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 249 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 250 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 251 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 252 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 253 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 254 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 255 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 256 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 257 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 258 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 259 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 260 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 261 "data//maps/CrateredCrest/scripts.pory"
	release
# 262 "data//maps/CrateredCrest/scripts.pory"
	end
# 263 "data//maps/CrateredCrest/scripts.pory"

# 264 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Dragonair::
# 265 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 266 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 267 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 268 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 269 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 270 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 271 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 272 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 273 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 274 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 275 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 276 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 277 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 278 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 279 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 280 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 281 "data//maps/CrateredCrest/scripts.pory"
	release
# 282 "data//maps/CrateredCrest/scripts.pory"
	end
# 283 "data//maps/CrateredCrest/scripts.pory"

# 284 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine1::
# 285 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 286 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 287 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 288 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 289 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 290 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 291 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 292 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 293 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 294 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 295 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 296 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 297 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 298 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 299 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 300 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 301 "data//maps/CrateredCrest/scripts.pory"
	release
# 302 "data//maps/CrateredCrest/scripts.pory"
	end
# 303 "data//maps/CrateredCrest/scripts.pory"

# 304 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine2::
# 305 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 306 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 307 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 308 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 309 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 310 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 311 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 312 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 313 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 314 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 315 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 316 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 317 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 318 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 319 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 320 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 321 "data//maps/CrateredCrest/scripts.pory"
	release
# 322 "data//maps/CrateredCrest/scripts.pory"
	end
# 323 "data//maps/CrateredCrest/scripts.pory"

# 324 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Gyarados::
# 325 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 326 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 327 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 328 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 329 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 330 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 331 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 332 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 333 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 334 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 335 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 336 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 337 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 338 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 339 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 340 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 341 "data//maps/CrateredCrest/scripts.pory"
	release
# 342 "data//maps/CrateredCrest/scripts.pory"
	end
# 343 "data//maps/CrateredCrest/scripts.pory"

# 344 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusNothing::
# 345 "data//maps/CrateredCrest/scripts.pory"
	release
# 346 "data//maps/CrateredCrest/scripts.pory"
	end
# 347 "data//maps/CrateredCrest/scripts.pory"

# 348 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusA::
# 349 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 350 "data//maps/CrateredCrest/scripts.pory"
	lock
# 351 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 352 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 353 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 354 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 355 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 356 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 357 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 358 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 359 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusA
# 360 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 361 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 362 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 363 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 364 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 365 "data//maps/CrateredCrest/scripts.pory"
	end
# 366 "data//maps/CrateredCrest/scripts.pory"

# 367 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusB::
# 368 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 369 "data//maps/CrateredCrest/scripts.pory"
	lock
# 370 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 371 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 372 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 373 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 374 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 375 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 376 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 377 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 378 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusB
# 379 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 380 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 381 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 382 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 383 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 384 "data//maps/CrateredCrest/scripts.pory"
	end
# 385 "data//maps/CrateredCrest/scripts.pory"

# 386 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusC::
# 387 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 388 "data//maps/CrateredCrest/scripts.pory"
	lock
# 389 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 390 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 391 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 392 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 393 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 394 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 395 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 396 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 397 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusC
# 398 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 399 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 400 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 401 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 402 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 403 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_Haxorus::
# 408 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 409 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 410 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 411 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 412 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_CRATERED_CREST_HAXORUS
# 413 "data//maps/CrateredCrest/scripts.pory"
	setwildbossmon 1
# 414 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 415 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 416 "data//maps/CrateredCrest/scripts.pory"
	special StartRegiBattle
# 417 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 418 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 419 "data//maps/CrateredCrest/scripts.pory"
	endwildbossmon
# 420 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_DEFEATED_CRATERED_CREST_HAXORUS
# 421 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS
# 422 "data//maps/CrateredCrest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 423 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CrateredCrest_EventScript_Haxorus_2
# 428 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CrateredCrest_EventScript_Haxorus_3
CrateredCrest_EventScript_Haxorus_1:
# 435 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusDefeated, MSGBOX_DEFAULT
# 436 "data//maps/CrateredCrest/scripts.pory"
	release
	return

CrateredCrest_EventScript_Haxorus_2:
# 424 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 425 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 426 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto CrateredCrest_EventScript_Haxorus_1

CrateredCrest_EventScript_Haxorus_3:
# 429 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 430 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 431 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 432 "data//maps/CrateredCrest/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 433 "data//maps/CrateredCrest/scripts.pory"
	msgbox gText_WildMonFled, MSGBOX_DEFAULT
	goto CrateredCrest_EventScript_Haxorus_1


# 439 "data//maps/CrateredCrest/scripts.pory"

# 440 "data//maps/CrateredCrest/scripts.pory"

# 441 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusDefeated:
# 442 "data//maps/CrateredCrest/scripts.pory"
    .string "The corpse of the wild HAXORUS\n"
# 443 "data//maps/CrateredCrest/scripts.pory"
    .string "collapsed into the marshy soil.$"
# 444 "data//maps/CrateredCrest/scripts.pory"

# 445 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Tyrantrum::
# 446 "data//maps/CrateredCrest/scripts.pory"
	lock
# 447 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 448 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 449 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 450 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 451 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 452 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 453 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 454 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 455 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 456 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 457 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 458 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 459 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 460 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 461 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 462 "data//maps/CrateredCrest/scripts.pory"
	release
# 463 "data//maps/CrateredCrest/scripts.pory"
	end
# 464 "data//maps/CrateredCrest/scripts.pory"

# 465 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DefeatedWildMon::
# 466 "data//maps/CrateredCrest/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 467 "data//maps/CrateredCrest/scripts.pory"
	release
# 468 "data//maps/CrateredCrest/scripts.pory"
	end
# 469 "data//maps/CrateredCrest/scripts.pory"

# 470 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_RanWildMon::
# 471 "data//maps/CrateredCrest/scripts.pory"
	goto Common_EventScript_WildMonFled
# 472 "data//maps/CrateredCrest/scripts.pory"
	release
# 473 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_RuinManiacPhil::
# 478 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 479 "data//maps/CrateredCrest/scripts.pory"
	checktrainerflag TRAINER_PHIL_CRATERED_CREST
	goto_if 0, CrateredCrest_EventScript_RuinManiacPhil_2
CrateredCrest_EventScript_RuinManiacPhil_1:
# 489 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_PhilPostBattle, MSGBOX_DEFAULT
# 490 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_PHIL, Common_Movement_FaceOriginalDirection
# 491 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 492 "data//maps/CrateredCrest/scripts.pory"
	release
	return

CrateredCrest_EventScript_RuinManiacPhil_2:
# 480 "data//maps/CrateredCrest/scripts.pory"
	playbgm MUS_ENCOUNTER_HIKER, FALSE
# 481 "data//maps/CrateredCrest/scripts.pory"
	message CrateredCrest_Text_PhilWait
# 482 "data//maps/CrateredCrest/scripts.pory"
	waitmessage
# 483 "data//maps/CrateredCrest/scripts.pory"
	delay 30
# 484 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 485 "data//maps/CrateredCrest/scripts.pory"
	delay 60
# 486 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_PhilIntro, MSGBOX_DEFAULT
# 487 "data//maps/CrateredCrest/scripts.pory"
	trainerbattle_no_intro TRAINER_PHIL_CRATERED_CREST, CrateredCrest_Text_PhilDefeat
	goto CrateredCrest_EventScript_RuinManiacPhil_1


# 495 "data//maps/CrateredCrest/scripts.pory"

# 496 "data//maps/CrateredCrest/scripts.pory"

# 497 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilWait:
# 498 "data//maps/CrateredCrest/scripts.pory"
    .string "… … … … … … … …\n"
# 499 "data//maps/CrateredCrest/scripts.pory"
	.string "… … … … … … … …$"
# 500 "data//maps/CrateredCrest/scripts.pory"

# 501 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilIntro:
# 502 "data//maps/CrateredCrest/scripts.pory"
    .string "I don't know how to swim…$"
# 503 "data//maps/CrateredCrest/scripts.pory"

# 504 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilDefeat:
# 505 "data//maps/CrateredCrest/scripts.pory"
    .string "Oh!\l"
# 506 "data//maps/CrateredCrest/scripts.pory"
    .string "You know how to swim?$"
# 507 "data//maps/CrateredCrest/scripts.pory"

# 508 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilPostBattle:
# 509 "data//maps/CrateredCrest/scripts.pory"
    .string "I came to investigate the ruins\n"
# 510 "data//maps/CrateredCrest/scripts.pory"
    .string "at the center of this crater.\p"
# 511 "data//maps/CrateredCrest/scripts.pory"
    .string "But they're in the middle of\n"
# 512 "data//maps/CrateredCrest/scripts.pory"
    .string "the lake…$"
# 513 "data//maps/CrateredCrest/scripts.pory"

# 514 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyOff:
# 515 "data//maps/CrateredCrest/scripts.pory"
	delay_16
# 516 "data//maps/CrateredCrest/scripts.pory"
	fly_up
# 517 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 518 "data//maps/CrateredCrest/scripts.pory"

# 519 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpI:
# 520 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 521 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 522 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 523 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 524 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 525 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 526 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 527 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 528 "data//maps/CrateredCrest/scripts.pory"

# 529 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpII:
# 530 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 531 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 532 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 533 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 534 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 535 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 536 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 537 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 538 "data//maps/CrateredCrest/scripts.pory"

# 539 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownI:
# 540 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 541 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 542 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 543 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 544 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 545 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 546 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 547 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 548 "data//maps/CrateredCrest/scripts.pory"

# 549 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownII:
# 550 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 551 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 552 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 553 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 554 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 555 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 556 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 557 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 558 "data//maps/CrateredCrest/scripts.pory"

# 559 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyDown:
# 560 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 561 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 562 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 563 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 564 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 565 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 566 "data//maps/CrateredCrest/scripts.pory"
	walk_faster_down
# 567 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 568 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 569 "data//maps/CrateredCrest/scripts.pory"

# 570 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_HaxorusApproach:
# 571 "data//maps/CrateredCrest/scripts.pory"
    walk_down
# 572 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 573 "data//maps/CrateredCrest/scripts.pory"

# 574 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusA:
# 575 "data//maps/CrateredCrest/scripts.pory"
    walk_right
# 576 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 577 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 578 "data//maps/CrateredCrest/scripts.pory"

# 579 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusB:
# 580 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 581 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 582 "data//maps/CrateredCrest/scripts.pory"

# 583 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusC:
# 584 "data//maps/CrateredCrest/scripts.pory"
    walk_left
# 585 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 586 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 587 "data//maps/CrateredCrest/scripts.pory"

# 588 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetInvisible:
# 589 "data//maps/CrateredCrest/scripts.pory"
	set_invisible
# 590 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 591 "data//maps/CrateredCrest/scripts.pory"

# 592 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetVisible:
# 593 "data//maps/CrateredCrest/scripts.pory"
	set_visible
# 594 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 595 "data//maps/CrateredCrest/scripts.pory"

# 596 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaFlewOff:
# 597 "data//maps/CrateredCrest/scripts.pory"
	.string "But it flew off…\p"
# 598 "data//maps/CrateredCrest/scripts.pory"
	.string "It seemed like it was headed back\n"
# 599 "data//maps/CrateredCrest/scripts.pory"
	.string "towards SKY PILLAR!$"
# 600 "data//maps/CrateredCrest/scripts.pory"

# 601 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaAppeared:
# 602 "data//maps/CrateredCrest/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 603 "data//maps/CrateredCrest/scripts.pory"
	.string "cliff's edge!$"
# 604 "data//maps/CrateredCrest/scripts.pory"

# 605 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaIsHere:
# 606 "data//maps/CrateredCrest/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 607 "data//maps/CrateredCrest/scripts.pory"

# 608 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusAttacked:
# 609 "data//maps/CrateredCrest/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 610 "data//maps/CrateredCrest/scripts.pory"

# 611 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_Clone:
# 612 "data//maps/CrateredCrest/scripts.pory"
	.string "Where am I?$"

CrateredCrest_EventScript_RandomiseOvrWrldMonPos::
# 617 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1
# 629 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1:
# 618 "data//maps/CrateredCrest/scripts.pory"
	random 3
# 619 "data//maps/CrateredCrest/scripts.pory"
	switch VAR_RESULT
# 620 "data//maps/CrateredCrest/scripts.pory"
	case 0, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5
# 622 "data//maps/CrateredCrest/scripts.pory"
	case 1, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6
# 624 "data//maps/CrateredCrest/scripts.pory"
	case 2, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5:
# 621 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6:
# 623 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosB
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7:
# 625 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosC
	return


CrateredCrest_EventScript_OvrWrldMonPosA::
	return


CrateredCrest_EventScript_OvrWrldMonPosB::
	return


CrateredCrest_EventScript_OvrWrldMonPosC::
	return

