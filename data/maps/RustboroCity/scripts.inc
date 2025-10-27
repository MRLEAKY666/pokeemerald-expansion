# 1 "data//maps/RustboroCity/scripts.pory"

# 2 "data//maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 3 "data//maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 4 "data//maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 5 "data//maps/RustboroCity/scripts.pory"
	.byte 0
# 6 "data//maps/RustboroCity/scripts.pory"

# 7 "data//maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition:
# 8 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 9 "data//maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 11 "data//maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 12 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
# 13 "data//maps/RustboroCity/scripts.pory"
	end
# 14 "data//maps/RustboroCity/scripts.pory"

# 15 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 16 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 17 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
# 18 "data//maps/RustboroCity/scripts.pory"
	end
# 19 "data//maps/RustboroCity/scripts.pory"

# 20 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 21 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
# 22 "data//maps/RustboroCity/scripts.pory"
	end
# 23 "data//maps/RustboroCity/scripts.pory"

# 24 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 25 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 26 "data//maps/RustboroCity/scripts.pory"
	return
# 27 "data//maps/RustboroCity/scripts.pory"

# 28 "data//maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 29 "data//maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 30 "data//maps/RustboroCity/scripts.pory"
	.2byte 0
# 31 "data//maps/RustboroCity/scripts.pory"

# 32 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 33 "data//maps/RustboroCity/scripts.pory"
	lockall
# 34 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 35 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 36 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 37 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 38 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 39 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_SCIENTIST
# 40 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 41 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 42 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 43 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
# 44 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 45 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
# 46 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 47 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 48 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 49 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 50 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 51 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 52 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 53 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 54 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 55 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 56 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 57 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 58 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 59 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 60 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 61 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 62 "data//maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 63 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 64 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 65 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 66 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 67 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 68 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 69 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 70 "data//maps/RustboroCity/scripts.pory"

# 71 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 72 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 73 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 74 "data//maps/RustboroCity/scripts.pory"
	delay 10
# 75 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 76 "data//maps/RustboroCity/scripts.pory"

# 77 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 78 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 79 "data//maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 80 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 81 "data//maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 82 "data//maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 83 "data//maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 84 "data//maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 85 "data//maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 86 "data//maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 87 "data//maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 88 "data//maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 89 "data//maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 90 "data//maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 91 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 92 "data//maps/RustboroCity/scripts.pory"
	delay 20
# 93 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 94 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 95 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 96 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 97 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 98 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 99 "data//maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 100 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 101 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 102 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 103 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 104 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 105 "data//maps/RustboroCity/scripts.pory"
	end
# 106 "data//maps/RustboroCity/scripts.pory"

# 107 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 108 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 109 "data//maps/RustboroCity/scripts.pory"
	step_end
# 110 "data//maps/RustboroCity/scripts.pory"

# 111 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 112 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 113 "data//maps/RustboroCity/scripts.pory"
	step_end
# 114 "data//maps/RustboroCity/scripts.pory"

# 115 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 116 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 117 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 118 "data//maps/RustboroCity/scripts.pory"
	step_end
# 119 "data//maps/RustboroCity/scripts.pory"

# 120 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 121 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 122 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 123 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 124 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 125 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 126 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 127 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 128 "data//maps/RustboroCity/scripts.pory"
	delay_16
# 129 "data//maps/RustboroCity/scripts.pory"
	step_end
# 130 "data//maps/RustboroCity/scripts.pory"

# 131 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 132 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 133 "data//maps/RustboroCity/scripts.pory"
	step_end
# 134 "data//maps/RustboroCity/scripts.pory"

# 135 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 136 "data//maps/RustboroCity/scripts.pory"
	lock
# 137 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 138 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 139 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 140 "data//maps/RustboroCity/scripts.pory"
	release
# 141 "data//maps/RustboroCity/scripts.pory"
	end
# 142 "data//maps/RustboroCity/scripts.pory"

# 143 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 144 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 145 "data//maps/RustboroCity/scripts.pory"
	release
# 146 "data//maps/RustboroCity/scripts.pory"
	end
# 147 "data//maps/RustboroCity/scripts.pory"

# 148 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 149 "data//maps/RustboroCity/scripts.pory"
	lock
# 150 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 151 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 152 "data//maps/RustboroCity/scripts.pory"
	release
