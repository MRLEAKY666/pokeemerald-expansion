# 1 "data//maps/SootopolisCity/scripts.pory"

# 2 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_MapScripts::
# 3 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
# 4 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
# 5 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
# 6 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
# 7 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
# 8 "data//maps/SootopolisCity/scripts.pory"
	.byte 0
# 9 "data//maps/SootopolisCity/scripts.pory"

# 10 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnLoad:
# 11 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
# 12 "data//maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
# 13 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
# 14 "data//maps/SootopolisCity/scripts.pory"
	end
# 15 "data//maps/SootopolisCity/scripts.pory"

# 16 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesNotArrived::
# 17 "data//maps/SootopolisCity/scripts.pory"
	end
# 18 "data//maps/SootopolisCity/scripts.pory"

# 19 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockHouseDoors::
# 20 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 21 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 22 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
# 23 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 24 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
# 25 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
# 26 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 27 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
# 28 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
# 29 "data//maps/SootopolisCity/scripts.pory"
	return
# 30 "data//maps/SootopolisCity/scripts.pory"

# 31 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockGymDoor::
# 32 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
# 33 "data//maps/SootopolisCity/scripts.pory"
	return
# 34 "data//maps/SootopolisCity/scripts.pory"

# 35 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnTransition:
# 36 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 37 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 38 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 39 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetWeather
# 40 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetLayout
# 41 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8008, 8
# 42 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_DEFEATED_SOOTOPOLIS_GYM, Common_EventScript_ResetGymTrainers
# 43 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
# 44 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
# 45 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
# 46 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBirchMeteoriteCall
# 47 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
# 48 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
# 49 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 50 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 51 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
# 52 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
# 53 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
# 54 "data//maps/SootopolisCity/scripts.pory"
	end
# 55 "data//maps/SootopolisCity/scripts.pory"

# 56 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_HideMapNamePopup::
# 57 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 58 "data//maps/SootopolisCity/scripts.pory"
	return
# 59 "data//maps/SootopolisCity/scripts.pory"

# 60 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBattleSpectators::
# 61 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_KIRI, 13, 48
# 62 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
# 63 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
# 64 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
# 65 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
# 66 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
# 67 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
# 68 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
# 69 "data//maps/SootopolisCity/scripts.pory"
	return
# 70 "data//maps/SootopolisCity/scripts.pory"

# 71 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBirchMeteoriteCall::
# 72 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_BIRCH_METEORITE_CALL_STEP_COUNTER, 0
# 73 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_BIRCH_CALL_METEORITE
# 74 "data//maps/SootopolisCity/scripts.pory"
	return
# 75 "data//maps/SootopolisCity/scripts.pory"

# 76 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BirchRayquazaCall::
# 77 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 78 "data//maps/SootopolisCity/scripts.pory"
	pokenavcall MatchCall_Text_BirchRayquazaCall 
# 79 "data//maps/SootopolisCity/scripts.pory"
	waitmessage
# 80 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 81 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_BIRCH_CALL_METEORITE
# 82 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 83 "data//maps/SootopolisCity/scripts.pory"
	end
# 84 "data//maps/SootopolisCity/scripts.pory"

# 85 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLayout::
# 86 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
# 87 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
# 88 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 89 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
# 90 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
# 91 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
# 92 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 93 "data//maps/SootopolisCity/scripts.pory"
	return
# 94 "data//maps/SootopolisCity/scripts.pory"

# 95 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalLayout::
# 96 "data//maps/SootopolisCity/scripts.pory"
	return
# 97 "data//maps/SootopolisCity/scripts.pory"

# 98 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLegendariesLayout::
# 99 "data//maps/SootopolisCity/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
# 100 "data//maps/SootopolisCity/scripts.pory"
	return
# 101 "data//maps/SootopolisCity/scripts.pory"

# 102 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWeather::
# 103 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
# 104 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
# 105 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 106 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 107 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
# 108 "data//maps/SootopolisCity/scripts.pory"
	return
# 109 "data//maps/SootopolisCity/scripts.pory"

# 110 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalWeather::
# 111 "data//maps/SootopolisCity/scripts.pory"
	return
# 112 "data//maps/SootopolisCity/scripts.pory"

# 113 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetDownpour::
# 114 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_DOWNPOUR
# 115 "data//maps/SootopolisCity/scripts.pory"
	return
# 116 "data//maps/SootopolisCity/scripts.pory"

# 117 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
# 118 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
# 119 "data//maps/SootopolisCity/scripts.pory"
	return
# 120 "data//maps/SootopolisCity/scripts.pory"

# 121 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
# 122 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 123 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 124 "data//maps/SootopolisCity/scripts.pory"
	return
# 125 "data//maps/SootopolisCity/scripts.pory"

# 126 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
# 127 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 128 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
# 129 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 130 "data//maps/SootopolisCity/scripts.pory"
	end
# 131 "data//maps/SootopolisCity/scripts.pory"

# 132 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetOutsideGymObjPos::
# 133 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 134 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
# 135 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
# 136 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
# 137 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
# 138 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
# 139 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
# 140 "data//maps/SootopolisCity/scripts.pory"
	return
# 141 "data//maps/SootopolisCity/scripts.pory"

# 142 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceMiddle::
# 143 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
# 144 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 145 "data//maps/SootopolisCity/scripts.pory"
	return
# 146 "data//maps/SootopolisCity/scripts.pory"

# 147 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceRight::
# 148 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
# 149 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 150 "data//maps/SootopolisCity/scripts.pory"
	return
# 151 "data//maps/SootopolisCity/scripts.pory"

# 152 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceLeft::
# 153 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
# 154 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 155 "data//maps/SootopolisCity/scripts.pory"
	return
# 156 "data//maps/SootopolisCity/scripts.pory"

# 157 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
# 158 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
# 159 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 160 "data//maps/SootopolisCity/scripts.pory"
	return
# 161 "data//maps/SootopolisCity/scripts.pory"

