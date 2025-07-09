# 1 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 2 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_MapScripts::
# 3 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
# 4 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
# 5 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_GameCorner_OnTransition
# 6 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_GameCorner_OnResume
# 7 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.byte 0
# 8 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 9 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_OnTransition:
# 10 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_notwearoutfit OUTFIT_OLD_MAN, MossdeepCity_GameCorner_1F_EventScript_TrySetObviousDisguiseFlag
# 11 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 12 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_eq VAR_TEMP_F, 1, MossdeepCity_GameCorner_1F_EventScript_SetExitArcadeFlag
# 13 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 14 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 15 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_OnResume:
# 16 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_notwearoutfit OUTFIT_OLD_MAN, MossdeepCity_GameCorner_1F_EventScript_TrySetObviousDisguiseFlag
# 17 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 18 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 19 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_TrySetObviousDisguiseFlag::
# 20 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_unset FLAG_TEMP_3, MossdeepCity_GameCorner_1F_EventScript_SetObviousDisguiseFlag
# 21 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	return
# 22 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 23 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_SetObviousDisguiseFlag::
# 24 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	setflag FLAG_TEMP_3
# 25 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	return 
# 26 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 27 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_SetExitArcadeFlag::
# 28 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	setvar VAR_TEMP_4, 1
# 29 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	return 
# 30 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 31 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_OnWarp:
# 32 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
# 33 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script_2 VAR_TEMP_4, 1, MossdeepCity_GameCorner_1F_OpenGate
# 34 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.2byte 0
# 35 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 36 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_OpenGate::
# 37 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call EventScript_OpenMossdeepGameCornerBarrier
# 38 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GC_DOORMAN, Common_Movement_FaceLeft
# 39 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	return
# 40 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 41 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_OnFrame:
# 42 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	@ map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
# 43 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	map_script_2 VAR_TEMP_4, 1, MossdeepCity_GameCorner_1F_EventScript_ExitArcade
# 44 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.2byte 0
# 45 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 46 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Script is redundant, the label in the goto also does lock and faceplayer
# 47 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
# 48 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lock
# 49 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	faceplayer
# 50 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto_if_set FLAG_ORIGINAL_MOSSDEEP_GAME_CORNER, MossdeepCity_GameCorner_1F_EventScript_InfoMan2
# 51 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 52 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	checkitem ITEM_COIN_CASE
# 53 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoManDenied
# 54 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_notwearoutfit OUTFIT_OLD_MAN, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoManDenied
# 55 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	
# 56 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan
# 57 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 58 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 59 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 60 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoManDenied::
# 61 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ArcadeInfoManDenied, MSGBOX_DEFAULT
# 62 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 63 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 64 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 65 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ArcadeInfoManDenied:
# 66 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "If you want to get in, talk to\n"
# 67 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "the old man to my right.$"
# 68 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 69 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Script is redundant, the label in the goto also does lock and faceplayer
# 70 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_OldMan::
# 71 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lock
# 72 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	faceplayer
# 73 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto_if_set FLAG_ORIGINAL_MOSSDEEP_GAME_CORNER, MossdeepCity_GameCorner_1F_EventScript_OldMan2
# 74 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 75 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ArcadeOldManCredentials, MSGBOX_DEFAULT
# 76 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmessage
# 77 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	checkitem ITEM_COIN_CASE
# 78 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_GameCorner_1F_EventScript_ArcadeOldManDenied
# 79 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 80 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call_if_wearoutfit OUTFIT_OLD_MAN, MossdeepCity_GameCorner_1F_EventScript_EnterArcade
# 81 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 82 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ABitYoung, MSGBOX_DEFAULT
# 83 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 84 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 85 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 86 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_ObviousDisguise::
# 87 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ObviousDisguise, MSGBOX_DEFAULT
# 88 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 89 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 90 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 91 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ObviousDisguise:
# 92 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "You can't fool me, youngster!\p"
# 93 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "That's a decent disguise, but\n"
# 94 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I just saw you put it on!$"
# 95 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 96 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_EnterArcade::
# 97 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto_if_set FLAG_TEMP_3, MossdeepCity_GameCorner_1F_EventScript_ObviousDisguise
# 98 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ApprovedEntry, MSGBOX_DEFAULT
# 99 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	closemessage
# 100 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	delay 10
# 101 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call EventScript_OpenMossdeepGameCornerBarrier
# 102 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	special DrawWholeMapView
# 103 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	playse SE_CLICK
# 104 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	delay 30
# 105 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 106 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmovement 0
# 107 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	closemessage
# 108 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_GameCorner_1F_Movement_PlayerEnterMinigameRoom
# 109 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmovement 0
# 110 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	delay 5
# 111 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	warp MAP_MOSSDEEP_CITY_GAME_CORNER_ARCADE, 1, 2
# 112 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 113 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 114 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 115 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_ExitArcade::
# 116 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lockall
# 117 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	@ call EventScript_OpenMossdeepGameCornerBarrier
# 118 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	@ special DrawWholeMapView
# 119 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	@ playse SE_CLICK
# 120 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	delay 5
# 121 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
# 122 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmovement 0
# 123 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GC_DOORMAN, Common_Movement_FaceDown
# 124 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmovement LOCALID_MOSSDEEP_GC_DOORMAN
# 125 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	delay 5
# 126 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	call EventScript_CloseMossdeepGameCornerBarrier
# 127 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	special DrawWholeMapView
# 128 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	playse SE_CLICK
# 129 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	setvar VAR_TEMP_4, 0
# 130 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	releaseall
# 131 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 132 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 133 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Movement_PlayerEnterMinigameRoom:
# 134 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	walk_left
# 135 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	walk_up
# 136 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	walk_up
# 137 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	walk_up
# 138 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	set_invisible
# 139 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	step_end
# 140 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 141 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_EventScript_ArcadeOldManDenied::
# 142 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ArcadeOldManDenied, MSGBOX_DEFAULT
# 143 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
# 144 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 145 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 146 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ApprovedEntry:
# 147 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Absolutely.\n"
# 148 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Enter right through here.$"
# 149 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 150 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ArcadeOldManCredentials:
# 151 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Oh? You want to enjoy our\n"
# 152 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "establishment?$"
# 153 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 154 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ArcadeOldManDenied:
# 155 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I'm sorry,\n"
# 156 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I can't let you in…$"
# 157 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 158 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_ABitYoung:
# 159 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Aren't you a bit young?\n"
# 160 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Come back when you're older!$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan::
# 164 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	lock
# 165 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	faceplayer
# 166 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	message MossdeepCity_GameCorner_1F_Text_DescribeWhichArcadeGame
# 167 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	waitmessage
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_0, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_1, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_2, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_3, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_4
# 169 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	switch VAR_RESULT
# 170 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	case 0, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_3
# 174 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	case 1, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_4
# 178 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	case 2, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_5
# 182 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	case 3, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_6
# 186 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	case 4, MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_7
MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_1:
# 189 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
	end

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_3:
# 171 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_OnixInfo, MSGBOX_DEFAULT
# 172 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
	end

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_4:
# 175 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_DropSpinInfo, MSGBOX_DEFAULT
# 176 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
	end

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_5:
# 179 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_BlockBuilderInfo, MSGBOX_DEFAULT
# 180 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
	end

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_6:
# 183 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_FlutterFreeInfo, MSGBOX_DEFAULT
# 184 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	release
	end

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_7:
# 187 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo
	goto MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_1


