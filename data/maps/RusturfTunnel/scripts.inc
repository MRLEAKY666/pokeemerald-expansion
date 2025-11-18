# 1 "data//maps/RusturfTunnel/scripts.pory"

# 2 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 3 "data//maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 4 "data//maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 5 "data//maps/RusturfTunnel/scripts.pory"
	.byte 0
# 6 "data//maps/RusturfTunnel/scripts.pory"

# 7 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 8 "data//maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
# 9 "data//maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
# 10 "data//maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 11 "data//maps/RusturfTunnel/scripts.pory"

# 12 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 13 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 14 "data//maps/RusturfTunnel/scripts.pory"
	end
# 15 "data//maps/RusturfTunnel/scripts.pory"

# 16 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 17 "data//maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_PEEKO, 13, 4
# 18 "data//maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_GRUNT, 13, 5
# 19 "data//maps/RusturfTunnel/scripts.pory"
	return
# 20 "data//maps/RusturfTunnel/scripts.pory"

# 21 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 22 "data//maps/RusturfTunnel/scripts.pory"
	lock
# 23 "data//maps/RusturfTunnel/scripts.pory"
	faceplayer
# 24 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 25 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 26 "data//maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 27 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 28 "data//maps/RusturfTunnel/scripts.pory"
	release
# 29 "data//maps/RusturfTunnel/scripts.pory"
	end
# 30 "data//maps/RusturfTunnel/scripts.pory"

# 31 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend::
# 32 "data//maps/RusturfTunnel/scripts.pory"
	lock
# 33 "data//maps/RusturfTunnel/scripts.pory"
	faceplayer
# 34 "data//maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 35 "data//maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 36 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 37 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 38 "data//maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 39 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 40 "data//maps/RusturfTunnel/scripts.pory"
	release
# 41 "data//maps/RusturfTunnel/scripts.pory"
	end
# 42 "data//maps/RusturfTunnel/scripts.pory"

# 43 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 44 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 45 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 46 "data//maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 47 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 48 "data//maps/RusturfTunnel/scripts.pory"
	release
# 49 "data//maps/RusturfTunnel/scripts.pory"
	end
# 50 "data//maps/RusturfTunnel/scripts.pory"

# 51 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 52 "data//maps/RusturfTunnel/scripts.pory"
	lockall
# 53 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 54 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 55 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 56 "data//maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 57 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 58 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 59 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 60 "data//maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 61 "data//maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 62 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 63 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 64 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 65 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 66 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 67 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 68 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 69 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 70 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 71 "data//maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 72 "data//maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 73 "data//maps/RusturfTunnel/scripts.pory"
	releaseall
# 74 "data//maps/RusturfTunnel/scripts.pory"
	end
# 75 "data//maps/RusturfTunnel/scripts.pory"

# 76 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 77 "data//maps/RusturfTunnel/scripts.pory"
	hidefollower
# 78 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 79 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 80 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 81 "data//maps/RusturfTunnel/scripts.pory"
	return
# 82 "data//maps/RusturfTunnel/scripts.pory"

# 83 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 84 "data//maps/RusturfTunnel/scripts.pory"
	hidefollower
# 85 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 86 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 87 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 88 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 89 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 90 "data//maps/RusturfTunnel/scripts.pory"
	return
# 91 "data//maps/RusturfTunnel/scripts.pory"

# 92 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 93 "data//maps/RusturfTunnel/scripts.pory"
	hidefollower
# 94 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 95 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 96 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 97 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 98 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 99 "data//maps/RusturfTunnel/scripts.pory"
	return
# 100 "data//maps/RusturfTunnel/scripts.pory"

# 101 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 102 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 103 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 104 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 105 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 106 "data//maps/RusturfTunnel/scripts.pory"
	return
# 107 "data//maps/RusturfTunnel/scripts.pory"

# 108 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 109 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 110 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 111 "data//maps/RusturfTunnel/scripts.pory"
	return
