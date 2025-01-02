# 1 "data//maps/MossdeepCity_Gym/scripts.pory"

# 2 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_MapScripts::
# 3 "data//maps/MossdeepCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
# 4 "data//maps/MossdeepCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
# 5 "data//maps/MossdeepCity_Gym/scripts.pory"
	.byte 0
# 6 "data//maps/MossdeepCity_Gym/scripts.pory"

# 7 "data//maps/MossdeepCity_Gym/scripts.pory"
@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below
# 8 "data//maps/MossdeepCity_Gym/scripts.pory"

# 9 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_OnTransition:
# 10 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 11 "data//maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 12 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
# 13 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 14 "data//maps/MossdeepCity_Gym/scripts.pory"

# 15 "data//maps/MossdeepCity_Gym/scripts.pory"
@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
# 16 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_OnLoad:
# 17 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
# 18 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 19 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 20 "data//maps/MossdeepCity_Gym/scripts.pory"

# 21 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch2::
# 22 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
# 23 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 24 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 25 "data//maps/MossdeepCity_Gym/scripts.pory"

# 26 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch3::
# 27 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
# 28 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 29 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 30 "data//maps/MossdeepCity_Gym/scripts.pory"

# 31 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch4::
# 32 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
# 33 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 34 "data//maps/MossdeepCity_Gym/scripts.pory"

# 35 "data//maps/MossdeepCity_Gym/scripts.pory"
@ All the below set metatile scripts are leftover from RS and are functionally unused
# 36 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
# 37 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 38 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 39 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 40 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 41 "data//maps/MossdeepCity_Gym/scripts.pory"

# 42 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
# 43 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 44 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 45 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 46 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 47 "data//maps/MossdeepCity_Gym/scripts.pory"

# 48 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
# 49 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 50 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 51 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 52 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 53 "data//maps/MossdeepCity_Gym/scripts.pory"

# 54 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
# 55 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
# 56 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 57 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 58 "data//maps/MossdeepCity_Gym/scripts.pory"

# 59 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLiza::
# 60 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
# 61 "data//maps/MossdeepCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 62 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
# 63 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
# 64 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
# 65 "data//maps/MossdeepCity_Gym/scripts.pory"
	release
# 66 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 67 "data//maps/MossdeepCity_Gym/scripts.pory"

# 68 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
# 69 "data//maps/MossdeepCity_Gym/scripts.pory"
	message MossdeepCity_Gym_Text_ReceivedMindBadge
# 70 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmessage
# 71 "data//maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 72 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
# 73 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 74 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_BADGE07_GET
# 75 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
# 76 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
# 77 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_UNKNOWN_0x393
# 78 "data//maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 79 "data//maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 80 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 81 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 82 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
# 83 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
# 84 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
# 85 "data//maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 1
# 86 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
# 87 "data//maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
# 88 "data//maps/MossdeepCity_Gym/scripts.pory"
	call MossdeepCity_Gym_EventScript_GiveCalmMind
# 89 "data//maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 90 "data//maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 91 "data//maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 92 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
# 93 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 94 "data//maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 95 "data//maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 96 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
# 97 "data//maps/MossdeepCity_Gym/scripts.pory"
	release
# 98 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 99 "data//maps/MossdeepCity_Gym/scripts.pory"

# 100 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GiveCalmMind2::
# 101 "data//maps/MossdeepCity_Gym/scripts.pory"
	giveitem ITEM_TM_CALM_MIND, 5
# 102 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 103 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
# 104 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_CALM_MIND
# 105 "data//maps/MossdeepCity_Gym/scripts.pory"
	release
# 106 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 107 "data//maps/MossdeepCity_Gym/scripts.pory"

# 108 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GiveCalmMind::
# 109 "data//maps/MossdeepCity_Gym/scripts.pory"
	giveitem ITEM_TM_CALM_MIND, 5
# 110 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 111 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
# 112 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_CALM_MIND
# 113 "data//maps/MossdeepCity_Gym/scripts.pory"
	return
# 114 "data//maps/MossdeepCity_Gym/scripts.pory"

