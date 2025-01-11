# 1 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 2 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_MapScripts::
# 3 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
# 4 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION Route121_SafariZoneEntrance_OnTransition
# 5 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	.byte 0
# 6 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 7 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_OnTransition:
# 8 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 9 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 10 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 11 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_OnFrame:
# 12 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
# 13 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	.2byte 0
# 14 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 15 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
# 16 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 17 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
# 18 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 19 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 20 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 21 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 22 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 23 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_ExitSafariZone:
# 24 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_up
# 25 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 26 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 27 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 28 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 29 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 30 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 31 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 32 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 33 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 34 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
# 35 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
# 36 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 37 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 38 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_InfoAttendant::
# 39 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lock
# 40 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	faceplayer
# 41 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
# 42 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
# 43 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
# 44 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 45 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 46 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 47 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
# 48 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
# 49 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 50 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 51 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 52 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
# 53 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 54 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 55 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 56 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	showmoneybox 0, 0
# 57 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
# 58 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
# 59 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
# 60 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 61 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 62 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 63 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
# 64 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	checkitem ITEM_POKEBLOCK_CASE
# 65 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
# 66 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
# 67 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	checkmoney 500
# 68 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
# 69 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	playse SE_SHOP
# 70 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
# 71 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	removemoney 500
# 72 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	updatemoneybox
# 73 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
# 74 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 75 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
# 76 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitfanfare
# 77 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
# 78 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 79 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 80 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
# 81 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 82 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	special EnterSafariMode
# 83 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 2
# 84 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 85 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
# 86 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitstate
# 87 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 88 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 89 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
# 90 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	getpartysize
# 91 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 92 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
# 93 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 94 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
# 95 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 96 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 97 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 98 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
# 99 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	return
# 100 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 101 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
# 102 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
# 103 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 104 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 105 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 106 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
# 107 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 108 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 109 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 110 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 111 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
# 112 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 113 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 114 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
# 115 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 116 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 117 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 118 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 119 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
# 120 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 121 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 122 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 123 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_EnterSafariZone:
# 124 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 125 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 126 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 127 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 128 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 129 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
# 130 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_down
# 131 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	delay_16
# 132 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 133 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 134 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
# 135 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
# 136 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
