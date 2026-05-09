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
	waitstate
# 43 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 44 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 45 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 46 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 47 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 48 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 49 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 50 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 51 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 52 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 53 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 54 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ProfOak::
# 55 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 56 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 57 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_START_LUGIA_QUEST, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock
# 58 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak
# 59 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_MET_PROF_OAK, LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak
# 60 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 61 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex
# 62 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 63 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 64 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MeetProfOak::
# 65 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_PROF_OAK
# 66 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak, MSGBOX_DEFAULT
# 67 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_APokedex, MSGBOX_DEFAULT
# 68 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 69 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 70 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetProfOak::
# 71 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak, MSGBOX_DEFAULT
# 72 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 73 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 74 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 75 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 76 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 77 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 78 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 79 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 80 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 81 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 82 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 83 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 84 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 85 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 86 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 87 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 88 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 89 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 90 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 91 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 92 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 93 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 94 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 95 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 96 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 97 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 98 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 99 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 100 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 101 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 102 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 103 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 104 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 105 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 106 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 107 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 108 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 109 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 110 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
# 111 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 112 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 113 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This POKéDEX is completely filled!\n"
# 114 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love POKéMON!\p"
# 115 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 116 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 117 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 118 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 119 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 120 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 121 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 122 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 123 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 124 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 125 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 126 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 127 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 128 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 129 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 130 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 131 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 132 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 133 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 134 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 135 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 136 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 137 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 138 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 139 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 140 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 141 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 142 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 143 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 144 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 145 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 146 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 147 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 148 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 149 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 150 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 151 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 152 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 153 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 154 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 155 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 156 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 157 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 158 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 159 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 160 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 161 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 162 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 163 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 164 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 165 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 166 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 167 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"
# 168 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 169 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetProfOak:
# 170 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF. OAK: Ah, hello. I am the\n"
# 171 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON Professor, PROF. OAK.\p"
# 172 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you are?\p"
# 173 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 174 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}! Excellent!$"
# 175 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 176 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_APokedex:
# 177 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 178 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "What have you got there?\n"
# 179 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A POKéDEX?\p"
# 180 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm very familiar with POKéDEX\n"
# 181 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "technology.\p"
# 182 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look at yours?$"
# 183 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 184 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MetProfOak:
# 185 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF: OAK: Ah, {PLAYER}.\n"
# 186 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Still working on that POKéDEX?\p"
# 187 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Mind if I take a look?$"
# 188 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 189 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticuno:
# 190 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 191 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 192 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?$"
# 193 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 194 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtArticuno:
# 195 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 196 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 197 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ARTICUNO?$"
# 198 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 199 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtArticuno:
# 200 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 201 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO?\p"
# 202 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 203 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 204 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 205 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdos:
# 206 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 207 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 208 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?$"
# 209 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 210 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtZapdos:
# 211 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 212 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 213 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured ZAPDOS?$"
# 214 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 215 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtZapdos:
# 216 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 217 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ZAPDOS?\p"
# 218 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 219 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 220 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 221 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenMoltres:
# 222 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 223 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 224 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen MOLTRES?$"
# 225 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 226 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_CaughtMoltres:
# 227 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 228 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And you've actually\n"
# 229 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES?$"
# 230 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 231 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_AlsoCaughtMoltres:
# 232 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also captured\n"
# 233 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "MOLTRES?\p"
# 234 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 235 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Incredible!$"
# 236 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 237 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_EvenCaughtMoltres:
# 238 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've even\n"
# 239 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "captured MOLTRES!?$"
# 240 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 241 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoZapdos:
# 242 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 243 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 244 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 245 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen ZAPDOS!?$"
# 246 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 247 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenArticunoMoltres:
# 248 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 249 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 250 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 251 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 252 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 253 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenZapdosMoltres:
# 254 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 255 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 256 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ZAPDOS?\p"
# 257 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 258 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 259 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeenAllBirds:
# 260 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … …\p"
# 261 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Remarkable!\n"
# 262 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've seen ARTICUNO?\p"
# 263 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "…And You've seen ZAPDOS?\p"
# 264 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You've also seen MOLTRES!?$"
# 265 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 266 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_StudyingBirds:
# 267 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm visiting the HOENN region\n"
# 268 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to study the legendary bird POKéMON:\l"
# 269 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "ARTICUNO, ZAPDOS, and MOLTRES.\p"
# 270 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you can capture them all and\n"
# 271 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me your POKéDEX, it would\l"
# 272 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "help my research immensely.$"
# 273 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 274 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NavelRock:
# 275 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}, my research, along\n"
# 276 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "with the POKéDEX data you've\l"
# 277 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "shown me . . .\p"
# 278 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yes, it strongly indicates that\n"
# 279 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "NAVEL ROCK is an important\l"
# 280 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "location for these POKéMON.$"
# 281 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 282 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_TakeThisTicket:
# 283 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this to the ferry port,\n"
# 284 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "and show it to the attendant$"
# 285 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 286 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GiveMysticTicket:
# 287 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "PROF OAK: That ticket will allow\n"
# 288 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "you to travel to NAVEL ROCK.$"
# 289 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 290 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_MeetMeThere:
# 291 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Meet me at NAVEL ROCK.\p"
# 292 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "We'll see if we can't make yet\n"
# 293 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "another groundbreaking discovery!$"
# 294 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 295 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_VisitingHoenn:
# 296 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Keep up the good work, {PLAYER}.\p"
# 297 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to HOENN because I\n"
# 298 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "heard that some rare bird\l"
# 299 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON were roosting here.\p"
# 300 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Come back  and show me if you\n"
# 301 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "find any POKéMON like that.$"
# 302 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 303 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_Thinking:
# 304 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock::
# 309 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock_Text_0, MSGBOX_DEFAULT
# 313 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex::
# 317 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	applymovement LOCALID_COVELILY_OAK, Common_Movement_WalkInPlaceUp
# 318 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 30
# 319 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playse SE_PC_ON
# 320 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitse
# 321 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 322 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 323 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 325 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_0x8004, 0
# 326 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 327 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 328 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 329 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 330 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num Hoenn seen
# 331 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num Hoenn caught
# 332 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_0, MSGBOX_DEFAULT
# 333 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_SYS_NATIONAL_DEX, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1:
# 343 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 344 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ARTICUNO
# 345 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4:
# 349 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_ZAPDOS
# 350 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7:
# 354 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getseenmon SPECIES_MOLTRES
# 355 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10:
# 359 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 360 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 361 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 362 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 363 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15
# 365 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16
# 367 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17
# 369 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_18
# 371 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_19
# 373 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20
# 375 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21
# 377 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 7, LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22
# 380 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 381 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13:
# 383 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_2:
# 334 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 335 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 336 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 337 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 338 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 339 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 340 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_1, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_1

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_5:
# 346 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_0, 1
# 347 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_4

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_8:
# 351 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 352 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_7

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_11:
# 356 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 357 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_10

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_15:
# 364 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_16:
# 366 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_17:
# 368 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_18:
# 370 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_19:
# 372 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_20:
# 374 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_21:
# 376 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_22:
# 378 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_13


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno::
# 387 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 388 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_2
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_1:
# 405 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 406 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_2:
# 389 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos::
# 410 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 411 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_2
# 421 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_1:
# 428 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 429 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_2:
# 412 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdos_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres::
# 433 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 434 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_2
# 444 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_1, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_1:
# 451 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 452 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_2:
# 435 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_Text_0, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenMoltres_1


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos::
# 456 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 457 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 458 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_1:
# 462 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 463 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_4:
# 467 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 468 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_9
# 472 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_10
# 476 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_11
# 480 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_12
# 485 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 486 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7:
# 488 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_2:
# 459 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 460 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_5:
# 464 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 2
# 465 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_9:
# 469 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 470 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 471 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_10:
# 473 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 474 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 475 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_11:
# 477 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 478 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARTICUNO
# 479 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_12:
# 481 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 482 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 483 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndZapdos_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres::
# 492 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 493 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 494 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_1:
# 498 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 499 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_4:
# 503 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 504 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_9
# 508 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_10
# 512 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_11
# 516 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_12
# 521 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 522 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7:
# 524 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_2:
# 495 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 496 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_5:
# 500 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 501 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_9:
# 505 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 506 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 507 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_10:
# 509 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 510 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 511 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_11:
# 513 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 514 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ARTICUNO
# 515 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_12:
# 517 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 518 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 519 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticunoAndMoltres_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres::
# 528 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 529 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 530 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_1:
# 534 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 535 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_4:
# 539 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 540 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_9
# 544 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_10
# 548 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_11
# 552 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_12
# 557 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 558 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7:
# 560 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_2:
# 531 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 532 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_5:
# 536 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 537 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_9:
# 541 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 542 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 543 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_10:
# 545 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 546 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 547 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_11:
# 549 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 550 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 551 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_12:
# 553 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 554 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 555 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenZapdosAndMoltres_7


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird::
# 564 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtNoneBird_Text_0, MSGBOX_DEFAULT
# 570 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 571 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird::
# 575 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtOneBird_Text_0, MSGBOX_DEFAULT
# 583 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 584 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds::
# 588 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_SawTwoCaughtTwoBirds_Text_0, MSGBOX_DEFAULT
# 595 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 596 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds::
# 600 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 601 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ARTICUNO
# 602 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_2
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_1:
# 606 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_ZAPDOS
# 607 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_5
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_4:
# 611 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	getcaughtmon SPECIES_MOLTRES
# 612 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_8
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_7:
# 616 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	switch VAR_TEMP_4
# 617 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 0, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_12
# 619 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 1, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_13
# 622 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 2, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_14
# 625 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 4, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_15
# 628 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 3, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_16
# 632 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 5, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_17
# 636 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 6, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_18
# 640 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	case 7, LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_19
# 643 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special DoSoftReset
# 644 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd
LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10:
# 646 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_2:
# 603 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_0, 1
# 604 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 1
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_5:
# 608 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
# 609 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 2
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_4

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_8:
# 613 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setvar VAR_TEMP_2, 4
# 614 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_TEMP_4, 4
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_7

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_12:
# 618 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_13:
# 620 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 621 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_14:
# 623 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 624 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_15:
# 626 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES
# 627 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_16:
# 629 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 630 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ZAPDOS
# 631 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_17:
# 633 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO
# 634 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 635 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_18:
# 637 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS
# 638 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_MOLTRES
# 639 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_19:
# 641 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_SeenAllBirds_10


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds::
# 650 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtNoBirds_Text_0, MSGBOX_DEFAULT
# 655 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 656 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird::
# 660 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtOneBird_Text_0, MSGBOX_DEFAULT
# 667 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 668 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds::
# 672 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtTwoBirds_Text_0, MSGBOX_DEFAULT
# 679 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 680 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds::
# 684 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_0, MSGBOX_DEFAULT
# 689 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_Thinking
# 690 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 691 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 692 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_1, MSGBOX_DEFAULT
# 698 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SS_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_2
# 712 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_4, MSGBOX_DEFAULT
# 713 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_8
# 720 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3, MSGBOX_DEFAULT
LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1:
# 724 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_5, MSGBOX_DEFAULT
# 727 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	closemessage
# 728 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_2:
# 699 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_2, MSGBOX_DEFAULT
# 700 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_5
# 707 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3, MSGBOX_DEFAULT
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_5:
# 701 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 702 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 703 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 704 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_START_LUGIA_QUEST
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_8:
# 714 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 715 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 716 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 717 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_START_LUGIA_QUEST
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_1


LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd::
# 732 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_0
# 733 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 734 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 40
# 735 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special ShowPokedexRatingMessage
# 736 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 737 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	delay 45
# 738 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_1, MSGBOX_DEFAULT
# 742 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	return


LilycoveCity_CoveLilyMotel_2F_EventScript_MeetAtNavelRock_Text_0:
# 309 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'll meet you at NAVEL ROCK to discuss\n"
	.string "our next steps towards finding LUGIA.\p"
	.string "Bring ARTICUNO, ZAPDOS, and MOLTRES\n"
	.string "with you,\p"
	.string "and be ready to catch a mighty POKéMON.\p"
	.string "LUGIA's POKéDEX data would be sure to\n"
	.string "send a tsunami through the POKéMON\l"
	.string "PROFESSOR community!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_0:
# 332 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Ah, so you've seen {STR_VAR_1} of HOENN's\nnative POKéMON.\pYou've even caught {STR_VAR_2} of them!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedex_Text_1:
# 340 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And on a nationwide basis…\pYou've seen {STR_VAR_1} POKéMON,\nand you've caught {STR_VAR_2} POKéMON…$"

LilycoveCity_CoveLilyMotel_2F_EventScript_SeenArticuno_Text_0:
# 389 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 398 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 412 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 421 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 435 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 444 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 564 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 575 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 588 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 650 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 660 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 672 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 684 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 692 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
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
# 699 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this;\n"
	.string "use it to travel to NAVEL ROCK on the\l"
	.string "S.S. TIDAL.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_3:
