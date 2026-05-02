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
	setflag FLAG_TEMP_7
# 42 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 43 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 44 "data//maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_UNLOCKED_NEW_MAUVILLE_BASEMENT_DOOR, NewMauville_Inside_EventScript_ShowLockedBasementDoor
# 45 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 46 "data//maps/NewMauville_Inside/scripts.pory"

# 47 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowLockedBasementDoor::
# 48 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_TEMP_7
# 49 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 12, METATILE_BikeShop_Basement_Door_Closed, TRUE
# 50 "data//maps/NewMauville_Inside/scripts.pory"
	return

NewMauville_Inside_EventScript_LockedBasementDoor::
# 55 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 56 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_EventScript_LockedBasementDoor_Text_0, MSGBOX_DEFAULT
# 57 "data//maps/NewMauville_Inside/scripts.pory"
	checkitem ITEM_BASEMENT_KEY
# 58 "data//maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq NewMauville_Inside_EventScript_LockedBasementDoor_2
NewMauville_Inside_EventScript_LockedBasementDoor_1:
# 69 "data//maps/NewMauville_Inside/scripts.pory"
	release
	end

NewMauville_Inside_EventScript_LockedBasementDoor_2:
# 59 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_EventScript_LockedBasementDoor_Text_1, MSGBOX_DEFAULT
# 60 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_UNLOCKED_NEW_MAUVILLE_BASEMENT_DOOR
# 61 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 12, METATILE_BikeShop_Basement_Door_Open, FALSE
# 62 "data//maps/NewMauville_Inside/scripts.pory"
	setobjectxy LOCALID_NEWMAUVILLE_LOCKED_BASEMENT, 33, 17
# 63 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_TEMP_7
# 64 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 65 "data//maps/NewMauville_Inside/scripts.pory"
	playse SE_UNLOCK
# 66 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 67 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_EventScript_LockedBasementDoor_Text_2, MSGBOX_DEFAULT
	goto NewMauville_Inside_EventScript_LockedBasementDoor_1


# 73 "data//maps/NewMauville_Inside/scripts.pory"

# 74 "data//maps/NewMauville_Inside/scripts.pory"

# 75 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_BlueButton::
# 76 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 77 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 1
# 78 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 79 "data//maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 80 "data//maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 81 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 82 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 83 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 84 "data//maps/NewMauville_Inside/scripts.pory"

# 85 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GreenButton::
# 86 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 87 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 88 "data//maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 1
# 89 "data//maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 90 "data//maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 91 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 92 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 93 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 94 "data//maps/NewMauville_Inside/scripts.pory"

# 95 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
# 96 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 97 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 98 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 99 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 100 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 101 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 102 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 103 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 104 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 105 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 106 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 107 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 108 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 109 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 110 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 111 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 112 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 113 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 114 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 115 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 116 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 117 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 118 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 119 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 120 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 121 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 122 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 123 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 124 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 125 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 126 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
# 127 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
# 128 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
# 129 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
# 130 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
# 131 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
# 132 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
# 133 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 134 "data//maps/NewMauville_Inside/scripts.pory"

# 135 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
# 136 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 137 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 138 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 139 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 140 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 141 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 142 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 143 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 144 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 145 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 146 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 147 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 148 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 149 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 150 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 151 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 152 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 153 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 154 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 155 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 156 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 157 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 158 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 159 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 160 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 161 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 162 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 163 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 164 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 165 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 166 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
# 167 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
# 168 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
# 169 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
# 170 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
# 171 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
# 172 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
# 173 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 174 "data//maps/NewMauville_Inside/scripts.pory"

# 175 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RedButton::
# 176 "data//maps/NewMauville_Inside/scripts.pory"
	@ lockall
# 177 "data//maps/NewMauville_Inside/scripts.pory"
	@ msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
# 178 "data//maps/NewMauville_Inside/scripts.pory"
	@ call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 179 "data//maps/NewMauville_Inside/scripts.pory"
	@ setvar VAR_NEW_MAUVILLE_STATE, 2
# 180 "data//maps/NewMauville_Inside/scripts.pory"
	@ releaseall
# 181 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 182 "data//maps/NewMauville_Inside/scripts.pory"

# 183 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
# 184 "data//maps/NewMauville_Inside/scripts.pory"
	@ setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
