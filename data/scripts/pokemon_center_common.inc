PokemonCenterCommon_OnResume::
# 2 "data//scripts/pokemon_center_common.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 3 "data//scripts/pokemon_center_common.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenterCommon_OnResume_2
# 12 "data//scripts/pokemon_center_common.pory"
	setmetatile 6, 8, METATILE_PokemonCenter_Warpful_Rug_L, FALSE
# 13 "data//scripts/pokemon_center_common.pory"
	setmetatile 7, 8, METATILE_PokemonCenter_Warpful_Rug_R, FALSE
# 14 "data//scripts/pokemon_center_common.pory"
	special DrawWholeMapView
# 15 "data//scripts/pokemon_center_common.pory"
	goto_if_set FLAG_POST_WHITEOUT, PokemonCenterCommon_OnResume_7
PokemonCenterCommon_OnResume_1:
	end

PokemonCenterCommon_OnResume_2:
# 4 "data//scripts/pokemon_center_common.pory"
	setmetatile 6, 8, METATILE_PokemonCenter_Warpless_Rug_L, FALSE
# 5 "data//scripts/pokemon_center_common.pory"
	setmetatile 7, 8, METATILE_PokemonCenter_Warpless_Rug_R, FALSE
# 6 "data//scripts/pokemon_center_common.pory"
	special DrawWholeMapView
# 7 "data//scripts/pokemon_center_common.pory"
	goto_if_unset FLAG_POST_WHITEOUT, PokemonCenterCommon_OnResume_5
	goto PokemonCenterCommon_OnResume_1

PokemonCenterCommon_OnResume_5:
# 8 "data//scripts/pokemon_center_common.pory"
	setflag FLAG_POST_WHITEOUT
	goto PokemonCenterCommon_OnResume_1

PokemonCenterCommon_OnResume_7:
# 16 "data//scripts/pokemon_center_common.pory"
	clearflag FLAG_POST_WHITEOUT
	goto PokemonCenterCommon_OnResume_1


PokemonCenterCommon_PokemonLeague_OnResume::
# 23 "data//scripts/pokemon_center_common.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 24 "data//scripts/pokemon_center_common.pory"
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenterCommon_PokemonLeague_OnResume_2
# 33 "data//scripts/pokemon_center_common.pory"
	setmetatile 9, 11, METATILE_PokemonCenter_Warpful_Rug_L, FALSE
# 34 "data//scripts/pokemon_center_common.pory"
	setmetatile 10, 11, METATILE_PokemonCenter_Warpful_Rug_R, FALSE
# 35 "data//scripts/pokemon_center_common.pory"
	special DrawWholeMapView
# 36 "data//scripts/pokemon_center_common.pory"
	goto_if_set FLAG_POST_WHITEOUT, PokemonCenterCommon_PokemonLeague_OnResume_7
PokemonCenterCommon_PokemonLeague_OnResume_1:
	end

PokemonCenterCommon_PokemonLeague_OnResume_2:
# 25 "data//scripts/pokemon_center_common.pory"
	setmetatile 9, 11, METATILE_PokemonCenter_Warpless_Rug_L, FALSE
# 26 "data//scripts/pokemon_center_common.pory"
	setmetatile 10, 11, METATILE_PokemonCenter_Warpless_Rug_R, FALSE
# 27 "data//scripts/pokemon_center_common.pory"
	special DrawWholeMapView
# 28 "data//scripts/pokemon_center_common.pory"
	goto_if_unset FLAG_POST_WHITEOUT, PokemonCenterCommon_PokemonLeague_OnResume_5
	goto PokemonCenterCommon_PokemonLeague_OnResume_1

PokemonCenterCommon_PokemonLeague_OnResume_5:
# 29 "data//scripts/pokemon_center_common.pory"
	setflag FLAG_POST_WHITEOUT
	goto PokemonCenterCommon_PokemonLeague_OnResume_1

