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
	call_if_unset FLAG_MET_BERRY_MASTER, Route123_BerryMastersHouse_EventScript_BerryMasterFirstTime
# 21 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call_if_set FLAG_MET_BERRY_MASTER, Route123_BerryMastersHouse_EventScript_BerryMasterEveryOtherTime
# 22 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	@ msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 23 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 24 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 25 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 26 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 27 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 28 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
# 29 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
# 30 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_BERRIES
# 31 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, NUM_BERRY_MASTER_BERRIES_SKIPPED
# 32 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 33 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 34 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 35 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 36 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call_if_unset FLAG_MET_BERRY_MASTER, Route123_BerryMastersHouse_EventScript_MetBerryMaster
# 37 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 38 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 39 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 40 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_MetBerryMaster::
# 41 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_MET_BERRY_MASTER
# 42 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 43 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 44 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMasterFirstTime::
# 45 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry, MSGBOX_DEFAULT
# 46 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 47 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 48 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMasterEveryOtherTime::
# 49 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_YoureDeservingOfBerry2, MSGBOX_DEFAULT
# 50 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	return
# 51 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 52 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedBerryToday::
# 53 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_DoneForToday, MSGBOX_DEFAULT
# 54 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 55 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 56 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 57 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_BerryMastersWife::
# 58 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 59 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 60 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	dotimebasedevents
# 61 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_DAILY_BERRY_MASTERS_WIFE, Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday
# 62 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_HeardAGoodSayingLately, MSGBOX_DEFAULT
# 63 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GOOD_SAYING
# 64 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	call Common_ShowEasyChatScreen
# 65 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	lock
# 66 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	faceplayer
# 67 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_BerryMastersHouse_EventScript_GavePhrase
# 68 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_BerryMastersHouse_EventScript_CancelPhrase
# 69 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 70 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 71 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_CancelPhrase::
# 72 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_Ah, MSGBOX_DEFAULT
# 73 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 74 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 75 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 76 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 77 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GavePhrase::
# 78 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, NOT_SPECIAL_PHRASE, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 79 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_GREAT_BATTLE, Route123_BerryMastersHouse_EventScript_GiveSpelonBerry
# 80 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_CHALLENGE_CONTEST, Route123_BerryMastersHouse_EventScript_GivePamtreBerry
# 81 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_OVERWHELMING_LATIAS, Route123_BerryMastersHouse_EventScript_GiveWatmelBerry
# 82 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_COOL_LATIOS, Route123_BerryMastersHouse_EventScript_GiveDurinBerry
# 83 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PHRASE_SUPER_HUSTLE, Route123_BerryMastersHouse_EventScript_GiveBelueBerry
# 84 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 85 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 86 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveNormalBerry::
# 87 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_GoodSayingTakeThis, MSGBOX_DEFAULT
# 88 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	random NUM_BERRY_MASTER_WIFE_BERRIES
# 89 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 90 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem VAR_RESULT
# 91 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 92 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 93 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 94 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 95 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 96 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveSpelonBerry::
# 97 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_SPELON_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 98 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 99 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_SPELON_BERRY
# 100 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 101 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_SPELON_BERRY
# 102 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 103 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 104 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 105 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GivePamtreBerry::
# 106 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_PAMTRE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 107 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 108 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_PAMTRE_BERRY
# 109 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 110 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_PAMTRE_BERRY
# 111 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 112 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 113 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 114 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveWatmelBerry::
# 115 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_WATMEL_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 116 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 117 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_WATMEL_BERRY
# 118 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 119 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_WATMEL_BERRY
# 120 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 121 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 122 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 123 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveDurinBerry::
# 124 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DURIN_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 125 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 126 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_DURIN_BERRY
# 127 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 128 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_DURIN_BERRY
# 129 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 130 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 131 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 132 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GiveBelueBerry::
# 133 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_BELUE_BERRY, Route123_BerryMastersHouse_EventScript_GiveNormalBerry
# 134 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_InspirationalTakeThis, MSGBOX_DEFAULT
# 135 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	giveitem ITEM_BELUE_BERRY
# 136 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 137 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_RECEIVED_BELUE_BERRY
# 138 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	goto Route123_BerryMastersHouse_EventScript_GaveBerry
# 139 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 140 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 141 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_ReceivedWifeBerryToday::
# 142 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 143 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 144 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
# 145 "data//maps/Route123_BerryMastersHouse/scripts.pory"

# 146 "data//maps/Route123_BerryMastersHouse/scripts.pory"
Route123_BerryMastersHouse_EventScript_GaveBerry::
# 147 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	setflag FLAG_DAILY_BERRY_MASTERS_WIFE
# 148 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	msgbox Route123_BerryMastersHouse_Text_JoyNeverGoesOutOfMyLife, MSGBOX_DEFAULT
# 149 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	release
# 150 "data//maps/Route123_BerryMastersHouse/scripts.pory"
	end
