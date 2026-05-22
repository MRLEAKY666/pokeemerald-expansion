# 1 "data//maps/VerdantPlateau/scripts.pory"

# 2 "data//maps/VerdantPlateau/scripts.pory"
.set LOCALID_TEAMLEADER, 1
# 3 "data//maps/VerdantPlateau/scripts.pory"

# 4 "data//maps/VerdantPlateau/scripts.pory"

# 5 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_MapScripts::
# 6 "data//maps/VerdantPlateau/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VerdantPlateau_OnLoad
# 7 "data//maps/VerdantPlateau/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdantPlateau_OnFrame
# 8 "data//maps/VerdantPlateau/scripts.pory"
	.byte 0
# 9 "data//maps/VerdantPlateau/scripts.pory"

# 10 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_OnLoad:
# 11 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_SetSun
# 12 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 3, VerdantPlateau_EventScript_SetSun
# 13 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 4, VerdantPlateau_EventScript_SetSun
# 14 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 5, VerdantPlateau_EventScript_SetSun
# 15 "data//maps/VerdantPlateau/scripts.pory"
	call_if_unset FLAG_PLATEAU_LEADER_EVENT, VerdantPlateau_EventScript_SetupTeamLeaderGfxId
# 16 "data//maps/VerdantPlateau/scripts.pory"
	end
# 17 "data//maps/VerdantPlateau/scripts.pory"

# 18 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetSun::
# 19 "data//maps/VerdantPlateau/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 20 "data//maps/VerdantPlateau/scripts.pory"
	doweather
# 21 "data//maps/VerdantPlateau/scripts.pory"
	return
# 22 "data//maps/VerdantPlateau/scripts.pory"

# 23 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetSunOnFrame::
# 24 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 25 "data//maps/VerdantPlateau/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 26 "data//maps/VerdantPlateau/scripts.pory"
	doweather
# 27 "data//maps/VerdantPlateau/scripts.pory"
	return
# 28 "data//maps/VerdantPlateau/scripts.pory"

# 29 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ClearSun::
# 30 "data//maps/VerdantPlateau/scripts.pory"
	setweather WEATHER_NONE
# 31 "data//maps/VerdantPlateau/scripts.pory"
	doweather
# 32 "data//maps/VerdantPlateau/scripts.pory"
	return
# 33 "data//maps/VerdantPlateau/scripts.pory"

# 34 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetupTeamLeaderGfxId::
# 35 "data//maps/VerdantPlateau/scripts.pory"
	call_if_set FLAG_HIDE_PLATEAU_LEADER, VerdantPlateau_EventScript_ShowPlateauLeader
# 36 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_le VAR_TIME_OF_DAY, 1, VerdantPlateau_EventScript_ShowArchie
# 37 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_le VAR_TIME_OF_DAY, 5, VerdantPlateau_EventScript_ShowMaxie
# 38 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_ge VAR_TIME_OF_DAY, 6, VerdantPlateau_EventScript_ShowArchie
# 39 "data//maps/VerdantPlateau/scripts.pory"
	return
# 40 "data//maps/VerdantPlateau/scripts.pory"

# 41 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowPlateauLeader::
# 42 "data//maps/VerdantPlateau/scripts.pory"
	clearflag FLAG_HIDE_PLATEAU_LEADER
# 43 "data//maps/VerdantPlateau/scripts.pory"
	return
# 44 "data//maps/VerdantPlateau/scripts.pory"

# 45 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowMaxie::
# 46 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE
# 47 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_IncrementTimeOfDay
# 48 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 4, VerdantPlateau_EventScript_IncrementTimeOfDay
# 49 "data//maps/VerdantPlateau/scripts.pory"
	return
# 50 "data//maps/VerdantPlateau/scripts.pory"

# 51 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowArchie::
# 52 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
# 53 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 0, VerdantPlateau_EventScript_IncrementTimeOfDay
# 54 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 6, VerdantPlateau_EventScript_IncrementTimeOfDay
# 55 "data//maps/VerdantPlateau/scripts.pory"
	return
# 56 "data//maps/VerdantPlateau/scripts.pory"

# 57 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_IncrementTimeOfDay::
# 58 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 59 "data//maps/VerdantPlateau/scripts.pory"
	return
# 60 "data//maps/VerdantPlateau/scripts.pory"

# 61 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_OnFrame:
# 62 "data//maps/VerdantPlateau/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_SwitchToDaytime
# 63 "data//maps/VerdantPlateau/scripts.pory"
	@ map_script_2 VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_SetSunOnFrame
# 64 "data//maps/VerdantPlateau/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 6, VerdantPlateau_EventScript_SwitchToNighttime
# 65 "data//maps/VerdantPlateau/scripts.pory"
	.2byte 0
# 66 "data//maps/VerdantPlateau/scripts.pory"

