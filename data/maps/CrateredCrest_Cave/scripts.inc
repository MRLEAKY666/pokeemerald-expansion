CrateredCrest_Cave_MapScripts::
# 2 "data//maps/CrateredCrest_Cave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 4 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_set FLAG_TRIGGERED_DRAKE_LATI_SCENE, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 15
# 6 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT
	return

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_EON_TICKET, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return


CrateredCrest_Cave_EventScript_InteractLatiStone::
# 15 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_0, MSGBOX_DEFAULT
# 16 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING, CrateredCrest_Cave_EventScript_InteractLatiStone_3
CrateredCrest_Cave_EventScript_InteractLatiStone_1:
# 107 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	return

CrateredCrest_Cave_EventScript_InteractLatiStone_2:
# 17 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_7
# 21 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 1
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_8
CrateredCrest_Cave_EventScript_InteractLatiStone_6:
# 25 "data//maps/CrateredCrest_Cave/scripts.pory"
	getseenmon VAR_TEMP_6
# 26 "data//maps/CrateredCrest_Cave/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 27 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_11
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_3:
# 16 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_EON_TICKET, CrateredCrest_Cave_EventScript_InteractLatiStone_2
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_7:
# 18 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1
# 19 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_TEMP_6, SPECIES_LATIAS
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_6

CrateredCrest_Cave_EventScript_InteractLatiStone_8:
# 22 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2
# 23 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_TEMP_6, SPECIES_LATIOS
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_6

CrateredCrest_Cave_EventScript_InteractLatiStone_11:
# 28 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_6
# 29 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMING_LATI_STATE, 1
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_13
# 83 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 84 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3
# 85 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 86 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 87 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 88 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 89 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_11, MSGBOX_DEFAULT
# 90 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMING_LATI_STATE, 2
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_16
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_13:
# 30 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 31 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3
# 32 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 33 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 34 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 35 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 36 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_4, MSGBOX_DEFAULT
# 37 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_TRIGGERED_DRAKE_LATI_SCENE
# 38 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 39 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 40
# 40 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_5, MSGBOX_DEFAULT
# 41 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 42 "data//maps/CrateredCrest_Cave/scripts.pory"
	hidefollower
# 43 "data//maps/CrateredCrest_Cave/scripts.pory"
	playse SE_PIN
# 44 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 45 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 46 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 47 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 48 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 49 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 21
# 50 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT
# 51 "data//maps/CrateredCrest_Cave/scripts.pory"
	addobject LOCALID_CRATER_CAVE_DRAKE, MAP_CRATERED_CREST_CAVE
# 52 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 15
# 53 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_ApproachPlayer
# 54 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 55 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 56 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_6, MSGBOX_DEFAULT
# 58 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_7
# 59 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 60 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 61 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 62 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 63 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_8, MSGBOX_DEFAULT
# 64 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 65 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 66 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_DrakeThinks
# 67 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 120
# 68 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Cave_Movement_PlayerMoveForDrake
# 69 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement LOCALID_CRATER_CAVE_DRAKE
# 70 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 71 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_9, MSGBOX_DEFAULT
# 73 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 74 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_WalkInPlaceUp
# 75 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 76 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_WalkInPlaceRight
# 77 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_10, MSGBOX_DEFAULT
# 80 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto CrateredCrest_Cave_EventScript_ChallengeDrake
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_16:
# 91 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_UNUSED_0x8014, 2
# 92 "data//maps/CrateredCrest_Cave/scripts.pory"
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON
# 93 "data//maps/CrateredCrest_Cave/scripts.pory"
	special InitRoamer
# 94 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_ROAMING_LATI_STATE, 0
# 95 "data//maps/CrateredCrest_Cave/scripts.pory"
	playmoncry VAR_TEMP_6, CRY_MODE_ENCOUNTER
# 96 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmoncry
# 97 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 98 "data//maps/CrateredCrest_Cave/scripts.pory"
	playmoncry VAR_TEMP_6, CRY_MODE_ENCOUNTER
# 99 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmoncry
# 100 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 45
# 101 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_12, MSGBOX_DEFAULT
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1


CrateredCrest_Cave_EventScript_ChallengeDrake::
# 111 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_FacePlayer
# 112 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 113 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_2
# 118 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 1
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_3
CrateredCrest_Cave_EventScript_ChallengeDrake_1:
# 123 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_7
CrateredCrest_Cave_EventScript_ChallengeDrake_6:
# 155 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_5, MSGBOX_DEFAULT
# 156 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	return

CrateredCrest_Cave_EventScript_ChallengeDrake_2:
# 114 "data//maps/CrateredCrest_Cave/scripts.pory"
	checkspecies SPECIES_LATIAS
# 115 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1
# 116 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LATIAS
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_1

CrateredCrest_Cave_EventScript_ChallengeDrake_3:
# 119 "data//maps/CrateredCrest_Cave/scripts.pory"
	checkspecies SPECIES_LATIOS
