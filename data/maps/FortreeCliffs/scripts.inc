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
FortreeCliffs_EventScript_PlaceBraviaryAtNest1::
# 33 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 34 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 35 "data//maps/FortreeCliffs/scripts.pory"
	return
# 36 "data//maps/FortreeCliffs/scripts.pory"

# 37 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest2::  
# 38 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 39 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 40 "data//maps/FortreeCliffs/scripts.pory"
	return
# 41 "data//maps/FortreeCliffs/scripts.pory"

# 42 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest3::       
# 43 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 44 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 45 "data//maps/FortreeCliffs/scripts.pory"
	return
# 46 "data//maps/FortreeCliffs/scripts.pory"

# 47 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest4::
# 48 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 49 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 50 "data//maps/FortreeCliffs/scripts.pory"
	return
# 51 "data//maps/FortreeCliffs/scripts.pory"

# 52 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_PlaceBraviaryAtNest5::
# 53 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 54 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 55 "data//maps/FortreeCliffs/scripts.pory"
	return
# 56 "data//maps/FortreeCliffs/scripts.pory"

# 57 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 58 "data//maps/FortreeCliffs/scripts.pory"
	end
# 59 "data//maps/FortreeCliffs/scripts.pory"

# 60 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BadVibeRock::
# 61 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 62 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BadVibeRock, MSGBOX_DEFAULT
# 63 "data//maps/FortreeCliffs/scripts.pory"
	release
# 64 "data//maps/FortreeCliffs/scripts.pory"
	end
# 65 "data//maps/FortreeCliffs/scripts.pory"

# 66 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Nest::
# 67 "data//maps/FortreeCliffs/scripts.pory"
	@ lock
# 68 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_TEMP_5
# 69 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan camera up 
# 70 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanUp
# 71 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 72 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 73 "data//maps/FortreeCliffs/scripts.pory"
	
# 74 "data//maps/FortreeCliffs/scripts.pory"
	call_if_lt VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_OfferBraviaryBerry           @ Ask to offer berry if untrusted
# 75 "data//maps/FortreeCliffs/scripts.pory"
	call_if_ge VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4, FortreeCliffs_EventScript_BraviaryWantsToFly           @ Ask to fly
# 76 "data//maps/FortreeCliffs/scripts.pory"

# 77 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_BraviaryRoutingSwitch                                                    @ choose which nest to fly to
# 78 "data//maps/FortreeCliffs/scripts.pory"

# 79 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3, FortreeCliffs_EventScript_WantsYouToFollow             @ ending with slight text difference after third berry and before first flight
# 80 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_FlewToTheNextNest, MSGBOX_DEFAULT
# 81 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 82 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 83 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 84 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 85 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 86 "data//maps/FortreeCliffs/scripts.pory"
	release
# 87 "data//maps/FortreeCliffs/scripts.pory"
	end
# 88 "data//maps/FortreeCliffs/scripts.pory"

# 89 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryRoutingSwitch::                                                          @ handles updating object locations and vars
# 90 "data//maps/FortreeCliffs/scripts.pory"
	waitse                                                                                                 @ fly away animation and cry
# 91 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 92 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 93 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 94 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryFlyOff
# 95 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_NEST, FortreeCliffs_Movement_BraviaryFlyOff
# 96 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1
# 97 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 98 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BRAVIARY_TRUST                                                                  
# 99 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch                                           @ stay in northern nests if low trust
# 100 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_BraviaryNorthernNestSwitch
# 101 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_BraviarySouthernNestSwitch                                           @ stay in southern nests if mid trust
# 102 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_BraviarySouthernNestSwitch
# 103 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_FORTREE_CLIFFS_BIRD_LOCATION                                                                @ choose next nest based on current nest
# 104 "data//maps/FortreeCliffs/scripts.pory"
	case 0, FortreeCliffs_EventScript_MoveBraviaryToNest2
# 105 "data//maps/FortreeCliffs/scripts.pory"
	case 1, FortreeCliffs_EventScript_MoveBraviaryToNest3
# 106 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 107 "data//maps/FortreeCliffs/scripts.pory"
	case 3, FortreeCliffs_EventScript_MoveBraviaryToNest5
# 108 "data//maps/FortreeCliffs/scripts.pory"
	case 4, FortreeCliffs_EventScript_MoveBraviaryToStartingNest                                           @ nest 1
# 109 "data//maps/FortreeCliffs/scripts.pory"
	return
# 110 "data//maps/FortreeCliffs/scripts.pory"

# 111 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryNorthernNestSwitch::
# 112 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1, FortreeCliffs_EventScript_MoveBraviaryToStartingNest  
# 113 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 114 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 115 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 116 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 117 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 118 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 119 "data//maps/FortreeCliffs/scripts.pory"
	return