# 67 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SwitchToDaytime::
# 68 "data//maps/VerdantPlateau/scripts.pory"
	@ goto VerdantPlateau_EventScript_SwitchToDaytimeNew
# 69 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 70 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 71 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 72 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 73 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 74 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 75 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_SetSun
# 76 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 77 "data//maps/VerdantPlateau/scripts.pory"
	releaseall
# 78 "data//maps/VerdantPlateau/scripts.pory"
	end
# 79 "data//maps/VerdantPlateau/scripts.pory"

# 80 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SwitchToNighttime::
# 81 "data//maps/VerdantPlateau/scripts.pory"
	@ warpcontinuescript MAP_VERDANT_PLATEAU, 49, 4, VerdantPlateau_EventScript_SwitchToNighttimeNew
# 82 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 83 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 84 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 85 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 86 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 87 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 88 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_ClearSun
# 89 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 90 "data//maps/VerdantPlateau/scripts.pory"
	releaseall
# 91 "data//maps/VerdantPlateau/scripts.pory"
	end

VerdantPlateau_EventScript_SwitchToDaytimeNew::
# 96 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 97 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 98 "data//maps/VerdantPlateau/scripts.pory"
	waitbuttonpress
# 99 "data//maps/VerdantPlateau/scripts.pory"
	delay 10
# 101 "data//maps/VerdantPlateau/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 102 "data//maps/VerdantPlateau/scripts.pory"
	special SpawnCameraObject
# 103 "data//maps/VerdantPlateau/scripts.pory"
	setobjectxy OBJ_EVENT_ID_CAMERA, 49, 4
# 104 "data//maps/VerdantPlateau/scripts.pory"
	special DrawWholeMapView
# 106 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 108 "data//maps/VerdantPlateau/scripts.pory"
	waitbuttonpress
# 110 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 111 "data//maps/VerdantPlateau/scripts.pory"
	waitbuttonpress
# 112 "data//maps/VerdantPlateau/scripts.pory"
	delay 10
# 114 "data//maps/VerdantPlateau/scripts.pory"
	setobjectxy OBJ_EVENT_ID_CAMERA, VAR_TEMP_E, VAR_TEMP_F
# 115 "data//maps/VerdantPlateau/scripts.pory"
	special DrawWholeMapView
# 116 "data//maps/VerdantPlateau/scripts.pory"
	special RemoveCameraObject
# 117 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 118 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 119 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 121 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 122 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_SetSun
# 123 "data//maps/VerdantPlateau/scripts.pory"
	releaseall
	end


VerdantPlateau_EventScript_SwitchToNighttimeNew::
# 128 "data//maps/VerdantPlateau/scripts.pory"
	waitstate
# 129 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
# 133 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 136 "data//maps/VerdantPlateau/scripts.pory"
	waitbuttonpress
# 138 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 139 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement
# 141 "data//maps/VerdantPlateau/scripts.pory"
	waitbuttonpress
# 143 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 145 "data//maps/VerdantPlateau/scripts.pory"
	delay 10
# 147 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetVisible
# 148 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement
# 149 "data//maps/VerdantPlateau/scripts.pory"
	setobjectxy LOCALID_PLAYER, VAR_TEMP_E, VAR_TEMP_F
# 153 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 154 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 155 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 157 "data//maps/VerdantPlateau/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 158 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_ClearSun
# 159 "data//maps/VerdantPlateau/scripts.pory"
	releaseall
	end


# 163 "data//maps/VerdantPlateau/scripts.pory"

# 164 "data//maps/VerdantPlateau/scripts.pory"

# 165 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_TeamLeaderX::
# 166 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_PLATEAU_LEADER_EVENT
# 167 "data//maps/VerdantPlateau/scripts.pory"
	@goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE, VerdantPlateau_EventScript_Maxie
# 168 "data//maps/VerdantPlateau/scripts.pory"
	@goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE, VerdantPlateau_EventScript_Archie
# 169 "data//maps/VerdantPlateau/scripts.pory"
	end
# 170 "data//maps/VerdantPlateau/scripts.pory"

# 171 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Maxie::
# 172 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 173 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 174 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 175 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 176 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 177 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 178 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 179 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 180 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 181 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 182 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 183 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 184 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 185 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 186 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 187 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 188 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 189 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 190 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 191 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 192 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 193 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 194 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 195 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesNorth
# 196 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesEast
# 197 "data//maps/VerdantPlateau/scripts.pory"
	release
# 198 "data//maps/VerdantPlateau/scripts.pory"
	end
# 199 "data//maps/VerdantPlateau/scripts.pory"

# 200 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 201 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 202 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 203 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 204 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 205 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 206 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 207 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 208 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 209 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 210 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 211 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 212 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 213 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 214 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 215 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 216 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 217 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 218 "data//maps/VerdantPlateau/scripts.pory"
	return
