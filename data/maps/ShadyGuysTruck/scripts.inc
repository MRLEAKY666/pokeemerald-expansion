ShadyGuysTruck_MapScripts::
	.byte 0


ShadyGuysTruck_EventScript_ShadyGuy::
# 23 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 24 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_ShadyGuy_2
# 30 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 31 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 32 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_6
# 38 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_2, MSGBOX_YESNO
ShadyGuysTruck_EventScript_ShadyGuy_5:
# 42 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_9
# 89 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_ShadyGuy_1:
# 94 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_ShadyGuy_2:
# 25 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_0, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_6:
# 33 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_1, MSGBOX_YESNO
	goto ShadyGuysTruck_EventScript_ShadyGuy_5

ShadyGuysTruck_EventScript_ShadyGuy_9:
# 43 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 44 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_12
# 51 "data//maps/ShadyGuysTruck/scripts.pory"
	showmoneybox 0, 0
# 52 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_4, MSGBOX_YESNO
# 55 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_15
# 81 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 82 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_12:
# 45 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_15:
# 56 "data//maps/ShadyGuysTruck/scripts.pory"
	checkmoney 1000
# 57 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_18
# 74 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_6, MSGBOX_DEFAULT
# 77 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_18:
# 58 "data//maps/ShadyGuysTruck/scripts.pory"
	removemoney 1000
# 59 "data//maps/ShadyGuysTruck/scripts.pory"
	updatemoneybox
# 60 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_SHOP
# 61 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 62 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 20
# 63 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 64 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 65 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 66 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_5, MSGBOX_DEFAULT
# 70 "data//maps/ShadyGuysTruck/scripts.pory"
	setflag FLAG_TEMP_3
	goto ShadyGuysTruck_EventScript_ShadyGuy_1


ShadyGuysTruck_EventScript_Musharna::
# 98 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 99 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 100 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Musharna_2
# 114 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 115 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 116 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 117 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 118 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Musharna_1:
# 120 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Musharna_2:
# 101 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_0, MSGBOX_YESNO
# 102 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Musharna_5
# 110 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Musharna_1

ShadyGuysTruck_EventScript_Musharna_5:
# 103 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_MUSHARNA
# 104 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 105 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 106 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 107 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Musharna_1


ShadyGuysTruck_EventScript_Hypno::
# 124 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 125 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 126 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Hypno_2
# 140 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 141 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 142 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 143 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 144 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Hypno_1:
# 146 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Hypno_2:
# 127 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_0, MSGBOX_YESNO
# 128 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Hypno_5
# 136 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Hypno_1

ShadyGuysTruck_EventScript_Hypno_5:
# 129 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_HYPNO
# 130 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 131 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 132 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 133 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Hypno_1


ShadyGuysTruck_EventScript_ExtractMemories::
# 150 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 151 "data//maps/ShadyGuysTruck/scripts.pory"
	special ChoosePartyMon
# 152 "data//maps/ShadyGuysTruck/scripts.pory"
	waitstate
# 153 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_2
# 157 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_TEMP_B, ScriptGetPartyMonSpecies
# 158 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeoutbgm 1
# 159 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 160 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 161 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_INTRO_BLAST
# 163 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 7
# 164 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 165 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 166 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 80
# 167 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry VAR_TEMP_B, CRY_MODE_WEAK
# 168 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 172 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_E, SPECIES_HYPNO
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_5
# 179 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 180 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 181 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_MUSHARNA, Common_Movement_FaceDown
# 182 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateVitaminFromPartyMon
ShadyGuysTruck_EventScript_ExtractMemories_4:
# 184 "data//maps/ShadyGuysTruck/scripts.pory"
	hidefollower
# 185 "data//maps/ShadyGuysTruck/scripts.pory"
	clearflag FLAG_TEMP_3
# 186 "data//maps/ShadyGuysTruck/scripts.pory"
	addvar VAR_TEMP_A, 1
# 187 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 8
# 188 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeinbgm 1
	return

ShadyGuysTruck_EventScript_ExtractMemories_2:
# 154 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	end

ShadyGuysTruck_EventScript_ExtractMemories_5:
# 173 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 174 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 175 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_HYPNO, Common_Movement_FaceUp
# 176 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateCandyFromPartyMon
	goto ShadyGuysTruck_EventScript_ExtractMemories_4


ShadyGuysTruck_EventScript_GiveMedicine::
# 193 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_REVIVE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_2
# 220 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_NONE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 220 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_D, 0
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 236 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 237 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 238 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 239 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 240 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 241 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 242 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 244 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem VAR_TEMP_C, VAR_TEMP_D
# 245 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 246 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 247 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 248 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_4, MSGBOX_DEFAULT
# 252 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_5, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_GiveMedicine_1:
# 254 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 3
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_10
ShadyGuysTruck_EventScript_GiveMedicine_9:
	return

