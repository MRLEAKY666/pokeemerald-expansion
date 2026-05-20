# 1 "data//scripts/players_house.pory"

# 2 "data//scripts/players_house.pory"

# 3 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
# 4 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
# 5 "data//scripts/players_house.pory"
	return
# 6 "data//scripts/players_house.pory"

# 7 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_EnterHouseMovingIn::
# 8 "data//scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 9 "data//scripts/players_house.pory"
	waitmovement 0
# 10 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8005, MALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
# 11 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8005, FEMALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
# 12 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
# 13 "data//scripts/players_house.pory"
	closemessage
# 14 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 15 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
# 16 "data//scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 17 "data//scripts/players_house.pory"
	waitmovement 0
# 18 "data//scripts/players_house.pory"
	releaseall
# 19 "data//scripts/players_house.pory"
	end
# 20 "data//scripts/players_house.pory"

# 21 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
# 22 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 23 "data//scripts/players_house.pory"
	waitmovement 0
# 24 "data//scripts/players_house.pory"
	return
# 25 "data//scripts/players_house.pory"

# 26 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
# 27 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 28 "data//scripts/players_house.pory"
	waitmovement 0
# 29 "data//scripts/players_house.pory"
	return
# 30 "data//scripts/players_house.pory"

# 31 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerWalkIn:
# 32 "data//scripts/players_house.pory"
	walk_up
# 33 "data//scripts/players_house.pory"
	step_end
# 34 "data//scripts/players_house.pory"

# 35 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomGoSeeRoom::
# 36 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
# 37 "data//scripts/players_house.pory"
	closemessage
# 38 "data//scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 39 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
# 40 "data//scripts/players_house.pory"
	waitmovement 0
# 41 "data//scripts/players_house.pory"
	releaseall
# 42 "data//scripts/players_house.pory"
	end
# 43 "data//scripts/players_house.pory"

# 44 "data//scripts/players_house.pory"
LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
# 45 "data//scripts/players_house.pory"
	lockall
# 46 "data//scripts/players_house.pory"
	setvar VAR_0x8004, MALE
# 47 "data//scripts/players_house.pory"
	goto PlayersHouse_2F_EventScript_WallClock
# 48 "data//scripts/players_house.pory"
	end
# 49 "data//scripts/players_house.pory"

# 50 "data//scripts/players_house.pory"
LittlerootTown_MaysHouse_2F_EventScript_WallClock::
# 51 "data//scripts/players_house.pory"
	lockall
# 52 "data//scripts/players_house.pory"
	setvar VAR_0x8004, FEMALE
# 53 "data//scripts/players_house.pory"
	goto PlayersHouse_2F_EventScript_WallClock
# 54 "data//scripts/players_house.pory"
	end
# 55 "data//scripts/players_house.pory"

# 56 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_WallClock::
# 57 "data//scripts/players_house.pory"
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
# 58 "data//scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
# 59 "data//scripts/players_house.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 60 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
# 61 "data//scripts/players_house.pory"
	setflag FLAG_SET_WALL_CLOCK
# 62 "data//scripts/players_house.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
# 63 "data//scripts/players_house.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
# 64 "data//scripts/players_house.pory"
	removeobject VAR_0x8008
# 65 "data//scripts/players_house.pory"
	forcesave
# 66 "data//scripts/players_house.pory"
	releaseall
# 67 "data//scripts/players_house.pory"
	end
# 68 "data//scripts/players_house.pory"

# 69 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsMale::
# 70 "data//scripts/players_house.pory"
	setvar VAR_0x8008, LOCALID_PLAYERS_HOUSE_2F_MOM
# 71 "data//scripts/players_house.pory"
	addobject VAR_0x8008
# 72 "data//scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
# 73 "data//scripts/players_house.pory"
	waitmovement 0
# 74 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 75 "data//scripts/players_house.pory"
	waitmovement 0
# 76 "data//scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
# 77 "data//scripts/players_house.pory"
	closemessage
# 78 "data//scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
# 79 "data//scripts/players_house.pory"
	waitmovement 0
# 80 "data//scripts/players_house.pory"
	return
# 81 "data//scripts/players_house.pory"

# 82 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
# 83 "data//scripts/players_house.pory"
	setvar VAR_0x8008, LOCALID_PLAYERS_HOUSE_2F_MOM
# 84 "data//scripts/players_house.pory"
	addobject VAR_0x8008
# 85 "data//scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
# 86 "data//scripts/players_house.pory"
	waitmovement 0
# 87 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 88 "data//scripts/players_house.pory"
	waitmovement 0
# 89 "data//scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
# 90 "data//scripts/players_house.pory"
	closemessage
# 91 "data//scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
# 92 "data//scripts/players_house.pory"
	waitmovement 0
