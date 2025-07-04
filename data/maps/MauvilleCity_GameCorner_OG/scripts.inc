# 1 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 2 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_MapScripts::
# 3 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_GameCorner_OG_OnTransition
# 4 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.byte 0
# 5 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 6 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
    @ Game Corner prices
# 7 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 8 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 9 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 10 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 11 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 12 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set DOLL_COINS, 1000
# 13 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 14 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set COINS_PRICE_50,  1000
# 15 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set COINS_PRICE_500, 10000
# 16 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 17 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_OnTransition::
# 18 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, MauvilleCity_GameCorner_OG_EventScript_TryResetAfterFailed
# 19 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 20 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 21 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TryResetAfterFailed::
# 22 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkfollowernpc
# 23 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_ResetAfterFailed
# 24 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 25 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 26 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ResetAfterFailed::
# 27 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	clearflag FLAG_GAME_CORNER_UNC
# 28 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 29 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 30 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CoinsClerk::
# 31 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 32 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 33 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 34 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 35 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NeedCoinCase
# 36 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WereYouLookingForCoins
# 37 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 38 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showmoneybox 0, 0
# 39 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 6
# 40 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault50
# 41 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 42 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault50::
# 43 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 44 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 45 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_Buy50Coins
# 46 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_Buy500Coins
# 47 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins
# 48 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 49 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 50 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 51 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault500::
# 52 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 53 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 54 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_Buy50Coins
# 55 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_Buy500Coins
# 56 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins
# 57 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 58 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 59 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Buy50Coins::
# 60 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 61 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins
# 62 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkmoney COINS_PRICE_50
# 63 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney
# 64 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 50
# 65 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removemoney COINS_PRICE_50
# 66 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatemoneybox
# 67 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 6
# 68 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 69 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 70 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 71 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 72 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 73 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 74 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 75 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Buy500Coins::
# 76 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 77 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins
# 78 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkmoney COINS_PRICE_500
# 79 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney
# 80 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 500
# 81 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removemoney COINS_PRICE_500
# 82 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatemoneybox
# 83 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 6
# 84 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 85 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 86 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 87 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 88 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 89 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 90 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 91 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NeedCoinCase::
# 92 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 93 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 94 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 95 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 96 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney::
# 97 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 98 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 99 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 100 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 101 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 102 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 103 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins::
# 104 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 105 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 106 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 107 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 108 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 109 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 110 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins::
# 111 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 112 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 113 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 114 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 115 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 116 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 117 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PrizeCornerDolls::
# 118 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 119 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 120 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 121 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 122 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrizeMessage
# 123 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 124 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 125 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 126 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrizeMessage::
# 127 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 128 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 129 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 0
# 130 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 1
# 131 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize
# 132 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 133 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize::
# 134 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 135 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 136 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize
# 137 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 138 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize::
# 139 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 140 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 141 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_TreeckoDoll
# 142 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_TorchicDoll
# 143 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_MudkipDoll
# 144 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 145 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 146 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 147 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 148 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TreeckoDoll::
# 149 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 1
# 150 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 151 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 152 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 153 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TorchicDoll::
# 154 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 2
# 155 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 156 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 157 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 158 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_MudkipDoll::
# 159 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 3
# 160 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 161 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 162 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 163 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize::
# 164 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 165 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 166 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_TEMP_1
# 167 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_BuyTreeckoDoll
# 168 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_BuyTorchicDoll
# 169 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_BuyMudkipDoll
# 170 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 171 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 172 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTreeckoDoll::
# 173 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 174 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 175 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 176 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 177 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 178 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 179 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 180 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 181 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 182 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 183 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 184 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 185 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 186 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTorchicDoll::
# 187 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 188 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 189 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 190 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 191 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 192 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 193 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 194 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 195 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 196 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 197 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 198 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 199 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 200 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyMudkipDoll::
# 201 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 202 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 203 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 204 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 205 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 206 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 207 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 208 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 209 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 210 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 211 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 212 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 213 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 214 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll::
# 215 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 216 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 217 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 218 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 219 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll::
# 220 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 221 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 222 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 223 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 224 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect::
# 225 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OhIsThatSo, MSGBOX_DEFAULT
# 226 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 0
# 227 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 228 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 229 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 230 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PrizeCornerTMs::
# 231 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 232 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 233 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 234 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 235 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrizeMessage
# 236 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 237 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 238 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 239 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrizeMessage::
# 240 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 241 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 242 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 0
# 243 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 1
# 244 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize
# 245 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 246 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize::
# 247 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 248 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 249 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize
# 250 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 251 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize::
# 252 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
# 253 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 254 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_TMDoubleTeam
# 255 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_TMPsychic
# 256 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_TMFlamethrower
# 257 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_TMThunderbolt
# 258 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 4, MauvilleCity_GameCorner_OG_EventScript_TMIceBeam
# 259 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 5, MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
# 260 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
# 261 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 262 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 263 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMDoubleTeam::
# 264 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 1
# 265 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 266 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 267 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 268 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 269 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMPsychic::
# 270 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 2
# 271 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 272 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 273 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 274 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 275 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMFlamethrower::
# 276 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 3
# 277 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 278 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 279 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 280 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 281 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMThunderbolt::
# 282 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 4
# 283 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 284 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 285 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 286 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 287 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMIceBeam::
# 288 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 5
# 289 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 290 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 291 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 292 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 293 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize::
# 294 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	special BufferTMHMMoveName
# 295 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
# 296 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
# 297 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_TEMP_1
# 298 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_BuyTMDoubleTeam
# 299 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_BuyTMPsychic
# 300 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_BuyTMFlamethrower
# 301 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 4, MauvilleCity_GameCorner_OG_EventScript_BuyTMThunderbolt
# 302 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 5, MauvilleCity_GameCorner_OG_EventScript_BuyTMIceBeam
# 303 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 304 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 305 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMDoubleTeam::
# 306 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 307 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 308 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 309 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 310 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 311 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 312 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 313 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 314 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 315 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 316 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 317 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 318 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMPsychic::
# 319 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 320 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 321 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 322 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 323 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 324 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 325 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 326 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 327 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 328 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 329 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 330 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 331 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMFlamethrower::
# 332 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 333 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 334 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 335 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 336 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 337 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 338 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 339 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 340 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 341 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 342 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 343 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 344 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMThunderbolt::
# 345 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 346 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 347 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 348 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 349 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 350 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 351 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 352 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 353 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 354 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 355 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 356 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 357 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMIceBeam::
# 358 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 359 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 360 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 361 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 362 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 363 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 364 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 365 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 366 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 367 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 368 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 369 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 370 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM::
# 371 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 372 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 373 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 374 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 375 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM::
# 376 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_BagIsFull
# 377 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 378 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 379 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 380 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect::
# 381 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OhIsThatSo, MSGBOX_DEFAULT
# 382 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 0
# 383 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 384 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 385 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 386 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Woman2::
# 387 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 388 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 389 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 390 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Gentleman::
# 391 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RouletteOnlyLuck, MSGBOX_NPC
# 392 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 393 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 394 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Girl::
# 395 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 396 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 397 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 398 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 399 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_DeclineStarterDoll
# 400 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_STARTER_MON
# 401 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TREECKO, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 402 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TORCHIC, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 403 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MUDKIP, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 404 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PIPLUP, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 405 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_EEVEE, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 406 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PICHU, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 407 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TOGEPI, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 408 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SNIVY, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 409 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ZORUA_HISUI, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 410 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ZORUA, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 411 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_GOTHITA, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 412 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SOLOSIS, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 413 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_AXEW, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 414 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_LARVESTA, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 415 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_GOOMY, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 416 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ROWLET, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 417 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_APPLIN, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 418 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MIME_JR, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 419 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MAGBY, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 420 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ELEKID, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 421 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MANKEY, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 422 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SWINUB, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 423 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_LARVITAR, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 424 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TURTWIG, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 425 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CHARMANDER, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 426 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SQUIRTLE, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 427 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_BULBASAUR, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 428 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_OSHAWOTT, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 429 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CYNDAQUIL, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 430 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_BUDEW, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 431 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SPHEAL, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 432 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SHINX, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 433 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SANDILE, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 434 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PAWNIARD, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 435 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CASTFORM, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 436 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 437 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 438 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll::
# 439 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 440 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 441 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 442 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 443 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 444 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 445 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 446 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 447 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 448 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll::
# 449 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 450 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 451 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 452 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 453 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 454 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 455 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 456 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 457 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 458 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll::
# 459 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 460 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 461 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 462 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 463 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 464 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 465 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 466 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 467 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 468 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll::
# 469 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 470 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 471 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 472 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 473 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 474 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_DeclineStarterDoll::
# 475 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontBeNegative, MSGBOX_DEFAULT
# 476 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 477 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 478 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 479 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll::
# 480 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CantWinJackpot, MSGBOX_DEFAULT
# 481 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 482 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 483 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 484 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Uncle::
# 485 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 486 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 487 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, MauvilleCity_GameCorner_OG_EventScript_RetryRetrievingUncle
# 488 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_Uncle, MSGBOX_DEFAULT
# 489 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 490 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 16
# 491 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 2, MauvilleCity_GameCorner_OG_EventScript_TaskedWithRetrievingUncle
# 492 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 40
# 493 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 494 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_lt VAR_COIN_CASE_QUEST, 1, MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest
# 495 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 496 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 497 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 498 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_RetryRetrievingUncle::
# 499 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle1, MSGBOX_YESNO
# 500 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 501 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_DeclineRetryRetrievingUncle
# 502 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle2, MSGBOX_DEFAULT
# 503 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setfollowernpc LOCALID_GAMECORNER_UNCLE, FNPC_LEAVE_WHITEOUT, MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing
# 504 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	facefollowernpc
# 505 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 506 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 507 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 508 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle1:
# 509 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 510 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 511 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 512 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … Huh…?\p"
# 513 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh…\l"
# 514 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's you…\p"
# 515 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You're going to try to take me\n"
# 516 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "out of here again?$"
# 517 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 518 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle2:
# 519 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Fine.\p"
# 520 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Let's hurry up and get out of here…\l"
# 521 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "And don't get us into trouble this time!$"
# 522 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 523 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_DeclineRetryRetrievingUncle::
# 524 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DeclineRetryRetrievingUncle, MSGBOX_DEFAULT
# 525 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 526 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 60
# 527 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 528 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_lt VAR_COIN_CASE_QUEST, 1, MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest
# 529 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 530 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 531 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 532 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DeclineRetryRetrievingUncle:
# 533 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Then quit bothering… …\l"
# 534 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "me… … …$"
# 535 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 536 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest::
# 537 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 1
# 538 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 539 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 540 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TaskedWithRetrievingUncle::
# 541 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 542 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 543 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceLeft
# 544 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_NORTH, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceSouth
# 545 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceRight
# 546 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 547 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 10
# 548 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 549 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_PIN
# 550 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 551 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 5
# 552 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 553 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_TaskedWithRetrievingUncle, MSGBOX_YESNO
# 554 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_NephewMayBeWorried
# 555 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 556 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 557 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleEast
# 558 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleNorth
# 559 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleWest
# 560 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 561 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow2, MSGBOX_DEFAULT
# 562 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setfollowernpc LOCALID_GAMECORNER_UNCLE, FNPC_LEAVE_WHITEOUT, MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing
# 563 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	facefollowernpc
# 564 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 3
# 565 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 566 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 567 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 568 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleEast::
# 569 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 570 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 571 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 572 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 573 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 574 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 575 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 576 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleEast
# 577 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledEast
# 578 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 579 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 580 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 581 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 582 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 583 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 584 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 585 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 586 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 587 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleNorth::
# 588 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 589 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 590 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 591 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 592 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 593 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 594 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 595 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleNorth
# 596 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledNorth
# 597 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 598 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 599 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 600 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 601 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 602 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 603 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 604 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 605 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 606 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleWest::
# 607 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 608 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 609 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 610 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 611 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 612 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 613 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 614 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleWest
# 615 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledWest
# 616 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 617 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 618 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 619 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 620 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 621 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 622 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 623 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 624 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 625 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewMayBeWorried::
# 626 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	@msgbox MauvilleCity_GameCorner_OG_Text_NephewMayBeWorried, MSGBOX_DEFAULT
# 627 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 628 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 629 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 630 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedEast
# 631 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedNorth
# 632 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedWest
# 633 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 634 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 635 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 636 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedEast::
# 637 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 638 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 639 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 640 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 641 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 642 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 643 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 644 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 645 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 646 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 647 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedNorth::
# 648 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 649 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 650 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 651 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 652 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 653 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 654 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 655 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 656 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 657 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 658 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedWest::
# 659 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 660 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 661 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 662 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 663 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 664 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 665 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 666 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 667 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 668 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 669 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing::
# 670 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OrCanGoBack, MSGBOX_YESNO
# 671 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_GameCorner_OG_EventScript_FollowingUncleLeaves
# 672 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UncleIsFollowing, MSGBOX_DEFAULT
# 673 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 674 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 675 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 676 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_FollowingUncleLeaves::
# 677 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UncleStopsFollowing, MSGBOX_DEFAULT
# 678 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 679 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	destroyfollowernpc
# 680 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	warpinplace
# 681 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 682 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 683 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	
# 684 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 685 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_OrCanGoBack:
# 686 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Will you just mind your own\n"
# 687 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "business and leave me alone?$"
# 688 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 689 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UncleStopsFollowing:
# 690 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "WOOHOO!\l"
# 691 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Finally!$"
# 692 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 693 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PokefanM::
# 694 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 695 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 696 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 697 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_TryGive20Coins
# 698 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 699 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 700 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 701 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 702 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TryGive20Coins::
# 703 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal
# 704 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 705 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 706 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 707 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 20
# 708 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 709 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 710 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal
# 711 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 712 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 713 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal::
# 714 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 715 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 716 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 717 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 718 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_OldMan::
# 719 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 720 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 721 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 722 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 723 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 724 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 725 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Cook::
# 726 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 727 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 728 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 729 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 730 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 731 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 732 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Man::
# 733 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 734 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 735 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 736 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 737 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 738 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 739 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots::
# 740 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 741 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 742 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 743 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 744 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 745 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 746 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Maniac::
# 747 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 748 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 749 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 750 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 751 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 752 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 753 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Woman::
# 754 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 755 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 756 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 757 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 758 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 759 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 760 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine0::
# 761 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 762 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 763 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 764 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 0
# 765 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 766 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 767 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 768 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 769 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 770 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine1::
# 771 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 772 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 773 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 774 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 1
# 775 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 776 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 777 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 778 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 779 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 780 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine2::
# 781 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 782 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 783 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 784 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 2
# 785 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 786 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 787 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 788 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 789 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 790 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine3::
# 791 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 792 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 793 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 794 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 3
# 795 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 796 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 797 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 798 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 799 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 800 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine4::
# 801 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 802 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 803 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 804 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 4
# 805 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 806 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 807 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 808 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 809 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 810 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine5::
# 811 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 812 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 813 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 814 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 5
# 815 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 816 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 817 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 818 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 819 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 820 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine6::
# 821 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 822 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 823 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 824 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 6
# 825 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 826 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 827 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 828 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 829 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 830 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine7::
# 831 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 832 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 833 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 834 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 7
# 835 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 836 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 837 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 838 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 839 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 840 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine8::
# 841 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 842 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 843 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 844 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 8
# 845 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 846 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 847 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 848 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 849 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 850 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine9::
# 851 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 852 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 853 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 854 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 9
# 855 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 856 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 857 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 858 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 859 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 860 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine10::
# 861 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 862 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 863 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 864 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 10
# 865 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 866 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 867 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 868 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 869 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 870 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine11::
# 871 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 872 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 873 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 874 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 11
# 875 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 876 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 877 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 878 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 879 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 880 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoCoinCase::
# 881 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 882 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 883 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 884 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 885 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleEast:
# 886 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 887 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 888 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 889 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 890 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 891 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 892 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 893 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 894 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 895 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 896 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 897 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledEast:
# 898 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 899 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 900 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 901 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 902 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 903 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 904 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 905 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 906 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleNorth:
# 907 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 908 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 909 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 910 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 911 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 912 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 913 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 914 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 915 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 916 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 917 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 918 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledNorth:
# 919 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 920 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 921 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 922 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 923 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 924 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 925 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 926 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 927 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleWest:
# 928 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 929 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 930 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 931 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 932 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 933 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 934 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 935 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 936 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 937 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 938 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 939 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledWest:
# 940 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 941 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 942 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 943 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 944 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 945 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 946 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 947 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 948 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceLeft::
# 949 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceLeft
# 950 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 951 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 952 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 953 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceLeft:
# 954 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 955 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 956 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 957 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceSouth::
# 958 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceSouth
# 959 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 960 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 961 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 962 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceSouth:
# 963 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_down
# 964 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 965 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 966 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceRight::
# 967 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceRight
# 968 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 969 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 970 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 971 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceRight:
# 972 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 973 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 974 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 975 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_Uncle:
# 976 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 977 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 978 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 979 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … Huh…?\p"
# 980 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh…!\l"
# 981 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Uh…\p"
# 982 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "No, I wasn't sleeping…\p"
# 983 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Everything is under control!$"
# 984 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 985 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DriftingOffAgain:
# 986 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "He seemed to start drifting off again…$"
# 987 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 988 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NephewMayBeWorried:
# 989 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "His nephew is probably really worried!$"
# 990 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 991 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1:
# 992 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Hey! Lay off me you grubby youth!$"
# 993 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 994 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow2:
# 995 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 996 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … What?\p"
# 997 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "My nephew? And my wife?\p"
# 998 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "But I just got here…!\p"
# 999 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Grr… Fine!\n"
# 1000 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Let's hurry back…\p"
# 1001 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I'll just show them I'm okay…\p" 
# 1002 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "and then…\p"
# 1003 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "then maybe I can come back!$"
# 1004 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1005 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UncleIsFollowing:
# 1006 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Then let's get a move on!\n"
# 1007 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The sooner I can show my family\l"
# 1008 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "that I'm okay, the sooner I can\l"
# 1009 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "get back to the slots!$"
# 1010 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1011 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_TaskedWithRetrievingUncle:
# 1012 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This must be the missing uncle of\n"
# 1013 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "that kid from PETALBURG!\p"
# 1014 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Try to convince him to come with you?$"
# 1015 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1016 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ThisIsMauvilleGameCorner:
# 1017 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"
# 1018 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1019 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NeedCoinCaseForCoins:
# 1020 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Okay, you wanted some COINS for\n"
# 1021 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the games?\p"
# 1022 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "But you don't have a COIN CASE for\n"
# 1023 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "stowing the COINS.$"
# 1024 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1025 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_WereYouLookingForCoins:
# 1026 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Were you looking for COINS?\p"
# 1027 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's ¥1000 for 50 COINS.\n"
# 1028 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Would you like some?$"
# 1029 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1030 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins:
# 1031 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Thank you very much!\n"
# 1032 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here are your COINS!$"
# 1033 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1034 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontHaveEnoughMoney:
# 1035 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Um… You don't appear to have\n"
# 1036 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "enough money…$"
# 1037 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1038 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CoinCaseIsFull:
# 1039 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh?\n"
# 1040 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Your COIN CASE is full.$"
# 1041 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1042 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontNeedCoinsThen:
# 1043 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh… You don't need COINS, then?\n"
# 1044 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Good luck on your adventure!$"
# 1045 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1046 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes:
# 1047 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Welcome.\p"
# 1048 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can exchange your COINS for\n"
# 1049 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "prizes here.$"
# 1050 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1051 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_WhichPrize:
# 1052 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Which prize would you like?$"
# 1053 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1054 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheTMX:
# 1055 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "So your choice is\n"
# 1056 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
# 1057 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1058 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SendToYourHomePC:
# 1059 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Thank you!\n"
# 1060 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 1061 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1062 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NotEnoughCoins:
# 1063 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You don't have enough COINS.$"
# 1064 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1065 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 1066 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NoRoomForPlacingDecor:
# 1067 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "There isn't any room available for\n"
# 1068 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 1069 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1070 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_OhIsThatSo:
# 1071 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, is that so? \n"
# 1072 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You need to save some COINS before\l"
# 1073 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "coming back here.$"
# 1074 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1075 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsX:
# 1076 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 1077 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1078 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HereYouGo:
# 1079 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here you go!$"
# 1080 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1081 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 1082 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantCarryAnyMore:
# 1083 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 1084 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1085 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_GotTwoOfSameDollWantOne:
# 1086 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I made a mistake and got two of\n"
# 1087 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the same DOLLS.\p"
# 1088 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Would you like one of them?$"
# 1089 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1090 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HereYouGo2:
# 1091 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here you go!$"
# 1092 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1093 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_YouWantItButNotNow:
# 1094 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Huh?\n"
# 1095 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You want it, but not right now?$"
# 1096 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1097 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontBeNegative:
# 1098 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 1099 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can have this!$"
# 1100 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1101 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantWinJackpot:
# 1102 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 1103 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the jackpot.$"
# 1104 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1105 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NeedCoinCaseGoNextDoor:
# 1106 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 1107 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "you need a COIN CASE.\p"
# 1108 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I think the young lady next door\n"
# 1109 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "had one. Go see her!$"
# 1110 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1111 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_LuckOnlyLastSoLongTakeCoins:
# 1112 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "My luck can only last so long.\n"
# 1113 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This is too much for me.\l"
# 1114 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here, take some COINS!$"
# 1115 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1116 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_MauvilleSomethingForEveryone:
# 1117 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "MAUVILLE has something for\n"
# 1118 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "everyone.\p"
# 1119 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "For me, it's the GAME CORNER.$"
# 1120 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1121 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RouletteTablesDifferentRates:
# 1122 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The ROULETTE tables have different\n"
# 1123 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "rates.\p"
# 1124 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Check your COINS if you're going to\n"
# 1125 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "pick a table.$"
# 1126 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1127 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_EasyToLoseTrackOfTime:
# 1128 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 1129 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I should get back to work.$"
# 1130 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1131 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CoinsAreNeededToPlay:
# 1132 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "COINS are needed to play here\n"
# 1133 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "in the GAME CORNER.$"
# 1134 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1135 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RouletteOnlyLuck:
# 1136 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This ROULETTE thing…\n"
# 1137 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's rather demanding.\p"
# 1138 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 1139 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1140 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UpTo3CoinsCanBeUsed:
# 1141 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Up to three COINS can be used to play\n"
# 1142 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the SLOTS.$"
# 1143 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1144 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DifficultToStopOn7:
# 1145 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 1146 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "right on “7.”\p"
# 1147 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "If it stops on “7” during the REEL TIME\n"
# 1148 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "bonus game, you'll receive extra COINS.$"
# 1149 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1150 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HeresSomeSlotsInfo:
# 1151 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here's some information for you\n"
# 1152 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "about the SLOTS.\p"
# 1153 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 1154 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the more REEL TIME chances you get.\p"
# 1155 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "In a game with the maximum five\n"
# 1156 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "REEL TIME chances…\p"
# 1157 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It is possible to receive four regular\n"
# 1158 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 1159 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "That would total 660 COINS, but it's\n"
# 1160 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "very difficult to get.$"
# 1161 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1162 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantPlayWithNoCoinCase:
# 1163 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can't play if you don't have\n"
# 1164 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "a COIN CASE.$"
