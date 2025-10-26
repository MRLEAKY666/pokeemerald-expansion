# 1 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 2 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_MapScripts::
# 3 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.byte 0
# 4 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 5 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Rydel::
# 6 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	lock
# 7 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	faceplayer
# 8 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 1, MauvilleCity_BikeShop_EventScript_HurryAndDeliver
# 9 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 2, MauvilleCity_BikeShop_EventScript_FinishedDelivering
# 10 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	@ goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
# 11 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 3, MauvilleCity_BikeShop_EventScript_BikeShopMenu
# 12 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_BIKE_QUEST_STATE, 4, MauvilleCity_BikeShop_EventScript_BikeQuestComplete
# 13 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
# 14 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
# 15 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 16 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
# 17 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
# 18 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 19 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 20 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HurryAndDeliver::
# 21 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HurryAndDeliver, MSGBOX_DEFAULT
# 22 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 23 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end

MauvilleCity_BikeShop_EventScript_BikeQuestComplete::
# 27 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeQuestComplete_Text_0
# 28 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
	end


MauvilleCity_BikeShop_EventScript_FinishedDelivering::
# 33 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_FinishedDelivering, MSGBOX_DEFAULT
# 34 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_FinishedDelivering_2
# 46 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_FinishedDelivering_3
# 54 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 2
	goto_if_eq MauvilleCity_BikeShop_EventScript_FinishedDelivering_4
# 60 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 3
	goto_if_eq MauvilleCity_BikeShop_EventScript_FinishedDelivering_5
# 66 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 4
	goto_if_eq MauvilleCity_BikeShop_EventScript_FinishedDelivering_6
# 73 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_12, MSGBOX_DEFAULT
# 74 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 75 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_13, MSGBOX_DEFAULT
# 76 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_RYDEL_DEBT, 500
MauvilleCity_BikeShop_EventScript_FinishedDelivering_1:
# 78 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_WHICH_BIKE
# 79 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_BIKE_QUEST_STATE, 3
# 80 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
	end

MauvilleCity_BikeShop_EventScript_FinishedDelivering_2:
# 35 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_0, MSGBOX_DEFAULT
# 36 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 37 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_1, MSGBOX_DEFAULT
# 38 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	closemessage
# 39 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	delay 20
# 40 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	applymovement LOCALID_RYDEL, Common_Movement_FaceAwayPlayer
# 41 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	delay 60
# 42 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	applymovement LOCALID_RYDEL, Common_Movement_FacePlayer
# 43 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	delay 20
# 44 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_2, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_FinishedDelivering_1

MauvilleCity_BikeShop_EventScript_FinishedDelivering_3:
# 47 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_3, MSGBOX_DEFAULT
# 48 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 49 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_4, MSGBOX_DEFAULT
# 50 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	closemessage
# 51 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	delay 40
# 52 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_5, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_FinishedDelivering_1

MauvilleCity_BikeShop_EventScript_FinishedDelivering_4:
# 55 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_6, MSGBOX_DEFAULT
# 56 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 57 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_7, MSGBOX_DEFAULT
# 58 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_RYDEL_DEBT, 50
	goto MauvilleCity_BikeShop_EventScript_FinishedDelivering_1

MauvilleCity_BikeShop_EventScript_FinishedDelivering_5:
# 61 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_8, MSGBOX_DEFAULT
# 62 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 63 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_9, MSGBOX_DEFAULT
# 64 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_RYDEL_DEBT, 100
	goto MauvilleCity_BikeShop_EventScript_FinishedDelivering_1

MauvilleCity_BikeShop_EventScript_FinishedDelivering_6:
# 67 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_10, MSGBOX_DEFAULT
# 68 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 69 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_11, MSGBOX_DEFAULT
# 70 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_RYDEL_DEBT, 250
	goto MauvilleCity_BikeShop_EventScript_FinishedDelivering_1


MauvilleCity_BikeShop_EventScript_BikeShopMenu::
# 85 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	bufferitemname STR_VAR_3, ITEM_ACRO_BIKE
# 86 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_2
# 98 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 1
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_3
# 98 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_3
# 103 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 2
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_4
# 103 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 100
	goto_if_lt MauvilleCity_BikeShop_EventScript_BikeShopMenu_4
