# 1 "data//maps/FortreeCliffs/scripts.pory"

# 2 "data//maps/FortreeCliffs/scripts.pory"

# 3 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_MapScripts::
# 4 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffs_OnResume
# 5 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffs_OnTransition
# 6 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeCliffs_OnFrame
# 7 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 8 "data//maps/FortreeCliffs/scripts.pory"

# 9 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnFrame:
# 10 "data//maps/FortreeCliffs/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 2, FortreeCliffs_EventScript_SwitchToDaytime
# 11 "data//maps/FortreeCliffs/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_SwitchToNighttime
# 12 "data//maps/FortreeCliffs/scripts.pory"
	.2byte 0
# 13 "data//maps/FortreeCliffs/scripts.pory"

# 14 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 15 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 16 "data//maps/FortreeCliffs/scripts.pory"
	end
# 17 "data//maps/FortreeCliffs/scripts.pory"

# 18 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 19 "data//maps/FortreeCliffs/scripts.pory"
	@ call FortreeCliffs_EventScript_ResetWildMons
# 20 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryOnTransitionSwitch
# 21 "data//maps/FortreeCliffs/scripts.pory"
	end
# 22 "data//maps/FortreeCliffs/scripts.pory"

# 23 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToDaytime::
# 24 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 25 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 26 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_SetSunElevationCheck
# 27 "data//maps/FortreeCliffs/scripts.pory"
	end
# 28 "data//maps/FortreeCliffs/scripts.pory"

# 29 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToNighttime::
# 30 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 31 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 32 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_ClearSunElevationCheck
# 33 "data//maps/FortreeCliffs/scripts.pory"
	end
# 34 "data//maps/FortreeCliffs/scripts.pory"

# 35 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSunElevationCheck::
# 36 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_SetSun
# 37 "data//maps/FortreeCliffs/scripts.pory"
	end
# 38 "data//maps/FortreeCliffs/scripts.pory"

# 39 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSunElevationCheck::
# 40 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_ClearSun
# 41 "data//maps/FortreeCliffs/scripts.pory"
	end
# 42 "data//maps/FortreeCliffs/scripts.pory"

# 43 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 44 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 45 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 46 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 47 "data//maps/FortreeCliffs/scripts.pory"
	return
# 48 "data//maps/FortreeCliffs/scripts.pory"

# 49 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryOnTransitionSwitch::
# 50 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                 @ place objects at correct spot when map loads
# 51 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_PlaceBraviaryAtNest1
# 52 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_PlaceBraviaryAtNest2                                             
# 53 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_PlaceBraviaryAtNest3
# 54 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_PlaceBraviaryAtNest4
# 55 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_PlaceBraviaryAtNest5                                           
# 56 "data//maps/FortreeCliffs/scripts.pory"
	return
# 57 "data//maps/FortreeCliffs/scripts.pory"

# 58 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TrySetSun::
# 59 "data//maps/FortreeCliffs/scripts.pory"
	call_if_le VAR_TIME_OF_DAY, 3, FortreeCliffs_EventScript_SetSun
# 60 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_ClearSun
# 61 "data//maps/FortreeCliffs/scripts.pory"
	end
# 62 "data//maps/FortreeCliffs/scripts.pory"

# 63 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSun::
# 64 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 65 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 66 "data//maps/FortreeCliffs/scripts.pory"
	return
# 67 "data//maps/FortreeCliffs/scripts.pory"

# 68 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSun::
# 69 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_NONE
# 70 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 71 "data//maps/FortreeCliffs/scripts.pory"
	return
# 72 "data//maps/FortreeCliffs/scripts.pory"

# 73 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Winona::
# 74 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 75 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 76 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona1, MSGBOX_DEFAULT
# 77 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 78 "data//maps/FortreeCliffs/scripts.pory"
	delay 30
# 79 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona2, MSGBOX_DEFAULT
# 80 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 81 "data//maps/FortreeCliffs/scripts.pory"
	delay 5
# 82 "data//maps/FortreeCliffs/scripts.pory"
	turnobject LOCALID_FORTREE_CLIFFS_WINONA, DIR_WEST
