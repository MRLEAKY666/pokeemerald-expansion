# 1 "data//maps/NewMauville_Inside/scripts.pory"

# 2 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_MapScripts::
# 3 "data//maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
# 4 "data//maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
# 5 "data//maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
# 6 "data//maps/NewMauville_Inside/scripts.pory"
	.byte 0
# 7 "data//maps/NewMauville_Inside/scripts.pory"

# 8 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnResume:
# 9 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 10 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 11 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
# 12 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 13 "data//maps/NewMauville_Inside/scripts.pory"

# 14 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_TryRemoveVoltorb::
# 15 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 16 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 17 "data//maps/NewMauville_Inside/scripts.pory"
	removeobject VAR_LAST_TALKED
# 18 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 19 "data//maps/NewMauville_Inside/scripts.pory"

# 20 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnTransition:
# 21 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 22 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 23 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
# 24 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
# 25 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
# 26 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 27 "data//maps/NewMauville_Inside/scripts.pory"

# 28 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb1::
# 29 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
# 30 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 31 "data//maps/NewMauville_Inside/scripts.pory"

# 32 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb2::
# 33 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
# 34 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 35 "data//maps/NewMauville_Inside/scripts.pory"

# 36 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb3::
# 37 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
# 38 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 39 "data//maps/NewMauville_Inside/scripts.pory"

# 40 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnLoad:
# 41 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 42 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 43 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 44 "data//maps/NewMauville_Inside/scripts.pory"

# 45 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_BlueButton::
# 46 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 47 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 1
# 48 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 49 "data//maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 50 "data//maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 51 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 52 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 53 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 54 "data//maps/NewMauville_Inside/scripts.pory"

# 55 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GreenButton::
# 56 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 57 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 58 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 1
# 59 "data//maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 60 "data//maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 61 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 62 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 63 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 64 "data//maps/NewMauville_Inside/scripts.pory"

# 65 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
# 66 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 67 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 68 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 69 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 70 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 71 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 72 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 73 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 74 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 75 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 76 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 77 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 78 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 79 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 80 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 81 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 82 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 83 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 84 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 85 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 86 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 87 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 88 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 89 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 90 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 91 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 92 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 93 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 94 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 95 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 96 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
# 97 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
# 98 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
# 99 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
# 100 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
# 101 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
# 102 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
# 103 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 104 "data//maps/NewMauville_Inside/scripts.pory"

# 105 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
# 106 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 107 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 108 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 109 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 110 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 111 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 112 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 113 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 114 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 115 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 116 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 117 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 118 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 119 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 120 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 121 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 122 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 123 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 124 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 125 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 126 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 127 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 128 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 129 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 130 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 131 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 132 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 133 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 134 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 135 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 136 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
# 137 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
# 138 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
# 139 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
# 140 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
# 141 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
# 142 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
# 143 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 144 "data//maps/NewMauville_Inside/scripts.pory"

# 145 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RedButton::
# 146 "data//maps/NewMauville_Inside/scripts.pory"
	@ lockall
# 147 "data//maps/NewMauville_Inside/scripts.pory"
	@ msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
# 148 "data//maps/NewMauville_Inside/scripts.pory"
	@ call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 149 "data//maps/NewMauville_Inside/scripts.pory"
	@ setvar VAR_NEW_MAUVILLE_STATE, 2
# 150 "data//maps/NewMauville_Inside/scripts.pory"
	@ releaseall
# 151 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 152 "data//maps/NewMauville_Inside/scripts.pory"

# 153 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
# 154 "data//maps/NewMauville_Inside/scripts.pory"
	@ setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
# 155 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
# 156 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
# 157 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
# 158 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
# 159 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
# 160 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
# 161 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
# 162 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
# 163 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 164 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 165 "data//maps/NewMauville_Inside/scripts.pory"

# 166 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Generator::
# 167 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 168 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_unset FLAG_REGI_DOORS_OPENED, NewMauville_Inside_EventScript_GeneratorOff
# 169 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_GeneratorOff
# 170 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
# 171 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 172 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 173 "data//maps/NewMauville_Inside/scripts.pory"

# 174 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GeneratorOff::
# 175 "data//maps/NewMauville_Inside/scripts.pory"
	@ msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
# 176 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRunningSmoothly, MSGBOX_DEFAULT
# 177 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 178 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 179 "data//maps/NewMauville_Inside/scripts.pory"

# 180 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb1::
# 181 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 182 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 183 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 184 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 185 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 186 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 187 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 188 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 189 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 190 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 191 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 192 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 193 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 194 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 195 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 196 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 197 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 198 "data//maps/NewMauville_Inside/scripts.pory"

# 199 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb1::
# 200 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 201 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 202 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 203 "data//maps/NewMauville_Inside/scripts.pory"

# 204 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb2::
# 205 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 206 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 207 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 208 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 209 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 210 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 211 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 212 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 213 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 214 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 215 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 216 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 217 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 218 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 219 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 220 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 221 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 222 "data//maps/NewMauville_Inside/scripts.pory"

# 223 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb2::
# 224 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 225 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 226 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 227 "data//maps/NewMauville_Inside/scripts.pory"

# 228 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb3::
# 229 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 230 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 231 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 232 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 233 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 234 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 235 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 236 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 237 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 238 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 239 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 240 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 241 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 242 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 243 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 244 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 245 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 246 "data//maps/NewMauville_Inside/scripts.pory"

# 247 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb3::
# 248 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 249 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 250 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 251 "data//maps/NewMauville_Inside/scripts.pory"

# 252 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRadiatingHeat:
# 253 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
# 254 "data//maps/NewMauville_Inside/scripts.pory"
	.string "can be felt even at a distance.\p"
# 255 "data//maps/NewMauville_Inside/scripts.pory"
	.string "It looks like it should be turned off\n"
# 256 "data//maps/NewMauville_Inside/scripts.pory"
	.string "as soon as possible.$"
# 257 "data//maps/NewMauville_Inside/scripts.pory"

# 258 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorQuietedDown:
# 259 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"
# 260 "data//maps/NewMauville_Inside/scripts.pory"

# 261 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRunningSmoothly:
# 262 "data//maps/NewMauville_Inside/scripts.pory"
	.string "It's a big generator.\l"
# 263 "data//maps/NewMauville_Inside/scripts.pory"
	.string "And it's running smoothly!$"
# 264 "data//maps/NewMauville_Inside/scripts.pory"

# 265 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
# 266 "data//maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
# 267 "data//maps/NewMauville_Inside/scripts.pory"
	.string "Click…\p"
# 268 "data//maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\n"
# 269 "data//maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\p"
# 270 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator appears to have\n"
# 271 "data//maps/NewMauville_Inside/scripts.pory"
	.string "stopped…$"
