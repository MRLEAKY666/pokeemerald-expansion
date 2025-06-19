# 1 "data//maps/InfinityCoast/scripts.pory"

# 2 "data//maps/InfinityCoast/scripts.pory"

# 3 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_MapScripts::
# 4 "data//maps/InfinityCoast/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InfinityCoast_OnResume
# 5 "data//maps/InfinityCoast/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InfinityCoast_OnTransition
# 6 "data//maps/InfinityCoast/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InfinityCoast_OnFrame
# 7 "data//maps/InfinityCoast/scripts.pory"
	.byte 0
# 8 "data//maps/InfinityCoast/scripts.pory"

# 9 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_OnFrame:
# 10 "data//maps/InfinityCoast/scripts.pory"
	map_script_2 VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 0, InfinityCoast_EventScript_DoRayquazaCry
# 11 "data//maps/InfinityCoast/scripts.pory"
	map_script_2 VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 2, InfinityCoast_EventScript_ContinueRayquazaScene
# 12 "data//maps/InfinityCoast/scripts.pory"
	map_script_2 VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 3, InfinityCoast_EventScript_DoMeteoriteSparkle
# 13 "data//maps/InfinityCoast/scripts.pory"
	.2byte 0
# 14 "data//maps/InfinityCoast/scripts.pory"

# 15 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_OnResume:
# 16 "data//maps/InfinityCoast/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 17 "data//maps/InfinityCoast/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, InfinityCoast_EventScript_TryRemoveZapdos
# 18 "data//maps/InfinityCoast/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, InfinityCoast_EventScript_TryRemoveWildMon
# 19 "data//maps/InfinityCoast/scripts.pory"
	end
# 20 "data//maps/InfinityCoast/scripts.pory"
	end
# 21 "data//maps/InfinityCoast/scripts.pory"

# 22 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_TryRemoveWildMon::
# 23 "data//maps/InfinityCoast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 24 "data//maps/InfinityCoast/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 25 "data//maps/InfinityCoast/scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data//maps/InfinityCoast/scripts.pory"
	return
# 27 "data//maps/InfinityCoast/scripts.pory"

# 28 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_OnTransition:
# 29 "data//maps/InfinityCoast/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, InfinityCoast_EventScript_HideZapdos
# 30 "data//maps/InfinityCoast/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, InfinityCoast_EventScript_TryShowZapdos
# 31 "data//maps/InfinityCoast/scripts.pory"
	end
# 32 "data//maps/InfinityCoast/scripts.pory"

# 33 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HideZapdos::
# 34 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 35 "data//maps/InfinityCoast/scripts.pory"
	return
# 36 "data//maps/InfinityCoast/scripts.pory"

# 37 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_TryShowZapdos::
# 38 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 39 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 40 "data//maps/InfinityCoast/scripts.pory"
	return
# 41 "data//maps/InfinityCoast/scripts.pory"

# 42 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Rayquaza::
# 43 "data//maps/InfinityCoast/scripts.pory"
	@ lock
# 44 "data//maps/InfinityCoast/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 45 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 46 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 47 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 48 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 49 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 50 "data//maps/InfinityCoast/scripts.pory"
	special ShakeCamera
# 51 "data//maps/InfinityCoast/scripts.pory"
	fadeoutbgm 1
# 52 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_RAYQUAZA, InfinityCoast_Movement_RayquazaFlyDown
# 53 "data//maps/InfinityCoast/scripts.pory"
	special SpawnCameraObject
# 54 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_CAMERA, InfinityCoast_Movement_CameraPanUpI
# 55 "data//maps/InfinityCoast/scripts.pory"
	waitmovement LOCALID_CAMERA
# 56 "data//maps/InfinityCoast/scripts.pory"
	special RemoveCameraObject
# 57 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 58 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 59 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 60 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 61 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 62 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 63 "data//maps/InfinityCoast/scripts.pory"
	special ShakeCamera
# 64 "data//maps/InfinityCoast/scripts.pory"
	waitstate
