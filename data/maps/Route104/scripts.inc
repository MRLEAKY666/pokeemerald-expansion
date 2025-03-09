# 1 "data//maps/Route104/scripts.pory"

# 2 "data//maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 3 "data//maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data//maps/Route104/scripts.pory"
.set LOCALID_RIVAL, 34
# 5 "data//maps/Route104/scripts.pory"

# 6 "data//maps/Route104/scripts.pory"
Route104_MapScripts::
# 7 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 8 "data//maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 9 "data//maps/Route104/scripts.pory"
	.byte 0
# 10 "data//maps/Route104/scripts.pory"

# 11 "data//maps/Route104/scripts.pory"
Route104_OnFrame:
# 12 "data//maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 13 "data//maps/Route104/scripts.pory"
	.2byte 0
# 14 "data//maps/Route104/scripts.pory"

# 15 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 16 "data//maps/Route104/scripts.pory"
	lockall
# 17 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 18 "data//maps/Route104/scripts.pory"
	end
# 19 "data//maps/Route104/scripts.pory"

# 20 "data//maps/Route104/scripts.pory"
Route104_OnTransition:
# 21 "data//maps/Route104/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 22 "data//maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 23 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 24 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 25 "data//maps/Route104/scripts.pory"
	end
# 26 "data//maps/Route104/scripts.pory"

# 27 "data//maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 28 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 29 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 30 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 31 "data//maps/Route104/scripts.pory"
	return
# 32 "data//maps/Route104/scripts.pory"

# 33 "data//maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 34 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 35 "data//maps/Route104/scripts.pory"
	return
# 36 "data//maps/Route104/scripts.pory"

# 37 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 38 "data//maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 39 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 40 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 41 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 17, 52
# 42 "data//maps/Route104/scripts.pory"
	return
# 43 "data//maps/Route104/scripts.pory"

# 44 "data//maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 45 "data//maps/Route104/scripts.pory"
	return
# 46 "data//maps/Route104/scripts.pory"

# 47 "data//maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 48 "data//maps/Route104/scripts.pory"
	lockall
# 49 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 50 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 51 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 52 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 53 "data//maps/Route104/scripts.pory"

# 54 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 55 "data//maps/Route104/scripts.pory"
	lockall
# 56 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 57 "data//maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 58 "data//maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 59 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 60 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 61 "data//maps/Route104/scripts.pory"
	delay 10
# 62 "data//maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL
# 63 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 64 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 65 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 66 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 67 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 68 "data//maps/Route104/scripts.pory"
	delay 20
# 69 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 70 "data//maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 71 "data//maps/Route104/scripts.pory"
	playse SE_PIN
# 72 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 73 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 74 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 75 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 76 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 77 "data//maps/Route104/scripts.pory"

# 78 "data//maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 79 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 80 "data//maps/Route104/scripts.pory"
	checkplayergender
# 81 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 82 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 83 "data//maps/Route104/scripts.pory"
	return
# 84 "data//maps/Route104/scripts.pory"

# 85 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 86 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 87 "data//maps/Route104/scripts.pory"
	return
# 88 "data//maps/Route104/scripts.pory"

# 89 "data//maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 90 "data//maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 91 "data//maps/Route104/scripts.pory"
	return
# 92 "data//maps/Route104/scripts.pory"

# 93 "data//maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 94 "data//maps/Route104/scripts.pory"
	checkplayergender
# 95 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 96 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 97 "data//maps/Route104/scripts.pory"
	end
# 98 "data//maps/Route104/scripts.pory"

# 99 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 100 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 101 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 102 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 103 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 104 "data//maps/Route104/scripts.pory"
	closemessage
# 105 "data//maps/Route104/scripts.pory"
	delay 30
# 106 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 107 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 108 "data//maps/Route104/scripts.pory"
	waitfanfare
# 109 "data//maps/Route104/scripts.pory"
	closemessage
# 110 "data//maps/Route104/scripts.pory"
	delay 30
# 111 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 112 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 113 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 114 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 115 "data//maps/Route104/scripts.pory"
	closemessage
# 116 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 117 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 118 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 119 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 120 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 121 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 122 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 123 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 124 "data//maps/Route104/scripts.pory"
	releaseall
# 125 "data//maps/Route104/scripts.pory"
	end
# 126 "data//maps/Route104/scripts.pory"

# 127 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 128 "data//maps/Route104/scripts.pory"
	walk_slow_left
