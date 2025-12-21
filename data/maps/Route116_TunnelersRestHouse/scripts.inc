# 1 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 2 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_MapScripts::
# 3 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
# 4 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.byte 0

Route116_TunnelersRestHouse_OnTransition::
# 12 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
# 13 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED, Route116_TunnelersRestHouse_OnTransition_2
	return

Route116_TunnelersRestHouse_OnTransition_1:
# 14 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_TEMP_5
# 15 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_TEMP_6
# 16 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_TEMP_7
	return

Route116_TunnelersRestHouse_OnTransition_2:
# 13 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_le Route116_TunnelersRestHouse_OnTransition_1
	return


Route116_TunnelersRestHouse_EventScript_Tunneler1::
# 21 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	lock
# 22 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	faceplayer
# 23 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 18
	goto_if_ge Route116_TunnelersRestHouse_EventScript_Tunneler1_17
Route116_TunnelersRestHouse_EventScript_Tunneler1_13:
# 118 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ge Route116_TunnelersRestHouse_EventScript_Tunneler1_12
Route116_TunnelersRestHouse_EventScript_Tunneler1_8:
# 127 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_gt Route116_TunnelersRestHouse_EventScript_Tunneler1_7
Route116_TunnelersRestHouse_EventScript_Tunneler1_5:
# 134 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_DEFAULT
Route116_TunnelersRestHouse_EventScript_Tunneler1_1:
# 136 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	release
	return

Route116_TunnelersRestHouse_EventScript_Tunneler1_2:
# 26 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_0, MSGBOX_DEFAULT
# 28 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 29 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 20
# 30 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	message Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_1
# 31 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmessage
# 32 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 20
# 33 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 34 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 40
# 35 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_2, MSGBOX_DEFAULT
# 37 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 38 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	getobjectfacingdirection LOCALID_TUNNELER1, VAR_RESULT
# 39 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	switch VAR_RESULT
# 40 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_SOUTH, Route116_TunnelersRestHouse_EventScript_Tunneler1_23
# 42 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_NORTH, Route116_TunnelersRestHouse_EventScript_Tunneler1_24
# 44 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_WEST, Route116_TunnelersRestHouse_EventScript_Tunneler1_25
Route116_TunnelersRestHouse_EventScript_Tunneler1_21:
# 47 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement
# 48 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER2, Common_Movement_WalkInPlaceDown
# 49 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER3, Common_Movement_WalkInPlaceRight
# 50 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_FacePlayer
# 51 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 30
# 52 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_3, MSGBOX_DEFAULT
# 55 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 56 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 30
# 57 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	switch VAR_RESULT
# 58 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_SOUTH, Route116_TunnelersRestHouse_EventScript_Tunneler1_28
# 76 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_NORTH, Route116_TunnelersRestHouse_EventScript_Tunneler1_29
# 94 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	case DIR_WEST, Route116_TunnelersRestHouse_EventScript_Tunneler1_30
Route116_TunnelersRestHouse_EventScript_Tunneler1_26:
# 113 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	removeobject LOCALID_TUNNELER1, MAP_ROUTE116_TUNNELERS_REST_HOUSE
# 114 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	removeobject LOCALID_TUNNELER2, MAP_ROUTE116_TUNNELERS_REST_HOUSE
# 115 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	removeobject LOCALID_TUNNELER3, MAP_ROUTE116_TUNNELERS_REST_HOUSE
# 116 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	setflag FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_1

Route116_TunnelersRestHouse_EventScript_Tunneler1_3:
# 121 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_5, MSGBOX_DEFAULT
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_1

Route116_TunnelersRestHouse_EventScript_Tunneler1_4:
# 130 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_6, MSGBOX_DEFAULT
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_1

Route116_TunnelersRestHouse_EventScript_Tunneler1_6:
# 129 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED, Route116_TunnelersRestHouse_EventScript_Tunneler1_4
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_5

Route116_TunnelersRestHouse_EventScript_Tunneler1_7:
# 128 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_Tunneler1_6
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_5

Route116_TunnelersRestHouse_EventScript_Tunneler1_11:
# 120 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED, Route116_TunnelersRestHouse_EventScript_Tunneler1_3
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_8

Route116_TunnelersRestHouse_EventScript_Tunneler1_12:
# 119 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_Tunneler1_11
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_8

Route116_TunnelersRestHouse_EventScript_Tunneler1_16:
# 25 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_Tunneler1_2
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_13

Route116_TunnelersRestHouse_EventScript_Tunneler1_17:
# 24 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt Route116_TunnelersRestHouse_EventScript_Tunneler1_16
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_13

Route116_TunnelersRestHouse_EventScript_Tunneler1_23:
# 41 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1LookAround
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_21

