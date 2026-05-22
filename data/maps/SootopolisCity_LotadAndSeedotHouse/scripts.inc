# 1 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 2 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_MapScripts::
# 3 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.byte 0
# 4 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 5 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
# 6 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 7 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 8 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 9 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
# 10 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 11 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 12 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
# 13 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareSeedotSize
# 14 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
# 15 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
# 16 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
# 17 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 18 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 19 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 20 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
# 21 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
# 22 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 23 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 24 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 25 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
# 26 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
# 27 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 28 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 29 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 30 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
# 31 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
# 32 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 33 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 34 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 35 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
# 36 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
# 37 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 38 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
# 39 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 40 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 41 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 42 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 43 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
# 44 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
# 45 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 46 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 47 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 48 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
# 49 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 50 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 51 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 52 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
# 53 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 54 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 55 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
# 56 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareLotadSize
# 57 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
# 58 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
# 59 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
# 60 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 61 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 62 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 63 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
# 64 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
# 65 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 66 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 67 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 68 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
# 69 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
# 70 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 71 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 72 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 73 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
# 74 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
# 75 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 76 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 77 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 78 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
# 79 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
# 80 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 81 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
# 82 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 83 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 84 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 85 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 86 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
# 87 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
# 88 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 89 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 90 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 91 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
# 92 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 93 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 94 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
# 95 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 96 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 97 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 98 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
# 99 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 100 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 101 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
# 102 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 103 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 104 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 105 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
# 106 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the POKéMON SEEDOT?\n"
# 107 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's hardly ever seen in SOOTOPOLIS.\p"
# 108 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Anyway, I love big SEEDOT.\n"
# 109 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The bigger the better.\p"
# 110 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But my younger brother, he says that\n"
# 111 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "LOTAD is bigger.\p"
# 112 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's silly.\n"
# 113 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "SEEDOT has to be bigger than that!\p"
# 114 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Huh? Do you have a SEEDOT with you?\n"
# 115 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please, show me!$"
# 116 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 117 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
# 118 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}!\n"
# 119 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, my gosh, this is a big one!\p"
# 120 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might even beat the big LOTAD\n"
# 121 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "my younger brother saw!\p"
# 122 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me.\n"
# 123 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 124 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 125 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 126 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
# 127 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a POTION.$"
# 128 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 129 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
# 130 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 131 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your BAG is crammed full.$"
# 132 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 133 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
# 134 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}, is it?\p"
# 135 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger SEEDOT\n"
# 136 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one.$"
# 137 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 138 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
# 139 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, now this is quite something…\n"
# 140 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's not a SEEDOT!$"
# 141 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 142 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
# 143 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "You don't have a big SEEDOT?\n"
# 144 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's too bad…\p"
# 145 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big SEEDOT, please\n"
# 146 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me.$"
# 147 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 148 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
# 149 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest SEEDOT in history!\n"
# 150 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3} giant!\p"
# 151 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A SEEDOT bigger than a LOTAD\n"
# 152 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
# 153 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 154 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
# 155 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the POKéMON LOTAD?\n"
# 156 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's rarely seen in SOOTOPOLIS.\p"
# 157 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "I love, I mean love, big LOTAD!\p"
# 158 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "My big brother says that SEEDOT is\n"
# 159 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "bigger.\p"
# 160 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But that's wrong! Everyone knows that\n"
# 161 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "LOTAD is a lot bigger.\p"
# 162 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh? Do you have a LOTAD?\n"
# 163 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please show me!$"
# 164 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 165 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
# 166 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}!\n"
# 167 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Wow, that is big!\p"
# 168 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might be even bigger than the huge\n"
# 169 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "SEEDOT my big brother saw.\p"
# 170 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me!\n"
# 171 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 172 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 173 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 174 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
# 175 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a POTION.$"
# 176 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 177 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
# 178 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 179 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your BAG is crammed full.$"
# 180 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 181 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
# 182 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}?\p"
# 183 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger LOTAD\n"
# 184 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one here.$"
# 185 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 186 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
# 187 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Well, isn't this something!\n"
# 188 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's no LOTAD!$"
# 189 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 190 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
# 191 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Don't you have a big LOTAD?\n"
# 192 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "How disappointing…\p"
# 193 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big LOTAD, please\n"
# 194 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me!$"
# 195 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 196 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
# 197 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest LOTAD in history!\n"
# 198 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3} colossus!\p"
# 199 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A LOTAD bigger than a SEEDOT\n"
# 200 "data//maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
