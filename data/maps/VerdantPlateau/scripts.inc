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
	faceplayer
# 22 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie, MSGBOX_DEFAULT
# 23 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 24 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 25 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 26 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 27 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie2, MSGBOX_DEFAULT 
# 28 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 29 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 30 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie3, MSGBOX_DEFAULT
# 31 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 32 "data//maps/VerdantPlateau/scripts.pory"
	delay 30
# 33 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 34 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 35 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie4, MSGBOX_DEFAULT
# 36 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 37 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 38 "data//maps/VerdantPlateau/scripts.pory"
	switch VAR_FACING
# 39 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_WEST, VerdantPlateau_EventScript_MaxieLeavesWest
# 40 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_NORTH, VerdantPlateau_EventScript_MaxieLeavesWest
# 41 "data//maps/VerdantPlateau/scripts.pory"
	case DIR_EAST, VerdantPlateau_EventScript_MaxieLeavesWest
# 42 "data//maps/VerdantPlateau/scripts.pory"
	release
# 43 "data//maps/VerdantPlateau/scripts.pory"
	end
# 44 "data//maps/VerdantPlateau/scripts.pory"

# 45 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesWest::
# 46 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 47 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 48 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 49 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 50 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 51 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 52 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 53 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 54 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 55 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 56 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 57 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 58 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 59 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 60 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 61 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 62 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 63 "data//maps/VerdantPlateau/scripts.pory"
	return
# 64 "data//maps/VerdantPlateau/scripts.pory"

# 65 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesEast::
# 66 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 67 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 68 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 69 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 70 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 71 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 72 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 73 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 74 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 75 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 76 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 77 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 78 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 79 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNormal
# 80 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 81 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 82 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 83 "data//maps/VerdantPlateau/scripts.pory"
	return
# 84 "data//maps/VerdantPlateau/scripts.pory"

# 85 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_EventScript_MaxieLeavesNorth::
# 86 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceUp
# 87 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 88 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 89 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceLeft
# 90 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 91 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 92 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, Common_Movement_FaceRight
# 93 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 94 "data//maps/VerdantPlateau/scripts.pory"
	delay 60
# 95 "data//maps/VerdantPlateau/scripts.pory"
	faceplayer
# 96 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 97 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie5, MSGBOX_DEFAULT
# 98 "data//maps/VerdantPlateau/scripts.pory"
	giveitem ITEM_SUN_STONE, 1
# 99 "data//maps/VerdantPlateau/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 100 "data//maps/VerdantPlateau/scripts.pory"
	msgbox VerdantPlateau_Text_Maxie6, MSGBOX_DEFAULT
# 101 "data//maps/VerdantPlateau/scripts.pory"
	closemessage
# 102 "data//maps/VerdantPlateau/scripts.pory"
	applymovement LOCALID_TEAMLEADER, VerdantPlateau_Movement_LeaderLeavesNorth
# 103 "data//maps/VerdantPlateau/scripts.pory"
	waitmovement LOCALID_TEAMLEADER
# 104 "data//maps/VerdantPlateau/scripts.pory"
	removeobject LOCALID_TEAMLEADER
# 105 "data//maps/VerdantPlateau/scripts.pory"
	@ setflag FLAG_HIDE_PLATEAU_LEADER
# 106 "data//maps/VerdantPlateau/scripts.pory"
	return
# 107 "data//maps/VerdantPlateau/scripts.pory"

# 108 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNormal:
# 109 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 110 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 111 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 112 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 113 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 114 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 115 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 116 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 117 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 118 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 119 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 120 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 121 "data//maps/VerdantPlateau/scripts.pory"
	delay_8
# 122 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 123 "data//maps/VerdantPlateau/scripts.pory"

# 124 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Movement_LeaderLeavesNorth:
# 125 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 126 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 127 "data//maps/VerdantPlateau/scripts.pory"
	walk_left
# 128 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 129 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
# 130 "data//maps/VerdantPlateau/scripts.pory"
	walk_down
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
	delay_8
# 138 "data//maps/VerdantPlateau/scripts.pory"
	step_end
# 139 "data//maps/VerdantPlateau/scripts.pory"

# 140 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie:
# 141 "data//maps/VerdantPlateau/scripts.pory"
	.string "Hm?\p"
# 142 "data//maps/VerdantPlateau/scripts.pory"
	.string "My apologies, it's unusual to run into\n"
# 143 "data//maps/VerdantPlateau/scripts.pory"
	.string "another trainer up here.$"
# 144 "data//maps/VerdantPlateau/scripts.pory"

# 145 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie2:
# 146 "data//maps/VerdantPlateau/scripts.pory"
	.string "From up here there is such a clear view\n"
# 147 "data//maps/VerdantPlateau/scripts.pory"
	.string "of the land extending all around us…\p"
# 148 "data//maps/VerdantPlateau/scripts.pory"
	.string "And the way the sunlight seems to burn\n"
# 149 "data//maps/VerdantPlateau/scripts.pory"
	.string "so bright…$" 
# 150 "data//maps/VerdantPlateau/scripts.pory"

# 151 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie3:
# 152 "data//maps/VerdantPlateau/scripts.pory"
	.string "Can you imagine an entire region as\n"
# 153 "data//maps/VerdantPlateau/scripts.pory"
	.string "beautiful as this plateau?\p"
# 154 "data//maps/VerdantPlateau/scripts.pory"
	.string "What if the whole world could be this\n"
# 155 "data//maps/VerdantPlateau/scripts.pory"
	.string "brilliant?$"
# 156 "data//maps/VerdantPlateau/scripts.pory"

# 157 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie4:
# 158 "data//maps/VerdantPlateau/scripts.pory"
	.string "That's the type of world I want to see.$"
# 159 "data//maps/VerdantPlateau/scripts.pory"

# 160 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie5:
# 161 "data//maps/VerdantPlateau/scripts.pory"
	.string "And to that end, I must depart.\p"
# 162 "data//maps/VerdantPlateau/scripts.pory"
	.string "What was your name?\p"
# 163 "data//maps/VerdantPlateau/scripts.pory"
	.string "{PLAYER} is it?\p"
# 164 "data//maps/VerdantPlateau/scripts.pory"
	.string "Well {PLAYER}, maybe we'll cross paths again\n"
# 165 "data//maps/VerdantPlateau/scripts.pory"
	.string "someday.\p"
# 166 "data//maps/VerdantPlateau/scripts.pory"
	.string "I wonder if we'll be living in a new world\n"
# 167 "data//maps/VerdantPlateau/scripts.pory"
	.string "when that time comes…\p"
# 168 "data//maps/VerdantPlateau/scripts.pory"
	.string "Thank you for listening, {PLAYER}.\n"
# 169 "data//maps/VerdantPlateau/scripts.pory"
	.string "Take this as a parting gift.$"
# 170 "data//maps/VerdantPlateau/scripts.pory"

# 171 "data//maps/VerdantPlateau/scripts.pory"
VerdantPlateau_Text_Maxie6:
# 172 "data//maps/VerdantPlateau/scripts.pory"
	.string "Goodbye for now…$"
