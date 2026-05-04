ShadyGuysTruck_MapScripts::
	.byte 0


ShadyGuysTruck_EventScript_ShadyGuy::
# 12 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 13 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_ShadyGuy_2
# 19 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 20 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 21 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_6
# 27 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_2, MSGBOX_YESNO
ShadyGuysTruck_EventScript_ShadyGuy_5:
# 31 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_9
# 78 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_ShadyGuy_1:
# 83 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_ShadyGuy_2:
# 14 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_0, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_6:
# 22 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_1, MSGBOX_YESNO
	goto ShadyGuysTruck_EventScript_ShadyGuy_5

ShadyGuysTruck_EventScript_ShadyGuy_9:
# 32 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 33 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_12
# 40 "data//maps/ShadyGuysTruck/scripts.pory"
	showmoneybox 0, 0
# 41 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_4, MSGBOX_YESNO
# 44 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_15
# 70 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 71 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_7, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_12:
# 34 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_15:
# 45 "data//maps/ShadyGuysTruck/scripts.pory"
	checkmoney 1000
# 46 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyGuysTruck_EventScript_ShadyGuy_18
# 63 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_6, MSGBOX_DEFAULT
# 66 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
	goto ShadyGuysTruck_EventScript_ShadyGuy_1

ShadyGuysTruck_EventScript_ShadyGuy_18:
# 47 "data//maps/ShadyGuysTruck/scripts.pory"
	removemoney 1000
# 48 "data//maps/ShadyGuysTruck/scripts.pory"
	updatemoneybox
# 49 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_SHOP
# 50 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 51 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 20
# 52 "data//maps/ShadyGuysTruck/scripts.pory"
	hidemoneybox
# 53 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
# 54 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 55 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_ShadyGuy_Text_5, MSGBOX_DEFAULT
# 59 "data//maps/ShadyGuysTruck/scripts.pory"
	setflag FLAG_TEMP_3
	goto ShadyGuysTruck_EventScript_ShadyGuy_1


ShadyGuysTruck_EventScript_Musharna::
# 87 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 88 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 89 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Musharna_2
# 103 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 104 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 105 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 106 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 107 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Musharna_1:
# 109 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Musharna_2:
# 90 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_0, MSGBOX_YESNO
# 91 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Musharna_5
# 99 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Musharna_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Musharna_1

ShadyGuysTruck_EventScript_Musharna_5:
# 92 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_MUSHARNA
# 93 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_MUSHARNA, CRY_MODE_NORMAL
# 94 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Musharna_Text_1
# 95 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 96 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Musharna_1


ShadyGuysTruck_EventScript_Hypno::
# 113 "data//maps/ShadyGuysTruck/scripts.pory"
	faceplayer
# 114 "data//maps/ShadyGuysTruck/scripts.pory"
	waitse
# 115 "data//maps/ShadyGuysTruck/scripts.pory"
	goto_if_set FLAG_TEMP_3, ShadyGuysTruck_EventScript_Hypno_2
# 129 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 130 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 131 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 132 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 133 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
ShadyGuysTruck_EventScript_Hypno_1:
# 135 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	return

ShadyGuysTruck_EventScript_Hypno_2:
# 116 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_0, MSGBOX_YESNO
# 117 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShadyGuysTruck_EventScript_Hypno_5
# 125 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_Hypno_Text_2, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_Hypno_1

ShadyGuysTruck_EventScript_Hypno_5:
# 118 "data//maps/ShadyGuysTruck/scripts.pory"
	setvar VAR_TEMP_E, SPECIES_HYPNO
# 119 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_NORMAL
# 120 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_Hypno_Text_1
# 121 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_ExtractMemories
# 122 "data//maps/ShadyGuysTruck/scripts.pory"
	call ShadyGuysTruck_EventScript_GiveMedicine
	goto ShadyGuysTruck_EventScript_Hypno_1


ShadyGuysTruck_EventScript_ExtractMemories::
# 139 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 140 "data//maps/ShadyGuysTruck/scripts.pory"
	special ChoosePartyMon
# 141 "data//maps/ShadyGuysTruck/scripts.pory"
	waitstate
