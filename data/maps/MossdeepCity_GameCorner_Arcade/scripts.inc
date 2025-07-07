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
	msgbox MossdeepCity_Arcade_EventScript_CallWaiter_Text_0, MSGBOX_YESNO
# 165 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_Arcade_EventScript_CallWaiter_8
MossdeepCity_Arcade_EventScript_CallWaiter_7:
# 169 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT
# 170 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 172 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 173 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_CallWaiter_12
# 175 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_CallWaiter_13
# 177 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_CallWaiter_14
# 179 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_CallWaiter_15
MossdeepCity_Arcade_EventScript_CallWaiter_10:
# 183 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement 0
# 184 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
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
# 166 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_CallWaiter_7

MossdeepCity_Arcade_EventScript_CallWaiter_12:
# 174 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_CallWaiter_10

MossdeepCity_Arcade_EventScript_CallWaiter_13:
# 176 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_CallWaiter_10

MossdeepCity_Arcade_EventScript_CallWaiter_14:
# 178 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_CallWaiter_10

MossdeepCity_Arcade_EventScript_CallWaiter_15:
# 180 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_CallWaiter_10


# 188 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 189 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 190 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool1::
# 191 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 192 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 1                                      @indicates whihc barstool
# 193 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 194 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 195 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 196 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 197 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 198 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 199 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 200 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 201 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 202 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach1
# 203 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 204 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 205 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 206 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 207 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 208 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 209 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
# 210 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 211 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 212 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 213 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 214 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool2::
# 215 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 216 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 2                                      @indicates whihc barstool
# 217 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 218 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 219 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 220 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 221 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 222 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 223 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 224 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 225 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 226 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach2
# 227 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 228 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 229 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 230 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 231 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 232 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 233 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
# 234 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 235 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 236 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 237 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 238 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool3::
# 239 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 240 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 3                                      @indicates whihc barstool
# 241 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 242 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 243 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 244 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 245 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 246 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 247 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 248 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 249 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 250 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach3
# 251 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 252 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 253 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 254 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 255 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 256 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 257 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
# 258 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 259 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 260 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end
# 261 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 262 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_EventScript_BarStool4::
# 263 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    lock
# 264 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    setvar VAR_TEMP_5, 4                                      @indicates whihc barstool
# 265 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    hidefollower
# 266 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 267 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 268 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 269 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 270 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    playse SE_PIN
# 271 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, Common_Movement_ExclamationMark
# 272 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitse
# 273 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 15
# 274 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterApproach4
# 275 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 276 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay 5
# 277 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_ReadyToOrder, MSGBOX_YESNO
# 278 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    goto_if_eq VAR_RESULT, YES, MossdeepCity_Arcade_EventScript_Waiter
# 279 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT 
# 280 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    closemessage
# 281 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
# 282 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    waitmovement 0
# 283 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    release
# 284 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    end

MossdeepCity_Arcade_EventScript_RichGuy::
# 288 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 289 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 290 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 291 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_RegularGuy::
# 296 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 297 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 298 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 299 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_PachinkoGirl::
# 304 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 305 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 306 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_PachinkoGirl_Text_0
# 307 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_OnixBoy::
# 312 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 313 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 314 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 315 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


MossdeepCity_Arcade_EventScript_BlockGuy::
# 320 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	lock
# 321 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	faceplayer
# 322 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_RichGuy_Text_0
# 323 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_NPCReturnToSlots
	end


# 327 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 328 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_ReadyToOrder:
# 329 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Welcome!\n"
# 330 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Do you know what you'd like?$"
# 331 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 332 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_LetMeKnow:
# 333 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Well, if you make up your mind\n"
# 334 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "just let me know!$"
# 335 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 336 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach1:
# 337 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 338 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 339 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 340 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 341 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 342 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach2:
# 343 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 344 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 345 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 346 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 347 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 348 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 349 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach3:
# 350 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 351 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 352 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 353 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 354 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 355 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 356 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterApproach4:
# 357 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_down
# 358 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 359 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 360 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 361 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 362 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end 
# 363 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 364 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave1:
# 365 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 366 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 367 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_right
# 368 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 369 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end
# 370 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 371 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave3:
# 372 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 373 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 374 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 375 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 376 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end
# 377 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 378 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Movement_WaiterLeave4:
# 379 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    delay_16
# 380 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 381 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_left
# 382 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    walk_up
# 383 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    face_down
# 384 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    step_end