# 129 "data//maps/Route104/scripts.pory"
	step_end
# 130 "data//maps/Route104/scripts.pory"

# 131 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 132 "data//maps/Route104/scripts.pory"
	walk_down
# 133 "data//maps/Route104/scripts.pory"
	face_right
# 134 "data//maps/Route104/scripts.pory"
	step_end
# 135 "data//maps/Route104/scripts.pory"

# 136 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 137 "data//maps/Route104/scripts.pory"
	delay_4
# 138 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 139 "data//maps/Route104/scripts.pory"
	step_end
# 140 "data//maps/Route104/scripts.pory"

# 141 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 142 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 143 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 144 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 145 "data//maps/Route104/scripts.pory"
	releaseall
# 146 "data//maps/Route104/scripts.pory"
	end
# 147 "data//maps/Route104/scripts.pory"

# 148 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 149 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 150 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 151 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_StartMayBattle
# 152 "data//maps/Route104/scripts.pory"
	end
# 153 "data//maps/Route104/scripts.pory"

# 154 "data//maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 155 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 156 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 157 "data//maps/Route104/scripts.pory"
	releaseall
# 158 "data//maps/Route104/scripts.pory"
	end
# 159 "data//maps/Route104/scripts.pory"

# 160 "data//maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 161 "data//maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 162 "data//maps/Route104/scripts.pory"
	fadedefaultbgm
# 163 "data//maps/Route104/scripts.pory"
	return
# 164 "data//maps/Route104/scripts.pory"

# 165 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartMayBattle::
# 166 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_A, Route104_Text_MayDefeat
# 167 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 168 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 169 "data//maps/Route104/scripts.pory"
	end
# 170 "data//maps/Route104/scripts.pory"

# 171 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 172 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 173 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 174 "data//maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 175 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 176 "data//maps/Route104/scripts.pory"
	closemessage
# 177 "data//maps/Route104/scripts.pory"
	delay 30
# 178 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 179 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 180 "data//maps/Route104/scripts.pory"
	waitfanfare
# 181 "data//maps/Route104/scripts.pory"
	closemessage
# 182 "data//maps/Route104/scripts.pory"
	delay 30
# 183 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 184 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 185 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 186 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 187 "data//maps/Route104/scripts.pory"
	closemessage
# 188 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 189 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 190 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 191 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 192 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 193 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 194 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 195 "data//maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 196 "data//maps/Route104/scripts.pory"
	releaseall
# 197 "data//maps/Route104/scripts.pory"
	end
# 198 "data//maps/Route104/scripts.pory"

# 199 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 200 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 201 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 202 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 203 "data//maps/Route104/scripts.pory"
	releaseall
# 204 "data//maps/Route104/scripts.pory"
	end
# 205 "data//maps/Route104/scripts.pory"

# 206 "data//maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 207 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 208 "data//maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 209 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_StartBrendanBattle
# 210 "data//maps/Route104/scripts.pory"
	end
# 211 "data//maps/Route104/scripts.pory"

# 212 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 213 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 214 "data//maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 215 "data//maps/Route104/scripts.pory"
	releaseall
# 216 "data//maps/Route104/scripts.pory"
	end
# 217 "data//maps/Route104/scripts.pory"

# 218 "data//maps/Route104/scripts.pory"
Route104_EventScript_StartBrendanBattle::
# 219 "data//maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_A, Route104_Text_BrendanDefeat
# 220 "data//maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 221 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 222 "data//maps/Route104/scripts.pory"
	end
# 223 "data//maps/Route104/scripts.pory"

# 224 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 225 "data//maps/Route104/scripts.pory"
	lock_facing_direction
# 226 "data//maps/Route104/scripts.pory"
	walk_down
# 227 "data//maps/Route104/scripts.pory"
	unlock_facing_direction
# 228 "data//maps/Route104/scripts.pory"
	step_end
# 229 "data//maps/Route104/scripts.pory"

# 230 "data//maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 231 "data//maps/Route104/scripts.pory"
	walk_down
# 232 "data//maps/Route104/scripts.pory"
	step_end
# 233 "data//maps/Route104/scripts.pory"

# 234 "data//maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 235 "data//maps/Route104/scripts.pory"
	lock
# 236 "data//maps/Route104/scripts.pory"
	faceplayer
# 237 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 238 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 239 "data//maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 240 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 241 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 242 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 243 "data//maps/Route104/scripts.pory"
	release