# 112 "data//maps/RusturfTunnel/scripts.pory"

# 113 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 114 "data//maps/RusturfTunnel/scripts.pory"
	return
# 115 "data//maps/RusturfTunnel/scripts.pory"

# 116 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 117 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 118 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 119 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 120 "data//maps/RusturfTunnel/scripts.pory"
	return
# 121 "data//maps/RusturfTunnel/scripts.pory"

# 122 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 123 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit1
# 124 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 125 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 126 "data//maps/RusturfTunnel/scripts.pory"
	return
# 127 "data//maps/RusturfTunnel/scripts.pory"

# 128 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 129 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 130 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit
# 131 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 132 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 133 "data//maps/RusturfTunnel/scripts.pory"
	return
# 134 "data//maps/RusturfTunnel/scripts.pory"

# 135 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 136 "data//maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 137 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_ExclamationMark
# 138 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 139 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_Delay48
# 140 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 141 "data//maps/RusturfTunnel/scripts.pory"
	return
# 142 "data//maps/RusturfTunnel/scripts.pory"

# 143 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 144 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 145 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 146 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 147 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 148 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 149 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 150 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 151 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 152 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 153 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 154 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 155 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 156 "data//maps/RusturfTunnel/scripts.pory"

# 157 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 158 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 159 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 160 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 161 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 162 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 163 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 164 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 165 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 166 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 167 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 168 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 169 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 170 "data//maps/RusturfTunnel/scripts.pory"

# 171 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 172 "data//maps/RusturfTunnel/scripts.pory"
	delay_8
# 173 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 174 "data//maps/RusturfTunnel/scripts.pory"
	delay_16
# 175 "data//maps/RusturfTunnel/scripts.pory"
	delay_16
# 176 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 177 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 178 "data//maps/RusturfTunnel/scripts.pory"

# 179 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 180 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 181 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 182 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 183 "data//maps/RusturfTunnel/scripts.pory"

# 184 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 185 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 186 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 187 "data//maps/RusturfTunnel/scripts.pory"
	delay_8
# 188 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 189 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 190 "data//maps/RusturfTunnel/scripts.pory"

# 191 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 192 "data//maps/RusturfTunnel/scripts.pory"
	walk_up
# 193 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 194 "data//maps/RusturfTunnel/scripts.pory"
	delay_8
# 195 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 196 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 197 "data//maps/RusturfTunnel/scripts.pory"

# 198 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 199 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 200 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 201 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 202 "data//maps/RusturfTunnel/scripts.pory"

# 203 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 204 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 205 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 206 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 207 "data//maps/RusturfTunnel/scripts.pory"

# 208 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 209 "data//maps/RusturfTunnel/scripts.pory"
	walk_up
# 210 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 211 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 212 "data//maps/RusturfTunnel/scripts.pory"

# 213 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 214 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 215 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 216 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 217 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 218 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 219 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 220 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 221 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 222 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 223 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 224 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 225 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 226 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 227 "data//maps/RusturfTunnel/scripts.pory"

# 228 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 229 "data//maps/RusturfTunnel/scripts.pory"
	walk_up
# 230 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 231 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 232 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 233 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 234 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 235 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 236 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 237 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 238 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 239 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 240 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 241 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 242 "data//maps/RusturfTunnel/scripts.pory"

# 243 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 244 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 245 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 246 "data//maps/RusturfTunnel/scripts.pory"

# 247 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 248 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 249 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 250 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 251 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 252 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 253 "data//maps/RusturfTunnel/scripts.pory"

# 254 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 255 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 256 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 257 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 258 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 259 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 260 "data//maps/RusturfTunnel/scripts.pory"

# 261 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 262 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 263 "data//maps/RusturfTunnel/scripts.pory"
	end
# 264 "data//maps/RusturfTunnel/scripts.pory"

# 265 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 266 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 267 "data//maps/RusturfTunnel/scripts.pory"
	end
# 268 "data//maps/RusturfTunnel/scripts.pory"

