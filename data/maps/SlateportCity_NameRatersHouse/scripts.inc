# 1 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 2 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_MapScripts::
# 3 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.byte 0
# 4 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 5 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_NameRater::
# 6 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	lock
# 7 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	faceplayer
# 8 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
# 9 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
# 10 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 11 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 12 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 13 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
# 14 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
# 15 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	special ChoosePartyMon
# 16 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
# 17 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 18 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 19 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 20 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
# 21 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
# 22 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 23 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 24 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 25 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
# 26 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 27 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
# 28 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 29 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	special IsMonOTIDNotPlayers
# 30 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
# 31 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, MonOTNameNotPlayer
# 32 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 33 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
# 34 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
# 35 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
# 36 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
# 37 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 38 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 39 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
# 40 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
# 41 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 42 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 43 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 44 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
# 45 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
# 46 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 47 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 48 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 49 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
# 50 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
# 51 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 52 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
# 53 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferMonNickname
# 54 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
# 55 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
# 56 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 57 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 58 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 59 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
# 60 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
# 61 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	release
# 62 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 63 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 64 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
# 65 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hi, hi! I'm the NAME RATER!\n"
# 66 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I'm the fortune-teller of names!\p"
# 67 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I shall be pleased to rate your\n"
# 68 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "POKéMON's nickname.$"
# 69 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 70 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
# 71 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Which POKéMON's nickname should\n"
# 72 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I critique?$"
# 73 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 74 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
# 75 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
# 76 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "quite a fine name you bestowed.\p"
# 77 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "But! What say you, if I were to\n"
# 78 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "suggest a slightly better name?$"
# 79 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 80 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
# 81 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Ah, good. Then, what shall the new\n"
# 82 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "nickname be?$"
# 83 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 84 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
# 85 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Done! From now on, this POKéMON\n"
# 86 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "shall be known as {STR_VAR_1}!\p"
# 87 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It is a better name than before!\n"
# 88 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How fortunate for you!$"
# 89 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 90 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_DoVisitAgain:
# 91 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I see.\n"
# 92 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Do come visit again.$"
# 93 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 94 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
# 95 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Done! From now on, this POKéMON\n"
# 96 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "shall be known as {STR_VAR_1}!\p"
# 97 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It looks no different from before,\n"
# 98 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "and yet, this is vastly superior!\p"
# 99 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How fortunate for you!$"
# 100 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 101 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_MagnificentName:
# 102 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Hmmm… {STR_VAR_1} it is!\p"
# 103 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "This is a magnificent nickname!\n"
# 104 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "It is impeccably beyond reproach!\p"
# 105 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "You'll do well to cherish your\n"
# 106 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "{STR_VAR_1} now and beyond.$"
# 107 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"

# 108 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
# 109 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Now, now.\n"
# 110 "data//maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "That is merely an EGG!$"
