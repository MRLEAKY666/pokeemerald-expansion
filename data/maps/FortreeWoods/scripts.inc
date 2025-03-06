# 1 "data//maps/FortreeWoods/scripts.pory"

# 2 "data//maps/FortreeWoods/scripts.pory"

# 3 "data//maps/FortreeWoods/scripts.pory"
.set LOCALID_FORTREE_WOODS_RAYQUAZA, 28
# 4 "data//maps/FortreeWoods/scripts.pory"

# 5 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_MapScripts::
# 6 "data//maps/FortreeWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeWoods_OnResume
# 7 "data//maps/FortreeWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeWoods_OnTransition
# 8 "data//maps/FortreeWoods/scripts.pory"
	.byte 0
# 9 "data//maps/FortreeWoods/scripts.pory"

# 10 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_OnResume:
# 11 "data//maps/FortreeWoods/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 12 "data//maps/FortreeWoods/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeWoods_EventScript_TryRemoveZapdos
# 13 "data//maps/FortreeWoods/scripts.pory"
	end
# 14 "data//maps/FortreeWoods/scripts.pory"

# 15 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_OnTransition:
# 16 "data//maps/FortreeWoods/scripts.pory"
	call_if_set FLAG_CAUGHT_ZAPDOS, FortreeWoods_EventScript_HideZapdos
# 17 "data//maps/FortreeWoods/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZAPDOS, FortreeWoods_EventScript_TryShowZapdos
# 18 "data//maps/FortreeWoods/scripts.pory"
	end
# 19 "data//maps/FortreeWoods/scripts.pory"

# 20 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_HideZapdos::
# 21 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_HIDE_ZAPDOS
# 22 "data//maps/FortreeWoods/scripts.pory"
	return
# 23 "data//maps/FortreeWoods/scripts.pory"

# 24 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_TryShowZapdos::
# 25 "data//maps/FortreeWoods/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 26 "data//maps/FortreeWoods/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS
# 27 "data//maps/FortreeWoods/scripts.pory"
	return
# 28 "data//maps/FortreeWoods/scripts.pory"

# 29 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_Rayquaza::
# 30 "data//maps/FortreeWoods/scripts.pory"
	lock
# 31 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 32 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 33 "data//maps/FortreeWoods/scripts.pory"
	fadeoutbgm 1
# 34 "data//maps/FortreeWoods/scripts.pory"
	special SpawnCameraObject
# 35 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanUpI
# 36 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 37 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FortreeWoods_Movement_CameraPanUpII
# 38 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanUpII
# 39 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 40 "data//maps/FortreeWoods/scripts.pory"
	special RemoveCameraObject
# 41 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 42 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 43 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 44 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 45 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 46 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 47 "data//maps/FortreeWoods/scripts.pory"
	special ShakeCamera
# 48 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 49 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 50 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 51 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 52 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 53 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 54 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 55 "data//maps/FortreeWoods/scripts.pory"
	special ShakeCamera
# 56 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 57 "data//maps/FortreeWoods/scripts.pory"
	waitmoncry
# 58 "data//maps/FortreeWoods/scripts.pory"
	applymovement LOCALID_FORTREE_WOODS_RAYQUAZA, FortreeWoods_Movement_RayquazaFlyOff
# 59 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 60 "data//maps/FortreeWoods/scripts.pory"
	removeobject LOCALID_FORTREE_WOODS_RAYQUAZA
# 61 "data//maps/FortreeWoods/scripts.pory"
	msgbox FortreeWoods_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 62 "data//maps/FortreeWoods/scripts.pory"
	closemessage
# 63 "data//maps/FortreeWoods/scripts.pory"
	delay 20
# 64 "data//maps/FortreeWoods/scripts.pory"
	special SpawnCameraObject
# 65 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanDownI
# 66 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FortreeWoods_Movement_CameraPanDownII
# 67 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 68 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 69 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanDownII
# 70 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 71 "data//maps/FortreeWoods/scripts.pory"
	fadeinbgm 1
