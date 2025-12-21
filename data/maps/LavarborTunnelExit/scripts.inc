LavarborTunnelExit_MapScripts::
# 7 "data//maps/LavarborTunnelExit/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD
# 15 "data//maps/LavarborTunnelExit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD:
# 8 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 9 "data//maps/LavarborTunnelExit/scripts.pory"
	setmetatile 39, 20, METATILE_Fallarbor_Rock1_Purple_Dirt_Floor, TRUE
# 10 "data//maps/LavarborTunnelExit/scripts.pory"
	setmetatile 38, 20, METATILE_Fallarbor_Rock2_Purple_Dirt_Floor, TRUE
# 11 "data//maps/LavarborTunnelExit/scripts.pory"
	setmetatile 40, 20, METATILE_Fallarbor_Purple_Dirt_Floor, FALSE
# 12 "data//maps/LavarborTunnelExit/scripts.pory"
	setmetatile 41, 19, METATILE_Fallarbor_Rock2_Purple_Dirt_Floor, TRUE
	return

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 8 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 17 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_gt LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 21 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_13
LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_12:
# 22 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_16
LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 25 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 29 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_6
LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 33 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_ne LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
	return

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 18 "data//maps/LavarborTunnelExit/scripts.pory"
	setflag FLAG_TEMP_5
# 19 "data//maps/LavarborTunnelExit/scripts.pory"
	setflag FLAG_TEMP_7
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 23 "data//maps/LavarborTunnelExit/scripts.pory"
	setflag FLAG_TEMP_5
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 26 "data//maps/LavarborTunnelExit/scripts.pory"
	setobjectxyperm LOCAL_ID_LAVARVOR_EXIT_FOSSIL_MANIAC, 41, 17
# 27 "data//maps/LavarborTunnelExit/scripts.pory"
	setobjectmovementtype LOCAL_ID_LAVARVOR_EXIT_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_LEFT
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 30 "data//maps/LavarborTunnelExit/scripts.pory"
	setvar VAR_TEMP_5, 1
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
# 29 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_unset FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 25 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 21 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_12

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 22 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	goto LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LavarborTunnelExit_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 34 "data//maps/LavarborTunnelExit/scripts.pory"
	setflag FLAG_TEMP_7
	return


LavarborTunnelExit_EventScript_FossilManiacTrigger::
# 40 "data//maps/LavarborTunnelExit/scripts.pory"
	applymovement LOCAL_ID_LAVARVOR_EXIT_FOSSIL_MANIAC, Common_Movement_WalkInPlaceRight
# 41 "data//maps/LavarborTunnelExit/scripts.pory"
	waitmovement
# 42 "data//maps/LavarborTunnelExit/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 43 "data//maps/LavarborTunnelExit/scripts.pory"
	waitmovement
# 44 "data//maps/LavarborTunnelExit/scripts.pory"
	goto LavarborTunnelExit_EventScript_FossilManiac
	return


LavarborTunnelExit_EventScript_FossilManiac::
# 48 "data//maps/LavarborTunnelExit/scripts.pory"
	lock
# 49 "data//maps/LavarborTunnelExit/scripts.pory"
	faceplayer
# 50 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq LavarborTunnelExit_EventScript_FossilManiac_9
LavarborTunnelExit_EventScript_FossilManiac_6:
# 57 "data//maps/LavarborTunnelExit/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq LavarborTunnelExit_EventScript_FossilManiac_5
LavarborTunnelExit_EventScript_FossilManiac_1:
# 63 "data//maps/LavarborTunnelExit/scripts.pory"
	msgbox LavarborTunnelExit_EventScript_FossilManiac_Text_2, MSGBOX_DEFAULT
# 66 "data//maps/LavarborTunnelExit/scripts.pory"
	setvar VAR_TEMP_5, 0
# 67 "data//maps/LavarborTunnelExit/scripts.pory"
	release
	return

LavarborTunnelExit_EventScript_FossilManiac_2:
# 52 "data//maps/LavarborTunnelExit/scripts.pory"
	msgbox LavarborTunnelExit_EventScript_FossilManiac_Text_0, MSGBOX_DEFAULT
# 54 "data//maps/LavarborTunnelExit/scripts.pory"
	release
	end

LavarborTunnelExit_EventScript_FossilManiac_3:
# 58 "data//maps/LavarborTunnelExit/scripts.pory"
	msgbox LavarborTunnelExit_EventScript_FossilManiac_Text_1, MSGBOX_DEFAULT
# 60 "data//maps/LavarborTunnelExit/scripts.pory"
	release
	end

LavarborTunnelExit_EventScript_FossilManiac_4:
# 57 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelExit_EventScript_FossilManiac_3
	goto LavarborTunnelExit_EventScript_FossilManiac_1

LavarborTunnelExit_EventScript_FossilManiac_5:
# 57 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, LavarborTunnelExit_EventScript_FossilManiac_4
	goto LavarborTunnelExit_EventScript_FossilManiac_1

LavarborTunnelExit_EventScript_FossilManiac_9:
# 50 "data//maps/LavarborTunnelExit/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FOSSIL_MANIAC_RECRUITED, LavarborTunnelExit_EventScript_FossilManiac_2
	goto LavarborTunnelExit_EventScript_FossilManiac_6


LavarborTunnelExit_EventScript_TunnelManiac::
# 71 "data//maps/LavarborTunnelExit/scripts.pory"
	lock
# 72 "data//maps/LavarborTunnelExit/scripts.pory"
	faceplayer
# 73 "data//maps/LavarborTunnelExit/scripts.pory"
	msgbox LavarborTunnelExit_EventScript_TunnelManiac_Text_0
# 75 "data//maps/LavarborTunnelExit/scripts.pory"
	release
	return


LavarborTunnelExit_EventScript_FossilManiac_Text_0:
# 52 "data//maps/LavarborTunnelExit/scripts.pory"
	.string "FOSSIL MANIAC: I heard about the\n"
	.string "tunnel project, so I decided to help!\p"
	.string "A tunnel this deep has gotta have some\n"
	.string "rare fossils!$"

LavarborTunnelExit_EventScript_FossilManiac_Text_1:
# 58 "data//maps/LavarborTunnelExit/scripts.pory"
	.string "FOSSIL MANIAC: I'm glad you told me\n"
	.string "about the project when you did,\p"
	.string "Pops' crew had almost finished breaking\n"
	.string "through this wall when I got here!$"

LavarborTunnelExit_EventScript_FossilManiac_Text_2:
# 63 "data//maps/LavarborTunnelExit/scripts.pory"
	.string "FOSSIL MANIAC: I wouldn't go down\n"
	.string "there if I were you…\p"
	.string "When I dug that way, I heard something\n"
	.string "terrible on the other side of that wall.\p"
	.string "I hope the Tunnel Crew is doing okay…$"

LavarborTunnelExit_EventScript_TunnelManiac_Text_0:
# 73 "data//maps/LavarborTunnelExit/scripts.pory"
	.string "TUNNEL MANIAC: Would you look at that!\p"
	.string "My eldest son!\p"
	.string "He heard about the tunnel we were\n"
	.string "digging and decided to help out!$"
