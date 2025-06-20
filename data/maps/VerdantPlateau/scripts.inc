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
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 69 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 70 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 71 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 72 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 73 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 74 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_SetSun
# 75 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 76 "data//maps/VerdantPlateau/scripts.pory"
	end
# 77 "data//maps/VerdantPlateau/scripts.pory"

# 78 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SwitchToNighttime::
# 79 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 80 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 81 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 82 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 83 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 84 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 85 "data//maps/VerdantPlateau/scripts.pory"
	call VerdantPlateau_EventScript_ClearSun
# 86 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 87 "data//maps/VerdantPlateau/scripts.pory"
	end
# 88 "data//maps/VerdantPlateau/scripts.pory"

# 89 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_TeamLeader::
# 90 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_PLATEAU_LEADER_EVENT
# 91 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE, VerdantPlateau_EventScript_Maxie
# 92 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE, VerdantPlateau_EventScript_Archie
# 93 "data//maps/VerdantPlateau/scripts.pory"
	end
# 94 "data//maps/VerdantPlateau/scripts.pory"

# 95 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Maxie::
# 96 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 97 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 98 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 99 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 100 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 101 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 102 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 103 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 104 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 105 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 106 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 107 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 108 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 109 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 110 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 111 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 112 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 113 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 114 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 115 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 116 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 117 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 118 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 119 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesNorth
# 120 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesEast
# 121 "data//maps/VerdantPlateau/scripts.pory"
	release
# 122 "data//maps/VerdantPlateau/scripts.pory"
	end
# 123 "data//maps/VerdantPlateau/scripts.pory"

# 124 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 125 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 126 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 127 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 128 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 129 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 130 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 131 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 132 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 133 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 134 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 135 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 136 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 137 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 138 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 139 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 140 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 141 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 142 "data//maps/VerdantPlateau/scripts.pory"
	return
# 143 "data//maps/VerdantPlateau/scripts.pory"

# 144 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 145 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 146 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 147 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 148 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 149 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 150 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 151 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 152 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 153 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 154 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 155 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 156 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 157 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 158 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 159 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 160 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 161 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 162 "data//maps/VerdantPlateau/scripts.pory"
	return
# 163 "data//maps/VerdantPlateau/scripts.pory"

# 164 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 165 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 166 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 167 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 168 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 169 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 170 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 171 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 172 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 173 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 174 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 175 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 176 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 177 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 178 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 179 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 180 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 181 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 182 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 183 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 184 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 185 "data//maps/VerdantPlateau/scripts.pory"
	return
# 186 "data//maps/VerdantPlateau/scripts.pory"

# 187 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Archie::
# 188 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 189 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 190 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Archie, MSGBOX_DEFAULT
# 191 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 192 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 193 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_ArchieLeavesWest
# 194 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_ArchieLeavesNorth
# 195 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_ArchieLeavesEast
# 196 "data//maps/VerdantPlateau/scripts.pory"
	release
# 197 "data//maps/VerdantPlateau/scripts.pory"
	end
# 198 "data//maps/VerdantPlateau/scripts.pory"

# 199 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesWest::
# 200 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 201 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 202 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 203 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 204 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 205 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 206 "data//maps/VerdantPlateau/scripts.pory"
	return
# 207 "data//maps/VerdantPlateau/scripts.pory"

# 208 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesEast::
# 209 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 210 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 211 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 212 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 213 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 214 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 215 "data//maps/VerdantPlateau/scripts.pory"
	return
# 216 "data//maps/VerdantPlateau/scripts.pory"

# 217 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesNorth::
# 218 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 219 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 220 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 221 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 222 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 223 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 224 "data//maps/VerdantPlateau/scripts.pory"
	return
# 225 "data//maps/VerdantPlateau/scripts.pory"

# 226 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 227 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 228 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 229 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 230 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 231 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 232 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 233 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 234 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 235 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 236 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 237 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 238 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 239 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 240 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 241 "data//maps/VerdantPlateau/scripts.pory"

# 242 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 243 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 244 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 245 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 246 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 247 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 248 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 249 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 250 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 251 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 252 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 253 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 254 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 255 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 256 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 257 "data//maps/VerdantPlateau/scripts.pory"

# 258 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 259 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 260 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 261 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 262 "data//maps/VerdantPlateau/scripts.pory"

# 263 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 264 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 265 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 266 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 267 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 268 "data//maps/VerdantPlateau/scripts.pory"

# 269 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 270 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 271 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 272 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 273 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 274 "data//maps/VerdantPlateau/scripts.pory"

# 275 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 276 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 277 "data//maps/VerdantPlateau/scripts.pory"

# 278 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 279 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 280 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 281 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 282 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 283 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 284 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 285 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 286 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 287 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 288 "data//maps/VerdantPlateau/scripts.pory"

# 289 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 290 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
# 291 "data//maps/VerdantPlateau/scripts.pory"

# 292 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Archie:
# 293 "data//maps/VerdantPlateau/scripts.pory"
	.string "Talk to me again when I have my scripts\n"
# 294 "data//maps/VerdantPlateau/scripts.pory"
	.string "written!$"
