# 1 "data//maps/DewfordTown_House2/scripts.pory"

# 2 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_MapScripts::
# 3 "data//maps/DewfordTown_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_House2_OnTransition
# 4 "data//maps/DewfordTown_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DewfordTown_House2_OnFrame
# 5 "data//maps/DewfordTown_House2/scripts.pory"
	.byte 0
# 6 "data//maps/DewfordTown_House2/scripts.pory"

# 7 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_OnTransition:
# 8 "data//maps/DewfordTown_House2/scripts.pory"
	call_if_le VAR_FLASH_QUEST_STATE, 3, DewfordTown_House2_EventScript_SetupOriginalDwellers
# 9 "data//maps/DewfordTown_House2/scripts.pory"
	call_if_eq VAR_FLASH_QUEST_STATE, 3, DewfordTown_House2_EventScript_TrySetupHouseSwapScene
# 10 "data//maps/DewfordTown_House2/scripts.pory"
	call_if_gt VAR_FLASH_QUEST_STATE, 3, DewfordTown_House2_EventScript_SetupNewDweller
# 11 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 12 "data//maps/DewfordTown_House2/scripts.pory"

# 13 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_OnFrame:
# 14 "data//maps/DewfordTown_House2/scripts.pory"
	map_script_2 VAR_FLASH_QUEST_STATE, 4, DewfordTown_House2_EventScript_HouseSwapScene
# 15 "data//maps/DewfordTown_House2/scripts.pory"
	@ map_script_2 VAR_FLASH_QUEST_STATE, 5, DewfordTown_House2_EventScript_HouseSwapScene
# 16 "data//maps/DewfordTown_House2/scripts.pory"
	.2byte 0
# 17 "data//maps/DewfordTown_House2/scripts.pory"

# 18 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_SetupOriginalDwellers::
# 19 "data//maps/DewfordTown_House2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
# 20 "data//maps/DewfordTown_House2/scripts.pory"
	return
# 21 "data//maps/DewfordTown_House2/scripts.pory"

# 22 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_SetupNewDweller::
# 23 "data//maps/DewfordTown_House2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HIKER
# 24 "data//maps/DewfordTown_House2/scripts.pory"
	setobjectxyperm LOCALID_DEWFORD_HOUSE_SON, 1, 0
# 25 "data//maps/DewfordTown_House2/scripts.pory"
	setobjectmovementtype LOCALID_DEWFORD_HOUSE_SON, MOVEMENT_TYPE_INVISIBLE
# 26 "data//maps/DewfordTown_House2/scripts.pory"
	return
# 27 "data//maps/DewfordTown_House2/scripts.pory"

# 28 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_TrySetupHouseSwapScene::
# 29 "data//maps/DewfordTown_House2/scripts.pory"
	getfollowernpc
# 30 "data//maps/DewfordTown_House2/scripts.pory"
	call_if_eq VAR_RESULT, FLAG_FLASH_GUY, DewfordTown_House2_EventScript_SetupHouseSwapScene
# 31 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 32 "data//maps/DewfordTown_House2/scripts.pory"

# 33 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_SetupHouseSwapScene::
# 34 "data//maps/DewfordTown_House2/scripts.pory"
	setvar VAR_FLASH_QUEST_STATE, 4
# 35 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 36 "data//maps/DewfordTown_House2/scripts.pory"

# 37 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_HouseSwapScene::
# 38 "data//maps/DewfordTown_House2/scripts.pory"
	@ lock
# 39 "data//maps/DewfordTown_House2/scripts.pory"
	destroyfollowernpc
# 40 "data//maps/DewfordTown_House2/scripts.pory"
	addobject LOCALID_DEWFORD_FLASHGUY
# 41 "data//maps/DewfordTown_House2/scripts.pory"
	setobjectxy LOCALID_DEWFORD_FLASHGUY, 3, 8
# 42 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_PLAYER, DewfordTown_House2_Movement_ArriveForSwapScene
# 43 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_PLAYER
# 44 "data//maps/DewfordTown_House2/scripts.pory"
	delay 5