# 153 "data//maps/RustboroCity/scripts.pory"
	end
# 154 "data//maps/RustboroCity/scripts.pory"

# 155 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 156 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 157 "data//maps/RustboroCity/scripts.pory"
	end
# 158 "data//maps/RustboroCity/scripts.pory"

# 159 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 160 "data//maps/RustboroCity/scripts.pory"
	lock
# 161 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 162 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 163 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 164 "data//maps/RustboroCity/scripts.pory"
	release
# 165 "data//maps/RustboroCity/scripts.pory"
	end
# 166 "data//maps/RustboroCity/scripts.pory"

# 167 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 168 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 169 "data//maps/RustboroCity/scripts.pory"
	release
# 170 "data//maps/RustboroCity/scripts.pory"
	end
# 171 "data//maps/RustboroCity/scripts.pory"

# 172 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 173 "data//maps/RustboroCity/scripts.pory"
	lock
# 174 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 175 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 176 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 177 "data//maps/RustboroCity/scripts.pory"
	release
# 178 "data//maps/RustboroCity/scripts.pory"
	end
# 179 "data//maps/RustboroCity/scripts.pory"

# 180 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 181 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 182 "data//maps/RustboroCity/scripts.pory"
	release
# 183 "data//maps/RustboroCity/scripts.pory"
	end
# 184 "data//maps/RustboroCity/scripts.pory"

# 185 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 186 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 187 "data//maps/RustboroCity/scripts.pory"
	end
# 188 "data//maps/RustboroCity/scripts.pory"

# 189 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 190 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 191 "data//maps/RustboroCity/scripts.pory"
	end
# 192 "data//maps/RustboroCity/scripts.pory"

# 193 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 194 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 195 "data//maps/RustboroCity/scripts.pory"
	end
# 196 "data//maps/RustboroCity/scripts.pory"

# 197 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 198 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 199 "data//maps/RustboroCity/scripts.pory"
	end
# 200 "data//maps/RustboroCity/scripts.pory"

# 201 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 202 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 203 "data//maps/RustboroCity/scripts.pory"
	end
# 204 "data//maps/RustboroCity/scripts.pory"

# 205 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 206 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 207 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 208 "data//maps/RustboroCity/scripts.pory"
	end
# 209 "data//maps/RustboroCity/scripts.pory"

# 210 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 211 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 212 "data//maps/RustboroCity/scripts.pory"
	end
# 213 "data//maps/RustboroCity/scripts.pory"

# 214 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 215 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 216 "data//maps/RustboroCity/scripts.pory"
	end
# 217 "data//maps/RustboroCity/scripts.pory"

# 218 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 219 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 220 "data//maps/RustboroCity/scripts.pory"
	end
# 221 "data//maps/RustboroCity/scripts.pory"

# 222 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 223 "data//maps/RustboroCity/scripts.pory"
	lock
# 224 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 225 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 226 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 227 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 228 "data//maps/RustboroCity/scripts.pory"
	release
# 229 "data//maps/RustboroCity/scripts.pory"
	end
# 230 "data//maps/RustboroCity/scripts.pory"

# 231 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 232 "data//maps/RustboroCity/scripts.pory"
	lock
# 233 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 234 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 235 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 236 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 237 "data//maps/RustboroCity/scripts.pory"
	release
# 238 "data//maps/RustboroCity/scripts.pory"
	end
# 239 "data//maps/RustboroCity/scripts.pory"

# 240 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 241 "data//maps/RustboroCity/scripts.pory"
	lock
# 242 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 243 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 244 "data//maps/RustboroCity/scripts.pory"
	release
# 245 "data//maps/RustboroCity/scripts.pory"
	end
# 246 "data//maps/RustboroCity/scripts.pory"

# 247 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 248 "data//maps/RustboroCity/scripts.pory"
	lockall
# 249 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 250 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 251 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 252 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 253 "data//maps/RustboroCity/scripts.pory"
	end
# 254 "data//maps/RustboroCity/scripts.pory"

# 255 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 256 "data//maps/RustboroCity/scripts.pory"
	lockall
# 257 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 258 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 259 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 260 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 261 "data//maps/RustboroCity/scripts.pory"
	end
# 262 "data//maps/RustboroCity/scripts.pory"

# 263 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 264 "data//maps/RustboroCity/scripts.pory"
	lockall