# 109 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 3
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_5
# 109 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 250
	goto_if_lt MauvilleCity_BikeShop_EventScript_BikeShopMenu_5
# 115 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 4
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_6
# 115 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 500
	goto_if_lt MauvilleCity_BikeShop_EventScript_BikeShopMenu_6
# 122 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_10, MSGBOX_DEFAULT
# 123 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5, 1
# 124 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_7, 2
# 125 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
MauvilleCity_BikeShop_EventScript_BikeShopMenu_1:
# 127 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_11, MSGBOX_DEFAULT
# 128 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultistack 15, 0, FALSE, 3, TRUE, 0, DYN_MULTICHOICE_CB_NONE
# 129 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 130 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_BikeShopMenu_23
# 138 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_BikeShopMenu_24
# 174 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_BikeShopMenu_25
MauvilleCity_BikeShop_EventScript_BikeShopMenu_21:
# 180 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
	end

MauvilleCity_BikeShop_EventScript_BikeShopMenu_2:
# 87 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_0, MSGBOX_DEFAULT
# 88 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_WHICH_BIKE, MauvilleCity_BikeShop_EventScript_BikeShopMenu_27
# 92 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	bufferitemname STR_VAR_3, ITEM_MACH_BIKE
MauvilleCity_BikeShop_EventScript_BikeShopMenu_26:
# 94 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_1, 0
# 95 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_2, 1
# 96 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_1

MauvilleCity_BikeShop_EventScript_BikeShopMenu_3:
# 99 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_4, MSGBOX_DEFAULT
# 100 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5, 1
# 101 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_1

MauvilleCity_BikeShop_EventScript_BikeShopMenu_4:
# 104 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_6, MSGBOX_DEFAULT
# 105 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5, 1
# 106 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_7, 2
# 107 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_1

MauvilleCity_BikeShop_EventScript_BikeShopMenu_5:
# 110 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_8, MSGBOX_DEFAULT
# 111 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5, 1
# 112 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_7, 2
# 113 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_1

MauvilleCity_BikeShop_EventScript_BikeShopMenu_6:
# 116 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_9, MSGBOX_DEFAULT
# 117 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5, 1
# 118 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_7, 2
# 119 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 3
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_1

MauvilleCity_BikeShop_EventScript_BikeShopMenu_23:
# 131 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
# 132 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_30
# 136 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_KeepBike
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_24:
# 139 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_12
# 140 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_BIKE_DELIVERY_COUNTER, 1
	goto_if_le MauvilleCity_BikeShop_EventScript_BikeShopMenu_33
# 140 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 0
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_33
# 172 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_18
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_25:
# 175 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_19, MSGBOX_DEFAULT
# 176 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_27:
# 89 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	bufferitemname STR_VAR_3, ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_26

MauvilleCity_BikeShop_EventScript_BikeShopMenu_30:
# 133 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_33:
# 141 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	showmoneybox 0, 0
# 142 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_13, MSGBOX_YESNO
# 143 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_38
# 167 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_17
# 168 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	hidemoneybox
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_38:
# 144 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkmoney 1000000
# 145 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopMenu_41
# 162 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_16
# 163 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	hidemoneybox
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_41:
# 146 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removemoney 1000000
# 147 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_WHICH_BIKE, MauvilleCity_BikeShop_EventScript_BikeShopMenu_45
# 151 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_TEMP_1, ITEM_MACH_BIKE
MauvilleCity_BikeShop_EventScript_BikeShopMenu_44:
# 153 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	updatemoneybox
# 154 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	playse SE_SHOP
# 155 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitse
# 156 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_14
# 157 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem VAR_TEMP_1
# 158 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_15
# 159 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_BIKE_QUEST_STATE, 4
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_21

MauvilleCity_BikeShop_EventScript_BikeShopMenu_45:
# 148 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_TEMP_1, ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_BikeShopMenu_44