# 83 "data//maps/FortreeCliffs/scripts.pory"
	delay 60
# 84 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3a, MSGBOX_DEFAULT
# 85 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 86 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 87 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_WINONA, Common_Movement_FacePlayer
# 88 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 89 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3, MSGBOX_DEFAULT
# 90 "data//maps/FortreeCliffs/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 91 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona4, MSGBOX_DEFAULT
# 92 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 93 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1
# 94 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 95 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 96 "data//maps/FortreeCliffs/scripts.pory"
	removeobject LOCALID_FORTREE_CLIFFS_WINONA
# 97 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 98 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 99 "data//maps/FortreeCliffs/scripts.pory"
	release
# 100 "data//maps/FortreeCliffs/scripts.pory"
	end
# 101 "data//maps/FortreeCliffs/scripts.pory"

# 102 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 103 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 104 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 105 "data//maps/FortreeCliffs/scripts.pory"
	return
# 106 "data//maps/FortreeCliffs/scripts.pory"

# 107 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 108 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 109 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 110 "data//maps/FortreeCliffs/scripts.pory"
	return
# 111 "data//maps/FortreeCliffs/scripts.pory"

# 112 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 113 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 114 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 115 "data//maps/FortreeCliffs/scripts.pory"
	return
# 116 "data//maps/FortreeCliffs/scripts.pory"

# 117 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 118 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 119 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 120 "data//maps/FortreeCliffs/scripts.pory"
	return
# 121 "data//maps/FortreeCliffs/scripts.pory"

# 122 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 123 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 124 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 125 "data//maps/FortreeCliffs/scripts.pory"
	return
# 126 "data//maps/FortreeCliffs/scripts.pory"

# 127 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 128 "data//maps/FortreeCliffs/scripts.pory"
	end
# 129 "data//maps/FortreeCliffs/scripts.pory"

# 130 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 131 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 132 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 133 "data//maps/FortreeCliffs/scripts.pory"
	release
# 134 "data//maps/FortreeCliffs/scripts.pory"
	end
# 135 "data//maps/FortreeCliffs/scripts.pory"

# 136 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 137 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 138 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 139 "data//maps/FortreeCliffs/scripts.pory"
	hidefollower 0
# 140 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 141 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 142 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 143 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 144 "data//maps/FortreeCliffs/scripts.pory"
	
# 145 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 146 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 147 "data//maps/FortreeCliffs/scripts.pory"

# 148 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 149 "data//maps/FortreeCliffs/scripts.pory"

# 150 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 151 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 152 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 153 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 154 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 155 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 156 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 157 "data//maps/FortreeCliffs/scripts.pory"
	release
# 158 "data//maps/FortreeCliffs/scripts.pory"
	end
# 159 "data//maps/FortreeCliffs/scripts.pory"

# 160 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 161 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 162 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 163 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 164 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 165 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 166 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 167 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 168 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 169 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 170 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 171 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 172 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 173 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 174 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 175 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 176 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 177 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 178 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 179 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 180 "data//maps/FortreeCliffs/scripts.pory"
	return
# 181 "data//maps/FortreeCliffs/scripts.pory"

# 182 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 183 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 184 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 185 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 186 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 187 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 188 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 189 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 190 "data//maps/FortreeCliffs/scripts.pory"
	return
# 191 "data//maps/FortreeCliffs/scripts.pory"

# 192 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 193 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 194 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 195 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 196 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 197 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 198 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 199 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 200 "data//maps/FortreeCliffs/scripts.pory"
	return
# 201 "data//maps/FortreeCliffs/scripts.pory"

# 202 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 203 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 204 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 205 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 206 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 207 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 208 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 209 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 210 "data//maps/FortreeCliffs/scripts.pory"
	return
# 211 "data//maps/FortreeCliffs/scripts.pory"

# 212 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 213 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 214 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 215 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 216 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 217 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 218 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 219 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 220 "data//maps/FortreeCliffs/scripts.pory"
	return
# 221 "data//maps/FortreeCliffs/scripts.pory"

# 222 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 223 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 224 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 225 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 226 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 227 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 228 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 229 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 230 "data//maps/FortreeCliffs/scripts.pory"
	return
