# 1 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 2 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_MapScripts::
# 3 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.byte 0
# 4 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 5 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_Cutter::
# 6 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	lock
# 7 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	faceplayer
# 8 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
# 9 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, RustboroCity_CuttersHouse_EventScript_NotReadyYet
# 10 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
# 11 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	giveitem ITEM_HM_CUT
# 12 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_CUT
# 13 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
# 14 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	release
# 15 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 16 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 17 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_NotReadyYet::
# 18 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_NotReadyYet, MSGBOX_DEFAULT
# 19 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	release
# 20 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 21 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 22 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_ExplainCut::
# 23 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
# 24 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	release
# 25 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 26 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 27 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_Lass::
# 28 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
# 29 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 30 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 31 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
# 32 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That determined expression…\n"
# 33 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That limber way you move…\l"
# 34 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "And your well-trained POKéMON…\p"
# 35 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "You're obviously a skilled TRAINER!\p"
# 36 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "No, wait, don't say a word.\n"
# 37 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "I can tell just by looking at you.\p"
# 38 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "I'm sure that you can put this\n"
# 39 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "HIDDEN MACHINE to good use.\p"
# 40 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "No need to be modest or shy.\n"
# 41 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Go on, take it!$"
# 42 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 43 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_ExplainCut:
# 44 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That HIDDEN MACHINE, or HM for\n"
# 45 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "short, is CUT.\p"
# 46 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "An HM move is one that can be used\n"
# 47 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "by POKéMON outside of battle.\p"
# 48 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Any POKéMON that's learned CUT can\n"
# 49 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "chop down thin trees if the TRAINER\l"
# 50 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "has earned the STONE BADGE.\p"
# 51 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "And, unlike a TM, an HM can be used\n"
# 52 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "more than once.$"
# 53 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 54 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_NotReadyYet:
# 55 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "I know a useful hidden skill for\n"
# 56 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "traversing the backcountry.\p"
# 57 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Hmm . . . You show some promise,\n"
# 58 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "but you're not ready yet.$"
# 59 "data//maps/RustboroCity_CuttersHouse/scripts.pory"

# 60 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
# 61 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "When they were expanding the city of\n"
# 62 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "RUSTBORO, my dad helped out.\p"
# 63 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "He made his POKéMON use CUT to clear\n"
# 64 "data//maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "the land of trees.$"