MauvilleCity_BikeShop_EventScript_PayDebtMenu::
# 185 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_RYDEL_DEBT
# 186 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_unset FLAG_TEMP_1, MauvilleCity_BikeShop_EventScript_PayDebtMenu_2
# 197 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_2, MSGBOX_DEFAULT
MauvilleCity_BikeShop_EventScript_PayDebtMenu_1:
# 199 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_3, 5
# 200 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3, 6
# 201 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 1
	goto_if_le MauvilleCity_BikeShop_EventScript_PayDebtMenu_6
# 204 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 10
	goto_if_le MauvilleCity_BikeShop_EventScript_PayDebtMenu_7
# 208 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 100
	goto_if_le MauvilleCity_BikeShop_EventScript_PayDebtMenu_8
# 214 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_4, 0
# 215 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_5, 1
# 216 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_6, 2
MauvilleCity_BikeShop_EventScript_PayDebtMenu_5:
# 219 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultistack 15, 0, FALSE, 5, TRUE, 7, DYN_MULTICHOICE_CB_NONE
# 220 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 221 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_PayDebtMenu_19
# 241 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_PayDebtMenu_20
# 261 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_PayDebtMenu_21
# 281 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 5, MauvilleCity_BikeShop_EventScript_PayDebtMenu_22
# 300 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 6, MauvilleCity_BikeShop_EventScript_PayDebtMenu_23
# 302 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 127, MauvilleCity_BikeShop_EventScript_PayDebtMenu_24
MauvilleCity_BikeShop_EventScript_PayDebtMenu_17:
# 305 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	clearflag FLAG_TEMP_1
# 306 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	hidemoneybox
# 307 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
	end

MauvilleCity_BikeShop_EventScript_PayDebtMenu_2:
# 187 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	showmoneybox 0, 0
# 188 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RYDEL_DEBT, 1
	goto_if_le MauvilleCity_BikeShop_EventScript_PayDebtMenu_14
# 192 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_1, MSGBOX_DEFAULT
MauvilleCity_BikeShop_EventScript_PayDebtMenu_13:
# 194 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_TEMP_1
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_1

MauvilleCity_BikeShop_EventScript_PayDebtMenu_6:
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_5

MauvilleCity_BikeShop_EventScript_PayDebtMenu_7:
# 205 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_4, 0
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_5

MauvilleCity_BikeShop_EventScript_PayDebtMenu_8:
# 209 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_4, 0
# 210 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	dynmultipush MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_5, 1
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_5

MauvilleCity_BikeShop_EventScript_PayDebtMenu_14:
# 189 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_0, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_13

MauvilleCity_BikeShop_EventScript_PayDebtMenu_19:
# 222 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_7, MSGBOX_YESNO
# 223 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_25
# 239 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_20:
# 242 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_10, MSGBOX_YESNO
# 243 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_28
# 259 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_21:
# 262 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_11, MSGBOX_YESNO
# 263 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_31
# 279 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_22:
# 282 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_12, MSGBOX_YESNO
# 283 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_34
# 298 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_23:
# 301 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_14, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_24:
# 303 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_14, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_25:
# 224 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkmoney 1000
# 225 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_37
# 234 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_9, MSGBOX_DEFAULT
# 235 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_28:
# 244 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkmoney 10000
# 245 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_40
# 254 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_9, MSGBOX_DEFAULT
# 255 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_31:
# 264 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkmoney 100000
# 265 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_43
# 274 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_9, MSGBOX_DEFAULT
# 275 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_34:
# 284 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	payoffrydeldebt
# 285 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_PayDebtMenu_46
# 293 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_9, MSGBOX_DEFAULT
# 294 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_37:
# 226 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removemoney 1000
# 227 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	addvar VAR_RYDEL_DEBT, -1
# 228 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	playse SE_SHOP
# 229 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	updatemoneybox
# 230 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitse
# 231 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_8, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_40:
# 246 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removemoney 10000
# 247 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	addvar VAR_RYDEL_DEBT, -10
# 248 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	playse SE_SHOP
# 249 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	updatemoneybox
# 250 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitse
# 251 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_8, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_43:
# 266 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removemoney 100000
# 267 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	addvar VAR_RYDEL_DEBT, -100
# 268 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	playse SE_SHOP
# 269 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	updatemoneybox
# 270 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitse
# 271 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_8, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17

