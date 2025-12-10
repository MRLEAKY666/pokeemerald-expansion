# 1 "data//maps/LavaridgeTown/scripts.pory"

# 2 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 3 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 4 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LavaridgeTown_OnWarp
# 5 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 6 "data//maps/LavaridgeTown/scripts.pory"
	.byte 0
# 7 "data//maps/LavaridgeTown/scripts.pory"

# 8 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 9 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 10 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 11 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 12 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_0x8008, 4
# 13 "data//maps/LavaridgeTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_LAVARIDGE_GYM, Common_EventScript_ResetGymTrainers
# 14 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 15 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 16 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 17 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 18 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1, LavaridgeTown_EventScript_TryClearBreakNurseFlag
# 19 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 20 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_TEMP_F, 7, LavaridgeTown_EventScript_HideMapNamePopup
# 21 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_TEMP_F, 7, LavaridgeTown_EventScript_SetupKickedOutOfSaunaLecture
# 22 "data//maps/LavaridgeTown/scripts.pory"
	end

LavaridgeTown_EventScript_TryClearBreakNurseFlag::
# 27 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_LAVARIDGE_BREAK_NURSE, LavaridgeTown_EventScript_TryClearBreakNurseFlag_2
LavaridgeTown_EventScript_TryClearBreakNurseFlag_1:
	return

LavaridgeTown_EventScript_TryClearBreakNurseFlag_2:
# 28 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_LAVARIDGE_BREAK_NURSE
	goto LavaridgeTown_EventScript_TryClearBreakNurseFlag_1


# 33 "data//maps/LavaridgeTown/scripts.pory"

# 34 "data//maps/LavaridgeTown/scripts.pory"

# 35 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 36 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 37 "data//maps/LavaridgeTown/scripts.pory"
	return
# 38 "data//maps/LavaridgeTown/scripts.pory"

# 39 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 40 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 41 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 21, LavaridgeTown_EventScript_SetRivalPos
# 42 "data//maps/LavaridgeTown/scripts.pory"
	return
# 43 "data//maps/LavaridgeTown/scripts.pory"

# 44 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 45 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 23, 21
# 46 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 21, 20
# 47 "data//maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 48 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 49 "data//maps/LavaridgeTown/scripts.pory"
	return
# 50 "data//maps/LavaridgeTown/scripts.pory"

# 51 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 52 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 53 "data//maps/LavaridgeTown/scripts.pory"
	return
# 54 "data//maps/LavaridgeTown/scripts.pory"

# 55 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 56 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 57 "data//maps/LavaridgeTown/scripts.pory"
	return
# 58 "data//maps/LavaridgeTown/scripts.pory"

# 59 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetupKickedOutOfSaunaLecture:
# 60 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_TEMP_4, 1
# 61 "data//maps/LavaridgeTown/scripts.pory"
	return
# 62 "data//maps/LavaridgeTown/scripts.pory"

# 63 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnWarp:
# 64 "data//maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_TEMP_4, 1, LavaridgeTown_EventScript_SetupSaunaLecture2
# 65 "data//maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 66 "data//maps/LavaridgeTown/scripts.pory"

# 67 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetupSaunaLecture2::
# 68 "data//maps/LavaridgeTown/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 69 "data//maps/LavaridgeTown/scripts.pory"
	end
# 70 "data//maps/LavaridgeTown/scripts.pory"

# 71 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 72 "data//maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 73 "data//maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_TEMP_4, 1, LavaridgeTown_EventScript_KickedOutOfSauna
# 74 "data//maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 75 "data//maps/LavaridgeTown/scripts.pory"

# 76 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 77 "data//maps/LavaridgeTown/scripts.pory"
	lockall
# 78 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 79 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalNoticePlayer
# 80 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExitHerbShop
# 81 "data//maps/LavaridgeTown/scripts.pory"
	delay 20