# 115 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaRematch::
# 116 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
# 117 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
# 118 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 119 "data//maps/MossdeepCity_Gym/scripts.pory"

# 120 "data//maps/MossdeepCity_Gym/scripts.pory"
@ All the below switch scripts are leftover from RS and are functionally unused
# 121 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch1::
# 122 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 123 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
# 124 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 125 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 126 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 127 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 128 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 129 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 130 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 131 "data//maps/MossdeepCity_Gym/scripts.pory"

# 132 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
# 133 "data//maps/MossdeepCity_Gym/scripts.pory"
	special DrawWholeMapView
# 134 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_CLICK
# 135 "data//maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 136 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 137 "data//maps/MossdeepCity_Gym/scripts.pory"

# 138 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch1::
# 139 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 140 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 141 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 142 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 143 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 144 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 145 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 146 "data//maps/MossdeepCity_Gym/scripts.pory"

# 147 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch2::
# 148 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 149 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
# 150 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 151 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 152 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 153 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 154 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 155 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 156 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 157 "data//maps/MossdeepCity_Gym/scripts.pory"

# 158 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch2::
# 159 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 160 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 161 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 162 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
# 163 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 164 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 165 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 166 "data//maps/MossdeepCity_Gym/scripts.pory"

# 167 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch3::
# 168 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 169 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
# 170 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 171 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 172 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 173 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
# 174 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 175 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 176 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 177 "data//maps/MossdeepCity_Gym/scripts.pory"

# 178 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch3::
# 179 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 180 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 181 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 182 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 183 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 184 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 185 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 186 "data//maps/MossdeepCity_Gym/scripts.pory"

# 187 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch4::
# 188 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 189 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
# 190 "data//maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 191 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 192 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 193 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
# 194 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
# 195 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 196 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 197 "data//maps/MossdeepCity_Gym/scripts.pory"

# 198 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch4::
# 199 "data//maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 200 "data//maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 201 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 202 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
# 203 "data//maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
# 204 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 205 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 206 "data//maps/MossdeepCity_Gym/scripts.pory"

# 207 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_WarpToEntrance::
# 208 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 209 "data//maps/MossdeepCity_Gym/scripts.pory"
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
# 210 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitstate
# 211 "data//maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 212 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 213 "data//maps/MossdeepCity_Gym/scripts.pory"

# 214 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Preston::
# 215 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
# 216 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
# 217 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 218 "data//maps/MossdeepCity_Gym/scripts.pory"

# 219 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Virgil::
# 220 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
# 221 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
# 222 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 223 "data//maps/MossdeepCity_Gym/scripts.pory"

# 224 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Blake::
# 225 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
# 226 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
# 227 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 228 "data//maps/MossdeepCity_Gym/scripts.pory"

# 229 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Hannah::
# 230 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
# 231 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
# 232 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 233 "data//maps/MossdeepCity_Gym/scripts.pory"

# 234 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Samantha::
# 235 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
# 236 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
# 237 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 238 "data//maps/MossdeepCity_Gym/scripts.pory"

# 239 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Maura::
# 240 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
# 241 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
# 242 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 243 "data//maps/MossdeepCity_Gym/scripts.pory"

# 244 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Sylvia::
# 245 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
# 246 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
# 247 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 248 "data//maps/MossdeepCity_Gym/scripts.pory"

# 249 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nate::
# 250 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
# 251 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
# 252 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 253 "data//maps/MossdeepCity_Gym/scripts.pory"

# 254 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Macey::
# 255 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
# 256 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
# 257 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 258 "data//maps/MossdeepCity_Gym/scripts.pory"

# 259 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Clifford::
# 260 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
# 261 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
# 262 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 263 "data//maps/MossdeepCity_Gym/scripts.pory"

# 264 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nicholas::
# 265 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
# 266 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
# 267 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 268 "data//maps/MossdeepCity_Gym/scripts.pory"

# 269 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Kathleen::
# 270 "data//maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
# 271 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
# 272 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 273 "data//maps/MossdeepCity_Gym/scripts.pory"

# 274 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuide::
# 275 "data//maps/MossdeepCity_Gym/scripts.pory"
	lock
