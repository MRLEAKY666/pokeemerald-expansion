# 1 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 2 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_MapScripts::
# 3 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.byte 0
# 4 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 5 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
# 6 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
# 7 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	return
# 8 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 9 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
# 10 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
# 11 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	return
# 12 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 13 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
# 14 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
# 15 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 16 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 17 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 18 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 19 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
# 20 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
# 21 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 22 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 23 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 24 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 25 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
# 26 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 27 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 28 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 29 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitmessage
# 30 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	bpmart BattleFrontier_ExchangeCorner_HeldItemMart, FALSE
# 31 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 32 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 33 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 34 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 35 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.align 2
# 36 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeCorner_HeldItemMart:
# 37 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_AIR_BALLOON
# 38 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 39 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_RED_CARD
# 40 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 41 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 42 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_EJECT_PACK
# 43 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_BLUNDER_POLICY
# 44 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WEAKNESS_POLICY
# 45 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_HERB
# 46 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 47 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 48 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_LEFTOVERS
# 49 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 50 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_QUICK_CLAW
# 51 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 52 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_BRIGHT_POWDER
# 53 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 54 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 55 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FOCUS_BAND
# 56 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_SCOPE_LENS
# 57 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_NONE
# 58 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 59 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 60 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 61 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
# 62 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 63 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 64 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 65 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitmessage
# 66 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	bpmart BattleFrontier_ExchangeCorner_VitaminMart, FALSE
# 67 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 68 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 69 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 70 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 71 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.align 2
# 72 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeCorner_VitaminMart:
# 73 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_HP_UP
# 74 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_PROTEIN
# 75 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_IRON
# 76 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_ZINC
# 77 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CALCIUM
# 78 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CARBOS
# 79 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_PP_UP
# 80 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_NONE
# 81 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 82 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 83 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 84 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorationsIClerk::
# 85 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 86 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 87 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 88 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitmessage
# 89 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	bpmart BattleFrontier_ExchangeCorner_DecorationsIMart, FALSE
# 90 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 91 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 92 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 93 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 94 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.align 2
# 95 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeCorner_DecorationsIMart:
# 96 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_KISS_POSTER
# 97 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_KISS_CUSHION
# 98 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_SMOOCHUM_DOLL
# 99 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_TOGEPI_DOLL
# 100 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_MEOWTH_DOLL
# 101 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CLEFAIRY_DOLL
# 102 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_DITTO_DOLL
# 103 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CYNDAQUIL_DOLL
# 104 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CHIKORITA_DOLL
# 105 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_TOTODILE_DOLL
# 106 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_NONE
# 107 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 108 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 109 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 110 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Man::
# 111 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
# 112 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 113 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 114 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
# 115 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
# 116 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 117 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 118 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
# 119 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 120 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
# 121 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 122 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 123 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 124 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
# 125 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
# 126 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 127 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 128 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
# 129 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
# 130 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 131 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 132 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
# 133 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hello, this is the EXCHANGE SERVICE\n"
# 134 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "CORNER.\p"
# 135 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We exchange the Battle Points you\n"
# 136 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "have collected for lovely prizes.\p"
# 137 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Would you like to exchange your BP\n"
# 138 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "for lovely prizes?$"
# 139 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 140 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
# 141 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you!\n"
# 142 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 143 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 144 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
# 145 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Here is your prize!$"
# 146 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 147 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
# 148 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 149 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have enough Battle Points…$"
# 150 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 151 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
# 152 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 153 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your PC appears to be full…$"
# 154 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 155 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
# 156 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 157 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have space to hold it…$"
# 158 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 159 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
# 160 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you very much.\p"
# 161 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please visit us when you have\n"
# 162 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "saved up Battle Points.$"
# 163 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 164 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
# 165 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Oh, they're so nice!\n"
# 166 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them!\l"
# 167 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Cute cushions!\l"
# 168 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Big plush DOLLS!\l"
# 169 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Little plush DOLLS!\l"
# 170 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them all!$"
# 171 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 172 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
# 173 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Leave it to your mommy!\p"
# 174 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If it's anything you want, I'll go\n"
# 175 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "through anything to get it, honey!$"
# 176 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 177 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
# 178 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If I can get hold of the items here,\n"
# 179 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "my POKéMON will get tougher.\p"
# 180 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You bet they will!\n"
# 181 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "No question about it!$"
# 182 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 183 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
# 184 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hah?\n"
# 185 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "What are you gawking at?\p"
# 186 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I don't like you staring at my plush\n"
# 187 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "doll like that.\p"
# 188 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you want it, go get one yourself!\n"
# 189 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Isn't that right, SMOOCHUM?$"
# 190 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 191 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
# 192 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Did you know?\p"
# 193 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you stretch your record at any of\n"
# 194 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the BATTLE facilities, they start\l"
# 195 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "giving you more and more Battle Points.$"
# 196 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 197 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
# 198 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large poster with a SMOOCHUM print.$"
# 199 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 200 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
# 201 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM cushion.\n"
# 202 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 203 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 204 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
# 205 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM DOLL.\n"
# 206 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 207 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 208 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
# 209 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOGEPI DOLL.\n"
# 210 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 211 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 212 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
# 213 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A MEOWTH DOLL.\n"
# 214 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 215 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 216 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
# 217 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CLEFAIRY DOLL.\n"
# 218 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 219 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 220 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
# 221 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A DITTO DOLL.\n"
# 222 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 223 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 224 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
# 225 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CYNDAQUIL DOLL.\n"
# 226 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 227 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 228 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
# 229 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CHIKORITA DOLL.\n"
# 230 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 231 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 232 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
# 233 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOTODILE DOLL.\n"
# 234 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 235 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 236 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
# 237 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large DOLL.\n"
# 238 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 239 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 240 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
# 241 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat ATTACK of one\n"
# 242 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 243 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 244 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
# 245 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. ATK of one\n"
# 246 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 247 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 248 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
# 249 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat DEFENSE of one\n"
# 250 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 251 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 252 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
# 253 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. DEF of one\n"
# 254 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 255 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 256 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
# 257 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SPEED of one\n"
# 258 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 259 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 260 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
# 261 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the HP of one POKéMON.$"
# 262 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 263 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
# 264 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that gradually restores\n"
# 265 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "HP in battle.$"
# 266 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 267 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
# 268 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that restores any\n"
# 269 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "lowered stat.$"
# 270 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 271 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
# 272 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally allows\n"
# 273 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the first strike.$"
# 274 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 275 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
# 276 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that snaps POKéMON out\n"
# 277 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "of infatuation.$"
# 278 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 279 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
# 280 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that casts a glare to\n"
# 281 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "reduce accuracy.$"
# 282 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 283 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
# 284 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises a move's power, but permits\n"
# 285 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "only that move.$"
# 286 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 287 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
# 288 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that may cause flinching\n"
# 289 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "when the foe is hit.$"
# 290 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 291 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
# 292 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally\n"
# 293 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "prevents fainting.$"
# 294 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 295 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
# 296 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that raises the\n"
# 297 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "critical-hit rate.$"
