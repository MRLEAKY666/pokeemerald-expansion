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
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCliffs_OnWarp
# 8 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 9 "data//maps/FortreeCliffs/scripts.pory"

# 10 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnFrame:
# 11 "data//maps/FortreeCliffs/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 2, FortreeCliffs_EventScript_SwitchToDaytime
# 12 "data//maps/FortreeCliffs/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_SwitchToNighttime
# 13 "data//maps/FortreeCliffs/scripts.pory"
	.2byte 0
# 14 "data//maps/FortreeCliffs/scripts.pory"

# 15 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnWarp:
# 16 "data//maps/FortreeCliffs/scripts.pory"
 	map_script_2 VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0, FortreeCliffs_EventScript_SetThunderstorm
# 17 "data//maps/FortreeCliffs/scripts.pory"
 	map_script_2 VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_SetThunderstorm
# 18 "data//maps/FortreeCliffs/scripts.pory"
 	map_script_2 VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_TrySetSun
# 19 "data//maps/FortreeCliffs/scripts.pory"
 	map_script_2 VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3, FortreeCliffs_EventScript_TrySetSun
# 20 "data//maps/FortreeCliffs/scripts.pory"
 	map_script_2 VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4, FortreeCliffs_EventScript_TrySetSun
# 21 "data//maps/FortreeCliffs/scripts.pory"
 	.2byte 0
# 22 "data//maps/FortreeCliffs/scripts.pory"

# 23 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 24 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 25 "data//maps/FortreeCliffs/scripts.pory"
	end
# 26 "data//maps/FortreeCliffs/scripts.pory"

# 27 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 28 "data//maps/FortreeCliffs/scripts.pory"
	@ call FortreeCliffs_EventScript_ResetWildMons
# 29 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryOnTransitionSwitch
# 30 "data//maps/FortreeCliffs/scripts.pory"
	end
# 31 "data//maps/FortreeCliffs/scripts.pory"

# 32 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToDaytime::
# 33 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 34 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 35 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_SetSunElevationCheck
# 36 "data//maps/FortreeCliffs/scripts.pory"
	return
# 37 "data//maps/FortreeCliffs/scripts.pory"

# 38 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToNighttime::
# 39 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 40 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 41 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_ClearSunElevationCheck
# 42 "data//maps/FortreeCliffs/scripts.pory"
	return
# 43 "data//maps/FortreeCliffs/scripts.pory"

# 44 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSunElevationCheck::
# 45 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_SetSun
# 46 "data//maps/FortreeCliffs/scripts.pory"
	return
# 47 "data//maps/FortreeCliffs/scripts.pory"

# 48 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSunElevationCheck::
# 49 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_ClearSun
# 50 "data//maps/FortreeCliffs/scripts.pory"
	return
# 51 "data//maps/FortreeCliffs/scripts.pory"

# 52 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 53 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 54 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 55 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 56 "data//maps/FortreeCliffs/scripts.pory"
	return
# 57 "data//maps/FortreeCliffs/scripts.pory"

# 58 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryOnTransitionSwitch::
# 59 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                 @ place objects at correct spot when map loads
# 60 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_PlaceBraviaryAtNest1
# 61 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_PlaceBraviaryAtNest2                                             
# 62 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_PlaceBraviaryAtNest3
# 63 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_PlaceBraviaryAtNest4
# 64 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_PlaceBraviaryAtNest5                                           
# 65 "data//maps/FortreeCliffs/scripts.pory"
	return
# 66 "data//maps/FortreeCliffs/scripts.pory"

# 67 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TrySetSun::
# 68 "data//maps/FortreeCliffs/scripts.pory"
	call_if_le VAR_TIME_OF_DAY, 3, FortreeCliffs_EventScript_SetSun
# 69 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_ClearSun
# 70 "data//maps/FortreeCliffs/scripts.pory"
	return
# 71 "data//maps/FortreeCliffs/scripts.pory"

# 72 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSun::
# 73 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 74 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 75 "data//maps/FortreeCliffs/scripts.pory"
	return
# 76 "data//maps/FortreeCliffs/scripts.pory"

# 77 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSun::
# 78 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_NONE
# 79 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 80 "data//maps/FortreeCliffs/scripts.pory"
	return
# 81 "data//maps/FortreeCliffs/scripts.pory"