# 276 "data//maps/MossdeepCity_Gym/scripts.pory"
	faceplayer
# 277 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
# 278 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 279 "data//maps/MossdeepCity_Gym/scripts.pory"
	release
# 280 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 281 "data//maps/MossdeepCity_Gym/scripts.pory"

# 282 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuidePostVictory::
# 283 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 284 "data//maps/MossdeepCity_Gym/scripts.pory"
	release
# 285 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 286 "data//maps/MossdeepCity_Gym/scripts.pory"

# 287 "data//maps/MossdeepCity_Gym/scripts.pory"
@ Leftover from RS, functionally unused
# 288 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
# 289 "data//maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 290 "data//maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 291 "data//maps/MossdeepCity_Gym/scripts.pory"
	step_end
# 292 "data//maps/MossdeepCity_Gym/scripts.pory"

# 293 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_LeftGymStatue::
# 294 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 295 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 296 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 297 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 298 "data//maps/MossdeepCity_Gym/scripts.pory"

# 299 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RightGymStatue::
# 300 "data//maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 301 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 302 "data//maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 303 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 304 "data//maps/MossdeepCity_Gym/scripts.pory"

# 305 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatueCertified::
# 306 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 307 "data//maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 308 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 309 "data//maps/MossdeepCity_Gym/scripts.pory"

# 310 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatue::
# 311 "data//maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 312 "data//maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 313 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 314 "data//maps/MossdeepCity_Gym/scripts.pory"

# 315 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_YellowFloorSwitch::
# 316 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 317 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 318 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 319 "data//maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 320 "data//maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 0
# 321 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 322 "data//maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 323 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 324 "data//maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 325 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 326 "data//maps/MossdeepCity_Gym/scripts.pory"

# 327 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_BlueFloorSwitch::
# 328 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 329 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 330 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 331 "data//maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 332 "data//maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 1
# 333 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 334 "data//maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 335 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 336 "data//maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 337 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 338 "data//maps/MossdeepCity_Gym/scripts.pory"

# 339 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GreenFloorSwitch::
# 340 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 341 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 342 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 343 "data//maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 344 "data//maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 2
# 345 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 346 "data//maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 347 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 348 "data//maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 349 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 350 "data//maps/MossdeepCity_Gym/scripts.pory"

# 351 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
# 352 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 353 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 354 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 355 "data//maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 356 "data//maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 3
# 357 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 358 "data//maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 359 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 360 "data//maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 361 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 362 "data//maps/MossdeepCity_Gym/scripts.pory"

# 363 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RedFloorSwitch::
# 364 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 365 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 366 "data//maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 367 "data//maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 368 "data//maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 4
# 369 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 370 "data//maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 371 "data//maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 372 "data//maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 373 "data//maps/MossdeepCity_Gym/scripts.pory"
	end
# 374 "data//maps/MossdeepCity_Gym/scripts.pory"

# 375 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymGuideAdvice:
# 376 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Yo, how's it going, CHAMPION-bound\n"
# 377 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER}?\p"
# 378 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "The GYM LEADERS here use\n"
# 379 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "PSYCHIC-type POKéMON.\p"
# 380 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "If you go up against them with\n"
# 381 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "FIGHTING- or POISON-type POKéMON,\l"
# 382 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "they'll inflict horrible damage!\p"
# 383 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Plus, they'll come at you with\n"
# 384 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "outstanding combination attacks.\p"
# 385 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "If you want to win, you'll need to show\n"
# 386 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "them how tight you are with your\l"
# 387 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "POKéMON. Go for it!$"
# 388 "data//maps/MossdeepCity_Gym/scripts.pory"

# 389 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymGuidePostVictory:
# 390 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Wow, you're astounding!\n"
# 391 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You're one great TRAINER!$"
# 392 "data//maps/MossdeepCity_Gym/scripts.pory"

# 393 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonIntro:
# 394 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Battles hinge on the strength of your\n"
# 395 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "spirit! The weak-spirited will never win!$"
# 396 "data//maps/MossdeepCity_Gym/scripts.pory"

