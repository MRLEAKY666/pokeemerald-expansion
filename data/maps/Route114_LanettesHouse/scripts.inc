# 1 "data//maps/Route114_LanettesHouse/scripts.pory"

# 2 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_MapScripts::
# 3 "data//maps/Route114_LanettesHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
# 4 "data//maps/Route114_LanettesHouse/scripts.pory"
	.byte 0
# 5 "data//maps/Route114_LanettesHouse/scripts.pory"

# 6 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_OnTransition:
# 7 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_LANDMARK_LANETTES_HOUSE
# 8 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 9 "data//maps/Route114_LanettesHouse/scripts.pory"

# 10 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Lanette::
# 11 "data//maps/Route114_LanettesHouse/scripts.pory"
	lock
# 12 "data//maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 13 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_BLANK_DISC_DELIVERED, Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc
# 14 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_ACCEPTED_BLANK_DISC_QUEST, Route114_LanettesHouse_EventScript_BlankDiscQuest
# 15 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
# 16 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 17 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
# 18 "data//maps/Route114_LanettesHouse/scripts.pory"
	givedecoration DECOR_LOTAD_DOLL
# 19 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
# 20 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_RECEIVED_DOLL_LANETTE
# 21 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_DevelopingBlankDisc, MSGBOX_DEFAULT
# 22 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_AskRunErrand, MSGBOX_YESNO
# 23 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_YouMustBeBusy
# 24 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ErrandStart, MSGBOX_DEFAULT
# 25 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_ACCEPTED_BLANK_DISC_QUEST
# 26 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
# 27 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 28 "data//maps/Route114_LanettesHouse/scripts.pory"

# 29 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_OfferAdvice::
# 30 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_DevelopingBlankDisc, MSGBOX_DEFAULT
# 31 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_AskRunErrand, MSGBOX_YESNO
# 32 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route114_LanettesHouse_EventScript_YouMustBeBusy
# 33 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ErrandStart, MSGBOX_DEFAULT
# 34 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_ACCEPTED_BLANK_DISC_QUEST
# 35 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
# 36 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 37 "data//maps/Route114_LanettesHouse/scripts.pory"

# 38 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_YouMustBeBusy::
# 39 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_YouMustBeBusy, MSGBOX_DEFAULT
# 40 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
# 41 "data//maps/Route114_LanettesHouse/scripts.pory"
	end

Route114_LanettesHouse_EventScript_BlankDiscQuest::
# 46 "data//maps/Route114_LanettesHouse/scripts.pory"
	checkitem ITEM_BLANK_DISC
# 47 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_BLANK_DISC_GIVEN, Route114_LanettesHouse_EventScript_BlankDiscQuest_4
Route114_LanettesHouse_EventScript_BlankDiscQuest_3:
# 116 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_7
Route114_LanettesHouse_EventScript_BlankDiscQuest_1:
# 118 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_BlankDiscQuest_2:
# 48 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_0
# 49 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_1
# 51 "data//maps/Route114_LanettesHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 52 "data//maps/Route114_LanettesHouse/scripts.pory"
	closemessage
# 53 "data//maps/Route114_LanettesHouse/scripts.pory"
	special Bag_ChooseTM
# 54 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitstate
# 55 "data//maps/Route114_LanettesHouse/scripts.pory"
	lock
# 56 "data//maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 57 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, 0
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_8
# 62 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM01
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 62 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM02
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 63 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM03
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 63 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM04
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 64 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM05
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 64 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM06
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 65 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM07
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 65 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM08
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_9
# 71 "data//maps/Route114_LanettesHouse/scripts.pory"
	removeitem VAR_ITEM_ID
# 72 "data//maps/Route114_LanettesHouse/scripts.pory"
	removeitem ITEM_BLANK_DISC
# 73 "data//maps/Route114_LanettesHouse/scripts.pory"
	bufferitemname STR_VAR_2, VAR_ITEM_ID
