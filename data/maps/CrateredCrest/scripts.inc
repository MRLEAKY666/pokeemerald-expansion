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

CrateredCrest_OnTransition::
# 39 "data//maps/CrateredCrest/scripts.pory"
	call_if_unset FLAG_CRATERED_CREST_METEORITE, CrateredCrest_EventScript_PrepRepeatSparkle
# 40 "data//maps/CrateredCrest/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 41 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_TEMP_F, 77
	goto_if_eq CrateredCrest_OnTransition_2
CrateredCrest_OnTransition_1:
# 44 "data//maps/CrateredCrest/scripts.pory"
	call_if_unset FLAG_CRATERED_CREST_CLONE, CrateredCrest_EventScript_HideClone
# 45 "data//maps/CrateredCrest/scripts.pory"
	call CrateredCrest_EventScript_SetupPlayerCloneGfxId
	return

CrateredCrest_OnTransition_2:
# 42 "data//maps/CrateredCrest/scripts.pory"
	call_if_le VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 1, CrateredCrest_EventScript_PrepRayquazaCry
	goto CrateredCrest_OnTransition_1


CrateredCrest_EventScript_PrepRayquazaCry::
# 49 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_1, 1
	return


# 53 "data//maps/CrateredCrest/scripts.pory"

# 54 "data//maps/CrateredCrest/scripts.pory"

# 55 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PrepRepeatSparkle::
# 56 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_2, 1
# 57 "data//maps/CrateredCrest/scripts.pory"
	return
# 58 "data//maps/CrateredCrest/scripts.pory"

# 59 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HideClone::
# 60 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_PLAYER_CLONE
# 61 "data//maps/CrateredCrest/scripts.pory"
	return
# 62 "data//maps/CrateredCrest/scripts.pory"

# 63 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_SetupPlayerCloneGfxId::
# 64 "data//maps/CrateredCrest/scripts.pory"
	checkplayergender
# 65 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, CrateredCrest_EventScript_PlayerCloneMale
# 66 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, CrateredCrest_EventScript_PlayerCloneFemale
# 67 "data//maps/CrateredCrest/scripts.pory"
	end
# 68 "data//maps/CrateredCrest/scripts.pory"

# 69 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PlayerCloneMale::
# 70 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 71 "data//maps/CrateredCrest/scripts.pory"
	return
# 72 "data//maps/CrateredCrest/scripts.pory"

# 73 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_PlayerCloneFemale::
# 74 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 75 "data//maps/CrateredCrest/scripts.pory"
	return
# 76 "data//maps/CrateredCrest/scripts.pory"

# 77 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Rayquaza::
# 78 "data//maps/CrateredCrest/scripts.pory"
	lock
# 79 "data//maps/CrateredCrest/scripts.pory"
    delay 20
# 80 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 81 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 82 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 83 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 84 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 85 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 86 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 87 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 88 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 89 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 90 "data//maps/CrateredCrest/scripts.pory"
    waitmovement LOCALID_PLAYER
# 91 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 92 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 93 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 94 "data//maps/CrateredCrest/scripts.pory"
	@ setweather WEATHER_SUNNY
# 95 "data//maps/CrateredCrest/scripts.pory"
	@ doweather
# 96 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 97 "data//maps/CrateredCrest/scripts.pory"
	fadeoutbgm 1
# 98 "data//maps/CrateredCrest/scripts.pory"
	getobjectxy LOCALID_PLAYER, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 99 "data//maps/CrateredCrest/scripts.pory"
	setobjectxyperm LOCALID_CRATERED_CREST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 100 "data//maps/CrateredCrest/scripts.pory"
	setobjectxy LOCALID_CRATERED_CREST_PLAYER_CLONE, VAR_TEMP_E, VAR_TEMP_F
# 101 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_CRATERED_CREST_CLONE
# 102 "data//maps/CrateredCrest/scripts.pory"
	addobject LOCALID_CRATERED_CREST_PLAYER_CLONE, MAP_CRATERED_CREST
# 103 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_PLAYER_CLONE, Common_Movement_FaceUp
# 104 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_PLAYER_CLONE
# 105 "data//maps/CrateredCrest/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_CRATERED_CREST
# 106 "data//maps/CrateredCrest/scripts.pory"
	showobjectat LOCALID_CRATERED_CREST_PLAYER_CLONE, MAP_CRATERED_CREST