# 162 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp:
# 163 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 164 "data//maps/SootopolisCity/scripts.pory"
	.2byte 0
# 165 "data//maps/SootopolisCity/scripts.pory"

# 166 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries::
# 167 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
# 168 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
# 169 "data//maps/SootopolisCity/scripts.pory"
	end
# 170 "data//maps/SootopolisCity/scripts.pory"

# 171 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1::
# 172 "data//maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 173 "data//maps/SootopolisCity/scripts.pory"
	return
# 174 "data//maps/SootopolisCity/scripts.pory"

# 175 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2::
# 176 "data//maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 177 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 178 "data//maps/SootopolisCity/scripts.pory"
	return
# 179 "data//maps/SootopolisCity/scripts.pory"

# 180 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume:
# 181 "data//maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
# 182 "data//maps/SootopolisCity/scripts.pory"
	end
# 183 "data//maps/SootopolisCity/scripts.pory"

# 184 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame:
# 185 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 186 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 187 "data//maps/SootopolisCity/scripts.pory"
	.2byte 0
# 188 "data//maps/SootopolisCity/scripts.pory"

# 189 "data//maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 190 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene::
# 191 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 192 "data//maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 193 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
# 194 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
# 195 "data//maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 196 "data//maps/SootopolisCity/scripts.pory"
	end
# 197 "data//maps/SootopolisCity/scripts.pory"

# 198 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
# 199 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 200 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 201 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 202 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 203 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 204 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 205 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 206 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 207 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 208 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 0 @ Just do Groudon/Kyogre fight scene
# 209 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 210 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 211 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 212 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 213 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 214 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 215 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 216 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 217 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 218 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 219 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 220 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 221 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 222 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 223 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 224 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 225 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 226 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 227 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 228 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 229 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 230 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 231 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 232 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 233 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 234 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 235 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 236 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 237 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 238 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 239 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 240 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 241 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 242 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 243 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 244 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 245 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 246 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 247 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 248 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 249 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 250 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 251 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 252 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 253 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 254 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 255 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 256 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 257 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 258 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 259 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 260 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 261 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 262 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 263 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 264 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 265 "data//maps/SootopolisCity/scripts.pory"
	end
# 266 "data//maps/SootopolisCity/scripts.pory"

# 267 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
# 268 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 269 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 270 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 271 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 272 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 273 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 274 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 275 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 276 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 277 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 278 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 279 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 280 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 281 "data//maps/SootopolisCity/scripts.pory"

# 282 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
# 283 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 284 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 285 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 286 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 287 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 288 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 289 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 290 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 291 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 292 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 293 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 294 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 295 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 296 "data//maps/SootopolisCity/scripts.pory"

# 297 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 298 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 299 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 300 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 301 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 302 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 303 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 304 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 305 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 306 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 307 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 0 @ Just do Groudon/Kyogre fight scene
# 308 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 309 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 310 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 311 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 312 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 313 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 314 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 315 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 316 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 317 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 318 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 319 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 320 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 321 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 322 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 323 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 324 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 325 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 326 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 327 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 328 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 329 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 330 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 331 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 332 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 333 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 334 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 335 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 336 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 337 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 338 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 339 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 340 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 341 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 342 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 343 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 344 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 345 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 346 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 347 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 348 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 349 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 350 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 351 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 352 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 353 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 354 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 355 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 356 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 357 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 358 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 359 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 360 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 361 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 362 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 363 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 364 "data//maps/SootopolisCity/scripts.pory"
	end
# 365 "data//maps/SootopolisCity/scripts.pory"

# 366 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 367 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 368 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 369 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 370 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 371 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 372 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 373 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 374 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 375 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 376 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 377 "data//maps/SootopolisCity/scripts.pory"

# 378 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
# 379 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 380 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 381 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 382 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 383 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 384 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 385 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 386 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 387 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 388 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 389 "data//maps/SootopolisCity/scripts.pory"

# 390 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 391 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 392 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 393 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 394 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 395 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 396 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 397 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 398 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 399 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 400 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 401 "data//maps/SootopolisCity/scripts.pory"

# 402 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
# 403 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 404 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 405 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 406 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 407 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 408 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 409 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 410 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 411 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 412 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 413 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 414 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 415 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 416 "data//maps/SootopolisCity/scripts.pory"

# 417 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 418 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 419 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 420 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 421 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 422 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 423 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 424 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 425 "data//maps/SootopolisCity/scripts.pory"

# 426 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 427 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 428 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 429 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 430 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 431 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 432 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 433 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 434 "data//maps/SootopolisCity/scripts.pory"

# 435 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 436 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 437 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 438 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 439 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 440 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 441 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 442 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 443 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 444 "data//maps/SootopolisCity/scripts.pory"

# 445 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
# 446 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 447 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 448 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 449 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 450 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 451 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 452 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 453 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 454 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 455 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 456 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 457 "data//maps/SootopolisCity/scripts.pory"

# 458 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 459 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 460 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 461 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 462 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 463 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 464 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 465 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 466 "data//maps/SootopolisCity/scripts.pory"

# 467 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 468 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 469 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 470 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 471 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 472 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 473 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 474 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 475 "data//maps/SootopolisCity/scripts.pory"

# 476 "data//maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 477 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 478 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 479 "data//maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 480 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 481 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 482 "data//maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 483 "data//maps/SootopolisCity/scripts.pory"
	end
# 484 "data//maps/SootopolisCity/scripts.pory"

# 485 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 486 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 487 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 488 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 489 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 490 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 491 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 492 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 493 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 494 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 495 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 496 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 497 "data//maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 498 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle
# 499 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1                                                                      @ 0 ends early, 1 has battle, 2 is vanilla 
# 500 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 501 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle
# 502 "data//maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 503 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 504 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 505 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 506 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 507 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 508 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 509 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 510 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 511 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 512 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 513 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 514 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 515 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 516 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 517 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 518 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 519 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 520 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 521 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 522 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 523 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 524 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 525 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 526 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 527 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 528 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 529 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 530 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 531 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 532 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 533 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 534 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 535 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 536 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 537 "data//maps/SootopolisCity/scripts.pory"
	end
