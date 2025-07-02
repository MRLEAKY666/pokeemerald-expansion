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
	waitstate
# 211 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 212 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 213 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 214 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 215 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 216 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 217 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 218 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 219 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 220 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 221 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 222 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 223 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 224 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 225 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 226 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 227 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 228 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 229 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 230 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 231 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 232 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 233 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 234 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 235 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 236 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 237 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 238 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 239 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 240 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 241 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 242 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 243 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 244 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 245 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 246 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 247 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 248 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 249 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 250 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 251 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 252 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 253 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 254 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 255 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 256 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 257 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 258 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 259 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 260 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 261 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 262 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 263 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 264 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 265 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 266 "data//maps/SootopolisCity/scripts.pory"
	end
# 267 "data//maps/SootopolisCity/scripts.pory"

# 268 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
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
	walk_slow_diag_southwest
# 281 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 282 "data//maps/SootopolisCity/scripts.pory"

# 283 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
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
	walk_slow_diag_northeast
# 296 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 297 "data//maps/SootopolisCity/scripts.pory"

# 298 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 299 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 300 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 301 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 302 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 303 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 304 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 305 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 306 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 307 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 308 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 0 @ Just do Groudon/Kyogre fight scene
# 309 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 310 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 311 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 312 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 313 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 314 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 315 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 316 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 317 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 318 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 319 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 320 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 321 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 322 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 323 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 324 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 325 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 326 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 327 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 328 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 329 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 330 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 331 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 332 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 333 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 334 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 335 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 336 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 337 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 338 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 339 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 340 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 341 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 342 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 343 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 344 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 345 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 346 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 347 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 348 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 349 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 350 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 351 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 352 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 353 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 354 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 355 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 356 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 357 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 358 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 359 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 360 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 361 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 362 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 363 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 364 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 365 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 366 "data//maps/SootopolisCity/scripts.pory"
	end
# 367 "data//maps/SootopolisCity/scripts.pory"

# 368 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 369 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 370 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
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
	walk_up
# 377 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 378 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 379 "data//maps/SootopolisCity/scripts.pory"

# 380 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
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
	walk_down
# 387 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 388 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 389 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 390 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 391 "data//maps/SootopolisCity/scripts.pory"

# 392 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 393 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 394 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 395 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 396 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 397 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 398 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 399 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 400 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 401 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 402 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 403 "data//maps/SootopolisCity/scripts.pory"

# 404 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
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
	delay_16
# 413 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 414 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 415 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 416 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 417 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 418 "data//maps/SootopolisCity/scripts.pory"

# 419 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 420 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 421 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 422 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 423 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 424 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 425 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 426 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 427 "data//maps/SootopolisCity/scripts.pory"

# 428 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 429 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 430 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 431 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 432 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 433 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 434 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 435 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 436 "data//maps/SootopolisCity/scripts.pory"

# 437 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 438 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 439 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 440 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 441 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 442 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 443 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 444 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 445 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 446 "data//maps/SootopolisCity/scripts.pory"

# 447 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
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
	delay_16
# 456 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 457 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 458 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 459 "data//maps/SootopolisCity/scripts.pory"

# 460 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 461 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 462 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 463 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 464 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 465 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 466 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 467 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 468 "data//maps/SootopolisCity/scripts.pory"

# 469 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 470 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 471 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 472 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 473 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 474 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 475 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 476 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 477 "data//maps/SootopolisCity/scripts.pory"

# 478 "data//maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 479 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 480 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 481 "data//maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 482 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 483 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 484 "data//maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 485 "data//maps/SootopolisCity/scripts.pory"
	end
# 486 "data//maps/SootopolisCity/scripts.pory"

# 487 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 488 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 489 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 490 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 491 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 492 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 493 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 494 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 495 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 496 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 497 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 498 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 499 "data//maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 500 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle
# 501 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1                                                                      @ 0 ends early, 1 has battle, 2 is vanilla 
# 502 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 503 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 504 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle
# 505 "data//maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 506 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 507 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 508 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 509 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 510 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 511 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 512 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 513 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 514 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 515 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 516 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 517 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 518 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 519 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 520 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 521 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 522 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 523 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 524 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 525 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 526 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 527 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 528 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 529 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 530 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 531 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 532 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 533 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 534 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 535 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 536 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 537 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 538 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 539 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 540 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 541 "data//maps/SootopolisCity/scripts.pory"
	end
# 542 "data//maps/SootopolisCity/scripts.pory"

# 543 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 544 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 545 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 546 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 547 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 548 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 549 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 550 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 551 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 552 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 553 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 554 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 555 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle
# 556 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1                                                                      @ 0 ends early, 1 has battle, 2 is vanilla 
# 557 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 558 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 559 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle
# 560 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 561 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 562 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 563 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 564 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 565 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 566 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 567 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 568 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 569 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 570 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 571 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 572 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 573 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 574 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 575 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 576 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 577 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 578 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 579 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 580 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 581 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 582 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 583 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 584 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 585 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 586 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 587 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 588 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 589 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 590 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 591 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 592 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 593 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 594 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 595 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 596 "data//maps/SootopolisCity/scripts.pory"
	end
