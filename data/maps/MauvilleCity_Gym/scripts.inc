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
	setvar VAR_0x8008, 3
# 19 "data//maps/MauvilleCity_Gym/scripts.pory"
	call_if_unset FLAG_DEFEATED_MAUVILLE_GYM, Common_EventScript_ResetGymTrainers
# 20 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 21 "data//maps/MauvilleCity_Gym/scripts.pory"

# 22 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_UpdateBarriers::
# 23 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
# 24 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 25 "data//maps/MauvilleCity_Gym/scripts.pory"

# 26 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetAltBarriers::
# 27 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
# 28 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
# 29 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
# 30 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 31 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 32 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 33 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 34 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
# 35 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
# 36 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
# 37 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
# 38 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 39 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 40 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 41 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 42 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 43 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 44 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 45 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 46 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
# 47 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
# 48 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
# 49 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
# 50 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
# 51 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
# 52 "data//maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
# 53 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 54 "data//maps/MauvilleCity_Gym/scripts.pory"

# 55 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1Pressed::
# 56 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 57 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 58 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 59 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 60 "data//maps/MauvilleCity_Gym/scripts.pory"

# 61 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2Pressed::
# 62 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 63 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 64 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 65 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 66 "data//maps/MauvilleCity_Gym/scripts.pory"

# 67 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3Pressed::
# 68 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 69 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 70 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 71 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 72 "data//maps/MauvilleCity_Gym/scripts.pory"

# 73 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4Pressed::
# 74 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 75 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 76 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 77 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 78 "data//maps/MauvilleCity_Gym/scripts.pory"

# 79 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_DeactivatePuzzle::
# 80 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 81 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 82 "data//maps/MauvilleCity_Gym/scripts.pory"

# 83 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Wattson::
# 84 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
# 85 "data//maps/MauvilleCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 86 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
# 87 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
# 88 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
# 89 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
# 90 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 91 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 92 "data//maps/MauvilleCity_Gym/scripts.pory"

# 93 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonDefeated::
# 94 "data//maps/MauvilleCity_Gym/scripts.pory"
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
# 95 "data//maps/MauvilleCity_Gym/scripts.pory"
	waitmessage
# 96 "data//maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 97 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
# 98 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 99 "data//maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 100 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 101 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 102 "data//maps/MauvilleCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 103 "data//maps/MauvilleCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 104 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 105 "data//maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 106 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 107 "data//maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 108 "data//maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 109 "data//maps/MauvilleCity_Gym/scripts.pory"
	call MauvilleCity_Gym_EventScript_GiveShockWave
# 110 "data//maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 111 "data//maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 112 "data//maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 113 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
# 114 "data//maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 115 "data//maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 116 "data//maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 117 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
# 118 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 119 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 120 "data//maps/MauvilleCity_Gym/scripts.pory"

# 121 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave2::
# 122 "data//maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE, 5
# 123 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 124 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 125 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 126 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 127 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 128 "data//maps/MauvilleCity_Gym/scripts.pory"

# 129 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GiveShockWave::
# 130 "data//maps/MauvilleCity_Gym/scripts.pory"
	giveitem ITEM_TM_SHOCK_WAVE, 5
# 131 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 132 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
# 133 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
# 134 "data//maps/MauvilleCity_Gym/scripts.pory"
	return
# 135 "data//maps/MauvilleCity_Gym/scripts.pory"

# 136 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_CompletedNewMauville::
# 137 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
# 138 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 139 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 140 "data//maps/MauvilleCity_Gym/scripts.pory"

# 141 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonRematch::
# 142 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
# 143 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
# 144 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 145 "data//maps/MauvilleCity_Gym/scripts.pory"

# 146 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1::
# 147 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 148 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 149 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 150 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 1
# 151 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 152 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 153 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 154 "data//maps/MauvilleCity_Gym/scripts.pory"

# 155 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2::
# 156 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 157 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 158 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 159 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 2
# 160 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 161 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 162 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 163 "data//maps/MauvilleCity_Gym/scripts.pory"

# 164 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3::
# 165 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 166 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 167 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 168 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 3
# 169 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 170 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 171 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 172 "data//maps/MauvilleCity_Gym/scripts.pory"

# 173 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4::
# 174 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 175 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 176 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 177 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 4
# 178 "data//maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 179 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 180 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 181 "data//maps/MauvilleCity_Gym/scripts.pory"

# 182 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_PressFloorSwitch::
# 183 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymSetDefaultBarriers
# 184 "data//maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 185 "data//maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 186 "data//maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 187 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
# 188 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
# 189 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 190 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 191 "data//maps/MauvilleCity_Gym/scripts.pory"

# 192 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SwitchDoNothing::
# 193 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 194 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 195 "data//maps/MauvilleCity_Gym/scripts.pory"