# 219 "data//maps/VerdantPlateau/scripts.pory"

# 220 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 221 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 222 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 223 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 224 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 225 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 226 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 227 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 228 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 229 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 230 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 231 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 232 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 233 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 234 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 235 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 236 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 237 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 238 "data//maps/VerdantPlateau/scripts.pory"
	return
# 239 "data//maps/VerdantPlateau/scripts.pory"

# 240 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 241 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 242 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 243 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 244 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 245 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 246 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 247 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 248 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 249 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 250 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 251 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 252 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 253 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 254 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 255 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 256 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 257 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 258 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 259 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 260 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 261 "data//maps/VerdantPlateau/scripts.pory"
	return

VerdantPlateau_EventScript_TeamLeader::
# 266 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 267 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 268 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 269 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 270 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 271 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_TeamLeader_3
# 272 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_SOUTH, VerdantPlateau_EventScript_TeamLeader_4
# 273 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_TeamLeader_5
# 274 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_TeamLeader_6
VerdantPlateau_EventScript_TeamLeader_1:
# 276 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement
# 277 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_8
# 281 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_7:
# 283 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 284 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 285 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 286 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 287 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_12
# 293 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_11:
# 295 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 296 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 297 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_16
# 304 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_15:
# 306 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 307 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 308 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 309 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 310 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_20
# 314 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_19:
# 316 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 318 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 319 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_TeamLeader_25
# 327 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_TeamLeader_26
# 338 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_TeamLeader_27
VerdantPlateau_EventScript_TeamLeader_23:
# 347 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 348 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_29
# 353 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_28:
# 355 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 356 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 357 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_TeamLeader_34
# 358 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_SOUTH, VerdantPlateau_EventScript_TeamLeader_35
# 359 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_TeamLeader_36
# 360 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_TeamLeader_37
VerdantPlateau_EventScript_TeamLeader_32:
# 362 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement
# 363 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_39
# 367 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
VerdantPlateau_EventScript_TeamLeader_38:
# 369 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 370 "data//maps/VerdantPlateau/scripts.pory"
	compare VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
	goto_if_eq VerdantPlateau_EventScript_TeamLeader_43
# 374 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
VerdantPlateau_EventScript_TeamLeader_42:
# 376 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 377 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 378 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_TeamLeader_48
# 379 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_SOUTH, VerdantPlateau_EventScript_TeamLeader_49
# 380 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_TeamLeader_50
# 381 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_TeamLeader_51
VerdantPlateau_EventScript_TeamLeader_46:
# 383 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 384 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 385 "data//maps/VerdantPlateau/scripts.pory"
	release
	end

VerdantPlateau_EventScript_TeamLeader_3:
# 271 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceDown
	goto VerdantPlateau_EventScript_TeamLeader_1

VerdantPlateau_EventScript_TeamLeader_4:
# 272 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
	goto VerdantPlateau_EventScript_TeamLeader_1

VerdantPlateau_EventScript_TeamLeader_5:
# 273 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
	goto VerdantPlateau_EventScript_TeamLeader_1

VerdantPlateau_EventScript_TeamLeader_6:
# 274 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
	goto VerdantPlateau_EventScript_TeamLeader_1

VerdantPlateau_EventScript_TeamLeader_8:
# 278 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_0, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_7

VerdantPlateau_EventScript_TeamLeader_12:
# 288 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_1, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_11

VerdantPlateau_EventScript_TeamLeader_16:
# 298 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_2, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_15

VerdantPlateau_EventScript_TeamLeader_20:
# 311 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_3, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_19

VerdantPlateau_EventScript_TeamLeader_25:
# 320 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 321 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 322 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 323 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 324 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 325 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 326 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceRight
	goto VerdantPlateau_EventScript_TeamLeader_23

VerdantPlateau_EventScript_TeamLeader_26:
# 328 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 329 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 330 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 331 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 332 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 333 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 334 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 335 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 336 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 337 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceDown
	goto VerdantPlateau_EventScript_TeamLeader_23

VerdantPlateau_EventScript_TeamLeader_27:
# 339 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 340 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 341 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 342 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 343 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 344 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 345 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceLeft
	goto VerdantPlateau_EventScript_TeamLeader_23

VerdantPlateau_EventScript_TeamLeader_29:
# 349 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_4, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_28

VerdantPlateau_EventScript_TeamLeader_34:
# 357 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceDown
	goto VerdantPlateau_EventScript_TeamLeader_32

VerdantPlateau_EventScript_TeamLeader_35:
# 358 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceUp
	goto VerdantPlateau_EventScript_TeamLeader_32

VerdantPlateau_EventScript_TeamLeader_36:
# 359 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceLeft
	goto VerdantPlateau_EventScript_TeamLeader_32

