DragonsRoost_House1_MapScripts::
	.byte 0

DragonsRoost_House1_EventScript_OldLady::
	@ lock
	faceplayer
	call_if_unset FLAG_MET_CRATERED_CREST_LADY, DragonsRoost_House1_EventScript_MeetOldLady
	msgbox DragonsRoost_House1_Text_DangerousCrater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DragonsRoost_House1_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, DragonsRoost_House1_EventScript_DeclineRest
	end

DragonsRoost_House1_EventScript_MeetOldLady::
	msgbox DragonsRoost_House1_Text_CraterStory1, MSGBOX_DEFAULT
	return

DragonsRoost_House1_EventScript_Rest::
	msgbox DragonsRoost_House1_Text_Rest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox DragonsRoost_House1_Text_PostRest, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_CRATERED_CREST_LADY, DragonsRoost_House1_EventScript_AskHearAboutCrater
	goto_if_unset FLAG_MET_CRATERED_CREST_LADY, DragonsRoost_House1_EventScript_TryMeetOldLadyFlag
	release
	end

DragonsRoost_House1_EventScript_DeclineRest::
	msgbox DragonsRoost_House1_Text_DeclineRest, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_CRATERED_CREST_LADY, DragonsRoost_House1_EventScript_AskHearAboutCrater
	goto_if_unset FLAG_MET_CRATERED_CREST_LADY, DragonsRoost_House1_EventScript_TryMeetOldLadyFlag
	release
	end

DragonsRoost_House1_EventScript_TryMeetOldLadyFlag::
	setflag FLAG_MET_CRATERED_CREST_LADY
	release
	end

DragonsRoost_House1_EventScript_AskHearAboutCrater::
	msgbox DragonsRoost_House1_Text_HearAboutCraterAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DragonsRoost_House1_EventScript_RepeatCraterInfo
	msgbox DragonsRoost_House1_Text_BeCareful, MSGBOX_DEFAULT
	release
	end

DragonsRoost_House1_Text_HearAboutCraterAgain:
	.string "Do you want to hear about the history\n"
	.string "of the crater again?$"

DragonsRoost_House1_Text_BeCareful:
	.string "Be very careful if you're planning\n"
	.string "to explore the crater!$"

DragonsRoost_House1_EventScript_RepeatCraterInfo::
	msgbox DragonsRoost_House1_Text_CraterStory2, MSGBOX_DEFAULT
	msgbox DragonsRoost_House1_Text_BeCareful, MSGBOX_DEFAULT
	release
	end

DragonsRoost_House1_EventScript_Drampa::
	@ lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAMPA, CRY_MODE_NORMAL
	msgbox DragonsRoost_House1_Text_Drampa, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DragonsRoost_House1_Text_CraterStory1:
	.string "Hello there.\p" 
	.string "It's not often I get visitors\n"
	.string "all the way out here.\p"
	.string "CRATERED CREST is commonly considered\n"
	.string "to be the site of an ancient eruption.\p"
	.string "But the legends of the tribe who settled\n"
	.string "here in the past tell a different story.\p"
	.string "They say this crater was formed when\n"
	.string "a meteor fell from the stars.\p"
	.string "According to their myth, rugged people\n"
	.string "and POKéMON are drawn here, seeing the\l"
	.string "crater as a place of power.$"

DragonsRoost_House1_Text_CraterStory2:
	.string "CRATERED CREST is commonly considered\n"
	.string "to be the site of an ancient eruption.\p"
	.string "But the legends of the tribe who settled\n"
	.string "here in the past tell a different story.\p"
	.string "They say this crater was formed when\n"
	.string "a meteor fell from the stars.\p"
	.string "According to their myth, rugged people\n"
	.string "and POKéMON are drawn here, seeing the\l"
	.string "crater as a place of power.$"

DragonsRoost_House1_Text_DangerousCrater:
	.string "If you'll be exploring the crater, why\n"
	.string "not have a rest before continuing?\p"
	.string "Do you want to take a rest?$"

DragonsRoost_House1_Text_Rest:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

DragonsRoost_House1_Text_PostRest:
	.string "There, isn't that better?\p"
	.string "You can take a rest here anytime.$"

DragonsRoost_House1_Text_DeclineRest:
	.string "Not right now? That's alright.\p"
	.string "You can take a rest here anytime.$"

DragonsRoost_House1_Text_Drampa:
	.string "Drooompapa!$"