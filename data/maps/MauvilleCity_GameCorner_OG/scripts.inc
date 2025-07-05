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
	.set ELECTIRIZER_COINS, 1500
# 14 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set MAGMARIZER_COINS, 1500
# 15 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set PROTECTOR_COINS, 1500
# 16 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set UPGRADE_COINS, 2000
# 17 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set DUBIOUS_DISC_COINS, 2500 
# 18 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set METAL_COAT_COINS, 2500
# 19 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set LINKING_CORD_COINS, 4000
# 20 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 21 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set COINS_PRICE_50,  1000
# 22 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.set COINS_PRICE_500, 10000
# 23 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 24 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_OnTransition::
# 25 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, MauvilleCity_GameCorner_OG_EventScript_TryResetAfterFailed
# 26 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 27 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 28 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TryResetAfterFailed::
# 29 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkfollowernpc
# 30 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_ResetAfterFailed
# 31 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 32 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 33 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ResetAfterFailed::
# 34 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	clearflag FLAG_GAME_CORNER_UNC
# 35 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 36 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 37 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CoinsClerk::
# 38 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 39 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 40 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 41 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 42 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NeedCoinCase
# 43 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WereYouLookingForCoins
# 44 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 45 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showmoneybox 0, 0
# 46 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 6
# 47 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault50
# 48 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 49 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault50::
# 50 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 51 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 52 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_Buy50Coins
# 53 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_Buy500Coins
# 54 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins
# 55 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 56 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 57 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 58 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseCoinsDefault500::
# 59 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 60 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 61 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_Buy50Coins
# 62 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_Buy500Coins
# 63 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins
# 64 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 65 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 66 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Buy50Coins::
# 67 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 68 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins
# 69 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkmoney COINS_PRICE_50
# 70 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney
# 71 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 50
# 72 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removemoney COINS_PRICE_50
# 73 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatemoneybox
# 74 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 6
# 75 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 76 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 77 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 78 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 79 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 80 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 81 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 82 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Buy500Coins::
# 83 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 84 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins
# 85 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkmoney COINS_PRICE_500
# 86 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney
# 87 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 500
# 88 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removemoney COINS_PRICE_500
# 89 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatemoneybox
# 90 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 6
# 91 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 92 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 93 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 94 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 95 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 96 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 97 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 98 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NeedCoinCase::
# 99 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 100 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 101 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 102 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 103 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughMoney::
# 104 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
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
MauvilleCity_GameCorner_OG_EventScript_CancelBuyCoins::
# 111 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
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
MauvilleCity_GameCorner_OG_EventScript_NoRoomForCoins::
# 118 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 119 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidemoneybox
# 120 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 5
# 121 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 122 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 123 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 124 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PrizeCornerDolls::
# 125 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 126 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 127 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 128 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 129 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrizeMessage
# 130 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 131 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 132 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 133 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrizeMessage::
# 134 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 135 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 136 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 0
# 137 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 1
# 138 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize
# 139 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 140 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize::
# 141 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 142 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 143 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize
# 144 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 145 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseDollPrize::
# 146 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 147 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 148 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_TreeckoDoll
# 149 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_TorchicDoll
# 150 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_MudkipDoll
# 151 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 152 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 153 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 154 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 155 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TreeckoDoll::
# 156 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 1
# 157 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 158 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 159 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 160 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TorchicDoll::
# 161 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 2
# 162 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 163 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 164 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 165 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_MudkipDoll::
# 166 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 3
# 167 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 168 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize
# 169 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 170 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ConfirmDollPrize::
# 171 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 172 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect
# 173 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_TEMP_1
# 174 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_BuyTreeckoDoll
# 175 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_BuyTorchicDoll
# 176 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_BuyMudkipDoll
# 177 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 178 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 179 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTreeckoDoll::
# 180 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 181 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 182 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 183 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 184 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 185 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 186 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 187 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 188 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 189 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 190 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 191 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 192 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 193 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTorchicDoll::
# 194 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 195 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 196 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 197 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 198 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 199 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 200 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 201 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 202 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 203 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 204 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 205 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 206 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 207 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyMudkipDoll::
# 208 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 209 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll
# 210 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 211 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 212 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll
# 213 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DOLL_COINS
# 214 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 215 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 216 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 217 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 218 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 219 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 220 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 221 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForDoll::
# 222 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 223 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 224 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 225 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 226 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForDoll::
# 227 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 228 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseDollPrize
# 229 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 230 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 231 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CancelDollSelect::
# 232 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OhIsThatSo, MSGBOX_DEFAULT
# 233 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 0
# 234 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 235 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 236 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 237 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PrizeCornerTMs::
# 238 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 239 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 240 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 241 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 242 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrizeMessage
# 243 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 244 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 245 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 246 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrizeMessage::
# 247 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 248 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 249 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 0
# 250 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	showcoinsbox 1, 1
# 251 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize
# 252 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 253 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize::
# 254 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	message MauvilleCity_GameCorner_OG_Text_WhichPrize
# 255 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmessage
# 256 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize::
# 262 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	dynmultichoice 10, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_0, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_1, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_2, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_3, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_4, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_5, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_6, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_7, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_8, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_9, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_10, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_11, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_12
# 268 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_RESULT
# 269 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 0, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_3
# 271 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_4
# 273 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_5
# 275 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_6
# 277 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 4, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_7
# 279 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 5, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_8
# 281 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 6, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_9
# 283 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 7, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_10
# 285 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 8, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_11
# 287 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 9, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_12
# 289 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 10, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_13
# 291 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 11, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_14
# 293 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 12, MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_15
MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1:
# 296 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_3:
# 270 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_TMDoubleTeam
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_4:
# 272 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_TMPsychic
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_5:
# 274 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_TMFlamethrower
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_6:
# 276 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_TMThunderbolt
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_7:
# 278 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_TMIceBeam
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_8:
# 280 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_Electirizer
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_9:
# 282 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_Magmarizer
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_10:
# 284 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_Protector
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_11:
# 286 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_Upgrade
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_12:
# 288 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_DubiousDisc
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_13:
# 290 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_MetalCoat
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_14:
# 292 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_LinkingCord
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_15:
# 294 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_1