# 82 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetThunderstorm::
# 83 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
# 84 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 85 "data//maps/FortreeCliffs/scripts.pory"
	return
# 86 "data//maps/FortreeCliffs/scripts.pory"

# 87 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Winona::
# 88 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 89 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 90 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona1, MSGBOX_DEFAULT
# 91 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 92 "data//maps/FortreeCliffs/scripts.pory"
	delay 30
# 93 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona2, MSGBOX_DEFAULT
# 94 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 95 "data//maps/FortreeCliffs/scripts.pory"
	delay 5
# 96 "data//maps/FortreeCliffs/scripts.pory"
	turnobject LOCALID_FORTREE_CLIFFS_WINONA, DIR_WEST
# 97 "data//maps/FortreeCliffs/scripts.pory"
	delay 60
# 98 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3a, MSGBOX_DEFAULT
# 99 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 100 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 101 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_WINONA, Common_Movement_FacePlayer
# 102 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 103 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3, MSGBOX_DEFAULT
# 104 "data//maps/FortreeCliffs/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 105 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona4, MSGBOX_DEFAULT
# 106 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 107 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1
# 108 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 109 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 110 "data//maps/FortreeCliffs/scripts.pory"
	removeobject LOCALID_FORTREE_CLIFFS_WINONA
# 111 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 112 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 113 "data//maps/FortreeCliffs/scripts.pory"
	release
# 114 "data//maps/FortreeCliffs/scripts.pory"
	end
# 115 "data//maps/FortreeCliffs/scripts.pory"

# 116 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 117 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 118 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 119 "data//maps/FortreeCliffs/scripts.pory"
	return
# 120 "data//maps/FortreeCliffs/scripts.pory"

# 121 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 122 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 123 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 124 "data//maps/FortreeCliffs/scripts.pory"
	return
# 125 "data//maps/FortreeCliffs/scripts.pory"

# 126 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 127 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 128 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 129 "data//maps/FortreeCliffs/scripts.pory"
	return
# 130 "data//maps/FortreeCliffs/scripts.pory"

# 131 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 132 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 133 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 134 "data//maps/FortreeCliffs/scripts.pory"
	return
# 135 "data//maps/FortreeCliffs/scripts.pory"

# 136 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 137 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 138 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 139 "data//maps/FortreeCliffs/scripts.pory"
	return
# 140 "data//maps/FortreeCliffs/scripts.pory"

# 141 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 142 "data//maps/FortreeCliffs/scripts.pory"
	end
# 143 "data//maps/FortreeCliffs/scripts.pory"

# 144 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 145 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 146 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 147 "data//maps/FortreeCliffs/scripts.pory"
	release
# 148 "data//maps/FortreeCliffs/scripts.pory"
	end
# 149 "data//maps/FortreeCliffs/scripts.pory"

# 150 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 151 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 152 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 153 "data//maps/FortreeCliffs/scripts.pory"
	hidefollower 0
# 154 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 155 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 156 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 157 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 158 "data//maps/FortreeCliffs/scripts.pory"
	
# 159 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 160 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 161 "data//maps/FortreeCliffs/scripts.pory"

# 162 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 163 "data//maps/FortreeCliffs/scripts.pory"

# 164 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 165 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 166 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 167 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 168 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 169 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 170 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 171 "data//maps/FortreeCliffs/scripts.pory"
	release
# 172 "data//maps/FortreeCliffs/scripts.pory"
	end
# 173 "data//maps/FortreeCliffs/scripts.pory"

# 174 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 175 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 176 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 177 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 178 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 179 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 180 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 181 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 182 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 183 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 184 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 185 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 186 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 187 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 188 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 189 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 190 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 191 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 192 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 193 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 194 "data//maps/FortreeCliffs/scripts.pory"
	return
# 195 "data//maps/FortreeCliffs/scripts.pory"

# 196 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 197 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 198 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 199 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 200 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 201 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 202 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 203 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 204 "data//maps/FortreeCliffs/scripts.pory"
	return
# 205 "data//maps/FortreeCliffs/scripts.pory"

# 206 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 207 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 208 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 209 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 210 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 211 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 212 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 213 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 214 "data//maps/FortreeCliffs/scripts.pory"
	return
# 215 "data//maps/FortreeCliffs/scripts.pory"

# 216 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 217 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 218 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 219 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 220 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 221 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 222 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 223 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 224 "data//maps/FortreeCliffs/scripts.pory"
	return
