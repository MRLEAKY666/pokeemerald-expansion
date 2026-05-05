# 1 "data//maps/RustboroCity/scripts.pory"

# 2 "data//maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 3 "data//maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 4 "data//maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 5 "data//maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, RustboroCity_OnResume
# 6 "data//maps/RustboroCity/scripts.pory"
	.byte 0

RustboroCity_OnTransition::
# 14 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_TEMP_1E
# 15 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 16 "data//maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 18 "data//maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 19 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	return


RustboroCity_OnResume::
# 23 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, RustboroCity_OnResume_1
# 27 "data//maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 28 "data//maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_E, 5
	goto_if_eq RustboroCity_OnResume_5
	return

RustboroCity_OnResume_1:
# 24 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_TEMP_1F
	return

RustboroCity_OnResume_4:
# 29 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_TEMP_1E
# 30 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_TEMP_1F
# 31 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
	return

RustboroCity_OnResume_5:
# 28 "data//maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_F, 42
	goto_if_eq RustboroCity_OnResume_4
	return


RustboroCity_EventScript_ReturningFromShadyTruck::
# 37 "data//maps/RustboroCity/scripts.pory"
	setobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY, 0
# 38 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 39 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_JumpOutOfTruck
# 40 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 41 "data//maps/RustboroCity/scripts.pory"
	goto_if_unset FLAG_KEEP_SHADY_TRUCK, RustboroCity_EventScript_ReturningFromShadyTruck_2
RustboroCity_EventScript_ReturningFromShadyTruck_1:
# 77 "data//maps/RustboroCity/scripts.pory"
	resetobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY
# 78 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_F, 0
# 79 "data//maps/RustboroCity/scripts.pory"
	release
	return

RustboroCity_EventScript_ReturningFromShadyTruck_2:
# 42 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_MoveAwayFromTruck
# 43 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 44 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceFasterDown
# 45 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 46 "data//maps/RustboroCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
# 47 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_0
# 48 "data//maps/RustboroCity/scripts.pory"
	waitmoncry
# 49 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 50 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 51 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, RustboroCity_Movement_AlakazamEnterTruck
# 52 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 53 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 54 "data//maps/RustboroCity/scripts.pory"
	waitmovement LOCALID_RUSTBORO_SHADY_ALAKAZAM
# 55 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 56 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 57 "data//maps/RustboroCity/scripts.pory"
	waitse
# 58 "data//maps/RustboroCity/scripts.pory"
	delay 15
# 59 "data//maps/RustboroCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 60 "data//maps/RustboroCity/scripts.pory"
	delay 60
# 61 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_MOVE
# 62 "data//maps/RustboroCity/scripts.pory"
	delay 120
# 63 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_STOP
# 64 "data//maps/RustboroCity/scripts.pory"
	waitse
# 65 "data//maps/RustboroCity/scripts.pory"
	delay 45
# 66 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SHADY_TRUCK
# 67 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SHADY_ALAKAZAM
# 68 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_TRUCK_COLLISION_A
# 69 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_TRUCK_COLLISION_B
# 70 "data//maps/RustboroCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 71 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 72 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_1
# 73 "data//maps/RustboroCity/scripts.pory"
	waitmessage
# 74 "data//maps/RustboroCity/scripts.pory"
	delay 90
# 75 "data//maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_ReturningFromShadyTruck_1


# 82 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_JumpOutOfTruck:
# 83 "data//maps/RustboroCity/scripts.pory"
	set_visible
# 84 "data//maps/RustboroCity/scripts.pory"
	jump_right
# 85 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 86 "data//maps/RustboroCity/scripts.pory"
	step_end

# 89 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_MoveAwayFromTruck:
# 90 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 91 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 92 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 93 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 94 "data//maps/RustboroCity/scripts.pory"
	step_end

# 97 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_AlakazamEnterTruck:
# 98 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 99 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 100 "data//maps/RustboroCity/scripts.pory"
	jump_left
# 101 "data//maps/RustboroCity/scripts.pory"
	set_invisible
# 102 "data//maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_ExamineShadyTruck::
# 106 "data//maps/RustboroCity/scripts.pory"
	lock
# 107 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ExamineShadyTruck_Text_0, MSGBOX_DEFAULT
# 109 "data//maps/RustboroCity/scripts.pory"
	release
	return


RustboroCity_EventScript_ShadyAlakazam::
# 113 "data//maps/RustboroCity/scripts.pory"
	lock
# 114 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 115 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 116 "data//maps/RustboroCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_HIGH_PITCH
# 117 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_0
# 118 "data//maps/RustboroCity/scripts.pory"
	waitmoncry
# 119 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 120 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ShadyAlakazam_Text_0
# 121 "data//maps/RustboroCity/scripts.pory"
	waitmessage
# 122 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 123 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 124 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq RustboroCity_EventScript_ShadyAlakazam_2
# 128 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ShadyAlakazam_Text_2, MSGBOX_YESNO
# 130 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 131 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_ShadyAlakazam_5
RustboroCity_EventScript_ShadyAlakazam_1:
# 135 "data//maps/RustboroCity/scripts.pory"
	release
	return

