CrateredCrest_Cave_MapScripts::
# 2 "data//maps/CrateredCrest_Cave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_set FLAG_TRIGGERED_DRAKE_LATI_SCENE, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 15
# 5 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT
	return

CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 3 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_EON_TICKET, CrateredCrest_Cave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return


CrateredCrest_Cave_EventScript_InteractLatiStone::
# 14 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_0, MSGBOX_DEFAULT
# 15 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING, CrateredCrest_Cave_EventScript_InteractLatiStone_3
CrateredCrest_Cave_EventScript_InteractLatiStone_1:
# 106 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	return

CrateredCrest_Cave_EventScript_InteractLatiStone_2:
# 16 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_7
# 20 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 1
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_8
CrateredCrest_Cave_EventScript_InteractLatiStone_6:
# 24 "data//maps/CrateredCrest_Cave/scripts.pory"
	getseenmon VAR_TEMP_6
# 25 "data//maps/CrateredCrest_Cave/scripts.pory"
	copyvar VAR_TEMP_5, VAR_RESULT
# 26 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_TEMP_5, TRUE
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_11
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_3:
# 15 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_EON_TICKET, CrateredCrest_Cave_EventScript_InteractLatiStone_2
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_7:
# 17 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1
# 18 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_TEMP_6, SPECIES_LATIAS
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_6

CrateredCrest_Cave_EventScript_InteractLatiStone_8:
# 21 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2
# 22 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_TEMP_6, SPECIES_LATIOS
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_6

CrateredCrest_Cave_EventScript_InteractLatiStone_11:
# 27 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_6
# 28 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMING_LATI_STATE, 1
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_13
# 82 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 83 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3
# 84 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 85 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 86 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 87 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 88 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_11, MSGBOX_DEFAULT
# 89 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMING_LATI_STATE, 2
	goto_if_eq CrateredCrest_Cave_EventScript_InteractLatiStone_16
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_13:
# 29 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 30 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3
# 31 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 32 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 33 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 34 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 35 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_4, MSGBOX_DEFAULT
# 36 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_TRIGGERED_DRAKE_LATI_SCENE
# 37 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 38 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 40
# 39 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_5, MSGBOX_DEFAULT
# 40 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 41 "data//maps/CrateredCrest_Cave/scripts.pory"
	hidefollower
# 42 "data//maps/CrateredCrest_Cave/scripts.pory"
	playse SE_PIN
# 43 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 44 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 45 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 46 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 47 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 48 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 21
# 49 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT
# 50 "data//maps/CrateredCrest_Cave/scripts.pory"
	addobject LOCALID_CRATER_CAVE_DRAKE, MAP_CRATERED_CREST_CAVE
# 51 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 13, 15
# 52 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_ApproachPlayer
# 53 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 54 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 55 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_6, MSGBOX_DEFAULT
# 57 "data//maps/CrateredCrest_Cave/scripts.pory"
	message CrateredCrest_Cave_EventScript_InteractLatiStone_Text_7
# 58 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmessage
# 59 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 60 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 61 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 62 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_8, MSGBOX_DEFAULT
# 63 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 64 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 65 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_DrakeThinks
# 66 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 120
# 67 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Cave_Movement_PlayerMoveForDrake
# 68 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement LOCALID_CRATER_CAVE_DRAKE
# 69 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 70 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_9, MSGBOX_DEFAULT
# 72 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 73 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_WalkInPlaceUp
# 74 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 75 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_WalkInPlaceRight
# 76 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_10, MSGBOX_DEFAULT
# 79 "data//maps/CrateredCrest_Cave/scripts.pory"
	goto CrateredCrest_Cave_EventScript_ChallengeDrake
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1

CrateredCrest_Cave_EventScript_InteractLatiStone_16:
# 90 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_UNUSED_0x8014, 2
# 91 "data//maps/CrateredCrest_Cave/scripts.pory"
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON
# 92 "data//maps/CrateredCrest_Cave/scripts.pory"
	special InitRoamer