# 65 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 66 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 67 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 68 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 69 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 70 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 71 "data//maps/InfinityCoast/scripts.pory"
	special ShakeCamera
# 72 "data//maps/InfinityCoast/scripts.pory"
	waitstate
# 73 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 74 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 2
# 75 "data//maps/InfinityCoast/scripts.pory"
	release 
# 76 "data//maps/InfinityCoast/scripts.pory"
	end 
# 77 "data//maps/InfinityCoast/scripts.pory"

# 78 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_ContinueRayquazaScene::
# 79 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 80 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 81 "data//maps/InfinityCoast/scripts.pory"
	delay 60
# 82 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_RAYQUAZA, InfinityCoast_Movement_RayquazaFlyOff
# 83 "data//maps/InfinityCoast/scripts.pory"
	waitmovement LOCALID_INFINITY_COAST_RAYQUAZA
# 84 "data//maps/InfinityCoast/scripts.pory"
	removeobject LOCALID_INFINITY_COAST_RAYQUAZA
# 85 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 86 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 87 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 88 "data//maps/InfinityCoast/scripts.pory"
	fadeinbgm 2
# 89 "data//maps/InfinityCoast/scripts.pory"
	special SpawnCameraObject
# 90 "data//maps/InfinityCoast/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 91 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_CAMERA, InfinityCoast_Movement_CameraPanDownII
# 92 "data//maps/InfinityCoast/scripts.pory"
	waitmovement LOCALID_CAMERA
# 93 "data//maps/InfinityCoast/scripts.pory"
	special RemoveCameraObject
# 94 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 3
# 95 "data//maps/InfinityCoast/scripts.pory"
	releaseall
# 96 "data//maps/InfinityCoast/scripts.pory"
	end
# 97 "data//maps/InfinityCoast/scripts.pory"

# 98 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_DoRayquazaCry::
# 99 "data//maps/InfinityCoast/scripts.pory"
	lock
# 100 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 101 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 102 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 103 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 104 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 105 "data//maps/InfinityCoast/scripts.pory"
	special ShakeCamera
# 106 "data//maps/InfinityCoast/scripts.pory"
	@ waitmovement 0
# 107 "data//maps/InfinityCoast/scripts.pory"
	waitstate
# 108 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 109 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 110 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 111 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 112 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 113 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 114 "data//maps/InfinityCoast/scripts.pory"
	special ShakeCamera
# 115 "data//maps/InfinityCoast/scripts.pory"
	@ waitmovement 0
# 116 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 117 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 118 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 1
# 119 "data//maps/InfinityCoast/scripts.pory"
	release
# 120 "data//maps/InfinityCoast/scripts.pory"
	end
# 121 "data//maps/InfinityCoast/scripts.pory"

# 122 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_DoMeteoriteSparkle::
# 123 "data//maps/InfinityCoast/scripts.pory"
	lock
# 124 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 125 "data//maps/InfinityCoast/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 126 "data//maps/InfinityCoast/scripts.pory"
	delay 45
# 127 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 128 "data//maps/InfinityCoast/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 129 "data//maps/InfinityCoast/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 130 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 131 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_INFINITY_COAST_METEORITE
# 132 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_INFINITY_COAST_RAYQUAZA_SCENE_STATE, 4
# 133 "data//maps/InfinityCoast/scripts.pory"
	release
# 134 "data//maps/InfinityCoast/scripts.pory"
	end
# 135 "data//maps/InfinityCoast/scripts.pory"

# 136 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_TryRemoveZapdos::
# 137 "data//maps/InfinityCoast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 138 "data//maps/InfinityCoast/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 139 "data//maps/InfinityCoast/scripts.pory"
	removeobject VAR_LAST_TALKED
# 140 "data//maps/InfinityCoast/scripts.pory"
	return
# 141 "data//maps/InfinityCoast/scripts.pory"

# 142 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Zapdos::
# 143 "data//maps/InfinityCoast/scripts.pory"
	lock