# 265 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 266 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 267 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 268 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 269 "data//maps/RustboroCity/scripts.pory"
	end
# 270 "data//maps/RustboroCity/scripts.pory"

# 271 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 272 "data//maps/RustboroCity/scripts.pory"
	lockall
# 273 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 274 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 275 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 276 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 277 "data//maps/RustboroCity/scripts.pory"
	end
# 278 "data//maps/RustboroCity/scripts.pory"

# 279 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 280 "data//maps/RustboroCity/scripts.pory"
	lockall
# 281 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 282 "data//maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 283 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 284 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 285 "data//maps/RustboroCity/scripts.pory"
	end
# 286 "data//maps/RustboroCity/scripts.pory"

# 287 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 288 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 289 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 290 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 291 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 292 "data//maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 293 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 294 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 295 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 296 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 297 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 298 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 299 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 300 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 301 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 302 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 303 "data//maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 304 "data//maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 305 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 306 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 307 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 308 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 309 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 310 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 311 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 312 "data//maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 313 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 314 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 315 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 316 "data//maps/RustboroCity/scripts.pory"
	end
# 317 "data//maps/RustboroCity/scripts.pory"

# 318 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 319 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 320 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 321 "data//maps/RustboroCity/scripts.pory"
	return
# 322 "data//maps/RustboroCity/scripts.pory"

# 323 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 324 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 325 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 326 "data//maps/RustboroCity/scripts.pory"
	return
# 327 "data//maps/RustboroCity/scripts.pory"

# 328 "data//maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 329 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 330 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 331 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 332 "data//maps/RustboroCity/scripts.pory"
	return
# 333 "data//maps/RustboroCity/scripts.pory"

# 334 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 335 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 336 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 337 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 338 "data//maps/RustboroCity/scripts.pory"
	return
# 339 "data//maps/RustboroCity/scripts.pory"

# 340 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 341 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 342 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 343 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 344 "data//maps/RustboroCity/scripts.pory"
	return
# 345 "data//maps/RustboroCity/scripts.pory"

# 346 "data//maps/RustboroCity/scripts.pory"
@ Unused, see above
# 347 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 348 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 349 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 350 "data//maps/RustboroCity/scripts.pory"
	return
# 351 "data//maps/RustboroCity/scripts.pory"

# 352 "data//maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 353 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 354 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 355 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 356 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 357 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 358 "data//maps/RustboroCity/scripts.pory"
	return
# 359 "data//maps/RustboroCity/scripts.pory"

# 360 "data//maps/RustboroCity/scripts.pory"
@ Unused
# 361 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 362 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 363 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 364 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 365 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 366 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 367 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 368 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 369 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 370 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 371 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 372 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 373 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 374 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 375 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 376 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 377 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 378 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 379 "data//maps/RustboroCity/scripts.pory"
	step_end
# 380 "data//maps/RustboroCity/scripts.pory"

# 381 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 382 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 383 "data//maps/RustboroCity/scripts.pory"
	walk_faster_right
# 384 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 385 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 386 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 387 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 388 "data//maps/RustboroCity/scripts.pory"
	walk_fast_right
# 389 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 390 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 391 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 392 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 393 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 394 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 395 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 396 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 397 "data//maps/RustboroCity/scripts.pory"
	walk_fast_up
# 398 "data//maps/RustboroCity/scripts.pory"
	step_end
# 399 "data//maps/RustboroCity/scripts.pory"

# 400 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 401 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 402 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 403 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 404 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 405 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 406 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 407 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 408 "data//maps/RustboroCity/scripts.pory"
	step_end
# 409 "data//maps/RustboroCity/scripts.pory"

# 410 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 411 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 412 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 413 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 414 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 415 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 416 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 417 "data//maps/RustboroCity/scripts.pory"
	walk_up
# 418 "data//maps/RustboroCity/scripts.pory"
	step_end
# 419 "data//maps/RustboroCity/scripts.pory"

# 420 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 421 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 422 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 423 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 424 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 425 "data//maps/RustboroCity/scripts.pory"
	step_end
# 426 "data//maps/RustboroCity/scripts.pory"

# 427 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 428 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 429 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 430 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 431 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 432 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 433 "data//maps/RustboroCity/scripts.pory"
	step_end
# 434 "data//maps/RustboroCity/scripts.pory"

