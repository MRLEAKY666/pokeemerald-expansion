# 1 "data//maps/Route102/scripts.pory"

# 2 "data//maps/Route102/scripts.pory"
Route102_MapScripts::
# 3 "data//maps/Route102/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route102_OnTransition
# 4 "data//maps/Route102/scripts.pory"
	.byte 0
# 5 "data//maps/Route102/scripts.pory"

# 6 "data//maps/Route102/scripts.pory"
Route102_OnTransition:
# 7 "data//maps/Route102/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 8 "data//maps/Route102/scripts.pory"
	end
# 9 "data//maps/Route102/scripts.pory"

# 10 "data//maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 11 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 12 "data//maps/Route102/scripts.pory"
	end
# 13 "data//maps/Route102/scripts.pory"

# 14 "data//maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 15 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 16 "data//maps/Route102/scripts.pory"
	end
# 17 "data//maps/Route102/scripts.pory"

# 18 "data//maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 19 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 20 "data//maps/Route102/scripts.pory"
	end
# 21 "data//maps/Route102/scripts.pory"

# 22 "data//maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 23 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 24 "data//maps/Route102/scripts.pory"
	end
# 25 "data//maps/Route102/scripts.pory"

# 26 "data//maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 27 "data//maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 28 "data//maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 29 "data//maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 30 "data//maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 31 "data//maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 32 "data//maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 33 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 34 "data//maps/Route102/scripts.pory"
	release
# 35 "data//maps/Route102/scripts.pory"
	end
# 36 "data//maps/Route102/scripts.pory"

# 37 "data//maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 38 "data//maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 39 "data//maps/Route102/scripts.pory"
	waitmovement 0
# 40 "data//maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 41 "data//maps/Route102/scripts.pory"
	release
# 42 "data//maps/Route102/scripts.pory"
	end
# 43 "data//maps/Route102/scripts.pory"

# 44 "data//maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 45 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 46 "data//maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 47 "data//maps/Route102/scripts.pory"
	release
# 48 "data//maps/Route102/scripts.pory"
	end
# 49 "data//maps/Route102/scripts.pory"

# 50 "data//maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 51 "data//maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 52 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 53 "data//maps/Route102/scripts.pory"
	release
# 54 "data//maps/Route102/scripts.pory"
	end
# 55 "data//maps/Route102/scripts.pory"

# 56 "data//maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 57 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 58 "data//maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 59 "data//maps/Route102/scripts.pory"
	release
# 60 "data//maps/Route102/scripts.pory"
	end
# 61 "data//maps/Route102/scripts.pory"

# 62 "data//maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 63 "data//maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 64 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 65 "data//maps/Route102/scripts.pory"
	end
# 66 "data//maps/Route102/scripts.pory"

# 67 "data//maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 68 "data//maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 69 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 70 "data//maps/Route102/scripts.pory"
	end
# 71 "data//maps/Route102/scripts.pory"

# 72 "data//maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 73 "data//maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 74 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 75 "data//maps/Route102/scripts.pory"
	end
# 76 "data//maps/Route102/scripts.pory"

# 77 "data//maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 78 "data//maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 79 "data//maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 80 "data//maps/Route102/scripts.pory"
	end
# 81 "data//maps/Route102/scripts.pory"

# 82 "data//maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 83 "data//maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 84 "data//maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 85 "data//maps/Route102/scripts.pory"
	.string "don't they?\p"
# 86 "data//maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 87 "data//maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 88 "data//maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 89 "data//maps/Route102/scripts.pory"

# 90 "data//maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 91 "data//maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 92 "data//maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 93 "data//maps/Route102/scripts.pory"

# 94 "data//maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 95 "data//maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 96 "data//maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 97 "data//maps/Route102/scripts.pory"

# 98 "data//maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 99 "data//maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 100 "data//maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 101 "data//maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 102 "data//maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 103 "data//maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 104 "data//maps/Route102/scripts.pory"

# 105 "data//maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 106 "data//maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 107 "data//maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 108 "data//maps/Route102/scripts.pory"

# 109 "data//maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 110 "data//maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 111 "data//maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 112 "data//maps/Route102/scripts.pory"

# 113 "data//maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 114 "data//maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 115 "data//maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"
