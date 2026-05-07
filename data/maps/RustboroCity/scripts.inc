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
	goto_if_set FLAG_SHOW_SHADY_TRUCK, RustboroCity_OnTransition_3
RustboroCity_OnTransition_1:
# 18 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 19 "data//maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 20 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 21 "data//maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 22 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	return

RustboroCity_OnTransition_2:
# 16 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_TEMP_1E
	goto RustboroCity_OnTransition_1

RustboroCity_OnTransition_3:
# 15 "data//maps/RustboroCity/scripts.pory"
	compare VAR_SHADY_TRUCK_LOCATION, 0
	goto_if_eq RustboroCity_OnTransition_2
	goto RustboroCity_OnTransition_1


RustboroCity_OnResume::
# 26 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, RustboroCity_OnResume_1
# 30 "data//maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 31 "data//maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_E, 5
	goto_if_eq RustboroCity_OnResume_5
	return

RustboroCity_OnResume_1:
# 27 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_TEMP_1F
	return

RustboroCity_OnResume_4:
# 32 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_TEMP_1E
# 33 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_TEMP_1F
# 34 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
	return

RustboroCity_OnResume_5:
# 31 "data//maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_F, 42
	goto_if_eq RustboroCity_OnResume_4
	return


RustboroCity_EventScript_ReturningFromShadyTruck::
# 40 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, RustboroCity_EventScript_ReturningFromShadyTruck_2
RustboroCity_EventScript_ReturningFromShadyTruck_1:
# 83 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_F, 0
# 84 "data//maps/RustboroCity/scripts.pory"
	release
	return

RustboroCity_EventScript_ReturningFromShadyTruck_2:
# 41 "data//maps/RustboroCity/scripts.pory"
	setobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY, 0
# 42 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 43 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_JumpOutOfTruck
# 44 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 45 "data//maps/RustboroCity/scripts.pory"
	goto_if_unset FLAG_SHOW_SHADY_TRUCK, RustboroCity_EventScript_ReturningFromShadyTruck_5
RustboroCity_EventScript_ReturningFromShadyTruck_4:
# 81 "data//maps/RustboroCity/scripts.pory"
	resetobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY
	goto RustboroCity_EventScript_ReturningFromShadyTruck_1

RustboroCity_EventScript_ReturningFromShadyTruck_5:
# 46 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_MoveAwayFromTruck
# 47 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 48 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceFasterDown
# 49 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 50 "data//maps/RustboroCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
# 51 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_0
# 52 "data//maps/RustboroCity/scripts.pory"
	waitmoncry
# 53 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 54 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 55 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, RustboroCity_Movement_AlakazamEnterTruck
# 56 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 57 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 58 "data//maps/RustboroCity/scripts.pory"
	waitmovement LOCALID_RUSTBORO_SHADY_ALAKAZAM
# 59 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 60 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 61 "data//maps/RustboroCity/scripts.pory"
	waitse
# 62 "data//maps/RustboroCity/scripts.pory"
	delay 15
# 63 "data//maps/RustboroCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 64 "data//maps/RustboroCity/scripts.pory"
	delay 60
# 65 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_MOVE
# 66 "data//maps/RustboroCity/scripts.pory"
	delay 120
# 67 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_STOP
# 68 "data//maps/RustboroCity/scripts.pory"
	waitse
# 69 "data//maps/RustboroCity/scripts.pory"
	delay 45
# 70 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SHADY_TRUCK
# 71 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SHADY_ALAKAZAM
# 72 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_TRUCK_COLLISION_A
# 73 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_TRUCK_COLLISION_B
# 74 "data//maps/RustboroCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 75 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 76 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_1
# 77 "data//maps/RustboroCity/scripts.pory"
	waitmessage
# 78 "data//maps/RustboroCity/scripts.pory"
	delay 90
# 79 "data//maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_ReturningFromShadyTruck_4


# 87 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_JumpOutOfTruck:
# 88 "data//maps/RustboroCity/scripts.pory"
	set_visible
# 89 "data//maps/RustboroCity/scripts.pory"
	jump_right
# 90 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 91 "data//maps/RustboroCity/scripts.pory"
	step_end

# 94 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_MoveAwayFromTruck:
# 95 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 96 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 97 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 98 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 99 "data//maps/RustboroCity/scripts.pory"
	step_end

# 102 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_AlakazamEnterTruck:
# 103 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 104 "data//maps/RustboroCity/scripts.pory"
	delay_8
# 105 "data//maps/RustboroCity/scripts.pory"
	jump_left
# 106 "data//maps/RustboroCity/scripts.pory"
	set_invisible
# 107 "data//maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_ExamineShadyTruck::
# 111 "data//maps/RustboroCity/scripts.pory"
	lock
# 112 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ExamineShadyTruck_Text_0, MSGBOX_DEFAULT
# 114 "data//maps/RustboroCity/scripts.pory"
	release
	return


RustboroCity_EventScript_ShadyAlakazam::
# 118 "data//maps/RustboroCity/scripts.pory"
	lock
# 119 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 120 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 121 "data//maps/RustboroCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_HIGH_PITCH
# 122 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ReturningFromShadyTruck_Text_0
# 123 "data//maps/RustboroCity/scripts.pory"
	waitmoncry