# 435 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 436 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 437 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 438 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 439 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 440 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 441 "data//maps/RustboroCity/scripts.pory"
	step_end
# 442 "data//maps/RustboroCity/scripts.pory"

# 443 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 444 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 445 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 446 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 447 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 448 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 449 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 450 "data//maps/RustboroCity/scripts.pory"
	step_end
# 451 "data//maps/RustboroCity/scripts.pory"

# 452 "data//maps/RustboroCity/scripts.pory"
@ Functionally unused
# 453 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 454 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 455 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 456 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 457 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 458 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 459 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 460 "data//maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 461 "data//maps/RustboroCity/scripts.pory"
	step_end
# 462 "data//maps/RustboroCity/scripts.pory"

# 463 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 464 "data//maps/RustboroCity/scripts.pory"
	lock
# 465 "data//maps/RustboroCity/scripts.pory"
	faceplayer
# 466 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 467 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 468 "data//maps/RustboroCity/scripts.pory"
	release
# 469 "data//maps/RustboroCity/scripts.pory"
	end
# 470 "data//maps/RustboroCity/scripts.pory"

# 471 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 472 "data//maps/RustboroCity/scripts.pory"
	waitse
# 473 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 474 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 475 "data//maps/RustboroCity/scripts.pory"
	end
# 476 "data//maps/RustboroCity/scripts.pory"

# 477 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 478 "data//maps/RustboroCity/scripts.pory"
	lockall
# 479 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 480 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 481 "data//maps/RustboroCity/scripts.pory"
	end
# 482 "data//maps/RustboroCity/scripts.pory"

# 483 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 484 "data//maps/RustboroCity/scripts.pory"
	lockall
# 485 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 486 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 487 "data//maps/RustboroCity/scripts.pory"
	end
# 488 "data//maps/RustboroCity/scripts.pory"

# 489 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 490 "data//maps/RustboroCity/scripts.pory"
	lockall
# 491 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 492 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 493 "data//maps/RustboroCity/scripts.pory"
	end
# 494 "data//maps/RustboroCity/scripts.pory"

# 495 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 496 "data//maps/RustboroCity/scripts.pory"
	lockall
# 497 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 498 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 499 "data//maps/RustboroCity/scripts.pory"
	end
# 500 "data//maps/RustboroCity/scripts.pory"

# 501 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 502 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 503 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 504 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 505 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 506 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 507 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 508 "data//maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 509 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 510 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 511 "data//maps/RustboroCity/scripts.pory"
	end
# 512 "data//maps/RustboroCity/scripts.pory"

# 513 "data//maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 514 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 515 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 516 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 517 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 518 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 519 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 520 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 521 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 522 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 523 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 524 "data//maps/RustboroCity/scripts.pory"
	return
# 525 "data//maps/RustboroCity/scripts.pory"

# 526 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 527 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 528 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 529 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 530 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 531 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 532 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 533 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 534 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 535 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 536 "data//maps/RustboroCity/scripts.pory"
	return
# 537 "data//maps/RustboroCity/scripts.pory"

# 538 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 539 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 540 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 541 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 542 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 543 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 544 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 545 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 546 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 547 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 548 "data//maps/RustboroCity/scripts.pory"
	return
# 549 "data//maps/RustboroCity/scripts.pory"

# 550 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 551 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 552 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 553 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 554 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 555 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 556 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 557 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 558 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 559 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 560 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 561 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 562 "data//maps/RustboroCity/scripts.pory"
	return
# 563 "data//maps/RustboroCity/scripts.pory"

# 564 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 565 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 566 "data//maps/RustboroCity/scripts.pory"
	step_end
# 567 "data//maps/RustboroCity/scripts.pory"

# 568 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 569 "data//maps/RustboroCity/scripts.pory"
	lockall
# 570 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 571 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 572 "data//maps/RustboroCity/scripts.pory"
	end
# 573 "data//maps/RustboroCity/scripts.pory"

# 574 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 575 "data//maps/RustboroCity/scripts.pory"
	lockall
# 576 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 577 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 578 "data//maps/RustboroCity/scripts.pory"
	end
# 579 "data//maps/RustboroCity/scripts.pory"

# 580 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 581 "data//maps/RustboroCity/scripts.pory"
	lockall
# 582 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 583 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 584 "data//maps/RustboroCity/scripts.pory"
	end
