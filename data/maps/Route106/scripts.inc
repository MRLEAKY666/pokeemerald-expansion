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
	clearflag FLAG_SYS_SAVE_GET
# 8 "data//maps/Route106/scripts.pory"
	end
# 9 "data//maps/Route106/scripts.pory"

# 10 "data//maps/Route106/scripts.pory"
Route106_EventScript_TrainerTipsSign::
# 11 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
# 12 "data//maps/Route106/scripts.pory"
	end
# 13 "data//maps/Route106/scripts.pory"

# 14 "data//maps/Route106/scripts.pory"
Route106_EventScript_Douglas::
# 15 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
# 16 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
# 17 "data//maps/Route106/scripts.pory"
	end
# 18 "data//maps/Route106/scripts.pory"

# 19 "data//maps/Route106/scripts.pory"
Route106_EventScript_Kyla::
# 20 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
# 21 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
# 22 "data//maps/Route106/scripts.pory"
	end
# 23 "data//maps/Route106/scripts.pory"

# 24 "data//maps/Route106/scripts.pory"
Route106_EventScript_Elliot::
# 25 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
# 26 "data//maps/Route106/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 27 "data//maps/Route106/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
# 28 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
# 29 "data//maps/Route106/scripts.pory"
	release
# 30 "data//maps/Route106/scripts.pory"
	end
# 31 "data//maps/Route106/scripts.pory"

# 32 "data//maps/Route106/scripts.pory"
Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
# 33 "data//maps/Route106/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 34 "data//maps/Route106/scripts.pory"
	waitmovement 0
# 35 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
# 36 "data//maps/Route106/scripts.pory"
	register_matchcall TRAINER_ELLIOT_1
# 37 "data//maps/Route106/scripts.pory"
	release
# 38 "data//maps/Route106/scripts.pory"
	end
# 39 "data//maps/Route106/scripts.pory"

# 40 "data//maps/Route106/scripts.pory"
Route106_EventScript_ElliotRematch::
# 41 "data//maps/Route106/scripts.pory"
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
# 42 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
# 43 "data//maps/Route106/scripts.pory"
	end
# 44 "data//maps/Route106/scripts.pory"

# 45 "data//maps/Route106/scripts.pory"
Route106_EventScript_Ned::
# 46 "data//maps/Route106/scripts.pory"
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
# 47 "data//maps/Route106/scripts.pory"
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
# 48 "data//maps/Route106/scripts.pory"
	end
# 49 "data//maps/Route106/scripts.pory"

# 50 "data//maps/Route106/scripts.pory"
Route106_Text_TrainerTips:
# 51 "data//maps/Route106/scripts.pory"
	.string "TRAINER TIPS\p"
# 52 "data//maps/Route106/scripts.pory"
	.string "Advice on catching POKéMON with a ROD:\n"
# 53 "data//maps/Route106/scripts.pory"
	.string "Press the A Button if you get a bite.$"
