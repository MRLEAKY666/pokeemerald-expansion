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
	waitstate
# 100 "data//scripts/players_house.pory"
	releaseall
# 101 "data//scripts/players_house.pory"
	end
# 102 "data//scripts/players_house.pory"

# 103 "data//scripts/players_house.pory"
PlayersHouse_2F_EventScript_SetWallClock::
# 104 "data//scripts/players_house.pory"
	fadescreen FADE_TO_BLACK
# 105 "data//scripts/players_house.pory"
	special StartWallClock
# 106 "data//scripts/players_house.pory"
	waitstate
# 107 "data//scripts/players_house.pory"
	return
# 108 "data//scripts/players_house.pory"

# 109 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersMale:
# 110 "data//scripts/players_house.pory"
	delay_8
# 111 "data//scripts/players_house.pory"
	walk_down
# 112 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 113 "data//scripts/players_house.pory"
	delay_16
# 114 "data//scripts/players_house.pory"
	delay_8
# 115 "data//scripts/players_house.pory"
	walk_left
# 116 "data//scripts/players_house.pory"
	step_end
# 117 "data//scripts/players_house.pory"

# 118 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsMale:
# 119 "data//scripts/players_house.pory"
	walk_right
# 120 "data//scripts/players_house.pory"
	walk_up
# 121 "data//scripts/players_house.pory"
	delay_8
# 122 "data//scripts/players_house.pory"
	step_end
# 123 "data//scripts/players_house.pory"

# 124 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersFemale:
# 125 "data//scripts/players_house.pory"
	delay_8
# 126 "data//scripts/players_house.pory"
	walk_down
# 127 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 128 "data//scripts/players_house.pory"
	delay_16
# 129 "data//scripts/players_house.pory"
	delay_8
# 130 "data//scripts/players_house.pory"
	walk_right
# 131 "data//scripts/players_house.pory"
	step_end
# 132 "data//scripts/players_house.pory"

# 133 "data//scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsFemale:
# 134 "data//scripts/players_house.pory"
	walk_left
# 135 "data//scripts/players_house.pory"
	walk_up
# 136 "data//scripts/players_house.pory"
	delay_8
# 137 "data//scripts/players_house.pory"
	step_end
# 138 "data//scripts/players_house.pory"

# 139 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetWatchedBroadcast::
# 140 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
# 141 "data//scripts/players_house.pory"
	releaseall
# 142 "data//scripts/players_house.pory"
	end
# 143 "data//scripts/players_house.pory"

# 144 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportMale::
# 145 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
# 146 "data//scripts/players_house.pory"
	waitmovement 0
# 147 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 148 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
# 149 "data//scripts/players_house.pory"
	waitmovement 0
# 150 "data//scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 151 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 152 "data//scripts/players_house.pory"
	closemessage
# 153 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
# 154 "data//scripts/players_house.pory"
	waitmovement 0
# 155 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
# 156 "data//scripts/players_house.pory"
	waitmovement 0
# 157 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 158 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 159 "data//scripts/players_house.pory"
	waitmovement 0
# 160 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 161 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 162 "data//scripts/players_house.pory"
	closemessage
# 163 "data//scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 164 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
# 165 "data//scripts/players_house.pory"
	waitmovement 0
# 166 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 167 "data//scripts/players_house.pory"
	end
# 168 "data//scripts/players_house.pory"

# 169 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
# 170 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
# 171 "data//scripts/players_house.pory"
	waitmovement 0
# 172 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 173 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
# 174 "data//scripts/players_house.pory"
	waitmovement 0
# 175 "data//scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 176 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 177 "data//scripts/players_house.pory"
	closemessage
# 178 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
# 179 "data//scripts/players_house.pory"
	waitmovement 0
# 180 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
# 181 "data//scripts/players_house.pory"
	waitmovement 0
# 182 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 183 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 184 "data//scripts/players_house.pory"
	waitmovement 0
# 185 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 186 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 187 "data//scripts/players_house.pory"
	closemessage
# 188 "data//scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 189 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
# 190 "data//scripts/players_house.pory"
	waitmovement 0
# 191 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 192 "data//scripts/players_house.pory"
	end
# 193 "data//scripts/players_house.pory"

# 194 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
# 195 "data//scripts/players_house.pory"
	playse SE_PIN
