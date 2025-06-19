# 1 "data//maps/DragonsRoost/scripts.pory"

# 2 "data//maps/DragonsRoost/scripts.pory"

# 3 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_MapScripts::
# 4 "data//maps/DragonsRoost/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DragonsRoost_OnResume
# 5 "data//maps/DragonsRoost/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DragonsRoost_OnTransition
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
	end
# 32 "data//maps/DragonsRoost/scripts.pory"

# 33 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HideZapdos::
# 34 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 35 "data//maps/DragonsRoost/scripts.pory"
	return
# 36 "data//maps/DragonsRoost/scripts.pory"

# 37 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryShowZapdos::
# 38 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 39 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 40 "data//maps/DragonsRoost/scripts.pory"
	return
# 41 "data//maps/DragonsRoost/scripts.pory"

# 42 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Rayquaza::
# 43 "data//maps/DragonsRoost/scripts.pory"
	@ lock
# 44 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 45 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 46 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 47 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 48 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 49 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 50 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 51 "data//maps/DragonsRoost/scripts.pory"
	fadeoutbgm 1
# 52 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyDown
# 53 "data//maps/DragonsRoost/scripts.pory"
	special SpawnCameraObject
# 54 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_CAMERA, DragonsRoost_Movement_CameraPanUpI
# 55 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_CAMERA
# 56 "data//maps/DragonsRoost/scripts.pory"
	special RemoveCameraObject
# 57 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 58 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 59 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 60 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 61 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 62 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 63 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 64 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 65 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 66 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 67 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 68 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 69 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 70 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 71 "data//maps/DragonsRoost/scripts.pory"
	special ShakeCamera
# 72 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 73 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 74 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 2
# 75 "data//maps/DragonsRoost/scripts.pory"
	release 
# 76 "data//maps/DragonsRoost/scripts.pory"
	end 
# 77 "data//maps/DragonsRoost/scripts.pory"

# 78 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_ContinueRayquazaScene::
# 79 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaAppeared, MSGBOX_DEFAULT
# 80 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 81 "data//maps/DragonsRoost/scripts.pory"
	delay 60
# 82 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_RAYQUAZA, DragonsRoost_Movement_RayquazaFlyOff
# 83 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_RAYQUAZA
# 84 "data//maps/DragonsRoost/scripts.pory"
	removeobject LOCALID_DRAGONS_ROOST_RAYQUAZA
# 85 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 86 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 87 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 88 "data//maps/DragonsRoost/scripts.pory"
	fadeinbgm 2
# 89 "data//maps/DragonsRoost/scripts.pory"
	special SpawnCameraObject
# 90 "data//maps/DragonsRoost/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 91 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_CAMERA, DragonsRoost_Movement_CameraPanDownII
# 92 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_CAMERA
# 93 "data//maps/DragonsRoost/scripts.pory"
	special RemoveCameraObject
# 94 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 3
# 95 "data//maps/DragonsRoost/scripts.pory"
	releaseall
# 96 "data//maps/DragonsRoost/scripts.pory"
	end
# 97 "data//maps/DragonsRoost/scripts.pory"

# 98 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoRayquazaCry::
# 99 "data//maps/DragonsRoost/scripts.pory"
	lock
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
	@ waitmovement 0
# 107 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 108 "data//maps/DragonsRoost/scripts.pory"
	waitse
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
	@ waitmovement 0
# 116 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_RayquazaIsHere, MSGBOX_DEFAULT
# 117 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 118 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 1
# 119 "data//maps/DragonsRoost/scripts.pory"
	release
# 120 "data//maps/DragonsRoost/scripts.pory"
	end
# 121 "data//maps/DragonsRoost/scripts.pory"

# 122 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DoMeteoriteSparkle::
# 123 "data//maps/DragonsRoost/scripts.pory"
	lock
# 124 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 125 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 126 "data//maps/DragonsRoost/scripts.pory"
	delay 45
# 127 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 128 "data//maps/DragonsRoost/scripts.pory"
	dofieldeffectsparkle 49, 10, 0
# 129 "data//maps/DragonsRoost/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 130 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 131 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_DRAGONS_ROOST_METEORITE
# 132 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_DRAGONS_ROOST_RAYQUAZA_SCENE_STATE, 4
# 133 "data//maps/DragonsRoost/scripts.pory"
	release
# 134 "data//maps/DragonsRoost/scripts.pory"
	end
# 135 "data//maps/DragonsRoost/scripts.pory"

# 136 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_TryRemoveZapdos::
# 137 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 138 "data//maps/DragonsRoost/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 139 "data//maps/DragonsRoost/scripts.pory"
	removeobject VAR_LAST_TALKED
# 140 "data//maps/DragonsRoost/scripts.pory"
	return
# 141 "data//maps/DragonsRoost/scripts.pory"