# 120 "data//maps/FortreeCliffs/scripts.pory"

# 121 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviarySouthernNestSwitch::
# 122 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest      
# 123 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 124 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 125 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 126 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 127 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 128 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 129 "data//maps/FortreeCliffs/scripts.pory"
	return
# 130 "data//maps/FortreeCliffs/scripts.pory"

# 131 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToStartingNest::
# 132 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 12                                                    @ move sign to nest 1 
# 133 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 12
# 134 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 0                                                             @ update location var to nest 1
# 135 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8                                               @ move bird to nest 1
# 136 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 8
# 137 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 138 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToStartingNest
# 139 "data//maps/FortreeCliffs/scripts.pory"
	return
# 140 "data//maps/FortreeCliffs/scripts.pory"

# 141 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest2::  
# 142 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 14, 18                                                    @ move sign to nest 2 
# 143 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 14, 18
# 144 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 1                                                             @ update location var to nest 2
# 145 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14                                              @ move bird to nest 2
# 146 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 14, 14
# 147 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 148 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest2
# 149 "data//maps/FortreeCliffs/scripts.pory"
	return
# 150 "data//maps/FortreeCliffs/scripts.pory"

# 151 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest:: 
# 152 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 13, 62                                                    @ move sign to nest 4 
# 153 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 13, 62
# 154 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 3                                                             @ update location var to nest 4
# 155 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58                                              @ move bird to nest 4
# 156 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 13, 58
# 157 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 158 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest
# 159 "data//maps/FortreeCliffs/scripts.pory"
	return
# 160 "data//maps/FortreeCliffs/scripts.pory"

# 161 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest3::     
# 162 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 22, 76                                                    @ move sign to nest 3 
# 163 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 22, 76
# 164 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 2                                                             @ update location var to nest 3
# 165 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72                                              @ move bird to nest 3
# 166 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 22, 72
# 167 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 168 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest3
# 169 "data//maps/FortreeCliffs/scripts.pory"
	return
# 170 "data//maps/FortreeCliffs/scripts.pory"

# 171 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_MoveBraviaryToNest5::
# 172 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_NEST, 24, 41                                                    @ move sign to nest 5 
# 173 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_NEST, 24, 41
# 174 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BIRD_LOCATION, 4                                                             @ update location var to nest 5
# 175 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxyperm LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37                                              @ move bird to nest 5
# 176 "data//maps/FortreeCliffs/scripts.pory"
	setobjectxy LOCALID_FORTREE_CLIFFS_BRAVIARY_1, 24, 37
# 177 "data//maps/FortreeCliffs/scripts.pory"
	resetobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS
# 178 "data//maps/FortreeCliffs/scripts.pory"
	call_if_set FLAG_TEMP_5, FortreeCliffs_EventScript_FlyPlayerToNest5
# 179 "data//maps/FortreeCliffs/scripts.pory"
	return
# 180 "data//maps/FortreeCliffs/scripts.pory"

# 181 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToStartingNest::
# 182 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                               @ fly away
# 183 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 184 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 185 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 186 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 187 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 13, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 188 "data//maps/FortreeCliffs/scripts.pory"
	end
# 189 "data//maps/FortreeCliffs/scripts.pory"

# 190 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 191 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                               @ fly away
# 192 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 193 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 194 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 195 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 196 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 14, 19, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 197 "data//maps/FortreeCliffs/scripts.pory"
	end
# 198 "data//maps/FortreeCliffs/scripts.pory"

# 199 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 200 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                               @ fly away
# 201 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 202 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 203 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 204 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 205 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 22, 77, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 206 "data//maps/FortreeCliffs/scripts.pory"
	end
# 207 "data//maps/FortreeCliffs/scripts.pory"

# 208 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 209 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                               @ fly away
# 210 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 211 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 212 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 213 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 214 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 13, 63, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 215 "data//maps/FortreeCliffs/scripts.pory"
	end
# 216 "data//maps/FortreeCliffs/scripts.pory"

# 217 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 218 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                               @ fly away
# 219 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 220 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 221 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                         @ hide player
# 222 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 223 "data//maps/FortreeCliffs/scripts.pory"
	warpcontinuescript MAP_FORTREE_CLIFFS, 24, 42, FortreeCliffs_EventScript_BraviaryLandsWithPlayer         @ landing coords         
# 224 "data//maps/FortreeCliffs/scripts.pory"
	end
# 225 "data//maps/FortreeCliffs/scripts.pory"