# 93 "data//scripts/players_house.pory"
	return
# 94 "data//scripts/players_house.pory"

# 95 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_CheckWallClock::
# 96 "data//scripts/players_house.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 97 "data//scripts/players_house.pory"
	fadescreen FADE_TO_BLACK
# 98 "data//scripts/players_house.pory"
	special Special_ViewWallClock
# 99 "data//scripts/players_house.pory"
	releaseall
# 100 "data//scripts/players_house.pory"
	end
# 101 "data//scripts/players_house.pory"

# 102 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_SetWallClock::
# 103 "data//scripts/players_house.pory"
	fadescreen FADE_TO_BLACK
# 104 "data//scripts/players_house.pory"
	special StartWallClock
# 105 "data//scripts/players_house.pory"
	return
# 106 "data//scripts/players_house.pory"

# 107 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersMale:
# 108 "data//scripts/players_house.pory"
	delay_8
# 109 "data//scripts/players_house.pory"
	walk_down
# 110 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 111 "data//scripts/players_house.pory"
	delay_16
# 112 "data//scripts/players_house.pory"
	delay_8
# 113 "data//scripts/players_house.pory"
	walk_left
# 114 "data//scripts/players_house.pory"
	step_end
# 115 "data//scripts/players_house.pory"

# 116 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsMale:
# 117 "data//scripts/players_house.pory"
	walk_right
# 118 "data//scripts/players_house.pory"
	walk_up
# 119 "data//scripts/players_house.pory"
	delay_8
# 120 "data//scripts/players_house.pory"
	step_end
# 121 "data//scripts/players_house.pory"

# 122 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersFemale:
# 123 "data//scripts/players_house.pory"
	delay_8
# 124 "data//scripts/players_house.pory"
	walk_down
# 125 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 126 "data//scripts/players_house.pory"
	delay_16
# 127 "data//scripts/players_house.pory"
	delay_8
# 128 "data//scripts/players_house.pory"
	walk_right
# 129 "data//scripts/players_house.pory"
	step_end
# 130 "data//scripts/players_house.pory"

# 131 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsFemale:
# 132 "data//scripts/players_house.pory"
	walk_left
# 133 "data//scripts/players_house.pory"
	walk_up
# 134 "data//scripts/players_house.pory"
	delay_8
# 135 "data//scripts/players_house.pory"
	step_end
# 136 "data//scripts/players_house.pory"

# 137 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetWatchedBroadcast::
# 138 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
# 139 "data//scripts/players_house.pory"
	releaseall
# 140 "data//scripts/players_house.pory"
	end
# 141 "data//scripts/players_house.pory"

# 142 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportMale::
# 143 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
# 144 "data//scripts/players_house.pory"
	waitmovement 0
# 145 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 146 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
# 147 "data//scripts/players_house.pory"
	waitmovement 0
# 148 "data//scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 149 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 150 "data//scripts/players_house.pory"
	closemessage
# 151 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
# 152 "data//scripts/players_house.pory"
	waitmovement 0
# 153 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
# 154 "data//scripts/players_house.pory"
	waitmovement 0
# 155 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 156 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 157 "data//scripts/players_house.pory"
	waitmovement 0
# 158 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 159 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 160 "data//scripts/players_house.pory"
	closemessage
# 161 "data//scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 162 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
# 163 "data//scripts/players_house.pory"
	waitmovement 0
# 164 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 165 "data//scripts/players_house.pory"
	end
# 166 "data//scripts/players_house.pory"

# 167 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
# 168 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
# 169 "data//scripts/players_house.pory"
	waitmovement 0
# 170 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 171 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
# 172 "data//scripts/players_house.pory"
	waitmovement 0
# 173 "data//scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 174 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 175 "data//scripts/players_house.pory"
	closemessage
# 176 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
# 177 "data//scripts/players_house.pory"
	waitmovement 0
# 178 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
# 179 "data//scripts/players_house.pory"
	waitmovement 0
# 180 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 181 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 182 "data//scripts/players_house.pory"
	waitmovement 0
# 183 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 184 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 185 "data//scripts/players_house.pory"
	closemessage
# 186 "data//scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 187 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
# 188 "data//scripts/players_house.pory"
	waitmovement 0
# 189 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 190 "data//scripts/players_house.pory"
	end
# 191 "data//scripts/players_house.pory"

# 192 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
# 193 "data//scripts/players_house.pory"
	playse SE_PIN
# 194 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
# 195 "data//scripts/players_house.pory"
	waitmovement 0
# 196 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_Delay48
# 197 "data//scripts/players_house.pory"
	waitmovement 0
# 198 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
# 199 "data//scripts/players_house.pory"
	closemessage
# 200 "data//scripts/players_house.pory"
	return
