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
	setflag FLAG_PROGRESS_BASED_LEVEL_SCALING
# 11 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 12 "data//maps/DewfordTown_Gym/scripts.pory"

# 13 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel::
# 14 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 15 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 16 "data//maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 17 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
# 18 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
# 19 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
# 20 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
# 21 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
# 22 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
# 23 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashLevel1
# 24 "data//maps/DewfordTown_Gym/scripts.pory"

# 25 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn::
# 26 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 0
# 27 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 28 "data//maps/DewfordTown_Gym/scripts.pory"

# 29 "data//maps/DewfordTown_Gym/scripts.pory"
@ Brightest
# 30 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel1::
# 31 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 1
# 32 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 33 "data//maps/DewfordTown_Gym/scripts.pory"

# 34 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel2::
# 35 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 2
# 36 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 37 "data//maps/DewfordTown_Gym/scripts.pory"

# 38 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel3::
# 39 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 3
# 40 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 41 "data//maps/DewfordTown_Gym/scripts.pory"

# 42 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel4::
# 43 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 4
# 44 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 45 "data//maps/DewfordTown_Gym/scripts.pory"

# 46 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel5::
# 47 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 5
# 48 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 49 "data//maps/DewfordTown_Gym/scripts.pory"

# 50 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel6::
# 51 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 6
# 52 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 53 "data//maps/DewfordTown_Gym/scripts.pory"

# 54 "data//maps/DewfordTown_Gym/scripts.pory"
@ Darkest
# 55 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel7::
# 56 "data//maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 7
# 57 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 58 "data//maps/DewfordTown_Gym/scripts.pory"

# 59 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom::
# 60 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 61 "data//maps/DewfordTown_Gym/scripts.pory"
	nop1
# 62 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
# 63 "data//maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 64 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 65 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 66 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 67 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 68 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 69 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 70 "data//maps/DewfordTown_Gym/scripts.pory"

# 71 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange::
# 72 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 73 "data//maps/DewfordTown_Gym/scripts.pory"

# 74 "data//maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 75 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
# 76 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 77 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 78 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 79 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 80 "data//maps/DewfordTown_Gym/scripts.pory"

# 81 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
# 82 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 83 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 84 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 85 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 86 "data//maps/DewfordTown_Gym/scripts.pory"

# 87 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
# 88 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 89 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 90 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 91 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 92 "data//maps/DewfordTown_Gym/scripts.pory"

# 93 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
# 94 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 95 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 96 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 97 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 98 "data//maps/DewfordTown_Gym/scripts.pory"

# 99 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
# 100 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 101 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 102 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 103 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 104 "data//maps/DewfordTown_Gym/scripts.pory"

# 105 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
# 106 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 107 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 108 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 109 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 110 "data//maps/DewfordTown_Gym/scripts.pory"

# 111 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
# 112 "data//maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 113 "data//maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 114 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 115 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 116 "data//maps/DewfordTown_Gym/scripts.pory"

# 117 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated::
# 118 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 119 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 120 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 121 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn::
# 122 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 123 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 124 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura::
# 125 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 126 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 127 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden::
# 128 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 129 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 130 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian::
# 131 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 132 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 133 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith::
# 134 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 135 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 136 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers::
# 137 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 138 "data//maps/DewfordTown_Gym/scripts.pory"

# 139 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly::
# 140 "data//maps/DewfordTown_Gym/scripts.pory"
	lock
# 141 "data//maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 142 "data//maps/DewfordTown_Gym/scripts.pory"
	call_if_unset FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder
# 143 "data//maps/DewfordTown_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 144 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
# 145 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
# 146 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 147 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 148 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 149 "data//maps/DewfordTown_Gym/scripts.pory"

# 150 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated::
# 151 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 152 "data//maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 153 "data//maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 154 "data//maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 155 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 156 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 157 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 158 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_BADGE_COUNT, 1
# 159 "data//maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 160 "data//maps/DewfordTown_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 161 "data//maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 162 "data//maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 163 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 164 "data//maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 165 "data//maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 166 "data//maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 167 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 168 "data//maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 169 "data//maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 170 "data//maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 171 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 172 "data//maps/DewfordTown_Gym/scripts.pory"
	@ setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 173 "data//maps/DewfordTown_Gym/scripts.pory"
	@ setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 174 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 175 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 176 "data//maps/DewfordTown_Gym/scripts.pory"

# 177 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp::
# 178 "data//maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP, 5
# 179 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 180 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 181 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 182 "data//maps/DewfordTown_Gym/scripts.pory"
	return
# 183 "data//maps/DewfordTown_Gym/scripts.pory"

