# 1 "data//maps/FortreeCliffs/scripts.pory"

# 2 "data//maps/FortreeCliffs/scripts.pory"

# 3 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_MapScripts::
# 4 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCliffs_OnResume
# 5 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffs_OnTransition
# 6 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 7 "data//maps/FortreeCliffs/scripts.pory"

# 8 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnResume:
# 9 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FortreeCliffs_EventScript_TryRemoveWildMons
# 10 "data//maps/FortreeCliffs/scripts.pory"
	end
# 11 "data//maps/FortreeCliffs/scripts.pory"

# 12 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryRemoveWildMons::
# 13 "data//maps/FortreeCliffs/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 15 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 16 "data//maps/FortreeCliffs/scripts.pory"
	return
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
FortreeCliffs_EventScript_BraviaryOnTransitionSwitch::
# 24 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                 @ place objects at correct spot when map loads
# 25 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_PlaceBraviaryAtNest1
# 26 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_PlaceBraviaryAtNest2                                             
# 27 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_PlaceBraviaryAtNest3
# 28 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_PlaceBraviaryAtNest4
# 29 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_PlaceBraviaryAtNest5                                           
# 30 "data//maps/FortreeCliffs/scripts.pory"
	return
# 31 "data//maps/FortreeCliffs/scripts.pory"

# 32 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Winona::
# 33 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 34 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 35 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona1, MSGBOX_DEFAULT
# 36 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 37 "data//maps/FortreeCliffs/scripts.pory"
	delay 30
# 38 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona2, MSGBOX_DEFAULT
# 39 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 40 "data//maps/FortreeCliffs/scripts.pory"
	delay 5
# 41 "data//maps/FortreeCliffs/scripts.pory"
	turnobject LOCALID_FORTREE_CLIFFS_WINONA, DIR_WEST
# 42 "data//maps/FortreeCliffs/scripts.pory"
	delay 60
# 43 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3a, MSGBOX_DEFAULT
# 44 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 45 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 46 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_WINONA, Common_Movement_FacePlayer
# 47 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 48 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona3, MSGBOX_DEFAULT
# 49 "data//maps/FortreeCliffs/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 50 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Winona4, MSGBOX_DEFAULT
# 51 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 52 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1
# 53 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 54 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 55 "data//maps/FortreeCliffs/scripts.pory"
	removeobject LOCALID_FORTREE_CLIFFS_WINONA
# 56 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 57 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_WINONA_LOCATION, 1
# 58 "data//maps/FortreeCliffs/scripts.pory"
	release
# 59 "data//maps/FortreeCliffs/scripts.pory"
	end
# 60 "data//maps/FortreeCliffs/scripts.pory"

# 61 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 62 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 63 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 64 "data//maps/FortreeCliffs/scripts.pory"
	return
# 65 "data//maps/FortreeCliffs/scripts.pory"

# 66 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 67 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 68 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 69 "data//maps/FortreeCliffs/scripts.pory"
	return
# 70 "data//maps/FortreeCliffs/scripts.pory"

# 71 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 72 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 73 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 74 "data//maps/FortreeCliffs/scripts.pory"
	return
# 75 "data//maps/FortreeCliffs/scripts.pory"

# 76 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 77 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 78 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 79 "data//maps/FortreeCliffs/scripts.pory"
	return
# 80 "data//maps/FortreeCliffs/scripts.pory"

# 81 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 82 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 83 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 84 "data//maps/FortreeCliffs/scripts.pory"
	return
# 85 "data//maps/FortreeCliffs/scripts.pory"

# 86 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 87 "data//maps/FortreeCliffs/scripts.pory"
	end
# 88 "data//maps/FortreeCliffs/scripts.pory"

# 89 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 90 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 91 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 92 "data//maps/FortreeCliffs/scripts.pory"
	release
# 93 "data//maps/FortreeCliffs/scripts.pory"
	end
# 94 "data//maps/FortreeCliffs/scripts.pory"

# 95 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 96 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 97 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 98 "data//maps/FortreeCliffs/scripts.pory"
	hidefollower 0
# 99 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 100 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 101 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 102 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 103 "data//maps/FortreeCliffs/scripts.pory"
	
# 104 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 105 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 106 "data//maps/FortreeCliffs/scripts.pory"

# 107 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 108 "data//maps/FortreeCliffs/scripts.pory"

# 109 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 110 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 111 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 112 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 113 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 114 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 115 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 116 "data//maps/FortreeCliffs/scripts.pory"
	release
# 117 "data//maps/FortreeCliffs/scripts.pory"
	end
# 118 "data//maps/FortreeCliffs/scripts.pory"