# 142 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_2
# 146 "data//maps/ShadyGuysTruck/scripts.pory"
	specialvar VAR_TEMP_B, ScriptGetPartyMonSpecies
# 147 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeoutbgm 1
# 148 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 40
# 149 "data//maps/ShadyGuysTruck/scripts.pory"
	closemessage
# 150 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_INTRO_BLAST
# 152 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 7
# 153 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 154 "data//maps/ShadyGuysTruck/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 155 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 80
# 156 "data//maps/ShadyGuysTruck/scripts.pory"
	playmoncry VAR_TEMP_B, CRY_MODE_WEAK
# 157 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmoncry
# 161 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_E, SPECIES_HYPNO
	goto_if_eq ShadyGuysTruck_EventScript_ExtractMemories_5
# 168 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 169 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 170 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_MUSHARNA, Common_Movement_FaceDown
# 171 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateVitaminFromPartyMon
ShadyGuysTruck_EventScript_ExtractMemories_4:
# 173 "data//maps/ShadyGuysTruck/scripts.pory"
	hidefollower
# 174 "data//maps/ShadyGuysTruck/scripts.pory"
	clearflag FLAG_TEMP_3
# 175 "data//maps/ShadyGuysTruck/scripts.pory"
	addvar VAR_TEMP_A, 1
# 176 "data//maps/ShadyGuysTruck/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 8
# 177 "data//maps/ShadyGuysTruck/scripts.pory"
	fadeinbgm 1
	return

ShadyGuysTruck_EventScript_ExtractMemories_2:
# 143 "data//maps/ShadyGuysTruck/scripts.pory"
	release
	end

ShadyGuysTruck_EventScript_ExtractMemories_5:
# 162 "data//maps/ShadyGuysTruck/scripts.pory"
	setobjectxy LOCALID_PLAYER, 2, 2
# 163 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 164 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_HYPNO, Common_Movement_FaceUp
# 165 "data//maps/ShadyGuysTruck/scripts.pory"
	callnative CreateCandyFromPartyMon
	goto ShadyGuysTruck_EventScript_ExtractMemories_4


ShadyGuysTruck_EventScript_GiveMedicine::
# 182 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_REVIVE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_2
# 208 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_C, ITEM_NONE
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 208 "data//maps/ShadyGuysTruck/scripts.pory"
	compare VAR_TEMP_D, 0
	goto_if_eq ShadyGuysTruck_EventScript_GiveMedicine_3
# 223 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 224 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 225 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 226 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 227 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 228 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 229 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_WalkInPlaceRight
# 231 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem VAR_TEMP_C, VAR_TEMP_D
# 232 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 233 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 234 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 235 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_4, MSGBOX_DEFAULT
# 239 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_5, MSGBOX_DEFAULT
ShadyGuysTruck_EventScript_GiveMedicine_1:
	return

ShadyGuysTruck_EventScript_GiveMedicine_2:
# 183 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 184 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 185 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 186 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 187 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 188 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 189 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 190 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 191 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 192 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_0, MSGBOX_DEFAULT
# 197 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_RARE_CANDY, VAR_TEMP_D
# 198 "data//maps/ShadyGuysTruck/scripts.pory"
	message ShadyGuysTruck_EventScript_GiveMedicine_Text_1
# 199 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmessage
# 200 "data//maps/ShadyGuysTruck/scripts.pory"
	waitbuttonpress
# 201 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 60
# 202 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 203 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_2, MSGBOX_DEFAULT
# 206 "data//maps/ShadyGuysTruck/scripts.pory"
	giveitem ITEM_REVIVE, 1
	goto ShadyGuysTruck_EventScript_GiveMedicine_1

ShadyGuysTruck_EventScript_GiveMedicine_3:
# 209 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_SHADYGUY_TRUCK_GUY, Common_Movement_ExclamationMark
# 210 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 211 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 10
# 212 "data//maps/ShadyGuysTruck/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 213 "data//maps/ShadyGuysTruck/scripts.pory"
	waitmovement
# 214 "data//maps/ShadyGuysTruck/scripts.pory"
	delay 30