# 231 "data//maps/FortreeCliffs/scripts.pory"

# 232 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 233 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 234 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 235 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 236 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 237 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 238 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 239 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 240 "data//maps/FortreeCliffs/scripts.pory"
	return
# 241 "data//maps/FortreeCliffs/scripts.pory"

# 242 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 243 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 244 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 245 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 246 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 247 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 248 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 249 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 250 "data//maps/FortreeCliffs/scripts.pory"
	return
# 251 "data//maps/FortreeCliffs/scripts.pory"

# 252 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 253 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 254 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 255 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 256 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 257 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 258 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 259 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 260 "data//maps/FortreeCliffs/scripts.pory"
	end
# 261 "data//maps/FortreeCliffs/scripts.pory"

# 262 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 263 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 264 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 265 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 266 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 267 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 268 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 269 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 270 "data//maps/FortreeCliffs/scripts.pory"
	end
# 271 "data//maps/FortreeCliffs/scripts.pory"

# 272 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 273 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 274 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 275 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 276 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 277 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 278 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 279 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 280 "data//maps/FortreeCliffs/scripts.pory"
	end
# 281 "data//maps/FortreeCliffs/scripts.pory"

# 282 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 283 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 284 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 285 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 286 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 287 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 288 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 289 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 290 "data//maps/FortreeCliffs/scripts.pory"
	end
# 291 "data//maps/FortreeCliffs/scripts.pory"

# 292 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 293 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 294 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 295 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 296 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 297 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 298 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 299 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 300 "data//maps/FortreeCliffs/scripts.pory"
	end
# 301 "data//maps/FortreeCliffs/scripts.pory"

# 302 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 303 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 304 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 305 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 306 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                        @ animate player landing
# 307 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 308 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 309 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 310 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 311 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 312 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 313 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 314 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 315 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 316 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1   
# 317 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP     
# 318 "data//maps/FortreeCliffs/scripts.pory"
	release
# 319 "data//maps/FortreeCliffs/scripts.pory"
	end
# 320 "data//maps/FortreeCliffs/scripts.pory"

# 321 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 322 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 323 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 324 "data//maps/FortreeCliffs/scripts.pory"
	return
# 325 "data//maps/FortreeCliffs/scripts.pory"

# 326 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 327 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 328 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 329 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 330 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_NORMAL
# 331 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 332 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 333 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 334 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 335 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 336 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 337 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 338 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 339 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 340 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 341 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 342 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 343 "data//maps/FortreeCliffs/scripts.pory"
	return
# 344 "data//maps/FortreeCliffs/scripts.pory"

# 345 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 346 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 347 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 348 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 349 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 350 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 351 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 352 "data//maps/FortreeCliffs/scripts.pory"
	end
# 353 "data//maps/FortreeCliffs/scripts.pory"

# 354 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 355 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 356 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 357 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 358 "data//maps/FortreeCliffs/scripts.pory"
	return
# 359 "data//maps/FortreeCliffs/scripts.pory"

# 360 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 361 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 362 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 363 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 364 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 365 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 366 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 367 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 368 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 369 "data//maps/FortreeCliffs/scripts.pory"
	return
# 370 "data//maps/FortreeCliffs/scripts.pory"

# 371 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 372 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 373 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 374 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 375 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 376 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 377 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 378 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 379 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 380 "data//maps/FortreeCliffs/scripts.pory"
	return
# 381 "data//maps/FortreeCliffs/scripts.pory"

# 382 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 383 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 384 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 385 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 386 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 387 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 388 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 389 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 390 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 391 "data//maps/FortreeCliffs/scripts.pory"
	return
# 392 "data//maps/FortreeCliffs/scripts.pory"

# 393 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 394 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 395 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 396 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 397 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 398 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 399 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 400 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 401 "data//maps/FortreeCliffs/scripts.pory"
	release
# 402 "data//maps/FortreeCliffs/scripts.pory"
	end
# 403 "data//maps/FortreeCliffs/scripts.pory"

# 404 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 405 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 406 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 407 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 408 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 409 "data//maps/FortreeCliffs/scripts.pory"
	return
# 410 "data//maps/FortreeCliffs/scripts.pory"

