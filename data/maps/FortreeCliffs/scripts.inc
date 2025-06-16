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
 	map_script_2 VAR_TEMP_0, 0, FortreeCliffs_EventScript_SetWeatherOnWarp
# 17 "data//maps/FortreeCliffs/scripts.pory"
 	.2byte 0
# 18 "data//maps/FortreeCliffs/scripts.pory"

# 19 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 20 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 21 "data//maps/FortreeCliffs/scripts.pory"
	end
# 22 "data//maps/FortreeCliffs/scripts.pory"

# 23 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetWeatherOnWarp::
# 24 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 25 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 38, FortreeCliffs_EventScript_SetThunderstorm
# 26 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 88, FortreeCliffs_EventScript_SetFog
# 27 "data//maps/FortreeCliffs/scripts.pory"
	goto FortreeCliffs_EventScript_TrySetSun
# 28 "data//maps/FortreeCliffs/scripts.pory"
	return
# 29 "data//maps/FortreeCliffs/scripts.pory"

# 30 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 31 "data//maps/FortreeCliffs/scripts.pory"
	@ call FortreeCliffs_EventScript_ResetWildMons
# 32 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryOnTransitionSwitch
# 33 "data//maps/FortreeCliffs/scripts.pory"
	end
# 34 "data//maps/FortreeCliffs/scripts.pory"

# 35 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToDaytime::
# 36 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 37 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 38 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_SetSunElevationCheck
# 39 "data//maps/FortreeCliffs/scripts.pory"
	return
# 40 "data//maps/FortreeCliffs/scripts.pory"

# 41 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToNighttime::
# 42 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 43 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 44 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_ClearSunElevationCheck
# 45 "data//maps/FortreeCliffs/scripts.pory"
	return
# 46 "data//maps/FortreeCliffs/scripts.pory"

# 47 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSunElevationCheck::
# 48 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_SetSun
# 49 "data//maps/FortreeCliffs/scripts.pory"
	return
# 50 "data//maps/FortreeCliffs/scripts.pory"

# 51 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSunElevationCheck::
# 52 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_ClearSun
# 53 "data//maps/FortreeCliffs/scripts.pory"
	return
# 54 "data//maps/FortreeCliffs/scripts.pory"

# 55 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 56 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 57 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 58 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 59 "data//maps/FortreeCliffs/scripts.pory"
	return
# 60 "data//maps/FortreeCliffs/scripts.pory"

# 61 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryOnTransitionSwitch::
# 62 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                 @ place objects at correct spot when map loads
# 63 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_PlaceBraviaryAtNest1
# 64 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_PlaceBraviaryAtNest2                                             
# 65 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_PlaceBraviaryAtNest3
# 66 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_PlaceBraviaryAtNest4
# 67 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_PlaceBraviaryAtNest5                                           
# 68 "data//maps/FortreeCliffs/scripts.pory"
	return
# 69 "data//maps/FortreeCliffs/scripts.pory"

# 70 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TrySetSun::
# 71 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_TIME_OF_DAY
# 72 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_ClearSun
# 73 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_ClearSun
# 74 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_SetSun
# 75 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_SetSun
# 76 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_ClearSun
# 77 "data//maps/FortreeCliffs/scripts.pory"
	return
# 78 "data//maps/FortreeCliffs/scripts.pory"

# 79 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSun::
# 80 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 81 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 82 "data//maps/FortreeCliffs/scripts.pory"
	return
# 83 "data//maps/FortreeCliffs/scripts.pory"

# 84 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSun::
# 85 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_NONE
# 86 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 87 "data//maps/FortreeCliffs/scripts.pory"
	return
# 88 "data//maps/FortreeCliffs/scripts.pory"

# 89 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetThunderstorm::
# 90 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
# 91 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 92 "data//maps/FortreeCliffs/scripts.pory"
	return
# 93 "data//maps/FortreeCliffs/scripts.pory"

# 94 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetFog::
# 95 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 96 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 97 "data//maps/FortreeCliffs/scripts.pory"
	return
# 98 "data//maps/FortreeCliffs/scripts.pory"

# 99 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Winona::
# 100 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 101 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 102 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona1, MSGBOX_DEFAULT
# 103 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 104 "data//maps/FortreeCliffs/scripts.pory"
	delay 30