# 124 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 125 "data//maps/RustboroCity/scripts.pory"
	message RustboroCity_EventScript_ShadyAlakazam_Text_0
# 126 "data//maps/RustboroCity/scripts.pory"
	waitmessage
# 127 "data//maps/RustboroCity/scripts.pory"
	delay 40
# 128 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 129 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq RustboroCity_EventScript_ShadyAlakazam_2
# 133 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ShadyAlakazam_Text_2, MSGBOX_YESNO
# 135 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 136 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_ShadyAlakazam_5
RustboroCity_EventScript_ShadyAlakazam_1:
# 140 "data//maps/RustboroCity/scripts.pory"
	release
	return

RustboroCity_EventScript_ShadyAlakazam_2:
# 130 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_ShadyAlakazam_Text_1, MSGBOX_DEFAULT
	goto RustboroCity_EventScript_ShadyAlakazam_1

RustboroCity_EventScript_ShadyAlakazam_5:
# 137 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EnterShadyTruck
	goto RustboroCity_EventScript_ShadyAlakazam_1


RustboroCity_EventScript_TruckEntrance::
# 144 "data//maps/RustboroCity/scripts.pory"
	goto_if_unset FLAG_TEMP_1E, RustboroCity_EventScript_TruckEntrance_1
	return

RustboroCity_EventScript_TruckEntrance_1:
# 145 "data//maps/RustboroCity/scripts.pory"
	lock
# 146 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 147 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 148 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 149 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 150 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne RustboroCity_EventScript_TruckEntrance_4
RustboroCity_EventScript_TruckEntrance_3:
# 154 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ShadyAlakazam
	return

RustboroCity_EventScript_TruckEntrance_4:
# 151 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 152 "data//maps/RustboroCity/scripts.pory"
	waitmovement
	goto RustboroCity_EventScript_TruckEntrance_3


RustboroCity_EventScript_EnterShadyTruck::
# 159 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 160 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceDown
# 161 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 162 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 163 "data//maps/RustboroCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 164 "data//maps/RustboroCity/scripts.pory"
	waitse
# 165 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 166 "data//maps/RustboroCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 167 "data//maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne RustboroCity_EventScript_EnterShadyTruck_2
RustboroCity_EventScript_EnterShadyTruck_1:
# 171 "data//maps/RustboroCity/scripts.pory"
	setobjectsubpriority LOCALID_RUSTBORO_SHADY_TRUCK, MAP_RUSTBORO_CITY, 0
# 172 "data//maps/RustboroCity/scripts.pory"
	hidefollower
# 173 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerEnterTruck
# 174 "data//maps/RustboroCity/scripts.pory"
	delay 32
# 175 "data//maps/RustboroCity/scripts.pory"
	playse SE_BIKE_HOP
# 176 "data//maps/RustboroCity/scripts.pory"
	waitmovement
# 177 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 178 "data//maps/RustboroCity/scripts.pory"
	waitse
# 179 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 180 "data//maps/RustboroCity/scripts.pory"
	warpcontinuescript MAP_SHADY_GUYS_TRUCK, 5, 2, ShadyGuysTruck_EventScript_PlayerEntersTruck
	return

RustboroCity_EventScript_EnterShadyTruck_2:
# 168 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 169 "data//maps/RustboroCity/scripts.pory"
	waitmovement
	goto RustboroCity_EventScript_EnterShadyTruck_1


# 183 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerEnterTruck:
# 184 "data//maps/RustboroCity/scripts.pory"
	face_left
# 185 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 186 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 187 "data//maps/RustboroCity/scripts.pory"
	jump_left
# 188 "data//maps/RustboroCity/scripts.pory"
	set_invisible
# 189 "data//maps/RustboroCity/scripts.pory"
	step_end

# 192 "data//maps/RustboroCity/scripts.pory"

# 193 "data//maps/RustboroCity/scripts.pory"

# 194 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 195 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_E, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 196 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
# 197 "data//maps/RustboroCity/scripts.pory"
	end
# 198 "data//maps/RustboroCity/scripts.pory"

# 199 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 200 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
# 201 "data//maps/RustboroCity/scripts.pory"
	end
# 202 "data//maps/RustboroCity/scripts.pory"

# 203 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 204 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 205 "data//maps/RustboroCity/scripts.pory"
	return
# 206 "data//maps/RustboroCity/scripts.pory"

# 207 "data//maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 208 "data//maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 209 "data//maps/RustboroCity/scripts.pory"
	map_script_2 VAR_TEMP_F, 42, RustboroCity_EventScript_ReturningFromShadyTruck
# 210 "data//maps/RustboroCity/scripts.pory"
	.2byte 0
# 211 "data//maps/RustboroCity/scripts.pory"

# 212 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 213 "data//maps/RustboroCity/scripts.pory"
	lockall
# 214 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 215 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 216 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 217 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 218 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 219 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_SCIENTIST
# 220 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 221 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 222 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 223 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
# 224 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 225 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
# 226 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 227 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 228 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 229 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 230 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 231 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 232 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 233 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 234 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 235 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 236 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 237 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 238 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 239 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 240 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 241 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 242 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 243 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 244 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 245 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 246 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 247 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 248 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 249 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 250 "data//maps/RustboroCity/scripts.pory"

