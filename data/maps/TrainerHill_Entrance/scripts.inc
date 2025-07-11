# 1 "data//maps/TrainerHill_Entrance/scripts.pory"

# 2 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_MapScripts::
# 3 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
# 4 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
# 5 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
# 6 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
# 7 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
# 8 "data//maps/TrainerHill_Entrance/scripts.pory"
	.byte 0
# 9 "data//maps/TrainerHill_Entrance/scripts.pory"

# 10 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnTransition:
# 11 "data//maps/TrainerHill_Entrance/scripts.pory"
	setflag FLAG_LANDMARK_TRAINER_HILL
# 12 "data//maps/TrainerHill_Entrance/scripts.pory"
	getplayerxy VAR_TEMP_D, VAR_RESULT
# 13 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 14 "data//maps/TrainerHill_Entrance/scripts.pory"

# 15 "data//maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 16 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnWarp:
# 17 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 18 "data//maps/TrainerHill_Entrance/scripts.pory"

# 19 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnResume:
# 20 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_resumetimer
# 21 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_0, 0
# 22 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getusingereader
# 23 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
# 24 "data//maps/TrainerHill_Entrance/scripts.pory"
	setobjectxy LOCALID_PLAYER, 9, 6
# 25 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 26 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 27 "data//maps/TrainerHill_Entrance/scripts.pory"

# 28 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_TryFaceAttendant::
# 29 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getwon
# 30 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
# 31 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 32 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 33 "data//maps/TrainerHill_Entrance/scripts.pory"

# 34 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
# 35 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 36 "data//maps/TrainerHill_Entrance/scripts.pory"

# 37 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnReturn:
# 38 "data//maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_TRAINER_HILL_NURSE
# 39 "data//maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_TRAINER_HILL_ATTENDANT
# 40 "data//maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_TRAINER_HILL_MAN
# 41 "data//maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_TRAINER_HILL_GIRL
# 42 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 43 "data//maps/TrainerHill_Entrance/scripts.pory"

# 44 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnLoad:
# 45 "data//maps/TrainerHill_Entrance/scripts.pory"
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
# 46 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 47 "data//maps/TrainerHill_Entrance/scripts.pory"

# 48 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_OpenCounterDoor::
# 49 "data//maps/TrainerHill_Entrance/scripts.pory"
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
# 50 "data//maps/TrainerHill_Entrance/scripts.pory"
	return
# 51 "data//maps/TrainerHill_Entrance/scripts.pory"

# 52 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnFrame:
# 53 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
# 54 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
# 55 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
# 56 "data//maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
# 57 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte 0
# 58 "data//maps/TrainerHill_Entrance/scripts.pory"

# 59 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitElevator::
# 60 "data//maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 61 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
# 62 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 63 "data//maps/TrainerHill_Entrance/scripts.pory"
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
# 64 "data//maps/TrainerHill_Entrance/scripts.pory"
	special DrawWholeMapView
# 65 "data//maps/TrainerHill_Entrance/scripts.pory"
	playse SE_CLICK
# 66 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitse
# 67 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_D, 0
# 68 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 69 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 70 "data//maps/TrainerHill_Entrance/scripts.pory"

# 71 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallenge::
# 72 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_0, 1
# 73 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getstatus
# 74 "data//maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 75 "data//maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
# 76 "data//maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
# 77 "data//maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge
# 78 "data//maps/TrainerHill_Entrance/scripts.pory"

# 79 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallengeLost::
# 80 "data//maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 81 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 82 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
# 83 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge
# 84 "data//maps/TrainerHill_Entrance/scripts.pory"

# 85 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallengeECard::
# 86 "data//maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 87 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 88 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
# 89 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
# 90 "data//maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 91 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 92 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 93 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 94 "data//maps/TrainerHill_Entrance/scripts.pory"
	special HealPlayerParty