# 244 "data//maps/Route104/scripts.pory"
	end
# 245 "data//maps/Route104/scripts.pory"

# 246 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 247 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 248 "data//maps/Route104/scripts.pory"
	release
# 249 "data//maps/Route104/scripts.pory"
	end
# 250 "data//maps/Route104/scripts.pory"

# 251 "data//maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 252 "data//maps/Route104/scripts.pory"
	lock
# 253 "data//maps/Route104/scripts.pory"
	faceplayer
# 254 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 255 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 256 "data//maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 257 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 258 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 259 "data//maps/Route104/scripts.pory"
	release
# 260 "data//maps/Route104/scripts.pory"
	end
# 261 "data//maps/Route104/scripts.pory"

# 262 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 263 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 264 "data//maps/Route104/scripts.pory"
	release
# 265 "data//maps/Route104/scripts.pory"
	end
# 266 "data//maps/Route104/scripts.pory"

# 267 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 268 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 269 "data//maps/Route104/scripts.pory"
	end
# 270 "data//maps/Route104/scripts.pory"

# 271 "data//maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 272 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 273 "data//maps/Route104/scripts.pory"
	end
# 274 "data//maps/Route104/scripts.pory"

# 275 "data//maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 276 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 277 "data//maps/Route104/scripts.pory"
	end
# 278 "data//maps/Route104/scripts.pory"

# 279 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 280 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 281 "data//maps/Route104/scripts.pory"
	end
# 282 "data//maps/Route104/scripts.pory"

# 283 "data//maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 284 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 285 "data//maps/Route104/scripts.pory"
	end
# 286 "data//maps/Route104/scripts.pory"

# 287 "data//maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 288 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 289 "data//maps/Route104/scripts.pory"
	end
# 290 "data//maps/Route104/scripts.pory"

# 291 "data//maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 292 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 293 "data//maps/Route104/scripts.pory"
	end
# 294 "data//maps/Route104/scripts.pory"

# 295 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 296 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 297 "data//maps/Route104/scripts.pory"
	end
# 298 "data//maps/Route104/scripts.pory"

# 299 "data//maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 300 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 301 "data//maps/Route104/scripts.pory"
	end
# 302 "data//maps/Route104/scripts.pory"

# 303 "data//maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 304 "data//maps/Route104/scripts.pory"
	lock
# 305 "data//maps/Route104/scripts.pory"
	faceplayer
# 306 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 307 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 308 "data//maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED, 2
# 309 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 310 "data//maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 311 "data//maps/Route104/scripts.pory"
	release
# 312 "data//maps/Route104/scripts.pory"
	end
# 313 "data//maps/Route104/scripts.pory"

# 314 "data//maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 315 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 316 "data//maps/Route104/scripts.pory"
	release
# 317 "data//maps/Route104/scripts.pory"
	end
# 318 "data//maps/Route104/scripts.pory"

# 319 "data//maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 320 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 321 "data//maps/Route104/scripts.pory"
	end
# 322 "data//maps/Route104/scripts.pory"

# 323 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 324 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 325 "data//maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 326 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
# 327 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 328 "data//maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 329 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 330 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 331 "data//maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 332 "data//maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 333 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 334 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 335 "data//maps/Route104/scripts.pory"
	end
# 336 "data//maps/Route104/scripts.pory"

# 337 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 338 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
# 339 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 340 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 341 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 342 "data//maps/Route104/scripts.pory"

# 343 "data//maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 344 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
# 345 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 346 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 347 "data//maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 348 "data//maps/Route104/scripts.pory"
	waitmessage
# 349 "data//maps/Route104/scripts.pory"
	delay 30
# 350 "data//maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 351 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 352 "data//maps/Route104/scripts.pory"
	waitfanfare
# 353 "data//maps/Route104/scripts.pory"
	closemessage
# 354 "data//maps/Route104/scripts.pory"
	delay 30
# 355 "data//maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 356 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 357 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 358 "data//maps/Route104/scripts.pory"
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
# 359 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 360 "data//maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 361 "data//maps/Route104/scripts.pory"

# 362 "data//maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 363 "data//maps/Route104/scripts.pory"
	delay 50