# 538 "data//maps/SootopolisCity/scripts.pory"

# 539 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 540 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 541 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 542 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 543 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 544 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 545 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 546 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 547 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 548 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 549 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 550 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 551 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle
# 552 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1                                                                      @ 0 ends early, 1 has battle, 2 is vanilla 
# 553 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 554 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle
# 555 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 556 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 557 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 558 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 559 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 560 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 561 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 562 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 563 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 564 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 565 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 566 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 567 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 568 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 569 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 570 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 571 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 572 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 573 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 574 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 575 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 576 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 577 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 578 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 579 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 580 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 581 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 582 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 583 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 584 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 585 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 586 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 587 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 588 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 589 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 590 "data//maps/SootopolisCity/scripts.pory"
	end
# 591 "data//maps/SootopolisCity/scripts.pory"
	
# 592 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle::
# 593 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPLIS_BATTLE_ACTIVE
# 594 "data//maps/SootopolisCity/scripts.pory"
	special SavePlayerParty
# 595 "data//maps/SootopolisCity/scripts.pory"
	special ZeroPlayerPartyMons
# 596 "data//maps/SootopolisCity/scripts.pory"
	setwilddoubleflag
# 597 "data//maps/SootopolisCity/scripts.pory"
	givemon SPECIES_RAYQUAZA, 70, item=ITEM_METEORITE, move1=MOVE_FLY, move2=MOVE_REST, move3=MOVE_DRAGON_DANCE, move4=MOVE_EXTREMESPEED, speedIv=0
# 598 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_TEMP_NO_CATCHING
# 599 "data//maps/SootopolisCity/scripts.pory"
	@ setflag FLAG_TEMP_SMART_WILD_AI
# 600 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_TEMP_NO_RUNNING
# 601 "data//maps/SootopolisCity/scripts.pory"
	@ settotemboost 0, atk=2,speed=2,evas=2
# 602 "data//maps/SootopolisCity/scripts.pory"
	@ createmon 0, 0, SPECIES_RAYQUAZA, 70, item=ITEM_CHESTO_BERRY, move1=MOVE_FLY, move2=MOVE_REST, move3=MOVE_DRAGON_DANCE, move4=MOVE_EXTREMESPEED, speedIv=0
# 603 "data//maps/SootopolisCity/scripts.pory"
	createmon 1, 1, SPECIES_GROUDON, 70, item=ITEM_RED_ORB, move1=MOVE_ANCIENT_POWER, move2=MOVE_LAVA_PLUME, move3=MOVE_BULK_UP, move4=MOVE_FISSURE, speedIv=31
# 604 "data//maps/SootopolisCity/scripts.pory"
	createmon 1, 3, SPECIES_KYOGRE, 70, item=ITEM_BLUE_ORB, move1=MOVE_CALM_MIND, move2=MOVE_ANCIENT_POWER, move3=MOVE_SURF, move4=MOVE_SHEER_COLD,  speedIv=31
# 605 "data//maps/SootopolisCity/scripts.pory"
	return
# 606 "data//maps/SootopolisCity/scripts.pory"

# 607 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle::
# 608 "data//maps/SootopolisCity/scripts.pory"
	special LoadPlayerParty
# 609 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SOOTOPLIS_BATTLE_ACTIVE
# 610 "data//maps/SootopolisCity/scripts.pory"
	return
# 611 "data//maps/SootopolisCity/scripts.pory"

# 612 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 613 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 614 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 615 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 616 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 617 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 618 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 619 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 620 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 621 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 622 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 623 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 624 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 625 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 626 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 627 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 628 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 629 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 630 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 631 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 632 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 633 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 634 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 635 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 636 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 637 "data//maps/SootopolisCity/scripts.pory"
	return
# 638 "data//maps/SootopolisCity/scripts.pory"

# 639 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 640 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 641 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 642 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 643 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 644 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 645 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 646 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 647 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 648 "data//maps/SootopolisCity/scripts.pory"

# 649 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 650 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 651 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 652 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 653 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 654 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 655 "data//maps/SootopolisCity/scripts.pory"

# 656 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 657 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 658 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 659 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 660 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 661 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 662 "data//maps/SootopolisCity/scripts.pory"

# 663 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 664 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 665 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 666 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 667 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 668 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 669 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 670 "data//maps/SootopolisCity/scripts.pory"

# 671 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 672 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
# 673 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 674 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 675 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 676 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 677 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 678 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 679 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 680 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 681 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 682 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 683 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 684 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 685 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 686 "data//maps/SootopolisCity/scripts.pory"

# 687 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 688 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
# 689 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 690 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 691 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 692 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 693 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 694 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 695 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 696 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 697 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 698 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 699 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 700 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 701 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 702 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 703 "data//maps/SootopolisCity/scripts.pory"

# 704 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 705 "data//maps/SootopolisCity/scripts.pory"
	lock
# 706 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 707 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 708 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 709 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 710 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 711 "data//maps/SootopolisCity/scripts.pory"
	release
# 712 "data//maps/SootopolisCity/scripts.pory"
	end
# 713 "data//maps/SootopolisCity/scripts.pory"

# 714 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 715 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 716 "data//maps/SootopolisCity/scripts.pory"
	release
# 717 "data//maps/SootopolisCity/scripts.pory"
	end
# 718 "data//maps/SootopolisCity/scripts.pory"

# 719 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 720 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 721 "data//maps/SootopolisCity/scripts.pory"
	release
# 722 "data//maps/SootopolisCity/scripts.pory"
	end
# 723 "data//maps/SootopolisCity/scripts.pory"

# 724 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 725 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 726 "data//maps/SootopolisCity/scripts.pory"
	release
# 727 "data//maps/SootopolisCity/scripts.pory"
	end