# 411 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 412 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 413 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 414 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 415 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 416 "data//maps/FortreeCliffs/scripts.pory"
	release
# 417 "data//maps/FortreeCliffs/scripts.pory"
	end
# 418 "data//maps/FortreeCliffs/scripts.pory"

# 419 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 420 "data//maps/FortreeCliffs/scripts.pory"
	return
# 421 "data//maps/FortreeCliffs/scripts.pory"

# 422 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 423 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 424 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 425 "data//maps/FortreeCliffs/scripts.pory"
	end
# 426 "data//maps/FortreeCliffs/scripts.pory"

# 427 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 428 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 429 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 430 "data//maps/FortreeCliffs/scripts.pory"
	end
# 431 "data//maps/FortreeCliffs/scripts.pory"

# 432 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 433 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 434 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 435 "data//maps/FortreeCliffs/scripts.pory"
	end
# 436 "data//maps/FortreeCliffs/scripts.pory"

# 437 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 438 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 439 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 440 "data//maps/FortreeCliffs/scripts.pory"
	end
# 441 "data//maps/FortreeCliffs/scripts.pory"

# 442 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 443 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 444 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 445 "data//maps/FortreeCliffs/scripts.pory"
	end
# 446 "data//maps/FortreeCliffs/scripts.pory"

# 447 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 448 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 449 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 450 "data//maps/FortreeCliffs/scripts.pory"
	end
# 451 "data//maps/FortreeCliffs/scripts.pory"

# 452 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 453 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 454 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 455 "data//maps/FortreeCliffs/scripts.pory"
	end
# 456 "data//maps/FortreeCliffs/scripts.pory"

# 457 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 458 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 459 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 460 "data//maps/FortreeCliffs/scripts.pory"
	end
# 461 "data//maps/FortreeCliffs/scripts.pory"

# 462 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 463 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 464 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 465 "data//maps/FortreeCliffs/scripts.pory"
	end
# 466 "data//maps/FortreeCliffs/scripts.pory"

# 467 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 468 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 469 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 470 "data//maps/FortreeCliffs/scripts.pory"
	end
# 471 "data//maps/FortreeCliffs/scripts.pory"

# 472 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 473 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 474 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 475 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 476 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 477 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 478 "data//maps/FortreeCliffs/scripts.pory"

# 479 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 480 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 481 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 482 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 483 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 484 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 485 "data//maps/FortreeCliffs/scripts.pory"

# 486 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 487 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 488 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 489 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 490 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 491 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 492 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 493 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 494 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 495 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 496 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 497 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 498 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 499 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 500 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 501 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 502 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 503 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 504 "data//maps/FortreeCliffs/scripts.pory"

# 505 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 506 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 507 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 508 "data//maps/FortreeCliffs/scripts.pory"

# 509 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 510 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 511 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 512 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 513 "data//maps/FortreeCliffs/scripts.pory"

# 514 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 515 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 516 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 517 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 518 "data//maps/FortreeCliffs/scripts.pory"

# 519 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 520 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 521 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 522 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 523 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 524 "data//maps/FortreeCliffs/scripts.pory"

# 525 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 526 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 527 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 528 "data//maps/FortreeCliffs/scripts.pory"

# 529 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 530 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 531 "data//maps/FortreeCliffs/scripts.pory"

# 532 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 533 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 534 "data//maps/FortreeCliffs/scripts.pory"

# 535 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 536 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 537 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 538 "data//maps/FortreeCliffs/scripts.pory"

# 539 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryAcceptedBerry:
# 540 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY accepted the {STR_VAR_1}.$"
# 541 "data//maps/FortreeCliffs/scripts.pory"

# 542 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 543 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 544 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 545 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 546 "data//maps/FortreeCliffs/scripts.pory"

# 547 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 548 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 549 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 550 "data//maps/FortreeCliffs/scripts.pory"

# 551 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 552 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 553 "data//maps/FortreeCliffs/scripts.pory"

# 554 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona1:
# 555 "data//maps/FortreeCliffs/scripts.pory"
	.string "… … … … … …$"
# 556 "data//maps/FortreeCliffs/scripts.pory"