# 105 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona2, MSGBOX_DEFAULT
# 106 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 107 "data//maps/FortreeCliffs/scripts.pory"
	delay 5
# 108 "data//maps/FortreeCliffs/scripts.pory"
	turnobject LOCALID_FORTREE_CLIFFS_WINONA, DIR_WEST
# 109 "data//maps/FortreeCliffs/scripts.pory"
	delay 60
# 110 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3a, MSGBOX_DEFAULT
# 111 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 112 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 113 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_WINONA, Common_Movement_FacePlayer
# 114 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 115 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3, MSGBOX_DEFAULT
# 116 "data//maps/FortreeCliffs/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 117 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona4, MSGBOX_DEFAULT
# 118 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 119 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1
# 120 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 121 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 122 "data//maps/FortreeCliffs/scripts.pory"
	removeobject LOCALID_FORTREE_CLIFFS_WINONA
# 123 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 124 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 125 "data//maps/FortreeCliffs/scripts.pory"
	release
# 126 "data//maps/FortreeCliffs/scripts.pory"
	end
# 127 "data//maps/FortreeCliffs/scripts.pory"

# 128 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 129 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 130 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 131 "data//maps/FortreeCliffs/scripts.pory"
	return
# 132 "data//maps/FortreeCliffs/scripts.pory"

# 133 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 134 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 135 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 136 "data//maps/FortreeCliffs/scripts.pory"
	return
# 137 "data//maps/FortreeCliffs/scripts.pory"

# 138 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 139 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 140 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 141 "data//maps/FortreeCliffs/scripts.pory"
	return
# 142 "data//maps/FortreeCliffs/scripts.pory"

# 143 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 144 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 145 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 146 "data//maps/FortreeCliffs/scripts.pory"
	return
# 147 "data//maps/FortreeCliffs/scripts.pory"

# 148 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 149 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 150 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 151 "data//maps/FortreeCliffs/scripts.pory"
	return
# 152 "data//maps/FortreeCliffs/scripts.pory"

# 153 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 154 "data//maps/FortreeCliffs/scripts.pory"
	end
# 155 "data//maps/FortreeCliffs/scripts.pory"

# 156 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 157 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 158 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 159 "data//maps/FortreeCliffs/scripts.pory"
	release
# 160 "data//maps/FortreeCliffs/scripts.pory"
	end
# 161 "data//maps/FortreeCliffs/scripts.pory"

# 162 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 163 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 164 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 165 "data//maps/FortreeCliffs/scripts.pory"
	hidefollower 0
# 166 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 167 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 168 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 169 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 170 "data//maps/FortreeCliffs/scripts.pory"
	
# 171 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 172 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 173 "data//maps/FortreeCliffs/scripts.pory"

# 174 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 175 "data//maps/FortreeCliffs/scripts.pory"

# 176 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 177 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 178 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 179 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 180 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 181 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 182 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 183 "data//maps/FortreeCliffs/scripts.pory"
	release
# 184 "data//maps/FortreeCliffs/scripts.pory"
	end
# 185 "data//maps/FortreeCliffs/scripts.pory"

# 186 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 187 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 188 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 189 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 190 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 191 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 192 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 193 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 194 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 195 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 196 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 197 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 198 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 199 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 200 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 201 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 202 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 203 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 204 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 205 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 206 "data//maps/FortreeCliffs/scripts.pory"
	return
# 207 "data//maps/FortreeCliffs/scripts.pory"

# 208 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 209 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 210 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 211 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 212 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 213 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 214 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 215 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 216 "data//maps/FortreeCliffs/scripts.pory"
	return
# 217 "data//maps/FortreeCliffs/scripts.pory"

# 218 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 219 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 220 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 221 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 222 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 223 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 224 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 225 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 226 "data//maps/FortreeCliffs/scripts.pory"
	return
# 227 "data//maps/FortreeCliffs/scripts.pory"

# 228 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 229 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 230 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 231 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 232 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 233 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 234 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 235 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 236 "data//maps/FortreeCliffs/scripts.pory"
	return
# 237 "data//maps/FortreeCliffs/scripts.pory"

# 238 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 239 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 240 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 241 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 242 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 243 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 244 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 245 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 246 "data//maps/FortreeCliffs/scripts.pory"
	return