# 201 "data//scripts/players_house.pory"

# 202 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_WatchGymBroadcast::
# 203 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 204 "data//scripts/players_house.pory"
	waitmovement 0
# 205 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
# 206 "data//scripts/players_house.pory"
	fadedefaultbgm
# 207 "data//scripts/players_house.pory"
	special TurnOffTVScreen
# 208 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_HOME
# 209 "data//scripts/players_house.pory"
	delay 35
# 210 "data//scripts/players_house.pory"
	return
# 211 "data//scripts/players_house.pory"

# 212 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadMale:
# 213 "data//scripts/players_house.pory"
	walk_up
# 214 "data//scripts/players_house.pory"
	walk_right
# 215 "data//scripts/players_house.pory"
	walk_right
# 216 "data//scripts/players_house.pory"
	walk_right
# 217 "data//scripts/players_house.pory"
	walk_right
# 218 "data//scripts/players_house.pory"
	walk_down
# 219 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 220 "data//scripts/players_house.pory"
	step_end
# 221 "data//scripts/players_house.pory"

# 222 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadFemale:
# 223 "data//scripts/players_house.pory"
	walk_up
# 224 "data//scripts/players_house.pory"
	walk_left
# 225 "data//scripts/players_house.pory"
	walk_left
# 226 "data//scripts/players_house.pory"
	walk_left
# 227 "data//scripts/players_house.pory"
	walk_left
# 228 "data//scripts/players_house.pory"
	walk_down
# 229 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 230 "data//scripts/players_house.pory"
	step_end
# 231 "data//scripts/players_house.pory"

# 232 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerMale:
# 233 "data//scripts/players_house.pory"
	walk_right
# 234 "data//scripts/players_house.pory"
	step_end
# 235 "data//scripts/players_house.pory"

# 236 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerFemale:
# 237 "data//scripts/players_house.pory"
	walk_left
# 238 "data//scripts/players_house.pory"
	step_end
# 239 "data//scripts/players_house.pory"

# 240 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
# 241 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 242 "data//scripts/players_house.pory"
	delay_16
# 243 "data//scripts/players_house.pory"
	delay_16
# 244 "data//scripts/players_house.pory"
	delay_16
# 245 "data//scripts/players_house.pory"
	delay_16
# 246 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 247 "data//scripts/players_house.pory"
	delay_16
# 248 "data//scripts/players_house.pory"
	delay_16
# 249 "data//scripts/players_house.pory"
	step_end
# 250 "data//scripts/players_house.pory"

# 251 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
# 252 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 253 "data//scripts/players_house.pory"
	delay_16
# 254 "data//scripts/players_house.pory"
	delay_16
# 255 "data//scripts/players_house.pory"
	delay_16
# 256 "data//scripts/players_house.pory"
	delay_16
# 257 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 258 "data//scripts/players_house.pory"
	delay_16
# 259 "data//scripts/players_house.pory"
	delay_16
# 260 "data//scripts/players_house.pory"
	step_end
# 261 "data//scripts/players_house.pory"

# 262 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
# 263 "data//scripts/players_house.pory"
	walk_up
# 264 "data//scripts/players_house.pory"
	walk_left
# 265 "data//scripts/players_house.pory"
	walk_left
# 266 "data//scripts/players_house.pory"
	step_end
# 267 "data//scripts/players_house.pory"

# 268 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
# 269 "data//scripts/players_house.pory"
	walk_up
# 270 "data//scripts/players_house.pory"
	walk_right
# 271 "data//scripts/players_house.pory"
	walk_right
# 272 "data//scripts/players_house.pory"
	step_end
# 273 "data//scripts/players_house.pory"

# 274 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
# 275 "data//scripts/players_house.pory"
	walk_left
# 276 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 277 "data//scripts/players_house.pory"
	step_end
# 278 "data//scripts/players_house.pory"

# 279 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
# 280 "data//scripts/players_house.pory"
	walk_right
# 281 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 282 "data//scripts/players_house.pory"
	step_end
# 283 "data//scripts/players_house.pory"

# 284 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatMale:
# 285 "data//scripts/players_house.pory"
	walk_left
# 286 "data//scripts/players_house.pory"
	walk_down
# 287 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 288 "data//scripts/players_house.pory"
	step_end
# 289 "data//scripts/players_house.pory"

# 290 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatFemale:
# 291 "data//scripts/players_house.pory"
	walk_right
# 292 "data//scripts/players_house.pory"
	walk_down
# 293 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 294 "data//scripts/players_house.pory"
	step_end
# 295 "data//scripts/players_house.pory"

# 296 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Mom::
# 297 "data//scripts/players_house.pory"
	lock
# 298 "data//scripts/players_house.pory"
	faceplayer
