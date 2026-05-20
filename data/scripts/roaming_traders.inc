RoamingTraders_EventScript_TMTrader::
# 2 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_TMTrader_Text_0, MSGBOX_YESNO
# 4 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_TMTrader_1
# 8 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_TMTrader_Text_1, MSGBOX_DEFAULT
	return

RoamingTraders_EventScript_TMTrader_1:
# 5 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingTMShop
	return


RoamingTraders_EventScript_GenerateRoamingTMShop::
# 13 "data//scripts/roaming_traders.pory"
	generateroamingshop FLAG_ROAMING_SCIENTIST
# 14 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_1, VAR_0x8007
# 15 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_2, VAR_0x8008
# 16 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_3, VAR_0x8009
# 17 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_0, VAR_0x8007
# 18 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_1, VAR_0x8008
# 19 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_2, VAR_0x8009
# 20 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_3, ITEM_NONE
# 21 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_4
# 22 "data//scripts/roaming_traders.pory"
	waitmessage
# 23 "data//scripts/roaming_traders.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, VAR_0x8007, DYN_MULTICHOICE_CB_SHOW_ITEM
# 24 "data//scripts/roaming_traders.pory"
	switch VAR_RESULT
# 25 "data//scripts/roaming_traders.pory"
	case VAR_0x8007, RoamingTraders_EventScript_GenerateRoamingTMShop_3
# 27 "data//scripts/roaming_traders.pory"
	case VAR_0x8008, RoamingTraders_EventScript_GenerateRoamingTMShop_4
# 29 "data//scripts/roaming_traders.pory"
	case VAR_0x8009, RoamingTraders_EventScript_GenerateRoamingTMShop_5
# 31 "data//scripts/roaming_traders.pory"
	case 0, RoamingTraders_EventScript_GenerateRoamingTMShop_6
# 35 "data//scripts/roaming_traders.pory"
	case 127, RoamingTraders_EventScript_GenerateRoamingTMShop_7
# 40 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_TMTrader_Text_1, MSGBOX_DEFAULT
# 41 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_1:
# 44 "data//scripts/roaming_traders.pory"
	compare VAR_0x8004, ITEM_BLANK_DISC
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingTMShop_10
# 49 "data//scripts/roaming_traders.pory"
	special BufferTMHMMoveName
# 50 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_6, MSGBOX_YESNO
RoamingTraders_EventScript_GenerateRoamingTMShop_9:
# 52 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingTMShop_13
# 112 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingTMShop
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_3:
# 26 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8007
	goto RoamingTraders_EventScript_GenerateRoamingTMShop_1

RoamingTraders_EventScript_GenerateRoamingTMShop_4:
# 28 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8008
	goto RoamingTraders_EventScript_GenerateRoamingTMShop_1

RoamingTraders_EventScript_GenerateRoamingTMShop_5:
# 30 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8009
	goto RoamingTraders_EventScript_GenerateRoamingTMShop_1

RoamingTraders_EventScript_GenerateRoamingTMShop_6:
# 32 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_TMTrader_Text_1, MSGBOX_DEFAULT
# 33 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_7:
# 36 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_TMTrader_Text_1, MSGBOX_DEFAULT
# 37 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_10:
# 45 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_1, VAR_0x8004
# 46 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_5, MSGBOX_YESNO
	goto RoamingTraders_EventScript_GenerateRoamingTMShop_9

RoamingTraders_EventScript_GenerateRoamingTMShop_13:
# 53 "data//scripts/roaming_traders.pory"
	showmoneybox 0, 0
# 54 "data//scripts/roaming_traders.pory"
	gettradersitemprice VAR_0x8005, VAR_0x8004
# 55 "data//scripts/roaming_traders.pory"
	buffernumberstring STR_VAR_3, VAR_0x8005
# 56 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_7
# 57 "data//scripts/roaming_traders.pory"
	waitmessage
# 58 "data//scripts/roaming_traders.pory"
	dynmultichoice 20, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_8, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_9
# 59 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, 1
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingTMShop_17
# 69 "data//scripts/roaming_traders.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 70 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingTMShop_20
# 80 "data//scripts/roaming_traders.pory"
	checkitemspace VAR_0x8004
# 81 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingTMShop_23
# 90 "data//scripts/roaming_traders.pory"
	special SubtractMoneyFromVar0x8005
# 91 "data//scripts/roaming_traders.pory"
	updatemoneybox
# 92 "data//scripts/roaming_traders.pory"
	playse SE_SHOP
# 93 "data//scripts/roaming_traders.pory"
	waitse
# 94 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 95 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_15
# 96 "data//scripts/roaming_traders.pory"
	waitmessage
# 97 "data//scripts/roaming_traders.pory"
	delay 60
# 98 "data//scripts/roaming_traders.pory"
	giveitem VAR_0x8004
# 99 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_16, MSGBOX_DEFAULT
# 101 "data//scripts/roaming_traders.pory"
	closemessage
# 102 "data//scripts/roaming_traders.pory"
	delay 10
# 103 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 104 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 105 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_SCIENTIST
# 106 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 107 "data//scripts/roaming_traders.pory"
	waitse
# 108 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_17:
# 60 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_10
# 61 "data//scripts/roaming_traders.pory"
	waitmessage
# 62 "data//scripts/roaming_traders.pory"
	delay 60
# 63 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 64 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_11, MSGBOX_DEFAULT
# 66 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_20:
# 71 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_12
# 72 "data//scripts/roaming_traders.pory"
	waitmessage
# 73 "data//scripts/roaming_traders.pory"
	delay 60
# 74 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 75 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_11, MSGBOX_DEFAULT
# 77 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingTMShop_23:
# 82 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingTMShop_Text_13
# 83 "data//scripts/roaming_traders.pory"
	waitmessage
# 84 "data//scripts/roaming_traders.pory"
	delay 60
# 85 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 86 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingTMShop_Text_14, MSGBOX_DEFAULT
# 87 "data//scripts/roaming_traders.pory"
	closemessage
	return


RoamingTraders_EventScript_BallTrader::
# 117 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_BallTrader_Text_0, MSGBOX_YESNO
# 120 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_BallTrader_1
# 124 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_BallTrader_Text_1, MSGBOX_DEFAULT
	return

RoamingTraders_EventScript_BallTrader_1:
# 121 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingBallShop
	return