# 364 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 365 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 366 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 367 "data//maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 368 "data//maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 369 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 370 "data//maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 371 "data//maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 372 "data//maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 373 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 374 "data//maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 375 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 376 "data//maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 377 "data//maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 378 "data//maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 379 "data//maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 380 "data//maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 381 "data//maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 382 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 383 "data//maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 384 "data//maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 385 "data//maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 386 "data//maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 387 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 388 "data//maps/Route104/scripts.pory"
	end
# 389 "data//maps/Route104/scripts.pory"

# 390 "data//maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 391 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 392 "data//maps/Route104/scripts.pory"
	releaseall
# 393 "data//maps/Route104/scripts.pory"
	end
# 394 "data//maps/Route104/scripts.pory"

# 395 "data//maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 396 "data//maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 397 "data//maps/Route104/scripts.pory"
	releaseall
# 398 "data//maps/Route104/scripts.pory"
	end
# 399 "data//maps/Route104/scripts.pory"

# 400 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 401 "data//maps/Route104/scripts.pory"
	walk_down
# 402 "data//maps/Route104/scripts.pory"
	walk_down
# 403 "data//maps/Route104/scripts.pory"
	walk_down
# 404 "data//maps/Route104/scripts.pory"
	walk_down
# 405 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 406 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 407 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 408 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 409 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 410 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 411 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 412 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 413 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 414 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 415 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 416 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 417 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 418 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 419 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 420 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 421 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 422 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 423 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 424 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 425 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 426 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 427 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 428 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 429 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 430 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 431 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 432 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 433 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 434 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 435 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 436 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 437 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 438 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 439 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 440 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 441 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 442 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 443 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 444 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 445 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 446 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 447 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 448 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 449 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 450 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 451 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 452 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 453 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 454 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 455 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 456 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 457 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 458 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 459 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 460 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 461 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 462 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 463 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 464 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 465 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 466 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 467 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 468 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 469 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 470 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 471 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 472 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 473 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 474 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 475 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 476 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 477 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 478 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 479 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 480 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 481 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 482 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 483 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 484 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 485 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 486 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 487 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 488 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 489 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 490 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 491 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 492 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 493 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 494 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 495 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 496 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 497 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 498 "data//maps/Route104/scripts.pory"
	step_end
# 499 "data//maps/Route104/scripts.pory"

# 500 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 501 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 502 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 503 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 504 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 505 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 506 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 507 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 508 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 509 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 510 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 511 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 512 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 513 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 514 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 515 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 516 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 517 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 518 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 519 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 520 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 521 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 522 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 523 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 524 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 525 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 526 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 527 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 528 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 529 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 530 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 531 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 532 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 533 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 534 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 535 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 536 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 537 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 538 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 539 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 540 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 541 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 542 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 543 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 544 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 545 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 546 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 547 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 548 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 549 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 550 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 551 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 552 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 553 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 554 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 555 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 556 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 557 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 558 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 559 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 560 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 561 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 562 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 563 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 564 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 565 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 566 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 567 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 568 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 569 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 570 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 571 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 572 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 573 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 574 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 575 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 576 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 577 "data//maps/Route104/scripts.pory"
	walk_right
# 578 "data//maps/Route104/scripts.pory"
	walk_right
# 579 "data//maps/Route104/scripts.pory"
	walk_down
# 580 "data//maps/Route104/scripts.pory"
	walk_down
# 581 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 582 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 583 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 584 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 585 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 586 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 587 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 588 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 589 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 590 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 591 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 592 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 593 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 594 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 595 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 596 "data//maps/Route104/scripts.pory"
	walk_down
# 597 "data//maps/Route104/scripts.pory"
	walk_down
# 598 "data//maps/Route104/scripts.pory"
	step_end
# 599 "data//maps/Route104/scripts.pory"

# 600 "data//maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 601 "data//maps/Route104/scripts.pory"
	walk_down
# 602 "data//maps/Route104/scripts.pory"
	walk_down
# 603 "data//maps/Route104/scripts.pory"
	walk_down
# 604 "data//maps/Route104/scripts.pory"
	walk_down