# 299 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 300 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 301 "data//scripts/players_house.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
# 302 "data//scripts/players_house.pory"
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
# 303 "data//scripts/players_house.pory"
	goto_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_SeeYouHoney
# 304 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, PlayersHouse_1F_EventScript_DidYouMeetProfBirch
# 305 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
# 306 "data//scripts/players_house.pory"
	release
# 307 "data//scripts/players_house.pory"
	end
# 308 "data//scripts/players_house.pory"

# 309 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
# 310 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 311 "data//scripts/players_house.pory"
	release
# 312 "data//scripts/players_house.pory"
	end
# 313 "data//scripts/players_house.pory"

# 314 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryRegisterMom::
# 315 "data//scripts/players_house.pory"
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
# 316 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
# 317 "data//scripts/players_house.pory"
	closemessage
# 318 "data//scripts/players_house.pory"
	delay 30
# 319 "data//scripts/players_house.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 320 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
# 321 "data//scripts/players_house.pory"
	waitfanfare
# 322 "data//scripts/players_house.pory"
	closemessage
# 323 "data//scripts/players_house.pory"
	delay 30
# 324 "data//scripts/players_house.pory"
	setflag FLAG_ENABLE_MOM_MATCH_CALL
# 325 "data//scripts/players_house.pory"
	release
# 326 "data//scripts/players_house.pory"
	end
# 327 "data//scripts/players_house.pory"

# 328 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
# 329 "data//scripts/players_house.pory"
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
# 330 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_MomHealsParty
# 331 "data//scripts/players_house.pory"

# 332 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
# 333 "data//scripts/players_house.pory"
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
# 334 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
# 335 "data//scripts/players_house.pory"
	giveitem ITEM_AMULET_COIN
# 336 "data//scripts/players_house.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 337 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 338 "data//scripts/players_house.pory"
	setflag FLAG_RECEIVED_AMULET_COIN
# 339 "data//scripts/players_house.pory"
	release
# 340 "data//scripts/players_house.pory"
	end
# 341 "data//scripts/players_house.pory"

# 342 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomHealsParty::
# 343 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
# 344 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_HealParty
# 345 "data//scripts/players_house.pory"
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut::
# 351 "data//scripts/players_house.pory"
	waitmovement
# 352 "data//scripts/players_house.pory"
	getpartysize
# 353 "data//scripts/players_house.pory"
	getrandomspecies VAR_0x8008, SPECIES_GENERATOR_MOM_AFTER_WHITEOUT
# 354 "data//scripts/players_house.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_2
# 358 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 359 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 360 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 361 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 362 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_10
# 364 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_11
# 366 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_12
# 368 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_13
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8:
# 371 "data//scripts/players_house.pory"
	waitmovement
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_1:
# 373 "data//scripts/players_house.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 374 "data//scripts/players_house.pory"
	playfanfare MUS_OBTAIN_ITEM
# 375 "data//scripts/players_house.pory"
	message PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_0
# 376 "data//scripts/players_house.pory"
	waitmessage
# 377 "data//scripts/players_house.pory"
	waitfanfare
# 378 "data//scripts/players_house.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 379 "data//scripts/players_house.pory"
	compare VAR_RESULT, YES
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_6
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5:
# 391 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PC
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_15
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_14:
# 395 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_1, MSGBOX_DEFAULT
# 397 "data//scripts/players_house.pory"
	delay 30
# 398 "data//scripts/players_house.pory"
	closemessage
# 399 "data//scripts/players_house.pory"
	fadedefaultbgm
# 400 "data//scripts/players_house.pory"
	updatefollowingmon
# 401 "data//scripts/players_house.pory"
	release
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_2:
# 355 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoRoomForPartyPokemon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_1

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_6:
# 380 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PARTY
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_17
# 384 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PC
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_18
# 388 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoMoreRoomForPokemon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_10:
# 363 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_11:
# 365 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_12:
# 367 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_13:
# 369 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_15:
# 392 "data//scripts/players_house.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_0x8008
# 393 "data//scripts/players_house.pory"
	call Common_EventScript_TransferredToPC
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_14

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_17:
# 381 "data//scripts/players_house.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 382 "data//scripts/players_house.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_18:
# 385 "data//scripts/players_house.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5


PlayersHouse_1F_EventScript_NoMoreRoomForPokemon::
# 406 "data//scripts/players_house.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 407 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_0, MSGBOX_DEFAULT
# 410 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 411 "data//scripts/players_house.pory"
	waitstate
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_2:
# 412 "data//scripts/players_house.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_3
# 418 "data//scripts/players_house.pory"
	callnative DeleteMonFromParty
# 419 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 420 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 421 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 422 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 423 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_7
# 425 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_8
# 427 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_9
# 429 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_10
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5:
# 432 "data//scripts/players_house.pory"
	waitmovement
