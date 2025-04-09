# 1 "data//maps/DewfordTown_Gym/scripts.pory"

# 2 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_MapScripts::
# 3 "data//maps/DewfordTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
# 4 "data//maps/DewfordTown_Gym/scripts.pory"
	.byte 0
# 5 "data//maps/DewfordTown_Gym/scripts.pory"

# 6 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_OnTransition:
# 7 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 8 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 9 "data//maps/DewfordTown_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_DEWFORD_GYM, Common_EventScript_ResetGymTrainers
# 10 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 11 "data//maps/DewfordTown_Gym/scripts.pory"

# 12 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel::
# 13 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 14 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 15 "data//maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 16 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
# 17 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
# 18 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
# 19 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
# 20 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
# 21 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
# 22 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashLevel1
# 23 "data//maps/DewfordTown_Gym/scripts.pory"

# 24 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn::
# 25 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 0
# 26 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 27 "data//maps/DewfordTown_Gym/scripts.pory"

# 28 "data//maps/DewfordTown_Gym/scripts.pory"
@ Brightest
# 29 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel1::
# 30 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 1
# 31 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 32 "data//maps/DewfordTown_Gym/scripts.pory"

# 33 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel2::
# 34 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 2
# 35 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 36 "data//maps/DewfordTown_Gym/scripts.pory"

# 37 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel3::
# 38 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 3
# 39 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 40 "data//maps/DewfordTown_Gym/scripts.pory"

# 41 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel4::
# 42 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 4
# 43 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 44 "data//maps/DewfordTown_Gym/scripts.pory"

# 45 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel5::
# 46 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 5
# 47 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 48 "data//maps/DewfordTown_Gym/scripts.pory"

# 49 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel6::
# 50 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 6
# 51 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 52 "data//maps/DewfordTown_Gym/scripts.pory"

# 53 "data//maps/DewfordTown_Gym/scripts.pory"
@ Darkest
# 54 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel7::
# 55 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 7
# 56 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 57 "data//maps/DewfordTown_Gym/scripts.pory"

# 58 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom::
# 59 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 60 "data//maps/DewfordTown_Gym/scripts.pory"
	nop1
# 61 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
# 62 "data//maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 63 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 64 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 65 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 66 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 67 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 68 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 69 "data//maps/DewfordTown_Gym/scripts.pory"

# 70 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange::
# 71 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 72 "data//maps/DewfordTown_Gym/scripts.pory"

# 73 "data//maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 74 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
# 75 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 76 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 77 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 78 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 79 "data//maps/DewfordTown_Gym/scripts.pory"

# 80 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
# 81 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 82 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 83 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 84 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 85 "data//maps/DewfordTown_Gym/scripts.pory"

# 86 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
# 87 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 88 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 89 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 90 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 91 "data//maps/DewfordTown_Gym/scripts.pory"

# 92 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
# 93 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 94 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 95 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 96 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 97 "data//maps/DewfordTown_Gym/scripts.pory"

# 98 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
# 99 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 100 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 101 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 102 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 103 "data//maps/DewfordTown_Gym/scripts.pory"

# 104 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
# 105 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 106 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 107 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 108 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 109 "data//maps/DewfordTown_Gym/scripts.pory"

# 110 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
# 111 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 112 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 113 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 114 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 115 "data//maps/DewfordTown_Gym/scripts.pory"

# 116 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated::
# 117 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 118 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 119 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 120 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn::
# 121 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 122 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 123 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura::
# 124 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 125 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 126 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden::
# 127 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 128 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 129 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian::
# 130 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 131 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 132 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith::
# 133 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 134 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 135 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers::
# 136 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 137 "data//maps/DewfordTown_Gym/scripts.pory"

# 138 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly::
# 139 "data//maps/DewfordTown_Gym/scripts.pory"
	lock
# 140 "data//maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 141 "data//maps/DewfordTown_Gym/scripts.pory"
	call_if_unset FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder
# 142 "data//maps/DewfordTown_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 143 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
# 144 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
# 145 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 146 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 147 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 148 "data//maps/DewfordTown_Gym/scripts.pory"

# 149 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated::
# 150 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 151 "data//maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 152 "data//maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 153 "data//maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 154 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 155 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 156 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 157 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 158 "data//maps/DewfordTown_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 159 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 160 "data//maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 161 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 162 "data//maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 163 "data//maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 164 "data//maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 165 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 166 "data//maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 167 "data//maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 168 "data//maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 169 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 170 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 171 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 172 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 173 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 174 "data//maps/DewfordTown_Gym/scripts.pory"

