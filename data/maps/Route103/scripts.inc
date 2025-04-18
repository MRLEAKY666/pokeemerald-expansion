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
	call Common_EventScript_SetupRivalGfxId
# 11 "data//maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data//maps/Route103/scripts.pory"
	end
# 13 "data//maps/Route103/scripts.pory"

# 14 "data//maps/Route103/scripts.pory"
Route103_OnLoad:
# 15 "data//maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 16 "data//maps/Route103/scripts.pory"
	end
# 17 "data//maps/Route103/scripts.pory"

# 18 "data//maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 19 "data//maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 20 "data//maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 21 "data//maps/Route103/scripts.pory"
	return
# 22 "data//maps/Route103/scripts.pory"

# 23 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 24 "data//maps/Route103/scripts.pory"
	lockall
# 25 "data//maps/Route103/scripts.pory"
	checkplayergender
# 26 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 27 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 28 "data//maps/Route103/scripts.pory"
	end
# 29 "data//maps/Route103/scripts.pory"

# 30 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 31 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 32 "data//maps/Route103/scripts.pory"
	closemessage
# 33 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 34 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 35 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 36 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 37 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 38 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 39 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 40 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 41 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 42 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_BattleMay
# 43 "data//maps/Route103/scripts.pory"
	end
# 44 "data//maps/Route103/scripts.pory"

# 45 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 46 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 47 "data//maps/Route103/scripts.pory"
	closemessage
# 48 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 49 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 50 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 51 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 52 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 53 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 54 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 55 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 56 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 57 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_BattleBrendan
# 58 "data//maps/Route103/scripts.pory"
	end
# 59 "data//maps/Route103/scripts.pory"

# 60 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleMay::
# 61 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_A, Route103_Text_MayDefeated
# 62 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 63 "data//maps/Route103/scripts.pory"
	end
# 64 "data//maps/Route103/scripts.pory"

# 65 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleBrendan::
# 66 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_A, Route103_Text_BrendanDefeated
# 67 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 68 "data//maps/Route103/scripts.pory"
	end
# 69 "data//maps/Route103/scripts.pory"

# 70 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 71 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 72 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 73 "data//maps/Route103/scripts.pory"
	end
# 74 "data//maps/Route103/scripts.pory"

# 75 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 76 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 77 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 78 "data//maps/Route103/scripts.pory"
	end
# 79 "data//maps/Route103/scripts.pory"

# 80 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 81 "data//maps/Route103/scripts.pory"
	closemessage
# 82 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 83 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 84 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 85 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 86 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 87 "data//maps/Route103/scripts.pory"
	end
# 88 "data//maps/Route103/scripts.pory"

# 89 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 90 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 91 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 92 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 93 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 94 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 95 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 96 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 97 "data//maps/Route103/scripts.pory"
	end
# 98 "data//maps/Route103/scripts.pory"

# 99 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 100 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 101 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 102 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 103 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 104 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 105 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 106 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 107 "data//maps/Route103/scripts.pory"
	end
# 108 "data//maps/Route103/scripts.pory"

# 109 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 110 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 111 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 112 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 113 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 114 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 115 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 116 "data//maps/Route103/scripts.pory"
	end
# 117 "data//maps/Route103/scripts.pory"

# 118 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 119 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 120 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 121 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 122 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 123 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 124 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 125 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 126 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 127 "data//maps/Route103/scripts.pory"
	releaseall
# 128 "data//maps/Route103/scripts.pory"
	end
# 129 "data//maps/Route103/scripts.pory"

# 130 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 131 "data//maps/Route103/scripts.pory"
	walk_left
# 132 "data//maps/Route103/scripts.pory"
	walk_down
# 133 "data//maps/Route103/scripts.pory"
	step_end
# 134 "data//maps/Route103/scripts.pory"

# 135 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 136 "data//maps/Route103/scripts.pory"
	jump_2_down
# 137 "data//maps/Route103/scripts.pory"
	delay_16
# 138 "data//maps/Route103/scripts.pory"
	walk_down
# 139 "data//maps/Route103/scripts.pory"
	walk_down
# 140 "data//maps/Route103/scripts.pory"
	walk_down
# 141 "data//maps/Route103/scripts.pory"
	walk_down
# 142 "data//maps/Route103/scripts.pory"
	step_end
# 143 "data//maps/Route103/scripts.pory"

# 144 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 145 "data//maps/Route103/scripts.pory"
	delay_16
# 146 "data//maps/Route103/scripts.pory"
	delay_4
# 147 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 148 "data//maps/Route103/scripts.pory"
	delay_16
# 149 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 150 "data//maps/Route103/scripts.pory"
	step_end
# 151 "data//maps/Route103/scripts.pory"

# 152 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 153 "data//maps/Route103/scripts.pory"
	walk_down
# 154 "data//maps/Route103/scripts.pory"
	step_end
# 155 "data//maps/Route103/scripts.pory"

# 156 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 157 "data//maps/Route103/scripts.pory"
	jump_2_down
# 158 "data//maps/Route103/scripts.pory"
	delay_16
# 159 "data//maps/Route103/scripts.pory"
	walk_down