# 728 "data//maps/SootopolisCity/scripts.pory"

# 729 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 730 "data//maps/SootopolisCity/scripts.pory"
	lock
# 731 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 732 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 733 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 734 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 735 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 736 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 737 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 738 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 739 "data//maps/SootopolisCity/scripts.pory"
	release
# 740 "data//maps/SootopolisCity/scripts.pory"
	end
# 741 "data//maps/SootopolisCity/scripts.pory"

# 742 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 743 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 744 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 745 "data//maps/SootopolisCity/scripts.pory"
	release
# 746 "data//maps/SootopolisCity/scripts.pory"
	end
# 747 "data//maps/SootopolisCity/scripts.pory"

# 748 "data//maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from BERRY_ID_POMEG to BERRY_ID_NOMEL, second is always Figy or Iapapa
# 749 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 750 "data//maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 751 "data//maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 752 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 753 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 754 "data//maps/SootopolisCity/scripts.pory"
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 755 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 756 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 757 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 758 "data//maps/SootopolisCity/scripts.pory"
	random 2
# 759 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 760 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 761 "data//maps/SootopolisCity/scripts.pory"
	end
# 762 "data//maps/SootopolisCity/scripts.pory"

# 763 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 764 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 765 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 766 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 767 "data//maps/SootopolisCity/scripts.pory"
	release
# 768 "data//maps/SootopolisCity/scripts.pory"
	end
# 769 "data//maps/SootopolisCity/scripts.pory"

# 770 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 771 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 772 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 773 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 774 "data//maps/SootopolisCity/scripts.pory"
	release
# 775 "data//maps/SootopolisCity/scripts.pory"
	end
# 776 "data//maps/SootopolisCity/scripts.pory"

# 777 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 778 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 779 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 780 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 781 "data//maps/SootopolisCity/scripts.pory"
	release
# 782 "data//maps/SootopolisCity/scripts.pory"
	end
# 783 "data//maps/SootopolisCity/scripts.pory"

# 784 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 785 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 786 "data//maps/SootopolisCity/scripts.pory"
	release
# 787 "data//maps/SootopolisCity/scripts.pory"
	end
# 788 "data//maps/SootopolisCity/scripts.pory"

# 789 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 790 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 791 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
# 792 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 793 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 794 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 795 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 796 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
# 797 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 798 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 799 "data//maps/SootopolisCity/scripts.pory"
	end
# 800 "data//maps/SootopolisCity/scripts.pory"

# 801 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 802 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 803 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 804 "data//maps/SootopolisCity/scripts.pory"
	end
# 805 "data//maps/SootopolisCity/scripts.pory"

# 806 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 807 "data//maps/SootopolisCity/scripts.pory"
	lock
# 808 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 809 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 810 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 811 "data//maps/SootopolisCity/scripts.pory"
	release
# 812 "data//maps/SootopolisCity/scripts.pory"
	end
# 813 "data//maps/SootopolisCity/scripts.pory"

# 814 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 815 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 816 "data//maps/SootopolisCity/scripts.pory"
	release
# 817 "data//maps/SootopolisCity/scripts.pory"
	end
# 818 "data//maps/SootopolisCity/scripts.pory"

# 819 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 820 "data//maps/SootopolisCity/scripts.pory"
	lock
# 821 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 822 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 823 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 824 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 825 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 826 "data//maps/SootopolisCity/scripts.pory"
	release
# 827 "data//maps/SootopolisCity/scripts.pory"
	end
# 828 "data//maps/SootopolisCity/scripts.pory"

# 829 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 830 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 831 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 832 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
# 833 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 834 "data//maps/SootopolisCity/scripts.pory"
	release
# 835 "data//maps/SootopolisCity/scripts.pory"
	end
# 836 "data//maps/SootopolisCity/scripts.pory"

# 837 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 838 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 839 "data//maps/SootopolisCity/scripts.pory"
	release
# 840 "data//maps/SootopolisCity/scripts.pory"
	end
# 841 "data//maps/SootopolisCity/scripts.pory"

# 842 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 843 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 844 "data//maps/SootopolisCity/scripts.pory"
	release
# 845 "data//maps/SootopolisCity/scripts.pory"
	end
# 846 "data//maps/SootopolisCity/scripts.pory"

# 847 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 848 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 849 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
# 850 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 851 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 852 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 853 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 854 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 855 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 856 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 857 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 858 "data//maps/SootopolisCity/scripts.pory"
	release
# 859 "data//maps/SootopolisCity/scripts.pory"
	end
# 860 "data//maps/SootopolisCity/scripts.pory"

# 861 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 862 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 863 "data//maps/SootopolisCity/scripts.pory"
	release
# 864 "data//maps/SootopolisCity/scripts.pory"
	end
# 865 "data//maps/SootopolisCity/scripts.pory"

# 866 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 867 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 868 "data//maps/SootopolisCity/scripts.pory"
	release
# 869 "data//maps/SootopolisCity/scripts.pory"
	end
# 870 "data//maps/SootopolisCity/scripts.pory"

# 871 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 872 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 873 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
# 874 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 875 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 876 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 877 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 878 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 879 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 880 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 881 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
# 882 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 883 "data//maps/SootopolisCity/scripts.pory"
	release
# 884 "data//maps/SootopolisCity/scripts.pory"
	end
# 885 "data//maps/SootopolisCity/scripts.pory"

# 886 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 887 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 888 "data//maps/SootopolisCity/scripts.pory"
	release
# 889 "data//maps/SootopolisCity/scripts.pory"
	end
# 890 "data//maps/SootopolisCity/scripts.pory"

# 891 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 892 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 893 "data//maps/SootopolisCity/scripts.pory"
	release
# 894 "data//maps/SootopolisCity/scripts.pory"
	end
# 895 "data//maps/SootopolisCity/scripts.pory"

# 896 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 897 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 898 "data//maps/SootopolisCity/scripts.pory"
	release
# 899 "data//maps/SootopolisCity/scripts.pory"
	end
