# 1 "data//maps/Route121/scripts.pory"

# 2 "data//maps/Route121/scripts.pory"
.set LOCALID_GRUNT_1, 12
# 3 "data//maps/Route121/scripts.pory"
.set LOCALID_GRUNT_2, 13
# 4 "data//maps/Route121/scripts.pory"
.set LOCALID_GRUNT_3, 14
# 5 "data//maps/Route121/scripts.pory"

# 6 "data//maps/Route121/scripts.pory"
Route121_MapScripts::
# 7 "data//maps/Route121/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route121_OnTransition
# 8 "data//maps/Route121/scripts.pory"
	.byte 0
# 9 "data//maps/Route121/scripts.pory"

# 10 "data//maps/Route121/scripts.pory"
Route121_OnTransition:
# 11 "data//maps/Route121/scripts.pory"
	end
# 12 "data//maps/Route121/scripts.pory"

# 13 "data//maps/Route121/scripts.pory"
Route121_EventScript_Woman::
# 14 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
# 15 "data//maps/Route121/scripts.pory"
	end
# 16 "data//maps/Route121/scripts.pory"

# 17 "data//maps/Route121/scripts.pory"
Route121_EventScript_MtPyrePierSign::
# 18 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
# 19 "data//maps/Route121/scripts.pory"
	end
# 20 "data//maps/Route121/scripts.pory"

# 21 "data//maps/Route121/scripts.pory"
Route121_EventScript_SafariZoneSign::
# 22 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
# 23 "data//maps/Route121/scripts.pory"
	end
# 24 "data//maps/Route121/scripts.pory"

# 25 "data//maps/Route121/scripts.pory"
Route121_EventScript_AquaGruntsMoveOut::
# 26 "data//maps/Route121/scripts.pory"
	lockall
# 27 "data//maps/Route121/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 28 "data//maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
# 29 "data//maps/Route121/scripts.pory"
	waitmovement 0
# 30 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
# 31 "data//maps/Route121/scripts.pory"
	closemessage
# 32 "data//maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
# 33 "data//maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
# 34 "data//maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
# 35 "data//maps/Route121/scripts.pory"
	waitmovement 0
# 36 "data//maps/Route121/scripts.pory"
	fadedefaultbgm
# 37 "data//maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 38 "data//maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 39 "data//maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 40 "data//maps/Route121/scripts.pory"
	setvar VAR_ROUTE121_STATE, 1
# 41 "data//maps/Route121/scripts.pory"
	releaseall
# 42 "data//maps/Route121/scripts.pory"
	end
# 43 "data//maps/Route121/scripts.pory"

# 44 "data//maps/Route121/scripts.pory"
Route121_Movement_Grunt1Exit:
# 45 "data//maps/Route121/scripts.pory"
	walk_down
# 46 "data//maps/Route121/scripts.pory"
	walk_down
# 47 "data//maps/Route121/scripts.pory"
	walk_down
# 48 "data//maps/Route121/scripts.pory"
	walk_down
# 49 "data//maps/Route121/scripts.pory"
	walk_down
# 50 "data//maps/Route121/scripts.pory"
	walk_down
# 51 "data//maps/Route121/scripts.pory"
	walk_down
# 52 "data//maps/Route121/scripts.pory"
	walk_down
# 53 "data//maps/Route121/scripts.pory"
	step_end
# 54 "data//maps/Route121/scripts.pory"

# 55 "data//maps/Route121/scripts.pory"
Route121_Movement_Grunt2Exit:
# 56 "data//maps/Route121/scripts.pory"
	walk_down
# 57 "data//maps/Route121/scripts.pory"
	walk_down
# 58 "data//maps/Route121/scripts.pory"
	walk_down
# 59 "data//maps/Route121/scripts.pory"
	walk_down
# 60 "data//maps/Route121/scripts.pory"
	walk_down
# 61 "data//maps/Route121/scripts.pory"
	walk_down
# 62 "data//maps/Route121/scripts.pory"
	walk_down