# 119 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 120 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 121 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 122 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 123 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 124 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 125 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 126 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 127 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 128 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 129 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 130 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 131 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 132 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 133 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 134 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 135 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 136 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 137 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 138 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 139 "data//maps/FortreeCliffs/scripts.pory"
	return
# 140 "data//maps/FortreeCliffs/scripts.pory"

# 141 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 142 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 143 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 144 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 145 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 146 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 147 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 148 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 149 "data//maps/FortreeCliffs/scripts.pory"
	return
# 150 "data//maps/FortreeCliffs/scripts.pory"

# 151 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 152 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 153 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 154 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 155 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 156 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 157 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 158 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 159 "data//maps/FortreeCliffs/scripts.pory"
	return
# 160 "data//maps/FortreeCliffs/scripts.pory"

# 161 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 162 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 163 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 164 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 165 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 166 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 167 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 168 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 169 "data//maps/FortreeCliffs/scripts.pory"
	return
# 170 "data//maps/FortreeCliffs/scripts.pory"

# 171 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 172 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 173 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 174 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 175 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 176 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 177 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 178 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 179 "data//maps/FortreeCliffs/scripts.pory"
	return
# 180 "data//maps/FortreeCliffs/scripts.pory"

# 181 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 182 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 183 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 184 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 185 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 186 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 187 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 188 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 189 "data//maps/FortreeCliffs/scripts.pory"
	return
# 190 "data//maps/FortreeCliffs/scripts.pory"

# 191 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 192 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 193 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 194 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 195 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 196 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 197 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 198 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 199 "data//maps/FortreeCliffs/scripts.pory"
	return
# 200 "data//maps/FortreeCliffs/scripts.pory"

# 201 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 202 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 203 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 204 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 205 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 206 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 207 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 208 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 209 "data//maps/FortreeCliffs/scripts.pory"
	return
# 210 "data//maps/FortreeCliffs/scripts.pory"

# 211 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 212 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 213 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 214 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 215 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 216 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 217 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 218 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 219 "data//maps/FortreeCliffs/scripts.pory"
	end
# 220 "data//maps/FortreeCliffs/scripts.pory"

# 221 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 222 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 223 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 224 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 225 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 226 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 227 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 228 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 229 "data//maps/FortreeCliffs/scripts.pory"
	end
# 230 "data//maps/FortreeCliffs/scripts.pory"

# 231 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 232 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 233 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 234 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 235 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 236 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 237 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 238 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 239 "data//maps/FortreeCliffs/scripts.pory"
	end
# 240 "data//maps/FortreeCliffs/scripts.pory"

# 241 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 242 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 243 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 244 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 245 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 246 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 247 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 248 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 249 "data//maps/FortreeCliffs/scripts.pory"
	end
# 250 "data//maps/FortreeCliffs/scripts.pory"

# 251 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 252 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                               @ fly away
# 253 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 254 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 255 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 256 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 257 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 258 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 259 "data//maps/FortreeCliffs/scripts.pory"
	end
# 260 "data//maps/FortreeCliffs/scripts.pory"

# 261 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 262 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 263 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 264 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 265 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                        @ animate player landing
# 266 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 267 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 268 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 269 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 270 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 271 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 272 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 273 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 274 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 275 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1   
# 276 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP     
# 277 "data//maps/FortreeCliffs/scripts.pory"
	release
# 278 "data//maps/FortreeCliffs/scripts.pory"
	end
# 279 "data//maps/FortreeCliffs/scripts.pory"

# 280 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 281 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 282 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 283 "data//maps/FortreeCliffs/scripts.pory"
	return
# 284 "data//maps/FortreeCliffs/scripts.pory"

# 285 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 286 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 287 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 288 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 289 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_NORMAL
# 290 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 291 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 292 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 293 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 294 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 295 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 296 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 297 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 298 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 299 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 300 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 301 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 302 "data//maps/FortreeCliffs/scripts.pory"
	return
# 303 "data//maps/FortreeCliffs/scripts.pory"

# 304 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 305 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 306 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 307 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 308 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 309 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 310 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 311 "data//maps/FortreeCliffs/scripts.pory"
	end
# 312 "data//maps/FortreeCliffs/scripts.pory"

# 313 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 314 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 315 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 316 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 317 "data//maps/FortreeCliffs/scripts.pory"
	return
# 318 "data//maps/FortreeCliffs/scripts.pory"

# 319 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 320 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 321 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 322 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 323 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 324 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 325 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 326 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 327 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 328 "data//maps/FortreeCliffs/scripts.pory"
	return
# 329 "data//maps/FortreeCliffs/scripts.pory"

# 330 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 331 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 332 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 333 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 334 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 335 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 336 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 337 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 338 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 339 "data//maps/FortreeCliffs/scripts.pory"
	return
