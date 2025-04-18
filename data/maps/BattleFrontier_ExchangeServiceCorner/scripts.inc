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
	@ waitmessage
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
	.2byte ITEM_POWER_WEIGHT
# 41 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_BRACER
# 42 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_BELT
# 43 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_LENS
# 44 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_BAND
# 45 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_ANKLET
# 46 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_TOXIC_ORB
# 47 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FLAME_ORB
# 48 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_EJECT_PACK
# 49 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_BLUNDER_POLICY
# 50 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WEAKNESS_POLICY
# 51 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_POWER_HERB
# 52 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 53 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 54 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_LEFTOVERS
# 55 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 56 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_QUICK_CLAW
# 57 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 58 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_BRIGHT_POWDER
# 59 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CHOICE_BAND
# 60 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CHOICE_SPECS
# 61 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CHOICE_SCARF
# 62 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 63 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_FOCUS_BAND
# 64 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_SCOPE_LENS
# 65 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_NONE
# 66 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 67 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 68 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 69 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
# 70 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 71 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 72 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 73 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	@ waitmessage
# 74 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	bpmart BattleFrontier_ExchangeCorner_VitaminMart, FALSE
# 75 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 76 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 77 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 78 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 79 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.align 2
# 80 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeCorner_VitaminMart:
# 81 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_HP_UP
# 82 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_PROTEIN
# 83 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_IRON
# 84 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_ZINC
# 85 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CALCIUM
# 86 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_CARBOS
# 87 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_PP_UP
# 88 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 89 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte ITEM_NONE
# 90 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 91 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 92 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 93 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorationsIClerk::
# 94 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 95 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 96 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 97 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitmessage
# 98 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	bpmart BattleFrontier_ExchangeCorner_DecorationsIMart, FALSE
# 99 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 100 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 101 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 102 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 103 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.align 2
# 104 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeCorner_DecorationsIMart:
# 105 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_KISS_POSTER
# 106 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_KISS_CUSHION
# 107 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_SMOOCHUM_DOLL
# 108 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_TOGEPI_DOLL
# 109 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_MEOWTH_DOLL
# 110 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CLEFAIRY_DOLL
# 111 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_DITTO_DOLL
# 112 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CYNDAQUIL_DOLL
# 113 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_CHIKORITA_DOLL
# 114 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_TOTODILE_DOLL
# 115 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.2byte DECOR_NONE
# 116 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 117 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 118 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 119 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Man::
# 120 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
# 121 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 122 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 123 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
# 124 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
# 125 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 126 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 127 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
# 128 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 129 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
# 130 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 131 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 132 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 133 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
# 134 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
# 135 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 136 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 137 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
# 138 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
# 139 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 140 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 141 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
# 142 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hello, this is the EXCHANGE SERVICE\n"
# 143 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "CORNER.\p"
# 144 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We exchange the Battle Points you\n"
# 145 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "have collected for lovely prizes.\p"
# 146 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Would you like to exchange your BP\n"
# 147 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "for lovely prizes?$"
# 148 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 149 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
# 150 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you!\n"
# 151 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 152 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 153 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
# 154 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Here is your prize!$"
# 155 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 156 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
# 157 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 158 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have enough Battle Points…$"
# 159 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 160 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
# 161 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 162 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your PC appears to be full…$"
# 163 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 164 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
# 165 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 166 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have space to hold it…$"
# 167 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 168 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
# 169 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you very much.\p"
# 170 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please visit us when you have\n"
# 171 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "saved up Battle Points.$"
# 172 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 173 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
# 174 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Oh, they're so nice!\n"
# 175 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them!\l"
# 176 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Cute cushions!\l"
# 177 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Big plush DOLLS!\l"
# 178 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Little plush DOLLS!\l"
# 179 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them all!$"
# 180 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 181 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
# 182 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Leave it to your mommy!\p"
# 183 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If it's anything you want, I'll go\n"
# 184 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "through anything to get it, honey!$"
# 185 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 186 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
# 187 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If I can get hold of the items here,\n"
# 188 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "my POKéMON will get tougher.\p"
# 189 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You bet they will!\n"
# 190 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "No question about it!$"
# 191 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 192 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
# 193 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hah?\n"
# 194 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "What are you gawking at?\p"
# 195 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I don't like you staring at my plush\n"
# 196 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "doll like that.\p"
# 197 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you want it, go get one yourself!\n"
# 198 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Isn't that right, SMOOCHUM?$"
# 199 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 200 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
# 201 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Did you know?\p"
# 202 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you stretch your record at any of\n"
# 203 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the BATTLE facilities, they start\l"
# 204 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "giving you more and more Battle Points.$"
# 205 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 206 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
# 207 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large poster with a SMOOCHUM print.$"
# 208 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 209 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
# 210 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM cushion.\n"
# 211 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 212 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 213 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
# 214 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM DOLL.\n"
# 215 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 216 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 217 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
# 218 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOGEPI DOLL.\n"
# 219 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 220 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 221 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
# 222 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A MEOWTH DOLL.\n"
# 223 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 224 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 225 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
# 226 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CLEFAIRY DOLL.\n"
# 227 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 228 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 229 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
# 230 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A DITTO DOLL.\n"
# 231 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 232 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 233 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
# 234 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CYNDAQUIL DOLL.\n"
# 235 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 236 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 237 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
# 238 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CHIKORITA DOLL.\n"
# 239 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 240 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 241 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
# 242 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOTODILE DOLL.\n"
# 243 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 244 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 245 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
# 246 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large DOLL.\n"
# 247 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 248 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 249 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
# 250 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat ATTACK of one\n"
# 251 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 252 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 253 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
# 254 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. ATK of one\n"
# 255 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 256 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 257 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
# 258 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat DEFENSE of one\n"
# 259 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 260 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 261 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
# 262 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. DEF of one\n"
# 263 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 264 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 265 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
# 266 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SPEED of one\n"
# 267 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON.$"
# 268 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 269 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
# 270 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the HP of one POKéMON.$"
# 271 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 272 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
# 273 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that gradually restores\n"
# 274 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "HP in battle.$"
# 275 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 276 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
# 277 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that restores any\n"
# 278 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "lowered stat.$"
# 279 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 280 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
# 281 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally allows\n"
# 282 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the first strike.$"
# 283 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 284 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
# 285 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that snaps POKéMON out\n"
# 286 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "of infatuation.$"
# 287 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 288 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
# 289 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that casts a glare to\n"
# 290 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "reduce accuracy.$"
# 291 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 292 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
# 293 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises a move's power, but permits\n"
# 294 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "only that move.$"
# 295 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 296 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
# 297 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that may cause flinching\n"
# 298 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "when the foe is hit.$"
# 299 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 300 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
# 301 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally\n"
# 302 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "prevents fainting.$"
# 303 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 304 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
# 305 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that raises the\n"
# 306 "data//maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "critical-hit rate.$"
