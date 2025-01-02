# 1 "data//maps/SootopolisCity/scripts.pory"

# 2 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_EXPERT, 1
# 3 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_WOMAN_2, 2
# 4 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_KIRI, 3
# 5 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_NINJA_BOY, 4
# 6 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_BOY_1, 5
# 7 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_STEVEN, 7
# 8 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_WOMAN_1, 8
# 9 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_GROUDON, 9
# 10 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_KYOGRE, 10
# 11 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_RAYQUAZA, 11
# 12 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_MANIAC, 12
# 13 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_GIRL, 13
# 14 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_BLACK_BELT, 14
# 15 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_BOY_2, 15
# 16 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_MAXIE, 16
# 17 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_ARCHIE, 17
# 18 "data//maps/SootopolisCity/scripts.pory"
.set LOCALID_WALLACE, 18
# 19 "data//maps/SootopolisCity/scripts.pory"

# 20 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_MapScripts::
# 21 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
# 22 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
# 23 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
# 24 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
# 25 "data//maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
# 26 "data//maps/SootopolisCity/scripts.pory"
	.byte 0
# 27 "data//maps/SootopolisCity/scripts.pory"

# 28 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnLoad:
# 29 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
# 30 "data//maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
# 31 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
# 32 "data//maps/SootopolisCity/scripts.pory"
	end
# 33 "data//maps/SootopolisCity/scripts.pory"

# 34 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesNotArrived::
# 35 "data//maps/SootopolisCity/scripts.pory"
	end
# 36 "data//maps/SootopolisCity/scripts.pory"

# 37 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockHouseDoors::
# 38 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 39 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 40 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
# 41 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 42 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
# 43 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
# 44 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 45 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
# 46 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
# 47 "data//maps/SootopolisCity/scripts.pory"
	return
# 48 "data//maps/SootopolisCity/scripts.pory"

# 49 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockGymDoor::
# 50 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
# 51 "data//maps/SootopolisCity/scripts.pory"
	return
# 52 "data//maps/SootopolisCity/scripts.pory"

# 53 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnTransition:
# 54 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 55 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 56 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 57 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 58 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetWeather
# 59 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetLayout
# 60 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8008, 8
# 61 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_DEFEATED_SOOTOPOLIS_GYM, Common_EventScript_ResetGymTrainers
# 62 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
# 63 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
# 64 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
# 65 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBirchMeteoriteCall
# 66 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
# 67 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
# 68 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 69 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 70 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
# 71 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
# 72 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
# 73 "data//maps/SootopolisCity/scripts.pory"
	end
# 74 "data//maps/SootopolisCity/scripts.pory"

# 75 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_HideMapNamePopup::
# 76 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 77 "data//maps/SootopolisCity/scripts.pory"
	return
# 78 "data//maps/SootopolisCity/scripts.pory"

# 79 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBattleSpectators::
# 80 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_KIRI, 13, 48
# 81 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_BOY_1, 46, 32
# 82 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_NINJA_BOY, 48, 41
# 83 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WOMAN_1, 45, 43
# 84 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
# 85 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_BOY_1, MOVEMENT_TYPE_FACE_LEFT
# 86 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
# 87 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
# 88 "data//maps/SootopolisCity/scripts.pory"
	return
# 89 "data//maps/SootopolisCity/scripts.pory"

# 90 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBirchMeteoriteCall::
# 91 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_BIRCH_METEORITE_CALL_STEP_COUNTER, 0
# 92 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_BIRCH_CALL_METEORITE
# 93 "data//maps/SootopolisCity/scripts.pory"
	return
# 94 "data//maps/SootopolisCity/scripts.pory"

# 95 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BirchRayquazaCall::
# 96 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 97 "data//maps/SootopolisCity/scripts.pory"
	pokenavcall MatchCall_Text_BirchRayquazaCall 
# 98 "data//maps/SootopolisCity/scripts.pory"
	waitmessage
# 99 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 100 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_BIRCH_CALL_METEORITE
# 101 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 102 "data//maps/SootopolisCity/scripts.pory"
	end
# 103 "data//maps/SootopolisCity/scripts.pory"

# 104 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLayout::
# 105 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
# 106 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
# 107 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 108 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
# 109 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
# 110 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
# 111 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 112 "data//maps/SootopolisCity/scripts.pory"
	return
# 113 "data//maps/SootopolisCity/scripts.pory"

# 114 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalLayout::
# 115 "data//maps/SootopolisCity/scripts.pory"
	return
# 116 "data//maps/SootopolisCity/scripts.pory"

# 117 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLegendariesLayout::
# 118 "data//maps/SootopolisCity/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
# 119 "data//maps/SootopolisCity/scripts.pory"
	return
# 120 "data//maps/SootopolisCity/scripts.pory"

# 121 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWeather::
# 122 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
# 123 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
# 124 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 125 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 126 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
# 127 "data//maps/SootopolisCity/scripts.pory"
	return
# 128 "data//maps/SootopolisCity/scripts.pory"

# 129 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalWeather::
# 130 "data//maps/SootopolisCity/scripts.pory"
	return
# 131 "data//maps/SootopolisCity/scripts.pory"

# 132 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetDownpour::
# 133 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_DOWNPOUR
# 134 "data//maps/SootopolisCity/scripts.pory"
	return
# 135 "data//maps/SootopolisCity/scripts.pory"

# 136 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
# 137 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
# 138 "data//maps/SootopolisCity/scripts.pory"
	return
# 139 "data//maps/SootopolisCity/scripts.pory"

# 140 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
# 141 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 30, 18
# 142 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 32, 18
# 143 "data//maps/SootopolisCity/scripts.pory"
	return
# 144 "data//maps/SootopolisCity/scripts.pory"

# 145 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
# 146 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 30, 18
# 147 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 31, 18
# 148 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 32, 18
# 149 "data//maps/SootopolisCity/scripts.pory"
	end
# 150 "data//maps/SootopolisCity/scripts.pory"

# 151 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetOutsideGymObjPos::
# 152 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 31, 18
# 153 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 29, 33
# 154 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 33, 35
# 155 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 34, 35
# 156 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
# 157 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
# 158 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
# 159 "data//maps/SootopolisCity/scripts.pory"
	return