# 185 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
# 186 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
# 187 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
# 188 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
# 189 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
# 190 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
# 191 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
# 192 "data//maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
# 193 "data//maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 194 "data//maps/NewMauville_Inside/scripts.pory"
	return
# 195 "data//maps/NewMauville_Inside/scripts.pory"

# 196 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Generator::
# 197 "data//maps/NewMauville_Inside/scripts.pory"
	lockall
# 198 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_unset FLAG_REGI_DOORS_OPENED, NewMauville_Inside_EventScript_GeneratorOff
# 199 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_GeneratorOff
# 200 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
# 201 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 202 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 203 "data//maps/NewMauville_Inside/scripts.pory"

# 204 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GeneratorOff::
# 205 "data//maps/NewMauville_Inside/scripts.pory"
	@ msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
# 206 "data//maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRunningSmoothly, MSGBOX_DEFAULT
# 207 "data//maps/NewMauville_Inside/scripts.pory"
	releaseall
# 208 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 209 "data//maps/NewMauville_Inside/scripts.pory"

# 210 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb1::
# 211 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 212 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 213 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 214 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 215 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 216 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 217 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 218 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 219 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 220 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 221 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 222 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 223 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 224 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 225 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 226 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 227 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 228 "data//maps/NewMauville_Inside/scripts.pory"

# 229 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb1::
# 230 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 231 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 232 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 233 "data//maps/NewMauville_Inside/scripts.pory"

# 234 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb2::
# 235 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 236 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 237 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 238 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 239 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 240 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 241 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 242 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 243 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 244 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 245 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 246 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 247 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 248 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 249 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 250 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 251 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 252 "data//maps/NewMauville_Inside/scripts.pory"

# 253 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb2::
# 254 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 255 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 256 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 257 "data//maps/NewMauville_Inside/scripts.pory"

# 258 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb3::
# 259 "data//maps/NewMauville_Inside/scripts.pory"
	lock
# 260 "data//maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 261 "data//maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 262 "data//maps/NewMauville_Inside/scripts.pory"
	waitse
# 263 "data//maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 264 "data//maps/NewMauville_Inside/scripts.pory"
	delay 40
# 265 "data//maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 266 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 267 "data//maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 268 "data//maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 269 "data//maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 270 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 271 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 272 "data//maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 273 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 274 "data//maps/NewMauville_Inside/scripts.pory"
	release
# 275 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 276 "data//maps/NewMauville_Inside/scripts.pory"

# 277 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb3::
# 278 "data//maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 279 "data//maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 280 "data//maps/NewMauville_Inside/scripts.pory"
	end
# 281 "data//maps/NewMauville_Inside/scripts.pory"

# 282 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRadiatingHeat:
# 283 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
# 284 "data//maps/NewMauville_Inside/scripts.pory"
	.string "can be felt even at a distance.\p"
# 285 "data//maps/NewMauville_Inside/scripts.pory"
	.string "It looks like it should be turned off\n"
# 286 "data//maps/NewMauville_Inside/scripts.pory"
	.string "as soon as possible.$"
# 287 "data//maps/NewMauville_Inside/scripts.pory"

# 288 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorQuietedDown:
# 289 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"
# 290 "data//maps/NewMauville_Inside/scripts.pory"

# 291 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRunningSmoothly:
# 292 "data//maps/NewMauville_Inside/scripts.pory"
	.string "It's a big generator.\l"
# 293 "data//maps/NewMauville_Inside/scripts.pory"
	.string "And it's running smoothly!$"
# 294 "data//maps/NewMauville_Inside/scripts.pory"

# 295 "data//maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
# 296 "data//maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
# 297 "data//maps/NewMauville_Inside/scripts.pory"
	.string "Click…\p"
# 298 "data//maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\n"
# 299 "data//maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\p"
# 300 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The generator appears to have\n"
# 301 "data//maps/NewMauville_Inside/scripts.pory"
	.string "stopped…$"

NewMauville_Inside_EventScript_LockedBasementDoor_Text_0:
# 56 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The door is locked.$"

NewMauville_Inside_EventScript_LockedBasementDoor_Text_1:
# 59 "data//maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} used the BASEMENT KEY!$"

NewMauville_Inside_EventScript_LockedBasementDoor_Text_2:
# 67 "data//maps/NewMauville_Inside/scripts.pory"
	.string "The basement door opened.$"
