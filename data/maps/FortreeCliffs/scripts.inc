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
	case 1, FortreeCliffs_EventScript_MoveBraviaryToLakeshoreNest                                          @ nest 4
# 106 "data//maps/FortreeCliffs/scripts.pory"
	case 2, FortreeCliffs_EventScript_MoveBraviaryToNest3
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
	setobjectmovementtype LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MOVEMENT_TYPE_INVISIBLE                     @ hide updated bird 
# 183 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                           @ fly away
# 184 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 185 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 186 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_INVISIBLE                                         @ hide player
# 187 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 188 "data//maps/FortreeCliffs/scripts.pory"

# 189 "data//maps/FortreeCliffs/scripts.pory"
	@ fadescreenswapbuffers FADE_TO_BLACK                                                                    @ warp to next nest
# 190 "data//maps/FortreeCliffs/scripts.pory"
	warpsilent MAP_FORTREE_CLIFFS, 24, 13                                                                 @ landing coords
# 191 "data//maps/FortreeCliffs/scripts.pory"

# 192 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                             @ animate landing
# 193 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 194 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 195 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_DOWN                                        @ show player
# 196 "data//maps/FortreeCliffs/scripts.pory"
	return
# 197 "data//maps/FortreeCliffs/scripts.pory"

# 198 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest2::
# 199 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MOVEMENT_TYPE_INVISIBLE                     @ hide updated bird 
# 200 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                           @ fly away
# 201 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 202 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 203 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_INVISIBLE                                         @ hide player
# 204 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 205 "data//maps/FortreeCliffs/scripts.pory"

# 206 "data//maps/FortreeCliffs/scripts.pory"
	@ fadescreenswapbuffers FADE_TO_BLACK                                                                    @ warp to next nest
# 207 "data//maps/FortreeCliffs/scripts.pory"
	warpsilent MAP_FORTREE_CLIFFS, 14, 19                                                                 @ landing coords
# 208 "data//maps/FortreeCliffs/scripts.pory"

# 209 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                             @ animate landing
# 210 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 211 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 212 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_DOWN                                        @ show player
# 213 "data//maps/FortreeCliffs/scripts.pory"
	return
# 214 "data//maps/FortreeCliffs/scripts.pory"

# 215 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest3::
# 216 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MOVEMENT_TYPE_INVISIBLE                     @ hide updated bird 
# 217 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                           @ fly away
# 218 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 219 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 220 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_INVISIBLE                                         @ hide player
# 221 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 222 "data//maps/FortreeCliffs/scripts.pory"

# 223 "data//maps/FortreeCliffs/scripts.pory"
	@ fadescreenswapbuffers FADE_TO_BLACK                                                                    @ warp to next nest
# 224 "data//maps/FortreeCliffs/scripts.pory"
	warpsilent MAP_FORTREE_CLIFFS, 22, 77                                                                 @ landing coords
# 225 "data//maps/FortreeCliffs/scripts.pory"

# 226 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                             @ animate landing
# 227 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 228 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 229 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_DOWN                                        @ show player
# 230 "data//maps/FortreeCliffs/scripts.pory"
	return
# 231 "data//maps/FortreeCliffs/scripts.pory"

# 232 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToLakeshoreNest::
# 233 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MOVEMENT_TYPE_INVISIBLE                     @ hide updated bird 
# 234 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                           @ fly away
# 235 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 236 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 237 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_INVISIBLE                                         @ hide player
# 238 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 239 "data//maps/FortreeCliffs/scripts.pory"

# 240 "data//maps/FortreeCliffs/scripts.pory"
	@ fadescreenswapbuffers FADE_TO_BLACK                                                                    @ warp to next nest
# 241 "data//maps/FortreeCliffs/scripts.pory"
	warpsilent MAP_FORTREE_CLIFFS, 13, 63                                                                 @ landing coords
# 242 "data//maps/FortreeCliffs/scripts.pory"

# 243 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, 1                                                                             @ animate landing
# 244 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 245 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 246 "data//maps/FortreeCliffs/scripts.pory"
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_DOWN                                        @ show player
# 247 "data//maps/FortreeCliffs/scripts.pory"
	return
# 248 "data//maps/FortreeCliffs/scripts.pory"