# 160 "data//maps/SootopolisCity/scripts.pory"

# 161 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceMiddle::
# 162 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 31, 33
# 163 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 164 "data//maps/SootopolisCity/scripts.pory"
	return
# 165 "data//maps/SootopolisCity/scripts.pory"

# 166 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceRight::
# 167 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 32, 33
# 168 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 169 "data//maps/SootopolisCity/scripts.pory"
	return
# 170 "data//maps/SootopolisCity/scripts.pory"

# 171 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceLeft::
# 172 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 30, 33
# 173 "data//maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 174 "data//maps/SootopolisCity/scripts.pory"
	return
# 175 "data//maps/SootopolisCity/scripts.pory"

# 176 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
# 177 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 29, 33
# 178 "data//maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 31, 18
# 179 "data//maps/SootopolisCity/scripts.pory"
	return
# 180 "data//maps/SootopolisCity/scripts.pory"

# 181 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp:
# 182 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 183 "data//maps/SootopolisCity/scripts.pory"
	.2byte 0
# 184 "data//maps/SootopolisCity/scripts.pory"

# 185 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries::
# 186 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
# 187 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
# 188 "data//maps/SootopolisCity/scripts.pory"
	end
# 189 "data//maps/SootopolisCity/scripts.pory"

# 190 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1::
# 191 "data//maps/SootopolisCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 192 "data//maps/SootopolisCity/scripts.pory"
	return
# 193 "data//maps/SootopolisCity/scripts.pory"

# 194 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2::
# 195 "data//maps/SootopolisCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 196 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 197 "data//maps/SootopolisCity/scripts.pory"
	return
# 198 "data//maps/SootopolisCity/scripts.pory"

# 199 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume:
# 200 "data//maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
# 201 "data//maps/SootopolisCity/scripts.pory"
	end
# 202 "data//maps/SootopolisCity/scripts.pory"

# 203 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame:
# 204 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 205 "data//maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 206 "data//maps/SootopolisCity/scripts.pory"
	.2byte 0
# 207 "data//maps/SootopolisCity/scripts.pory"

# 208 "data//maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 209 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene::
# 210 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 211 "data//maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 212 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
# 213 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
# 214 "data//maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 215 "data//maps/SootopolisCity/scripts.pory"
	end
# 216 "data//maps/SootopolisCity/scripts.pory"

# 217 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
# 218 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 219 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 220 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 221 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 222 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 223 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 224 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 225 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 226 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 227 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 228 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 229 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 230 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 231 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 232 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 233 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 234 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 235 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 236 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 237 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 238 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 239 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 240 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 241 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 242 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 243 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 244 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 245 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 246 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 247 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 248 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 249 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 250 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 251 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
# 252 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 253 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 254 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 255 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 256 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 257 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 258 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 259 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 260 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 261 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 262 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 263 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 264 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 265 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 266 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 267 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 268 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 269 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 270 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 271 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 272 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 273 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 274 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 275 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 276 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 277 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 278 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
# 279 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 280 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 281 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 282 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 283 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 284 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 285 "data//maps/SootopolisCity/scripts.pory"
	end
# 286 "data//maps/SootopolisCity/scripts.pory"

# 287 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
# 288 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 289 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 290 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 291 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 292 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 293 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 294 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 295 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 296 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 297 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 298 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 299 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 300 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 301 "data//maps/SootopolisCity/scripts.pory"

# 302 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
# 303 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 304 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 305 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 306 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 307 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 308 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 309 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 310 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 311 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 312 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 313 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 314 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 315 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 316 "data//maps/SootopolisCity/scripts.pory"

# 317 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 318 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 319 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 320 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 321 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 322 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 323 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 324 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 325 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 326 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 327 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 328 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 329 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 330 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 331 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 332 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 333 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 334 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 335 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 336 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 337 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 338 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 339 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 340 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 341 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 342 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 343 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 344 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 345 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 346 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 347 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 348 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 349 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 350 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 351 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
# 352 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 353 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 354 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 355 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 356 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 357 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 358 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 359 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 360 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 361 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 362 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 363 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 364 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 365 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 366 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 367 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 368 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 369 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 370 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 371 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 372 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 373 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 374 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 375 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 376 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 377 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 378 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
# 379 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 380 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 381 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 382 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 383 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 384 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 385 "data//maps/SootopolisCity/scripts.pory"
	end
# 386 "data//maps/SootopolisCity/scripts.pory"

# 387 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 388 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 389 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 390 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 391 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 392 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 393 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 394 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 395 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 396 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 397 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 398 "data//maps/SootopolisCity/scripts.pory"

# 399 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
# 400 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 401 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 402 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 403 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 404 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 405 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 406 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 407 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 408 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 409 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 410 "data//maps/SootopolisCity/scripts.pory"

# 411 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 412 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 413 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 414 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 415 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 416 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 417 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 418 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 419 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 420 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 421 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 422 "data//maps/SootopolisCity/scripts.pory"

# 423 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
# 424 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 425 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 426 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 427 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 428 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 429 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 430 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 431 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 432 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 433 "data//maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 434 "data//maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 435 "data//maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 436 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 437 "data//maps/SootopolisCity/scripts.pory"

# 438 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 439 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 440 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 441 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 442 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 443 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 444 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 445 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 446 "data//maps/SootopolisCity/scripts.pory"

# 447 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 448 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 449 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 450 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 451 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 452 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 453 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 454 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 455 "data//maps/SootopolisCity/scripts.pory"

# 456 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 457 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 458 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 459 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 460 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 461 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 462 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 463 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 464 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 465 "data//maps/SootopolisCity/scripts.pory"

# 466 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
# 467 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 468 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 469 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 470 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 471 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 472 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 473 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 474 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 475 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 476 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 477 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 478 "data//maps/SootopolisCity/scripts.pory"

# 479 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 480 "data//maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 481 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 482 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 483 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 484 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 485 "data//maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 486 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 487 "data//maps/SootopolisCity/scripts.pory"

# 488 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 489 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 490 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 491 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 492 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 493 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 494 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 495 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 496 "data//maps/SootopolisCity/scripts.pory"

