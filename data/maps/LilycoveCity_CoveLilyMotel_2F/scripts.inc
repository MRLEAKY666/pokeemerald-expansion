# 1 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 2 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_MapScripts::
# 3 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_CoveLilyMotel_OnTransition
# 4 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.byte 0
# 5 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 6 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_OnTransition:
# 7 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_3
# 8 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 9 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 10 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
# 11 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 12 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 13 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 14 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 15 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 16 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 17 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 18 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 19 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 20 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
# 21 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 22 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 23 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 24 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
# 25 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 26 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 27 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitfanfare
# 28 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 29 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 30 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 31 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
# 32 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
# 33 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 34 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 35 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 36 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitstate
# 37 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 38 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 39 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 40 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 41 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 42 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 43 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 44 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 45 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 46 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 47 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 48 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ProfOak::
# 49 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 50 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 51 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak
# 52 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak
# 53 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 54 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex
# 55 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 56 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 57 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak::
# 58 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_PROF_OAK
# 59 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak, MSGBOX_DEFAULT
# 60 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 61 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_APokedex, MSGBOX_DEFAULT
# 62 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 63 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 64 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak::
# 65 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak, MSGBOX_DEFAULT
# 66 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 67 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 68 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 69 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 70 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 71 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 72 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 73 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 74 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 75 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 76 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 77 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 78 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 79 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 80 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 81 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 82 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 83 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 84 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 85 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 86 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 87 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 88 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 89 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 90 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 91 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 92 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 93 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 94 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 95 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 96 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 97 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 98 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 99 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 100 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 101 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 102 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 103 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 104 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
# 105 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 106 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 107 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This POKéDEX is completely filled!\n"
# 108 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love POKéMON!\p"
# 109 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 110 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 111 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 112 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 113 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 114 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 115 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 116 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 117 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 118 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 119 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 120 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 121 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 122 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 123 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 124 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 125 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 126 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 127 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 128 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 129 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 130 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 131 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 132 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 133 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 134 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 135 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 136 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 137 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 138 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 139 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 140 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 141 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 142 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 143 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 144 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 145 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 146 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 147 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 148 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 149 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 150 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 151 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 152 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 153 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 154 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 155 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 156 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 157 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 158 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 159 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 160 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 161 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"
# 162 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 163 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak:
# 164 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF. OAK: Ah, hello. I am the\n"
# 165 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON Professor, PROF. OAK.\p"
# 166 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you are?\p"
# 167 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 168 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}! Excellent!$"
# 169 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 170 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_APokedex:
# 171 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 172 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "What have you got there?\n"
# 173 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A POKéDEX?\p"
# 174 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm very familiar with POKéDEX\n"
# 175 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "technology.\p"
# 176 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look at yours?$"
# 177 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 178 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak:
# 179 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF: OAK: Ah, {PLAYER}.\n"
# 180 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Still working on that POKéDEX?\p"
# 181 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look?$"
# 182 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 183 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno:
# 184 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 185 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 186 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?$"
# 187 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 188 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno:
# 189 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 190 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 191 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ARTICUNO?$"
# 192 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 193 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtArticuno:
# 194 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 195 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO?\p"
# 196 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 197 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 198 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 199 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos:
# 200 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 201 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 202 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?$"
# 203 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 204 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos:
# 205 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 206 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 207 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ZAPDOS?$"
# 208 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 209 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos:
# 210 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 211 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ZAPDOS?\p"
# 212 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 213 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 214 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 215 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres:
# 216 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 217 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 218 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen MOLTRES?$"
# 219 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 220 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres:
# 221 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 222 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 223 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES?$"
# 224 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 225 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres:
# 226 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 227 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "MOLTRES?\p"
# 228 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 229 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 230 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 231 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres:
# 232 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've even\n"
# 233 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES!?$"
# 234 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 235 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos:
# 236 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 237 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 238 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 239 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen ZAPDOS!?$"
# 240 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 241 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres:
# 242 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 243 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 244 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 245 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 246 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 247 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres:
# 248 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 249 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 250 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?\p"
# 251 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 252 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 253 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds:
# 254 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 255 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 256 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 257 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "…And You've seen ZAPDOS?\p"
# 258 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 259 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 260 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds:
# 261 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm visiting the HOENN region\n"
# 262 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to study the legendary bird POKéMON:\l"
# 263 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES.\p"
# 264 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you can capture them all and\n"
# 265 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me your POKéDEX, it would\l"
# 266 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "help my research immensely.$"
# 267 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 268 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NavelRock:
# 269 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}, my research, along\n"
# 270 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "with the POKéDEX data you've\l"
# 271 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "shown me . . .\p"
# 272 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yes, it strongly indicates that\n"
# 273 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "NAVEL ROCK is an important\l"
# 274 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "location for these POKéMON.$"
# 275 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 276 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket:
# 277 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this to the ferry port,\n"
# 278 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "and show it to the attendant$"
# 279 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 280 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket:
# 281 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF OAK: That ticket will allow\n"
# 282 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "you to travel to NAVEL ROCK.$"
# 283 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 284 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere:
# 285 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Meet me at NAVEL ROCK.\p"
# 286 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "We'll see if we can't make yet\n"
# 287 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "another groundbreaking discovery!$"
# 288 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 289 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn:
# 290 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Keep up the good work, {PLAYER}.\p"
# 291 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to HOENN because I\n"
# 292 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "heard that some rare bird\l"
# 293 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON were roosting here.\p"
# 294 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Come back  and show me if you\n"
# 295 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "find any POKéMON like that.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex::
# 299 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playse SE_PC_ON
# 300 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitse
# 301 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ARTICUNO
# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 303 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ZAPDOS
# 304 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 305 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_MOLTRES
# 306 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 307 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_40
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36:
# 316 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_35
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31:
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_30
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26:
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_25
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21:
# 357 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16:
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11:
# 403 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_0, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9:
# 478 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn
# 479 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 480 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1:
# 483 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 484 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 485 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2:
# 308 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno
# 309 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 310 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 311 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_45
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_3:
# 317 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos
# 318 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 319 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_47
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4:
# 326 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres
# 327 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 328 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_49
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5:
# 335 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos
# 336 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 337 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 338 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_52
# 351 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 352 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_63
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_6:
# 358 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres
# 359 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 360 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 361 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_55
# 374 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_68
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7:
# 381 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres
# 382 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 383 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 384 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_58
# 397 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_73
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8:
# 404 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds
# 405 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 406 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 407 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_61
# 444 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 445 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_79
# 462 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 463 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_85
# 471 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 472 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 473 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10:
# 403 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_12
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_12:
# 403 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_9

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15:
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17:
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20:
# 357 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22:
# 357 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_6
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_25:
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_27
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_27:
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_30:
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_32
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_32:
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_26

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_35:
# 316 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_37
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_37:
# 316 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_3
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_31

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_40:
# 307 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_1, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_42
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_42:
# 307 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_TEMP_2, FALSE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_36

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_45:
# 312 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 313 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_47:
# 321 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 322 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_49:
# 330 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 331 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_52:
# 339 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 340 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 341 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 342 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_66
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_65:
# 346 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 347 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 348 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_55:
# 362 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 363 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 364 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 365 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_71
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_70:
# 369 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 370 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 371 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_58:
# 385 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 386 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 387 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 388 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_76
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_75:
# 392 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 393 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 394 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_61:
# 408 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno
# 409 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 410 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 411 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_82
# 439 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 440 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 441 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_63:
# 353 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 354 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_66:
# 343 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos
# 344 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_65

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_68:
# 376 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 377 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_71:
# 366 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 367 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_70

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_73:
# 399 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 400 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_76:
# 389 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 390 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_75

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_79:
# 446 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos
# 447 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 448 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 449 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_88
# 457 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 458 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 459 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_82:
# 412 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos
# 413 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 414 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 415 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_91
# 434 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 435 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 436 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_85:
# 464 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres
# 465 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 466 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 467 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 468 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_88:
# 450 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres
# 451 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 452 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds
# 453 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 454 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_91:
# 416 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres
# 417 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 418 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NavelRock
# 419 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 420 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_94
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_93:
# 430 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere
# 431 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_94:
# 421 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket
# 422 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 423 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 424 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 425 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 426 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_START_LUGIA_QUEST
# 427 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket
# 428 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_93