PokemonCenterCommon_PokemonLeague_OnResume_7:
# 37 "data//scripts/pokemon_center_common.pory"
	clearflag FLAG_POST_WHITEOUT
	goto PokemonCenterCommon_PokemonLeague_OnResume_1


PokemonCenterCommon_EventScript_InnAttendantTrigger1::
# 44 "data//scripts/pokemon_center_common.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 45 "data//scripts/pokemon_center_common.pory"
	switch VAR_RESULT
# 46 "data//scripts/pokemon_center_common.pory"
	case DIR_WEST, PokemonCenterCommon_EventScript_InnAttendantTrigger1_3
# 50 "data//scripts/pokemon_center_common.pory"
	setvar VAR_0x8004, FLAG_POKEMON_CENTER_INN_ATTENDANT
# 51 "data//scripts/pokemon_center_common.pory"
	special GetObjectEventLocalIdByFlag
# 52 "data//scripts/pokemon_center_common.pory"
	copyvar VAR_LAST_TALKED, VAR_0x8005
# 53 "data//scripts/pokemon_center_common.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 54 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 55 "data//scripts/pokemon_center_common.pory"
	delay 15
# 56 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 57 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 58 "data//scripts/pokemon_center_common.pory"
	delay 15
# 59 "data//scripts/pokemon_center_common.pory"
	goto PokemonCenterCommon_EventScript_InnAttendant
	return

PokemonCenterCommon_EventScript_InnAttendantTrigger1_3:
# 47 "data//scripts/pokemon_center_common.pory"
	release
	end


PokemonCenterCommon_EventScript_InnAttendantTrigger2::
# 63 "data//scripts/pokemon_center_common.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 64 "data//scripts/pokemon_center_common.pory"
	switch VAR_RESULT
# 65 "data//scripts/pokemon_center_common.pory"
	case DIR_WEST, PokemonCenterCommon_EventScript_InnAttendantTrigger2_3
# 69 "data//scripts/pokemon_center_common.pory"
	setvar VAR_0x8004, FLAG_POKEMON_CENTER_INN_ATTENDANT
# 70 "data//scripts/pokemon_center_common.pory"
	special GetObjectEventLocalIdByFlag
# 71 "data//scripts/pokemon_center_common.pory"
	copyvar VAR_LAST_TALKED, VAR_0x8005
# 72 "data//scripts/pokemon_center_common.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
# 73 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 74 "data//scripts/pokemon_center_common.pory"
	delay 15
# 75 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
# 76 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 77 "data//scripts/pokemon_center_common.pory"
	delay 15
# 78 "data//scripts/pokemon_center_common.pory"
	goto PokemonCenterCommon_EventScript_InnAttendant
	return

PokemonCenterCommon_EventScript_InnAttendantTrigger2_3:
# 66 "data//scripts/pokemon_center_common.pory"
	release
	end


PokemonCenterCommon_EventScript_NurseAfterWhiteOut::
# 82 "data//scripts/pokemon_center_common.pory"
	message gText_WelcomeCutShort
# 83 "data//scripts/pokemon_center_common.pory"
	waitmessage
# 84 "data//scripts/pokemon_center_common.pory"
	delay 30
# 85 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_NurseAfterWhiteOut_Text_0, MSGBOX_DEFAULT
# 88 "data//scripts/pokemon_center_common.pory"
	closemessage
# 89 "data//scripts/pokemon_center_common.pory"
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
# 90 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 91 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_NurseAfterWhiteOut_Text_1, MSGBOX_DEFAULT
# 92 "data//scripts/pokemon_center_common.pory"
	release
	end


PokemonCenterCommon_EventScript_InnAttendant::
# 97 "data//scripts/pokemon_center_common.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 98 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 101 "data//scripts/pokemon_center_common.pory"
	showmoneybox 0, 0
# 102 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_InnAttendant_Text_0, MSGBOX_YESNO
# 106 "data//scripts/pokemon_center_common.pory"
	compare VAR_RESULT, NO
	goto_if_eq PokemonCenterCommon_EventScript_InnAttendant_2