RoamingTraders_EventScript_GenerateRoamingBallShop::
# 130 "data//scripts/roaming_traders.pory"
	generateroamingshop FLAG_ROAMING_BREEDER
# 131 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_1, VAR_0x8007
# 132 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_2, VAR_0x8008
# 133 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_3, VAR_0x8009
# 134 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_0, VAR_0x8007
# 135 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_1, VAR_0x8008
# 136 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_2, VAR_0x8009
# 137 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_3, ITEM_NONE
# 138 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_0
# 139 "data//scripts/roaming_traders.pory"
	waitmessage
# 140 "data//scripts/roaming_traders.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, VAR_0x8007, DYN_MULTICHOICE_CB_SHOW_ITEM
# 141 "data//scripts/roaming_traders.pory"
	switch VAR_RESULT
# 142 "data//scripts/roaming_traders.pory"
	case VAR_0x8007, RoamingTraders_EventScript_GenerateRoamingBallShop_3
# 144 "data//scripts/roaming_traders.pory"
	case VAR_0x8008, RoamingTraders_EventScript_GenerateRoamingBallShop_4
# 146 "data//scripts/roaming_traders.pory"
	case VAR_0x8009, RoamingTraders_EventScript_GenerateRoamingBallShop_5
# 148 "data//scripts/roaming_traders.pory"
	case 0, RoamingTraders_EventScript_GenerateRoamingBallShop_6
# 153 "data//scripts/roaming_traders.pory"
	case 127, RoamingTraders_EventScript_GenerateRoamingBallShop_7
# 159 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_BallTrader_Text_1, MSGBOX_DEFAULT
# 161 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_1:
# 164 "data//scripts/roaming_traders.pory"
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 6
# 165 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_1, MSGBOX_YESNO
# 166 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingBallShop_9
# 226 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingBallShop
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_3:
# 143 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8007
	goto RoamingTraders_EventScript_GenerateRoamingBallShop_1

RoamingTraders_EventScript_GenerateRoamingBallShop_4:
# 145 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8008
	goto RoamingTraders_EventScript_GenerateRoamingBallShop_1

RoamingTraders_EventScript_GenerateRoamingBallShop_5:
# 147 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8009
	goto RoamingTraders_EventScript_GenerateRoamingBallShop_1

RoamingTraders_EventScript_GenerateRoamingBallShop_6:
# 149 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_BallTrader_Text_1, MSGBOX_DEFAULT
# 151 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_7:
# 154 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_BallTrader_Text_1, MSGBOX_DEFAULT
# 156 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_9:
# 167 "data//scripts/roaming_traders.pory"
	showmoneybox 0, 0
# 168 "data//scripts/roaming_traders.pory"
	gettradersitemprice VAR_0x8005, VAR_0x8004, 6
# 169 "data//scripts/roaming_traders.pory"
	buffernumberstring STR_VAR_3, VAR_0x8005
# 170 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_2
# 171 "data//scripts/roaming_traders.pory"
	waitmessage
# 172 "data//scripts/roaming_traders.pory"
	dynmultichoice 20, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_8, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_9
# 173 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, 1
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingBallShop_13
# 183 "data//scripts/roaming_traders.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 184 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingBallShop_16
# 194 "data//scripts/roaming_traders.pory"
	checkitemspace VAR_0x8004
# 195 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingBallShop_19
# 204 "data//scripts/roaming_traders.pory"
	special SubtractMoneyFromVar0x8005
# 205 "data//scripts/roaming_traders.pory"
	updatemoneybox
# 206 "data//scripts/roaming_traders.pory"
	playse SE_SHOP
# 207 "data//scripts/roaming_traders.pory"
	waitse
# 208 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 209 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_9
# 210 "data//scripts/roaming_traders.pory"
	waitmessage
# 211 "data//scripts/roaming_traders.pory"
	delay 40
# 212 "data//scripts/roaming_traders.pory"
	giveitem VAR_0x8004, 6
# 213 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_10, MSGBOX_DEFAULT
# 215 "data//scripts/roaming_traders.pory"
	closemessage
# 216 "data//scripts/roaming_traders.pory"
	delay 10
# 217 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 218 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 219 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_BREEDER
# 220 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 221 "data//scripts/roaming_traders.pory"
	waitse
# 222 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_13:
# 174 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_3
# 175 "data//scripts/roaming_traders.pory"
	waitmessage
# 176 "data//scripts/roaming_traders.pory"
	delay 60
# 177 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 178 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_4, MSGBOX_DEFAULT
# 180 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_16:
# 185 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_5
# 186 "data//scripts/roaming_traders.pory"
	waitmessage
# 187 "data//scripts/roaming_traders.pory"
	delay 60
# 188 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 189 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_6, MSGBOX_DEFAULT
# 191 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingBallShop_19:
# 196 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_7
# 197 "data//scripts/roaming_traders.pory"
	waitmessage
# 198 "data//scripts/roaming_traders.pory"
	delay 60
# 199 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 200 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_8, MSGBOX_DEFAULT
# 201 "data//scripts/roaming_traders.pory"
	closemessage
	return


RoamingTraders_EventScript_SurvivalItemTrader::
# 231 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_SurvivalItemTrader_Text_0, MSGBOX_YESNO
# 232 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_SurvivalItemTrader_1
# 236 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_SurvivalItemTrader_Text_1, MSGBOX_DEFAULT
	return

RoamingTraders_EventScript_SurvivalItemTrader_1:
# 233 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingSurvivalShop
	return


RoamingTraders_EventScript_GenerateRoamingSurvivalShop::
# 242 "data//scripts/roaming_traders.pory"
	generateroamingshop FLAG_ROAMING_HIKER
# 243 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_1, VAR_0x8007
# 244 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_2, VAR_0x8008
# 245 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_3, VAR_0x8009
# 246 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_0, VAR_0x8007
# 247 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_1, VAR_0x8008
# 248 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_2, VAR_0x8009
# 249 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_3, ITEM_NONE
# 250 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_0
# 251 "data//scripts/roaming_traders.pory"
	waitmessage
# 252 "data//scripts/roaming_traders.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, VAR_0x8007, DYN_MULTICHOICE_CB_SHOW_ITEM
# 253 "data//scripts/roaming_traders.pory"
	switch VAR_RESULT
