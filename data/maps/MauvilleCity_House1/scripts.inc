# 1 "data//maps/MauvilleCity_House1/scripts.pory"

# 2 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_MapScripts::
# 3 "data//maps/MauvilleCity_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_House1_OnTransition
# 4 "data//maps/MauvilleCity_House1/scripts.pory"
	.byte 0
# 5 "data//maps/MauvilleCity_House1/scripts.pory"

# 6 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_OnTransition:
# 7 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_le VAR_FLASH_QUEST_STATE, 1, MauvilleCity_House1_EventScript_SetScientist
# 8 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_ge VAR_FLASH_QUEST_STATE, 2, MauvilleCity_House1_EventScript_SetHiker
# 9 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_FLASH_QUEST_STATE, 3, MauvilleCity_House1_EventScript_TryResetAfterFailed
# 10 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_ge VAR_FLASH_QUEST_STATE, 5, MauvilleCity_House1_EventScript_ShowNewResidents
# 11 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 12 "data//maps/MauvilleCity_House1/scripts.pory"

# 13 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_SetScientist::
# 14 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCIENTIST_1
# 15 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 16 "data//maps/MauvilleCity_House1/scripts.pory"

# 17 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_SetHiker::
# 18 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HIKER
# 19 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 20 "data//maps/MauvilleCity_House1/scripts.pory"

# 21 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ShowNewResidents::
# 22 "data//maps/MauvilleCity_House1/scripts.pory"
	clearflag FLAG_FLASH_GUY
# 23 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_3
# 24 "data//maps/MauvilleCity_House1/scripts.pory"
	setobjectxyperm LOCALID_MOVED_SON, 1, 3
# 25 "data//maps/MauvilleCity_House1/scripts.pory"
	setobjectmovementtype LOCALID_MOVED_SON, MOVEMENT_TYPE_LOOK_AROUND
# 26 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 27 "data//maps/MauvilleCity_House1/scripts.pory"

# 28 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_TryResetAfterFailed::
# 29 "data//maps/MauvilleCity_House1/scripts.pory"
	checkfollowernpc
# 30 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, MauvilleCity_House1_EventScript_ResetAfterFailed
# 31 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 32 "data//maps/MauvilleCity_House1/scripts.pory"

# 33 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ResetAfterFailed::
# 34 "data//maps/MauvilleCity_House1/scripts.pory"
	clearflag FLAG_FLASH_GUY
# 35 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 36 "data//maps/MauvilleCity_House1/scripts.pory"

# 37 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_Boy::
# 38 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_WattsonSoCool, MSGBOX_NPC
# 39 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 40 "data//maps/MauvilleCity_House1/scripts.pory"

# 41 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_RockSmashDude::
# 42 "data//maps/MauvilleCity_House1/scripts.pory"
	lock
# 43 "data//maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 44 "data//maps/MauvilleCity_House1/scripts.pory"
	call MauvilleCity_House1_EventScript_ReceivedRockSmash
# 45 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
# 46 "data//maps/MauvilleCity_House1/scripts.pory"
	giveitem ITEM_HM_ROCK_SMASH
# 47 "data//maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
# 48 "data//maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
# 49 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
# 50 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 51 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 52 "data//maps/MauvilleCity_House1/scripts.pory"

# 53 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ReceivedRockSmash::
# 54 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
# 55 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 56 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 57 "data//maps/MauvilleCity_House1/scripts.pory"

# 58 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_MovedDad::
# 59 "data//maps/MauvilleCity_House1/scripts.pory"
	lock
# 60 "data//maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 61 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_set FLAG_RECEIVED_SILK_SCARF, MauvilleCity_House1_EventScript_ExplainSilkScarf
# 62 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
# 63 "data//maps/MauvilleCity_House1/scripts.pory"
	giveitem ITEM_SILK_SCARF
# 64 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_House1_EventScript_NoRoomForScarf
# 65 "data//maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_SILK_SCARF
# 66 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 67 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 68 "data//maps/MauvilleCity_House1/scripts.pory"