# 597 "data//maps/SootopolisCity/scripts.pory"
	
# 598 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetupRayquazaVsLegendsBattle::
# 599 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPLIS_BATTLE_ACTIVE
# 600 "data//maps/SootopolisCity/scripts.pory"
	setwilddoubleflag
# 601 "data//maps/SootopolisCity/scripts.pory"
	special SavePlayerParty
# 602 "data//maps/SootopolisCity/scripts.pory"
	special ZeroPlayerPartyMons
# 603 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_TEMP_NO_CATCHING
# 604 "data//maps/SootopolisCity/scripts.pory"
	@ setflag FLAG_TEMP_SMART_WILD_AI
# 605 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_TEMP_NO_RUNNING
# 606 "data//maps/SootopolisCity/scripts.pory"
	@ settotemboost 0, atk=2,speed=2,evas=2
# 607 "data//maps/SootopolisCity/scripts.pory"
	createmon 0, 0, SPECIES_RAYQUAZA, 70, item=ITEM_CHESTO_BERRY, move1=MOVE_FLY, move2=MOVE_REST, move3=MOVE_DRAGON_DANCE, move4=MOVE_EXTREMESPEED, speedIv=0
# 608 "data//maps/SootopolisCity/scripts.pory"
	createmon 1, 1, SPECIES_GROUDON, 70, item=ITEM_RED_ORB, move1=MOVE_ANCIENT_POWER, move2=MOVE_LAVA_PLUME, move3=MOVE_BULK_UP, move4=MOVE_FISSURE, speedIv=31
# 609 "data//maps/SootopolisCity/scripts.pory"
	createmon 1, 3, SPECIES_KYOGRE, 70, item=ITEM_BLUE_ORB, move1=MOVE_CALM_MIND, move2=MOVE_ANCIENT_POWER, move3=MOVE_SURF, move4=MOVE_SHEER_COLD,  speedIv=31
# 610 "data//maps/SootopolisCity/scripts.pory"
	return
# 611 "data//maps/SootopolisCity/scripts.pory"

# 612 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ClearRayquazaVsLegendsBattle::
# 613 "data//maps/SootopolisCity/scripts.pory"
	special LoadPlayerParty
# 614 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SOOTOPLIS_BATTLE_ACTIVE
# 615 "data//maps/SootopolisCity/scripts.pory"
	return
# 616 "data//maps/SootopolisCity/scripts.pory"

# 617 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 618 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 619 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 620 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 621 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 622 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 623 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 624 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 625 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 626 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 627 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 628 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 629 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 630 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 631 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 632 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 633 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 634 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 635 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 636 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 637 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 638 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 639 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 640 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 641 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 642 "data//maps/SootopolisCity/scripts.pory"
	return
# 643 "data//maps/SootopolisCity/scripts.pory"

# 644 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 645 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 646 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 647 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 648 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 649 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 650 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 651 "data//maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 652 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 653 "data//maps/SootopolisCity/scripts.pory"

# 654 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 655 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 656 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 657 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 658 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 659 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 660 "data//maps/SootopolisCity/scripts.pory"

# 661 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 662 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 663 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 664 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 665 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 666 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 667 "data//maps/SootopolisCity/scripts.pory"

# 668 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 669 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 670 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 671 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 672 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 673 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 674 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 675 "data//maps/SootopolisCity/scripts.pory"

# 676 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 677 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
# 678 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 679 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 680 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 681 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 682 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 683 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 684 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 685 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 686 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 687 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 688 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 689 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 690 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 691 "data//maps/SootopolisCity/scripts.pory"

# 692 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 693 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
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
	walk_down
# 701 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 702 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 703 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 704 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 705 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 706 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 707 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 708 "data//maps/SootopolisCity/scripts.pory"

# 709 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 710 "data//maps/SootopolisCity/scripts.pory"
	lock
# 711 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 712 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 713 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 714 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 715 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 716 "data//maps/SootopolisCity/scripts.pory"
	release
# 717 "data//maps/SootopolisCity/scripts.pory"
	end
# 718 "data//maps/SootopolisCity/scripts.pory"

# 719 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 720 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 721 "data//maps/SootopolisCity/scripts.pory"
	release
# 722 "data//maps/SootopolisCity/scripts.pory"
	end
# 723 "data//maps/SootopolisCity/scripts.pory"

# 724 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 725 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 726 "data//maps/SootopolisCity/scripts.pory"
	release
# 727 "data//maps/SootopolisCity/scripts.pory"
	end
# 728 "data//maps/SootopolisCity/scripts.pory"

# 729 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 730 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 731 "data//maps/SootopolisCity/scripts.pory"
	release
# 732 "data//maps/SootopolisCity/scripts.pory"
	end