# 707 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Huh?\p"
	.string "You already have the MYSTIC TICKET.\p"
	.string "You should be all set to travel to NAVEL\n"
	.string "ROCK then.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_4:
# 712 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Take this;\p"
	.string "when the long-awaited S.S. TIDAL\n"
	.string "finally sets sail, use it to travel to\l"
	.string "NAVEL ROCK.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_CaughtAllBirds_Text_5:
# 724 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'll meet you there to discuss our next\n"
	.string "steps.\p"
	.string "Bring ARTICUNO, ZAPDOS, and MOLTRES\n"
	.string "with you, and be ready to catch a mighty\l"
	.string "POKéMON.\p"
	.string "LUGIA's POKéDEX data would be sure to\n"
	.string "make waves in the POKéMON PROFESSOR\l"
	.string "community!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_0:
# 732 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Here's some advice:$"

LilycoveCity_CoveLilyMotel_2F_EventScript_OakCheckPokedexEnd_Text_1:
# 738 "data//maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Trust me, I know what I'm talking about.\n"
	.string "Take it from an old-timer like me!\p"
	.string "To be honest, I'm here in HOENN looking\n"
	.string "for some rare POKéMON.\p"
	.string "Three BIRD POKéMON representing ICE,\n"
	.string "ELECTRIC, and FIRE have been spotted\l"
	.string "and are believed to be roosting here.\p"
	.string "Come show me your POKéDEX if you learn\n"
	.string "anything about these POKéMON!$"
