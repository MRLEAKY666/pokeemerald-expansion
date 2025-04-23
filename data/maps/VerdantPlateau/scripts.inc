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
	end
# 13 "data//maps/VerdantPlateau/scripts.pory"

# 14 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_SetSun::
# 15 "data//maps/VerdantPlateau/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 16 "data//maps/VerdantPlateau/scripts.pory"
	doweather
# 17 "data//maps/VerdantPlateau/scripts.pory"
	return
# 18 "data//maps/VerdantPlateau/scripts.pory"

# 19 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_Maxie::
# 20 "data//maps/VerdantPlateau/scripts.pory"
	lock
# 21 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_ExclamationMark
# 22 "data//maps/VerdantPlateau/scripts.pory"
	playse SE_PIN
# 23 "data//maps/VerdantPlateau/scripts.pory"
	waitse
# 24 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 25 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 26 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 27 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 28 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 29 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 30 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 31 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 32 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 33 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 34 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 35 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 36 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 37 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 38 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 39 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 40 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 41 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 42 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 43 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesNorth
# 44 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesEast
# 45 "data//maps/VerdantPlateau/scripts.pory"
	release
# 46 "data//maps/VerdantPlateau/scripts.pory"
	end
# 47 "data//maps/VerdantPlateau/scripts.pory"

# 48 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 49 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 50 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 51 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 52 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 53 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 54 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 55 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 56 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 57 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 58 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 59 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 60 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 61 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 62 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 63 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 64 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 65 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 66 "data//maps/VerdantPlateau/scripts.pory"
	return
# 67 "data//maps/VerdantPlateau/scripts.pory"

# 68 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 69 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 70 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 71 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 72 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 73 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 74 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 75 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 76 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 77 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 78 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 79 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 80 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 81 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 82 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 83 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 84 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 85 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 86 "data//maps/VerdantPlateau/scripts.pory"
	return
# 87 "data//maps/VerdantPlateau/scripts.pory"

# 88 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 89 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 90 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 91 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 92 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 93 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 94 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 95 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 96 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 97 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 98 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 99 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 100 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 101 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 102 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 103 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 104 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 105 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 106 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 107 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 108 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 109 "data//maps/VerdantPlateau/scripts.pory"
	return
# 110 "data//maps/VerdantPlateau/scripts.pory"

# 111 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 112 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 113 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 114 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 115 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 116 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 117 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 118 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 119 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 120 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 121 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 122 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 123 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 124 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 125 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 126 "data//maps/VerdantPlateau/scripts.pory"

# 127 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 128 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 129 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 130 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 131 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 132 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 133 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 134 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 135 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 136 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 137 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 138 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 139 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 140 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 141 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 142 "data//maps/VerdantPlateau/scripts.pory"

# 143 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 144 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 145 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 146 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 147 "data//maps/VerdantPlateau/scripts.pory"

# 148 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 149 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 150 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 151 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 152 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 153 "data//maps/VerdantPlateau/scripts.pory"

# 154 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 155 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 156 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 157 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 158 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 159 "data//maps/VerdantPlateau/scripts.pory"

# 160 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 161 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 162 "data//maps/VerdantPlateau/scripts.pory"

# 163 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 164 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 165 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 166 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 167 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 168 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 169 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 170 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 171 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 172 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 173 "data//maps/VerdantPlateau/scripts.pory"

# 174 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 175 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