# 95 "data//maps/TrainerHill_Entrance/scripts.pory"
	callnative UpdateFollowingPokemon
# 96 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 97 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_EndExitChallenge::
# 98 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 99 "data//maps/TrainerHill_Entrance/scripts.pory"

# 100 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Nurse::
# 101 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
# 102 "data//maps/TrainerHill_Entrance/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 103 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 104 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitbuttonpress
# 105 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 106 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 107 "data//maps/TrainerHill_Entrance/scripts.pory"

# 108 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Attendant::
# 109 "data//maps/TrainerHill_Entrance/scripts.pory"
	lock
# 110 "data//maps/TrainerHill_Entrance/scripts.pory"
	faceplayer
# 111 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_inchallenge
# 112 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
# 113 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
# 114 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AttendantEnd
# 115 "data//maps/TrainerHill_Entrance/scripts.pory"

# 116 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ThanksForPlaying::
# 117 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
# 118 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AttendantEnd::
# 119 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 120 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 121 "data//maps/TrainerHill_Entrance/scripts.pory"

# 122 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_EntryTrigger::
# 123 "data//maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 124 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 125 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
# 126 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
# 127 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getsaved
# 128 "data//maps/TrainerHill_Entrance/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
# 129 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_allfloorsused
# 130 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
# 131 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
# 132 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
# 133 "data//maps/TrainerHill_Entrance/scripts.pory"

# 134 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AllFloorsUsed::
# 135 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
# 136 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
# 137 "data//maps/TrainerHill_Entrance/scripts.pory"
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
# 138 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 139 "data//maps/TrainerHill_Entrance/scripts.pory"
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
# 140 "data//maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 141 "data//maps/TrainerHill_Entrance/scripts.pory"
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
# 142 "data//maps/TrainerHill_Entrance/scripts.pory"
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
# 143 "data//maps/TrainerHill_Entrance/scripts.pory"
	case 2, TrainerHill_Entrance_EventScript_Info
# 144 "data//maps/TrainerHill_Entrance/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
# 145 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 146 "data//maps/TrainerHill_Entrance/scripts.pory"

# 147 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Info::
# 148 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
# 149 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
# 150 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 151 "data//maps/TrainerHill_Entrance/scripts.pory"

# 152 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ChooseChallenge::
# 153 "data//maps/TrainerHill_Entrance/scripts.pory"
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
# 154 "data//maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 155 "data//maps/TrainerHill_Entrance/scripts.pory"
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
# 156 "data//maps/TrainerHill_Entrance/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
# 157 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_setmode VAR_RESULT
# 158 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
# 159 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 0
# 160 "data//maps/TrainerHill_Entrance/scripts.pory"
	special HealPlayerParty
# 161 "data//maps/TrainerHill_Entrance/scripts.pory"
	callnative UpdateFollowingPokemon
# 162 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
# 163 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_start
# 164 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 165 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 166 "data//maps/TrainerHill_Entrance/scripts.pory"

# 167 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_CancelEntry::
# 168 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 0
# 169 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
# 170 "data//maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 171 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 172 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 173 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 174 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 175 "data//maps/TrainerHill_Entrance/scripts.pory"

# 176 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_SaveGame::
# 177 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
# 178 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_setsaved
# 179 "data//maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 1
# 180 "data//maps/TrainerHill_Entrance/scripts.pory"
	call Common_EventScript_SaveGame
# 181 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
# 182 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_setsaved
# 183 "data//maps/TrainerHill_Entrance/scripts.pory"
	return
# 184 "data//maps/TrainerHill_Entrance/scripts.pory"

# 185 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_SaveFailed::
# 186 "data//maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_clearsaved
# 187 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_CancelEntry
# 188 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 189 "data//maps/TrainerHill_Entrance/scripts.pory"

# 190 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Closed::
# 191 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
# 192 "data//maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 193 "data//maps/TrainerHill_Entrance/scripts.pory"
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 194 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 195 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 196 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 197 "data//maps/TrainerHill_Entrance/scripts.pory"

