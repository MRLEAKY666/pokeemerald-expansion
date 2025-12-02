# 1 "data//maps/LavaridgeTown/scripts.pory"

# 2 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 3 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 4 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 5 "data//maps/LavaridgeTown/scripts.pory"
	.byte 0
# 6 "data//maps/LavaridgeTown/scripts.pory"

# 7 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 8 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 9 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 10 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 11 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_0x8008, 4
# 12 "data//maps/LavaridgeTown/scripts.pory"
	call_if_unset FLAG_DEFEATED_LAVARIDGE_GYM, Common_EventScript_ResetGymTrainers
# 13 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 14 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 15 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 16 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 17 "data//maps/LavaridgeTown/scripts.pory"
	end
# 18 "data//maps/LavaridgeTown/scripts.pory"

# 19 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 20 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 21 "data//maps/LavaridgeTown/scripts.pory"
	return
# 22 "data//maps/LavaridgeTown/scripts.pory"

# 23 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 24 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 25 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 21, LavaridgeTown_EventScript_SetRivalPos
# 26 "data//maps/LavaridgeTown/scripts.pory"
	return
# 27 "data//maps/LavaridgeTown/scripts.pory"

# 28 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 29 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 23, 21
# 30 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 21, 20
# 31 "data//maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 32 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 33 "data//maps/LavaridgeTown/scripts.pory"
	return
# 34 "data//maps/LavaridgeTown/scripts.pory"

# 35 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 36 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 37 "data//maps/LavaridgeTown/scripts.pory"
	return
# 38 "data//maps/LavaridgeTown/scripts.pory"

# 39 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 40 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 41 "data//maps/LavaridgeTown/scripts.pory"
	return
# 42 "data//maps/LavaridgeTown/scripts.pory"

# 43 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 44 "data//maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 45 "data//maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 46 "data//maps/LavaridgeTown/scripts.pory"

# 47 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 48 "data//maps/LavaridgeTown/scripts.pory"
	lockall
# 49 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 50 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalNoticePlayer
# 51 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExitHerbShop
# 52 "data//maps/LavaridgeTown/scripts.pory"
	delay 20
# 53 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 54 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 55 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 56 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalApproachPlayer1
# 57 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalApproachPlayer2
# 58 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 59 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 60 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 61 "data//maps/LavaridgeTown/scripts.pory"
	end
# 62 "data//maps/LavaridgeTown/scripts.pory"

# 63 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 64 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 65 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 66 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 67 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 68 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 69 "data//maps/LavaridgeTown/scripts.pory"
	end
# 70 "data//maps/LavaridgeTown/scripts.pory"

# 71 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 72 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 73 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 74 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 75 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 76 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 77 "data//maps/LavaridgeTown/scripts.pory"
	end
# 78 "data//maps/LavaridgeTown/scripts.pory"

# 79 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 80 "data//maps/LavaridgeTown/scripts.pory"
	closemessage
# 81 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 82 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 83 "data//maps/LavaridgeTown/scripts.pory"
	delay 30
# 84 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExit1
# 85 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 21, LavaridgeTown_EventScript_RivalExit2
# 86 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 87 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 88 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 89 "data//maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 90 "data//maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 91 "data//maps/LavaridgeTown/scripts.pory"
	releaseall
# 92 "data//maps/LavaridgeTown/scripts.pory"
	end
# 93 "data//maps/LavaridgeTown/scripts.pory"

# 94 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 95 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 96 "data//maps/LavaridgeTown/scripts.pory"
	return
# 97 "data//maps/LavaridgeTown/scripts.pory"

# 98 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 99 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 100 "data//maps/LavaridgeTown/scripts.pory"
	return
# 101 "data//maps/LavaridgeTown/scripts.pory"

# 102 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 103 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 104 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 105 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 106 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 107 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 108 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 109 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 110 "data//maps/LavaridgeTown/scripts.pory"
	return
# 111 "data//maps/LavaridgeTown/scripts.pory"

# 112 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 113 "data//maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 114 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 115 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL
# 116 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 117 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 118 "data//maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 119 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 120 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 121 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 122 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 123 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 124 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 125 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 126 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 127 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 128 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 129 "data//maps/LavaridgeTown/scripts.pory"
	return
# 130 "data//maps/LavaridgeTown/scripts.pory"

# 131 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 132 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 133 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 134 "data//maps/LavaridgeTown/scripts.pory"
	return
# 135 "data//maps/LavaridgeTown/scripts.pory"

# 136 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 137 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 138 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 139 "data//maps/LavaridgeTown/scripts.pory"
	return
# 140 "data//maps/LavaridgeTown/scripts.pory"