MossdeepCity_Arcade_EventScript_Waiter::
# 389 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	message MossdeepCity_Arcade_EventScript_Waiter_Text_0
# 390 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmessage
# 391 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 392 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto_if_set FLAG_TEMP_2, MossdeepCity_Arcade_EventScript_Waiter_2
MossdeepCity_Arcade_EventScript_Waiter_1:
# 396 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	showmoneybox 0, 0
# 397 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	dynmultichoice 15, 0, FALSE, 5, VAR_TEMP_2, DYN_MULTICHOICE_CB_NONE, MossdeepCity_Arcade_EventScript_Waiter_Text_1, MossdeepCity_Arcade_EventScript_Waiter_Text_2, MossdeepCity_Arcade_EventScript_Waiter_Text_3, MossdeepCity_Arcade_EventScript_Waiter_Text_4, MossdeepCity_Arcade_EventScript_CoinMachine_Text_2
# 402 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_RESULT
# 403 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 0, MossdeepCity_Arcade_EventScript_Waiter_6
# 443 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_7
# 483 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_8
# 524 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_9
# 566 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 567 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_Text_LetMeKnow, MSGBOX_DEFAULT
# 568 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 569 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 570 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_12
# 572 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_13
# 574 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_14
# 576 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_15
MossdeepCity_Arcade_EventScript_Waiter_10:
# 579 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 580 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 581 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_2:
# 393 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 394 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	clearflag FLAG_TEMP_2
	goto MossdeepCity_Arcade_EventScript_Waiter_1

MossdeepCity_Arcade_EventScript_Waiter_6:
# 404 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 0
# 405 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_5, MSGBOX_YESNO
# 406 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_17
MossdeepCity_Arcade_EventScript_Waiter_16:
# 410 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 100
# 411 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_29
# 416 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 417 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_41
# 421 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_40:
# 423 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 100
# 424 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 425 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 426 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_BERRY_JUICE
# 427 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 428 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 429 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 430 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 431 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_58
# 433 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_59
# 435 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_60
# 437 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_61
MossdeepCity_Arcade_EventScript_Waiter_56:
# 440 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 441 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_7:
# 444 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 1
# 445 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_8, MSGBOX_YESNO
# 446 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_20
MossdeepCity_Arcade_EventScript_Waiter_19:
# 450 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 200
# 451 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_32
# 456 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 457 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_45
# 461 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_44:
# 463 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 200
# 464 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 465 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 466 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_FRESH_WATER
# 467 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 468 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 469 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 470 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 471 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_64
# 473 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_65
# 475 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_66
# 477 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_67
MossdeepCity_Arcade_EventScript_Waiter_62:
# 480 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 481 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_8:
# 484 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 2
# 485 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_9, MSGBOX_YESNO
# 486 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_23
MossdeepCity_Arcade_EventScript_Waiter_22:
# 490 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 350
# 491 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_35
# 496 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 497 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_49
# 501 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_48:
# 503 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 350
# 504 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 505 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 506 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_LEMONADE
# 507 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 508 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 509 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 510 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 511 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_70
# 513 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_71
# 515 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_72
# 517 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_73
MossdeepCity_Arcade_EventScript_Waiter_68:
# 520 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 521 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_9:
# 525 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setvar VAR_TEMP_2, 3
# 526 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_10, MSGBOX_YESNO
# 527 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_26
MossdeepCity_Arcade_EventScript_Waiter_25:
# 531 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	checkmoney 500
# 532 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_38
# 537 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	delay 10
# 538 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	compare VAR_TEMP_5, 1
	goto_if_eq MossdeepCity_Arcade_EventScript_Waiter_53
# 542 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceDown
MossdeepCity_Arcade_EventScript_Waiter_52:
# 544 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	removemoney 500
# 545 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	updatemoneybox
# 546 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	playse SE_SHOP
# 547 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	additem ITEM_MOOMOO_MILK
# 548 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_7, MSGBOX_DEFAULT
# 549 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	closemessage
# 550 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	hidemoneybox
# 551 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	switch VAR_TEMP_5
# 552 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 1, MossdeepCity_Arcade_EventScript_Waiter_76
# 554 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 2, MossdeepCity_Arcade_EventScript_Waiter_77
# 556 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 3, MossdeepCity_Arcade_EventScript_Waiter_78
# 558 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	case 4, MossdeepCity_Arcade_EventScript_Waiter_79
MossdeepCity_Arcade_EventScript_Waiter_74:
# 561 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	waitmovement LOCALID_ARCADE_WAITER
# 562 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_12:
# 571 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_13:
# 573 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_14:
# 575 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_15:
# 577 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_10

MossdeepCity_Arcade_EventScript_Waiter_17:
# 407 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 408 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_16

MossdeepCity_Arcade_EventScript_Waiter_20:
# 447 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 448 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_19

