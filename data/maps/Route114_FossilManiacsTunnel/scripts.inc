# 1 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 2 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_MapScripts::
# 3 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
# 4 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
# 5 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.byte 0
# 6 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 7 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnTransition:
# 8 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
# 9 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	call Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac
# 10 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 11 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 12 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
# 13 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
# 14 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
# 15 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 16 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 17 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_OnLoad:
# 18 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
# 19 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 20 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 21 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
# 22 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
# 23 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
# 24 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	return
# 25 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 26 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
# 27 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	lockall
# 28 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
# 29 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 30 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement 0
# 31 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
# 32 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setvar VAR_FOSSIL_MANIAC_STATE, 2 @ already mentioned cave in 
# 33 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	releaseall
# 34 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 35 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 36 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_FossilManiac::
# 37 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	lock
# 38 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	faceplayer
# 39 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	call_if_set FLAG_OPENED_SIDEROOM_1, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac
# 40 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
# 41 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 42 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 43 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 44 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
# 45 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
# 46 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 47 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac::
# 54 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FALLARBOR_OPENED, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_2
# 57 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	message Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_0
# 58 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmessage
# 59 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 20
# 60 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	closemessage
# 61 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 60
# 62 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_1, MSGBOX_DEFAULT
# 64 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	message Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_2
# 65 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmessage
# 66 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 5
# 67 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	closemessage
# 68 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_ExclamationMark
# 69 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	playse SE_PIN
# 70 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitse
# 71 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_3, MSGBOX_DEFAULT
# 75 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	closemessage
# 76 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 20
# 77 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_FaceAwayPlayer
# 78 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement
# 79 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 60
# 80 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_FacePlayer
# 81 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement
# 82 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 15
# 83 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_ExclamationMark
# 84 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	playse SE_PIN
# 85 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitse
# 86 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_4, MSGBOX_DEFAULT
# 89 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	closemessage
# 90 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 45
# 91 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_5, MSGBOX_DEFAULT
# 92 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	closemessage
# 93 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	delay 20
# 94 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setflag FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED
# 95 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setflag FLAG_TEMP_5
# 96 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	getobjectxy LOCALID_FOSSIL_MANIAC, CURRENT_POSITION, VAR_TEMP_E, VAR_TEMP_F
# 97 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	getobjectfacingdirection LOCALID_FOSSIL_MANIAC, VAR_RESULT
# 98 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	compare VAR_TEMP_E, 6
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_5
# 109 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	switch VAR_RESULT
# 110 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	case DIR_EAST, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_13
# 112 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	case DIR_SOUTH, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_14
Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4:
# 116 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	waitmovement
# 117 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	removeobject LOCALID_FOSSIL_MANIAC
# 118 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setvar VAR_FOSSIL_MANIAC_STATE, 2
# 119 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
	end

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_2:
	return

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_5:
# 99 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	switch VAR_RESULT
# 100 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	case DIR_SOUTH, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_9
# 102 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	case DIR_NORTH, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_10
# 104 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	case DIR_WEST, Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_11
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_9:
# 101 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesSouth
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_10:
# 103 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesNorthWest
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_11:
# 105 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesNorthWest
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_13:
# 111 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesEast
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_14:
# 113 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	applymovement LOCALID_FOSSIL_MANIAC, Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesSouth2
	goto Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_4


Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac::
# 124 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_8
Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_6:
# 127 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FALLARBOR_OPENED, Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_5
Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_4:
# 130 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_3
	return

Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_1:
# 125 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setflag FLAG_TEMP_5
	return

Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_2:
# 128 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setflag FLAG_TEMP_5
	return

Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_3:
# 131 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	setflag FLAG_TEMP_5
	return

Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_5:
# 127 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_2
	goto Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_4

Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_8:
# 124 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_1
	goto Route114_FossilManiacsTunnel_EventScript_TryHideFossilManiac_6


# 135 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 136 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 137 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesNorthWest:
# 138 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 139 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 140 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 141 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 142 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 143 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 144 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 145 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 146 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	step_end
# 147 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 148 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesSouth:
# 149 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_left
# 150 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 151 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 152 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 153 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 154 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_right
# 155 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 156 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 157 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 158 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 159 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	step_end
# 160 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 161 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesEast:
# 162 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 163 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 164 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 165 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 166 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_right
# 167 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 168 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 169 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 170 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 171 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	step_end
# 172 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 173 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Movement_FossilManiacLeavesSouth2:
# 174 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_right
# 175 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 176 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 177 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 178 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 179 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 180 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 181 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 182 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	walk_down
# 183 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	step_end
# 184 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 185 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
# 186 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
# 187 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 188 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 189 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 190 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
# 191 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
# 192 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	release
# 193 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	end
# 194 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 195 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
# 196 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm the FOSSIL MANIAC…\n"
# 197 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I'm a nice guy who loves FOSSILS…\p"
# 198 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Do you want a FOSSIL?\p"
# 199 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But the FOSSILS around these parts all\n"
# 200 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "belong to me… None for you…\p"
# 201 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "If you can't bear to go without\n"
# 202 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "a FOSSIL, look in a desert where there\l"
# 203 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "are boulders and sand that may hide\l"
# 204 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…$"
# 205 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 206 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
# 207 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "You found a FOSSIL, didn't you?\n"
# 208 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "That's so nice… It's so dreamy…\p"
# 209 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "What are you going to do with that\n"
# 210 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSIL?\p"
# 211 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "From what I've heard, DEVON is doing\n"
# 212 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "research on reviving POKéMON from\l"
# 213 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS…\p"
# 214 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I love my FOSSILS, so I would never\n"
# 215 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "do anything like that…$"
# 216 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 217 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
# 218 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSILS are so… Wonderful…\n"
# 219 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's so dreamy…$"
# 220 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"

# 221 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
# 222 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "Oh…\n"
# 223 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "It's not safe that way…\p"
# 224 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I was digging away, you see…\n"
# 225 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "When the whole wall collapsed…\p"
# 226 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I think there's a giant cavern\n"
# 227 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "underneath now…\p"
# 228 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "But I've left it alone because I don't\n"
# 229 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "think there are any FOSSILS there…$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_0:
# 57 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_1:
# 62 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "FOSSIL MANIAC: That smell…\l"
	.string "I know that delicious fragrance…\p"
	.string "You've been digging around some\n"
	.string "exquisitely rare fossils, haven't you?$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_2:
# 64 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "… {PAUSE 20}… {PAUSE 20}… {PAUSE 20}… {PAUSE 10}… {PAUSE 10}… {PAUSE 10}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_3:
# 71 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "You said a guy called TUNNEL MANIAC is\n"
	.string "tunneling from LAVARIDGE to\l"
	.string "FALLARBOR?\p"
	.string "TUNNEL MANIAC is my old man!\p"
	.string "I can't believe you got him to leave the\n"
	.string "sauna!\p"
	.string "I've gotta see what kinds of fresh\n"
	.string "fossils they're digging up down there!$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_4:
# 86 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "I know!\p"
	.string "I'll start digging on the FALLARBOR side\n"
	.string "until I meet Dad's crew!\p"
	.string "Then I can finally earn his respect by\n"
	.string "contributing to his dig,\l"
	.string "but I'll also get to see those fossils!$"

Route114_FossilManiacsTunnel_EventScript_RecruitFossilManiac_Text_5:
# 91 "data//maps/Route114_FossilManiacsTunnel/scripts.pory"
	.string "No time to waste!$"
