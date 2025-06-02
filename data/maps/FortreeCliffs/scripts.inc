# 1 "data//maps/FortreeCliffs/scripts.pory"

# 2 "data//maps/FortreeCliffs/scripts.pory"

# 3 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_MapScripts::
# 4 "data//maps/FortreeCliffs/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCliffs_OnTransition
# 5 "data//maps/FortreeCliffs/scripts.pory"
	.byte 0
# 6 "data//maps/FortreeCliffs/scripts.pory"

# 7 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_OnTransition:
# 8 "data//maps/FortreeCliffs/scripts.pory"
	call FortreeCliffs_EventScript_ResetWildMons
# 9 "data//maps/FortreeCliffs/scripts.pory"
	end
# 10 "data//maps/FortreeCliffs/scripts.pory"

# 11 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_Snorlax::
# 12 "data//maps/FortreeCliffs/scripts.pory"
	lock
# 13 "data//maps/FortreeCliffs/scripts.pory"
	faceplayer
# 14 "data//maps/FortreeCliffs/scripts.pory"
	waitse
# 15 "data//maps/FortreeCliffs/scripts.pory"
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
# 16 "data//maps/FortreeCliffs/scripts.pory"
	msgbox FortreeCliffs_Text_Snorlax, MSGBOX_DEFAULT
# 17 "data//maps/FortreeCliffs/scripts.pory"
	delay 10
# 18 "data//maps/FortreeCliffs/scripts.pory"
	waitmoncry
# 19 "data//maps/FortreeCliffs/scripts.pory"
	setwildbattle SPECIES_SNORLAX, 60
# 20 "data//maps/FortreeCliffs/scripts.pory"
	dowildbattle
# 21 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 22 "data//maps/FortreeCliffs/scripts.pory"
	removeobject VAR_LAST_TALKED
# 23 "data//maps/FortreeCliffs/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 24 "data//maps/FortreeCliffs/scripts.pory"
	release
# 25 "data//maps/FortreeCliffs/scripts.pory"
	end
# 26 "data//maps/FortreeCliffs/scripts.pory"

# 27 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_EventScript_ResetWildMons::
# 28 "data//maps/FortreeCliffs/scripts.pory"
	clearflag FLAG_FORTREE_CLIFFS_SNORLAX
# 29 "data//maps/FortreeCliffs/scripts.pory"
	end
# 30 "data//maps/FortreeCliffs/scripts.pory"

# 31 "data//maps/FortreeCliffs/scripts.pory"
FortreeCliffs_Text_Snorlax:
# 32 "data//maps/FortreeCliffs/scripts.pory"
	.string "Snooooooooo!$"