# 74 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_4
# 75 "data//maps/Route114_LanettesHouse/scripts.pory"
	playbgm MUS_EVOLUTION, FALSE
# 77 "data//maps/Route114_LanettesHouse/scripts.pory"
	closemessage
# 78 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 20
# 79 "data//maps/Route114_LanettesHouse/scripts.pory"
	getobjectfacingdirection LOCALID_LANETTESHOUSE_LANETTE, VAR_RESULT
# 80 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_28
# 84 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteToComputerSouth
Route114_LanettesHouse_EventScript_BlankDiscQuest_27:
# 86 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 87 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 30
# 88 "data//maps/Route114_LanettesHouse/scripts.pory"
	playse SE_DEX_SEARCH
# 89 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteUseComputer
# 90 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 91 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Common_Movement_ExclamationMark
# 92 "data//maps/Route114_LanettesHouse/scripts.pory"
	playse SE_PIN
# 93 "data//maps/Route114_LanettesHouse/scripts.pory"
	fadedefaultbgm
# 94 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitse
# 95 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 30
# 96 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_32
# 100 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteFromComputerSouth
Route114_LanettesHouse_EventScript_BlankDiscQuest_31:
# 102 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 103 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 30
# 104 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_5
# 105 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_36
# 109 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Common_Movement_WalkInPlaceDown
Route114_LanettesHouse_EventScript_BlankDiscQuest_35:
# 111 "data//maps/Route114_LanettesHouse/scripts.pory"
	giveitem VAR_ITEM_ID, 2
# 112 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_6
# 113 "data//maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_BLANK_DISC_DELIVERED
	goto Route114_LanettesHouse_EventScript_BlankDiscQuest_1

Route114_LanettesHouse_EventScript_BlankDiscQuest_4:
# 47 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route114_LanettesHouse_EventScript_BlankDiscQuest_2
	goto Route114_LanettesHouse_EventScript_BlankDiscQuest_3

Route114_LanettesHouse_EventScript_BlankDiscQuest_8:
# 58 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_2
# 59 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_BlankDiscQuest_9:
# 66 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_3
# 67 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_BlankDiscQuest_28:
# 81 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteToComputerNorth
	goto Route114_LanettesHouse_EventScript_BlankDiscQuest_27

Route114_LanettesHouse_EventScript_BlankDiscQuest_32:
# 97 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteFromComputerNorth
	goto Route114_LanettesHouse_EventScript_BlankDiscQuest_31

Route114_LanettesHouse_EventScript_BlankDiscQuest_36:
# 106 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Common_Movement_WalkInPlaceUp
	goto Route114_LanettesHouse_EventScript_BlankDiscQuest_35


Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc::
# 123 "data//maps/Route114_LanettesHouse/scripts.pory"
	checkitem ITEM_BLANK_DISC
# 124 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_2
# 191 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_7, MSGBOX_DEFAULT
Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_1:
# 193 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_2:
# 125 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_0, MSGBOX_YESNO
# 126 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_5
# 187 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_6, MSGBOX_DEFAULT
	goto Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_1

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_5:
# 127 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_1
# 129 "data//maps/Route114_LanettesHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 130 "data//maps/Route114_LanettesHouse/scripts.pory"
	closemessage
# 131 "data//maps/Route114_LanettesHouse/scripts.pory"
	special Bag_ChooseTM
# 132 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitstate
# 133 "data//maps/Route114_LanettesHouse/scripts.pory"
	lock
# 134 "data//maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 135 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, 0
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_9
# 140 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM01
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 140 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM02
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 141 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM03
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 141 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM04
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 142 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM05
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 142 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM06
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 143 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM07
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 143 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_ITEM_ID, ITEM_HM08
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10
# 149 "data//maps/Route114_LanettesHouse/scripts.pory"
	removeitem VAR_ITEM_ID
# 150 "data//maps/Route114_LanettesHouse/scripts.pory"
	removeitem ITEM_BLANK_DISC