# 175 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp::
# 176 "data//maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP, 5
# 177 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 178 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 179 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 180 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 181 "data//maps/DewfordTown_Gym/scripts.pory"

# 182 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp2:
# 183 "data//maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP, 5
# 184 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 185 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 186 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 187 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 188 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 189 "data//maps/DewfordTown_Gym/scripts.pory"

# 190 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 191 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
# 192 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 193 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 194 "data//maps/DewfordTown_Gym/scripts.pory"

# 195 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao::
# 196 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 197 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 198 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 199 "data//maps/DewfordTown_Gym/scripts.pory"

# 200 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom::
# 201 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 202 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 203 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 204 "data//maps/DewfordTown_Gym/scripts.pory"

# 205 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn::
# 206 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 207 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 208 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 209 "data//maps/DewfordTown_Gym/scripts.pory"

# 210 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom::
# 211 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 212 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 213 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 214 "data//maps/DewfordTown_Gym/scripts.pory"

# 215 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura::
# 216 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 217 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 218 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 219 "data//maps/DewfordTown_Gym/scripts.pory"

# 220 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom::
# 221 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 222 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 223 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 224 "data//maps/DewfordTown_Gym/scripts.pory"

# 225 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden::
# 226 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 227 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 228 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 229 "data//maps/DewfordTown_Gym/scripts.pory"

# 230 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom::
# 231 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 232 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 233 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 234 "data//maps/DewfordTown_Gym/scripts.pory"

# 235 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian::
# 236 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 237 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 238 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 239 "data//maps/DewfordTown_Gym/scripts.pory"

# 240 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom::
# 241 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 242 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 243 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 244 "data//maps/DewfordTown_Gym/scripts.pory"

# 245 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith::
# 246 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 247 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 248 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 249 "data//maps/DewfordTown_Gym/scripts.pory"

# 250 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom::
# 251 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 252 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 253 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 254 "data//maps/DewfordTown_Gym/scripts.pory"

# 255 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide::
# 256 "data//maps/DewfordTown_Gym/scripts.pory"
	lock
# 257 "data//maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 258 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 259 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 260 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 261 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 262 "data//maps/DewfordTown_Gym/scripts.pory"

# 263 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory::
# 264 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 265 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 266 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 267 "data//maps/DewfordTown_Gym/scripts.pory"

# 268 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue::
# 269 "data//maps/DewfordTown_Gym/scripts.pory"
	lockall
# 270 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 271 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 272 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 273 "data//maps/DewfordTown_Gym/scripts.pory"

# 274 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue::
# 275 "data//maps/DewfordTown_Gym/scripts.pory"
	lockall
# 276 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 277 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 278 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 279 "data//maps/DewfordTown_Gym/scripts.pory"

# 280 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified::
# 281 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 282 "data//maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 283 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 284 "data//maps/DewfordTown_Gym/scripts.pory"

# 285 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue::
# 286 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 287 "data//maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 288 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 289 "data//maps/DewfordTown_Gym/scripts.pory"

# 290 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuideAdvice:
# 291 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 292 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 293 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
# 294 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING-type POKéMON.\p"
# 295 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Going against him with NORMAL-type\n"
# 296 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "POKéMON is asking for trouble.\p"
# 297 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING POKéMON will lay a serious\n"
# 298 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "smack down on NORMAL POKéMON,\l"
# 299 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "so be careful!\p"
# 300 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "What's worse, the GYM is as dark as\n"
# 301 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "the ocean floor.\p"
# 302 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 303 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "the TRAINERS in your way.\p"
# 304 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 305 "data//maps/DewfordTown_Gym/scripts.pory"

# 306 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory:
# 307 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 308 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 309 "data//maps/DewfordTown_Gym/scripts.pory"

# 310 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro:
# 311 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 312 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 313 "data//maps/DewfordTown_Gym/scripts.pory"

# 314 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat:
# 315 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 316 "data//maps/DewfordTown_Gym/scripts.pory"

# 317 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle:
# 318 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 319 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 320 "data//maps/DewfordTown_Gym/scripts.pory"

# 321 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro:
# 322 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for BRAWLY to be\n"
# 323 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 324 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 325 "data//maps/DewfordTown_Gym/scripts.pory"

# 326 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat:
# 327 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 328 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 329 "data//maps/DewfordTown_Gym/scripts.pory"

# 330 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle:
# 331 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 332 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 333 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a GYM LEADER…\p"
# 334 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the POKéMON LEAGUE\n"
# 335 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "CHAMPION!$"
# 336 "data//maps/DewfordTown_Gym/scripts.pory"