# 192 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 193 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 194 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_DescribeWhichArcadeGame:
# 195 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I can explain the arcade games,\n"
# 196 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "if you'd like.\p"
# 197 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Which game should I describe?$"
# 198 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 199 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_OnixInfo:
# 200 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "“ONIX”\p"
# 201 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Info$"
# 202 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 203 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 204 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_DropSpinInfo:
# 205 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "“DROPSPIN”\p"
# 206 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Info$"
# 207 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	
# 208 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 209 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_BlockBuilderInfo:
# 210 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "“BLOCK BUILDER”\p"
# 211 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Info$"
# 212 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	
# 213 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 214 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
MossdeepCity_GameCorner_1F_Text_FlutterFreeInfo:
# 215 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "“FLUTTERFREE”\p"
# 216 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Info$"
# 217 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	
# 218 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 219 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ Everything below is leftover from RS
# 220 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
# 221 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ The text below is unused and duplicated in its replacement in Sootopolis City
# 222 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
@ And the BG Door event was moved inaccessibly into a wall
# 223 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 224 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_EventScript_Door::
# 225 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
# 226 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	end
# 227 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 228 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_OldManGreeting:
# 229 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "When I was young, I traveled the world\n"
# 230 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "as a POKéMON TRAINER.\p"
# 231 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Now that I've become an old buzzard,\n"
# 232 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "my only amusement is watching young\l"
# 233 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "TRAINERS battle.$"
# 234 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 235 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_DoorIsLocked:
# 236 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "The door appears to be locked.$"
# 237 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 238 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
# 239 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "A TRAINER named {STR_VAR_1} is\n"
# 240 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "visiting my home.\p"
# 241 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Would you like to challenge\n"
# 242 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "{STR_VAR_1}?$"
# 243 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 244 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_YouWontBattle:
# 245 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "You won't battle? I'm disappointed\n"
# 246 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "that I can't see you battle…$"
# 247 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 248 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_KeepItToA3On3:
# 249 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Oh, good, good!\p"
# 250 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "But my house isn't all that sturdy.\p"
# 251 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Could I ask you to keep it down to\n"
# 252 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "a 3-on-3 match?$"
# 253 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 254 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_SaveYourProgress:
# 255 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Before you two battle, you should\n"
# 256 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "save your progress.$"
# 257 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 258 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
# 259 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I hope to see a good match!$"
# 260 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 261 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleTie:
# 262 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "So, it became a standoff.\p"
# 263 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "It was a brilliant match in which\n"
# 264 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "neither side conceded a step!$"
# 265 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 266 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleWon:
# 267 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "That was superlative!\p"
# 268 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Why, it was like seeing myself in\n"
# 269 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "my youth again!$"
# 270 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"

# 271 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
RS_MysteryEventsHouse_Text_BattleLost:
# 272 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Ah, too bad for you!\p"
# 273 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "But it was a good match.\n"
# 274 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "I hope you can win next time.$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_0:
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Onix$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_1:
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "DropSpin$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_2:
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Block Builder$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_3:
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "FlutterFree$"

MossdeepCity_GameCorner_1F_EventScript_ArcadeInfoMan_Text_4:
# 168 "data//maps/MossdeepCity_GameCorner_1F/scripts.pory"
	.string "Dodrio Berry Picking$"