# 900 "data//maps/SootopolisCity/scripts.pory"

# 901 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 902 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 903 "data//maps/SootopolisCity/scripts.pory"
	end
# 904 "data//maps/SootopolisCity/scripts.pory"

# 905 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 906 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 907 "data//maps/SootopolisCity/scripts.pory"
	end
# 908 "data//maps/SootopolisCity/scripts.pory"

# 909 "data//maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 910 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 911 "data//maps/SootopolisCity/scripts.pory"
	end
# 912 "data//maps/SootopolisCity/scripts.pory"

# 913 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 914 "data//maps/SootopolisCity/scripts.pory"
	lock
# 915 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
# 916 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 917 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 918 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 919 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 920 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 921 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 922 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 923 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 924 "data//maps/SootopolisCity/scripts.pory"
	end
# 925 "data//maps/SootopolisCity/scripts.pory"

# 926 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 927 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 928 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 929 "data//maps/SootopolisCity/scripts.pory"
	end
# 930 "data//maps/SootopolisCity/scripts.pory"

# 931 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 932 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 933 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 934 "data//maps/SootopolisCity/scripts.pory"
	end
# 935 "data//maps/SootopolisCity/scripts.pory"

# 936 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 937 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 938 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 939 "data//maps/SootopolisCity/scripts.pory"
	end
# 940 "data//maps/SootopolisCity/scripts.pory"

# 941 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 942 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 943 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 944 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 945 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 946 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 947 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 948 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 949 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 950 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 951 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 952 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 953 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 954 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 955 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 956 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 957 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 958 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 959 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 960 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 961 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 962 "data//maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 963 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 964 "data//maps/SootopolisCity/scripts.pory"
	end
# 965 "data//maps/SootopolisCity/scripts.pory"

# 966 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 967 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 968 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 969 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 970 "data//maps/SootopolisCity/scripts.pory"
	return
# 971 "data//maps/SootopolisCity/scripts.pory"

# 972 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 973 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 974 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 975 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 976 "data//maps/SootopolisCity/scripts.pory"
	return
# 977 "data//maps/SootopolisCity/scripts.pory"

# 978 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 979 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 980 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 981 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 982 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 983 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 984 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 985 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 986 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 987 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 988 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 989 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 990 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 991 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 992 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 993 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 994 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 995 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 996 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 997 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 998 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 999 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1000 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1001 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1002 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1003 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1004 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1005 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1006 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1007 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1008 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1009 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1010 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1011 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1012 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1013 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1014 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1015 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1016 "data//maps/SootopolisCity/scripts.pory"

# 1017 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 1018 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1019 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1020 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1021 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1023 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1024 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1025 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1026 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1027 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1028 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1029 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1030 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1031 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1032 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1033 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1034 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1035 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1036 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1037 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1038 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1040 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1041 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1042 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1043 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1044 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1045 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1046 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1047 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1048 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1049 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1050 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1051 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1052 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1053 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1054 "data//maps/SootopolisCity/scripts.pory"

# 1055 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1056 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1057 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1058 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1059 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1060 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1061 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1062 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1063 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1064 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1065 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1066 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1067 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1068 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1069 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1070 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1071 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1072 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1073 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1074 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1075 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1076 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1077 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1078 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1079 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1080 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1081 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1082 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1083 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1084 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1085 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1086 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1087 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1088 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1089 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1090 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1091 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1092 "data//maps/SootopolisCity/scripts.pory"

# 1093 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1094 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1095 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1096 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1097 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1098 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1099 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1100 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1101 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1102 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1103 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1104 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1105 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1106 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1107 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1108 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1109 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1110 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1111 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1112 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1113 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1114 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1115 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1116 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1117 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1118 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1119 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1120 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1121 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1122 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1123 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1124 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1125 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1126 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1127 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1128 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1129 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1130 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1131 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1132 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1133 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1134 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1135 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1136 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1137 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1138 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1139 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1140 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1141 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1142 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1143 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1144 "data//maps/SootopolisCity/scripts.pory"
	delay_4
# 1145 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1146 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1147 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1148 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1149 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1150 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1151 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1152 "data//maps/SootopolisCity/scripts.pory"

# 1153 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1154 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1155 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1156 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1157 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1158 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1159 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1160 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1161 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1162 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1163 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1164 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1165 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1166 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1167 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1168 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1169 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1170 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1171 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1172 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1173 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1174 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1175 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1176 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1177 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1178 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1179 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1180 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1181 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1182 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1183 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1184 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1185 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1186 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1187 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1188 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1189 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1190 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1191 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1192 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1193 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1194 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1195 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1196 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1197 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1198 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1199 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1200 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1201 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1202 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1203 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1204 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1205 "data//maps/SootopolisCity/scripts.pory"

# 1206 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1207 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1208 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1209 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1210 "data//maps/SootopolisCity/scripts.pory"

# 1211 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1212 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1213 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1214 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1215 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1216 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1217 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1218 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1219 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1220 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1221 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1222 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1223 "data//maps/SootopolisCity/scripts.pory"

# 1224 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1225 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1226 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1227 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1228 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1229 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1230 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1231 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1232 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1233 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1234 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1235 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1236 "data//maps/SootopolisCity/scripts.pory"

# 1237 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1238 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1239 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1240 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1241 "data//maps/SootopolisCity/scripts.pory"

# 1242 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1243 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1244 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
# 1245 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1246 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1247 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1248 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1249 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
# 1250 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1251 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1252 "data//maps/SootopolisCity/scripts.pory"
	end
# 1253 "data//maps/SootopolisCity/scripts.pory"

# 1254 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1255 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1256 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1257 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1258 "data//maps/SootopolisCity/scripts.pory"
	end
# 1259 "data//maps/SootopolisCity/scripts.pory"

# 1260 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1261 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1262 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1263 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1264 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1265 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1266 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1267 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1268 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1269 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1270 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1271 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1272 "data//maps/SootopolisCity/scripts.pory"
	end
