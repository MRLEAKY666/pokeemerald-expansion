# 1 "data//maps/LavaridgeTown/scripts.pory"

# 2 "data//maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 7
# 3 "data//maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL, 8
# 4 "data//maps/LavaridgeTown/scripts.pory"

# 5 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 6 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 7 "data//maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 8 "data//maps/LavaridgeTown/scripts.pory"
	.byte 0
# 9 "data//maps/LavaridgeTown/scripts.pory"

# 10 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 11 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 12 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 13 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 14 "data//maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 15 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 16 "data//maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 17 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 18 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 19 "data//maps/LavaridgeTown/scripts.pory"
	end
# 20 "data//maps/LavaridgeTown/scripts.pory"

# 21 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 22 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 23 "data//maps/LavaridgeTown/scripts.pory"
	return
# 24 "data//maps/LavaridgeTown/scripts.pory"

# 25 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 26 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 27 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 28 "data//maps/LavaridgeTown/scripts.pory"
	return
# 29 "data//maps/LavaridgeTown/scripts.pory"

# 30 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 31 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 11, 9
# 32 "data//maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
# 33 "data//maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 34 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 35 "data//maps/LavaridgeTown/scripts.pory"
	return
# 36 "data//maps/LavaridgeTown/scripts.pory"

# 37 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 38 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 39 "data//maps/LavaridgeTown/scripts.pory"
	return
# 40 "data//maps/LavaridgeTown/scripts.pory"

# 41 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 42 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 43 "data//maps/LavaridgeTown/scripts.pory"
	return
# 44 "data//maps/LavaridgeTown/scripts.pory"

# 45 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 46 "data//maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 47 "data//maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 48 "data//maps/LavaridgeTown/scripts.pory"

# 49 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 50 "data//maps/LavaridgeTown/scripts.pory"
	lockall
# 51 "data//maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 52 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 53 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 54 "data//maps/LavaridgeTown/scripts.pory"
	delay 20
# 55 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 56 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 57 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 58 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 59 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 60 "data//maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 61 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 62 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 63 "data//maps/LavaridgeTown/scripts.pory"
	end
# 64 "data//maps/LavaridgeTown/scripts.pory"

# 65 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 66 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 67 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 68 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 69 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 70 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 71 "data//maps/LavaridgeTown/scripts.pory"
	end
# 72 "data//maps/LavaridgeTown/scripts.pory"

# 73 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 74 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 75 "data//maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 76 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 77 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 78 "data//maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 79 "data//maps/LavaridgeTown/scripts.pory"
	end
# 80 "data//maps/LavaridgeTown/scripts.pory"

# 81 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 82 "data//maps/LavaridgeTown/scripts.pory"
	closemessage
# 83 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 84 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 85 "data//maps/LavaridgeTown/scripts.pory"
	delay 30
# 86 "data//maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 87 "data//maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 88 "data//maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 89 "data//maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 90 "data//maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 91 "data//maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 92 "data//maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 93 "data//maps/LavaridgeTown/scripts.pory"
	releaseall
# 94 "data//maps/LavaridgeTown/scripts.pory"
	end
# 95 "data//maps/LavaridgeTown/scripts.pory"

# 96 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 97 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 98 "data//maps/LavaridgeTown/scripts.pory"
	return
# 99 "data//maps/LavaridgeTown/scripts.pory"

# 100 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 101 "data//maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 102 "data//maps/LavaridgeTown/scripts.pory"
	return
# 103 "data//maps/LavaridgeTown/scripts.pory"

# 104 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 105 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 106 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 107 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 108 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 109 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 110 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 111 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 112 "data//maps/LavaridgeTown/scripts.pory"
	return
# 113 "data//maps/LavaridgeTown/scripts.pory"

# 114 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 115 "data//maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 116 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 117 "data//maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL
# 118 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 119 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 120 "data//maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 121 "data//maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 122 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 123 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 124 "data//maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 125 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 126 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 127 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 128 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 129 "data//maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 130 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 131 "data//maps/LavaridgeTown/scripts.pory"
	return
# 132 "data//maps/LavaridgeTown/scripts.pory"

# 133 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 134 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 135 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 136 "data//maps/LavaridgeTown/scripts.pory"
	return