# 733 "data//maps/SootopolisCity/scripts.pory"

# 734 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 735 "data//maps/SootopolisCity/scripts.pory"
	lock
# 736 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 737 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 738 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 739 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 740 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 741 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 742 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 743 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 744 "data//maps/SootopolisCity/scripts.pory"
	release
# 745 "data//maps/SootopolisCity/scripts.pory"
	end
# 746 "data//maps/SootopolisCity/scripts.pory"

# 747 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 748 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 749 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 750 "data//maps/SootopolisCity/scripts.pory"
	release
# 751 "data//maps/SootopolisCity/scripts.pory"
	end
# 752 "data//maps/SootopolisCity/scripts.pory"

# 753 "data//maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
# 754 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 755 "data//maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 756 "data//maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 757 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 758 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 759 "data//maps/SootopolisCity/scripts.pory"
	random NUM_KIRI_BERRIES
# 760 "data//maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
# 761 "data//maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 762 "data//maps/SootopolisCity/scripts.pory"
	giveitem VAR_RESULT
# 763 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 764 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 765 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 766 "data//maps/SootopolisCity/scripts.pory"
	random 2
# 767 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 768 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 769 "data//maps/SootopolisCity/scripts.pory"
	end
# 770 "data//maps/SootopolisCity/scripts.pory"

# 771 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 772 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 773 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 774 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 775 "data//maps/SootopolisCity/scripts.pory"
	release
# 776 "data//maps/SootopolisCity/scripts.pory"
	end
# 777 "data//maps/SootopolisCity/scripts.pory"

# 778 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 779 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 780 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 781 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 782 "data//maps/SootopolisCity/scripts.pory"
	release
# 783 "data//maps/SootopolisCity/scripts.pory"
	end
# 784 "data//maps/SootopolisCity/scripts.pory"

# 785 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 786 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 787 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 788 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 789 "data//maps/SootopolisCity/scripts.pory"
	release
# 790 "data//maps/SootopolisCity/scripts.pory"
	end
# 791 "data//maps/SootopolisCity/scripts.pory"

# 792 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 793 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 794 "data//maps/SootopolisCity/scripts.pory"
	release
# 795 "data//maps/SootopolisCity/scripts.pory"
	end
# 796 "data//maps/SootopolisCity/scripts.pory"

# 797 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 798 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 799 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
# 800 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 801 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 802 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 803 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 804 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
# 805 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 806 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 807 "data//maps/SootopolisCity/scripts.pory"
	end
# 808 "data//maps/SootopolisCity/scripts.pory"

# 809 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 810 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 811 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 812 "data//maps/SootopolisCity/scripts.pory"
	end
# 813 "data//maps/SootopolisCity/scripts.pory"

# 814 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 815 "data//maps/SootopolisCity/scripts.pory"
	lock
# 816 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 817 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 818 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 819 "data//maps/SootopolisCity/scripts.pory"
	release
# 820 "data//maps/SootopolisCity/scripts.pory"
	end
# 821 "data//maps/SootopolisCity/scripts.pory"

# 822 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 823 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 824 "data//maps/SootopolisCity/scripts.pory"
	release
# 825 "data//maps/SootopolisCity/scripts.pory"
	end
# 826 "data//maps/SootopolisCity/scripts.pory"

# 827 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 828 "data//maps/SootopolisCity/scripts.pory"
	lock
# 829 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 830 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 831 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 832 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 833 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 834 "data//maps/SootopolisCity/scripts.pory"
	release
# 835 "data//maps/SootopolisCity/scripts.pory"
	end
# 836 "data//maps/SootopolisCity/scripts.pory"

# 837 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 838 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 839 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 840 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
# 841 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 842 "data//maps/SootopolisCity/scripts.pory"
	release
# 843 "data//maps/SootopolisCity/scripts.pory"
	end
# 844 "data//maps/SootopolisCity/scripts.pory"

# 845 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 846 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 847 "data//maps/SootopolisCity/scripts.pory"
	release
# 848 "data//maps/SootopolisCity/scripts.pory"
	end
# 849 "data//maps/SootopolisCity/scripts.pory"

# 850 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 851 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 852 "data//maps/SootopolisCity/scripts.pory"
	release
# 853 "data//maps/SootopolisCity/scripts.pory"
	end
# 854 "data//maps/SootopolisCity/scripts.pory"

# 855 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 856 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 857 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
# 858 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 859 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 860 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 861 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 862 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 863 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 864 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 865 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 866 "data//maps/SootopolisCity/scripts.pory"
	release
# 867 "data//maps/SootopolisCity/scripts.pory"
	end
# 868 "data//maps/SootopolisCity/scripts.pory"

# 869 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 870 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 871 "data//maps/SootopolisCity/scripts.pory"
	release
# 872 "data//maps/SootopolisCity/scripts.pory"
	end
# 873 "data//maps/SootopolisCity/scripts.pory"