# 249 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_FlyPlayerToNest5::
# 250 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                        @ fly away
# 251 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 252 "data//maps/FortreeCliffs/scripts.pory"
	delay 15
# 253 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ hide player
# 254 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 255 "data//maps/FortreeCliffs/scripts.pory"

# 256 "data//maps/FortreeCliffs/scripts.pory"
	waitbuttonpress @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ to stop and check script flow                                         
# 257 "data//maps/FortreeCliffs/scripts.pory"

# 258 "data//maps/FortreeCliffs/scripts.pory"
	waitbuttonpress @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ to stop and check script flow
# 259 "data//maps/FortreeCliffs/scripts.pory"

# 260 "data//maps/FortreeCliffs/scripts.pory"
	warpsilent MAP_FORTREE_CLIFFS, 24, 42                                                           @ landing coords
# 261 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK                  
# 262 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 263 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ hide updated bird 
# 264 "data//maps/FortreeCliffs/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS 
# 265 "data//maps/FortreeCliffs/scripts.pory"

# 266 "data//maps/FortreeCliffs/scripts.pory"
	setfieldeffectargument 0, LOCALID_PLAYER                                                        @ animate landing
# 267 "data//maps/FortreeCliffs/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 268 "data//maps/FortreeCliffs/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 269 "data//maps/FortreeCliffs/scripts.pory"

# 270 "data//maps/FortreeCliffs/scripts.pory"
	@ showobjectat LOCALID_PLAYER, MAP_FORTREE_CLIFFS                                                 @ show player
# 271 "data//maps/FortreeCliffs/scripts.pory"

# 272 "data//maps/FortreeCliffs/scripts.pory"
	@ showobjectat LOCALID_FORTREE_CLIFFS_BRAVIARY_1, MAP_FORTREE_CLIFFS                              @ show updated bird 
# 273 "data//maps/FortreeCliffs/scripts.pory"

# 274 "data//maps/FortreeCliffs/scripts.pory"
	return
# 275 "data//maps/FortreeCliffs/scripts.pory"

# 276 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_OfferBraviaryBerry::
# 277 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_SkepticalBraviary, MSGBOX_YESNO
# 278 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCliffs_EventScript_TryGiveBraviaryBerry
# 279 "data//maps/FortreeCliffs/scripts.pory"
	return
# 280 "data//maps/FortreeCliffs/scripts.pory"

# 281 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_TryGiveBraviaryBerry::
# 282 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 283 "data//maps/FortreeCliffs/scripts.pory"
	special Bag_ChooseBerry
# 284 "data//maps/FortreeCliffs/scripts.pory"
	waitstate
# 285 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_ENCOUNTER
# 286 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 287 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, 0, FortreeCliffs_EventScript_DidntGiveBerry
# 288 "data//maps/FortreeCliffs/scripts.pory"
	switch VAR_ITEM_ID                                                                                 @ check that the berry is one bird likes 
# 289 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_POMEG_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 290 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_KELPSY_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 291 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_QUALOT_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 292 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_HONDEW_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 293 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_GREPA_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 294 "data//maps/FortreeCliffs/scripts.pory"
	case ITEM_TAMATO_BERRY, FortreeCliffs_EventScript_InspectBerryOffering 
# 295 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 296 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 297 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 298 "data//maps/FortreeCliffs/scripts.pory"
	return
# 299 "data//maps/FortreeCliffs/scripts.pory"

# 300 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_InspectBerryOffering::
# 301 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_1, FortreeCliffs_EventScript_BraviaryUninterested                  @ can't give duplicates
# 302 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_2, FortreeCliffs_EventScript_BraviaryUninterested
# 303 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_ITEM_ID, VAR_BRAVIARY_BERRY_3, FortreeCliffs_EventScript_BraviaryUninterested
# 304 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_1, 0, FortreeCliffs_EventScript_GiveFirstBerry                                  @ check how many have been given
# 305 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_2, 0, FortreeCliffs_EventScript_GiveSecondBerry
# 306 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_BRAVIARY_BERRY_3, 0, FortreeCliffs_EventScript_GiveThirdBerry
# 307 "data//maps/FortreeCliffs/scripts.pory"
	end
# 308 "data//maps/FortreeCliffs/scripts.pory"

