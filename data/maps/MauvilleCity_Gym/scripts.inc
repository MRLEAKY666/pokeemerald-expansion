# 1 "data//maps/MauvilleCity_Gym/scripts.pory"

# 2 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_MapScripts::
# 3 "data//maps/MauvilleCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
# 4 "data//maps/MauvilleCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_Gym_OnTransition
# 5 "data//maps/MauvilleCity_Gym/scripts.pory"
	.byte 0
# 6 "data//maps/MauvilleCity_Gym/scripts.pory"

# 7 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_OnLoad:
# 8 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
# 9 "data//maps/MauvilleCity_Gym/scripts.pory"
	switch VAR_MAUVILLE_GYM_STATE
# 10 "data//maps/MauvilleCity_Gym/scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
# 11 "data//maps/MauvilleCity_Gym/scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
# 12 "data//maps/MauvilleCity_Gym/scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
# 13 "data//maps/MauvilleCity_Gym/scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
# 14 "data//maps/MauvilleCity_Gym/scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
# 15 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 16 "data//maps/MauvilleCity_Gym/scripts.pory"

# 17 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_OnTransition:
# 18 "data//maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 19 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 20 "data//maps/MauvilleCity_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_MAUVILLE_GYM, Common_EventScript_ResetGymTrainers
# 21 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 22 "data//maps/MauvilleCity_Gym/scripts.pory"

# 23 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_UpdateBarriers::
# 24 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
# 25 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 26 "data//maps/MauvilleCity_Gym/scripts.pory"

# 27 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetAltBarriers::
# 28 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
# 29 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
# 30 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
# 31 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 32 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 33 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 34 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 35 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 36 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 37 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 38 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 39 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 40 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 41 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 42 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 43 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 44 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 45 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 46 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 47 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
# 48 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
# 49 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
# 50 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 51 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 52 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 53 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 54 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 55 "data//maps/MauvilleCity_Gym/scripts.pory"

# 56 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1Pressed::
# 57 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 58 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 59 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 60 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 61 "data//maps/MauvilleCity_Gym/scripts.pory"

# 62 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2Pressed::
# 63 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 64 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 65 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 66 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 67 "data//maps/MauvilleCity_Gym/scripts.pory"

# 68 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3Pressed::
# 69 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 70 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 71 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 72 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 73 "data//maps/MauvilleCity_Gym/scripts.pory"

# 74 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4Pressed::
# 75 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 76 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 77 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 78 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 79 "data//maps/MauvilleCity_Gym/scripts.pory"

# 80 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_DeactivatePuzzle::
# 81 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 82 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 83 "data//maps/MauvilleCity_Gym/scripts.pory"

# 84 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Wattson::
# 85 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
# 86 "data//maps/MauvilleCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 87 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
# 88 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
# 89 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
# 90 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
# 91 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 92 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 93 "data//maps/MauvilleCity_Gym/scripts.pory"

# 94 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonDefeated::
# 95 "data//maps/MauvilleCity_Gym/scripts.pory"
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
# 96 "data//maps/MauvilleCity_Gym/scripts.pory"
	waitmessage
# 97 "data//maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 98 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
# 99 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 100 "data//maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 101 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 102 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 103 "data//maps/MauvilleCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 104 "data//maps/MauvilleCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 105 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 106 "data//maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 107 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 108 "data//maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 109 "data//maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 110 "data//maps/MauvilleCity_Gym/scripts.pory"
	call MauvilleCity_Gym_EventScript_GiveShockWave
# 111 "data//maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 112 "data//maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 113 "data//maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 114 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
# 115 "data//maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 116 "data//maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 117 "data//maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 118 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
# 119 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 120 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 121 "data//maps/MauvilleCity_Gym/scripts.pory"

# 122 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave2::
# 123 "data//maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE, 5
# 124 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 125 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 126 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 127 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 128 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 129 "data//maps/MauvilleCity_Gym/scripts.pory"

# 130 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave::
# 131 "data//maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE, 5
# 132 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 133 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 134 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 135 "data//maps/MauvilleCity_Gym/scripts.pory"
	return
# 136 "data//maps/MauvilleCity_Gym/scripts.pory"

# 137 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_CompletedNewMauville::
# 138 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
# 139 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 140 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 141 "data//maps/MauvilleCity_Gym/scripts.pory"

# 142 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonRematch::
# 143 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
# 144 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
# 145 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 146 "data//maps/MauvilleCity_Gym/scripts.pory"

# 147 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1::
# 148 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 149 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 150 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 151 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 1
# 152 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 153 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 154 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 155 "data//maps/MauvilleCity_Gym/scripts.pory"

# 156 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2::
# 157 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 158 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 159 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 160 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 2
# 161 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 162 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 163 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 164 "data//maps/MauvilleCity_Gym/scripts.pory"

# 165 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3::
# 166 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 167 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 168 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 169 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 3
# 170 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 171 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 172 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 173 "data//maps/MauvilleCity_Gym/scripts.pory"

