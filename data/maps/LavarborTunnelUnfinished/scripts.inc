LavarborTunnelUnfinished_MapScripts::
# 6 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME
# 14 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD
# 36 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME:
# 7 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME_1
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME_1:
# 8 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 9 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME_3
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_RESUME_3:
# 10 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	removeobject VAR_LAST_TALKED
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD:
# 15 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_4
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_3:
# 16 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 20
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_8
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 21 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_15
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_14:
# 22 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 21
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_19
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_12:
# 28 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_25
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_24:
# 29 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 22
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_29
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 17 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 24, 19, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 18 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 25, 19, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 19 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 25, 20, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_1

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 15 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 20
	goto_if_ge LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_2
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_3

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 16 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_2
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_1

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_8:
# 16 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_7
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_1

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_13:
# 23 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 23, 10, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 24 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 24, 10, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 25 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 23, 11, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 26 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 24, 11, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_12

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_15:
# 21 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 21
	goto_if_ge LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_13
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_14

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_18:
# 22 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_13
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_12

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_19:
# 22 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_18
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_12

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_23:
# 30 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 12, 21, METATILE_Cave_Regular_Dark_Top_Cliff_Edge, TRUE
# 31 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 13, 21, METATILE_Cave_Regular_Dark_Top_Cliff_Edge, TRUE
# 32 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 14, 21, METATILE_Cave_Regular_Dark_Top_Cliff_Edge, TRUE
# 33 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmetatile 13, 20, METATILE_Cave_Regular_Dark_Floor, FALSE
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_25:
# 28 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 22
	goto_if_ge LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_23
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_24

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_28:
# 29 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_23
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_29:
# 29 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_LOAD_28
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 37 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_TUNNEL_ORTHWORM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 40 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 18
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 50 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 19
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 64 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 20
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 92 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 21
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 124 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 22
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_29
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_28:
# 162 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 23
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_35
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_34:
# 167 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_eq LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_53
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_52:
# 170 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 23
	goto_if_ge LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_62
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 38 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_A, 1
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 41 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmaplayoutindex LAYOUT_LAVARBOR_TUNNEL_PHASE1
# 42 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 53, 32
# 43 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_1, 52, 30
# 44 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_1, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT
# 45 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 54, 27
# 46 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_AROUND
# 47 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 58, 30
# 48 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 51 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmaplayoutindex LAYOUT_LAVARBOR_TUNNEL_PHASE2
# 52 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 45, 23
# 53 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_1, 43, 22
# 54 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_1, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT
# 55 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 45, 21
# 56 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_JOG_IN_PLACE_UP
# 57 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 46, 34
# 58 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_AROUND
# 59 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_2, 47, 26
# 60 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_2, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 61 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_2, 54, 29
# 62 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_2, MOVEMENT_TYPE_WANDER_AROUND
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 65 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmaplayoutindex LAYOUT_LAVARBOR_TUNNEL_PHASE3
# 66 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 29, 21
# 67 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_TUNNEL_MANIAC, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT
# 68 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 28, 29
# 69 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 70 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 31, 25
# 71 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_JOG_IN_PLACE_UP
# 72 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_1, 47, 25
# 73 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_1, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 74 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_2, 54, 29
# 75 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_2, MOVEMENT_TYPE_WANDER_AROUND
# 76 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_2, 46, 34
# 77 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_2, MOVEMENT_TYPE_WANDER_AROUND
# 78 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_3, 41, 20
# 79 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 80 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_25
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 85 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_19
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_18:
# 86 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_22
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 93 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmaplayoutindex LAYOUT_LAVARBOR_TUNNEL_PHASE4
# 94 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 26, 12
# 95 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_TUNNEL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
# 96 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_3, 28, 29
# 97 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 98 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 32, 13
# 99 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_WANDER_AROUND
# 100 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 32, 19
# 101 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 102 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_2, 54, 29
# 103 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_2, MOVEMENT_TYPE_WANDER_AROUND
# 104 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_2, 46, 34
# 105 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_2, MOVEMENT_TYPE_WANDER_AROUND
# 106 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_3, 41, 20
# 107 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 108 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_32
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_31:
# 112 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_49
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_44:
# 117 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_43
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_42:
# 118 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_46
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 81 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_5, 25, 21
# 82 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DIGGERSBY_5, 25, 21
# 83 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 87 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_5, 32, 19
# 88 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DIGGERSBY_5, 32, 19
# 89 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_19:
# 85 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_18

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 86 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_25:
# 80 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_16
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_20

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 125 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setmaplayoutindex LAYOUT_LAVARBOR_TUNNEL_PHASE5
# 126 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 15, 18
# 127 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_TUNNEL_MANIAC, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
# 128 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_1, 11, 10
# 129 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_1, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 130 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 32, 19
# 131 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 132 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_2, 54, 29
# 133 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_2, MOVEMENT_TYPE_WANDER_AROUND
# 134 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_2, 46, 34
# 135 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_2, MOVEMENT_TYPE_WANDER_AROUND
# 136 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_3, 41, 20
# 137 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 138 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_3, 28, 29
# 139 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 140 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_4, 5, 12
# 141 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_4, MOVEMENT_TYPE_WANDER_AROUND
# 142 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_38
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_37:
# 146 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_60
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_59:
# 150 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_73
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_68:
# 155 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_67
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_66:
# 156 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_70
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_28

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 109 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_2, 25, 23
# 110 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_2, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_31

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_35:
# 163 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_56
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_34

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_38:
# 143 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_2, 25, 23
# 144 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_2, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_37

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_40:
# 113 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_5, 24, 12
# 114 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DUGTRIO_5, 24, 12
# 115 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_41:
# 119 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_5, 23, 12
# 120 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DUGTRIO_5, 23, 12
# 121 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_5, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_43:
# 117 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_41
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_42

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_46:
# 118 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_41
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_49:
# 112 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_40
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_44

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_53:
# 168 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 33, 0
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_52

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_55:
# 164 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_TUNNEL_MANIAC, 33, 0
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_34

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_56:
# 163 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_55
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_34

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_60:
# 147 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 24, 12
# 148 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_59

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_62:
# 171 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_1, 11, 10
# 172 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_1, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 173 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_1, 32, 19
# 174 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_1, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 175 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_2, 54, 29
# 176 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_2, MOVEMENT_TYPE_WANDER_AROUND
# 177 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_2, 46, 34
# 178 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_2, MOVEMENT_TYPE_WANDER_AROUND
# 179 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_3, 41, 20
# 180 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 181 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_3, 28, 29
# 182 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
# 183 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_4, 5, 12
# 184 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_4, MOVEMENT_TYPE_WANDER_AROUND
# 185 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_77
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_76:
# 189 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_80
LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_79:
# 193 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_82
	return

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_64:
# 151 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_5, 13, 20
# 152 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_EXCADRILL_5, 13, 20
# 153 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_5, MOVEMENT_TYPE_JOG_IN_PLACE_DOWN
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_28

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_65:
# 157 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_5, 13, 17
# 158 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_EXCADRILL_5, 13, 17
# 159 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_28

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_67:
# 155 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_65
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_66

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_70:
# 156 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_65
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_28

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_73:
# 150 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_64
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_68

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_77:
# 186 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_2, 25, 23
# 187 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_2, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_76

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_80:
# 190 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_1, 24, 12
# 191 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_1, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	goto LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_79

