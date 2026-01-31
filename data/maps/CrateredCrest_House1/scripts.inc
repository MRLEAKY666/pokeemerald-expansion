# 1 "data//maps/CrateredCrest_House1/scripts.pory"

# 2 "data//maps/CrateredCrest_House1/scripts.pory"

# 3 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_MapScripts::
# 4 "data//maps/CrateredCrest_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CrateredCrest_House1_OnTransition
# 5 "data//maps/CrateredCrest_House1/scripts.pory"
	.byte 0

CrateredCrest_House1_OnTransition::
# 11 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_set FLAG_TRIGGERED_DRAKE_LATI_SCENE, CrateredCrest_House1_OnTransition_2
	return

CrateredCrest_House1_OnTransition_1:
# 12 "data//maps/CrateredCrest_House1/scripts.pory"
	setflag FLAG_TEMP_3
	return

CrateredCrest_House1_OnTransition_2:
# 11 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_unset FLAG_RECEIVED_EON_TICKET, CrateredCrest_House1_OnTransition_1
	return


# 16 "data//maps/CrateredCrest_House1/scripts.pory"

# 17 "data//maps/CrateredCrest_House1/scripts.pory"

# 18 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_OldLady::
# 19 "data//maps/CrateredCrest_House1/scripts.pory"
	@ lock
# 20 "data//maps/CrateredCrest_House1/scripts.pory"
	faceplayer
# 21 "data//maps/CrateredCrest_House1/scripts.pory"
	call_if_unset FLAG_MET_CRATERED_CREST_LADY, CrateredCrest_House1_EventScript_MeetOldLady
# 22 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_DangerousCrater, MSGBOX_YESNO
# 23 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_eq VAR_RESULT, YES, CrateredCrest_House1_EventScript_Rest
# 24 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CrateredCrest_House1_EventScript_DeclineRest
# 25 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 26 "data//maps/CrateredCrest_House1/scripts.pory"

# 27 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_MeetOldLady::
# 28 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_CraterStory1, MSGBOX_DEFAULT
# 29 "data//maps/CrateredCrest_House1/scripts.pory"
	return
# 30 "data//maps/CrateredCrest_House1/scripts.pory"

# 31 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_Rest::
# 32 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_Rest, MSGBOX_DEFAULT
# 33 "data//maps/CrateredCrest_House1/scripts.pory"
	closemessage
# 34 "data//maps/CrateredCrest_House1/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 35 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_PostRest, MSGBOX_DEFAULT
# 36 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_set FLAG_MET_CRATERED_CREST_LADY, CrateredCrest_House1_EventScript_AskHearAboutCrater
# 37 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_unset FLAG_MET_CRATERED_CREST_LADY, CrateredCrest_House1_EventScript_TryMeetOldLadyFlag
# 38 "data//maps/CrateredCrest_House1/scripts.pory"
	release
# 39 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 40 "data//maps/CrateredCrest_House1/scripts.pory"

# 41 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_DeclineRest::
# 42 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_DeclineRest, MSGBOX_DEFAULT
# 43 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_set FLAG_MET_CRATERED_CREST_LADY, CrateredCrest_House1_EventScript_AskHearAboutCrater
# 44 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_unset FLAG_MET_CRATERED_CREST_LADY, CrateredCrest_House1_EventScript_TryMeetOldLadyFlag
# 45 "data//maps/CrateredCrest_House1/scripts.pory"
	release
# 46 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 47 "data//maps/CrateredCrest_House1/scripts.pory"

# 48 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_TryMeetOldLadyFlag::
# 49 "data//maps/CrateredCrest_House1/scripts.pory"
	setflag FLAG_MET_CRATERED_CREST_LADY
# 50 "data//maps/CrateredCrest_House1/scripts.pory"
	release
# 51 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 52 "data//maps/CrateredCrest_House1/scripts.pory"

# 53 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_AskHearAboutCrater::
# 54 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_HearAboutCraterAgain, MSGBOX_YESNO
# 55 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_eq VAR_RESULT, YES, CrateredCrest_House1_EventScript_RepeatCraterInfo
# 56 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_BeCareful, MSGBOX_DEFAULT
# 57 "data//maps/CrateredCrest_House1/scripts.pory"
	release
# 58 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 59 "data//maps/CrateredCrest_House1/scripts.pory"

# 60 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_HearAboutCraterAgain:
# 61 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Do you want to hear about the history\n"
# 62 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "of the crater again?$"
# 63 "data//maps/CrateredCrest_House1/scripts.pory"

# 64 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_BeCareful:
# 65 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Be very careful if you're planning\n"
# 66 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "to explore the crater!$"
# 67 "data//maps/CrateredCrest_House1/scripts.pory"

# 68 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_EventScript_RepeatCraterInfo::
# 69 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_CraterStory2, MSGBOX_DEFAULT
# 70 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_Text_BeCareful, MSGBOX_DEFAULT
# 71 "data//maps/CrateredCrest_House1/scripts.pory"
	release