# 337 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro:
# 338 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 339 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 340 "data//maps/DewfordTown_Gym/scripts.pory"

# 341 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat:
# 342 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 343 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 344 "data//maps/DewfordTown_Gym/scripts.pory"

# 345 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle:
# 346 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 347 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 348 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 349 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "see BRAWLY's face…$"
# 350 "data//maps/DewfordTown_Gym/scripts.pory"

# 351 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro:
# 352 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 353 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 354 "data//maps/DewfordTown_Gym/scripts.pory"

# 355 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat:
# 356 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 357 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 358 "data//maps/DewfordTown_Gym/scripts.pory"

# 359 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle:
# 360 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 361 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 362 "data//maps/DewfordTown_Gym/scripts.pory"

# 363 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro:
# 364 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 365 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 366 "data//maps/DewfordTown_Gym/scripts.pory"

# 367 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat:
# 368 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 369 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 370 "data//maps/DewfordTown_Gym/scripts.pory"

# 371 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle:
# 372 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 373 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "our GYM LEADER.$"
# 374 "data//maps/DewfordTown_Gym/scripts.pory"

# 375 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro:
# 376 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 377 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 378 "data//maps/DewfordTown_Gym/scripts.pory"

# 379 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat:
# 380 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 381 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 382 "data//maps/DewfordTown_Gym/scripts.pory"

# 383 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle:
# 384 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 385 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that BADGE!$"
# 386 "data//maps/DewfordTown_Gym/scripts.pory"

# 387 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro:
# 388 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm BRAWLY!\n"
# 389 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER!\p"
# 390 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 391 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 392 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 393 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 394 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 395 "data//maps/DewfordTown_Gym/scripts.pory"

# 396 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat:
# 397 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 398 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 399 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 400 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 401 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Take this GYM BADGE!$"
# 402 "data//maps/DewfordTown_Gym/scripts.pory"

# 403 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge:
# 404 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the KNUCKLE BADGE\n"
# 405 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "from BRAWLY.$"
# 406 "data//maps/DewfordTown_Gym/scripts.pory"

# 407 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
# 408 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Now you'll be able to use the HM move\n"
# 409 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FLASH outside of battle.\p"
# 410 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, use this TECHNICAL\n"
# 411 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "MACHINE, too.$"
# 412 "data//maps/DewfordTown_Gym/scripts.pory"

# 413 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ExplainBulkUp:
# 414 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "That TM08 contains BULK UP.\p"
# 415 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's a move that raises both ATTACK\n"
# 416 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "and DEFENSE stats.\p"
# 417 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "… … … … … …$"
# 418 "data//maps/DewfordTown_Gym/scripts.pory"

# 419 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly:
# 420 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Registered GYM LEADER BRAWLY\n"
# 421 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 422 "data//maps/DewfordTown_Gym/scripts.pory"

# 423 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle:
# 424 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 425 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 426 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "among TRAINERS one day!$"
# 427 "data//maps/DewfordTown_Gym/scripts.pory"

# 428 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue:
# 429 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM$"
# 430 "data//maps/DewfordTown_Gym/scripts.pory"

# 431 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified:
# 432 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\p"
# 433 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
# 434 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 435 "data//maps/DewfordTown_Gym/scripts.pory"

# 436 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch:
# 437 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 438 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 439 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 440 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 441 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Show me how much higher\n"
# 442 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 443 "data//maps/DewfordTown_Gym/scripts.pory"

# 444 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat:
# 445 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 446 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 447 "data//maps/DewfordTown_Gym/scripts.pory"

# 448 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch:
# 449 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: Battling is vast and it's deep.\n"
# 450 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 451 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of HOENN!$"
# 452 "data//maps/DewfordTown_Gym/scripts.pory"

# 453 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
# 454 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 455 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 456 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 457 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 458 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one POKéMON\n"
# 459 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 460 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 461 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "with at least two POKéMON.$"

DewfordTown_Gym_EventScript_BrawlyBadgeOrder::
# 464 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyIntro
# 465 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder_2
# 471 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder_3
# 478 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 479 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1
# 480 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1C
# 481 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1:
	return

DewfordTown_Gym_EventScript_BrawlyBadgeOrder_2:
# 466 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 467 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1
# 468 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1B
# 469 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
	goto DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1

DewfordTown_Gym_EventScript_BrawlyBadgeOrder_3:
# 472 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 473 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1B
# 474 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1C
# 475 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
	goto DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1