# 874 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 875 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 876 "data//maps/SootopolisCity/scripts.pory"
	release
# 877 "data//maps/SootopolisCity/scripts.pory"
	end
# 878 "data//maps/SootopolisCity/scripts.pory"

# 879 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 880 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 881 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
# 882 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 883 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 884 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 885 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 886 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 887 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 888 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 889 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
# 890 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 891 "data//maps/SootopolisCity/scripts.pory"
	release
# 892 "data//maps/SootopolisCity/scripts.pory"
	end
# 893 "data//maps/SootopolisCity/scripts.pory"

# 894 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 895 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 896 "data//maps/SootopolisCity/scripts.pory"
	release
# 897 "data//maps/SootopolisCity/scripts.pory"
	end
# 898 "data//maps/SootopolisCity/scripts.pory"

# 899 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 900 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 901 "data//maps/SootopolisCity/scripts.pory"
	release
# 902 "data//maps/SootopolisCity/scripts.pory"
	end
# 903 "data//maps/SootopolisCity/scripts.pory"

# 904 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 905 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 906 "data//maps/SootopolisCity/scripts.pory"
	release
# 907 "data//maps/SootopolisCity/scripts.pory"
	end
# 908 "data//maps/SootopolisCity/scripts.pory"

# 909 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 910 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 911 "data//maps/SootopolisCity/scripts.pory"
	end
# 912 "data//maps/SootopolisCity/scripts.pory"

# 913 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 914 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 915 "data//maps/SootopolisCity/scripts.pory"
	end
# 916 "data//maps/SootopolisCity/scripts.pory"

# 917 "data//maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 918 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 919 "data//maps/SootopolisCity/scripts.pory"
	end
# 920 "data//maps/SootopolisCity/scripts.pory"

# 921 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 922 "data//maps/SootopolisCity/scripts.pory"
	lock
# 923 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
# 924 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 925 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 926 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 927 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 928 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 929 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 930 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 931 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 932 "data//maps/SootopolisCity/scripts.pory"
	end
# 933 "data//maps/SootopolisCity/scripts.pory"

# 934 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 935 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 936 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 937 "data//maps/SootopolisCity/scripts.pory"
	end
# 938 "data//maps/SootopolisCity/scripts.pory"

# 939 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 940 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 941 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 942 "data//maps/SootopolisCity/scripts.pory"
	end
# 943 "data//maps/SootopolisCity/scripts.pory"

# 944 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 945 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 946 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 947 "data//maps/SootopolisCity/scripts.pory"
	end
# 948 "data//maps/SootopolisCity/scripts.pory"

# 949 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 950 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 951 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 952 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 953 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 954 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 955 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 956 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 957 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 958 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 959 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 960 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 961 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 962 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 963 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 964 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 965 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 966 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 967 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 968 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 969 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 970 "data//maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 971 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 972 "data//maps/SootopolisCity/scripts.pory"
	end
# 973 "data//maps/SootopolisCity/scripts.pory"

# 974 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 975 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 976 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 977 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 978 "data//maps/SootopolisCity/scripts.pory"
	return
# 979 "data//maps/SootopolisCity/scripts.pory"

# 980 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 981 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 982 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 983 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 984 "data//maps/SootopolisCity/scripts.pory"
	return
# 985 "data//maps/SootopolisCity/scripts.pory"

# 986 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 987 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 988 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 989 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 990 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 991 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 992 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 993 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 994 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 995 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 996 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 997 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 998 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 999 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1000 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1001 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1008 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1009 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1010 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1011 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1012 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1013 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1014 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1015 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1016 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1017 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1018 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1019 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1020 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1021 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1023 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1024 "data//maps/SootopolisCity/scripts.pory"

# 1025 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 1026 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1027 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1028 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1029 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1030 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1031 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1032 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1033 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1034 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1035 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1036 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1037 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1038 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1040 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1041 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1048 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1049 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1050 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1051 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1052 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1053 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1054 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1055 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1056 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1057 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1058 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1059 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1060 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1061 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1062 "data//maps/SootopolisCity/scripts.pory"

# 1063 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1064 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1065 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1066 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1067 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1068 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1069 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1070 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1071 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1072 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1073 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1074 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1075 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1076 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1077 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1078 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1079 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1086 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1087 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1088 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1089 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1090 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1091 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1092 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1093 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1094 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1095 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1096 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1097 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1098 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1099 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1100 "data//maps/SootopolisCity/scripts.pory"

# 1101 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1102 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1103 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1104 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1105 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1106 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1107 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1108 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1109 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1110 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1111 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1112 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1113 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1114 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1115 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_right
# 1124 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1125 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1126 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1127 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1128 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1129 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1130 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1131 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1132 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1133 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1134 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1135 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1136 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1137 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1138 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1139 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1140 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1141 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1142 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1143 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1144 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1145 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1146 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1147 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1148 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1149 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1150 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1151 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1152 "data//maps/SootopolisCity/scripts.pory"
	delay_4