# 45 "data//maps/DewfordTown_House2/scripts.pory"

# 46 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_FaceUp
# 47 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 48 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_SetVisible
# 49 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_FLASHGUY
# 50 "data//maps/DewfordTown_House2/scripts.pory"
	delay 15
# 51 "data//maps/DewfordTown_House2/scripts.pory"

# 52 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, Common_Movement_ExclamationMark
# 53 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_HOUSE_DAD
# 54 "data//maps/DewfordTown_House2/scripts.pory"
	playse SE_PIN
# 55 "data//maps/DewfordTown_House2/scripts.pory"
	delay 5
# 56 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, Common_Movement_FaceDown
# 57 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_HOUSE_DAD
# 58 "data//maps/DewfordTown_House2/scripts.pory"
	delay 10
# 59 "data//maps/DewfordTown_House2/scripts.pory"

# 60 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_PLAYER, DewfordTown_House2_Movement_PlayerPosForSwapScene
# 61 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, DewfordTown_House2_Movement_FollowerPosForSwapScene1
# 62 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_FLASHGUY
# 63 "data//maps/DewfordTown_House2/scripts.pory"
	delay 15
# 64 "data//maps/DewfordTown_House2/scripts.pory"

# 65 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, DewfordTown_House2_Movement_FollowerPosForSwapScene2
# 66 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_FLASHGUY
# 67 "data//maps/DewfordTown_House2/scripts.pory"

# 68 "data//maps/DewfordTown_House2/scripts.pory"
	delay 30
# 69 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, DewfordTown_House2_Movement_DadConverse
# 70 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, DewfordTown_House2_Movement_GuyConverse
# 71 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement LOCALID_DEWFORD_FLASHGUY
# 72 "data//maps/DewfordTown_House2/scripts.pory"
	delay 20
# 73 "data//maps/DewfordTown_House2/scripts.pory"
	playse SE_RG_HELP_OPEN
# 74 "data//maps/DewfordTown_House2/scripts.pory"
	waitse
# 75 "data//maps/DewfordTown_House2/scripts.pory"
	delay 30
# 76 "data//maps/DewfordTown_House2/scripts.pory"

# 77 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_FaceLeft
# 78 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 79 "data//maps/DewfordTown_House2/scripts.pory"

# 80 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_WalkToPlayer
# 81 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 82 "data//maps/DewfordTown_House2/scripts.pory"

# 83 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_SwapScene1, MSGBOX_DEFAULT
# 84 "data//maps/DewfordTown_House2/scripts.pory"

# 85 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, Common_Movement_WalkInPlaceFasterLeft
# 86 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 87 "data//maps/DewfordTown_House2/scripts.pory"

# 88 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_SwapScene2, MSGBOX_DEFAULT
# 89 "data//maps/DewfordTown_House2/scripts.pory"
	waitmessage
# 90 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_WalkInPlaceFasterLeft
# 91 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_SwapScene3, MSGBOX_DEFAULT
# 92 "data//maps/DewfordTown_House2/scripts.pory"
	waitmessage
# 93 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_WalkInPlaceLeft
# 94 "data//maps/DewfordTown_House2/scripts.pory"
	giveitem ITEM_HM_FLASH
# 95 "data//maps/DewfordTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 96 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_ExplainFlash, MSGBOX_DEFAULT
# 97 "data//maps/DewfordTown_House2/scripts.pory"
	delay 10
# 98 "data//maps/DewfordTown_House2/scripts.pory"

# 99 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, DewfordTown_House2_Movement_DadReadyToLeave
# 100 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 101 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_SON, Common_Movement_WalkInPlaceRight
# 102 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 103 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_SwapScene4, MSGBOX_DEFAULT
# 104 "data//maps/DewfordTown_House2/scripts.pory"
	delay 10
# 105 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_DAD, Common_Movement_WalkInPlaceDown
# 106 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_HOUSE_SON, Common_Movement_WalkInPlaceDown
# 107 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 108 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 109 "data//maps/DewfordTown_House2/scripts.pory"
	applymovement LOCALID_DEWFORD_FLASHGUY, Common_Movement_FaceUp