# 225 "data//maps/FortreeCliffs/scripts.pory"

# 226 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 227 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 228 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 229 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 230 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 231 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 232 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 233 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 234 "data//maps/FortreeCliffs/scripts.pory"
	return
# 235 "data//maps/FortreeCliffs/scripts.pory"

# 236 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 237 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 238 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 239 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 240 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 241 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 242 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 243 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 244 "data//maps/FortreeCliffs/scripts.pory"
	return
# 245 "data//maps/FortreeCliffs/scripts.pory"

# 246 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 247 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 248 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 249 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 250 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 251 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 252 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 253 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 254 "data//maps/FortreeCliffs/scripts.pory"
	return
# 255 "data//maps/FortreeCliffs/scripts.pory"

# 256 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 257 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 258 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 259 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 260 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 261 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 262 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 263 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 264 "data//maps/FortreeCliffs/scripts.pory"
	return
# 265 "data//maps/FortreeCliffs/scripts.pory"

# 266 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 267 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 268 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 269 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 270 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 271 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 272 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 273 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 274 "data//maps/FortreeCliffs/scripts.pory"
	end
# 275 "data//maps/FortreeCliffs/scripts.pory"

# 276 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 277 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 278 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 279 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 280 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 281 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 282 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 283 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 284 "data//maps/FortreeCliffs/scripts.pory"
	end
# 285 "data//maps/FortreeCliffs/scripts.pory"

# 286 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 287 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 288 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 289 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 290 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 291 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 292 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 293 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 294 "data//maps/FortreeCliffs/scripts.pory"
	end
# 295 "data//maps/FortreeCliffs/scripts.pory"

# 296 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 297 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 298 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 299 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 300 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 301 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 302 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 303 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 304 "data//maps/FortreeCliffs/scripts.pory"
	end
# 305 "data//maps/FortreeCliffs/scripts.pory"

# 306 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 307 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 308 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 309 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 310 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 311 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 312 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 313 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 314 "data//maps/FortreeCliffs/scripts.pory"
	end
# 315 "data//maps/FortreeCliffs/scripts.pory"

# 316 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 317 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 318 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 319 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 320 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                        @ animate player landing
# 321 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 322 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 323 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 324 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 325 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 326 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 327 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 328 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 329 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 330 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1   
# 331 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP     
# 332 "data//maps/FortreeCliffs/scripts.pory"
	release
# 333 "data//maps/FortreeCliffs/scripts.pory"
	end
# 334 "data//maps/FortreeCliffs/scripts.pory"

# 335 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 336 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 337 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 338 "data//maps/FortreeCliffs/scripts.pory"
	return
# 339 "data//maps/FortreeCliffs/scripts.pory"

# 340 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 341 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 342 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 343 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 344 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_NORMAL
# 345 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 346 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 347 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 348 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 349 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 350 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 351 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 352 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 353 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 354 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 355 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 356 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 357 "data//maps/FortreeCliffs/scripts.pory"
	return
# 358 "data//maps/FortreeCliffs/scripts.pory"

# 359 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 360 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 361 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 362 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 363 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 364 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 365 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 366 "data//maps/FortreeCliffs/scripts.pory"
	end
# 367 "data//maps/FortreeCliffs/scripts.pory"

# 368 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 369 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 370 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 371 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 372 "data//maps/FortreeCliffs/scripts.pory"
	return
# 373 "data//maps/FortreeCliffs/scripts.pory"

# 374 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 375 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 376 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 377 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 378 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 379 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 380 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 381 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 382 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 383 "data//maps/FortreeCliffs/scripts.pory"
	return
# 384 "data//maps/FortreeCliffs/scripts.pory"

# 385 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 386 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 387 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 388 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 389 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 390 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 391 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 392 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 393 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 394 "data//maps/FortreeCliffs/scripts.pory"
	return
# 395 "data//maps/FortreeCliffs/scripts.pory"

# 396 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 397 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 398 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 399 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 400 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 401 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 402 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 403 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 404 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 405 "data//maps/FortreeCliffs/scripts.pory"
	return
# 406 "data//maps/FortreeCliffs/scripts.pory"

# 407 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 408 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 409 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 410 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 411 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 412 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 413 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 414 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 415 "data//maps/FortreeCliffs/scripts.pory"
	release
# 416 "data//maps/FortreeCliffs/scripts.pory"
	end