# 557 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona2:
# 558 "data//maps/FortreeCliffs/scripts.pory"
	.string "I train atop these cliffs\n"
# 559 "data//maps/FortreeCliffs/scripts.pory"
	.string "because of my devotion to reaching\l"
# 560 "data//maps/FortreeCliffs/scripts.pory"
	.string "the greatest heights.\p"
# 561 "data//maps/FortreeCliffs/scripts.pory"
	.string "Very few TRAINERS ever soar so high\n"
# 562 "data//maps/FortreeCliffs/scripts.pory"
	.string "above FORTREE's thick forests and\l"
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "steep cliffs.$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "Take this and meet me at my gym if you\n"
# 567 "data//maps/FortreeCliffs/scripts.pory"
	.string "think you're up to the challenge.$"
# 568 "data//maps/FortreeCliffs/scripts.pory"

# 569 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3a:
# 570 "data//maps/FortreeCliffs/scripts.pory"
	.string "If you made it here, then perhaps you\n" 
# 571 "data//maps/FortreeCliffs/scripts.pory"
	.string "are ready to fly.$"
# 572 "data//maps/FortreeCliffs/scripts.pory"

# 573 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona4:
# 574 "data//maps/FortreeCliffs/scripts.pory"
	.string "Until we meet again, {PLAYER}.$"
# 575 "data//maps/FortreeCliffs/scripts.pory"

# 576 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 577 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 578 "data//maps/FortreeCliffs/scripts.pory"

# 579 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 580 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 581 "data//maps/FortreeCliffs/scripts.pory"

# 582 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 583 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 584 "data//maps/FortreeCliffs/scripts.pory"

# 585 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 586 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 587 "data//maps/FortreeCliffs/scripts.pory"

# 588 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 589 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 590 "data//maps/FortreeCliffs/scripts.pory"

# 591 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 592 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 593 "data//maps/FortreeCliffs/scripts.pory"

# 594 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 595 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 596 "data//maps/FortreeCliffs/scripts.pory"

# 597 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 598 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 599 "data//maps/FortreeCliffs/scripts.pory"

# 600 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 601 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 602 "data//maps/FortreeCliffs/scripts.pory"

# 603 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 604 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 605 "data//maps/FortreeCliffs/scripts.pory"

# 606 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 607 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 608 "data//maps/FortreeCliffs/scripts.pory"

# 609 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 610 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 611 "data//maps/FortreeCliffs/scripts.pory"

# 612 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 613 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 614 "data//maps/FortreeCliffs/scripts.pory"

# 615 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 616 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 617 "data//maps/FortreeCliffs/scripts.pory"

# 618 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 619 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 620 "data//maps/FortreeCliffs/scripts.pory"

# 621 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 622 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 623 "data//maps/FortreeCliffs/scripts.pory"

# 624 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 625 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 626 "data//maps/FortreeCliffs/scripts.pory"

# 627 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 628 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 629 "data//maps/FortreeCliffs/scripts.pory"

# 630 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 631 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 632 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 633 "data//maps/FortreeCliffs/scripts.pory"

# 634 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 635 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 636 "data//maps/FortreeCliffs/scripts.pory"

# 637 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 638 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 639 "data//maps/FortreeCliffs/scripts.pory"

# 640 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 641 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 642 "data//maps/FortreeCliffs/scripts.pory"

# 643 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 644 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 645 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 646 "data//maps/FortreeCliffs/scripts.pory"

# 647 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 648 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 649 "data//maps/FortreeCliffs/scripts.pory"

# 650 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 651 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 652 "data//maps/FortreeCliffs/scripts.pory"

# 653 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 654 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 655 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 656 "data//maps/FortreeCliffs/scripts.pory"

# 657 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 658 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 659 "data//maps/FortreeCliffs/scripts.pory"

# 660 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 661 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 662 "data//maps/FortreeCliffs/scripts.pory"

# 663 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 664 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 665 "data//maps/FortreeCliffs/scripts.pory"

# 666 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 667 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?\p"
# 668 "data//maps/FortreeCliffs/scripts.pory"
	.string "She is friends with powerful\n"
# 669 "data//maps/FortreeCliffs/scripts.pory"
	.string "BIRD POKéMON!$"