MossdeepCity_Arcade_EventScript_Waiter_23:
# 487 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 488 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_22

MossdeepCity_Arcade_EventScript_Waiter_26:
# 528 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	setflag FLAG_TEMP_2
# 529 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	goto MossdeepCity_Arcade_EventScript_Waiter
	goto MossdeepCity_Arcade_EventScript_Waiter_25

MossdeepCity_Arcade_EventScript_Waiter_29:
# 412 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 413 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_32:
# 452 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 453 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_35:
# 492 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 493 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_38:
# 533 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	msgbox MossdeepCity_Arcade_EventScript_Waiter_Text_6, MSGBOX_DEFAULT
# 534 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	release
	end

MossdeepCity_Arcade_EventScript_Waiter_41:
# 418 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_40

MossdeepCity_Arcade_EventScript_Waiter_45:
# 458 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_44

MossdeepCity_Arcade_EventScript_Waiter_49:
# 498 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_48

MossdeepCity_Arcade_EventScript_Waiter_53:
# 539 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, Common_Movement_WalkInPlaceLeft
	goto MossdeepCity_Arcade_EventScript_Waiter_52

MossdeepCity_Arcade_EventScript_Waiter_58:
# 432 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_59:
# 434 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_60:
# 436 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_61:
# 438 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_56

MossdeepCity_Arcade_EventScript_Waiter_64:
# 472 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_65:
# 474 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_66:
# 476 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_67:
# 478 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_62

MossdeepCity_Arcade_EventScript_Waiter_70:
# 512 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_71:
# 514 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_72:
# 516 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_73:
# 518 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_68

MossdeepCity_Arcade_EventScript_Waiter_76:
# 553 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_77:
# 555 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave1
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_78:
# 557 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave3
	goto MossdeepCity_Arcade_EventScript_Waiter_74

MossdeepCity_Arcade_EventScript_Waiter_79:
# 559 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	applymovement LOCALID_ARCADE_WAITER, MossdeepCity_Arcade_Movement_WaiterLeave4
	goto MossdeepCity_Arcade_EventScript_Waiter_74


# 585 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 586 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 587 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_PinballGuy:
# 588 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "Each pinball machine has a different\n"
# 589 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "theme,\p"
# 590 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "but they all have crazy lights and\n"
# 591 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "sounds!$"
# 592 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 593 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_CoinMachine:
# 594 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "It's a coin machine;\n"
# 595 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "you can exchange money for COINS.$"
# 596 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 597 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_NotEnoughMoney:
# 598 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "You don't have enough money…$"
# 599 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 600 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_InsertMoney:
# 601 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "You put your money into the machine…$"
# 602 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 603 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_ThankYouHereAreYourCoins:
# 604 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
    .string "The machine dispensed your coins!$"
# 605 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"

# 606 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
MossdeepCity_Arcade_Text_NoRoomForCoins:
# 607 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
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
# 164 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Oh?\n"
	.string "You're ready to order now?$"

MossdeepCity_Arcade_EventScript_RichGuy_Text_0:
# 290 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Placeholder.$"

MossdeepCity_Arcade_EventScript_PachinkoGirl_Text_0:
# 306 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "I think we're in a basement right now!\p"
	.string "I have no clue how long I've been\n"
	.string "playing!$"

MossdeepCity_Arcade_EventScript_Waiter_Text_0:
# 389 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "What can I get for you?$"

MossdeepCity_Arcade_EventScript_Waiter_Text_1:
# 397 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "BERRY JUICE  ¥100$"

MossdeepCity_Arcade_EventScript_Waiter_Text_2:
# 398 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "FRESH WATER  ¥200$"

MossdeepCity_Arcade_EventScript_Waiter_Text_3:
# 399 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "LEMONADE       ¥350$"

MossdeepCity_Arcade_EventScript_Waiter_Text_4:
# 400 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "MOOMOO MILK  ¥500$"

MossdeepCity_Arcade_EventScript_Waiter_Text_5:
# 405 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "BERRY JUICE? That will be ¥100.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_6:
# 412 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Oh… I'm sorry…\pIt seems like you don't have the money…$"

MossdeepCity_Arcade_EventScript_Waiter_Text_7:
# 427 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "Here you are.\nEnjoy!$"

MossdeepCity_Arcade_EventScript_Waiter_Text_8:
# 445 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "FRESH WATER? That will be ¥200.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_9:
# 485 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "LEMONADE? That will be ¥350.$"

MossdeepCity_Arcade_EventScript_Waiter_Text_10:
# 526 "data//maps/MossdeepCity_GameCorner_Arcade/scripts.pory"
	.string "MOOMOO MILK? Good choice…\n"
	.string "That will be ¥500.$"