# 151 "data//maps/Route114_LanettesHouse/scripts.pory"
	bufferitemname STR_VAR_2, VAR_ITEM_ID
# 152 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_3
# 154 "data//maps/Route114_LanettesHouse/scripts.pory"
	closemessage
# 155 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 20
# 156 "data//maps/Route114_LanettesHouse/scripts.pory"
	getobjectfacingdirection LOCALID_LANETTESHOUSE_LANETTE, VAR_RESULT
# 157 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_29
# 161 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteToComputerSouth
Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_28:
# 163 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 164 "data//maps/Route114_LanettesHouse/scripts.pory"
	playse SE_DEX_SEARCH
# 165 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteUseComputer
# 166 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 167 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 30
# 168 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_33
# 172 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteFromComputerSouth
Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_32:
# 174 "data//maps/Route114_LanettesHouse/scripts.pory"
	waitmovement LOCALID_LANETTESHOUSE_LANETTE
# 175 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay 30
# 176 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_4
# 177 "data//maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_37
# 181 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Common_Movement_WalkInPlaceDown
Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_36:
# 183 "data//maps/Route114_LanettesHouse/scripts.pory"
	giveitem VAR_ITEM_ID, 2
# 184 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_5
	goto Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_1

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_9:
# 136 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_1
# 137 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_10:
# 144 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_2
# 145 "data//maps/Route114_LanettesHouse/scripts.pory"
	release
	end

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_29:
# 158 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteToComputerNorth
	goto Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_28

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_33:
# 169 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Route114_LanettesHouse_Movement_LanetteFromComputerNorth
	goto Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_32

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_37:
# 178 "data//maps/Route114_LanettesHouse/scripts.pory"
	applymovement LOCALID_LANETTESHOUSE_LANETTE, Common_Movement_WalkInPlaceUp
	goto Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_36


# 197 "data//maps/Route114_LanettesHouse/scripts.pory"

# 198 "data//maps/Route114_LanettesHouse/scripts.pory"

# 199 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Notebook::
# 200 "data//maps/Route114_LanettesHouse/scripts.pory"
	lockall
# 201 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
# 202 "data//maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
# 203 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
# 204 "data//maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 205 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 206 "data//maps/Route114_LanettesHouse/scripts.pory"

# 207 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage2::
# 208 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
# 209 "data//maps/Route114_LanettesHouse/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
# 210 "data//maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 211 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 212 "data//maps/Route114_LanettesHouse/scripts.pory"

# 213 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage3::
# 214 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
# 215 "data//maps/Route114_LanettesHouse/scripts.pory"
	return
# 216 "data//maps/Route114_LanettesHouse/scripts.pory"

# 217 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_PC::
# 218 "data//maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
# 219 "data//maps/Route114_LanettesHouse/scripts.pory"
	end
# 220 "data//maps/Route114_LanettesHouse/scripts.pory"

# 221 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
# 222 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "LANETTE: Oh! {PLAYER}{KUN}!\p"
# 223 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "I'm sorry everything is so cluttered…\n"
# 224 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "When I get engrossed in research,\l"
# 225 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "things end up this way…\p"
# 226 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "This is embarrassing… Please keep\n"
# 227 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "this a secret in exchange for this.$"
# 228 "data//maps/Route114_LanettesHouse/scripts.pory"

# 229 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_DevelopingBlankDisc:
# 230 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Thanks for keeping my secret…\p"
# 231 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "The truth is that I've been working\n"
# 232 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "with DEVON CORP on a new system.\p"
# 233 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "We have devised a way to duplicate TMs\n"
# 234 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "using the PC.\p"
# 235 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "We've ironed out most of the bugs,\n"
# 236 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "but to test it I need an item that\l"
# 237 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "DEVON has been developing…$"
# 238 "data//maps/Route114_LanettesHouse/scripts.pory"

# 239 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_AskRunErrand:
# 240 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Would you pick up an item called\n"
# 241 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "BLANK DISC from DEVON CORP and\l"
# 242 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "deliver it to me here?$"
# 243 "data//maps/Route114_LanettesHouse/scripts.pory"