# 254 "data//scripts/roaming_traders.pory"
	case VAR_0x8007, RoamingTraders_EventScript_GenerateRoamingSurvivalShop_3
# 256 "data//scripts/roaming_traders.pory"
	case VAR_0x8008, RoamingTraders_EventScript_GenerateRoamingSurvivalShop_4
# 258 "data//scripts/roaming_traders.pory"
	case VAR_0x8009, RoamingTraders_EventScript_GenerateRoamingSurvivalShop_5
# 260 "data//scripts/roaming_traders.pory"
	case 0, RoamingTraders_EventScript_GenerateRoamingSurvivalShop_6
# 265 "data//scripts/roaming_traders.pory"
	case 127, RoamingTraders_EventScript_GenerateRoamingSurvivalShop_7
# 271 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_SurvivalItemTrader_Text_1, MSGBOX_DEFAULT
# 273 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_1:
# 276 "data//scripts/roaming_traders.pory"
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 6
# 277 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_1, MSGBOX_YESNO
# 278 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingSurvivalShop_9
# 338 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingSurvivalShop
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_3:
# 255 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8007
	goto RoamingTraders_EventScript_GenerateRoamingSurvivalShop_1

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_4:
# 257 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8008
	goto RoamingTraders_EventScript_GenerateRoamingSurvivalShop_1

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_5:
# 259 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8009
	goto RoamingTraders_EventScript_GenerateRoamingSurvivalShop_1

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_6:
# 261 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_SurvivalItemTrader_Text_1, MSGBOX_DEFAULT
# 263 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_7:
# 266 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_SurvivalItemTrader_Text_1, MSGBOX_DEFAULT
# 268 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_9:
# 279 "data//scripts/roaming_traders.pory"
	showmoneybox 0, 0
# 280 "data//scripts/roaming_traders.pory"
	gettradersitemprice VAR_0x8005, VAR_0x8004, 5
# 281 "data//scripts/roaming_traders.pory"
	buffernumberstring STR_VAR_3, VAR_0x8005
# 282 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_2
# 283 "data//scripts/roaming_traders.pory"
	waitmessage
# 284 "data//scripts/roaming_traders.pory"
	dynmultichoice 20, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_8, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_9
# 285 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, 1
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingSurvivalShop_13
# 295 "data//scripts/roaming_traders.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 296 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingSurvivalShop_16
# 306 "data//scripts/roaming_traders.pory"
	checkitemspace VAR_0x8004
# 307 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingSurvivalShop_19
# 316 "data//scripts/roaming_traders.pory"
	special SubtractMoneyFromVar0x8005
# 317 "data//scripts/roaming_traders.pory"
	updatemoneybox
# 318 "data//scripts/roaming_traders.pory"
	playse SE_SHOP
# 319 "data//scripts/roaming_traders.pory"
	waitse
# 320 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 321 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_7
# 322 "data//scripts/roaming_traders.pory"
	waitmessage
# 323 "data//scripts/roaming_traders.pory"
	delay 40
# 324 "data//scripts/roaming_traders.pory"
	giveitem VAR_0x8004, 5
# 325 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_8, MSGBOX_DEFAULT
# 327 "data//scripts/roaming_traders.pory"
	closemessage
# 328 "data//scripts/roaming_traders.pory"
	delay 10
# 329 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 330 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 331 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_HIKER
# 332 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 333 "data//scripts/roaming_traders.pory"
	waitse
# 334 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_13:
# 286 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_3
# 287 "data//scripts/roaming_traders.pory"
	waitmessage
# 288 "data//scripts/roaming_traders.pory"
	delay 60
# 289 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 290 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_4, MSGBOX_DEFAULT
# 292 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_16:
# 297 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_5
# 298 "data//scripts/roaming_traders.pory"
	waitmessage
# 299 "data//scripts/roaming_traders.pory"
	delay 60
# 300 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 301 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_6, MSGBOX_DEFAULT
# 303 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_19:
# 308 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_7
# 309 "data//scripts/roaming_traders.pory"
	waitmessage
# 310 "data//scripts/roaming_traders.pory"
	delay 60
# 311 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 312 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingBallShop_Text_8, MSGBOX_DEFAULT
# 313 "data//scripts/roaming_traders.pory"
	closemessage
	return


RoamingTraders_EventScript_HerbTrader::
# 343 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_HerbTrader_Text_0, MSGBOX_YESNO
# 344 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_HerbTrader_1
# 348 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_HerbTrader_Text_1, MSGBOX_DEFAULT
	return

RoamingTraders_EventScript_HerbTrader_1:
# 345 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingHerbShop
	return


RoamingTraders_EventScript_GenerateRoamingHerbShop::
# 354 "data//scripts/roaming_traders.pory"
	generateroamingshop FLAG_ROAMING_RANGER
# 355 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_1, VAR_0x8007
# 356 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_2, VAR_0x8008
# 357 "data//scripts/roaming_traders.pory"
	bufferitemname STR_VAR_3, VAR_0x8009
# 358 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_0, VAR_0x8007
# 359 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_1, VAR_0x8008
# 360 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_2, VAR_0x8009
# 361 "data//scripts/roaming_traders.pory"
	dynmultipush RoamingTraders_EventScript_GenerateRoamingTMShop_Text_3, ITEM_NONE
# 362 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_0
# 363 "data//scripts/roaming_traders.pory"
	waitmessage
# 364 "data//scripts/roaming_traders.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, VAR_0x8007, DYN_MULTICHOICE_CB_SHOW_ITEM
# 365 "data//scripts/roaming_traders.pory"
	switch VAR_RESULT
# 366 "data//scripts/roaming_traders.pory"
	case VAR_0x8007, RoamingTraders_EventScript_GenerateRoamingHerbShop_3
# 368 "data//scripts/roaming_traders.pory"
	case VAR_0x8008, RoamingTraders_EventScript_GenerateRoamingHerbShop_4
# 370 "data//scripts/roaming_traders.pory"
	case VAR_0x8009, RoamingTraders_EventScript_GenerateRoamingHerbShop_5
# 372 "data//scripts/roaming_traders.pory"
	case 0, RoamingTraders_EventScript_GenerateRoamingHerbShop_6
# 377 "data//scripts/roaming_traders.pory"
	case 127, RoamingTraders_EventScript_GenerateRoamingHerbShop_7