# 300 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 301 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 302 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMDoubleTeam::
# 303 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 1
# 304 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 305 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 306 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 307 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 308 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMPsychic::
# 309 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 2
# 310 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 311 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 312 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 313 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 314 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMFlamethrower::
# 315 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 3
# 316 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 317 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 318 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 319 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 320 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMThunderbolt::
# 321 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 4
# 322 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 323 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 324 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 325 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 326 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TMIceBeam::
# 327 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 5
# 328 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 329 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 330 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 331 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 332 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Electirizer::
# 333 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 6
# 334 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ELECTIRIZER
# 335 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_ELECTIRIZER
# 336 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 337 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 338 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Magmarizer::
# 339 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 7
# 340 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_MAGMARIZER
# 341 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGMARIZER
# 342 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 343 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 344 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Protector::
# 345 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 8
# 346 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTECTOR
# 347 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_PROTECTOR
# 348 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 349 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 350 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Upgrade::
# 351 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 9
# 352 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_UPGRADE
# 353 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_UPGRADE
# 354 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 355 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 356 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_DubiousDisc::
# 357 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 10
# 358 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_DUBIOUS_DISC
# 359 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_DUBIOUS_DISC
# 360 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 361 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 362 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_MetalCoat::
# 363 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 11
# 364 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_METAL_COAT
# 365 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_METAL_COAT
# 366 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize
# 367 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 368 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_LinkingCord::
# 369 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_TEMP_1, 12
# 370 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_LINKING_CORD
# 371 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, ITEM_LINKING_CORD
# 372 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize::
# 375 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	compare VAR_TEMP_1, 5
	goto_if_le MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_2
