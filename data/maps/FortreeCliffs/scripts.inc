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
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 33 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_TEMP_F, 88, FortreeCliffs_EventScript_SetFog
# 34 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryOnTransitionSwitch
# 35 "data//maps/FortreeCliffs/scripts.pory"
	end
# 36 "data//maps/FortreeCliffs/scripts.pory"

# 37 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToDaytime::
# 38 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 39 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 40 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_SetSunElevationCheck
# 41 "data//maps/FortreeCliffs/scripts.pory"
	return
# 42 "data//maps/FortreeCliffs/scripts.pory"

# 43 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SwitchToNighttime::
# 44 "data//maps/FortreeCliffs/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 45 "data//maps/FortreeCliffs/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 46 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_le VAR_TEMP_F, 87, FortreeCliffs_EventScript_ClearSunElevationCheck
# 47 "data//maps/FortreeCliffs/scripts.pory"
	return
# 48 "data//maps/FortreeCliffs/scripts.pory"

# 49 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSunElevationCheck::
# 50 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_SetSun
# 51 "data//maps/FortreeCliffs/scripts.pory"
	return
# 52 "data//maps/FortreeCliffs/scripts.pory"

# 53 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSunElevationCheck::
# 54 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ge VAR_TEMP_F, 40, FortreeCliffs_EventScript_ClearSun
# 55 "data//maps/FortreeCliffs/scripts.pory"
	return
# 56 "data//maps/FortreeCliffs/scripts.pory"

# 57 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 58 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 59 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 60 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 61 "data//maps/FortreeCliffs/scripts.pory"
	return
# 62 "data//maps/FortreeCliffs/scripts.pory"

# 63 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryOnTransitionSwitch::
# 64 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                 @ place objects at correct spot when map loads
# 65 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_PlaceBraviaryAtNest1
# 66 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_PlaceBraviaryAtNest2                                             
# 67 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_PlaceBraviaryAtNest3
# 68 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_PlaceBraviaryAtNest4
# 69 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_PlaceBraviaryAtNest5                                           
# 70 "data//maps/FortreeCliffs/scripts.pory"
	return
# 71 "data//maps/FortreeCliffs/scripts.pory"

# 72 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TrySetSun::
# 73 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_TIME_OF_DAY
# 74 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_ClearSun
# 75 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_ClearSun
# 76 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_SetSun
# 77 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_SetSun
# 78 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_TIME_OF_DAY, 4, FortreeCliffs_EventScript_ClearSun
# 79 "data//maps/FortreeCliffs/scripts.pory"
	return
# 80 "data//maps/FortreeCliffs/scripts.pory"

# 81 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetSun::
# 82 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 83 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 84 "data//maps/FortreeCliffs/scripts.pory"
	return
# 85 "data//maps/FortreeCliffs/scripts.pory"

# 86 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ClearSun::
# 87 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_NONE
# 88 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 89 "data//maps/FortreeCliffs/scripts.pory"
	return
# 90 "data//maps/FortreeCliffs/scripts.pory"

# 91 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetThunderstorm::
# 92 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_RAIN_THUNDERSTORM
# 93 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 94 "data//maps/FortreeCliffs/scripts.pory"
	return
# 95 "data//maps/FortreeCliffs/scripts.pory"

# 96 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_SetFog::
# 97 "data//maps/FortreeCliffs/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 98 "data//maps/FortreeCliffs/scripts.pory"
	doweather
# 99 "data//maps/FortreeCliffs/scripts.pory"
	return
# 100 "data//maps/FortreeCliffs/scripts.pory"

# 101 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Winona::
# 102 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 103 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 104 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona1, MSGBOX_DEFAULT
# 105 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 106 "data//maps/FortreeCliffs/scripts.pory"
	delay 30
# 107 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona2, MSGBOX_DEFAULT
# 108 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 109 "data//maps/FortreeCliffs/scripts.pory"
	delay 5
# 110 "data//maps/FortreeCliffs/scripts.pory"
	turnobject LOCALID_FORTREE_CLIFFS_WINONA, DIR_WEST
# 111 "data//maps/FortreeCliffs/scripts.pory"
	delay 60