# 251 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 252 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 253 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 254 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 255 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 256 "data//maps/RustboroCity/scripts.pory"

# 257 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 258 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 259 "data//maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 260 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 261 "data//maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 262 "data//maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 263 "data//maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 264 "data//maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 265 "data//maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 266 "data//maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 267 "data//maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 268 "data//maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 269 "data//maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 270 "data//maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 271 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 272 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 273 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 274 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 275 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 276 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 277 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 278 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 279 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 280 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 281 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 282 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 283 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 284 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 285 "data//maps/RustboroCity/scripts.pory"
	end
# 286 "data//maps/RustboroCity/scripts.pory"

# 287 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 288 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 289 "data//maps/RustboroCity/scripts.pory"
	step_end
# 290 "data//maps/RustboroCity/scripts.pory"

# 291 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 292 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 293 "data//maps/RustboroCity/scripts.pory"
	step_end
# 294 "data//maps/RustboroCity/scripts.pory"

# 295 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 296 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 297 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 298 "data//maps/RustboroCity/scripts.pory"
	step_end
# 299 "data//maps/RustboroCity/scripts.pory"

# 300 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 301 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 302 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 303 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 304 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 305 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 306 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 307 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 308 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 309 "data//maps/RustboroCity/scripts.pory"
	step_end
# 310 "data//maps/RustboroCity/scripts.pory"

# 311 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 312 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 313 "data//maps/RustboroCity/scripts.pory"
	step_end
# 314 "data//maps/RustboroCity/scripts.pory"

# 315 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 316 "data//maps/RustboroCity/scripts.pory"
	lock
# 317 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 318 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 319 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 320 "data//maps/RustboroCity/scripts.pory"
	release
# 321 "data//maps/RustboroCity/scripts.pory"
	end
# 322 "data//maps/RustboroCity/scripts.pory"

# 323 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 324 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 325 "data//maps/RustboroCity/scripts.pory"
	release
# 326 "data//maps/RustboroCity/scripts.pory"
	end
# 327 "data//maps/RustboroCity/scripts.pory"

# 328 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 329 "data//maps/RustboroCity/scripts.pory"
	lock
# 330 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 331 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 332 "data//maps/RustboroCity/scripts.pory"
	release
# 333 "data//maps/RustboroCity/scripts.pory"
	end
# 334 "data//maps/RustboroCity/scripts.pory"

# 335 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 336 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 337 "data//maps/RustboroCity/scripts.pory"
	end
# 338 "data//maps/RustboroCity/scripts.pory"

# 339 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 340 "data//maps/RustboroCity/scripts.pory"
	lock
# 341 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 342 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 343 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 344 "data//maps/RustboroCity/scripts.pory"
	release
# 345 "data//maps/RustboroCity/scripts.pory"
	end
# 346 "data//maps/RustboroCity/scripts.pory"

# 347 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 348 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 349 "data//maps/RustboroCity/scripts.pory"
	release
# 350 "data//maps/RustboroCity/scripts.pory"
	end
# 351 "data//maps/RustboroCity/scripts.pory"

# 352 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 353 "data//maps/RustboroCity/scripts.pory"
	lock
# 354 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 355 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 356 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 357 "data//maps/RustboroCity/scripts.pory"
	release
# 358 "data//maps/RustboroCity/scripts.pory"
	end
# 359 "data//maps/RustboroCity/scripts.pory"

# 360 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 361 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 362 "data//maps/RustboroCity/scripts.pory"
	release
# 363 "data//maps/RustboroCity/scripts.pory"
	end
# 364 "data//maps/RustboroCity/scripts.pory"

# 365 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 366 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 367 "data//maps/RustboroCity/scripts.pory"
	end
# 368 "data//maps/RustboroCity/scripts.pory"

# 369 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 370 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 371 "data//maps/RustboroCity/scripts.pory"
	end
# 372 "data//maps/RustboroCity/scripts.pory"

# 373 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 374 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 375 "data//maps/RustboroCity/scripts.pory"
	end
# 376 "data//maps/RustboroCity/scripts.pory"

# 377 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 378 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 379 "data//maps/RustboroCity/scripts.pory"
	end
# 380 "data//maps/RustboroCity/scripts.pory"

# 381 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 382 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 383 "data//maps/RustboroCity/scripts.pory"
	end
# 384 "data//maps/RustboroCity/scripts.pory"

# 385 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 386 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 387 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 388 "data//maps/RustboroCity/scripts.pory"
	end
# 389 "data//maps/RustboroCity/scripts.pory"

# 390 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 391 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 392 "data//maps/RustboroCity/scripts.pory"
	end
# 393 "data//maps/RustboroCity/scripts.pory"

# 394 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 395 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 396 "data//maps/RustboroCity/scripts.pory"
	end
# 397 "data//maps/RustboroCity/scripts.pory"

# 398 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 399 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 400 "data//maps/RustboroCity/scripts.pory"
	end
# 401 "data//maps/RustboroCity/scripts.pory"

# 402 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 403 "data//maps/RustboroCity/scripts.pory"
	lock
# 404 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 405 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 406 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 407 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 408 "data//maps/RustboroCity/scripts.pory"
	release