# 82 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 83 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 84 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 85 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalApproachPlayer1
# 86 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalApproachPlayer2
# 87 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 88 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 89 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 90 "data//maps/LavaridgeTown/scripts.pory"
	end
# 91 "data//maps/LavaridgeTown/scripts.pory"

# 92 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 93 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 94 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 95 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 96 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 97 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 98 "data//maps/LavaridgeTown/scripts.pory"
	end
# 99 "data//maps/LavaridgeTown/scripts.pory"

# 100 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 101 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 102 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 103 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 104 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 105 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 106 "data//maps/LavaridgeTown/scripts.pory"
	end
# 107 "data//maps/LavaridgeTown/scripts.pory"

# 108 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 109 "data//maps/LavaridgeTown/scripts.pory"
	closemessage
# 110 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 111 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 112 "data//maps/LavaridgeTown/scripts.pory"
	delay 30
# 113 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExit1
# 114 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExit2
# 115 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 116 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 117 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 118 "data//maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 119 "data//maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 120 "data//maps/LavaridgeTown/scripts.pory"
	releaseall
# 121 "data//maps/LavaridgeTown/scripts.pory"
	end
# 122 "data//maps/LavaridgeTown/scripts.pory"

# 123 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 124 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 125 "data//maps/LavaridgeTown/scripts.pory"
	return
# 126 "data//maps/LavaridgeTown/scripts.pory"

# 127 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 128 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 129 "data//maps/LavaridgeTown/scripts.pory"
	return
# 130 "data//maps/LavaridgeTown/scripts.pory"

# 131 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 132 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 133 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 134 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 135 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 136 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 137 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 138 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 139 "data//maps/LavaridgeTown/scripts.pory"
	return
# 140 "data//maps/LavaridgeTown/scripts.pory"

# 141 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 142 "data//maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 143 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 144 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL
# 145 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 146 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 147 "data//maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 148 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 149 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 150 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 151 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 152 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 153 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 154 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 155 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 156 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 157 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 158 "data//maps/LavaridgeTown/scripts.pory"
	return
# 159 "data//maps/LavaridgeTown/scripts.pory"

# 160 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 161 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 162 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 163 "data//maps/LavaridgeTown/scripts.pory"
	return
# 164 "data//maps/LavaridgeTown/scripts.pory"

# 165 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 166 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 167 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 168 "data//maps/LavaridgeTown/scripts.pory"
	return
# 169 "data//maps/LavaridgeTown/scripts.pory"

# 170 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 171 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 172 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 173 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 174 "data//maps/LavaridgeTown/scripts.pory"
	return
# 175 "data//maps/LavaridgeTown/scripts.pory"

# 176 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 177 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 178 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 179 "data//maps/LavaridgeTown/scripts.pory"
	return
# 180 "data//maps/LavaridgeTown/scripts.pory"

# 181 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SaunaAttendant::
# 182 "data//maps/LavaridgeTown/scripts.pory"
	lock
# 183 "data//maps/LavaridgeTown/scripts.pory"
	faceplayer
# 184 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_SaunaAttendant, MSGBOX_DEFAULT
# 185 "data//maps/LavaridgeTown/scripts.pory"
	waitse
# 186 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_SAUNA_ATTENDANT, Common_Movement_FaceOriginalDirection
# 187 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 188 "data//maps/LavaridgeTown/scripts.pory"
	release
# 189 "data//maps/LavaridgeTown/scripts.pory"
	end
# 190 "data//maps/LavaridgeTown/scripts.pory"

# 191 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_SaunaAttendant:
# 192 "data//maps/LavaridgeTown/scripts.pory"
	.string "Through here is the SAUNA.\p"
# 193 "data//maps/LavaridgeTown/scripts.pory"
	.string "Feel free to spend some time in there,\n"
# 194 "data//maps/LavaridgeTown/scripts.pory"
	.string "but remember to respect the peace\l"
# 195 "data//maps/LavaridgeTown/scripts.pory"
	.string "and relaxation of our other patrons.$"