# 72 "data//maps/FortreeWoods/scripts.pory"
	special RemoveCameraObject
# 73 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_FORTREE_WOODS_RAYQUAZA_CRY_DONE, 1
# 74 "data//maps/FortreeWoods/scripts.pory"
	releaseall
# 75 "data//maps/FortreeWoods/scripts.pory"
	end
# 76 "data//maps/FortreeWoods/scripts.pory"

# 77 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_TryRemoveZapdos::
# 78 "data//maps/FortreeWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 79 "data//maps/FortreeWoods/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 80 "data//maps/FortreeWoods/scripts.pory"
	removeobject VAR_LAST_TALKED
# 81 "data//maps/FortreeWoods/scripts.pory"
	return
# 82 "data//maps/FortreeWoods/scripts.pory"

# 83 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_Zapdos::
# 84 "data//maps/FortreeWoods/scripts.pory"
	@ lock
# 85 "data//maps/FortreeWoods/scripts.pory"
	faceplayer
# 86 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 87 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 88 "data//maps/FortreeWoods/scripts.pory"
	delay 40
# 89 "data//maps/FortreeWoods/scripts.pory"
	waitmoncry
# 90 "data//maps/FortreeWoods/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 91 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 92 "data//maps/FortreeWoods/scripts.pory"
	special StartRegiBattle
# 93 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 94 "data//maps/FortreeWoods/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 95 "data//maps/FortreeWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 96 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeWoods_EventScript_DefeatedZapdos
# 97 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeWoods_EventScript_RanFromZapdos
# 98 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeWoods_EventScript_RanFromZapdos
# 99 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 100 "data//maps/FortreeWoods/scripts.pory"
	release
# 101 "data//maps/FortreeWoods/scripts.pory"
	end
# 102 "data//maps/FortreeWoods/scripts.pory"

# 103 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_DefeatedZapdos::
# 104 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 105 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 106 "data//maps/FortreeWoods/scripts.pory"
	end
# 107 "data//maps/FortreeWoods/scripts.pory"

# 108 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_RanFromZapdos::
# 109 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 110 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 111 "data//maps/FortreeWoods/scripts.pory"
	end
# 112 "data//maps/FortreeWoods/scripts.pory"

# 113 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_RayquazaFlyOff:
# 114 "data//maps/FortreeWoods/scripts.pory"
	delay_16
# 115 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 116 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 117 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 118 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 119 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 120 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 121 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 122 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 123 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 124 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 125 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 126 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 127 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 128 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 129 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 130 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 131 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 132 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 133 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 134 "data//maps/FortreeWoods/scripts.pory"

# 135 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanUpI:
# 136 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 137 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 138 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 139 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 140 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 141 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 142 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 143 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 144 "data//maps/FortreeWoods/scripts.pory"

# 145 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanUpII:
# 146 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 147 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 148 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 149 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 150 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 151 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 152 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 153 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 154 "data//maps/FortreeWoods/scripts.pory"

# 155 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanDownI:
# 156 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 157 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 158 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 159 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 160 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 161 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 162 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 163 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 164 "data//maps/FortreeWoods/scripts.pory"

# 165 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanDownII:
# 166 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 167 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 168 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 169 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 170 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 171 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 172 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 173 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 174 "data//maps/FortreeWoods/scripts.pory"

# 175 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_SetInvisible:
# 176 "data//maps/FortreeWoods/scripts.pory"
	set_invisible
# 177 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 178 "data//maps/FortreeWoods/scripts.pory"

# 179 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_SetVisible:
# 180 "data//maps/FortreeWoods/scripts.pory"
	set_visible
# 181 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 182 "data//maps/FortreeWoods/scripts.pory"

# 183 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Text_RayquazaFlewOff:
# 184 "data//maps/FortreeWoods/scripts.pory"
	.string "RAYQUAZA flew off somewhere . . .$"
