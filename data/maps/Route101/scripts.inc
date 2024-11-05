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
	clearflag FLAG_SYS_SAVE_GET
# 12 "data//maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 13 "data//maps/Route101/scripts.pory"
	end
# 14 "data//maps/Route101/scripts.pory"

# 15 "data//maps/Route101/scripts.pory"
Route101_OnFrame:
# 16 "data//maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 17 "data//maps/Route101/scripts.pory"
	.2byte 0
# 18 "data//maps/Route101/scripts.pory"

# 19 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 20 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 21 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 22 "data//maps/Route101/scripts.pory"
	end
# 23 "data//maps/Route101/scripts.pory"

# 24 "data//maps/Route101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 25 "data//maps/Route101/scripts.pory"
	lockall
# 26 "data//maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 27 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 28 "data//maps/Route101/scripts.pory"
	closemessage
# 29 "data//maps/Route101/scripts.pory"
	setobjectxy LOCALID_BIRCH, 0, 15
# 30 "data//maps/Route101/scripts.pory"
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
# 31 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
# 32 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
# 33 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 34 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 35 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 36 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
# 37 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 38 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 39 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 40 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 41 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 42 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 43 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 44 "data//maps/Route101/scripts.pory"
	closemessage
# 45 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 46 "data//maps/Route101/scripts.pory"
	releaseall
# 47 "data//maps/Route101/scripts.pory"
	end
# 48 "data//maps/Route101/scripts.pory"

# 49 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 50 "data//maps/Route101/scripts.pory"
	lockall
# 51 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 52 "data//maps/Route101/scripts.pory"
	closemessage
# 53 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
# 54 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 55 "data//maps/Route101/scripts.pory"
	releaseall
# 56 "data//maps/Route101/scripts.pory"
	end
# 57 "data//maps/Route101/scripts.pory"

# 58 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 59 "data//maps/Route101/scripts.pory"
	lockall
# 60 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 61 "data//maps/Route101/scripts.pory"
	closemessage
# 62 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
# 63 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 64 "data//maps/Route101/scripts.pory"
	releaseall
# 65 "data//maps/Route101/scripts.pory"
	end
# 66 "data//maps/Route101/scripts.pory"

# 67 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitEast::
# 68 "data//maps/Route101/scripts.pory"
	lockall
# 69 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 70 "data//maps/Route101/scripts.pory"
	closemessage
# 71 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitEast
# 72 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 73 "data//maps/Route101/scripts.pory"
	releaseall
# 74 "data//maps/Route101/scripts.pory"
	end
# 75 "data//maps/Route101/scripts.pory"

# 76 "data//maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 77 "data//maps/Route101/scripts.pory"
	lockall
# 78 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 79 "data//maps/Route101/scripts.pory"
	closemessage
# 80 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
# 81 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 82 "data//maps/Route101/scripts.pory"
	releaseall
# 83 "data//maps/Route101/scripts.pory"
	end
# 84 "data//maps/Route101/scripts.pory"

# 85 "data//maps/Route101/scripts.pory"
Route101_EventScript_PleadingBirch::
# 86 "data//maps/Route101/scripts.pory"
	lockall
# 87 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 88 "data//maps/Route101/scripts.pory"
	closemessage
# 89 "data//maps/Route101/scripts.pory"
	releaseall
# 90 "data//maps/Route101/scripts.pory"
	end
# 91 "data//maps/Route101/scripts.pory"

# 92 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 93 "data//maps/Route101/scripts.pory"
	walk_up
# 94 "data//maps/Route101/scripts.pory"
	step_end
# 95 "data//maps/Route101/scripts.pory"

# 96 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 97 "data//maps/Route101/scripts.pory"
	walk_right
# 98 "data//maps/Route101/scripts.pory"
	step_end
# 99 "data//maps/Route101/scripts.pory"

# 100 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitEast:
# 101 "data//maps/Route101/scripts.pory"
	walk_left
# 102 "data//maps/Route101/scripts.pory"
	step_end
# 103 "data//maps/Route101/scripts.pory"

# 104 "data//maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 105 "data//maps/Route101/scripts.pory"
	walk_down
# 106 "data//maps/Route101/scripts.pory"
	step_end
# 107 "data//maps/Route101/scripts.pory"

# 108 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 109 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 110 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 111 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 112 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 113 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 114 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 115 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 116 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 117 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 118 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 119 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 120 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 121 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 122 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 123 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 124 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 125 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 126 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 127 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 128 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 129 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 130 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 131 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 132 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 133 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 134 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 135 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 136 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 137 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 138 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 139 "data//maps/Route101/scripts.pory"
	step_end
# 140 "data//maps/Route101/scripts.pory"

# 141 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 142 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 143 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 144 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 145 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 146 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 147 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 148 "data//maps/Route101/scripts.pory"
	step_end
# 149 "data//maps/Route101/scripts.pory"

# 150 "data//maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 151 "data//maps/Route101/scripts.pory"
	step_end
# 152 "data//maps/Route101/scripts.pory"

# 153 "data//maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 154 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 155 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 156 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 157 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 158 "data//maps/Route101/scripts.pory"
	step_end
# 159 "data//maps/Route101/scripts.pory"

# 160 "data//maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 161 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 162 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 163 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 164 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 165 "data//maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 166 "data//maps/Route101/scripts.pory"
	step_end
# 167 "data//maps/Route101/scripts.pory"