RustboroCity_EventScript_ShadyAlakazam_2:
# 125 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ShadyAlakazam_Text_1, MSGBOX_DEFAULT
	goto RustboroCity_EventScript_ShadyAlakazam_1

RustboroCity_EventScript_ShadyAlakazam_5:
# 132 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EnterShadyTruck
	goto RustboroCity_EventScript_ShadyAlakazam_1


RustboroCity_EventScript_TruckEntrance::
# 139 "data//maps/RustboroCity/scripts.pory"
	goto_if_unset FLAG_TEMP_1E, RustboroCity_EventScript_TruckEntrance_1
	return

RustboroCity_EventScript_TruckEntrance_1:
# 140 "data//maps/RustboroCity/scripts.pory"
	lock
# 141 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 142 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 143 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 144 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 145 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne RustboroCity_EventScript_TruckEntrance_4
RustboroCity_EventScript_TruckEntrance_3:
# 149 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ShadyAlakazam
	return

RustboroCity_EventScript_TruckEntrance_4:
# 146 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 147 "data//maps/RustboroCity/scripts.pory"
	waitmovement
	goto RustboroCity_EventScript_TruckEntrance_3


RustboroCity_EventScript_EnterShadyTruck::
# 154 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 155 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceDown
# 156 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 157 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 158 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 159 "data//maps/RustboroCity/scripts.pory"
	waitse
# 160 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 161 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 162 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne RustboroCity_EventScript_EnterShadyTruck_2
RustboroCity_EventScript_EnterShadyTruck_1:
# 166 "data//maps/RustboroCity/scripts.pory"
	setobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY, 0
# 167 "data//maps/RustboroCity/scripts.pory"
	hidefollower
# 168 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerEnterTruck
# 169 "data//maps/RustboroCity/scripts.pory"
	delay 32
# 170 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 171 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 172 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 173 "data//maps/RustboroCity/scripts.pory"
	waitse
# 174 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 175 "data//maps/RustboroCity/scripts.pory"
	warpcontinuescript MAP_SHADY_GUYS_TRUCK, 5, 2, ShadyGuysTruck_EventScript_PlayerEntersTruck
	return

RustboroCity_EventScript_EnterShadyTruck_2:
# 163 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 164 "data//maps/RustboroCity/scripts.pory"
	waitmovement
	goto RustboroCity_EventScript_EnterShadyTruck_1


# 178 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerEnterTruck:
# 179 "data//maps/RustboroCity/scripts.pory"
	face_left
# 180 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 181 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 182 "data//maps/RustboroCity/scripts.pory"
	jump_left
# 183 "data//maps/RustboroCity/scripts.pory"
	set_invisible
# 184 "data//maps/RustboroCity/scripts.pory"
	step_end

# 187 "data//maps/RustboroCity/scripts.pory"

# 188 "data//maps/RustboroCity/scripts.pory"

# 189 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 190 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_E, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 191 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
# 192 "data//maps/RustboroCity/scripts.pory"
	end
# 193 "data//maps/RustboroCity/scripts.pory"

# 194 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 195 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
# 196 "data//maps/RustboroCity/scripts.pory"
	end
# 197 "data//maps/RustboroCity/scripts.pory"

# 198 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 199 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 200 "data//maps/RustboroCity/scripts.pory"
	return
# 201 "data//maps/RustboroCity/scripts.pory"

# 202 "data//maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 203 "data//maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 204 "data//maps/RustboroCity/scripts.pory"
	map_script_2 VAR_TEMP_F, 42, RustboroCity_EventScript_ReturningFromShadyTruck
# 205 "data//maps/RustboroCity/scripts.pory"
	.2byte 0
# 206 "data//maps/RustboroCity/scripts.pory"

# 207 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 208 "data//maps/RustboroCity/scripts.pory"
	lockall
# 209 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 210 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 211 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 212 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 213 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 214 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_SCIENTIST
# 215 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 216 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 217 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 218 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
# 219 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 220 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
# 221 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 222 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 223 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 224 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 225 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 226 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 227 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 228 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 229 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 230 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 231 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 232 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 233 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 234 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 235 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 236 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 237 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 238 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 239 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 240 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 241 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 242 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 243 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 244 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 245 "data//maps/RustboroCity/scripts.pory"

# 246 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 247 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 248 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 249 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 250 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 251 "data//maps/RustboroCity/scripts.pory"

# 252 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 253 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 254 "data//maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 255 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 256 "data//maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 257 "data//maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 258 "data//maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 259 "data//maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 260 "data//maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 261 "data//maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 262 "data//maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 263 "data//maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 264 "data//maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 265 "data//maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 266 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 267 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 268 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 269 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 270 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 271 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 272 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 273 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 274 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 275 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 276 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 277 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 278 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 279 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 280 "data//maps/RustboroCity/scripts.pory"
	end
# 281 "data//maps/RustboroCity/scripts.pory"

# 282 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 283 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 284 "data//maps/RustboroCity/scripts.pory"
	step_end
# 285 "data//maps/RustboroCity/scripts.pory"