# 196 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
# 197 "data//scripts/players_house.pory"
	waitmovement 0
# 198 "data//scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_Delay48
# 199 "data//scripts/players_house.pory"
	waitmovement 0
# 200 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
# 201 "data//scripts/players_house.pory"
	closemessage
# 202 "data//scripts/players_house.pory"
	return
# 203 "data//scripts/players_house.pory"

# 204 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_WatchGymBroadcast::
# 205 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 206 "data//scripts/players_house.pory"
	waitmovement 0
# 207 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
# 208 "data//scripts/players_house.pory"
	fadedefaultbgm
# 209 "data//scripts/players_house.pory"
	special TurnOffTVScreen
# 210 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_HOME
# 211 "data//scripts/players_house.pory"
	delay 35
# 212 "data//scripts/players_house.pory"
	return
# 213 "data//scripts/players_house.pory"

# 214 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadMale:
# 215 "data//scripts/players_house.pory"
	walk_up
# 216 "data//scripts/players_house.pory"
	walk_right
# 217 "data//scripts/players_house.pory"
	walk_right
# 218 "data//scripts/players_house.pory"
	walk_right
# 219 "data//scripts/players_house.pory"
	walk_right
# 220 "data//scripts/players_house.pory"
	walk_down
# 221 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 222 "data//scripts/players_house.pory"
	step_end
# 223 "data//scripts/players_house.pory"

# 224 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadFemale:
# 225 "data//scripts/players_house.pory"
	walk_up
# 226 "data//scripts/players_house.pory"
	walk_left
# 227 "data//scripts/players_house.pory"
	walk_left
# 228 "data//scripts/players_house.pory"
	walk_left
# 229 "data//scripts/players_house.pory"
	walk_left
# 230 "data//scripts/players_house.pory"
	walk_down
# 231 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 232 "data//scripts/players_house.pory"
	step_end
# 233 "data//scripts/players_house.pory"

# 234 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerMale:
# 235 "data//scripts/players_house.pory"
	walk_right
# 236 "data//scripts/players_house.pory"
	step_end
# 237 "data//scripts/players_house.pory"

# 238 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerFemale:
# 239 "data//scripts/players_house.pory"
	walk_left
# 240 "data//scripts/players_house.pory"
	step_end
# 241 "data//scripts/players_house.pory"

# 242 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
# 243 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 244 "data//scripts/players_house.pory"
	delay_16
# 245 "data//scripts/players_house.pory"
	delay_16
# 246 "data//scripts/players_house.pory"
	delay_16
# 247 "data//scripts/players_house.pory"
	delay_16
# 248 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 249 "data//scripts/players_house.pory"
	delay_16
# 250 "data//scripts/players_house.pory"
	delay_16
# 251 "data//scripts/players_house.pory"
	step_end
# 252 "data//scripts/players_house.pory"

# 253 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
# 254 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 255 "data//scripts/players_house.pory"
	delay_16
# 256 "data//scripts/players_house.pory"
	delay_16
# 257 "data//scripts/players_house.pory"
	delay_16
# 258 "data//scripts/players_house.pory"
	delay_16
# 259 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 260 "data//scripts/players_house.pory"
	delay_16
# 261 "data//scripts/players_house.pory"
	delay_16
# 262 "data//scripts/players_house.pory"
	step_end
# 263 "data//scripts/players_house.pory"

# 264 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
# 265 "data//scripts/players_house.pory"
	walk_up
# 266 "data//scripts/players_house.pory"
	walk_left
# 267 "data//scripts/players_house.pory"
	walk_left
# 268 "data//scripts/players_house.pory"
	step_end
# 269 "data//scripts/players_house.pory"

# 270 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
# 271 "data//scripts/players_house.pory"
	walk_up
# 272 "data//scripts/players_house.pory"
	walk_right
# 273 "data//scripts/players_house.pory"
	walk_right
# 274 "data//scripts/players_house.pory"
	step_end
# 275 "data//scripts/players_house.pory"

# 276 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
# 277 "data//scripts/players_house.pory"
	walk_left
# 278 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 279 "data//scripts/players_house.pory"
	step_end
# 280 "data//scripts/players_house.pory"

# 281 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
# 282 "data//scripts/players_house.pory"
	walk_right
# 283 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 284 "data//scripts/players_house.pory"
	step_end
# 285 "data//scripts/players_house.pory"