# 198 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PlayerFaceAttendant:
# 199 "data//maps/TrainerHill_Entrance/scripts.pory"
	face_right
# 200 "data//maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 201 "data//maps/TrainerHill_Entrance/scripts.pory"

# 202 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
# 203 "data//maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 204 "data//maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 205 "data//maps/TrainerHill_Entrance/scripts.pory"

# 206 "data//maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 207 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_FaceUp:
# 208 "data//maps/TrainerHill_Entrance/scripts.pory"
	face_up
# 209 "data//maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 210 "data//maps/TrainerHill_Entrance/scripts.pory"

# 211 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PlayerExitElevator:
# 212 "data//maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 213 "data//maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 214 "data//maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 215 "data//maps/TrainerHill_Entrance/scripts.pory"

# 216 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Records::
# 217 "data//maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 218 "data//maps/TrainerHill_Entrance/scripts.pory"
	fadescreen FADE_TO_BLACK
# 219 "data//maps/TrainerHill_Entrance/scripts.pory"
	special ShowTrainerHillRecords
# 220 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitstate
# 221 "data//maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 222 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 223 "data//maps/TrainerHill_Entrance/scripts.pory"

# 224 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Man::
# 225 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
# 226 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
# 227 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 228 "data//maps/TrainerHill_Entrance/scripts.pory"

# 229 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
# 230 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
# 231 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 232 "data//maps/TrainerHill_Entrance/scripts.pory"

# 233 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Girl::
# 234 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
# 235 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
# 236 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 237 "data//maps/TrainerHill_Entrance/scripts.pory"

# 238 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
# 239 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
# 240 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 241 "data//maps/TrainerHill_Entrance/scripts.pory"

# 242 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Clerk::
# 243 "data//maps/TrainerHill_Entrance/scripts.pory"
	lock
# 244 "data//maps/TrainerHill_Entrance/scripts.pory"
	faceplayer
# 245 "data//maps/TrainerHill_Entrance/scripts.pory"
	message gText_HowMayIServeYou
# 246 "data//maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 247 "data//maps/TrainerHill_Entrance/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
# 248 "data//maps/TrainerHill_Entrance/scripts.pory"
	pokemart TrainerHill_Entrance_Pokemart_Basic
# 249 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 250 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 251 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 252 "data//maps/TrainerHill_Entrance/scripts.pory"

# 253 "data//maps/TrainerHill_Entrance/scripts.pory"
	.align 2
# 254 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Pokemart_Basic:
# 255 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 256 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 257 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 258 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_AWAKENING
# 259 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_NONE
# 260 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 261 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 262 "data//maps/TrainerHill_Entrance/scripts.pory"

# 263 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExpandedPokemart::
# 264 "data//maps/TrainerHill_Entrance/scripts.pory"
	pokemart TrainerHill_Entrance_Pokemart_Expanded
# 265 "data//maps/TrainerHill_Entrance/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 266 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 267 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 268 "data//maps/TrainerHill_Entrance/scripts.pory"

# 269 "data//maps/TrainerHill_Entrance/scripts.pory"
	.align 2
# 270 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Pokemart_Expanded:
# 271 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 272 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_MAX_POTION
# 273 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 274 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 275 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_LIECHI_BERRY
# 276 "data//maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_NONE
# 277 "data//maps/TrainerHill_Entrance/scripts.pory"
	release
# 278 "data//maps/TrainerHill_Entrance/scripts.pory"
	end
# 279 "data//maps/TrainerHill_Entrance/scripts.pory"

# 280 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_StillGettingReady:
# 281 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "This is the TRAINER HILL where\n"
# 282 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "you may enjoy tag battles with many\l"
# 283 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "TRAINERS.\p"
# 284 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Unfortunately, we're still getting\n"
# 285 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "things ready. Please come back later!$"
# 286 "data//maps/TrainerHill_Entrance/scripts.pory"