# 247 "data//maps/FortreeCliffs/scripts.pory"

# 248 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 249 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 250 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 251 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 252 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 253 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 254 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 255 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 256 "data//maps/FortreeCliffs/scripts.pory"
	return
# 257 "data//maps/FortreeCliffs/scripts.pory"

# 258 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 259 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 260 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 261 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 262 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 263 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 264 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 265 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 266 "data//maps/FortreeCliffs/scripts.pory"
	return
# 267 "data//maps/FortreeCliffs/scripts.pory"

# 268 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 269 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 270 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 271 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 272 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 273 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 274 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 275 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 276 "data//maps/FortreeCliffs/scripts.pory"
	return
# 277 "data//maps/FortreeCliffs/scripts.pory"

# 278 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 279 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 280 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 281 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 282 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 283 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 284 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 285 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 286 "data//maps/FortreeCliffs/scripts.pory"
	end
# 287 "data//maps/FortreeCliffs/scripts.pory"

# 288 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 289 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 290 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 291 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 292 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 293 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 294 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 295 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 296 "data//maps/FortreeCliffs/scripts.pory"
	end
# 297 "data//maps/FortreeCliffs/scripts.pory"

# 298 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 299 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 300 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 301 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 302 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 303 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 304 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 305 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 306 "data//maps/FortreeCliffs/scripts.pory"
	end
# 307 "data//maps/FortreeCliffs/scripts.pory"

# 308 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 309 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 310 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 311 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 312 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 313 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 314 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 315 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 316 "data//maps/FortreeCliffs/scripts.pory"
	end
# 317 "data//maps/FortreeCliffs/scripts.pory"

# 318 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 319 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 320 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 321 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 322 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 323 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 324 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 325 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 326 "data//maps/FortreeCliffs/scripts.pory"
	end
# 327 "data//maps/FortreeCliffs/scripts.pory"

# 328 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 329 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 330 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 331 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 332 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                        @ animate player landing
# 333 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 334 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 335 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 336 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 337 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 338 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 339 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 340 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 341 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 342 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1   
# 343 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP     
# 344 "data//maps/FortreeCliffs/scripts.pory"
	release
# 345 "data//maps/FortreeCliffs/scripts.pory"
	end
# 346 "data//maps/FortreeCliffs/scripts.pory"

# 347 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 348 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 349 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 350 "data//maps/FortreeCliffs/scripts.pory"
	return
# 351 "data//maps/FortreeCliffs/scripts.pory"

# 352 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 353 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 354 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 355 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 356 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_NORMAL
# 357 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 358 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 359 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 360 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 361 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 362 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 363 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 364 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 365 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 366 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 367 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 368 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 369 "data//maps/FortreeCliffs/scripts.pory"
	return
# 370 "data//maps/FortreeCliffs/scripts.pory"

# 371 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 372 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 373 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 374 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 375 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 376 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 377 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 378 "data//maps/FortreeCliffs/scripts.pory"
	end
# 379 "data//maps/FortreeCliffs/scripts.pory"

# 380 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 381 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 382 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 383 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 384 "data//maps/FortreeCliffs/scripts.pory"
	return
# 385 "data//maps/FortreeCliffs/scripts.pory"

# 386 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 387 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 388 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 389 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 390 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 391 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 392 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 393 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 394 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 395 "data//maps/FortreeCliffs/scripts.pory"
	return
# 396 "data//maps/FortreeCliffs/scripts.pory"

# 397 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 398 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 399 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 400 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 401 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 402 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 403 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 404 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 405 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 406 "data//maps/FortreeCliffs/scripts.pory"
	return
# 407 "data//maps/FortreeCliffs/scripts.pory"

# 408 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 409 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 410 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 411 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 412 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 413 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 414 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 415 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 416 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 417 "data//maps/FortreeCliffs/scripts.pory"
	return
# 418 "data//maps/FortreeCliffs/scripts.pory"

# 419 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 420 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 421 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 422 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 423 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 424 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 425 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 426 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 427 "data//maps/FortreeCliffs/scripts.pory"
	release
# 428 "data//maps/FortreeCliffs/scripts.pory"
	end
# 429 "data//maps/FortreeCliffs/scripts.pory"

# 430 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 431 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 432 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 433 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 434 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 435 "data//maps/FortreeCliffs/scripts.pory"
	return
