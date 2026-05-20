# 1 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 2 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_MapScripts::
# 3 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_CoveLilyMotel_OnTransition
# 4 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.byte 0

LilycoveCity_CoveLilyMotel_OnTransition::
# 9 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_CAUGHT_LUGIA, LilycoveCity_CoveLilyMotel_OnTransition_1
	return

LilycoveCity_CoveLilyMotel_OnTransition_1:
# 10 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_3
	return


# 14 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 15 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 16 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
# 17 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 18 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 19 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 20 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 21 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 22 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 23 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 24 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 25 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 26 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
# 27 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 28 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 29 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 30 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
# 31 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 32 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 33 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitfanfare
# 34 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 35 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 36 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 37 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
# 38 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
# 39 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 40 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 41 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 42 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 43 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 44 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 45 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 46 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 47 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 48 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 49 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 50 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 51 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 52 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 53 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ProfOak::
# 54 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 55 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 56 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_START_LUGIA_QUEST, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock
# 57 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak
# 58 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak
# 59 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 60 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex
# 61 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 62 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 63 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak::
# 64 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_PROF_OAK
# 65 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak, MSGBOX_DEFAULT
# 66 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_APokedex, MSGBOX_DEFAULT
# 67 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 68 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 69 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak::
# 70 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak, MSGBOX_DEFAULT
# 71 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 72 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 73 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 74 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 75 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 76 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 77 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 78 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 79 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 80 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 81 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 82 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 83 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 84 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 85 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 86 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 87 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 88 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 89 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 90 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 91 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 92 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 93 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 94 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 95 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 96 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 97 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 98 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 99 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 100 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 101 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 102 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 103 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 104 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 105 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 106 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 107 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 108 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 109 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
# 110 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 111 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 112 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This POKéDEX is completely filled!\n"
# 113 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love POKéMON!\p"
# 114 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 115 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 116 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 117 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 118 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 119 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 120 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 121 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 122 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 123 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 124 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 125 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 126 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 127 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 128 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 129 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 130 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 131 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 132 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 133 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 134 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 135 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 136 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 137 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 138 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 139 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 140 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 141 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 142 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 143 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 144 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 145 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 146 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 147 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 148 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 149 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 150 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 151 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 152 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 153 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 154 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 155 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 156 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 157 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 158 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 159 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 160 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 161 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 162 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 163 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 164 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 165 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 166 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"
# 167 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 168 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak:
# 169 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF. OAK: Ah, hello. I am the\n"
# 170 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON Professor, PROF. OAK.\p"
# 171 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you are?\p"
# 172 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 173 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}! Excellent!$"
# 174 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 175 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_APokedex:
# 176 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 177 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "What have you got there?\n"
# 178 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A POKéDEX?\p"
# 179 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm very familiar with POKéDEX\n"
# 180 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "technology.\p"
# 181 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look at yours?$"
# 182 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 183 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak:
# 184 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF: OAK: Ah, {PLAYER}.\n"
# 185 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Still working on that POKéDEX?\p"
# 186 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look?$"
# 187 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 188 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno:
# 189 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 190 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 191 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?$"
# 192 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 193 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno:
# 194 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 195 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 196 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ARTICUNO?$"
# 197 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 198 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtArticuno:
# 199 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 200 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO?\p"
# 201 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 202 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 203 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 204 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos:
# 205 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 206 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 207 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?$"
# 208 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 209 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos:
# 210 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 211 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 212 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ZAPDOS?$"
# 213 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 214 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos:
# 215 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 216 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ZAPDOS?\p"
# 217 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 218 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 219 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 220 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres:
# 221 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 222 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 223 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen MOLTRES?$"
# 224 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 225 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres:
# 226 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 227 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 228 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES?$"
# 229 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 230 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres:
# 231 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 232 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "MOLTRES?\p"
# 233 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 234 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 235 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 236 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres:
# 237 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've even\n"
# 238 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES!?$"
# 239 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 240 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos:
# 241 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 242 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 243 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 244 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen ZAPDOS!?$"
# 245 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 246 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres:
# 247 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 248 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 249 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 250 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 251 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 252 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres:
# 253 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 254 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 255 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?\p"
# 256 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 257 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 258 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds:
# 259 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 260 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 261 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 262 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "…And You've seen ZAPDOS?\p"
# 263 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 264 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 265 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds:
# 266 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm visiting the HOENN region\n"
# 267 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to study the legendary bird POKéMON:\l"
# 268 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES.\p"
# 269 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you can capture them all and\n"
# 270 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me your POKéDEX, it would\l"
# 271 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "help my research immensely.$"
# 272 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 273 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NavelRock:
# 274 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}, my research, along\n"
# 275 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "with the POKéDEX data you've\l"
# 276 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "shown me . . .\p"
# 277 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yes, it strongly indicates that\n"
# 278 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "NAVEL ROCK is an important\l"
# 279 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "location for these POKéMON.$"
# 280 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 281 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket:
# 282 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this to the ferry port,\n"
# 283 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "and show it to the attendant$"
# 284 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 285 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket:
# 286 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF OAK: That ticket will allow\n"
# 287 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "you to travel to NAVEL ROCK.$"
# 288 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 289 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere:
# 290 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Meet me at NAVEL ROCK.\p"
# 291 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "We'll see if we can't make yet\n"
# 292 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "another groundbreaking discovery!$"
# 293 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 294 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn:
# 295 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Keep up the good work, {PLAYER}.\p"
# 296 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to HOENN because I\n"
# 297 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "heard that some rare bird\l"
# 298 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON were roosting here.\p"
# 299 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Come back  and show me if you\n"
# 300 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "find any POKéMON like that.$"
# 301 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_Thinking:
# 303 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock::
# 308 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock_Text_0, MSGBOX_DEFAULT
# 312 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex::
# 316 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	applymovement LOCALID_COVELILY_OAK, Common_Movement_WalkInPlaceUp
# 317 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 30
# 318 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playse SE_PC_ON
# 319 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitse
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 321 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 322 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 324 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_0x8004, 0
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 326 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 327 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 328 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num Hoenn seen
# 330 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num Hoenn caught
# 331 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_0, MSGBOX_DEFAULT
# 332 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_SYS_NATIONAL_DEX, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1:
# 342 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 343 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ARTICUNO
# 344 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4:
# 348 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ZAPDOS
# 349 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7:
# 353 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_MOLTRES
# 354 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10:
# 358 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 359 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 360 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 361 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 362 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15
# 364 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16
# 366 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17
# 368 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_18
# 370 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_19
# 372 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20
# 374 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21
# 376 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 7, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22
# 379 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13:
# 382 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2:
# 333 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 335 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 336 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 337 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 338 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 339 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_1, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5:
# 345 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_0, 1
# 346 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8:
# 350 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 351 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11:
# 355 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 356 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15:
# 363 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16:
# 365 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17:
# 367 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_18:
# 369 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_19:
# 371 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20:
# 373 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21:
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22:
# 377 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno::
# 386 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 387 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_2
# 397 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_1:
# 404 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 405 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_2:
# 388 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos::
# 409 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 410 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_2
# 420 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_1:
# 427 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 428 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_2:
# 411 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres::
# 432 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 433 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_2
# 443 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_1:
# 450 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 451 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_2:
# 434 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos::
# 455 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 456 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 457 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_1:
# 461 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 462 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_4:
# 466 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 467 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_9
# 471 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_10
# 475 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_11
# 479 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_12
# 484 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 485 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7:
# 487 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_2:
# 458 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 459 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_5:
# 463 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 2
# 464 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_9:
# 468 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 469 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 470 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_10:
# 472 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 473 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 474 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_11:
# 476 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 477 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARTICUNO
# 478 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_12:
# 480 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 481 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 482 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres::
# 491 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 492 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 493 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_1:
# 497 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 498 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_4:
# 502 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 503 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_9
# 507 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_10
# 511 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_11
# 515 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_12
# 520 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 521 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7:
# 523 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_2:
# 494 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 495 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_5:
# 499 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 500 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_9:
# 504 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 505 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 506 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_10:
# 508 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 509 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 510 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_11:
# 512 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 513 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARTICUNO
# 514 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_12:
# 516 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 517 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 518 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres::
# 527 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 528 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 529 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_1:
# 533 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 534 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_4:
# 538 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 539 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_9
# 543 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_10
# 547 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_11
# 551 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_12
# 556 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 557 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7:
# 559 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_2:
# 530 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 531 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_5:
# 535 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 536 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_9:
# 540 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 541 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 542 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_10:
# 544 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 545 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 546 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_11:
# 548 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 549 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 550 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_12:
# 552 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 553 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 554 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird::
# 563 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird_Text_0, MSGBOX_DEFAULT
# 569 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 570 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird::
# 574 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird_Text_0, MSGBOX_DEFAULT
# 582 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 583 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds::
# 587 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds_Text_0, MSGBOX_DEFAULT
# 594 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 595 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds::
# 599 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 600 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 601 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_1:
# 605 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 606 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_4:
# 610 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 611 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_8
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_7:
# 615 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 616 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_12
# 618 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_13
# 621 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_14
# 624 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_15
# 627 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_16
# 631 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_17
# 635 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_18
# 639 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 7, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_19
# 642 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 643 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10:
# 645 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_2:
# 602 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_0, 1
# 603 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_5:
# 607 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 608 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_8:
# 612 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 613 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_12:
# 617 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_13:
# 619 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 620 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_14:
# 622 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 623 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_15:
# 625 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 626 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_16:
# 628 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 629 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 630 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_17:
# 632 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 633 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 634 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_18:
# 636 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 637 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 638 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_19:
# 640 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds::
# 649 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds_Text_0, MSGBOX_DEFAULT
# 654 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 655 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird::
# 659 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird_Text_0, MSGBOX_DEFAULT
# 666 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 667 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds::
# 671 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds_Text_0, MSGBOX_DEFAULT
# 678 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 679 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds::
# 683 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_0, MSGBOX_DEFAULT
# 688 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 689 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 690 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 691 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_1, MSGBOX_DEFAULT
# 697 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SS_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_2
# 711 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_4, MSGBOX_DEFAULT
# 712 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_8
# 719 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1:
# 723 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_5, MSGBOX_DEFAULT
# 726 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 727 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_2:
# 698 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_2, MSGBOX_DEFAULT
# 699 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_5
# 706 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_5:
# 700 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 701 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 702 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 703 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_START_LUGIA_QUEST
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_8:
# 713 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 714 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 715 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 716 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_START_LUGIA_QUEST
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1


LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd::
# 731 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_0
# 732 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 733 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 40
# 734 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special ShowPokedexRatingMessage
# 735 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 736 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 737 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_1, MSGBOX_DEFAULT
# 741 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock_Text_0:
# 308 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'll meet you at NAVEL ROCK to discuss\n"
	.string "our next steps towards finding LUGIA.\p"
	.string "Bring ARTICUNO, ZAPDOS, and MOLTRES\n"
	.string "with you,\p"
	.string "and be ready to catch a mighty POKéMON.\p"
	.string "LUGIA's POKéDEX data would be sure to\n"
	.string "send a tsunami through the POKéMON\l"
	.string "PROFESSOR community!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_0:
# 331 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Ah, so you've seen {STR_VAR_1} of HOENN's\nnative POKéMON.\pYou've even caught {STR_VAR_2} of them!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_1:
# 339 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And on a nationwide basis…\pYou've seen {STR_VAR_1} POKéMON,\nand you've caught {STR_VAR_2} POKéMON…$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_0:
# 388 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've even caught the POKéMON\n"
	.string "ARTICUNO!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "ARTICUNO is one of these POKéMON!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about this rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "learn anything about the other two\l"
	.string "POKéMON!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_1:
# 397 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON ARTICUNO!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "ARTICUNO is one of these POKéMON!\p"
	.string "If you manage to catch that POKéMON,\n"
	.string "please show me your POKéDEX again!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_0:
# 411 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've even caught the POKéMON ZAPDOS!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "ZAPDOS is one of these POKéMON!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about this rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "learn anything about the other two\l"
	.string "POKéMON!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_1:
# 420 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON ZAPDOS!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "ZAPDOS is one of these POKéMON!\p"
	.string "If you manage to catch that POKéMON,\n"
	.string "please show me your POKéDEX again!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_0:
# 434 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've even caught the POKéMON\n"
	.string "MOLTRES!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "MOLTRES is one of these POKéMON!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about this rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "learn anything about the other two\l"
	.string "POKéMON!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_1:
# 443 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON MOLTRES!\p"
	.string "To be honest, that POKéMON is exactly\n"
	.string "why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "MOLTRES is one of these POKéMON!\p"
	.string "If you manage to catch that POKéMON,\n"
	.string "please show me your POKéDEX again!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird_Text_0:
# 563 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN!\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "{STR_VAR_1} and {STR_VAR_2} are\n"
	.string "two of these POKéMON!\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch either of them!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird_Text_0:
# 574 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2},\l"
	.string "and you've even caught {STR_VAR_1}!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "{STR_VAR_1} and {STR_VAR_2} are\n"
	.string "two of these POKéMON!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about this rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch the other two!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds_Text_0:
# 587 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've caught the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "{STR_VAR_1} and {STR_VAR_2} are\n"
	.string "two of these POKéMON!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about these rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch the third one!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds_Text_0:
# 649 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON ARTICUNO,\n"
	.string "ZAPDOS, and MOLTRES!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "These are the three LEGENDARY BIRD\n"
	.string "POKéMON representing ICE, ELECTRIC,\l"
	.string "and FIRE!\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch any of them!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird_Text_0:
# 659 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON ARTICUNO,\n"
	.string "ZAPDOS, and MOLTRES…\p"
	.string "and you've even caught {STR_VAR_1}!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "These are the three LEGENDARY BIRD\n"
	.string "POKéMON representing ICE, ELECTRIC,\l"
	.string "and FIRE!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about this rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch the other two!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds_Text_0:
# 671 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've seen the POKéMON ARTICUNO,\n"
	.string "ZAPDOS, and MOLTRES…\p"
	.string "and you've even caught {STR_VAR_1}\n"
	.string "and {STR_VAR_2}!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "These are the three LEGENDARY BIRD\n"
	.string "POKéMON representing ICE, ELECTRIC,\l"
	.string "and FIRE!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about these rare and\l"
	.string "powerful POKéMON.\p"
	.string "Come show me your POKéDEX again if you\n"
	.string "manage to catch the third one!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_0:
# 683 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, that's interesting…\p"
	.string "You've caught the POKéMON ARTICUNO,\n"
	.string "ZAPDOS, and MOLTRES!\p"
	.string "To be honest, those POKéMON are\n"
	.string "exactly why I'm visiting HOENN.\p"
	.string "These are the three LEGENDARY BIRD\n"
	.string "POKéMON representing ICE, ELECTRIC,\l"
	.string "and FIRE!\p"
	.string "Thanks to this POKéDEX data, we'll be\n"
	.string "able to learn a lot about these rare and\l"
	.string "powerful POKéMON.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_1:
# 691 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Actually…\l"
	.string "Maybe you can help…\p"
	.string "There's another LEGENDARY POKéMON\n"
	.string "related to these three.\p"
	.string "Yes, the POKéMON LUGIA is said to be\n"
	.string "connected to the LEGENDARY BIRD\l"
	.string "POKéMON!\p"
	.string "Apparently LUGIA has been known to\n"
	.string "roost in the nearby landmark NAVEL\l"
	.string "ROCK…\p"
	.string "But this POKéMON is a force of nature!\p"
	.string "My POKéMON and I are long in the tooth;\n"
	.string "our battling days are over,\p"
	.string "But catching those three LEGENDARY\n"
	.string "BIRD POKéMON was quite a feat…\p"
	.string "Yes,\n"
	.string "I'm sure you can help!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_2:
# 698 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this;\n"
	.string "use it to travel to NAVEL ROCK on the\l"
	.string "S.S. TIDAL.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3:
# 706 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Huh?\p"
	.string "You already have the MYSTIC TICKET.\p"
	.string "You should be all set to travel to NAVEL\n"
	.string "ROCK then.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_4:
# 711 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this;\p"
	.string "when the long-awaited S.S. TIDAL\n"
	.string "finally sets sail, use it to travel to\l"
	.string "NAVEL ROCK.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_5:
# 723 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'll meet you there to discuss our next\n"
	.string "steps.\p"
	.string "Bring ARTICUNO, ZAPDOS, and MOLTRES\n"
	.string "with you, and be ready to catch a mighty\l"
	.string "POKéMON.\p"
	.string "LUGIA's POKéDEX data would be sure to\n"
	.string "make waves in the POKéMON PROFESSOR\l"
	.string "community!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_0:
# 731 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Here's some advice:$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_1:
# 737 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Trust me, I know what I'm talking about.\n"
	.string "Take it from an old-timer like me!\p"
	.string "To be honest, I'm here in HOENN looking\n"
	.string "for some rare POKéMON.\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "Come show me your POKéDEX if you learn\n"
	.string "anything about these POKéMON!$"
