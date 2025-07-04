# 1 "data//maps/PetalburgCity_House2/scripts.pory"

# 2 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_MapScripts::
# 3 "data//maps/PetalburgCity_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_House2_OnTransition
# 4 "data//maps/PetalburgCity_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_House2_OnFrame
# 5 "data//maps/PetalburgCity_House2/scripts.pory"
	.byte 0
# 6 "data//maps/PetalburgCity_House2/scripts.pory"

# 7 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_OnTransition::
# 8 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, PetalburgCity_House2_EventScript_TrySetupCoinCaseScene
# 9 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 5, PetalburgCity_House2_EventScript_ShowUncle
# 10 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 11 "data//maps/PetalburgCity_House2/scripts.pory"

# 12 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_OnFrame::
# 13 "data//maps/PetalburgCity_House2/scripts.pory"
	map_script_2 VAR_COIN_CASE_QUEST, 4, PetalburgCity_House2_EventScript_CoinCaseScene
# 14 "data//maps/PetalburgCity_House2/scripts.pory"
	.2byte 0
# 15 "data//maps/PetalburgCity_House2/scripts.pory"

# 16 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_ShowUncle::
# 17 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectxy LOCALID_PETALBURG_UNCLE, 9, 3
# 18 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectxyperm LOCALID_PETALBURG_UNCLE, 9, 3
# 19 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectmovementtype LOCALID_PETALBURG_UNCLE, MOVEMENT_TYPE_FACE_DOWN
# 20 "data//maps/PetalburgCity_House2/scripts.pory"
	showobjectat LOCALID_PETALBURG_UNCLE, MAP_PETALBURG_CITY_HOUSE2
# 21 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 22 "data//maps/PetalburgCity_House2/scripts.pory"

# 23 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_TrySetupCoinCaseScene::
# 24 "data//maps/PetalburgCity_House2/scripts.pory"
	getfollowernpc
# 25 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, FLAG_GAME_CORNER_UNC, PetalburgCity_House2_EventScript_SetupCoinCaseScene
# 26 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 27 "data//maps/PetalburgCity_House2/scripts.pory"

# 28 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_SetupCoinCaseScene::
# 29 "data//maps/PetalburgCity_House2/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 4
# 30 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectmovementtype LOCALID_PETALBURG_UNCLE, MOVEMENT_TYPE_FACE_DOWN
# 31 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectmovementtype LOCALID_CRAZY_LADY, MOVEMENT_TYPE_LOOK_AROUND
# 32 "data//maps/PetalburgCity_House2/scripts.pory"
	@ showobjectat LOCALID_PETALBURG_UNCLE, MAP_PETALBURG_CITY_HOUSE2
# 33 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 34 "data//maps/PetalburgCity_House2/scripts.pory"

# 35 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_CoinCaseScene::
# 36 "data//maps/PetalburgCity_House2/scripts.pory"

# 37 "data//maps/PetalburgCity_House2/scripts.pory"
	destroyfollowernpc
# 38 "data//maps/PetalburgCity_House2/scripts.pory"
	addobject LOCALID_PETALBURG_UNCLE
# 39 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, Common_Movement_SetInvisible
# 40 "data//maps/PetalburgCity_House2/scripts.pory"
	setobjectxy LOCALID_PETALBURG_UNCLE, 3, 7
# 41 "data//maps/PetalburgCity_House2/scripts.pory"

# 42 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_House2_Movement_ArriveForSwapScene
# 43 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PLAYER
# 44 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 5
# 45 "data//maps/PetalburgCity_House2/scripts.pory"

# 46 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, Common_Movement_FaceUp
# 47 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement 0
# 48 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, Common_Movement_SetVisible
# 49 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_UNCLE
# 50 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 15
# 51 "data//maps/PetalburgCity_House2/scripts.pory"

# 52 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_ExclamationMark
# 53 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 54 "data//maps/PetalburgCity_House2/scripts.pory"
	playse SE_PIN