# 286 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatMale:
# 287 "data//scripts/players_house.pory"
	walk_left
# 288 "data//scripts/players_house.pory"
	walk_down
# 289 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 290 "data//scripts/players_house.pory"
	step_end
# 291 "data//scripts/players_house.pory"

# 292 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatFemale:
# 293 "data//scripts/players_house.pory"
	walk_right
# 294 "data//scripts/players_house.pory"
	walk_down
# 295 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 296 "data//scripts/players_house.pory"
	step_end
# 297 "data//scripts/players_house.pory"

# 298 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Mom::
# 299 "data//scripts/players_house.pory"
	lock
# 300 "data//scripts/players_house.pory"
	faceplayer
# 301 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 302 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 303 "data//scripts/players_house.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
# 304 "data//scripts/players_house.pory"
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
# 305 "data//scripts/players_house.pory"
	goto_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_SeeYouHoney
# 306 "data//scripts/players_house.pory"
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, PlayersHouse_1F_EventScript_DidYouMeetProfBirch
# 307 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
# 308 "data//scripts/players_house.pory"
	release
# 309 "data//scripts/players_house.pory"
	end
# 310 "data//scripts/players_house.pory"

# 311 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
# 312 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 313 "data//scripts/players_house.pory"
	release
# 314 "data//scripts/players_house.pory"
	end
# 315 "data//scripts/players_house.pory"

# 316 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryRegisterMom::
# 317 "data//scripts/players_house.pory"
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
# 318 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
# 319 "data//scripts/players_house.pory"
	closemessage
# 320 "data//scripts/players_house.pory"
	delay 30
# 321 "data//scripts/players_house.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 322 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
# 323 "data//scripts/players_house.pory"
	waitfanfare
# 324 "data//scripts/players_house.pory"
	closemessage
# 325 "data//scripts/players_house.pory"
	delay 30
# 326 "data//scripts/players_house.pory"
	setflag FLAG_ENABLE_MOM_MATCH_CALL
# 327 "data//scripts/players_house.pory"
	release
# 328 "data//scripts/players_house.pory"
	end
# 329 "data//scripts/players_house.pory"

# 330 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
# 331 "data//scripts/players_house.pory"
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
# 332 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_MomHealsParty
# 333 "data//scripts/players_house.pory"

# 334 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
# 335 "data//scripts/players_house.pory"
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
# 336 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
# 337 "data//scripts/players_house.pory"
	giveitem ITEM_AMULET_COIN
# 338 "data//scripts/players_house.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 339 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 340 "data//scripts/players_house.pory"
	setflag FLAG_RECEIVED_AMULET_COIN
# 341 "data//scripts/players_house.pory"
	release
# 342 "data//scripts/players_house.pory"
	end
# 343 "data//scripts/players_house.pory"

# 344 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomHealsParty::
# 345 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
# 346 "data//scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_HealParty
# 347 "data//scripts/players_house.pory"
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut::
# 353 "data//scripts/players_house.pory"
	waitmovement
# 354 "data//scripts/players_house.pory"
	getpartysize
# 355 "data//scripts/players_house.pory"
	getrandomspecies VAR_0x8008, SPECIES_GENERATOR_MOM_AFTER_WHITEOUT
# 356 "data//scripts/players_house.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_2
# 360 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 361 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 362 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 363 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 364 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_10
# 366 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_11
# 368 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_12
# 370 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_13
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8:
# 373 "data//scripts/players_house.pory"
	waitmovement
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_1:
# 375 "data//scripts/players_house.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 376 "data//scripts/players_house.pory"
	playfanfare MUS_OBTAIN_ITEM
# 377 "data//scripts/players_house.pory"
	message PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_0
# 378 "data//scripts/players_house.pory"
	waitmessage
# 379 "data//scripts/players_house.pory"
	waitfanfare
# 380 "data//scripts/players_house.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 381 "data//scripts/players_house.pory"
	compare VAR_RESULT, YES
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_6
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5:
# 393 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PC
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_15
PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_14:
# 397 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_1, MSGBOX_DEFAULT
# 399 "data//scripts/players_house.pory"
	delay 30
# 400 "data//scripts/players_house.pory"
	closemessage
# 401 "data//scripts/players_house.pory"
	fadedefaultbgm
# 402 "data//scripts/players_house.pory"
	updatefollowingmon
