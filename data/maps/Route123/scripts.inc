# 1 "data//maps/Route123/scripts.pory"

# 2 "data//maps/Route123/scripts.pory"
Route123_MapScripts::
# 3 "data//maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 4 "data//maps/Route123/scripts.pory"
	.byte 0
# 5 "data//maps/Route123/scripts.pory"

# 6 "data//maps/Route123/scripts.pory"
Route123_OnTransition:
# 7 "data//maps/Route123/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 8 "data//maps/Route123/scripts.pory"
	special SetRoute123Weather
# 9 "data//maps/Route123/scripts.pory"
	end
# 10 "data//maps/Route123/scripts.pory"

# 11 "data//maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl::
# 12 "data//maps/Route123/scripts.pory"
	lock
# 13 "data//maps/Route123/scripts.pory"
	faceplayer
# 14 "data//maps/Route123/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
# 15 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
# 16 "data//maps/Route123/scripts.pory"
	special IsGrassTypeInParty
# 17 "data//maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
# 18 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
# 19 "data//maps/Route123/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN, 2
# 20 "data//maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 21 "data//maps/Route123/scripts.pory"
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
# 22 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 23 "data//maps/Route123/scripts.pory"
	release
# 24 "data//maps/Route123/scripts.pory"
	end
# 25 "data//maps/Route123/scripts.pory"

# 26 "data//maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons::
# 27 "data//maps/Route123/scripts.pory"
	release
# 28 "data//maps/Route123/scripts.pory"
	end
# 29 "data//maps/Route123/scripts.pory"

# 30 "data//maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain::
# 31 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 32 "data//maps/Route123/scripts.pory"
	release
# 33 "data//maps/Route123/scripts.pory"
	end
# 34 "data//maps/Route123/scripts.pory"

# 35 "data//maps/Route123/scripts.pory"
Route123_EventScript_RouteSign::
# 36 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 37 "data//maps/Route123/scripts.pory"
	end
# 38 "data//maps/Route123/scripts.pory"

# 39 "data//maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre::
# 40 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 41 "data//maps/Route123/scripts.pory"
	end
# 42 "data//maps/Route123/scripts.pory"

# 43 "data//maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign::
# 44 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 45 "data//maps/Route123/scripts.pory"
	end
# 46 "data//maps/Route123/scripts.pory"

# 47 "data//maps/Route123/scripts.pory"
Route123_EventScript_Wendy::
# 48 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
# 49 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 50 "data//maps/Route123/scripts.pory"
	end
# 51 "data//maps/Route123/scripts.pory"

# 52 "data//maps/Route123/scripts.pory"
Route123_EventScript_Braxton::
# 53 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
# 54 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 55 "data//maps/Route123/scripts.pory"
	end
# 56 "data//maps/Route123/scripts.pory"

# 57 "data//maps/Route123/scripts.pory"
Route123_EventScript_Violet::
# 58 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
# 59 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 60 "data//maps/Route123/scripts.pory"
	end
# 61 "data//maps/Route123/scripts.pory"

# 62 "data//maps/Route123/scripts.pory"
Route123_EventScript_Cameron::
# 63 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
# 64 "data//maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 65 "data//maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
# 66 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 67 "data//maps/Route123/scripts.pory"
	release
# 68 "data//maps/Route123/scripts.pory"
	end
# 69 "data//maps/Route123/scripts.pory"

# 70 "data//maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron::
# 71 "data//maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 72 "data//maps/Route123/scripts.pory"
	waitmovement 0
# 73 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 74 "data//maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 75 "data//maps/Route123/scripts.pory"
	release
# 76 "data//maps/Route123/scripts.pory"
	end
# 77 "data//maps/Route123/scripts.pory"

# 78 "data//maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron::
# 79 "data//maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 80 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 81 "data//maps/Route123/scripts.pory"
	end
# 82 "data//maps/Route123/scripts.pory"

# 83 "data//maps/Route123/scripts.pory"
Route123_EventScript_Jacki::
# 84 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
# 85 "data//maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 86 "data//maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
# 87 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 88 "data//maps/Route123/scripts.pory"
	release
# 89 "data//maps/Route123/scripts.pory"
	end
# 90 "data//maps/Route123/scripts.pory"

# 91 "data//maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki::
# 92 "data//maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 93 "data//maps/Route123/scripts.pory"
	waitmovement 0
# 94 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 95 "data//maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 96 "data//maps/Route123/scripts.pory"
	release
# 97 "data//maps/Route123/scripts.pory"
	end
# 98 "data//maps/Route123/scripts.pory"

# 99 "data//maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki::
# 100 "data//maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 101 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 102 "data//maps/Route123/scripts.pory"
	end
# 103 "data//maps/Route123/scripts.pory"