# 112 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3a, MSGBOX_DEFAULT
# 113 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 114 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 115 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_WINONA, Common_Movement_FacePlayer
# 116 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 117 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3, MSGBOX_DEFAULT
# 118 "data//maps/FortreeCliffs/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 119 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona4, MSGBOX_DEFAULT
# 120 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 121 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1
# 122 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 123 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 124 "data//maps/FortreeCliffs/scripts.pory"
	removeobject LOCALID_FORTREE_CLIFFS_WINONA
# 125 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 126 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 127 "data//maps/FortreeCliffs/scripts.pory"
	release
# 128 "data//maps/FortreeCliffs/scripts.pory"
	end
# 129 "data//maps/FortreeCliffs/scripts.pory"

# 130 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 131 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 132 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 133 "data//maps/FortreeCliffs/scripts.pory"
	return
# 134 "data//maps/FortreeCliffs/scripts.pory"

# 135 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 136 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 137 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 138 "data//maps/FortreeCliffs/scripts.pory"
	return
# 139 "data//maps/FortreeCliffs/scripts.pory"

# 140 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 141 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 142 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 143 "data//maps/FortreeCliffs/scripts.pory"
	return
# 144 "data//maps/FortreeCliffs/scripts.pory"

# 145 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 146 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 147 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 148 "data//maps/FortreeCliffs/scripts.pory"
	return
# 149 "data//maps/FortreeCliffs/scripts.pory"

# 150 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 151 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 152 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 153 "data//maps/FortreeCliffs/scripts.pory"
	return
# 154 "data//maps/FortreeCliffs/scripts.pory"

# 155 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 156 "data//maps/FortreeCliffs/scripts.pory"
	end
# 157 "data//maps/FortreeCliffs/scripts.pory"

# 158 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 159 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 160 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 161 "data//maps/FortreeCliffs/scripts.pory"
	release
# 162 "data//maps/FortreeCliffs/scripts.pory"
	end
# 163 "data//maps/FortreeCliffs/scripts.pory"

# 164 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 165 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 166 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 167 "data//maps/FortreeCliffs/scripts.pory"
	hidefollower 0
# 168 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 169 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 170 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 171 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 172 "data//maps/FortreeCliffs/scripts.pory"
	
# 173 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 174 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 175 "data//maps/FortreeCliffs/scripts.pory"

# 176 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 177 "data//maps/FortreeCliffs/scripts.pory"

# 178 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 179 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 180 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 181 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 182 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 183 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 184 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 185 "data//maps/FortreeCliffs/scripts.pory"
	release
# 186 "data//maps/FortreeCliffs/scripts.pory"
	end
# 187 "data//maps/FortreeCliffs/scripts.pory"

# 188 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 189 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 190 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 191 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 192 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 193 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 194 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 195 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 196 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 197 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 198 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 199 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 200 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 201 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 202 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 203 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 204 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 205 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 206 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 207 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 208 "data//maps/FortreeCliffs/scripts.pory"
	return
# 209 "data//maps/FortreeCliffs/scripts.pory"

# 210 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 211 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 212 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 213 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 214 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 215 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 216 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 217 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 218 "data//maps/FortreeCliffs/scripts.pory"
	return
# 219 "data//maps/FortreeCliffs/scripts.pory"

# 220 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 221 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 222 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 223 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 224 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 225 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 226 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 227 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 228 "data//maps/FortreeCliffs/scripts.pory"
	return
# 229 "data//maps/FortreeCliffs/scripts.pory"

# 230 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 231 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 232 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 233 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 234 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 235 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 236 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 237 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 238 "data//maps/FortreeCliffs/scripts.pory"
	return
# 239 "data//maps/FortreeCliffs/scripts.pory"

# 240 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 241 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 242 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 243 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 244 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 245 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 246 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 247 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 248 "data//maps/FortreeCliffs/scripts.pory"
	return
# 249 "data//maps/FortreeCliffs/scripts.pory"

# 250 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 251 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 252 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 253 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 254 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 255 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 256 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 257 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 258 "data//maps/FortreeCliffs/scripts.pory"
	return
# 259 "data//maps/FortreeCliffs/scripts.pory"