# 144 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 145 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 146 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 147 "data//maps/InfinityCoast/scripts.pory"
	delay 40
# 148 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 149 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 150 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 151 "data//maps/InfinityCoast/scripts.pory"
	special StartRegiBattle
# 152 "data//maps/InfinityCoast/scripts.pory"
	waitstate
# 153 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 154 "data//maps/InfinityCoast/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 155 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedZapdos
# 156 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanFromZapdos
# 157 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanFromZapdos
# 158 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 159 "data//maps/InfinityCoast/scripts.pory"
	release
# 160 "data//maps/InfinityCoast/scripts.pory"
	end
# 161 "data//maps/InfinityCoast/scripts.pory"

# 162 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_DefeatedZapdos::
# 163 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 164 "data//maps/InfinityCoast/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 165 "data//maps/InfinityCoast/scripts.pory"
	release
# 166 "data//maps/InfinityCoast/scripts.pory"
	end
# 167 "data//maps/InfinityCoast/scripts.pory"

# 168 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_RanFromZapdos::
# 169 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 170 "data//maps/InfinityCoast/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 171 "data//maps/InfinityCoast/scripts.pory"
	release
# 172 "data//maps/InfinityCoast/scripts.pory"
	end
# 173 "data//maps/InfinityCoast/scripts.pory"

# 174 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Croconaw::
# 175 "data//maps/InfinityCoast/scripts.pory"
	lock
# 176 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 177 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 178 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 179 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 180 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 181 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 182 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 183 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 184 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 185 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 186 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 187 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 188 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 189 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 190 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 191 "data//maps/InfinityCoast/scripts.pory"
	release
# 192 "data//maps/InfinityCoast/scripts.pory"
	end
# 193 "data//maps/InfinityCoast/scripts.pory"

# 194 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Aurorus::
# 195 "data//maps/InfinityCoast/scripts.pory"
	lock
# 196 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 197 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 198 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 199 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 200 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 201 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 202 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 203 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 204 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 205 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 206 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 207 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 208 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 209 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 210 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 211 "data//maps/InfinityCoast/scripts.pory"
	release
# 212 "data//maps/InfinityCoast/scripts.pory"
	end
# 213 "data//maps/InfinityCoast/scripts.pory"

# 214 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Dragonair::
# 215 "data//maps/InfinityCoast/scripts.pory"
	lock
# 216 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 217 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 218 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 219 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 220 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 221 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 222 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 223 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 224 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 225 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 226 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 227 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 228 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 229 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 230 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 231 "data//maps/InfinityCoast/scripts.pory"
	release
# 232 "data//maps/InfinityCoast/scripts.pory"
	end
# 233 "data//maps/InfinityCoast/scripts.pory"

# 234 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Carnivine1::
# 235 "data//maps/InfinityCoast/scripts.pory"
	lock
# 236 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 237 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 238 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 239 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 240 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 241 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 242 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 243 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 244 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 245 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 246 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 247 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 248 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 249 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 250 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 251 "data//maps/InfinityCoast/scripts.pory"
	release
# 252 "data//maps/InfinityCoast/scripts.pory"
	end
# 253 "data//maps/InfinityCoast/scripts.pory"

# 254 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Gyarados::
# 255 "data//maps/InfinityCoast/scripts.pory"
	lock
# 256 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 257 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 258 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 259 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 260 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 261 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 262 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 263 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 264 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 265 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 266 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 267 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 268 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 269 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 270 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 271 "data//maps/InfinityCoast/scripts.pory"
	release
# 272 "data//maps/InfinityCoast/scripts.pory"
	end
# 273 "data//maps/InfinityCoast/scripts.pory"

# 274 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusNothing::
# 275 "data//maps/InfinityCoast/scripts.pory"
	release
# 276 "data//maps/InfinityCoast/scripts.pory"
	end
# 277 "data//maps/InfinityCoast/scripts.pory"