# 107 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_RAYQUAZA, CrateredCrest_Movement_RayquazaFlyDown
# 108 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_CameraPanUpI
# 109 "data//maps/CrateredCrest/scripts.pory"
	hidefollower
# 110 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_RAYQUAZA
# 111 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 2
# 112 "data//maps/CrateredCrest/scripts.pory"
	release 
# 113 "data//maps/CrateredCrest/scripts.pory"
	end 
# 114 "data//maps/CrateredCrest/scripts.pory"

# 115 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_ContinueRayquazaScene::
# 116 "data//maps/CrateredCrest/scripts.pory"

# 117 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 118 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 119 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 120 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 121 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 122 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 123 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 124 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 125 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 126 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 127 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 128 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 129 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 130 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 131 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 132 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 133 "data//maps/CrateredCrest/scripts.pory"

# 134 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 135 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 136 "data//maps/CrateredCrest/scripts.pory"

# 137 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_FAINT
# 138 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 139 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 140 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 141 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 142 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 143 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 144 "data//maps/CrateredCrest/scripts.pory"

# 145 "data//maps/CrateredCrest/scripts.pory"
	delay 45
# 146 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_RAYQUAZA, CrateredCrest_Movement_RayquazaFlyOff
# 147 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_CRATERED_CREST_RAYQUAZA
# 148 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_RAYQUAZA
# 149 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 150 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 151 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 152 "data//maps/CrateredCrest/scripts.pory"
	fadeinbgm 2
# 153 "data//maps/CrateredCrest/scripts.pory"

# 154 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_CameraPanDownII
# 155 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 156 "data//maps/CrateredCrest/scripts.pory"
	removeobject LOCALID_CRATERED_CREST_PLAYER_CLONE
# 157 "data//maps/CrateredCrest/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 158 "data//maps/CrateredCrest/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_CRATERED_CREST
# 159 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 160 "data//maps/CrateredCrest/scripts.pory"

# 161 "data//maps/CrateredCrest/scripts.pory"
	resetweather
# 162 "data//maps/CrateredCrest/scripts.pory"
	doweather
# 163 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3
# 164 "data//maps/CrateredCrest/scripts.pory"
	release
# 165 "data//maps/CrateredCrest/scripts.pory"
	end
# 166 "data//maps/CrateredCrest/scripts.pory"

# 167 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DoRayquazaCry::
# 168 "data//maps/CrateredCrest/scripts.pory"
	lock
# 169 "data//maps/CrateredCrest/scripts.pory"
    delay 20
# 170 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 171 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 172 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 173 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 174 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 175 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 176 "data//maps/CrateredCrest/scripts.pory"
	@ waitmovement 0
# 177 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 178 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 179 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 180 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 181 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 182 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 183 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 184 "data//maps/CrateredCrest/scripts.pory"
	special ShakeCamera
# 185 "data//maps/CrateredCrest/scripts.pory"
	@ waitmovement 0
# 186 "data//maps/CrateredCrest/scripts.pory"
    applymovement LOCALID_CRATERED_CREST_PHIL, CrateredCrest_Movement_SurprisedPhil
# 187 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 188 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 189 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 190 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 191 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 1
# 192 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_1, 0
# 193 "data//maps/CrateredCrest/scripts.pory"
	release
# 194 "data//maps/CrateredCrest/scripts.pory"
	end
# 195 "data//maps/CrateredCrest/scripts.pory"

# 196 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SurprisedPhil:
# 197 "data//maps/CrateredCrest/scripts.pory"
    emote_exclamation_mark
# 198 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 199 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_left
# 200 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 201 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_right
# 202 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 203 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_fast_up
# 204 "data//maps/CrateredCrest/scripts.pory"
    delay_16
# 205 "data//maps/CrateredCrest/scripts.pory"
    step_end
# 206 "data//maps/CrateredCrest/scripts.pory"

# 207 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DoMeteoriteSparkle::
# 208 "data//maps/CrateredCrest/scripts.pory"
	lock
# 209 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 210 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 211 "data//maps/CrateredCrest/scripts.pory"
	delay 45
# 212 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 213 "data//maps/CrateredCrest/scripts.pory"
	dofieldeffectsparkle 52, 11, 0
# 214 "data//maps/CrateredCrest/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 215 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 216 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_CRATERED_CREST_METEORITE
# 217 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 4
# 218 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_TEMP_2, 0
# 219 "data//maps/CrateredCrest/scripts.pory"
	release
# 220 "data//maps/CrateredCrest/scripts.pory"
	end
