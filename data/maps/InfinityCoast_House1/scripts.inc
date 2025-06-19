InfinityCoast_House1_MapScripts::
	.byte 0

InfinityCoast_House1_EventScript_OldLady::
	@ lock
	faceplayer
	goto_if_unset FLAG_MET_INFINITY_COAST_LADY, InfinityCoast_House1_EventScript_MeetOldLady
	goto_if_unset FLAG_DEFEATED_ZAPDOS, InfinityCoast_House1_EventScript_ZapdosRoosting
	msgbox InfinityCoast_House1_Text_DangerousWoods, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InfinityCoast_House1_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, InfinityCoast_House1_EventScript_DeclineRest
	end

InfinityCoast_House1_EventScript_MeetOldLady::
	msgbox InfinityCoast_House1_Text_MeetOldLady, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_MET_INFINITY_COAST_LADY
	return

InfinityCoast_House1_EventScript_ZapdosRoosting::
	msgbox InfinityCoast_House1_Text_ZapdosRoosting, MSGBOX_DEFAULT
	msgbox InfinityCoast_House1_Text_DangerousWoods, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InfinityCoast_House1_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, InfinityCoast_House1_EventScript_DeclineRest
	end

InfinityCoast_House1_EventScript_Rest::
	msgbox InfinityCoast_House1_Text_Rest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox InfinityCoast_House1_Text_PostRest, MSGBOX_DEFAULT
	release
	end

InfinityCoast_House1_EventScript_DeclineRest::
	msgbox InfinityCoast_House1_Text_DeclineRest, MSGBOX_DEFAULT
	release
	end

InfinityCoast_House1_EventScript_Drampa::
	@ lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAMPA, CRY_MODE_NORMAL
	msgbox InfinityCoast_House1_Text_Drampa, MSGBOX_DEFAULT
	waitmoncry
	release
	end

InfinityCoast_House1_Text_MeetOldLady:
	.string "Hello there! It's not often I see\n"
	.string "visitors all the way out here.\p"
	.string ". . .\n"
	.string ". . .\p"
	.string "You're looking for RAYQUAZA?\p"
	.string "It came here to regain its strength\n"
	.string "after an exhausting battle, but it has\l"
	.string "since moved on.\p"
	.string "I did find this interesting object\n"
	.string "that RAYQUAZA seemingly left behind.\p"
	.string "Please take it.\n"
	.string "It may help in your search.$"

InfinityCoast_House1_Text_DangerousWoods:
	.string "If you're planning to\n"
	.string "explore these woods, you should\l"
	.string "consider having a rest first.\p"
	.string "Do you want to take a rest?$"

InfinityCoast_House1_Text_ZapdosRoosting:
	.string "A wild ZAPDOS has been roosting\n"
	.string "here lately.\p"
	.string "Could that be why RAYQUAZA moved on?\p"
	.string "Powerful POKéMON like that\n"
	.string "rarely share territory.$"

InfinityCoast_House1_Text_Rest:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

InfinityCoast_House1_Text_PostRest:
	.string "There, isn't that better?\p"
	.string "You can take a rest here anytime.$"

InfinityCoast_House1_Text_DeclineRest:
	.string "Not right now? That's alright.\p"
	.string "You can take a rest here anytime.$"

InfinityCoast_House1_Text_Drampa:
	.string "Drooompapa!$"