# 93 "data//maps/CrateredCrest_Cave/scripts.pory"
	setvar VAR_ROAMING_LATI_STATE, 0
# 94 "data//maps/CrateredCrest_Cave/scripts.pory"
	playmoncry VAR_TEMP_6, CRY_MODE_ENCOUNTER
# 95 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmoncry
# 96 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 30
# 97 "data//maps/CrateredCrest_Cave/scripts.pory"
	playmoncry VAR_TEMP_6, CRY_MODE_ENCOUNTER
# 98 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmoncry
# 99 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 45
# 100 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_InteractLatiStone_Text_12, MSGBOX_DEFAULT
	goto CrateredCrest_Cave_EventScript_InteractLatiStone_1


CrateredCrest_Cave_EventScript_ChallengeDrake::
# 110 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, Common_Movement_FacePlayer
# 111 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement
# 112 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_2
# 117 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_ROAMER_POKEMON, 1
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_3
CrateredCrest_Cave_EventScript_ChallengeDrake_1:
# 122 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_7
CrateredCrest_Cave_EventScript_ChallengeDrake_6:
# 154 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_5, MSGBOX_DEFAULT
# 155 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	return

CrateredCrest_Cave_EventScript_ChallengeDrake_2:
# 113 "data//maps/CrateredCrest_Cave/scripts.pory"
	checkspecies SPECIES_LATIAS
# 114 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1
# 115 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LATIAS
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_1

CrateredCrest_Cave_EventScript_ChallengeDrake_3:
# 118 "data//maps/CrateredCrest_Cave/scripts.pory"
	checkspecies SPECIES_LATIOS
# 119 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferstring STR_VAR_1, CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2
# 120 "data//maps/CrateredCrest_Cave/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LATIOS
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_1

CrateredCrest_Cave_EventScript_ChallengeDrake_7:
# 123 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_0, MSGBOX_YESNO
# 124 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_9
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_6

CrateredCrest_Cave_EventScript_ChallengeDrake_9:
# 125 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_1, MSGBOX_DEFAULT
# 127 "data//maps/CrateredCrest_Cave/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAKE_CRATERED_CREST, CrateredCrest_Cave_EventScript_ChallengeDrake_Text_2
# 128 "data//maps/CrateredCrest_Cave/scripts.pory"
	hidefollower
# 129 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_3, MSGBOX_DEFAULT
# 131 "data//maps/CrateredCrest_Cave/scripts.pory"
	giveitem ITEM_EON_TICKET
# 132 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_RECEIVED_EON_TICKET
# 133 "data//maps/CrateredCrest_Cave/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 134 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 20
# 135 "data//maps/CrateredCrest_Cave/scripts.pory"
	msgbox CrateredCrest_Cave_EventScript_ChallengeDrake_Text_4, MSGBOX_DEFAULT
# 137 "data//maps/CrateredCrest_Cave/scripts.pory"
	closemessage
# 138 "data//maps/CrateredCrest_Cave/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 139 "data//maps/CrateredCrest_Cave/scripts.pory"
	compare VAR_TEMP_E, 13
	goto_if_eq CrateredCrest_Cave_EventScript_ChallengeDrake_12
CrateredCrest_Cave_EventScript_ChallengeDrake_11:
# 143 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_CRATER_CAVE_DRAKE, CrateredCrest_Cave_Movement_DrakeLeaves
# 144 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 60
# 145 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 146 "data//maps/CrateredCrest_Cave/scripts.pory"
	waitmovement LOCALID_CRATER_CAVE_DRAKE
# 147 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectxyperm LOCALID_CRATER_CAVE_DRAKE, 26, 25
# 148 "data//maps/CrateredCrest_Cave/scripts.pory"
	setobjectmovementtype LOCALID_CRATER_CAVE_DRAKE, MOVEMENT_TYPE_INVISIBLE