# 497 "data//maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 498 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 499 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 500 "data//maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 501 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 502 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 503 "data//maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 504 "data//maps/SootopolisCity/scripts.pory"
	end
# 505 "data//maps/SootopolisCity/scripts.pory"

# 506 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 507 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 508 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 509 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 510 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 511 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 512 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 513 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 514 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 515 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_GROUDON
# 516 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_KYOGRE
# 517 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_RAYQUAZA
# 518 "data//maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 519 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 520 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 521 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 522 "data//maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 523 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 524 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
# 525 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 526 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 527 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 528 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 529 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 530 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 531 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 532 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 533 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 534 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 535 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 536 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 537 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 538 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 539 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 540 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 541 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 542 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 543 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 544 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 545 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 546 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 547 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_RAYQUAZA
# 548 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 549 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 550 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 551 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 552 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 553 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 554 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 555 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 556 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 557 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 558 "data//maps/SootopolisCity/scripts.pory"
	end
# 559 "data//maps/SootopolisCity/scripts.pory"

# 560 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 561 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 562 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 563 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 564 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 565 "data//maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 566 "data//maps/SootopolisCity/scripts.pory"
	delay 60
# 567 "data//maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 568 "data//maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 569 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_GROUDON
# 570 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_KYOGRE
# 571 "data//maps/SootopolisCity/scripts.pory"
	addobject LOCALID_RAYQUAZA
# 572 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 573 "data//maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 574 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 575 "data//maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 576 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
# 577 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 578 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 579 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 580 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 581 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 582 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 583 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 584 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 585 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 586 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 587 "data//maps/SootopolisCity/scripts.pory"
	waitse
# 588 "data//maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 589 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 590 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 591 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 592 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 593 "data//maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 594 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 595 "data//maps/SootopolisCity/scripts.pory"
	waitmoncry
# 596 "data//maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 597 "data//maps/SootopolisCity/scripts.pory"
	doweather
# 598 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 599 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 600 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_RAYQUAZA
# 601 "data//maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 602 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 603 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 604 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 605 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 606 "data//maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SURF
# 607 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 608 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 609 "data//maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 610 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 611 "data//maps/SootopolisCity/scripts.pory"
	end
# 612 "data//maps/SootopolisCity/scripts.pory"

# 613 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 614 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 615 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 616 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 617 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 618 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 619 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 620 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 621 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 622 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 623 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 624 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 625 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 626 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 627 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 628 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 629 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 630 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 631 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 632 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 633 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 634 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 635 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 636 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 637 "data//maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 638 "data//maps/SootopolisCity/scripts.pory"
	return
# 639 "data//maps/SootopolisCity/scripts.pory"

# 640 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 641 "data//maps/SootopolisCity/scripts.pory"
	walk_fast_up
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
	walk_faster_up
# 648 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 649 "data//maps/SootopolisCity/scripts.pory"

# 650 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 651 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 652 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 653 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 654 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 655 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 656 "data//maps/SootopolisCity/scripts.pory"

# 657 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 658 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 659 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 660 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 661 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 662 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 663 "data//maps/SootopolisCity/scripts.pory"

# 664 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 665 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 666 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 667 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 668 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 669 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 670 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 671 "data//maps/SootopolisCity/scripts.pory"

# 672 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 673 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
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
	walk_slow_diag_northeast
# 682 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 683 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 684 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 685 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 686 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 687 "data//maps/SootopolisCity/scripts.pory"

# 688 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 689 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
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
	walk_down
# 701 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 702 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 703 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 704 "data//maps/SootopolisCity/scripts.pory"

# 705 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 706 "data//maps/SootopolisCity/scripts.pory"
	lock
# 707 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 708 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 709 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 710 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 711 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 712 "data//maps/SootopolisCity/scripts.pory"
	release
# 713 "data//maps/SootopolisCity/scripts.pory"
	end
# 714 "data//maps/SootopolisCity/scripts.pory"

# 715 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 716 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 717 "data//maps/SootopolisCity/scripts.pory"
	release
# 718 "data//maps/SootopolisCity/scripts.pory"
	end
# 719 "data//maps/SootopolisCity/scripts.pory"

# 720 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 721 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 722 "data//maps/SootopolisCity/scripts.pory"
	release
# 723 "data//maps/SootopolisCity/scripts.pory"
	end
# 724 "data//maps/SootopolisCity/scripts.pory"

# 725 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 726 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 727 "data//maps/SootopolisCity/scripts.pory"
	release
# 728 "data//maps/SootopolisCity/scripts.pory"
	end
# 729 "data//maps/SootopolisCity/scripts.pory"

# 730 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 731 "data//maps/SootopolisCity/scripts.pory"
	lock
# 732 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 733 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 734 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 735 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 736 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 737 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 738 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 739 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 740 "data//maps/SootopolisCity/scripts.pory"
	release
# 741 "data//maps/SootopolisCity/scripts.pory"
	end
# 742 "data//maps/SootopolisCity/scripts.pory"

# 743 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 744 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 745 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 746 "data//maps/SootopolisCity/scripts.pory"
	release
# 747 "data//maps/SootopolisCity/scripts.pory"
	end
# 748 "data//maps/SootopolisCity/scripts.pory"

# 749 "data//maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
# 750 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 751 "data//maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 752 "data//maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 753 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 754 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 755 "data//maps/SootopolisCity/scripts.pory"
	random NUM_KIRI_BERRIES
# 756 "data//maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
# 757 "data//maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 758 "data//maps/SootopolisCity/scripts.pory"
	giveitem VAR_RESULT
# 759 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 760 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 761 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 762 "data//maps/SootopolisCity/scripts.pory"
	random 2
# 763 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 764 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 765 "data//maps/SootopolisCity/scripts.pory"
	end
# 766 "data//maps/SootopolisCity/scripts.pory"

# 767 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 768 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 769 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 770 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 771 "data//maps/SootopolisCity/scripts.pory"
	release
# 772 "data//maps/SootopolisCity/scripts.pory"
	end
# 773 "data//maps/SootopolisCity/scripts.pory"

# 774 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 775 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 776 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 777 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 778 "data//maps/SootopolisCity/scripts.pory"
	release
# 779 "data//maps/SootopolisCity/scripts.pory"
	end
