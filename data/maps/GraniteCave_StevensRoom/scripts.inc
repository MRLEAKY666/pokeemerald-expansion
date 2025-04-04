# 1 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 2 "data//maps/GraniteCave_StevensRoom/scripts.pory"
.set LOCALID_STEVEN, 1
# 3 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 4 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_MapScripts::
# 5 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.byte 0
# 6 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 7 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_Steven::
# 8 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 9 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 10 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
# 11 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	setvar VAR_0x8004, ITEM_LETTER
# 12 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 13 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_DELIVERED_STEVEN_LETTER
# 14 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
# 15 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	giveitem ITEM_HM_ROCK_SMASH, 1
# 16 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
# 17 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
# 18 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
# 19 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
# 20 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 21 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 22 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 23 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
# 24 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	waitfanfare
# 25 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 26 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay 30
# 27 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_REGISTERED_STEVEN_POKENAV
# 28 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
# 29 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 30 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
# 31 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
# 32 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 33 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
# 34 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	playse SE_EXIT
# 35 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	removeobject LOCALID_STEVEN
# 36 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	release
# 37 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	end
# 38 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 39 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitNorth::
# 40 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 41 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 42 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 43 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 44 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
# 45 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 46 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
# 47 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 48 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 49 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 50 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_StevenExitSouth::
# 51 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
# 52 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
# 53 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	waitmovement 0
# 54 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 55 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 56 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_EventScript_BagFull::
# 57 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
# 58 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	return
# 59 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 60 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExit:
# 61 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 62 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 63 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 64 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 65 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 66 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 67 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 68 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 69 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
# 70 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 71 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 72 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay_16
# 73 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_in_place_faster_up
# 74 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 75 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 76 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Movement_StevenExitSouth:
# 77 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_left
# 78 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 79 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 80 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 81 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_right
# 82 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 83 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	walk_up
# 84 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	delay_8
# 85 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	step_end
# 86 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 87 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
# 88 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "My name is STEVEN.\p"
# 89 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'm interested in rare stones,\n"
# 90 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "so I travel here and there.\p"
# 91 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh?\n"
# 92 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "A LETTER for me?$"
# 93 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 94 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_ThankYouTakeThis:
# 95 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "STEVEN: Okay, thank you.\p"
# 96 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "You went through all this trouble to\n"
# 97 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "deliver that. I need to thank you.\p"
# 98 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Let me see…\n"
# 99 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I'll give you this HM.\p"
# 100 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "It contains a useful move,\n"
# 101 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "ROCK SMASH.$"
# 102 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 103 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
# 104 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "STEVEN: That HM allows you to\n"
# 105 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "teach the move ROCK SMASH to your\l"
# 106 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "POKEMON.\p"
# 107 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "With that move, you can break apart\n"
# 108 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "crumbling rocks in the backcountry.\p"
# 109 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "But you'll need the GYM BADGE from\n"
# 110 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "MAUVILLE CITY to use it outside of\l"
# 111 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "battle.\p"
# 112 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string ". . .\p"
# 113 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Your POKéMON appear quite\n"
# 114 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "capable.\p"
# 115 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "If you keep training, you could even\n"
# 116 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "become the CHAMPION of the POKéMON\l"
# 117 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "LEAGUE one day. That's what I think.\p"
# 118 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "I know, since we've gotten to know each\n"
# 119 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "other, let's register one another in\l"
# 120 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "our POKéNAVS.\p"
# 121 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "… … … … … …$"
# 122 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 123 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_RegisteredSteven:
# 124 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Registered STEVEN\n"
# 125 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "in the POKéNAV.$"
# 126 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 127 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
# 128 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Now, I've got to hurry along.$"
# 129 "data//maps/GraniteCave_StevensRoom/scripts.pory"

# 130 "data//maps/GraniteCave_StevensRoom/scripts.pory"
GraniteCave_StevensRoom_Text_OhBagIsFull:
# 131 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "Oh, your BAG is full…\n"
# 132 "data//maps/GraniteCave_StevensRoom/scripts.pory"
	.string "That's too bad, then.$"
