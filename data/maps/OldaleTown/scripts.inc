# 1 "data//maps/OldaleTown/scripts.pory"

# 2 "data//maps/OldaleTown/scripts.pory"
OldaleTown_MapScripts::
# 3 "data//maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 4 "data//maps/OldaleTown/scripts.pory"
	.byte 0
# 5 "data//maps/OldaleTown/scripts.pory"

# 6 "data//maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition:
# 7 "data//maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 8 "data//maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 9 "data//maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 10 "data//maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 11 "data//maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 12 "data//maps/OldaleTown/scripts.pory"
	end
# 13 "data//maps/OldaleTown/scripts.pory"

# 14 "data//maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 15 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState::
# 16 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 17 "data//maps/OldaleTown/scripts.pory"
	return
# 18 "data//maps/OldaleTown/scripts.pory"

# 19 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance::
# 20 "data//maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 21 "data//maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 22 "data//maps/OldaleTown/scripts.pory"
	return
# 23 "data//maps/OldaleTown/scripts.pory"

# 24 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee::
# 25 "data//maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_OLDALE_MART_EMPLOYEE, 13, 14
# 26 "data//maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_OLDALE_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 27 "data//maps/OldaleTown/scripts.pory"
	return
# 28 "data//maps/OldaleTown/scripts.pory"

# 29 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_TownSign::
# 30 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
# 31 "data//maps/OldaleTown/scripts.pory"
	end
# 32 "data//maps/OldaleTown/scripts.pory"

# 33 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl::
# 34 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 35 "data//maps/OldaleTown/scripts.pory"
	end
# 36 "data//maps/OldaleTown/scripts.pory"

# 37 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee::
# 38 "data//maps/OldaleTown/scripts.pory"
	lock
# 39 "data//maps/OldaleTown/scripts.pory"
	faceplayer
# 40 "data//maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 41 "data//maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 42 "data//maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 43 "data//maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 44 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 45 "data//maps/OldaleTown/scripts.pory"
	closemessage
# 46 "data//maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 47 "data//maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 48 "data//maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 49 "data//maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 50 "data//maps/OldaleTown/scripts.pory"
	end
# 51 "data//maps/OldaleTown/scripts.pory"

# 52 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth::
# 53 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 54 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerSouth
# 55 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 56 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 57 "data//maps/OldaleTown/scripts.pory"
	end
# 58 "data//maps/OldaleTown/scripts.pory"

# 59 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth::
# 60 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 61 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerNorth
# 62 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 63 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 64 "data//maps/OldaleTown/scripts.pory"
	end
# 65 "data//maps/OldaleTown/scripts.pory"

# 66 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast::
# 67 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerEast
# 68 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 69 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 70 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 71 "data//maps/OldaleTown/scripts.pory"
	end
# 72 "data//maps/OldaleTown/scripts.pory"

# 73 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart::
# 74 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 75 "data//maps/OldaleTown/scripts.pory"
	giveitem ITEM_POTION
# 76 "data//maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
# 77 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 78 "data//maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 79 "data//maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 80 "data//maps/OldaleTown/scripts.pory"
	release
# 81 "data//maps/OldaleTown/scripts.pory"
	end
# 82 "data//maps/OldaleTown/scripts.pory"

# 83 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion::
# 84 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 85 "data//maps/OldaleTown/scripts.pory"
	release
# 86 "data//maps/OldaleTown/scripts.pory"
	end
# 87 "data//maps/OldaleTown/scripts.pory"

# 88 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull::
# 89 "data//maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 90 "data//maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 91 "data//maps/OldaleTown/scripts.pory"
	release
# 92 "data//maps/OldaleTown/scripts.pory"
	end
# 93 "data//maps/OldaleTown/scripts.pory"

# 94 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast:
# 95 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 96 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 97 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 98 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 99 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 100 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 101 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 102 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 103 "data//maps/OldaleTown/scripts.pory"
	step_end
# 104 "data//maps/OldaleTown/scripts.pory"

# 105 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth:
# 106 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 107 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 108 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 109 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 110 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 111 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 112 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 113 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 114 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 116 "data//maps/OldaleTown/scripts.pory"
	step_end