# 780 "data//maps/SootopolisCity/scripts.pory"

# 781 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 782 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 783 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 784 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 785 "data//maps/SootopolisCity/scripts.pory"
	release
# 786 "data//maps/SootopolisCity/scripts.pory"
	end
# 787 "data//maps/SootopolisCity/scripts.pory"

# 788 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 789 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 790 "data//maps/SootopolisCity/scripts.pory"
	release
# 791 "data//maps/SootopolisCity/scripts.pory"
	end
# 792 "data//maps/SootopolisCity/scripts.pory"

# 793 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 794 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 795 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_2, Common_Movement_FacePlayer
# 796 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 797 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 798 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 799 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 800 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_2, Common_Movement_FaceOriginalDirection
# 801 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 802 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 803 "data//maps/SootopolisCity/scripts.pory"
	end
# 804 "data//maps/SootopolisCity/scripts.pory"

# 805 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 806 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 807 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 808 "data//maps/SootopolisCity/scripts.pory"
	end
# 809 "data//maps/SootopolisCity/scripts.pory"

# 810 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 811 "data//maps/SootopolisCity/scripts.pory"
	lock
# 812 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 813 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 814 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 815 "data//maps/SootopolisCity/scripts.pory"
	release
# 816 "data//maps/SootopolisCity/scripts.pory"
	end
# 817 "data//maps/SootopolisCity/scripts.pory"

# 818 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 819 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 820 "data//maps/SootopolisCity/scripts.pory"
	release
# 821 "data//maps/SootopolisCity/scripts.pory"
	end
# 822 "data//maps/SootopolisCity/scripts.pory"

# 823 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 824 "data//maps/SootopolisCity/scripts.pory"
	lock
# 825 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 826 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 827 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 828 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 829 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 830 "data//maps/SootopolisCity/scripts.pory"
	release
# 831 "data//maps/SootopolisCity/scripts.pory"
	end
# 832 "data//maps/SootopolisCity/scripts.pory"

# 833 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 834 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 835 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 836 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 837 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 838 "data//maps/SootopolisCity/scripts.pory"
	release
# 839 "data//maps/SootopolisCity/scripts.pory"
	end
# 840 "data//maps/SootopolisCity/scripts.pory"

# 841 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 842 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 843 "data//maps/SootopolisCity/scripts.pory"
	release
# 844 "data//maps/SootopolisCity/scripts.pory"
	end
# 845 "data//maps/SootopolisCity/scripts.pory"

# 846 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 847 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 848 "data//maps/SootopolisCity/scripts.pory"
	release
# 849 "data//maps/SootopolisCity/scripts.pory"
	end
# 850 "data//maps/SootopolisCity/scripts.pory"

# 851 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 852 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 853 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_NINJA_BOY, Common_Movement_FacePlayer
# 854 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 855 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 856 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 857 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 858 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 859 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 860 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 861 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 862 "data//maps/SootopolisCity/scripts.pory"
	release
# 863 "data//maps/SootopolisCity/scripts.pory"
	end
# 864 "data//maps/SootopolisCity/scripts.pory"

# 865 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 866 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 867 "data//maps/SootopolisCity/scripts.pory"
	release
# 868 "data//maps/SootopolisCity/scripts.pory"
	end
# 869 "data//maps/SootopolisCity/scripts.pory"

# 870 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 871 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 872 "data//maps/SootopolisCity/scripts.pory"
	release
# 873 "data//maps/SootopolisCity/scripts.pory"
	end
# 874 "data//maps/SootopolisCity/scripts.pory"

# 875 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 876 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 877 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_1, Common_Movement_FacePlayer
# 878 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 879 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 880 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 881 "data//maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 882 "data//maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 883 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 884 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 885 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_1, Common_Movement_FaceOriginalDirection
# 886 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 887 "data//maps/SootopolisCity/scripts.pory"
	release
# 888 "data//maps/SootopolisCity/scripts.pory"
	end
# 889 "data//maps/SootopolisCity/scripts.pory"

# 890 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 891 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 892 "data//maps/SootopolisCity/scripts.pory"
	release
# 893 "data//maps/SootopolisCity/scripts.pory"
	end
# 894 "data//maps/SootopolisCity/scripts.pory"

# 895 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 896 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 897 "data//maps/SootopolisCity/scripts.pory"
	release
# 898 "data//maps/SootopolisCity/scripts.pory"
	end
# 899 "data//maps/SootopolisCity/scripts.pory"

# 900 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 901 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 902 "data//maps/SootopolisCity/scripts.pory"
	release
# 903 "data//maps/SootopolisCity/scripts.pory"
	end
# 904 "data//maps/SootopolisCity/scripts.pory"

# 905 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 906 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 907 "data//maps/SootopolisCity/scripts.pory"
	end
# 908 "data//maps/SootopolisCity/scripts.pory"

# 909 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 910 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 911 "data//maps/SootopolisCity/scripts.pory"
	end
# 912 "data//maps/SootopolisCity/scripts.pory"

# 913 "data//maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 914 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 915 "data//maps/SootopolisCity/scripts.pory"
	end
# 916 "data//maps/SootopolisCity/scripts.pory"

# 917 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 918 "data//maps/SootopolisCity/scripts.pory"
	lock
# 919 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 920 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 921 "data//maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 922 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 923 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 924 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 925 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 926 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 927 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 928 "data//maps/SootopolisCity/scripts.pory"
	end
# 929 "data//maps/SootopolisCity/scripts.pory"

# 930 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 931 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 932 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 933 "data//maps/SootopolisCity/scripts.pory"
	end
# 934 "data//maps/SootopolisCity/scripts.pory"

# 935 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 936 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 937 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 938 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 939 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 940 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 941 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_StevenUntilNextTime, MSGBOX_DEFAULT
# 942 "data//maps/SootopolisCity/scripts.pory"
	waitmessage
# 943 "data//maps/SootopolisCity/scripts.pory"
	@ delay 50
# 944 "data//maps/SootopolisCity/scripts.pory"
	setfieldeffectargument 0, 1
# 945 "data//maps/SootopolisCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 946 "data//maps/SootopolisCity/scripts.pory"
	delay 15
