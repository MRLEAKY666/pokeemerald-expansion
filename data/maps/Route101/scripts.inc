# 1 "data/maps/Route101/scripts.pory"

# 2 "data/maps/Route101/scripts.pory"
Route101_MapScripts::
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 4 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 5 "data/maps/Route101/scripts.pory"
	.byte 0
# 6 "data/maps/Route101/scripts.pory"

# 7 "data/maps/Route101/scripts.pory"
Route101_OnTransition:
# 8 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 9 "data/maps/Route101/scripts.pory"
	end
# 10 "data/maps/Route101/scripts.pory"

# 11 "data/maps/Route101/scripts.pory"
Route101_OnFrame:
# 12 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 13 "data/maps/Route101/scripts.pory"
	.2byte 0
# 14 "data/maps/Route101/scripts.pory"

# 15 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 16 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 17 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 18 "data/maps/Route101/scripts.pory"
	end
# 19 "data/maps/Route101/scripts.pory"

# 20 "data/maps/Route101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 21 "data/maps/Route101/scripts.pory"
	lockall
# 22 "data/maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 23 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 24 "data/maps/Route101/scripts.pory"
	closemessage
# 25 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
# 26 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
# 27 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
# 28 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
# 29 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 30 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 31 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 32 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
# 33 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 35 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 37 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 38 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 39 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 40 "data/maps/Route101/scripts.pory"
	closemessage
# 41 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 42 "data/maps/Route101/scripts.pory"
	releaseall
# 43 "data/maps/Route101/scripts.pory"
	end
# 44 "data/maps/Route101/scripts.pory"

# 45 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 46 "data/maps/Route101/scripts.pory"
	lockall
# 47 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 48 "data/maps/Route101/scripts.pory"
	closemessage
# 49 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 50 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route101/scripts.pory"
	releaseall
# 52 "data/maps/Route101/scripts.pory"
	end
# 53 "data/maps/Route101/scripts.pory"

# 54 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 55 "data/maps/Route101/scripts.pory"
	lockall
# 56 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 57 "data/maps/Route101/scripts.pory"
	closemessage
# 58 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 59 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 60 "data/maps/Route101/scripts.pory"
	releaseall
# 61 "data/maps/Route101/scripts.pory"
	end
# 62 "data/maps/Route101/scripts.pory"

# 63 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitEast::
# 64 "data/maps/Route101/scripts.pory"
	lockall
# 65 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 66 "data/maps/Route101/scripts.pory"
	closemessage
# 67 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitEast
# 68 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route101/scripts.pory"
	releaseall
# 70 "data/maps/Route101/scripts.pory"
	end
# 71 "data/maps/Route101/scripts.pory"

# 72 "data/maps/Route101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 73 "data/maps/Route101/scripts.pory"
	lockall
# 74 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 75 "data/maps/Route101/scripts.pory"
	closemessage
# 76 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 77 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 78 "data/maps/Route101/scripts.pory"
	releaseall
# 79 "data/maps/Route101/scripts.pory"
	end
# 80 "data/maps/Route101/scripts.pory"

# 81 "data/maps/Route101/scripts.pory"
Route101_EventScript_PleadingBirch::
# 82 "data/maps/Route101/scripts.pory"
	lockall
# 83 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 84 "data/maps/Route101/scripts.pory"
	closemessage
# 85 "data/maps/Route101/scripts.pory"
	releaseall
# 86 "data/maps/Route101/scripts.pory"
	end
# 87 "data/maps/Route101/scripts.pory"

# 88 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 89 "data/maps/Route101/scripts.pory"
	walk_up
# 90 "data/maps/Route101/scripts.pory"
	step_end
# 91 "data/maps/Route101/scripts.pory"

# 92 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 93 "data/maps/Route101/scripts.pory"
	walk_right
# 94 "data/maps/Route101/scripts.pory"
	step_end
# 95 "data/maps/Route101/scripts.pory"

# 96 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitEast:
# 97 "data/maps/Route101/scripts.pory"
	walk_left
# 98 "data/maps/Route101/scripts.pory"
	step_end
# 99 "data/maps/Route101/scripts.pory"

# 100 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 101 "data/maps/Route101/scripts.pory"
	walk_down
# 102 "data/maps/Route101/scripts.pory"
	step_end
# 103 "data/maps/Route101/scripts.pory"

# 104 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 105 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 106 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 107 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 108 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 109 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 110 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 111 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 112 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 113 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 116 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 117 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 118 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 119 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 120 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 121 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 122 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 123 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 124 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 127 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 128 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 129 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 130 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 131 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 132 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 133 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 134 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 135 "data/maps/Route101/scripts.pory"
	step_end
# 136 "data/maps/Route101/scripts.pory"

# 137 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 138 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 139 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 140 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 141 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 142 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route101/scripts.pory"
	step_end
# 145 "data/maps/Route101/scripts.pory"

# 146 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 147 "data/maps/Route101/scripts.pory"
	step_end
# 148 "data/maps/Route101/scripts.pory"

# 149 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 150 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 151 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 152 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 153 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 154 "data/maps/Route101/scripts.pory"
	step_end
# 155 "data/maps/Route101/scripts.pory"

# 156 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 159 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 160 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 161 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 162 "data/maps/Route101/scripts.pory"
	step_end
# 163 "data/maps/Route101/scripts.pory"

# 164 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 165 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 166 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 167 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 168 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 169 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 170 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 171 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 172 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 173 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 174 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 176 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 177 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 178 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 179 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 180 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 181 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 182 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 183 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 184 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 185 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 186 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 187 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 189 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 190 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 191 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 192 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 193 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 194 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 195 "data/maps/Route101/scripts.pory"
	step_end
