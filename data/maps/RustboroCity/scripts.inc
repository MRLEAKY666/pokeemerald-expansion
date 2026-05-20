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
	switch VAR_RESULT
# 261 "data//maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 262 "data//maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 263 "data//maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 264 "data//maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 265 "data//maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 266 "data//maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 267 "data//maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 268 "data//maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 269 "data//maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 270 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 271 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 272 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 273 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 274 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 275 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 276 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 277 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 278 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 279 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 280 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 281 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 282 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 283 "data//maps/RustboroCity/scripts.pory"
	end
# 284 "data//maps/RustboroCity/scripts.pory"

# 285 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 286 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 287 "data//maps/RustboroCity/scripts.pory"
	step_end
# 288 "data//maps/RustboroCity/scripts.pory"

# 289 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 290 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 291 "data//maps/RustboroCity/scripts.pory"
	step_end
# 292 "data//maps/RustboroCity/scripts.pory"

# 293 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 294 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 295 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 296 "data//maps/RustboroCity/scripts.pory"
	step_end
# 297 "data//maps/RustboroCity/scripts.pory"

# 298 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 299 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 300 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 301 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 302 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 303 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 304 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 305 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 306 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 307 "data//maps/RustboroCity/scripts.pory"
	step_end
# 308 "data//maps/RustboroCity/scripts.pory"

# 309 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 310 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 311 "data//maps/RustboroCity/scripts.pory"
	step_end
# 312 "data//maps/RustboroCity/scripts.pory"

# 313 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 314 "data//maps/RustboroCity/scripts.pory"
	lock
# 315 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 316 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 317 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 318 "data//maps/RustboroCity/scripts.pory"
	release
# 319 "data//maps/RustboroCity/scripts.pory"
	end
# 320 "data//maps/RustboroCity/scripts.pory"

# 321 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 322 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 323 "data//maps/RustboroCity/scripts.pory"
	release
# 324 "data//maps/RustboroCity/scripts.pory"
	end
# 325 "data//maps/RustboroCity/scripts.pory"

# 326 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 327 "data//maps/RustboroCity/scripts.pory"
	lock
# 328 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 329 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 330 "data//maps/RustboroCity/scripts.pory"
	release
# 331 "data//maps/RustboroCity/scripts.pory"
	end
# 332 "data//maps/RustboroCity/scripts.pory"

# 333 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 334 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 335 "data//maps/RustboroCity/scripts.pory"
	end
# 336 "data//maps/RustboroCity/scripts.pory"

# 337 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 338 "data//maps/RustboroCity/scripts.pory"
	lock
# 339 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 340 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 341 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 342 "data//maps/RustboroCity/scripts.pory"
	release
# 343 "data//maps/RustboroCity/scripts.pory"
	end
# 344 "data//maps/RustboroCity/scripts.pory"

# 345 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 346 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 347 "data//maps/RustboroCity/scripts.pory"
	release
# 348 "data//maps/RustboroCity/scripts.pory"
	end
# 349 "data//maps/RustboroCity/scripts.pory"

# 350 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 351 "data//maps/RustboroCity/scripts.pory"
	lock
# 352 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 353 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 354 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 355 "data//maps/RustboroCity/scripts.pory"
	release
# 356 "data//maps/RustboroCity/scripts.pory"
	end
# 357 "data//maps/RustboroCity/scripts.pory"

# 358 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 359 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 360 "data//maps/RustboroCity/scripts.pory"
	release
# 361 "data//maps/RustboroCity/scripts.pory"
	end
# 362 "data//maps/RustboroCity/scripts.pory"

# 363 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 364 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 365 "data//maps/RustboroCity/scripts.pory"
	end
# 366 "data//maps/RustboroCity/scripts.pory"

# 367 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 368 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 369 "data//maps/RustboroCity/scripts.pory"
	end
# 370 "data//maps/RustboroCity/scripts.pory"

# 371 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 372 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 373 "data//maps/RustboroCity/scripts.pory"
	end
# 374 "data//maps/RustboroCity/scripts.pory"

# 375 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 376 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 377 "data//maps/RustboroCity/scripts.pory"
	end
# 378 "data//maps/RustboroCity/scripts.pory"

# 379 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 380 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 381 "data//maps/RustboroCity/scripts.pory"
	end
