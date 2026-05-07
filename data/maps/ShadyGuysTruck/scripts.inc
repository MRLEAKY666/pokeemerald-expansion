ShadyGuysTruck_MapScripts::
# 10 "data//maps/ShadyGuysTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data//maps/ShadyGuysTruck/scripts.pory"
	switch VAR_SHADY_TRUCK_DAY
# 12 "data//maps/ShadyGuysTruck/scripts.pory"
	case 1, ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 14 "data//maps/ShadyGuysTruck/scripts.pory"
	case 2, ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 16 "data//maps/ShadyGuysTruck/scripts.pory"
	case 3, ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
# 19 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_A, 0
	return

ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 13 "data//maps/ShadyGuysTruck/scripts.pory"
	copyvar VAR_TEMP_A, VAR_SHADY_TRUCK_DAY
	return

ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 15 "data//maps/ShadyGuysTruck/scripts.pory"
	copyvar VAR_TEMP_A, VAR_SHADY_TRUCK_DAY
	return

ShadyGuysTruck_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 17 "data//maps/ShadyGuysTruck/scripts.pory"
	copyvar VAR_TEMP_A, VAR_SHADY_TRUCK_DAY
	return


ShadyGuysTruck_EventScript_ShadyGuy::
# 35 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 36 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_ShadyGuy_2
# 42 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 43 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 44 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_6
# 50 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_2, MSGBOX_YESNO
ShadyGuysTruck_EventScript_ShadyGuy_5:
# 54 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_9
# 101 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_ShadyGuy_1:
# 106 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_ShadyGuy_2:
# 37 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_0, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_6:
# 45 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_1, MSGBOX_YESNO
	goto ShadyGuysTruck_EventScript_ShadyGuy_5

ShadyGuysTruck_EventScript_ShadyGuy_9:
# 55 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 56 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_12
# 63 "data//maps/ShadyGuysTruck/scripts.pory"
	showmoneybox 0, 0
# 64 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_4, MSGBOX_YESNO
# 67 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_15
# 93 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 94 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_12:
# 57 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_15:
# 68 "data//maps/ShadyGuysTruck/scripts.pory"
	checkmoney 1000
# 69 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_18
# 86 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_6, MSGBOX_DEFAULT
# 89 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_18:
# 70 "data//maps/ShadyGuysTruck/scripts.pory"
	removemoney 1000
# 71 "data//maps/ShadyGuysTruck/scripts.pory"
	updatemoneybox
# 72 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_SHOP
# 73 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 74 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 20
# 75 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 76 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 77 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 78 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_5, MSGBOX_DEFAULT
# 82 "data//maps/ShadyGuysTruck/scripts.pory"
	setflag FLAG_TEMP_3
	goto ShadyGuysTruck_EventScript_ShadyGuy_1


ShadyGuysTruck_EventScript_Musharna::
# 110 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 111 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 112 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Musharna_2
# 126 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 127 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 128 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 129 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 130 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Musharna_1:
# 132 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Musharna_2:
# 113 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_0, MSGBOX_YESNO
# 114 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Musharna_5
# 122 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Musharna_1

ShadyGuysTruck_EventScript_Musharna_5:
# 115 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_MUSHARNA
# 116 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 117 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 118 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 119 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Musharna_1


ShadyGuysTruck_EventScript_Hypno::
# 136 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 137 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 138 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Hypno_2
# 152 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 153 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 154 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 155 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 156 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Hypno_1:
# 158 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Hypno_2:
# 139 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_0, MSGBOX_YESNO
# 140 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Hypno_5
# 148 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Hypno_1

ShadyGuysTruck_EventScript_Hypno_5:
# 141 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_HYPNO
# 142 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 143 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 144 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 145 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Hypno_1


ShadyGuysTruck_EventScript_ExtractMemories::
# 162 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 163 "data//maps/ShadyGuysTruck/scripts.pory"
	special ChoosePartyMon
# 164 "data//maps/ShadyGuysTruck/scripts.pory"
	waitstate