# 221 "data//maps/CrateredCrest/scripts.pory"

# 222 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Clone::
# 223 "data//maps/CrateredCrest/scripts.pory"
	lock
# 224 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_Clone, MSGBOX_DEFAULT 
# 225 "data//maps/CrateredCrest/scripts.pory"
	release
# 226 "data//maps/CrateredCrest/scripts.pory"
	end
# 227 "data//maps/CrateredCrest/scripts.pory"

# 228 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Croconaw::
# 229 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 230 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 231 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 232 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 233 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 234 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 235 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 236 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 237 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 238 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 239 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 240 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 241 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 242 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 243 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 244 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 245 "data//maps/CrateredCrest/scripts.pory"
	release
# 246 "data//maps/CrateredCrest/scripts.pory"
	end
# 247 "data//maps/CrateredCrest/scripts.pory"

# 248 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Aurorus::
# 249 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 250 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 251 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 252 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 253 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 254 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 255 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 256 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 257 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 258 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 259 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 260 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 261 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 262 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 263 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 264 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 265 "data//maps/CrateredCrest/scripts.pory"
	release
# 266 "data//maps/CrateredCrest/scripts.pory"
	end
# 267 "data//maps/CrateredCrest/scripts.pory"

# 268 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Dragonair::
# 269 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 270 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 271 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 272 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 273 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 274 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 275 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 276 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 277 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 278 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 279 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 280 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 281 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 282 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 283 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 284 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 285 "data//maps/CrateredCrest/scripts.pory"
	release
# 286 "data//maps/CrateredCrest/scripts.pory"
	end
# 287 "data//maps/CrateredCrest/scripts.pory"

# 288 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine1::
# 289 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 290 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 291 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 292 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 293 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 294 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 295 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 296 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 297 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 298 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 299 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 300 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 301 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 302 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 303 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 304 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 305 "data//maps/CrateredCrest/scripts.pory"
	release
# 306 "data//maps/CrateredCrest/scripts.pory"
	end
# 307 "data//maps/CrateredCrest/scripts.pory"

# 308 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Carnivine2::
# 309 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 310 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 311 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 312 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 313 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 314 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 315 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 316 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 317 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 318 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 319 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 320 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 321 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 322 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 323 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 324 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 325 "data//maps/CrateredCrest/scripts.pory"
	release
# 326 "data//maps/CrateredCrest/scripts.pory"
	end
# 327 "data//maps/CrateredCrest/scripts.pory"

# 328 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Gyarados::
# 329 "data//maps/CrateredCrest/scripts.pory"
	lockall
# 330 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 331 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 332 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 333 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 334 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 335 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 336 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 337 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 338 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 339 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 340 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 341 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 342 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 343 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 344 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 345 "data//maps/CrateredCrest/scripts.pory"
	release
# 346 "data//maps/CrateredCrest/scripts.pory"
	end
# 347 "data//maps/CrateredCrest/scripts.pory"

# 348 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusNothing::
# 349 "data//maps/CrateredCrest/scripts.pory"
	release
# 350 "data//maps/CrateredCrest/scripts.pory"
	end
# 351 "data//maps/CrateredCrest/scripts.pory"

# 352 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusA::
# 353 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 354 "data//maps/CrateredCrest/scripts.pory"
	lock
# 355 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 356 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 357 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 358 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 359 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 360 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 361 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 362 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 363 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusA
# 364 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 365 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 366 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 367 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 368 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 369 "data//maps/CrateredCrest/scripts.pory"
	end
# 370 "data//maps/CrateredCrest/scripts.pory"

# 371 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusB::
# 372 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 373 "data//maps/CrateredCrest/scripts.pory"
	lock
# 374 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 375 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 376 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 377 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 378 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 379 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 380 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 381 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 382 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusB
# 383 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 384 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 385 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 386 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 387 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 388 "data//maps/CrateredCrest/scripts.pory"
	end
# 389 "data//maps/CrateredCrest/scripts.pory"

# 390 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_HaxorusC::
# 391 "data//maps/CrateredCrest/scripts.pory"
	goto_if_set FLAG_DEFEATED_CRATERED_CREST_HAXORUS, CrateredCrest_EventScript_HaxorusNothing
# 392 "data//maps/CrateredCrest/scripts.pory"
	lock
# 393 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_FaceDown
# 394 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 395 "data//maps/CrateredCrest/scripts.pory"
	playse SE_PIN