# 142 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Zapdos::
# 143 "data//maps/DragonsRoost/scripts.pory"
	lock
# 144 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 145 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 146 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 147 "data//maps/DragonsRoost/scripts.pory"
	delay 40
# 148 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 149 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 150 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 151 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 152 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 153 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 154 "data//maps/DragonsRoost/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 155 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedZapdos
# 156 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanFromZapdos
# 157 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanFromZapdos
# 158 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 159 "data//maps/DragonsRoost/scripts.pory"
	release
# 160 "data//maps/DragonsRoost/scripts.pory"
	end
# 161 "data//maps/DragonsRoost/scripts.pory"

# 162 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedZapdos::
# 163 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 164 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 165 "data//maps/DragonsRoost/scripts.pory"
	release
# 166 "data//maps/DragonsRoost/scripts.pory"
	end
# 167 "data//maps/DragonsRoost/scripts.pory"

# 168 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanFromZapdos::
# 169 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 170 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 171 "data//maps/DragonsRoost/scripts.pory"
	release
# 172 "data//maps/DragonsRoost/scripts.pory"
	end
# 173 "data//maps/DragonsRoost/scripts.pory"

# 174 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Croconaw::
# 175 "data//maps/DragonsRoost/scripts.pory"
	lock
# 176 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 177 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 178 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CROCONAW, CRY_MODE_ENCOUNTER
# 179 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 180 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 181 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CROCONAW, 50
# 182 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 183 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 184 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 185 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 186 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CROCONAW
# 187 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 188 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 189 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 190 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 191 "data//maps/DragonsRoost/scripts.pory"
	release
# 192 "data//maps/DragonsRoost/scripts.pory"
	end
# 193 "data//maps/DragonsRoost/scripts.pory"

# 194 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Aurorus::
# 195 "data//maps/DragonsRoost/scripts.pory"
	lock
# 196 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 197 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 198 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_AURORUS, CRY_MODE_ENCOUNTER
# 199 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 200 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 201 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_AURORUS, 50
# 202 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 203 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 204 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 205 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 206 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_AURORUS
# 207 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 208 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 209 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 210 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 211 "data//maps/DragonsRoost/scripts.pory"
	release
# 212 "data//maps/DragonsRoost/scripts.pory"
	end
# 213 "data//maps/DragonsRoost/scripts.pory"

# 214 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Dragonair::
# 215 "data//maps/DragonsRoost/scripts.pory"
	lock
# 216 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 217 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 218 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_DRAGONAIR, CRY_MODE_ENCOUNTER
# 219 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 220 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 221 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 50
# 222 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 223 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 224 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 225 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 226 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONAIR
# 227 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 228 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 229 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 230 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 231 "data//maps/DragonsRoost/scripts.pory"
	release
# 232 "data//maps/DragonsRoost/scripts.pory"
	end
# 233 "data//maps/DragonsRoost/scripts.pory"

# 234 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Carnivine1::
# 235 "data//maps/DragonsRoost/scripts.pory"
	lock
# 236 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 237 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 238 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_CARNIVINE, CRY_MODE_ENCOUNTER
# 239 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 240 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 241 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_CARNIVINE, 50
# 242 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 243 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 244 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 245 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 246 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_CARNIVINE
# 247 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 248 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 249 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 250 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 251 "data//maps/DragonsRoost/scripts.pory"
	release
# 252 "data//maps/DragonsRoost/scripts.pory"
	end
# 253 "data//maps/DragonsRoost/scripts.pory"

# 254 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Gyarados::
# 255 "data//maps/DragonsRoost/scripts.pory"
	lock
# 256 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 257 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 258 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
# 259 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 260 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 261 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_GYARADOS, 50
# 262 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 263 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 264 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 265 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 266 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 267 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 268 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 269 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 270 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 271 "data//maps/DragonsRoost/scripts.pory"
	release
# 272 "data//maps/DragonsRoost/scripts.pory"
	end
# 273 "data//maps/DragonsRoost/scripts.pory"

# 274 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusNothing::
# 275 "data//maps/DragonsRoost/scripts.pory"
	release
# 276 "data//maps/DragonsRoost/scripts.pory"
	end
# 277 "data//maps/DragonsRoost/scripts.pory"

# 278 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusA::
# 279 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 280 "data//maps/DragonsRoost/scripts.pory"
	lock
# 281 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceLeft
# 282 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 283 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 284 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 285 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 286 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 287 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachA
# 288 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 289 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 290 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 291 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 292 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 293 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 294 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 295 "data//maps/DragonsRoost/scripts.pory"
	end
# 296 "data//maps/DragonsRoost/scripts.pory"

# 297 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusB::
# 298 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 299 "data//maps/DragonsRoost/scripts.pory"
	lock
