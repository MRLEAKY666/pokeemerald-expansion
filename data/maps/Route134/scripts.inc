# 1 "data//maps/Route134/scripts.pory"

# 2 "data//maps/Route134/scripts.pory"
Route134_MapScripts::
# 3 "data//maps/Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
# 4 "data//maps/Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route134_OnTransition
# 5 "data//maps/Route134/scripts.pory"
	.byte 0
# 6 "data//maps/Route134/scripts.pory"

# 7 "data//maps/Route134/scripts.pory"
Route134_OnResume:
# 8 "data//maps/Route134/scripts.pory"
	setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6
# 9 "data//maps/Route134/scripts.pory"
	end
# 10 "data//maps/Route134/scripts.pory"

# 11 "data//maps/Route134/scripts.pory"
Route134_OnTransition:
# 12 "data//maps/Route134/scripts.pory"
	end
# 13 "data//maps/Route134/scripts.pory"

# 14 "data//maps/Route134/scripts.pory"
Route134_EventScript_Jack::
# 15 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
# 16 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
# 17 "data//maps/Route134/scripts.pory"
	end
# 18 "data//maps/Route134/scripts.pory"

# 19 "data//maps/Route134/scripts.pory"
Route134_EventScript_Laurel::
# 20 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
# 21 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
# 22 "data//maps/Route134/scripts.pory"
	end
# 23 "data//maps/Route134/scripts.pory"

# 24 "data//maps/Route134/scripts.pory"
Route134_EventScript_Alex::
# 25 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
# 26 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
# 27 "data//maps/Route134/scripts.pory"
	end
# 28 "data//maps/Route134/scripts.pory"

# 29 "data//maps/Route134/scripts.pory"
Route134_EventScript_Aaron::
# 30 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
# 31 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
# 32 "data//maps/Route134/scripts.pory"
	end
# 33 "data//maps/Route134/scripts.pory"

# 34 "data//maps/Route134/scripts.pory"
Route134_EventScript_Hitoshi::
# 35 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
# 36 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
# 37 "data//maps/Route134/scripts.pory"
	end
# 38 "data//maps/Route134/scripts.pory"

# 39 "data//maps/Route134/scripts.pory"
Route134_EventScript_Hudson::
# 40 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
# 41 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
# 42 "data//maps/Route134/scripts.pory"
	end
# 43 "data//maps/Route134/scripts.pory"

# 44 "data//maps/Route134/scripts.pory"
Route134_EventScript_Reyna::
# 45 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
# 46 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
# 47 "data//maps/Route134/scripts.pory"
	end
# 48 "data//maps/Route134/scripts.pory"

# 49 "data//maps/Route134/scripts.pory"
Route134_EventScript_Marley::
# 50 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
# 51 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
# 52 "data//maps/Route134/scripts.pory"
	end
# 53 "data//maps/Route134/scripts.pory"

# 54 "data//maps/Route134/scripts.pory"
Route134_EventScript_Kelvin::
# 55 "data//maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
# 56 "data//maps/Route134/scripts.pory"
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
# 57 "data//maps/Route134/scripts.pory"
	end