# 436 "data//maps/FortreeCliffs/scripts.pory"

# 437 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 438 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 439 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 440 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 441 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 442 "data//maps/FortreeCliffs/scripts.pory"
	release
# 443 "data//maps/FortreeCliffs/scripts.pory"
	end
# 444 "data//maps/FortreeCliffs/scripts.pory"

# 445 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 446 "data//maps/FortreeCliffs/scripts.pory"
	return
# 447 "data//maps/FortreeCliffs/scripts.pory"

# 448 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 449 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 450 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 451 "data//maps/FortreeCliffs/scripts.pory"
	end
# 452 "data//maps/FortreeCliffs/scripts.pory"

# 453 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 454 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 455 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 456 "data//maps/FortreeCliffs/scripts.pory"
	end
# 457 "data//maps/FortreeCliffs/scripts.pory"

# 458 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 459 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 460 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 461 "data//maps/FortreeCliffs/scripts.pory"
	end
# 462 "data//maps/FortreeCliffs/scripts.pory"

# 463 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 464 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 465 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 466 "data//maps/FortreeCliffs/scripts.pory"
	end
# 467 "data//maps/FortreeCliffs/scripts.pory"

# 468 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 469 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 470 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 471 "data//maps/FortreeCliffs/scripts.pory"
	end
# 472 "data//maps/FortreeCliffs/scripts.pory"

# 473 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 474 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 475 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 476 "data//maps/FortreeCliffs/scripts.pory"
	end
# 477 "data//maps/FortreeCliffs/scripts.pory"

# 478 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 479 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 480 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 481 "data//maps/FortreeCliffs/scripts.pory"
	end
# 482 "data//maps/FortreeCliffs/scripts.pory"

# 483 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 484 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 485 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 486 "data//maps/FortreeCliffs/scripts.pory"
	end
# 487 "data//maps/FortreeCliffs/scripts.pory"

# 488 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 489 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 490 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 491 "data//maps/FortreeCliffs/scripts.pory"
	end
# 492 "data//maps/FortreeCliffs/scripts.pory"

# 493 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 494 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 495 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 496 "data//maps/FortreeCliffs/scripts.pory"
	end
# 497 "data//maps/FortreeCliffs/scripts.pory"

# 498 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 499 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 500 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 501 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 502 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 503 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 504 "data//maps/FortreeCliffs/scripts.pory"

# 505 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 506 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 507 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 508 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 509 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 510 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 511 "data//maps/FortreeCliffs/scripts.pory"

# 512 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 513 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 514 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 515 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 516 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 517 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 518 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 519 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 520 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 521 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 522 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 523 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 524 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 525 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 526 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 527 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 528 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 529 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 530 "data//maps/FortreeCliffs/scripts.pory"

# 531 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 532 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 533 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 534 "data//maps/FortreeCliffs/scripts.pory"

# 535 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 536 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 537 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 538 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 539 "data//maps/FortreeCliffs/scripts.pory"

# 540 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 541 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 542 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 543 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 544 "data//maps/FortreeCliffs/scripts.pory"

# 545 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 546 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 547 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 548 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 549 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 550 "data//maps/FortreeCliffs/scripts.pory"

# 551 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 552 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 553 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 554 "data//maps/FortreeCliffs/scripts.pory"

# 555 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 556 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 557 "data//maps/FortreeCliffs/scripts.pory"

# 558 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 559 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 560 "data//maps/FortreeCliffs/scripts.pory"

# 561 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 562 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryAcceptedBerry:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY accepted the {STR_VAR_1}.$"
# 567 "data//maps/FortreeCliffs/scripts.pory"

# 568 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 569 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 570 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 571 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 572 "data//maps/FortreeCliffs/scripts.pory"

# 573 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 574 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 575 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 576 "data//maps/FortreeCliffs/scripts.pory"

# 577 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 578 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 579 "data//maps/FortreeCliffs/scripts.pory"

# 580 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona1:
# 581 "data//maps/FortreeCliffs/scripts.pory"
	.string "… … … … … …$"
# 582 "data//maps/FortreeCliffs/scripts.pory"

# 583 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona2:
# 584 "data//maps/FortreeCliffs/scripts.pory"
	.string "I train atop these cliffs\n"