# 382 "data//maps/RustboroCity/scripts.pory"

# 383 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 384 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 385 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 386 "data//maps/RustboroCity/scripts.pory"
	end
# 387 "data//maps/RustboroCity/scripts.pory"

# 388 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 389 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 390 "data//maps/RustboroCity/scripts.pory"
	end
# 391 "data//maps/RustboroCity/scripts.pory"

# 392 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 393 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 394 "data//maps/RustboroCity/scripts.pory"
	end
# 395 "data//maps/RustboroCity/scripts.pory"

# 396 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 397 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 398 "data//maps/RustboroCity/scripts.pory"
	end
# 399 "data//maps/RustboroCity/scripts.pory"

# 400 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 401 "data//maps/RustboroCity/scripts.pory"
	lock
# 402 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 403 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 404 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 405 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 406 "data//maps/RustboroCity/scripts.pory"
	release
# 407 "data//maps/RustboroCity/scripts.pory"
	end
# 408 "data//maps/RustboroCity/scripts.pory"

# 409 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 410 "data//maps/RustboroCity/scripts.pory"
	lock
# 411 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 412 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 413 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 414 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 415 "data//maps/RustboroCity/scripts.pory"
	release
# 416 "data//maps/RustboroCity/scripts.pory"
	end
# 417 "data//maps/RustboroCity/scripts.pory"

# 418 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 419 "data//maps/RustboroCity/scripts.pory"
	lock
# 420 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 421 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 422 "data//maps/RustboroCity/scripts.pory"
	release
# 423 "data//maps/RustboroCity/scripts.pory"
	end
# 424 "data//maps/RustboroCity/scripts.pory"

# 425 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 426 "data//maps/RustboroCity/scripts.pory"
	lockall
# 427 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 428 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 429 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 430 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 431 "data//maps/RustboroCity/scripts.pory"
	end
# 432 "data//maps/RustboroCity/scripts.pory"

# 433 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 434 "data//maps/RustboroCity/scripts.pory"
	lockall
# 435 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 436 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 437 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 438 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 439 "data//maps/RustboroCity/scripts.pory"
	end
# 440 "data//maps/RustboroCity/scripts.pory"

# 441 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 442 "data//maps/RustboroCity/scripts.pory"
	lockall
# 443 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 444 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 445 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 446 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 447 "data//maps/RustboroCity/scripts.pory"
	end
# 448 "data//maps/RustboroCity/scripts.pory"

# 449 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 450 "data//maps/RustboroCity/scripts.pory"
	lockall
# 451 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 452 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 453 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 454 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 455 "data//maps/RustboroCity/scripts.pory"
	end
# 456 "data//maps/RustboroCity/scripts.pory"

# 457 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 458 "data//maps/RustboroCity/scripts.pory"
	lockall
# 459 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 460 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 461 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 462 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 463 "data//maps/RustboroCity/scripts.pory"
	end
# 464 "data//maps/RustboroCity/scripts.pory"

# 465 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 466 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 467 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 468 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 469 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 470 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 471 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 472 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 473 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 474 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 475 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 476 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 477 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 478 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 479 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 480 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 481 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 482 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 483 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 484 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 485 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 486 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 487 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 488 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 489 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 490 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 491 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 492 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 493 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 494 "data//maps/RustboroCity/scripts.pory"
	end
# 495 "data//maps/RustboroCity/scripts.pory"

# 496 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 497 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 498 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 499 "data//maps/RustboroCity/scripts.pory"
	return
# 500 "data//maps/RustboroCity/scripts.pory"

# 501 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 502 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 503 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 504 "data//maps/RustboroCity/scripts.pory"
	return
# 505 "data//maps/RustboroCity/scripts.pory"

# 506 "data//maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 507 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 508 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 509 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 510 "data//maps/RustboroCity/scripts.pory"
	return
# 511 "data//maps/RustboroCity/scripts.pory"

# 512 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 513 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 514 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 515 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 516 "data//maps/RustboroCity/scripts.pory"
	return
# 517 "data//maps/RustboroCity/scripts.pory"

# 518 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 519 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 520 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 521 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 522 "data//maps/RustboroCity/scripts.pory"
	return
# 523 "data//maps/RustboroCity/scripts.pory"

# 524 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 525 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 526 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 527 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 528 "data//maps/RustboroCity/scripts.pory"
	return