# 585 "data//maps/RustboroCity/scripts.pory"

# 586 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 587 "data//maps/RustboroCity/scripts.pory"
	lockall
# 588 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 589 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 590 "data//maps/RustboroCity/scripts.pory"
	end
# 591 "data//maps/RustboroCity/scripts.pory"

# 592 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 593 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 594 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 595 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 596 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 597 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 598 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 599 "data//maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 600 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 601 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 602 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 603 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 604 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 605 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 606 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 607 "data//maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 608 "data//maps/RustboroCity/scripts.pory"
	waitstate
# 609 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 610 "data//maps/RustboroCity/scripts.pory"
	end
# 611 "data//maps/RustboroCity/scripts.pory"

# 612 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 613 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 614 "data//maps/RustboroCity/scripts.pory"
	return
# 615 "data//maps/RustboroCity/scripts.pory"

# 616 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 617 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 618 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 619 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 620 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 621 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 622 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 623 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 624 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 625 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 626 "data//maps/RustboroCity/scripts.pory"
	return
# 627 "data//maps/RustboroCity/scripts.pory"

# 628 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 629 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 630 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 631 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 632 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 633 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 634 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 635 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 636 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 637 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 638 "data//maps/RustboroCity/scripts.pory"
	return
# 639 "data//maps/RustboroCity/scripts.pory"

# 640 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 641 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 642 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 643 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 644 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 645 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 646 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 647 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 648 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 649 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 650 "data//maps/RustboroCity/scripts.pory"
	return
# 651 "data//maps/RustboroCity/scripts.pory"

# 652 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 653 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 654 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 655 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 656 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 657 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 658 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 659 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 660 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 661 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 662 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 663 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 664 "data//maps/RustboroCity/scripts.pory"
	return
# 665 "data//maps/RustboroCity/scripts.pory"

# 666 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 667 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 668 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 669 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 670 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 671 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 672 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 673 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 674 "data//maps/RustboroCity/scripts.pory"
	return
# 675 "data//maps/RustboroCity/scripts.pory"

# 676 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 677 "data//maps/RustboroCity/scripts.pory"
	lockall
# 678 "data//maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 679 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 680 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 681 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 682 "data//maps/RustboroCity/scripts.pory"

# 683 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 684 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 685 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 686 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 687 "data//maps/RustboroCity/scripts.pory"
	return
# 688 "data//maps/RustboroCity/scripts.pory"

# 689 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 690 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 691 "data//maps/RustboroCity/scripts.pory"
	return
# 692 "data//maps/RustboroCity/scripts.pory"

# 693 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 694 "data//maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 695 "data//maps/RustboroCity/scripts.pory"
	return
# 696 "data//maps/RustboroCity/scripts.pory"

# 697 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 698 "data//maps/RustboroCity/scripts.pory"
	lockall
# 699 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 700 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 701 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 702 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 703 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 704 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 705 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 706 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 707 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 708 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 710 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 711 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 712 "data//maps/RustboroCity/scripts.pory"

# 713 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 714 "data//maps/RustboroCity/scripts.pory"
	lockall
# 715 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 716 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 717 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 718 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 719 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 720 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 721 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 722 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 723 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 724 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 725 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 726 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 727 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 728 "data//maps/RustboroCity/scripts.pory"

# 729 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 730 "data//maps/RustboroCity/scripts.pory"
	lockall
# 731 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 732 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 733 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 734 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 735 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 736 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 737 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 738 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 739 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 740 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 741 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 742 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 743 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 744 "data//maps/RustboroCity/scripts.pory"

# 745 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 746 "data//maps/RustboroCity/scripts.pory"
	lockall
# 747 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 748 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 749 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 750 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 751 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 752 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 753 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 754 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 755 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 756 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 757 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 758 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 759 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 760 "data//maps/RustboroCity/scripts.pory"

# 761 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 762 "data//maps/RustboroCity/scripts.pory"
	lockall
# 763 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 764 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 765 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 766 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 767 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 768 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 769 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 770 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 771 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 772 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 774 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 775 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 776 "data//maps/RustboroCity/scripts.pory"

# 777 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 778 "data//maps/RustboroCity/scripts.pory"
	lockall
# 779 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 780 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 781 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 782 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 783 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 784 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 785 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 786 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 787 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 788 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 790 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 791 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 792 "data//maps/RustboroCity/scripts.pory"