# 165 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_2
# 169 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_TEMP_B, ScriptGetPartyMonSpecies
# 170 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeoutbgm 1
# 171 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 172 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 173 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_INTRO_BLAST
# 175 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 7
# 176 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 177 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 178 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 80
# 179 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry VAR_TEMP_B, CRY_MODE_WEAK
# 180 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 184 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_E, SPECIES_HYPNO
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_5
# 191 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 192 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 193 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_MUSHARNA, Common_Movement_FaceDown
# 194 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateVitaminFromPartyMon
ShadyGuysTruck_EventScript_ExtractMemories_4:
# 196 "data//maps/ShadyGuysTruck/scripts.pory"
	hidefollower
# 197 "data//maps/ShadyGuysTruck/scripts.pory"
	clearflag FLAG_TEMP_3
# 198 "data//maps/ShadyGuysTruck/scripts.pory"
	addvar VAR_TEMP_A, 1
# 199 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 8
# 200 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeinbgm 1
	return

ShadyGuysTruck_EventScript_ExtractMemories_2:
# 166 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	end

ShadyGuysTruck_EventScript_ExtractMemories_5:
# 185 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 186 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 187 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_HYPNO, Common_Movement_FaceUp
# 188 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateCandyFromPartyMon
	goto ShadyGuysTruck_EventScript_ExtractMemories_4


ShadyGuysTruck_EventScript_GiveMedicine::
# 205 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_REVIVE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_2
# 232 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_NONE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 232 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_D, 0
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 248 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 249 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 250 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 251 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 252 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 253 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 254 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 256 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem VAR_TEMP_C, VAR_TEMP_D
# 257 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 258 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 259 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 260 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_4, MSGBOX_DEFAULT
# 264 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_5, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_GiveMedicine_1:
# 266 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 3
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_10
ShadyGuysTruck_EventScript_GiveMedicine_9:
	return

ShadyGuysTruck_EventScript_GiveMedicine_2:
# 206 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 207 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 208 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 209 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 210 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 211 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 212 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 213 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 214 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 215 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 216 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_0, MSGBOX_DEFAULT
# 221 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_RARE_CANDY, VAR_TEMP_D
# 222 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_GiveMedicine_Text_1
# 223 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 224 "data//maps/ShadyGuysTruck/scripts.pory"
	waitbuttonpress
# 225 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 226 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 227 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_2, MSGBOX_DEFAULT
# 230 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_REVIVE, 1
	goto ShadyGuysTruck_EventScript_GiveMedicine_1

ShadyGuysTruck_EventScript_GiveMedicine_3:
# 233 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 234 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 235 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 236 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 237 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 238 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 239 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 240 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 241 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 242 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 243 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_GiveMedicine_1

ShadyGuysTruck_EventScript_GiveMedicine_10:
# 267 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 268 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 269 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_GiveMedicine_Text_6
# 270 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 271 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 272 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_7, MSGBOX_DEFAULT
# 277 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 278 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 279 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, ShadyGuysTruck_Movement_LeaveTruckMaxExtractions
# 280 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 281 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_LeaveTruck
	goto ShadyGuysTruck_EventScript_GiveMedicine_9


# 286 "data//maps/ShadyGuysTruck/scripts.pory"
ShadyGuysTruck_Movement_LeaveTruckMaxExtractions:
# 287 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 288 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 289 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 290 "data//maps/ShadyGuysTruck/scripts.pory"
	step_end

ShadyGuysTruck_EventScript_LeaveTruck::
# 294 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 3
	goto_if_ne ShadyGuysTruck_EventScript_LeaveTruck_2
# 298 "data//maps/ShadyGuysTruck/scripts.pory"
	clearflag FLAG_SHOW_SHADY_TRUCK
ShadyGuysTruck_EventScript_LeaveTruck_1:
# 300 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 301 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 302 "data//maps/ShadyGuysTruck/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 303 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne ShadyGuysTruck_EventScript_LeaveTruck_6
ShadyGuysTruck_EventScript_LeaveTruck_5:
# 307 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_LeaveTruck_Text_0
# 309 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 310 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 311 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 312 "data//maps/ShadyGuysTruck/scripts.pory"
	hidefollower