# 69 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ExplainSilkScarf::
# 70 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ExplainSilkScarf, MSGBOX_DEFAULT
# 71 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 72 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 73 "data//maps/MauvilleCity_House1/scripts.pory"

# 74 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_NoRoomForScarf::
# 75 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_NoRoom, MSGBOX_DEFAULT
# 76 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 77 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 78 "data//maps/MauvilleCity_House1/scripts.pory"

# 79 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuy::
# 80 "data//maps/MauvilleCity_House1/scripts.pory"
	lock
# 81 "data//maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 82 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_ge VAR_FLASH_QUEST_STATE, 5, MauvilleCity_House1_EventScript_MovedDad
# 83 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_FLASH_QUEST_STATE, 2, MauvilleCity_House1_EventScript_FlashGuyReadyToLeave
# 84 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_FLASH_QUEST_STATE, 3, MauvilleCity_House1_EventScript_FlashGuyReadyAfterFailed
# 85 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuy1, MSGBOX_DEFAULT
# 86 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuy2, MSGBOX_YESNO
# 87 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House1_EventScript_FlashGuyYouSaidNo
# 88 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_le VAR_FLASH_QUEST_STATE, 0, MauvilleCity_House1_EventScript_FlashGuyHopes
# 89 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmessage
# 90 "data//maps/MauvilleCity_House1/scripts.pory"
	waitse
# 91 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_ExclamationMark
# 92 "data//maps/MauvilleCity_House1/scripts.pory"
	playse SE_PIN
# 93 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 94 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 5
# 95 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyYouDo, MSGBOX_DEFAULT
# 96 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuySomeoneIsMoving, MSGBOX_DEFAULT
# 97 "data//maps/MauvilleCity_House1/scripts.pory"
	closemessage
# 98 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 15
# 99 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_FaceAwayPlayer
# 100 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 101 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 15
# 102 "data//maps/MauvilleCity_House1/scripts.pory"
	getobjectfacingdirection LOCALID_FLASHGUY, VAR_RESULT
# 103 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_NORTH, MauvilleCity_House1_EventScript_WalkInPlaceNorth
# 104 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_House1_EventScript_WalkInPlaceSouth
# 105 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_House1_EventScript_WalkInPlaceEast
# 106 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_House1_EventScript_WalkInPlaceWest
# 107 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyDewford, MSGBOX_DEFAULT
# 108 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmessage
# 109 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_FacePlayer
# 110 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 111 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 15
# 112 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_ExclamationMark
# 113 "data//maps/MauvilleCity_House1/scripts.pory"
	playse SE_PIN
# 114 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 115 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 5
# 116 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyTakeMeThere, MSGBOX_DEFAULT
# 117 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmessage
# 118 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 15
# 119 "data//maps/MauvilleCity_House1/scripts.pory"
	getobjectfacingdirection LOCALID_FLASHGUY, VAR_RESULT
# 120 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_NORTH, MauvilleCity_House1_EventScript_WalkInPlaceNorth
# 121 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_House1_EventScript_WalkInPlaceSouth
# 122 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_House1_EventScript_WalkInPlaceEast
# 123 "data//maps/MauvilleCity_House1/scripts.pory"
	call_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_House1_EventScript_WalkInPlaceWest
# 124 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyTakeMeThere2, MSGBOX_YESNO
# 125 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House1_EventScript_FlashGuyHopes2
# 126 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyPrepare, MSGBOX_DEFAULT
# 127 "data//maps/MauvilleCity_House1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 128 "data//maps/MauvilleCity_House1/scripts.pory"
	removeobject LOCALID_FLASHGUY
# 129 "data//maps/MauvilleCity_House1/scripts.pory"
	closemessage
# 130 "data//maps/MauvilleCity_House1/scripts.pory"
	delay 60
# 131 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HIKER
# 132 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_FLASH_QUEST_STATE, 2
# 133 "data//maps/MauvilleCity_House1/scripts.pory"
	addobject LOCALID_FLASHGUY
# 134 "data//maps/MauvilleCity_House1/scripts.pory"
	clearflag FLAG_FLASH_GUY