# 110 "data//maps/DewfordTown_House2/scripts.pory"
	waitmovement 0
# 111 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_SwapScene5, MSGBOX_DEFAULT
# 112 "data//maps/DewfordTown_House2/scripts.pory"
	closemessage
# 113 "data//maps/DewfordTown_House2/scripts.pory"
	setvar VAR_FLASH_QUEST_STATE, 5
# 114 "data//maps/DewfordTown_House2/scripts.pory"
	delay 5
# 115 "data//maps/DewfordTown_House2/scripts.pory"

# 116 "data//maps/DewfordTown_House2/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 117 "data//maps/DewfordTown_House2/scripts.pory"
	warpinplace
# 118 "data//maps/DewfordTown_House2/scripts.pory"

# 119 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 120 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 121 "data//maps/DewfordTown_House2/scripts.pory"

# 122 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Man_Vanilla::
# 123 "data//maps/DewfordTown_House2/scripts.pory"
	lock
# 124 "data//maps/DewfordTown_House2/scripts.pory"
	faceplayer
# 125 "data//maps/DewfordTown_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
# 126 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
# 127 "data//maps/DewfordTown_House2/scripts.pory"
	giveitem ITEM_SILK_SCARF
# 128 "data//maps/DewfordTown_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
# 129 "data//maps/DewfordTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_SILK_SCARF
# 130 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 131 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 132 "data//maps/DewfordTown_House2/scripts.pory"

# 133 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Man::
# 134 "data//maps/DewfordTown_House2/scripts.pory"
	lock
# 135 "data//maps/DewfordTown_House2/scripts.pory"
	faceplayer 
# 136 "data//maps/DewfordTown_House2/scripts.pory"
	goto_if_ge VAR_FLASH_QUEST_STATE, 5, DewfordTown_House2_EventScript_NewResident
# 137 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_Man1, MSGBOX_DEFAULT
# 138 "data//maps/DewfordTown_House2/scripts.pory"
	call_if_eq VAR_FLASH_QUEST_STATE, 0, DewfordTown_House2_EventScript_StartFlashQuest
# 139 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 140 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 141 "data//maps/DewfordTown_House2/scripts.pory"

# 142 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_StartFlashQuest::
# 143 "data//maps/DewfordTown_House2/scripts.pory"
	setvar VAR_FLASH_QUEST_STATE, 1
# 144 "data//maps/DewfordTown_House2/scripts.pory"
	return
# 145 "data//maps/DewfordTown_House2/scripts.pory"

# 146 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_NewResident::
# 147 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_NewResident, MSGBOX_DEFAULT
# 148 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 149 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 150 "data//maps/DewfordTown_House2/scripts.pory"

# 151 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_NoRoomForScarf::
# 152 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
# 153 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 154 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 155 "data//maps/DewfordTown_House2/scripts.pory"

# 156 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_ExplainSilkScarf::
# 157 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
# 158 "data//maps/DewfordTown_House2/scripts.pory"
	release
# 159 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 160 "data//maps/DewfordTown_House2/scripts.pory"

# 161 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Boy::
# 162 "data//maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
# 163 "data//maps/DewfordTown_House2/scripts.pory"
	end
# 164 "data//maps/DewfordTown_House2/scripts.pory"

# 165 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_ArriveForSwapScene:
# 166 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 167 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 168 "data//maps/DewfordTown_House2/scripts.pory"

# 169 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_PlayerPosForSwapScene:
# 170 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 171 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 172 "data//maps/DewfordTown_House2/scripts.pory"
	face_right
# 173 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 174 "data//maps/DewfordTown_House2/scripts.pory"

# 175 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_FollowerPosForSwapScene1:
# 176 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 177 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 178 "data//maps/DewfordTown_House2/scripts.pory"

# 179 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_FollowerPosForSwapScene2:
# 180 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 181 "data//maps/DewfordTown_House2/scripts.pory"
	walk_right