# 396 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, Common_Movement_ExclamationMark
# 397 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 398 "data//maps/CrateredCrest/scripts.pory"
	delay 20
# 399 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_HAXORUS, CrateredCrest_Movement_HaxorusApproach
# 400 "data//maps/CrateredCrest/scripts.pory"
	@ delay 35
# 401 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Movement_ApproachHaxorusC
# 402 "data//maps/CrateredCrest/scripts.pory"
	waitmovement LOCALID_PLAYER
# 403 "data//maps/CrateredCrest/scripts.pory"
	delay 15
# 404 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 405 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 406 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_Haxorus
# 407 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_Haxorus::
# 412 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 413 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 414 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 415 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 416 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_CRATERED_CREST_HAXORUS
# 417 "data//maps/CrateredCrest/scripts.pory"
	setwildbossmon 1
# 418 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 419 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 420 "data//maps/CrateredCrest/scripts.pory"
	special StartRegiBattle
# 421 "data//maps/CrateredCrest/scripts.pory"
	waitstate
# 422 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 423 "data//maps/CrateredCrest/scripts.pory"
	endwildbossmon
# 424 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_DEFEATED_CRATERED_CREST_HAXORUS
# 425 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS
# 426 "data//maps/CrateredCrest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 427 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CrateredCrest_EventScript_Haxorus_2
# 432 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CrateredCrest_EventScript_Haxorus_3
CrateredCrest_EventScript_Haxorus_1:
# 439 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_HaxorusDefeated, MSGBOX_DEFAULT
# 440 "data//maps/CrateredCrest/scripts.pory"
	release
	return

CrateredCrest_EventScript_Haxorus_2:
# 428 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 429 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 430 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto CrateredCrest_EventScript_Haxorus_1

CrateredCrest_EventScript_Haxorus_3:
# 433 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 434 "data//maps/CrateredCrest/scripts.pory"
	removeobject VAR_LAST_TALKED
# 435 "data//maps/CrateredCrest/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 436 "data//maps/CrateredCrest/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 437 "data//maps/CrateredCrest/scripts.pory"
	msgbox gText_WildMonFled, MSGBOX_DEFAULT
	goto CrateredCrest_EventScript_Haxorus_1


# 443 "data//maps/CrateredCrest/scripts.pory"

# 444 "data//maps/CrateredCrest/scripts.pory"

# 445 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusDefeated:
# 446 "data//maps/CrateredCrest/scripts.pory"
    .string "The corpse of the wild HAXORUS\n"
# 447 "data//maps/CrateredCrest/scripts.pory"
    .string "collapsed into the marshy soil.$"
# 448 "data//maps/CrateredCrest/scripts.pory"

# 449 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_Tyrantrum::
# 450 "data//maps/CrateredCrest/scripts.pory"
	lock
# 451 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 452 "data//maps/CrateredCrest/scripts.pory"
	waitse
# 453 "data//maps/CrateredCrest/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 454 "data//maps/CrateredCrest/scripts.pory"
	delay 10
# 455 "data//maps/CrateredCrest/scripts.pory"
	waitmoncry
# 456 "data//maps/CrateredCrest/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 457 "data//maps/CrateredCrest/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 458 "data//maps/CrateredCrest/scripts.pory"
	dowildbattle
# 459 "data//maps/CrateredCrest/scripts.pory"
	@ waitstate
# 460 "data//maps/CrateredCrest/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 461 "data//maps/CrateredCrest/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 462 "data//maps/CrateredCrest/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 463 "data//maps/CrateredCrest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CrateredCrest_EventScript_DefeatedWildMon
# 464 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CrateredCrest_EventScript_RanWildMon
# 465 "data//maps/CrateredCrest/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CrateredCrest_EventScript_RanWildMon
# 466 "data//maps/CrateredCrest/scripts.pory"
	release
# 467 "data//maps/CrateredCrest/scripts.pory"
	end
# 468 "data//maps/CrateredCrest/scripts.pory"

# 469 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_DefeatedWildMon::
# 470 "data//maps/CrateredCrest/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 471 "data//maps/CrateredCrest/scripts.pory"
	release
# 472 "data//maps/CrateredCrest/scripts.pory"
	end
# 473 "data//maps/CrateredCrest/scripts.pory"

# 474 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_EventScript_RanWildMon::
# 475 "data//maps/CrateredCrest/scripts.pory"
	goto Common_EventScript_WildMonFled
# 476 "data//maps/CrateredCrest/scripts.pory"
	release