# 433 "data//scripts/players_house.pory"
	message PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_2
# 434 "data//scripts/players_house.pory"
	waitmessage
# 435 "data//scripts/players_house.pory"
	delay 45
# 436 "data//scripts/players_house.pory"
	closemessage
# 437 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 438 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_13
# 440 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_14
# 442 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_15
# 444 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_16
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11:
# 447 "data//scripts/players_house.pory"
	waitmovement
	return

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_3:
# 413 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_1, MSGBOX_DEFAULT
# 415 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 416 "data//scripts/players_house.pory"
	waitstate
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_2

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_7:
# 424 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_8:
# 426 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_9:
# 428 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_10:
# 430 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_13:
# 439 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_14:
# 441 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_15:
# 443 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_16:
# 445 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11


PlayersHouse_1F_EventScript_NoRoomForPartyPokemon::
# 451 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_0, MSGBOX_DEFAULT
# 453 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 454 "data//scripts/players_house.pory"
	waitstate
PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_2:
# 455 "data//scripts/players_house.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_3
# 461 "data//scripts/players_house.pory"
	sendpartymontofirstpcslot
# 462 "data//scripts/players_house.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_5
# 466 "data//scripts/players_house.pory"
	call Common_EventScript_TransferredToPC
# 467 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 468 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 469 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 470 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 471 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_9
# 473 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_10
# 475 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_11
# 477 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_12
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_3:
# 456 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_1, MSGBOX_DEFAULT
# 458 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 459 "data//scripts/players_house.pory"
	waitstate
	goto PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_2

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_5:
# 463 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoMoreRoomForPokemon
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_9:
# 472 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_10:
# 474 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_11:
# 476 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_12:
# 478 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
# 479 "data//scripts/players_house.pory"
	waitmovement
	return


# 484 "data//scripts/players_house.pory"

# 485 "data//scripts/players_house.pory"

# 486 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SeeYouHoney::
# 487 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
# 488 "data//scripts/players_house.pory"
	release
# 489 "data//scripts/players_house.pory"
	end
# 490 "data//scripts/players_house.pory"

# 491 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_HealParty::
# 492 "data//scripts/players_house.pory"
	closemessage
# 493 "data//scripts/players_house.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 494 "data//scripts/players_house.pory"
	incrementgamestat GAME_STAT_RESTED_AT_HOME
# 495 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
# 496 "data//scripts/players_house.pory"
	release
# 497 "data//scripts/players_house.pory"
	end
# 498 "data//scripts/players_house.pory"

# 499 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
# 500 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
# 501 "data//scripts/players_house.pory"
	release
# 502 "data//scripts/players_house.pory"
	end
# 503 "data//scripts/players_house.pory"

# 504 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth1::
# 505 "data//scripts/players_house.pory"
	lock
# 506 "data//scripts/players_house.pory"
	faceplayer
# 507 "data//scripts/players_house.pory"
	waitse
# 508 "data//scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
# 509 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
# 510 "data//scripts/players_house.pory"
	waitmoncry
# 511 "data//scripts/players_house.pory"
	release
# 512 "data//scripts/players_house.pory"
	end
# 513 "data//scripts/players_house.pory"

# 514 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth2::
# 515 "data//scripts/players_house.pory"
	lock
# 516 "data//scripts/players_house.pory"
	faceplayer
# 517 "data//scripts/players_house.pory"
	waitse
# 518 "data//scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
# 519 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
# 520 "data//scripts/players_house.pory"
	waitmoncry
# 521 "data//scripts/players_house.pory"
	release
# 522 "data//scripts/players_house.pory"
	end
# 523 "data//scripts/players_house.pory"

# 524 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
# 525 "data//scripts/players_house.pory"
	walk_fast_down
# 526 "data//scripts/players_house.pory"
	walk_fast_down
# 527 "data//scripts/players_house.pory"
	walk_fast_left
# 528 "data//scripts/players_house.pory"
	walk_fast_left
# 529 "data//scripts/players_house.pory"
	walk_fast_left
# 530 "data//scripts/players_house.pory"
	jump_in_place_left
# 531 "data//scripts/players_house.pory"
	step_end
# 532 "data//scripts/players_house.pory"
	
# 533 "data//scripts/players_house.pory"

# 534 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVMale:
# 535 "data//scripts/players_house.pory"
	walk_left
# 536 "data//scripts/players_house.pory"
	step_end
# 537 "data//scripts/players_house.pory"

# 538 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
# 539 "data//scripts/players_house.pory"
	walk_fast_down
# 540 "data//scripts/players_house.pory"
	walk_fast_down
# 541 "data//scripts/players_house.pory"
	walk_fast_right
# 542 "data//scripts/players_house.pory"
	walk_fast_right
# 543 "data//scripts/players_house.pory"
	walk_fast_right