# 529 "data//maps/RustboroCity/scripts.pory"

# 530 "data//maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 531 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 532 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 533 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 534 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 535 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 536 "data//maps/RustboroCity/scripts.pory"
	return
# 537 "data//maps/RustboroCity/scripts.pory"

# 538 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 539 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 540 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 541 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 542 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 543 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 544 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 545 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 555 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 556 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 557 "data//maps/RustboroCity/scripts.pory"
	step_end
# 558 "data//maps/RustboroCity/scripts.pory"

# 559 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 560 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 561 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 562 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 563 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 564 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 565 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 566 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 574 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 575 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 576 "data//maps/RustboroCity/scripts.pory"
	step_end
# 577 "data//maps/RustboroCity/scripts.pory"

# 578 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 579 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 580 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 581 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 582 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 583 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 584 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 585 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 586 "data//maps/RustboroCity/scripts.pory"
	step_end
# 587 "data//maps/RustboroCity/scripts.pory"

# 588 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 589 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 590 "data//maps/RustboroCity/scripts.pory"
	walk_up
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
	step_end
# 597 "data//maps/RustboroCity/scripts.pory"

# 598 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 599 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 600 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 601 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 602 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 603 "data//maps/RustboroCity/scripts.pory"
	step_end
# 604 "data//maps/RustboroCity/scripts.pory"

# 605 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 606 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 607 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 608 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 609 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 610 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 611 "data//maps/RustboroCity/scripts.pory"
	step_end
# 612 "data//maps/RustboroCity/scripts.pory"

# 613 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 614 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 615 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 616 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 617 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 618 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 619 "data//maps/RustboroCity/scripts.pory"
	step_end
# 620 "data//maps/RustboroCity/scripts.pory"

# 621 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 622 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 623 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 624 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 625 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 626 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 627 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 628 "data//maps/RustboroCity/scripts.pory"
	step_end
# 629 "data//maps/RustboroCity/scripts.pory"

# 630 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 631 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 632 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 633 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 634 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 635 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 636 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 637 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 638 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 639 "data//maps/RustboroCity/scripts.pory"
	step_end
# 640 "data//maps/RustboroCity/scripts.pory"

# 641 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 642 "data//maps/RustboroCity/scripts.pory"
	lock
# 643 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 644 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 645 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 646 "data//maps/RustboroCity/scripts.pory"
	release
# 647 "data//maps/RustboroCity/scripts.pory"
	end
# 648 "data//maps/RustboroCity/scripts.pory"

# 649 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 650 "data//maps/RustboroCity/scripts.pory"
	waitse
# 651 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 652 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 653 "data//maps/RustboroCity/scripts.pory"
	end
# 654 "data//maps/RustboroCity/scripts.pory"

# 655 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 656 "data//maps/RustboroCity/scripts.pory"
	lockall
# 657 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 658 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 659 "data//maps/RustboroCity/scripts.pory"
	end
# 660 "data//maps/RustboroCity/scripts.pory"

# 661 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 662 "data//maps/RustboroCity/scripts.pory"
	lockall
# 663 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 664 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 665 "data//maps/RustboroCity/scripts.pory"
	end
# 666 "data//maps/RustboroCity/scripts.pory"

# 667 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 668 "data//maps/RustboroCity/scripts.pory"
	lockall
# 669 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 670 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 671 "data//maps/RustboroCity/scripts.pory"
	end
# 672 "data//maps/RustboroCity/scripts.pory"

# 673 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 674 "data//maps/RustboroCity/scripts.pory"
	lockall
# 675 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 676 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 677 "data//maps/RustboroCity/scripts.pory"
	end
# 678 "data//maps/RustboroCity/scripts.pory"

# 679 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 680 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 681 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 682 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 683 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 684 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 685 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 686 "data//maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 687 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 688 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 689 "data//maps/RustboroCity/scripts.pory"
	end
# 690 "data//maps/RustboroCity/scripts.pory"

# 691 "data//maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 692 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 693 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 694 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 695 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 696 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 697 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 698 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 699 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 700 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 701 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 702 "data//maps/RustboroCity/scripts.pory"
	return
# 703 "data//maps/RustboroCity/scripts.pory"

# 704 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 705 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 706 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 707 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 708 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 709 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 710 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 711 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 712 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 713 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 714 "data//maps/RustboroCity/scripts.pory"
	return