# 278 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusA::
# 279 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_INFINITY_COAST_HAXORUS, InfinityCoast_EventScript_HaxorusNothing
# 280 "data//maps/InfinityCoast/scripts.pory"
	lock
# 281 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_FaceLeft
# 282 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 283 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 284 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_ExclamationMark
# 285 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 286 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 287 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 288 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, InfinityCoast_Movement_HaxorusApproachA
# 289 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 290 "data//maps/InfinityCoast/scripts.pory"
	delay 15
# 291 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 292 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 293 "data//maps/InfinityCoast/scripts.pory"
	goto InfinityCoast_EventScript_Haxorus
# 294 "data//maps/InfinityCoast/scripts.pory"
	end
# 295 "data//maps/InfinityCoast/scripts.pory"

# 296 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusB::
# 297 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_INFINITY_COAST_HAXORUS, InfinityCoast_EventScript_HaxorusNothing
# 298 "data//maps/InfinityCoast/scripts.pory"
	lock
# 299 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_FaceDown
# 300 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 301 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 302 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_ExclamationMark
# 303 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 304 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 305 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 306 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, InfinityCoast_Movement_HaxorusApproachB
# 307 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 308 "data//maps/InfinityCoast/scripts.pory"
	delay 15
# 309 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 310 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 311 "data//maps/InfinityCoast/scripts.pory"
	goto InfinityCoast_EventScript_Haxorus
# 312 "data//maps/InfinityCoast/scripts.pory"
	end
# 313 "data//maps/InfinityCoast/scripts.pory"

# 314 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusC::
# 315 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_INFINITY_COAST_HAXORUS, InfinityCoast_EventScript_HaxorusNothing
# 316 "data//maps/InfinityCoast/scripts.pory"
	lock
# 317 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_FaceDown
# 318 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 319 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 320 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_ExclamationMark
# 321 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 322 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 323 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 324 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, InfinityCoast_Movement_HaxorusApproachC
# 325 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 326 "data//maps/InfinityCoast/scripts.pory"
	delay 15
# 327 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 328 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 329 "data//maps/InfinityCoast/scripts.pory"
	goto InfinityCoast_EventScript_Haxorus
# 330 "data//maps/InfinityCoast/scripts.pory"
	end
# 331 "data//maps/InfinityCoast/scripts.pory"

# 332 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusD::
# 333 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_INFINITY_COAST_HAXORUS, InfinityCoast_EventScript_HaxorusNothing
# 334 "data//maps/InfinityCoast/scripts.pory"
	lock
# 335 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_FaceDown
# 336 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 337 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 338 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_ExclamationMark
# 339 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 340 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 341 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 342 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, InfinityCoast_Movement_HaxorusApproachD
# 343 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 344 "data//maps/InfinityCoast/scripts.pory"
	delay 15
# 345 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 346 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 347 "data//maps/InfinityCoast/scripts.pory"
	goto InfinityCoast_EventScript_Haxorus
# 348 "data//maps/InfinityCoast/scripts.pory"
	end
# 349 "data//maps/InfinityCoast/scripts.pory"

# 350 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_HaxorusE::
# 351 "data//maps/InfinityCoast/scripts.pory"
	goto_if_set FLAG_DEFEATED_INFINITY_COAST_HAXORUS, InfinityCoast_EventScript_HaxorusNothing
# 352 "data//maps/InfinityCoast/scripts.pory"
	lock
# 353 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_FaceDown
# 354 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 355 "data//maps/InfinityCoast/scripts.pory"
	playse SE_PIN
# 356 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, Common_Movement_ExclamationMark
# 357 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 358 "data//maps/InfinityCoast/scripts.pory"
	delay 20
# 359 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 360 "data//maps/InfinityCoast/scripts.pory"
	applymovement LOCALID_INFINITY_COAST_HAXORUS, InfinityCoast_Movement_HaxorusApproachE
# 361 "data//maps/InfinityCoast/scripts.pory"
	waitmovement
