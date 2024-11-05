# 1 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 2 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_MapScripts::
# 3 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
# 4 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	.byte 0
# 5 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 6 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_OnTransition:
# 7 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 8 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 9 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 10 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_OnFrame:
# 11 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
# 12 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	.2byte 0
# 13 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 14 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
# 15 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 16 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
# 17 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 18 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 19 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 20 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 21 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 22 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_ExitSafariZone:
# 23 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_up
# 24 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
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
	step_end
# 32 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 33 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
# 34 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
# 35 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 36 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 37 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_InfoAttendant::
# 38 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lock
# 39 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	faceplayer
# 40 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
# 41 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
# 42 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
# 43 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 44 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 45 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 46 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
# 47 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
# 48 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	release
# 49 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 50 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 51 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
# 52 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	lockall
# 53 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 54 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 55 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	showmoneybox 0, 0
# 56 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
# 57 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
# 58 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
# 59 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 60 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 61 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 62 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
# 63 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	checkitem ITEM_POKEBLOCK_CASE
# 64 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
# 65 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
# 66 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	checkmoney 500
# 67 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
# 68 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	playse SE_SHOP
# 69 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
# 70 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	removemoney 500
# 71 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	updatemoneybox
# 72 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
# 73 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 74 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
# 75 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitfanfare
# 76 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
# 77 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 78 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 79 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
# 80 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 81 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	special EnterSafariMode
# 82 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 2
# 83 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 84 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
# 85 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitstate
# 86 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 87 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 88 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
# 89 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	getpartysize
# 90 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 91 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
# 92 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
# 93 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
# 94 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 95 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 96 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 97 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
# 98 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	return
# 99 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 100 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
# 101 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
# 102 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 103 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 104 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 105 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
# 106 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 107 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
# 108 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 109 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 110 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
# 111 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	closemessage
# 112 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	hidemoneybox
# 113 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
# 114 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	waitmovement 0
# 115 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	releaseall
# 116 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
# 117 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 118 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
# 119 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_right
# 120 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 121 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 122 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_Movement_EnterSafariZone:
# 123 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	walk_left
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
	walk_down
# 130 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	delay_16
# 131 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	step_end
# 132 "data//maps/Route121_SafariZoneEntrance/scripts.pory"

# 133 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
# 134 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
# 135 "data//maps/Route121_SafariZoneEntrance/scripts.pory"
	end