# 226 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryLandsWithPlayer::
# 227 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 228 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 229 "data//maps/FortreeCliffs/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 230 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                        @ animate player landing
# 231 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 232 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 233 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ reshow player
# 234 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_FLY_IN
# 235 "data//maps/FortreeCliffs/scripts.pory"
	setobjectsubpriority LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS, 3
# 236 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryJumpUp            @ braviary landing begins
# 237 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 238 "data//maps/FortreeCliffs/scripts.pory"
	showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 239 "data//maps/FortreeCliffs/scripts.pory"
	applymovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1, FortreeCliffs_Movement_BraviaryLands 
# 240 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement LOCALID_FORTREE_CLIFFS_BRAVIARY_1        
# 241 "data//maps/FortreeCliffs/scripts.pory"
	release
# 242 "data//maps/FortreeCliffs/scripts.pory"
	end
# 243 "data//maps/FortreeCliffs/scripts.pory"

# 244 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 245 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 246 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 247 "data//maps/FortreeCliffs/scripts.pory"
	return
# 248 "data//maps/FortreeCliffs/scripts.pory"

# 249 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 250 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 251 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 252 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 253 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 254 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 255 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 256 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 257 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 258 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 259 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 260 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 261 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 262 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 263 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 264 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 265 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 266 "data//maps/FortreeCliffs/scripts.pory"
	return
# 267 "data//maps/FortreeCliffs/scripts.pory"

# 268 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 269 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 270 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 271 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 272 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 273 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 274 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 275 "data//maps/FortreeCliffs/scripts.pory"
	end
# 276 "data//maps/FortreeCliffs/scripts.pory"

# 277 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 278 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 279 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 280 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 281 "data//maps/FortreeCliffs/scripts.pory"
	return
# 282 "data//maps/FortreeCliffs/scripts.pory"

# 283 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 284 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 285 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 286 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 287 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 288 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 289 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 290 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 291 "data//maps/FortreeCliffs/scripts.pory"
	return
# 292 "data//maps/FortreeCliffs/scripts.pory"

# 293 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 294 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 295 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 296 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 297 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 298 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 299 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 300 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 301 "data//maps/FortreeCliffs/scripts.pory"
	return
# 302 "data//maps/FortreeCliffs/scripts.pory"

# 303 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 304 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 305 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 306 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 307 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 308 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 309 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 310 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 311 "data//maps/FortreeCliffs/scripts.pory"
	return
# 312 "data//maps/FortreeCliffs/scripts.pory"

# 313 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 314 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 315 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 316 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 317 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 318 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 319 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 320 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 321 "data//maps/FortreeCliffs/scripts.pory"
	release
# 322 "data//maps/FortreeCliffs/scripts.pory"
	end
# 323 "data//maps/FortreeCliffs/scripts.pory"

# 324 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 325 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 326 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 327 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 328 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 329 "data//maps/FortreeCliffs/scripts.pory"
	return
# 330 "data//maps/FortreeCliffs/scripts.pory"

# 331 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 332 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 333 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 334 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 335 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 336 "data//maps/FortreeCliffs/scripts.pory"
	release
# 337 "data//maps/FortreeCliffs/scripts.pory"
	end
# 338 "data//maps/FortreeCliffs/scripts.pory"

# 339 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 340 "data//maps/FortreeCliffs/scripts.pory"
	return
# 341 "data//maps/FortreeCliffs/scripts.pory"

# 342 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 343 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 344 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 345 "data//maps/FortreeCliffs/scripts.pory"
	end
# 346 "data//maps/FortreeCliffs/scripts.pory"

# 347 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 348 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 349 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 350 "data//maps/FortreeCliffs/scripts.pory"
	end
# 351 "data//maps/FortreeCliffs/scripts.pory"

# 352 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 353 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 354 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 355 "data//maps/FortreeCliffs/scripts.pory"
	end
# 356 "data//maps/FortreeCliffs/scripts.pory"

# 357 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 358 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 359 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 360 "data//maps/FortreeCliffs/scripts.pory"
	end
# 361 "data//maps/FortreeCliffs/scripts.pory"

# 362 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 363 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 364 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 365 "data//maps/FortreeCliffs/scripts.pory"
	end
# 366 "data//maps/FortreeCliffs/scripts.pory"

# 367 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 368 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 369 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 370 "data//maps/FortreeCliffs/scripts.pory"
	end
# 371 "data//maps/FortreeCliffs/scripts.pory"

# 372 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 373 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 374 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 375 "data//maps/FortreeCliffs/scripts.pory"
	end
# 376 "data//maps/FortreeCliffs/scripts.pory"

# 377 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 378 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 379 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 380 "data//maps/FortreeCliffs/scripts.pory"
	end