# 286 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 287 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 288 "data//maps/RustboroCity/scripts.pory"
	step_end
# 289 "data//maps/RustboroCity/scripts.pory"

# 290 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 291 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 292 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 293 "data//maps/RustboroCity/scripts.pory"
	step_end
# 294 "data//maps/RustboroCity/scripts.pory"

# 295 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 296 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 297 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 298 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 299 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 300 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 301 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 302 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 303 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 304 "data//maps/RustboroCity/scripts.pory"
	step_end
# 305 "data//maps/RustboroCity/scripts.pory"

# 306 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 307 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 308 "data//maps/RustboroCity/scripts.pory"
	step_end
# 309 "data//maps/RustboroCity/scripts.pory"

# 310 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 311 "data//maps/RustboroCity/scripts.pory"
	lock
# 312 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 313 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 314 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 315 "data//maps/RustboroCity/scripts.pory"
	release
# 316 "data//maps/RustboroCity/scripts.pory"
	end
# 317 "data//maps/RustboroCity/scripts.pory"

# 318 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 319 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 320 "data//maps/RustboroCity/scripts.pory"
	release
# 321 "data//maps/RustboroCity/scripts.pory"
	end
# 322 "data//maps/RustboroCity/scripts.pory"

# 323 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 324 "data//maps/RustboroCity/scripts.pory"
	lock
# 325 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 326 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 327 "data//maps/RustboroCity/scripts.pory"
	release
# 328 "data//maps/RustboroCity/scripts.pory"
	end
# 329 "data//maps/RustboroCity/scripts.pory"

# 330 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 331 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 332 "data//maps/RustboroCity/scripts.pory"
	end
# 333 "data//maps/RustboroCity/scripts.pory"

# 334 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 335 "data//maps/RustboroCity/scripts.pory"
	lock
# 336 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 337 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 338 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 339 "data//maps/RustboroCity/scripts.pory"
	release
# 340 "data//maps/RustboroCity/scripts.pory"
	end
# 341 "data//maps/RustboroCity/scripts.pory"

# 342 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 343 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 344 "data//maps/RustboroCity/scripts.pory"
	release
# 345 "data//maps/RustboroCity/scripts.pory"
	end
# 346 "data//maps/RustboroCity/scripts.pory"

# 347 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 348 "data//maps/RustboroCity/scripts.pory"
	lock
# 349 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 350 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 351 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 352 "data//maps/RustboroCity/scripts.pory"
	release
# 353 "data//maps/RustboroCity/scripts.pory"
	end
# 354 "data//maps/RustboroCity/scripts.pory"

# 355 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 356 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 357 "data//maps/RustboroCity/scripts.pory"
	release
# 358 "data//maps/RustboroCity/scripts.pory"
	end
# 359 "data//maps/RustboroCity/scripts.pory"

# 360 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 361 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 362 "data//maps/RustboroCity/scripts.pory"
	end
# 363 "data//maps/RustboroCity/scripts.pory"

# 364 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 365 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 366 "data//maps/RustboroCity/scripts.pory"
	end
# 367 "data//maps/RustboroCity/scripts.pory"

# 368 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 369 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 370 "data//maps/RustboroCity/scripts.pory"
	end
# 371 "data//maps/RustboroCity/scripts.pory"

# 372 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 373 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 374 "data//maps/RustboroCity/scripts.pory"
	end
# 375 "data//maps/RustboroCity/scripts.pory"

# 376 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 377 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 378 "data//maps/RustboroCity/scripts.pory"
	end
# 379 "data//maps/RustboroCity/scripts.pory"

# 380 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 381 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 382 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 383 "data//maps/RustboroCity/scripts.pory"
	end
# 384 "data//maps/RustboroCity/scripts.pory"

# 385 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 386 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 387 "data//maps/RustboroCity/scripts.pory"
	end
# 388 "data//maps/RustboroCity/scripts.pory"

# 389 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 390 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 391 "data//maps/RustboroCity/scripts.pory"
	end
# 392 "data//maps/RustboroCity/scripts.pory"

# 393 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 394 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 395 "data//maps/RustboroCity/scripts.pory"
	end
# 396 "data//maps/RustboroCity/scripts.pory"

# 397 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 398 "data//maps/RustboroCity/scripts.pory"
	lock
# 399 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 400 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 401 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 402 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 403 "data//maps/RustboroCity/scripts.pory"
	release
# 404 "data//maps/RustboroCity/scripts.pory"
	end
# 405 "data//maps/RustboroCity/scripts.pory"

# 406 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 407 "data//maps/RustboroCity/scripts.pory"
	lock
# 408 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 409 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 410 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 411 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 412 "data//maps/RustboroCity/scripts.pory"
	release
# 413 "data//maps/RustboroCity/scripts.pory"
	end
# 414 "data//maps/RustboroCity/scripts.pory"

# 415 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 416 "data//maps/RustboroCity/scripts.pory"
	lock
# 417 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 418 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 419 "data//maps/RustboroCity/scripts.pory"
	release
# 420 "data//maps/RustboroCity/scripts.pory"
	end
# 421 "data//maps/RustboroCity/scripts.pory"

