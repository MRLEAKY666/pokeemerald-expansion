# 1 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 2 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_GameCorner_Arcade_MapScripts::
# 3 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.byte 0

MossdeepCity_Arcade_EventScript_CoinMachine::
# 8 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 9 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	message MossdeepCity_Arcade_Text_CoinMachine
# 10 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmessage
# 11 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 12 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	showmoneybox 0, 0
# 13 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	showcoinsbox 1, 6
# 14 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	dynmultichoice 15, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, MossdeepCity_Arcade_EventScript_CoinMachine_Text_0, MossdeepCity_Arcade_EventScript_CoinMachine_Text_1, MossdeepCity_Arcade_EventScript_CoinMachine_Text_2
# 15 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_RESULT
# 16 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 0, MossdeepCity_Arcade_EventScript_CoinMachine_3
# 18 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_CoinMachine_4
# 20 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_CoinMachine_5
MossdeepCity_Arcade_EventScript_CoinMachine_1:
# 23 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_CancelBuyCoins
	end

MossdeepCity_Arcade_EventScript_CoinMachine_3:
# 17 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Buy50Coins
	goto MossdeepCity_Arcade_EventScript_CoinMachine_1

MossdeepCity_Arcade_EventScript_CoinMachine_4:
# 19 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Buy500Coins
	goto MossdeepCity_Arcade_EventScript_CoinMachine_1

MossdeepCity_Arcade_EventScript_CoinMachine_5:
# 21 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_CancelBuyCoins
	goto MossdeepCity_Arcade_EventScript_CoinMachine_1


# 27 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 28 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 29 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_Buy50Coins::
# 30 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkcoins VAR_TEMP_1
# 31 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MossdeepCity_Arcade_EventScript_NoRoomForCoins
# 32 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 1000
# 33 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_Arcade_EventScript_NotEnoughMoney
# 34 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 35 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	message MossdeepCity_Arcade_Text_InsertMoney
# 36 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmessage
# 37 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 38 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_DEX_SEARCH
# 39 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 40 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 10
# 41 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 42 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 43 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 44 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 7
# 45 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 46 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 47 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 48 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 8
# 49 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 50 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 10
# 51 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 52 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 53 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 54 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	addcoins 50
# 55 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 1000
# 56 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 57 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatecoinsbox 1, 6
# 58 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_SHOP
# 59 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 60 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 61 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidecoinsbox 0, 5
# 62 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 63 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 64 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 65 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_Buy500Coins::
# 66 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkcoins VAR_TEMP_1
# 67 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MossdeepCity_Arcade_EventScript_NoRoomForCoins
# 68 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 10000
# 69 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_Arcade_EventScript_NotEnoughMoney
# 70 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 71 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	message MossdeepCity_Arcade_Text_InsertMoney
# 72 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmessage
# 73 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 74 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_DEX_SEARCH
# 75 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 76 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 10
# 77 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 78 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 79 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 80 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 7
# 81 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 82 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 83 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 84 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 8
# 85 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 86 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 10
# 87 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_VEND
# 88 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 89 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 90 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	addcoins 500
# 91 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 10000
# 92 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 93 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatecoinsbox 1, 6
# 94 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 95 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 96 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 97 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidecoinsbox 0, 5
# 98 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 99 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 100 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 101 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_CancelBuyCoins::
# 102 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	@ msgbox MossdeepCity_Arcade_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 103 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 104 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidecoinsbox 0, 5
# 105 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 106 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 107 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 108 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_NotEnoughMoney::
# 109 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 110 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 111 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidecoinsbox 0, 5
# 112 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 113 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 114 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 115 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_NoRoomForCoins::
# 116 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_NoRoomForCoins, MSGBOX_DEFAULT
# 117 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 118 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidecoinsbox 0, 5
# 119 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 120 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 121 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 122 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_PinballGuy::
# 123 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 124 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 125 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_PinballGuy, MSGBOX_DEFAULT
# 126 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	@ goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
# 127 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 128 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end
# 129 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 130 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_NPCReturnToSlots::
# 131 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 132 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 133 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 134 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
# 135 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	end

MossdeepCity_Arcade_EventScript_CallWaiter::
# 139 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 140 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 5
# 141 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 142 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_CallWaiter_3
# 147 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_CallWaiter_4
# 152 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_CallWaiter_5
# 157 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_CallWaiter_6
MossdeepCity_Arcade_EventScript_CallWaiter_1:
# 164 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_set FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_CallWaiter_8
# 168 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_CallWaiter_Text_1, MSGBOX_YESNO
MossdeepCity_Arcade_EventScript_CallWaiter_7:
# 171 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_Arcade_EventScript_CallWaiter_12
MossdeepCity_Arcade_EventScript_CallWaiter_11:
# 175 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT
# 176 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 178 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 179 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_CallWaiter_16
# 181 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_CallWaiter_17
# 183 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_CallWaiter_18
# 185 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_CallWaiter_19
MossdeepCity_Arcade_EventScript_CallWaiter_14:
# 189 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 190 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_CallWaiter_3:
# 143 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach1
# 144 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 145 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 5
# 146 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_CallWaiter_1