# 477 "data//maps/CrateredCrest/scripts.pory"
	end

CrateredCrest_EventScript_RuinManiacPhil::
# 482 "data//maps/CrateredCrest/scripts.pory"
	faceplayer
# 483 "data//maps/CrateredCrest/scripts.pory"
	checktrainerflag TRAINER_PHIL_CRATERED_CREST
	goto_if 0, CrateredCrest_EventScript_RuinManiacPhil_2
CrateredCrest_EventScript_RuinManiacPhil_1:
# 493 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_PhilPostBattle, MSGBOX_DEFAULT
# 494 "data//maps/CrateredCrest/scripts.pory"
	applymovement LOCALID_CRATERED_CREST_PHIL, Common_Movement_FaceOriginalDirection
# 495 "data//maps/CrateredCrest/scripts.pory"
	waitmovement
# 496 "data//maps/CrateredCrest/scripts.pory"
	release
	return

CrateredCrest_EventScript_RuinManiacPhil_2:
# 484 "data//maps/CrateredCrest/scripts.pory"
	playbgm MUS_ENCOUNTER_HIKER, FALSE
# 485 "data//maps/CrateredCrest/scripts.pory"
	message CrateredCrest_Text_PhilWait
# 486 "data//maps/CrateredCrest/scripts.pory"
	waitmessage
# 487 "data//maps/CrateredCrest/scripts.pory"
	delay 30
# 488 "data//maps/CrateredCrest/scripts.pory"
	closemessage
# 489 "data//maps/CrateredCrest/scripts.pory"
	delay 60
# 490 "data//maps/CrateredCrest/scripts.pory"
	msgbox CrateredCrest_Text_PhilIntro, MSGBOX_DEFAULT
# 491 "data//maps/CrateredCrest/scripts.pory"
	trainerbattle_no_intro TRAINER_PHIL_CRATERED_CREST, CrateredCrest_Text_PhilDefeat
	goto CrateredCrest_EventScript_RuinManiacPhil_1


# 499 "data//maps/CrateredCrest/scripts.pory"

# 500 "data//maps/CrateredCrest/scripts.pory"

# 501 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilWait:
# 502 "data//maps/CrateredCrest/scripts.pory"
    .string "… … … … … … … …\n"
# 503 "data//maps/CrateredCrest/scripts.pory"
	.string "… … … … … … … …$"
# 504 "data//maps/CrateredCrest/scripts.pory"

# 505 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilIntro:
# 506 "data//maps/CrateredCrest/scripts.pory"
    .string "I don't know how to swim…$"
# 507 "data//maps/CrateredCrest/scripts.pory"

# 508 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilDefeat:
# 509 "data//maps/CrateredCrest/scripts.pory"
    .string "Oh!\l"
# 510 "data//maps/CrateredCrest/scripts.pory"
    .string "You know how to swim?$"
# 511 "data//maps/CrateredCrest/scripts.pory"

# 512 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_PhilPostBattle:
# 513 "data//maps/CrateredCrest/scripts.pory"
    .string "I came to investigate the ruins\n"
# 514 "data//maps/CrateredCrest/scripts.pory"
    .string "at the center of this crater.\p"
# 515 "data//maps/CrateredCrest/scripts.pory"
    .string "But they're in the middle of\n"
# 516 "data//maps/CrateredCrest/scripts.pory"
    .string "the lake…$"
# 517 "data//maps/CrateredCrest/scripts.pory"

# 518 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyOff:
# 519 "data//maps/CrateredCrest/scripts.pory"
	delay_16
# 520 "data//maps/CrateredCrest/scripts.pory"
	fly_up
# 521 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 522 "data//maps/CrateredCrest/scripts.pory"

# 523 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpI:
# 524 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 525 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 526 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 527 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 528 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 529 "data//maps/CrateredCrest/scripts.pory"
	walk_up
# 530 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 531 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 532 "data//maps/CrateredCrest/scripts.pory"

# 533 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanUpII:
# 534 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 535 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 536 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 537 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 538 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 539 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 540 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 541 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 542 "data//maps/CrateredCrest/scripts.pory"

# 543 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownI:
# 544 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 545 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 546 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 547 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 548 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 549 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 550 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 551 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 552 "data//maps/CrateredCrest/scripts.pory"

# 553 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_CameraPanDownII:
# 554 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 555 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 556 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 557 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 558 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_down
# 559 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 560 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_down
# 561 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 562 "data//maps/CrateredCrest/scripts.pory"