# 63 "data//maps/Route121/scripts.pory"
	walk_down
# 64 "data//maps/Route121/scripts.pory"
	step_end
# 65 "data//maps/Route121/scripts.pory"

# 66 "data//maps/Route121/scripts.pory"
Route121_Movement_Grunt3Exit:
# 67 "data//maps/Route121/scripts.pory"
	walk_down
# 68 "data//maps/Route121/scripts.pory"
	walk_down
# 69 "data//maps/Route121/scripts.pory"
	walk_down
# 70 "data//maps/Route121/scripts.pory"
	walk_down
# 71 "data//maps/Route121/scripts.pory"
	walk_down
# 72 "data//maps/Route121/scripts.pory"
	walk_down
# 73 "data//maps/Route121/scripts.pory"
	walk_down
# 74 "data//maps/Route121/scripts.pory"
	walk_down
# 75 "data//maps/Route121/scripts.pory"
	step_end
# 76 "data//maps/Route121/scripts.pory"

# 77 "data//maps/Route121/scripts.pory"
Route121_EventScript_Vanessa::
# 78 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
# 79 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 80 "data//maps/Route121/scripts.pory"
	end
# 81 "data//maps/Route121/scripts.pory"

# 82 "data//maps/Route121/scripts.pory"
Route121_EventScript_Walter::
# 83 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
# 84 "data//maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 85 "data//maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchWalter
# 86 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
# 87 "data//maps/Route121/scripts.pory"
	release
# 88 "data//maps/Route121/scripts.pory"
	end
# 89 "data//maps/Route121/scripts.pory"

# 90 "data//maps/Route121/scripts.pory"
Route121_EventScript_RegisterWalter::
# 91 "data//maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 92 "data//maps/Route121/scripts.pory"
	waitmovement 0
# 93 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
# 94 "data//maps/Route121/scripts.pory"
	register_matchcall TRAINER_WALTER_1
# 95 "data//maps/Route121/scripts.pory"
	release
# 96 "data//maps/Route121/scripts.pory"
	end
# 97 "data//maps/Route121/scripts.pory"

# 98 "data//maps/Route121/scripts.pory"
Route121_EventScript_RematchWalter::
# 99 "data//maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
# 100 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
# 101 "data//maps/Route121/scripts.pory"
	end
# 102 "data//maps/Route121/scripts.pory"

# 103 "data//maps/Route121/scripts.pory"
Route121_EventScript_Tammy::
# 104 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
# 105 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 106 "data//maps/Route121/scripts.pory"
	end
# 107 "data//maps/Route121/scripts.pory"

# 108 "data//maps/Route121/scripts.pory"
Route121_EventScript_Kate::
# 109 "data//maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
# 110 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 111 "data//maps/Route121/scripts.pory"
	end
# 112 "data//maps/Route121/scripts.pory"

# 113 "data//maps/Route121/scripts.pory"
Route121_EventScript_Joy::
# 114 "data//maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
# 115 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
# 116 "data//maps/Route121/scripts.pory"
	end
# 117 "data//maps/Route121/scripts.pory"

# 118 "data//maps/Route121/scripts.pory"
Route121_EventScript_Jessica::
# 119 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
# 120 "data//maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 121 "data//maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
# 122 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
# 123 "data//maps/Route121/scripts.pory"
	release
# 124 "data//maps/Route121/scripts.pory"
	end
# 125 "data//maps/Route121/scripts.pory"

# 126 "data//maps/Route121/scripts.pory"
Route121_EventScript_RegisterJessica::
# 127 "data//maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 128 "data//maps/Route121/scripts.pory"
	waitmovement 0
# 129 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
# 130 "data//maps/Route121/scripts.pory"
	register_matchcall TRAINER_JESSICA_1
# 131 "data//maps/Route121/scripts.pory"
	release
# 132 "data//maps/Route121/scripts.pory"
	end
# 133 "data//maps/Route121/scripts.pory"