# 174 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4::
# 175 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 176 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 177 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 178 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 4
# 179 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 180 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 181 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 182 "data//maps/MauvilleCity_Gym/scripts.pory"

# 183 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_PressFloorSwitch::
# 184 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymSetDefaultBarriers
# 185 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 186 "data//maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 187 "data//maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 188 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
# 189 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
# 190 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 191 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 192 "data//maps/MauvilleCity_Gym/scripts.pory"

# 193 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SwitchDoNothing::
# 194 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 195 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 196 "data//maps/MauvilleCity_Gym/scripts.pory"

# 197 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetBarriersAltState::
# 198 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 199 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 200 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 201 "data//maps/MauvilleCity_Gym/scripts.pory"

# 202 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_ClearBarriersAltState::
# 203 "data//maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 204 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 205 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 206 "data//maps/MauvilleCity_Gym/scripts.pory"

# 207 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Kirk::
# 208 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
# 209 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
# 210 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 211 "data//maps/MauvilleCity_Gym/scripts.pory"

# 212 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Shawn::
# 213 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
# 214 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
# 215 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 216 "data//maps/MauvilleCity_Gym/scripts.pory"

# 217 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Ben::
# 218 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
# 219 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
# 220 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 221 "data//maps/MauvilleCity_Gym/scripts.pory"

# 222 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Vivian::
# 223 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
# 224 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
# 225 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 226 "data//maps/MauvilleCity_Gym/scripts.pory"

# 227 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Angelo::
# 228 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
# 229 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
# 230 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 231 "data//maps/MauvilleCity_Gym/scripts.pory"

# 232 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuide::
# 233 "data//maps/MauvilleCity_Gym/scripts.pory"
	lock
# 234 "data//maps/MauvilleCity_Gym/scripts.pory"
	faceplayer
# 235 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
# 236 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 237 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 238 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 239 "data//maps/MauvilleCity_Gym/scripts.pory"

# 240 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuidePostVictory::
# 241 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 242 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 243 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 244 "data//maps/MauvilleCity_Gym/scripts.pory"

# 245 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_LeftGymStatue::
# 246 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 247 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 248 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 249 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 250 "data//maps/MauvilleCity_Gym/scripts.pory"

# 251 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_RightGymStatue::
# 252 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 253 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 254 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 255 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 256 "data//maps/MauvilleCity_Gym/scripts.pory"

# 257 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatueCertified::
# 258 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 259 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 260 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 261 "data//maps/MauvilleCity_Gym/scripts.pory"

# 262 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatue::
# 263 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 264 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 265 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 266 "data//maps/MauvilleCity_Gym/scripts.pory"

# 267 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuideAdvice:
# 268 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 269 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 270 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, the LEADER of MAUVILLE\n"
# 271 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "GYM, uses ELECTRIC-type POKéMON.\p"
# 272 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "If you challenge him with WATER-type\n"
# 273 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, he'll zap them! Bzzt!\p"
# 274 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "And, he's put in switch-controlled\n"
# 275 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "doors all over his GYM! Eccentric!\p"
# 276 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, go for it!$"
# 277 "data//maps/MauvilleCity_Gym/scripts.pory"

# 278 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuidePostVictory:
# 279 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Whoa, you're electrifying!\n"
# 280 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You've powered the door open!$"
# 281 "data//maps/MauvilleCity_Gym/scripts.pory"

# 282 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkIntro:
# 283 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "My electric soul, it'll shatter your\n"
# 284 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "dreams whole, whoa-yeahah!$"
# 285 "data//maps/MauvilleCity_Gym/scripts.pory"

# 286 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkDefeat:
# 287 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "That was plugged in, amped up,\n"
# 288 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "over-driven electric, man!$"
# 289 "data//maps/MauvilleCity_Gym/scripts.pory"

# 290 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkPostBattle:
# 291 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON and rock, it's all about heart,\n"
# 292 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "whoa-yeah!$"
# 293 "data//maps/MauvilleCity_Gym/scripts.pory"

# 294 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnIntro:
# 295 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I trained under WATTSON!\n"
# 296 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "There ain't no way I'll lose easily!$"
# 297 "data//maps/MauvilleCity_Gym/scripts.pory"

# 298 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnDefeat:
# 299 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Unplugged and turned off…$"
# 300 "data//maps/MauvilleCity_Gym/scripts.pory"

# 301 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnPostBattle:
# 302 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, our GYM LEADER, has been\n"
# 303 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "around for a long, long time.\p"
# 304 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He was battling even before your\n"
# 305 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "daddy was born, that tough coot.$"
# 306 "data//maps/MauvilleCity_Gym/scripts.pory"

# 307 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenIntro:
# 308 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "This GYM's got puzzles!\n"
# 309 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Isn't it fun?$"
# 310 "data//maps/MauvilleCity_Gym/scripts.pory"

# 311 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenDefeat:
# 312 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "It's no fun to lose…$"
# 313 "data//maps/MauvilleCity_Gym/scripts.pory"

