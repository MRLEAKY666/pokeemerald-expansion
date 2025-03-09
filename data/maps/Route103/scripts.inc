# 1 "data//maps/Route103/scripts.pory"

# 2 "data//maps/Route103/scripts.pory"
.set LOCALID_RIVAL, 2
# 3 "data//maps/Route103/scripts.pory"

# 4 "data//maps/Route103/scripts.pory"
Route103_MapScripts::
# 5 "data//maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 6 "data//maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 7 "data//maps/Route103/scripts.pory"
	.byte 0
# 8 "data//maps/Route103/scripts.pory"

# 9 "data//maps/Route103/scripts.pory"
Route103_OnTransition:
# 10 "data//maps/Route103/scripts.pory"
	clearflag FLAG_SYS_SAVE_GET
# 11 "data//maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data//maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 13 "data//maps/Route103/scripts.pory"
	end
# 14 "data//maps/Route103/scripts.pory"

# 15 "data//maps/Route103/scripts.pory"
Route103_OnLoad:
# 16 "data//maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 17 "data//maps/Route103/scripts.pory"
	end
# 18 "data//maps/Route103/scripts.pory"

# 19 "data//maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 20 "data//maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 21 "data//maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 22 "data//maps/Route103/scripts.pory"
	return
# 23 "data//maps/Route103/scripts.pory"

# 24 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 25 "data//maps/Route103/scripts.pory"
	lockall
# 26 "data//maps/Route103/scripts.pory"
	checkplayergender
# 27 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 28 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 29 "data//maps/Route103/scripts.pory"
	end
# 30 "data//maps/Route103/scripts.pory"

# 31 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 32 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 33 "data//maps/Route103/scripts.pory"
	closemessage
# 34 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 35 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 36 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 37 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 38 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 39 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 40 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 41 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 42 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 43 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_BattleMay
# 44 "data//maps/Route103/scripts.pory"
	end
# 45 "data//maps/Route103/scripts.pory"

# 46 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 47 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 48 "data//maps/Route103/scripts.pory"
	closemessage
# 49 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 50 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 51 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 52 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 53 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 54 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 55 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 56 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 57 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 58 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_BattleBrendan
# 59 "data//maps/Route103/scripts.pory"
	end
# 60 "data//maps/Route103/scripts.pory"

# 61 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleMay::
# 62 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_A, Route103_Text_MayDefeated
# 63 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 64 "data//maps/Route103/scripts.pory"
	end
# 65 "data//maps/Route103/scripts.pory"

# 66 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleBrendan::
# 67 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_A, Route103_Text_BrendanDefeated
# 68 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 69 "data//maps/Route103/scripts.pory"
	end
# 70 "data//maps/Route103/scripts.pory"

# 71 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 72 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 73 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 74 "data//maps/Route103/scripts.pory"
	end
# 75 "data//maps/Route103/scripts.pory"

# 76 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 77 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 78 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 79 "data//maps/Route103/scripts.pory"
	end
# 80 "data//maps/Route103/scripts.pory"

# 81 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 82 "data//maps/Route103/scripts.pory"
	closemessage
# 83 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 84 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 85 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 86 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 87 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 88 "data//maps/Route103/scripts.pory"
	end
# 89 "data//maps/Route103/scripts.pory"

# 90 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 91 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 92 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 93 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 94 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 95 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 96 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 97 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 98 "data//maps/Route103/scripts.pory"
	end
# 99 "data//maps/Route103/scripts.pory"

# 100 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 101 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 102 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 103 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 104 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 105 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 106 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 107 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 108 "data//maps/Route103/scripts.pory"
	end
# 109 "data//maps/Route103/scripts.pory"

# 110 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 111 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 112 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 113 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 114 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 115 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 116 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 117 "data//maps/Route103/scripts.pory"
	end
# 118 "data//maps/Route103/scripts.pory"

# 119 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 120 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 121 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 122 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 123 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 124 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 125 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 126 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 127 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 128 "data//maps/Route103/scripts.pory"
	releaseall
# 129 "data//maps/Route103/scripts.pory"
	end
# 130 "data//maps/Route103/scripts.pory"

# 131 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 132 "data//maps/Route103/scripts.pory"
	walk_left
# 133 "data//maps/Route103/scripts.pory"
	walk_down
# 134 "data//maps/Route103/scripts.pory"
	step_end
# 135 "data//maps/Route103/scripts.pory"

# 136 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 137 "data//maps/Route103/scripts.pory"
	jump_2_down
# 138 "data//maps/Route103/scripts.pory"
	delay_16
# 139 "data//maps/Route103/scripts.pory"
	walk_down
# 140 "data//maps/Route103/scripts.pory"
	walk_down
# 141 "data//maps/Route103/scripts.pory"
	walk_down
# 142 "data//maps/Route103/scripts.pory"
	walk_down
# 143 "data//maps/Route103/scripts.pory"
	step_end
# 144 "data//maps/Route103/scripts.pory"

# 145 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 146 "data//maps/Route103/scripts.pory"
	delay_16
# 147 "data//maps/Route103/scripts.pory"
	delay_4
# 148 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 149 "data//maps/Route103/scripts.pory"
	delay_16
# 150 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 151 "data//maps/Route103/scripts.pory"
	step_end
# 152 "data//maps/Route103/scripts.pory"

# 153 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 154 "data//maps/Route103/scripts.pory"
	walk_down
# 155 "data//maps/Route103/scripts.pory"
	step_end