# 141 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 142 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 143 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 144 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 145 "data//maps/LavaridgeTown/scripts.pory"
	return
# 146 "data//maps/LavaridgeTown/scripts.pory"

# 147 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 148 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 149 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 150 "data//maps/LavaridgeTown/scripts.pory"
	return
# 151 "data//maps/LavaridgeTown/scripts.pory"

# 152 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SaunaAttendant::
# 153 "data//maps/LavaridgeTown/scripts.pory"
	lock
# 154 "data//maps/LavaridgeTown/scripts.pory"
	faceplayer
# 155 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_SaunaAttendant, MSGBOX_DEFAULT
# 156 "data//maps/LavaridgeTown/scripts.pory"
	waitse
# 157 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_SAUNA_ATTENDANT, Common_Movement_FaceOriginalDirection
# 158 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 159 "data//maps/LavaridgeTown/scripts.pory"
	release
# 160 "data//maps/LavaridgeTown/scripts.pory"
	end
# 161 "data//maps/LavaridgeTown/scripts.pory"

# 162 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_SaunaAttendant:
# 163 "data//maps/LavaridgeTown/scripts.pory"
	.string "Through here is the SAUNA.\p"
# 164 "data//maps/LavaridgeTown/scripts.pory"
	.string "Feel free to spend some time in there,\n"
# 165 "data//maps/LavaridgeTown/scripts.pory"
	.string "but our other patrons strongly prefer\l"
# 166 "data//maps/LavaridgeTown/scripts.pory"
	.string "to be left alone.$"
# 167 "data//maps/LavaridgeTown/scripts.pory"

# 168 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 169 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 170 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 171 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 172 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 173 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 174 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 175 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 176 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 177 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 178 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 179 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 180 "data//maps/LavaridgeTown/scripts.pory"

# 181 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 182 "data//maps/LavaridgeTown/scripts.pory"
	delay_16
# 183 "data//maps/LavaridgeTown/scripts.pory"
	delay_8
# 184 "data//maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 185 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 186 "data//maps/LavaridgeTown/scripts.pory"

# 187 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 188 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 189 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 190 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 191 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 192 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 193 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 194 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 195 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 196 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 197 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 198 "data//maps/LavaridgeTown/scripts.pory"

# 199 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 200 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 201 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 202 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 203 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 204 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 205 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 206 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 207 "data//maps/LavaridgeTown/scripts.pory"

# 208 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 209 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 210 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 211 "data//maps/LavaridgeTown/scripts.pory"
	walk_up
# 212 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 213 "data//maps/LavaridgeTown/scripts.pory"

# 214 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 215 "data//maps/LavaridgeTown/scripts.pory"
	walk_down
# 216 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 217 "data//maps/LavaridgeTown/scripts.pory"

# 218 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 219 "data//maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 220 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 221 "data//maps/LavaridgeTown/scripts.pory"
	end
# 222 "data//maps/LavaridgeTown/scripts.pory"

# 223 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 224 "data//maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 225 "data//maps/LavaridgeTown/scripts.pory"
	end
# 226 "data//maps/LavaridgeTown/scripts.pory"

# 227 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 228 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 229 "data//maps/LavaridgeTown/scripts.pory"
	end
# 230 "data//maps/LavaridgeTown/scripts.pory"

# 231 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 232 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 233 "data//maps/LavaridgeTown/scripts.pory"
	end
# 234 "data//maps/LavaridgeTown/scripts.pory"

# 235 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 236 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 237 "data//maps/LavaridgeTown/scripts.pory"
	end
# 238 "data//maps/LavaridgeTown/scripts.pory"

# 239 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 240 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 241 "data//maps/LavaridgeTown/scripts.pory"
	end
# 242 "data//maps/LavaridgeTown/scripts.pory"

# 243 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 244 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 245 "data//maps/LavaridgeTown/scripts.pory"
	end
# 246 "data//maps/LavaridgeTown/scripts.pory"

# 247 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 248 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 249 "data//maps/LavaridgeTown/scripts.pory"
	end
# 250 "data//maps/LavaridgeTown/scripts.pory"

# 251 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 252 "data//maps/LavaridgeTown/scripts.pory"
	lock
# 253 "data//maps/LavaridgeTown/scripts.pory"
	faceplayer
# 254 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 255 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 256 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 257 "data//maps/LavaridgeTown/scripts.pory"
	getpartysize
# 258 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 259 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 260 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 261 "data//maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 262 "data//maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 263 "data//maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 264 "data//maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 265 "data//maps/LavaridgeTown/scripts.pory"
	release