# 196 "data//maps/LavaridgeTown/scripts.pory"

# 197 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 198 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 199 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 200 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 201 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 202 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 203 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 204 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 205 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 206 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 207 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 208 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 209 "data//maps/LavaridgeTown/scripts.pory"

# 210 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 211 "data//maps/LavaridgeTown/scripts.pory"
	delay_16
# 212 "data//maps/LavaridgeTown/scripts.pory"
	delay_8
# 213 "data//maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 214 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 215 "data//maps/LavaridgeTown/scripts.pory"

# 216 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 217 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 218 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 219 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 220 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 221 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 222 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 223 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 224 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 225 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 226 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 227 "data//maps/LavaridgeTown/scripts.pory"

# 228 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 229 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 230 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 231 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 232 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 233 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 234 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 235 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 236 "data//maps/LavaridgeTown/scripts.pory"

# 237 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 238 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 239 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 240 "data//maps/LavaridgeTown/scripts.pory"
	walk_up
# 241 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 242 "data//maps/LavaridgeTown/scripts.pory"

# 243 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 244 "data//maps/LavaridgeTown/scripts.pory"
	walk_down
# 245 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 246 "data//maps/LavaridgeTown/scripts.pory"

# 247 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 248 "data//maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 249 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 250 "data//maps/LavaridgeTown/scripts.pory"
	end
# 251 "data//maps/LavaridgeTown/scripts.pory"

# 252 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 253 "data//maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 254 "data//maps/LavaridgeTown/scripts.pory"
	end
# 255 "data//maps/LavaridgeTown/scripts.pory"

# 256 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 257 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 258 "data//maps/LavaridgeTown/scripts.pory"
	end
# 259 "data//maps/LavaridgeTown/scripts.pory"

# 260 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 261 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 262 "data//maps/LavaridgeTown/scripts.pory"
	end
# 263 "data//maps/LavaridgeTown/scripts.pory"

# 264 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 265 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 266 "data//maps/LavaridgeTown/scripts.pory"
	end
# 267 "data//maps/LavaridgeTown/scripts.pory"

# 268 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 269 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 270 "data//maps/LavaridgeTown/scripts.pory"
	end
# 271 "data//maps/LavaridgeTown/scripts.pory"

# 272 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 273 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 274 "data//maps/LavaridgeTown/scripts.pory"
	end
# 275 "data//maps/LavaridgeTown/scripts.pory"

# 276 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman3::
# 277 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EveryoneAlwaysTraipsing, MSGBOX_NPC
# 278 "data//maps/LavaridgeTown/scripts.pory"
	end
# 279 "data//maps/LavaridgeTown/scripts.pory"

# 280 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman4::
# 281 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_SaunaMenRetired, MSGBOX_NPC
# 282 "data//maps/LavaridgeTown/scripts.pory"
	end
# 283 "data//maps/LavaridgeTown/scripts.pory"

# 284 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 285 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 286 "data//maps/LavaridgeTown/scripts.pory"
	end
# 287 "data//maps/LavaridgeTown/scripts.pory"

# 288 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 289 "data//maps/LavaridgeTown/scripts.pory"
	lock
# 290 "data//maps/LavaridgeTown/scripts.pory"
	faceplayer
# 291 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 292 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 293 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 294 "data//maps/LavaridgeTown/scripts.pory"
	getpartysize
# 295 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 296 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 297 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 298 "data//maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 299 "data//maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 300 "data//maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 301 "data//maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 302 "data//maps/LavaridgeTown/scripts.pory"
	release
# 303 "data//maps/LavaridgeTown/scripts.pory"
	end
# 304 "data//maps/LavaridgeTown/scripts.pory"

# 305 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 306 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 307 "data//maps/LavaridgeTown/scripts.pory"
	release
# 308 "data//maps/LavaridgeTown/scripts.pory"
	end
# 309 "data//maps/LavaridgeTown/scripts.pory"