LavarborTunnelUnfinished_MapScripts_MAP_SCRIPT_ON_TRANSITION_82:
# 194 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_4, 14, 20
# 195 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_4, MOVEMENT_TYPE_WANDER_AROUND
	return


LavarborTunnelUnfinished_EventScript_Fossil::
# 202 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	lock
# 203 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_TEMP_3, LavarborTunnelUnfinished_EventScript_Fossil_2
LavarborTunnelUnfinished_EventScript_Fossil_1:
# 217 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	bufferitemname STR_VAR_1, VAR_TEMP_3
# 218 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_Fossil_Text_0, MSGBOX_YESNO
# 220 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq LavarborTunnelUnfinished_EventScript_Fossil_5
# 225 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	giveitem VAR_TEMP_3
# 226 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 227 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 228 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	removeobject LOCALID_LAVARBOR_FOSSIL
# 229 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 230 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return

LavarborTunnelUnfinished_EventScript_Fossil_2:
# 204 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	random 4
# 205 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	switch VAR_RESULT
# 206 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 0, LavarborTunnelUnfinished_EventScript_Fossil_9
# 208 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 1, LavarborTunnelUnfinished_EventScript_Fossil_10
# 210 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 2, LavarborTunnelUnfinished_EventScript_Fossil_11
# 212 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 3, LavarborTunnelUnfinished_EventScript_Fossil_12
LavarborTunnelUnfinished_EventScript_Fossil_7:
# 215 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_TEMP_3
	goto LavarborTunnelUnfinished_EventScript_Fossil_1