# 184 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp2:
# 185 "data//maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP, 5
# 186 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 187 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 188 "data//maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 189 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 190 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 191 "data//maps/DewfordTown_Gym/scripts.pory"

# 192 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 193 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
# 194 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 195 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 196 "data//maps/DewfordTown_Gym/scripts.pory"

# 197 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao::
# 198 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 199 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 200 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 201 "data//maps/DewfordTown_Gym/scripts.pory"

# 202 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom::
# 203 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 204 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 205 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 206 "data//maps/DewfordTown_Gym/scripts.pory"

# 207 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn::
# 208 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 209 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 210 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 211 "data//maps/DewfordTown_Gym/scripts.pory"

# 212 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom::
# 213 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 214 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 215 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 216 "data//maps/DewfordTown_Gym/scripts.pory"

# 217 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura::
# 218 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 219 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 220 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 221 "data//maps/DewfordTown_Gym/scripts.pory"

# 222 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom::
# 223 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 224 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 225 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 226 "data//maps/DewfordTown_Gym/scripts.pory"

# 227 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden::
# 228 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 229 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 230 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 231 "data//maps/DewfordTown_Gym/scripts.pory"

# 232 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom::
# 233 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 234 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 235 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 236 "data//maps/DewfordTown_Gym/scripts.pory"

# 237 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian::
# 238 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 239 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 240 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 241 "data//maps/DewfordTown_Gym/scripts.pory"

# 242 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom::
# 243 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 244 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 245 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 246 "data//maps/DewfordTown_Gym/scripts.pory"

# 247 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith::
# 248 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 249 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 250 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 251 "data//maps/DewfordTown_Gym/scripts.pory"

# 252 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom::
# 253 "data//maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 254 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 255 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 256 "data//maps/DewfordTown_Gym/scripts.pory"

# 257 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide::
# 258 "data//maps/DewfordTown_Gym/scripts.pory"
	lock
# 259 "data//maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 260 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 261 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 262 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 263 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 264 "data//maps/DewfordTown_Gym/scripts.pory"

# 265 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory::
# 266 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 267 "data//maps/DewfordTown_Gym/scripts.pory"
	release
# 268 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 269 "data//maps/DewfordTown_Gym/scripts.pory"

# 270 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue::
# 271 "data//maps/DewfordTown_Gym/scripts.pory"
	lockall
# 272 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 273 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 274 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 275 "data//maps/DewfordTown_Gym/scripts.pory"

# 276 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue::
# 277 "data//maps/DewfordTown_Gym/scripts.pory"
	lockall
# 278 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 279 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 280 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 281 "data//maps/DewfordTown_Gym/scripts.pory"

# 282 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified::
# 283 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 284 "data//maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 285 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 286 "data//maps/DewfordTown_Gym/scripts.pory"

# 287 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue::
# 288 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 289 "data//maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 290 "data//maps/DewfordTown_Gym/scripts.pory"
	end
# 291 "data//maps/DewfordTown_Gym/scripts.pory"

# 292 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuideAdvice:
# 293 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 294 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 295 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
# 296 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING-type POKéMON.\p"
# 297 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Going against him with NORMAL-type\n"
# 298 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "POKéMON is asking for trouble.\p"
# 299 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING POKéMON will lay a serious\n"
# 300 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "smack down on NORMAL POKéMON,\l"
# 301 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "so be careful!\p"
# 302 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "What's worse, the GYM is as dark as\n"
# 303 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "the ocean floor.\p"
# 304 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 305 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "the TRAINERS in your way.\p"
# 306 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 307 "data//maps/DewfordTown_Gym/scripts.pory"

# 308 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory:
# 309 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 310 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 311 "data//maps/DewfordTown_Gym/scripts.pory"

# 312 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro:
# 313 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 314 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 315 "data//maps/DewfordTown_Gym/scripts.pory"

# 316 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat:
# 317 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 318 "data//maps/DewfordTown_Gym/scripts.pory"

# 319 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle:
# 320 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 321 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 322 "data//maps/DewfordTown_Gym/scripts.pory"

# 323 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro:
# 324 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for BRAWLY to be\n"
# 325 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 326 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 327 "data//maps/DewfordTown_Gym/scripts.pory"

# 328 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat:
# 329 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 330 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 331 "data//maps/DewfordTown_Gym/scripts.pory"

# 332 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle:
# 333 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 334 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 335 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a GYM LEADER…\p"
# 336 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the POKéMON LEAGUE\n"
# 337 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "CHAMPION!$"
# 338 "data//maps/DewfordTown_Gym/scripts.pory"

# 339 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro:
# 340 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 341 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 342 "data//maps/DewfordTown_Gym/scripts.pory"

# 343 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat:
# 344 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 345 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 346 "data//maps/DewfordTown_Gym/scripts.pory"