# 314 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenPostBattle:
# 315 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON says he likes setting up\n"
# 316 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "little traps with switches.$"
# 317 "data//maps/MauvilleCity_Gym/scripts.pory"

# 318 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianIntro:
# 319 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "With my charm and my POKéMON's moves,\n"
# 320 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "you'll be shocked!$"
# 321 "data//maps/MauvilleCity_Gym/scripts.pory"

# 322 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianDefeat:
# 323 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I'm shocked by your power!$"
# 324 "data//maps/MauvilleCity_Gym/scripts.pory"

# 325 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianPostBattle:
# 326 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I've heard that MAUVILLE was founded\n"
# 327 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "by WATTSON.\p"
# 328 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He was a TRAINER long before we\n"
# 329 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "became TRAINERS.\l"
# 330 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He must know all sorts of things!$"
# 331 "data//maps/MauvilleCity_Gym/scripts.pory"

# 332 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloIntro:
# 333 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I love shiny things!$"
# 334 "data//maps/MauvilleCity_Gym/scripts.pory"

# 335 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloDefeat:
# 336 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh…\n"
# 337 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "My eyes are frazzled…$"
# 338 "data//maps/MauvilleCity_Gym/scripts.pory"

# 339 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloPostBattle:
# 340 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM's WATTSON has a shiny\n"
# 341 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "forehead. It makes me happy!$"
# 342 "data//maps/MauvilleCity_Gym/scripts.pory"

# 343 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonIntro:
# 344 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I've given up on my plans to convert\n"
# 345 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "the city, I have.\p"
# 346 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "And so, I put my time into making\n"
# 347 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "door traps in my GYM.\p"
# 348 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh? Now, what are you doing here?\p"
# 349 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "What's that? You say you've gotten\n"
# 350 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "past all my rigged doors?\p"
# 351 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 352 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Now, that is amusing!\p"
# 353 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Then, I, WATTSON, the LEADER of\n"
# 354 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM, shall electrify you!$"
# 355 "data//maps/MauvilleCity_Gym/scripts.pory"

# 356 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonDefeat:
# 357 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 358 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Fine, I lost!\p"
# 359 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You ended up giving me a thrill!\n"
# 360 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Take this BADGE!$"
# 361 "data//maps/MauvilleCity_Gym/scripts.pory"

# 362 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ReceivedDynamoBadge:
# 363 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER} received the DYNAMO BADGE\n"
# 364 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "from WATTSON.$"
# 365 "data//maps/MauvilleCity_Gym/scripts.pory"

# 366 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
# 367 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "With the DYNAMO BADGE, POKéMON can\n"
# 368 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "use ROCK SMASH out of battle.\p"
# 369 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "And, it will make your POKéMON a little\n"
# 370 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "bit faster, too.\p"
# 371 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hmm…\n"
# 372 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You should take this, too!$"
# 373 "data//maps/MauvilleCity_Gym/scripts.pory"

# 374 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainShockWave:
# 375 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "That TM34 there contains SHOCK WAVE.\p"
# 376 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "It's a trustworthy move that never\n"
# 377 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "misses! You can count on it!\p"
# 378 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 379 "data//maps/MauvilleCity_Gym/scripts.pory"

# 380 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_RegisteredWattson:
# 381 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Registered GYM LEADER WATTSON\n"
# 382 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 383 "data//maps/MauvilleCity_Gym/scripts.pory"

# 384 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostBattle:
# 385 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I swell with optimism, seeing a promising\n"
# 386 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "young TRAINER like you!$"
# 387 "data//maps/MauvilleCity_Gym/scripts.pory"

# 388 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
# 389 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 390 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Go forth and endeavor, youngster!$"
# 391 "data//maps/MauvilleCity_Gym/scripts.pory"

# 392 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatue:
# 393 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM$"
# 394 "data//maps/MauvilleCity_Gym/scripts.pory"

# 395 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatueCertified:
# 396 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM\p"
# 397 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
# 398 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 399 "data//maps/MauvilleCity_Gym/scripts.pory"

# 400 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPreRematch:
# 401 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 402 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 403 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 404 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 405 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I'll make sparks fly from you!\n"
# 406 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Don't say I didn't warn you!$"
# 407 "data//maps/MauvilleCity_Gym/scripts.pory"

# 408 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchDefeat:
# 409 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oof…\n"
# 410 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Our batteries ran dry…$"
# 411 "data//maps/MauvilleCity_Gym/scripts.pory"

# 412 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostRematch:
# 413 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: We'll have to recharge our\n"
# 414 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "batteries again.\p"
# 415 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "When we're fully charged up, we'll\n"
# 416 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "gladly accept your challenge.\p"
# 417 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "So, come back again sometime,\n"
# 418 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "won't you?$"
# 419 "data//maps/MauvilleCity_Gym/scripts.pory"

# 420 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
# 421 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 422 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 423 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 424 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 425 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oops! Wait!\n"
# 426 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You've only one POKéMON with you!\p"
# 427 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Come see me with two or more\n"
# 428 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, all right?$"