LavarborTunnelUnfinished_EventScript_Fossil_5:
# 221 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_Fossil_Text_1, MSGBOX_DEFAULT
# 222 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	end

LavarborTunnelUnfinished_EventScript_Fossil_9:
# 207 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_3, ITEM_ARMOR_FOSSIL
	goto LavarborTunnelUnfinished_EventScript_Fossil_7

LavarborTunnelUnfinished_EventScript_Fossil_10:
# 209 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_3, ITEM_SKULL_FOSSIL
	goto LavarborTunnelUnfinished_EventScript_Fossil_7

LavarborTunnelUnfinished_EventScript_Fossil_11:
# 211 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_3, ITEM_JAW_FOSSIL
	goto LavarborTunnelUnfinished_EventScript_Fossil_7

LavarborTunnelUnfinished_EventScript_Fossil_12:
# 213 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_3, ITEM_SAIL_FOSSIL
	goto LavarborTunnelUnfinished_EventScript_Fossil_7


LavarborTunnelUnfinished_EventScript_TunnelManiac::
# 235 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	faceplayer
# 236 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	switch VAR_LAVARBOR_TUNNEL_QUEST_STATE
# 237 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 18, LavarborTunnelUnfinished_EventScript_TunnelManiac_3
# 241 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 19, LavarborTunnelUnfinished_EventScript_TunnelManiac_4
# 245 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 20, LavarborTunnelUnfinished_EventScript_TunnelManiac_5
# 327 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 21, LavarborTunnelUnfinished_EventScript_TunnelManiac_6
# 417 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 22, LavarborTunnelUnfinished_EventScript_TunnelManiac_7
# 509 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 23, LavarborTunnelUnfinished_EventScript_TunnelManiac_8
# 517 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	case 25, LavarborTunnelUnfinished_EventScript_TunnelManiac_9
LavarborTunnelUnfinished_EventScript_TunnelManiac_1:
# 520 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return

LavarborTunnelUnfinished_EventScript_TunnelManiac_3:
# 238 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_0, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_4:
# 242 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_1, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_5:
# 246 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_16
LavarborTunnelUnfinished_EventScript_TunnelManiac_14:
# 302 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_13
LavarborTunnelUnfinished_EventScript_TunnelManiac_12:
# 316 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_11
# 317 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 318 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 319 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 320 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 321 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 322 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 323 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 324 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 325 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_12
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_6:
# 328 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_26
LavarborTunnelUnfinished_EventScript_TunnelManiac_24:
# 386 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_23
LavarborTunnelUnfinished_EventScript_TunnelManiac_22:
# 400 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_19
# 401 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 402 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 403 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 404 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 405 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 406 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceLeft
# 407 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 408 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 409 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 410 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 411 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 412 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_12
LavarborTunnelUnfinished_EventScript_TunnelManiac_19:
# 414 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 15
# 415 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FaceOriginalDirection
# 416 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_7:
# 418 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_35
LavarborTunnelUnfinished_EventScript_TunnelManiac_33:
# 481 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_DIGGING_SIDEROOM, LavarborTunnelUnfinished_EventScript_TunnelManiac_32
LavarborTunnelUnfinished_EventScript_TunnelManiac_31:
# 495 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_24
# 496 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 497 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 498 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 499 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 500 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 501 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceDown
# 502 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 503 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 504 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 505 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 506 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 507 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_12
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_8:
# 510 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_25, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_9:
# 518 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 1
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_10:
# 247 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_2, MSGBOX_DEFAULT
# 249 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 250 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 251 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 252 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 253 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 254 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 255 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 256 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 257 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_3
# 258 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 259 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	dynmultichoice 22, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_4, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_5
# 260 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 261 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_6, MSGBOX_DEFAULT
# 263 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 264 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 265 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	hidefollower
# 266 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterDown
# 267 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 268 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 269 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_7, MSGBOX_DEFAULT
# 270 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 271 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 272 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_eq LavarborTunnelUnfinished_EventScript_TunnelManiac_39
# 276 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterRight
LavarborTunnelUnfinished_EventScript_TunnelManiac_38:
# 278 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 279 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_8, MSGBOX_DEFAULT
# 280 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 281 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 282 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_DIGGERSBY_5, Common_Movement_SetInvisible
# 283 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 284 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_eq LavarborTunnelUnfinished_EventScript_TunnelManiac_51
# 290 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_5, 32, 19
# 291 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DIGGERSBY_5, 32, 19
LavarborTunnelUnfinished_EventScript_TunnelManiac_50:
# 293 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DIGGERSBY_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
# 294 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_DIGGERSBY_5
# 295 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_DIGGERSBY_5, LavarborTunnelCavern_Movement_MonUnearthedUp
# 296 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playse SE_BIKE_HOP
# 297 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 298 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_DIGGERSBY, CRY_MODE_ENCOUNTER
# 299 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmoncry
# 300 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_LAVARBOR_DIGGING_SIDEROOM
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_11:
# 303 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_9, MSGBOX_DEFAULT
# 304 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 305 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 306 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceLeft
# 307 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 308 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 309 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 310 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 311 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 312 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_10, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_13:
# 302 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_EventScript_TunnelManiac_11
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_12