# 300 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 301 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 302 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 303 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 304 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 305 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 306 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachB
# 307 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 308 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 309 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 310 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 311 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 312 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 313 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 314 "data//maps/DragonsRoost/scripts.pory"
	end
# 315 "data//maps/DragonsRoost/scripts.pory"

# 316 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusC::
# 317 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 318 "data//maps/DragonsRoost/scripts.pory"
	lock
# 319 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 320 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 321 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 322 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 323 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 324 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 325 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachC
# 326 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 327 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 328 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 329 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 330 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 331 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 332 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 333 "data//maps/DragonsRoost/scripts.pory"
	end
# 334 "data//maps/DragonsRoost/scripts.pory"

# 335 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusD::
# 336 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 337 "data//maps/DragonsRoost/scripts.pory"
	lock
# 338 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 339 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 340 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 341 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 342 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 343 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 344 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachD
# 345 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 346 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 347 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 348 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 349 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 350 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 351 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 352 "data//maps/DragonsRoost/scripts.pory"
	end
# 353 "data//maps/DragonsRoost/scripts.pory"

# 354 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_HaxorusE::
# 355 "data//maps/DragonsRoost/scripts.pory"
	goto_if_set FLAG_DEFEATED_DRAGONS_ROOST_HAXORUS, DragonsRoost_EventScript_HaxorusNothing
# 356 "data//maps/DragonsRoost/scripts.pory"
	lock
# 357 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_FaceDown
# 358 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 359 "data//maps/DragonsRoost/scripts.pory"
	playse SE_PIN
# 360 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, Common_Movement_ExclamationMark
# 361 "data//maps/DragonsRoost/scripts.pory"
	waitmovement
# 362 "data//maps/DragonsRoost/scripts.pory"
	delay 20
# 363 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_DRAGONS_ROOST_HAXORUS, DragonsRoost_Movement_HaxorusApproachE
# 364 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 365 "data//maps/DragonsRoost/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 366 "data//maps/DragonsRoost/scripts.pory"
	waitmovement LOCALID_DRAGONS_ROOST_HAXORUS
# 367 "data//maps/DragonsRoost/scripts.pory"
	delay 15
# 368 "data//maps/DragonsRoost/scripts.pory"
	msgbox DragonsRoost_Text_HaxorusAttacked, MSGBOX_DEFAULT
# 369 "data//maps/DragonsRoost/scripts.pory"
	closemessage
# 370 "data//maps/DragonsRoost/scripts.pory"
	goto DragonsRoost_EventScript_Haxorus
# 371 "data//maps/DragonsRoost/scripts.pory"
	end
# 372 "data//maps/DragonsRoost/scripts.pory"

# 373 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Haxorus::
# 374 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 375 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_HAXORUS, CRY_MODE_ENCOUNTER
# 376 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 377 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 378 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_DRAGONS_ROOST_HAXORUS
# 379 "data//maps/DragonsRoost/scripts.pory"
	setwildbossmon 1
# 380 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 60
# 381 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 382 "data//maps/DragonsRoost/scripts.pory"
	special StartRegiBattle
# 383 "data//maps/DragonsRoost/scripts.pory"
	waitstate
# 384 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 385 "data//maps/DragonsRoost/scripts.pory"
	endwildbossmon
# 386 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_HAXORUS 
# 387 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 388 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 389 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 390 "data//maps/DragonsRoost/scripts.pory"
	release
# 391 "data//maps/DragonsRoost/scripts.pory"
	end
# 392 "data//maps/DragonsRoost/scripts.pory"

# 393 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_Tyrantrum::
# 394 "data//maps/DragonsRoost/scripts.pory"
	lock
# 395 "data//maps/DragonsRoost/scripts.pory"
	faceplayer
# 396 "data//maps/DragonsRoost/scripts.pory"
	waitse
# 397 "data//maps/DragonsRoost/scripts.pory"
	playmoncry SPECIES_TYRANTRUM, CRY_MODE_ENCOUNTER
# 398 "data//maps/DragonsRoost/scripts.pory"
	delay 10
# 399 "data//maps/DragonsRoost/scripts.pory"
	waitmoncry
# 400 "data//maps/DragonsRoost/scripts.pory"
	setwildbattle SPECIES_TYRANTRUM, 50
# 401 "data//maps/DragonsRoost/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 402 "data//maps/DragonsRoost/scripts.pory"
	dowildbattle
# 403 "data//maps/DragonsRoost/scripts.pory"
	@ waitstate
# 404 "data//maps/DragonsRoost/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 405 "data//maps/DragonsRoost/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRANTRUM
# 406 "data//maps/DragonsRoost/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 407 "data//maps/DragonsRoost/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsRoost_EventScript_DefeatedWildMon
# 408 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsRoost_EventScript_RanWildMon
# 409 "data//maps/DragonsRoost/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsRoost_EventScript_RanWildMon
# 410 "data//maps/DragonsRoost/scripts.pory"
	release