# 793 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 794 "data//maps/RustboroCity/scripts.pory"
	lockall
# 795 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 796 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 797 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 798 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 799 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 800 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 801 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 802 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 803 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 804 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 806 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 807 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 808 "data//maps/RustboroCity/scripts.pory"

# 809 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 810 "data//maps/RustboroCity/scripts.pory"
	lockall
# 811 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 812 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 813 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 814 "data//maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 815 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 816 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 817 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 818 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 819 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 820 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data//maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 822 "data//maps/RustboroCity/scripts.pory"
	waitmovement 0
# 823 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 824 "data//maps/RustboroCity/scripts.pory"

# 825 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 826 "data//maps/RustboroCity/scripts.pory"
	checkplayergender
# 827 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 828 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 829 "data//maps/RustboroCity/scripts.pory"
	end
# 830 "data//maps/RustboroCity/scripts.pory"

# 831 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 832 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 833 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 834 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 835 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 836 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 837 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 838 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 839 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 840 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 841 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 842 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 843 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 844 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 845 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 846 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 847 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 848 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 849 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 850 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 851 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 852 "data//maps/RustboroCity/scripts.pory"
	end
# 853 "data//maps/RustboroCity/scripts.pory"

# 854 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 855 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 856 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 857 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 858 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 859 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 860 "data//maps/RustboroCity/scripts.pory"
	end
# 861 "data//maps/RustboroCity/scripts.pory"

# 862 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 863 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 864 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 865 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartMayBattle
# 866 "data//maps/RustboroCity/scripts.pory"
	end
# 867 "data//maps/RustboroCity/scripts.pory"

# 868 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 869 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 870 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 871 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 872 "data//maps/RustboroCity/scripts.pory"
	end
# 873 "data//maps/RustboroCity/scripts.pory"

# 874 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 875 "data//maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 876 "data//maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 877 "data//maps/RustboroCity/scripts.pory"
	return
# 878 "data//maps/RustboroCity/scripts.pory"

# 879 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartMayBattle::
# 880 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, RustboroCity_Text_MayDefeat
# 881 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 882 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 883 "data//maps/RustboroCity/scripts.pory"
	end
# 884 "data//maps/RustboroCity/scripts.pory"

# 885 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 886 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 887 "data//maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 888 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 889 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 890 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 891 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 892 "data//maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 893 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 894 "data//maps/RustboroCity/scripts.pory"
	waitfanfare
# 895 "data//maps/RustboroCity/scripts.pory"
	closemessage
# 896 "data//maps/RustboroCity/scripts.pory"
	delay 30
# 897 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 898 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 899 "data//maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 900 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 901 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 902 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 903 "data//maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 904 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 905 "data//maps/RustboroCity/scripts.pory"
	end
# 906 "data//maps/RustboroCity/scripts.pory"

# 907 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 908 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 909 "data//maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 910 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 911 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 912 "data//maps/RustboroCity/scripts.pory"
	end
# 913 "data//maps/RustboroCity/scripts.pory"

# 914 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 915 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 916 "data//maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 917 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StartBrendanBattle
# 918 "data//maps/RustboroCity/scripts.pory"
	end
# 919 "data//maps/RustboroCity/scripts.pory"

# 920 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 921 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 922 "data//maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 923 "data//maps/RustboroCity/scripts.pory"
	releaseall
# 924 "data//maps/RustboroCity/scripts.pory"
	end
# 925 "data//maps/RustboroCity/scripts.pory"

# 926 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StartBrendanBattle::
# 927 "data//maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, RustboroCity_Text_BrendanDefeat
# 928 "data//maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 929 "data//maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 930 "data//maps/RustboroCity/scripts.pory"
	end
# 931 "data//maps/RustboroCity/scripts.pory"

# 932 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 933 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 934 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 935 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 936 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 937 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 938 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 939 "data//maps/RustboroCity/scripts.pory"
	step_end
# 940 "data//maps/RustboroCity/scripts.pory"

# 941 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 942 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 943 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 944 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 945 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 946 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 947 "data//maps/RustboroCity/scripts.pory"
	step_end
# 948 "data//maps/RustboroCity/scripts.pory"