# 134 "data//maps/Route121/scripts.pory"
Route121_EventScript_RematchJessica::
# 135 "data//maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
# 136 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
# 137 "data//maps/Route121/scripts.pory"
	end
# 138 "data//maps/Route121/scripts.pory"

# 139 "data//maps/Route121/scripts.pory"
Route121_EventScript_Cale::
# 140 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
# 141 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 142 "data//maps/Route121/scripts.pory"
	end
# 143 "data//maps/Route121/scripts.pory"

# 144 "data//maps/Route121/scripts.pory"
Route121_EventScript_Myles::
# 145 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
# 146 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 147 "data//maps/Route121/scripts.pory"
	end
# 148 "data//maps/Route121/scripts.pory"

# 149 "data//maps/Route121/scripts.pory"
Route121_EventScript_Pat::
# 150 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
# 151 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 152 "data//maps/Route121/scripts.pory"
	end
# 153 "data//maps/Route121/scripts.pory"

# 154 "data//maps/Route121/scripts.pory"
Route121_EventScript_Marcel::
# 155 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
# 156 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 157 "data//maps/Route121/scripts.pory"
	end
# 158 "data//maps/Route121/scripts.pory"

# 159 "data//maps/Route121/scripts.pory"
Route121_EventScript_Cristin::
# 160 "data//maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
# 161 "data//maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 162 "data//maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchCristin
# 163 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
# 164 "data//maps/Route121/scripts.pory"
	release
# 165 "data//maps/Route121/scripts.pory"
	end
# 166 "data//maps/Route121/scripts.pory"

# 167 "data//maps/Route121/scripts.pory"
Route121_EventScript_RegisterCristin::
# 168 "data//maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 169 "data//maps/Route121/scripts.pory"
	waitmovement 0
# 170 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
# 171 "data//maps/Route121/scripts.pory"
	register_matchcall TRAINER_CRISTIN_1
# 172 "data//maps/Route121/scripts.pory"
	release
# 173 "data//maps/Route121/scripts.pory"
	end
# 174 "data//maps/Route121/scripts.pory"

# 175 "data//maps/Route121/scripts.pory"
Route121_EventScript_RematchCristin::
# 176 "data//maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
# 177 "data//maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
# 178 "data//maps/Route121/scripts.pory"
	end
# 179 "data//maps/Route121/scripts.pory"

# 180 "data//maps/Route121/scripts.pory"
Route121_Text_OkayMoveOutToMtPyre:
# 181 "data//maps/Route121/scripts.pory"
	.string "Okay!\n"
# 182 "data//maps/Route121/scripts.pory"
	.string "We're to move out to MT. PYRE!$"
# 183 "data//maps/Route121/scripts.pory"

# 184 "data//maps/Route121/scripts.pory"
Route121_Text_AheadLoomsMtPyre:
# 185 "data//maps/Route121/scripts.pory"
	.string "Ahead looms MT. PYRE…\p"
# 186 "data//maps/Route121/scripts.pory"
	.string "It is a natural monument to the spirits \n"
# 187 "data//maps/Route121/scripts.pory"
	.string "of departed POKéMON…$"
# 188 "data//maps/Route121/scripts.pory"

# 189 "data//maps/Route121/scripts.pory"
Route121_Text_MtPyrePierSign:
# 190 "data//maps/Route121/scripts.pory"
	.string "MT. PYRE PIER\p"
# 191 "data//maps/Route121/scripts.pory"
	.string "…The sign is old and worn out.\n"
# 192 "data//maps/Route121/scripts.pory"
	.string "The words are barely legible…$"
# 193 "data//maps/Route121/scripts.pory"

# 194 "data//maps/Route121/scripts.pory"
Route121_Text_SafariZoneSign:
# 195 "data//maps/Route121/scripts.pory"
	.string "“Filled with rare POKéMON!”\n"
# 196 "data//maps/Route121/scripts.pory"
	.string "SAFARI ZONE$"