# 544 "data//scripts/players_house.pory"
	jump_in_place_right
# 545 "data//scripts/players_house.pory"
	step_end
# 546 "data//scripts/players_house.pory"
	
# 547 "data//scripts/players_house.pory"

# 548 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
# 549 "data//scripts/players_house.pory"
	walk_right
# 550 "data//scripts/players_house.pory"
	step_end
# 551 "data//scripts/players_house.pory"

# 552 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
# 553 "data//scripts/players_house.pory"
	walk_up
# 554 "data//scripts/players_house.pory"
	step_end
# 555 "data//scripts/players_house.pory"

# 556 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
# 557 "data//scripts/players_house.pory"
	lockall
# 558 "data//scripts/players_house.pory"
	checkplayergender
# 559 "data//scripts/players_house.pory"
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
# 560 "data//scripts/players_house.pory"
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
# 561 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerEnterRoomMale
# 562 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
# 563 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_FacePlayer
# 564 "data//scripts/players_house.pory"
	waitmovement 0
# 565 "data//scripts/players_house.pory"
	playse SE_PIN
# 566 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 567 "data//scripts/players_house.pory"
	waitmovement 0
# 568 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_Delay48
# 569 "data//scripts/players_house.pory"
	waitmovement 0
# 570 "data//scripts/players_house.pory"
	delay 20
# 571 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadApproachPlayerMale
# 572 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadApproachPlayerFemale
# 573 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
# 574 "data//scripts/players_house.pory"
	giveitem ITEM_SS_TICKET
# 575 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
# 576 "data//scripts/players_house.pory"
	closemessage
# 577 "data//scripts/players_house.pory"
	delay 20
# 578 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachDadMale
# 579 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachDadFemale
# 580 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
# 581 "data//scripts/players_house.pory"
	closemessage
# 582 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadExitsMale
# 583 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadExitsFemale
# 584 "data//scripts/players_house.pory"
	playse SE_DOOR
# 585 "data//scripts/players_house.pory"
	removeobject VAR_0x8009
# 586 "data//scripts/players_house.pory"
	setflag FLAG_RECEIVED_SS_TICKET
# 587 "data//scripts/players_house.pory"
	delay 30
# 588 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerMale
# 589 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerFemale
# 590 "data//scripts/players_house.pory"
	delay 20
# 591 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
# 592 "data//scripts/players_house.pory"
	closemessage
# 593 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 594 "data//scripts/players_house.pory"
	special TurnOnTVScreen
# 595 "data//scripts/players_house.pory"
	delay 60
# 596 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
# 597 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
# 598 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
# 599 "data//scripts/players_house.pory"
	closemessage
# 600 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
# 601 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
# 602 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
# 603 "data//scripts/players_house.pory"
	closemessage
# 604 "data//scripts/players_house.pory"
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
# 605 "data//scripts/players_house.pory"
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
# 606 "data//scripts/players_house.pory"
	setvar VAR_UNUSED_0x8014, 2
# 607 "data//scripts/players_house.pory"
	special TurnOffTVScreen
# 608 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
# 609 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
# 610 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
# 611 "data//scripts/players_house.pory"
	multichoice 22, 8, MULTI_TV_LATI, TRUE
# 612 "data//scripts/players_house.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 613 "data//scripts/players_house.pory"
	special InitRoamer
# 614 "data//scripts/players_house.pory"
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
# 615 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
# 616 "data//scripts/players_house.pory"
	closemessage
# 617 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
# 618 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
# 619 "data//scripts/players_house.pory"
	releaseall
# 620 "data//scripts/players_house.pory"
	end
# 621 "data//scripts/players_house.pory"

# 622 "data//scripts/players_house.pory"
@ Never called.
# 623 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_AirLatiBroadcast::
# 624 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 625 "data//scripts/players_house.pory"
	return
# 626 "data//scripts/players_house.pory"

# 627 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
# 628 "data//scripts/players_house.pory"
	setvar VAR_0x8008, MALE
# 629 "data//scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_PLAYERS_HOUSE_1F_DAD
# 630 "data//scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_PLAYERS_HOUSE_1F_MOM
# 631 "data//scripts/players_house.pory"
	return
# 632 "data//scripts/players_house.pory"

# 633 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
# 634 "data//scripts/players_house.pory"
	setvar VAR_0x8008, FEMALE
# 635 "data//scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_PLAYERS_HOUSE_1F_DAD
# 636 "data//scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_PLAYERS_HOUSE_1F_MOM
# 637 "data//scripts/players_house.pory"
	return
# 638 "data//scripts/players_house.pory"

# 639 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerMale::
# 640 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
# 641 "data//scripts/players_house.pory"
	waitmovement 0
# 642 "data//scripts/players_house.pory"
	return