# 417 "data//maps/FortreeCliffs/scripts.pory"

# 418 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 419 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 420 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 421 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 422 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 423 "data//maps/FortreeCliffs/scripts.pory"
	return
# 424 "data//maps/FortreeCliffs/scripts.pory"

# 425 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 426 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 427 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 428 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 429 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 430 "data//maps/FortreeCliffs/scripts.pory"
	release
# 431 "data//maps/FortreeCliffs/scripts.pory"
	end
# 432 "data//maps/FortreeCliffs/scripts.pory"

# 433 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 434 "data//maps/FortreeCliffs/scripts.pory"
	return
# 435 "data//maps/FortreeCliffs/scripts.pory"

# 436 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 437 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 438 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 439 "data//maps/FortreeCliffs/scripts.pory"
	end
# 440 "data//maps/FortreeCliffs/scripts.pory"

# 441 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 442 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 443 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 444 "data//maps/FortreeCliffs/scripts.pory"
	end
# 445 "data//maps/FortreeCliffs/scripts.pory"

# 446 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 447 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 448 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 449 "data//maps/FortreeCliffs/scripts.pory"
	end
# 450 "data//maps/FortreeCliffs/scripts.pory"

# 451 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 452 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 453 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 454 "data//maps/FortreeCliffs/scripts.pory"
	end
# 455 "data//maps/FortreeCliffs/scripts.pory"

# 456 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 457 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 458 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 459 "data//maps/FortreeCliffs/scripts.pory"
	end
# 460 "data//maps/FortreeCliffs/scripts.pory"

# 461 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 462 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 463 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 464 "data//maps/FortreeCliffs/scripts.pory"
	end
# 465 "data//maps/FortreeCliffs/scripts.pory"

# 466 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 467 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 468 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 469 "data//maps/FortreeCliffs/scripts.pory"
	end
# 470 "data//maps/FortreeCliffs/scripts.pory"

# 471 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 472 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 473 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 474 "data//maps/FortreeCliffs/scripts.pory"
	end
# 475 "data//maps/FortreeCliffs/scripts.pory"

# 476 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 477 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 478 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 479 "data//maps/FortreeCliffs/scripts.pory"
	end
# 480 "data//maps/FortreeCliffs/scripts.pory"

# 481 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 482 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 483 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 484 "data//maps/FortreeCliffs/scripts.pory"
	end
# 485 "data//maps/FortreeCliffs/scripts.pory"

# 486 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 487 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 488 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 489 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 490 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 491 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 492 "data//maps/FortreeCliffs/scripts.pory"

# 493 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 494 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 495 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 496 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 497 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 498 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 499 "data//maps/FortreeCliffs/scripts.pory"

# 500 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 501 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 502 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 503 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 504 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 505 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 506 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 507 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 508 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 509 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 510 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 511 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 512 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 513 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 514 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 515 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 516 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 517 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 518 "data//maps/FortreeCliffs/scripts.pory"

# 519 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 520 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 521 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 522 "data//maps/FortreeCliffs/scripts.pory"

# 523 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 524 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 525 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 526 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 527 "data//maps/FortreeCliffs/scripts.pory"

# 528 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 529 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 530 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 531 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 532 "data//maps/FortreeCliffs/scripts.pory"

# 533 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 534 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 535 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 536 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 537 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 538 "data//maps/FortreeCliffs/scripts.pory"

# 539 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 540 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 541 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 542 "data//maps/FortreeCliffs/scripts.pory"

# 543 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 544 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 545 "data//maps/FortreeCliffs/scripts.pory"

# 546 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 547 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 548 "data//maps/FortreeCliffs/scripts.pory"

# 549 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 550 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 551 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 552 "data//maps/FortreeCliffs/scripts.pory"

# 553 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryAcceptedBerry:
# 554 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY accepted the {STR_VAR_1}.$"
# 555 "data//maps/FortreeCliffs/scripts.pory"

# 556 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 557 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 558 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 559 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 560 "data//maps/FortreeCliffs/scripts.pory"

# 561 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 562 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 567 "data//maps/FortreeCliffs/scripts.pory"

# 568 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona1:
# 569 "data//maps/FortreeCliffs/scripts.pory"
	.string "… … … … … …$"
# 570 "data//maps/FortreeCliffs/scripts.pory"

# 571 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona2:
# 572 "data//maps/FortreeCliffs/scripts.pory"
	.string "I train atop these cliffs\n"