# 422 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 423 "data//maps/RustboroCity/scripts.pory"
	lockall
# 424 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 425 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 426 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 427 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 428 "data//maps/RustboroCity/scripts.pory"
	end
# 429 "data//maps/RustboroCity/scripts.pory"

# 430 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 431 "data//maps/RustboroCity/scripts.pory"
	lockall
# 432 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 433 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 434 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 435 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 436 "data//maps/RustboroCity/scripts.pory"
	end
# 437 "data//maps/RustboroCity/scripts.pory"

# 438 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 439 "data//maps/RustboroCity/scripts.pory"
	lockall
# 440 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 441 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 442 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 443 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 444 "data//maps/RustboroCity/scripts.pory"
	end
# 445 "data//maps/RustboroCity/scripts.pory"

# 446 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 447 "data//maps/RustboroCity/scripts.pory"
	lockall
# 448 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 449 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 450 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 451 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 452 "data//maps/RustboroCity/scripts.pory"
	end
# 453 "data//maps/RustboroCity/scripts.pory"

# 454 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 455 "data//maps/RustboroCity/scripts.pory"
	lockall
# 456 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 457 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 458 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 459 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 460 "data//maps/RustboroCity/scripts.pory"
	end
# 461 "data//maps/RustboroCity/scripts.pory"

# 462 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 463 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 464 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 465 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 466 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 467 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 468 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 469 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 470 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 471 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 472 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 473 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 474 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 475 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 476 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 477 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 478 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 479 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 480 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 481 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 482 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 483 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 484 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 485 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 486 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 487 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 488 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 489 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 490 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 491 "data//maps/RustboroCity/scripts.pory"
	end
# 492 "data//maps/RustboroCity/scripts.pory"

# 493 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 494 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 495 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 496 "data//maps/RustboroCity/scripts.pory"
	return
# 497 "data//maps/RustboroCity/scripts.pory"

# 498 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 499 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 500 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 501 "data//maps/RustboroCity/scripts.pory"
	return
# 502 "data//maps/RustboroCity/scripts.pory"

# 503 "data//maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 504 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 505 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 506 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 507 "data//maps/RustboroCity/scripts.pory"
	return
# 508 "data//maps/RustboroCity/scripts.pory"

# 509 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 510 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 511 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 512 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 513 "data//maps/RustboroCity/scripts.pory"
	return
# 514 "data//maps/RustboroCity/scripts.pory"

# 515 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 516 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 517 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 518 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 519 "data//maps/RustboroCity/scripts.pory"
	return
# 520 "data//maps/RustboroCity/scripts.pory"

# 521 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 522 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 523 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 524 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 525 "data//maps/RustboroCity/scripts.pory"
	return
# 526 "data//maps/RustboroCity/scripts.pory"

# 527 "data//maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 528 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 529 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 530 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 531 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 532 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 533 "data//maps/RustboroCity/scripts.pory"
	return
# 534 "data//maps/RustboroCity/scripts.pory"

# 535 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 536 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 537 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 538 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 539 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 540 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 541 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 542 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 543 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 544 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 545 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 546 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 547 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 548 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 549 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 550 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 551 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 552 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 553 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 554 "data//maps/RustboroCity/scripts.pory"
	step_end
# 555 "data//maps/RustboroCity/scripts.pory"

# 556 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 557 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 558 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 559 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 560 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 561 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 562 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 563 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 564 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 565 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 566 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 567 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 568 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 569 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 570 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 571 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 572 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 573 "data//maps/RustboroCity/scripts.pory"
	step_end
# 574 "data//maps/RustboroCity/scripts.pory"

# 575 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 576 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 577 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 578 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 579 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 580 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 581 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 582 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 583 "data//maps/RustboroCity/scripts.pory"
	step_end
# 584 "data//maps/RustboroCity/scripts.pory"

# 585 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 586 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 587 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 588 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 589 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 590 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 591 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 592 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 593 "data//maps/RustboroCity/scripts.pory"
	step_end
# 594 "data//maps/RustboroCity/scripts.pory"

# 595 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 596 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 597 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 598 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 599 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 600 "data//maps/RustboroCity/scripts.pory"
	step_end
# 601 "data//maps/RustboroCity/scripts.pory"

# 602 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 603 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 604 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 605 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 606 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 607 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 608 "data//maps/RustboroCity/scripts.pory"
	step_end
# 609 "data//maps/RustboroCity/scripts.pory"

# 610 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 611 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 612 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 613 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 614 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 615 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 616 "data//maps/RustboroCity/scripts.pory"
	step_end
# 617 "data//maps/RustboroCity/scripts.pory"

# 618 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 619 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 620 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 621 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 622 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 623 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 624 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 625 "data//maps/RustboroCity/scripts.pory"
	step_end
# 626 "data//maps/RustboroCity/scripts.pory"

# 627 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 628 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 629 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 630 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 631 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 632 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 633 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 634 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 635 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 636 "data//maps/RustboroCity/scripts.pory"
	step_end
# 637 "data//maps/RustboroCity/scripts.pory"

# 638 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 639 "data//maps/RustboroCity/scripts.pory"
	lock