# 156 "data//maps/Route103/scripts.pory"

# 157 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 158 "data//maps/Route103/scripts.pory"
	jump_2_down
# 159 "data//maps/Route103/scripts.pory"
	delay_16
# 160 "data//maps/Route103/scripts.pory"
	walk_down
# 161 "data//maps/Route103/scripts.pory"
	walk_down
# 162 "data//maps/Route103/scripts.pory"
	walk_down
# 163 "data//maps/Route103/scripts.pory"
	step_end
# 164 "data//maps/Route103/scripts.pory"

# 165 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 166 "data//maps/Route103/scripts.pory"
	delay_16
# 167 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 168 "data//maps/Route103/scripts.pory"
	step_end
# 169 "data//maps/Route103/scripts.pory"

# 170 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 171 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 172 "data//maps/Route103/scripts.pory"
	end
# 173 "data//maps/Route103/scripts.pory"

# 174 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 175 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 176 "data//maps/Route103/scripts.pory"
	end
# 177 "data//maps/Route103/scripts.pory"

# 178 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 179 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 180 "data//maps/Route103/scripts.pory"
	end
# 181 "data//maps/Route103/scripts.pory"

# 182 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 183 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 184 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 185 "data//maps/Route103/scripts.pory"
	end
# 186 "data//maps/Route103/scripts.pory"

# 187 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 188 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 189 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 190 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 191 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 192 "data//maps/Route103/scripts.pory"
	end
# 193 "data//maps/Route103/scripts.pory"

# 194 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 195 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 196 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 197 "data//maps/Route103/scripts.pory"
	release
# 198 "data//maps/Route103/scripts.pory"
	end
# 199 "data//maps/Route103/scripts.pory"

# 200 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 201 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 202 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 203 "data//maps/Route103/scripts.pory"
	end
# 204 "data//maps/Route103/scripts.pory"

# 205 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 206 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 207 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 208 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 209 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 210 "data//maps/Route103/scripts.pory"
	end
# 211 "data//maps/Route103/scripts.pory"

# 212 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 213 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 214 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 215 "data//maps/Route103/scripts.pory"
	release
# 216 "data//maps/Route103/scripts.pory"
	end
# 217 "data//maps/Route103/scripts.pory"

# 218 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 219 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 220 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 221 "data//maps/Route103/scripts.pory"
	end
# 222 "data//maps/Route103/scripts.pory"

# 223 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 224 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 225 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 226 "data//maps/Route103/scripts.pory"
	end
# 227 "data//maps/Route103/scripts.pory"

# 228 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 229 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 230 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 231 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 232 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 233 "data//maps/Route103/scripts.pory"
	release
# 234 "data//maps/Route103/scripts.pory"
	end
# 235 "data//maps/Route103/scripts.pory"

# 236 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 237 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 238 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 239 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 240 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 241 "data//maps/Route103/scripts.pory"
	release
# 242 "data//maps/Route103/scripts.pory"
	end
# 243 "data//maps/Route103/scripts.pory"

# 244 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 245 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 246 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 247 "data//maps/Route103/scripts.pory"
	end
# 248 "data//maps/Route103/scripts.pory"

# 249 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 250 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 251 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 252 "data//maps/Route103/scripts.pory"
	end
# 253 "data//maps/Route103/scripts.pory"

# 254 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 255 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 256 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 257 "data//maps/Route103/scripts.pory"
	end
# 258 "data//maps/Route103/scripts.pory"

# 259 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 260 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 261 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 262 "data//maps/Route103/scripts.pory"
	end
# 263 "data//maps/Route103/scripts.pory"

# 264 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 265 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 266 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 267 "data//maps/Route103/scripts.pory"
	end
# 268 "data//maps/Route103/scripts.pory"

# 269 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 270 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 271 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 272 "data//maps/Route103/scripts.pory"

# 273 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 274 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 275 "data//maps/Route103/scripts.pory"
	.string "That old geezer wanted us\n"
# 276 "data//maps/Route103/scripts.pory"
	.string "to battle?\p"
# 277 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 278 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 279 "data//maps/Route103/scripts.pory"

# 280 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 281 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 282 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 283 "data//maps/Route103/scripts.pory"

# 284 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 285 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 286 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 287 "data//maps/Route103/scripts.pory"
	.string "I mean you found your way out here\n"
# 288 "data//maps/Route103/scripts.pory"
	.string "with dangerous POKéMON everywhere.\p"
# 289 "data//maps/Route103/scripts.pory"
	.string "You might be able to defeat any\n"
# 290 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 291 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 292 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 293 "data//maps/Route103/scripts.pory"

# 294 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 295 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 296 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 297 "data//maps/Route103/scripts.pory"

# 298 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 299 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 300 "data//maps/Route103/scripts.pory"
	.string "…Oh, you some dumb POKéMON too?\p"
# 301 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 302 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 303 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 304 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 305 "data//maps/Route103/scripts.pory"

# 306 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 307 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 308 "data//maps/Route103/scripts.pory"

# 309 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 310 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 311 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 312 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 313 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON doesn't hate you,\n"
# 314 "data//maps/Route103/scripts.pory"
	.string "even though you seem boring.\p"
# 315 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 316 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 317 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 318 "data//maps/Route103/scripts.pory"

# 319 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 320 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 321 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 322 "data//maps/Route103/scripts.pory"

# 323 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 324 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 325 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 326 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 327 "data//maps/Route103/scripts.pory"

# 328 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 329 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 330 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