# 403 "data//scripts/players_house.pory"
	release
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_2:
# 357 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoRoomForPartyPokemon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_1

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_6:
# 382 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PARTY
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_17
# 386 "data//scripts/players_house.pory"
	compare VAR_0x8005, MON_GIVEN_TO_PC
	goto_if_eq PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_18
# 390 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoMoreRoomForPokemon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_10:
# 365 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_11:
# 367 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_12:
# 369 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_13:
# 371 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_8

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_15:
# 394 "data//scripts/players_house.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_0x8008
# 395 "data//scripts/players_house.pory"
	call Common_EventScript_TransferredToPC
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_14

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_17:
# 383 "data//scripts/players_house.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 384 "data//scripts/players_house.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_18:
# 387 "data//scripts/players_house.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_5


PlayersHouse_1F_EventScript_NoMoreRoomForPokemon::
# 408 "data//scripts/players_house.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8008
# 409 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_0, MSGBOX_DEFAULT
# 412 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 413 "data//scripts/players_house.pory"
	waitstate
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_2:
# 414 "data//scripts/players_house.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_3
# 420 "data//scripts/players_house.pory"
	callnative DeleteMonFromParty
# 421 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 422 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 423 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 424 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 425 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_7
# 427 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_8
# 429 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_9
# 431 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_10
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5:
# 434 "data//scripts/players_house.pory"
	waitmovement
# 435 "data//scripts/players_house.pory"
	message PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_2
# 436 "data//scripts/players_house.pory"
	waitmessage
# 437 "data//scripts/players_house.pory"
	delay 45
# 438 "data//scripts/players_house.pory"
	closemessage
# 439 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 440 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_13
# 442 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_14
# 444 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_15
# 446 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_16
PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11:
# 449 "data//scripts/players_house.pory"
	waitmovement
	return

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_3:
# 415 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_1, MSGBOX_DEFAULT
# 417 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 418 "data//scripts/players_house.pory"
	waitstate
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_2

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_7:
# 426 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_8:
# 428 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_9:
# 430 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_10:
# 432 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_5

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_13:
# 441 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_14:
# 443 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_15:
# 445 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_16:
# 447 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
	goto PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_11


PlayersHouse_1F_EventScript_NoRoomForPartyPokemon::
# 453 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_0, MSGBOX_DEFAULT
# 455 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 456 "data//scripts/players_house.pory"
	waitstate
PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_2:
# 457 "data//scripts/players_house.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_3
# 463 "data//scripts/players_house.pory"
	sendpartymontofirstpcslot
# 464 "data//scripts/players_house.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_5
# 468 "data//scripts/players_house.pory"
	call Common_EventScript_TransferredToPC
# 469 "data//scripts/players_house.pory"
	givemon VAR_0x8008, 5, move4 = MOVE_RANDOM_TEACHABLE
# 470 "data//scripts/players_house.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 471 "data//scripts/players_house.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 472 "data//scripts/players_house.pory"
	switch VAR_RESULT
# 473 "data//scripts/players_house.pory"
	case DIR_NORTH, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_9
# 475 "data//scripts/players_house.pory"
	case DIR_SOUTH, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_10
# 477 "data//scripts/players_house.pory"
	case DIR_EAST, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_11
# 479 "data//scripts/players_house.pory"
	case DIR_WEST, PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_12
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_3:
# 458 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_1, MSGBOX_DEFAULT
# 460 "data//scripts/players_house.pory"
	special ChoosePartyMon
# 461 "data//scripts/players_house.pory"
	waitstate
	goto PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_2

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_5:
# 465 "data//scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_NoMoreRoomForPokemon
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_9:
# 474 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceDown
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_10:
# 476 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceUp
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_11:
# 478 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceLeft
	return

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_12:
# 480 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceRight
# 481 "data//scripts/players_house.pory"
	waitmovement
	return


# 486 "data//scripts/players_house.pory"

# 487 "data//scripts/players_house.pory"

# 488 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SeeYouHoney::
# 489 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
# 490 "data//scripts/players_house.pory"
	release
# 491 "data//scripts/players_house.pory"
	end
# 492 "data//scripts/players_house.pory"

# 493 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_HealParty::
# 494 "data//scripts/players_house.pory"
	closemessage
# 495 "data//scripts/players_house.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 496 "data//scripts/players_house.pory"
	incrementgamestat GAME_STAT_RESTED_AT_HOME