# 182 "data//maps/DewfordTown_House2/scripts.pory"
	walk_right
# 183 "data//maps/DewfordTown_House2/scripts.pory"
	walk_right
# 184 "data//maps/DewfordTown_House2/scripts.pory"
	face_up
# 185 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 186 "data//maps/DewfordTown_House2/scripts.pory"

# 187 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_DadConverse:
# 188 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 189 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 190 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 191 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_down
# 192 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_down
# 193 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 194 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 195 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_down
# 196 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_down
# 197 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 198 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 199 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 200 "data//maps/DewfordTown_House2/scripts.pory"

# 201 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_GuyConverse:
# 202 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_up
# 203 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_up
# 204 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_up
# 205 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 206 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 207 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_up
# 208 "data//maps/DewfordTown_House2/scripts.pory"
	walk_in_place_up
# 209 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 210 "data//maps/DewfordTown_House2/scripts.pory"
	delay_16
# 211 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 212 "data//maps/DewfordTown_House2/scripts.pory"

# 213 "data//maps/DewfordTown_House2/scripts.pory"
Common_Movement_WalkToPlayer:
# 214 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 215 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 216 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 217 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 218 "data//maps/DewfordTown_House2/scripts.pory"

# 219 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Movement_DadReadyToLeave:
# 220 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 221 "data//maps/DewfordTown_House2/scripts.pory"
	walk_up
# 222 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 223 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 224 "data//maps/DewfordTown_House2/scripts.pory"
	walk_left
# 225 "data//maps/DewfordTown_House2/scripts.pory"
	step_end
# 226 "data//maps/DewfordTown_House2/scripts.pory"

# 227 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_ExplainFlash:
# 228 "data//maps/DewfordTown_House2/scripts.pory"
	.string "RESTLESS MAN: That HM contains FLASH\p"
# 229 "data//maps/DewfordTown_House2/scripts.pory"
	.string "You'd think I'd want to have that\n"
# 230 "data//maps/DewfordTown_House2/scripts.pory"
	.string "now more than ever…\p"
# 231 "data//maps/DewfordTown_House2/scripts.pory"
	.string "But right now I'm just happy\n"
# 232 "data//maps/DewfordTown_House2/scripts.pory"
	.string "to be here.\p"
# 233 "data//maps/DewfordTown_House2/scripts.pory"
	.string "So don't worry about me, use that HM to\n" 
# 234 "data//maps/DewfordTown_House2/scripts.pory"
	.string "light your way on your adventure!$"
# 235 "data//maps/DewfordTown_House2/scripts.pory"

# 236 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_SwapScene1:
# 237 "data//maps/DewfordTown_House2/scripts.pory"
	.string "RESTLESS MAN: They agreed!!$"
# 238 "data//maps/DewfordTown_House2/scripts.pory"

# 239 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_SwapScene2:
# 240 "data//maps/DewfordTown_House2/scripts.pory"
	.string "SINGLE DAD: That's right, we'll be\n"
# 241 "data//maps/DewfordTown_House2/scripts.pory"
	.string "moving to MAUVILLE CITY right away!$"
# 242 "data//maps/DewfordTown_House2/scripts.pory"

# 243 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_SwapScene3:
# 244 "data//maps/DewfordTown_House2/scripts.pory"
	.string "RESTLESS MAN: Thank you for arranging\n"
# 245 "data//maps/DewfordTown_House2/scripts.pory"
	.string "all this and helping me arrive safely!\p"
# 246 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Let me give you this as a thank you.$"
# 247 "data//maps/DewfordTown_House2/scripts.pory"

# 248 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_WantYouToHaveSilkScarf:
# 249 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Gorge your eyes on this!\p"
# 250 "data//maps/DewfordTown_House2/scripts.pory"
	.string "It's a SILK SCARF. It's right at the\n"
# 251 "data//maps/DewfordTown_House2/scripts.pory"
	.string "cutting edge of fashion, yeah!\p"
# 252 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Oh, I can see your eyes twinkling!\n"
# 253 "data//maps/DewfordTown_House2/scripts.pory"
	.string "You appreciate my dazzling style!\p"