MauvilleCity_BikeShop_EventScript_PayDebtMenu_46:
# 286 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	playse SE_SHOP
# 287 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	updatemoneybox
# 288 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitse
# 289 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_RYDEL_DEBT, 0
# 290 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_13, MSGBOX_DEFAULT
	goto MauvilleCity_BikeShop_EventScript_PayDebtMenu_17


# 311 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 312 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 313 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SkipGreeting::
# 314 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 315 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
# 316 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
# 317 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 318 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 319 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseBike::
# 320 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
# 321 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 322 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 21, 8, MULTI_BIKE, TRUE
# 323 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 324 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
# 325 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
# 326 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 327 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 328 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseBikeReplacement::
# 329 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_BikeDelivery, MSGBOX_DEFAULT
# 330 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_BikeDeliveryYesNo, MSGBOX_YESNO
# 331 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_StartDeliveryQuest
# 332 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_BikeDeliveryDeclined, MSGBOX_DEFAULT
# 333 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 334 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 335 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DeliveryInstructions, MSGBOX_DEFAULT
# 336 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 337 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 338 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 339 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_StartDeliveryQuest::
# 340 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_BikeDeliveryAccepted, MSGBOX_DEFAULT
# 341 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 342 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 343 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DeliveryInstructions, MSGBOX_DEFAULT
# 344 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 345 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 346 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 347 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_NotFar::
# 348 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_DECLINED_BIKE
# 349 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
# 350 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 351 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 352 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 353 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_YesFar::
# 354 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_RECEIVED_BIKE
# 355 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setvar VAR_BIKE_QUEST_STATE, 1
# 356 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseBikeReplacement
# 357 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 358 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 359 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetMachBike::
# 360 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
# 361 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 362 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 363 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 364 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 365 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 366 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetAcroBike::
# 367 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
# 368 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 369 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 370 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 371 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 372 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 373 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
# 374 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
# 375 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	special SwapRegisteredBike
# 376 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 377 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 378 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 379 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
# 380 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
# 381 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
# 382 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
# 383 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 384 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 385 "data//maps/MauvilleCity_BikeShop/scripts.pory"
@ If the player does not have a bike on them Rydel assumes its stored in the PC
# 386 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchBikes::
# 387 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
# 388 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_unset FLAG_WHICH_BIKE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
# 389 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_WHICH_BIKE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
# 390 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 391 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 392 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 393 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_KeepBike::
# 394 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
# 395 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 396 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 397 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 398 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
# 399 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 400 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_ACRO_BIKE
# 401 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_BikeShop_EventScript_OhYourBikeIsInPC
# 402 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
# 403 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removeitem ITEM_ACRO_BIKE
# 404 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 405 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_WHICH_BIKE 
# 406 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 407 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 408 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 409 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_OhYourBikeIsInPC::
# 410 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
# 411 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 412 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 413 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 414 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
# 415 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 416 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_MACH_BIKE
# 417 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_BikeShop_EventScript_OhYourBikeIsInPC
# 418 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
# 419 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	removeitem ITEM_MACH_BIKE
# 420 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 421 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	clearflag FLAG_WHICH_BIKE 
# 422 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 423 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 424 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 425 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Assistant::
# 426 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
# 427 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 428 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 429 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
# 430 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
# 431 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 432 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 433 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 434 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 435 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
# 436 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
# 437 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 438 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
# 439 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
# 440 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
# 441 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 442 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 443 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 444 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 445 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToRide::
# 446 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
# 447 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 448 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 449 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 450 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 451 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToTurn::
# 452 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
# 453 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 454 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 455 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 456 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 457 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SandySlopes::
# 458 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_SandySlopes
# 459 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 460 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 461 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 462 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 463 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
# 464 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 465 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 466 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 467 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
# 468 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
# 469 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 470 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 471 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 472 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 473 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
# 474 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
# 475 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 476 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
# 477 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
# 478 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
# 479 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 480 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 481 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 482 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 483 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Wheelies::
# 484 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Wheelies
# 485 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 486 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 487 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 488 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 489 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_BunnyHops::
# 490 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_BunnyHops
# 491 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 492 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 493 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 494 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 495 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Jumps::
# 496 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Jumps
# 497 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 498 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 499 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 500 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 501 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
# 502 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 503 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 504 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 505 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_FinishedDelivering:
# 506 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: So you delivered the BIKE!$"
# 507 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 508 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HurryAndDeliver:
# 509 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Hurry up and deliver that\n"
# 510 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "BIKE already!\p"
# 511 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "My customer lives in VERDANTURF TOWN\n"
# 512 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "in the easternmost house.\p"
# 513 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If I'd known you were going to take\n"
# 514 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "THIS long, I wouldn't have asked!$"
# 515 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 516 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_RydelGreeting:
# 517 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, well, what have we here?\n"
# 518 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A most energetic customer!\p"
# 519 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Me? You may call me RYDEL.\n"
# 520 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm the owner of this cycle shop.$"
# 521 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 522 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
# 523 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Your RUNNING SHOES…\n"
# 524 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They're awfully filthy.\p"
# 525 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Did you come from far away?$"
# 526 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 527 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
# 528 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Is that right?\p"
# 529 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Then, I guess you have no need for\n"
# 530 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "any of my BIKES.$"
# 531 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 532 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
# 533 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Hm, hm… … … … …\p"
# 534 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You're saying that you came all this\n"
# 535 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "way from LITTLEROOT?\p"
# 536 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "My goodness!\n"
# 537 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "That's ridiculously far!\p"
# 538 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you had one of my BIKES, you could\n"
# 539 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "go anywhere easily while feeling the\l"
# 540 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "gentle caress of the wind!\p"
# 541 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll tell you what!\n"
# 542 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll give you a BIKE!\p"
# 543 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, wait a second!\p"
# 544 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I forgot to tell you that there are\n"
# 545 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "two kinds of BIKES!\p"
# 546 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They are the MACH BIKE and\n"
# 547 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the ACRO BIKE!\p"
# 548 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The MACH BIKE is for cyclists who want\n"
# 549 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to feel the wind with their bodies!\p"
# 550 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And an ACRO BIKE is for those who\n"
# 551 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "prefer technical rides!\p"
# 552 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm a real sweetheart, so you can\n"
# 553 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "have whichever one you like!\p"
# 554 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which one will you choose?$"
# 555 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 556 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BikeDelivery:
# 557 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Hm, hm… … … … …\p"
# 558 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You're saying that you came all this\n"
# 559 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "way from LITTLEROOT?\p"
# 560 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "My goodness!\n"
# 561 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "That's ridiculously far!\p"
# 562 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you had one of my BIKES, you could\n"
# 563 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "go anywhere easily while feeling the\l"
# 564 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "gentle caress of the wind!\p"
# 565 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll tell you what!\l"
# 566 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you deliver this ACRO BIKE to my\n"
# 567 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "customer in VERDANTURF TOWN, I'll give\l"
# 568 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "you a BIKE as well!$"
# 569 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 570 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BikeDeliveryYesNo:
# 571 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "How about it?$"
# 572 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 573 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BikeDeliveryDeclined:
# 574 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh come on, my BIKES are so fast,\n"
# 575 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "it will only take a second to ride\l"
# 576 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "over to VERDANTURF!$"
# 577 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 578 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BikeDeliveryAccepted:
# 579 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Great! My BIKES are so fast,\n"
# 580 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "it will only take a second to ride over\l"
# 581 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to VERDANTURF!$"
# 582 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 583 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_DeliveryInstructions:
# 584 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The customer lives in VERDANTURF TOWN\n"
# 585 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "in the easternmost house.\p"
# 586 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Let me know when it's been delivered,\n"
# 587 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll give you one for yourself!$"
# 588 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 589 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseMachBike:
# 590 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the MACH BIKE.$"
# 591 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 592 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseAcroBike:
# 593 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the ACRO BIKE.$"
# 594 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 595 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
# 596 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: If you get the urge to switch\n"
# 597 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "BIKES, just come see me!$"
# 598 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 599 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_WantToSwitchBikes:
# 600 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Oh? Were you thinking about\n"
# 601 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "switching BIKES?$"
# 602 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 603 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_IllSwitchBikes:
# 604 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Okay, no problem!\n"
# 605 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll switch BIKES for you!$"
# 606 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 607 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
# 608 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} got the MACH BIKE exchanged\n"
# 609 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "for an ACRO BIKE.$"
# 610 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 611 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
# 612 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
# 613 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "for a MACH BIKE.$"
# 614 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 615 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HappyYouLikeIt:
# 616 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Good, good!\n"
# 617 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm happy that you like it!$"
# 618 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 619 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
# 620 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh? What happened to that BIKE\n"
# 621 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I gave you?\p"
# 622 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, I get it, you stored it using your PC.\p"
# 623 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, take it out of PC storage,\n"
# 624 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and I'll be happy to exchange it!\p"
# 625 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "May the wind always be at your back\n"
# 626 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "on your adventure!$"
# 627 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 628 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HandbooksAreInBack:
# 629 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm learning about BIKES while\n"
# 630 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I work here.\p"
# 631 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you need advice on how to ride your\n"
# 632 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "BIKE, there're a couple handbooks in\l"
# 633 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the back.$"
# 634 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 635 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
# 636 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the MACH BIKE.\p"
# 637 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 638 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 639 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToRideMachBike:
# 640 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A BIKE moves in the direction that\n"
# 641 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the + Control Pad is pressed.\p"
# 642 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It will speed up once it gets rolling.\p"
# 643 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "To stop, release the + Control Pad.\n"
# 644 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The BIKE will slow to a stop.\p"
# 645 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 646 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 647 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToTurnMachBike:
# 648 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A MACH BIKE is speedy, but it can't\n"
# 649 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "stop very quickly.\p"
# 650 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It gets a little tricky to get around\n"
# 651 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "a corner.\p"
# 652 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Release the + Control Pad a little\n"
# 653 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "before the corner and slow down.\p"
# 654 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 655 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 656 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_SandySlopes:
# 657 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "There are small sandy slopes\n"
# 658 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "throughout the HOENN region.\p"
# 659 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The loose, crumbly sand makes it\n"
# 660 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "impossible to climb normally.\p"
# 661 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "But if you have a MACH BIKE, you can\n"
# 662 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "zip up a sandy slope.\p"
# 663 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 664 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 665 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
# 666 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the ACRO BIKE.\p"
# 667 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 668 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 669 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Wheelies:
# 670 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button while riding,\n"
# 671 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and the front wheel lifts up.\p"
# 672 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can zip around with the front\n"
# 673 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "wheel up using the + Control Pad.\p"
# 674 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a wheelie.\p"
# 675 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 676 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 677 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BunnyHops:
# 678 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Keeping the B Button pressed,\n"
# 679 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "your BIKE can hop on the spot.\p"
# 680 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a bunny hop.\p"
# 681 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can ride while hopping, too.\p"
# 682 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 683 "data//maps/MauvilleCity_BikeShop/scripts.pory"