# 409 "data//maps/RustboroCity/scripts.pory"
	end
# 410 "data//maps/RustboroCity/scripts.pory"

# 411 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 412 "data//maps/RustboroCity/scripts.pory"
	lock
# 413 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 414 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 415 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 416 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 417 "data//maps/RustboroCity/scripts.pory"
	release
# 418 "data//maps/RustboroCity/scripts.pory"
	end
# 419 "data//maps/RustboroCity/scripts.pory"

# 420 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 421 "data//maps/RustboroCity/scripts.pory"
	lock
# 422 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 423 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 424 "data//maps/RustboroCity/scripts.pory"
	release
# 425 "data//maps/RustboroCity/scripts.pory"
	end
# 426 "data//maps/RustboroCity/scripts.pory"

# 427 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 428 "data//maps/RustboroCity/scripts.pory"
	lockall
# 429 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 430 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 431 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 432 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 433 "data//maps/RustboroCity/scripts.pory"
	end
# 434 "data//maps/RustboroCity/scripts.pory"

# 435 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 436 "data//maps/RustboroCity/scripts.pory"
	lockall
# 437 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 438 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 439 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 440 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 441 "data//maps/RustboroCity/scripts.pory"
	end
# 442 "data//maps/RustboroCity/scripts.pory"

# 443 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 444 "data//maps/RustboroCity/scripts.pory"
	lockall
# 445 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 446 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 447 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 448 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 449 "data//maps/RustboroCity/scripts.pory"
	end
# 450 "data//maps/RustboroCity/scripts.pory"

# 451 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 452 "data//maps/RustboroCity/scripts.pory"
	lockall
# 453 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 454 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 455 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 456 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 457 "data//maps/RustboroCity/scripts.pory"
	end
# 458 "data//maps/RustboroCity/scripts.pory"

# 459 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 460 "data//maps/RustboroCity/scripts.pory"
	lockall
# 461 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 462 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 463 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 464 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 465 "data//maps/RustboroCity/scripts.pory"
	end
# 466 "data//maps/RustboroCity/scripts.pory"

# 467 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 468 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 469 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 470 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 471 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 472 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 473 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 474 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 475 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 476 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 477 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 478 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 479 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 480 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 481 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 482 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 483 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 484 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 485 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 486 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 487 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 488 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 489 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 490 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 491 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 492 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 493 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 494 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 495 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 496 "data//maps/RustboroCity/scripts.pory"
	end
# 497 "data//maps/RustboroCity/scripts.pory"

# 498 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 499 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 500 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 501 "data//maps/RustboroCity/scripts.pory"
	return
# 502 "data//maps/RustboroCity/scripts.pory"

# 503 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 504 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 505 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 506 "data//maps/RustboroCity/scripts.pory"
	return
# 507 "data//maps/RustboroCity/scripts.pory"

# 508 "data//maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 509 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 510 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 511 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 512 "data//maps/RustboroCity/scripts.pory"
	return
# 513 "data//maps/RustboroCity/scripts.pory"

# 514 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 515 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 516 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 517 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 518 "data//maps/RustboroCity/scripts.pory"
	return
# 519 "data//maps/RustboroCity/scripts.pory"

# 520 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 521 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 522 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 523 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 524 "data//maps/RustboroCity/scripts.pory"
	return
# 525 "data//maps/RustboroCity/scripts.pory"

# 526 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 527 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 528 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 529 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 530 "data//maps/RustboroCity/scripts.pory"
	return
# 531 "data//maps/RustboroCity/scripts.pory"

# 532 "data//maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 533 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 534 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 535 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 536 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 537 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 538 "data//maps/RustboroCity/scripts.pory"
	return
# 539 "data//maps/RustboroCity/scripts.pory"

# 540 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 541 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 542 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 543 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 544 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 545 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 546 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 547 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 555 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 556 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 557 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 558 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 559 "data//maps/RustboroCity/scripts.pory"
	step_end
# 560 "data//maps/RustboroCity/scripts.pory"

# 561 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 562 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 563 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 564 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 565 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 566 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 567 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 568 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 569 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 570 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 571 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 572 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 573 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 574 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 575 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 576 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 577 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 578 "data//maps/RustboroCity/scripts.pory"
	step_end
# 579 "data//maps/RustboroCity/scripts.pory"

# 580 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 581 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 582 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 583 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 584 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 585 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 586 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 587 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 588 "data//maps/RustboroCity/scripts.pory"
	step_end
# 589 "data//maps/RustboroCity/scripts.pory"

# 590 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 591 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 592 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 593 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 594 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 595 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 596 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 597 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 598 "data//maps/RustboroCity/scripts.pory"
	step_end
# 599 "data//maps/RustboroCity/scripts.pory"

# 600 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 601 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 602 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 603 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 604 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 605 "data//maps/RustboroCity/scripts.pory"
	step_end
# 606 "data//maps/RustboroCity/scripts.pory"

# 607 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 608 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 609 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 610 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 611 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 612 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 613 "data//maps/RustboroCity/scripts.pory"
	step_end
# 614 "data//maps/RustboroCity/scripts.pory"

# 615 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 616 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 617 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 618 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 619 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 620 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 621 "data//maps/RustboroCity/scripts.pory"
	step_end
# 622 "data//maps/RustboroCity/scripts.pory"