# 949 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 950 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 951 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 952 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 953 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 954 "data//maps/RustboroCity/scripts.pory"
	step_end
# 955 "data//maps/RustboroCity/scripts.pory"

# 956 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 957 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 958 "data//maps/RustboroCity/scripts.pory"
	walk_left
# 959 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 960 "data//maps/RustboroCity/scripts.pory"
	step_end
# 961 "data//maps/RustboroCity/scripts.pory"

# 962 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 963 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 964 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 965 "data//maps/RustboroCity/scripts.pory"
	step_end
# 966 "data//maps/RustboroCity/scripts.pory"

# 967 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 968 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 969 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 970 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 971 "data//maps/RustboroCity/scripts.pory"
	step_end
# 972 "data//maps/RustboroCity/scripts.pory"

# 973 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 974 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 975 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 976 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 977 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 978 "data//maps/RustboroCity/scripts.pory"
	step_end
# 979 "data//maps/RustboroCity/scripts.pory"

# 980 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 981 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 982 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 983 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 984 "data//maps/RustboroCity/scripts.pory"
	walk_right
# 985 "data//maps/RustboroCity/scripts.pory"
	walk_down
# 986 "data//maps/RustboroCity/scripts.pory"
	step_end
# 987 "data//maps/RustboroCity/scripts.pory"

# 988 "data//maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 989 "data//maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 990 "data//maps/RustboroCity/scripts.pory"
	end
# 991 "data//maps/RustboroCity/scripts.pory"

# 992 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 993 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 994 "data//maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 995 "data//maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 996 "data//maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 997 "data//maps/RustboroCity/scripts.pory"

# 998 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 999 "data//maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1000 "data//maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1001 "data//maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1002 "data//maps/RustboroCity/scripts.pory"

# 1003 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1004 "data//maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1005 "data//maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1006 "data//maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1007 "data//maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1008 "data//maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1009 "data//maps/RustboroCity/scripts.pory"

# 1010 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1011 "data//maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1012 "data//maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1013 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1014 "data//maps/RustboroCity/scripts.pory"

# 1015 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1016 "data//maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1017 "data//maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1018 "data//maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1019 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1020 "data//maps/RustboroCity/scripts.pory"

# 1021 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1022 "data//maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1023 "data//maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1024 "data//maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1025 "data//maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1026 "data//maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1027 "data//maps/RustboroCity/scripts.pory"

# 1028 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1029 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1030 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1031 "data//maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1032 "data//maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1033 "data//maps/RustboroCity/scripts.pory"

# 1034 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1035 "data//maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1036 "data//maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1037 "data//maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1038 "data//maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1039 "data//maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1040 "data//maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1041 "data//maps/RustboroCity/scripts.pory"

# 1042 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1043 "data//maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1044 "data//maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1045 "data//maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1046 "data//maps/RustboroCity/scripts.pory"

# 1047 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1048 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1049 "data//maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1050 "data//maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1051 "data//maps/RustboroCity/scripts.pory"

# 1052 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1053 "data//maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1054 "data//maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1055 "data//maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1056 "data//maps/RustboroCity/scripts.pory"

# 1057 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1058 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1059 "data//maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1060 "data//maps/RustboroCity/scripts.pory"

# 1061 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1062 "data//maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1063 "data//maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1064 "data//maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1065 "data//maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1066 "data//maps/RustboroCity/scripts.pory"

# 1067 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1068 "data//maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1069 "data//maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1070 "data//maps/RustboroCity/scripts.pory"

# 1071 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1072 "data//maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1073 "data//maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1074 "data//maps/RustboroCity/scripts.pory"

# 1075 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1076 "data//maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1077 "data//maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1078 "data//maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1079 "data//maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1080 "data//maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1081 "data//maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1082 "data//maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1083 "data//maps/RustboroCity/scripts.pory"

# 1084 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1085 "data//maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1086 "data//maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1087 "data//maps/RustboroCity/scripts.pory"

# 1088 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1089 "data//maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1090 "data//maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1091 "data//maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1092 "data//maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1093 "data//maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1094 "data//maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1095 "data//maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1096 "data//maps/RustboroCity/scripts.pory"

# 1097 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1098 "data//maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1099 "data//maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1100 "data//maps/RustboroCity/scripts.pory"