# 260 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 261 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 262 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 263 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 264 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 265 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 266 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 267 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 268 "data//maps/FortreeCliffs/scripts.pory"
	return
# 269 "data//maps/FortreeCliffs/scripts.pory"

# 270 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 271 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 272 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 273 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 274 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 275 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 276 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 277 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 278 "data//maps/FortreeCliffs/scripts.pory"
	return
# 279 "data//maps/FortreeCliffs/scripts.pory"

# 280 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 281 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 282 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 283 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 284 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 285 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 286 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 287 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 288 "data//maps/FortreeCliffs/scripts.pory"
	end
# 289 "data//maps/FortreeCliffs/scripts.pory"

# 290 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 291 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 292 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 293 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 294 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 295 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 296 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 297 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 298 "data//maps/FortreeCliffs/scripts.pory"
	end
# 299 "data//maps/FortreeCliffs/scripts.pory"

# 300 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 301 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 302 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 303 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 304 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 305 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 306 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 307 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 308 "data//maps/FortreeCliffs/scripts.pory"
	end
# 309 "data//maps/FortreeCliffs/scripts.pory"

# 310 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 311 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 312 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 313 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 314 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 315 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 316 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 317 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 318 "data//maps/FortreeCliffs/scripts.pory"
	end
# 319 "data//maps/FortreeCliffs/scripts.pory"

# 320 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 321 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 322 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 323 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 324 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 325 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 326 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 327 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 328 "data//maps/FortreeCliffs/scripts.pory"
	end
# 329 "data//maps/FortreeCliffs/scripts.pory"

# 330 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 331 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 332 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 333 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 334 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                        @ animate player landing
# 335 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 336 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 337 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 338 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 339 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 340 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 341 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 342 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 343 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 344 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1   
# 345 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP     
# 346 "data//maps/FortreeCliffs/scripts.pory"
	release
# 347 "data//maps/FortreeCliffs/scripts.pory"
	end
# 348 "data//maps/FortreeCliffs/scripts.pory"

# 349 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 350 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 351 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 352 "data//maps/FortreeCliffs/scripts.pory"
	return
# 353 "data//maps/FortreeCliffs/scripts.pory"

# 354 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 355 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 356 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 357 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 358 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_NORMAL
# 359 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 360 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 361 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 362 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 363 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 364 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 365 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 366 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 367 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 368 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 369 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 370 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 371 "data//maps/FortreeCliffs/scripts.pory"
	return
# 372 "data//maps/FortreeCliffs/scripts.pory"

# 373 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 374 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 375 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 376 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 377 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 378 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 379 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 380 "data//maps/FortreeCliffs/scripts.pory"
	end
# 381 "data//maps/FortreeCliffs/scripts.pory"

# 382 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 383 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 384 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 385 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 386 "data//maps/FortreeCliffs/scripts.pory"
	return
# 387 "data//maps/FortreeCliffs/scripts.pory"

# 388 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 389 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 390 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 391 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 392 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 393 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 394 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 395 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 396 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 397 "data//maps/FortreeCliffs/scripts.pory"
	return
# 398 "data//maps/FortreeCliffs/scripts.pory"

# 399 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 400 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 401 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 402 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 403 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 404 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 405 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 406 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 407 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 408 "data//maps/FortreeCliffs/scripts.pory"
	return
# 409 "data//maps/FortreeCliffs/scripts.pory"

# 410 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 411 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 412 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 413 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 414 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 415 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 416 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 417 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 418 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 419 "data//maps/FortreeCliffs/scripts.pory"
	return
# 420 "data//maps/FortreeCliffs/scripts.pory"

# 421 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 422 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 423 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 424 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 425 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 426 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 427 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 428 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 429 "data//maps/FortreeCliffs/scripts.pory"
	release
# 430 "data//maps/FortreeCliffs/scripts.pory"
	end
# 431 "data//maps/FortreeCliffs/scripts.pory"

# 432 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 433 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 434 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 435 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 436 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 437 "data//maps/FortreeCliffs/scripts.pory"
	return
# 438 "data//maps/FortreeCliffs/scripts.pory"

# 439 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 440 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 441 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 442 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 443 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 444 "data//maps/FortreeCliffs/scripts.pory"
	release