# 340 "data//maps/FortreeCliffs/scripts.pory"

# 341 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 342 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 343 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 344 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 345 "data//maps/FortreeCliffs/scripts.pory"
	bufferitemname STR_VAR_1, VAR_ITEM_ID
# 346 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryAcceptedBerry, MSGBOX_DEFAULT
# 347 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 348 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 349 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 350 "data//maps/FortreeCliffs/scripts.pory"
	return
# 351 "data//maps/FortreeCliffs/scripts.pory"

# 352 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 353 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 354 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 355 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 356 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 357 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 358 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 359 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 360 "data//maps/FortreeCliffs/scripts.pory"
	release
# 361 "data//maps/FortreeCliffs/scripts.pory"
	end
# 362 "data//maps/FortreeCliffs/scripts.pory"

# 363 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 364 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 365 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 366 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 367 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 368 "data//maps/FortreeCliffs/scripts.pory"
	return
# 369 "data//maps/FortreeCliffs/scripts.pory"

# 370 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 371 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 372 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 373 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 374 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 375 "data//maps/FortreeCliffs/scripts.pory"
	release
# 376 "data//maps/FortreeCliffs/scripts.pory"
	end
# 377 "data//maps/FortreeCliffs/scripts.pory"

# 378 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 379 "data//maps/FortreeCliffs/scripts.pory"
	return
# 380 "data//maps/FortreeCliffs/scripts.pory"

# 381 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 382 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 383 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 384 "data//maps/FortreeCliffs/scripts.pory"
	end
# 385 "data//maps/FortreeCliffs/scripts.pory"

# 386 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 387 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 388 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 389 "data//maps/FortreeCliffs/scripts.pory"
	end
# 390 "data//maps/FortreeCliffs/scripts.pory"

# 391 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 392 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 393 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 394 "data//maps/FortreeCliffs/scripts.pory"
	end
# 395 "data//maps/FortreeCliffs/scripts.pory"

# 396 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 397 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 398 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 399 "data//maps/FortreeCliffs/scripts.pory"
	end
# 400 "data//maps/FortreeCliffs/scripts.pory"

# 401 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 402 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 403 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 404 "data//maps/FortreeCliffs/scripts.pory"
	end
# 405 "data//maps/FortreeCliffs/scripts.pory"

# 406 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 407 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 408 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 409 "data//maps/FortreeCliffs/scripts.pory"
	end
# 410 "data//maps/FortreeCliffs/scripts.pory"

# 411 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 412 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 413 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 414 "data//maps/FortreeCliffs/scripts.pory"
	end
# 415 "data//maps/FortreeCliffs/scripts.pory"

# 416 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 417 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 418 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 419 "data//maps/FortreeCliffs/scripts.pory"
	end
# 420 "data//maps/FortreeCliffs/scripts.pory"

# 421 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 422 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 423 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 424 "data//maps/FortreeCliffs/scripts.pory"
	end
# 425 "data//maps/FortreeCliffs/scripts.pory"

# 426 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 427 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 428 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 429 "data//maps/FortreeCliffs/scripts.pory"
	end
# 430 "data//maps/FortreeCliffs/scripts.pory"

# 431 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 432 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 433 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 434 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 435 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 436 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 437 "data//maps/FortreeCliffs/scripts.pory"

# 438 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 439 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 440 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 441 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 442 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 443 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 444 "data//maps/FortreeCliffs/scripts.pory"

# 445 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 446 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 447 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 448 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 449 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 450 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 451 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 452 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 453 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 454 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 455 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 456 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 457 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 458 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 459 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 460 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 461 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 462 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 463 "data//maps/FortreeCliffs/scripts.pory"

# 464 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 465 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 466 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 467 "data//maps/FortreeCliffs/scripts.pory"

# 468 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 469 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 470 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 471 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 472 "data//maps/FortreeCliffs/scripts.pory"

# 473 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 474 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 475 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 476 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 477 "data//maps/FortreeCliffs/scripts.pory"

# 478 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 479 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 480 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 481 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 482 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 483 "data//maps/FortreeCliffs/scripts.pory"

# 484 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 485 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 486 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 487 "data//maps/FortreeCliffs/scripts.pory"

# 488 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 489 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 490 "data//maps/FortreeCliffs/scripts.pory"

# 491 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 492 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 493 "data//maps/FortreeCliffs/scripts.pory"

# 494 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 495 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 496 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 497 "data//maps/FortreeCliffs/scripts.pory"

# 498 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryAcceptedBerry:
# 499 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY accepted the {STR_VAR_1}.$"
# 500 "data//maps/FortreeCliffs/scripts.pory"

# 501 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 502 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 503 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 504 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 505 "data//maps/FortreeCliffs/scripts.pory"

