# 1 "data//maps/Route132/scripts.pory"

# 2 "data//maps/Route132/scripts.pory"
Route132_MapScripts::
# 3 "data//maps/Route132/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route132_OnTransition
# 4 "data//maps/Route132/scripts.pory"
	.byte 0
# 5 "data//maps/Route132/scripts.pory"

# 6 "data//maps/Route132/scripts.pory"
Route132_OnTransition:
# 7 "data//maps/Route132/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 8 "data//maps/Route132/scripts.pory"
	end
# 9 "data//maps/Route132/scripts.pory"

# 10 "data//maps/Route132/scripts.pory"
Route132_EventScript_Gilbert::
# 11 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_GILBERT, Route132_Text_GilbertIntro, Route132_Text_GilbertDefeat
# 12 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_GilbertPostBattle, MSGBOX_AUTOCLOSE
# 13 "data//maps/Route132/scripts.pory"
	end
# 14 "data//maps/Route132/scripts.pory"

# 15 "data//maps/Route132/scripts.pory"
Route132_EventScript_Dana::
# 16 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_DANA, Route132_Text_DanaIntro, Route132_Text_DanaDefeat
# 17 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
# 18 "data//maps/Route132/scripts.pory"
	end
# 19 "data//maps/Route132/scripts.pory"

# 20 "data//maps/Route132/scripts.pory"
Route132_EventScript_Ronald::
# 21 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_RONALD, Route132_Text_RonaldIntro, Route132_Text_RonaldDefeat
# 22 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
# 23 "data//maps/Route132/scripts.pory"
	end
# 24 "data//maps/Route132/scripts.pory"

# 25 "data//maps/Route132/scripts.pory"
Route132_EventScript_Kiyo::
# 26 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_KIYO, Route132_Text_KiyoIntro, Route132_Text_KiyoDefeat
# 27 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
# 28 "data//maps/Route132/scripts.pory"
	end
# 29 "data//maps/Route132/scripts.pory"

# 30 "data//maps/Route132/scripts.pory"
Route132_EventScript_Paxton::
# 31 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_PAXTON, Route132_Text_PaxtonIntro, Route132_Text_PaxtonDefeat
# 32 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_PaxtonPostBattle, MSGBOX_AUTOCLOSE
# 33 "data//maps/Route132/scripts.pory"
	end
# 34 "data//maps/Route132/scripts.pory"

# 35 "data//maps/Route132/scripts.pory"
Route132_EventScript_Darcy::
# 36 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_DARCY, Route132_Text_DarcyIntro, Route132_Text_DarcyDefeat
# 37 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
# 38 "data//maps/Route132/scripts.pory"
	end
# 39 "data//maps/Route132/scripts.pory"

# 40 "data//maps/Route132/scripts.pory"
Route132_EventScript_Jonathan::
# 41 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_JONATHAN, Route132_Text_JonathanIntro, Route132_Text_JonathanDefeat
# 42 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_JonathanPostBattle, MSGBOX_AUTOCLOSE
# 43 "data//maps/Route132/scripts.pory"
	end
# 44 "data//maps/Route132/scripts.pory"

# 45 "data//maps/Route132/scripts.pory"
Route132_EventScript_Makayla::
# 46 "data//maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_MAKAYLA, Route132_Text_MakaylaIntro, Route132_Text_MakaylaDefeat
# 47 "data//maps/Route132/scripts.pory"
	msgbox Route132_Text_MakaylaPostBattle, MSGBOX_AUTOCLOSE
# 48 "data//maps/Route132/scripts.pory"
	end
