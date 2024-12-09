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
	case SPECIES_TREECKO, Route103_EventScript_StartMayBattleTreecko
# 44 "data//maps/Route103/scripts.pory"
	case SPECIES_TORCHIC, Route103_EventScript_StartMayBattleTorchic
# 45 "data//maps/Route103/scripts.pory"
	case SPECIES_MUDKIP, Route103_EventScript_StartMayBattleMudkip
# 46 "data//maps/Route103/scripts.pory"
	case SPECIES_CASTFORM, Route103_EventScript_StartMayBattleTreecko
# 47 "data//maps/Route103/scripts.pory"
	case SPECIES_PIPLUP, Route103_EventScript_StartMayBattleTorchic
# 48 "data//maps/Route103/scripts.pory"
	case SPECIES_EEVEE, Route103_EventScript_StartMayBattleMudkip
# 49 "data//maps/Route103/scripts.pory"
	case SPECIES_PICHU, Route103_EventScript_StartMayBattleTreecko
# 50 "data//maps/Route103/scripts.pory"
	case SPECIES_TOGEPI, Route103_EventScript_StartMayBattleTorchic
# 51 "data//maps/Route103/scripts.pory"
	case SPECIES_PORYGON, Route103_EventScript_StartMayBattleMudkip
# 52 "data//maps/Route103/scripts.pory"
	case SPECIES_SNIVY, Route103_EventScript_StartMayBattleTreecko
# 53 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, Route103_EventScript_StartMayBattleTorchic
# 54 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA, Route103_EventScript_StartMayBattleMudkip
# 55 "data//maps/Route103/scripts.pory"
	case SPECIES_GOTHITA, Route103_EventScript_StartMayBattleTreecko
# 56 "data//maps/Route103/scripts.pory"
	case SPECIES_SOLOSIS, Route103_EventScript_StartMayBattleTorchic
# 57 "data//maps/Route103/scripts.pory"
	case SPECIES_AXEW, Route103_EventScript_StartMayBattleMudkip
# 58 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVESTA, Route103_EventScript_StartMayBattleTreecko
# 59 "data//maps/Route103/scripts.pory"
	case SPECIES_GOOMY, Route103_EventScript_StartMayBattleTorchic
# 60 "data//maps/Route103/scripts.pory"
	case SPECIES_ROWLET, Route103_EventScript_StartMayBattleMudkip
# 61 "data//maps/Route103/scripts.pory"
	case SPECIES_APPLIN, Route103_EventScript_StartMayBattleTreecko
# 62 "data//maps/Route103/scripts.pory"
	case SPECIES_MIME_JR, Route103_EventScript_StartMayBattleTorchic
# 63 "data//maps/Route103/scripts.pory"
	case SPECIES_MAGBY, Route103_EventScript_StartMayBattleMudkip
# 64 "data//maps/Route103/scripts.pory"
	case SPECIES_ELEKID, Route103_EventScript_StartMayBattleTreecko
# 65 "data//maps/Route103/scripts.pory"
	case SPECIES_MANKEY, Route103_EventScript_StartMayBattleTorchic
# 66 "data//maps/Route103/scripts.pory"
	case SPECIES_SWINUB, Route103_EventScript_StartMayBattleMudkip
# 67 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVITAR, Route103_EventScript_StartMayBattleTreecko
# 68 "data//maps/Route103/scripts.pory"
	end
# 69 "data//maps/Route103/scripts.pory"

# 70 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 71 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 72 "data//maps/Route103/scripts.pory"
	closemessage
# 73 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 74 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 75 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 76 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 77 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 78 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 79 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 80 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 81 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 82 "data//maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 83 "data//maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 84 "data//maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 85 "data//maps/Route103/scripts.pory"
	end
# 86 "data//maps/Route103/scripts.pory"

# 87 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 88 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 89 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 90 "data//maps/Route103/scripts.pory"
	end
# 91 "data//maps/Route103/scripts.pory"

# 92 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 93 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 94 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 95 "data//maps/Route103/scripts.pory"
	end
# 96 "data//maps/Route103/scripts.pory"

# 97 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 98 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 99 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 100 "data//maps/Route103/scripts.pory"
	end
# 101 "data//maps/Route103/scripts.pory"