# 715 "data//maps/RustboroCity/scripts.pory"

# 716 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 717 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 718 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 719 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 720 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 721 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 722 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 723 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 724 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 725 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 726 "data//maps/RustboroCity/scripts.pory"
	return
# 727 "data//maps/RustboroCity/scripts.pory"

# 728 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 729 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 730 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 731 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 732 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 733 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 734 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 735 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 736 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 737 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 738 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 739 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 740 "data//maps/RustboroCity/scripts.pory"
	return
# 741 "data//maps/RustboroCity/scripts.pory"

# 742 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 743 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 744 "data//maps/RustboroCity/scripts.pory"
	step_end
# 745 "data//maps/RustboroCity/scripts.pory"

# 746 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 747 "data//maps/RustboroCity/scripts.pory"
	lockall
# 748 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 749 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 750 "data//maps/RustboroCity/scripts.pory"
	end
# 751 "data//maps/RustboroCity/scripts.pory"

# 752 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 753 "data//maps/RustboroCity/scripts.pory"
	lockall
# 754 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 755 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 756 "data//maps/RustboroCity/scripts.pory"
	end
# 757 "data//maps/RustboroCity/scripts.pory"

# 758 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 759 "data//maps/RustboroCity/scripts.pory"
	lockall
# 760 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 761 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 762 "data//maps/RustboroCity/scripts.pory"
	end
# 763 "data//maps/RustboroCity/scripts.pory"

# 764 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 765 "data//maps/RustboroCity/scripts.pory"
	lockall
# 766 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 767 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 768 "data//maps/RustboroCity/scripts.pory"
	end
# 769 "data//maps/RustboroCity/scripts.pory"

# 770 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 771 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 772 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 773 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 774 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 775 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 776 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 777 "data//maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 778 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 779 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 780 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 781 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 782 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 783 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 784 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 785 "data//maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 786 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 787 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 788 "data//maps/RustboroCity/scripts.pory"
	end
# 789 "data//maps/RustboroCity/scripts.pory"

# 790 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 791 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 792 "data//maps/RustboroCity/scripts.pory"
	return
# 793 "data//maps/RustboroCity/scripts.pory"

# 794 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 795 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 796 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 797 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 798 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 799 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 800 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 801 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 802 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 803 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 804 "data//maps/RustboroCity/scripts.pory"
	return
# 805 "data//maps/RustboroCity/scripts.pory"

# 806 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 807 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 808 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 809 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 810 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 811 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 812 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 813 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 814 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 815 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 816 "data//maps/RustboroCity/scripts.pory"
	return
# 817 "data//maps/RustboroCity/scripts.pory"

# 818 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 819 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 820 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 822 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 823 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 824 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 825 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 826 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 827 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 828 "data//maps/RustboroCity/scripts.pory"
	return
# 829 "data//maps/RustboroCity/scripts.pory"

# 830 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 831 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 832 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 833 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 834 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 835 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 836 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 837 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 838 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 839 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 840 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 841 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 842 "data//maps/RustboroCity/scripts.pory"
	return
# 843 "data//maps/RustboroCity/scripts.pory"

# 844 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 845 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 846 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 847 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 848 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 849 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 850 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 851 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 852 "data//maps/RustboroCity/scripts.pory"
	return
# 853 "data//maps/RustboroCity/scripts.pory"

# 854 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 855 "data//maps/RustboroCity/scripts.pory"
	lockall
# 856 "data//maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 857 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 858 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 859 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 860 "data//maps/RustboroCity/scripts.pory"

# 861 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 862 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 863 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 864 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 865 "data//maps/RustboroCity/scripts.pory"
	return
# 866 "data//maps/RustboroCity/scripts.pory"

# 867 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 868 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 869 "data//maps/RustboroCity/scripts.pory"
	return
# 870 "data//maps/RustboroCity/scripts.pory"

# 871 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 872 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 873 "data//maps/RustboroCity/scripts.pory"
	return
# 874 "data//maps/RustboroCity/scripts.pory"

# 875 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 876 "data//maps/RustboroCity/scripts.pory"
	lockall
# 877 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 878 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 879 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 880 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 881 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 882 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 883 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 884 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 885 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 886 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 887 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 888 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 889 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 890 "data//maps/RustboroCity/scripts.pory"