# 309 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryUninterested::
# 310 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_WEAK
# 311 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BraviaryUninterested, MSGBOX_DEFAULT
# 312 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 313 "data//maps/FortreeCliffs/scripts.pory"
	return
# 314 "data//maps/FortreeCliffs/scripts.pory"

# 315 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveFirstBerry::
# 316 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 1
# 317 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 318 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_1, VAR_ITEM_ID
# 319 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 320 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 321 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveFirstBerry, MSGBOX_DEFAULT
# 322 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 323 "data//maps/FortreeCliffs/scripts.pory"
	return
# 324 "data//maps/FortreeCliffs/scripts.pory"

# 325 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveSecondBerry::
# 326 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 2
# 327 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 328 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_2, VAR_ITEM_ID
# 329 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 330 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 331 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveSecondBerry, MSGBOX_DEFAULT
# 332 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 333 "data//maps/FortreeCliffs/scripts.pory"
	return
# 334 "data//maps/FortreeCliffs/scripts.pory"

# 335 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_GiveThirdBerry::
# 336 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 3
# 337 "data//maps/FortreeCliffs/scripts.pory"
	removeitem VAR_ITEM_ID
# 338 "data//maps/FortreeCliffs/scripts.pory"
	copyvar VAR_BRAVIARY_BERRY_3, VAR_ITEM_ID
# 339 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_BRAVIARY, CRY_MODE_HIGH_PITCH
# 340 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 341 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_GaveThirdBerry, MSGBOX_DEFAULT
# 342 "data//maps/FortreeCliffs/scripts.pory"
	@ goto FortreeCliffs_EventScript_BraviaryRoutingSwitch
# 343 "data//maps/FortreeCliffs/scripts.pory"
	return
# 344 "data//maps/FortreeCliffs/scripts.pory"

# 345 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_WantsYouToFollow::
# 346 "data//maps/FortreeCliffs/scripts.pory"
	setvar VAR_FORTREE_CLIFFS_BRAVIARY_TRUST, 4
# 347 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_WantsYouToFollow, MSGBOX_DEFAULT
# 348 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 349 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 350 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 351 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 352 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 353 "data//maps/FortreeCliffs/scripts.pory"
	release
# 354 "data//maps/FortreeCliffs/scripts.pory"
	end
# 355 "data//maps/FortreeCliffs/scripts.pory"

# 356 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BraviaryWantsToFly::
# 357 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_AskingToFly, MSGBOX_YESNO
# 358 "data//maps/FortreeCliffs/scripts.pory"
	closemessage
# 359 "data//maps/FortreeCliffs/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FortreeCliffs_EventScript_DeclinedFlight
# 360 "data//maps/FortreeCliffs/scripts.pory"
	setflag FLAG_TEMP_5
# 361 "data//maps/FortreeCliffs/scripts.pory"
	return
# 362 "data//maps/FortreeCliffs/scripts.pory"

# 363 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DeclinedFlight::
# 364 "data//maps/FortreeCliffs/scripts.pory"
	special SpawnCameraObject                                                                               @ pan back down
# 365 "data//maps/FortreeCliffs/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, FortreeCliffs_Movement_CameraPanDown
# 366 "data//maps/FortreeCliffs/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 367 "data//maps/FortreeCliffs/scripts.pory"
	special RemoveCameraObject
# 368 "data//maps/FortreeCliffs/scripts.pory"
	release
# 369 "data//maps/FortreeCliffs/scripts.pory"
	end
# 370 "data//maps/FortreeCliffs/scripts.pory"

# 371 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_DidntGiveBerry::
# 372 "data//maps/FortreeCliffs/scripts.pory"
	return
# 373 "data//maps/FortreeCliffs/scripts.pory"

# 374 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja1::
# 375 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_1, FortreeCliffs_Text_Ninja1Intro, FortreeCliffs_Text_Ninja1Defeat
# 376 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja1PostBattle, MSGBOX_AUTOCLOSE
# 377 "data//maps/FortreeCliffs/scripts.pory"
	end
# 378 "data//maps/FortreeCliffs/scripts.pory"

# 379 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja2::
# 380 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_2, FortreeCliffs_Text_Ninja2Intro, FortreeCliffs_Text_Ninja2Defeat
# 381 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja2PostBattle, MSGBOX_AUTOCLOSE
# 382 "data//maps/FortreeCliffs/scripts.pory"
	end