# 102 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 103 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 104 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 105 "data//maps/Route103/scripts.pory"
	end
# 106 "data//maps/Route103/scripts.pory"

# 107 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 108 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 109 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 110 "data//maps/Route103/scripts.pory"
	end
# 111 "data//maps/Route103/scripts.pory"

# 112 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 113 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 114 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 115 "data//maps/Route103/scripts.pory"
	end
# 116 "data//maps/Route103/scripts.pory"

# 117 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 118 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 119 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 120 "data//maps/Route103/scripts.pory"
	end
# 121 "data//maps/Route103/scripts.pory"

# 122 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 123 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 124 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 125 "data//maps/Route103/scripts.pory"
	end
# 126 "data//maps/Route103/scripts.pory"

# 127 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 128 "data//maps/Route103/scripts.pory"
	closemessage
# 129 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 130 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 131 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 132 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 133 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 134 "data//maps/Route103/scripts.pory"
	end
# 135 "data//maps/Route103/scripts.pory"

# 136 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 137 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 138 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 139 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 140 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 141 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 142 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 143 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 144 "data//maps/Route103/scripts.pory"
	end
# 145 "data//maps/Route103/scripts.pory"

# 146 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 147 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 148 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 149 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 150 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 151 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 152 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 153 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 154 "data//maps/Route103/scripts.pory"
	end
# 155 "data//maps/Route103/scripts.pory"

# 156 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 157 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 158 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 159 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 160 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 161 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 162 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 163 "data//maps/Route103/scripts.pory"
	end
# 164 "data//maps/Route103/scripts.pory"

# 165 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 166 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 167 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 168 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 169 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 170 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 171 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 172 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 173 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 174 "data//maps/Route103/scripts.pory"
	releaseall
# 175 "data//maps/Route103/scripts.pory"
	end
# 176 "data//maps/Route103/scripts.pory"

# 177 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 178 "data//maps/Route103/scripts.pory"
	walk_left
# 179 "data//maps/Route103/scripts.pory"
	walk_down
# 180 "data//maps/Route103/scripts.pory"
	step_end
# 181 "data//maps/Route103/scripts.pory"

# 182 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 183 "data//maps/Route103/scripts.pory"
	jump_2_down
# 184 "data//maps/Route103/scripts.pory"
	delay_16
# 185 "data//maps/Route103/scripts.pory"
	walk_down
# 186 "data//maps/Route103/scripts.pory"
	walk_down
# 187 "data//maps/Route103/scripts.pory"
	walk_down
# 188 "data//maps/Route103/scripts.pory"
	walk_down
# 189 "data//maps/Route103/scripts.pory"
	step_end
# 190 "data//maps/Route103/scripts.pory"

# 191 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 192 "data//maps/Route103/scripts.pory"
	delay_16
# 193 "data//maps/Route103/scripts.pory"
	delay_4
# 194 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 195 "data//maps/Route103/scripts.pory"
	delay_16
# 196 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 197 "data//maps/Route103/scripts.pory"
	step_end
# 198 "data//maps/Route103/scripts.pory"

# 199 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 200 "data//maps/Route103/scripts.pory"
	walk_down
# 201 "data//maps/Route103/scripts.pory"
	step_end
# 202 "data//maps/Route103/scripts.pory"

# 203 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 204 "data//maps/Route103/scripts.pory"
	jump_2_down
# 205 "data//maps/Route103/scripts.pory"
	delay_16
# 206 "data//maps/Route103/scripts.pory"
	walk_down
# 207 "data//maps/Route103/scripts.pory"
	walk_down
# 208 "data//maps/Route103/scripts.pory"
	walk_down
# 209 "data//maps/Route103/scripts.pory"
	step_end
# 210 "data//maps/Route103/scripts.pory"

# 211 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 212 "data//maps/Route103/scripts.pory"
	delay_16
# 213 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 214 "data//maps/Route103/scripts.pory"
	step_end
# 215 "data//maps/Route103/scripts.pory"

# 216 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 217 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 218 "data//maps/Route103/scripts.pory"
	end
# 219 "data//maps/Route103/scripts.pory"

# 220 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 221 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 222 "data//maps/Route103/scripts.pory"
	end
# 223 "data//maps/Route103/scripts.pory"

