# 1 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 2 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_MapScripts::
# 3 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_BerryMastersHouse_OnTransition
# 4 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	.byte 0
# 5 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 6 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_OnTransition:
# 7 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_LANDMARK_BERRY_MASTERS_HOUSE
# 8 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DISCOVERED_ROOT_CELLAR, Route123_BerryMastersHouse_EventScript_SetCellarDoorOpen
# 9 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 10 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 11 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_SetCellarDoorOpen::
# 12 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE123_BERRY_MASTERS_HOUSE_ROOT_CELLAR_OPEN
# 13 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 14 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 15 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMaster::
# 16 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 17 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 18 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 19 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route123_BerryMastersHouse_EventScript_ReceivedBerryToday
# 20 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 21 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 22 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 23 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 24 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 25 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 26 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
# 27 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
# 28 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 29 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 30 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 31 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 32 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 33 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 34 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 35 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 36 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 37 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
# 38 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
# 39 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 40 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 41 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 42 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
# 43 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 44 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 45 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 46 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
# 47 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
# 48 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
# 49 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call Common_ShowEasyChatScreen
# 50 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 51 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 52 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_BerryMastersHouse_EventScript_GavePhrase
# 53 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_BerryMastersHouse_EventScript_CancelPhrase
# 54 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 55 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 56 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_CancelPhrase::
# 57 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
# 58 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 59 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 60 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 61 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 62 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GavePhrase::
# 63 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, NOT_SPECIAL_PHRASE, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 64 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_GREAT_BATTLE, Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
# 65 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_CHALLENGE_CONTEST, Route123_BerryMastersHouse_EventScript_GivePamtreBerry
# 66 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_OVERWHELMING_LATIAS, Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
# 67 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_COOL_LATIOS, Route123_BerryMastersHouse_EventScript_GiveDurinBerry
# 68 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_SUPER_HUSTLE, Route123_BerryMastersHouse_EventScript_GiveBelueBerry
# 69 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 70 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 71 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveNormalBerry::
# 72 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
# 73 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_WIFE_BERRIES
# 74 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 75 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 76 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 77 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 78 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 79 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 80 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 81 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveSpelonBerry::
# 82 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 83 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 84 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_SPELON_BERRY
# 85 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 86 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_SPELON_BERRY
# 87 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 88 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 89 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 90 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GivePamtreBerry::
# 91 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 92 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 93 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_PAMTRE_BERRY
# 94 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 95 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_PAMTRE_BERRY
# 96 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 97 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 98 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 99 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveWatmelBerry::
# 100 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 101 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 102 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_WATMEL_BERRY
# 103 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 104 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_WATMEL_BERRY
# 105 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 106 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 107 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 108 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveDurinBerry::
# 109 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 110 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 111 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_DURIN_BERRY
# 112 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 113 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_DURIN_BERRY
# 114 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 115 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 116 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 117 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveBelueBerry::
# 118 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 119 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 120 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_BELUE_BERRY
# 121 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 122 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELUE_BERRY
# 123 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 124 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 125 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 126 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday::
# 127 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 128 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 129 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 130 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 131 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GaveBerry::
# 132 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
# 133 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 134 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 135 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