# 947 "data//maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_STEVEN
# 948 "data//maps/SootopolisCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 949 "data//maps/SootopolisCity/scripts.pory"
	@ warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 950 "data//maps/SootopolisCity/scripts.pory"
	@ waitstate
# 951 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 952 "data//maps/SootopolisCity/scripts.pory"
	end
# 953 "data//maps/SootopolisCity/scripts.pory"

# 954 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 955 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 956 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 957 "data//maps/SootopolisCity/scripts.pory"
	end
# 958 "data//maps/SootopolisCity/scripts.pory"

# 959 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 960 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 961 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 962 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 963 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 964 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 965 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 966 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 967 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 968 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 969 "data//maps/SootopolisCity/scripts.pory"
	delay 120
# 970 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 971 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 972 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 973 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 974 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 975 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 976 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 977 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 978 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 979 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 980 "data//maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 981 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 982 "data//maps/SootopolisCity/scripts.pory"
	end
# 983 "data//maps/SootopolisCity/scripts.pory"

# 984 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 985 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 986 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 987 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 988 "data//maps/SootopolisCity/scripts.pory"
	return
# 989 "data//maps/SootopolisCity/scripts.pory"

# 990 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 991 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 992 "data//maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 993 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 994 "data//maps/SootopolisCity/scripts.pory"
	return
# 995 "data//maps/SootopolisCity/scripts.pory"

# 996 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 997 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 998 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 999 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1000 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1001 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1002 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1013 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1014 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1015 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1016 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1017 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1018 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1019 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1020 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1021 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_in_place_faster_down
# 1033 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1034 "data//maps/SootopolisCity/scripts.pory"

# 1035 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 1036 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1037 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1038 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1040 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1041 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1042 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1053 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1054 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1055 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1056 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1057 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1058 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1059 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1060 "data//maps/SootopolisCity/scripts.pory"
	walk_left
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
	step_end
# 1072 "data//maps/SootopolisCity/scripts.pory"

# 1073 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1074 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1075 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1076 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1077 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1078 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1079 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1080 "data//maps/SootopolisCity/scripts.pory"
	walk_up
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
	walk_left
# 1091 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1092 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1093 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1094 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1095 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1096 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1097 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1098 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1099 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1100 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1101 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1102 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1103 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1104 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1105 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1106 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1107 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1108 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1109 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1110 "data//maps/SootopolisCity/scripts.pory"

# 1111 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1112 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1113 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1114 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1115 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1116 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1117 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1118 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1119 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1120 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1121 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1122 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1123 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1124 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1125 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1126 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1127 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1128 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1129 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1130 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1131 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1132 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1133 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1134 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1135 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1136 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1137 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1138 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1139 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1140 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1141 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1142 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1143 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1144 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1145 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1146 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1147 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1148 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1149 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1150 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1151 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1152 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1153 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1154 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1155 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1156 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1157 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1158 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1159 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1160 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1161 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1162 "data//maps/SootopolisCity/scripts.pory"
	delay_4
# 1163 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1164 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1165 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1166 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1167 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1168 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1169 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1170 "data//maps/SootopolisCity/scripts.pory"

# 1171 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1172 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1173 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1174 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1175 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1176 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1177 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1178 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1179 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1180 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1181 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1182 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1183 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1184 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1185 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1186 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1187 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1188 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1189 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1190 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1191 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1192 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1193 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1194 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1195 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1196 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1197 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1198 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1199 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1200 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1201 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1202 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1203 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1204 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1205 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1206 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1207 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1208 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1209 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1210 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1211 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1212 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1213 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1214 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1215 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1216 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1217 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1218 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1219 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1220 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1221 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1222 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1223 "data//maps/SootopolisCity/scripts.pory"

# 1224 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1225 "data//maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1226 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1227 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1228 "data//maps/SootopolisCity/scripts.pory"

# 1229 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1230 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1231 "data//maps/SootopolisCity/scripts.pory"
	walk_down
# 1232 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1233 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1234 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1235 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1236 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1237 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1238 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1239 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1240 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1241 "data//maps/SootopolisCity/scripts.pory"

# 1242 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1243 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1244 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1245 "data//maps/SootopolisCity/scripts.pory"
	delay_16
# 1246 "data//maps/SootopolisCity/scripts.pory"
	delay_8
# 1247 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1248 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1249 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1250 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1251 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1252 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1253 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1254 "data//maps/SootopolisCity/scripts.pory"

# 1255 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1256 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1257 "data//maps/SootopolisCity/scripts.pory"
	walk_up
# 1258 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1259 "data//maps/SootopolisCity/scripts.pory"

# 1260 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1261 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1262 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_2, Common_Movement_FacePlayer
# 1263 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1264 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1265 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1266 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1267 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_2, Common_Movement_FaceOriginalDirection
# 1268 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1269 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1270 "data//maps/SootopolisCity/scripts.pory"
	end
# 1271 "data//maps/SootopolisCity/scripts.pory"

# 1272 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1273 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1274 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1275 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1276 "data//maps/SootopolisCity/scripts.pory"
	end
# 1277 "data//maps/SootopolisCity/scripts.pory"

# 1278 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1279 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1280 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1281 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1282 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1283 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
# 1284 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1285 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1286 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1287 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1288 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1289 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1290 "data//maps/SootopolisCity/scripts.pory"
	end
# 1291 "data//maps/SootopolisCity/scripts.pory"

# 1292 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1293 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
# 1294 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1295 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1296 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1297 "data//maps/SootopolisCity/scripts.pory"
	end
# 1298 "data//maps/SootopolisCity/scripts.pory"

# 1299 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1300 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1301 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GIRL, Common_Movement_FacePlayer
# 1302 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1303 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1304 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1305 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1306 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GIRL, Common_Movement_FaceOriginalDirection
# 1307 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1308 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1309 "data//maps/SootopolisCity/scripts.pory"
	end
# 1310 "data//maps/SootopolisCity/scripts.pory"

# 1311 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1312 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1313 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1314 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1315 "data//maps/SootopolisCity/scripts.pory"
	end
# 1316 "data//maps/SootopolisCity/scripts.pory"