# 120 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2
# 121 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LATIOS
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_1

CrateredCrest_Cave_EventScript_ChallengeDrake_7:
# 124 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_0, MSGBOX_YESNO
# 125 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_9
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_6

CrateredCrest_Cave_EventScript_ChallengeDrake_9:
# 126 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_1, MSGBOX_DEFAULT
# 128 "data//maps/CrateredCrest_Cave/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE_CRATERED_CREST, CrateredCrest_Cave_EventScript_ChallengeDrake_Text_2
# 129 "data//maps/CrateredCrest_Cave/scripts.pory"
	hidefollower
# 130 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_3, MSGBOX_DEFAULT
# 132 "data//maps/CrateredCrest_Cave/scripts.pory"
	giveitem ITEM_EON_TICKET
# 133 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_RECEIVED_EON_TICKET
# 134 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 135 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 136 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_4, MSGBOX_DEFAULT
# 138 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 139 "data//maps/CrateredCrest_Cave/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 140 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_TEMP_E, 13
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_12
CrateredCrest_Cave_EventScript_ChallengeDrake_11:
# 144 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_DrakeLeaves
# 145 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 146 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 147 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement LOCALID_CRATER_CAVE_DRAKE
# 148 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 26, 25
# 149 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_INVISIBLE
# 150 "data//maps/CrateredCrest_Cave/scripts.pory"
	addobject LOCALID_CRATER_CAVE_DRAKE, MAP_CRATERED_CREST_CAVE
# 151 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	end

CrateredCrest_Cave_EventScript_ChallengeDrake_12:
# 141 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Cave_Movement_PlayerMoveForDrake
# 142 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 10
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_11


# 159 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_DrakeLeaves:
# 160 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 161 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 162 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 163 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 164 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 165 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 166 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 167 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 168 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 169 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 170 "data//maps/CrateredCrest_Cave/scripts.pory"
	set_invisible
# 171 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 174 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_ApproachPlayer:
# 175 "data//maps/CrateredCrest_Cave/scripts.pory"
	set_visible
# 176 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 177 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 178 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 179 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 180 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 181 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 184 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_DrakeThinks:
# 185 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 186 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 187 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 188 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 189 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 190 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 191 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 192 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 193 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 194 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_in_place_right
# 195 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 198 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_PlayerMoveForDrake:
# 199 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_right
# 200 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_in_place_left
# 201 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_0:
# 15 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "Weird rock flavour text.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1:
# 18 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "red$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2:
# 22 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "blue$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3:
# 31 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "…{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_4:
# 36 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "White and {STR_VAR_1} feathers are strewn\naround near this strange stone.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_5:
# 40 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "{PLAYER}?$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_6:
# 56 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "DRAKE: Yes, a rare and powerful POKéMON\nroosts here.\p"
	.string "The POKéMON {STR_VAR_2} was in a deep sleep\nuntil it was disturbed by recent events.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_7:
# 58 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "…{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_8:
# 63 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "And it appears you've managed to tame\n"
	.string "that {STR_VAR_2}!$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_9:
# 71 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "When I was younger, I too sought to\n"
	.string "tame one of these rare DRAGONS.\p"
	.string "Sailing distant seas, I discovered an\n"
	.string "island far to the south with a stone\l"
	.string "not unlike this one.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_10:
# 77 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "{PLAYER}.\p"
	.string "If you can prove you are truly worthy\n"
	.string "of wielding that POKéMON in battle,\p"
	.string "you will have also proven yourself\n"
	.string "worthy enough to tame the POKéMON\l"
	.string "of that SOUTHERN ISLAND as well…\p"
	.string "But be prepared; I will test you with\n"
	.string "the full furiocity of my most vicious\l"
	.string "POKéMON!$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_11:
# 89 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "White and {STR_VAR_1} feathers are strewn\naround near this strange stone.\pWas {STR_VAR_2} roosting here?$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_12:
# 101 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "That was {STR_VAR_2}' cry!\pIt must have been able to recover\nits strength here.\p"
	.string "{STR_VAR_2} seems to be roaming\nHOENN again!$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_0:
# 124 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "Are you ready to prove yourself?$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_1:
# 126 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "This won't be like our battles at the\nPOKéMON LEAGUE, {PLAYER}.\p"
	.string "This is a real battle!$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_2:
# 128 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "So, you really do have what it takes to\nlet your vicious side loose.$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_3:
# 130 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "You and {STR_VAR_2} had the fortitude\nto withstand our intensity, and the\lsheer strength to defeat us.\p"
	.string "You've shown me you're worthy.\pTake this ticket to travel to\nSOUTHERN ISLAND.$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_4:
# 136 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "There you may just find the nest of\nanother rare DRAGON.\p"
	.string "Good luck, {PLAYER}$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_5:
# 155 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "When you're ready to prove yourself,\ncome back here with {STR_VAR_2} and\l challenge me.$"