VerdantPlateau_EventScript_TeamLeader_37:
# 360 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_WalkInPlaceRight
	goto VerdantPlateau_EventScript_TeamLeader_32

VerdantPlateau_EventScript_TeamLeader_39:
# 364 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
	goto VerdantPlateau_EventScript_TeamLeader_38

VerdantPlateau_EventScript_TeamLeader_43:
# 371 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_EventScript_TeamLeader_Text_5, MSGBOX_DEFAULT
	goto VerdantPlateau_EventScript_TeamLeader_42

VerdantPlateau_EventScript_TeamLeader_48:
# 378 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
	goto VerdantPlateau_EventScript_TeamLeader_46

VerdantPlateau_EventScript_TeamLeader_49:
# 379 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
	goto VerdantPlateau_EventScript_TeamLeader_46

VerdantPlateau_EventScript_TeamLeader_50:
# 380 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
	goto VerdantPlateau_EventScript_TeamLeader_46

VerdantPlateau_EventScript_TeamLeader_51:
# 381 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
	goto VerdantPlateau_EventScript_TeamLeader_46


# 389 "data//maps/VerdantPlateau/scripts.pory"

# 390 "data//maps/VerdantPlateau/scripts.pory"

# 391 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 392 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 393 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 394 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 395 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 396 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 397 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 398 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 399 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 400 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 401 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 402 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 403 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 404 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 405 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 406 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 407 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 408 "data//maps/VerdantPlateau/scripts.pory"

# 409 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 410 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 411 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 412 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 413 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 414 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 415 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 416 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 417 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 418 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 419 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 420 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 421 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 422 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 423 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 424 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 425 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 426 "data//maps/VerdantPlateau/scripts.pory"

# 427 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 428 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 429 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 430 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 431 "data//maps/VerdantPlateau/scripts.pory"

# 432 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 433 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 434 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 435 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 436 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 437 "data//maps/VerdantPlateau/scripts.pory"

# 438 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 439 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 440 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 441 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 442 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 443 "data//maps/VerdantPlateau/scripts.pory"

# 444 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 445 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 446 "data//maps/VerdantPlateau/scripts.pory"

# 447 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 448 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 449 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 450 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 451 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 452 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 453 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 454 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 455 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 456 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 457 "data//maps/VerdantPlateau/scripts.pory"

# 458 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 459 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
# 460 "data//maps/VerdantPlateau/scripts.pory"

# 461 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Archie:
# 462 "data//maps/VerdantPlateau/scripts.pory"
	.string "Talk to me again when I have my scripts\n"
# 463 "data//maps/VerdantPlateau/scripts.pory"
	.string "written!$"

VerdantPlateau_EventScript_TeamLeader_Text_0:
# 278 "data//maps/VerdantPlateau/scripts.pory"
	.string "Oh?\p"
	.string "Look at that…{PAUSE 20}\n"
	.string "another trainer all the way up here!$"

VerdantPlateau_EventScript_TeamLeader_Text_1:
# 288 "data//maps/VerdantPlateau/scripts.pory"
	.string "Gaze out on the vast expanse of\n"
	.string "wilderness that is central HOENN…\p"
	.string "Observe the great MT. CHIMNEY that\n"
	.string "created it looming over the horizon…\p"
	.string "It's certainly impressive, but it's also\n"
	.string "frightening.$"

VerdantPlateau_EventScript_TeamLeader_Text_2:
# 298 "data//maps/VerdantPlateau/scripts.pory"
	.string "It's right to be frightened.\p"
	.string "The fire in that mountain paved the way\n"
	.string "for human life…\p"
	.string "Lives that we've used to build our own\n"
	.string "monuments of fire;\p"
	.string "our wasteful technologies that ooze\n"
	.string "over the earth like lava in our quest\l"
	.string "for expansion…$"

VerdantPlateau_EventScript_TeamLeader_Text_3:
# 311 "data//maps/VerdantPlateau/scripts.pory"
	.string "But imagine…{PAUSE 20}{PAUSE 20}{PAUSE 20}\n"
	.string "Imagine if it could all be washed away.\p"
	.string "Imagine the vast sea\n"
	.string "of possibility…{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20} …{PAUSE 20}$"

VerdantPlateau_EventScript_TeamLeader_Text_4:
# 349 "data//maps/VerdantPlateau/scripts.pory"
	.string "Ah shoot,\n"
	.string "but I got lost in my thoughts!\p"
	.string "I need to get going.\n"
	.string "Thanks for listening to my rambling, kid.\p"
	.string "You can have this as a parting gift.$"

VerdantPlateau_EventScript_TeamLeader_Text_5:
# 371 "data//maps/VerdantPlateau/scripts.pory"
	.string "Maybe I'll see you around again out\n"
	.string "there!\p"
	.string "But look alive, kid;\n"
	.string "things are about to get interesting!$"