# 137 "data//maps/LavaridgeTown/scripts.pory"

# 138 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 139 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 140 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 141 "data//maps/LavaridgeTown/scripts.pory"
	return
# 142 "data//maps/LavaridgeTown/scripts.pory"

# 143 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 144 "data//maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 145 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 146 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 147 "data//maps/LavaridgeTown/scripts.pory"
	return
# 148 "data//maps/LavaridgeTown/scripts.pory"

# 149 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 150 "data//maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 151 "data//maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 152 "data//maps/LavaridgeTown/scripts.pory"
	return
# 153 "data//maps/LavaridgeTown/scripts.pory"

# 154 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 155 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 156 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 157 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 158 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 159 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 160 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 161 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 162 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 163 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 164 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 165 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 166 "data//maps/LavaridgeTown/scripts.pory"

# 167 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 168 "data//maps/LavaridgeTown/scripts.pory"
	delay_16
# 169 "data//maps/LavaridgeTown/scripts.pory"
	delay_8
# 170 "data//maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 171 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 172 "data//maps/LavaridgeTown/scripts.pory"

# 173 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 174 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 175 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 176 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 177 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 178 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 179 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 180 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 181 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 182 "data//maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 183 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 184 "data//maps/LavaridgeTown/scripts.pory"

# 185 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 186 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 187 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 188 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 189 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 190 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 191 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 192 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 193 "data//maps/LavaridgeTown/scripts.pory"

# 194 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 195 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 196 "data//maps/LavaridgeTown/scripts.pory"
	walk_left
# 197 "data//maps/LavaridgeTown/scripts.pory"
	walk_up
# 198 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 199 "data//maps/LavaridgeTown/scripts.pory"

# 200 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 201 "data//maps/LavaridgeTown/scripts.pory"
	walk_down
# 202 "data//maps/LavaridgeTown/scripts.pory"
	step_end
# 203 "data//maps/LavaridgeTown/scripts.pory"

# 204 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 205 "data//maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 206 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 207 "data//maps/LavaridgeTown/scripts.pory"
	end
# 208 "data//maps/LavaridgeTown/scripts.pory"

# 209 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 210 "data//maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 211 "data//maps/LavaridgeTown/scripts.pory"
	end
# 212 "data//maps/LavaridgeTown/scripts.pory"

# 213 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 214 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 215 "data//maps/LavaridgeTown/scripts.pory"
	end
# 216 "data//maps/LavaridgeTown/scripts.pory"

# 217 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 218 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 219 "data//maps/LavaridgeTown/scripts.pory"
	end
# 220 "data//maps/LavaridgeTown/scripts.pory"

# 221 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 222 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 223 "data//maps/LavaridgeTown/scripts.pory"
	end
# 224 "data//maps/LavaridgeTown/scripts.pory"

# 225 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 226 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 227 "data//maps/LavaridgeTown/scripts.pory"
	end
# 228 "data//maps/LavaridgeTown/scripts.pory"

# 229 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 230 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 231 "data//maps/LavaridgeTown/scripts.pory"
	end
# 232 "data//maps/LavaridgeTown/scripts.pory"

# 233 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 234 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 235 "data//maps/LavaridgeTown/scripts.pory"
	end
# 236 "data//maps/LavaridgeTown/scripts.pory"

# 237 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 238 "data//maps/LavaridgeTown/scripts.pory"
	lock
# 239 "data//maps/LavaridgeTown/scripts.pory"
	faceplayer
# 240 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 241 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 242 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 243 "data//maps/LavaridgeTown/scripts.pory"
	getpartysize
# 244 "data//maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 245 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 246 "data//maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 247 "data//maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 248 "data//maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 249 "data//maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 250 "data//maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 251 "data//maps/LavaridgeTown/scripts.pory"
	release
# 252 "data//maps/LavaridgeTown/scripts.pory"
	end
# 253 "data//maps/LavaridgeTown/scripts.pory"

# 254 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 255 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 256 "data//maps/LavaridgeTown/scripts.pory"
	release
# 257 "data//maps/LavaridgeTown/scripts.pory"
	end
# 258 "data//maps/LavaridgeTown/scripts.pory"

# 259 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 260 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 261 "data//maps/LavaridgeTown/scripts.pory"
	release