MossdeepCity_Arcade_EventScript_CallWaiter_4:
# 148 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach2
# 149 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 150 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 5
# 151 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
	goto MossdeepCity_Arcade_EventScript_CallWaiter_1

MossdeepCity_Arcade_EventScript_CallWaiter_5:
# 153 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach3
# 154 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 155 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 5
# 156 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
	goto MossdeepCity_Arcade_EventScript_CallWaiter_1

MossdeepCity_Arcade_EventScript_CallWaiter_6:
# 158 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach4
# 159 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 160 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 5
# 161 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
	goto MossdeepCity_Arcade_EventScript_CallWaiter_1

MossdeepCity_Arcade_EventScript_CallWaiter_8:
# 165 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_CallWaiter_Text_0, MSGBOX_YESNO
	goto MossdeepCity_Arcade_EventScript_CallWaiter_7

MossdeepCity_Arcade_EventScript_CallWaiter_12:
# 172 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_CallWaiter_11

MossdeepCity_Arcade_EventScript_CallWaiter_16:
# 180 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_CallWaiter_14

MossdeepCity_Arcade_EventScript_CallWaiter_17:
# 182 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_CallWaiter_14

MossdeepCity_Arcade_EventScript_CallWaiter_18:
# 184 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_CallWaiter_14

MossdeepCity_Arcade_EventScript_CallWaiter_19:
# 186 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_CallWaiter_14


# 194 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 195 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 196 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool1::
# 197 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 198 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 1                                      @indicates whihc barstool
# 199 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 200 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 201 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 202 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 203 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 204 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 205 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 206 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 207 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 208 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach1
# 209 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 210 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 211 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    call_if_set FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_ClearAlreadyOrderedFlag 
# 212 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 213 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 214 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 215 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 216 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
# 217 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 218 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 219 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 220 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 221 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_ClearAlreadyOrderedFlag::
# 222 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    clearflag FLAG_TEMP_3
# 223 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    return
# 224 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 225 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool2::
# 226 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 227 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 2                                      @indicates whihc barstool
# 228 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 229 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 230 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 231 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 232 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 233 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 234 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 235 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 236 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 237 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach2
# 238 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 239 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 240 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    call_if_set FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_ClearAlreadyOrderedFlag 
# 241 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 242 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 243 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 244 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 245 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
# 246 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 247 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 248 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 249 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 250 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool3::
# 251 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 252 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 3                                      @indicates whihc barstool
# 253 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 254 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 255 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 256 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 257 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 258 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 259 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 260 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 261 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 262 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach3
# 263 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 264 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 265 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    call_if_set FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_ClearAlreadyOrderedFlag 
# 266 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 267 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 268 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 269 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 270 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
# 271 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 272 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 273 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 274 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 275 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool4::
# 276 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 277 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 4                                      @indicates whihc barstool
# 278 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 279 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 280 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 281 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 282 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 283 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 284 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 285 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 286 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 287 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach4
# 288 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 289 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 290 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    call_if_set FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_ClearAlreadyOrderedFlag 
# 291 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 292 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 293 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 294 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 295 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
# 296 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 297 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 298 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end

MossdeepCity_Arcade_EventScript_RichGuy::
# 302 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 303 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 304 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 305 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_RegularGuy::
# 310 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 311 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 312 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 313 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_PachinkoGirl::
# 318 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 319 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 320 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_PachinkoGirl_Text_0
# 321 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_OnixBoy::
# 326 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 327 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 328 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 329 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_BlockGuy::
# 334 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 335 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 336 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 337 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


# 341 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 342 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_ReadyToOrder:
# 343 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Welcome!\n"
# 344 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Do you know what you'd like?$"
# 345 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 346 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_LetMeKnow:
# 347 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Well, if you make up your mind\n"
# 348 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "just let me know!$"
# 349 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 350 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach1:
# 351 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 352 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 353 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 354 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 355 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 356 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach2:
# 357 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 358 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 359 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 360 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 361 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 362 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 363 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach3:
# 364 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 365 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 366 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 367 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 368 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 369 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 370 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach4:
# 371 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 372 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 373 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 374 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 375 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 376 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 377 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 378 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave1:
# 379 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 380 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 381 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 382 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 383 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end
# 384 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 385 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave3:
# 386 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 387 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 388 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 389 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 390 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end
# 391 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 392 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave4:
# 393 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 394 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 395 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 396 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 397 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 398 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end