# 149 "data//maps/CrateredCrest_Cave/scripts.pory"
	addobject LOCALID_CRATER_CAVE_DRAKE, MAP_CRATERED_CREST_CAVE
# 150 "data//maps/CrateredCrest_Cave/scripts.pory"
	release
	end

CrateredCrest_Cave_EventScript_ChallengeDrake_12:
# 140 "data//maps/CrateredCrest_Cave/scripts.pory"
	applymovement LOCALID_PLAYER, CrateredCrest_Cave_Movement_PlayerMoveForDrake
# 141 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay 10
	goto CrateredCrest_Cave_EventScript_ChallengeDrake_11


# 158 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_DrakeLeaves:
# 159 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
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
	set_invisible
# 170 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 173 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_ApproachPlayer:
# 174 "data//maps/CrateredCrest_Cave/scripts.pory"
	set_visible
# 175 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 176 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 177 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 178 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 179 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 180 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 183 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_DrakeThinks:
# 184 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 185 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_down
# 186 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 187 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 188 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 189 "data//maps/CrateredCrest_Cave/scripts.pory"
	delay_16
# 190 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 191 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 192 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_up
# 193 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_in_place_right
# 194 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

# 197 "data//maps/CrateredCrest_Cave/scripts.pory"
CrateredCrest_Cave_Movement_PlayerMoveForDrake:
# 198 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_right
# 199 "data//maps/CrateredCrest_Cave/scripts.pory"
	walk_in_place_left
# 200 "data//maps/CrateredCrest_Cave/scripts.pory"
	step_end

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_0:
# 14 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "Weird rock flavour text.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_1:
# 17 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "red$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_2:
# 21 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "blue$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_3:
# 30 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "…{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_4:
# 35 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "White and {STR_VAR_1} feathers are strewn\naround near this strange stone.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_5:
# 39 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "{PLAYER}?$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_6:
# 55 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "DRAKE: Yes, a rare and powerful POKéMON\nroosts here.\p"
	.string "The POKéMON {STR_VAR_2} was in a deep sleep\nuntil it was disturbed by recent events.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_7:
# 57 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "…{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …{PAUSE 5} …$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_8:
# 62 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "And it appears you've managed to tame\n"
	.string "that {STR_VAR_2}!$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_9:
# 70 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "When I was younger, I too sought to\n"
	.string "tame one of these rare DRAGONS.\p"
	.string "Sailing distant seas, I discovered an\n"
	.string "island far to the south with a stone\l"
	.string "not unlike this one.$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_10:
# 76 "data//maps/CrateredCrest_Cave/scripts.pory"
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
# 88 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "White and {STR_VAR_1} feathers are strewn\naround near this strange stone.\pWas {STR_VAR_2} roosting here?$"

CrateredCrest_Cave_EventScript_InteractLatiStone_Text_12:
# 100 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "That was {STR_VAR_2}' cry!\pIt must have been able to recover\nits strength here.\p"
	.string "{STR_VAR_2} seems to be roaming\nHOENN again!$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_0:
# 123 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "Are you ready to prove yourself?$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_1:
# 125 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "This won't be like our battles at the\nPOKéMON LEAGUE, {PLAYER}.\p"
	.string "This is a real battle!$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_2:
# 127 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "So, you really do have what it takes to\nlet your vicious side loose.$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_3:
# 129 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "You and {STR_VAR_2} had the fortitude\nto withstand our intensity, and the\lsheer strength to defeat us.\p"
	.string "You've shown me you're worthy.\pTake this ticket to travel to\nSOUTHERN ISLAND.$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_4:
# 135 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "There you may just find the nest of\nanother rare DRAGON.\p"
	.string "Good luck, {PLAYER}$"

CrateredCrest_Cave_EventScript_ChallengeDrake_Text_5:
# 154 "data//maps/CrateredCrest_Cave/scripts.pory"
	.string "When you're ready to prove yourself,\ncome back here with {STR_VAR_2} and\l challenge me.$"