# 445 "data//maps/FortreeCliffs/scripts.pory"
	end
# 446 "data//maps/FortreeCliffs/scripts.pory"

# 447 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 448 "data//maps/FortreeCliffs/scripts.pory"
	return
# 449 "data//maps/FortreeCliffs/scripts.pory"

# 450 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 451 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 452 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 453 "data//maps/FortreeCliffs/scripts.pory"
	end
# 454 "data//maps/FortreeCliffs/scripts.pory"

# 455 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 456 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 457 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 458 "data//maps/FortreeCliffs/scripts.pory"
	end
# 459 "data//maps/FortreeCliffs/scripts.pory"

# 460 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 461 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 462 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 463 "data//maps/FortreeCliffs/scripts.pory"
	end
# 464 "data//maps/FortreeCliffs/scripts.pory"

# 465 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 466 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 467 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 468 "data//maps/FortreeCliffs/scripts.pory"
	end
# 469 "data//maps/FortreeCliffs/scripts.pory"

# 470 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 471 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 472 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 473 "data//maps/FortreeCliffs/scripts.pory"
	end
# 474 "data//maps/FortreeCliffs/scripts.pory"

# 475 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 476 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 477 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 478 "data//maps/FortreeCliffs/scripts.pory"
	end
# 479 "data//maps/FortreeCliffs/scripts.pory"

# 480 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 481 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 482 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 483 "data//maps/FortreeCliffs/scripts.pory"
	end
# 484 "data//maps/FortreeCliffs/scripts.pory"

# 485 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 486 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 487 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 488 "data//maps/FortreeCliffs/scripts.pory"
	end
# 489 "data//maps/FortreeCliffs/scripts.pory"

# 490 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 491 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 492 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 493 "data//maps/FortreeCliffs/scripts.pory"
	end
# 494 "data//maps/FortreeCliffs/scripts.pory"

# 495 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 496 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 497 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 498 "data//maps/FortreeCliffs/scripts.pory"
	end
# 499 "data//maps/FortreeCliffs/scripts.pory"

# 500 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 501 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 502 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 503 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 504 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 505 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 506 "data//maps/FortreeCliffs/scripts.pory"

# 507 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 508 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 509 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 510 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 511 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 512 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 513 "data//maps/FortreeCliffs/scripts.pory"

# 514 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 515 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 516 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 517 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 518 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 519 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 520 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
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
	slide_up
# 529 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 530 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 531 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 532 "data//maps/FortreeCliffs/scripts.pory"

# 533 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 534 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 535 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 536 "data//maps/FortreeCliffs/scripts.pory"

# 537 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 538 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 539 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 540 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 541 "data//maps/FortreeCliffs/scripts.pory"

# 542 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 543 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 544 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 545 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 546 "data//maps/FortreeCliffs/scripts.pory"

# 547 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 548 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 549 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 550 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 551 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 552 "data//maps/FortreeCliffs/scripts.pory"

# 553 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 554 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 555 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 556 "data//maps/FortreeCliffs/scripts.pory"

# 557 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 558 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 559 "data//maps/FortreeCliffs/scripts.pory"

# 560 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 561 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 562 "data//maps/FortreeCliffs/scripts.pory"

# 563 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 564 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 565 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 566 "data//maps/FortreeCliffs/scripts.pory"

# 567 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryAcceptedBerry:
# 568 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY accepted the {STR_VAR_1}.$"
# 569 "data//maps/FortreeCliffs/scripts.pory"

# 570 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 571 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 572 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 573 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 574 "data//maps/FortreeCliffs/scripts.pory"

# 575 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 576 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 577 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 578 "data//maps/FortreeCliffs/scripts.pory"

# 579 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 580 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 581 "data//maps/FortreeCliffs/scripts.pory"

# 582 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona1:
# 583 "data//maps/FortreeCliffs/scripts.pory"
	.string "… … … … … …$"
# 584 "data//maps/FortreeCliffs/scripts.pory"

# 585 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona2:
# 586 "data//maps/FortreeCliffs/scripts.pory"
	.string "I train atop these cliffs\n"
# 587 "data//maps/FortreeCliffs/scripts.pory"
	.string "because of my devotion to reaching\l"