# 1273 "data//maps/SootopolisCity/scripts.pory"

# 1274 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1275 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1276 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1277 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1278 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1279 "data//maps/SootopolisCity/scripts.pory"
	end
# 1280 "data//maps/SootopolisCity/scripts.pory"

# 1281 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1282 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1283 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
# 1284 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1285 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1286 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1287 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1288 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
# 1289 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1290 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1291 "data//maps/SootopolisCity/scripts.pory"
	end
# 1292 "data//maps/SootopolisCity/scripts.pory"

# 1293 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1294 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1295 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1296 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1297 "data//maps/SootopolisCity/scripts.pory"
	end
# 1298 "data//maps/SootopolisCity/scripts.pory"

# 1299 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1300 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1301 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
# 1302 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1303 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1304 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1305 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1306 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
# 1307 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1308 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1309 "data//maps/SootopolisCity/scripts.pory"
	end
# 1310 "data//maps/SootopolisCity/scripts.pory"

# 1311 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1312 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1313 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1314 "data//maps/SootopolisCity/scripts.pory"
	end
# 1315 "data//maps/SootopolisCity/scripts.pory"

# 1316 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1317 "data//maps/SootopolisCity/scripts.pory"
	lock
# 1318 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 1319 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1320 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1321 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1322 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1323 "data//maps/SootopolisCity/scripts.pory"
	release
# 1324 "data//maps/SootopolisCity/scripts.pory"
	end
# 1325 "data//maps/SootopolisCity/scripts.pory"

# 1326 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1327 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1328 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1329 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1330 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1331 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1332 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1333 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1334 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1335 "data//maps/SootopolisCity/scripts.pory"
	release
# 1336 "data//maps/SootopolisCity/scripts.pory"
	end
# 1337 "data//maps/SootopolisCity/scripts.pory"

# 1338 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1339 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1340 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1341 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1342 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1343 "data//maps/SootopolisCity/scripts.pory"
	return
# 1344 "data//maps/SootopolisCity/scripts.pory"

# 1345 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1346 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1347 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1348 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1349 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1350 "data//maps/SootopolisCity/scripts.pory"
	return
# 1351 "data//maps/SootopolisCity/scripts.pory"

# 1352 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1353 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1354 "data//maps/SootopolisCity/scripts.pory"
	release
# 1355 "data//maps/SootopolisCity/scripts.pory"
	end
# 1356 "data//maps/SootopolisCity/scripts.pory"

# 1357 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1358 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1359 "data//maps/SootopolisCity/scripts.pory"
	release
# 1360 "data//maps/SootopolisCity/scripts.pory"
	end
# 1361 "data//maps/SootopolisCity/scripts.pory"

# 1362 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1363 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1364 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1365 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1366 "data//maps/SootopolisCity/scripts.pory"

# 1367 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1368 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1369 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1370 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1371 "data//maps/SootopolisCity/scripts.pory"

# 1372 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1373 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1374 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1375 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1376 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1377 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1378 "data//maps/SootopolisCity/scripts.pory"
	end
# 1379 "data//maps/SootopolisCity/scripts.pory"

# 1380 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1381 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1382 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1383 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1384 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1385 "data//maps/SootopolisCity/scripts.pory"
	end
# 1386 "data//maps/SootopolisCity/scripts.pory"

# 1387 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1388 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1389 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1390 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1391 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1392 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1393 "data//maps/SootopolisCity/scripts.pory"
	end
# 1394 "data//maps/SootopolisCity/scripts.pory"

# 1395 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1396 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1397 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1398 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1399 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1400 "data//maps/SootopolisCity/scripts.pory"
	end
# 1401 "data//maps/SootopolisCity/scripts.pory"

# 1402 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1403 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1404 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1405 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1406 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1407 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1408 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1409 "data//maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1410 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 1411 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1412 "data//maps/SootopolisCity/scripts.pory"
	end
# 1413 "data//maps/SootopolisCity/scripts.pory"

# 1414 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1415 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1416 "data//maps/SootopolisCity/scripts.pory"
	levitate
# 1417 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1418 "data//maps/SootopolisCity/scripts.pory"

# 1419 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1420 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1421 "data//maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1422 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1423 "data//maps/SootopolisCity/scripts.pory"

# 1424 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1425 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
# 1426 "data//maps/SootopolisCity/scripts.pory"
	.string "LEADER: JUAN\p"
# 1427 "data//maps/SootopolisCity/scripts.pory"
	.string "“The GYM LEADER with the beauty\n"
# 1428 "data//maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1429 "data//maps/SootopolisCity/scripts.pory"

# 1430 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1431 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY\p"
# 1432 "data//maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1433 "data//maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1434 "data//maps/SootopolisCity/scripts.pory"

# 1435 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1436 "data//maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1437 "data//maps/SootopolisCity/scripts.pory"

# 1438 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1439 "data//maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1440 "data//maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1441 "data//maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1442 "data//maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1443 "data//maps/SootopolisCity/scripts.pory"

# 1444 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1445 "data//maps/SootopolisCity/scripts.pory"
	.string "These giant POKéMON suddenly appeared\n"
# 1446 "data//maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1447 "data//maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1448 "data//maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1449 "data//maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1450 "data//maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1451 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1452 "data//maps/SootopolisCity/scripts.pory"

# 1453 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1454 "data//maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1455 "data//maps/SootopolisCity/scripts.pory"
	.string "What is that green POKéMON?!$"
# 1456 "data//maps/SootopolisCity/scripts.pory"

# 1457 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1458 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON and KYOGRE…\n"
# 1459 "data//maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1460 "data//maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1461 "data//maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1462 "data//maps/SootopolisCity/scripts.pory"

# 1463 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1464 "data//maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1465 "data//maps/SootopolisCity/scripts.pory"
	.string "the two POKéMON aren't angry.\p"