# 55 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 5
# 56 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_FaceDown
# 57 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 58 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 10
# 59 "data//maps/PetalburgCity_House2/scripts.pory"

# 60 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgCity_House2_Movement_PlayerPosForSwapScene
# 61 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, PetalburgCity_House2_Movement_FollowerPosForSwapScene1
# 62 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_UNCLE
# 63 "data//maps/PetalburgCity_House2/scripts.pory"

# 64 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_FaceLeft
# 65 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, PetalburgCity_House2_Movement_FollowerPosForSwapScene2
# 66 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_UNCLE
# 67 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 15
# 68 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, PetalburgCity_House2_Movement_NephewApproachUncle
# 69 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 70 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 16
# 71 "data//maps/PetalburgCity_House2/scripts.pory"

# 72 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, PetalburgCity_House2_Movement_NephewReprimandUncle
# 73 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, PetalburgCity_House2_Movement_UncleGetReprimanded
# 74 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 75 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 40
# 76 "data//maps/PetalburgCity_House2/scripts.pory"

# 77 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_WalkInPlaceLeft
# 78 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 79 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 5
# 80 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_UNCLE, PetalburgCity_House2_Movement_UncleGoAway
# 81 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_UNCLE
# 82 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, PetalburgCity_House2_Movement_NephewApproachPlayer
# 83 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 84 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 16
# 85 "data//maps/PetalburgCity_House2/scripts.pory"

# 86 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 87 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NephewThankPlayer1, MSGBOX_DEFAULT
# 88 "data//maps/PetalburgCity_House2/scripts.pory"
	closemessage
# 89 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 20
# 90 "data//maps/PetalburgCity_House2/scripts.pory"

# 91 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_FaceAwayPlayer
# 92 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 93 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 40
# 94 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_FacePlayer
# 95 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 96 "data//maps/PetalburgCity_House2/scripts.pory"

# 97 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 40
# 98 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NephewThankPlayer2, MSGBOX_DEFAULT
# 99 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_WalkInPlaceLeft
# 100 "data//maps/PetalburgCity_House2/scripts.pory"
	waitmovement LOCALID_PETALBURG_NEPHEW
# 101 "data//maps/PetalburgCity_House2/scripts.pory"

# 102 "data//maps/PetalburgCity_House2/scripts.pory"
	giveitem ITEM_COIN_CASE
# 103 "data//maps/PetalburgCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_COIN_CASE
# 104 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NephewThankPlayer3, MSGBOX_DEFAULT
# 105 "data//maps/PetalburgCity_House2/scripts.pory"
	closemessage
# 106 "data//maps/PetalburgCity_House2/scripts.pory"

# 107 "data//maps/PetalburgCity_House2/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 5
# 108 "data//maps/PetalburgCity_House2/scripts.pory"
	releaseall
# 109 "data//maps/PetalburgCity_House2/scripts.pory"

# 110 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 111 "data//maps/PetalburgCity_House2/scripts.pory"

# 112 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_UncleGetReprimanded:
# 113 "data//maps/PetalburgCity_House2/scripts.pory"
	delay_16
# 114 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_right
# 115 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_right
# 116 "data//maps/PetalburgCity_House2/scripts.pory"
	delay_16
# 117 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_right
# 118 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_right
# 119 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 120 "data//maps/PetalburgCity_House2/scripts.pory"

# 121 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_NephewReprimandUncle:
# 122 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_left
# 123 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_left
# 124 "data//maps/PetalburgCity_House2/scripts.pory"
	delay_16
# 125 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_left
# 126 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_faster_left
# 127 "data//maps/PetalburgCity_House2/scripts.pory"
	delay_16
# 128 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_left
# 129 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 130 "data//maps/PetalburgCity_House2/scripts.pory"

# 131 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_UncleGoAway:
# 132 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 133 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 134 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 135 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 136 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 137 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 138 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 139 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_right
# 140 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_down
# 141 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 142 "data//maps/PetalburgCity_House2/scripts.pory"