# 563 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_RayquazaFlyDown:
# 564 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 565 "data//maps/CrateredCrest/scripts.pory"
	walk_slow_up
# 566 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 567 "data//maps/CrateredCrest/scripts.pory"
	walk_fast_up
# 568 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 569 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 570 "data//maps/CrateredCrest/scripts.pory"
	walk_faster_down
# 571 "data//maps/CrateredCrest/scripts.pory"
	walk_down
# 572 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 573 "data//maps/CrateredCrest/scripts.pory"

# 574 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_HaxorusApproach:
# 575 "data//maps/CrateredCrest/scripts.pory"
    walk_down
# 576 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 577 "data//maps/CrateredCrest/scripts.pory"

# 578 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusA:
# 579 "data//maps/CrateredCrest/scripts.pory"
    walk_right
# 580 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 581 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 582 "data//maps/CrateredCrest/scripts.pory"

# 583 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusB:
# 584 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 585 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 586 "data//maps/CrateredCrest/scripts.pory"

# 587 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_ApproachHaxorusC:
# 588 "data//maps/CrateredCrest/scripts.pory"
    walk_left
# 589 "data//maps/CrateredCrest/scripts.pory"
    walk_in_place_up
# 590 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 591 "data//maps/CrateredCrest/scripts.pory"

# 592 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetInvisible:
# 593 "data//maps/CrateredCrest/scripts.pory"
	set_invisible
# 594 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 595 "data//maps/CrateredCrest/scripts.pory"

# 596 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Movement_SetVisible:
# 597 "data//maps/CrateredCrest/scripts.pory"
	set_visible
# 598 "data//maps/CrateredCrest/scripts.pory"
	step_end
# 599 "data//maps/CrateredCrest/scripts.pory"

# 600 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaFlewOff:
# 601 "data//maps/CrateredCrest/scripts.pory"
	.string "But it flew off…\p"
# 602 "data//maps/CrateredCrest/scripts.pory"
	.string "It seemed like it was headed back\n"
# 603 "data//maps/CrateredCrest/scripts.pory"
	.string "towards SKY PILLAR!$"
# 604 "data//maps/CrateredCrest/scripts.pory"

# 605 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaAppeared:
# 606 "data//maps/CrateredCrest/scripts.pory"
	.string "RAYQUAZA appeared from beyond the\n" 
# 607 "data//maps/CrateredCrest/scripts.pory"
	.string "cliff's edge!$"
# 608 "data//maps/CrateredCrest/scripts.pory"

# 609 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_RayquazaIsHere:
# 610 "data//maps/CrateredCrest/scripts.pory"
	.string "It sounds like RAYQUAZA is nearby!$"
# 611 "data//maps/CrateredCrest/scripts.pory"

# 612 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_HaxorusAttacked:
# 613 "data//maps/CrateredCrest/scripts.pory"
	.string "HAXORUS approached aggresively!$"
# 614 "data//maps/CrateredCrest/scripts.pory"

# 615 "data//maps/CrateredCrest/scripts.pory"
CrateredCrest_Text_Clone:
# 616 "data//maps/CrateredCrest/scripts.pory"
	.string "Where am I?$"

CrateredCrest_EventScript_RandomiseOvrWrldMonPos::
# 621 "data//maps/CrateredCrest/scripts.pory"
	compare VAR_CRATERED_CREST_RAYQUAZA_SCENE_STATE, 3
	goto_if_ge CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1
# 633 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_1:
# 622 "data//maps/CrateredCrest/scripts.pory"
	random 3
# 623 "data//maps/CrateredCrest/scripts.pory"
	switch VAR_RESULT
# 624 "data//maps/CrateredCrest/scripts.pory"
	case 0, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5
# 626 "data//maps/CrateredCrest/scripts.pory"
	case 1, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6
# 628 "data//maps/CrateredCrest/scripts.pory"
	case 2, CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_5:
# 625 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosA
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_6:
# 627 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosB
	return

CrateredCrest_EventScript_RandomiseOvrWrldMonPos_7:
# 629 "data//maps/CrateredCrest/scripts.pory"
	goto CrateredCrest_EventScript_OvrWrldMonPosC
	return


CrateredCrest_EventScript_OvrWrldMonPosA::
	return


CrateredCrest_EventScript_OvrWrldMonPosB::
	return


CrateredCrest_EventScript_OvrWrldMonPosC::
	return