# 891 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 892 "data//maps/RustboroCity/scripts.pory"
	lockall
# 893 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 894 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 895 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 896 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 897 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 898 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 899 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 900 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 901 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 902 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 903 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 904 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 905 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 906 "data//maps/RustboroCity/scripts.pory"

# 907 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 908 "data//maps/RustboroCity/scripts.pory"
	lockall
# 909 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 910 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 911 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 912 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 913 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 914 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 915 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 916 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 917 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 918 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 919 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 920 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 921 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 922 "data//maps/RustboroCity/scripts.pory"

# 923 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 924 "data//maps/RustboroCity/scripts.pory"
	lockall
# 925 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 926 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 927 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 928 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 929 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 930 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 931 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 932 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 933 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 934 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 935 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 936 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 937 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 938 "data//maps/RustboroCity/scripts.pory"

# 939 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 940 "data//maps/RustboroCity/scripts.pory"
	lockall
# 941 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 942 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 943 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 944 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 945 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 946 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 947 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 948 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 949 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 950 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 951 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 952 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 953 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 954 "data//maps/RustboroCity/scripts.pory"

# 955 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 956 "data//maps/RustboroCity/scripts.pory"
	lockall
# 957 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 958 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 959 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 960 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 961 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 962 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 963 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 964 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 965 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 966 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 967 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 968 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 969 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 970 "data//maps/RustboroCity/scripts.pory"

# 971 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 972 "data//maps/RustboroCity/scripts.pory"
	lockall
# 973 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 974 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 975 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 976 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 977 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 978 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 979 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 980 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 981 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 982 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 983 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 984 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 985 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 986 "data//maps/RustboroCity/scripts.pory"

# 987 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 988 "data//maps/RustboroCity/scripts.pory"
	lockall
# 989 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 990 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 991 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 992 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 993 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 994 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 995 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 996 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 997 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 998 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 999 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1000 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1001 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1002 "data//maps/RustboroCity/scripts.pory"

# 1003 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1004 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 1005 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1006 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1007 "data//maps/RustboroCity/scripts.pory"
	end
# 1008 "data//maps/RustboroCity/scripts.pory"

# 1009 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1010 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1011 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1012 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1013 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1014 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1015 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1016 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1017 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1018 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1019 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1020 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1021 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1022 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1023 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1024 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1025 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1026 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1027 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1028 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1029 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1030 "data//maps/RustboroCity/scripts.pory"
	end
# 1031 "data//maps/RustboroCity/scripts.pory"

# 1032 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1033 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1034 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1035 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1036 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1037 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1038 "data//maps/RustboroCity/scripts.pory"
	end
# 1039 "data//maps/RustboroCity/scripts.pory"

# 1040 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1041 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1042 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1043 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartMayBattle
# 1044 "data//maps/RustboroCity/scripts.pory"
	end
# 1045 "data//maps/RustboroCity/scripts.pory"

# 1046 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1047 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1048 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1049 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1050 "data//maps/RustboroCity/scripts.pory"
	end
# 1051 "data//maps/RustboroCity/scripts.pory"

# 1052 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1053 "data//maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1054 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1055 "data//maps/RustboroCity/scripts.pory"
	return
# 1056 "data//maps/RustboroCity/scripts.pory"

# 1057 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartMayBattle::
# 1058 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, RustboroCity_Text_MayDefeat
# 1059 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1060 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1061 "data//maps/RustboroCity/scripts.pory"
	end
# 1062 "data//maps/RustboroCity/scripts.pory"

# 1063 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1064 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1065 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1066 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1067 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1068 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1069 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1070 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1071 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1072 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 1073 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 1074 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 1075 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1076 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1077 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1078 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1079 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1080 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1081 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1082 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1083 "data//maps/RustboroCity/scripts.pory"
	end
# 1084 "data//maps/RustboroCity/scripts.pory"

# 1085 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1086 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1087 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1088 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1089 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1090 "data//maps/RustboroCity/scripts.pory"
	end
# 1091 "data//maps/RustboroCity/scripts.pory"

# 1092 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1093 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1094 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1095 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartBrendanBattle
# 1096 "data//maps/RustboroCity/scripts.pory"
	end
# 1097 "data//maps/RustboroCity/scripts.pory"

# 1098 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1099 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1100 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1101 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 1102 "data//maps/RustboroCity/scripts.pory"
	end