# 1153 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1154 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1155 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1156 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1157 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1158 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1159 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1160 "data//maps/SootopolisCity/scripts.pory"

# 1161 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1162 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1163 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1164 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1165 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1166 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1167 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1168 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1169 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1170 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1171 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1172 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1173 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1174 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1175 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1176 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_right
# 1185 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1186 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1187 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1188 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1189 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1190 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1191 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1192 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1193 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1194 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1195 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1196 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1197 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1198 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1199 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1200 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1201 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1202 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1203 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1204 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1205 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1206 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1207 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1208 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1209 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1210 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1211 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1212 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1213 "data//maps/SootopolisCity/scripts.pory"

# 1214 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1215 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1216 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1217 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1218 "data//maps/SootopolisCity/scripts.pory"

# 1219 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1220 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1221 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1222 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1223 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1224 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1225 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1226 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1227 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1228 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1229 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1230 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1231 "data//maps/SootopolisCity/scripts.pory"

# 1232 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1233 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1234 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1235 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1236 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1237 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1238 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1239 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1240 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1241 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1242 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1243 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1244 "data//maps/SootopolisCity/scripts.pory"

# 1245 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1246 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1247 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1248 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1249 "data//maps/SootopolisCity/scripts.pory"

# 1250 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1251 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1252 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
# 1253 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1254 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1255 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1256 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1257 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
# 1258 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1259 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1260 "data//maps/SootopolisCity/scripts.pory"
	end
# 1261 "data//maps/SootopolisCity/scripts.pory"

# 1262 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1263 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1264 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1265 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1266 "data//maps/SootopolisCity/scripts.pory"
	end
# 1267 "data//maps/SootopolisCity/scripts.pory"

# 1268 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1269 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1270 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1271 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1272 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1273 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1274 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1275 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1276 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1277 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1278 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1279 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1280 "data//maps/SootopolisCity/scripts.pory"
	end
# 1281 "data//maps/SootopolisCity/scripts.pory"

# 1282 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1283 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1284 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1285 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1286 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1287 "data//maps/SootopolisCity/scripts.pory"
	end
# 1288 "data//maps/SootopolisCity/scripts.pory"

# 1289 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1290 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1291 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
# 1292 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1293 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1294 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1295 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1296 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
# 1297 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1298 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1299 "data//maps/SootopolisCity/scripts.pory"
	end
# 1300 "data//maps/SootopolisCity/scripts.pory"

# 1301 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1302 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1303 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1304 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1305 "data//maps/SootopolisCity/scripts.pory"
	end
# 1306 "data//maps/SootopolisCity/scripts.pory"

# 1307 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1308 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1309 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
# 1310 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1311 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1312 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1313 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1314 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
# 1315 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1316 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1317 "data//maps/SootopolisCity/scripts.pory"
	end
# 1318 "data//maps/SootopolisCity/scripts.pory"

# 1319 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1320 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1321 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1322 "data//maps/SootopolisCity/scripts.pory"
	end
# 1323 "data//maps/SootopolisCity/scripts.pory"

# 1324 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1325 "data//maps/SootopolisCity/scripts.pory"
	lock
# 1326 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 1327 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1328 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1329 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1330 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1331 "data//maps/SootopolisCity/scripts.pory"
	release
# 1332 "data//maps/SootopolisCity/scripts.pory"
	end
# 1333 "data//maps/SootopolisCity/scripts.pory"

# 1334 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1335 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1336 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1337 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1338 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1339 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1340 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1341 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1342 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1343 "data//maps/SootopolisCity/scripts.pory"
	release
# 1344 "data//maps/SootopolisCity/scripts.pory"
	end
# 1345 "data//maps/SootopolisCity/scripts.pory"

# 1346 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1347 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1348 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1349 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1350 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1351 "data//maps/SootopolisCity/scripts.pory"
	return
# 1352 "data//maps/SootopolisCity/scripts.pory"

# 1353 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1354 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1355 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1356 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1357 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1358 "data//maps/SootopolisCity/scripts.pory"
	return
# 1359 "data//maps/SootopolisCity/scripts.pory"

# 1360 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1361 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1362 "data//maps/SootopolisCity/scripts.pory"
	release
# 1363 "data//maps/SootopolisCity/scripts.pory"
	end
# 1364 "data//maps/SootopolisCity/scripts.pory"

# 1365 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1366 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1367 "data//maps/SootopolisCity/scripts.pory"
	release
# 1368 "data//maps/SootopolisCity/scripts.pory"
	end
# 1369 "data//maps/SootopolisCity/scripts.pory"

# 1370 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1371 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1372 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1373 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1374 "data//maps/SootopolisCity/scripts.pory"

# 1375 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1376 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1377 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1378 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1379 "data//maps/SootopolisCity/scripts.pory"

# 1380 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1381 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1382 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1383 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1384 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1385 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1386 "data//maps/SootopolisCity/scripts.pory"
	end
# 1387 "data//maps/SootopolisCity/scripts.pory"