# 643 "data//scripts/players_house.pory"

# 644 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
# 645 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
# 646 "data//scripts/players_house.pory"
	waitmovement 0
# 647 "data//scripts/players_house.pory"
	return
# 648 "data//scripts/players_house.pory"

# 649 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadMale::
# 650 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
# 651 "data//scripts/players_house.pory"
	waitmovement 0
# 652 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
# 653 "data//scripts/players_house.pory"
	waitmovement 0
# 654 "data//scripts/players_house.pory"
	return
# 655 "data//scripts/players_house.pory"

# 656 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadFemale::
# 657 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
# 658 "data//scripts/players_house.pory"
	waitmovement 0
# 659 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
# 660 "data//scripts/players_house.pory"
	waitmovement 0
# 661 "data//scripts/players_house.pory"
	return
# 662 "data//scripts/players_house.pory"

# 663 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsMale::
# 664 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 665 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 666 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
# 667 "data//scripts/players_house.pory"
	waitmovement 0
# 668 "data//scripts/players_house.pory"
	return
# 669 "data//scripts/players_house.pory"

# 670 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsFemale::
# 671 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 672 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 673 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
# 674 "data//scripts/players_house.pory"
	waitmovement 0
# 675 "data//scripts/players_house.pory"
	return
# 676 "data//scripts/players_house.pory"

# 677 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
# 678 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
# 679 "data//scripts/players_house.pory"
	waitmovement 0
# 680 "data//scripts/players_house.pory"
	return
# 681 "data//scripts/players_house.pory"

# 682 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
# 683 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
# 684 "data//scripts/players_house.pory"
	waitmovement 0
# 685 "data//scripts/players_house.pory"
	return
# 686 "data//scripts/players_house.pory"

# 687 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
# 688 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
# 689 "data//scripts/players_house.pory"
	waitmovement 0
# 690 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterLeft
# 691 "data//scripts/players_house.pory"
	waitmovement 0
# 692 "data//scripts/players_house.pory"
	return
# 693 "data//scripts/players_house.pory"

# 694 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
# 695 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
# 696 "data//scripts/players_house.pory"
	waitmovement 0
# 697 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterRight
# 698 "data//scripts/players_house.pory"
	waitmovement 0
# 699 "data//scripts/players_house.pory"
	return
# 700 "data//scripts/players_house.pory"

# 701 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerMale::
# 702 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
# 703 "data//scripts/players_house.pory"
	waitmovement 0
# 704 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 705 "data//scripts/players_house.pory"
	waitmovement 0
# 706 "data//scripts/players_house.pory"
	return
# 707 "data//scripts/players_house.pory"

# 708 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
# 709 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
# 710 "data//scripts/players_house.pory"
	waitmovement 0
# 711 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 712 "data//scripts/players_house.pory"
	waitmovement 0
# 713 "data//scripts/players_house.pory"
	return
# 714 "data//scripts/players_house.pory"

# 715 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
# 716 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
# 717 "data//scripts/players_house.pory"
	waitmovement 0
# 718 "data//scripts/players_house.pory"
	return
# 719 "data//scripts/players_house.pory"

# 720 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
# 721 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
# 722 "data//scripts/players_house.pory"
	waitmovement 0
# 723 "data//scripts/players_house.pory"
	return
# 724 "data//scripts/players_house.pory"

# 725 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
# 726 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
# 727 "data//scripts/players_house.pory"
	waitmovement 0
# 728 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 729 "data//scripts/players_house.pory"
	waitmovement 0
# 730 "data//scripts/players_house.pory"
	return
# 731 "data//scripts/players_house.pory"

# 732 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
# 733 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
# 734 "data//scripts/players_house.pory"
	waitmovement 0
# 735 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 736 "data//scripts/players_house.pory"
	waitmovement 0
# 737 "data//scripts/players_house.pory"
	return
# 738 "data//scripts/players_house.pory"

# 739 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerMale:
# 740 "data//scripts/players_house.pory"
	walk_right
# 741 "data//scripts/players_house.pory"
	walk_right
# 742 "data//scripts/players_house.pory"
	step_end
# 743 "data//scripts/players_house.pory"

# 744 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerFemale:
# 745 "data//scripts/players_house.pory"
	walk_left
# 746 "data//scripts/players_house.pory"
	walk_left
# 747 "data//scripts/players_house.pory"
	step_end
# 748 "data//scripts/players_house.pory"

# 749 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomMale:
# 750 "data//scripts/players_house.pory"
	face_left
# 751 "data//scripts/players_house.pory"
	step_end
# 752 "data//scripts/players_house.pory"

# 753 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomFemale:
# 754 "data//scripts/players_house.pory"
	face_right
# 755 "data//scripts/players_house.pory"
	step_end