# 287 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_WelcomeToTrainerHill:
# 288 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Welcome!\p"
# 289 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "This is the TRAINER HILL where\n"
# 290 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "you may enjoy tag battles with many\l"
# 291 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "TRAINERS!$"
# 292 "data//maps/TrainerHill_Entrance/scripts.pory"

# 293 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_SaveGameBeforeEnter:
# 294 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Is this your first visit here?\p"
# 295 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Before you enter, please save\n"
# 296 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "your game.$"
# 297 "data//maps/TrainerHill_Entrance/scripts.pory"

# 298 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TrainersUpToFloorX:
# 299 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Let's see…\n"
# 300 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "The TRAINERS here now are…\p"
# 301 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Up to floor no. {STR_VAR_1}.$"
# 302 "data//maps/TrainerHill_Entrance/scripts.pory"

# 303 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TrainersInEveryRoom:
# 304 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Let's see…\n"
# 305 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "The TRAINERS here now are…\p"
# 306 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "There appear to be TRAINERS gathered\n"
# 307 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "in every room.$"
# 308 "data//maps/TrainerHill_Entrance/scripts.pory"

# 309 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_LikeToChallengeTrainers:
# 310 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Would you like to challenge the\n"
# 311 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "waiting TRAINERS?$"
# 312 "data//maps/TrainerHill_Entrance/scripts.pory"

# 313 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TimeProgessGetSetGo:
# 314 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I will time your progress.\n"
# 315 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Best of luck!\p"
# 316 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "On your marks…\p"
# 317 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Get set…\p"
# 318 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Go!$"
# 319 "data//maps/TrainerHill_Entrance/scripts.pory"

# 320 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_PleaseVisitUsAgain:
# 321 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Please do visit us again!$"
# 322 "data//maps/TrainerHill_Entrance/scripts.pory"

# 323 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TooBadTremendousEffort:
# 324 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "That was too bad.\p"
# 325 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I think you put in a tremendous\n"
# 326 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "effort in your battling.\p"
# 327 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Please come back and try again!$"
# 328 "data//maps/TrainerHill_Entrance/scripts.pory"

# 329 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
# 330 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I hope you give it your best.$"
# 331 "data//maps/TrainerHill_Entrance/scripts.pory"

# 332 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
# 333 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "When the TRAINERS switch places,\n"
# 334 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "the movement can be hectic.\p"
# 335 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "To avoid the stampede, we moved\n"
# 336 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "the reception counter here.\p"
# 337 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I'm sorry for the inconvenience.$"
# 338 "data//maps/TrainerHill_Entrance/scripts.pory"

# 339 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ThankYouForPlaying:
# 340 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Thank you for playing!$"
# 341 "data//maps/TrainerHill_Entrance/scripts.pory"

# 342 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ExplainTrainerHill:
# 343 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Here at the TRAINER HILL, we conduct\n"
# 344 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "an event called the Time Attack.\p"
# 345 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "It is a race that measures how long\n"
# 346 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "you take to reach our owner on\l"
# 347 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "the rooftop from this counter.\p"
# 348 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "The fastest times are posted on\n"
# 349 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "the Time Board--try competing with\l"
# 350 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "your friends.\p"
# 351 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "In TRAINER battles along the way,\n"
# 352 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "neither Exp. Points nor money will\l"
# 353 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "be awarded.$"
# 354 "data//maps/TrainerHill_Entrance/scripts.pory"

# 355 "data//maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 356 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
# 357 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, I'm sorry, but you appear to have\n"
# 358 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "only one POKéMON with you.\p"
# 359 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You will need at least two POKéMON\n"
# 360 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "to enter this event.$"
# 361 "data//maps/TrainerHill_Entrance/scripts.pory"