# 1388 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1389 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1390 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1391 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1392 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1393 "data//maps/SootopolisCity/scripts.pory"
	end
# 1394 "data//maps/SootopolisCity/scripts.pory"

# 1395 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1396 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1397 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1398 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1399 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1400 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1401 "data//maps/SootopolisCity/scripts.pory"
	end
# 1402 "data//maps/SootopolisCity/scripts.pory"

# 1403 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1404 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1405 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1406 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1407 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1408 "data//maps/SootopolisCity/scripts.pory"
	end
# 1409 "data//maps/SootopolisCity/scripts.pory"

# 1410 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1411 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1412 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1413 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1414 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1415 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1416 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1417 "data//maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1418 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 1419 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1420 "data//maps/SootopolisCity/scripts.pory"
	end
# 1421 "data//maps/SootopolisCity/scripts.pory"

# 1422 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1423 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1424 "data//maps/SootopolisCity/scripts.pory"
	levitate
# 1425 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1426 "data//maps/SootopolisCity/scripts.pory"

# 1427 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1428 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1429 "data//maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1430 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1431 "data//maps/SootopolisCity/scripts.pory"

# 1432 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1433 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
# 1434 "data//maps/SootopolisCity/scripts.pory"
	.string "LEADER: JUAN\p"
# 1435 "data//maps/SootopolisCity/scripts.pory"
	.string "“The GYM LEADER with the beauty\n"
# 1436 "data//maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1437 "data//maps/SootopolisCity/scripts.pory"

# 1438 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1439 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY\p"
# 1440 "data//maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1441 "data//maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1442 "data//maps/SootopolisCity/scripts.pory"

# 1443 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1444 "data//maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1445 "data//maps/SootopolisCity/scripts.pory"

# 1446 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1447 "data//maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1448 "data//maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1449 "data//maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1450 "data//maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1451 "data//maps/SootopolisCity/scripts.pory"

# 1452 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1453 "data//maps/SootopolisCity/scripts.pory"
	.string "These giant POKéMON suddenly appeared\n"
# 1454 "data//maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1455 "data//maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1456 "data//maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1457 "data//maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1458 "data//maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1459 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1460 "data//maps/SootopolisCity/scripts.pory"

# 1461 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1462 "data//maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1463 "data//maps/SootopolisCity/scripts.pory"
	.string "What is that green POKéMON?!$"
# 1464 "data//maps/SootopolisCity/scripts.pory"

# 1465 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1466 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON and KYOGRE…\n"
# 1467 "data//maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1468 "data//maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1469 "data//maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1470 "data//maps/SootopolisCity/scripts.pory"

# 1471 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1472 "data//maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1473 "data//maps/SootopolisCity/scripts.pory"
	.string "the two POKéMON aren't angry.\p"
# 1474 "data//maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1475 "data//maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1476 "data//maps/SootopolisCity/scripts.pory"

# 1477 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1478 "data//maps/SootopolisCity/scripts.pory"
	.string "That flying POKéMON came down from\n"
# 1479 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1480 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON…$"
# 1481 "data//maps/SootopolisCity/scripts.pory"

# 1482 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1483 "data//maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1484 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1485 "data//maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1486 "data//maps/SootopolisCity/scripts.pory"

# 1487 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1488 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1489 "data//maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1490 "data//maps/SootopolisCity/scripts.pory"

# 1491 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1492 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1493 "data//maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1494 "data//maps/SootopolisCity/scripts.pory"

# 1495 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1496 "data//maps/SootopolisCity/scripts.pory"
	.string "Go for it, red POKéMON!\n"
# 1497 "data//maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue POKéMON!$"
# 1498 "data//maps/SootopolisCity/scripts.pory"

# 1499 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1500 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1501 "data//maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1502 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON fighting over there?$"
# 1503 "data//maps/SootopolisCity/scripts.pory"

# 1504 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1505 "data//maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1506 "data//maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1507 "data//maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1508 "data//maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1509 "data//maps/SootopolisCity/scripts.pory"

# 1510 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1511 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1512 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1513 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1514 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1515 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1516 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1517 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1518 "data//maps/SootopolisCity/scripts.pory"

# 1519 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1520 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1521 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1522 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1523 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1524 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1525 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1526 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1527 "data//maps/SootopolisCity/scripts.pory"

# 1528 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1529 "data//maps/SootopolisCity/scripts.pory"
	.string "A big POKéMON is fighting with\n"
# 1530 "data//maps/SootopolisCity/scripts.pory"
	.string "another big POKéMON!\p"
# 1531 "data//maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1532 "data//maps/SootopolisCity/scripts.pory"

# 1533 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1534 "data//maps/SootopolisCity/scripts.pory"
	.string "A pretty POKéMON came down from\n"
# 1535 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1536 "data//maps/SootopolisCity/scripts.pory"