# 497 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
# 498 "data//scripts/players_house.pory"
	release
# 499 "data//scripts/players_house.pory"
	end
# 500 "data//scripts/players_house.pory"

# 501 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
# 502 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
# 503 "data//scripts/players_house.pory"
	release
# 504 "data//scripts/players_house.pory"
	end
# 505 "data//scripts/players_house.pory"

# 506 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth1::
# 507 "data//scripts/players_house.pory"
	lock
# 508 "data//scripts/players_house.pory"
	faceplayer
# 509 "data//scripts/players_house.pory"
	waitse
# 510 "data//scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
# 511 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
# 512 "data//scripts/players_house.pory"
	waitmoncry
# 513 "data//scripts/players_house.pory"
	release
# 514 "data//scripts/players_house.pory"
	end
# 515 "data//scripts/players_house.pory"

# 516 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth2::
# 517 "data//scripts/players_house.pory"
	lock
# 518 "data//scripts/players_house.pory"
	faceplayer
# 519 "data//scripts/players_house.pory"
	waitse
# 520 "data//scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
# 521 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
# 522 "data//scripts/players_house.pory"
	waitmoncry
# 523 "data//scripts/players_house.pory"
	release
# 524 "data//scripts/players_house.pory"
	end
# 525 "data//scripts/players_house.pory"

# 526 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
# 527 "data//scripts/players_house.pory"
	walk_fast_down
# 528 "data//scripts/players_house.pory"
	walk_fast_down
# 529 "data//scripts/players_house.pory"
	walk_fast_left
# 530 "data//scripts/players_house.pory"
	walk_fast_left
# 531 "data//scripts/players_house.pory"
	walk_fast_left
# 532 "data//scripts/players_house.pory"
	jump_in_place_left
# 533 "data//scripts/players_house.pory"
	step_end
# 534 "data//scripts/players_house.pory"
	
# 535 "data//scripts/players_house.pory"

# 536 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVMale:
# 537 "data//scripts/players_house.pory"
	walk_left
# 538 "data//scripts/players_house.pory"
	step_end
# 539 "data//scripts/players_house.pory"

# 540 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
# 541 "data//scripts/players_house.pory"
	walk_fast_down
# 542 "data//scripts/players_house.pory"
	walk_fast_down
# 543 "data//scripts/players_house.pory"
	walk_fast_right
# 544 "data//scripts/players_house.pory"
	walk_fast_right
# 545 "data//scripts/players_house.pory"
	walk_fast_right
# 546 "data//scripts/players_house.pory"
	jump_in_place_right
# 547 "data//scripts/players_house.pory"
	step_end
# 548 "data//scripts/players_house.pory"
	
# 549 "data//scripts/players_house.pory"

# 550 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
# 551 "data//scripts/players_house.pory"
	walk_right
# 552 "data//scripts/players_house.pory"
	step_end
# 553 "data//scripts/players_house.pory"

# 554 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
# 555 "data//scripts/players_house.pory"
	walk_up
# 556 "data//scripts/players_house.pory"
	step_end
# 557 "data//scripts/players_house.pory"

# 558 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
# 559 "data//scripts/players_house.pory"
	lockall
# 560 "data//scripts/players_house.pory"
	checkplayergender
# 561 "data//scripts/players_house.pory"
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
# 562 "data//scripts/players_house.pory"
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
# 563 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerEnterRoomMale
# 564 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
# 565 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_FacePlayer
# 566 "data//scripts/players_house.pory"
	waitmovement 0
# 567 "data//scripts/players_house.pory"
	playse SE_PIN
# 568 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 569 "data//scripts/players_house.pory"
	waitmovement 0
# 570 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_Delay48
# 571 "data//scripts/players_house.pory"
	waitmovement 0
# 572 "data//scripts/players_house.pory"
	delay 20
# 573 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadApproachPlayerMale
# 574 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadApproachPlayerFemale
# 575 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
# 576 "data//scripts/players_house.pory"
	giveitem ITEM_SS_TICKET
# 577 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
# 578 "data//scripts/players_house.pory"
	closemessage
# 579 "data//scripts/players_house.pory"
	delay 20
# 580 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachDadMale
# 581 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachDadFemale
# 582 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
# 583 "data//scripts/players_house.pory"
	closemessage