LavarborTunnelUnfinished_EventScript_TunnelManiac_16:
# 246 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_1, LavarborTunnelUnfinished_EventScript_TunnelManiac_10
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_14

LavarborTunnelUnfinished_EventScript_TunnelManiac_20:
# 329 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_13, MSGBOX_DEFAULT
# 331 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 332 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 333 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 334 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 335 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 336 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceLeft
# 337 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 338 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 339 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 340 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 341 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 342 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_3
# 343 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 344 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	dynmultichoice 22, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_14, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_15
# 345 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 346 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_6, MSGBOX_DEFAULT
# 348 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 349 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 350 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	hidefollower
# 351 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterRight
# 352 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 353 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 354 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_DUGTRIO
# 355 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_16, MSGBOX_DEFAULT
# 356 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 357 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 358 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterLeft
# 359 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 360 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_8, MSGBOX_DEFAULT
# 361 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 362 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 363 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_DUGTRIO_5, Common_Movement_SetInvisible
# 364 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 365 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_TEMP_B, 0
	goto_if_eq LavarborTunnelUnfinished_EventScript_TunnelManiac_43
# 374 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_5, 23, 12
# 375 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DUGTRIO_5, 23, 12
# 376 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_5, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT
# 377 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_DUGTRIO_5
# 378 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_DUGTRIO_5, LavarborTunnelCavern_Movement_MonUnearthedLeft
LavarborTunnelUnfinished_EventScript_TunnelManiac_42:
# 380 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playse SE_BIKE_HOP
# 381 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 382 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_DUGTRIO, CRY_MODE_ENCOUNTER
# 383 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmoncry
# 384 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_LAVARBOR_DIGGING_SIDEROOM
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_19

LavarborTunnelUnfinished_EventScript_TunnelManiac_21:
# 387 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_17, MSGBOX_DEFAULT
# 388 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 389 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 390 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceLeft
# 391 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 392 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 393 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 394 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 395 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 396 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_18, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_19

LavarborTunnelUnfinished_EventScript_TunnelManiac_23:
# 386 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_EventScript_TunnelManiac_21
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_22

LavarborTunnelUnfinished_EventScript_TunnelManiac_26:
# 328 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_2, LavarborTunnelUnfinished_EventScript_TunnelManiac_20
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_24

LavarborTunnelUnfinished_EventScript_TunnelManiac_29:
# 419 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_20, MSGBOX_DEFAULT
# 421 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 422 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 423 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceUp
# 424 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 425 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 426 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceDown
# 427 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 428 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 429 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 430 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 431 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 432 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_3
# 433 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 434 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	dynmultichoice 22, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_14, LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_21
# 435 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	copyvar VAR_TEMP_B, VAR_RESULT
# 436 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_6, MSGBOX_DEFAULT
# 438 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 439 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 440 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	hidefollower
# 441 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterLeft
# 442 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 443 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 444 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_22, MSGBOX_DEFAULT
# 445 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 446 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 447 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_TEMP_B, 1
	goto_if_eq LavarborTunnelUnfinished_EventScript_TunnelManiac_47