# 362 "data//maps/InfinityCoast/scripts.pory"
	delay 15
# 363 "data//maps/InfinityCoast/scripts.pory"
	msgbox InfinityCoast_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 364 "data//maps/InfinityCoast/scripts.pory"
	closemessage
# 365 "data//maps/InfinityCoast/scripts.pory"
	goto InfinityCoast_EventScript_Haxorus
# 366 "data//maps/InfinityCoast/scripts.pory"
	end
# 367 "data//maps/InfinityCoast/scripts.pory"

# 368 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Haxorus::
# 369 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 370 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 371 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 372 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 373 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_INFINITY_COAST_HAXORUS
# 374 "data//maps/InfinityCoast/scripts.pory"
	setwildbossmon 1
# 375 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 376 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 377 "data//maps/InfinityCoast/scripts.pory"
	special StartRegiBattle
# 378 "data//maps/InfinityCoast/scripts.pory"
	waitstate
# 379 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 380 "data//maps/InfinityCoast/scripts.pory"
	endwildbossmon
# 381 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 382 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 383 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 384 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 385 "data//maps/InfinityCoast/scripts.pory"
	release
# 386 "data//maps/InfinityCoast/scripts.pory"
	end
# 387 "data//maps/InfinityCoast/scripts.pory"

# 388 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_Tyrantrum::
# 389 "data//maps/InfinityCoast/scripts.pory"
	lock
# 390 "data//maps/InfinityCoast/scripts.pory"
	faceplayer
# 391 "data//maps/InfinityCoast/scripts.pory"
	waitse
# 392 "data//maps/InfinityCoast/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 393 "data//maps/InfinityCoast/scripts.pory"
	delay 10
# 394 "data//maps/InfinityCoast/scripts.pory"
	waitmoncry
# 395 "data//maps/InfinityCoast/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 396 "data//maps/InfinityCoast/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 397 "data//maps/InfinityCoast/scripts.pory"
	dowildbattle
# 398 "data//maps/InfinityCoast/scripts.pory"
	@ waitstate
# 399 "data//maps/InfinityCoast/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 400 "data//maps/InfinityCoast/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 401 "data//maps/InfinityCoast/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 402 "data//maps/InfinityCoast/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, InfinityCoast_EventScript_DefeatedWildMon
# 403 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, InfinityCoast_EventScript_RanWildMon
# 404 "data//maps/InfinityCoast/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, InfinityCoast_EventScript_RanWildMon
# 405 "data//maps/InfinityCoast/scripts.pory"
	release
# 406 "data//maps/InfinityCoast/scripts.pory"
	end
# 407 "data//maps/InfinityCoast/scripts.pory"

# 408 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_DefeatedWildMon::
# 409 "data//maps/InfinityCoast/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 410 "data//maps/InfinityCoast/scripts.pory"
	release
# 411 "data//maps/InfinityCoast/scripts.pory"
	end
# 412 "data//maps/InfinityCoast/scripts.pory"

# 413 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_EventScript_RanWildMon::
# 414 "data//maps/InfinityCoast/scripts.pory"
	goto Common_EventScript_WildMonFled
# 415 "data//maps/InfinityCoast/scripts.pory"
	release
# 416 "data//maps/InfinityCoast/scripts.pory"
	end
# 417 "data//maps/InfinityCoast/scripts.pory"

# 418 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_RayquazaFlyOff:
# 419 "data//maps/InfinityCoast/scripts.pory"
	delay_16
# 420 "data//maps/InfinityCoast/scripts.pory"
	fly_up
# 421 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 422 "data//maps/InfinityCoast/scripts.pory"

# 423 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_CameraPanUpI:
# 424 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 425 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 426 "data//maps/InfinityCoast/scripts.pory"
	walk_up
# 427 "data//maps/InfinityCoast/scripts.pory"
	walk_up
# 428 "data//maps/InfinityCoast/scripts.pory"
	walk_up
# 429 "data//maps/InfinityCoast/scripts.pory"
	walk_faster_up