Route116_TunnelersRestHouse_EventScript_Tunneler1_24:
# 43 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1LookAround
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_21

Route116_TunnelersRestHouse_EventScript_Tunneler1_25:
# 45 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1LookAround3
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_21

Route116_TunnelersRestHouse_EventScript_Tunneler1_28:
# 59 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceUp
# 60 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement
# 61 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_4, MSGBOX_DEFAULT
# 62 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 63 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceLeft
# 64 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 30
# 65 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	hidefollower
# 66 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1Leave1
# 67 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER2, Route116_TunnelersRestHouse_Movement_Tunneler2Leave
# 68 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER3, Route116_TunnelersRestHouse_Movement_Tunneler3Leave
# 69 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 40
# 70 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 71 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 20
# 72 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 73 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 60
# 74 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 75 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement LOCALID_TUNNELER2
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_26

Route116_TunnelersRestHouse_EventScript_Tunneler1_29:
# 77 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceLeft
# 78 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement
# 79 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_4, MSGBOX_DEFAULT
# 80 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 81 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceDown
# 82 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 30
# 83 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	hidefollower
# 84 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1Leave2
# 85 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER2, Route116_TunnelersRestHouse_Movement_Tunneler2Leave
# 86 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER3, Route116_TunnelersRestHouse_Movement_Tunneler3Leave
# 87 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 40
# 88 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 89 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 20
# 90 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 91 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 60
# 92 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 93 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement LOCALID_TUNNELER2
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_26

Route116_TunnelersRestHouse_EventScript_Tunneler1_30:
# 95 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceUp
# 96 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement
# 97 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_4, MSGBOX_DEFAULT
# 98 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	closemessage
# 99 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Common_Movement_WalkInPlaceLeft
# 100 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 30
# 101 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	hidefollower
# 102 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER1, Route116_TunnelersRestHouse_Movement_Tunneler1Leave2
# 103 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER2, Route116_TunnelersRestHouse_Movement_Tunneler2Leave2
# 104 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	applymovement LOCALID_TUNNELER3, Route116_TunnelersRestHouse_Movement_Tunneler3Leave
# 105 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 40
# 106 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 107 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 20
# 108 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 109 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay 80
# 110 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	playse SE_EXIT
# 111 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	waitmovement LOCALID_TUNNELER2
	goto Route116_TunnelersRestHouse_EventScript_Tunneler1_26


# 139 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 140 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 141 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler1Leave1:
# 142 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 143 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 144 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 145 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 146 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	set_invisible
# 147 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 148 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 149 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler1Leave2:
# 150 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 151 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 152 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 153 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 154 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	set_invisible
# 155 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 156 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 157 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler2Leave:
# 158 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 159 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 160 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 161 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 162 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 163 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 164 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 165 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 166 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	set_invisible
# 167 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 168 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 169 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler2Leave2:
# 170 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 171 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 172 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_left
# 173 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 174 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 175 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 176 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 177 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 178 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 179 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	set_invisible
# 180 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 181 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 182 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler3Leave:
# 183 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_right
# 184 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 185 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_down
# 186 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	set_invisible
# 187 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 188 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 189 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler1LookAround:
# 190 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_up
# 191 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay_16
# 192 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_left
# 193 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay_16
# 194 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_up
# 195 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end
# 196 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 197 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Movement_Tunneler1LookAround3:
# 198 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_up
# 199 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay_16
# 200 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_down
# 201 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	delay_16
# 202 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	walk_in_place_left
# 203 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	step_end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
# 208 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	lock
# 209 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	faceplayer
# 210 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_DEFAULT
# 211 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	release
	return


Route116_TunnelersRestHouse_EventScript_Tunneler3::
# 215 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	lock
# 216 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	faceplayer
# 217 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_Tunneler3_8
Route116_TunnelersRestHouse_EventScript_Tunneler3_6:
# 220 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_Tunneler3_5
Route116_TunnelersRestHouse_EventScript_Tunneler3_4:
# 235 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
Route116_TunnelersRestHouse_EventScript_Tunneler3_1:
# 237 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	release
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3_2:
# 218 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	goto Route116_TunnelersRestHouse_EventScript_Tunneler3_1

Route116_TunnelersRestHouse_EventScript_Tunneler3_3:
# 221 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	goto_if_set FLAG_LAVARBOR_RUSTURF_CREW_RECRUITED, Route116_TunnelersRestHouse_EventScript_Tunneler3_11
# 226 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler3_Text_1, MSGBOX_DEFAULT
	goto Route116_TunnelersRestHouse_EventScript_Tunneler3_1

Route116_TunnelersRestHouse_EventScript_Tunneler3_5:
# 220 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ge Route116_TunnelersRestHouse_EventScript_Tunneler3_3
	goto Route116_TunnelersRestHouse_EventScript_Tunneler3_4