# 244 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_YouMustBeBusy:
# 245 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "I get it, you're a busy trainer on a\n"
# 246 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "long adventure!\p"
# 247 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Well, when you have a break, let me\n"
# 248 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "know if you can help.$"
# 249 "data//maps/Route114_LanettesHouse/scripts.pory"

# 250 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ErrandStart:
# 251 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Oh, thank you!\p"
# 252 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "We can test the system by copying\n"
# 253 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "one of your TMs!\p"
# 254 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "You can keep them both when we're\n"
# 255 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "done.\p"
# 256 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "I'm no trainer, so they're not of much\n"
# 257 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "use to me anyway…$"
# 258 "data//maps/Route114_LanettesHouse/scripts.pory"

# 259 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage1:
# 260 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "It's LANETTE's research notes.\n"
# 261 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "There's information about BOXES.\p"
# 262 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Design BOXES to hold 30 POKéMON each.\p"
# 263 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Each TRAINER should be able to store\n"
# 264 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "420 POKéMON on the PC system.\p"
# 265 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 266 "data//maps/Route114_LanettesHouse/scripts.pory"

# 267 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage2:
# 268 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "A marking system should be added to\n"
# 269 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "make POKéMON easier to organize.\p"
# 270 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "The name and wallpaper design of each\n"
# 271 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "BOX will be made changeable to please\l"
# 272 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "the stored POKéMON.\p"
# 273 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 274 "data//maps/Route114_LanettesHouse/scripts.pory"

# 275 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage3:
# 276 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "When storing a POKéMON, it should be\n"
# 277 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "sent to the BOX inspected last.\p"
# 278 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "If that BOX is full, the received\n"
# 279 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "POKéMON is stored in the next BOX.\p"
# 280 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "In other words, when a BOX is examined,\n"
# 281 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "it is automatically selected as the BOX\l"
# 282 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "to which POKéMON are sent.$"
# 283 "data//maps/Route114_LanettesHouse/scripts.pory"

# 284 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ClosedTheNotebook:
# 285 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "{PLAYER} closed the notebook.$"
# 286 "data//maps/Route114_LanettesHouse/scripts.pory"

# 287 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EmailFromBill:
# 288 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "There's an e-mail from someone on\n"
# 289 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "the PC.\p"
# 290 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“… … … … … … …\p"
# 291 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“Your Storage System offers more\n"
# 292 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "convenience than mine.\p"
# 293 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“It has a lot of user-friendly features\n"
# 294 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "that make it fun and useful, too.\p"
# 295 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“It makes me proud that I played\n"
# 296 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "a part in its development.\p"
# 297 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“Here's hoping that you'll continue\n"
# 298 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "research in Storage Systems.\p"
# 299 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "“From BILL\n"
# 300 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "… … … … … … … …”$"
# 301 "data//maps/Route114_LanettesHouse/scripts.pory"

# 302 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Movement_LanetteToComputerNorth:
# 303 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 304 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 305 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 306 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 307 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 308 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 309 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 310 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 311 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 312 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 313 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 314 "data//maps/Route114_LanettesHouse/scripts.pory"
	step_end
# 315 "data//maps/Route114_LanettesHouse/scripts.pory"

# 316 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Movement_LanetteToComputerSouth:
# 317 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 318 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 319 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 320 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 321 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 322 "data//maps/Route114_LanettesHouse/scripts.pory"
	step_end
# 323 "data//maps/Route114_LanettesHouse/scripts.pory"

# 324 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Movement_LanetteUseComputer:
# 325 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 326 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay_16
# 327 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 328 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 329 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay_16
# 330 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 331 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay_16
# 332 "data//maps/Route114_LanettesHouse/scripts.pory"
	step_end
# 333 "data//maps/Route114_LanettesHouse/scripts.pory"