# 430 "data//maps/InfinityCoast/scripts.pory"
	walk_faster_up
# 431 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 432 "data//maps/InfinityCoast/scripts.pory"

# 433 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_CameraPanUpII:
# 434 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 435 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 436 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 437 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 438 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 439 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 440 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 441 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 442 "data//maps/InfinityCoast/scripts.pory"

# 443 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_CameraPanDownI:
# 444 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 445 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 446 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 447 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 448 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 449 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 450 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 451 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 452 "data//maps/InfinityCoast/scripts.pory"

# 453 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_CameraPanDownII:
# 454 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 455 "data//maps/InfinityCoast/scripts.pory"
	walk_faster_down
# 456 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 457 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 458 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 459 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 460 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_down
# 461 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 462 "data//maps/InfinityCoast/scripts.pory"

# 463 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_RayquazaFlyDown:
# 464 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 465 "data//maps/InfinityCoast/scripts.pory"
	walk_slow_up
# 466 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_up
# 467 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_up
# 468 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 469 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 470 "data//maps/InfinityCoast/scripts.pory"
	walk_faster_down
# 471 "data//maps/InfinityCoast/scripts.pory"
	walk_down
# 472 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 473 "data//maps/InfinityCoast/scripts.pory"

# 474 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_HaxorusApproachA:
# 475 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 476 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 477 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 478 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 479 "data//maps/InfinityCoast/scripts.pory"
	walk_in_place_down
# 480 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 481 "data//maps/InfinityCoast/scripts.pory"

# 482 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_HaxorusApproachB:
# 483 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 484 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 485 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 486 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 487 "data//maps/InfinityCoast/scripts.pory"
	walk_in_place_down
# 488 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 489 "data//maps/InfinityCoast/scripts.pory"

# 490 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_HaxorusApproachC:
# 491 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_left
# 492 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 493 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 494 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 495 "data//maps/InfinityCoast/scripts.pory"

# 496 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_HaxorusApproachD:
# 497 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 498 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 499 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 500 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 501 "data//maps/InfinityCoast/scripts.pory"

# 502 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_HaxorusApproachE:
# 503 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 504 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 505 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_right
# 506 "data//maps/InfinityCoast/scripts.pory"
	walk_fast_down
# 507 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 508 "data//maps/InfinityCoast/scripts.pory"

# 509 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_SetInvisible:
# 510 "data//maps/InfinityCoast/scripts.pory"
	set_invisible
# 511 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 512 "data//maps/InfinityCoast/scripts.pory"

# 513 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Movement_SetVisible:
# 514 "data//maps/InfinityCoast/scripts.pory"
	set_visible
# 515 "data//maps/InfinityCoast/scripts.pory"
	step_end
# 516 "data//maps/InfinityCoast/scripts.pory"

# 517 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Text_RayquazaFlewOff:
# 518 "data//maps/InfinityCoast/scripts.pory"
	.string "But it flew off…\p"
# 519 "data//maps/InfinityCoast/scripts.pory"
	.string "It seemed like it was headed back\n"
# 520 "data//maps/InfinityCoast/scripts.pory"
	.string "towards SKY PILLAR!$"
# 521 "data//maps/InfinityCoast/scripts.pory"

# 522 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Text_RayquazaAppeared:
# 523 "data//maps/InfinityCoast/scripts.pory"
	.string "RAYQUAZA appeared!$"
# 524 "data//maps/InfinityCoast/scripts.pory"

# 525 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Text_RayquazaIsHere:
# 526 "data//maps/InfinityCoast/scripts.pory"
	.string "RAYQUAZA roared nearby!$"
# 527 "data//maps/InfinityCoast/scripts.pory"

# 528 "data//maps/InfinityCoast/scripts.pory"
InfinityCoast_Text_HaxorusAttacked:
# 529 "data//maps/InfinityCoast/scripts.pory"
	.string "HAXORUS approached aggresively!$"