# 381 "data//maps/FortreeCliffs/scripts.pory"

# 382 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 383 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 384 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 385 "data//maps/FortreeCliffs/scripts.pory"
	end
# 386 "data//maps/FortreeCliffs/scripts.pory"

# 387 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 388 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 389 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 390 "data//maps/FortreeCliffs/scripts.pory"
	end
# 391 "data//maps/FortreeCliffs/scripts.pory"

# 392 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 393 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 394 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 395 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 396 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 397 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 398 "data//maps/FortreeCliffs/scripts.pory"

# 399 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 400 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 401 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 402 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 403 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 404 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 405 "data//maps/FortreeCliffs/scripts.pory"

# 406 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 407 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 408 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 409 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 410 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 411 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 412 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 413 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 414 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 415 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 416 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 417 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 418 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 419 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 420 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 421 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 422 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 423 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 424 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 425 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 426 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 427 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 428 "data//maps/FortreeCliffs/scripts.pory"

# 429 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryJumpUp::
# 430 "data//maps/FortreeCliffs/scripts.pory"
	jump_2_up
# 431 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 432 "data//maps/FortreeCliffs/scripts.pory"

# 433 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryLands::
# 434 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 435 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 436 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 437 "data//maps/FortreeCliffs/scripts.pory"

# 438 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 439 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 440 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 441 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 442 "data//maps/FortreeCliffs/scripts.pory"

# 443 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 444 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 445 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 446 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 447 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 448 "data//maps/FortreeCliffs/scripts.pory"

# 449 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 450 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 451 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 452 "data//maps/FortreeCliffs/scripts.pory"

# 453 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 454 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 455 "data//maps/FortreeCliffs/scripts.pory"

# 456 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 457 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 458 "data//maps/FortreeCliffs/scripts.pory"

# 459 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 460 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 461 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 462 "data//maps/FortreeCliffs/scripts.pory"

# 463 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 464 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 465 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 466 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 467 "data//maps/FortreeCliffs/scripts.pory"

# 468 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 469 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 470 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 471 "data//maps/FortreeCliffs/scripts.pory"

# 472 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 473 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 474 "data//maps/FortreeCliffs/scripts.pory"

# 475 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 476 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 477 "data//maps/FortreeCliffs/scripts.pory"

# 478 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 479 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 480 "data//maps/FortreeCliffs/scripts.pory"

# 481 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 482 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 483 "data//maps/FortreeCliffs/scripts.pory"

# 484 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 485 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 486 "data//maps/FortreeCliffs/scripts.pory"

# 487 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 488 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 489 "data//maps/FortreeCliffs/scripts.pory"

# 490 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 491 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 492 "data//maps/FortreeCliffs/scripts.pory"

# 493 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 494 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 495 "data//maps/FortreeCliffs/scripts.pory"

# 496 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 497 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 498 "data//maps/FortreeCliffs/scripts.pory"

# 499 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 500 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 501 "data//maps/FortreeCliffs/scripts.pory"

# 502 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 503 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 504 "data//maps/FortreeCliffs/scripts.pory"

# 505 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 506 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 507 "data//maps/FortreeCliffs/scripts.pory"

# 508 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 509 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 510 "data//maps/FortreeCliffs/scripts.pory"

# 511 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 512 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 513 "data//maps/FortreeCliffs/scripts.pory"

# 514 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 515 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 516 "data//maps/FortreeCliffs/scripts.pory"

# 517 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 518 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 519 "data//maps/FortreeCliffs/scripts.pory"

# 520 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 521 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 522 "data//maps/FortreeCliffs/scripts.pory"

# 523 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 524 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 525 "data//maps/FortreeCliffs/scripts.pory"

# 526 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 527 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 528 "data//maps/FortreeCliffs/scripts.pory"

# 529 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 530 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 531 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 532 "data//maps/FortreeCliffs/scripts.pory"

# 533 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 534 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 535 "data//maps/FortreeCliffs/scripts.pory"

# 536 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 537 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 538 "data//maps/FortreeCliffs/scripts.pory"

# 539 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 540 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 541 "data//maps/FortreeCliffs/scripts.pory"

# 542 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 543 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 544 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 545 "data//maps/FortreeCliffs/scripts.pory"

# 546 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 547 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 548 "data//maps/FortreeCliffs/scripts.pory"

# 549 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 550 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 551 "data//maps/FortreeCliffs/scripts.pory"

# 552 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 553 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 554 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 555 "data//maps/FortreeCliffs/scripts.pory"

# 556 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 557 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 558 "data//maps/FortreeCliffs/scripts.pory"

# 559 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 560 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 561 "data//maps/FortreeCliffs/scripts.pory"

# 562 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?$"