# 135 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_FacePlayer
# 136 "data//maps/MauvilleCity_House1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 137 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_FLASH_QUEST_STATE, 2, MauvilleCity_House1_EventScript_FlashGuyReadyToLeave
# 138 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 139 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 140 "data//maps/MauvilleCity_House1/scripts.pory"

# 141 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_WalkInPlaceNorth::
# 142 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_WalkInPlaceUp
# 143 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 144 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 145 "data//maps/MauvilleCity_House1/scripts.pory"

# 146 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_WalkInPlaceSouth::
# 147 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_WalkInPlaceDown
# 148 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 149 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 150 "data//maps/MauvilleCity_House1/scripts.pory"

# 151 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_WalkInPlaceEast::
# 152 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_WalkInPlaceRight
# 153 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 154 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 155 "data//maps/MauvilleCity_House1/scripts.pory"

# 156 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_WalkInPlaceWest::
# 157 "data//maps/MauvilleCity_House1/scripts.pory"
	applymovement LOCALID_FLASHGUY, Common_Movement_WalkInPlaceLeft
# 158 "data//maps/MauvilleCity_House1/scripts.pory"
	waitmovement 0
# 159 "data//maps/MauvilleCity_House1/scripts.pory"
	return
# 160 "data//maps/MauvilleCity_House1/scripts.pory"

# 161 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyReadyToLeave::
# 162 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyReadyToLeave, MSGBOX_YESNO
# 163 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House1_EventScript_FlashGuyWhenReadyToLeave
# 164 "data//maps/MauvilleCity_House1/scripts.pory"
	setfollowernpc LOCALID_FLASHGUY, FNPC_LEAVE_WHITEOUT, MauvilleCity_House1_EventScript_FlashGuyFollowing
# 165 "data//maps/MauvilleCity_House1/scripts.pory"
	facefollowernpc
# 166 "data//maps/MauvilleCity_House1/scripts.pory"
	setvar VAR_FLASH_QUEST_STATE, 3
# 167 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyLetsGo, MSGBOX_DEFAULT
# 168 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 169 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 170 "data//maps/MauvilleCity_House1/scripts.pory"

# 171 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyReadyAfterFailed::
# 172 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyReadyAfterFailed, MSGBOX_YESNO
# 173 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House1_EventScript_FlashGuyWhenReadyToLeave
# 174 "data//maps/MauvilleCity_House1/scripts.pory"
	setfollowernpc LOCALID_FLASHGUY, FNPC_LEAVE_WHITEOUT, MauvilleCity_House1_EventScript_FlashGuyFollowing
# 175 "data//maps/MauvilleCity_House1/scripts.pory"
	facefollowernpc
# 176 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyLetsGo, MSGBOX_DEFAULT
# 177 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 178 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 179 "data//maps/MauvilleCity_House1/scripts.pory"

# 180 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyFollowing::
# 181 "data//maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 182 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyDewfordIsFar, MSGBOX_YESNO
# 183 "data//maps/MauvilleCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House1_EventScript_FollowingFlashGuyLeaves
# 184 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyLetsGoShort, MSGBOX_DEFAULT
# 185 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 186 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 187 "data//maps/MauvilleCity_House1/scripts.pory"

# 188 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FollowingFlashGuyLeaves::
# 189 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyStopsFollowing, MSGBOX_DEFAULT
# 190 "data//maps/MauvilleCity_House1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 191 "data//maps/MauvilleCity_House1/scripts.pory"
	destroyfollowernpc
# 192 "data//maps/MauvilleCity_House1/scripts.pory"
	warpinplace
# 193 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 194 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 195 "data//maps/MauvilleCity_House1/scripts.pory"

# 196 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyYouSaidNo::
# 197 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyYouSaidNo, MSGBOX_DEFAULT
# 198 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 199 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 200 "data//maps/MauvilleCity_House1/scripts.pory"

# 201 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyHopes::
# 202 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyHopes, MSGBOX_DEFAULT
# 203 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 204 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 205 "data//maps/MauvilleCity_House1/scripts.pory"