# 573 "data//maps/FortreeCliffs/scripts.pory"
	.string "because of my devotion to reaching\l"
# 574 "data//maps/FortreeCliffs/scripts.pory"
	.string "the greatest heights.\p"
# 575 "data//maps/FortreeCliffs/scripts.pory"
	.string "Very few TRAINERS ever soar so high\n"
# 576 "data//maps/FortreeCliffs/scripts.pory"
	.string "above FORTREE's thick forests and\l"
# 577 "data//maps/FortreeCliffs/scripts.pory"
	.string "steep cliffs.$"
# 578 "data//maps/FortreeCliffs/scripts.pory"

# 579 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3:
# 580 "data//maps/FortreeCliffs/scripts.pory"
	.string "Take this and meet me at my gym if you\n"
# 581 "data//maps/FortreeCliffs/scripts.pory"
	.string "think you're up to the challenge.$"
# 582 "data//maps/FortreeCliffs/scripts.pory"

# 583 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3a:
# 584 "data//maps/FortreeCliffs/scripts.pory"
	.string "If you made it here, then perhaps you\n" 
# 585 "data//maps/FortreeCliffs/scripts.pory"
	.string "are ready to fly.$"
# 586 "data//maps/FortreeCliffs/scripts.pory"

# 587 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona4:
# 588 "data//maps/FortreeCliffs/scripts.pory"
	.string "Until we meet again, {PLAYER}.$"
# 589 "data//maps/FortreeCliffs/scripts.pory"

# 590 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 591 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 592 "data//maps/FortreeCliffs/scripts.pory"

# 593 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 594 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 595 "data//maps/FortreeCliffs/scripts.pory"

# 596 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 597 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 598 "data//maps/FortreeCliffs/scripts.pory"

# 599 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 600 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 601 "data//maps/FortreeCliffs/scripts.pory"

# 602 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 603 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 604 "data//maps/FortreeCliffs/scripts.pory"

# 605 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 606 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 607 "data//maps/FortreeCliffs/scripts.pory"

# 608 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 609 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 610 "data//maps/FortreeCliffs/scripts.pory"

# 611 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 612 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 613 "data//maps/FortreeCliffs/scripts.pory"

# 614 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 615 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 616 "data//maps/FortreeCliffs/scripts.pory"

# 617 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 618 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 619 "data//maps/FortreeCliffs/scripts.pory"

# 620 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 621 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 622 "data//maps/FortreeCliffs/scripts.pory"

# 623 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 624 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 625 "data//maps/FortreeCliffs/scripts.pory"

# 626 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 627 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 628 "data//maps/FortreeCliffs/scripts.pory"

# 629 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 630 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 631 "data//maps/FortreeCliffs/scripts.pory"

# 632 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 633 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 634 "data//maps/FortreeCliffs/scripts.pory"

# 635 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 636 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 637 "data//maps/FortreeCliffs/scripts.pory"

# 638 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 639 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 640 "data//maps/FortreeCliffs/scripts.pory"

# 641 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 642 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 643 "data//maps/FortreeCliffs/scripts.pory"

# 644 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 645 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 646 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 647 "data//maps/FortreeCliffs/scripts.pory"

# 648 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 649 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 650 "data//maps/FortreeCliffs/scripts.pory"

# 651 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 652 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 653 "data//maps/FortreeCliffs/scripts.pory"

# 654 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 655 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 656 "data//maps/FortreeCliffs/scripts.pory"

# 657 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 658 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 659 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 660 "data//maps/FortreeCliffs/scripts.pory"

# 661 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 662 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 663 "data//maps/FortreeCliffs/scripts.pory"

# 664 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 665 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 666 "data//maps/FortreeCliffs/scripts.pory"

# 667 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 668 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 669 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 670 "data//maps/FortreeCliffs/scripts.pory"

# 671 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 672 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 673 "data//maps/FortreeCliffs/scripts.pory"

# 674 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 675 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 676 "data//maps/FortreeCliffs/scripts.pory"

# 677 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 678 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 679 "data//maps/FortreeCliffs/scripts.pory"

# 680 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 681 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?\p"
# 682 "data//maps/FortreeCliffs/scripts.pory"
	.string "She is friends with powerful\n"
# 683 "data//maps/FortreeCliffs/scripts.pory"
	.string "BIRD POKéMON!$"