# 1317 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1318 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1319 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_MANIAC, Common_Movement_FacePlayer
# 1320 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1321 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1322 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1323 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1324 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_MANIAC, Common_Movement_FaceOriginalDirection
# 1325 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1326 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1327 "data//maps/SootopolisCity/scripts.pory"
	end
# 1328 "data//maps/SootopolisCity/scripts.pory"

# 1329 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1330 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1331 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1332 "data//maps/SootopolisCity/scripts.pory"
	end
# 1333 "data//maps/SootopolisCity/scripts.pory"

# 1334 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1335 "data//maps/SootopolisCity/scripts.pory"
	lock
# 1336 "data//maps/SootopolisCity/scripts.pory"
	faceplayer
# 1337 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1338 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1339 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1340 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1341 "data//maps/SootopolisCity/scripts.pory"
	release
# 1342 "data//maps/SootopolisCity/scripts.pory"
	end
# 1343 "data//maps/SootopolisCity/scripts.pory"

# 1344 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1345 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1346 "data//maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1347 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1348 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1349 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1350 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1351 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1352 "data//maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1353 "data//maps/SootopolisCity/scripts.pory"
	release
# 1354 "data//maps/SootopolisCity/scripts.pory"
	end
# 1355 "data//maps/SootopolisCity/scripts.pory"

# 1356 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1357 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1358 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1359 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_WALLACE
# 1360 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1361 "data//maps/SootopolisCity/scripts.pory"
	return
# 1362 "data//maps/SootopolisCity/scripts.pory"

# 1363 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1364 "data//maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1365 "data//maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1366 "data//maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_WALLACE
# 1367 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1368 "data//maps/SootopolisCity/scripts.pory"
	return
# 1369 "data//maps/SootopolisCity/scripts.pory"

# 1370 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1371 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1372 "data//maps/SootopolisCity/scripts.pory"
	release
# 1373 "data//maps/SootopolisCity/scripts.pory"
	end
# 1374 "data//maps/SootopolisCity/scripts.pory"

# 1375 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1376 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1377 "data//maps/SootopolisCity/scripts.pory"
	release
# 1378 "data//maps/SootopolisCity/scripts.pory"
	end
# 1379 "data//maps/SootopolisCity/scripts.pory"

# 1380 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1381 "data//maps/SootopolisCity/scripts.pory"
	walk_right
# 1382 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1383 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1384 "data//maps/SootopolisCity/scripts.pory"

# 1385 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1386 "data//maps/SootopolisCity/scripts.pory"
	walk_left
# 1387 "data//maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1388 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1389 "data//maps/SootopolisCity/scripts.pory"

# 1390 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1391 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1392 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1393 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1394 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1395 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1396 "data//maps/SootopolisCity/scripts.pory"
	end
# 1397 "data//maps/SootopolisCity/scripts.pory"

# 1398 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1399 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1400 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1401 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1402 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1403 "data//maps/SootopolisCity/scripts.pory"
	end
# 1404 "data//maps/SootopolisCity/scripts.pory"

# 1405 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1406 "data//maps/SootopolisCity/scripts.pory"
	lockall
# 1407 "data//maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1408 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1409 "data//maps/SootopolisCity/scripts.pory"
	closemessage
# 1410 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1411 "data//maps/SootopolisCity/scripts.pory"
	end
# 1412 "data//maps/SootopolisCity/scripts.pory"

# 1413 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1414 "data//maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1415 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1416 "data//maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1417 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1418 "data//maps/SootopolisCity/scripts.pory"
	end
# 1419 "data//maps/SootopolisCity/scripts.pory"

# 1420 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1421 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1422 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1423 "data//maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1424 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1425 "data//maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1426 "data//maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1427 "data//maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1428 "data//maps/SootopolisCity/scripts.pory"
	waitstate
# 1429 "data//maps/SootopolisCity/scripts.pory"
	releaseall
# 1430 "data//maps/SootopolisCity/scripts.pory"
	end
# 1431 "data//maps/SootopolisCity/scripts.pory"

# 1432 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1433 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1434 "data//maps/SootopolisCity/scripts.pory"
	levitate
# 1435 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1436 "data//maps/SootopolisCity/scripts.pory"

# 1437 "data//maps/SootopolisCity/scripts.pory"
@ Unused
# 1438 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1439 "data//maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1440 "data//maps/SootopolisCity/scripts.pory"
	step_end
# 1441 "data//maps/SootopolisCity/scripts.pory"

# 1442 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1443 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
# 1444 "data//maps/SootopolisCity/scripts.pory"
	.string "LEADER: JUAN\p"
# 1445 "data//maps/SootopolisCity/scripts.pory"
	.string "“The GYM LEADER with the beauty\n"
# 1446 "data//maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1447 "data//maps/SootopolisCity/scripts.pory"

# 1448 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1449 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY\p"
# 1450 "data//maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1451 "data//maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1452 "data//maps/SootopolisCity/scripts.pory"

# 1453 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1454 "data//maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1455 "data//maps/SootopolisCity/scripts.pory"

# 1456 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1457 "data//maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1458 "data//maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1459 "data//maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1460 "data//maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1461 "data//maps/SootopolisCity/scripts.pory"

# 1462 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1463 "data//maps/SootopolisCity/scripts.pory"
	.string "These giant POKéMON suddenly appeared\n"
# 1464 "data//maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1465 "data//maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1466 "data//maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1467 "data//maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1468 "data//maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1469 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1470 "data//maps/SootopolisCity/scripts.pory"

# 1471 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1472 "data//maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1473 "data//maps/SootopolisCity/scripts.pory"
	.string "What is that green POKéMON?!$"
# 1474 "data//maps/SootopolisCity/scripts.pory"

# 1475 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1476 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON and KYOGRE…\n"
# 1477 "data//maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1478 "data//maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1479 "data//maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1480 "data//maps/SootopolisCity/scripts.pory"

# 1481 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1482 "data//maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1483 "data//maps/SootopolisCity/scripts.pory"
	.string "the two POKéMON aren't angry.\p"
# 1484 "data//maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1485 "data//maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1486 "data//maps/SootopolisCity/scripts.pory"

# 1487 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1488 "data//maps/SootopolisCity/scripts.pory"
	.string "That flying POKéMON came down from\n"
