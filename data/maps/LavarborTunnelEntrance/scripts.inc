LavarborTunnelEntrance_MapScripts::
# 4 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 12 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data//maps/LavarborTunnelEntrance/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 0
	goto_if_eq LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_NURSE_ON_BREAK, 4, 4
# 7 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectxy LOCALID_LAVARIDGE_NURSE_ON_BREAK, 4, 4
# 8 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_NURSE_ON_BREAK, MOVEMENT_TYPE_FACE_UP
# 9 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_TEMP_2, 1
	return

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data//maps/LavarborTunnelEntrance/scripts.pory"
	map_script_2 VAR_TEMP_2, 1, LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 14 "data//maps/LavarborTunnelEntrance/scripts.pory"
	lock
# 15 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 15
# 16 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, Common_Movement_ExclamationMark
# 17 "data//maps/LavarborTunnelEntrance/scripts.pory"
	playse SE_PIN
# 18 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitse
# 19 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 20
# 20 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, Common_Movement_WalkInPlaceFasterDown
# 21 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitmovement
# 22 "data//maps/LavarborTunnelEntrance/scripts.pory"
	msgbox LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, MSGBOX_DEFAULT
# 30 "data//maps/LavarborTunnelEntrance/scripts.pory"
	closemessage
# 31 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 15
# 32 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, LavarborTunnelEntrance_Movement_NurseLeaves1
# 33 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitmovement LOCALID_LAVARIDGE_NURSE_ON_BREAK
# 34 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_PLAYER, LavarborTunnelEntrance_Movement_PlayerMovesForNurse
# 35 "data//maps/LavarborTunnelEntrance/scripts.pory"
	applymovement LOCALID_LAVARIDGE_NURSE_ON_BREAK, LavarborTunnelEntrance_Movement_NurseLeaves2
# 36 "data//maps/LavarborTunnelEntrance/scripts.pory"
	delay 16
# 37 "data//maps/LavarborTunnelEntrance/scripts.pory"
	playse SE_EXIT
# 38 "data//maps/LavarborTunnelEntrance/scripts.pory"
	waitse
# 39 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_TEMP_2, 0
# 40 "data//maps/LavarborTunnelEntrance/scripts.pory"
	setvar VAR_LAVARBOR_TUNNEL_QUEST_STATE, 1
# 41 "data//maps/LavarborTunnelEntrance/scripts.pory"
	release
	end


# 47 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 48 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 49 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_NurseLeaves1:
# 50 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_right
# 51 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 52 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 53 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_8
# 54 "data//maps/LavarborTunnelEntrance/scripts.pory"
    nurse_joy_bow
# 55 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_4
# 56 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end
# 57 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 58 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_NurseLeaves2:
# 59 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_down
# 60 "data//maps/LavarborTunnelEntrance/scripts.pory"
    delay_8
# 61 "data//maps/LavarborTunnelEntrance/scripts.pory"
    set_invisible
# 62 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_fast_down
# 63 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end
# 64 "data//maps/LavarborTunnelEntrance/scripts.pory"

# 65 "data//maps/LavarborTunnelEntrance/scripts.pory"
LavarborTunnelEntrance_Movement_PlayerMovesForNurse:
# 66 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_right
# 67 "data//maps/LavarborTunnelEntrance/scripts.pory"
    walk_in_place_left
# 68 "data//maps/LavarborTunnelEntrance/scripts.pory"
    step_end

LavarborTunnelEntrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
# 22 "data//maps/LavarborTunnelEntrance/scripts.pory"
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