# 623 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 624 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 625 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 626 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 627 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 628 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 629 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 630 "data//maps/RustboroCity/scripts.pory"
	step_end
# 631 "data//maps/RustboroCity/scripts.pory"

# 632 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 633 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 634 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 635 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 636 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 637 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 638 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 639 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 640 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 641 "data//maps/RustboroCity/scripts.pory"
	step_end
# 642 "data//maps/RustboroCity/scripts.pory"

# 643 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 644 "data//maps/RustboroCity/scripts.pory"
	lock
# 645 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 646 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 647 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 648 "data//maps/RustboroCity/scripts.pory"
	release
# 649 "data//maps/RustboroCity/scripts.pory"
	end
# 650 "data//maps/RustboroCity/scripts.pory"

# 651 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 652 "data//maps/RustboroCity/scripts.pory"
	waitse
# 653 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 654 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 655 "data//maps/RustboroCity/scripts.pory"
	end
# 656 "data//maps/RustboroCity/scripts.pory"

# 657 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 658 "data//maps/RustboroCity/scripts.pory"
	lockall
# 659 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 660 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 661 "data//maps/RustboroCity/scripts.pory"
	end
# 662 "data//maps/RustboroCity/scripts.pory"

# 663 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 664 "data//maps/RustboroCity/scripts.pory"
	lockall
# 665 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 666 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 667 "data//maps/RustboroCity/scripts.pory"
	end
# 668 "data//maps/RustboroCity/scripts.pory"

# 669 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 670 "data//maps/RustboroCity/scripts.pory"
	lockall
# 671 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 672 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 673 "data//maps/RustboroCity/scripts.pory"
	end
# 674 "data//maps/RustboroCity/scripts.pory"

# 675 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 676 "data//maps/RustboroCity/scripts.pory"
	lockall
# 677 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 678 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 679 "data//maps/RustboroCity/scripts.pory"
	end
# 680 "data//maps/RustboroCity/scripts.pory"

# 681 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 682 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 683 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 684 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 685 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 686 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 687 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 688 "data//maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 689 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 690 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 691 "data//maps/RustboroCity/scripts.pory"
	end
# 692 "data//maps/RustboroCity/scripts.pory"

# 693 "data//maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 694 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 695 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 696 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 697 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 698 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 699 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 700 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 701 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 702 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 703 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 704 "data//maps/RustboroCity/scripts.pory"
	return
# 705 "data//maps/RustboroCity/scripts.pory"

# 706 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 707 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 708 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 710 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 711 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 712 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 713 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 714 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 715 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 716 "data//maps/RustboroCity/scripts.pory"
	return
# 717 "data//maps/RustboroCity/scripts.pory"

# 718 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 719 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 720 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 721 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 722 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 723 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 724 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 725 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 726 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 727 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 728 "data//maps/RustboroCity/scripts.pory"
	return
# 729 "data//maps/RustboroCity/scripts.pory"

# 730 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 731 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 732 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 733 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 734 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 735 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 736 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 737 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 738 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 739 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 740 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 741 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 742 "data//maps/RustboroCity/scripts.pory"
	return
# 743 "data//maps/RustboroCity/scripts.pory"

# 744 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 745 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 746 "data//maps/RustboroCity/scripts.pory"
	step_end
# 747 "data//maps/RustboroCity/scripts.pory"

# 748 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 749 "data//maps/RustboroCity/scripts.pory"
	lockall
# 750 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 751 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 752 "data//maps/RustboroCity/scripts.pory"
	end
# 753 "data//maps/RustboroCity/scripts.pory"

# 754 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 755 "data//maps/RustboroCity/scripts.pory"
	lockall
# 756 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 757 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 758 "data//maps/RustboroCity/scripts.pory"
	end
# 759 "data//maps/RustboroCity/scripts.pory"

# 760 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 761 "data//maps/RustboroCity/scripts.pory"
	lockall
# 762 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 763 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 764 "data//maps/RustboroCity/scripts.pory"
	end
# 765 "data//maps/RustboroCity/scripts.pory"

# 766 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 767 "data//maps/RustboroCity/scripts.pory"
	lockall
# 768 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 769 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 770 "data//maps/RustboroCity/scripts.pory"
	end
# 771 "data//maps/RustboroCity/scripts.pory"

# 772 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 773 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 774 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 775 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 776 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 777 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 778 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 779 "data//maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 780 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 781 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 782 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 783 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 784 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 785 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 786 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 787 "data//maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 788 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 789 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 790 "data//maps/RustboroCity/scripts.pory"
	end
# 791 "data//maps/RustboroCity/scripts.pory"

# 792 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 793 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 794 "data//maps/RustboroCity/scripts.pory"
	return
# 795 "data//maps/RustboroCity/scripts.pory"

# 796 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 797 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 798 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 799 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 800 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 801 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 802 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 803 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 804 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 805 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 806 "data//maps/RustboroCity/scripts.pory"
	return
# 807 "data//maps/RustboroCity/scripts.pory"

# 808 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 809 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 810 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 811 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 812 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 813 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 814 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 815 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 816 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 817 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 818 "data//maps/RustboroCity/scripts.pory"
	return
# 819 "data//maps/RustboroCity/scripts.pory"