# 72 "data//maps/CrateredCrest_House1/scripts.pory"
	end
# 73 "data//maps/CrateredCrest_House1/scripts.pory"

# 74 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_CraterStory1:
# 75 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Hello there.\p" 
# 76 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "It's not often I get visitors\n"
# 77 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "all the way out here.\p"
# 78 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "CRATERED CREST is commonly considered\n"
# 79 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "to be the site of an ancient eruption.\p"
# 80 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "But the legends of the tribe who settled\n"
# 81 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "here in the past tell a different story.\p"
# 82 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "They say this crater was formed when\n"
# 83 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "a meteor fell from the stars.\p"
# 84 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "According to their myth, rugged people\n"
# 85 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "and POKéMON are drawn here, seeing the\l"
# 86 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "crater as a place of power.$"
# 87 "data//maps/CrateredCrest_House1/scripts.pory"

# 88 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_CraterStory2:
# 89 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "CRATERED CREST is commonly considered\n"
# 90 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "to be the site of an ancient eruption.\p"
# 91 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "But the legends of the tribe who settled\n"
# 92 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "here in the past tell a different story.\p"
# 93 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "They say this crater was formed when\n"
# 94 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "a meteor fell from the stars.\p"
# 95 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "According to their myth, rugged people\n"
# 96 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "and POKéMON are drawn here, seeing the\l"
# 97 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "crater as a place of power.$"
# 98 "data//maps/CrateredCrest_House1/scripts.pory"

# 99 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_DangerousCrater:
# 100 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "If you'll be exploring the crater, why\n"
# 101 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "not have a rest before continuing?\p"
# 102 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Do you want to take a rest?$"
# 103 "data//maps/CrateredCrest_House1/scripts.pory"

# 104 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_Rest:
# 105 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "That's right.\n"
# 106 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Take your time and rest up!$"
# 107 "data//maps/CrateredCrest_House1/scripts.pory"

# 108 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_PostRest:
# 109 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "There, isn't that better?\p"
# 110 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "You can take a rest here anytime.$"
# 111 "data//maps/CrateredCrest_House1/scripts.pory"

# 112 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_DeclineRest:
# 113 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Not right now? That's alright.\p"
# 114 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "You can take a rest here anytime.$"
# 115 "data//maps/CrateredCrest_House1/scripts.pory"

# 116 "data//maps/CrateredCrest_House1/scripts.pory"
CrateredCrest_House1_Text_Drampa:
# 117 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Drooompapa!$"

CrateredCrest_House1_EventScript_Drake::
# 123 "data//maps/CrateredCrest_House1/scripts.pory"
	faceplayer
# 124 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_unset FLAG_MET_CRATERED_CREST_DRAKE, CrateredCrest_House1_EventScript_Drake_2
CrateredCrest_House1_EventScript_Drake_1:
# 137 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_2, MSGBOX_YESNO
# 138 "data//maps/CrateredCrest_House1/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CrateredCrest_House1_EventScript_Drake_5
# 166 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_5, MSGBOX_DEFAULT
CrateredCrest_House1_EventScript_Drake_4:
# 168 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_set FLAG_DRAKE_DRACO_METEOR_TUTORING, CrateredCrest_House1_EventScript_Drake_13
CrateredCrest_House1_EventScript_Drake_12:
# 171 "data//maps/CrateredCrest_House1/scripts.pory"
	applymovement LOCALID_CRATER_COTTAGE_DRAKE, Common_Movement_FaceOriginalDirection
# 172 "data//maps/CrateredCrest_House1/scripts.pory"
	waitmovement
# 173 "data//maps/CrateredCrest_House1/scripts.pory"
	release
	end

CrateredCrest_House1_EventScript_Drake_2:
# 125 "data//maps/CrateredCrest_House1/scripts.pory"
	goto_if_unset FLAG_MET_ELITE_FOUR_DRAKE, CrateredCrest_House1_EventScript_Drake_9
# 131 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_1, MSGBOX_DEFAULT
CrateredCrest_House1_EventScript_Drake_8:
# 135 "data//maps/CrateredCrest_House1/scripts.pory"
	setflag FLAG_MET_CRATERED_CREST_DRAKE
	goto CrateredCrest_House1_EventScript_Drake_1

CrateredCrest_House1_EventScript_Drake_5:
# 139 "data//maps/CrateredCrest_House1/scripts.pory"
	checktype TYPE_DRAGON
# 140 "data//maps/CrateredCrest_House1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CrateredCrest_House1_EventScript_Drake_15
# 160 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_7, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_4

CrateredCrest_House1_EventScript_Drake_9:
# 126 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_0, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_8