# 506 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 507 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 508 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 509 "data//maps/FortreeCliffs/scripts.pory"

# 510 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 511 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 512 "data//maps/FortreeCliffs/scripts.pory"

# 513 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona1:
# 514 "data//maps/FortreeCliffs/scripts.pory"
	.string "… … … … … …$"
# 515 "data//maps/FortreeCliffs/scripts.pory"

# 516 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona2:
# 517 "data//maps/FortreeCliffs/scripts.pory"
	.string "I train atop these cliffs\n"
# 518 "data//maps/FortreeCliffs/scripts.pory"
	.string "because of my devotion to reaching\l"
# 519 "data//maps/FortreeCliffs/scripts.pory"
	.string "the greatest heights.\p"
# 520 "data//maps/FortreeCliffs/scripts.pory"
	.string "Very few TRAINERS ever soar so high\n"
# 521 "data//maps/FortreeCliffs/scripts.pory"
	.string "above FORTREE's thick forests and\l"
# 522 "data//maps/FortreeCliffs/scripts.pory"
	.string "steep cliffs.$"
# 523 "data//maps/FortreeCliffs/scripts.pory"

# 524 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3:
# 525 "data//maps/FortreeCliffs/scripts.pory"
	.string "Take this and meet me at my gym if you\n"
# 526 "data//maps/FortreeCliffs/scripts.pory"
	.string "think you're up to the challenge.$"
# 527 "data//maps/FortreeCliffs/scripts.pory"

# 528 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona3a:
# 529 "data//maps/FortreeCliffs/scripts.pory"
	.string "If you made it here, then perhaps you\n" 
# 530 "data//maps/FortreeCliffs/scripts.pory"
	.string "are ready to fly.$"
# 531 "data//maps/FortreeCliffs/scripts.pory"

# 532 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Winona4:
# 533 "data//maps/FortreeCliffs/scripts.pory"
	.string "Until we meet again, {PLAYER}.$"
# 534 "data//maps/FortreeCliffs/scripts.pory"

# 535 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 536 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 537 "data//maps/FortreeCliffs/scripts.pory"

# 538 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 539 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 540 "data//maps/FortreeCliffs/scripts.pory"

# 541 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 542 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 543 "data//maps/FortreeCliffs/scripts.pory"

# 544 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 545 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 546 "data//maps/FortreeCliffs/scripts.pory"

# 547 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 548 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 549 "data//maps/FortreeCliffs/scripts.pory"

# 550 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 551 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 552 "data//maps/FortreeCliffs/scripts.pory"

# 553 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 554 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 555 "data//maps/FortreeCliffs/scripts.pory"

# 556 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 557 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 558 "data//maps/FortreeCliffs/scripts.pory"

# 559 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 560 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 561 "data//maps/FortreeCliffs/scripts.pory"

# 562 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 567 "data//maps/FortreeCliffs/scripts.pory"

# 568 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 569 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 570 "data//maps/FortreeCliffs/scripts.pory"

# 571 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 572 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 573 "data//maps/FortreeCliffs/scripts.pory"

# 574 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 575 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 576 "data//maps/FortreeCliffs/scripts.pory"

# 577 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 578 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 579 "data//maps/FortreeCliffs/scripts.pory"

# 580 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 581 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 582 "data//maps/FortreeCliffs/scripts.pory"

# 583 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 584 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 585 "data//maps/FortreeCliffs/scripts.pory"

# 586 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 587 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 588 "data//maps/FortreeCliffs/scripts.pory"

# 589 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 590 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 591 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 592 "data//maps/FortreeCliffs/scripts.pory"

# 593 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 594 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 595 "data//maps/FortreeCliffs/scripts.pory"

# 596 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 597 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 598 "data//maps/FortreeCliffs/scripts.pory"

# 599 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 600 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 601 "data//maps/FortreeCliffs/scripts.pory"

# 602 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 603 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 604 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 605 "data//maps/FortreeCliffs/scripts.pory"

# 606 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 607 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 608 "data//maps/FortreeCliffs/scripts.pory"

# 609 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 610 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 611 "data//maps/FortreeCliffs/scripts.pory"

# 612 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 613 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 614 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 615 "data//maps/FortreeCliffs/scripts.pory"

# 616 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 617 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 618 "data//maps/FortreeCliffs/scripts.pory"

# 619 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 620 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 621 "data//maps/FortreeCliffs/scripts.pory"

# 622 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 623 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 624 "data//maps/FortreeCliffs/scripts.pory"

# 625 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 626 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?\p"
# 627 "data//maps/FortreeCliffs/scripts.pory"
	.string "She is friends with powerful\n"
# 628 "data//maps/FortreeCliffs/scripts.pory"
	.string "BIRD POKéMON!$"