# 756 "data//scripts/players_house.pory"

# 757 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsMale:
# 758 "data//scripts/players_house.pory"
	walk_down
# 759 "data//scripts/players_house.pory"
	walk_right
# 760 "data//scripts/players_house.pory"
	walk_down
# 761 "data//scripts/players_house.pory"
	delay_8
# 762 "data//scripts/players_house.pory"
	step_end
# 763 "data//scripts/players_house.pory"

# 764 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsFemale:
# 765 "data//scripts/players_house.pory"
	walk_down
# 766 "data//scripts/players_house.pory"
	walk_left
# 767 "data//scripts/players_house.pory"
	walk_down
# 768 "data//scripts/players_house.pory"
	delay_8
# 769 "data//scripts/players_house.pory"
	step_end
# 770 "data//scripts/players_house.pory"

# 771 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomMale:
# 772 "data//scripts/players_house.pory"
	delay_16
# 773 "data//scripts/players_house.pory"
	walk_down
# 774 "data//scripts/players_house.pory"
	walk_down
# 775 "data//scripts/players_house.pory"
	walk_down
# 776 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 777 "data//scripts/players_house.pory"
	step_end
# 778 "data//scripts/players_house.pory"

# 779 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
# 780 "data//scripts/players_house.pory"
	delay_8
# 781 "data//scripts/players_house.pory"
	delay_16
# 782 "data//scripts/players_house.pory"
	delay_16
# 783 "data//scripts/players_house.pory"
	walk_in_place_faster_down
# 784 "data//scripts/players_house.pory"
	step_end
# 785 "data//scripts/players_house.pory"

# 786 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
# 787 "data//scripts/players_house.pory"
	delay_16
# 788 "data//scripts/players_house.pory"
	walk_down
# 789 "data//scripts/players_house.pory"
	walk_down
# 790 "data//scripts/players_house.pory"
	walk_down
# 791 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 792 "data//scripts/players_house.pory"
	step_end
# 793 "data//scripts/players_house.pory"

# 794 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
# 795 "data//scripts/players_house.pory"
	walk_up
# 796 "data//scripts/players_house.pory"
	walk_left
# 797 "data//scripts/players_house.pory"
	walk_left
# 798 "data//scripts/players_house.pory"
	walk_left
# 799 "data//scripts/players_house.pory"
	walk_left
# 800 "data//scripts/players_house.pory"
	walk_in_place_faster_up
# 801 "data//scripts/players_house.pory"
	step_end
# 802 "data//scripts/players_house.pory"

# 803 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
# 804 "data//scripts/players_house.pory"
	walk_up
# 805 "data//scripts/players_house.pory"
	walk_right
# 806 "data//scripts/players_house.pory"
	walk_right
# 807 "data//scripts/players_house.pory"
	walk_right
# 808 "data//scripts/players_house.pory"
	walk_right
# 809 "data//scripts/players_house.pory"
	walk_in_place_faster_up
# 810 "data//scripts/players_house.pory"
	step_end
# 811 "data//scripts/players_house.pory"

# 812 "data//scripts/players_house.pory"
EventScript_RunningShoesManual::
# 813 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
# 814 "data//scripts/players_house.pory"
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_0:
# 375 "data//scripts/players_house.pory"
	.string "{PLAYER} obtained a {STR_VAR_1}.$"

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_1:
# 395 "data//scripts/players_house.pory"
	.string "Good luck out there, {PLAYER}…\p"
	.string "Try to be more careful,{PAUSE 20}\n"
	.string "okay?$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_0:
# 407 "data//scripts/players_house.pory"
	.string "Wow,{PAUSE 20} you're all out of PC storage space!\p"
	.string "Let me hold onto one of your dead\n"
	.string "POKéMON, then.\p"
	.string "If we can revive it, we'll let the gym\n"
	.string "trainers use it instead of this\l"
	.string "{STR_VAR_1}.$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_1:
# 413 "data//scripts/players_house.pory"
	.string "You really ought to have a living\n"
	.string "POKéMON in your party…\p"
	.string "Come on, {PLAYER}.\p"
	.string "Choose a dead POKéMON to give me.$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_2:
# 433 "data//scripts/players_house.pory"
	.string "{PLAYER} handed over the dead\n"
	.string "POKéMON.$"

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_0:
# 451 "data//scripts/players_house.pory"
	.string "Oh,{PAUSE 20} but you don't have room for it in\n"
	.string "your party…\p"
	.string "Let's send one of your POKéMON to the\n"
	.string "PC, then.$"

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_1:
# 456 "data//scripts/players_house.pory"
	.string "You really ought to have a living\n"
	.string "POKéMON in your party…\p"
	.string "Come on, {PLAYER}.\p"
	.string "Let's send one of your POKéMON to the\n"
	.string "PC.$"
