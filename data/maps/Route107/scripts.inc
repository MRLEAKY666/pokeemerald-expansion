# 1 "data//maps/Route107/scripts.pory"

# 2 "data//maps/Route107/scripts.pory"
Route107_MapScripts::
# 3 "data//maps/Route107/scripts.pory"
	.byte 0
# 4 "data//maps/Route107/scripts.pory"

# 5 "data//maps/Route107/scripts.pory"
Route107_OnTransition:
# 6 "data//maps/Route107/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 7 "data//maps/Route107/scripts.pory"
	end
# 8 "data//maps/Route107/scripts.pory"

# 9 "data//maps/Route107/scripts.pory"
Route107_EventScript_Darrin::
# 10 "data//maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated
# 11 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
# 12 "data//maps/Route107/scripts.pory"
	end
# 13 "data//maps/Route107/scripts.pory"

# 14 "data//maps/Route107/scripts.pory"
Route107_EventScript_Tony::
# 15 "data//maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_TONY_1, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Route107_EventScript_TonyRegisterMatchCallAfterBattle
# 16 "data//maps/Route107/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 17 "data//maps/Route107/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route107_EventScript_TonyRematch
# 18 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyPostBattle, MSGBOX_DEFAULT
# 19 "data//maps/Route107/scripts.pory"
	release
# 20 "data//maps/Route107/scripts.pory"
	end
# 21 "data//maps/Route107/scripts.pory"

# 22 "data//maps/Route107/scripts.pory"
Route107_EventScript_TonyRegisterMatchCallAfterBattle::
# 23 "data//maps/Route107/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 24 "data//maps/Route107/scripts.pory"
	waitmovement 0
# 25 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyRegister, MSGBOX_DEFAULT
# 26 "data//maps/Route107/scripts.pory"
	register_matchcall TRAINER_TONY_1
# 27 "data//maps/Route107/scripts.pory"
	release
# 28 "data//maps/Route107/scripts.pory"
	end
# 29 "data//maps/Route107/scripts.pory"

# 30 "data//maps/Route107/scripts.pory"
Route107_EventScript_TonyRematch::
# 31 "data//maps/Route107/scripts.pory"
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_TonyRematchIntro, Route107_Text_TonyRematchDefeated
# 32 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
# 33 "data//maps/Route107/scripts.pory"
	end
# 34 "data//maps/Route107/scripts.pory"

# 35 "data//maps/Route107/scripts.pory"
Route107_EventScript_Denise::
# 36 "data//maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated
# 37 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
# 38 "data//maps/Route107/scripts.pory"
	end
# 39 "data//maps/Route107/scripts.pory"

# 40 "data//maps/Route107/scripts.pory"
Route107_EventScript_Beth::
# 41 "data//maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_BETH, Route107_Text_BethIntro, Route107_Text_BethDefeated
# 42 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_BethPostBattle, MSGBOX_AUTOCLOSE
# 43 "data//maps/Route107/scripts.pory"
	end
# 44 "data//maps/Route107/scripts.pory"

# 45 "data//maps/Route107/scripts.pory"
Route107_EventScript_Lisa::
# 46 "data//maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_LisaIntro, Route107_Text_LisaDefeated, Route107_Text_LisaNotEnoughPokemon
# 47 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
# 48 "data//maps/Route107/scripts.pory"
	end
# 49 "data//maps/Route107/scripts.pory"

# 50 "data//maps/Route107/scripts.pory"
Route107_EventScript_Ray::
# 51 "data//maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_RayIntro, Route107_Text_RayDefeated, Route107_Text_RayNotEnoughPokemon
# 52 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
# 53 "data//maps/Route107/scripts.pory"
	end
# 54 "data//maps/Route107/scripts.pory"

# 55 "data//maps/Route107/scripts.pory"
Route107_EventScript_Camron::
# 56 "data//maps/Route107/scripts.pory"
	trainerbattle_single TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated
# 57 "data//maps/Route107/scripts.pory"
	msgbox Route107_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
# 58 "data//maps/Route107/scripts.pory"
	end
