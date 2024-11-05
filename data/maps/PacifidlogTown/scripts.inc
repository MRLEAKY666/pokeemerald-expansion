# 1 "data//maps/PacifidlogTown/scripts.pory"

# 2 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_MapScripts::
# 3 "data//maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
# 4 "data//maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
# 5 "data//maps/PacifidlogTown/scripts.pory"
	.byte 0
# 6 "data//maps/PacifidlogTown/scripts.pory"

# 7 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnTransition:
# 8 "data//maps/PacifidlogTown/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 9 "data//maps/PacifidlogTown/scripts.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 10 "data//maps/PacifidlogTown/scripts.pory"
	end
# 11 "data//maps/PacifidlogTown/scripts.pory"

# 12 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnResume:
# 13 "data//maps/PacifidlogTown/scripts.pory"
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
# 14 "data//maps/PacifidlogTown/scripts.pory"
	end
# 15 "data//maps/PacifidlogTown/scripts.pory"

# 16 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 17 "data//maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 18 "data//maps/PacifidlogTown/scripts.pory"
	end
# 19 "data//maps/PacifidlogTown/scripts.pory"

# 20 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 21 "data//maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 22 "data//maps/PacifidlogTown/scripts.pory"
	end
# 23 "data//maps/PacifidlogTown/scripts.pory"

# 24 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 25 "data//maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 26 "data//maps/PacifidlogTown/scripts.pory"
	end
# 27 "data//maps/PacifidlogTown/scripts.pory"

# 28 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 29 "data//maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 30 "data//maps/PacifidlogTown/scripts.pory"
	end
# 31 "data//maps/PacifidlogTown/scripts.pory"

# 32 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 33 "data//maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 34 "data//maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 35 "data//maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 36 "data//maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 37 "data//maps/PacifidlogTown/scripts.pory"

# 38 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 39 "data//maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 40 "data//maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 41 "data//maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 42 "data//maps/PacifidlogTown/scripts.pory"

# 43 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 44 "data//maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 45 "data//maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 46 "data//maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 47 "data//maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 48 "data//maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 49 "data//maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 50 "data//maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 51 "data//maps/PacifidlogTown/scripts.pory"

# 52 "data//maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 53 "data//maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 54 "data//maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 55 "data//maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