# 585 "data//maps/FortreeCliffs/scripts.pory"
	.string "because of my devotion to reaching\l"
# 586 "data//maps/FortreeCliffs/scripts.pory"
	.string "the greatest heights.\p"
# 587 "data//maps/FortreeCliffs/scripts.pory"
	.string "Very few TRAINERS ever soar so high\n"
# 588 "data//maps/FortreeCliffs/scripts.pory"
	.string "above FORTREE's thick forests and\l"
# 589 "data//maps/FortreeCliffs/scripts.pory"
	.string "steep cliffs.$"
# 590 "data//maps/FortreeCliffs/scripts.pory"

# 591 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3:
# 592 "data//maps/FortreeCliffs/scripts.pory"
	.string "Take this and meet me at my gym if you\n"
# 593 "data//maps/FortreeCliffs/scripts.pory"
	.string "think you're up to the challenge.$"
# 594 "data//maps/FortreeCliffs/scripts.pory"

# 595 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3a:
# 596 "data//maps/FortreeCliffs/scripts.pory"
	.string "If you made it here, then perhaps you\n" 
# 597 "data//maps/FortreeCliffs/scripts.pory"
	.string "are ready to fly.$"
# 598 "data//maps/FortreeCliffs/scripts.pory"

# 599 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona4:
# 600 "data//maps/FortreeCliffs/scripts.pory"
	.string "Until we meet again, {PLAYER}.$"
# 601 "data//maps/FortreeCliffs/scripts.pory"

# 602 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 603 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 604 "data//maps/FortreeCliffs/scripts.pory"

# 605 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 606 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 607 "data//maps/FortreeCliffs/scripts.pory"

# 608 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 609 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 610 "data//maps/FortreeCliffs/scripts.pory"

# 611 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 612 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 613 "data//maps/FortreeCliffs/scripts.pory"

# 614 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 615 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 616 "data//maps/FortreeCliffs/scripts.pory"

# 617 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 618 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 619 "data//maps/FortreeCliffs/scripts.pory"

# 620 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 621 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 622 "data//maps/FortreeCliffs/scripts.pory"

# 623 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 624 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 625 "data//maps/FortreeCliffs/scripts.pory"

# 626 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 627 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 628 "data//maps/FortreeCliffs/scripts.pory"

# 629 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 630 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 631 "data//maps/FortreeCliffs/scripts.pory"

# 632 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 633 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 634 "data//maps/FortreeCliffs/scripts.pory"

# 635 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 636 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 637 "data//maps/FortreeCliffs/scripts.pory"

# 638 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 639 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 640 "data//maps/FortreeCliffs/scripts.pory"

# 641 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 642 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 643 "data//maps/FortreeCliffs/scripts.pory"

# 644 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 645 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 646 "data//maps/FortreeCliffs/scripts.pory"

# 647 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 648 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 649 "data//maps/FortreeCliffs/scripts.pory"

# 650 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 651 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 652 "data//maps/FortreeCliffs/scripts.pory"

# 653 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 654 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 655 "data//maps/FortreeCliffs/scripts.pory"

# 656 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 657 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 658 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 659 "data//maps/FortreeCliffs/scripts.pory"

# 660 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 661 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 662 "data//maps/FortreeCliffs/scripts.pory"

# 663 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 664 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 665 "data//maps/FortreeCliffs/scripts.pory"

# 666 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 667 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 668 "data//maps/FortreeCliffs/scripts.pory"

# 669 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 670 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 671 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 672 "data//maps/FortreeCliffs/scripts.pory"

# 673 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 674 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 675 "data//maps/FortreeCliffs/scripts.pory"

# 676 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 677 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 678 "data//maps/FortreeCliffs/scripts.pory"

# 679 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 680 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 681 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 682 "data//maps/FortreeCliffs/scripts.pory"

# 683 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 684 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 685 "data//maps/FortreeCliffs/scripts.pory"

# 686 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 687 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 688 "data//maps/FortreeCliffs/scripts.pory"

# 689 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 690 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 691 "data//maps/FortreeCliffs/scripts.pory"

# 692 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 693 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?\p"
# 694 "data//maps/FortreeCliffs/scripts.pory"
	.string "She is friends with powerful\n"
# 695 "data//maps/FortreeCliffs/scripts.pory"
	.string "BIRD POKéMON!$"
