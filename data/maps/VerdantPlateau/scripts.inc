# 1 "data//maps/VerdantPlateau/scripts.pory"

# 2 "data//maps/VerdantPlateau/scripts.pory"
.set LOCALID_TEAMLEADER, 1
# 3 "data//maps/VerdantPlateau/scripts.pory"

# 4 "data//maps/VerdantPlateau/scripts.pory"

# 5 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_MapScripts::
# 6 "data//maps/VerdantPlateau/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantPlateau_OnTransition
# 7 "data//maps/VerdantPlateau/scripts.pory"
	.byte 0
# 8 "data//maps/VerdantPlateau/scripts.pory"

# 9 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_OnTransition:
# 10 "data//maps/VerdantPlateau/scripts.pory"
	callnative Script_GetTimeOfDay
# 11 "data//maps/VerdantPlateau/scripts.pory"
	call_if_le VAR_TIME_OF_DAY, 1, VerdantPlateau_EventScript_SetSun
# 12 "data//maps/VerdantPlateau/scripts.pory"
	call_if_unset FLAG_HIDE_PLATEAU_LEADER, VerdantPlateau_EventScript_SetupTeamLeaderGfxId
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
	goto_if_le VAR_TIME_OF_DAY, 1, VerdantPlateau_EventScript_ShowMaxie
# 22 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_ge VAR_TIME_OF_DAY, 2, VerdantPlateau_EventScript_ShowArchie
# 23 "data//maps/VerdantPlateau/scripts.pory"
	return
# 24 "data//maps/VerdantPlateau/scripts.pory"

# 25 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowMaxie::
# 26 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE
# 27 "data//maps/VerdantPlateau/scripts.pory"
	return
# 28 "data//maps/VerdantPlateau/scripts.pory"

# 29 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ShowArchie::
# 30 "data//maps/VerdantPlateau/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE
# 31 "data//maps/VerdantPlateau/scripts.pory"
	return
# 32 "data//maps/VerdantPlateau/scripts.pory"

# 33 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_TeamLeader::
# 34 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAXIE, VerdantPlateau_EventScript_Maxie
# 35 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARCHIE, VerdantPlateau_EventScript_Archie
# 36 "data//maps/VerdantPlateau/scripts.pory"
	end
# 37 "data//maps/VerdantPlateau/scripts.pory"

# 38 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Maxie::
# 39 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 40 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 41 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 42 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 43 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 44 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 45 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 46 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 47 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 48 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 49 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 50 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 51 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 52 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 53 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 54 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 55 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 56 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 57 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 58 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 59 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 60 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 61 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 62 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesNorth
# 63 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesEast
# 64 "data//maps/VerdantPlateau/scripts.pory"
	release
# 65 "data//maps/VerdantPlateau/scripts.pory"
	end
# 66 "data//maps/VerdantPlateau/scripts.pory"

# 67 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 68 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 69 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 70 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 71 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 72 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 73 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 74 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 75 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 76 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 77 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 78 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 79 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 80 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 81 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 82 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 83 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 84 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 85 "data//maps/VerdantPlateau/scripts.pory"
	return
# 86 "data//maps/VerdantPlateau/scripts.pory"

# 87 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 88 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 89 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 90 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 91 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 92 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 93 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 94 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 95 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 96 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 97 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 98 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 99 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 100 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 101 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 102 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 103 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 104 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 105 "data//maps/VerdantPlateau/scripts.pory"
	return
# 106 "data//maps/VerdantPlateau/scripts.pory"

# 107 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 108 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 109 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 110 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 111 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 112 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 113 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 114 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 115 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 116 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 117 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 118 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 119 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 120 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 121 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 122 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 123 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 124 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 125 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 126 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 127 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 128 "data//maps/VerdantPlateau/scripts.pory"
	return
# 129 "data//maps/VerdantPlateau/scripts.pory"

# 130 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Archie::
# 131 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 132 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 133 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Archie, MSGBOX_DEFAULT
# 134 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 135 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 136 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_ArchieLeavesWest
# 137 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_ArchieLeavesNorth
# 138 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_ArchieLeavesEast
# 139 "data//maps/VerdantPlateau/scripts.pory"
	release
# 140 "data//maps/VerdantPlateau/scripts.pory"
	end
# 141 "data//maps/VerdantPlateau/scripts.pory"

# 142 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesWest::
# 143 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 144 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 145 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 146 "data//maps/VerdantPlateau/scripts.pory"
	return
# 147 "data//maps/VerdantPlateau/scripts.pory"

# 148 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesEast::
# 149 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 150 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 151 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 152 "data//maps/VerdantPlateau/scripts.pory"
	return
# 153 "data//maps/VerdantPlateau/scripts.pory"

# 154 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_ArchieLeavesNorth::
# 155 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 156 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 157 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 158 "data//maps/VerdantPlateau/scripts.pory"
	return
# 159 "data//maps/VerdantPlateau/scripts.pory"

# 160 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 161 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 162 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 163 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 164 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 165 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 166 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 167 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 168 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 169 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 170 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 171 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 172 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 173 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 174 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 175 "data//maps/VerdantPlateau/scripts.pory"

# 176 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 177 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 178 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 179 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 180 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 181 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 182 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 183 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 184 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 185 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 186 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 187 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 188 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 189 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 190 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 191 "data//maps/VerdantPlateau/scripts.pory"

# 192 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 193 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 194 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 195 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 196 "data//maps/VerdantPlateau/scripts.pory"

# 197 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 198 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 199 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 200 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 201 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 202 "data//maps/VerdantPlateau/scripts.pory"

# 203 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 204 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 205 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 206 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 207 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 208 "data//maps/VerdantPlateau/scripts.pory"

# 209 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 210 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 211 "data//maps/VerdantPlateau/scripts.pory"

# 212 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 213 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 214 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 215 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 216 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 217 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 218 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 219 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 220 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 221 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 222 "data//maps/VerdantPlateau/scripts.pory"

# 223 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 224 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
# 225 "data//maps/VerdantPlateau/scripts.pory"

# 226 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Archie:
# 227 "data//maps/VerdantPlateau/scripts.pory"
	.string "Talk to me again when I have my scripts\n"
# 228 "data//maps/VerdantPlateau/scripts.pory"
	.string "written!$"
