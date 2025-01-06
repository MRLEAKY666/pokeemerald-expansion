# 1 "data//maps/FortreeWoods/scripts.pory"

# 2 "data//maps/FortreeWoods/scripts.pory"

# 3 "data//maps/FortreeWoods/scripts.pory"
.set LOCALID_FORTREE_WOODS_RAYQUAZA, 28
# 4 "data//maps/FortreeWoods/scripts.pory"

# 5 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_Rayquaza::
# 6 "data//maps/FortreeWoods/scripts.pory"
	lock
# 7 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 8 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 9 "data//maps/FortreeWoods/scripts.pory"
	fadeoutbgm 1
# 10 "data//maps/FortreeWoods/scripts.pory"
	special SpawnCameraObject
# 11 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanUpI
# 12 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 13 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FortreeWoods_Movement_CameraPanUpII
# 14 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanUpII
# 15 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 16 "data//maps/FortreeWoods/scripts.pory"
	special RemoveCameraObject
# 17 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 18 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 19 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 20 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 21 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 22 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 23 "data//maps/FortreeWoods/scripts.pory"
	special ShakeCamera
# 24 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 25 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 26 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 27 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 28 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 29 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 30 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 31 "data//maps/FortreeWoods/scripts.pory"
	special ShakeCamera
# 32 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 33 "data//maps/FortreeWoods/scripts.pory"
	waitmoncry
# 34 "data//maps/FortreeWoods/scripts.pory"
	applymovement LOCALID_FORTREE_WOODS_RAYQUAZA, FortreeWoods_Movement_RayquazaFlyOff
# 35 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 36 "data//maps/FortreeWoods/scripts.pory"
	removeobject LOCALID_FORTREE_WOODS_RAYQUAZA
# 37 "data//maps/FortreeWoods/scripts.pory"
	msgbox FortreeWoods_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 38 "data//maps/FortreeWoods/scripts.pory"
	closemessage
# 39 "data//maps/FortreeWoods/scripts.pory"
	delay 20
# 40 "data//maps/FortreeWoods/scripts.pory"
	special SpawnCameraObject
# 41 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanDownI
# 42 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FortreeWoods_Movement_CameraPanDownII
# 43 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 44 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 45 "data//maps/FortreeWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeWoods_Movement_CameraPanDownII
# 46 "data//maps/FortreeWoods/scripts.pory"
	waitmovement 0
# 47 "data//maps/FortreeWoods/scripts.pory"
	fadeinbgm 1
# 48 "data//maps/FortreeWoods/scripts.pory"
	special RemoveCameraObject
# 49 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_FORTREE_WOODS_RAYQUAZA_CRY_DONE, 1
# 50 "data//maps/FortreeWoods/scripts.pory"
	releaseall
# 51 "data//maps/FortreeWoods/scripts.pory"
	end
# 52 "data//maps/FortreeWoods/scripts.pory"

# 53 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_MapScripts::
# 54 "data//maps/FortreeWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeWoods_OnResume
# 55 "data//maps/FortreeWoods/scripts.pory"
	.byte 0
# 56 "data//maps/FortreeWoods/scripts.pory"

# 57 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_OnResume:
# 58 "data//maps/FortreeWoods/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 59 "data//maps/FortreeWoods/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeWoods_EventScript_TryRemoveZapdos
# 60 "data//maps/FortreeWoods/scripts.pory"
	end
# 61 "data//maps/FortreeWoods/scripts.pory"

# 62 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_TryRemoveZapdos::
# 63 "data//maps/FortreeWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 64 "data//maps/FortreeWoods/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 65 "data//maps/FortreeWoods/scripts.pory"
	removeobject VAR_LAST_TALKED
# 66 "data//maps/FortreeWoods/scripts.pory"
	return
# 67 "data//maps/FortreeWoods/scripts.pory"

# 68 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_Zapdos::
# 69 "data//maps/FortreeWoods/scripts.pory"
	@ lock
# 70 "data//maps/FortreeWoods/scripts.pory"
	faceplayer
# 71 "data//maps/FortreeWoods/scripts.pory"
	waitse
# 72 "data//maps/FortreeWoods/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 73 "data//maps/FortreeWoods/scripts.pory"
	delay 40
# 74 "data//maps/FortreeWoods/scripts.pory"
	waitmoncry
# 75 "data//maps/FortreeWoods/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 50
# 76 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data//maps/FortreeWoods/scripts.pory"
	special StartRegiBattle
# 78 "data//maps/FortreeWoods/scripts.pory"
	waitstate
# 79 "data//maps/FortreeWoods/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 80 "data//maps/FortreeWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 81 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FortreeWoods_EventScript_DefeatedZapdos
# 82 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FortreeWoods_EventScript_RanFromZapdos
# 83 "data//maps/FortreeWoods/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FortreeWoods_EventScript_RanFromZapdos
# 84 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 85 "data//maps/FortreeWoods/scripts.pory"
	release
# 86 "data//maps/FortreeWoods/scripts.pory"
	end
# 87 "data//maps/FortreeWoods/scripts.pory"

# 88 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_DefeatedZapdos::
# 89 "data//maps/FortreeWoods/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 90 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 91 "data//maps/FortreeWoods/scripts.pory"
	end
# 92 "data//maps/FortreeWoods/scripts.pory"

# 93 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_EventScript_RanFromZapdos::
# 94 "data//maps/FortreeWoods/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 95 "data//maps/FortreeWoods/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 96 "data//maps/FortreeWoods/scripts.pory"
	end
# 97 "data//maps/FortreeWoods/scripts.pory"

# 98 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_RayquazaFlyOff:
# 99 "data//maps/FortreeWoods/scripts.pory"
	delay_16
# 100 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 101 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 102 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 103 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 104 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 105 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 106 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 107 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 108 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 109 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 110 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 111 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 112 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 113 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 114 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 115 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 116 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 117 "data//maps/FortreeWoods/scripts.pory"
	slide_up
# 118 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 119 "data//maps/FortreeWoods/scripts.pory"

# 120 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanUpI:
# 121 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 122 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 123 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 124 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 125 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 126 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 127 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 128 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 129 "data//maps/FortreeWoods/scripts.pory"

# 130 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanUpII:
# 131 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 132 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 133 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 134 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 135 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 136 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 137 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_up
# 138 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 139 "data//maps/FortreeWoods/scripts.pory"

# 140 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanDownI:
# 141 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 142 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 143 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 144 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 145 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 146 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 147 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 148 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 149 "data//maps/FortreeWoods/scripts.pory"

# 150 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_CameraPanDownII:
# 151 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 152 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 153 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 154 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 155 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 156 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 157 "data//maps/FortreeWoods/scripts.pory"
	walk_slow_down
# 158 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 159 "data//maps/FortreeWoods/scripts.pory"

# 160 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_SetInvisible:
# 161 "data//maps/FortreeWoods/scripts.pory"
	set_invisible
# 162 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 163 "data//maps/FortreeWoods/scripts.pory"

# 164 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Movement_SetVisible:
# 165 "data//maps/FortreeWoods/scripts.pory"
	set_visible
# 166 "data//maps/FortreeWoods/scripts.pory"
	step_end
# 167 "data//maps/FortreeWoods/scripts.pory"

# 168 "data//maps/FortreeWoods/scripts.pory"
FortreeWoods_Text_RayquazaFlewOff:
# 169 "data//maps/FortreeWoods/scripts.pory"
	.string "RAYQUAZA flew off somewhere . . .$"