# 117 "data//maps/OldaleTown/scripts.pory"

# 118 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth:
# 119 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 120 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 121 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 122 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 123 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 124 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 125 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 126 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 127 "data//maps/OldaleTown/scripts.pory"
	step_end
# 128 "data//maps/OldaleTown/scripts.pory"

# 129 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1:
# 130 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 131 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 132 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 133 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 134 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 135 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 136 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 137 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 138 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 139 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 140 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 141 "data//maps/OldaleTown/scripts.pory"
	delay_8
# 142 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 143 "data//maps/OldaleTown/scripts.pory"
	step_end
# 144 "data//maps/OldaleTown/scripts.pory"

# 145 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast:
# 146 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 147 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 148 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 149 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 150 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 151 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 152 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 153 "data//maps/OldaleTown/scripts.pory"
	step_end
# 154 "data//maps/OldaleTown/scripts.pory"

# 155 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth:
# 156 "data//maps/OldaleTown/scripts.pory"
	delay_16
# 157 "data//maps/OldaleTown/scripts.pory"
	delay_16
# 158 "data//maps/OldaleTown/scripts.pory"
	delay_16
# 159 "data//maps/OldaleTown/scripts.pory"
	delay_16
# 160 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 161 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 162 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 163 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 164 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 165 "data//maps/OldaleTown/scripts.pory"
	step_end
# 166 "data//maps/OldaleTown/scripts.pory"

# 167 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth:
# 168 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 169 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 170 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 171 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 172 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 173 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 175 "data//maps/OldaleTown/scripts.pory"
	step_end
# 176 "data//maps/OldaleTown/scripts.pory"

# 177 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2:
# 178 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 179 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 180 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 181 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 182 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 183 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 184 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 185 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 186 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 187 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 188 "data//maps/OldaleTown/scripts.pory"
	walk_up
# 189 "data//maps/OldaleTown/scripts.pory"
	step_end
# 190 "data//maps/OldaleTown/scripts.pory"

# 191 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan::
# 192 "data//maps/OldaleTown/scripts.pory"
	lock
# 193 "data//maps/OldaleTown/scripts.pory"
	faceplayer
# 194 "data//maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_HO_OH, OldaleTown_EventScript_NotBlockingPath2
# 195 "data//maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_BEAST_SPECIES, SPECIES_NONE, OldaleTown_EventScript_NotBlockingPath2
# 196 "data//maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 197 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 198 "data//maps/OldaleTown/scripts.pory"
	closemessage
# 199 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 200 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 201 "data//maps/OldaleTown/scripts.pory"
	release
# 202 "data//maps/OldaleTown/scripts.pory"
	end
# 203 "data//maps/OldaleTown/scripts.pory"

# 204 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath::
# 205 "data//maps/OldaleTown/scripts.pory"
	lockall
# 206 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 207 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 208 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 209 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 210 "data//maps/OldaleTown/scripts.pory"
	closemessage
# 211 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 212 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 213 "data//maps/OldaleTown/scripts.pory"
	releaseall
# 214 "data//maps/OldaleTown/scripts.pory"
	end
# 215 "data//maps/OldaleTown/scripts.pory"

# 216 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath::
# 217 "data//maps/OldaleTown/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_BEAST_SPECIES
# 218 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 219 "data//maps/OldaleTown/scripts.pory"
	release
# 220 "data//maps/OldaleTown/scripts.pory"
	end
# 221 "data//maps/OldaleTown/scripts.pory"

# 222 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath2::
# 223 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints2, MSGBOX_DEFAULT
# 224 "data//maps/OldaleTown/scripts.pory"
	release
# 225 "data//maps/OldaleTown/scripts.pory"
	end
# 226 "data//maps/OldaleTown/scripts.pory"

# 227 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival::
# 228 "data//maps/OldaleTown/scripts.pory"
	lockall
# 229 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, Common_Movement_FacePlayer
# 230 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 231 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 232 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 233 "data//maps/OldaleTown/scripts.pory"
	end
# 234 "data//maps/OldaleTown/scripts.pory"