# 640 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 641 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 642 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 643 "data//maps/RustboroCity/scripts.pory"
	release
# 644 "data//maps/RustboroCity/scripts.pory"
	end
# 645 "data//maps/RustboroCity/scripts.pory"

# 646 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 647 "data//maps/RustboroCity/scripts.pory"
	waitse
# 648 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 649 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 650 "data//maps/RustboroCity/scripts.pory"
	end
# 651 "data//maps/RustboroCity/scripts.pory"

# 652 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 653 "data//maps/RustboroCity/scripts.pory"
	lockall
# 654 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 655 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 656 "data//maps/RustboroCity/scripts.pory"
	end
# 657 "data//maps/RustboroCity/scripts.pory"

# 658 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 659 "data//maps/RustboroCity/scripts.pory"
	lockall
# 660 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 661 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 662 "data//maps/RustboroCity/scripts.pory"
	end
# 663 "data//maps/RustboroCity/scripts.pory"

# 664 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 665 "data//maps/RustboroCity/scripts.pory"
	lockall
# 666 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 667 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 668 "data//maps/RustboroCity/scripts.pory"
	end
# 669 "data//maps/RustboroCity/scripts.pory"

# 670 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 671 "data//maps/RustboroCity/scripts.pory"
	lockall
# 672 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 673 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 674 "data//maps/RustboroCity/scripts.pory"
	end
# 675 "data//maps/RustboroCity/scripts.pory"

# 676 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 677 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 678 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 679 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 680 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 681 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 682 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 683 "data//maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 684 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 685 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 686 "data//maps/RustboroCity/scripts.pory"
	end
# 687 "data//maps/RustboroCity/scripts.pory"

# 688 "data//maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 689 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 690 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 691 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 692 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 693 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 694 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 695 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 696 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 697 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 698 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 699 "data//maps/RustboroCity/scripts.pory"
	return
# 700 "data//maps/RustboroCity/scripts.pory"

# 701 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 702 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 703 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 704 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 705 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 706 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 707 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 708 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 710 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 711 "data//maps/RustboroCity/scripts.pory"
	return
# 712 "data//maps/RustboroCity/scripts.pory"

# 713 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 714 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 715 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 716 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 717 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 718 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 719 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 720 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 721 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 722 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 723 "data//maps/RustboroCity/scripts.pory"
	return
# 724 "data//maps/RustboroCity/scripts.pory"

# 725 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 726 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 727 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 728 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 729 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 730 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 731 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 732 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 733 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 734 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 735 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 736 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 737 "data//maps/RustboroCity/scripts.pory"
	return
# 738 "data//maps/RustboroCity/scripts.pory"

# 739 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 740 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 741 "data//maps/RustboroCity/scripts.pory"
	step_end
# 742 "data//maps/RustboroCity/scripts.pory"

# 743 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 744 "data//maps/RustboroCity/scripts.pory"
	lockall
# 745 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 746 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 747 "data//maps/RustboroCity/scripts.pory"
	end
# 748 "data//maps/RustboroCity/scripts.pory"

# 749 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 750 "data//maps/RustboroCity/scripts.pory"
	lockall
# 751 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 752 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 753 "data//maps/RustboroCity/scripts.pory"
	end
# 754 "data//maps/RustboroCity/scripts.pory"

# 755 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 756 "data//maps/RustboroCity/scripts.pory"
	lockall
# 757 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 758 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 759 "data//maps/RustboroCity/scripts.pory"
	end
# 760 "data//maps/RustboroCity/scripts.pory"

# 761 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 762 "data//maps/RustboroCity/scripts.pory"
	lockall
# 763 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 764 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 765 "data//maps/RustboroCity/scripts.pory"
	end
# 766 "data//maps/RustboroCity/scripts.pory"

# 767 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 768 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 769 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 770 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 771 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 772 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 773 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 774 "data//maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 775 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 776 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 777 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 778 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 779 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 780 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 781 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 782 "data//maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 783 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 784 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 785 "data//maps/RustboroCity/scripts.pory"
	end
# 786 "data//maps/RustboroCity/scripts.pory"

# 787 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 788 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 789 "data//maps/RustboroCity/scripts.pory"
	return
# 790 "data//maps/RustboroCity/scripts.pory"

# 791 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 792 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 793 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 794 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 795 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 796 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 797 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 798 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 799 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 800 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 801 "data//maps/RustboroCity/scripts.pory"
	return
# 802 "data//maps/RustboroCity/scripts.pory"

# 803 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 804 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 805 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 806 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 807 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 808 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 809 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 810 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 811 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 812 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 813 "data//maps/RustboroCity/scripts.pory"
	return
# 814 "data//maps/RustboroCity/scripts.pory"

# 815 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 816 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 817 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 818 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 819 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 820 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 822 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 823 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 824 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 825 "data//maps/RustboroCity/scripts.pory"
	return
# 826 "data//maps/RustboroCity/scripts.pory"

# 827 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 828 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 829 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 830 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 831 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 832 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 833 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 834 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 835 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 836 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 837 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 838 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 839 "data//maps/RustboroCity/scripts.pory"
	return
