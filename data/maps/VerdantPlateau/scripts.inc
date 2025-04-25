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
	call_if_le VAR_TIME_OF_DAY, 3, VerdantPlateau_EventScript_SetSun
# 12 "data//maps/VerdantPlateau/scripts.pory"
	call_if_unset FLAG_PLATEAU_LEADER_EVENT, VerdantPlateau_EventScript_SetupTeamLeaderGfxId
# 13 "data//maps/VerdantPlateau/scripts.pory"
	end
# 14 "data//maps/VerdantPlateau/scripts.pory"

# 15 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetSun::
# 16 "data//maps/VerdantPlateau/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 17 "data//maps/VerdantPlateau/scripts.pory"
	doweather
# 18 "data//maps/VerdantPlateau/scripts.pory"
	return
# 19 "data//maps/VerdantPlateau/scripts.pory"

# 20 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetupTeamLeaderGfxId::
# 21 "data//maps/VerdantPlateau/scripts.pory"
	call_if_set FLAG_HIDE_PLATEAU_LEADER, VerdantPlateau_EventScript_ShowPlateauLeader
# 22 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_le VAR_TIME_OF_DAY, 3, VerdantPlateau_EventScript_ShowMaxie
# 23 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_ge VAR_TIME_OF_DAY, 4, VerdantPlateau_EventScript_ShowArchie
# 24 "data//maps/VerdantPlateau/scripts.pory"
	return
# 25 "data//maps/VerdantPlateau/scripts.pory"

# 26 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowPlateauLeader::
# 27 "data//maps/VerdantPlateau/scripts.pory"
	clearflag FLAG_HIDE_PLATEAU_LEADER
# 28 "data//maps/VerdantPlateau/scripts.pory"
	return
# 29 "data//maps/VerdantPlateau/scripts.pory"

# 30 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowMaxie::
# 31 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE
# 32 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 0, VerdantPlateau_EventScript_IncrementTimeOfDay
# 33 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_IncrementTimeOfDay
# 34 "data//maps/VerdantPlateau/scripts.pory"
	return
# 35 "data//maps/VerdantPlateau/scripts.pory"

# 36 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowArchie::
# 37 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
# 38 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 4, VerdantPlateau_EventScript_IncrementTimeOfDay
# 39 "data//maps/VerdantPlateau/scripts.pory"
	call_if_eq VAR_TIME_OF_DAY, 6, VerdantPlateau_EventScript_IncrementTimeOfDay
# 40 "data//maps/VerdantPlateau/scripts.pory"
	return
# 41 "data//maps/VerdantPlateau/scripts.pory"

# 42 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_IncrementTimeOfDay::
# 43 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 44 "data//maps/VerdantPlateau/scripts.pory"
	return
# 45 "data//maps/VerdantPlateau/scripts.pory"

# 46 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_OnFrame:
# 47 "data//maps/VerdantPlateau/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 0, VerdantPlateau_EventScript_SwitchToDaytime
# 48 "data//maps/VerdantPlateau/scripts.pory"
	map_script_2 VAR_TIME_OF_DAY, 4, VerdantPlateau_EventScript_SwitchToNighttime
# 49 "data//maps/VerdantPlateau/scripts.pory"
	.2byte 0
# 50 "data//maps/VerdantPlateau/scripts.pory"

# 51 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SwitchToDaytime::
# 52 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 53 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 54 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 55 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 56 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 57 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 58 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 59 "data//maps/VerdantPlateau/scripts.pory"
	end
# 60 "data//maps/VerdantPlateau/scripts.pory"

# 61 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SwitchToNighttime::
# 62 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 63 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 64 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 65 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 66 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_HIDE_PLATEAU_LEADER
# 67 "data//maps/VerdantPlateau/scripts.pory"
	addvar VAR_TIME_OF_DAY, 1
# 68 "data//maps/VerdantPlateau/scripts.pory"
	@ clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 69 "data//maps/VerdantPlateau/scripts.pory"
	end
# 70 "data//maps/VerdantPlateau/scripts.pory"

# 71 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_TeamLeader::
# 72 "data//maps/VerdantPlateau/scripts.pory"
	setflag FLAG_PLATEAU_LEADER_EVENT