# 383 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_HerbTrader_Text_1, MSGBOX_DEFAULT
# 385 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_1:
# 388 "data//scripts/roaming_traders.pory"
	bufferitemnameplural STR_VAR_2, VAR_0x8004, 1
# 389 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_1, MSGBOX_YESNO
# 390 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, YES
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingHerbShop_9
# 449 "data//scripts/roaming_traders.pory"
	call RoamingTraders_EventScript_GenerateRoamingHerbShop
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_3:
# 367 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8007
	goto RoamingTraders_EventScript_GenerateRoamingHerbShop_1

RoamingTraders_EventScript_GenerateRoamingHerbShop_4:
# 369 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8008
	goto RoamingTraders_EventScript_GenerateRoamingHerbShop_1

RoamingTraders_EventScript_GenerateRoamingHerbShop_5:
# 371 "data//scripts/roaming_traders.pory"
	copyvar VAR_0x8004, VAR_0x8009
	goto RoamingTraders_EventScript_GenerateRoamingHerbShop_1

RoamingTraders_EventScript_GenerateRoamingHerbShop_6:
# 373 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_HerbTrader_Text_1, MSGBOX_DEFAULT
# 375 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_7:
# 378 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_HerbTrader_Text_1, MSGBOX_DEFAULT
# 380 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_9:
# 391 "data//scripts/roaming_traders.pory"
	showmoneybox 0, 0
# 392 "data//scripts/roaming_traders.pory"
	getitemprice VAR_0x8005, VAR_0x8004, 1
# 393 "data//scripts/roaming_traders.pory"
	buffernumberstring STR_VAR_3, VAR_0x8005
# 394 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_2
# 395 "data//scripts/roaming_traders.pory"
	waitmessage
# 396 "data//scripts/roaming_traders.pory"
	dynmultichoice 20, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_8, RoamingTraders_EventScript_GenerateRoamingTMShop_Text_9
# 397 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, 1
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingHerbShop_13
# 407 "data//scripts/roaming_traders.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 408 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingHerbShop_16
# 418 "data//scripts/roaming_traders.pory"
	checkitemspace VAR_0x8004
# 419 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_GenerateRoamingHerbShop_19
# 428 "data//scripts/roaming_traders.pory"
	special SubtractMoneyFromVar0x8005
# 429 "data//scripts/roaming_traders.pory"
	updatemoneybox
# 430 "data//scripts/roaming_traders.pory"
	playse SE_SHOP
# 431 "data//scripts/roaming_traders.pory"
	waitse
# 432 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 433 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_7
# 434 "data//scripts/roaming_traders.pory"
	waitmessage
# 435 "data//scripts/roaming_traders.pory"
	delay 40
# 436 "data//scripts/roaming_traders.pory"
	giveitem VAR_0x8004, 5
# 437 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_8, MSGBOX_DEFAULT
# 438 "data//scripts/roaming_traders.pory"
	closemessage
# 439 "data//scripts/roaming_traders.pory"
	delay 10
# 440 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 441 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 442 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_RANGER
# 443 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 444 "data//scripts/roaming_traders.pory"
	waitse
# 445 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_13:
# 398 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_3
# 399 "data//scripts/roaming_traders.pory"
	waitmessage
# 400 "data//scripts/roaming_traders.pory"
	delay 60
# 401 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 402 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_4, MSGBOX_DEFAULT
# 404 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_16:
# 409 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_5
# 410 "data//scripts/roaming_traders.pory"
	waitmessage
# 411 "data//scripts/roaming_traders.pory"
	delay 60
# 412 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 413 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_4, MSGBOX_DEFAULT
# 415 "data//scripts/roaming_traders.pory"
	closemessage
	return

RoamingTraders_EventScript_GenerateRoamingHerbShop_19:
# 420 "data//scripts/roaming_traders.pory"
	message RoamingTraders_EventScript_GenerateRoamingBallShop_Text_7
# 421 "data//scripts/roaming_traders.pory"
	waitmessage
# 422 "data//scripts/roaming_traders.pory"
	delay 60
# 423 "data//scripts/roaming_traders.pory"
	hidemoneybox
# 424 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_6, MSGBOX_DEFAULT
# 425 "data//scripts/roaming_traders.pory"
	closemessage
	return


RoamingTraders_EventScript_RoamingMonTrader::
# 454 "data//scripts/roaming_traders.pory"
	switch VAR_OBJ_GFX_ID_C
# 455 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_LASS, RoamingTraders_EventScript_RoamingMonTrader_3
# 463 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_BUG_CATCHER, RoamingTraders_EventScript_RoamingMonTrader_4
# 471 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_YOUNGSTER, RoamingTraders_EventScript_RoamingMonTrader_5
# 479 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_HEX_MANIAC, RoamingTraders_EventScript_RoamingMonTrader_6
# 487 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, RoamingTraders_EventScript_RoamingMonTrader_7
# 495 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M, RoamingTraders_EventScript_RoamingMonTrader_8
RoamingTraders_EventScript_RoamingMonTrader_1:
# 504 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_10, MSGBOX_YESNO
# 505 "data//scripts/roaming_traders.pory"
	goto_if_eq VAR_RESULT, NO, RoamingTraders_EventScript_DeclineTrade
# 506 "data//scripts/roaming_traders.pory"
	special ChoosePartyMon
# 507 "data//scripts/roaming_traders.pory"
	waitstate
# 508 "data//scripts/roaming_traders.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 509 "data//scripts/roaming_traders.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq RoamingTraders_EventScript_RoamingMonTrader_10
RoamingTraders_EventScript_RoamingMonTrader_9:
# 513 "data//scripts/roaming_traders.pory"
	specialvar VAR_0x8008, GetTradeSpecies
# 514 "data//scripts/roaming_traders.pory"
	compare VAR_0x8008, SPECIES_NONE
	goto_if_eq RoamingTraders_EventScript_RoamingMonTrader_13
# 519 "data//scripts/roaming_traders.pory"
	compare VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto_if_ne RoamingTraders_EventScript_RoamingMonTrader_16
RoamingTraders_EventScript_RoamingMonTrader_15:
# 527 "data//scripts/roaming_traders.pory"
	special CreateRoamingTraderPokemon
# 528 "data//scripts/roaming_traders.pory"
	special DoInGameTradeScene