# 1466 "data//maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1467 "data//maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1468 "data//maps/SootopolisCity/scripts.pory"

# 1469 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1470 "data//maps/SootopolisCity/scripts.pory"
	.string "That flying POKéMON came down from\n"
# 1471 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1472 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON…$"
# 1473 "data//maps/SootopolisCity/scripts.pory"

# 1474 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1475 "data//maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1476 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1477 "data//maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1478 "data//maps/SootopolisCity/scripts.pory"

# 1479 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1480 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1481 "data//maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1482 "data//maps/SootopolisCity/scripts.pory"

# 1483 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1484 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1485 "data//maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1486 "data//maps/SootopolisCity/scripts.pory"

# 1487 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1488 "data//maps/SootopolisCity/scripts.pory"
	.string "Go for it, red POKéMON!\n"
# 1489 "data//maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue POKéMON!$"
# 1490 "data//maps/SootopolisCity/scripts.pory"

# 1491 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1492 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1493 "data//maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1494 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON fighting over there?$"
# 1495 "data//maps/SootopolisCity/scripts.pory"

# 1496 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1497 "data//maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1498 "data//maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1499 "data//maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1500 "data//maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1501 "data//maps/SootopolisCity/scripts.pory"

# 1502 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1503 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1504 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1505 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1506 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1507 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1508 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1509 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1510 "data//maps/SootopolisCity/scripts.pory"

# 1511 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1512 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1513 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1514 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1515 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1516 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1517 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1518 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1519 "data//maps/SootopolisCity/scripts.pory"

# 1520 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1521 "data//maps/SootopolisCity/scripts.pory"
	.string "A big POKéMON is fighting with\n"
# 1522 "data//maps/SootopolisCity/scripts.pory"
	.string "another big POKéMON!\p"
# 1523 "data//maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1524 "data//maps/SootopolisCity/scripts.pory"

# 1525 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1526 "data//maps/SootopolisCity/scripts.pory"
	.string "A pretty POKéMON came down from\n"
# 1527 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1528 "data//maps/SootopolisCity/scripts.pory"

# 1529 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1530 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1531 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY will get wrecked!$"
# 1532 "data//maps/SootopolisCity/scripts.pory"

# 1533 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1534 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
# 1535 "data//maps/SootopolisCity/scripts.pory"

# 1536 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1537 "data//maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1538 "data//maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to SOOTOPOLIS?\l"
# 1539 "data//maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1540 "data//maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1541 "data//maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1542 "data//maps/SootopolisCity/scripts.pory"

# 1543 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1544 "data//maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1545 "data//maps/SootopolisCity/scripts.pory"

# 1546 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1547 "data//maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1548 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN.\p"
# 1549 "data//maps/SootopolisCity/scripts.pory"
	.string "The spirits of POKéMON, becalmed at\n"
# 1550 "data//maps/SootopolisCity/scripts.pory"
	.string "MT. PYRE, are said to be revived here.\p"
# 1551 "data//maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1552 "data//maps/SootopolisCity/scripts.pory"

# 1553 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1554 "data//maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1555 "data//maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1556 "data//maps/SootopolisCity/scripts.pory"
	.string "A TRAINER who has knowledge and\n"
# 1557 "data//maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of POKéMON…\p"
# 1558 "data//maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1559 "data//maps/SootopolisCity/scripts.pory"
	.string "instructed by WALLACE to lead that\l"
# 1560 "data//maps/SootopolisCity/scripts.pory"
	.string "TRAINER to this CAVE.$"
# 1561 "data//maps/SootopolisCity/scripts.pory"

# 1562 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1563 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1564 "data//maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1565 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON was quelled by the awakening\l"
# 1566 "data//maps/SootopolisCity/scripts.pory"
	.string "of a third POKéMON…$"
# 1567 "data//maps/SootopolisCity/scripts.pory"

# 1568 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1569 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN…\p"
# 1570 "data//maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1571 "data//maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1572 "data//maps/SootopolisCity/scripts.pory"

# 1573 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1574 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS sprang up as a town in\n"
# 1575 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1576 "data//maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1577 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1578 "data//maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1579 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1580 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS the most beautiful.$"
# 1581 "data//maps/SootopolisCity/scripts.pory"

# 1582 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1583 "data//maps/SootopolisCity/scripts.pory"
	.string "When two POKéMON that gigantic\n"
# 1584 "data//maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1585 "data//maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1586 "data//maps/SootopolisCity/scripts.pory"

# 1587 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1588 "data//maps/SootopolisCity/scripts.pory"
	.string "When that third POKéMON flew down,\n"
# 1589 "data//maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1590 "data//maps/SootopolisCity/scripts.pory"

# 1591 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1592 "data//maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1593 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1594 "data//maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1595 "data//maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1596 "data//maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1597 "data//maps/SootopolisCity/scripts.pory"

# 1598 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1599 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1600 "data//maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1601 "data//maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1602 "data//maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1603 "data//maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1604 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1605 "data//maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1606 "data//maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1607 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1608 "data//maps/SootopolisCity/scripts.pory"

# 1609 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1610 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1611 "data//maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1612 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON here?\p"
# 1613 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1614 "data//maps/SootopolisCity/scripts.pory"

# 1615 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1616 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: G… GROUDON…\n"
# 1617 "data//maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1618 "data//maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1619 "data//maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all HOENN, not just\n"
# 1620 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS, will be utterly ruined!$"
# 1621 "data//maps/SootopolisCity/scripts.pory"

# 1622 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1623 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: So the super-ancient POKéMON\n"
# 1624 "data//maps/SootopolisCity/scripts.pory"
	.string "weren't only GROUDON and KYOGRE…\p"
# 1625 "data//maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1626 "data//maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one POKéMON's\l"
# 1627 "data//maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1628 "data//maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1629 "data//maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1630 "data//maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1631 "data//maps/SootopolisCity/scripts.pory"