# 334 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Movement_LanetteFromComputerNorth:
# 335 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_right
# 336 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 337 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 338 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 339 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 340 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 341 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 342 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 343 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 344 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_up
# 345 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay_4
# 346 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_up
# 347 "data//maps/Route114_LanettesHouse/scripts.pory"
	step_end
# 348 "data//maps/Route114_LanettesHouse/scripts.pory"

# 349 "data//maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Movement_LanetteFromComputerSouth:
# 350 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 351 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_left
# 352 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 353 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_down
# 354 "data//maps/Route114_LanettesHouse/scripts.pory"
	delay_4
# 355 "data//maps/Route114_LanettesHouse/scripts.pory"
	walk_in_place_down
# 356 "data//maps/Route114_LanettesHouse/scripts.pory"
	step_end

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_0:
# 48 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Oh!\l"
	.string "You brought the BLANK DISC\n"
	.string "from DEVON CORP!\p"
	.string "Let's give it a try…$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_1:
# 49 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Which of your TMs should we copy?$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_2:
# 58 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Oh, you don't want to risk losing one of\n"
	.string "your TMs?\p"
	.string "Even though I'm quite sure the system\n"
	.string "is safe to use, I understand.\p"
	.string "If you come across a TM you aren't\n"
	.string "worried about losing please let me try\l"
	.string "to copy it!$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_3:
# 66 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Ah, this is an HM…\p"
	.string "Unfortunately, my system is only\n"
	.string "capable of copying TMs…\p"
	.string "Come back with a TM so we can test the\n"
	.string "BLANK DISC!$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_4:
# 74 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Ah, {STR_VAR_2}.\n"
	.string "This will work perfectly.\p"
	.string "Wait right here while I attempt to run\n"
	.string "the program.$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_5:
# 104 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "The BLANK DISC worked perfectly!\p"
	.string "I was able to copy the POKéMON move\n"
	.string "data from your TM onto the BLANK DISC.\p"
	.string "See for yourself!$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_6:
# 112 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Excellent.\p"
	.string "If you find another BLANK DISC, come\n"
	.string "see me.\p"
	.string "I'll copy TMs for you anytime!$"

Route114_LanettesHouse_EventScript_BlankDiscQuest_Text_7:
# 116 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Hi, {PLAYER}!\n"
	.string "How has your adventure been going?\p"
	.string "Let me know when you've retrieved the\n"
	.string "BLANK DISC from DEVON CORP.\p"
	.string "I can test it by copying one of your\n"
	.string "TMs!$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_0:
# 125 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "LANETTE: Hello, {PLAYER}.\p"
	.string "Are you here to copy another TM using\n"
	.string "my new system?$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_1:
# 136 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Oh, you changed your mind?\p"
	.string "Well if you want to copy a TM onto a\n"
	.string "BLANK DISC, come back and see me.$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_2:
# 144 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Ah, this is an HM…\p"
	.string "Unfortunately, my system is only\n"
	.string "capable of copying TMs…\p"
	.string "So if you want to copy a TM onto a BLANK\n"
	.string "DISC, come back and see me.$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_3:
# 152 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Ah, {STR_VAR_2}.\n"
	.string "Perfect.\p"
	.string "Wait right here while I run the program.$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_4:
# 176 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "I was able to copy the POKéMON move\n"
	.string "data from your TM onto the BLANK DISC.\p"
	.string "Here is your original, and the copy!$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_5:
# 184 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "If you find another BLANK DISC, come\n"
	.string "see me.\p"
	.string "I'll copy TMs for you anytime!$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_6:
# 187 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "Then may I offer advice about my\n"
	.string "POKéMON Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_EventScript_LanetteAlreadyDeliveredDisc_Text_7:
# 191 "data//maps/Route114_LanettesHouse/scripts.pory"
	.string "LANETTE: If you have a BLANK DISC, I'd\n"
	.string "be happy to copy another TM for you.\p"
	.string "And may I offer advice about my\n"
	.string "POKéMON Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"
