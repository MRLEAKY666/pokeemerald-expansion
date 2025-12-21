LavarborTunnelEntrance_MapScripts::
# 4 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 19 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_LOAD:
# 5 "data//maps/LavarborTunnelEntrance/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 18
	goto_if_ge LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 6 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setmetatile 5, 5, METATILE_Lavaridge_Ladder_Down, FALSE
# 7 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setmetatile 4, 6, METATILE_Lavaridge_Regular_Cave_Floor, FALSE
# 8 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setmetatile 6, 4, METATILE_Lavaridge_Regular_Cave_Floor, FALSE
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 12 "data//maps/LavarborTunnelEntrance/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 13 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_NURSE_ON_BREAK, 4, 4
# 14 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectxy LOCALID_LAVARIDGE_NURSE_ON_BREAK, 4, 4
# 15 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_NURSE_ON_BREAK, MOVEMENT_TYPE_FACE_UP
# 16 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_TEMP_2, 1
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script_2 VAR_TEMP_2, 1, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 21 "data//maps/LavarborTunnelEntrance/scripts.pory"
	lock
# 22 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 15
# 23 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, Common_Movement_ExclamationMark
# 24 "data//maps/LavarborTunnelEntrance/scripts.pory"
	playse SE_PIN
# 25 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitse
# 26 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 20
# 27 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, Common_Movement_WalkInPlaceFasterDown
# 28 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitmovement
# 29 "data//maps/LavarborTunnelEntrance/scripts.pory"
	msgbox LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, MSGBOX_DEFAULT
# 37 "data//maps/LavarborTunnelEntrance/scripts.pory"
	closemessage
# 38 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 15
# 39 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, LavarborTunnelEntrance_Movement_NurseLeaves1
# 40 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitmovement LOCALID_LAVARIDGE_NURSE_ON_BREAK
# 41 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, LavarborTunnelEntrance_Movement_PlayerMovesForNurse
# 42 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, LavarborTunnelEntrance_Movement_NurseLeaves2
# 43 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 16
# 44 "data//maps/LavarborTunnelEntrance/scripts.pory"
	playse SE_EXIT
# 45 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitse
# 46 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_TEMP_2, 0
# 47 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 48 "data//maps/LavarborTunnelEntrance/scripts.pory"
	release
	end


# 54 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 55 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 56 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_NurseLeaves1:
# 57 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_right
# 58 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 59 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 60 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_8
# 61 "data//maps/LavarborTunnelEntrance/scripts.pory"
    nurse_joy_bow
# 62 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_4
# 63 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end
# 64 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 65 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_NurseLeaves2:
# 66 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 67 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_8
# 68 "data//maps/LavarborTunnelEntrance/scripts.pory"
    set_invisible
# 69 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_fast_down
# 70 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end
# 71 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 72 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_PlayerMovesForNurse:
# 73 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_right
# 74 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_in_place_left
# 75 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 29 "data//maps/LavarborTunnelEntrance/scripts.pory"
	.string "Oh!\l"
	.string "You startled me!\p"
	.string "This is where I take breaks, because\n"
	.string "nobody knows where to find me.\p"
	.string "They started to dig a tunnel from here\n"
	.string "to FALLARBOR TOWN, but the project was\l"
	.string "cancelled…\p"
	.string "They burnt through all their funding\n"
	.string "without making much progress.\p"
	.string "Apparently the project leader was\n"
	.string "spending a lot of time at the sauna\l"
	.string "instead of directing the dig.\p"
	.string "He's still there almost all the time!\n"
	.string "He basically retired early and never\l"
	.string "looked back.\p"
	.string "Anyway, I should get back to work.\n"
	.string "NURSE JOY is probably waiting for me.$"