# 117 "data//scripts/pokemon_center_common.pory"
	checkmoney 500
# 118 "data//scripts/pokemon_center_common.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PokemonCenterCommon_EventScript_InnAttendant_5
# 130 "data//scripts/pokemon_center_common.pory"
	removemoney 500
# 131 "data//scripts/pokemon_center_common.pory"
	updatemoneybox
# 132 "data//scripts/pokemon_center_common.pory"
	playse SE_SHOP
# 133 "data//scripts/pokemon_center_common.pory"
	waitse
# 134 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_InnAttendant_Text_3, MSGBOX_DEFAULT
# 135 "data//scripts/pokemon_center_common.pory"
	setvar VAR_TEMP_0, 1
# 136 "data//scripts/pokemon_center_common.pory"
	hidemoneybox
# 137 "data//scripts/pokemon_center_common.pory"
	closemessage
# 139 "data//scripts/pokemon_center_common.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
# 140 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 141 "data//scripts/pokemon_center_common.pory"
	delay 30
# 142 "data//scripts/pokemon_center_common.pory"
	release
	return

PokemonCenterCommon_EventScript_InnAttendant_2:
# 107 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_InnAttendant_Text_1, MSGBOX_DEFAULT
# 109 "data//scripts/pokemon_center_common.pory"
	hidemoneybox
# 110 "data//scripts/pokemon_center_common.pory"
	closemessage
# 111 "data//scripts/pokemon_center_common.pory"
	delay 10
# 112 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 113 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 114 "data//scripts/pokemon_center_common.pory"
	release
	end

PokemonCenterCommon_EventScript_InnAttendant_5:
# 119 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_InnAttendant_Text_2, MSGBOX_DEFAULT
# 122 "data//scripts/pokemon_center_common.pory"
	hidemoneybox
# 123 "data//scripts/pokemon_center_common.pory"
	closemessage
# 124 "data//scripts/pokemon_center_common.pory"
	delay 10
# 125 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
# 126 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 127 "data//scripts/pokemon_center_common.pory"
	release
	end


PokemonCenterCommon_EventScript_PkmnCntrBed::
# 146 "data//scripts/pokemon_center_common.pory"
	hidefollower
# 147 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
# 148 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 149 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_PkmnCntrBed_Text_0, MSGBOX_YESNO
# 151 "data//scripts/pokemon_center_common.pory"
	compare VAR_RESULT, NO
	goto_if_eq PokemonCenterCommon_EventScript_PkmnCntrBed_2
# 155 "data//scripts/pokemon_center_common.pory"
	message PokemonCenterCommon_EventScript_PkmnCntrBed_Text_1
# 156 "data//scripts/pokemon_center_common.pory"
	waitmessage
# 157 "data//scripts/pokemon_center_common.pory"
	dynmultichoice 18, 2, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, PokemonCenterCommon_EventScript_PkmnCntrBed_Text_2, PokemonCenterCommon_EventScript_PkmnCntrBed_Text_3, PokemonCenterCommon_EventScript_PkmnCntrBed_Text_4, PokemonCenterCommon_EventScript_PkmnCntrBed_Text_5, PokemonCenterCommon_EventScript_PkmnCntrBed_Text_6
# 165 "data//scripts/pokemon_center_common.pory"
	switch VAR_RESULT
# 166 "data//scripts/pokemon_center_common.pory"
	case 0, PokemonCenterCommon_EventScript_PkmnCntrBed_6
# 168 "data//scripts/pokemon_center_common.pory"
	case 1, PokemonCenterCommon_EventScript_PkmnCntrBed_7
# 170 "data//scripts/pokemon_center_common.pory"
	case 2, PokemonCenterCommon_EventScript_PkmnCntrBed_8
# 172 "data//scripts/pokemon_center_common.pory"
	case 3, PokemonCenterCommon_EventScript_PkmnCntrBed_9