# 143 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_NephewApproachPlayer:
# 144 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_left
# 145 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 146 "data//maps/PetalburgCity_House2/scripts.pory"

# 147 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_Woman::
# 148 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
# 149 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 150 "data//maps/PetalburgCity_House2/scripts.pory"

# 151 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_CrazyLady::
# 152 "data//maps/PetalburgCity_House2/scripts.pory"
	lock
# 153 "data//maps/PetalburgCity_House2/scripts.pory"
	faceplayer
# 154 "data//maps/PetalburgCity_House2/scripts.pory"
	waitse
# 155 "data//maps/PetalburgCity_House2/scripts.pory"
	playse SE_DEX_SEARCH
# 156 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_CrazyLady, MSGBOX_DEFAULT
# 157 "data//maps/PetalburgCity_House2/scripts.pory"
	waitse
# 158 "data//maps/PetalburgCity_House2/scripts.pory"
	closemessage
# 159 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 30
# 160 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_ShesMutering, MSGBOX_DEFAULT
# 161 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 162 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 163 "data//maps/PetalburgCity_House2/scripts.pory"

# 164 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_SchoolKid::
# 165 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
# 166 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 167 "data//maps/PetalburgCity_House2/scripts.pory"

# 168 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_Nephew::
# 169 "data//maps/PetalburgCity_House2/scripts.pory"
	lock
# 170 "data//maps/PetalburgCity_House2/scripts.pory"
	faceplayer
# 171 "data//maps/PetalburgCity_House2/scripts.pory"

# 172 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 5, PetalburgCity_House2_EventScript_BroughtUncleHome
# 173 "data//maps/PetalburgCity_House2/scripts.pory"

# 174 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 3, PetalburgCity_House2_EventScript_TaskedWithRetrievingUncle
# 175 "data//maps/PetalburgCity_House2/scripts.pory"

# 176 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 2, PetalburgCity_House2_EventScript_TaskedWithRetrievingUncle
# 177 "data//maps/PetalburgCity_House2/scripts.pory"

# 178 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_lt VAR_COIN_CASE_QUEST, 1, PetalburgCity_House2_EventScript_NotMetUncle
# 179 "data//maps/PetalburgCity_House2/scripts.pory"

# 180 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_NephewShort, MSGBOX_DEFAULT
# 181 "data//maps/PetalburgCity_House2/scripts.pory"
	closemessage
# 182 "data//maps/PetalburgCity_House2/scripts.pory"

# 183 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 24
# 184 "data//maps/PetalburgCity_House2/scripts.pory"
	applymovement LOCALID_PETALBURG_NEPHEW, Common_Movement_QuestionMark
# 185 "data//maps/PetalburgCity_House2/scripts.pory"
	playse SE_PIN
# 186 "data//maps/PetalburgCity_House2/scripts.pory"
	waitse
# 187 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 5
# 188 "data//maps/PetalburgCity_House2/scripts.pory"

# 189 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_YouveSeenHim, MSGBOX_YESNO
# 190 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, NO, PetalburgCity_House2_EventScript_OhWell
# 191 "data//maps/PetalburgCity_House2/scripts.pory"

# 192 "data//maps/PetalburgCity_House2/scripts.pory"
	call_if_eq VAR_COIN_CASE_QUEST, 1, PetalburgCity_House2_EventScript_RetrieveUncle
# 193 "data//maps/PetalburgCity_House2/scripts.pory"

# 194 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_SoNice, MSGBOX_DEFAULT
# 195 "data//maps/PetalburgCity_House2/scripts.pory"

# 196 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 197 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 198 "data//maps/PetalburgCity_House2/scripts.pory"

# 199 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_BroughtUncleHome::
# 200 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_BroughtUncleHome, MSGBOX_DEFAULT
# 201 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 202 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 203 "data//maps/PetalburgCity_House2/scripts.pory"

# 204 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_Uncle::
# 205 "data//maps/PetalburgCity_House2/scripts.pory"
	lock
# 206 "data//maps/PetalburgCity_House2/scripts.pory"
	@ faceplayer