# 380 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheItem, MSGBOX_YESNO
MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_1:
# 382 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect
# 383 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_TEMP_1
# 384 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 1, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_7
# 386 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 2, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_8
# 388 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 3, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_9
# 390 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 4, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_10
# 392 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 5, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_11
# 394 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 6, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_12
# 396 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 7, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_13
# 398 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 8, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_14
# 400 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 9, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_15
# 402 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 10, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_16
# 404 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 11, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_17
# 406 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case 12, MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_18
MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5:
	end

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_2:
# 376 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	special BufferTMHMMoveName
# 377 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_1

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_7:
# 385 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyTMDoubleTeam
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_8:
# 387 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyTMPsychic
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_9:
# 389 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyTMFlamethrower
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_10:
# 391 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyTMThunderbolt
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_11:
# 393 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyTMIceBeam
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_12:
# 395 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyElectirizer
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_13:
# 397 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyMagmarizer
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_14:
# 399 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyProtector
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_15:
# 401 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyUpgrade
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_16:
# 403 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyDubiousDisc
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_17:
# 405 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyMetalCoat
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5

MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_18:
# 407 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_BuyLinkingCord
	goto MauvilleCity_GameCorner_OG_EventScript_ConfirmTMPrize_5


# 412 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 413 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMDoubleTeam::
# 414 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 415 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 416 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 417 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 418 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 419 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 420 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 421 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 422 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 423 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 424 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 425 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 426 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMPsychic::
# 427 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 428 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 429 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 430 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 431 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 432 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 433 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 434 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 435 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 436 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 437 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 438 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 439 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMFlamethrower::
# 440 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 441 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 442 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 443 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 444 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 445 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 446 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 447 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 448 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 449 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 450 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 451 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 452 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMThunderbolt::
# 453 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 454 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 455 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 456 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 457 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 458 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 459 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 460 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 461 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 462 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 463 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 464 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 465 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyTMIceBeam::
# 466 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 467 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 468 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 469 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 470 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 471 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 472 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 473 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 474 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 475 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 476 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 477 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 478 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyUpgrade::
# 479 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 480 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, UPGRADE_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 481 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_UPGRADE
# 482 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 483 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins UPGRADE_COINS
# 484 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_UPGRADE
# 485 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 486 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 487 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 488 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 489 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 490 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 491 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyDubiousDisc::
# 492 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 493 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, DUBIOUS_DISC_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 494 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_DUBIOUS_DISC
# 495 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 496 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins DUBIOUS_DISC_COINS
# 497 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_DUBIOUS_DISC
# 498 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 499 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 500 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 501 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 502 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 503 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 504 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyElectirizer::
# 505 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 506 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, ELECTIRIZER_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 507 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_ELECTIRIZER
# 508 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 509 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins ELECTIRIZER_COINS
# 510 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_ELECTIRIZER
# 511 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 512 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 513 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 514 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 515 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 516 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 517 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyMagmarizer::
# 518 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 519 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, MAGMARIZER_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 520 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_MAGMARIZER
# 521 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 522 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins MAGMARIZER_COINS
# 523 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_MAGMARIZER
# 524 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 525 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 526 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 527 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 528 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 529 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 530 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyProtector::
# 531 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 532 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, PROTECTOR_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 533 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_PROTECTOR
# 534 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 535 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins PROTECTOR_COINS
# 536 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_PROTECTOR
# 537 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 538 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 539 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 540 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 541 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 542 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 543 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyMetalCoat::
# 544 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 545 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, METAL_COAT_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 546 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_METAL_COAT
# 547 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 548 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins METAL_COAT_COINS
# 549 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_METAL_COAT
# 550 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 551 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 552 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 553 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 554 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 555 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 556 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_BuyLinkingCord::
# 557 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_2
# 558 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_lt VAR_TEMP_2, LINKING_CORD_COINS, MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM
# 559 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitemspace ITEM_LINKING_CORD
# 560 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM
# 561 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	removecoins LINKING_CORD_COINS
# 562 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	additem ITEM_LINKING_CORD
# 563 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	updatecoinsbox 1, 1
# 564 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 565 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo, MSGBOX_DEFAULT
# 566 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 567 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 568 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 569 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NotEnoughCoinsForTM::
# 570 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 571 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 572 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 573 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 574 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForTM::
# 575 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_BagIsFull
# 576 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReturnToChooseTMPrize
# 577 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 578 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 579 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_CancelTMSelect::
# 580 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OhIsThatSo, MSGBOX_DEFAULT
# 581 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	hidecoinsbox 0, 0
# 582 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 583 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 584 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 585 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Woman2::
# 586 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 587 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 588 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 589 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Gentleman::
# 590 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RouletteOnlyLuck, MSGBOX_NPC
# 591 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 592 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 593 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Girl::
# 594 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 595 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 596 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 597 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 598 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_DeclineStarterDoll
# 599 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	switch VAR_STARTER_MON
# 600 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TREECKO, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 601 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TORCHIC, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 602 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MUDKIP, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 603 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PIPLUP, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 604 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_EEVEE, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 605 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PICHU, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 606 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TOGEPI, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 607 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SNIVY, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 608 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ZORUA_HISUI, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 609 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ZORUA, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 610 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_GOTHITA, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 611 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SOLOSIS, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 612 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_AXEW, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 613 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_LARVESTA, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 614 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_GOOMY, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 615 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ROWLET, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 616 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_APPLIN, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 617 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MIME_JR, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 618 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MAGBY, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 619 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_ELEKID, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 620 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_MANKEY, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 621 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SWINUB, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 622 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_LARVITAR, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 623 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_TURTWIG, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 624 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CHARMANDER, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 625 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SQUIRTLE, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 626 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_BULBASAUR, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 627 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_OSHAWOTT, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 628 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CYNDAQUIL, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 629 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_BUDEW, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 630 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SPHEAL, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 631 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SHINX, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 632 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_SANDILE, MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll
# 633 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_PAWNIARD, MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll
# 634 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	case SPECIES_CASTFORM, MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll
# 635 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 636 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 637 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveTreeckoDoll::
# 638 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 639 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 640 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 641 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 642 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 643 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 644 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 645 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 646 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 647 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveTorchicDoll::
# 648 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 649 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 650 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 651 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 652 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 653 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 654 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 655 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 656 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 657 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_GiveMudkipDoll::
# 658 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 659 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 660 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll
# 661 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HereYouGo2, MSGBOX_DEFAULT
# 662 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 663 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 664 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll
# 665 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 666 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 667 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoRoomForStarterDoll::
# 668 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 669 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 670 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 671 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 672 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 673 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_DeclineStarterDoll::
# 674 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DontBeNegative, MSGBOX_DEFAULT
# 675 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 676 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 677 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 678 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_ReceivedStarterDoll::
# 679 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CantWinJackpot, MSGBOX_DEFAULT
# 680 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 681 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 682 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 683 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Uncle::
# 684 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 685 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 686 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, MauvilleCity_GameCorner_OG_EventScript_RetryRetrievingUncle
# 687 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_Uncle, MSGBOX_DEFAULT
# 688 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 689 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 16
# 690 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 2, MauvilleCity_GameCorner_OG_EventScript_TaskedWithRetrievingUncle
# 691 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 692 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_SNORE
# 693 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 40
# 694 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 695 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 696 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_lt VAR_COIN_CASE_QUEST, 1, MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest
# 697 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 698 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 699 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 700 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_RetryRetrievingUncle::
# 701 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle1, MSGBOX_YESNO
# 702 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 703 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_DeclineRetryRetrievingUncle
# 704 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle2, MSGBOX_DEFAULT
# 705 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setfollowernpc LOCALID_GAMECORNER_UNCLE, FNPC_LEAVE_WHITEOUT, MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing
# 706 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	facefollowernpc
# 707 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 708 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 709 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 710 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle1:
# 711 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 712 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 713 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 714 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … Huh…?\p"
# 715 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh…\l"
# 716 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's you…\p"
# 717 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You're going to try to take me\n"
# 718 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "out of here again?$"
# 719 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 720 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RetryRetrievingUncle2:
# 721 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Fine.\p"
# 722 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Let's hurry up and get out of here…\l"
# 723 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "And don't get us into trouble this time!$"
# 724 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 725 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_DeclineRetryRetrievingUncle::
# 726 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DeclineRetryRetrievingUncle, MSGBOX_DEFAULT
# 727 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 728 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 729 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_SNORE
# 730 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 60
# 731 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 732 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 733 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_lt VAR_COIN_CASE_QUEST, 1, MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest
# 734 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 735 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 736 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 737 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DeclineRetryRetrievingUncle:
# 738 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Then quit bothering… …\l"
# 739 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "me… … …$"
# 740 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 741 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_StartCoinCaseQuest::
# 742 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 1
# 743 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 744 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 745 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TaskedWithRetrievingUncle::
# 746 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 747 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 748 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceLeft
# 749 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_NORTH, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceSouth
# 750 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_PlayerFaceRight
# 751 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 752 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 10
# 753 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 754 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_PIN
# 755 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 756 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 5
# 757 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 758 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_TaskedWithRetrievingUncle, MSGBOX_YESNO
# 759 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_OG_EventScript_NephewMayBeWorried
# 760 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 761 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 762 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleEast
# 763 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleNorth
# 764 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleWest
# 765 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 766 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow2, MSGBOX_DEFAULT
# 767 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setfollowernpc LOCALID_GAMECORNER_UNCLE, FNPC_LEAVE_WHITEOUT, MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing
# 768 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	facefollowernpc
# 769 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 3
# 770 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 771 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 772 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 773 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleEast::
# 774 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 775 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 776 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 777 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 778 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 779 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 780 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 781 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleEast
# 782 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledEast
# 783 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 784 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 785 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 786 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 787 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 788 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 789 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 790 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 791 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 792 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleNorth::
# 793 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 794 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 795 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 796 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 797 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 798 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 799 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 800 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleNorth
# 801 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledNorth
# 802 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 803 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 804 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 805 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 806 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 807 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 808 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 809 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 810 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 811 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerWrangleUncleWest::
# 812 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 813 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 814 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 815 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1, MSGBOX_DEFAULT
# 816 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 817 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 818 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 819 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleWest
# 820 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledWest
# 821 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 822 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 823 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 824 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 825 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 32
# 826 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_TAKE_DOWN
# 827 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 828 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 829 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 830 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewMayBeWorried::
# 831 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	@msgbox MauvilleCity_GameCorner_OG_Text_NephewMayBeWorried, MSGBOX_DEFAULT
# 832 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 833 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 834 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_RESULT
# 835 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedEast
# 836 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedNorth
# 837 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_GameCorner_OG_EventScript_NephewWorriedWest
# 838 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 839 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 840 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 841 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedEast::
# 842 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
# 843 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 844 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 845 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_SNORE
# 846 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 847 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 848 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 849 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 850 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 851 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 852 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 853 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 854 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 855 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedNorth::
# 856 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 857 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 858 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 859 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_SNORE
# 860 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 861 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 862 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 863 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 864 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 865 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 866 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 867 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 868 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 869 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NephewWorriedWest::
# 870 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 871 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_PLAYER
# 872 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 873 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_M_SNORE
# 874 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay 15
# 875 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 876 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DriftingOffAgain, MSGBOX_DEFAULT
# 877 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitse
# 878 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_GAMECORNER_UNCLE, Common_Movement_FaceOriginalDirection
# 879 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement LOCALID_GAMECORNER_UNCLE
# 880 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 881 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 882 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 883 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_UncleIsFollowing::
# 884 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 885 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_OrCanGoBack, MSGBOX_YESNO
# 886 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_GameCorner_OG_EventScript_FollowingUncleLeaves
# 887 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UncleIsFollowing, MSGBOX_DEFAULT
# 888 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 889 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 890 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 891 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_FollowingUncleLeaves::
# 892 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UncleStopsFollowing, MSGBOX_DEFAULT
# 893 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 894 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	destroyfollowernpc
# 895 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	warpinplace
# 896 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 897 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 898 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 899 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_OrCanGoBack:
# 900 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Will you just mind your own\n"
# 901 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "business and leave me alone?$"
# 902 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 903 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UncleStopsFollowing:
# 904 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "WOOHOO!\l"
# 905 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Finally!$"
# 906 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 907 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PokefanM::
# 908 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 909 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 910 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 911 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_OG_EventScript_TryGive20Coins
# 912 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 913 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 914 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 915 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 916 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_TryGive20Coins::
# 917 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal
# 918 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkcoins VAR_TEMP_1
# 919 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 920 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 921 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	addcoins 20
# 922 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 923 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playse SE_SHOP
# 924 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal
# 925 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 926 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 927 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PokefanMNormal::
# 928 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 929 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 930 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 931 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 932 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_OldMan::
# 933 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 934 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 935 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 936 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 937 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 938 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 939 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Cook::
# 940 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 941 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 942 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 943 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 944 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 945 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 946 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Man::
# 947 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 948 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 949 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 950 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 951 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 952 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 953 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots::
# 954 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	closemessage
# 955 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 956 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 957 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	release
# 958 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 959 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 960 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Maniac::
# 961 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 962 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 963 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 964 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 965 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 966 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 967 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_Woman::
# 968 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lock
# 969 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	faceplayer
# 970 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 971 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto MauvilleCity_GameCorner_OG_EventScript_NPCReturnToSlots
# 972 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 973 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 974 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine0::
# 975 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 976 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 977 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 978 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 0
# 979 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 980 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 981 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 982 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 983 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 984 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine1::
# 985 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 986 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 987 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 988 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 1
# 989 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 990 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 991 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 992 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 993 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 994 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine2::
# 995 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 996 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 997 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 998 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 2
# 999 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1000 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1001 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1002 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1003 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1004 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine3::
# 1005 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1006 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1007 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1008 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 3
# 1009 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1010 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1011 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1012 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1013 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1014 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine4::
# 1015 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1016 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1017 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1018 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 4
# 1019 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1020 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1021 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1022 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1023 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1024 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine5::
# 1025 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1026 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1027 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1028 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 5
# 1029 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1030 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1031 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1032 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1033 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1034 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine6::
# 1035 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1036 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1037 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1038 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 6
# 1039 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1040 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1041 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1042 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1043 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1044 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine7::
# 1045 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1046 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1047 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1048 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 7
# 1049 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1050 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1051 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1052 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1053 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1054 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine8::
# 1055 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1056 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1057 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1058 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 8
# 1059 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1060 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1061 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1062 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1063 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1064 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine9::
# 1065 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1066 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1067 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1068 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 9
# 1069 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1070 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1071 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1072 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1073 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1074 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine10::
# 1075 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1076 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1077 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1078 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 10
# 1079 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1080 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1081 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1082 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1083 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1084 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_SlotMachine11::
# 1085 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	lockall
# 1086 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	checkitem ITEM_COIN_CASE
# 1087 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_OG_EventScript_NoCoinCase
# 1088 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	setvar VAR_0x8004, 11
# 1089 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 1090 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	playslotmachine VAR_RESULT
# 1091 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1092 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1093 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1094 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_NoCoinCase::
# 1095 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	msgbox MauvilleCity_GameCorner_OG_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 1096 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	releaseall
# 1097 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	end
# 1098 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1099 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleEast:
# 1100 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1101 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1102 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1103 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1104 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1105 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1106 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1107 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1108 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1109 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1110 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1111 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledEast:
# 1112 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1113 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1114 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1115 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1116 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1117 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1118 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1119 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1120 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleNorth:
# 1121 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1122 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1123 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1124 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1125 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1126 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1127 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1128 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_up
# 1129 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1130 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1131 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1132 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledNorth:
# 1133 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 1134 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1135 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 1136 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1137 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_vertical
# 1138 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1139 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1140 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1141 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerWrangleUncleWest:
# 1142 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1143 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1144 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1145 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1146 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1147 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1148 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1149 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1150 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1151 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1152 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1153 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_UncleGetWrangledWest:
# 1154 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1155 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1156 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1157 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1158 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	shake_horizontal
# 1159 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	delay_16
# 1160 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1161 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1162 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceLeft::
# 1163 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceLeft
# 1164 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 1165 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 1166 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1167 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceLeft:
# 1168 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_left
# 1169 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1170 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1171 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceSouth::
# 1172 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceSouth
# 1173 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 1174 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 1175 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1176 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceSouth:
# 1177 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_down
# 1178 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1179 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1180 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_EventScript_PlayerFaceRight::
# 1181 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	applymovement LOCALID_PLAYER, MauvilleCity_GameCorner_OG_Movement_PlayerFaceRight
# 1182 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	waitmovement 0
# 1183 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	return
# 1184 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1185 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Movement_PlayerFaceRight:
# 1186 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	walk_in_place_right
# 1187 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	step_end
# 1188 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1189 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_Uncle:
# 1190 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 1191 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 1192 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\l"
# 1193 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … Huh…?\p"
# 1194 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh…!\l"
# 1195 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Uh…\p"
# 1196 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "No, I wasn't sleeping…\p"
# 1197 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Everything is under control!$"
# 1198 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1199 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DriftingOffAgain:
# 1200 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "He seemed to start drifting off again…$"
# 1201 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1202 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NephewMayBeWorried:
# 1203 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "His nephew is probably really worried!$"
# 1204 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1205 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow1:
# 1206 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Hey! Lay off me you grubby youth!$"
# 1207 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1208 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ConvinceUncleToFollow2:
# 1209 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … … …\n"
# 1210 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "… … … … … … … What?\p"
# 1211 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "My nephew? And my wife?\p"
# 1212 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "But I just got here…!\p"
# 1213 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Grr… Fine!\n"
# 1214 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Let's hurry back…\p"
# 1215 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I'll just show them I'm okay…\p" 
# 1216 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "and then…\p"
# 1217 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "then maybe I can come back!$"
# 1218 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1219 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UncleIsFollowing:
# 1220 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Then let's get a move on!\n"
# 1221 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The sooner I can show my family\l"
# 1222 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "that I'm okay, the sooner I can\l"
# 1223 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "get back to the slots!$"
# 1224 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1225 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_TaskedWithRetrievingUncle:
# 1226 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This must be the missing uncle of\n"
# 1227 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "that kid from PETALBURG!\p"
# 1228 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Try to convince him to come with you?$"
# 1229 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1230 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ThisIsMauvilleGameCorner:
# 1231 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"
# 1232 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1233 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NeedCoinCaseForCoins:
# 1234 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Okay, you wanted some COINS for\n"
# 1235 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the games?\p"
# 1236 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "But you don't have a COIN CASE for\n"
# 1237 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "stowing the COINS.$"
# 1238 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1239 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_WereYouLookingForCoins:
# 1240 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Were you looking for COINS?\p"
# 1241 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's ¥1000 for 50 COINS.\n"
# 1242 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Would you like some?$"
# 1243 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1244 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ThankYouHereAreYourCoins:
# 1245 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Thank you very much!\n"
# 1246 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here are your COINS!$"
# 1247 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1248 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontHaveEnoughMoney:
# 1249 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Um… You don't appear to have\n"
# 1250 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "enough money…$"
# 1251 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1252 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CoinCaseIsFull:
# 1253 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh?\n"
# 1254 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Your COIN CASE is full.$"
# 1255 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1256 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontNeedCoinsThen:
# 1257 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh… You don't need COINS, then?\n"
# 1258 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Good luck on your adventure!$"
# 1259 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1260 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_ExchangeCoinsForPrizes:
# 1261 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Welcome.\p"
# 1262 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can exchange your COINS for\n"
# 1263 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "prizes here.$"
# 1264 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1265 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_WhichPrize:
# 1266 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Which prize would you like?$"
# 1267 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1268 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheTMX:
# 1269 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "So your choice is\n"
# 1270 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "{STR_VAR_1} {STR_VAR_2}?$"
# 1271 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1272 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsTheItem:
# 1273 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "So your choice is\n"
# 1274 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the {STR_VAR_1}?$"
# 1275 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1276 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SendToYourHomePC:
# 1277 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Thank you!\n"
# 1278 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 1279 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1280 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NotEnoughCoins:
# 1281 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You don't have enough COINS.$"
# 1282 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1283 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 1284 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NoRoomForPlacingDecor:
# 1285 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "There isn't any room available for\n"
# 1286 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 1287 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1288 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_OhIsThatSo:
# 1289 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, is that so? \n"
# 1290 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You need to save some COINS before\l"
# 1291 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "coming back here.$"
# 1292 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1293 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_SoYourChoiceIsX:
# 1294 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 1295 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1296 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HereYouGo:
# 1297 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here you go!$"
# 1298 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1299 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
@ Unused
# 1300 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantCarryAnyMore:
# 1301 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 1302 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1303 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_GotTwoOfSameDollWantOne:
# 1304 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I made a mistake and got two of\n"
# 1305 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the same DOLLS.\p"
# 1306 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Would you like one of them?$"
# 1307 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1308 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HereYouGo2:
# 1309 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here you go!$"
# 1310 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1311 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_YouWantItButNotNow:
# 1312 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Huh?\n"
# 1313 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You want it, but not right now?$"
# 1314 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1315 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DontBeNegative:
# 1316 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 1317 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can have this!$"
# 1318 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1319 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantWinJackpot:
# 1320 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 1321 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the jackpot.$"
# 1322 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1323 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_NeedCoinCaseGoNextDoor:
# 1324 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 1325 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "you need a COIN CASE.\p"
# 1326 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I think the young lady next door\n"
# 1327 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "had one. Go see her!$"
# 1328 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1329 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_LuckOnlyLastSoLongTakeCoins:
# 1330 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "My luck can only last so long.\n"
# 1331 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This is too much for me.\l"
# 1332 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here, take some COINS!$"
# 1333 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1334 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_MauvilleSomethingForEveryone:
# 1335 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "MAUVILLE has something for\n"
# 1336 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "everyone.\p"
# 1337 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "For me, it's the GAME CORNER.$"
# 1338 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1339 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RouletteTablesDifferentRates:
# 1340 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The ROULETTE tables have different\n"
# 1341 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "rates.\p"
# 1342 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Check your COINS if you're going to\n"
# 1343 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "pick a table.$"
# 1344 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1345 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_EasyToLoseTrackOfTime:
# 1346 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 1347 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "I should get back to work.$"
# 1348 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1349 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CoinsAreNeededToPlay:
# 1350 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "COINS are needed to play here\n"
# 1351 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "in the GAME CORNER.$"
# 1352 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1353 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_RouletteOnlyLuck:
# 1354 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "This ROULETTE thing…\n"
# 1355 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's rather demanding.\p"
# 1356 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 1357 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1358 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_UpTo3CoinsCanBeUsed:
# 1359 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Up to three COINS can be used to play\n"
# 1360 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the SLOTS.$"
# 1361 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1362 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_DifficultToStopOn7:
# 1363 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 1364 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "right on “7.”\p"
# 1365 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "If it stops on “7” during the REEL TIME\n"
# 1366 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "bonus game, you'll receive extra COINS.$"
# 1367 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1368 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_HeresSomeSlotsInfo:
# 1369 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Here's some information for you\n"
# 1370 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "about the SLOTS.\p"
# 1371 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 1372 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "the more REEL TIME chances you get.\p"
# 1373 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "In a game with the maximum five\n"
# 1374 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "REEL TIME chances…\p"
# 1375 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "It is possible to receive four regular\n"
# 1376 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 1377 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "That would total 660 COINS, but it's\n"
# 1378 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "very difficult to get.$"
# 1379 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"

# 1380 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
MauvilleCity_GameCorner_OG_Text_CantPlayWithNoCoinCase:
# 1381 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "You can't play if you don't have\n"
# 1382 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "a COIN CASE.$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_0:
# 262 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "TM32                1,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_1:
# 262 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "TM29                3,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_2:
# 263 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "TM35                4,000 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_3:
# 263 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "TM24                4,000 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_4:
# 264 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "TM13                4,000 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_5:
# 264 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Electirizer     1,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_6:
# 265 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Magmarizer      1,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_7:
# 265 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Protector       1,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_8:
# 266 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Upgrade           2,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_9:
# 266 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Dubious Disc   2,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_10:
# 267 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Metal Coat      2,500 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_11:
# 267 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Linking Cord   4,000 COINS$"

MauvilleCity_GameCorner_OG_EventScript_ChooseTMPrize_Text_12:
# 267 "data//maps/MauvilleCity_GameCorner_OG/scripts.pory"
	.string "Cancel$"