ShadyGuysTruck_EventScript_GiveMedicine_2:
# 194 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 195 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 196 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 197 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 198 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 199 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 200 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 201 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 202 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 203 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 204 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_0, MSGBOX_DEFAULT
# 209 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_RARE_CANDY, VAR_TEMP_D
# 210 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_GiveMedicine_Text_1
# 211 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 212 "data//maps/ShadyGuysTruck/scripts.pory"
	waitbuttonpress
# 213 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 214 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 215 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_2, MSGBOX_DEFAULT
# 218 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_REVIVE, 1
	goto ShadyGuysTruck_EventScript_GiveMedicine_1

ShadyGuysTruck_EventScript_GiveMedicine_3:
# 221 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 222 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 223 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 224 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 225 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 226 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 227 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 228 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 229 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 230 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 231 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_GiveMedicine_1

ShadyGuysTruck_EventScript_GiveMedicine_10:
# 255 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 256 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 257 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_GiveMedicine_Text_6
# 258 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 259 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 260 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_7, MSGBOX_DEFAULT
# 265 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 266 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 267 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, ShadyGuysTruck_Movement_LeaveTruckMaxExtractions
# 268 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 269 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_LeaveTruck
	goto ShadyGuysTruck_EventScript_GiveMedicine_9


# 274 "data//maps/ShadyGuysTruck/scripts.pory"
ShadyGuysTruck_Movement_LeaveTruckMaxExtractions:
# 275 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 276 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 277 "data//maps/ShadyGuysTruck/scripts.pory"
	walk_right
# 278 "data//maps/ShadyGuysTruck/scripts.pory"
	step_end

ShadyGuysTruck_EventScript_LeaveTruck::
# 282 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 3
	goto_if_ne ShadyGuysTruck_EventScript_LeaveTruck_2
# 286 "data//maps/ShadyGuysTruck/scripts.pory"
	clearflag FLAG_KEEP_SHADY_TRUCK
ShadyGuysTruck_EventScript_LeaveTruck_1:
# 288 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 289 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 290 "data//maps/ShadyGuysTruck/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 291 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne ShadyGuysTruck_EventScript_LeaveTruck_6
ShadyGuysTruck_EventScript_LeaveTruck_5:
# 295 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_LeaveTruck_Text_0
# 297 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 298 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 299 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 300 "data//maps/ShadyGuysTruck/scripts.pory"
	hidefollower
# 301 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 302 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 303 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 304 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
# 305 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_EXIT
# 306 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 307 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreen FADE_TO_BLACK
# 308 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_SHADY_TRUCK_LOCATION, MAP_LILYCOVE_CITY
# 309 "data//maps/ShadyGuysTruck/scripts.pory"
	switch VAR_SHADY_TRUCK_LOCATION
# 310 "data//maps/ShadyGuysTruck/scripts.pory"
	case MAP_RUSTBORO_CITY, ShadyGuysTruck_EventScript_LeaveTruck_9
# 312 "data//maps/ShadyGuysTruck/scripts.pory"
	case MAP_SLATEPORT_CITY, ShadyGuysTruck_EventScript_LeaveTruck_10
# 314 "data//maps/ShadyGuysTruck/scripts.pory"
	case MAP_LILYCOVE_CITY, ShadyGuysTruck_EventScript_LeaveTruck_11
	return

ShadyGuysTruck_EventScript_LeaveTruck_2:
# 283 "data//maps/ShadyGuysTruck/scripts.pory"
	setflag FLAG_KEEP_SHADY_TRUCK
	goto ShadyGuysTruck_EventScript_LeaveTruck_1

ShadyGuysTruck_EventScript_LeaveTruck_6:
# 292 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 293 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_LeaveTruck_5

ShadyGuysTruck_EventScript_LeaveTruck_9:
# 311 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_RUSTBORO_CITY, 5, 42
	return

ShadyGuysTruck_EventScript_LeaveTruck_10:
# 313 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_SLATEPORT_CITY, 10, 59
	return

ShadyGuysTruck_EventScript_LeaveTruck_11:
# 315 "data//maps/ShadyGuysTruck/scripts.pory"
	warpsilent MAP_LILYCOVE_CITY, 40, 30
	return


