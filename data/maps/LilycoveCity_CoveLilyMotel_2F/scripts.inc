# 1 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 2 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_MapScripts::
# 3 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.byte 0
# 4 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 5 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
# 6 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 7 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 8 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 9 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 10 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 11 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 12 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 13 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 14 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 15 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
# 16 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 17 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 18 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 19 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
# 20 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 21 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 22 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitfanfare
# 23 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 24 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 25 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 26 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
# 27 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
# 28 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 29 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 30 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 31 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitstate
# 32 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 33 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 34 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 35 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 36 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 37 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 38 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 39 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 40 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 41 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 42 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 43 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ProfOak::
# 44 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 45 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 46 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak
# 47 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak
# 48 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 49 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex
# 50 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 51 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 52 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak::
# 53 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_PROF_OAK
# 54 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak, MSGBOX_DEFAULT
# 55 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 56 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_APokedex, MSGBOX_DEFAULT
# 57 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 58 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 59 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak::
# 60 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak, MSGBOX_DEFAULT
# 61 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 62 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 63 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 64 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 65 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 66 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 67 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 68 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 69 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 70 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 71 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 72 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 73 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 74 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 75 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 76 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 77 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 78 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 79 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 80 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 81 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 82 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 83 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 84 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 85 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 86 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 87 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 88 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 89 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 90 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 91 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 92 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 93 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 94 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 95 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 96 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 97 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 98 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 99 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
# 100 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 101 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 102 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This POKéDEX is completely filled!\n"
# 103 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love POKéMON!\p"
# 104 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 105 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 106 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 107 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 108 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 109 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 110 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 111 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 112 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 113 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 114 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 115 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 116 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 117 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 118 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 119 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 120 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 121 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 122 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 123 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 124 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 125 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 126 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 127 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 128 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 129 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 130 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 131 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 132 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 133 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 134 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 135 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 136 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 137 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 138 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 139 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 140 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 141 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 142 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 143 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 144 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 145 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 146 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 147 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 148 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 149 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 150 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 151 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 152 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 153 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 154 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 155 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 156 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"
# 157 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 158 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak:
# 159 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF. OAK: Ah, hello. I am the\n"
# 160 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON Professor, PROF. OAK.\p"
# 161 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you are?\p"
# 162 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 163 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}! Excellent!$"
# 164 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 165 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_APokedex:
# 166 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 167 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "What have you got there?\n"
# 168 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A POKéDEX?\p"
# 169 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm very familiar with POKéDEX\n"
# 170 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "technology.\p"
# 171 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look at yours?$"
# 172 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 173 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak:
# 174 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF: OAK: Ah, {PLAYER}.\n"
# 175 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Still working on that POKéDEX?\p"
# 176 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look?$"
# 177 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 178 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno:
# 179 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 180 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 181 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?$"
# 182 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 183 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno:
# 184 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 185 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 186 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ARTICUNO?$"
# 187 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 188 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtArticuno:
# 189 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 190 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO?\p"
# 191 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 192 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 193 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 194 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos:
# 195 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 196 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 197 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?$"
# 198 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 199 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos:
# 200 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 201 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 202 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ZAPDOS?$"
# 203 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 204 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos:
# 205 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 206 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ZAPDOS?\p"
# 207 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 208 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 209 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 210 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres:
# 211 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 212 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 213 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen MOLTRES?$"
# 214 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 215 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres:
# 216 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 217 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 218 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES?$"
# 219 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 220 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres:
# 221 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 222 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "MOLTRES?\p"
# 223 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 224 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 225 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 226 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres:
# 227 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've even\n"
# 228 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES!?$"
# 229 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 230 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos:
# 231 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 232 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 233 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 234 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen ZAPDOS!?$"
# 235 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 236 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres:
# 237 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 238 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 239 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 240 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 241 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 242 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres:
# 243 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 244 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 245 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?\p"
# 246 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 247 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 248 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds:
# 249 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 250 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 251 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 252 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "…And You've seen ZAPDOS?\p"
# 253 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 254 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 255 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds:
# 256 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm visiting the HOENN region\n"
# 257 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to study the legendary bird POKéMON:\l"
# 258 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES.\p"
# 259 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you can capture them all and\n"
# 260 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me your POKéDEX, it would\l"
# 261 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "help my research immensely.$"
# 262 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 263 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NavelRock:
# 264 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}, my research, along\n"
# 265 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "with the POKéDEX data you've\l"
# 266 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "shown me . . .\p"
# 267 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yes, it strongly indicates that\n"
# 268 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "NAVEL ROCK is an important\l"
# 269 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "location for these POKéMON.$"
# 270 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 271 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket:
# 272 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this to the ferry port,\n"
# 273 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "and show it to the attendant$"
# 274 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 275 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket:
# 276 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF OAK: That ticket will allow\n"
# 277 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "you to travel to NAVEL ROCK.$"
# 278 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 279 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere:
# 280 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Meet me at NAVEL ROCK.\p"
# 281 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "We'll see if we can't make yet\n"
# 282 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "another groundbreaking discovery!$"
# 283 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 284 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn:
# 285 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Keep up the good work, {PLAYER}.\p"
# 286 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to HOENN because I\n"
# 287 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "heard that some rare bird\l"
# 288 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON were roosting here.\p"
# 289 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Come back  and show me if you\n"
# 290 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "find any POKéMON like that.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex::
# 294 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playse SE_PC_ON
# 295 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitse
# 296 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ARTICUNO
# 297 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 298 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ZAPDOS
# 299 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 300 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_MOLTRES
# 301 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_40
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36:
# 311 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_35
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31:
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_30
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26:
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_25
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21:
# 352 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16:
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11:
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9:
# 472 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn
# 473 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 474 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1:
# 477 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 478 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 479 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2:
# 303 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno
# 304 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 305 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 306 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_45
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_3:
# 312 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos
# 313 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 314 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 315 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_47
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4:
# 321 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres
# 322 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 323 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 324 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_49
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5:
# 330 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos
# 331 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 332 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 333 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_52
# 346 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 347 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_63
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_6:
# 353 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres
# 354 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 355 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 356 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_55
# 369 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 370 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_68
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7:
# 376 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres
# 377 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 378 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 379 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_58
# 392 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 393 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_73
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8:
# 399 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds
# 400 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 401 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 402 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_61
# 438 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 439 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_79
# 456 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 457 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_85
# 465 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 466 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 467 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10:
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_12
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_12:
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15:
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17:
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20:
# 352 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22:
# 352 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_6
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_25:
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_27
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_27:
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_30:
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_32
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_32:
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_35:
# 311 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_37
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_37:
# 311 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_3
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_40:
# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_42
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_42:
# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_45:
# 307 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 308 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_47:
# 316 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 317 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_49:
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 326 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_52:
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 335 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 336 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 337 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_66
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_65:
# 341 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 342 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 343 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_55:
# 357 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 358 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 359 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 360 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_71
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_70:
# 364 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 365 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 366 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_58:
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 381 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 382 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 383 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_76
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_75:
# 387 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 388 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 389 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_61:
# 403 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 404 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 405 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 406 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_82
# 433 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 434 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 435 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_63:
# 348 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 349 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_66:
# 338 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos
# 339 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_65

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_68:
# 371 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 372 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_71:
# 361 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 362 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_70

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_73:
# 394 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 395 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_76:
# 384 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 385 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_75

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_79:
# 440 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 441 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 442 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 443 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_88
# 451 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 452 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 453 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_82:
# 407 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos
# 408 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 409 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 410 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_91
# 428 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 429 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 430 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_85:
# 458 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 459 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 460 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 461 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 462 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_88:
# 444 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 445 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 446 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 447 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 448 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_91:
# 411 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres
# 412 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 413 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NavelRock
# 414 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 415 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_94
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_93:
# 424 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere
# 425 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_94:
# 416 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket
# 417 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 418 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 419 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 420 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 421 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket
# 422 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_93

