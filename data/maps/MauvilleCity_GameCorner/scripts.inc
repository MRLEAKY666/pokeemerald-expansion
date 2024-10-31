# 1 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 2 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_MapScripts::
# 3 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.byte 0
# 4 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 5 "data//maps/MauvilleCity_GameCorner/scripts.pory"
    @ Game Corner prices
# 6 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 7 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 8 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 9 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 10 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 11 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS, 1000
# 12 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 13 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,  1000
# 14 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500, 10000
# 15 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 16 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CoinsClerk::
# 17 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 18 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 19 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 20 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 21 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 22 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
# 23 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 24 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 25 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 6
# 26 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
# 27 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 28 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
# 29 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 30 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 31 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 32 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 33 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 34 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 35 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 36 "data//maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 37 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
# 38 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 39 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 40 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 41 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 42 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 43 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 44 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 45 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy50Coins::
# 46 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 47 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 48 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_50
# 49 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 50 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 50
# 51 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_50
# 52 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 53 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 54 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 55 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 56 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 57 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 58 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 59 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 60 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 61 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy500Coins::
# 62 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 63 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 64 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_500
# 65 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 66 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 500
# 67 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_500
# 68 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 69 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 70 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 71 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 72 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 73 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 74 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 75 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 76 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 77 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NeedCoinCase::
# 78 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 79 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 80 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 81 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 82 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
# 83 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 84 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 85 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 86 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 87 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 88 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 89 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
# 90 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 91 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 92 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 93 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 94 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 95 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 96 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
# 97 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 98 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 99 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 100 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 101 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 102 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 103 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
# 104 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 105 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 106 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 107 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 108 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
# 109 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 110 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 111 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 112 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
# 113 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 114 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 115 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 116 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 117 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 118 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 119 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
# 120 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 121 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 122 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 123 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 124 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
# 125 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 126 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 127 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
# 128 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
# 129 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
# 130 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 131 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 132 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 133 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 134 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TreeckoDoll::
# 135 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 136 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 137 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 138 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 139 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TorchicDoll::
# 140 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 141 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 142 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 143 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 144 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MudkipDoll::
# 145 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 146 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 147 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 148 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 149 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
# 150 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 151 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 152 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 153 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
# 154 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
# 155 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
# 156 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 157 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 158 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
# 159 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 160 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 161 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 162 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 163 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 164 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 165 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 166 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 167 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 168 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 169 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 170 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 171 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 172 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
# 173 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 174 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 175 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 176 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 177 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 178 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 179 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 180 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 181 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 182 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 183 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 184 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 185 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 186 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
# 187 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 188 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 189 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 190 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 191 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 192 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 193 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 194 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 195 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 196 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 197 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 198 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 199 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 200 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
# 201 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 202 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 203 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 204 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 205 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
# 206 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 207 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 208 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 209 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 210 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelDollSelect::
# 211 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 212 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 213 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 214 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 215 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 216 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
# 217 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 218 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 219 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 220 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 221 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
# 222 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 223 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 224 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 225 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
# 226 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 227 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 228 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 229 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 230 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 231 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 232 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
# 233 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 234 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 235 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 236 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 237 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
# 238 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
# 239 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 240 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
# 241 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
# 242 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
# 243 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
# 244 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
# 245 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 246 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 247 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 248 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 249 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
# 250 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 251 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 252 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 253 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 254 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 255 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMPsychic::
# 256 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 257 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 258 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 259 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 260 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 261 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMFlamethrower::
# 262 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 263 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 264 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 265 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 266 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 267 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMThunderbolt::
# 268 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 4
# 269 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 270 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 271 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 272 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 273 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMIceBeam::
# 274 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 5
# 275 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 276 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 277 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 278 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 279 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
# 280 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	special BufferTMHMMoveName
# 281 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
# 282 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 283 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 284 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
# 285 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
# 286 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
# 287 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
# 288 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
# 289 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 290 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 291 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
# 292 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 293 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 294 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 295 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 296 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 297 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 298 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 299 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 300 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 301 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 302 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 303 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 304 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
# 305 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 306 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 307 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 308 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 309 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 310 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 311 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 312 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 313 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 314 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 315 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 316 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 317 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
# 318 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 319 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 320 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 321 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 322 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 323 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 324 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 325 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 326 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 327 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 328 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 329 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 330 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
# 331 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 332 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 333 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 334 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 335 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 336 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 337 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 338 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 339 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 340 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 341 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 342 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 343 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
# 344 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 345 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 346 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 347 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 348 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 349 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 350 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 351 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 352 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 353 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 354 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 355 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 356 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
# 357 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 358 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 359 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 360 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 361 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForTM::
# 362 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 363 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 364 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 365 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 366 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelTMSelect::
# 367 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 368 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 369 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 370 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 371 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 372 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman2::
# 373 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 374 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 375 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 376 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gentleman::
# 377 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
# 378 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 379 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 380 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Girl::
# 381 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 382 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 383 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 384 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 385 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
# 386 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_STARTER_MON
# 387 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_TREECKO, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 388 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_TORCHIC, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 389 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_MUDKIP, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 390 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_CASTFORM, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 391 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_PIPLUP, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 392 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_EEVEE, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 393 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_PICHU, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 394 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_TOGEPI, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 395 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_PORYGON, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 396 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_SNIVY, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 397 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 398 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_ZORUA, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 399 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_GOTHITA, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 400 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_SOLOSIS, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 401 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_AXEW, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 402 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_LARVESTA, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 403 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_GOOMY, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 404 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_ROWLET, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 405 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_APPLIN, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 406 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_MIME_JR, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 407 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_MAGBY, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 408 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_ELEKID, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 409 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_MANKEY, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 410 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_SWINUB, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 411 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	case SPECIES_LARVITAR, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 412 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 413 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 414 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
# 415 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 416 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 417 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 418 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 419 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 420 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 421 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 422 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 423 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 424 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
# 425 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 426 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 427 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 428 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 429 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 430 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 431 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 432 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 433 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 434 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
# 435 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 436 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 437 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 438 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 439 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 440 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 441 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 442 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 443 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 444 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
# 445 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 446 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 447 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 448 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 449 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 450 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
# 451 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
# 452 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 453 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 454 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 455 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
# 456 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
# 457 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 458 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 459 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 460 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanM::
# 461 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 462 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 463 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 464 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
# 465 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 466 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 467 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 468 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 469 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TryGive20Coins::
# 470 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 471 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 472 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 473 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 474 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 20
# 475 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 476 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 477 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 478 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 479 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 480 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanMNormal::
# 481 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 482 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 483 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 484 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 485 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_OldMan::
# 486 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 487 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 488 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 489 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 490 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 491 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 492 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cook::
# 493 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 494 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 495 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 496 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 497 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 498 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 499 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Man::
# 500 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 501 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 502 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 503 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 504 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 505 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 506 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
# 507 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 508 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 509 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 510 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 511 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 512 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 513 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Maniac::
# 514 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 515 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 516 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 517 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 518 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 519 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 520 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman::
# 521 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 522 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 523 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 524 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 525 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 526 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 527 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine0::
# 528 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 529 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 530 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 531 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 532 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 533 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 534 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 535 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 536 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 537 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine1::
# 538 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 539 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 540 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 541 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 542 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 543 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 544 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 545 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 546 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 547 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine2::
# 548 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 549 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 550 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 551 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 552 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 553 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 554 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 555 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 556 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 557 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine3::
# 558 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 559 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 560 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 561 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 562 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 563 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 564 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 565 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 566 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 567 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine4::
# 568 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 569 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 570 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 571 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 572 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 573 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 574 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 575 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 576 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 577 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine5::
# 578 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 579 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 580 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 581 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 582 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 583 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 584 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 585 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 586 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 587 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine6::
# 588 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 589 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 590 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 591 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 592 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 593 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 594 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 595 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 596 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 597 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine7::
# 598 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 599 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 600 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 601 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 602 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 603 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 604 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 605 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 606 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 607 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine8::
# 608 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 609 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 610 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 611 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 612 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 613 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 614 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 615 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 616 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 617 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine9::
# 618 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 619 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 620 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 621 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 622 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 623 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 624 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 625 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 626 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 627 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine10::
# 628 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 629 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 630 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 631 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 632 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 633 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 634 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 635 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 636 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 637 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine11::
# 638 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 639 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 640 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 641 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 642 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 643 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 644 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 645 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 646 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 647 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase::
# 648 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 649 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 650 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 651 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 652 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
# 653 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"
# 654 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 655 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
# 656 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some COINS for\n"
# 657 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the games?\p"
# 658 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But you don't have a COIN CASE for\n"
# 659 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "stowing the COINS.$"
# 660 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 661 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
# 662 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for COINS?\p"
# 663 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ¥1000 for 50 COINS.\n"
# 664 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like some?$"
# 665 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 666 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
# 667 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much!\n"
# 668 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here are your COINS!$"
# 669 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 670 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
# 671 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have\n"
# 672 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "enough money…$"
# 673 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 674 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinCaseIsFull:
# 675 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh?\n"
# 676 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Your COIN CASE is full.$"
# 677 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 678 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
# 679 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need COINS, then?\n"
# 680 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Good luck on your adventure!$"
# 681 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 682 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
# 683 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 684 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your COINS for\n"
# 685 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "prizes here.$"
# 686 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 687 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPrize:
# 688 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"
# 689 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 690 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
# 691 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is\n"
# 692 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
# 693 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 694 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SendToYourHomePC:
# 695 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\n"
# 696 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 697 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 698 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NotEnoughCoins:
# 699 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS.$"
# 700 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 701 "data//maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 702 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
# 703 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
# 704 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 705 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 706 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_OhIsThatSo:
# 707 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? \n"
# 708 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to save some COINS before\l"
# 709 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "coming back here.$"
# 710 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 711 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
# 712 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 713 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 714 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo:
# 715 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 716 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 717 "data//maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 718 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
# 719 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 720 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 721 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
# 722 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of\n"
# 723 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the same DOLLS.\p"
# 724 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like one of them?$"
# 725 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 726 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo2:
# 727 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 728 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 729 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_YouWantItButNotNow:
# 730 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh?\n"
# 731 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want it, but not right now?$"
# 732 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 733 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontBeNegative:
# 734 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 735 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can have this!$"
# 736 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 737 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantWinJackpot:
# 738 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 739 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the jackpot.$"
# 740 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 741 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
# 742 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 743 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "you need a COIN CASE.\p"
# 744 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I think the young lady next door\n"
# 745 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "had one. Go see her!$"
# 746 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 747 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
# 748 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long.\n"
# 749 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is too much for me.\l"
# 750 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here, take some COINS!$"
# 751 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 752 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
# 753 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "MAUVILLE has something for\n"
# 754 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "everyone.\p"
# 755 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "For me, it's the GAME CORNER.$"
# 756 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 757 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
# 758 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The ROULETTE tables have different\n"
# 759 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rates.\p"
# 760 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Check your COINS if you're going to\n"
# 761 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick a table.$"
# 762 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 763 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
# 764 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 765 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I should get back to work.$"
# 766 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 767 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
# 768 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "COINS are needed to play here\n"
# 769 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in the GAME CORNER.$"
# 770 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 771 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
# 772 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This ROULETTE thing…\n"
# 773 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's rather demanding.\p"
# 774 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 775 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 776 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
# 777 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three COINS can be used to play\n"
# 778 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the SLOTS.$"
# 779 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 780 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DifficultToStopOn7:
# 781 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 782 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "right on “7.”\p"
# 783 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "If it stops on “7” during the REEL TIME\n"
# 784 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonus game, you'll receive extra COINS.$"
# 785 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 786 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
# 787 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you\n"
# 788 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "about the SLOTS.\p"
# 789 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 790 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the more REEL TIME chances you get.\p"
# 791 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "In a game with the maximum five\n"
# 792 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "REEL TIME chances…\p"
# 793 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It is possible to receive four regular\n"
# 794 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 795 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "That would total 660 COINS, but it's\n"
# 796 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "very difficult to get.$"
# 797 "data//maps/MauvilleCity_GameCorner/scripts.pory"

# 798 "data//maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
# 799 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have\n"
# 800 "data//maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a COIN CASE.$"