# 347 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle:
# 348 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 349 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 350 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 351 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "see BRAWLY's face…$"
# 352 "data//maps/DewfordTown_Gym/scripts.pory"

# 353 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro:
# 354 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 355 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 356 "data//maps/DewfordTown_Gym/scripts.pory"

# 357 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat:
# 358 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 359 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 360 "data//maps/DewfordTown_Gym/scripts.pory"

# 361 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle:
# 362 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 363 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 364 "data//maps/DewfordTown_Gym/scripts.pory"

# 365 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro:
# 366 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 367 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 368 "data//maps/DewfordTown_Gym/scripts.pory"

# 369 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat:
# 370 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 371 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 372 "data//maps/DewfordTown_Gym/scripts.pory"

# 373 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle:
# 374 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 375 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "our GYM LEADER.$"
# 376 "data//maps/DewfordTown_Gym/scripts.pory"

# 377 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro:
# 378 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 379 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 380 "data//maps/DewfordTown_Gym/scripts.pory"

# 381 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat:
# 382 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 383 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 384 "data//maps/DewfordTown_Gym/scripts.pory"

# 385 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle:
# 386 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 387 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that BADGE!$"
# 388 "data//maps/DewfordTown_Gym/scripts.pory"

# 389 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro:
# 390 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm BRAWLY!\n"
# 391 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER!\p"
# 392 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 393 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 394 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 395 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 396 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 397 "data//maps/DewfordTown_Gym/scripts.pory"

# 398 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat:
# 399 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 400 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 401 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 402 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 403 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Take this GYM BADGE!$"
# 404 "data//maps/DewfordTown_Gym/scripts.pory"

# 405 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge:
# 406 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the KNUCKLE BADGE\n"
# 407 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "from BRAWLY.$"
# 408 "data//maps/DewfordTown_Gym/scripts.pory"

# 409 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
# 410 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Now you'll be able to use the HM move\n"
# 411 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "FLASH outside of battle.\p"
# 412 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, use this TECHNICAL\n"
# 413 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "MACHINE, too.$"
# 414 "data//maps/DewfordTown_Gym/scripts.pory"

# 415 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ExplainBulkUp:
# 416 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "That TM08 contains BULK UP.\p"
# 417 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's a move that raises both ATTACK\n"
# 418 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "and DEFENSE stats.\p"
# 419 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "… … … … … …$"
# 420 "data//maps/DewfordTown_Gym/scripts.pory"

# 421 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly:
# 422 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Registered GYM LEADER BRAWLY\n"
# 423 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 424 "data//maps/DewfordTown_Gym/scripts.pory"

# 425 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle:
# 426 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 427 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 428 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "among TRAINERS one day!$"
# 429 "data//maps/DewfordTown_Gym/scripts.pory"

# 430 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue:
# 431 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM$"
# 432 "data//maps/DewfordTown_Gym/scripts.pory"

# 433 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified:
# 434 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\p"
# 435 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
# 436 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 437 "data//maps/DewfordTown_Gym/scripts.pory"

# 438 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch:
# 439 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 440 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 441 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 442 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 443 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Show me how much higher\n"
# 444 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 445 "data//maps/DewfordTown_Gym/scripts.pory"

# 446 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat:
# 447 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 448 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 449 "data//maps/DewfordTown_Gym/scripts.pory"

# 450 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch:
# 451 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: Battling is vast and it's deep.\n"
# 452 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 453 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of HOENN!$"
# 454 "data//maps/DewfordTown_Gym/scripts.pory"

# 455 "data//maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
# 456 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 457 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 458 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 459 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 460 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one POKéMON\n"
# 461 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 462 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 463 "data//maps/DewfordTown_Gym/scripts.pory"
	.string "with at least two POKéMON.$"

DewfordTown_Gym_EventScript_BrawlyBadgeOrder::
# 466 "data//maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyIntro
# 467 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder_2
# 473 "data//maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, DewfordTown_Gym_EventScript_BrawlyBadgeOrder_3
# 480 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 481 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1
# 482 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1C
# 483 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1:
	return

DewfordTown_Gym_EventScript_BrawlyBadgeOrder_2:
# 468 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 469 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1
# 470 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1B
# 471 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
	goto DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1

DewfordTown_Gym_EventScript_BrawlyBadgeOrder_3:
# 474 "data//maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1C, DewfordTown_Gym_Text_BrawlyDefeat
# 475 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1B
# 476 "data//maps/DewfordTown_Gym/scripts.pory"
	settrainerflag TRAINER_BRAWLY_1C
# 477 "data//maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_BrawlyDefeated
	goto DewfordTown_Gym_EventScript_BrawlyBadgeOrder_1