# 269 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 270 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 271 "data//maps/RusturfTunnel/scripts.pory"
	end
# 272 "data//maps/RusturfTunnel/scripts.pory"

# 273 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 274 "data//maps/RusturfTunnel/scripts.pory"
	lockall
# 275 "data//maps/RusturfTunnel/scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 276 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 277 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 278 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 279 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 280 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 281 "data//maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_GRUNT
# 282 "data//maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_PEEKO
# 283 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 284 "data//maps/RusturfTunnel/scripts.pory"
	releaseall
# 285 "data//maps/RusturfTunnel/scripts.pory"
	end
# 286 "data//maps/RusturfTunnel/scripts.pory"

# 287 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 288 "data//maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 289 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 290 "data//maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 291 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 292 "data//maps/RusturfTunnel/scripts.pory"

# 293 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 294 "data//maps/RusturfTunnel/scripts.pory"
	lock
# 295 "data//maps/RusturfTunnel/scripts.pory"
	faceplayer
# 296 "data//maps/RusturfTunnel/scripts.pory"
	waitse
# 297 "data//maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 298 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 299 "data//maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 300 "data//maps/RusturfTunnel/scripts.pory"
	release
# 301 "data//maps/RusturfTunnel/scripts.pory"
	end
# 302 "data//maps/RusturfTunnel/scripts.pory"

# 303 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Grunt::
# 304 "data//maps/RusturfTunnel/scripts.pory"
	lock
# 305 "data//maps/RusturfTunnel/scripts.pory"
	faceplayer
# 306 "data//maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 307 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 308 "data//maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 309 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 310 "data//maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_PARTS
# 311 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 312 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 313 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntEscape
# 314 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 315 "data//maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_GRUNT
# 316 "data//maps/RusturfTunnel/scripts.pory"
	delay 50
# 317 "data//maps/RusturfTunnel/scripts.pory"
	addobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 318 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
# 319 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 320 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 321 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
# 322 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 323 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 324 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, Common_Movement_FacePlayer
# 325 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 326 "data//maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 327 "data//maps/RusturfTunnel/scripts.pory"
	waitmessage
# 328 "data//maps/RusturfTunnel/scripts.pory"
	waitse
# 329 "data//maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 330 "data//maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 331 "data//maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 332 "data//maps/RusturfTunnel/scripts.pory"
	closemessage
# 333 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 334 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyExit
# 335 "data//maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_PeekoExit
# 336 "data//maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 337 "data//maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 338 "data//maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_PEEKO
# 339 "data//maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 340 "data//maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 341 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 342 "data//maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 343 "data//maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 344 "data//maps/RusturfTunnel/scripts.pory"
	release
# 345 "data//maps/RusturfTunnel/scripts.pory"
	end
# 346 "data//maps/RusturfTunnel/scripts.pory"

# 347 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 348 "data//maps/RusturfTunnel/scripts.pory"
	face_down
# 349 "data//maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 350 "data//maps/RusturfTunnel/scripts.pory"
	walk_up
# 351 "data//maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 352 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 353 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 354 "data//maps/RusturfTunnel/scripts.pory"

# 355 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 356 "data//maps/RusturfTunnel/scripts.pory"
	walk_down
# 357 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 358 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 359 "data//maps/RusturfTunnel/scripts.pory"

# 360 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 361 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 362 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 363 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 364 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 365 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 366 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 367 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 368 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 369 "data//maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 370 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 371 "data//maps/RusturfTunnel/scripts.pory"

# 372 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 373 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 374 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 375 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 376 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 377 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 378 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 379 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 380 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 381 "data//maps/RusturfTunnel/scripts.pory"

# 382 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 383 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 384 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 385 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 386 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 387 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 388 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 389 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 390 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 391 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 392 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 393 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 394 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 395 "data//maps/RusturfTunnel/scripts.pory"

# 396 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 397 "data//maps/RusturfTunnel/scripts.pory"
	delay_16