# 168 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 169 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 170 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 171 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 172 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 173 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 174 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 175 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 176 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 177 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 178 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 179 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 180 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 181 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 182 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 183 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 184 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 185 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 186 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 187 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 188 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 189 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 190 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 191 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 192 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 193 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 194 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 195 "data//maps/Route101/scripts.pory"
	walk_fast_down
# 196 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 197 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 198 "data//maps/Route101/scripts.pory"
	walk_fast_left
# 199 "data//maps/Route101/scripts.pory"
	step_end
# 200 "data//maps/Route101/scripts.pory"

# 201 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 202 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 203 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 204 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 205 "data//maps/Route101/scripts.pory"
	walk_fast_right
# 206 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 207 "data//maps/Route101/scripts.pory"
	walk_fast_up
# 208 "data//maps/Route101/scripts.pory"
	step_end
# 209 "data//maps/Route101/scripts.pory"

# 210 "data//maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 211 "data//maps/Route101/scripts.pory"
	step_end
# 212 "data//maps/Route101/scripts.pory"

# 213 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 214 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 215 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 216 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 217 "data//maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 218 "data//maps/Route101/scripts.pory"
	step_end
# 219 "data//maps/Route101/scripts.pory"

# 220 "data//maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 221 "data//maps/Route101/scripts.pory"
	walk_up
# 222 "data//maps/Route101/scripts.pory"
	walk_up
# 223 "data//maps/Route101/scripts.pory"
	step_end
# 224 "data//maps/Route101/scripts.pory"

# 225 "data//maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 226 "data//maps/Route101/scripts.pory"
	walk_up
# 227 "data//maps/Route101/scripts.pory"
	walk_left
# 228 "data//maps/Route101/scripts.pory"
	walk_up
# 229 "data//maps/Route101/scripts.pory"
	step_end
# 230 "data//maps/Route101/scripts.pory"

# 231 "data//maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 232 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 233 "data//maps/Route101/scripts.pory"
	end
# 234 "data//maps/Route101/scripts.pory"

# 235 "data//maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 236 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 237 "data//maps/Route101/scripts.pory"
	end
# 238 "data//maps/Route101/scripts.pory"

# 239 "data//maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 240 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 241 "data//maps/Route101/scripts.pory"
	end
# 242 "data//maps/Route101/scripts.pory"

# 243 "data//maps/Route101/scripts.pory"
Route101_EventScript_BirchsBag::
# 244 "data//maps/Route101/scripts.pory"
	lock
# 245 "data//maps/Route101/scripts.pory"
	faceplayer
# 246 "data//maps/Route101/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 247 "data//maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 248 "data//maps/Route101/scripts.pory"
	removeobject LOCALID_ZIGZAGOON
# 249 "data//maps/Route101/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
# 250 "data//maps/Route101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 251 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 252 "data//maps/Route101/scripts.pory"
	special ChooseStarter
# 253 "data//maps/Route101/scripts.pory"
	waitstate
# 254 "data//maps/Route101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
# 255 "data//maps/Route101/scripts.pory"
	waitmovement 0
# 256 "data//maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 257 "data//maps/Route101/scripts.pory"
	special HealPlayerParty
# 258 "data//maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 259 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 260 "data//maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 261 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 262 "data//maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 263 "data//maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 264 "data//maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 265 "data//maps/Route101/scripts.pory"
	checkplayergender
# 266 "data//maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 267 "data//maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 268 "data//maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 269 "data//maps/Route101/scripts.pory"
	waitstate
# 270 "data//maps/Route101/scripts.pory"
	release
# 271 "data//maps/Route101/scripts.pory"
	end
# 272 "data//maps/Route101/scripts.pory"

# 273 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 274 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 275 "data//maps/Route101/scripts.pory"
	return
# 276 "data//maps/Route101/scripts.pory"

# 277 "data//maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 278 "data//maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 279 "data//maps/Route101/scripts.pory"
	return
# 280 "data//maps/Route101/scripts.pory"

# 281 "data//maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 282 "data//maps/Route101/scripts.pory"
	walk_right
# 283 "data//maps/Route101/scripts.pory"
	step_end
# 284 "data//maps/Route101/scripts.pory"

# 285 "data//maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 286 "data//maps/Route101/scripts.pory"
	.string "H-help me!$"
# 287 "data//maps/Route101/scripts.pory"

# 288 "data//maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 289 "data//maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 290 "data//maps/Route101/scripts.pory"
	.string "Please! Help!$"
# 291 "data//maps/Route101/scripts.pory"

# 292 "data//maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 293 "data//maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 294 "data//maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 295 "data//maps/Route101/scripts.pory"

# 296 "data//maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 297 "data//maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 298 "data//maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 299 "data//maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 300 "data//maps/Route101/scripts.pory"
	.string "My idiot kid must have\n"
# 301 "data//maps/Route101/scripts.pory"
	.string "'borrowed' my POKéMON again . . .\p"
# 302 "data//maps/Route101/scripts.pory"
	.string "This is a dangerous place to chat, so\n"
# 303 "data//maps/Route101/scripts.pory"
	.string "lets off to my POKéMON LAB, okay?$"
# 304 "data//maps/Route101/scripts.pory"

# 305 "data//maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 306 "data//maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 307 "data//maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 308 "data//maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 309 "data//maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 310 "data//maps/Route101/scripts.pory"

# 311 "data//maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 312 "data//maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 313 "data//maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 314 "data//maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 315 "data//maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 316 "data//maps/Route101/scripts.pory"

# 317 "data//maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 318 "data//maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 319 "data//maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