# 605 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 606 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 607 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 608 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 609 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 610 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 611 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 612 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 613 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 614 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 615 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 616 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 617 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 618 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 619 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 620 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 621 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 622 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 623 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 624 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 625 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 626 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 627 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 628 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 629 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 630 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 631 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 632 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 633 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 634 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 635 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 636 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 637 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 638 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 639 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 640 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 641 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 642 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 643 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 644 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 645 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 646 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 647 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 648 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 649 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 650 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 651 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 652 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 653 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 654 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 655 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 656 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 657 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 658 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 659 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 660 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 661 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 662 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 663 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 664 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 665 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 666 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 667 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 668 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 669 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 670 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 671 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 672 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 673 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 674 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 675 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 676 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 677 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 678 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 679 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 680 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 681 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 682 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 683 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 684 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 685 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 686 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 687 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 688 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 689 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 690 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 691 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 692 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 693 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 694 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 695 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 696 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 697 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 698 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 699 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 700 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 701 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data//maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 723 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 724 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 725 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 726 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 727 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 728 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 729 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 730 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 731 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 732 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 733 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 734 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 735 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 736 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 737 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 738 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 739 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 740 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 741 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 742 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 743 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 744 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 745 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 746 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 747 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 748 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 749 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 750 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 751 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 752 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 753 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 754 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 755 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 756 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 757 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 758 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 759 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 760 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 761 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 762 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 763 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 764 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 765 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 766 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 767 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 768 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 769 "data//maps/Route104/scripts.pory"
	walk_faster_right
# 770 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 771 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 772 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 773 "data//maps/Route104/scripts.pory"
	walk_fast_right
# 774 "data//maps/Route104/scripts.pory"
	walk_right
# 775 "data//maps/Route104/scripts.pory"
	walk_right
# 776 "data//maps/Route104/scripts.pory"
	walk_down
# 777 "data//maps/Route104/scripts.pory"
	walk_down
# 778 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 779 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 780 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 781 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 782 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 783 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 784 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 785 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 786 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 787 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 788 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 789 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 790 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 791 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 792 "data//maps/Route104/scripts.pory"
	walk_fast_down
# 793 "data//maps/Route104/scripts.pory"
	walk_down
# 794 "data//maps/Route104/scripts.pory"
	walk_down
# 795 "data//maps/Route104/scripts.pory"
	step_end
# 796 "data//maps/Route104/scripts.pory"

# 797 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 798 "data//maps/Route104/scripts.pory"
	walk_left
# 799 "data//maps/Route104/scripts.pory"
	walk_down
# 800 "data//maps/Route104/scripts.pory"
	walk_down
# 801 "data//maps/Route104/scripts.pory"
	step_end
# 802 "data//maps/Route104/scripts.pory"

# 803 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 804 "data//maps/Route104/scripts.pory"
	walk_down
# 805 "data//maps/Route104/scripts.pory"
	step_end
# 806 "data//maps/Route104/scripts.pory"

# 807 "data//maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 808 "data//maps/Route104/scripts.pory"
	walk_down
# 809 "data//maps/Route104/scripts.pory"
	walk_left
# 810 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 811 "data//maps/Route104/scripts.pory"
	step_end
# 812 "data//maps/Route104/scripts.pory"

# 813 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 814 "data//maps/Route104/scripts.pory"
	walk_down
# 815 "data//maps/Route104/scripts.pory"
	walk_down
# 816 "data//maps/Route104/scripts.pory"
	step_end
# 817 "data//maps/Route104/scripts.pory"

# 818 "data//maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 819 "data//maps/Route104/scripts.pory"
	walk_down
# 820 "data//maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 821 "data//maps/Route104/scripts.pory"
	step_end
# 822 "data//maps/Route104/scripts.pory"

# 823 "data//maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 824 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 825 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 826 "data//maps/Route104/scripts.pory"
	end
# 827 "data//maps/Route104/scripts.pory"

# 828 "data//maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 829 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 830 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 831 "data//maps/Route104/scripts.pory"
	end
# 832 "data//maps/Route104/scripts.pory"

# 833 "data//maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 834 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 835 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 836 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 837 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 838 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 839 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 840 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 841 "data//maps/Route104/scripts.pory"
	release
# 842 "data//maps/Route104/scripts.pory"
	end
# 843 "data//maps/Route104/scripts.pory"

# 844 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 845 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 846 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 847 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 848 "data//maps/Route104/scripts.pory"
	release
# 849 "data//maps/Route104/scripts.pory"
	end
# 850 "data//maps/Route104/scripts.pory"

# 851 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 852 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 853 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 854 "data//maps/Route104/scripts.pory"
	release
# 855 "data//maps/Route104/scripts.pory"
	end
# 856 "data//maps/Route104/scripts.pory"

# 857 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 858 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 859 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 860 "data//maps/Route104/scripts.pory"
	release