# 411 "data//maps/DragonsRoost/scripts.pory"
	end
# 412 "data//maps/DragonsRoost/scripts.pory"

# 413 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_DefeatedWildMon::
# 414 "data//maps/DragonsRoost/scripts.pory"
    goto Common_EventScript_RemoveStaticPokemon
# 415 "data//maps/DragonsRoost/scripts.pory"
	release
# 416 "data//maps/DragonsRoost/scripts.pory"
	end
# 417 "data//maps/DragonsRoost/scripts.pory"

# 418 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_EventScript_RanWildMon::
# 419 "data//maps/DragonsRoost/scripts.pory"
	goto Common_EventScript_WildMonFled
# 420 "data//maps/DragonsRoost/scripts.pory"
	release
# 421 "data//maps/DragonsRoost/scripts.pory"
	end
# 422 "data//maps/DragonsRoost/scripts.pory"

# 423 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyOff:
# 424 "data//maps/DragonsRoost/scripts.pory"
	delay_16
# 425 "data//maps/DragonsRoost/scripts.pory"
	fly_up
# 426 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 427 "data//maps/DragonsRoost/scripts.pory"

# 428 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpI:
# 429 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 430 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 431 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 432 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 433 "data//maps/DragonsRoost/scripts.pory"
	walk_up
# 434 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_up
# 435 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_up
# 436 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 437 "data//maps/DragonsRoost/scripts.pory"

# 438 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanUpII:
# 439 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 440 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 441 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 442 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 443 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 444 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 445 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 446 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 447 "data//maps/DragonsRoost/scripts.pory"

# 448 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownI:
# 449 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 450 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 451 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 452 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 453 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 454 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 455 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 456 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 457 "data//maps/DragonsRoost/scripts.pory"

# 458 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_CameraPanDownII:
# 459 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 460 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 461 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 462 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 463 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 464 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 465 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_down
# 466 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 467 "data//maps/DragonsRoost/scripts.pory"

# 468 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_RayquazaFlyDown:
# 469 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 470 "data//maps/DragonsRoost/scripts.pory"
	walk_slow_up
# 471 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 472 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_up
# 473 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 474 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 475 "data//maps/DragonsRoost/scripts.pory"
	walk_faster_down
# 476 "data//maps/DragonsRoost/scripts.pory"
	walk_down
# 477 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 478 "data//maps/DragonsRoost/scripts.pory"

# 479 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachA:
# 480 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 481 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 482 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 483 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 484 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 485 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 486 "data//maps/DragonsRoost/scripts.pory"

# 487 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachB:
# 488 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 489 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 490 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 491 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 492 "data//maps/DragonsRoost/scripts.pory"
	walk_in_place_down
# 493 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 494 "data//maps/DragonsRoost/scripts.pory"

# 495 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachC:
# 496 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_left
# 497 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 498 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 499 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 500 "data//maps/DragonsRoost/scripts.pory"

# 501 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachD:
# 502 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 503 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 504 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 505 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 506 "data//maps/DragonsRoost/scripts.pory"

# 507 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_HaxorusApproachE:
# 508 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 509 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 510 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_right
# 511 "data//maps/DragonsRoost/scripts.pory"
	walk_fast_down
# 512 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 513 "data//maps/DragonsRoost/scripts.pory"

# 514 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetInvisible:
# 515 "data//maps/DragonsRoost/scripts.pory"
	set_invisible
# 516 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 517 "data//maps/DragonsRoost/scripts.pory"

# 518 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Movement_SetVisible:
# 519 "data//maps/DragonsRoost/scripts.pory"
	set_visible
# 520 "data//maps/DragonsRoost/scripts.pory"
	step_end
# 521 "data//maps/DragonsRoost/scripts.pory"

# 522 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaFlewOff:
# 523 "data//maps/DragonsRoost/scripts.pory"
	.string "But it flew off…\p"
# 524 "data//maps/DragonsRoost/scripts.pory"
	.string "It seemed like it was headed back\n"
# 525 "data//maps/DragonsRoost/scripts.pory"
	.string "towards SKY PILLAR!$"
# 526 "data//maps/DragonsRoost/scripts.pory"

# 527 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaAppeared:
# 528 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA appeared!$"
# 529 "data//maps/DragonsRoost/scripts.pory"

# 530 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_RayquazaIsHere:
# 531 "data//maps/DragonsRoost/scripts.pory"
	.string "RAYQUAZA roared nearby!$"
# 532 "data//maps/DragonsRoost/scripts.pory"

# 533 "data//maps/DragonsRoost/scripts.pory"
DragonsRoost_Text_HaxorusAttacked:
# 534 "data//maps/DragonsRoost/scripts.pory"
	.string "HAXORUS approached aggresively!$"