# 207 "data//maps/PetalburgCity_House2/scripts.pory"
	waitse
# 208 "data//maps/PetalburgCity_House2/scripts.pory"
	playse SE_M_SNORE
# 209 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_Uncle, MSGBOX_DEFAULT
# 210 "data//maps/PetalburgCity_House2/scripts.pory"
	waitse
# 211 "data//maps/PetalburgCity_House2/scripts.pory"
	closemessage
# 212 "data//maps/PetalburgCity_House2/scripts.pory"
	delay 30
# 213 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_HesSleeping, MSGBOX_DEFAULT
# 214 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 215 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 216 "data//maps/PetalburgCity_House2/scripts.pory"

# 217 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_BroughtUncleHome:
# 218 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "It was such a big help for you to bring\n"
# 219 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "my troublemaker uncle home!\p"
# 220 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "It's so much easier to care for my\n"
# 221 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "aunt when I don't have to worry about\l"
# 222 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "him causing even more problems.$"
# 223 "data//maps/PetalburgCity_House2/scripts.pory"

# 224 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_TaskedWithRetrievingUncle::
# 225 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_HaventFoundHimYet, MSGBOX_DEFAULT
# 226 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 227 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 228 "data//maps/PetalburgCity_House2/scripts.pory"

# 229 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_RetrieveUncle::
# 230 "data//maps/PetalburgCity_House2/scripts.pory"
	setvar VAR_COIN_CASE_QUEST, 2
# 231 "data//maps/PetalburgCity_House2/scripts.pory"
	return
# 232 "data//maps/PetalburgCity_House2/scripts.pory"

# 233 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_NotMetUncle::
# 234 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_Nephew, MSGBOX_DEFAULT
# 235 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 236 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 237 "data//maps/PetalburgCity_House2/scripts.pory"

# 238 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_EventScript_OhWell::
# 239 "data//maps/PetalburgCity_House2/scripts.pory"
	msgbox PetalburgCity_House2_Text_OhWell, MSGBOX_DEFAULT
# 240 "data//maps/PetalburgCity_House2/scripts.pory"
	release
# 241 "data//maps/PetalburgCity_House2/scripts.pory"
	end
# 242 "data//maps/PetalburgCity_House2/scripts.pory"

# 243 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_ArriveForSwapScene:
# 244 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 245 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 246 "data//maps/PetalburgCity_House2/scripts.pory"

# 247 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_PlayerPosForSwapScene:
# 248 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 249 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_left
# 250 "data//maps/PetalburgCity_House2/scripts.pory"
	face_right
# 251 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 252 "data//maps/PetalburgCity_House2/scripts.pory"

# 253 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_FollowerPosForSwapScene1:
# 254 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 255 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 256 "data//maps/PetalburgCity_House2/scripts.pory"

# 257 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_FollowerPosForSwapScene2:
# 258 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_up
# 259 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_in_place_right
# 260 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 261 "data//maps/PetalburgCity_House2/scripts.pory"

# 262 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Movement_NephewApproachUncle:
# 263 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_left
# 264 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_left
# 265 "data//maps/PetalburgCity_House2/scripts.pory"
	walk_left
# 266 "data//maps/PetalburgCity_House2/scripts.pory"
	step_end
# 267 "data//maps/PetalburgCity_House2/scripts.pory"

# 268 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NephewThankPlayer1:
# 269 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Thanks for bringing my uncle back…\p"
# 270 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Hopefully he will just pass out here.\p"
# 271 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "That way I won't have to worry about\n"
# 272 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "him sneaking off again.$"
# 273 "data//maps/PetalburgCity_House2/scripts.pory"

# 274 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NephewThankPlayer2:
# 275 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Hey, you seem like a responsible\n"
# 276 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "person.\p"
# 277 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "If I give this to you, my uncle won't\n"
# 278 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "be able to use it anymore!$"
# 279 "data//maps/PetalburgCity_House2/scripts.pory"

