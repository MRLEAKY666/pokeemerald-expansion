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
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 22 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 23 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
# 24 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
# 25 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 26 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 27 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 28 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call_if_unset FLAG_MET_BERRY_MASTER, Route123_BerryMastersHouse_EventScript_MetBerryMaster
# 29 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 30 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 31 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 32 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_MetBerryMaster::
# 33 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_MET_BERRY_MASTER
# 34 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 35 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 36 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMasterFirstTime::
# 37 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 38 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 39 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 40 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMasterEveryOtherTime::
# 41 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry2, MSGBOX_DEFAULT
# 42 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 43 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 44 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
# 45 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
# 46 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 47 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 48 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 49 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
# 50 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 51 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 52 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 53 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
# 54 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
# 55 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
# 56 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call Common_ShowEasyChatScreen
# 57 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 58 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 59 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_BerryMastersHouse_EventScript_GavePhrase
# 60 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_BerryMastersHouse_EventScript_CancelPhrase
# 61 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 62 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 63 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_CancelPhrase::
# 64 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
# 65 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 66 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 67 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 68 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 69 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GavePhrase::
# 70 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, NOT_SPECIAL_PHRASE, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 71 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_GREAT_BATTLE, Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
# 72 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_CHALLENGE_CONTEST, Route123_BerryMastersHouse_EventScript_GivePamtreBerry
# 73 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_OVERWHELMING_LATIAS, Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
# 74 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_COOL_LATIOS, Route123_BerryMastersHouse_EventScript_GiveDurinBerry
# 75 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_SUPER_HUSTLE, Route123_BerryMastersHouse_EventScript_GiveBelueBerry
# 76 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 77 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 78 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveNormalBerry::
# 79 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
# 80 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
# 81 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 82 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 83 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 84 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 85 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 86 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveSpelonBerry::
# 87 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 88 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 89 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_SPELON_BERRY
# 90 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 91 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_SPELON_BERRY
# 92 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 93 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 94 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 95 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GivePamtreBerry::
# 96 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 97 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 98 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_PAMTRE_BERRY
# 99 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 100 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_PAMTRE_BERRY
# 101 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 102 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 103 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 104 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveWatmelBerry::
# 105 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 106 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 107 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_WATMEL_BERRY
# 108 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 109 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_WATMEL_BERRY
# 110 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 111 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 112 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 113 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveDurinBerry::
# 114 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 115 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 116 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_DURIN_BERRY
# 117 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 118 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_DURIN_BERRY
# 119 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 120 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 121 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 122 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveBelueBerry::
# 123 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 124 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 125 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_BELUE_BERRY
# 126 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 127 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELUE_BERRY
# 128 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 129 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 130 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 131 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday::
# 132 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 133 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 134 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 135 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 136 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GaveBerry::
# 137 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
# 138 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 139 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 140 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