# 684 "data//maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Jumps:
# 685 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button and the + Control\n"
# 686 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pad at the same time to jump.\p"
# 687 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the + Control Pad to the side\n"
# 688 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to jump sideways.\p"
# 689 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press it backwards to make the BIKE\n"
# 690 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "change directions while jumping.\p"
# 691 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_EventScript_BikeQuestComplete_Text_0:
# 27 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Ah, my number one customer is\n"
	.string "back!\p"
	.string "Unfortunately, you already own both\n"
	.string "the ACRO BIKE and the MACH BIKE…\p"
	.string "That's everything I sell here!\p"
	.string "But please keep spreading the word\n"
	.string "about RYDEL'S CYCLES wherever you go!$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_0:
# 35 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And you did it in less than a day!\n"
	.string "That's fantastic!\p"
	.string "As promised, I'll thank you with your\n"
	.string "very own BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_1:
# 37 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Yes, they are usually very expensive,\n"
	.string "but don't worry!\p"
	.string "This will be good for both of us! You'll\n"
	.string "have a slick and fast new way to travel,\p"
	.string "and once people everywhere see how\n"
	.string "useful a BIKE can be, they'll need to\l"
	.string "order one!$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_2:
# 44 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "In fact, since you've proven to be\n"
	.string "dependable, I'll help you out some more!\p"
	.string "Keep the MACH BIKE for now, but if you\n"
	.string "want to swap it for an ACRO BIKE later,\l"
	.string "just let me know.\p"
	.string "Once you realize you need them both,\n"
	.string "I'll sell you the one you're missing!$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_3:
# 47 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And it only took a day!\p"
	.string "As promised, I'll thank you with your\n"
	.string "very own BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_4:
# 49 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Yes, they are usually very expensive,\n"
	.string "but don't worry!\p"
	.string "This will be good for both of us! You'll\n"
	.string "have a slick and fast new way to travel,\p"
	.string "and once people everywhere see how\n"
	.string "useful a MACH BIKE can be, they'll need\l"
	.string "to order one!$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_5:
# 52 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And by the way…\p"
	.string "If you ever decide you can't live\n"
	.string "without an ACRO BIKE too, you know\l"
	.string "where to find me.\p"
	.string "Having both models can be really\n"
	.string "convenient!$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_6:
# 55 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well it did take a while…\n"
	.string "But you took care of it.\p"
	.string "As promised, I'll thank you with your\n"
	.string "very own BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_7:
# 57 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Unfortunately, I have a pretty strict\n"
	.string "reputation to uphold, so I can't\l"
	.string "tolerate slow deliveries.\p"
	.string "I'm going to have to put a bit of money\n"
	.string "on your tab here, so make sure you're\l"
	.string "ready to pay it all off before you think\l"
	.string "about buying an ACRO BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_8:
# 61 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "But you really took your time.\p"
	.string "I gave you my word though,\n"
	.string "so I still owe you a BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_9:
# 63 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I really can't tolerate slow deliveries,\n"
	.string "so I'm going to have to charge your tab\l"
	.string "for the losses.\p"
	.string "Make sure you're ready to pay it all off\n"
	.string "before you even think about buying an\l"
	.string "ACRO BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_10:
# 67 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You took so long, I thought I'd never\n"
	.string "see you again.\p"
	.string "But I gave you my word,\n"
	.string "so I'll thank you with a BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_11:
# 69 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Outright bad service like this is\n"
	.string "extremely damaging to my reputation,\p"
	.string "so I'm going to have to charge your tab\n"
	.string "for the losses.\p"
	.string "Make sure you're ready to pay it all off\n"
	.string "before you even think about buying an\l"
	.string "ACRO BIKE.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_12:
# 73 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "But you took forever!\p"
	.string "My customer wrote me multiple times by\n"
	.string "MAIL to complain.\p"
	.string "How did I receive multiple deliveries\n"
	.string "from the customer before you managed\l"
	.string "to make one short trip over there??\p"
	.string "You're lucky I'm such a great guy,\n"
	.string "You really don't deserve this.$"

MauvilleCity_BikeShop_EventScript_FinishedDelivering_Text_13:
# 75 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I can't believe you even bothered\n"
	.string "showing up around here after pulling a\l"
	.string "stunt like that.\p"
	.string "I'm going to have to tack a pretty\n"
	.string "hefty bill onto your tab for the\l"
	.string "reputational damage.\p"
	.string "By now I bet the whole western half of\n"
	.string "HOENN is gossipping about that sketchy\l"
	.string "bike shop, RYDEL'S CYCLES in\l"
	.string "MAUVILLE CITY.\p"
	.string "Good grief…$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_0:
# 87 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Welcome back! Are you here to swap\n"
	.string "BIKES, or are you thinking of buying?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_1:
# 94 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Swap for {STR_VAR_3}$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_2:
# 95 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Buy {STR_VAR_3}$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_3:
# 96 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Exit$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_4:
# 99 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Welcome back! Are you thinking\n"
	.string "of buying an ACRO BIKE?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_5:
# 100 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Buy ACRO BIKE$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_6:
# 104 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Ah, you're back! The MACH BIKE\n"
	.string "must be holding up well, and yet you\l"
	.string "can't stop thinking about my excellent\l"
	.string "ACRO BIKE…\p"
	.string "Is that it?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_7:
# 106 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pay debt$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_8:
# 110 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: You again!\l"
	.string "you must not have been able to forget\l"
	.string "how impressive the ACRO BIKE was…\p"
	.string "Is that it?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_9:
# 116 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Wow, you came back?\p"
	.string "I guess the ACRO BIKE really made an\n"
	.string "impression on you…\p"
	.string "Is that it?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_10:
# 122 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: … … … … … …\p"
	.string "You came back in here?\p"
	.string "I guess you're really curious about the\n"
	.string "ACRO BIKE…\p"
	.string "Is that it?\p"
	.string "Well don't forget, you've got a massive\n"
	.string "tab to pay down before I'll sell you an\l"
	.string "ACRO BIKE…$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_11:
# 127 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "What brings you to RYDEL'S CYCLES\n"
	.string "today?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_12:
# 139 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "So you want to buy one of my renowned\n"
	.string "{STR_VAR_3}s?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_13:
# 142 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well I hope you can afford it!\n"
	.string "The {STR_VAR_3} costs ¥1,000,000.\l"
	.string "So… Are you in?$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_14:
# 156 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "WOW!\p"
	.string "Thank you very much!\p"
	.string "And here is your brand new\n"
	.string "{STR_VAR_3}!$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_15:
# 158 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "To be such a successful TRAINER…\p"
	.string "You must travel all over the place!\p"
	.string "When you're out on the road,\n"
	.string "make sure to tell everyone all over\l"
	.string "HOENN about RYDEL'S CYCLES!!$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_16:
# 162 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Hey!\n"
	.string "This isn't a joke!\p"
	.string "I know it seems like a lot, but these\n"
	.string "BIKES are really incredible!\p"
	.string "If you really want one, just come back\n"
	.string "when you have the cash.$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_17:
# 167 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I know it seems like a lot, but these\n"
	.string "BIKES are really incredible!\p"
	.string "If you really want one, just come back\n"
	.string "when you have the cash.$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_18:
# 172 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You haven't even paid off what you owe\n"
	.string "me for screwing up that delivery!\p"
	.string "Pay off your balance here first, then\n"
	.string "we can talk about an ACRO BIKE.$"

MauvilleCity_BikeShop_EventScript_BikeShopMenu_Text_19:
# 175 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Ah, you've come to pay me back for that\n"
	.string "botched delivery!\p"
	.string "That's great, I really respect that.$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_0:
# 189 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Let's see here, it looks like you still\n"
	.string "owe me ¥{STR_VAR_2},000…\p"
	.string "Are you finally ready to finish\n"
	.string "paying off this debt?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_1:
# 192 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Let's see here, it looks like you still\n"
	.string "owe me ¥{STR_VAR_2},000…\p"
	.string "So do you want to pay the rest all at\n"
	.string "once,\p"
	.string "or will it just be a partial payment\n"
	.string "today?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_2:
# 197 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "So how much did you want to pay off\n"
	.string "today?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_3:
# 199 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pay completely$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_4:
# 205 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pay ¥1,000$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_5:
# 210 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pay ¥10,000$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_6:
# 216 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pay ¥100,000$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_7:
# 222 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You want to put ¥1,000 towards paying\n"
	.string "down your balance?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_8:
# 231 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Thanks!\n"
	.string "You're not so bad after all!\p"
	.string "Stop back by RYDEL'S CYCLES anytime!$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_9:
# 234 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You don't have enough money for that!$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_10:
# 242 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You want to put ¥10,000 towards paying\n"
	.string "down your balance?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_11:
# 262 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You want to put ¥100,000 towards\n"
	.string "paying down your balance?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_12:
# 282 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You want to pay the rest of your\n"
	.string "balance all at once?$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_13:
# 290 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Thanks!\n"
	.string "That must feel like a weight off your\l"
	.string "back!\p"
	.string "Stop back by RYDEL'S CYCLES anytime,\n"
	.string "I'd love to sell you an ACRO BIKE!$"

MauvilleCity_BikeShop_EventScript_PayDebtMenu_Text_14:
# 301 "data//maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Come back when you're ready to pay off\n"
	.string "what you owe me!$"