# 1101 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1102 "data//maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1103 "data//maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1104 "data//maps/RustboroCity/scripts.pory"

# 1105 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1106 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1107 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1108 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1109 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1110 "data//maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1111 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1112 "data//maps/RustboroCity/scripts.pory"

# 1113 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1114 "data//maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1115 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1116 "data//maps/RustboroCity/scripts.pory"

# 1117 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1118 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1119 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1120 "data//maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1121 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1122 "data//maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1123 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1124 "data//maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1125 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1126 "data//maps/RustboroCity/scripts.pory"

# 1127 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1128 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1129 "data//maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1130 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1131 "data//maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1132 "data//maps/RustboroCity/scripts.pory"

# 1133 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1134 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1135 "data//maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1136 "data//maps/RustboroCity/scripts.pory"

# 1137 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1138 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1139 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1140 "data//maps/RustboroCity/scripts.pory"

# 1141 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1142 "data//maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1143 "data//maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1144 "data//maps/RustboroCity/scripts.pory"

# 1145 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1146 "data//maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1147 "data//maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1148 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1149 "data//maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1150 "data//maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1151 "data//maps/RustboroCity/scripts.pory"

# 1152 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1153 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1154 "data//maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1155 "data//maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1156 "data//maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1157 "data//maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1158 "data//maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1159 "data//maps/RustboroCity/scripts.pory"

# 1160 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1161 "data//maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1162 "data//maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1163 "data//maps/RustboroCity/scripts.pory"

# 1164 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1165 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1166 "data//maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1167 "data//maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1168 "data//maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1169 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1170 "data//maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1171 "data//maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1172 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1173 "data//maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1174 "data//maps/RustboroCity/scripts.pory"

# 1175 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1176 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1177 "data//maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1178 "data//maps/RustboroCity/scripts.pory"

# 1179 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1180 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1181 "data//maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1182 "data//maps/RustboroCity/scripts.pory"

# 1183 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1184 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1185 "data//maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1186 "data//maps/RustboroCity/scripts.pory"

# 1187 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1188 "data//maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1189 "data//maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1190 "data//maps/RustboroCity/scripts.pory"

# 1191 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1192 "data//maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1193 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1194 "data//maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1195 "data//maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1196 "data//maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1197 "data//maps/RustboroCity/scripts.pory"

# 1198 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1199 "data//maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1200 "data//maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1201 "data//maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1202 "data//maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1203 "data//maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1204 "data//maps/RustboroCity/scripts.pory"

# 1205 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1206 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1207 "data//maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1208 "data//maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1209 "data//maps/RustboroCity/scripts.pory"

# 1210 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1211 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1212 "data//maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1213 "data//maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1214 "data//maps/RustboroCity/scripts.pory"

# 1215 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1216 "data//maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1217 "data//maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1218 "data//maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1219 "data//maps/RustboroCity/scripts.pory"

# 1220 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1221 "data//maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1222 "data//maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1223 "data//maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1224 "data//maps/RustboroCity/scripts.pory"

# 1225 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1226 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1227 "data//maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1228 "data//maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1229 "data//maps/RustboroCity/scripts.pory"

# 1230 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1231 "data//maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1232 "data//maps/RustboroCity/scripts.pory"

# 1233 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1234 "data//maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1235 "data//maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1236 "data//maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1237 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1238 "data//maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1239 "data//maps/RustboroCity/scripts.pory"

# 1240 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1241 "data//maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1242 "data//maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1243 "data//maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1244 "data//maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1245 "data//maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1246 "data//maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1247 "data//maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1248 "data//maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1249 "data//maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1250 "data//maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1251 "data//maps/RustboroCity/scripts.pory"

# 1252 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1253 "data//maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1254 "data//maps/RustboroCity/scripts.pory"

# 1255 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1256 "data//maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1257 "data//maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1258 "data//maps/RustboroCity/scripts.pory"

# 1259 "data//maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1260 "data//maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1261 "data//maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1262 "data//maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1263 "data//maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1264 "data//maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1265 "data//maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1266 "data//maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1267 "data//maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"