# 266 "data//maps/LavaridgeTown/scripts.pory"
	end
# 267 "data//maps/LavaridgeTown/scripts.pory"

# 268 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 269 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 270 "data//maps/LavaridgeTown/scripts.pory"
	release
# 271 "data//maps/LavaridgeTown/scripts.pory"
	end
# 272 "data//maps/LavaridgeTown/scripts.pory"

# 273 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 274 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 275 "data//maps/LavaridgeTown/scripts.pory"
	release
# 276 "data//maps/LavaridgeTown/scripts.pory"
	end
# 277 "data//maps/LavaridgeTown/scripts.pory"

# 278 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 279 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 280 "data//maps/LavaridgeTown/scripts.pory"
	release
# 281 "data//maps/LavaridgeTown/scripts.pory"
	end
# 282 "data//maps/LavaridgeTown/scripts.pory"

# 283 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 284 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 285 "data//maps/LavaridgeTown/scripts.pory"
	end
# 286 "data//maps/LavaridgeTown/scripts.pory"

# 287 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 288 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 289 "data//maps/LavaridgeTown/scripts.pory"
	end
# 290 "data//maps/LavaridgeTown/scripts.pory"

# 291 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 292 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 293 "data//maps/LavaridgeTown/scripts.pory"
	end
# 294 "data//maps/LavaridgeTown/scripts.pory"

# 295 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 296 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 297 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 298 "data//maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 299 "data//maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 300 "data//maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 301 "data//maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 302 "data//maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 303 "data//maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 304 "data//maps/LavaridgeTown/scripts.pory"

# 305 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 306 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 307 "data//maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 308 "data//maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 309 "data//maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 310 "data//maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 311 "data//maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 312 "data//maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 313 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 314 "data//maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 315 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 316 "data//maps/LavaridgeTown/scripts.pory"

# 317 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 318 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 319 "data//maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 320 "data//maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 321 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 322 "data//maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 323 "data//maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 324 "data//maps/LavaridgeTown/scripts.pory"

# 325 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 326 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 327 "data//maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 328 "data//maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 329 "data//maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 330 "data//maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 331 "data//maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 332 "data//maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 333 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 334 "data//maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 335 "data//maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 336 "data//maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 337 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 338 "data//maps/LavaridgeTown/scripts.pory"

# 339 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 340 "data//maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 341 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 342 "data//maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 343 "data//maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 344 "data//maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 345 "data//maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 346 "data//maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 347 "data//maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 348 "data//maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 349 "data//maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 350 "data//maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 351 "data//maps/LavaridgeTown/scripts.pory"

# 352 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 353 "data//maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 354 "data//maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 355 "data//maps/LavaridgeTown/scripts.pory"

# 356 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 357 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 358 "data//maps/LavaridgeTown/scripts.pory"

# 359 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 360 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 361 "data//maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 362 "data//maps/LavaridgeTown/scripts.pory"

# 363 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 364 "data//maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 365 "data//maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 366 "data//maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 367 "data//maps/LavaridgeTown/scripts.pory"

# 368 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 369 "data//maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 370 "data//maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 371 "data//maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 372 "data//maps/LavaridgeTown/scripts.pory"

# 373 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 374 "data//maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 375 "data//maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 376 "data//maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 377 "data//maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 378 "data//maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 379 "data//maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 380 "data//maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 381 "data//maps/LavaridgeTown/scripts.pory"

# 382 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 383 "data//maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 384 "data//maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 385 "data//maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 386 "data//maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 387 "data//maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 388 "data//maps/LavaridgeTown/scripts.pory"

# 389 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 390 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 391 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 392 "data//maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 393 "data//maps/LavaridgeTown/scripts.pory"

# 394 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 395 "data//maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 396 "data//maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 397 "data//maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 398 "data//maps/LavaridgeTown/scripts.pory"

# 399 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 400 "data//maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 401 "data//maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 402 "data//maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 403 "data//maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 404 "data//maps/LavaridgeTown/scripts.pory"

# 405 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 406 "data//maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 407 "data//maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 408 "data//maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 409 "data//maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 410 "data//maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 411 "data//maps/LavaridgeTown/scripts.pory"

# 412 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 413 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 414 "data//maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 415 "data//maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 416 "data//maps/LavaridgeTown/scripts.pory"

# 417 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 418 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 419 "data//maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 420 "data//maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 421 "data//maps/LavaridgeTown/scripts.pory"

# 422 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 423 "data//maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 424 "data//maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