# 529 "data//scripts/roaming_traders.pory"
	waitstate
# 530 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 531 "data//scripts/roaming_traders.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 532 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_12, MSGBOX_DEFAULT
# 535 "data//scripts/roaming_traders.pory"
	closemessage
# 536 "data//scripts/roaming_traders.pory"
	delay 10
# 537 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 538 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 539 "data//scripts/roaming_traders.pory"
	switch VAR_OBJ_GFX_ID_C
# 540 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_LASS, RoamingTraders_EventScript_RoamingMonTrader_20
# 542 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_BUG_CATCHER, RoamingTraders_EventScript_RoamingMonTrader_21
# 544 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_YOUNGSTER, RoamingTraders_EventScript_RoamingMonTrader_22
# 546 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_HEX_MANIAC, RoamingTraders_EventScript_RoamingMonTrader_23
# 548 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, RoamingTraders_EventScript_RoamingMonTrader_24
# 550 "data//scripts/roaming_traders.pory"
	case OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M, RoamingTraders_EventScript_RoamingMonTrader_25
RoamingTraders_EventScript_RoamingMonTrader_18:
# 553 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 554 "data//scripts/roaming_traders.pory"
	waitse
# 555 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_RoamingMonTrader_3:
# 456 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_PSYCHIC
# 457 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 458 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_0, MSGBOX_DEFAULT
# 460 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_PSYCHIC
# 461 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_PSYCHIC
# 462 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_1
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_4:
# 464 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_BUG_CATCHER
# 465 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 466 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_2, MSGBOX_DEFAULT
# 468 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_BUG_CATCHER
# 469 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_BUG
# 470 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_3
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_5:
# 472 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_YOUNGSTER
# 473 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 474 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_4, MSGBOX_DEFAULT
# 476 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_YOUNGSTER
# 477 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_NORMAL
# 478 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_5
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_6:
# 480 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_HEX_MANIAC
# 481 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 482 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_0, MSGBOX_DEFAULT
# 484 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_HEX_MANIAC
# 485 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_PSYCHIC
# 486 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_1
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_7:
# 488 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_TRIATHLETE_F
# 489 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 490 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_6, MSGBOX_DEFAULT
# 492 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_TRIATHLETE_F
# 493 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_WATER
# 494 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_7
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_8:
# 496 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_ROAMING_TRIATHLETE_M
# 497 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 498 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_8, MSGBOX_DEFAULT
# 500 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_TRIATHLETE_M
# 501 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8003, TYPE_ICE
# 502 "data//scripts/roaming_traders.pory"
	bufferstring STR_VAR_3, RoamingTraders_EventScript_RoamingMonTrader_Text_9
	goto RoamingTraders_EventScript_RoamingMonTrader_1

RoamingTraders_EventScript_RoamingMonTrader_10:
# 511 "data//scripts/roaming_traders.pory"
	goto RoamingTraders_EventScript_DeclineTrade
	goto RoamingTraders_EventScript_RoamingMonTrader_9

RoamingTraders_EventScript_RoamingMonTrader_13:
# 515 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_11, MSGBOX_DEFAULT
	return

RoamingTraders_EventScript_RoamingMonTrader_16:
# 520 "data//scripts/roaming_traders.pory"
	checkspecieshastype VAR_0x8008, VAR_0x8003
# 521 "data//scripts/roaming_traders.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingTraders_EventScript_RoamingMonTrader_26
	goto RoamingTraders_EventScript_RoamingMonTrader_15

RoamingTraders_EventScript_RoamingMonTrader_20:
# 541 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_PSYCHIC
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_21:
# 543 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_BUG_CATCHER
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_22:
# 545 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_YOUNGSTER
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_23:
# 547 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_HEX_MANIAC
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_24:
# 549 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_TRIATHLETE_F
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_25:
# 551 "data//scripts/roaming_traders.pory"
	setflag FLAG_ROAMING_TRIATHLETE_M
	goto RoamingTraders_EventScript_RoamingMonTrader_18

RoamingTraders_EventScript_RoamingMonTrader_26:
# 522 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_RoamingMonTrader_Text_11, MSGBOX_DEFAULT
	return


RoamingTraders_EventScript_DeclineTrade::
# 560 "data//scripts/roaming_traders.pory"
	compare VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_SCIENTIST_2
	goto_if_eq RoamingTraders_EventScript_DeclineTrade_2
# 564 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_DeclineTrade_Text_1, MSGBOX_DEFAULT
RoamingTraders_EventScript_DeclineTrade_1:
# 567 "data//scripts/roaming_traders.pory"
	release
	end

RoamingTraders_EventScript_DeclineTrade_2:
# 561 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_DeclineTrade_Text_0, MSGBOX_DEFAULT
	goto RoamingTraders_EventScript_DeclineTrade_1


RoamingTraders_EventScript_AfterWhiteoutTrader::
# 572 "data//scripts/roaming_traders.pory"
	generateroamingnpctrade FLAG_AFTER_WHITEOUT_TRADE
# 573 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 574 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_AfterWhiteoutTrader_Text_0, MSGBOX_DEFAULT
# 578 "data//scripts/roaming_traders.pory"
	setvar VAR_0x8005, INGAME_TRADE_AFTER_WHITEOUT
# 579 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_AfterWhiteoutTrader_Text_1, MSGBOX_YESNO
# 580 "data//scripts/roaming_traders.pory"
	goto_if_eq VAR_RESULT, NO, RoamingTraders_EventScript_DeclineTrade
# 581 "data//scripts/roaming_traders.pory"
	special ChoosePartyMon
# 582 "data//scripts/roaming_traders.pory"
	waitstate
# 583 "data//scripts/roaming_traders.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 584 "data//scripts/roaming_traders.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq RoamingTraders_EventScript_AfterWhiteoutTrader_2
RoamingTraders_EventScript_AfterWhiteoutTrader_1:
# 588 "data//scripts/roaming_traders.pory"
	specialvar VAR_0x8008, GetTradeSpecies
# 589 "data//scripts/roaming_traders.pory"
	compare VAR_0x8008, SPECIES_NONE
	goto_if_eq RoamingTraders_EventScript_AfterWhiteoutTrader_5
# 594 "data//scripts/roaming_traders.pory"
	special CreateRoamingTraderPokemon
# 595 "data//scripts/roaming_traders.pory"
	special DoInGameTradeScene