CrateredCrest_House1_EventScript_Drake_13:
# 169 "data//maps/CrateredCrest_House1/scripts.pory"
	clearflag FLAG_DRAKE_DRACO_METEOR_TUTORING
	goto CrateredCrest_House1_EventScript_Drake_12

CrateredCrest_House1_EventScript_Drake_15:
# 141 "data//maps/CrateredCrest_House1/scripts.pory"
	setflag FLAG_DRAKE_DRACO_METEOR_TUTORING
# 142 "data//maps/CrateredCrest_House1/scripts.pory"
	setvar VAR_0x8005, MOVE_DRACO_METEOR
# 143 "data//maps/CrateredCrest_House1/scripts.pory"
	fadescreen FADE_TO_BLACK
# 144 "data//maps/CrateredCrest_House1/scripts.pory"
	special ChooseMonForMoveTutor
# 145 "data//maps/CrateredCrest_House1/scripts.pory"
	waitstate
# 146 "data//maps/CrateredCrest_House1/scripts.pory"
	compare VAR_RESULT, TYPE_DRAGON
	goto_if_eq CrateredCrest_House1_EventScript_Drake_18
# 149 "data//maps/CrateredCrest_House1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CrateredCrest_House1_EventScript_Drake_19
# 152 "data//maps/CrateredCrest_House1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CrateredCrest_House1_EventScript_Drake_20
# 156 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_6, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_4

CrateredCrest_House1_EventScript_Drake_18:
# 147 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_3, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_4

CrateredCrest_House1_EventScript_Drake_19:
# 150 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_4, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_4

CrateredCrest_House1_EventScript_Drake_20:
# 153 "data//maps/CrateredCrest_House1/scripts.pory"
	msgbox CrateredCrest_House1_EventScript_Drake_Text_5, MSGBOX_DEFAULT
	goto CrateredCrest_House1_EventScript_Drake_4


CrateredCrest_House1_EventScript_Drampa::
# 179 "data//maps/CrateredCrest_House1/scripts.pory"
	faceplayer
# 180 "data//maps/CrateredCrest_House1/scripts.pory"
	waitse
# 181 "data//maps/CrateredCrest_House1/scripts.pory"
	playmoncry SPECIES_DRAMPA, CRY_MODE_NORMAL
# 182 "data//maps/CrateredCrest_House1/scripts.pory"
	message CrateredCrest_House1_Text_Drampa
# 183 "data//maps/CrateredCrest_House1/scripts.pory"
	waitmessage
# 184 "data//maps/CrateredCrest_House1/scripts.pory"
	delay 90
# 185 "data//maps/CrateredCrest_House1/scripts.pory"
	closemessage
# 186 "data//maps/CrateredCrest_House1/scripts.pory"
	release
	return


CrateredCrest_House1_EventScript_Drake_Text_0:
# 126 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "Greetings.\p"
	.string "My name is DRAKE, and I am considered to\n"
	.string "be an expert DRAGON type TRAINER.\p"
	.string "Since prehistory, the toughest people\n"
	.string "in HOENN…\p"
	.string "The most skilled DRAGON TRAINERS have\n"
	.string "settled in this high-altitude crater.$"

CrateredCrest_House1_EventScript_Drake_Text_1:
# 131 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "This is my home outside of EVERGRANDE\n"
	.string "CITY.\p"
	.string "Since prehistory, the toughest people\n"
	.string "in HOENN…\p"
	.string "The most skilled DRAGON TRAINERS have\n"
	.string "settled in this high-altitude crater.$"

CrateredCrest_House1_EventScript_Drake_Text_2:
# 137 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "DRAKE: Have you come here to learn the\n"
	.string "ultimate DRAGON type move?$"

CrateredCrest_House1_EventScript_Drake_Text_3:
# 147 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "This POKéMON…\p"
	.string "It may be capable of performing this\n"
	.string "move, but not until it trusts you more.$"

CrateredCrest_House1_EventScript_Drake_Text_4:
# 150 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "There.\p"
	.string "With that move, your POKéMON can\n"
	.string "finally reach it's full terrifying\l"
	.string "potential in battle.$"

CrateredCrest_House1_EventScript_Drake_Text_5:
# 153 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "When one of your DRAGON POKéMON is\n"
	.string "ready to ascend to the peak of\l"
	.string "strength, come back to see me.$"

CrateredCrest_House1_EventScript_Drake_Text_6:
# 156 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "This POKéMON…\p"
	.string "Though it may be capable of performing\n"
	.string "this move, it is not a DRAGON…\p"
	.string "I cannot teach this POKéMON.$"

CrateredCrest_House1_EventScript_Drake_Text_7:
# 160 "data//maps/CrateredCrest_House1/scripts.pory"
	.string "None of your POKéMON can handle this\n"
	.string "move.\p"
	.string "Come back with a DRAGON POKéMON strong\n"
	.string "enough to endure my tutelage,\p"
	.string "then I'll teach your POKéMON.$"