# 196 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetBarriersAltState::
# 197 "data//maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 198 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 199 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 200 "data//maps/MauvilleCity_Gym/scripts.pory"

# 201 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_ClearBarriersAltState::
# 202 "data//maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 203 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 204 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 205 "data//maps/MauvilleCity_Gym/scripts.pory"

# 206 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Kirk::
# 207 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
# 208 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
# 209 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 210 "data//maps/MauvilleCity_Gym/scripts.pory"

# 211 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Shawn::
# 212 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
# 213 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
# 214 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 215 "data//maps/MauvilleCity_Gym/scripts.pory"

# 216 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Ben::
# 217 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
# 218 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
# 219 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 220 "data//maps/MauvilleCity_Gym/scripts.pory"

# 221 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Vivian::
# 222 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
# 223 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
# 224 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 225 "data//maps/MauvilleCity_Gym/scripts.pory"

# 226 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Angelo::
# 227 "data//maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
# 228 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
# 229 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 230 "data//maps/MauvilleCity_Gym/scripts.pory"

# 231 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuide::
# 232 "data//maps/MauvilleCity_Gym/scripts.pory"
	lock
# 233 "data//maps/MauvilleCity_Gym/scripts.pory"
	faceplayer
# 234 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
# 235 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 236 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 237 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 238 "data//maps/MauvilleCity_Gym/scripts.pory"

# 239 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuidePostVictory::
# 240 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 241 "data//maps/MauvilleCity_Gym/scripts.pory"
	release
# 242 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 243 "data//maps/MauvilleCity_Gym/scripts.pory"

# 244 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_LeftGymStatue::
# 245 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 246 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 247 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 248 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 249 "data//maps/MauvilleCity_Gym/scripts.pory"

# 250 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_RightGymStatue::
# 251 "data//maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 252 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 253 "data//maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 254 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 255 "data//maps/MauvilleCity_Gym/scripts.pory"

# 256 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatueCertified::
# 257 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 258 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 259 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 260 "data//maps/MauvilleCity_Gym/scripts.pory"

# 261 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatue::
# 262 "data//maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 263 "data//maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 264 "data//maps/MauvilleCity_Gym/scripts.pory"
	end
# 265 "data//maps/MauvilleCity_Gym/scripts.pory"

# 266 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuideAdvice:
# 267 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 268 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 269 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, the LEADER of MAUVILLE\n"
# 270 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "GYM, uses ELECTRIC-type POKéMON.\p"
# 271 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "If you challenge him with WATER-type\n"
# 272 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, he'll zap them! Bzzt!\p"
# 273 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "And, he's put in switch-controlled\n"
# 274 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "doors all over his GYM! Eccentric!\p"
# 275 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, go for it!$"
# 276 "data//maps/MauvilleCity_Gym/scripts.pory"

# 277 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuidePostVictory:
# 278 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Whoa, you're electrifying!\n"
# 279 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You've powered the door open!$"
# 280 "data//maps/MauvilleCity_Gym/scripts.pory"

# 281 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkIntro:
# 282 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "My electric soul, it'll shatter your\n"
# 283 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "dreams whole, whoa-yeahah!$"
# 284 "data//maps/MauvilleCity_Gym/scripts.pory"

# 285 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkDefeat:
# 286 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "That was plugged in, amped up,\n"
# 287 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "over-driven electric, man!$"
# 288 "data//maps/MauvilleCity_Gym/scripts.pory"

# 289 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkPostBattle:
# 290 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON and rock, it's all about heart,\n"
# 291 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "whoa-yeah!$"
# 292 "data//maps/MauvilleCity_Gym/scripts.pory"

# 293 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnIntro:
# 294 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I trained under WATTSON!\n"
# 295 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "There ain't no way I'll lose easily!$"
# 296 "data//maps/MauvilleCity_Gym/scripts.pory"

# 297 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnDefeat:
# 298 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Unplugged and turned off…$"
# 299 "data//maps/MauvilleCity_Gym/scripts.pory"

# 300 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnPostBattle:
# 301 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON, our GYM LEADER, has been\n"
# 302 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "around for a long, long time.\p"
# 303 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He was battling even before your\n"
# 304 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "daddy was born, that tough coot.$"
# 305 "data//maps/MauvilleCity_Gym/scripts.pory"

# 306 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenIntro:
# 307 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "This GYM's got puzzles!\n"
# 308 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Isn't it fun?$"
# 309 "data//maps/MauvilleCity_Gym/scripts.pory"

# 310 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenDefeat:
# 311 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "It's no fun to lose…$"
# 312 "data//maps/MauvilleCity_Gym/scripts.pory"

# 313 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenPostBattle:
# 314 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON says he likes setting up\n"
# 315 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "little traps with switches.$"
# 316 "data//maps/MauvilleCity_Gym/scripts.pory"

# 317 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianIntro:
# 318 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "With my charm and my POKéMON's moves,\n"
# 319 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "you'll be shocked!$"
# 320 "data//maps/MauvilleCity_Gym/scripts.pory"