# 861 "data//maps/Route104/scripts.pory"
	end
# 862 "data//maps/Route104/scripts.pory"

# 863 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 864 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 865 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 866 "data//maps/Route104/scripts.pory"
	release
# 867 "data//maps/Route104/scripts.pory"
	end
# 868 "data//maps/Route104/scripts.pory"

# 869 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 870 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 871 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 872 "data//maps/Route104/scripts.pory"
	end
# 873 "data//maps/Route104/scripts.pory"

# 874 "data//maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 875 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 876 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 877 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 878 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 879 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 880 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 881 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 882 "data//maps/Route104/scripts.pory"
	release
# 883 "data//maps/Route104/scripts.pory"
	end
# 884 "data//maps/Route104/scripts.pory"

# 885 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 886 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 887 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 888 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 889 "data//maps/Route104/scripts.pory"
	release
# 890 "data//maps/Route104/scripts.pory"
	end
# 891 "data//maps/Route104/scripts.pory"

# 892 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 893 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 894 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 895 "data//maps/Route104/scripts.pory"
	release
# 896 "data//maps/Route104/scripts.pory"
	end
# 897 "data//maps/Route104/scripts.pory"

# 898 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 899 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 900 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 901 "data//maps/Route104/scripts.pory"
	release
# 902 "data//maps/Route104/scripts.pory"
	end
# 903 "data//maps/Route104/scripts.pory"

# 904 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 905 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 906 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 907 "data//maps/Route104/scripts.pory"
	release
# 908 "data//maps/Route104/scripts.pory"
	end
# 909 "data//maps/Route104/scripts.pory"

# 910 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 911 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 912 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 913 "data//maps/Route104/scripts.pory"
	end
# 914 "data//maps/Route104/scripts.pory"

# 915 "data//maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 916 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
# 917 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 918 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 919 "data//maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 920 "data//maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 921 "data//maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 922 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 923 "data//maps/Route104/scripts.pory"
	release
# 924 "data//maps/Route104/scripts.pory"
	end
# 925 "data//maps/Route104/scripts.pory"

# 926 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 927 "data//maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 928 "data//maps/Route104/scripts.pory"
	waitmovement 0
# 929 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 930 "data//maps/Route104/scripts.pory"
	release
# 931 "data//maps/Route104/scripts.pory"
	end
# 932 "data//maps/Route104/scripts.pory"

# 933 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 934 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 935 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 936 "data//maps/Route104/scripts.pory"
	release
# 937 "data//maps/Route104/scripts.pory"
	end
# 938 "data//maps/Route104/scripts.pory"

# 939 "data//maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 940 "data//maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 941 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 942 "data//maps/Route104/scripts.pory"
	release
# 943 "data//maps/Route104/scripts.pory"
	end
# 944 "data//maps/Route104/scripts.pory"

# 945 "data//maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 946 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 947 "data//maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 948 "data//maps/Route104/scripts.pory"
	release
# 949 "data//maps/Route104/scripts.pory"
	end
# 950 "data//maps/Route104/scripts.pory"

# 951 "data//maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 952 "data//maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 953 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 954 "data//maps/Route104/scripts.pory"
	end
# 955 "data//maps/Route104/scripts.pory"

# 956 "data//maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 957 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 958 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 959 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 960 "data//maps/Route104/scripts.pory"
	release
# 961 "data//maps/Route104/scripts.pory"
	end
# 962 "data//maps/Route104/scripts.pory"

# 963 "data//maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 964 "data//maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 965 "data//maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 966 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 967 "data//maps/Route104/scripts.pory"
	release
# 968 "data//maps/Route104/scripts.pory"
	end
# 969 "data//maps/Route104/scripts.pory"

# 970 "data//maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 971 "data//maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 972 "data//maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 973 "data//maps/Route104/scripts.pory"
	end
# 974 "data//maps/Route104/scripts.pory"

# 975 "data//maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 976 "data//maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 977 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 978 "data//maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 979 "data//maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 980 "data//maps/Route104/scripts.pory"

# 981 "data//maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 982 "data//maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 983 "data//maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 984 "data//maps/Route104/scripts.pory"
	.string "of the sea?$"
# 985 "data//maps/Route104/scripts.pory"

# 986 "data//maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 987 "data//maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 988 "data//maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 989 "data//maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 990 "data//maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 991 "data//maps/Route104/scripts.pory"