# 224 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 225 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 226 "data//maps/Route103/scripts.pory"
	end
# 227 "data//maps/Route103/scripts.pory"

# 228 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 229 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 230 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 231 "data//maps/Route103/scripts.pory"
	end
# 232 "data//maps/Route103/scripts.pory"

# 233 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 234 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 235 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 236 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 237 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 238 "data//maps/Route103/scripts.pory"
	end
# 239 "data//maps/Route103/scripts.pory"

# 240 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 241 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 242 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 243 "data//maps/Route103/scripts.pory"
	release
# 244 "data//maps/Route103/scripts.pory"
	end
# 245 "data//maps/Route103/scripts.pory"

# 246 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 247 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 248 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 249 "data//maps/Route103/scripts.pory"
	end
# 250 "data//maps/Route103/scripts.pory"

# 251 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 252 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 253 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 254 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 255 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 256 "data//maps/Route103/scripts.pory"
	end
# 257 "data//maps/Route103/scripts.pory"

# 258 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 259 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 260 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 261 "data//maps/Route103/scripts.pory"
	release
# 262 "data//maps/Route103/scripts.pory"
	end
# 263 "data//maps/Route103/scripts.pory"

# 264 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 265 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 266 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 267 "data//maps/Route103/scripts.pory"
	end
# 268 "data//maps/Route103/scripts.pory"

# 269 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 270 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 271 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 272 "data//maps/Route103/scripts.pory"
	end
# 273 "data//maps/Route103/scripts.pory"

# 274 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 275 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 276 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 277 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 278 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 279 "data//maps/Route103/scripts.pory"
	release
# 280 "data//maps/Route103/scripts.pory"
	end
# 281 "data//maps/Route103/scripts.pory"

# 282 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 283 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 284 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 285 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 286 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 287 "data//maps/Route103/scripts.pory"
	release
# 288 "data//maps/Route103/scripts.pory"
	end
# 289 "data//maps/Route103/scripts.pory"

# 290 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 291 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 292 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 293 "data//maps/Route103/scripts.pory"
	end
# 294 "data//maps/Route103/scripts.pory"

# 295 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 296 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 297 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 298 "data//maps/Route103/scripts.pory"
	end
# 299 "data//maps/Route103/scripts.pory"

# 300 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 301 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 302 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 303 "data//maps/Route103/scripts.pory"
	end
# 304 "data//maps/Route103/scripts.pory"

# 305 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 306 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 307 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 308 "data//maps/Route103/scripts.pory"
	end
# 309 "data//maps/Route103/scripts.pory"

# 310 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 311 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 312 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 313 "data//maps/Route103/scripts.pory"
	end
# 314 "data//maps/Route103/scripts.pory"

# 315 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 316 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 317 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 318 "data//maps/Route103/scripts.pory"

# 319 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 320 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 321 "data//maps/Route103/scripts.pory"
	.string "That old geezer wanted us\n"
# 322 "data//maps/Route103/scripts.pory"
	.string "to battle?\p"
# 323 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 324 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 325 "data//maps/Route103/scripts.pory"

# 326 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 327 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 328 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 329 "data//maps/Route103/scripts.pory"

# 330 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 331 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 332 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 333 "data//maps/Route103/scripts.pory"
	.string "I mean you found your way out here\n"
# 334 "data//maps/Route103/scripts.pory"
	.string "with dangerous POKéMON everywhere.\p"
# 335 "data//maps/Route103/scripts.pory"
	.string "You might be able to defeat any\n"
# 336 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 337 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 338 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 339 "data//maps/Route103/scripts.pory"

# 340 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 341 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 342 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 343 "data//maps/Route103/scripts.pory"

# 344 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 345 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 346 "data//maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 347 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 348 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 349 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 350 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 351 "data//maps/Route103/scripts.pory"

# 352 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 353 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 354 "data//maps/Route103/scripts.pory"

# 355 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 356 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 357 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 358 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 359 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 360 "data//maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 361 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 362 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 363 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 364 "data//maps/Route103/scripts.pory"

# 365 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 366 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 367 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 368 "data//maps/Route103/scripts.pory"

# 369 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 370 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 371 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 372 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 373 "data//maps/Route103/scripts.pory"

# 374 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 375 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 376 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