# 397 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonDefeat:
# 398 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I lost!\n"
# 399 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I must temper my spirit again!$"
# 400 "data//maps/MossdeepCity_Gym/scripts.pory"

# 401 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonPostBattle:
# 402 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "The indecisive lose.\n"
# 403 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "That's my warning to you.$"
# 404 "data//maps/MossdeepCity_Gym/scripts.pory"

# 405 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilIntro:
# 406 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me see your talent!$"
# 407 "data//maps/MossdeepCity_Gym/scripts.pory"

# 408 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilDefeat:
# 409 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You possess spectacular talent!$"
# 410 "data//maps/MossdeepCity_Gym/scripts.pory"

# 411 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilPostBattle:
# 412 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "If there are prodigies in the world,\n"
# 413 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "then our GYM LEADERS are them!\p"
# 414 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "However, you may be even more talented\n"
# 415 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "than them…$"
# 416 "data//maps/MossdeepCity_Gym/scripts.pory"

# 417 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeIntro:
# 418 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Fufufufu… Watch me levitate a POKé\n"
# 419 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "BALL telekinetically!\p"
# 420 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Wrooooooooaaaar!\n"
# 421 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … … …\p"
# 422 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Sometimes, I'm out of sync…$"
# 423 "data//maps/MossdeepCity_Gym/scripts.pory"

# 424 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeDefeat:
# 425 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "My POKéMON battling skills are out\n"
# 426 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "of sync, too!$"
# 427 "data//maps/MossdeepCity_Gym/scripts.pory"

# 428 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakePostBattle:
# 429 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "A POKé BALL was too heavy to lift\n"
# 430 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "psychically. But this dust bunny…\p"
# 431 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Whoooooooooooooooh!\n"
# 432 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …\p"
# 433 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "No, I'm not cheating!\n"
# 434 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I didn't blow on it! Honestly!$"
# 435 "data//maps/MossdeepCity_Gym/scripts.pory"

# 436 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahIntro:
# 437 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "When you lose to me, don't be too hard\n"
# 438 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "on yourself.\p"
# 439 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "It's not that you're weak--I'm just\n"
# 440 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "too strong!$"
# 441 "data//maps/MossdeepCity_Gym/scripts.pory"

# 442 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahDefeat:
# 443 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You're just too strong!$"
# 444 "data//maps/MossdeepCity_Gym/scripts.pory"

# 445 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahPostBattle:
# 446 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I'm not going to get down on myself for\n"
# 447 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "losing. I just need to train harder.\p"
# 448 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Positive thinking--that's my strong\n"
# 449 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "point!$"
# 450 "data//maps/MossdeepCity_Gym/scripts.pory"

# 451 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaIntro:
# 452 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I see it…\n"
# 453 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I see your future…\p"
# 454 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "If you can beat me, I will tell you\n"
# 455 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "your future!$"
# 456 "data//maps/MossdeepCity_Gym/scripts.pory"

# 457 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaDefeat:
# 458 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I surrender!$"
# 459 "data//maps/MossdeepCity_Gym/scripts.pory"

# 460 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaPostBattle:
# 461 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You will wage a terrifically intense\n"
# 462 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "battle with our GYM LEADERS…\p"
# 463 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "The result…\n"
# 464 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You won't hear it from me!$"
# 465 "data//maps/MossdeepCity_Gym/scripts.pory"

# 466 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraIntro:
# 467 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "The roads you have traveled…\n"
# 468 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "What you have experienced…\p"
# 469 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Come at me with everything you've\n"
# 470 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "learned!$"
# 471 "data//maps/MossdeepCity_Gym/scripts.pory"

# 472 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraDefeat:
# 473 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You've traveled a path of greatness!$"
# 474 "data//maps/MossdeepCity_Gym/scripts.pory"

# 475 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraPostBattle:
# 476 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "A bright future awaits those who have\n"
# 477 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "worked diligently.\p"
# 478 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "For those who lazed idly, there is\n"
# 479 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "only despair at the end.\p"
# 480 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "What goes around comes around…$"
# 481 "data//maps/MossdeepCity_Gym/scripts.pory"