# 383 "data//maps/FortreeCliffs/scripts.pory"

# 384 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja3::
# 385 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_3, FortreeCliffs_Text_Ninja3Intro, FortreeCliffs_Text_Ninja3Defeat
# 386 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja3PostBattle, MSGBOX_AUTOCLOSE
# 387 "data//maps/FortreeCliffs/scripts.pory"
	end
# 388 "data//maps/FortreeCliffs/scripts.pory"

# 389 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Expert1::
# 390 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_EXPERT_1, FortreeCliffs_Text_Expert1Intro, FortreeCliffs_Text_Expert1Defeat
# 391 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Expert1PostBattle, MSGBOX_AUTOCLOSE
# 392 "data//maps/FortreeCliffs/scripts.pory"
	end
# 393 "data//maps/FortreeCliffs/scripts.pory"

# 394 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja4::
# 395 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_4, FortreeCliffs_Text_Ninja4Intro, FortreeCliffs_Text_Ninja4Defeat
# 396 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja4PostBattle, MSGBOX_AUTOCLOSE
# 397 "data//maps/FortreeCliffs/scripts.pory"
	end
# 398 "data//maps/FortreeCliffs/scripts.pory"

# 399 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja5::
# 400 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_5, FortreeCliffs_Text_Ninja5Intro, FortreeCliffs_Text_Ninja5Defeat
# 401 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja5PostBattle, MSGBOX_AUTOCLOSE
# 402 "data//maps/FortreeCliffs/scripts.pory"
	end
# 403 "data//maps/FortreeCliffs/scripts.pory"

# 404 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ninja6::
# 405 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_NINJA_6, FortreeCliffs_Text_Ninja6Intro, FortreeCliffs_Text_Ninja6Defeat
# 406 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ninja6PostBattle, MSGBOX_AUTOCLOSE
# 407 "data//maps/FortreeCliffs/scripts.pory"
	end
# 408 "data//maps/FortreeCliffs/scripts.pory"

# 409 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_BirdKeeper1::
# 410 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_BIRDKEEPER_1, FortreeCliffs_Text_BirdKeeper1Intro, FortreeCliffs_Text_BirdKeeper1Defeat
# 411 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_BirdKeeper1PostBattle, MSGBOX_AUTOCLOSE
# 412 "data//maps/FortreeCliffs/scripts.pory"
	end
# 413 "data//maps/FortreeCliffs/scripts.pory"

# 414 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger1::
# 415 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_1, FortreeCliffs_Text_Ranger1Intro, FortreeCliffs_Text_Ranger1Defeat
# 416 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger1PostBattle, MSGBOX_AUTOCLOSE
# 417 "data//maps/FortreeCliffs/scripts.pory"
	end
# 418 "data//maps/FortreeCliffs/scripts.pory"

# 419 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Ranger2::
# 420 "data//maps/FortreeCliffs/scripts.pory"
	trainerbattle_single TRAINER_FORTREE_CLIFFS_RANGER_2, FortreeCliffs_Text_Ranger2Intro, FortreeCliffs_Text_Ranger2Defeat
# 421 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Ranger2PostBattle, MSGBOX_AUTOCLOSE
# 422 "data//maps/FortreeCliffs/scripts.pory"
	end
# 423 "data//maps/FortreeCliffs/scripts.pory"

# 424 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanUp:
# 425 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 426 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 427 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 428 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 429 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 430 "data//maps/FortreeCliffs/scripts.pory"

# 431 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_CameraPanDown:
# 432 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 433 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 434 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 435 "data//maps/FortreeCliffs/scripts.pory"
	walk_down
# 436 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 437 "data//maps/FortreeCliffs/scripts.pory"

# 438 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Movement_BraviaryFlyOff:
# 439 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 440 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 441 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 442 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 443 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 444 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 445 "data//maps/FortreeCliffs/scripts.pory"
	walk_up
# 446 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 447 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 448 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 449 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 450 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
# 451 "data//maps/FortreeCliffs/scripts.pory"
	slide_up
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
	walk_down
# 459 "data//maps/FortreeCliffs/scripts.pory"
	step_end