# 262 "data//maps/LavaridgeTown/scripts.pory"
	end
# 263 "data//maps/LavaridgeTown/scripts.pory"

# 264 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 265 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 266 "data//maps/LavaridgeTown/scripts.pory"
	release
# 267 "data//maps/LavaridgeTown/scripts.pory"
	end
# 268 "data//maps/LavaridgeTown/scripts.pory"

# 269 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 270 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 271 "data//maps/LavaridgeTown/scripts.pory"
	end
# 272 "data//maps/LavaridgeTown/scripts.pory"

# 273 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 274 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 275 "data//maps/LavaridgeTown/scripts.pory"
	end
# 276 "data//maps/LavaridgeTown/scripts.pory"

# 277 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 278 "data//maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 279 "data//maps/LavaridgeTown/scripts.pory"
	end
# 280 "data//maps/LavaridgeTown/scripts.pory"

# 281 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 282 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 283 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 284 "data//maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 285 "data//maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 286 "data//maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 287 "data//maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 288 "data//maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 289 "data//maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 290 "data//maps/LavaridgeTown/scripts.pory"

# 291 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 292 "data//maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 293 "data//maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 294 "data//maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 295 "data//maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 296 "data//maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 297 "data//maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 298 "data//maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 299 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 300 "data//maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 301 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 302 "data//maps/LavaridgeTown/scripts.pory"

# 303 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 304 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 305 "data//maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 306 "data//maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 307 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 308 "data//maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 309 "data//maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 310 "data//maps/LavaridgeTown/scripts.pory"

# 311 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 312 "data//maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 313 "data//maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 314 "data//maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 315 "data//maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 316 "data//maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 317 "data//maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 318 "data//maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 319 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 320 "data//maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 321 "data//maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 322 "data//maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 323 "data//maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 324 "data//maps/LavaridgeTown/scripts.pory"

# 325 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 326 "data//maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 327 "data//maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 328 "data//maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 329 "data//maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 330 "data//maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 331 "data//maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 332 "data//maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 333 "data//maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 334 "data//maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 335 "data//maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 336 "data//maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 337 "data//maps/LavaridgeTown/scripts.pory"

# 338 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 339 "data//maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 340 "data//maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 341 "data//maps/LavaridgeTown/scripts.pory"

# 342 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 343 "data//maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 344 "data//maps/LavaridgeTown/scripts.pory"

# 345 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 346 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 347 "data//maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 348 "data//maps/LavaridgeTown/scripts.pory"

# 349 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 350 "data//maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 351 "data//maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 352 "data//maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 353 "data//maps/LavaridgeTown/scripts.pory"

# 354 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 355 "data//maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 356 "data//maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 357 "data//maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 358 "data//maps/LavaridgeTown/scripts.pory"

# 359 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 360 "data//maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 361 "data//maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 362 "data//maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 363 "data//maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 364 "data//maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 365 "data//maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 366 "data//maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 367 "data//maps/LavaridgeTown/scripts.pory"

# 368 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 369 "data//maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 370 "data//maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 371 "data//maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 372 "data//maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 373 "data//maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 374 "data//maps/LavaridgeTown/scripts.pory"

# 375 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 376 "data//maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 377 "data//maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 378 "data//maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 379 "data//maps/LavaridgeTown/scripts.pory"

# 380 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 381 "data//maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 382 "data//maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 383 "data//maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 384 "data//maps/LavaridgeTown/scripts.pory"

# 385 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 386 "data//maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 387 "data//maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 388 "data//maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 389 "data//maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 390 "data//maps/LavaridgeTown/scripts.pory"

# 391 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 392 "data//maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 393 "data//maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 394 "data//maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 395 "data//maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 396 "data//maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 397 "data//maps/LavaridgeTown/scripts.pory"

# 398 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 399 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 400 "data//maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 401 "data//maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 402 "data//maps/LavaridgeTown/scripts.pory"

# 403 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 404 "data//maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 405 "data//maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 406 "data//maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 407 "data//maps/LavaridgeTown/scripts.pory"

# 408 "data//maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 409 "data//maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 410 "data//maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