# 840 "data//maps/RustboroCity/scripts.pory"

# 841 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 842 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 843 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 844 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 845 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 846 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 847 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 848 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 849 "data//maps/RustboroCity/scripts.pory"
	return
# 850 "data//maps/RustboroCity/scripts.pory"

# 851 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 852 "data//maps/RustboroCity/scripts.pory"
	lockall
# 853 "data//maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 854 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 855 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 856 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 857 "data//maps/RustboroCity/scripts.pory"

# 858 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 859 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 860 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 861 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 862 "data//maps/RustboroCity/scripts.pory"
	return
# 863 "data//maps/RustboroCity/scripts.pory"

# 864 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 865 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 866 "data//maps/RustboroCity/scripts.pory"
	return
# 867 "data//maps/RustboroCity/scripts.pory"

# 868 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 869 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 870 "data//maps/RustboroCity/scripts.pory"
	return
# 871 "data//maps/RustboroCity/scripts.pory"

# 872 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 873 "data//maps/RustboroCity/scripts.pory"
	lockall
# 874 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 875 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 876 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 877 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 878 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 879 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 880 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 881 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 882 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 883 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 884 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 885 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 886 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 887 "data//maps/RustboroCity/scripts.pory"

# 888 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 889 "data//maps/RustboroCity/scripts.pory"
	lockall
# 890 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 891 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 892 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 893 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 894 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 895 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 896 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 897 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 898 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 899 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 900 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 901 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 902 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 903 "data//maps/RustboroCity/scripts.pory"

# 904 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 905 "data//maps/RustboroCity/scripts.pory"
	lockall
# 906 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 907 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 908 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 909 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 910 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 911 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 912 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 913 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 914 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 915 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 916 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 917 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 918 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 919 "data//maps/RustboroCity/scripts.pory"

# 920 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 921 "data//maps/RustboroCity/scripts.pory"
	lockall
# 922 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 923 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 924 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 925 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 926 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 927 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 928 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 929 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 930 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 931 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 932 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 933 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 934 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 935 "data//maps/RustboroCity/scripts.pory"

# 936 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 937 "data//maps/RustboroCity/scripts.pory"
	lockall
# 938 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 939 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 940 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 941 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 942 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 943 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 944 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 945 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 946 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 947 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 948 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 949 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 950 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 951 "data//maps/RustboroCity/scripts.pory"

# 952 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 953 "data//maps/RustboroCity/scripts.pory"
	lockall
# 954 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 955 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 956 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 957 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 958 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 959 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 960 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 961 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 962 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 963 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 964 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 965 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 966 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 967 "data//maps/RustboroCity/scripts.pory"

# 968 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 969 "data//maps/RustboroCity/scripts.pory"
	lockall
# 970 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 971 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 972 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 973 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 974 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 975 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 976 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 977 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 978 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 979 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 980 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 981 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 982 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 983 "data//maps/RustboroCity/scripts.pory"

# 984 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 985 "data//maps/RustboroCity/scripts.pory"
	lockall
# 986 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 987 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 988 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 989 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 990 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 991 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 992 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 993 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 994 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 995 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 996 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 997 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 998 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 999 "data//maps/RustboroCity/scripts.pory"

# 1000 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1001 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 1002 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1003 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1004 "data//maps/RustboroCity/scripts.pory"
	end
# 1005 "data//maps/RustboroCity/scripts.pory"

# 1006 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1007 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1008 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1009 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1010 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1011 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1012 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1013 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1014 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1015 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1016 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1017 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1018 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1019 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1020 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1021 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1022 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1023 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1024 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1025 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1026 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1027 "data//maps/RustboroCity/scripts.pory"
	end
# 1028 "data//maps/RustboroCity/scripts.pory"

# 1029 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1030 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1031 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1032 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1033 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1034 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1035 "data//maps/RustboroCity/scripts.pory"
	end
# 1036 "data//maps/RustboroCity/scripts.pory"

# 1037 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1038 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1039 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1040 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartMayBattle
# 1041 "data//maps/RustboroCity/scripts.pory"
	end
# 1042 "data//maps/RustboroCity/scripts.pory"

# 1043 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1044 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1045 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1046 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1047 "data//maps/RustboroCity/scripts.pory"
	end
# 1048 "data//maps/RustboroCity/scripts.pory"

# 1049 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1050 "data//maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1051 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1052 "data//maps/RustboroCity/scripts.pory"
	return
# 1053 "data//maps/RustboroCity/scripts.pory"

# 1054 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartMayBattle::
# 1055 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, RustboroCity_Text_MayDefeat
# 1056 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1057 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1058 "data//maps/RustboroCity/scripts.pory"
	end
# 1059 "data//maps/RustboroCity/scripts.pory"

# 1060 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1061 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1062 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1063 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1064 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1065 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1066 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1067 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1068 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1069 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1070 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1071 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1072 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1073 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1074 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1075 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1076 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1077 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1078 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1079 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1080 "data//maps/RustboroCity/scripts.pory"
	end
# 1081 "data//maps/RustboroCity/scripts.pory"