# 584 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadExitsMale
# 585 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadExitsFemale
# 586 "data//scripts/players_house.pory"
	playse SE_DOOR
# 587 "data//scripts/players_house.pory"
	removeobject VAR_0x8009
# 588 "data//scripts/players_house.pory"
	setflag FLAG_RECEIVED_SS_TICKET
# 589 "data//scripts/players_house.pory"
	delay 30
# 590 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerMale
# 591 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerFemale
# 592 "data//scripts/players_house.pory"
	delay 20
# 593 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
# 594 "data//scripts/players_house.pory"
	closemessage
# 595 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 596 "data//scripts/players_house.pory"
	special TurnOnTVScreen
# 597 "data//scripts/players_house.pory"
	delay 60
# 598 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
# 599 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
# 600 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
# 601 "data//scripts/players_house.pory"
	closemessage
# 602 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
# 603 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
# 604 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
# 605 "data//scripts/players_house.pory"
	closemessage
# 606 "data//scripts/players_house.pory"
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
# 607 "data//scripts/players_house.pory"
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
# 608 "data//scripts/players_house.pory"
	setvar VAR_UNUSED_0x8014, 2
# 609 "data//scripts/players_house.pory"
	special TurnOffTVScreen
# 610 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
# 611 "data//scripts/players_house.pory"
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
# 612 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
# 613 "data//scripts/players_house.pory"
	multichoice 22, 8, MULTI_TV_LATI, TRUE
# 614 "data//scripts/players_house.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 615 "data//scripts/players_house.pory"
	special InitRoamer
# 616 "data//scripts/players_house.pory"
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
# 617 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
# 618 "data//scripts/players_house.pory"
	closemessage
# 619 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
# 620 "data//scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
# 621 "data//scripts/players_house.pory"
	releaseall
# 622 "data//scripts/players_house.pory"
	end
# 623 "data//scripts/players_house.pory"

# 624 "data//scripts/players_house.pory"
@ Never called.
# 625 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_AirLatiBroadcast::
# 626 "data//scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 627 "data//scripts/players_house.pory"
	return
# 628 "data//scripts/players_house.pory"

# 629 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
# 630 "data//scripts/players_house.pory"
	setvar VAR_0x8008, MALE
# 631 "data//scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_PLAYERS_HOUSE_1F_DAD
# 632 "data//scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_PLAYERS_HOUSE_1F_MOM
# 633 "data//scripts/players_house.pory"
	return
# 634 "data//scripts/players_house.pory"

# 635 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
# 636 "data//scripts/players_house.pory"
	setvar VAR_0x8008, FEMALE
# 637 "data//scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_PLAYERS_HOUSE_1F_DAD
# 638 "data//scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_PLAYERS_HOUSE_1F_MOM
# 639 "data//scripts/players_house.pory"
	return
# 640 "data//scripts/players_house.pory"

# 641 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerMale::
# 642 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
# 643 "data//scripts/players_house.pory"
	waitmovement 0
# 644 "data//scripts/players_house.pory"
	return
# 645 "data//scripts/players_house.pory"

# 646 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
# 647 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
# 648 "data//scripts/players_house.pory"
	waitmovement 0
# 649 "data//scripts/players_house.pory"
	return
# 650 "data//scripts/players_house.pory"

# 651 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadMale::
# 652 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
# 653 "data//scripts/players_house.pory"
	waitmovement 0
# 654 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
# 655 "data//scripts/players_house.pory"
	waitmovement 0
# 656 "data//scripts/players_house.pory"
	return
# 657 "data//scripts/players_house.pory"

# 658 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadFemale::
# 659 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
# 660 "data//scripts/players_house.pory"
	waitmovement 0
# 661 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
# 662 "data//scripts/players_house.pory"
	waitmovement 0
# 663 "data//scripts/players_house.pory"
	return
# 664 "data//scripts/players_house.pory"

# 665 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsMale::
# 666 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 667 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 668 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
# 669 "data//scripts/players_house.pory"
	waitmovement 0
# 670 "data//scripts/players_house.pory"
	return
# 671 "data//scripts/players_house.pory"

# 672 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsFemale::
# 673 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 674 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 675 "data//scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
# 676 "data//scripts/players_house.pory"
	waitmovement 0
# 677 "data//scripts/players_house.pory"
	return
# 678 "data//scripts/players_house.pory"