Route116_TunnelersRestHouse_EventScript_Tunneler3_8:
# 217 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt Route116_TunnelersRestHouse_EventScript_Tunneler3_2
	goto Route116_TunnelersRestHouse_EventScript_Tunneler3_6

Route116_TunnelersRestHouse_EventScript_Tunneler3_11:
# 222 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_EventScript_Tunneler3_Text_0, MSGBOX_DEFAULT
	goto Route116_TunnelersRestHouse_EventScript_Tunneler3_1


# 241 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 242 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 243 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_EventScript_TunnelOpened::
# 244 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
# 245 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	release
# 246 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	end
# 247 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 248 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
# 249 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "That RUSTURF TUNNEL there…\p"
# 250 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "At first, we had a huge work crew boring\n"
# 251 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "through rock with the latest machinery.\l"
# 252 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "But, we had to stop.\p"
# 253 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "It turns out that we would have had\n"
# 254 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "a negative effect on wild POKéMON in\l"
# 255 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "the area.\p"
# 256 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "So, we've got nothing to do but loll\n"
# 257 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "around here doing nothing.$"
# 258 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 259 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
# 260 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "There's a man digging his way to\n"
# 261 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "VERDANTURF all by his lonesome.\l"
# 262 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "He's desperate to get through.\p"
# 263 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "He says that if he digs little by little\n"
# 264 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "without using machines, he won't\l"
# 265 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "disturb POKéMON, and he'll avoid\l"
# 266 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "harming the natural environment.\p"
# 267 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "I wonder if he made it through yet.$"
# 268 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 269 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
# 270 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "To get to VERDANTURF without using\n"
# 271 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "this TUNNEL, you'd have to cross the\l"
# 272 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "sea to DEWFORD, sail on to SLATEPORT,\l"
# 273 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "then travel through MAUVILLE.$"
# 274 "data//maps/Route116_TunnelersRestHouse/scripts.pory"

# 275 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
# 276 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Did you hear? The TUNNEL to VERDANTURF\n"
# 277 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "has gone through!\p"
# 278 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Sometimes, if you hope strongly enough,\n"
# 279 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "dreams do come true.$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_0:
# 26 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "I heard the LAVARBOR TUNNEL\n"
	.string "construction has resumed!\p"
	.string "Our region is becoming more and more\n"
	.string "interconnected everyday.$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_1:
# 30 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_2:
# 35 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "You're working on the LAVARBOR TUNNEL?\p"
	.string "And you say the tunnel master is\n"
	.string "looking for more help?$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_3:
# 52 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "I think all the guys are up for another\n"
	.string "project!\p"
	.string "Living the tunneler's lifestyle, we're\n"
	.string "always looking for the next job.\p"
	.string "It's important to stay on the move, and\n"
	.string "keep busy!$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_4:
# 61 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Come on boys! Let's hit the next dig\n"
	.string "site!$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_5:
# 121 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "I heard that the TUNNEL MANIAC finally\n"
	.string "completed LAVAROR TUNNEL…\p"
	.string "He succeeded where we couldn't!\p"
	.string "I think he gets around regulations by\n"
	.string "using POKéMON to dig his tunnels…\p"
	.string "POKéMON dig tunnels in the wild,\n"
	.string "so building artificial tunnels that way\l"
	.string "is friendlier for the environment.\p"
	.string "Plus, POKéMON are cheaper to employ!$"

Route116_TunnelersRestHouse_EventScript_Tunneler1_Text_6:
# 130 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "We're back from working on the\n"
	.string "newly-dug LAVARBOR TUNNEL.\p"
	.string "It was strenuous work!\n"
	.string "But through the collective effort of\l"
	.string "TUNNEL MANIAC's crew and ourselves, we\l"
	.string "successfully connected the towns of\l"
	.string "LAVARIDGE and FALLARBOR!$"

Route116_TunnelersRestHouse_EventScript_Tunneler3_Text_0:
# 222 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "We are so proud to have been able to\n"
	.string "contribute to both the RUSTURF TUNNEL\l"
	.string "and the LAVARBOR TUNNEL!\p"
	.string "Sometimes, if you hope strongly enough,\n"
	.string "dreams do come true.$"

Route116_TunnelersRestHouse_EventScript_Tunneler3_Text_1:
# 226 "data//maps/Route116_TunnelersRestHouse/scripts.pory"
	.string "Did you hear? The TUNNEL to VERDANTURF\n"
	.string "has gone through!\p"
	.string "And the tunnel from LAVARIDGE\n"
	.string "to FALLARBOR too!\p"
	.string "Sometimes, if you hope strongly enough,\n"
	.string "dreams do come true.$"