# 73 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE, VerdantPlateau_EventScript_Maxie
# 74 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE, VerdantPlateau_EventScript_Archie
# 75 "data//maps/VerdantPlateau/scripts.pory"
	end
# 76 "data//maps/VerdantPlateau/scripts.pory"

# 77 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Maxie::
# 78 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 79 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 80 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 81 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 82 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 83 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 84 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 85 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 86 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 87 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 88 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 89 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 90 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 91 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 92 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 93 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 94 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 95 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 96 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 97 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 98 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 99 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 100 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 101 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesNorth
# 102 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesEast
# 103 "data//maps/VerdantPlateau/scripts.pory"
	release
# 104 "data//maps/VerdantPlateau/scripts.pory"
	end
# 105 "data//maps/VerdantPlateau/scripts.pory"

# 106 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 107 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 108 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 109 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 110 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 111 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 112 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 113 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 114 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 115 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 116 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 117 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 118 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 119 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 120 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 121 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 122 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 123 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 124 "data//maps/VerdantPlateau/scripts.pory"
	return
# 125 "data//maps/VerdantPlateau/scripts.pory"

# 126 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 127 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 128 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 129 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 130 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 131 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 132 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 133 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 134 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 135 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 136 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 137 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 138 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 139 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 140 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 141 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 142 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 143 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 144 "data//maps/VerdantPlateau/scripts.pory"
	return
# 145 "data//maps/VerdantPlateau/scripts.pory"

# 146 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 147 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 148 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 149 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 150 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 151 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 152 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 153 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 154 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 155 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 156 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 157 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 158 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 159 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 160 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 161 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 162 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 163 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 164 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 165 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 166 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 167 "data//maps/VerdantPlateau/scripts.pory"
	return
# 168 "data//maps/VerdantPlateau/scripts.pory"

# 169 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Archie::
# 170 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 171 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 172 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Archie, MSGBOX_DEFAULT
# 173 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 174 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 175 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_ArchieLeavesWest
# 176 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_ArchieLeavesNorth
# 177 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_ArchieLeavesEast
# 178 "data//maps/VerdantPlateau/scripts.pory"
	release
# 179 "data//maps/VerdantPlateau/scripts.pory"
	end
# 180 "data//maps/VerdantPlateau/scripts.pory"

# 181 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesWest::
# 182 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 183 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 184 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 185 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 186 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 187 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 188 "data//maps/VerdantPlateau/scripts.pory"
	return
# 189 "data//maps/VerdantPlateau/scripts.pory"

# 190 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesEast::
# 191 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 192 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 193 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 194 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 195 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 196 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 197 "data//maps/VerdantPlateau/scripts.pory"
	return
# 198 "data//maps/VerdantPlateau/scripts.pory"

# 199 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesNorth::
# 200 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_MOON_STONE, 1
# 201 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 202 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 203 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 204 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 205 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 206 "data//maps/VerdantPlateau/scripts.pory"
	return
# 207 "data//maps/VerdantPlateau/scripts.pory"

# 208 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 209 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 210 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 211 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 212 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 213 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 214 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 215 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 216 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 217 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 218 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 219 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 220 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 221 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 222 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 223 "data//maps/VerdantPlateau/scripts.pory"

# 224 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 225 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 226 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 227 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 228 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 229 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 230 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 231 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 232 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 233 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 234 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 235 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 236 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 237 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 238 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 239 "data//maps/VerdantPlateau/scripts.pory"

# 240 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 241 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 242 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 243 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 244 "data//maps/VerdantPlateau/scripts.pory"

# 245 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 246 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 247 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 248 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 249 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 250 "data//maps/VerdantPlateau/scripts.pory"

# 251 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 252 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 253 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 254 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 255 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 256 "data//maps/VerdantPlateau/scripts.pory"

# 257 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 258 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 259 "data//maps/VerdantPlateau/scripts.pory"

# 260 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 261 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 262 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 263 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 264 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 265 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 266 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 267 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 268 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 269 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 270 "data//maps/VerdantPlateau/scripts.pory"

# 271 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 272 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
# 273 "data//maps/VerdantPlateau/scripts.pory"

# 274 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Archie:
# 275 "data//maps/VerdantPlateau/scripts.pory"
	.string "Talk to me again when I have my scripts\n"
# 276 "data//maps/VerdantPlateau/scripts.pory"
	.string "written!$"