# 460 "data//maps/FortreeCliffs/scripts.pory"

# 461 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_SkepticalBraviary:
# 462 "data//maps/FortreeCliffs/scripts.pory"
	.string "This BRAVIARY is looking at you\n"
# 463 "data//maps/FortreeCliffs/scripts.pory"
	.string "with skepticism.\p"
# 464 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try offering it a BERRY?$"
# 465 "data//maps/FortreeCliffs/scripts.pory"

# 466 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_AskingToFly:
# 467 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you\n"
# 468 "data//maps/FortreeCliffs/scripts.pory"
	.string "approvingly.\p"
# 469 "data//maps/FortreeCliffs/scripts.pory"
	.string "Try asking for help navigating the\n" 
# 470 "data//maps/FortreeCliffs/scripts.pory"
	.string "cliffs?$"
# 471 "data//maps/FortreeCliffs/scripts.pory"

# 472 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BraviaryUninterested:
# 473 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY doesn't seem interested\n"
# 474 "data//maps/FortreeCliffs/scripts.pory"
	.string "this berry…$"
# 475 "data//maps/FortreeCliffs/scripts.pory"

# 476 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BadVibeRock:
# 477 "data//maps/FortreeCliffs/scripts.pory"
	.string "This rock gives off a bad vibe…$"
# 478 "data//maps/FortreeCliffs/scripts.pory"

# 479 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_FlewToTheNextNest:
# 480 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…$"
# 481 "data//maps/FortreeCliffs/scripts.pory"

# 482 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_WantsYouToFollow:
# 483 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY flew to another nest…\p"
# 484 "data//maps/FortreeCliffs/scripts.pory"
	.string "but it looks like it wants you to follow!$"
# 485 "data//maps/FortreeCliffs/scripts.pory"

# 486 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveFirstBerry:
# 487 "data//maps/FortreeCliffs/scripts.pory"
	.string "The harsh look in BRAVIARY's eyes\n"
# 488 "data//maps/FortreeCliffs/scripts.pory"
	.string "softened a bit.\p"
# 489 "data//maps/FortreeCliffs/scripts.pory"
	.string "You may be able to gain its trust!$"
# 490 "data//maps/FortreeCliffs/scripts.pory"

# 491 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveSecondBerry:
# 492 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY seems a bit more relaxed\n"
# 493 "data//maps/FortreeCliffs/scripts.pory"
	.string "in your presence.$"
# 494 "data//maps/FortreeCliffs/scripts.pory"

# 495 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_GaveThirdBerry:
# 496 "data//maps/FortreeCliffs/scripts.pory"
	.string "BRAVIARY is looking at you approvingly!$"
# 497 "data//maps/FortreeCliffs/scripts.pory"

# 498 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Intro:
# 499 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 500 "data//maps/FortreeCliffs/scripts.pory"

# 501 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1PostBattle:
# 502 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 503 "data//maps/FortreeCliffs/scripts.pory"

# 504 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja1Defeat:
# 505 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 506 "data//maps/FortreeCliffs/scripts.pory"

# 507 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Intro:
# 508 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 509 "data//maps/FortreeCliffs/scripts.pory"

# 510 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2PostBattle:
# 511 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 512 "data//maps/FortreeCliffs/scripts.pory"

# 513 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja2Defeat:
# 514 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 515 "data//maps/FortreeCliffs/scripts.pory"

# 516 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Intro:
# 517 "data//maps/FortreeCliffs/scripts.pory"
	.string "Our grandpa is annoying as heck!$"
# 518 "data//maps/FortreeCliffs/scripts.pory"

# 519 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3PostBattle:
# 520 "data//maps/FortreeCliffs/scripts.pory"
	.string "Ha! Idiot!$"
# 521 "data//maps/FortreeCliffs/scripts.pory"

# 522 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja3Defeat:
# 523 "data//maps/FortreeCliffs/scripts.pory"
	.string "You're annoying too!$"
# 524 "data//maps/FortreeCliffs/scripts.pory"

# 525 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Intro:
# 526 "data//maps/FortreeCliffs/scripts.pory"
	.string "Surprise! I've been studying KECLEON!$"
# 527 "data//maps/FortreeCliffs/scripts.pory"