# 160 "data//maps/Route103/scripts.pory"
	walk_down
# 161 "data//maps/Route103/scripts.pory"
	walk_down
# 162 "data//maps/Route103/scripts.pory"
	step_end
# 163 "data//maps/Route103/scripts.pory"

# 164 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 165 "data//maps/Route103/scripts.pory"
	delay_16
# 166 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 167 "data//maps/Route103/scripts.pory"
	step_end
# 168 "data//maps/Route103/scripts.pory"

# 169 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 170 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 171 "data//maps/Route103/scripts.pory"
	end
# 172 "data//maps/Route103/scripts.pory"

# 173 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 174 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 175 "data//maps/Route103/scripts.pory"
	end
# 176 "data//maps/Route103/scripts.pory"

# 177 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 178 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 179 "data//maps/Route103/scripts.pory"
	end
# 180 "data//maps/Route103/scripts.pory"

# 181 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 182 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 183 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 184 "data//maps/Route103/scripts.pory"
	end
# 185 "data//maps/Route103/scripts.pory"

# 186 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 187 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 188 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 189 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 190 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 191 "data//maps/Route103/scripts.pory"
	end
# 192 "data//maps/Route103/scripts.pory"

# 193 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 194 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 195 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 196 "data//maps/Route103/scripts.pory"
	release
# 197 "data//maps/Route103/scripts.pory"
	end
# 198 "data//maps/Route103/scripts.pory"

# 199 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 200 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 201 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 202 "data//maps/Route103/scripts.pory"
	end
# 203 "data//maps/Route103/scripts.pory"

# 204 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 205 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 206 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 207 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 208 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 209 "data//maps/Route103/scripts.pory"
	end
# 210 "data//maps/Route103/scripts.pory"

# 211 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 212 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 213 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 214 "data//maps/Route103/scripts.pory"
	release
# 215 "data//maps/Route103/scripts.pory"
	end
# 216 "data//maps/Route103/scripts.pory"

# 217 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 218 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 219 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 220 "data//maps/Route103/scripts.pory"
	end
# 221 "data//maps/Route103/scripts.pory"

# 222 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 223 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 224 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 225 "data//maps/Route103/scripts.pory"
	end
# 226 "data//maps/Route103/scripts.pory"

# 227 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 228 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 229 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 230 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 231 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 232 "data//maps/Route103/scripts.pory"
	release
# 233 "data//maps/Route103/scripts.pory"
	end
# 234 "data//maps/Route103/scripts.pory"

# 235 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 236 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 237 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 238 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 239 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 240 "data//maps/Route103/scripts.pory"
	release
# 241 "data//maps/Route103/scripts.pory"
	end
# 242 "data//maps/Route103/scripts.pory"

# 243 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 244 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 245 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 246 "data//maps/Route103/scripts.pory"
	end
# 247 "data//maps/Route103/scripts.pory"

# 248 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 249 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 250 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 251 "data//maps/Route103/scripts.pory"
	end
# 252 "data//maps/Route103/scripts.pory"

# 253 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 254 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 255 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 256 "data//maps/Route103/scripts.pory"
	end
# 257 "data//maps/Route103/scripts.pory"

# 258 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 259 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 260 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 261 "data//maps/Route103/scripts.pory"
	end
# 262 "data//maps/Route103/scripts.pory"

# 263 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 264 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 265 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 266 "data//maps/Route103/scripts.pory"
	end
# 267 "data//maps/Route103/scripts.pory"

# 268 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 269 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 270 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 271 "data//maps/Route103/scripts.pory"

# 272 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 273 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 274 "data//maps/Route103/scripts.pory"
	.string "That old geezer wanted us\n"
# 275 "data//maps/Route103/scripts.pory"
	.string "to battle?\p"
# 276 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 277 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 278 "data//maps/Route103/scripts.pory"

# 279 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 280 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 281 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 282 "data//maps/Route103/scripts.pory"

# 283 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 284 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 285 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 286 "data//maps/Route103/scripts.pory"
	.string "I mean you found your way out here\n"
# 287 "data//maps/Route103/scripts.pory"
	.string "with dangerous POKéMON everywhere.\p"
# 288 "data//maps/Route103/scripts.pory"
	.string "You might be able to defeat any\n"
# 289 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 290 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 291 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 292 "data//maps/Route103/scripts.pory"

# 293 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 294 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 295 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 296 "data//maps/Route103/scripts.pory"

# 297 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 298 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 299 "data//maps/Route103/scripts.pory"
	.string "…Oh, you have some dumb POKéMON too?\p"
# 300 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 301 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 302 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 303 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 304 "data//maps/Route103/scripts.pory"

# 305 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 306 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 307 "data//maps/Route103/scripts.pory"

# 308 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 309 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 310 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 311 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 312 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON doesn't hate you,\n"
# 313 "data//maps/Route103/scripts.pory"
	.string "even though you seem boring.\p"
# 314 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 315 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 316 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 317 "data//maps/Route103/scripts.pory"

# 318 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 319 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 320 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 321 "data//maps/Route103/scripts.pory"

# 322 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 323 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 324 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 325 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 326 "data//maps/Route103/scripts.pory"

# 327 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 328 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 329 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