# 398 "data//maps/RusturfTunnel/scripts.pory"
	delay_8
# 399 "data//maps/RusturfTunnel/scripts.pory"
	delay_4
# 400 "data//maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 401 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 402 "data//maps/RusturfTunnel/scripts.pory"

# 403 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 404 "data//maps/RusturfTunnel/scripts.pory"
	delay_16
# 405 "data//maps/RusturfTunnel/scripts.pory"
	walk_right
# 406 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 407 "data//maps/RusturfTunnel/scripts.pory"

# 408 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 409 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 410 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 411 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 412 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 413 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 414 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 415 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 416 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 417 "data//maps/RusturfTunnel/scripts.pory"
	walk_left
# 418 "data//maps/RusturfTunnel/scripts.pory"
	step_end
# 419 "data//maps/RusturfTunnel/scripts.pory"

# 420 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 421 "data//maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 422 "data//maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 423 "data//maps/RusturfTunnel/scripts.pory"
	end
# 424 "data//maps/RusturfTunnel/scripts.pory"

# 425 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 426 "data//maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 427 "data//maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 428 "data//maps/RusturfTunnel/scripts.pory"

# 429 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 430 "data//maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 431 "data//maps/RusturfTunnel/scripts.pory"

# 432 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 433 "data//maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 434 "data//maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 435 "data//maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 436 "data//maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 437 "data//maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 438 "data//maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 439 "data//maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 440 "data//maps/RusturfTunnel/scripts.pory"

# 441 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 442 "data//maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 443 "data//maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 444 "data//maps/RusturfTunnel/scripts.pory"

# 445 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 446 "data//maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 447 "data//maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 448 "data//maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 449 "data//maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 450 "data//maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 451 "data//maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 452 "data//maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 453 "data//maps/RusturfTunnel/scripts.pory"

# 454 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 455 "data//maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 456 "data//maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 457 "data//maps/RusturfTunnel/scripts.pory"

# 458 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 459 "data//maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 460 "data//maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 461 "data//maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 462 "data//maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 463 "data//maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 464 "data//maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 465 "data//maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 466 "data//maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 467 "data//maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 468 "data//maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 469 "data//maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 470 "data//maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 471 "data//maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 472 "data//maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 473 "data//maps/RusturfTunnel/scripts.pory"

# 474 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 475 "data//maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 476 "data//maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 477 "data//maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 478 "data//maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 479 "data//maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 480 "data//maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 481 "data//maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 482 "data//maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 483 "data//maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 484 "data//maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 485 "data//maps/RusturfTunnel/scripts.pory"

# 486 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 487 "data//maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 488 "data//maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 489 "data//maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 490 "data//maps/RusturfTunnel/scripts.pory"

# 491 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 492 "data//maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 493 "data//maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 494 "data//maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 495 "data//maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 496 "data//maps/RusturfTunnel/scripts.pory"

# 497 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 498 "data//maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 499 "data//maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 500 "data//maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 501 "data//maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 502 "data//maps/RusturfTunnel/scripts.pory"

# 503 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 504 "data//maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 505 "data//maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 506 "data//maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 507 "data//maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 508 "data//maps/RusturfTunnel/scripts.pory"

# 509 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 510 "data//maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 511 "data//maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 512 "data//maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 513 "data//maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 514 "data//maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 515 "data//maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 516 "data//maps/RusturfTunnel/scripts.pory"

# 517 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 518 "data//maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 519 "data//maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 520 "data//maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 521 "data//maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 522 "data//maps/RusturfTunnel/scripts.pory"

# 523 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 524 "data//maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 525 "data//maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 526 "data//maps/RusturfTunnel/scripts.pory"

# 527 "data//maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 528 "data//maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 529 "data//maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 530 "data//maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"