# 1082 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1083 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1084 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1085 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1086 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1087 "data//maps/RustboroCity/scripts.pory"
	end
# 1088 "data//maps/RustboroCity/scripts.pory"

# 1089 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1090 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1091 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1092 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartBrendanBattle
# 1093 "data//maps/RustboroCity/scripts.pory"
	end
# 1094 "data//maps/RustboroCity/scripts.pory"

# 1095 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1096 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1097 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1098 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1099 "data//maps/RustboroCity/scripts.pory"
	end
# 1100 "data//maps/RustboroCity/scripts.pory"

# 1101 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartBrendanBattle::
# 1102 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, RustboroCity_Text_BrendanDefeat
# 1103 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1104 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1105 "data//maps/RustboroCity/scripts.pory"
	end
# 1106 "data//maps/RustboroCity/scripts.pory"

# 1107 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1108 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1109 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1110 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1111 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1112 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1113 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1114 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1115 "data//maps/RustboroCity/scripts.pory"

# 1116 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1117 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1118 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1119 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1120 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1121 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1122 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1123 "data//maps/RustboroCity/scripts.pory"

# 1124 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1125 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1126 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1127 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1128 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1129 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1130 "data//maps/RustboroCity/scripts.pory"

# 1131 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1132 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1133 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1134 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1135 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1136 "data//maps/RustboroCity/scripts.pory"

# 1137 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1138 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1139 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1140 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1141 "data//maps/RustboroCity/scripts.pory"

# 1142 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1143 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1144 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1145 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1146 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1147 "data//maps/RustboroCity/scripts.pory"

# 1148 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1149 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1150 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1151 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1152 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1153 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1154 "data//maps/RustboroCity/scripts.pory"

# 1155 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1156 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1157 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1158 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1159 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1160 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1161 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1162 "data//maps/RustboroCity/scripts.pory"

# 1163 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1164 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1165 "data//maps/RustboroCity/scripts.pory"
	end
# 1166 "data//maps/RustboroCity/scripts.pory"

# 1167 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1168 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1169 "data//maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1170 "data//maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1171 "data//maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1172 "data//maps/RustboroCity/scripts.pory"

# 1173 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1174 "data//maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1175 "data//maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1176 "data//maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1177 "data//maps/RustboroCity/scripts.pory"

# 1178 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1179 "data//maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1180 "data//maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1181 "data//maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1182 "data//maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1183 "data//maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1184 "data//maps/RustboroCity/scripts.pory"

# 1185 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1186 "data//maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1187 "data//maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1188 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1189 "data//maps/RustboroCity/scripts.pory"

# 1190 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1191 "data//maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1192 "data//maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1193 "data//maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1194 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1195 "data//maps/RustboroCity/scripts.pory"

# 1196 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1197 "data//maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1198 "data//maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1199 "data//maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1200 "data//maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1201 "data//maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1202 "data//maps/RustboroCity/scripts.pory"

# 1203 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1204 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1205 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1206 "data//maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1207 "data//maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1208 "data//maps/RustboroCity/scripts.pory"

# 1209 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1210 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1211 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1212 "data//maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1213 "data//maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1214 "data//maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1215 "data//maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1216 "data//maps/RustboroCity/scripts.pory"

# 1217 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1218 "data//maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1219 "data//maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1220 "data//maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1221 "data//maps/RustboroCity/scripts.pory"

# 1222 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1223 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1224 "data//maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1225 "data//maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1226 "data//maps/RustboroCity/scripts.pory"

# 1227 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1228 "data//maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1229 "data//maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1230 "data//maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1231 "data//maps/RustboroCity/scripts.pory"

# 1232 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1233 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1234 "data//maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1235 "data//maps/RustboroCity/scripts.pory"

# 1236 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1237 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1238 "data//maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1239 "data//maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1240 "data//maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1241 "data//maps/RustboroCity/scripts.pory"

# 1242 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1243 "data//maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1244 "data//maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1245 "data//maps/RustboroCity/scripts.pory"

# 1246 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1247 "data//maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1248 "data//maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1249 "data//maps/RustboroCity/scripts.pory"

# 1250 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1251 "data//maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1252 "data//maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1253 "data//maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1254 "data//maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1255 "data//maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1256 "data//maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1257 "data//maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1258 "data//maps/RustboroCity/scripts.pory"

# 1259 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1260 "data//maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1261 "data//maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1262 "data//maps/RustboroCity/scripts.pory"

# 1263 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1264 "data//maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1265 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1266 "data//maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1267 "data//maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1268 "data//maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1269 "data//maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1270 "data//maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1271 "data//maps/RustboroCity/scripts.pory"

# 1272 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1273 "data//maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1274 "data//maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1275 "data//maps/RustboroCity/scripts.pory"

# 1276 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1277 "data//maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1278 "data//maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1279 "data//maps/RustboroCity/scripts.pory"

# 1280 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1281 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1282 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1283 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1284 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1285 "data//maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1286 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1287 "data//maps/RustboroCity/scripts.pory"