# 528 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4PostBattle:
# 529 "data//maps/FortreeCliffs/scripts.pory"
	.string "My camouflage is perfect!$"
# 530 "data//maps/FortreeCliffs/scripts.pory"

# 531 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja4Defeat:
# 532 "data//maps/FortreeCliffs/scripts.pory"
	.string "$"
# 533 "data//maps/FortreeCliffs/scripts.pory"

# 534 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Intro:
# 535 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm the star pupil!$"
# 536 "data//maps/FortreeCliffs/scripts.pory"

# 537 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5PostBattle:
# 538 "data//maps/FortreeCliffs/scripts.pory"
	.string "That's why I'm Grandpa's favorite!$"
# 539 "data//maps/FortreeCliffs/scripts.pory"

# 540 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja5Defeat:
# 541 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm such a disappointment…$"
# 542 "data//maps/FortreeCliffs/scripts.pory"

# 543 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Intro:
# 544 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm trying to take it easy here!$"
# 545 "data//maps/FortreeCliffs/scripts.pory"

# 546 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6PostBattle:
# 547 "data//maps/FortreeCliffs/scripts.pory"
	.string "Resting pays off just as much as training.$"
# 548 "data//maps/FortreeCliffs/scripts.pory"

# 549 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ninja6Defeat:
# 550 "data//maps/FortreeCliffs/scripts.pory"
	.string "I guess I should be trying harder…$"
# 551 "data//maps/FortreeCliffs/scripts.pory"

# 552 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Intro:
# 553 "data//maps/FortreeCliffs/scripts.pory"
	.string "Training my grandchildren is rewarding,\n"
# 554 "data//maps/FortreeCliffs/scripts.pory"
	.string "but they can also be quite irksome!$"
# 555 "data//maps/FortreeCliffs/scripts.pory"

# 556 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1PostBattle:
# 557 "data//maps/FortreeCliffs/scripts.pory"
	.string "I'm always dealing with children…$"
# 558 "data//maps/FortreeCliffs/scripts.pory"

# 559 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Expert1Defeat:
# 560 "data//maps/FortreeCliffs/scripts.pory"
	.string "Finally, a fellow adult!$"
# 561 "data//maps/FortreeCliffs/scripts.pory"

# 562 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Intro:
# 563 "data//maps/FortreeCliffs/scripts.pory"
	.string "Do you have the right berries?$"
# 564 "data//maps/FortreeCliffs/scripts.pory"

# 565 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1PostBattle:
# 566 "data//maps/FortreeCliffs/scripts.pory"
	.string "Collect more berries, and learn their\n"
# 567 "data//maps/FortreeCliffs/scripts.pory"
	.string "effects.$"
# 568 "data//maps/FortreeCliffs/scripts.pory"

# 569 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger1Defeat:
# 570 "data//maps/FortreeCliffs/scripts.pory"
	.string "I need more berries now!$"
# 571 "data//maps/FortreeCliffs/scripts.pory"

# 572 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Intro:
# 573 "data//maps/FortreeCliffs/scripts.pory"
	.string "Are you prepared for this terrain?$"
# 574 "data//maps/FortreeCliffs/scripts.pory"

# 575 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2PostBattle:
# 576 "data//maps/FortreeCliffs/scripts.pory"
	.string "Before exploring far from town,\n"
# 577 "data//maps/FortreeCliffs/scripts.pory"
	.string "double check your supplies!$"
# 578 "data//maps/FortreeCliffs/scripts.pory"

# 579 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Ranger2Defeat:
# 580 "data//maps/FortreeCliffs/scripts.pory"
	.string "I wasn't prepared for this!$"
# 581 "data//maps/FortreeCliffs/scripts.pory"

# 582 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Intro:
# 583 "data//maps/FortreeCliffs/scripts.pory"
	.string "WINONA trains here, on the highest cliffs!$"
# 584 "data//maps/FortreeCliffs/scripts.pory"

# 585 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1PostBattle:
# 586 "data//maps/FortreeCliffs/scripts.pory"
	.string "I simply mirrored WINONA's training.$"
# 587 "data//maps/FortreeCliffs/scripts.pory"

# 588 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_BirdKeeper1Defeat:
# 589 "data//maps/FortreeCliffs/scripts.pory"
	.string "How does WINONA fly so high?$"