# 254 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you're a delight!\n"
# 255 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Here you go. I want you to have it!$"
# 256 "data//maps/DewfordTown_House2/scripts.pory"

# 257 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_NoRoom:
# 258 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you don't have room?\p"
# 259 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Now, listen tight, this SCARF is a must-\n"
# 260 "data//maps/DewfordTown_House2/scripts.pory"
	.string "have! Why, I would sell all my items\l"
# 261 "data//maps/DewfordTown_House2/scripts.pory"
	.string "in order to get it!$"
# 262 "data//maps/DewfordTown_House2/scripts.pory"

# 263 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_Man1:
# 264 "data//maps/DewfordTown_House2/scripts.pory"
	.string "It's just me and my son living here.\p"
# 265 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Sometimes I worry there isn't a wide\n"
# 266 "data//maps/DewfordTown_House2/scripts.pory"
	.string "enough variety of opportunities and\l"
# 267 "data//maps/DewfordTown_House2/scripts.pory"
	.string "role models here for the boy…\p"
# 268 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Especially as he grows!\p"
# 269 "data//maps/DewfordTown_House2/scripts.pory"
	.string "I think moving somewhere more\n"
# 270 "data//maps/DewfordTown_House2/scripts.pory"
	.string "developed might be good for him.$" 
# 271 "data//maps/DewfordTown_House2/scripts.pory"

# 272 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_SwapScene4:
# 273 "data//maps/DewfordTown_House2/scripts.pory"
	.string "SINGLE DAD: Well son, we should\n"
# 274 "data//maps/DewfordTown_House2/scripts.pory"
	.string "get going!$"
# 275 "data//maps/DewfordTown_House2/scripts.pory"

# 276 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_SwapScene5:
# 277 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Come visit us in MAUVILLE sometime!\l"
# 278 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Goodbye!$"
# 279 "data//maps/DewfordTown_House2/scripts.pory"

# 280 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_ExplainSilkScarf:
# 281 "data//maps/DewfordTown_House2/scripts.pory"
	.string "The SILK SCARF raises the power of\n"
# 282 "data//maps/DewfordTown_House2/scripts.pory"
	.string "NORMAL-type moves.\p"
# 283 "data//maps/DewfordTown_House2/scripts.pory"
	.string "It's a marvelous SCARF that will go\n"
# 284 "data//maps/DewfordTown_House2/scripts.pory"
	.string "with almost all POKéMON!$"
# 285 "data//maps/DewfordTown_House2/scripts.pory"

# 286 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_NewResident:	
# 287 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Oh it's you!\p"
# 288 "data//maps/DewfordTown_House2/scripts.pory"
	.string "How have I been enjoying my life\n"
# 289 "data//maps/DewfordTown_House2/scripts.pory"
	.string "here in DEWFORD TOWN?\p"
# 290 "data//maps/DewfordTown_House2/scripts.pory"
	.string "It's fantastic!\n"
# 291 "data//maps/DewfordTown_House2/scripts.pory"
	.string "The night sky is so full of stars.\p"
# 292 "data//maps/DewfordTown_House2/scripts.pory"
	.string "And I can get lost exploring GRANITE\n"
# 293 "data//maps/DewfordTown_House2/scripts.pory"
	.string "CAVE anytime!$"
# 294 "data//maps/DewfordTown_House2/scripts.pory"

# 295 "data//maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_BrawlySoCool:
# 296 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Wow, you bothered to cross the sea\n"
# 297 "data//maps/DewfordTown_House2/scripts.pory"
	.string "to visit DEWFORD?\p"
# 298 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Did you maybe come here because you\n"
# 299 "data//maps/DewfordTown_House2/scripts.pory"
	.string "heard about BRAWLY?\p"
# 300 "data//maps/DewfordTown_House2/scripts.pory"
	.string "He's so cool…\n"
# 301 "data//maps/DewfordTown_House2/scripts.pory"
	.string "Everyone idolizes him.$"