# 174 "data//scripts/pokemon_center_common.pory"
	case 4, PokemonCenterCommon_EventScript_PkmnCntrBed_10
# 177 "data//scripts/pokemon_center_common.pory"
	case 127, PokemonCenterCommon_EventScript_PkmnCntrBed_11
# 181 "data//scripts/pokemon_center_common.pory"
	release
	end

PokemonCenterCommon_EventScript_PkmnCntrBed_2:
# 152 "data//scripts/pokemon_center_common.pory"
	release
	end

PokemonCenterCommon_EventScript_PkmnCntrBed_4:
# 184 "data//scripts/pokemon_center_common.pory"
	fadescreen FADE_TO_BLACK
# 185 "data//scripts/pokemon_center_common.pory"
	playfanfare MUS_HEAL
# 186 "data//scripts/pokemon_center_common.pory"
	special HealPlayerParty
# 187 "data//scripts/pokemon_center_common.pory"
	setvar VAR_TEMP_0, 0
# 188 "data//scripts/pokemon_center_common.pory"
	waitfanfare
# 189 "data//scripts/pokemon_center_common.pory"
	delay 30
# 190 "data//scripts/pokemon_center_common.pory"
	fadescreen FADE_FROM_BLACK
# 191 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_PkmnCntrBed_Text_7
# 192 "data//scripts/pokemon_center_common.pory"
	release
	end

PokemonCenterCommon_EventScript_PkmnCntrBed_6:
# 167 "data//scripts/pokemon_center_common.pory"
	fwdtime MORNING_HOUR_BEGIN, 0
	goto PokemonCenterCommon_EventScript_PkmnCntrBed_4

PokemonCenterCommon_EventScript_PkmnCntrBed_7:
# 169 "data//scripts/pokemon_center_common.pory"
	fwdtime DAY_HOUR_BEGIN, 0
	goto PokemonCenterCommon_EventScript_PkmnCntrBed_4

PokemonCenterCommon_EventScript_PkmnCntrBed_8:
# 171 "data//scripts/pokemon_center_common.pory"
	fwdtime EVENING_HOUR_BEGIN, 0
	goto PokemonCenterCommon_EventScript_PkmnCntrBed_4

PokemonCenterCommon_EventScript_PkmnCntrBed_9:
# 173 "data//scripts/pokemon_center_common.pory"
	fwdtime NIGHT_HOUR_BEGIN, 0
	goto PokemonCenterCommon_EventScript_PkmnCntrBed_4

PokemonCenterCommon_EventScript_PkmnCntrBed_10:
# 175 "data//scripts/pokemon_center_common.pory"
	release
	end

PokemonCenterCommon_EventScript_PkmnCntrBed_11:
# 178 "data//scripts/pokemon_center_common.pory"
	release
	end


PokemonCenterCommon_EventScript_CantLeave::
# 197 "data//scripts/pokemon_center_common.pory"
	lock
# 198 "data//scripts/pokemon_center_common.pory"
	msgbox PokemonCenterCommon_EventScript_CantLeave_Text_0, MSGBOX_DEFAULT
# 199 "data//scripts/pokemon_center_common.pory"
	closemessage
# 200 "data//scripts/pokemon_center_common.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 201 "data//scripts/pokemon_center_common.pory"
	switch VAR_RESULT
# 202 "data//scripts/pokemon_center_common.pory"
	case DIR_NORTH, PokemonCenterCommon_EventScript_CantLeave_3
# 204 "data//scripts/pokemon_center_common.pory"
	case DIR_SOUTH, PokemonCenterCommon_EventScript_CantLeave_4
# 206 "data//scripts/pokemon_center_common.pory"
	case DIR_EAST, PokemonCenterCommon_EventScript_CantLeave_5
# 208 "data//scripts/pokemon_center_common.pory"
	case DIR_WEST, PokemonCenterCommon_EventScript_CantLeave_6
PokemonCenterCommon_EventScript_CantLeave_1:
# 211 "data//scripts/pokemon_center_common.pory"
	waitmovement