# 235 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1::
# 236 "data//maps/OldaleTown/scripts.pory"
	lockall
# 237 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 238 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 239 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 240 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 241 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 242 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 243 "data//maps/OldaleTown/scripts.pory"
	end
# 244 "data//maps/OldaleTown/scripts.pory"

# 245 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2::
# 246 "data//maps/OldaleTown/scripts.pory"
	lockall
# 247 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 248 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 249 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 250 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 251 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 252 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 253 "data//maps/OldaleTown/scripts.pory"
	end
# 254 "data//maps/OldaleTown/scripts.pory"

# 255 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3::
# 256 "data//maps/OldaleTown/scripts.pory"
	lockall
# 257 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 258 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 259 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 260 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 261 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 262 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 263 "data//maps/OldaleTown/scripts.pory"
	end
# 264 "data//maps/OldaleTown/scripts.pory"

# 265 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage::
# 266 "data//maps/OldaleTown/scripts.pory"
	checkplayergender
# 267 "data//maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
# 268 "data//maps/OldaleTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
# 269 "data//maps/OldaleTown/scripts.pory"
	end
# 270 "data//maps/OldaleTown/scripts.pory"

# 271 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage::
# 272 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 273 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 274 "data//maps/OldaleTown/scripts.pory"
	end
# 275 "data//maps/OldaleTown/scripts.pory"

# 276 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage::
# 277 "data//maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 278 "data//maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 279 "data//maps/OldaleTown/scripts.pory"
	end
# 280 "data//maps/OldaleTown/scripts.pory"

# 281 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish::
# 282 "data//maps/OldaleTown/scripts.pory"
	closemessage
# 283 "data//maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
# 284 "data//maps/OldaleTown/scripts.pory"
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
# 285 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 286 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 287 "data//maps/OldaleTown/scripts.pory"
	removeobject LOCALID_OLDALE_RIVAL
# 288 "data//maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 289 "data//maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 290 "data//maps/OldaleTown/scripts.pory"
	releaseall
# 291 "data//maps/OldaleTown/scripts.pory"
	end
# 292 "data//maps/OldaleTown/scripts.pory"

# 293 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1::
# 294 "data//maps/OldaleTown/scripts.pory"
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
# 295 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 296 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 297 "data//maps/OldaleTown/scripts.pory"
	return
# 298 "data//maps/OldaleTown/scripts.pory"

# 299 "data//maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2::
# 300 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 301 "data//maps/OldaleTown/scripts.pory"
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
# 302 "data//maps/OldaleTown/scripts.pory"
	waitmovement 0
# 303 "data//maps/OldaleTown/scripts.pory"
	return
# 304 "data//maps/OldaleTown/scripts.pory"

# 305 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1:
# 306 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 307 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 308 "data//maps/OldaleTown/scripts.pory"
	step_end
# 309 "data//maps/OldaleTown/scripts.pory"

# 310 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2:
# 311 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 312 "data//maps/OldaleTown/scripts.pory"
	step_end
# 313 "data//maps/OldaleTown/scripts.pory"

# 314 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3:
# 315 "data//maps/OldaleTown/scripts.pory"
	face_left
# 316 "data//maps/OldaleTown/scripts.pory"
	step_end
# 317 "data//maps/OldaleTown/scripts.pory"

# 318 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit:
# 319 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 320 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 321 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 322 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 323 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 324 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 325 "data//maps/OldaleTown/scripts.pory"
	step_end
# 326 "data//maps/OldaleTown/scripts.pory"

# 327 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit:
# 328 "data//maps/OldaleTown/scripts.pory"
	delay_8
# 329 "data//maps/OldaleTown/scripts.pory"
	delay_4
# 330 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_down
# 331 "data//maps/OldaleTown/scripts.pory"
	step_end
# 332 "data//maps/OldaleTown/scripts.pory"

# 333 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack:
# 334 "data//maps/OldaleTown/scripts.pory"
	delay_8
# 335 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 336 "data//maps/OldaleTown/scripts.pory"
	step_end
# 337 "data//maps/OldaleTown/scripts.pory"

# 338 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp:
# 339 "data//maps/OldaleTown/scripts.pory"
	walk_fast_up
