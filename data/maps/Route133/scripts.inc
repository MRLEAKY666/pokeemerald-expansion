# 1 "data//maps/Route133/scripts.pory"

# 2 "data//maps/Route133/scripts.pory"
Route133_MapScripts::
# 3 "data//maps/Route133/scripts.pory"
	.byte 0
# 4 "data//maps/Route133/scripts.pory"

# 5 "data//maps/Route133/scripts.pory"
Route133_OnTransition:
# 6 "data//maps/Route133/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 7 "data//maps/Route133/scripts.pory"
	end
# 8 "data//maps/Route133/scripts.pory"

# 9 "data//maps/Route133/scripts.pory"
Route133_EventScript_Franklin::
# 10 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
# 11 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
# 12 "data//maps/Route133/scripts.pory"
	end
# 13 "data//maps/Route133/scripts.pory"

# 14 "data//maps/Route133/scripts.pory"
Route133_EventScript_Debra::
# 15 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
# 16 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
# 17 "data//maps/Route133/scripts.pory"
	end
# 18 "data//maps/Route133/scripts.pory"

# 19 "data//maps/Route133/scripts.pory"
Route133_EventScript_Linda::
# 20 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
# 21 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
# 22 "data//maps/Route133/scripts.pory"
	end
# 23 "data//maps/Route133/scripts.pory"

# 24 "data//maps/Route133/scripts.pory"
Route133_EventScript_Warren::
# 25 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
# 26 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
# 27 "data//maps/Route133/scripts.pory"
	end
# 28 "data//maps/Route133/scripts.pory"

# 29 "data//maps/Route133/scripts.pory"
Route133_EventScript_Beck::
# 30 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
# 31 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
# 32 "data//maps/Route133/scripts.pory"
	end
# 33 "data//maps/Route133/scripts.pory"

# 34 "data//maps/Route133/scripts.pory"
Route133_EventScript_Mollie::
# 35 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
# 36 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
# 37 "data//maps/Route133/scripts.pory"
	end
# 38 "data//maps/Route133/scripts.pory"

# 39 "data//maps/Route133/scripts.pory"
Route133_EventScript_Conor::
# 40 "data//maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
# 41 "data//maps/Route133/scripts.pory"
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
# 42 "data//maps/Route133/scripts.pory"
	end