# 321 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianDefeat:
# 322 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I'm shocked by your power!$"
# 323 "data//maps/MauvilleCity_Gym/scripts.pory"

# 324 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianPostBattle:
# 325 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I've heard that MAUVILLE was founded\n"
# 326 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "by WATTSON.\p"
# 327 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He was a TRAINER long before we\n"
# 328 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "became TRAINERS.\l"
# 329 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "He must know all sorts of things!$"
# 330 "data//maps/MauvilleCity_Gym/scripts.pory"

# 331 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloIntro:
# 332 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I love shiny things!$"
# 333 "data//maps/MauvilleCity_Gym/scripts.pory"

# 334 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloDefeat:
# 335 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh…\n"
# 336 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "My eyes are frazzled…$"
# 337 "data//maps/MauvilleCity_Gym/scripts.pory"

# 338 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloPostBattle:
# 339 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM's WATTSON has a shiny\n"
# 340 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "forehead. It makes me happy!$"
# 341 "data//maps/MauvilleCity_Gym/scripts.pory"

# 342 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonIntro:
# 343 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I've given up on my plans to convert\n"
# 344 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "the city, I have.\p"
# 345 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "And so, I put my time into making\n"
# 346 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "door traps in my GYM.\p"
# 347 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh? Now, what are you doing here?\p"
# 348 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "What's that? You say you've gotten\n"
# 349 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "past all my rigged doors?\p"
# 350 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 351 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Now, that is amusing!\p"
# 352 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Then, I, WATTSON, the LEADER of\n"
# 353 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE GYM, shall electrify you!$"
# 354 "data//maps/MauvilleCity_Gym/scripts.pory"

# 355 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonDefeat:
# 356 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 357 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Fine, I lost!\p"
# 358 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You ended up giving me a thrill!\n"
# 359 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Take this BADGE!$"
# 360 "data//maps/MauvilleCity_Gym/scripts.pory"

# 361 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ReceivedDynamoBadge:
# 362 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER} received the DYNAMO BADGE\n"
# 363 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "from WATTSON.$"
# 364 "data//maps/MauvilleCity_Gym/scripts.pory"

# 365 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
# 366 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "With the DYNAMO BADGE, POKéMON can\n"
# 367 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "use ROCK SMASH out of battle.\p"
# 368 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Hmm…\n"
# 369 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You should take this, too!$"
# 370 "data//maps/MauvilleCity_Gym/scripts.pory"

# 371 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainShockWave:
# 372 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "That TM34 there contains SHOCK WAVE.\p"
# 373 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "It's a trustworthy move that never\n"
# 374 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "misses! You can count on it!\p"
# 375 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 376 "data//maps/MauvilleCity_Gym/scripts.pory"

# 377 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_RegisteredWattson:
# 378 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Registered GYM LEADER WATTSON\n"
# 379 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 380 "data//maps/MauvilleCity_Gym/scripts.pory"

# 381 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostBattle:
# 382 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I swell with optimism, seeing a promising\n"
# 383 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "young TRAINER like you!$"
# 384 "data//maps/MauvilleCity_Gym/scripts.pory"

# 385 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
# 386 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 387 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Go forth and endeavor, youngster!$"
# 388 "data//maps/MauvilleCity_Gym/scripts.pory"

# 389 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatue:
# 390 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM$"
# 391 "data//maps/MauvilleCity_Gym/scripts.pory"

# 392 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatueCertified:
# 393 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "MAUVILLE CITY POKéMON GYM\p"
# 394 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
# 395 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 396 "data//maps/MauvilleCity_Gym/scripts.pory"

# 397 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPreRematch:
# 398 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 399 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 400 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 401 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 402 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I'll make sparks fly from you!\n"
# 403 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Don't say I didn't warn you!$"
# 404 "data//maps/MauvilleCity_Gym/scripts.pory"

# 405 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchDefeat:
# 406 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oof…\n"
# 407 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Our batteries ran dry…$"
# 408 "data//maps/MauvilleCity_Gym/scripts.pory"

# 409 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostRematch:
# 410 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: We'll have to recharge our\n"
# 411 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "batteries again.\p"
# 412 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "When we're fully charged up, we'll\n"
# 413 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "gladly accept your challenge.\p"
# 414 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "So, come back again sometime,\n"
# 415 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "won't you?$"
# 416 "data//maps/MauvilleCity_Gym/scripts.pory"

# 417 "data//maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
# 418 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "WATTSON: Ah-ha! Here at last!\n"
# 419 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 420 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my POKéMON!\p"
# 421 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 422 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Oops! Wait!\n"
# 423 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "You've only one POKéMON with you!\p"
# 424 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "Come see me with two or more\n"
# 425 "data//maps/MauvilleCity_Gym/scripts.pory"
	.string "POKéMON, all right?$"