# 310 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 311 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 312 "data//maps/LavaridgeTown/scripts.pory"
	release
# 313 "data//maps/LavaridgeTown/scripts.pory"
	end
# 314 "data//maps/LavaridgeTown/scripts.pory"

# 315 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 316 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 317 "data//maps/LavaridgeTown/scripts.pory"
	release
# 318 "data//maps/LavaridgeTown/scripts.pory"
	end
# 319 "data//maps/LavaridgeTown/scripts.pory"

# 320 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 321 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 322 "data//maps/LavaridgeTown/scripts.pory"
	end
# 323 "data//maps/LavaridgeTown/scripts.pory"

# 324 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 325 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 326 "data//maps/LavaridgeTown/scripts.pory"
	end
# 327 "data//maps/LavaridgeTown/scripts.pory"

# 328 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 329 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 330 "data//maps/LavaridgeTown/scripts.pory"
	end
# 331 "data//maps/LavaridgeTown/scripts.pory"

# 332 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_KickedOutOfSauna::
# 333 "data//maps/LavaridgeTown/scripts.pory"
	@ lock
# 334 "data//maps/LavaridgeTown/scripts.pory"
	@ applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 335 "data//maps/LavaridgeTown/scripts.pory"
	@ fadescreen FADE_FROM_WHITE
# 336 "data//maps/LavaridgeTown/scripts.pory"
	delay 30
# 337 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_SAUNA_ATTENDANT, Common_Movement_WalkInPlaceDown
# 338 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_KickedOutOfSauna, MSGBOX_NPC
# 339 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_TEMP_4, 0
# 340 "data//maps/LavaridgeTown/scripts.pory"
	release
# 341 "data//maps/LavaridgeTown/scripts.pory"
	end
# 342 "data//maps/LavaridgeTown/scripts.pory"

# 343 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_KickedOutOfSauna:
# 344 "data//maps/LavaridgeTown/scripts.pory"
	.string "The sauna is open to anyone, but\n"
# 345 "data//maps/LavaridgeTown/scripts.pory"
	.string "relaxation is very important to\l"
# 346 "data//maps/LavaridgeTown/scripts.pory"
	.string "our guests.\p"
# 347 "data//maps/LavaridgeTown/scripts.pory"
	.string "That means you aren't allowed to waltz\n"
# 348 "data//maps/LavaridgeTown/scripts.pory"
	.string "in and bother everybody like that.\p"
# 349 "data//maps/LavaridgeTown/scripts.pory"
	.string "If you want to use the sauna, you need\n"
# 350 "data//maps/LavaridgeTown/scripts.pory"
	.string "to be respectful;\p"
# 351 "data//maps/LavaridgeTown/scripts.pory"
	.string "give other guests their personal space,\n"
# 352 "data//maps/LavaridgeTown/scripts.pory"
	.string "and don't make too much noise!\p"
# 353 "data//maps/LavaridgeTown/scripts.pory"
	.string "Think of it like a sweaty library…\l"
# 354 "data//maps/LavaridgeTown/scripts.pory"
	.string "With no books.\p"
# 355 "data//maps/LavaridgeTown/scripts.pory"
	.string "This should all be common sense, but\n"
# 356 "data//maps/LavaridgeTown/scripts.pory"
	.string "today's youth just have no respect\l"
# 357 "data//maps/LavaridgeTown/scripts.pory"
	.string "for authority,\p"
# 358 "data//maps/LavaridgeTown/scripts.pory"
	.string "or their elders!$"
# 359 "data//maps/LavaridgeTown/scripts.pory"

# 360 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 361 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 362 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 363 "data//maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 364 "data//maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 365 "data//maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 366 "data//maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 367 "data//maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 368 "data//maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 369 "data//maps/LavaridgeTown/scripts.pory"

# 370 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 371 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 372 "data//maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 373 "data//maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 374 "data//maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 375 "data//maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 376 "data//maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 377 "data//maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 378 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 379 "data//maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 380 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 381 "data//maps/LavaridgeTown/scripts.pory"