# 1103 "data//maps/RustboroCity/scripts.pory"

# 1104 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartBrendanBattle::
# 1105 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, RustboroCity_Text_BrendanDefeat
# 1106 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1107 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1108 "data//maps/RustboroCity/scripts.pory"
	end
# 1109 "data//maps/RustboroCity/scripts.pory"

# 1110 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1111 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1112 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1113 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1114 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1115 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1116 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1117 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1118 "data//maps/RustboroCity/scripts.pory"

# 1119 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1120 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1121 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1122 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1123 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1124 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1125 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1126 "data//maps/RustboroCity/scripts.pory"

# 1127 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1128 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1129 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1130 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1131 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1132 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1133 "data//maps/RustboroCity/scripts.pory"

# 1134 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1135 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1136 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 1137 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1138 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1139 "data//maps/RustboroCity/scripts.pory"

# 1140 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1141 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1142 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1143 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1144 "data//maps/RustboroCity/scripts.pory"

# 1145 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1146 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1147 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1148 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1149 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1150 "data//maps/RustboroCity/scripts.pory"

# 1151 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1152 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1153 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1154 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1155 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1156 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1157 "data//maps/RustboroCity/scripts.pory"

# 1158 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1159 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1160 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1161 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1162 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 1163 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 1164 "data//maps/RustboroCity/scripts.pory"
	step_end
# 1165 "data//maps/RustboroCity/scripts.pory"

# 1166 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1167 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1168 "data//maps/RustboroCity/scripts.pory"
	end
# 1169 "data//maps/RustboroCity/scripts.pory"

# 1170 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1171 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1172 "data//maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1173 "data//maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1174 "data//maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1175 "data//maps/RustboroCity/scripts.pory"

# 1176 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1177 "data//maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1178 "data//maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1179 "data//maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1180 "data//maps/RustboroCity/scripts.pory"

# 1181 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1182 "data//maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1183 "data//maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1184 "data//maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1185 "data//maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1186 "data//maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1187 "data//maps/RustboroCity/scripts.pory"

# 1188 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1189 "data//maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1190 "data//maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1191 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1192 "data//maps/RustboroCity/scripts.pory"

# 1193 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1194 "data//maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1195 "data//maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1196 "data//maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1197 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1198 "data//maps/RustboroCity/scripts.pory"

# 1199 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1200 "data//maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1201 "data//maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1202 "data//maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1203 "data//maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1204 "data//maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1205 "data//maps/RustboroCity/scripts.pory"

# 1206 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1207 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1208 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1209 "data//maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1210 "data//maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1211 "data//maps/RustboroCity/scripts.pory"

# 1212 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1213 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1214 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1215 "data//maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1216 "data//maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1217 "data//maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1218 "data//maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1219 "data//maps/RustboroCity/scripts.pory"

# 1220 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1221 "data//maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1222 "data//maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1223 "data//maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1224 "data//maps/RustboroCity/scripts.pory"

# 1225 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1226 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1227 "data//maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1228 "data//maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1229 "data//maps/RustboroCity/scripts.pory"

# 1230 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1231 "data//maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1232 "data//maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1233 "data//maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1234 "data//maps/RustboroCity/scripts.pory"

# 1235 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1236 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1237 "data//maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1238 "data//maps/RustboroCity/scripts.pory"

# 1239 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1240 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1241 "data//maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1242 "data//maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1243 "data//maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1244 "data//maps/RustboroCity/scripts.pory"

# 1245 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1246 "data//maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1247 "data//maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1248 "data//maps/RustboroCity/scripts.pory"

# 1249 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1250 "data//maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1251 "data//maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1252 "data//maps/RustboroCity/scripts.pory"

# 1253 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1254 "data//maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1255 "data//maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1256 "data//maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1257 "data//maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1258 "data//maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1259 "data//maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1260 "data//maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1261 "data//maps/RustboroCity/scripts.pory"

# 1262 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1263 "data//maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1264 "data//maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1265 "data//maps/RustboroCity/scripts.pory"

# 1266 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1267 "data//maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1268 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1269 "data//maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1270 "data//maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1271 "data//maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1272 "data//maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1273 "data//maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1274 "data//maps/RustboroCity/scripts.pory"