# 451 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterUp
LavarborTunnelUnfinished_EventScript_TunnelManiac_46:
# 453 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterDown
# 454 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 455 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_8, MSGBOX_DEFAULT
# 456 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 457 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 458 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_EXCADRILL_5, Common_Movement_SetInvisible
# 459 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 460 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_TEMP_B, 1
	goto_if_eq LavarborTunnelUnfinished_EventScript_TunnelManiac_55
# 469 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_5, 13, 17
# 470 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_EXCADRILL_5, 13, 17
# 471 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
# 472 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_EXCADRILL_5
# 473 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_EXCADRILL_5, LavarborTunnelCavern_Movement_MonUnearthedUp
LavarborTunnelUnfinished_EventScript_TunnelManiac_54:
# 475 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playse SE_BIKE_HOP
# 476 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 477 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_EXCADRILL, CRY_MODE_ENCOUNTER
# 478 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmoncry
# 479 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_LAVARBOR_DIGGING_SIDEROOM
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_30:
# 482 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_17, MSGBOX_DEFAULT
# 483 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 484 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 485 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceDown
# 486 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 487 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 488 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_FacePlayer
# 489 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 490 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 491 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	msgbox LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_23, MSGBOX_DEFAULT
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_1

LavarborTunnelUnfinished_EventScript_TunnelManiac_32:
# 481 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_set FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_EventScript_TunnelManiac_30
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_31

LavarborTunnelUnfinished_EventScript_TunnelManiac_35:
# 418 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto_if_unset FLAG_OPENED_SIDEROOM_3, LavarborTunnelUnfinished_EventScript_TunnelManiac_29
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_33

LavarborTunnelUnfinished_EventScript_TunnelManiac_39:
# 273 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterLeft
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_38

LavarborTunnelUnfinished_EventScript_TunnelManiac_43:
# 366 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DUGTRIO_5, 24, 12
# 367 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DUGTRIO_5, 24, 12
# 368 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_OPENED_SIDEROOM_2
# 369 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_DUGTRIO_5, MOVEMENT_TYPE_JOG_IN_PLACE_UP
# 370 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_DUGTRIO_5
# 371 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_DUGTRIO_5, LavarborTunnelCavern_Movement_MonUnearthedUp
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_42

LavarborTunnelUnfinished_EventScript_TunnelManiac_47:
# 448 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_MANIAC, Common_Movement_WalkInPlaceFasterDown
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_46

LavarborTunnelUnfinished_EventScript_TunnelManiac_51:
# 285 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_DIGGERSBY_5, 25, 21
# 286 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_DIGGERSBY_5, 25, 21
# 287 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_OPENED_SIDEROOM_1
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_50

LavarborTunnelUnfinished_EventScript_TunnelManiac_55:
# 461 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxyperm LOCALID_LAVARBOR_EXCADRILL_5, 13, 20
# 462 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_EXCADRILL_5, 13, 20
# 463 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_OPENED_SIDEROOM_3
# 464 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setobjectmovementtype LOCALID_LAVARBOR_EXCADRILL_5, MOVEMENT_TYPE_JOG_IN_PLACE_DOWN
# 465 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_EXCADRILL_5
# 466 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_EXCADRILL_5, LavarborTunnelCavern_Movement_MonUnearthedDown
	goto LavarborTunnelUnfinished_EventScript_TunnelManiac_54


LavarborTunnelUnfinished_EventScript_OrthwormAttacks::
# 524 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	lock
# 525 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	fadeoutbgm 0
# 526 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_TEMP_A, 0
# 527 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	addobject LOCALID_LAVARBOR_TUNNEL_ORTHWORM
# 528 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	clearflag FLAG_LAVARBOR_TUNNEL_ORTHWORM
# 529 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement LOCALID_LAVARBOR_TUNNEL_ORTHWORM, LavarborTunnelCavern_Movement_GarchompUnearthed
# 530 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playse SE_BIKE_HOP
# 531 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 532 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 534 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_ORTHWORM, CRY_MODE_ENCOUNTER
# 535 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_OrthwormAttacks_Text_0
# 536 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 537 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 90
# 538 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 539 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 20
# 540 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setwildbattle SPECIES_ORTHWORM, 35
# 541 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_LAVARBOR_TUNNEL_ORTHWORM
# 542 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 543 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	dowildbattle
# 544 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 545 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	setvar VAR_0x8004, SPECIES_ORTHWORM
# 546 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 547 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq LavarborTunnelUnfinished_EventScript_OrthwormAttacks_2
# 551 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq LavarborTunnelUnfinished_EventScript_OrthwormAttacks_3
# 551 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq LavarborTunnelUnfinished_EventScript_OrthwormAttacks_3
LavarborTunnelUnfinished_EventScript_OrthwormAttacks_1:
# 555 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return

