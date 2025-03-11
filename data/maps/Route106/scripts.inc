# 1 "data//maps/Route106/scripts.pory"

# 2 "data//maps/Route106/scripts.pory"
Route106_MapScripts::
# 3 "data//maps/Route106/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
# 4 "data//maps/Route106/scripts.pory"
	.byte 0
# 5 "data//maps/Route106/scripts.pory"

# 6 "data//maps/Route106/scripts.pory"
Route106_OnTransition:
# 7 "data//maps/Route106/scripts.pory"
	end
# 8 "data//maps/Route106/scripts.pory"

# 9 "data//maps/Route106/scripts.pory"
Route106_EventScript_TrainerTipsSign::
# 10 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
# 11 "data//maps/Route106/scripts.pory"
	end
# 12 "data//maps/Route106/scripts.pory"

# 13 "data//maps/Route106/scripts.pory"
Route106_EventScript_Douglas::
# 14 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
# 15 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
# 16 "data//maps/Route106/scripts.pory"
	end
# 17 "data//maps/Route106/scripts.pory"

# 18 "data//maps/Route106/scripts.pory"
Route106_EventScript_Kyla::
# 19 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
# 20 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
# 21 "data//maps/Route106/scripts.pory"
	end
# 22 "data//maps/Route106/scripts.pory"

# 23 "data//maps/Route106/scripts.pory"
Route106_EventScript_Elliot::
# 24 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
# 25 "data//maps/Route106/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 26 "data//maps/Route106/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
# 27 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
# 28 "data//maps/Route106/scripts.pory"
	release
# 29 "data//maps/Route106/scripts.pory"
	end
# 30 "data//maps/Route106/scripts.pory"

# 31 "data//maps/Route106/scripts.pory"
Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
# 32 "data//maps/Route106/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 33 "data//maps/Route106/scripts.pory"
	waitmovement 0
# 34 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
# 35 "data//maps/Route106/scripts.pory"
	register_matchcall TRAINER_ELLIOT_1
# 36 "data//maps/Route106/scripts.pory"
	release
# 37 "data//maps/Route106/scripts.pory"
	end
# 38 "data//maps/Route106/scripts.pory"

# 39 "data//maps/Route106/scripts.pory"
Route106_EventScript_ElliotRematch::
# 40 "data//maps/Route106/scripts.pory"
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
# 41 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
# 42 "data//maps/Route106/scripts.pory"
	end
# 43 "data//maps/Route106/scripts.pory"

# 44 "data//maps/Route106/scripts.pory"
Route106_EventScript_Ned::
# 45 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
# 46 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
# 47 "data//maps/Route106/scripts.pory"
	end
# 48 "data//maps/Route106/scripts.pory"

# 49 "data//maps/Route106/scripts.pory"
Route106_Text_TrainerTips:
# 50 "data//maps/Route106/scripts.pory"
	.string "TRAINER TIPS\p"
# 51 "data//maps/Route106/scripts.pory"
	.string "Advice on catching POKéMON with a ROD:\n"
# 52 "data//maps/Route106/scripts.pory"
	.string "Press the A Button if you get a bite.$"