# 206 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyHopes2::
# 207 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyHopes2, MSGBOX_DEFAULT
# 208 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 209 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 210 "data//maps/MauvilleCity_House1/scripts.pory"

# 211 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_FlashGuyWhenReadyToLeave::
# 212 "data//maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_FlashGuyWhenReadyToLeave, MSGBOX_DEFAULT
# 213 "data//maps/MauvilleCity_House1/scripts.pory"
	release
# 214 "data//maps/MauvilleCity_House1/scripts.pory"
	end
# 215 "data//maps/MauvilleCity_House1/scripts.pory"

# 216 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyStopsFollowing:
# 217 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Oh…\l"
# 218 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Okay…\l"
# 219 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I guess I'll try and make it\n"
# 220 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "back home by myself…\p"
# 221 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Come find me in MAUVILLE when\n"
# 222 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "you have time…$"
# 223 "data//maps/MauvilleCity_House1/scripts.pory"

# 224 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuy1:
# 225 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I may look like a metropolitan kind\n"
# 226 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "of guy…\p"
# 227 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "The kind of guy who favors modern\n"
# 228 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "comforts…\p"
# 229 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "But the truth is, I've gotten tired\n"
# 230 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "of living here, near the bright lights.\p"
# 231 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "At this point, I wouldn't mind moving\n"
# 232 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "somewhere slower.\p"
# 233 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Somewhere quieter, where at night it\n"
# 234 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "gets truly dark…$"
# 235 "data//maps/MauvilleCity_House1/scripts.pory"

# 236 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuy2:
# 237 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Do you know a place like that?$"
# 238 "data//maps/MauvilleCity_House1/scripts.pory"

# 239 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyYouSaidNo:
# 240 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I hope that someday I can finally get\n"
# 241 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "away from all the lights…$"
# 242 "data//maps/MauvilleCity_House1/scripts.pory"

# 243 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyHopes:
# 244 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Yeah, right!\p"
# 245 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Don't get my hopes up!$"
# 246 "data//maps/MauvilleCity_House1/scripts.pory"

# 247 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyHopes2:
# 248 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Well then don't get my hopes up!$"
# 249 "data//maps/MauvilleCity_House1/scripts.pory"

# 250 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyYouDo:
# 251 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, you do??$"
# 252 "data//maps/MauvilleCity_House1/scripts.pory"

# 253 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuySomeoneIsMoving:
# 254 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "You met someone in DEWFORD who's\n"
# 255 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "looking to move?$"
# 256 "data//maps/MauvilleCity_House1/scripts.pory"

# 257 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyDewford:
# 258 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "DEWFORD is pretty remote…\p"
# 259 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "And I've heard GRANITE CAVE is one\n"
# 260 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "of the darkest places in HOENN…$"
# 261 "data//maps/MauvilleCity_House1/scripts.pory"

# 262 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyTakeMeThere:
# 263 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I know!\p"
# 264 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I'll offer to trade my house here in\n"
# 265 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "MAUVILLE for their place in DEWFORD!\p"
# 266 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "After all, MAUVILLE CITY is a great\n"
# 267 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "location in a lot of ways!\p"
# 268 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "But DEWFORD is far away…$"
# 269 "data//maps/MauvilleCity_House1/scripts.pory"

# 270 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyTakeMeThere2:
# 271 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "You're a trainer,\n"
# 272 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "and you already know the way…\p"
# 273 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Will you take me there?\n"
# 274 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Please?$"
# 275 "data//maps/MauvilleCity_House1/scripts.pory"

# 276 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyPrepare:
# 277 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "The moment I've been dreaming of!\p"
# 278 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Wait right there, I only need a moment\n" 
# 279 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "to prepare!$"
# 280 "data//maps/MauvilleCity_House1/scripts.pory"

# 281 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyReadyToLeave:
# 282 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "So are you ready to take me to DEWFORD?$"
# 283 "data//maps/MauvilleCity_House1/scripts.pory"

# 284 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyReadyAfterFailed:
# 285 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Wow, that got pretty scary!\p"
# 286 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Do you think you can take me safely\n"
# 287 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "to DEWFORD now?$"
# 288 "data//maps/MauvilleCity_House1/scripts.pory"