# 212 "data//scripts/pokemon_center_common.pory"
	release
	return

PokemonCenterCommon_EventScript_CantLeave_3:
# 203 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	goto PokemonCenterCommon_EventScript_CantLeave_1

PokemonCenterCommon_EventScript_CantLeave_4:
# 205 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	goto PokemonCenterCommon_EventScript_CantLeave_1

PokemonCenterCommon_EventScript_CantLeave_5:
# 207 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	goto PokemonCenterCommon_EventScript_CantLeave_1

PokemonCenterCommon_EventScript_CantLeave_6:
# 209 "data//scripts/pokemon_center_common.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	goto PokemonCenterCommon_EventScript_CantLeave_1


PokemonCenterCommon_EventScript_NurseAfterWhiteOut_Text_0:
# 85 "data//scripts/pokemon_center_common.pory"
	.string "Oh my…\p"
	.string "All of your POKéMON are dead!\p"
	.string "How terrible…\p"
	.string "Well,{PAUSE 20}\n"
	.string "I'm afraid I can't help with that at this\l"
	.string "time.\p"
	.string "Make sure to bring a living POKéMON with\n"
	.string "you if you're going back out into the\l"
	.string "field!$"

PokemonCenterCommon_EventScript_NurseAfterWhiteOut_Text_1:
# 91 "data//scripts/pokemon_center_common.pory"
	.string "We hope you excel!$"

PokemonCenterCommon_EventScript_InnAttendant_Text_0:
# 102 "data//scripts/pokemon_center_common.pory"
	.string "Welcome to the POKéMON CENTER.\p"
	.string "Through here is a room that TRAINERS\n"
	.string "can rent for a time.\p"
	.string "You can sleep for a while, rest your\n"
	.string "POKéMON, and change into a clean\l"
	.string "outfit.\p"
	.string "It's ¥500 to spend the night, would you\n"
	.string "like to stay?$"

PokemonCenterCommon_EventScript_InnAttendant_Text_1:
# 107 "data//scripts/pokemon_center_common.pory"
	.string "Come back anytime if you need to rest\n"
	.string "for a while.\p"
	.string "We hope to see you again!$"

PokemonCenterCommon_EventScript_InnAttendant_Text_2:
# 119 "data//scripts/pokemon_center_common.pory"
	.string "But you don't have enough money to\n"
	.string "rent this room…\p"
	.string "Come back with enough money if you\n"
	.string "need to rest for a while.\p"
	.string "We hope to see you again!$"

PokemonCenterCommon_EventScript_InnAttendant_Text_3:
# 134 "data//scripts/pokemon_center_common.pory"
	.string "Please enjoy our accomodations for the\n"
	.string "night.$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_0:
# 149 "data//scripts/pokemon_center_common.pory"
	.string "It's a bed for TRAINERS to spend the\n"
	.string "night.\p"
	.string "Do you want to sleep for a while?$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_1:
# 155 "data//scripts/pokemon_center_common.pory"
	.string "How long do you want to sleep?$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_2:
# 160 "data//scripts/pokemon_center_common.pory"
	.string "Morning$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_3:
# 161 "data//scripts/pokemon_center_common.pory"
	.string "Day$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_4:
# 162 "data//scripts/pokemon_center_common.pory"
	.string "Evening$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_5:
# 163 "data//scripts/pokemon_center_common.pory"
	.string "Night$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_6:
# 164 "data//scripts/pokemon_center_common.pory"
	.string "Cancel$"

PokemonCenterCommon_EventScript_PkmnCntrBed_Text_7:
# 191 "data//scripts/pokemon_center_common.pory"
	.string "{PLAYER} and the party woke up some\n"
	.string "time later feeling refreshed.$"

PokemonCenterCommon_EventScript_CantLeave_Text_0:
# 198 "data//scripts/pokemon_center_common.pory"
	.string "You can't leave without any living\n"
	.string "POKéMON in your party!$"