# 215 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_E
# 216 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_B
# 217 "data//maps/ShadyGuysTruck/scripts.pory"
	bufferitemnameplural STR_VAR_3, VAR_TEMP_C, VAR_TEMP_D
# 218 "data//maps/ShadyGuysTruck/scripts.pory"
	msgbox ShadyGuysTruck_EventScript_GiveMedicine_Text_3, MSGBOX_DEFAULT
	goto ShadyGuysTruck_EventScript_GiveMedicine_1


ShadyGuysTruck_EventScript_ShadyGuy_Text_0:
# 14 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_1:
# 22 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Welcome, traveler!\p"
	.string "My assistants can turn your POKéMON's\n"
	.string "memories into strengthening medicine.\p"
	.string "Would you like to try it?\n"
	.string "Your POKéMON will suffer…$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_2:
# 27 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Ah…\p"
	.string "You've had a bit of our strengthening\n"
	.string "medicine, and now you want more.\p"
	.string "Are you sure?\n"
	.string "Even though your POKéMON will suffer?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_3:
# 34 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Oh?\p"
	.string "You only have one POKéMON in your\n"
	.string "party…\p"
	.string "If something were to happen to it,\n"
	.string "well…\p"
	.string "You'd be defenseless.\p"
	.string "Come back with an extra teammate or\n"
	.string "two, just in case.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_4:
# 41 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I charge ¥1000 for our service.\p"
	.string "It's a good deal for such a rare skill…\p"
	.string "You'll benefit greatly, but your\n"
	.string "POKéMON will suffer.\p"
	.string "Do you still want to try it?$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_5:
# 55 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Well then…\p"
	.string "Talk to one of my assistants to get\n"
	.string "started.\p"
	.string "HYPNO will extract memories of your\n"
	.string "POKéMON's experience,\p"
	.string "while MUSHARNA will extract memories of\n"
	.string "their effort.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_6:
# 63 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "You don't have enough money for our\n"
	.string "service.\p"
	.string "It's quite taxing on me and my POKéMON\n"
	.string "to perform this skill.\p"
	.string "If you wish to benefit from our talents,\n"
	.string "expect to compensate us appropriately.$"

ShadyGuysTruck_EventScript_ShadyGuy_Text_7:
# 71 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Yes, I understand.\p"
	.string "Your POKéMON would find you cruel for\n"
	.string "subjecting them to this technique.\p"
	.string "You're kind to spare them.$"

ShadyGuysTruck_EventScript_Musharna_Text_0:
# 90 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask MUSHARNA to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Musharna_Text_1:
# 94 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "MUUUUUUU…$"

ShadyGuysTruck_EventScript_Musharna_Text_2:
# 99 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking HYPNO instead.$"

ShadyGuysTruck_EventScript_Hypno_Text_0:
# 116 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Do you want to ask HYPNO to forcibly\n"
	.string "extract your POKéMON's memories?$"

ShadyGuysTruck_EventScript_Hypno_Text_1:
# 120 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "NOOOOOOO…$"

ShadyGuysTruck_EventScript_Hypno_Text_2:
# 125 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "Try asking MUSHARNA instead.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_0:
# 192 "data//maps/ShadyGuysTruck/scripts.pory"
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
# 198 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "That candy represents the extent of\n"
	.string "its experience in crystal form.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_2:
# 203 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "But we were also able to crystallize the\n"
	.string "last of its life force into this\l"
	.string "powerful medicine.\p"
	.string "Use it wisely,\p"
	.string "and remember {STR_VAR_2} when you\n"
	.string "do.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_3:
# 218 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "SHADY PERSON: Your POKéMON…\p"
	.string "My {STR_VAR_1} did its best, but\n"
	.string "{STR_VAR_2} just doesn't have\l"
	.string "enough experience to be of use.\p"
	.string "Next time, bring a more experienced\n"
	.string "POKéMON.$"

ShadyGuysTruck_EventScript_GiveMedicine_Text_4:
# 235 "data//maps/ShadyGuysTruck/scripts.pory"
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
# 239 "data//maps/ShadyGuysTruck/scripts.pory"
	.string "I hope you're happy!$"