# 196 "data/maps/Route101/scripts.pory"

# 197 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 198 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 199 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 200 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 201 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 202 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 203 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 204 "data/maps/Route101/scripts.pory"
	step_end
# 205 "data/maps/Route101/scripts.pory"

# 206 "data/maps/Route101/scripts.pory"
@ Leftover data? This command is unused.
# 207 "data/maps/Route101/scripts.pory"
	step_end
# 208 "data/maps/Route101/scripts.pory"

# 209 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 210 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 211 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 212 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 213 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 214 "data/maps/Route101/scripts.pory"
	step_end
# 215 "data/maps/Route101/scripts.pory"

# 216 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 217 "data/maps/Route101/scripts.pory"
	walk_up
# 218 "data/maps/Route101/scripts.pory"
	walk_up
# 219 "data/maps/Route101/scripts.pory"
	step_end
# 220 "data/maps/Route101/scripts.pory"

# 221 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 222 "data/maps/Route101/scripts.pory"
	walk_up
# 223 "data/maps/Route101/scripts.pory"
	walk_left
# 224 "data/maps/Route101/scripts.pory"
	walk_up
# 225 "data/maps/Route101/scripts.pory"
	step_end
# 226 "data/maps/Route101/scripts.pory"

# 227 "data/maps/Route101/scripts.pory"
Route101_EventScript_Youngster::
# 228 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 229 "data/maps/Route101/scripts.pory"
	end
# 230 "data/maps/Route101/scripts.pory"

# 231 "data/maps/Route101/scripts.pory"
Route101_EventScript_Boy::
# 232 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 233 "data/maps/Route101/scripts.pory"
	end
# 234 "data/maps/Route101/scripts.pory"

# 235 "data/maps/Route101/scripts.pory"
Route101_EventScript_RouteSign::
# 236 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 237 "data/maps/Route101/scripts.pory"
	end
# 238 "data/maps/Route101/scripts.pory"

# 239 "data/maps/Route101/scripts.pory"
Route101_EventScript_BirchsBag::
# 240 "data/maps/Route101/scripts.pory"
	lock
# 241 "data/maps/Route101/scripts.pory"
	faceplayer
# 242 "data/maps/Route101/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 243 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 244 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE101_ZIGZAGOON
# 245 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_PLAYER, 6, 13
# 246 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 247 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 248 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 249 "data/maps/Route101/scripts.pory"
	waitstate
# 250 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchApproachPlayer
# 251 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 252 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 253 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 254 "data/maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 255 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 256 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 257 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 258 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 259 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 260 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 261 "data/maps/Route101/scripts.pory"
	checkplayergender
# 262 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 263 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 264 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 8, 5
# 265 "data/maps/Route101/scripts.pory"
	waitstate
# 266 "data/maps/Route101/scripts.pory"
	release
# 267 "data/maps/Route101/scripts.pory"
	end
# 268 "data/maps/Route101/scripts.pory"

# 269 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 270 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 271 "data/maps/Route101/scripts.pory"
	return
# 272 "data/maps/Route101/scripts.pory"

# 273 "data/maps/Route101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 274 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 275 "data/maps/Route101/scripts.pory"
	return
# 276 "data/maps/Route101/scripts.pory"

# 277 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 278 "data/maps/Route101/scripts.pory"
	walk_right
# 279 "data/maps/Route101/scripts.pory"
	step_end
# 280 "data/maps/Route101/scripts.pory"

# 281 "data/maps/Route101/scripts.pory"
Route101_Text_HelpMe:
# 282 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"
# 283 "data/maps/Route101/scripts.pory"

# 284 "data/maps/Route101/scripts.pory"
Route101_Text_PleaseHelp:
# 285 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
# 286 "data/maps/Route101/scripts.pory"
	.string "Please! Help!$"
# 287 "data/maps/Route101/scripts.pory"

# 288 "data/maps/Route101/scripts.pory"
Route101_Text_DontLeaveMe:
# 289 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 290 "data/maps/Route101/scripts.pory"
	.string "Don't leave me like this!$"
# 291 "data/maps/Route101/scripts.pory"

# 292 "data/maps/Route101/scripts.pory"
Route101_Text_YouSavedMe:
# 293 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 294 "data/maps/Route101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 295 "data/maps/Route101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 296 "data/maps/Route101/scripts.pory"
	.string "My idiot kid must have\n"
# 297 "data/maps/Route101/scripts.pory"
	.string "‘borrowed’ my POKéMON again . . .\p"
# 298 "data/maps/Route101/scripts.pory"
	.string "This is a dangerous place to chat, so\n"
# 299 "data/maps/Route101/scripts.pory"
	.string "lets off to my POKéMON LAB, okay?$"
# 300 "data/maps/Route101/scripts.pory"

# 301 "data/maps/Route101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 302 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 303 "data/maps/Route101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 304 "data/maps/Route101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 305 "data/maps/Route101/scripts.pory"
	.string "TOWN right close by.$"
# 306 "data/maps/Route101/scripts.pory"

# 307 "data/maps/Route101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 308 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 309 "data/maps/Route101/scripts.pory"
	.string "tall grass.\p"
# 310 "data/maps/Route101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 311 "data/maps/Route101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 312 "data/maps/Route101/scripts.pory"

# 313 "data/maps/Route101/scripts.pory"
Route101_Text_RouteSign:
# 314 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
# 315 "data/maps/Route101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