# 280 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NephewThankPlayer3:
# 281 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "You can use that to store coins\n"
# 282 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "for the GAME CORNER.\p" 
# 283 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Thanks, really!\p"
# 284 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "If my uncle wanders off again,\n"
# 285 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "at least I'll know who to call!$"
# 286 "data//maps/PetalburgCity_House2/scripts.pory"

# 287 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_CrazyLady:
# 288 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "… … … … … … … … …\n"
# 289 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "… … … … … … … … …$"
# 290 "data//maps/PetalburgCity_House2/scripts.pory"

# 291 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_ShesMutering:
# 292 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "She's muttering incoherently…$"
# 293 "data//maps/PetalburgCity_House2/scripts.pory"

# 294 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_Uncle:
# 295 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "… … … … … … … … …\n"
# 296 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "… … … … … … … … …$"
# 297 "data//maps/PetalburgCity_House2/scripts.pory"

# 298 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_HesSleeping:
# 299 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "He's sleeping…$"
# 300 "data//maps/PetalburgCity_House2/scripts.pory"

# 301 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_Nephew:
# 302 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Sigh…\p"
# 303 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "My uncle has gone missing…\p"
# 304 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "He probably sneaked off to gamble\n"
# 305 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "in MAUVILLE CITY again…\p"
# 306 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "He could be gone for days,\l"
# 307 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "but I have to look after my aunt here,\n"
# 308 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "so I can't go out to retrieve him…\p"
# 309 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I just hope he doesn't get into any\n"
# 310 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "danger out on the road…$"
# 311 "data//maps/PetalburgCity_House2/scripts.pory"

# 312 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NephewShort:
# 313 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Sigh…\p"
# 314 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "My uncle has gone missing…\p"
# 315 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "He probably sneaked off to gamble\n"
# 316 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "in MAUVILLE CITY again…\p"
# 317 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Sometimes he's gone for days, but\n"
# 318 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I have to look after my aunt here,\l"
# 319 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "so I can't go out to retrieve him…$"
# 320 "data//maps/PetalburgCity_House2/scripts.pory"

# 321 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_YouveSeenHim:
# 322 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "What?\n"
# 323 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "You've seen him??\p"
# 324 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Well since you can get to MAUVILLE\n"
# 325 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "and back, would you be willing\l"
# 326 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "to retrieve my uncle?\p"
# 327 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "It would be a huge help to me and\n"
# 328 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "my aunt…$"
# 329 "data//maps/PetalburgCity_House2/scripts.pory"

# 330 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_OhWell:
# 331 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Oh well…\p"
# 332 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I just hope he doesn't get into any\n"
# 333 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "danger out on the road…$"
# 334 "data//maps/PetalburgCity_House2/scripts.pory"

# 335 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_SoNice:
# 336 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Wow, that's so nice of you!\p"
# 337 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I hope he's not too much trouble\n"
# 338 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "to wrangle!$"
# 339 "data//maps/PetalburgCity_House2/scripts.pory"

# 340 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_HaventFoundHimYet:
# 341 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "Have you found my uncle yet?\p"
# 342 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I think he's on a gambling binge\n"
# 343 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "in MAUVILLE CITY…\p"
# 344 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I just hope he doesn't get into any\n"
# 345 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "danger…$"
# 346 "data//maps/PetalburgCity_House2/scripts.pory"

# 347 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_NormanBecameGymLeader:
# 348 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "NORMAN became our town's new\n"
# 349 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "GYM LEADER.\p"
# 350 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I think he called his family over from\n"
# 351 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "somewhere far away.$"
# 352 "data//maps/PetalburgCity_House2/scripts.pory"

# 353 "data//maps/PetalburgCity_House2/scripts.pory"
PetalburgCity_House2_Text_BattledNormanOnce:
# 354 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I battled NORMAN once, but, whew,\n"
# 355 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "he was way too strong.\p"
# 356 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "How would I put it?\p"
# 357 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "I just got the feeling that he\n"
# 358 "data//maps/PetalburgCity_House2/scripts.pory"
	.string "lives for POKéMON.$"