# 1632 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1633 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
# 1634 "data//maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the RED ORB!\l"
# 1635 "data//maps/SootopolisCity/scripts.pory"
	.string "Calm down! KYOGRE!\p"
# 1636 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1637 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1638 "data//maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1639 "data//maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1640 "data//maps/SootopolisCity/scripts.pory"

# 1641 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1642 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE and GROUDON both\n"
# 1643 "data//maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1644 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather in HOENN has returned\n"
# 1645 "data//maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1646 "data//maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1647 "data//maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1648 "data//maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1649 "data//maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1650 "data//maps/SootopolisCity/scripts.pory"
	.string "to POKéMON…$"
# 1651 "data//maps/SootopolisCity/scripts.pory"

# 1652 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1653 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Those POKéMON fighting…\n"
# 1654 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON… And KYOGRE…\p"
# 1655 "data//maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient POKéMON\n"
# 1656 "data//maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1657 "data//maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1658 "data//maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1659 "data//maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1660 "data//maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1661 "data//maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1662 "data//maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1663 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1664 "data//maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1665 "data//maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1666 "data//maps/SootopolisCity/scripts.pory"

# 1667 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1668 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
# 1669 "data//maps/SootopolisCity/scripts.pory"
	.string "Does seeing GROUDON and KYOGRE make\n"
# 1670 "data//maps/SootopolisCity/scripts.pory"
	.string "you think POKéMON are to be feared?\p"
# 1671 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1672 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON are really more…\p"
# 1673 "data//maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1674 "data//maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1675 "data//maps/SootopolisCity/scripts.pory"

# 1676 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1677 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Okay, here we are!\p"
# 1678 "data//maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1679 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE.\p"
# 1680 "data//maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1681 "data//maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1682 "data//maps/SootopolisCity/scripts.pory"

# 1683 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1684 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: I think you have what's\n"
# 1685 "data//maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1686 "data//maps/SootopolisCity/scripts.pory"

# 1687 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1688 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: The SKY PILLAR…\p"
# 1689 "data//maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1690 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1691 "data//maps/SootopolisCity/scripts.pory"

# 1692 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1693 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: So that's RAYQUAZA…\p"
# 1694 "data//maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1695 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON would flee from it in fear…$"
# 1696 "data//maps/SootopolisCity/scripts.pory"

# 1697 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1698 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: It looks like both MAXIE and\n"
# 1699 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE have gone away somewhere.\p"
# 1700 "data//maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to MT. PYRE to\n"
# 1701 "data//maps/SootopolisCity/scripts.pory"
	.string "return those ORBS…$"
# 1702 "data//maps/SootopolisCity/scripts.pory"

# 1703 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenGiveDevonScope:
# 1704 "data//maps/SootopolisCity/scripts.pory"
	.string "RAYQUAZA seemingly flew off towards\n"
# 1705 "data//maps/SootopolisCity/scripts.pory"
	.string "the forests around FORTREE CITY.\p"
# 1706 "data//maps/SootopolisCity/scripts.pory"
	.string "If you're going to track it down\n"
# 1707 "data//maps/SootopolisCity/scripts.pory"
	.string "you'll need this DEVON SCOPE.\p"
# 1708 "data//maps/SootopolisCity/scripts.pory"
	.string "A POKéMON called KECLEON makes\n"
# 1709 "data//maps/SootopolisCity/scripts.pory"
	.string "that area hard to navigate . . .\p"
# 1710 "data//maps/SootopolisCity/scripts.pory"
	.string "the DEVON SCOPE allows you to see\n"
# 1711 "data//maps/SootopolisCity/scripts.pory"
	.string "through their camouflage.$"
# 1712 "data//maps/SootopolisCity/scripts.pory"

# 1713 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenUntilNextTime:
# 1714 "data//maps/SootopolisCity/scripts.pory"
	.string "Until next time, {PLAYER}!$"
# 1715 "data//maps/SootopolisCity/scripts.pory"

# 1716 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1717 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: Oh?\n"
# 1718 "data//maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1719 "data//maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the SKY PILLAR\n"
# 1720 "data//maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1721 "data//maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1722 "data//maps/SootopolisCity/scripts.pory"
	.string "the top of the SKY PILLAR…$"
# 1723 "data//maps/SootopolisCity/scripts.pory"

# 1724 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1725 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 1726 "data//maps/SootopolisCity/scripts.pory"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
# 1727 "data//maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1728 "data//maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1729 "data//maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1730 "data//maps/SootopolisCity/scripts.pory"

# 1731 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1732 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\n"
# 1733 "data//maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1734 "data//maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, SOOTOPOLIS…\n"
# 1735 "data//maps/SootopolisCity/scripts.pory"
	.string "No, all of HOENN was saved.\p"
# 1736 "data//maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1737 "data//maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1738 "data//maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1739 "data//maps/SootopolisCity/scripts.pory"

# 1740 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1741 "data//maps/SootopolisCity/scripts.pory"
	.string "That HIDDEN MACHINE contains\n"
# 1742 "data//maps/SootopolisCity/scripts.pory"
	.string "WATERFALL.\p"
# 1743 "data//maps/SootopolisCity/scripts.pory"
	.string "If you have the RAIN BADGE, a POKéMON\n"
# 1744 "data//maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1745 "data//maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1746 "data//maps/SootopolisCity/scripts.pory"
	.string "And where does one get the RAIN BADGE?\n"
# 1747 "data//maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1748 "data//maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1749 "data//maps/SootopolisCity/scripts.pory"
	.string "the SOOTOPOLIS GYM LEADER.\p"
# 1750 "data//maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1751 "data//maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1752 "data//maps/SootopolisCity/scripts.pory"

# 1753 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1754 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: I'm sure that you will be\n"
# 1755 "data//maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1756 "data//maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