# 820 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 821 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 822 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 823 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 824 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 825 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 826 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 827 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 828 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 829 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 830 "data//maps/RustboroCity/scripts.pory"
	return
# 831 "data//maps/RustboroCity/scripts.pory"

# 832 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 833 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 834 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 835 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 836 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 837 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 838 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 839 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 840 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 841 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 842 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 843 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 844 "data//maps/RustboroCity/scripts.pory"
	return
# 845 "data//maps/RustboroCity/scripts.pory"

# 846 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 847 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 848 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 849 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 850 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 851 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 852 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 853 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 854 "data//maps/RustboroCity/scripts.pory"
	return
# 855 "data//maps/RustboroCity/scripts.pory"

# 856 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 857 "data//maps/RustboroCity/scripts.pory"
	lockall
# 858 "data//maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 859 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 860 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 861 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 862 "data//maps/RustboroCity/scripts.pory"

# 863 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 864 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 865 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 866 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 867 "data//maps/RustboroCity/scripts.pory"
	return
# 868 "data//maps/RustboroCity/scripts.pory"

# 869 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 870 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 871 "data//maps/RustboroCity/scripts.pory"
	return
# 872 "data//maps/RustboroCity/scripts.pory"

# 873 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 874 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 875 "data//maps/RustboroCity/scripts.pory"
	return
# 876 "data//maps/RustboroCity/scripts.pory"

# 877 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 878 "data//maps/RustboroCity/scripts.pory"
	lockall
# 879 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 880 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 881 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 882 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 883 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 884 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 885 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 886 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 887 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 888 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 889 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 890 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 891 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 892 "data//maps/RustboroCity/scripts.pory"

# 893 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 894 "data//maps/RustboroCity/scripts.pory"
	lockall
# 895 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 896 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 897 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 898 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 899 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 900 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 901 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 902 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 903 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 904 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 905 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 906 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 907 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 908 "data//maps/RustboroCity/scripts.pory"

# 909 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 910 "data//maps/RustboroCity/scripts.pory"
	lockall
# 911 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 912 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 913 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 914 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 915 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 916 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 917 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 918 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 919 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 920 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 921 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 922 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 923 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 924 "data//maps/RustboroCity/scripts.pory"

# 925 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 926 "data//maps/RustboroCity/scripts.pory"
	lockall
# 927 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 928 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 929 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 930 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 931 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 932 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 933 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 934 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 935 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 936 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 937 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 938 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 939 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 940 "data//maps/RustboroCity/scripts.pory"

# 941 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 942 "data//maps/RustboroCity/scripts.pory"
	lockall
# 943 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 944 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 945 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 946 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 947 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 948 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 949 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 950 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 951 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 952 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 953 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 954 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 955 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 956 "data//maps/RustboroCity/scripts.pory"

# 957 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 958 "data//maps/RustboroCity/scripts.pory"
	lockall
# 959 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 960 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 961 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 962 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 963 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 964 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 965 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 966 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 967 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 968 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 969 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 970 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 971 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 972 "data//maps/RustboroCity/scripts.pory"

# 973 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 974 "data//maps/RustboroCity/scripts.pory"
	lockall
# 975 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 976 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 977 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 978 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 979 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 980 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 981 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 982 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 983 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 984 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 985 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 986 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 987 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 988 "data//maps/RustboroCity/scripts.pory"

# 989 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 990 "data//maps/RustboroCity/scripts.pory"
	lockall
# 991 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 992 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 993 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 994 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 995 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 996 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 997 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 998 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 999 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 1000 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1001 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1002 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1003 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1004 "data//maps/RustboroCity/scripts.pory"

# 1005 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1006 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 1007 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1008 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1009 "data//maps/RustboroCity/scripts.pory"
	end
# 1010 "data//maps/RustboroCity/scripts.pory"

# 1011 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1012 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1013 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1014 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1015 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1016 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1017 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1018 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1019 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1020 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1021 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1022 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1023 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1024 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1025 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1026 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1027 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1028 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1029 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1030 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1031 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1032 "data//maps/RustboroCity/scripts.pory"
	end
# 1033 "data//maps/RustboroCity/scripts.pory"

# 1034 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1035 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1036 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1037 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1038 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1039 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1040 "data//maps/RustboroCity/scripts.pory"
	end
# 1041 "data//maps/RustboroCity/scripts.pory"

# 1042 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1043 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1044 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1045 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartMayBattle
# 1046 "data//maps/RustboroCity/scripts.pory"
	end
# 1047 "data//maps/RustboroCity/scripts.pory"

# 1048 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1049 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1050 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1051 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1052 "data//maps/RustboroCity/scripts.pory"
	end
# 1053 "data//maps/RustboroCity/scripts.pory"

# 1054 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1055 "data//maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1056 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1057 "data//maps/RustboroCity/scripts.pory"
	return
# 1058 "data//maps/RustboroCity/scripts.pory"

# 1059 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartMayBattle::
# 1060 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, RustboroCity_Text_MayDefeat
# 1061 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1062 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1063 "data//maps/RustboroCity/scripts.pory"
	end
# 1064 "data//maps/RustboroCity/scripts.pory"