# 1537 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1538 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1539 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY will get wrecked!$"
# 1540 "data//maps/SootopolisCity/scripts.pory"

# 1541 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1542 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
# 1543 "data//maps/SootopolisCity/scripts.pory"

# 1544 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1545 "data//maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1546 "data//maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to SOOTOPOLIS?\l"
# 1547 "data//maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1548 "data//maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1549 "data//maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1550 "data//maps/SootopolisCity/scripts.pory"

# 1551 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1552 "data//maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1553 "data//maps/SootopolisCity/scripts.pory"

# 1554 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1555 "data//maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1556 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN.\p"
# 1557 "data//maps/SootopolisCity/scripts.pory"
	.string "The spirits of POKéMON, becalmed at\n"
# 1558 "data//maps/SootopolisCity/scripts.pory"
	.string "MT. PYRE, are said to be revived here.\p"
# 1559 "data//maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1560 "data//maps/SootopolisCity/scripts.pory"

# 1561 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1562 "data//maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1563 "data//maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1564 "data//maps/SootopolisCity/scripts.pory"
	.string "A TRAINER who has knowledge and\n"
# 1565 "data//maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of POKéMON…\p"
# 1566 "data//maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1567 "data//maps/SootopolisCity/scripts.pory"
	.string "instructed by WALLACE to lead that\l"
# 1568 "data//maps/SootopolisCity/scripts.pory"
	.string "TRAINER to this CAVE.$"
# 1569 "data//maps/SootopolisCity/scripts.pory"

# 1570 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1571 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1572 "data//maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1573 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON was quelled by the awakening\l"
# 1574 "data//maps/SootopolisCity/scripts.pory"
	.string "of a third POKéMON…$"
# 1575 "data//maps/SootopolisCity/scripts.pory"

# 1576 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1577 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN…\p"
# 1578 "data//maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1579 "data//maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1580 "data//maps/SootopolisCity/scripts.pory"

# 1581 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1582 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS sprang up as a town in\n"
# 1583 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1584 "data//maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1585 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1586 "data//maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1587 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1588 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS the most beautiful.$"
# 1589 "data//maps/SootopolisCity/scripts.pory"

# 1590 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1591 "data//maps/SootopolisCity/scripts.pory"
	.string "When two POKéMON that gigantic\n"
# 1592 "data//maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1593 "data//maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1594 "data//maps/SootopolisCity/scripts.pory"

# 1595 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1596 "data//maps/SootopolisCity/scripts.pory"
	.string "When that third POKéMON flew down,\n"
# 1597 "data//maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1598 "data//maps/SootopolisCity/scripts.pory"

# 1599 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1600 "data//maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1601 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1602 "data//maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1603 "data//maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1604 "data//maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1605 "data//maps/SootopolisCity/scripts.pory"

# 1606 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1607 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1608 "data//maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1609 "data//maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1610 "data//maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1611 "data//maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1612 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1613 "data//maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1614 "data//maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1615 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1616 "data//maps/SootopolisCity/scripts.pory"

# 1617 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1618 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1619 "data//maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1620 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON here?\p"
# 1621 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1622 "data//maps/SootopolisCity/scripts.pory"

# 1623 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1624 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: G… GROUDON…\n"
# 1625 "data//maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1626 "data//maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1627 "data//maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all HOENN, not just\n"
# 1628 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS, will be utterly ruined!$"
# 1629 "data//maps/SootopolisCity/scripts.pory"

# 1630 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1631 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: So the super-ancient POKéMON\n"
# 1632 "data//maps/SootopolisCity/scripts.pory"
	.string "weren't only GROUDON and KYOGRE…\p"
# 1633 "data//maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1634 "data//maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one POKéMON's\l"
# 1635 "data//maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1636 "data//maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1637 "data//maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1638 "data//maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1639 "data//maps/SootopolisCity/scripts.pory"

# 1640 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1641 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
# 1642 "data//maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the RED ORB!\l"
# 1643 "data//maps/SootopolisCity/scripts.pory"
	.string "Calm down! KYOGRE!\p"
# 1644 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1645 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1646 "data//maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1647 "data//maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1648 "data//maps/SootopolisCity/scripts.pory"

# 1649 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1650 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE and GROUDON both\n"
# 1651 "data//maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1652 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather in HOENN has returned\n"
# 1653 "data//maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1654 "data//maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1655 "data//maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1656 "data//maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1657 "data//maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1658 "data//maps/SootopolisCity/scripts.pory"
	.string "to POKéMON…$"
# 1659 "data//maps/SootopolisCity/scripts.pory"

# 1660 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1661 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Those POKéMON fighting…\n"
# 1662 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON… And KYOGRE…\p"
# 1663 "data//maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient POKéMON\n"
# 1664 "data//maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1665 "data//maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1666 "data//maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1667 "data//maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1668 "data//maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1669 "data//maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1670 "data//maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1671 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1672 "data//maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1673 "data//maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1674 "data//maps/SootopolisCity/scripts.pory"