# 1489 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1490 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON…$"
# 1491 "data//maps/SootopolisCity/scripts.pory"

# 1492 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1493 "data//maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1494 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1495 "data//maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1496 "data//maps/SootopolisCity/scripts.pory"

# 1497 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1498 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1499 "data//maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1500 "data//maps/SootopolisCity/scripts.pory"

# 1501 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1502 "data//maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1503 "data//maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1504 "data//maps/SootopolisCity/scripts.pory"

# 1505 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1506 "data//maps/SootopolisCity/scripts.pory"
	.string "Go for it, red POKéMON!\n"
# 1507 "data//maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue POKéMON!$"
# 1508 "data//maps/SootopolisCity/scripts.pory"

# 1509 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1510 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1511 "data//maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1512 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON fighting over there?$"
# 1513 "data//maps/SootopolisCity/scripts.pory"

# 1514 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1515 "data//maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1516 "data//maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1517 "data//maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1518 "data//maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1519 "data//maps/SootopolisCity/scripts.pory"

# 1520 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1521 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1522 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1523 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1524 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1525 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1526 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1527 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1528 "data//maps/SootopolisCity/scripts.pory"

# 1529 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1530 "data//maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1531 "data//maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1532 "data//maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1533 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1534 "data//maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1535 "data//maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1536 "data//maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1537 "data//maps/SootopolisCity/scripts.pory"

# 1538 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1539 "data//maps/SootopolisCity/scripts.pory"
	.string "A big POKéMON is fighting with\n"
# 1540 "data//maps/SootopolisCity/scripts.pory"
	.string "another big POKéMON!\p"
# 1541 "data//maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1542 "data//maps/SootopolisCity/scripts.pory"

# 1543 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1544 "data//maps/SootopolisCity/scripts.pory"
	.string "A pretty POKéMON came down from\n"
# 1545 "data//maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1546 "data//maps/SootopolisCity/scripts.pory"

# 1547 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1548 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1549 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY will get wrecked!$"
# 1550 "data//maps/SootopolisCity/scripts.pory"

# 1551 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1552 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
# 1553 "data//maps/SootopolisCity/scripts.pory"

# 1554 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1555 "data//maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1556 "data//maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to SOOTOPOLIS?\l"
# 1557 "data//maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1558 "data//maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1559 "data//maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1560 "data//maps/SootopolisCity/scripts.pory"

# 1561 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1562 "data//maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1563 "data//maps/SootopolisCity/scripts.pory"

# 1564 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1565 "data//maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1566 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN.\p"
# 1567 "data//maps/SootopolisCity/scripts.pory"
	.string "The spirits of POKéMON, becalmed at\n"
# 1568 "data//maps/SootopolisCity/scripts.pory"
	.string "MT. PYRE, are said to be revived here.\p"
# 1569 "data//maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1570 "data//maps/SootopolisCity/scripts.pory"

# 1571 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1572 "data//maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1573 "data//maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1574 "data//maps/SootopolisCity/scripts.pory"
	.string "A TRAINER who has knowledge and\n"
# 1575 "data//maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of POKéMON…\p"
# 1576 "data//maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1577 "data//maps/SootopolisCity/scripts.pory"
	.string "instructed by WALLACE to lead that\l"
# 1578 "data//maps/SootopolisCity/scripts.pory"
	.string "TRAINER to this CAVE.$"
# 1579 "data//maps/SootopolisCity/scripts.pory"

# 1580 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1581 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1582 "data//maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1583 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON was quelled by the awakening\l"
# 1584 "data//maps/SootopolisCity/scripts.pory"
	.string "of a third POKéMON…$"
# 1585 "data//maps/SootopolisCity/scripts.pory"

# 1586 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1587 "data//maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN…\p"
# 1588 "data//maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1589 "data//maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1590 "data//maps/SootopolisCity/scripts.pory"

# 1591 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1592 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS sprang up as a town in\n"
# 1593 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1594 "data//maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1595 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1596 "data//maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1597 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1598 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS the most beautiful.$"
# 1599 "data//maps/SootopolisCity/scripts.pory"

# 1600 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1601 "data//maps/SootopolisCity/scripts.pory"
	.string "When two POKéMON that gigantic\n"
# 1602 "data//maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1603 "data//maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1604 "data//maps/SootopolisCity/scripts.pory"

# 1605 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1606 "data//maps/SootopolisCity/scripts.pory"
	.string "When that third POKéMON flew down,\n"
# 1607 "data//maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1608 "data//maps/SootopolisCity/scripts.pory"

# 1609 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1610 "data//maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1611 "data//maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1612 "data//maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1613 "data//maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1614 "data//maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1615 "data//maps/SootopolisCity/scripts.pory"

# 1616 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1617 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1618 "data//maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1619 "data//maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1620 "data//maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1621 "data//maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1622 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1623 "data//maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1624 "data//maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1625 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1626 "data//maps/SootopolisCity/scripts.pory"

# 1627 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1628 "data//maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1629 "data//maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1630 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON here?\p"
# 1631 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1632 "data//maps/SootopolisCity/scripts.pory"

# 1633 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1634 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: G… GROUDON…\n"
# 1635 "data//maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1636 "data//maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1637 "data//maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all HOENN, not just\n"
# 1638 "data//maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS, will be utterly ruined!$"
# 1639 "data//maps/SootopolisCity/scripts.pory"

# 1640 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1641 "data//maps/SootopolisCity/scripts.pory"
	.string "MAXIE: So the super-ancient POKéMON\n"
# 1642 "data//maps/SootopolisCity/scripts.pory"
	.string "weren't only GROUDON and KYOGRE…\p"
# 1643 "data//maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1644 "data//maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one POKéMON's\l"
# 1645 "data//maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1646 "data//maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1647 "data//maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1648 "data//maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1649 "data//maps/SootopolisCity/scripts.pory"

# 1650 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1651 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
# 1652 "data//maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the RED ORB!\l"
# 1653 "data//maps/SootopolisCity/scripts.pory"
	.string "Calm down! KYOGRE!\p"