# 596 "data//scripts/roaming_traders.pory"
	waitstate
# 597 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 598 "data//scripts/roaming_traders.pory"
	bufferspeciesname STR_VAR_2, VAR_0x8007
# 599 "data//scripts/roaming_traders.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 600 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_AfterWhiteoutTrader_Text_3, MSGBOX_DEFAULT
# 603 "data//scripts/roaming_traders.pory"
	closemessage
# 604 "data//scripts/roaming_traders.pory"
	delay 10
# 605 "data//scripts/roaming_traders.pory"
	fadescreen FADE_TO_BLACK
# 606 "data//scripts/roaming_traders.pory"
	removeobject VAR_LAST_TALKED
# 607 "data//scripts/roaming_traders.pory"
	setflag FLAG_AFTER_WHITEOUT_TRADE
# 608 "data//scripts/roaming_traders.pory"
	playse SE_EXIT
# 609 "data//scripts/roaming_traders.pory"
	waitse
# 610 "data//scripts/roaming_traders.pory"
	fadescreen FADE_FROM_BLACK
	return

RoamingTraders_EventScript_AfterWhiteoutTrader_2:
# 586 "data//scripts/roaming_traders.pory"
	goto RoamingTraders_EventScript_DeclineTrade
	goto RoamingTraders_EventScript_AfterWhiteoutTrader_1

RoamingTraders_EventScript_AfterWhiteoutTrader_5:
# 590 "data//scripts/roaming_traders.pory"
	msgbox RoamingTraders_EventScript_AfterWhiteoutTrader_Text_2, MSGBOX_DEFAULT
	return


RoamingTraders_EventScript_TMTrader_Text_0:
# 2 "data//scripts/roaming_traders.pory"
	.string "Greetings young trainer,\p"
	.string "I'm traveling around HOENN on behalf of\n"
	.string "DEVON CORP to spread the word about\l"
	.string "some of our new TMs.\p"
	.string "I've got a small selection of demo units\n"
	.string "for upcoming new models!\p"
	.string "Do you want to take a look?$"

RoamingTraders_EventScript_TMTrader_Text_1:
# 8 "data//scripts/roaming_traders.pory"
	.string "They're really quite marvelous, but\n"
	.string "that's okay.\p"
	.string "We're likely to cross paths again\n"
	.string "anyway.$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_0:
# 17 "data//scripts/roaming_traders.pory"
	.string "{STR_VAR_1}$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_1:
# 18 "data//scripts/roaming_traders.pory"
	.string "{STR_VAR_2}$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_2:
# 19 "data//scripts/roaming_traders.pory"
	.string "{STR_VAR_3}$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_3:
# 20 "data//scripts/roaming_traders.pory"
	.string "Cancel$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_4:
# 21 "data//scripts/roaming_traders.pory"
	.string "Here are the TMs I have with me right\n"
	.string "now.$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_5:
# 46 "data//scripts/roaming_traders.pory"
	.string "Oh, that's brand new!\p"
	.string "You're interested in the\n"
	.string "{STR_VAR_1}?$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_6:
# 50 "data//scripts/roaming_traders.pory"
	.string "Oh, you're interested in\n"
	.string "{STR_VAR_1}: {STR_VAR_2}?$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_7:
# 56 "data//scripts/roaming_traders.pory"
	.string "These are demo units, so I'm selling\n"
	.string "them at a discount;\p"
	.string "How does a promotional price of\n"
	.string "¥{STR_VAR_3} sound?$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_8:
# 58 "data//scripts/roaming_traders.pory"
	.string "Accept$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_9:
# 58 "data//scripts/roaming_traders.pory"
	.string "Decline$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_10:
# 60 "data//scripts/roaming_traders.pory"
	.string "Oh,{PAUSE 20}{PAUSE 20}\n"
	.string "still too much?$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_11:
# 64 "data//scripts/roaming_traders.pory"
	.string "Well\l"
	.string "I'm sure we'll run into each other again.\p"
	.string "Maybe by then you'll have saved up\n"
	.string "enough!$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_12:
# 71 "data//scripts/roaming_traders.pory"
	.string "Oh,{PAUSE 20}{PAUSE 20}\n"
	.string "but you don't have that much!$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_13:
# 82 "data//scripts/roaming_traders.pory"
	.string "Oh!$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_14:
# 86 "data//scripts/roaming_traders.pory"
	.string "you don't have room for it.\p"
	.string "Talk to me again if you make room!$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_15:
# 95 "data//scripts/roaming_traders.pory"
	.string "Excellent choice!\n"
	.string "{PAUSE 20}Here you go.$"

RoamingTraders_EventScript_GenerateRoamingTMShop_Text_16:
# 99 "data//scripts/roaming_traders.pory"
	.string "Well,\l"
	.string "I'm sure we'll run into each other again,\n"
	.string "but for now, I've got to get moving!\p"
	.string "MR. STONE has me traveling at a\n"
	.string "demanding pace!$"

RoamingTraders_EventScript_BallTrader_Text_0:
# 117 "data//scripts/roaming_traders.pory"
	.string "Hey trainer!\p"
	.string "If you're catching or breeding POKéMON,\n"
	.string "you'll need lots of POKéBALLS!\p"
	.string "I'm traveling around HOENN selling\n"
	.string "POKéBALLS in bulk right now;\p"
	.string "you can get a great deal on some rare\n"
	.string "BALLS in packs of six!\p"
	.string "Want to see what BALLS I have in stock\n"
	.string "right now?$"

RoamingTraders_EventScript_BallTrader_Text_1:
# 124 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}\n"
	.string "That's too bad\p"
	.string "But if you're not caching or breeding\n"
	.string "many POKéMON, I understand…\p"
	.string "Maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_0:
# 138 "data//scripts/roaming_traders.pory"
	.string "I've got packs of these BALLS in stock\n"
	.string "right now.$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_1:
# 165 "data//scripts/roaming_traders.pory"
	.string "You want to buy a pack of six\n"
	.string "{STR_VAR_2}?$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_2:
# 170 "data//scripts/roaming_traders.pory"
	.string "Sure, I can sell you six {STR_VAR_2}\n"
	.string "for ¥{STR_VAR_3}. How's that?$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_3:
# 174 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "still too much?$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_4:
# 178 "data//scripts/roaming_traders.pory"
	.string "It really is a great deal…\p"
	.string "But if you're not caching or breeding\n"
	.string "many POKéMON, I understand…\p"
	.string "Maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_5:
# 185 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "but you don't have that much!$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_6:
# 189 "data//scripts/roaming_traders.pory"
	.string "well,{PAUSE 20}\n"
	.string "it is a great deal…\p"
	.string "But if you can't afford it, I\n"
	.string "understand…\p"
	.string "Maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_7:
# 196 "data//scripts/roaming_traders.pory"
	.string "Oh, but…$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_8:
# 200 "data//scripts/roaming_traders.pory"
	.string "you don't have room for it!\p"
	.string "Talk to me again if you make room!$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_9:
# 209 "data//scripts/roaming_traders.pory"
	.string "What a steal!\n"
	.string "{PAUSE 20}Here you go.$"

RoamingTraders_EventScript_GenerateRoamingBallShop_Text_10:
# 213 "data//scripts/roaming_traders.pory"
	.string "I'm sure I'll see you again,\n"
	.string "but I've gotta head out now!\p"
	.string "POKéMON everywhere need quality BALLS\n"
	.string "to call home!$"

RoamingTraders_EventScript_SurvivalItemTrader_Text_0:
# 231 "data//scripts/roaming_traders.pory"
	.string "Hello there!\p"
	.string "I'm selling packs of items to help\n"
	.string "trainers survive in the backcountry.\p"
	.string "My supplies are so affordable because\n"
	.string "they come in packs of five.\p"
	.string "Want to see?$"

RoamingTraders_EventScript_SurvivalItemTrader_Text_1:
# 236 "data//scripts/roaming_traders.pory"
	.string "Huh?{PAUSE 20}\n"
	.string "Are you sure?\p"
	.string "Well I guess if you just plan to hang\n"
	.string "around town and take it easy, you\l"
	.string "wouldn't need this kind of stuff!\p"
	.string "See you around, trainer.$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_0:
# 250 "data//scripts/roaming_traders.pory"
	.string "These are the supplies I have for sale\n"
	.string "currently.$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_1:
# 277 "data//scripts/roaming_traders.pory"
	.string "You want to buy a pack of five\n"
	.string "{STR_VAR_2}?$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_2:
# 282 "data//scripts/roaming_traders.pory"
	.string "It's ¥{STR_VAR_3} for a pack of five\n"
	.string "{STR_VAR_2}. Does that work for\l"
	.string "you?$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_3:
# 286 "data//scripts/roaming_traders.pory"
	.string "Huh?{PAUSE 20}\n"
	.string "You don't like my price?$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_4:
# 290 "data//scripts/roaming_traders.pory"
	.string "I doubt you'll find a better deal…\p"
	.string "But if you just plan to hang around\n"
	.string "town and take it easy, you wouldn't\l"
	.string "need this kind of stuff!\p"
	.string "Maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_5:
# 297 "data//scripts/roaming_traders.pory"
	.string "Huh?{PAUSE 20}\n"
	.string "You can't afford it!$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_6:
# 301 "data//scripts/roaming_traders.pory"
	.string "I doubt you'll find a better deal.\p"
	.string "You should definitely save up if you're\n"
	.string "headed into the backcountry.\p"
	.string "Maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_7:
# 321 "data//scripts/roaming_traders.pory"
	.string "Yeah, this'll come in handy.\n"
	.string "{PAUSE 20}Here you go.$"

RoamingTraders_EventScript_GenerateRoamingSurvivalShop_Text_8:
# 325 "data//scripts/roaming_traders.pory"
	.string "Well I'll be seeing you, trainer.\n"
	.string "I have to hit the road.\p"
	.string "I have a calling to ensure that trainers\n"
	.string "everywhere stay well supplied!$"

RoamingTraders_EventScript_HerbTrader_Text_0:
# 343 "data//scripts/roaming_traders.pory"
	.string "Hey, you must be a TRAINER!\p"
	.string "I'm gathering wild MINTS from around\n"
	.string "HOENN to sell to trainers like you!\p"
	.string "Want to take a look?$"

RoamingTraders_EventScript_HerbTrader_Text_1:
# 348 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "Really?\p"
	.string "That's too bad,\n"
	.string "your POKéMON would love these MINTS.\p"
	.string "But that's okay,{PAUSE 20}\n"
	.string "maybe next time!$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_0:
# 362 "data//scripts/roaming_traders.pory"
	.string "Here are the fresh MINTS I've found\n"
	.string "recently!$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_1:
# 389 "data//scripts/roaming_traders.pory"
	.string "Oh, good eye,\n"
	.string "you're want the {STR_VAR_2}?$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_2:
# 394 "data//scripts/roaming_traders.pory"
	.string "For the {STR_VAR_2} that'll be\n"
	.string "¥{STR_VAR_3}. Sound good?$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_3:
# 398 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "Really?$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_4:
# 402 "data//scripts/roaming_traders.pory"
	.string "That's too bad,\n"
	.string "your POKéMON would love these MINTS.\p"
	.string "But that's okay,{PAUSE 20}\n"
	.string "maybe next time, then!$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_5:
# 409 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "But you don't have the money…$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_6:
# 424 "data//scripts/roaming_traders.pory"
	.string "Oh…{PAUSE 20}{PAUSE 20}\n"
	.string "But you don't have room for it…\p"
	.string "Talk to me again if you make room!$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_7:
# 433 "data//scripts/roaming_traders.pory"
	.string "Great choice!{PAUSE 20}\n"
	.string "Your POKéMON will love this!\l"
	.string "Here you go.$"

RoamingTraders_EventScript_GenerateRoamingHerbShop_Text_8:
# 437 "data//scripts/roaming_traders.pory"
	.string "Well that's all for now,\n"
	.string "I've got to get moving.\p"
	.string "These MINTS don't collect themselves.\p"
	.string "See you next time, trainer!$"

RoamingTraders_EventScript_RoamingMonTrader_Text_0:
# 458 "data//scripts/roaming_traders.pory"
	.string "Ugh{PAUSE 20}{PAUSE 20}\n"
	.string "I caught this {STR_VAR_2},\p"
	.string "but it doesn't get along with my other\n"
	.string "POKéMON at all!\p"
	.string "I know!{PAUSE 20}\n"
	.string "you're a trainer, right?\l"
	.string "Maybe we could do a trade!\p"
	.string "I'd take any PSYCHIC TYPE over this\n"
	.string "{STR_VAR_2}…$"