# 588 "data//maps/FortreeCliffs/scripts.pory"
	.string "the greatest heights.\p"
# 589 "data//maps/FortreeCliffs/scripts.pory"
	.string "Very few TRAINERS ever soar so high\n"
# 590 "data//maps/FortreeCliffs/scripts.pory"
	.string "above FORTREE's thick forests and\l"
# 591 "data//maps/FortreeCliffs/scripts.pory"
	.string "steep cliffs.$"
# 592 "data//maps/FortreeCliffs/scripts.pory"

# 593 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3:
# 594 "data//maps/FortreeCliffs/scripts.pory"
	.string "Take this and meet me at my gym if you\n"
# 595 "data//maps/FortreeCliffs/scripts.pory"
	.string "think you're up to the challenge.$"
# 596 "data//maps/FortreeCliffs/scripts.pory"

# 597 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3a:
# 598 "data//maps/FortreeCliffs/scripts.pory"
	.string "If you made it here, then perhaps you\n" 
# 599 "data//maps/FortreeCliffs/scripts.pory"
	.string "are ready to fly.$"
# 600 "data//maps/FortreeCliffs/scripts.pory"

# 601 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona4:
# 602 "data//maps/FortreeCliffs/scripts.pory"
	.string "Until we meet again, {PLAYER}.$"
# 603 "data//maps/FortreeCliffs/scripts.pory"

# 604 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 605 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 606 "data//maps/FortreeCliffs/scripts.pory"

# 607 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 608 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 609 "data//maps/FortreeCliffs/scripts.pory"

# 610 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 611 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 612 "data//maps/FortreeCliffs/scripts.pory"

# 613 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 614 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 615 "data//maps/FortreeCliffs/scripts.pory"

# 616 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 617 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 618 "data//maps/FortreeCliffs/scripts.pory"

# 619 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 620 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 621 "data//maps/FortreeCliffs/scripts.pory"

# 622 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 623 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 624 "data//maps/FortreeCliffs/scripts.pory"

# 625 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 626 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 627 "data//maps/FortreeCliffs/scripts.pory"

# 628 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 629 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 630 "data//maps/FortreeCliffs/scripts.pory"

# 631 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 632 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 633 "data//maps/FortreeCliffs/scripts.pory"

# 634 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 635 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 636 "data//maps/FortreeCliffs/scripts.pory"

# 637 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 638 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 639 "data//maps/FortreeCliffs/scripts.pory"

# 640 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 641 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 642 "data//maps/FortreeCliffs/scripts.pory"

# 643 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 644 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 645 "data//maps/FortreeCliffs/scripts.pory"

# 646 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 647 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 648 "data//maps/FortreeCliffs/scripts.pory"

# 649 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 650 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 651 "data//maps/FortreeCliffs/scripts.pory"

# 652 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 653 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 654 "data//maps/FortreeCliffs/scripts.pory"

# 655 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 656 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 657 "data//maps/FortreeCliffs/scripts.pory"

# 658 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 659 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 660 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 661 "data//maps/FortreeCliffs/scripts.pory"

# 662 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 663 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 664 "data//maps/FortreeCliffs/scripts.pory"

# 665 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 666 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 667 "data//maps/FortreeCliffs/scripts.pory"

# 668 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 669 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 670 "data//maps/FortreeCliffs/scripts.pory"

# 671 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 672 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 673 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 674 "data//maps/FortreeCliffs/scripts.pory"

# 675 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 676 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 677 "data//maps/FortreeCliffs/scripts.pory"

# 678 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 679 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 680 "data//maps/FortreeCliffs/scripts.pory"

# 681 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 682 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 683 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 684 "data//maps/FortreeCliffs/scripts.pory"

# 685 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 686 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 687 "data//maps/FortreeCliffs/scripts.pory"

# 688 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 689 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 690 "data//maps/FortreeCliffs/scripts.pory"

# 691 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 692 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 693 "data//maps/FortreeCliffs/scripts.pory"

# 694 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 695 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?\p"
# 696 "data//maps/FortreeCliffs/scripts.pory"
	.string "She is friends with powerful\n"
# 697 "data//maps/FortreeCliffs/scripts.pory"
	.string "BIRD POKéMON!$"