# 482 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaIntro:
# 483 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Even at the risk of life, I will win\n"
# 484 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "this battle!$"
# 485 "data//maps/MossdeepCity_Gym/scripts.pory"

# 486 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaDefeat:
# 487 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "What you do…\n"
# 488 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "It horrifies me…$"
# 489 "data//maps/MossdeepCity_Gym/scripts.pory"

# 490 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaPostBattle:
# 491 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "How dare you beat me…\p"
# 492 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "It won't be my fault if something\n"
# 493 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "horrible befalls you…$"
# 494 "data//maps/MossdeepCity_Gym/scripts.pory"

# 495 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateIntro:
# 496 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Hohoho.\p"
# 497 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You need me to show you how tenacious\n"
# 498 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "the PSYCHIC type can be.$"
# 499 "data//maps/MossdeepCity_Gym/scripts.pory"

# 500 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateDefeat:
# 501 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh! My, my!\n"
# 502 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Your battle style is fantastic!$"
# 503 "data//maps/MossdeepCity_Gym/scripts.pory"

# 504 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NatePostBattle:
# 505 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I… I don't let defeat rattle m-me,\n"
# 506 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "however b-badly.$"
# 507 "data//maps/MossdeepCity_Gym/scripts.pory"

# 508 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenIntro:
# 509 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me show you a perfectly awful,\n"
# 510 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "horrifying time!$"
# 511 "data//maps/MossdeepCity_Gym/scripts.pory"

# 512 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenDefeat:
# 513 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "N-nooooo!$"
# 514 "data//maps/MossdeepCity_Gym/scripts.pory"

# 515 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenPostBattle:
# 516 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Your vitality is contagious!\n"
# 517 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Get away from me quickly!$"
# 518 "data//maps/MossdeepCity_Gym/scripts.pory"

# 519 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordIntro:
# 520 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "I may be past my prime, but I suggest\n"
# 521 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "you not patronize me.$"
# 522 "data//maps/MossdeepCity_Gym/scripts.pory"

# 523 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordDefeat:
# 524 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Ah, you overflow with the power\n"
# 525 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "of youth!$"
# 526 "data//maps/MossdeepCity_Gym/scripts.pory"

# 527 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordPostBattle:
# 528 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "It seems that I could not overcome\n"
# 529 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "your youthful energy.$"
# 530 "data//maps/MossdeepCity_Gym/scripts.pory"

# 531 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyIntro:
# 532 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "You're not getting through to the end!\n"
# 533 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Not if I can help it!$"
# 534 "data//maps/MossdeepCity_Gym/scripts.pory"

# 535 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyDefeat:
# 536 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "How could you be so ludicrously\n"
# 537 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "strong?$"
# 538 "data//maps/MossdeepCity_Gym/scripts.pory"

# 539 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyPostBattle:
# 540 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Humph! You may be strong, but you're\n"
# 541 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "not suitable for the PSYCHIC type!\p"
# 542 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "The way you battle is somehow brutal!$"
# 543 "data//maps/MossdeepCity_Gym/scripts.pory"

# 544 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasIntro:
# 545 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Wroooar! Have a taste of my super\n"
# 546 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "POKéMON hard-battling power!$"
# 547 "data//maps/MossdeepCity_Gym/scripts.pory"

# 548 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasDefeat:
# 549 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh!\n"
# 550 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Done in!$"
# 551 "data//maps/MossdeepCity_Gym/scripts.pory"

# 552 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasPostBattle:
# 553 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "All right! I think I'll develop a special\n"
# 554 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "invincible POKéMON power next.$"
# 555 "data//maps/MossdeepCity_Gym/scripts.pory"

# 556 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaIntro:
# 557 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Hehehe… Were you surprised?\p"
# 558 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Fufufu… Were you surprised?\p"
# 559 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: That there are two GYM LEADERS?\n"
# 560 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: That there are two GYM LEADERS?\p"
# 561 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We're twins!\n"
# 562 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We're twins!\p"
# 563 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We don't need to talk because…\n"
# 564 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We can each determine what…\p"
# 565 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: The other is thinking…\n"
# 566 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: All in our minds!\p"
# 567 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: This combination of ours…\n"
# 568 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Can you beat it?$"
# 569 "data//maps/MossdeepCity_Gym/scripts.pory"