RoamingTraders_EventScript_RoamingMonTrader_Text_1:
# 462 "data//scripts/roaming_traders.pory"
	.string "PSYCHIC$"

RoamingTraders_EventScript_RoamingMonTrader_Text_2:
# 466 "data//scripts/roaming_traders.pory"
	.string "Ugh{PAUSE 20}{PAUSE 20}\n"
	.string "I caught this {STR_VAR_2},\p"
	.string "but it doesn't get along with my other\n"
	.string "POKéMON at all!\p"
	.string "I know!{PAUSE 20}\n"
	.string "you're a trainer, right?\l"
	.string "Maybe we could do a trade!\p"
	.string "I'd take any BUG TYPE over this\n"
	.string "{STR_VAR_2}…$"

RoamingTraders_EventScript_RoamingMonTrader_Text_3:
# 470 "data//scripts/roaming_traders.pory"
	.string "BUG$"

RoamingTraders_EventScript_RoamingMonTrader_Text_4:
# 474 "data//scripts/roaming_traders.pory"
	.string "Ugh{PAUSE 20}{PAUSE 20}\n"
	.string "I caught this {STR_VAR_2},\p"
	.string "but it doesn't get along with my other\n"
	.string "POKéMON at all!\p"
	.string "I know!{PAUSE 20}\n"
	.string "you're a trainer, right?\l"
	.string "Maybe we could do a trade!\p"
	.string "I'd take any NORMAL TYPE over this\n"
	.string "{STR_VAR_2}…$"

RoamingTraders_EventScript_RoamingMonTrader_Text_5:
# 478 "data//scripts/roaming_traders.pory"
	.string "NORMAL$"

RoamingTraders_EventScript_RoamingMonTrader_Text_6:
# 490 "data//scripts/roaming_traders.pory"
	.string "Ugh{PAUSE 20}{PAUSE 20}\n"
	.string "I caught this {STR_VAR_2},\p"
	.string "but it doesn't get along with my other\n"
	.string "POKéMON at all!\p"
	.string "I know!{PAUSE 20}\n"
	.string "you're a trainer, right?\l"
	.string "Maybe we could do a trade!\p"
	.string "I'd take any WATER TYPE over this\n"
	.string "{STR_VAR_2}…$"

RoamingTraders_EventScript_RoamingMonTrader_Text_7:
# 494 "data//scripts/roaming_traders.pory"
	.string "WATER$"

RoamingTraders_EventScript_RoamingMonTrader_Text_8:
# 498 "data//scripts/roaming_traders.pory"
	.string "Ugh{PAUSE 20}{PAUSE 20}\n"
	.string "I caught this {STR_VAR_2},\p"
	.string "but it doesn't get along with my other\n"
	.string "POKéMON at all!\p"
	.string "I know!{PAUSE 20}\n"
	.string "you're a trainer, right?\l"
	.string "Maybe we could do a trade!\p"
	.string "I'd take any ICE TYPE over this\n"
	.string "{STR_VAR_2}…$"

RoamingTraders_EventScript_RoamingMonTrader_Text_9:
# 502 "data//scripts/roaming_traders.pory"
	.string "ICE$"

RoamingTraders_EventScript_RoamingMonTrader_Text_10:
# 504 "data//scripts/roaming_traders.pory"
	.string "Will you trade your {STR_VAR_3} TYPE\n"
	.string "POKéMON?$"

RoamingTraders_EventScript_RoamingMonTrader_Text_11:
# 515 "data//scripts/roaming_traders.pory"
	.string "Hey, I'm serious, I want to get rid of\n"
	.string "this thing!\p"
	.string "If you really want to trade, come back\n"
	.string "and offer me a real {STR_VAR_3} TYPE\l"
	.string "POKéMON!$"

RoamingTraders_EventScript_RoamingMonTrader_Text_12:
# 532 "data//scripts/roaming_traders.pory"
	.string "Thanks!\p"
	.string "I sure am glad to be rid of that little\n"
	.string "freak!\p"
	.string "Now my POKéMON and I can get back to\n"
	.string "battling!\p"
	.string "Maybe I'll see you around, Trainer.$"

RoamingTraders_EventScript_DeclineTrade_Text_0:
# 561 "data//scripts/roaming_traders.pory"
	.string "Oh, you think you'll find another way\n"
	.string "out of here?\p"
	.string "Good luck!$"

RoamingTraders_EventScript_DeclineTrade_Text_1:
# 564 "data//scripts/roaming_traders.pory"
	.string "Shoot, I was really hoping to get rid of\n"
	.string "this little freak!$"

RoamingTraders_EventScript_AfterWhiteoutTrader_Text_0:
# 574 "data//scripts/roaming_traders.pory"
	.string "Oh{PAUSE 20}…{PAUSE 20} …{PAUSE 20} …{PAUSE 20}\n"
	.string "You're a trainer, but every single one\l"
	.string "of your POKéMON is dead?\p"
	.string "How terrible{PAUSE 20}…{PAUSE 20} …{PAUSE 20} …{PAUSE 20}\p"
	.string "Well maybe with my help, your\n"
	.string "predicament can turn out to be mutually\l"
	.string "beneficial for us.\p"
	.string "I'll take one of your POKéMON corpses\n"
	.string "off your hands in exchange for one of\l"
	.string "my lab rats.$"

RoamingTraders_EventScript_AfterWhiteoutTrader_Text_1:
# 579 "data//scripts/roaming_traders.pory"
	.string "What do you say?$"

RoamingTraders_EventScript_AfterWhiteoutTrader_Text_2:
# 590 "data//scripts/roaming_traders.pory"
	.string "What am I supposed to do with that?\p"
	.string "If you really want to trade, come back\n"
	.string "and offer me a real POKéMON!$"

RoamingTraders_EventScript_AfterWhiteoutTrader_Text_3:
# 600 "data//scripts/roaming_traders.pory"
	.string "That {STR_VAR_2} is certainly not\n"
	.string "impressive, but hopefully it helps.\p"
	.string "I know this {STR_VAR_1} corpse will\n"
	.string "prove useful for my research…\p"
	.string "See you next time, Trainer…$"