# 1065 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1066 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1067 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1068 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1069 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1070 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1071 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1072 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1073 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1074 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1075 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1076 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1077 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1078 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1079 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1080 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1081 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1082 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1083 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1084 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1085 "data//maps/RustboroCity/scripts.pory"
	end
# 1086 "data//maps/RustboroCity/scripts.pory"

# 1087 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1088 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1089 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1090 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1091 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1092 "data//maps/RustboroCity/scripts.pory"
	end
# 1093 "data//maps/RustboroCity/scripts.pory"

# 1094 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1095 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1096 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1097 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartBrendanBattle
# 1098 "data//maps/RustboroCity/scripts.pory"
	end
# 1099 "data//maps/RustboroCity/scripts.pory"

# 1100 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1101 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1102 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1103 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1104 "data//maps/RustboroCity/scripts.pory"
	end
# 1105 "data//maps/RustboroCity/scripts.pory"

# 1106 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartBrendanBattle::
# 1107 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, RustboroCity_Text_BrendanDefeat
# 1108 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1109 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1110 "data//maps/RustboroCity/scripts.pory"
	end
# 1111 "data//maps/RustboroCity/scripts.pory"

# 1112 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1113 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1114 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1115 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1116 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1117 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1118 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1119 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1120 "data//maps/RustboroCity/scripts.pory"

# 1121 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1122 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1123 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1124 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1125 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1126 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1127 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1128 "data//maps/RustboroCity/scripts.pory"

# 1129 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1130 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1131 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1132 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1133 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1134 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1135 "data//maps/RustboroCity/scripts.pory"

# 1136 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1137 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1138 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1139 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1140 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1141 "data//maps/RustboroCity/scripts.pory"

# 1142 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1143 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1144 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1145 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1146 "data//maps/RustboroCity/scripts.pory"

# 1147 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1148 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1149 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1150 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1151 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1152 "data//maps/RustboroCity/scripts.pory"

# 1153 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1154 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1155 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1156 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1157 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1158 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1159 "data//maps/RustboroCity/scripts.pory"

# 1160 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1161 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1162 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1163 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1164 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1165 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1166 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1167 "data//maps/RustboroCity/scripts.pory"

# 1168 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1169 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1170 "data//maps/RustboroCity/scripts.pory"
	end
# 1171 "data//maps/RustboroCity/scripts.pory"

# 1172 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1173 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1174 "data//maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1175 "data//maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1176 "data//maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1177 "data//maps/RustboroCity/scripts.pory"

# 1178 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1179 "data//maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1180 "data//maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1181 "data//maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1182 "data//maps/RustboroCity/scripts.pory"

# 1183 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1184 "data//maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1185 "data//maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1186 "data//maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1187 "data//maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1188 "data//maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1189 "data//maps/RustboroCity/scripts.pory"

# 1190 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1191 "data//maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1192 "data//maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1193 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1194 "data//maps/RustboroCity/scripts.pory"

# 1195 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1196 "data//maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1197 "data//maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1198 "data//maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1199 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1200 "data//maps/RustboroCity/scripts.pory"

# 1201 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1202 "data//maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1203 "data//maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1204 "data//maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1205 "data//maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1206 "data//maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1207 "data//maps/RustboroCity/scripts.pory"

# 1208 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1209 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1210 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1211 "data//maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1212 "data//maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1213 "data//maps/RustboroCity/scripts.pory"

# 1214 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1215 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1216 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1217 "data//maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1218 "data//maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1219 "data//maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1220 "data//maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1221 "data//maps/RustboroCity/scripts.pory"

# 1222 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1223 "data//maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1224 "data//maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1225 "data//maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1226 "data//maps/RustboroCity/scripts.pory"

# 1227 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1228 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1229 "data//maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1230 "data//maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1231 "data//maps/RustboroCity/scripts.pory"

# 1232 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1233 "data//maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1234 "data//maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1235 "data//maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1236 "data//maps/RustboroCity/scripts.pory"

# 1237 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1238 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1239 "data//maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1240 "data//maps/RustboroCity/scripts.pory"

# 1241 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1242 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1243 "data//maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1244 "data//maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1245 "data//maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1246 "data//maps/RustboroCity/scripts.pory"

# 1247 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1248 "data//maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1249 "data//maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1250 "data//maps/RustboroCity/scripts.pory"

# 1251 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1252 "data//maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1253 "data//maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1254 "data//maps/RustboroCity/scripts.pory"

# 1255 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1256 "data//maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1257 "data//maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1258 "data//maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1259 "data//maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1260 "data//maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1261 "data//maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1262 "data//maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1263 "data//maps/RustboroCity/scripts.pory"

# 1264 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1265 "data//maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1266 "data//maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1267 "data//maps/RustboroCity/scripts.pory"

# 1268 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1269 "data//maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1270 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1271 "data//maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1272 "data//maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1273 "data//maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1274 "data//maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1275 "data//maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1276 "data//maps/RustboroCity/scripts.pory"

# 1277 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1278 "data//maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1279 "data//maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1280 "data//maps/RustboroCity/scripts.pory"

# 1281 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1282 "data//maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1283 "data//maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1284 "data//maps/RustboroCity/scripts.pory"