# 570 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaDefeat:
# 571 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: What?! Our combination…\n"
# 572 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Was shattered!\p"
# 573 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It can't be helped. You've won…\n"
# 574 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: So, in recognition, take this.$"
# 575 "data//maps/MossdeepCity_Gym/scripts.pory"

# 576 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ReceivedMindBadge:
# 577 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER} received the MIND BADGE\n"
# 578 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "from TATE and LIZA.$"
# 579 "data//maps/MossdeepCity_Gym/scripts.pory"

# 580 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
# 581 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: The MIND BADGE enhances the\n"
# 582 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
# 583 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It also lets you use the HM move\n"
# 584 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "DIVE outside of battle.\p"
# 585 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You should also take this, too.$"
# 586 "data//maps/MossdeepCity_Gym/scripts.pory"

# 587 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainCalmMind:
# 588 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: That TM04 contains…\n"
# 589 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: CALM MIND!\p"
# 590 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It raises SP. ATK and…\n"
# 591 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It raises SP. DEF!\p"
# 592 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: It's a move that's perfect…\n"
# 593 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: For PSYCHIC POKéMON!\p"
# 594 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 595 "data//maps/MossdeepCity_Gym/scripts.pory"

# 596 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_RegisteredTateAndLiza:
# 597 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "Registered GYM LEADERS TATE & LIZA\n"
# 598 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 599 "data//maps/MossdeepCity_Gym/scripts.pory"

# 600 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostBattle:
# 601 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Looks like the bond between you\n"
# 602 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "and your POKéMON is far stronger than\l"
# 603 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "the bond that we share as twins.\p"
# 604 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You will become even stronger!\n"
# 605 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "We've battled you, so we know.$"
# 606 "data//maps/MossdeepCity_Gym/scripts.pory"

# 607 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
# 608 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Hehehe… Were you surprised?\p"
# 609 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: That there are two GYM LEADERS?\p"
# 610 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Oops, you have only one…\n"
# 611 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: POKéMON that can battle.\p"
# 612 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We can't battle that way!\p"
# 613 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: If you want to challenge us,\n"
# 614 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "bring some more POKéMON.$"
# 615 "data//maps/MossdeepCity_Gym/scripts.pory"

# 616 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatue:
# 617 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM$"
# 618 "data//maps/MossdeepCity_Gym/scripts.pory"

# 619 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatueCertified:
# 620 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\p"
# 621 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
# 622 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 623 "data//maps/MossdeepCity_Gym/scripts.pory"

# 624 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPreRematch:
# 625 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: POKéMON…\n"
# 626 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: POKéMON…\p"
# 627 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: By changing the party's mix…\n"
# 628 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: The battle style changes.\p"
# 629 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: But me…\n"
# 630 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: But me…\p"
# 631 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: I'll always be with LIZA!\n"
# 632 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: I'll always be with TATE!\p"
# 633 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: Our combination…\n"
# 634 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: We'll show you again and again!$"
# 635 "data//maps/MossdeepCity_Gym/scripts.pory"

# 636 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
# 637 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You and your POKéMON…\n"
# 638 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: It's as if you were siblings!$"
# 639 "data//maps/MossdeepCity_Gym/scripts.pory"

# 640 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostRematch:
# 641 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You can knock us down,\n"
# 642 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "but we'll never stay down!\p"
# 643 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Because the two of us,\n"
# 644 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "we always support each other!$"
# 645 "data//maps/MossdeepCity_Gym/scripts.pory"

# 646 "data//maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
# 647 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You're back again…\n"
# 648 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You're back again…\p"
# 649 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: To give us a rematch.\n"
# 650 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: To give us a rematch.\p"
# 651 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: But…\n"
# 652 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: For our match…\p"
# 653 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: You brought just one POKéMON!\n"
# 654 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: You brought just one POKéMON!\p"
# 655 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "TATE: We need you to bring at least…\n"
# 656 "data//maps/MossdeepCity_Gym/scripts.pory"
	.string "LIZA: Two POKéMON when you come back.$"