# 1675 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1676 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
# 1677 "data//maps/SootopolisCity/scripts.pory"
	.string "Does seeing GROUDON and KYOGRE make\n"
# 1678 "data//maps/SootopolisCity/scripts.pory"
	.string "you think POKéMON are to be feared?\p"
# 1679 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1680 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON are really more…\p"
# 1681 "data//maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1682 "data//maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1683 "data//maps/SootopolisCity/scripts.pory"

# 1684 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1685 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Okay, here we are!\p"
# 1686 "data//maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1687 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE.\p"
# 1688 "data//maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1689 "data//maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1690 "data//maps/SootopolisCity/scripts.pory"

# 1691 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1692 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: I think you have what's\n"
# 1693 "data//maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1694 "data//maps/SootopolisCity/scripts.pory"

# 1695 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1696 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: The SKY PILLAR…\p"
# 1697 "data//maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1698 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1699 "data//maps/SootopolisCity/scripts.pory"

# 1700 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1701 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: So that's RAYQUAZA…\p"
# 1702 "data//maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1703 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON would flee from it in fear…$"
# 1704 "data//maps/SootopolisCity/scripts.pory"

# 1705 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1706 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: It looks like both MAXIE and\n"
# 1707 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE have gone away somewhere.\p"
# 1708 "data//maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to MT. PYRE to\n"
# 1709 "data//maps/SootopolisCity/scripts.pory"
	.string "return those ORBS…$"
# 1710 "data//maps/SootopolisCity/scripts.pory"

# 1711 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenGiveDevonScope:
# 1712 "data//maps/SootopolisCity/scripts.pory"
	.string "RAYQUAZA seemingly flew off towards\n"
# 1713 "data//maps/SootopolisCity/scripts.pory"
	.string "the forests around FORTREE CITY.\p"
# 1714 "data//maps/SootopolisCity/scripts.pory"
	.string "If you're going to track it down\n"
# 1715 "data//maps/SootopolisCity/scripts.pory"
	.string "you'll need this DEVON SCOPE.\p"
# 1716 "data//maps/SootopolisCity/scripts.pory"
	.string "A POKéMON called KECLEON makes\n"
# 1717 "data//maps/SootopolisCity/scripts.pory"
	.string "that area hard to navigate . . .\p"
# 1718 "data//maps/SootopolisCity/scripts.pory"
	.string "the DEVON SCOPE allows you to see\n"
# 1719 "data//maps/SootopolisCity/scripts.pory"
	.string "through their camouflage.$"
# 1720 "data//maps/SootopolisCity/scripts.pory"

# 1721 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenUntilNextTime:
# 1722 "data//maps/SootopolisCity/scripts.pory"
	.string "Until next time, {PLAYER}!$"
# 1723 "data//maps/SootopolisCity/scripts.pory"

# 1724 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1725 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: Oh?\n"
# 1726 "data//maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1727 "data//maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the SKY PILLAR\n"
# 1728 "data//maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1729 "data//maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1730 "data//maps/SootopolisCity/scripts.pory"
	.string "the top of the SKY PILLAR…$"
# 1731 "data//maps/SootopolisCity/scripts.pory"

# 1732 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1733 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 1734 "data//maps/SootopolisCity/scripts.pory"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
# 1735 "data//maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1736 "data//maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1737 "data//maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1738 "data//maps/SootopolisCity/scripts.pory"

# 1739 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1740 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\n"
# 1741 "data//maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1742 "data//maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, SOOTOPOLIS…\n"
# 1743 "data//maps/SootopolisCity/scripts.pory"
	.string "No, all of HOENN was saved.\p"
# 1744 "data//maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1745 "data//maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1746 "data//maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1747 "data//maps/SootopolisCity/scripts.pory"

# 1748 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1749 "data//maps/SootopolisCity/scripts.pory"
	.string "That HIDDEN MACHINE contains\n"
# 1750 "data//maps/SootopolisCity/scripts.pory"
	.string "WATERFALL.\p"
# 1751 "data//maps/SootopolisCity/scripts.pory"
	.string "If you have the RAIN BADGE, a POKéMON\n"
# 1752 "data//maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1753 "data//maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1754 "data//maps/SootopolisCity/scripts.pory"
	.string "And where does one get the RAIN BADGE?\n"
# 1755 "data//maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1756 "data//maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1757 "data//maps/SootopolisCity/scripts.pory"
	.string "the SOOTOPOLIS GYM LEADER.\p"
# 1758 "data//maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1759 "data//maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1760 "data//maps/SootopolisCity/scripts.pory"

# 1761 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1762 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: I'm sure that you will be\n"
# 1763 "data//maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1764 "data//maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