LavarborTunnelUnfinished_EventScript_OrthwormAttacks_2:
# 548 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 549 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	goto LavarborTunnelUnfinished_EventScript_OrthwormAttacks_1

LavarborTunnelUnfinished_EventScript_OrthwormAttacks_3:
# 552 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	goto Common_EventScript_WildMonFled
# 553 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	goto LavarborTunnelUnfinished_EventScript_OrthwormAttacks_1


# 558 "data//maps/LavarborTunnelUnfinished/scripts.pory"
LavarborTunnelCavern_Movement_MonUnearthedUp:
# 559 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	set_visible
# 560 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	jump_in_place_up
# 561 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay_16
# 562 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	step_end

# 565 "data//maps/LavarborTunnelUnfinished/scripts.pory"
LavarborTunnelCavern_Movement_MonUnearthedLeft:
# 566 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	set_visible
# 567 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	jump_in_place_left
# 568 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay_16
# 569 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	step_end

# 572 "data//maps/LavarborTunnelUnfinished/scripts.pory"
LavarborTunnelCavern_Movement_MonUnearthedDown:
# 573 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	set_visible
# 574 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	jump_in_place_down
# 575 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay_16
# 576 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	step_end

LavarborTunnelUnfinished_EventScript_Diggersby::
# 581 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 582 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 583 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_DIGGERSBY, CRY_MODE_ENCOUNTER
# 584 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_Diggersby_Text_0
# 586 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 587 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 588 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 589 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 590 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 591 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 592 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Excadrill::
# 597 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 598 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 599 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_EXCADRILL, CRY_MODE_ENCOUNTER
# 600 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_Excadrill_Text_0
# 602 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 603 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 604 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 605 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 606 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 607 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 608 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Dugtrio::
# 613 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 614 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 615 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	playmoncry SPECIES_DUGTRIO, CRY_MODE_ENCOUNTER
# 616 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	message LavarborTunnelUnfinished_EventScript_Dugtrio_Text_0
# 618 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmessage
# 619 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 30
# 620 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	closemessage
# 621 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 10
# 622 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 623 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 624 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_FossilManiac::
# 629 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	faceplayer
# 630 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 1
# 631 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 632 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 633 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Tunneler1::
# 638 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	faceplayer
# 639 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 1
# 640 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 641 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 642 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Tunneler2::
# 647 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	faceplayer
# 648 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 1
# 649 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 650 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 651 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Tunneler3::
# 656 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	faceplayer
# 657 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	delay 1
# 658 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 659 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	waitmovement
# 660 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	release
	return


LavarborTunnelUnfinished_EventScript_Fossil_Text_0:
# 218 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "You found the {STR_VAR_1}.\p"
	.string "Take the {STR_VAR_1}?$"

LavarborTunnelUnfinished_EventScript_Fossil_Text_1:
# 221 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "alone.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_0:
# 238 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: Ah, {PLAYER}.\p"
	.string "Look at this!\p"
	.string "The humble beginnings of our tunnel to\n"
	.string "FALLARBOR.\p"
	.string "Remember how this meagar tunnel looks\n"
	.string "today…\p"
	.string "Because once it's complete, this tunnel\n"
	.string "will be one of the most impressive\l"
	.string "constructions in HOENN!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_1:
# 242 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: Hello again, {PLAYER}.\n"
	.string "Come back to see the progress?\p"
	.string "Well as you can see, we've started\n"
	.string "descending deeper underground.\p"
	.string "FALLARBOR is at a lower elevation than\n"
	.string "LAVARIDGE, so we need to tunnel down\l"
	.string "quite far.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_2:
# 247 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: {PLAYER}, I'm glad you\n"
	.string "came!\p"
	.string "We'll be tunneling to the north from\n"
	.string "here, but I want your opinion whether\l"
	.string "we should work on the left or right side\l"
	.string "of this wall here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_3:
# 257 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "What do you think?$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_4:
# 259 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Left$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_5:
# 259 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Right$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_6:
# 261 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Great idea!\p"
	.string "We'll get started on that right away,\n"
	.string "but if we can't get through over there\l"
	.string "it will delay the project a bit.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_7:
# 269 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Hey you!\l"
	.string "DIGGERSBY!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_8:
# 279 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Get to work on that wall!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_9:
# 303 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: Well, we opened up that\n"
	.string "wall like you asked…$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_10:
# 312 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Turns out there was a small cavern back\n"
	.string "there!\p"
	.string "Unfortunately, that means we'll have to\n"
	.string "reroute and dig a little deeper before\l"
	.string "we can proceed.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_11:
# 316 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: We're still working on\n"
	.string "this wall here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_12:
# 325 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Check back soon, I'm sure we'll break\n"
	.string "through any day now!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_13:
# 329 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: {PLAYER}, I'm glad you\n"
	.string "came!\p"
	.string "We're having trouble deciding whether\n"
	.string "to dig North or West from here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_14:
# 344 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "North$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_15:
# 344 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "West$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_16:
# 355 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Hey you!\l"
	.string "DUGTRIO!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_17:
# 387 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: Well, we tunneled in the\n"
	.string "direction you asked…$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_18:
# 396 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Turns out there was a small cavern up\n"
	.string "there!\p"
	.string "Unfortunately, that means we wasted\n"
	.string "time digging in the wrong direction.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_19:
# 400 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: We're still digging back\n"
	.string "here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_20:
# 419 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: {PLAYER}, I'm glad you\n"
	.string "came!\p"
	.string "We're having trouble deciding whether\n"
	.string "to dig North or South from here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_21:
# 434 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "South$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_22:
# 444 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Hey you!\l"
	.string "EXCADRILL!$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_23:
# 491 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "Turns out there was a small cavern down\n"
	.string "there!\p"
	.string "Unfortunately, that means we wasted\n"
	.string "time digging in the wrong direction.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_24:
# 495 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MANIAC: We're still digging down\n"
	.string "here.$"

LavarborTunnelUnfinished_EventScript_TunnelManiac_Text_25:
# 510 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "TUNNEL MASTER: {PLAYER}!\l"
	.string "Just the person I wanted to see!\p"
	.string "We were tunneling up through this wall\n"
	.string "when suddenly all the POKéMON became\l"
	.string "very wary.\p"
	.string "It's a shame;\p"
	.string "I'm quite certain there's a large\n"
	.string "natural cavern through here,\p"
	.string "and we are definitely getting close to\n"
	.string "FALLARBOR…\p"
	.string "But there's something dangerous in\n"
	.string "there, that's for sure!\p"
	.string "Since you're a talented up-and-coming\n"
	.string "TRAINER, I thought you might be willing\l"
	.string "to take a look?\p"
	.string "But exercise extreme caution!\p"
	.string "We wouldn't want to lose any more crew\n"
	.string "members!$"

LavarborTunnelUnfinished_EventScript_OrthwormAttacks_Text_0:
# 535 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "W{PAUSE 5}O{PAUSE 5}O{PAUSE 5}O{PAUSE 5}O{PAUSE 5}O{PAUSE 5}O{PAUSE 5}R{PAUSE 5}M!$"

LavarborTunnelUnfinished_EventScript_Diggersby_Text_0:
# 584 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "D{PAUSE 5}I{PAUSE 5}I{PAUSE 5}I{PAUSE 5}I{PAUSE 5}I{PAUSE 5}I{PAUSE 5}G{PAUSE 5}G{PAUSE 5}!$"

LavarborTunnelUnfinished_EventScript_Excadrill_Text_0:
# 600 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "D{PAUSE 2}R{PAUSE 2}I{PAUSE 2}I{PAUSE 2}I{PAUSE 2}I{PAUSE 2}I{PAUSE 2}L{PAUSE 2}L{PAUSE 2}!$"

LavarborTunnelUnfinished_EventScript_Dugtrio_Text_0:
# 616 "data//maps/LavarborTunnelUnfinished/scripts.pory"
	.string "D{PAUSE 2}U{PAUSE 2}U{PAUSE 2}U{PAUSE 2}U{PAUSE 2}U{PAUSE 2}U{PAUSE 2}G{PAUSE 2}!$"