# 340 "data//maps/OldaleTown/scripts.pory"
	walk_in_place_faster_left
# 341 "data//maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 342 "data//maps/OldaleTown/scripts.pory"
	walk_right
# 343 "data//maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 344 "data//maps/OldaleTown/scripts.pory"
	step_end
# 345 "data//maps/OldaleTown/scripts.pory"

# 346 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition:
# 347 "data//maps/OldaleTown/scripts.pory"
	walk_down
# 348 "data//maps/OldaleTown/scripts.pory"
	walk_left
# 349 "data//maps/OldaleTown/scripts.pory"
	step_end
# 350 "data//maps/OldaleTown/scripts.pory"

# 351 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress:
# 352 "data//maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 353 "data//maps/OldaleTown/scripts.pory"
	.string "progress.\p"
# 354 "data//maps/OldaleTown/scripts.pory"
	.string "If you're leaving town, you should\n"
# 355 "data//maps/OldaleTown/scripts.pory"
	.string "save your progress too.$"
# 356 "data//maps/OldaleTown/scripts.pory"

# 357 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart:
# 358 "data//maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 359 "data//maps/OldaleTown/scripts.pory"
	.string "I work at a POKéMON MART.\p"
# 360 "data//maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 361 "data//maps/OldaleTown/scripts.pory"

# 362 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 363 "data//maps/OldaleTown/scripts.pory"
	.string "This is a POKéMON MART.\n"
# 364 "data//maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 365 "data//maps/OldaleTown/scripts.pory"
	.string "We sell a variety of goods including\n"
# 366 "data//maps/OldaleTown/scripts.pory"
	.string "POKé BALLS for catching POKéMON.\p"
# 367 "data//maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 368 "data//maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 369 "data//maps/OldaleTown/scripts.pory"

# 370 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation:
# 371 "data//maps/OldaleTown/scripts.pory"
	.string "A POTION can be used anytime, so it's\n"
# 372 "data//maps/OldaleTown/scripts.pory"
	.string "even more useful than a POKéMON CENTER\l"
# 373 "data//maps/OldaleTown/scripts.pory"
	.string "in certain situations.$"
# 374 "data//maps/OldaleTown/scripts.pory"

# 375 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere:
# 376 "data//maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 377 "data//maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 378 "data//maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 379 "data//maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 380 "data//maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 381 "data//maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 382 "data//maps/OldaleTown/scripts.pory"

# 383 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints:
# 384 "data//maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 385 "data//maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON!\p"
# 386 "data//maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 387 "data//maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 388 "data//maps/OldaleTown/scripts.pory"

# 389 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints:
# 390 "data//maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 391 "data//maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 392 "data//maps/OldaleTown/scripts.pory"
	.string "It turns out they belonged to the\n"
# 393 "data//maps/OldaleTown/scripts.pory"
	.string "POKéMON {STR_VAR_2}!$"
# 394 "data//maps/OldaleTown/scripts.pory"

# 395 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints2:
# 396 "data//maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 397 "data//maps/OldaleTown/scripts.pory"
	.string "a rare POKéMON.\p"
# 398 "data//maps/OldaleTown/scripts.pory"
	.string "Lot of rare POKéMON have been roaming\n"
# 399 "data//maps/OldaleTown/scripts.pory"
	.string "around HOENN lately!$"
# 400 "data//maps/OldaleTown/scripts.pory"

# 401 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack:
# 402 "data//maps/OldaleTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\n"
# 403 "data//maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 404 "data//maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 405 "data//maps/OldaleTown/scripts.pory"

# 406 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack:
# 407 "data//maps/OldaleTown/scripts.pory"
	.string "BRENDAN: I'm heading back to my dad's\n"
# 408 "data//maps/OldaleTown/scripts.pory"
	.string "LAB now.\l"
# 409 "data//maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 410 "data//maps/OldaleTown/scripts.pory"

# 411 "data//maps/OldaleTown/scripts.pory"
OldaleTown_Text_TownSign:
# 412 "data//maps/OldaleTown/scripts.pory"
	.string "OLDALE TOWN\n"
# 413 "data//maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"