ShadyGuysTruck_EventScript_TruckExitTile::
# 320 "data//maps/ShadyGuysTruck/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 321 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_2
# 321 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_2
ShadyGuysTruck_EventScript_TruckExitTile_1:
# 355 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_TruckExitTile_2:
# 322 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 15
# 323 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_TruckExitTile_6
# 337 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 338 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 339 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 340 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 341 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 342 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_1, MSGBOX_YESNO
# 343 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_TruckExitTile_9
# 347 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_2, MSGBOX_DEFAULT
# 349 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 350 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 351 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_TruckExitTile_1

ShadyGuysTruck_EventScript_TruckExitTile_6:
# 324 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIN
# 325 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 326 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 327 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 328 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 329 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_TruckExitTile_Text_0, MSGBOX_DEFAULT
# 332 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 333 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 334 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
	goto ShadyGuysTruck_EventScript_TruckExitTile_1

ShadyGuysTruck_EventScript_TruckExitTile_9:
# 344 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_LeaveTruck
	goto ShadyGuysTruck_EventScript_TruckExitTile_1


ShadyGuysTruck_EventScript_PlayerEntersTruck::
# 359 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 360 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 361 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 362 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return


ShadyGuysTruck_EventScript_ShadyGuy_Text_0:
# 25 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_1:
# 33 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Welcome, traveler!\p"
	.string "My assistants can turn your POKéMON's\n"
	.string "memories into strengthening medicine.\p"
	.string "Would you like to try it?\n"
	.string "Your POKéMON will suffer…$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_2:
# 38 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Ah…\p"
	.string "You've had a bit of our strengthening\n"
	.string "medicine, and now you want more.\p"
	.string "Are you sure?\n"
	.string "Even though your POKéMON will suffer?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_3:
# 45 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Oh?\p"
	.string "You only have one POKéMON in your\n"
	.string "party…\p"
	.string "If something were to happen to it,\n"
	.string "well…\p"
	.string "You'd be defenseless.\p"
	.string "Come back with an extra teammate or\n"
	.string "two, just in case.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_4:
# 52 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I charge ¥1000 for our service.\p"
	.string "It's a good deal for such a rare skill…\p"
	.string "You'll benefit greatly, but your\n"
	.string "POKéMON will suffer.\p"
	.string "Do you still want to try it?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_5:
# 66 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Well then…\p"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_6:
# 74 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "You don't have enough money for our\n"
	.string "service.\p"
	.string "It's quite taxing on me and my POKéMON\n"
	.string "to perform this skill.\p"
	.string "If you wish to benefit from our talents,\n"
	.string "expect to compensate us appropriately.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_7:
# 82 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Yes, I understand.\p"
	.string "Your POKéMON would find you cruel for\n"
	.string "subjecting them to this technique.\p"
	.string "You're kind to spare them.$"

ShadyGuysTruck_EventScript_Musharna_Text_0:
# 101 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask MUSHARNA to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Musharna_Text_1:
# 105 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "MUUUUUUU…$"

ShadyGuysTruck_EventScript_Musharna_Text_2:
# 110 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking HYPNO instead.$"

ShadyGuysTruck_EventScript_Hypno_Text_0:
# 127 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask HYPNO to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Hypno_Text_1:
# 131 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "NOOOOOOO…$"

ShadyGuysTruck_EventScript_Hypno_Text_2:
# 136 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking MUSHARNA instead.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_0:
# 204 "data//maps/ShadyGuysTruck/scripts.pory"
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
# 210 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "That candy represents the extent of\n"
	.string "its experience in crystal form.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_2:
# 215 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "But we were also able to crystallize the\n"
	.string "last of its life force into this\l"
	.string "powerful medicine.\p"
	.string "Use it wisely,\p"
	.string "and remember {STR_VAR_2} when you\n"
	.string "do.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_3:
# 231 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Your POKéMON…\p"
	.string "My {STR_VAR_1} did its best, but\n"
	.string "{STR_VAR_2} just doesn't have\l"
	.string "enough experience to be of use.\p"
	.string "Next time, bring a more experienced\n"
	.string "POKéMON.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_4:
# 248 "data//maps/ShadyGuysTruck/scripts.pory"
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
# 252 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I hope you're happy!$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_6:
# 257 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_7:
# 260 "data//maps/ShadyGuysTruck/scripts.pory"
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
# 295 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: My truck is always open\n"
	.string "to reliable and discrete customers!\p"
	.string "Stop back by if you see us again.$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_0:
# 329 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Oh, are you leaving?\p"
	.string "But you already paid for our service.\p"
	.string "Speak with one of my assistants to\n"
	.string "transform the memories of your POKéMON\l"
	.string "into something useful.$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_1:
# 342 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Oh, are you headed out?$"

ShadyGuysTruck_EventScript_TruckExitTile_Text_2:
# 347 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Good, good.\p"
	.string "Our service is hard to come by,\n"
	.string "consider giving it a try…$"