# 1288 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1289 "data//maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1290 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1291 "data//maps/RustboroCity/scripts.pory"

# 1292 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1293 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1294 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1295 "data//maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1296 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1297 "data//maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1298 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1299 "data//maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1300 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1301 "data//maps/RustboroCity/scripts.pory"

# 1302 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1303 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1304 "data//maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1305 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1306 "data//maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1307 "data//maps/RustboroCity/scripts.pory"

# 1308 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1309 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1310 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1311 "data//maps/RustboroCity/scripts.pory"

# 1312 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1313 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1314 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1315 "data//maps/RustboroCity/scripts.pory"

# 1316 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1317 "data//maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1318 "data//maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1319 "data//maps/RustboroCity/scripts.pory"

# 1320 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1321 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1322 "data//maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1323 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1324 "data//maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1325 "data//maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1326 "data//maps/RustboroCity/scripts.pory"

# 1327 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1328 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1329 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1330 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1331 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1332 "data//maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1333 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1334 "data//maps/RustboroCity/scripts.pory"

# 1335 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1336 "data//maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1337 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1338 "data//maps/RustboroCity/scripts.pory"

# 1339 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1340 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1341 "data//maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1342 "data//maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1343 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1344 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1345 "data//maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1346 "data//maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1347 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1348 "data//maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1349 "data//maps/RustboroCity/scripts.pory"

# 1350 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1351 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1352 "data//maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1353 "data//maps/RustboroCity/scripts.pory"

# 1354 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1355 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1356 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1357 "data//maps/RustboroCity/scripts.pory"

# 1358 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1359 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1360 "data//maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1361 "data//maps/RustboroCity/scripts.pory"

# 1362 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1363 "data//maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1364 "data//maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1365 "data//maps/RustboroCity/scripts.pory"

# 1366 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1367 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1368 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1369 "data//maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1370 "data//maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1371 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1372 "data//maps/RustboroCity/scripts.pory"

# 1373 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1374 "data//maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1375 "data//maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1376 "data//maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1377 "data//maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1378 "data//maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1379 "data//maps/RustboroCity/scripts.pory"

# 1380 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1381 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1382 "data//maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1383 "data//maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1384 "data//maps/RustboroCity/scripts.pory"

# 1385 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1386 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1387 "data//maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1388 "data//maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1389 "data//maps/RustboroCity/scripts.pory"

# 1390 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1391 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1392 "data//maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1393 "data//maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1394 "data//maps/RustboroCity/scripts.pory"

# 1395 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1396 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1397 "data//maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1398 "data//maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1399 "data//maps/RustboroCity/scripts.pory"

# 1400 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1401 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1402 "data//maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1403 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1404 "data//maps/RustboroCity/scripts.pory"

# 1405 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1406 "data//maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1407 "data//maps/RustboroCity/scripts.pory"

# 1408 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1409 "data//maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1410 "data//maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1411 "data//maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1412 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1413 "data//maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1414 "data//maps/RustboroCity/scripts.pory"

# 1415 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1416 "data//maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1417 "data//maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1418 "data//maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1419 "data//maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1420 "data//maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1421 "data//maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1422 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1423 "data//maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1424 "data//maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1425 "data//maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1426 "data//maps/RustboroCity/scripts.pory"

# 1427 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1428 "data//maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1429 "data//maps/RustboroCity/scripts.pory"

# 1430 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1431 "data//maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1432 "data//maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1433 "data//maps/RustboroCity/scripts.pory"

# 1434 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1435 "data//maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1436 "data//maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1437 "data//maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1438 "data//maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1439 "data//maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1440 "data//maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1441 "data//maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1442 "data//maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_ReturningFromShadyTruck_Text_0:
# 47 "data//maps/RustboroCity/scripts.pory"
	.string "ZAZAZAAAAAAM!!$"

RustboroCity_EventScript_ReturningFromShadyTruck_Text_1:
# 72 "data//maps/RustboroCity/scripts.pory"
	.string "The truck drove off…$"

RustboroCity_EventScript_ExamineShadyTruck_Text_0:
# 107 "data//maps/RustboroCity/scripts.pory"
	.string "It's a big beat-up truck with no plates\n"
	.string "or logos.\p"
	.string "It must have been difficult to park\n"
	.string "here.$"

RustboroCity_EventScript_ShadyAlakazam_Text_0:
# 120 "data//maps/RustboroCity/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

RustboroCity_EventScript_ShadyAlakazam_Text_1:
# 125 "data//maps/RustboroCity/scripts.pory"
	.string "ALAKAZAM is beckoning you towards the\n"
	.string "truck doors.$"

RustboroCity_EventScript_ShadyAlakazam_Text_2:
# 128 "data//maps/RustboroCity/scripts.pory"
	.string "This shady-looking ALAKAZAM is asking\n"
	.string "if you want to enter the truck.\p"
	.string "Do you trust ALAKAZAM enough to get\n"
	.string "into the sketchy truck?$"