# 1285 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1286 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1287 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1288 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1289 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1290 "data//maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1291 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1292 "data//maps/RustboroCity/scripts.pory"

# 1293 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1294 "data//maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1295 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1296 "data//maps/RustboroCity/scripts.pory"

# 1297 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1298 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1299 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1300 "data//maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1301 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1302 "data//maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1303 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1304 "data//maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1305 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1306 "data//maps/RustboroCity/scripts.pory"

# 1307 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1308 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1309 "data//maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1310 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1311 "data//maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1312 "data//maps/RustboroCity/scripts.pory"

# 1313 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1314 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1315 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1316 "data//maps/RustboroCity/scripts.pory"

# 1317 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1318 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1319 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1320 "data//maps/RustboroCity/scripts.pory"

# 1321 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1322 "data//maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1323 "data//maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1324 "data//maps/RustboroCity/scripts.pory"

# 1325 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1326 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1327 "data//maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1328 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1329 "data//maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1330 "data//maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1331 "data//maps/RustboroCity/scripts.pory"

# 1332 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1333 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1334 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1335 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1336 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1337 "data//maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1338 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1339 "data//maps/RustboroCity/scripts.pory"

# 1340 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1341 "data//maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1342 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1343 "data//maps/RustboroCity/scripts.pory"

# 1344 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1345 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1346 "data//maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1347 "data//maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1348 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1349 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1350 "data//maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1351 "data//maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1352 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1353 "data//maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1354 "data//maps/RustboroCity/scripts.pory"

# 1355 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1356 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1357 "data//maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1358 "data//maps/RustboroCity/scripts.pory"

# 1359 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1360 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1361 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1362 "data//maps/RustboroCity/scripts.pory"

# 1363 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1364 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1365 "data//maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1366 "data//maps/RustboroCity/scripts.pory"

# 1367 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1368 "data//maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1369 "data//maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1370 "data//maps/RustboroCity/scripts.pory"

# 1371 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1372 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1373 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1374 "data//maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1375 "data//maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1376 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1377 "data//maps/RustboroCity/scripts.pory"

# 1378 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1379 "data//maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1380 "data//maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1381 "data//maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1382 "data//maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1383 "data//maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1384 "data//maps/RustboroCity/scripts.pory"

# 1385 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1386 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1387 "data//maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1388 "data//maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1389 "data//maps/RustboroCity/scripts.pory"

# 1390 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1391 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1392 "data//maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1393 "data//maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1394 "data//maps/RustboroCity/scripts.pory"

# 1395 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1396 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1397 "data//maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1398 "data//maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1399 "data//maps/RustboroCity/scripts.pory"

# 1400 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1401 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1402 "data//maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1403 "data//maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1404 "data//maps/RustboroCity/scripts.pory"

# 1405 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1406 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1407 "data//maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1408 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1409 "data//maps/RustboroCity/scripts.pory"

# 1410 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1411 "data//maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1412 "data//maps/RustboroCity/scripts.pory"

# 1413 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1414 "data//maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1415 "data//maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1416 "data//maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1417 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1418 "data//maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1419 "data//maps/RustboroCity/scripts.pory"

# 1420 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1421 "data//maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1422 "data//maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1423 "data//maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1424 "data//maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1425 "data//maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1426 "data//maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1427 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1428 "data//maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1429 "data//maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1430 "data//maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1431 "data//maps/RustboroCity/scripts.pory"

# 1432 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1433 "data//maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1434 "data//maps/RustboroCity/scripts.pory"

# 1435 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1436 "data//maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1437 "data//maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1438 "data//maps/RustboroCity/scripts.pory"

# 1439 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1440 "data//maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1441 "data//maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1442 "data//maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1443 "data//maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1444 "data//maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1445 "data//maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1446 "data//maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1447 "data//maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_ReturningFromShadyTruck_Text_0:
# 51 "data//maps/RustboroCity/scripts.pory"
	.string "ZAZAZAAAAAAM!!$"

RustboroCity_EventScript_ReturningFromShadyTruck_Text_1:
# 76 "data//maps/RustboroCity/scripts.pory"
	.string "The truck drove off…$"

RustboroCity_EventScript_ExamineShadyTruck_Text_0:
# 112 "data//maps/RustboroCity/scripts.pory"
	.string "It's a big beat-up truck with no plates\n"
	.string "or logos.\p"
	.string "It must have been difficult to park\n"
	.string "here.$"

RustboroCity_EventScript_ShadyAlakazam_Text_0:
# 125 "data//maps/RustboroCity/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

RustboroCity_EventScript_ShadyAlakazam_Text_1:
# 130 "data//maps/RustboroCity/scripts.pory"
	.string "ALAKAZAM is beckoning you towards the\n"
	.string "truck doors.$"

RustboroCity_EventScript_ShadyAlakazam_Text_2:
# 133 "data//maps/RustboroCity/scripts.pory"
	.string "This shady-looking ALAKAZAM is asking\n"
	.string "if you want to enter the truck.\p"
	.string "Do you trust ALAKAZAM enough to get\n"
	.string "into the sketchy truck?$"