# 362 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_YouFinallyCameBravo:
# 363 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Hm! Hm!\p"
# 364 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You finally came!\n"
# 365 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Yes, you have arrived!\p"
# 366 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Wait! Don't say it!\n"
# 367 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I know why you came all the way\l"
# 368 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "here by yourself!\p"
# 369 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You wanted to see me, the owner\n"
# 370 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "of the TRAINER HILL, because…\p"
# 371 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You want to form a tag team with me!\n"
# 372 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Wa-hoo!\p"
# 373 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "…Uh?\n"
# 374 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "That's not it?\p"
# 375 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Anyway, I watched you on your way up.\n"
# 376 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Marvelous battling! Bravo, indeed!$"
# 377 "data//maps/TrainerHill_Entrance/scripts.pory"

# 378 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
# 379 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "For a marvelous someone like you,\n"
# 380 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I have the most marvelous gift!$"
# 381 "data//maps/TrainerHill_Entrance/scripts.pory"

# 382 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
# 383 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, no, full up with things!\n"
# 384 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You'll be back later for this!$"
# 385 "data//maps/TrainerHill_Entrance/scripts.pory"

# 386 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
# 387 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, hold on here! Did you possibly get\n"
# 388 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "here marvelously quickly?\p"
# 389 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "How splendid! You needn't have\n"
# 390 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "hurried so to see me!\p"
# 391 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "That is so delightful. I'll have the Time\n"
# 392 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Board at the reception updated!$"
# 393 "data//maps/TrainerHill_Entrance/scripts.pory"

# 394 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_YouWerentVeryQuick:
# 395 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "But, oh…\n"
# 396 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "You weren't very quick getting here.$"
# 397 "data//maps/TrainerHill_Entrance/scripts.pory"

# 398 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_ArriveZippierNextTime:
# 399 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Perhaps it would please me more if you\n"
# 400 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "arrived zippier next time.\p"
# 401 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Then, I should be pleased to form\n"
# 402 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "a tag team with you!\p"
# 403 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Until we meet again, amigo!$"
# 404 "data//maps/TrainerHill_Entrance/scripts.pory"

# 405 "data//maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 406 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
# 407 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I had the TRAINER HILL built for but\n"
# 408 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "one reason and one only!\p"
# 409 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "To find the most suitable partner\n"
# 410 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "with whom I may form a tag team!$"
# 411 "data//maps/TrainerHill_Entrance/scripts.pory"

# 412 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ChallengeTime:
# 413 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
# 414 "data//maps/TrainerHill_Entrance/scripts.pory"

# 415 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
# 416 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Who knows what sort of TRAINERS\n"
# 417 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "and POKéMON combos are ahead?\p"
# 418 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "All I know is that I'll knock aside\n"
# 419 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "anyone that stands in my way!$"
# 420 "data//maps/TrainerHill_Entrance/scripts.pory"

# 421 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
# 422 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I heard tough TRAINERS come to this\n"
# 423 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "TRAINER HILL from all over.\p"
# 424 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I can't wait to test the waters!\p"
# 425 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I'll knock aside anyone that stands\n"
# 426 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "in my way!$"
# 427 "data//maps/TrainerHill_Entrance/scripts.pory"

# 428 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
# 429 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Do you see the Time Board over there?\p"
# 430 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "My friends and I are trying to see who\n"
# 431 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "can reach the top in the least time.$"
# 432 "data//maps/TrainerHill_Entrance/scripts.pory"

# 433 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
# 434 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Do you know when they're opening\n"
# 435 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "this place up?\p"
# 436 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "I'm waiting here to be the first\n"
# 437 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "challenger ever!$"
# 438 "data//maps/TrainerHill_Entrance/scripts.pory"

# 439 "data//maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Elevator_Text_ReturnToReception:
# 440 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "Would you like to return to\n"
# 441 "data//maps/TrainerHill_Entrance/scripts.pory"
	.string "the reception counter?$"