# 1275 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1276 "data//maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1277 "data//maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1278 "data//maps/RustboroCity/scripts.pory"

# 1279 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1280 "data//maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1281 "data//maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1282 "data//maps/RustboroCity/scripts.pory"

# 1283 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1284 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1285 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1286 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1287 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1288 "data//maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1289 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1290 "data//maps/RustboroCity/scripts.pory"

# 1291 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1292 "data//maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1293 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1294 "data//maps/RustboroCity/scripts.pory"

# 1295 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1296 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1297 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1298 "data//maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1299 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1300 "data//maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1301 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1302 "data//maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1303 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1304 "data//maps/RustboroCity/scripts.pory"

# 1305 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1306 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1307 "data//maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1308 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1309 "data//maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1310 "data//maps/RustboroCity/scripts.pory"

# 1311 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1312 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1313 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1314 "data//maps/RustboroCity/scripts.pory"

# 1315 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1316 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1317 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1318 "data//maps/RustboroCity/scripts.pory"

# 1319 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1320 "data//maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1321 "data//maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1322 "data//maps/RustboroCity/scripts.pory"

# 1323 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1324 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1325 "data//maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1326 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1327 "data//maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1328 "data//maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1329 "data//maps/RustboroCity/scripts.pory"

# 1330 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1331 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1332 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1333 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1334 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1335 "data//maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1336 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1337 "data//maps/RustboroCity/scripts.pory"

# 1338 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1339 "data//maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1340 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1341 "data//maps/RustboroCity/scripts.pory"

# 1342 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1343 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1344 "data//maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1345 "data//maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1346 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1347 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1348 "data//maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1349 "data//maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1350 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1351 "data//maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1352 "data//maps/RustboroCity/scripts.pory"

# 1353 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1354 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1355 "data//maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1356 "data//maps/RustboroCity/scripts.pory"

# 1357 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1358 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1359 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1360 "data//maps/RustboroCity/scripts.pory"

# 1361 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1362 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1363 "data//maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1364 "data//maps/RustboroCity/scripts.pory"

# 1365 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1366 "data//maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1367 "data//maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1368 "data//maps/RustboroCity/scripts.pory"

# 1369 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1370 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1371 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1372 "data//maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1373 "data//maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1374 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1375 "data//maps/RustboroCity/scripts.pory"

# 1376 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1377 "data//maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1378 "data//maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1379 "data//maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1380 "data//maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1381 "data//maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1382 "data//maps/RustboroCity/scripts.pory"

# 1383 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1384 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1385 "data//maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1386 "data//maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1387 "data//maps/RustboroCity/scripts.pory"

# 1388 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1389 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1390 "data//maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1391 "data//maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1392 "data//maps/RustboroCity/scripts.pory"

# 1393 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1394 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1395 "data//maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1396 "data//maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1397 "data//maps/RustboroCity/scripts.pory"

# 1398 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1399 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1400 "data//maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1401 "data//maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1402 "data//maps/RustboroCity/scripts.pory"

# 1403 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1404 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1405 "data//maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1406 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1407 "data//maps/RustboroCity/scripts.pory"

# 1408 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1409 "data//maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1410 "data//maps/RustboroCity/scripts.pory"

# 1411 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1412 "data//maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1413 "data//maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1414 "data//maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1415 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1416 "data//maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1417 "data//maps/RustboroCity/scripts.pory"

# 1418 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1419 "data//maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1420 "data//maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1421 "data//maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1422 "data//maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1423 "data//maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1424 "data//maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1425 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1426 "data//maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1427 "data//maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1428 "data//maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1429 "data//maps/RustboroCity/scripts.pory"

# 1430 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1431 "data//maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1432 "data//maps/RustboroCity/scripts.pory"

# 1433 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1434 "data//maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1435 "data//maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1436 "data//maps/RustboroCity/scripts.pory"

# 1437 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1438 "data//maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1439 "data//maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1440 "data//maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1441 "data//maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1442 "data//maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1443 "data//maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1444 "data//maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1445 "data//maps/RustboroCity/scripts.pory"
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