# 289 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyWhenReadyToLeave:
# 290 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Well, let me know when you're\n"
# 291 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "ready to go…$"
# 292 "data//maps/MauvilleCity_House1/scripts.pory"

# 293 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyDewfordIsFar:
# 294 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Wow, DEWFORD TOWN sure is far away…\p"
# 295 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Do you still have time to take me there?$"
# 296 "data//maps/MauvilleCity_House1/scripts.pory"

# 297 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyLetsGo:
# 298 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Well then, let's go!\p"
# 299 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Off to new horizons, unscathed by\n"
# 300 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "modern light polution!$"
# 301 "data//maps/MauvilleCity_House1/scripts.pory"

# 302 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_FlashGuyLetsGoShort:
# 303 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Off we go, to new horizons!$"
# 304 "data//maps/MauvilleCity_House1/scripts.pory"

# 305 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_WantYouToHaveSilkScarf:
# 306 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Ah, my friend!\p"
# 307 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "MAUVILLE CITY has been treating us\n"
# 308 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "excellently!\p"
# 309 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Since coming here, I've learned just how\n"
# 310 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "out of touch people in DEWFORD were\l"
# 311 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "about modern trends!\p"
# 312 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "For example, gorge your eyes on this!\p"
# 313 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "It's a SILK SCARF. It's right at the\n"
# 314 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "cutting edge of fashion, yeah!\p"
# 315 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, I can see your eyes twinkling!\n"
# 316 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "You appreciate my dazzling style!\p"
# 317 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, you're a delight!\n"
# 318 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Here you go. I want you to have it!\p"
# 319 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Consider it thanks for helping us!$"
# 320 "data//maps/MauvilleCity_House1/scripts.pory"

# 321 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_NoRoom:
# 322 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, you don't have room?\p"
# 323 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Now, listen tight, this SCARF is a must-\n"
# 324 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "have! Why, I would sell all my items\l"
# 325 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "in order to get it!$"
# 326 "data//maps/MauvilleCity_House1/scripts.pory"

# 327 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ExplainSilkScarf:
# 328 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "The SILK SCARF raises the power of\n"
# 329 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "NORMAL-type moves.\p"
# 330 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "It's a marvelous SCARF that will go\n"
# 331 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "with almost all POKéMON!$"
# 332 "data//maps/MauvilleCity_House1/scripts.pory"

# 333 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_WattsonSoCool:
# 334 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "We came all the way across the sea\n"
# 335 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "to live in MAUVILLE CITY\p"
# 336 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "When we got here, I learned about\n"
# 337 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "MAUVILLE's gym leader, WATTSON!\p"
# 338 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "He's so cool…\p"
# 339 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "He can build all kinds of\n"
# 340 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "electronic contraptions!$"
# 341 "data//maps/MauvilleCity_House1/scripts.pory"

# 342 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
# 343 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 344 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I hear people call me the ROCK SMASH\n"
# 345 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "GUY, but I find that sort of degrading.\p"
# 346 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I think I deserve a bit more respect,\n"
# 347 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "like maybe the ROCK SMASH DUDE.\p"
# 348 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 349 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Anyways, your POKéMON look pretty\n"
# 350 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "strong.\p"
# 351 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "I like that!\n"
# 352 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Here, take this HIDDEN MACHINE!$"
# 353 "data//maps/MauvilleCity_House1/scripts.pory"

# 354 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ExplainRockSmash:
# 355 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "That HM contains ROCK SMASH.\p"
# 356 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "If you come across large boulders\n"
# 357 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "that block your path…\p"
# 358 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Well, use that HM move and smash\n"
# 359 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "them right out of your way!\p"
# 360 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Yes, sir! Smash rocks aside, I say!\n"
# 361 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"
# 362 "data//maps/MauvilleCity_House1/scripts.pory"

# 363 "data//maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
# 364 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Hey! If you smash a rock, a POKéMON\n"
# 365 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "could come flying out of hiding.\p"
# 366 "data//maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"
