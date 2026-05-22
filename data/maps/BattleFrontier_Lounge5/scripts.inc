# 1 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 2 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_MapScripts::
# 3 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.byte 0
# 4 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 5 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirl::
# 6 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 7 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 8 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
# 9 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 10 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	special ChoosePartyMon
# 11 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 12 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 13 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 14 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 15 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
# 16 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	special ShowNatureGirlMessage
# 17 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	waitmessage
# 18 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	waitbuttonpress
# 19 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 20 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 21 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 22 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
# 23 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
# 24 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 25 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 26 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 27 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
# 28 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
# 29 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 30 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 31 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 32 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_Gentleman::
# 33 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
# 34 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 35 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 36 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_BlackBelt::
# 37 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
# 38 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 39 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 40 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_LittleBoy::
# 41 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
# 42 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 43 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 44 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlGreeting::
# 45 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Ehehe!\n"
# 46 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can tell what POKéMON are thinking!\p"
# 47 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Please!\n"
# 48 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Can I see your POKéMON?$"
# 49 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 50 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
# 51 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Boo!\n"
# 52 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Cheapie!$"
# 53 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 54 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
# 55 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 56 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 57 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 58 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 59 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 60 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
# 61 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 62 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 63 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 64 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 65 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 66 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
# 67 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 68 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 69 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 70 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 71 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 72 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
# 73 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 74 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 75 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 76 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 77 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 78 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
# 79 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 80 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 81 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it worries about itself whether\l"
# 82 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "or not it has a lot of ouchies!$"
# 83 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 84 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
# 85 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 86 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 87 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 88 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 89 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 90 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
# 91 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 92 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 93 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 94 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 95 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 96 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
# 97 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 98 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 99 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 100 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 101 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 102 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
# 103 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 104 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 105 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it likes to be sneaky even\l"
# 106 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 107 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 108 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlEgg::
# 109 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That's silly! An EGG is asleep!\n"
# 110 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can't talk to it!$"
# 111 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 112 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
# 113 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "How charming!\n"
# 114 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little lady claims she can\l"
# 115 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "understand POKéMON!$"
# 116 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 117 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
# 118 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I have this feeling that the little girl\n"
# 119 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "is saying something profound.$"
# 120 "data//maps/BattleFrontier_Lounge5/scripts.pory"

# 121 "data//maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
# 122 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I know something!\p"
# 123 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little girl plays at the red house\n"
# 124 "data//maps/BattleFrontier_Lounge5/scripts.pory"
	.string "a lot!$"