# 104 "data//maps/Route123/scripts.pory"
Route123_EventScript_Miu::
# 105 "data//maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
# 106 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 107 "data//maps/Route123/scripts.pory"
	end
# 108 "data//maps/Route123/scripts.pory"

# 109 "data//maps/Route123/scripts.pory"
Route123_EventScript_Yuki::
# 110 "data//maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
# 111 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 112 "data//maps/Route123/scripts.pory"
	end
# 113 "data//maps/Route123/scripts.pory"

# 114 "data//maps/Route123/scripts.pory"
Route123_EventScript_Kindra::
# 115 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
# 116 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 117 "data//maps/Route123/scripts.pory"
	end
# 118 "data//maps/Route123/scripts.pory"

# 119 "data//maps/Route123/scripts.pory"
Route123_EventScript_Frederick::
# 120 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
# 121 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 122 "data//maps/Route123/scripts.pory"
	end
# 123 "data//maps/Route123/scripts.pory"

# 124 "data//maps/Route123/scripts.pory"
Route123_EventScript_Alberto::
# 125 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
# 126 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 127 "data//maps/Route123/scripts.pory"
	end
# 128 "data//maps/Route123/scripts.pory"

# 129 "data//maps/Route123/scripts.pory"
Route123_EventScript_Ed::
# 130 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
# 131 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 132 "data//maps/Route123/scripts.pory"
	end
# 133 "data//maps/Route123/scripts.pory"

# 134 "data//maps/Route123/scripts.pory"
Route123_EventScript_Kayley::
# 135 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
# 136 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 137 "data//maps/Route123/scripts.pory"
	end
# 138 "data//maps/Route123/scripts.pory"

# 139 "data//maps/Route123/scripts.pory"
Route123_EventScript_Jonas::
# 140 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
# 141 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 142 "data//maps/Route123/scripts.pory"
	end
# 143 "data//maps/Route123/scripts.pory"

# 144 "data//maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn::
# 145 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
# 146 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 147 "data//maps/Route123/scripts.pory"
	end
# 148 "data//maps/Route123/scripts.pory"

# 149 "data//maps/Route123/scripts.pory"
Route123_EventScript_Davis::
# 150 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
# 151 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 152 "data//maps/Route123/scripts.pory"
	end
# 153 "data//maps/Route123/scripts.pory"

# 154 "data//maps/Route123/scripts.pory"
Route123_EventScript_Fernando::
# 155 "data//maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
# 156 "data//maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 157 "data//maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
# 158 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 159 "data//maps/Route123/scripts.pory"
	release
# 160 "data//maps/Route123/scripts.pory"
	end
# 161 "data//maps/Route123/scripts.pory"

# 162 "data//maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando::
# 163 "data//maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 164 "data//maps/Route123/scripts.pory"
	waitmovement 0
# 165 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 166 "data//maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 167 "data//maps/Route123/scripts.pory"
	release
# 168 "data//maps/Route123/scripts.pory"
	end
# 169 "data//maps/Route123/scripts.pory"

# 170 "data//maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando::
# 171 "data//maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 172 "data//maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 173 "data//maps/Route123/scripts.pory"
	end
# 174 "data//maps/Route123/scripts.pory"

# 175 "data//maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny:
# 176 "data//maps/Route123/scripts.pory"
	.string "I love GRASS-type POKéMON!\p"
# 177 "data//maps/Route123/scripts.pory"
	.string "Do you have any GRASS-type POKéMON?$"
# 178 "data//maps/Route123/scripts.pory"

# 179 "data//maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis:
# 180 "data//maps/Route123/scripts.pory"
	.string "Oh?\p"
# 181 "data//maps/Route123/scripts.pory"
	.string "You like GRASS-type POKéMON, too,\n"
# 182 "data//maps/Route123/scripts.pory"
	.string "don't you?\p"
# 183 "data//maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 184 "data//maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 185 "data//maps/Route123/scripts.pory"

# 186 "data//maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon:
# 187 "data//maps/Route123/scripts.pory"
	.string "I check trees with my GRASS-type\n"
# 188 "data//maps/Route123/scripts.pory"
	.string "POKéMON. I'm like a tree doctor.$"
# 189 "data//maps/Route123/scripts.pory"

# 190 "data//maps/Route123/scripts.pory"
Route123_Text_RouteSign:
# 191 "data//maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 123\n"
# 192 "data//maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 118$"
# 193 "data//maps/Route123/scripts.pory"

# 194 "data//maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre:
# 195 "data//maps/Route123/scripts.pory"
	.string "{UP_ARROW} MT. PYRE\n"
# 196 "data//maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 197 "data//maps/Route123/scripts.pory"

# 198 "data//maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse:
# 199 "data//maps/Route123/scripts.pory"
	.string "BERRY MASTER'S HOUSE$"