# 992 "data//maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 993 "data//maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 994 "data//maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 995 "data//maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 996 "data//maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 997 "data//maps/Route104/scripts.pory"

# 998 "data//maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 999 "data//maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1000 "data//maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1001 "data//maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1002 "data//maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1003 "data//maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1004 "data//maps/Route104/scripts.pory"

# 1005 "data//maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1006 "data//maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1007 "data//maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1008 "data//maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1009 "data//maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1010 "data//maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1011 "data//maps/Route104/scripts.pory"

# 1012 "data//maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1013 "data//maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1014 "data//maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1015 "data//maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1016 "data//maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1017 "data//maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1018 "data//maps/Route104/scripts.pory"

# 1019 "data//maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1020 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1021 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1022 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1023 "data//maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1024 "data//maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1025 "data//maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1026 "data//maps/Route104/scripts.pory"

# 1027 "data//maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1028 "data//maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1029 "data//maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1030 "data//maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1031 "data//maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1032 "data//maps/Route104/scripts.pory"

# 1033 "data//maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1034 "data//maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1035 "data//maps/Route104/scripts.pory"

# 1036 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1037 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1038 "data//maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1039 "data//maps/Route104/scripts.pory"

# 1040 "data//maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1041 "data//maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1042 "data//maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1043 "data//maps/Route104/scripts.pory"

# 1044 "data//maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1045 "data//maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1046 "data//maps/Route104/scripts.pory"

# 1047 "data//maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1048 "data//maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1049 "data//maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1050 "data//maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1051 "data//maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1052 "data//maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1053 "data//maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1054 "data//maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1055 "data//maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1056 "data//maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1057 "data//maps/Route104/scripts.pory"

# 1058 "data//maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1059 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1060 "data//maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1061 "data//maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1062 "data//maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1063 "data//maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1064 "data//maps/Route104/scripts.pory"

# 1065 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1066 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1067 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1068 "data//maps/Route104/scripts.pory"

# 1069 "data//maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1070 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1071 "data//maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1072 "data//maps/Route104/scripts.pory"

# 1073 "data//maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1074 "data//maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1075 "data//maps/Route104/scripts.pory"
	.string "So…\l"
# 1076 "data//maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1077 "data//maps/Route104/scripts.pory"

# 1078 "data//maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1079 "data//maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1080 "data//maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1081 "data//maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1082 "data//maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1083 "data//maps/Route104/scripts.pory"

# 1084 "data//maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1085 "data//maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1086 "data//maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1087 "data//maps/Route104/scripts.pory"

# 1088 "data//maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1089 "data//maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1090 "data//maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1091 "data//maps/Route104/scripts.pory"

# 1092 "data//maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1093 "data//maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1094 "data//maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1095 "data//maps/Route104/scripts.pory"

# 1096 "data//maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1097 "data//maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1098 "data//maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1099 "data//maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1100 "data//maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1101 "data//maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1102 "data//maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1103 "data//maps/Route104/scripts.pory"

# 1104 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1105 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1106 "data//maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1107 "data//maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1108 "data//maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1109 "data//maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1110 "data//maps/Route104/scripts.pory"

# 1111 "data//maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1112 "data//maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1113 "data//maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1114 "data//maps/Route104/scripts.pory"

# 1115 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1116 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1117 "data//maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1118 "data//maps/Route104/scripts.pory"

# 1119 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1120 "data//maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1121 "data//maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1122 "data//maps/Route104/scripts.pory"
	.string "a battle?$"
# 1123 "data//maps/Route104/scripts.pory"

# 1124 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1125 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1126 "data//maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1127 "data//maps/Route104/scripts.pory"

# 1128 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1129 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1130 "data//maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1131 "data//maps/Route104/scripts.pory"

# 1132 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1133 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1134 "data//maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1135 "data//maps/Route104/scripts.pory"

# 1136 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1137 "data//maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1138 "data//maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1139 "data//maps/Route104/scripts.pory"

# 1140 "data//maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1141 "data//maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1142 "data//maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1143 "data//maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1144 "data//maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1145 "data//maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1146 "data//maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"
