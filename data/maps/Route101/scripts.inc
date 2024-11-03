# 1 "data//maps/Route101/scripts.pory"

# 2 "data//maps/Route101/scripts.pory"
.set LOCALID_BIRCH, 2
# 3 "data//maps/Route101/scripts.pory"
.set LOCALID_ZIGZAGOON, 4
# 4 "data//maps/Route101/scripts.pory"

# 5 "data//maps/Route101/scripts.pory"
Route101_MapScripts::
# 6 "data//maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 7 "data//maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 8 "data//maps/Route101/scripts.pory"
	.byte 0
# 9 "data//maps/Route101/scripts.pory"

# 10 "data//maps/Route101/scripts.pory"
Route101_OnTransition:
# 11 "data//maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data//maps/Route101/scripts.pory"
	end
# 13 "data//maps/Route101/scripts.pory"

# 14 "data//maps/Route101/scripts.pory"
Route101_OnFrame:
# 15 "data//maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 16 "data//maps/Route101/scripts.pory"
	.2byte 0
# 17 "data//maps/Route101/scripts.pory"

# 18 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 19 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 20 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 21 "data//maps/Route101/scripts.pory"
	end
# 22 "data//maps/Route101/scripts.pory"

# 23 "data//maps/Route101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 24 "data//maps/Route101/scripts.pory"
	lockall
# 25 "data//maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 26 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 27 "data//maps/Route101/scripts.pory"
	closemessage
# 28 "data//maps/Route101/scripts.pory"
	setobjectxy LOCALID_BIRCH, 0, 15
# 29 "data//maps/Route101/scripts.pory"
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
# 30 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
# 31 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
# 32 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 33 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 34 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 35 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
# 36 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 37 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 38 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 39 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 40 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 41 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 42 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 43 "data//maps/Route101/scripts.pory"
	closemessage
# 44 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 45 "data//maps/Route101/scripts.pory"
	releaseall
# 46 "data//maps/Route101/scripts.pory"
	end
# 47 "data//maps/Route101/scripts.pory"

# 48 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 49 "data//maps/Route101/scripts.pory"
	lockall
# 50 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 51 "data//maps/Route101/scripts.pory"
	closemessage
# 52 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
# 53 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 54 "data//maps/Route101/scripts.pory"
	releaseall
# 55 "data//maps/Route101/scripts.pory"
	end
# 56 "data//maps/Route101/scripts.pory"

# 57 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 58 "data//maps/Route101/scripts.pory"
	lockall
# 59 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 60 "data//maps/Route101/scripts.pory"
	closemessage
# 61 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
# 62 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 63 "data//maps/Route101/scripts.pory"
	releaseall
# 64 "data//maps/Route101/scripts.pory"
	end
# 65 "data//maps/Route101/scripts.pory"

# 66 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitEast::
# 67 "data//maps/Route101/scripts.pory"
	lockall
# 68 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 69 "data//maps/Route101/scripts.pory"
	closemessage
# 70 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitEast
# 71 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 72 "data//maps/Route101/scripts.pory"
	releaseall
# 73 "data//maps/Route101/scripts.pory"
	end
# 74 "data//maps/Route101/scripts.pory"

# 75 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 76 "data//maps/Route101/scripts.pory"
	lockall
# 77 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 78 "data//maps/Route101/scripts.pory"
	closemessage
# 79 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
# 80 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 81 "data//maps/Route101/scripts.pory"
	releaseall
# 82 "data//maps/Route101/scripts.pory"
	end
# 83 "data//maps/Route101/scripts.pory"

# 84 "data//maps/Route101/scripts.pory"
Route101_EventScript_PleadingBirch::
# 85 "data//maps/Route101/scripts.pory"
	lockall
# 86 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 87 "data//maps/Route101/scripts.pory"
	closemessage
# 88 "data//maps/Route101/scripts.pory"
	releaseall
# 89 "data//maps/Route101/scripts.pory"
	end
# 90 "data//maps/Route101/scripts.pory"

# 91 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 92 "data//maps/Route101/scripts.pory"
	walk_up
# 93 "data//maps/Route101/scripts.pory"
	step_end
# 94 "data//maps/Route101/scripts.pory"

# 95 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 96 "data//maps/Route101/scripts.pory"
	walk_right
# 97 "data//maps/Route101/scripts.pory"
	step_end
# 98 "data//maps/Route101/scripts.pory"

# 99 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitEast:
# 100 "data//maps/Route101/scripts.pory"
	walk_left
# 101 "data//maps/Route101/scripts.pory"
	step_end
# 102 "data//maps/Route101/scripts.pory"

# 103 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 104 "data//maps/Route101/scripts.pory"
	walk_down
# 105 "data//maps/Route101/scripts.pory"
	step_end
# 106 "data//maps/Route101/scripts.pory"

# 107 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 108 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 109 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 110 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 111 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 112 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 113 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 114 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 115 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 116 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 117 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 118 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 119 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 120 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 121 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 122 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 123 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 124 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 125 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 126 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 127 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 128 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 129 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 130 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 131 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 132 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 133 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 134 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 135 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 136 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 137 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 138 "data//maps/Route101/scripts.pory"
	step_end
# 139 "data//maps/Route101/scripts.pory"

# 140 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 141 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 142 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 143 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 144 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 145 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 146 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 147 "data//maps/Route101/scripts.pory"
	step_end
# 148 "data//maps/Route101/scripts.pory"

# 149 "data//maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 150 "data//maps/Route101/scripts.pory"
	step_end
# 151 "data//maps/Route101/scripts.pory"