# 382 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 383 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 384 "data//maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 385 "data//maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 386 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 387 "data//maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 388 "data//maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 389 "data//maps/LavaridgeTown/scripts.pory"

# 390 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 391 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 392 "data//maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 393 "data//maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 394 "data//maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 395 "data//maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 396 "data//maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 397 "data//maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 398 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 399 "data//maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 400 "data//maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 401 "data//maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 402 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 403 "data//maps/LavaridgeTown/scripts.pory"

# 404 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 405 "data//maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 406 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 407 "data//maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 408 "data//maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 409 "data//maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 410 "data//maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 411 "data//maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 412 "data//maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 413 "data//maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 414 "data//maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 415 "data//maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 416 "data//maps/LavaridgeTown/scripts.pory"

# 417 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 418 "data//maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 419 "data//maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 420 "data//maps/LavaridgeTown/scripts.pory"

# 421 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 422 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 423 "data//maps/LavaridgeTown/scripts.pory"

# 424 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 425 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 426 "data//maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 427 "data//maps/LavaridgeTown/scripts.pory"

# 428 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 429 "data//maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 430 "data//maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 431 "data//maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 432 "data//maps/LavaridgeTown/scripts.pory"

# 433 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 434 "data//maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 435 "data//maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 436 "data//maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 437 "data//maps/LavaridgeTown/scripts.pory"

# 438 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 439 "data//maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 440 "data//maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 441 "data//maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 442 "data//maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 443 "data//maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 444 "data//maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 445 "data//maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 446 "data//maps/LavaridgeTown/scripts.pory"

# 447 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 448 "data//maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 449 "data//maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 450 "data//maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 451 "data//maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 452 "data//maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 453 "data//maps/LavaridgeTown/scripts.pory"

# 454 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 455 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 456 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 457 "data//maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 458 "data//maps/LavaridgeTown/scripts.pory"

# 459 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 460 "data//maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 461 "data//maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 462 "data//maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 463 "data//maps/LavaridgeTown/scripts.pory"

# 464 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 465 "data//maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 466 "data//maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 467 "data//maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 468 "data//maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 469 "data//maps/LavaridgeTown/scripts.pory"

# 470 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 471 "data//maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 472 "data//maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 473 "data//maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 474 "data//maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 475 "data//maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 476 "data//maps/LavaridgeTown/scripts.pory"

# 477 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EveryoneAlwaysTraipsing:
# 478 "data//maps/LavaridgeTown/scripts.pory"
	.string "People are always traipsing through\n"
# 479 "data//maps/LavaridgeTown/scripts.pory"
	.string "this pool on their way to the sauna…\p"
# 480 "data//maps/LavaridgeTown/scripts.pory"
	.string "You and everyone else are diluting my\n"
# 481 "data//maps/LavaridgeTown/scripts.pory"
	.string "hot water!$"
# 482 "data//maps/LavaridgeTown/scripts.pory"

# 483 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_SaunaMenRetired:
# 484 "data//maps/LavaridgeTown/scripts.pory"
	.string "The sauna is full of grumpy old men.\p"
# 485 "data//maps/LavaridgeTown/scripts.pory"
	.string "They spend all their time in there,\n"
# 486 "data//maps/LavaridgeTown/scripts.pory"
	.string "so you'd think they'd be more relaxed…$"
# 487 "data//maps/LavaridgeTown/scripts.pory"

# 488 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 489 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 490 "data//maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 491 "data//maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 492 "data//maps/LavaridgeTown/scripts.pory"

# 493 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 494 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 495 "data//maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 496 "data//maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 497 "data//maps/LavaridgeTown/scripts.pory"

# 498 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 499 "data//maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 500 "data//maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