MossdeepCity_Arcade_EventScript_Waiter::
# 403 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	message MossdeepCity_Arcade_EventScript_Waiter_Text_0
# 404 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmessage
# 405 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 406 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_set FLAG_TEMP_2, MossdeepCity_Arcade_EventScript_Waiter_2
MossdeepCity_Arcade_EventScript_Waiter_1:
# 410 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	showmoneybox 0, 0
# 411 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	dynmultichoice 15, 0, FALSE, 5, VAR_TEMP_2, DYN_MULTICHOICE_CB_NONE, MossdeepCity_Arcade_EventScript_Waiter_Text_1, MossdeepCity_Arcade_EventScript_Waiter_Text_2, MossdeepCity_Arcade_EventScript_Waiter_Text_3, MossdeepCity_Arcade_EventScript_Waiter_Text_4, MossdeepCity_Arcade_EventScript_CoinMachine_Text_2
# 416 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_RESULT
# 417 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 0, MossdeepCity_Arcade_EventScript_Waiter_6
# 461 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_7
# 505 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_8
# 550 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_9
# 596 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 597 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT
# 598 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 599 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 600 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_12
# 602 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_13
# 604 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_14
# 606 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_15
MossdeepCity_Arcade_EventScript_Waiter_10:
# 609 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 610 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 611 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_2:
# 407 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 408 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	clearflag FLAG_TEMP_2
	goto MossdeepCity_Arcade_EventScript_Waiter_1

MossdeepCity_Arcade_EventScript_Waiter_6:
# 418 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 419 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_5, MSGBOX_YESNO
# 420 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_17
MossdeepCity_Arcade_EventScript_Waiter_16:
# 424 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 100
# 425 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_29
# 430 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 431 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_41
# 435 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_40:
# 437 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 100
# 438 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 439 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 440 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_BERRY_JUICE
# 441 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 442 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 443 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 444 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 445 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_58
# 447 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_59
# 449 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_60
# 451 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_61
MossdeepCity_Arcade_EventScript_Waiter_56:
# 454 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 455 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 456 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_unset FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_Waiter_81
MossdeepCity_Arcade_EventScript_Waiter_80:
# 459 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_7:
# 462 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 1
# 463 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_8, MSGBOX_YESNO
# 464 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_20
MossdeepCity_Arcade_EventScript_Waiter_19:
# 468 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 200
# 469 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_32
# 474 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 475 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_45
# 479 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_44:
# 481 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 200
# 482 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 483 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 484 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_FRESH_WATER
# 485 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 486 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 487 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 488 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 489 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_64
# 491 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_65
# 493 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_66
# 495 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_67
MossdeepCity_Arcade_EventScript_Waiter_62:
# 498 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 499 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 500 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_unset FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_Waiter_84
MossdeepCity_Arcade_EventScript_Waiter_83:
# 503 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_8:
# 506 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 2
# 507 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_9, MSGBOX_YESNO
# 508 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_23
MossdeepCity_Arcade_EventScript_Waiter_22:
# 512 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 350
# 513 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_35
# 518 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 519 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_49
# 523 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_48:
# 525 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 350
# 526 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 527 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 528 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_LEMONADE
# 529 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 530 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 531 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 532 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 533 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_70
# 535 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_71
# 537 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_72
# 539 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_73
MossdeepCity_Arcade_EventScript_Waiter_68:
# 542 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 543 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 544 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_unset FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_Waiter_87
MossdeepCity_Arcade_EventScript_Waiter_86:
# 547 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_9:
# 551 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 3
# 552 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_10, MSGBOX_YESNO
# 553 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_26
MossdeepCity_Arcade_EventScript_Waiter_25:
# 557 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 500
# 558 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_38
# 563 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 564 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_53
# 568 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_52:
# 570 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 500
# 571 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 572 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 573 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_MOOMOO_MILK
# 574 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 575 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 576 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 577 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 578 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_76
# 580 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_77
# 582 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_78
# 584 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_79
MossdeepCity_Arcade_EventScript_Waiter_74:
# 587 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 588 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 589 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_unset FLAG_TEMP_3, MossdeepCity_Arcade_EventScript_Waiter_90
MossdeepCity_Arcade_EventScript_Waiter_89:
# 592 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_12:
# 601 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_13:
# 603 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_14:
# 605 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_15:
# 607 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_17:
# 421 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 422 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_16

MossdeepCity_Arcade_EventScript_Waiter_20:
# 465 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 466 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_19