# 152 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 153 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 154 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 155 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 156 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 157 "data//maps/Route101/scripts.pory"
	step_end
# 158 "data//maps/Route101/scripts.pory"

# 159 "data//maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 160 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 161 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 162 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 163 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 164 "data//maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 165 "data//maps/Route101/scripts.pory"
	step_end
# 166 "data//maps/Route101/scripts.pory"

# 167 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 168 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 169 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 170 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 171 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 172 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 173 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 174 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 175 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 176 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 177 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 178 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 179 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 180 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 181 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 182 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 183 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 184 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 185 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 186 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 187 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 188 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 189 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 190 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 191 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 192 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 193 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 194 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 195 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 196 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 197 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 198 "data//maps/Route101/scripts.pory"
	step_end
# 199 "data//maps/Route101/scripts.pory"

# 200 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 201 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 202 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 203 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 204 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 205 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 206 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 207 "data//maps/Route101/scripts.pory"
	step_end
# 208 "data//maps/Route101/scripts.pory"

# 209 "data//maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 210 "data//maps/Route101/scripts.pory"
	step_end
# 211 "data//maps/Route101/scripts.pory"

# 212 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 213 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 214 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 215 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 216 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 217 "data//maps/Route101/scripts.pory"
	step_end
# 218 "data//maps/Route101/scripts.pory"

# 219 "data//maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 220 "data//maps/Route101/scripts.pory"
	walk_up
# 221 "data//maps/Route101/scripts.pory"
	walk_up
# 222 "data//maps/Route101/scripts.pory"
	step_end
# 223 "data//maps/Route101/scripts.pory"

# 224 "data//maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 225 "data//maps/Route101/scripts.pory"
	walk_up
# 226 "data//maps/Route101/scripts.pory"
	walk_left
# 227 "data//maps/Route101/scripts.pory"
	walk_up
# 228 "data//maps/Route101/scripts.pory"
	step_end
# 229 "data//maps/Route101/scripts.pory"

# 230 "data//maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 231 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 232 "data//maps/Route101/scripts.pory"
	end
# 233 "data//maps/Route101/scripts.pory"

# 234 "data//maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 235 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 236 "data//maps/Route101/scripts.pory"
	end
# 237 "data//maps/Route101/scripts.pory"

# 238 "data//maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 239 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 240 "data//maps/Route101/scripts.pory"
	end
# 241 "data//maps/Route101/scripts.pory"

# 242 "data//maps/Route101/scripts.pory"
Route101_EventScript_BirchsBag::
# 243 "data//maps/Route101/scripts.pory"
	lock
# 244 "data//maps/Route101/scripts.pory"
	faceplayer
# 245 "data//maps/Route101/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 246 "data//maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 247 "data//maps/Route101/scripts.pory"
	removeobject LOCALID_ZIGZAGOON
# 248 "data//maps/Route101/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
# 249 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 250 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 251 "data//maps/Route101/scripts.pory"
	special ChooseStarter
# 252 "data//maps/Route101/scripts.pory"
	waitstate
# 253 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
# 254 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 255 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 256 "data//maps/Route101/scripts.pory"
	special HealPlayerParty
# 257 "data//maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 258 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 259 "data//maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 260 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 261 "data//maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 262 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 263 "data//maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 264 "data//maps/Route101/scripts.pory"
	checkplayergender
# 265 "data//maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 266 "data//maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 267 "data//maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 268 "data//maps/Route101/scripts.pory"
	waitstate
# 269 "data//maps/Route101/scripts.pory"
	release
# 270 "data//maps/Route101/scripts.pory"
	end
# 271 "data//maps/Route101/scripts.pory"

# 272 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 273 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 274 "data//maps/Route101/scripts.pory"
	return
# 275 "data//maps/Route101/scripts.pory"

# 276 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 277 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 278 "data//maps/Route101/scripts.pory"
	return
# 279 "data//maps/Route101/scripts.pory"

# 280 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 281 "data//maps/Route101/scripts.pory"
	walk_right
# 282 "data//maps/Route101/scripts.pory"
	step_end
# 283 "data//maps/Route101/scripts.pory"

# 284 "data//maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 285 "data//maps/Route101/scripts.pory"
	.string "H-help me!$"
# 286 "data//maps/Route101/scripts.pory"

# 287 "data//maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 288 "data//maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 289 "data//maps/Route101/scripts.pory"
	.string "Please! Help!$"
# 290 "data//maps/Route101/scripts.pory"

# 291 "data//maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 292 "data//maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 293 "data//maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 294 "data//maps/Route101/scripts.pory"

# 295 "data//maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 296 "data//maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 297 "data//maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 298 "data//maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 299 "data//maps/Route101/scripts.pory"
	.string "My idiot kid must have\n"
# 300 "data//maps/Route101/scripts.pory"
	.string "'borrowed' my POKéMON again . . .\p"
# 301 "data//maps/Route101/scripts.pory"
	.string "This is a dangerous place to chat, so\n"
# 302 "data//maps/Route101/scripts.pory"
	.string "lets off to my POKéMON LAB, okay?$"
# 303 "data//maps/Route101/scripts.pory"

# 304 "data//maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 305 "data//maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 306 "data//maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 307 "data//maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 308 "data//maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 309 "data//maps/Route101/scripts.pory"

# 310 "data//maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 311 "data//maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 312 "data//maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 313 "data//maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 314 "data//maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 315 "data//maps/Route101/scripts.pory"

# 316 "data//maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 317 "data//maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 318 "data//maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