# 313 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 314 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 315 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 316 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
# 317 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_EXIT
# 318 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 319 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreen FADE_TO_BLACK
# 320 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_gt ShadyGuysTruck_EventScript_LeaveTruck_9
ShadyGuysTruck_EventScript_LeaveTruck_8:
# 323 "data//maps/ShadyGuysTruck/scripts.pory"
	switch VAR_SHADY_TRUCK_LOCATION
# 324 "data//maps/ShadyGuysTruck/scripts.pory"
	case 0, ShadyGuysTruck_EventScript_LeaveTruck_12
# 326 "data//maps/ShadyGuysTruck/scripts.pory"
	case 1, ShadyGuysTruck_EventScript_LeaveTruck_13
# 328 "data//maps/ShadyGuysTruck/scripts.pory"
	case 2, ShadyGuysTruck_EventScript_LeaveTruck_14
	return

ShadyGuysTruck_EventScript_LeaveTruck_2:
# 295 "data//maps/ShadyGuysTruck/scripts.pory"
	setflag FLAG_SHOW_SHADY_TRUCK
	goto ShadyGuysTruck_EventScript_LeaveTruck_1

ShadyGuysTruck_EventScript_LeaveTruck_6:
# 304 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 305 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_LeaveTruck_5

ShadyGuysTruck_EventScript_LeaveTruck_9:
# 321 "data//maps/ShadyGuysTruck/scripts.pory"
	copyvar VAR_SHADY_TRUCK_DAY, VAR_TEMP_A
	goto ShadyGuysTruck_EventScript_LeaveTruck_8

ShadyGuysTruck_EventScript_LeaveTruck_12:
# 325 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_RUSTBORO_CITY, 5, 42
	return

ShadyGuysTruck_EventScript_LeaveTruck_13:
# 327 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_SLATEPORT_CITY, 10, 59
	return

ShadyGuysTruck_EventScript_LeaveTruck_14:
# 329 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_LILYCOVE_CITY, 40, 30
	return


ShadyGuysTruck_EventScript_TruckExitTile::
# 334 "data//maps/ShadyGuysTruck/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 335 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_2
# 335 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_2
ShadyGuysTruck_EventScript_TruckExitTile_1:
# 369 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_TruckExitTile_2:
# 336 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 15
# 337 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_TruckExitTile_6
# 351 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 352 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 353 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 354 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 355 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 356 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_1, MSGBOX_YESNO
# 357 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_9
# 361 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_2, MSGBOX_DEFAULT
# 363 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 364 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 365 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_TruckExitTile_1

ShadyGuysTruck_EventScript_TruckExitTile_6:
# 338 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 339 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 340 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 341 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 342 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 343 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_0, MSGBOX_DEFAULT
# 346 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 347 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 348 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_TruckExitTile_1

ShadyGuysTruck_EventScript_TruckExitTile_9:
# 358 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_LeaveTruck
	goto ShadyGuysTruck_EventScript_TruckExitTile_1


ShadyGuysTruck_EventScript_PlayerEntersTruck::
# 373 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 374 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 375 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 376 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return


ShadyGuysTruck_EventScript_ShadyGuy_Text_0:
# 37 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_1:
# 45 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Welcome, traveler!\p"
	.string "My assistants can turn your POKéMON's\n"
	.string "memories into strengthening medicine.\p"
	.string "Would you like to try it?\n"
	.string "Your POKéMON will suffer…$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_2:
# 50 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Ah…\p"
	.string "You've had a bit of our strengthening\n"
	.string "medicine, and now you want more.\p"
	.string "Are you sure?\n"
	.string "Even though your POKéMON will suffer?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_3:
# 57 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Oh?\p"
	.string "You only have one POKéMON in your\n"
	.string "party…\p"
	.string "If something were to happen to it,\n"
	.string "well…\p"
	.string "You'd be defenseless.\p"
	.string "Come back with an extra teammate or\n"
	.string "two, just in case.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_4:
# 64 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I charge ¥1000 for our service.\p"
	.string "It's a good deal for such a rare skill…\p"
	.string "You'll benefit greatly, but your\n"
	.string "POKéMON will suffer.\p"
	.string "Do you still want to try it?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_5:
# 78 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Well then…\p"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_6:
# 86 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "You don't have enough money for our\n"
	.string "service.\p"
	.string "It's quite taxing on me and my POKéMON\n"
	.string "to perform this skill.\p"
	.string "If you wish to benefit from our talents,\n"
	.string "expect to compensate us appropriately.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_7:
# 94 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Yes, I understand.\p"
	.string "Your POKéMON would find you cruel for\n"
	.string "subjecting them to this technique.\p"
	.string "You're kind to spare them.$"

ShadyGuysTruck_EventScript_Musharna_Text_0:
# 113 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask MUSHARNA to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Musharna_Text_1:
# 117 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "MUUUUUUU…$"

ShadyGuysTruck_EventScript_Musharna_Text_2:
# 122 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking HYPNO instead.$"

ShadyGuysTruck_EventScript_Hypno_Text_0:
# 139 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask HYPNO to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Hypno_Text_1:
# 143 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "NOOOOOOO…$"

ShadyGuysTruck_EventScript_Hypno_Text_2:
# 148 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking MUSHARNA instead.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_0:
# 216 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Oh…\l"
	.string "That's not right…\p"
	.string "It seems my {STR_VAR_1} got carried\n"
	.string "away with its ability…\p"
	.string "It devoured the entirety of your\n"
	.string "{STR_VAR_2}'s experience.\p"
	.string "{STR_VAR_2} wasn't able to survive\n"
	.string "in such a severely weakened state.\p"
	.string "Your {STR_VAR_2} has died.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_1:
# 222 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "That candy represents the extent of\n"
	.string "its experience in crystal form.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_2:
# 227 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "But we were also able to crystallize the\n"
	.string "last of its life force into this\l"
	.string "powerful medicine.\p"
	.string "Use it wisely,\p"
	.string "and remember {STR_VAR_2} when you\n"
	.string "do.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_3:
# 243 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Your POKéMON…\p"
	.string "My {STR_VAR_1} did its best, but\n"
	.string "{STR_VAR_2} just doesn't have\l"
	.string "enough experience to be of use.\p"
	.string "Next time, bring a more experienced\n"
	.string "POKéMON.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_4:
# 260 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Yes…\l"
	.string "This is our talent.\p"
	.string "My {STR_VAR_1} was able to extract\n"
	.string "the memories of your {STR_VAR_2} to\l"
	.string "create {STR_VAR_3}.\p"
	.string "But in exchange, your {STR_VAR_2} is\n"
	.string "that much weaker.\p"
	.string "It's as though it never had that\n"
	.string "experience at all.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_5:
# 264 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I hope you're happy!$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_6:
# 269 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_7:
# 272 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Well look at that,\p"
	.string "It's about time we get moving.\p"
	.string "Offering a service like this attracts a\n"
	.string "lot of attention,\p"
	.string "especially with repeat customers like\n"
	.string "you spreading the word.\p"
	.string "We appreciate the business, but we have\n"
	.string "to keep a low profile.\p"
	.string "Please see yourself out, I'm sure we'll\n"
	.string "cross paths again soon.$"

ShadyGuysTruck_EventScript_LeaveTruck_Text_0:
# 307 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: My truck is always open\n"
	.string "to reliable and discrete customers!\p"
	.string "Stop back by if you see us again.$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_0:
# 343 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Oh, are you leaving?\p"
	.string "But you already paid for our service.\p"
	.string "Speak with one of my assistants to\n"
	.string "transform the memories of your POKéMON\l"
	.string "into something useful.$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_1:
# 356 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Oh, are you headed out?$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_2:
# 361 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Good, good.\p"
	.string "Our service is hard to come by,\n"
	.string "consider giving it a try…$"