MossdeepCity_Arcade_EventScript_Waiter_23:
# 509 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 510 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_22

MossdeepCity_Arcade_EventScript_Waiter_26:
# 554 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 555 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_25

MossdeepCity_Arcade_EventScript_Waiter_29:
# 426 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 427 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_32:
# 470 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 471 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_35:
# 514 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 515 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_38:
# 559 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 560 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_41:
# 432 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_40

MossdeepCity_Arcade_EventScript_Waiter_45:
# 476 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_44

MossdeepCity_Arcade_EventScript_Waiter_49:
# 520 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_48

MossdeepCity_Arcade_EventScript_Waiter_53:
# 565 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_52

MossdeepCity_Arcade_EventScript_Waiter_58:
# 446 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_59:
# 448 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_60:
# 450 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_61:
# 452 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_64:
# 490 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_65:
# 492 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_66:
# 494 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_67:
# 496 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_70:
# 534 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_71:
# 536 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_72:
# 538 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_73:
# 540 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_76:
# 579 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_77:
# 581 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_78:
# 583 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_79:
# 585 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_81:
# 457 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_3
	goto MossdeepCity_Arcade_EventScript_Waiter_80

MossdeepCity_Arcade_EventScript_Waiter_84:
# 501 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_3
	goto MossdeepCity_Arcade_EventScript_Waiter_83

MossdeepCity_Arcade_EventScript_Waiter_87:
# 545 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_3
	goto MossdeepCity_Arcade_EventScript_Waiter_86

MossdeepCity_Arcade_EventScript_Waiter_90:
# 590 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_3
	goto MossdeepCity_Arcade_EventScript_Waiter_89


# 615 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 616 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 617 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_PinballGuy:
# 618 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Each pinball machine has a different\n"
# 619 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "theme,\p"
# 620 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "but they all have crazy lights and\n"
# 621 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "sounds!$"
# 622 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 623 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_CoinMachine:
# 624 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "It's a coin machine;\n"
# 625 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "you can exchange money for COINS.$"
# 626 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 627 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_NotEnoughMoney:
# 628 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "You don't have enough money…$"
# 629 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 630 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_InsertMoney:
# 631 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "You put your money into the machine…$"
# 632 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 633 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_ThankYouHereAreYourCoins:
# 634 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "The machine dispensed your coins!$"
# 635 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 636 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_NoRoomForCoins:
# 637 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "You can't hold that many coins!$"

MossdeepCity_Arcade_EventScript_CoinMachine_Text_0:
# 14 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "  50 COINS           ¥1,000$"

MossdeepCity_Arcade_EventScript_CoinMachine_Text_1:
# 14 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "500 COINS         ¥10,000$"

MossdeepCity_Arcade_EventScript_CoinMachine_Text_2:
# 14 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "EXIT$"

MossdeepCity_Arcade_EventScript_CallWaiter_Text_0:
# 165 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Oh?\n"
	.string "You'd like to order something else?$"

MossdeepCity_Arcade_EventScript_CallWaiter_Text_1:
# 168 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Oh?\n"
	.string "You're ready to order now?$"

MossdeepCity_Arcade_EventScript_RichGuy_Text_0:
# 304 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Placeholder.$"

MossdeepCity_Arcade_EventScript_PachinkoGirl_Text_0:
# 320 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "I think we're in a basement right now!\p"
	.string "I have no clue how long I've been\n"
	.string "playing!$"

MossdeepCity_Arcade_EventScript_Waiter_Text_0:
# 403 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "What can I get for you?$"

MossdeepCity_Arcade_EventScript_Waiter_Text_1:
# 411 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "BERRY JUICE  ¥100$"

MossdeepCity_Arcade_EventScript_Waiter_Text_2:
# 412 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "FRESH WATER  ¥200$"

MossdeepCity_Arcade_EventScript_Waiter_Text_3:
# 413 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "LEMONADE       ¥350$"

MossdeepCity_Arcade_EventScript_Waiter_Text_4:
# 414 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "MOOMOO MILK  ¥500$"

MossdeepCity_Arcade_EventScript_Waiter_Text_5:
# 419 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "BERRY JUICE? That will be ¥100.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_6:
# 426 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Oh… I'm sorry…\pIt seems like you don't have the money…$"

MossdeepCity_Arcade_EventScript_Waiter_Text_7:
# 441 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Here you are.\nEnjoy!$"

MossdeepCity_Arcade_EventScript_Waiter_Text_8:
# 463 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "FRESH WATER? That will be ¥200.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_9:
# 507 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "LEMONADE? That will be ¥350.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_10:
# 552 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "MOOMOO MILK? Good choice…\n"
	.string "That will be ¥500.$"