# 679 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
# 680 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
# 681 "data//scripts/players_house.pory"
	waitmovement 0
# 682 "data//scripts/players_house.pory"
	return
# 683 "data//scripts/players_house.pory"

# 684 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
# 685 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
# 686 "data//scripts/players_house.pory"
	waitmovement 0
# 687 "data//scripts/players_house.pory"
	return
# 688 "data//scripts/players_house.pory"

# 689 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
# 690 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
# 691 "data//scripts/players_house.pory"
	waitmovement 0
# 692 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterLeft
# 693 "data//scripts/players_house.pory"
	waitmovement 0
# 694 "data//scripts/players_house.pory"
	return
# 695 "data//scripts/players_house.pory"

# 696 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
# 697 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
# 698 "data//scripts/players_house.pory"
	waitmovement 0
# 699 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterRight
# 700 "data//scripts/players_house.pory"
	waitmovement 0
# 701 "data//scripts/players_house.pory"
	return
# 702 "data//scripts/players_house.pory"

# 703 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerMale::
# 704 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
# 705 "data//scripts/players_house.pory"
	waitmovement 0
# 706 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 707 "data//scripts/players_house.pory"
	waitmovement 0
# 708 "data//scripts/players_house.pory"
	return
# 709 "data//scripts/players_house.pory"

# 710 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
# 711 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
# 712 "data//scripts/players_house.pory"
	waitmovement 0
# 713 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 714 "data//scripts/players_house.pory"
	waitmovement 0
# 715 "data//scripts/players_house.pory"
	return
# 716 "data//scripts/players_house.pory"

# 717 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
# 718 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
# 719 "data//scripts/players_house.pory"
	waitmovement 0
# 720 "data//scripts/players_house.pory"
	return
# 721 "data//scripts/players_house.pory"

# 722 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
# 723 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
# 724 "data//scripts/players_house.pory"
	waitmovement 0
# 725 "data//scripts/players_house.pory"
	return
# 726 "data//scripts/players_house.pory"

# 727 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
# 728 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
# 729 "data//scripts/players_house.pory"
	waitmovement 0
# 730 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 731 "data//scripts/players_house.pory"
	waitmovement 0
# 732 "data//scripts/players_house.pory"
	return
# 733 "data//scripts/players_house.pory"

# 734 "data//scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
# 735 "data//scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
# 736 "data//scripts/players_house.pory"
	waitmovement 0
# 737 "data//scripts/players_house.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 738 "data//scripts/players_house.pory"
	waitmovement 0
# 739 "data//scripts/players_house.pory"
	return
# 740 "data//scripts/players_house.pory"

# 741 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerMale:
# 742 "data//scripts/players_house.pory"
	walk_right
# 743 "data//scripts/players_house.pory"
	walk_right
# 744 "data//scripts/players_house.pory"
	step_end
# 745 "data//scripts/players_house.pory"

# 746 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerFemale:
# 747 "data//scripts/players_house.pory"
	walk_left
# 748 "data//scripts/players_house.pory"
	walk_left
# 749 "data//scripts/players_house.pory"
	step_end
# 750 "data//scripts/players_house.pory"

# 751 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomMale:
# 752 "data//scripts/players_house.pory"
	face_left
# 753 "data//scripts/players_house.pory"
	step_end
# 754 "data//scripts/players_house.pory"

# 755 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomFemale:
# 756 "data//scripts/players_house.pory"
	face_right
# 757 "data//scripts/players_house.pory"
	step_end
# 758 "data//scripts/players_house.pory"

# 759 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsMale:
# 760 "data//scripts/players_house.pory"
	walk_down
# 761 "data//scripts/players_house.pory"
	walk_right
# 762 "data//scripts/players_house.pory"
	walk_down
# 763 "data//scripts/players_house.pory"
	delay_8
# 764 "data//scripts/players_house.pory"
	step_end
# 765 "data//scripts/players_house.pory"

# 766 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsFemale:
# 767 "data//scripts/players_house.pory"
	walk_down
# 768 "data//scripts/players_house.pory"
	walk_left
# 769 "data//scripts/players_house.pory"
	walk_down
# 770 "data//scripts/players_house.pory"
	delay_8
# 771 "data//scripts/players_house.pory"
	step_end
# 772 "data//scripts/players_house.pory"

# 773 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomMale:
# 774 "data//scripts/players_house.pory"
	delay_16