# 1654 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1655 "data//maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1656 "data//maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1657 "data//maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1658 "data//maps/SootopolisCity/scripts.pory"

# 1659 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1660 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE and GROUDON both\n"
# 1661 "data//maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1662 "data//maps/SootopolisCity/scripts.pory"
	.string "The weather in HOENN has returned\n"
# 1663 "data//maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1664 "data//maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1665 "data//maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1666 "data//maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1667 "data//maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1668 "data//maps/SootopolisCity/scripts.pory"
	.string "to POKéMON…$"
# 1669 "data//maps/SootopolisCity/scripts.pory"

# 1670 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1671 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Those POKéMON fighting…\n"
# 1672 "data//maps/SootopolisCity/scripts.pory"
	.string "GROUDON… And KYOGRE…\p"
# 1673 "data//maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient POKéMON\n"
# 1674 "data//maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1675 "data//maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1676 "data//maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1677 "data//maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1678 "data//maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1679 "data//maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1680 "data//maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1681 "data//maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1682 "data//maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1683 "data//maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1684 "data//maps/SootopolisCity/scripts.pory"

# 1685 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1686 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
# 1687 "data//maps/SootopolisCity/scripts.pory"
	.string "Does seeing GROUDON and KYOGRE make\n"
# 1688 "data//maps/SootopolisCity/scripts.pory"
	.string "you think POKéMON are to be feared?\p"
# 1689 "data//maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1690 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON are really more…\p"
# 1691 "data//maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1692 "data//maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1693 "data//maps/SootopolisCity/scripts.pory"

# 1694 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1695 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Okay, here we are!\p"
# 1696 "data//maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1697 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE.\p"
# 1698 "data//maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1699 "data//maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1700 "data//maps/SootopolisCity/scripts.pory"

# 1701 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1702 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: I think you have what's\n"
# 1703 "data//maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1704 "data//maps/SootopolisCity/scripts.pory"

# 1705 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1706 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: The SKY PILLAR…\p"
# 1707 "data//maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1708 "data//maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1709 "data//maps/SootopolisCity/scripts.pory"

# 1710 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1711 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: So that's RAYQUAZA…\p"
# 1712 "data//maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1713 "data//maps/SootopolisCity/scripts.pory"
	.string "POKéMON would flee from it in fear…$"
# 1714 "data//maps/SootopolisCity/scripts.pory"

# 1715 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1716 "data//maps/SootopolisCity/scripts.pory"
	.string "STEVEN: It looks like both MAXIE and\n"
# 1717 "data//maps/SootopolisCity/scripts.pory"
	.string "ARCHIE have gone away somewhere.\p"
# 1718 "data//maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to MT. PYRE to\n"
# 1719 "data//maps/SootopolisCity/scripts.pory"
	.string "return those ORBS…$"
# 1720 "data//maps/SootopolisCity/scripts.pory"

# 1721 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenGiveDevonScope:
# 1722 "data//maps/SootopolisCity/scripts.pory"
	.string "RAYQUAZA seemingly flew off towards\n"
# 1723 "data//maps/SootopolisCity/scripts.pory"
	.string "the forests around FORTREE CITY.\p"
# 1724 "data//maps/SootopolisCity/scripts.pory"
	.string "If you're going to track it down\n"
# 1725 "data//maps/SootopolisCity/scripts.pory"
	.string "you'll need this DEVON SCOPE.\p"
# 1726 "data//maps/SootopolisCity/scripts.pory"
	.string "A POKéMON called KECLEON makes\n"
# 1727 "data//maps/SootopolisCity/scripts.pory"
	.string "that area hard to navigate . . .\p"
# 1728 "data//maps/SootopolisCity/scripts.pory"
	.string "the DEVON SCOPE allows you to see\n"
# 1729 "data//maps/SootopolisCity/scripts.pory"
	.string "through their camouflage.$"
# 1730 "data//maps/SootopolisCity/scripts.pory"

# 1731 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_StevenUntilNextTime:
# 1732 "data//maps/SootopolisCity/scripts.pory"
	.string "Until next time, {PLAYER}!$"
# 1733 "data//maps/SootopolisCity/scripts.pory"

# 1734 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1735 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: Oh?\n"
# 1736 "data//maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1737 "data//maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the SKY PILLAR\n"
# 1738 "data//maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1739 "data//maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1740 "data//maps/SootopolisCity/scripts.pory"
	.string "the top of the SKY PILLAR…$"
# 1741 "data//maps/SootopolisCity/scripts.pory"

# 1742 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1743 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 1744 "data//maps/SootopolisCity/scripts.pory"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
# 1745 "data//maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1746 "data//maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1747 "data//maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1748 "data//maps/SootopolisCity/scripts.pory"

# 1749 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1750 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\n"
# 1751 "data//maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1752 "data//maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, SOOTOPOLIS…\n"
# 1753 "data//maps/SootopolisCity/scripts.pory"
	.string "No, all of HOENN was saved.\p"
# 1754 "data//maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1755 "data//maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1756 "data//maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1757 "data//maps/SootopolisCity/scripts.pory"

# 1758 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1759 "data//maps/SootopolisCity/scripts.pory"
	.string "That HIDDEN MACHINE contains\n"
# 1760 "data//maps/SootopolisCity/scripts.pory"
	.string "WATERFALL.\p"
# 1761 "data//maps/SootopolisCity/scripts.pory"
	.string "If you have the RAIN BADGE, a POKéMON\n"
# 1762 "data//maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1763 "data//maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1764 "data//maps/SootopolisCity/scripts.pory"
	.string "And where does one get the RAIN BADGE?\n"
# 1765 "data//maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1766 "data//maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1767 "data//maps/SootopolisCity/scripts.pory"
	.string "the SOOTOPOLIS GYM LEADER.\p"
# 1768 "data//maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1769 "data//maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1770 "data//maps/SootopolisCity/scripts.pory"

# 1771 "data//maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1772 "data//maps/SootopolisCity/scripts.pory"
	.string "WALLACE: I'm sure that you will be\n"
# 1773 "data//maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1774 "data//maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