# 775 "data//scripts/players_house.pory"
	walk_down
# 776 "data//scripts/players_house.pory"
	walk_down
# 777 "data//scripts/players_house.pory"
	walk_down
# 778 "data//scripts/players_house.pory"
	walk_in_place_faster_left
# 779 "data//scripts/players_house.pory"
	step_end
# 780 "data//scripts/players_house.pory"

# 781 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
# 782 "data//scripts/players_house.pory"
	delay_8
# 783 "data//scripts/players_house.pory"
	delay_16
# 784 "data//scripts/players_house.pory"
	delay_16
# 785 "data//scripts/players_house.pory"
	walk_in_place_faster_down
# 786 "data//scripts/players_house.pory"
	step_end
# 787 "data//scripts/players_house.pory"

# 788 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
# 789 "data//scripts/players_house.pory"
	delay_16
# 790 "data//scripts/players_house.pory"
	walk_down
# 791 "data//scripts/players_house.pory"
	walk_down
# 792 "data//scripts/players_house.pory"
	walk_down
# 793 "data//scripts/players_house.pory"
	walk_in_place_faster_right
# 794 "data//scripts/players_house.pory"
	step_end
# 795 "data//scripts/players_house.pory"

# 796 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
# 797 "data//scripts/players_house.pory"
	walk_up
# 798 "data//scripts/players_house.pory"
	walk_left
# 799 "data//scripts/players_house.pory"
	walk_left
# 800 "data//scripts/players_house.pory"
	walk_left
# 801 "data//scripts/players_house.pory"
	walk_left
# 802 "data//scripts/players_house.pory"
	walk_in_place_faster_up
# 803 "data//scripts/players_house.pory"
	step_end
# 804 "data//scripts/players_house.pory"

# 805 "data//scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
# 806 "data//scripts/players_house.pory"
	walk_up
# 807 "data//scripts/players_house.pory"
	walk_right
# 808 "data//scripts/players_house.pory"
	walk_right
# 809 "data//scripts/players_house.pory"
	walk_right
# 810 "data//scripts/players_house.pory"
	walk_right
# 811 "data//scripts/players_house.pory"
	walk_in_place_faster_up
# 812 "data//scripts/players_house.pory"
	step_end
# 813 "data//scripts/players_house.pory"

# 814 "data//scripts/players_house.pory"
EventScript_RunningShoesManual::
# 815 "data//scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
# 816 "data//scripts/players_house.pory"
	end

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_0:
# 377 "data//scripts/players_house.pory"
	.string "{PLAYER} obtained a {STR_VAR_1}.$"

PlayersHouse_1F_EventScript_MomGivesMonAfterWhiteOut_Text_1:
# 397 "data//scripts/players_house.pory"
	.string "Good luck out there, {PLAYER}…\p"
	.string "Try to be more careful,{PAUSE 20}\n"
	.string "okay?$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_0:
# 409 "data//scripts/players_house.pory"
	.string "Wow,{PAUSE 20} you're all out of PC storage space!\p"
	.string "Let me hold onto one of your dead\n"
	.string "POKéMON, then.\p"
	.string "If we can revive it, we'll let the gym\n"
	.string "trainers use it instead of this\l"
	.string "{STR_VAR_1}.$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_1:
# 415 "data//scripts/players_house.pory"
	.string "You really ought to have a living\n"
	.string "POKéMON in your party…\p"
	.string "Come on, {PLAYER}.\p"
	.string "Choose a dead POKéMON to give me.$"

PlayersHouse_1F_EventScript_NoMoreRoomForPokemon_Text_2:
# 435 "data//scripts/players_house.pory"
	.string "{PLAYER} handed over the dead\n"
	.string "POKéMON.$"

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_0:
# 453 "data//scripts/players_house.pory"
	.string "Oh,{PAUSE 20} but you don't have room for it in\n"
	.string "your party…\p"
	.string "Let's send one of your POKéMON to the\n"
	.string "PC, then.$"

PlayersHouse_1F_EventScript_NoRoomForPartyPokemon_Text_1:
# 458 "data//scripts/players_house.pory"
	.string "You really ought to have a living\n"
	.string "POKéMON in your party…\p"
	.string "Come on, {PLAYER}.\p"
	.string "Let's send one of your POKéMON to the\n"
	.string "PC.$"
