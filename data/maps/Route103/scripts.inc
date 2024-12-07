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
	case SPECIES_TREECKO, Route103_EventScript_StartMayBattleTreecko
# 43 "data//maps/Route103/scripts.pory"
	case SPECIES_TORCHIC, Route103_EventScript_StartMayBattleTorchic
# 44 "data//maps/Route103/scripts.pory"
	case SPECIES_MUDKIP, Route103_EventScript_StartMayBattleMudkip
# 45 "data//maps/Route103/scripts.pory"
	case SPECIES_CASTFORM, Route103_EventScript_StartMayBattleTreecko
# 46 "data//maps/Route103/scripts.pory"
	case SPECIES_PIPLUP, Route103_EventScript_StartMayBattleTorchic
# 47 "data//maps/Route103/scripts.pory"
	case SPECIES_EEVEE, Route103_EventScript_StartMayBattleMudkip
# 48 "data//maps/Route103/scripts.pory"
	case SPECIES_PICHU, Route103_EventScript_StartMayBattleTreecko
# 49 "data//maps/Route103/scripts.pory"
	case SPECIES_TOGEPI, Route103_EventScript_StartMayBattleTorchic
# 50 "data//maps/Route103/scripts.pory"
	case SPECIES_PORYGON, Route103_EventScript_StartMayBattleMudkip
# 51 "data//maps/Route103/scripts.pory"
	case SPECIES_SNIVY, Route103_EventScript_StartMayBattleTreecko
# 52 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, Route103_EventScript_StartMayBattleTorchic
# 53 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA, Route103_EventScript_StartMayBattleMudkip
# 54 "data//maps/Route103/scripts.pory"
	case SPECIES_GOTHITA, Route103_EventScript_StartMayBattleTreecko
# 55 "data//maps/Route103/scripts.pory"
	case SPECIES_SOLOSIS, Route103_EventScript_StartMayBattleTorchic
# 56 "data//maps/Route103/scripts.pory"
	case SPECIES_AXEW, Route103_EventScript_StartMayBattleMudkip
# 57 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVESTA, Route103_EventScript_StartMayBattleTreecko
# 58 "data//maps/Route103/scripts.pory"
	case SPECIES_GOOMY, Route103_EventScript_StartMayBattleTorchic
# 59 "data//maps/Route103/scripts.pory"
	case SPECIES_ROWLET, Route103_EventScript_StartMayBattleMudkip
# 60 "data//maps/Route103/scripts.pory"
	case SPECIES_APPLIN, Route103_EventScript_StartMayBattleTreecko
# 61 "data//maps/Route103/scripts.pory"
	case SPECIES_MIME_JR, Route103_EventScript_StartMayBattleTorchic
# 62 "data//maps/Route103/scripts.pory"
	case SPECIES_MAGBY, Route103_EventScript_StartMayBattleMudkip
# 63 "data//maps/Route103/scripts.pory"
	case SPECIES_ELEKID, Route103_EventScript_StartMayBattleTreecko
# 64 "data//maps/Route103/scripts.pory"
	case SPECIES_MANKEY, Route103_EventScript_StartMayBattleTorchic
# 65 "data//maps/Route103/scripts.pory"
	case SPECIES_SWINUB, Route103_EventScript_StartMayBattleMudkip
# 66 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVITAR, Route103_EventScript_StartMayBattleTreecko
# 67 "data//maps/Route103/scripts.pory"
	end
# 68 "data//maps/Route103/scripts.pory"

# 69 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 70 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 71 "data//maps/Route103/scripts.pory"
	closemessage
# 72 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 73 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 74 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 75 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 76 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 77 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 78 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 79 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 80 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 81 "data//maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 82 "data//maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 83 "data//maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 84 "data//maps/Route103/scripts.pory"
	end
# 85 "data//maps/Route103/scripts.pory"

# 86 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 87 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 88 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 89 "data//maps/Route103/scripts.pory"
	end
# 90 "data//maps/Route103/scripts.pory"

# 91 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 92 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 93 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 94 "data//maps/Route103/scripts.pory"
	end
# 95 "data//maps/Route103/scripts.pory"

# 96 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 97 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 98 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 99 "data//maps/Route103/scripts.pory"
	end
# 100 "data//maps/Route103/scripts.pory"

# 101 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 102 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 103 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 104 "data//maps/Route103/scripts.pory"
	end
# 105 "data//maps/Route103/scripts.pory"

# 106 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 107 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 108 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 109 "data//maps/Route103/scripts.pory"
	end
# 110 "data//maps/Route103/scripts.pory"

# 111 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 112 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 113 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 114 "data//maps/Route103/scripts.pory"
	end
# 115 "data//maps/Route103/scripts.pory"

# 116 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 117 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 118 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 119 "data//maps/Route103/scripts.pory"
	end
# 120 "data//maps/Route103/scripts.pory"

# 121 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 122 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 123 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 124 "data//maps/Route103/scripts.pory"
	end
# 125 "data//maps/Route103/scripts.pory"

# 126 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 127 "data//maps/Route103/scripts.pory"
	closemessage
# 128 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 129 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 130 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 131 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 132 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 133 "data//maps/Route103/scripts.pory"
	end
# 134 "data//maps/Route103/scripts.pory"

# 135 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 136 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 137 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 138 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 139 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 140 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 141 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 142 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 143 "data//maps/Route103/scripts.pory"
	end
# 144 "data//maps/Route103/scripts.pory"

# 145 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 146 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 147 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 148 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 149 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 150 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 151 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 152 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 153 "data//maps/Route103/scripts.pory"
	end
# 154 "data//maps/Route103/scripts.pory"

# 155 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 156 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 157 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 158 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 159 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 160 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 161 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 162 "data//maps/Route103/scripts.pory"
	end
# 163 "data//maps/Route103/scripts.pory"

# 164 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 165 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 166 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 167 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 168 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 169 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 170 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 171 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 172 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 173 "data//maps/Route103/scripts.pory"
	releaseall
# 174 "data//maps/Route103/scripts.pory"
	end
# 175 "data//maps/Route103/scripts.pory"

# 176 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 177 "data//maps/Route103/scripts.pory"
	walk_left
# 178 "data//maps/Route103/scripts.pory"
	walk_down
# 179 "data//maps/Route103/scripts.pory"
	step_end
# 180 "data//maps/Route103/scripts.pory"

# 181 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 182 "data//maps/Route103/scripts.pory"
	jump_2_down
# 183 "data//maps/Route103/scripts.pory"
	delay_16
# 184 "data//maps/Route103/scripts.pory"
	walk_down
# 185 "data//maps/Route103/scripts.pory"
	walk_down
# 186 "data//maps/Route103/scripts.pory"
	walk_down
# 187 "data//maps/Route103/scripts.pory"
	walk_down
# 188 "data//maps/Route103/scripts.pory"
	step_end
# 189 "data//maps/Route103/scripts.pory"

# 190 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 191 "data//maps/Route103/scripts.pory"
	delay_16
# 192 "data//maps/Route103/scripts.pory"
	delay_4
# 193 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 194 "data//maps/Route103/scripts.pory"
	delay_16
# 195 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 196 "data//maps/Route103/scripts.pory"
	step_end
# 197 "data//maps/Route103/scripts.pory"

# 198 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 199 "data//maps/Route103/scripts.pory"
	walk_down
# 200 "data//maps/Route103/scripts.pory"
	step_end
# 201 "data//maps/Route103/scripts.pory"

# 202 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 203 "data//maps/Route103/scripts.pory"
	jump_2_down
# 204 "data//maps/Route103/scripts.pory"
	delay_16
# 205 "data//maps/Route103/scripts.pory"
	walk_down
# 206 "data//maps/Route103/scripts.pory"
	walk_down
# 207 "data//maps/Route103/scripts.pory"
	walk_down
# 208 "data//maps/Route103/scripts.pory"
	step_end
# 209 "data//maps/Route103/scripts.pory"

# 210 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 211 "data//maps/Route103/scripts.pory"
	delay_16
# 212 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 213 "data//maps/Route103/scripts.pory"
	step_end
# 214 "data//maps/Route103/scripts.pory"

# 215 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 216 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 217 "data//maps/Route103/scripts.pory"
	end
# 218 "data//maps/Route103/scripts.pory"

# 219 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 220 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 221 "data//maps/Route103/scripts.pory"
	end
# 222 "data//maps/Route103/scripts.pory"

# 223 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 224 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 225 "data//maps/Route103/scripts.pory"
	end
# 226 "data//maps/Route103/scripts.pory"

# 227 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 228 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 229 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 230 "data//maps/Route103/scripts.pory"
	end
# 231 "data//maps/Route103/scripts.pory"

# 232 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 233 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 234 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 235 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 236 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 237 "data//maps/Route103/scripts.pory"
	end
# 238 "data//maps/Route103/scripts.pory"

# 239 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 240 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 241 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 242 "data//maps/Route103/scripts.pory"
	release
# 243 "data//maps/Route103/scripts.pory"
	end
# 244 "data//maps/Route103/scripts.pory"

# 245 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 246 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 247 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 248 "data//maps/Route103/scripts.pory"
	end
# 249 "data//maps/Route103/scripts.pory"

# 250 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 251 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 252 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 253 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 254 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 255 "data//maps/Route103/scripts.pory"
	end
# 256 "data//maps/Route103/scripts.pory"

# 257 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 258 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 259 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 260 "data//maps/Route103/scripts.pory"
	release
# 261 "data//maps/Route103/scripts.pory"
	end
# 262 "data//maps/Route103/scripts.pory"

# 263 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 264 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 265 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 266 "data//maps/Route103/scripts.pory"
	end
# 267 "data//maps/Route103/scripts.pory"

# 268 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 269 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 270 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 271 "data//maps/Route103/scripts.pory"
	end
# 272 "data//maps/Route103/scripts.pory"

# 273 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 274 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 275 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 276 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 277 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 278 "data//maps/Route103/scripts.pory"
	release
# 279 "data//maps/Route103/scripts.pory"
	end
# 280 "data//maps/Route103/scripts.pory"

# 281 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 282 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 283 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 284 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 285 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 286 "data//maps/Route103/scripts.pory"
	release
# 287 "data//maps/Route103/scripts.pory"
	end
# 288 "data//maps/Route103/scripts.pory"

# 289 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 290 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 291 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 292 "data//maps/Route103/scripts.pory"
	end
# 293 "data//maps/Route103/scripts.pory"

# 294 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 295 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 296 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 297 "data//maps/Route103/scripts.pory"
	end
# 298 "data//maps/Route103/scripts.pory"

# 299 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 300 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 301 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 302 "data//maps/Route103/scripts.pory"
	end
# 303 "data//maps/Route103/scripts.pory"

# 304 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 305 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 306 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 307 "data//maps/Route103/scripts.pory"
	end
# 308 "data//maps/Route103/scripts.pory"

# 309 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 310 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 311 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 312 "data//maps/Route103/scripts.pory"
	end
# 313 "data//maps/Route103/scripts.pory"

# 314 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 315 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 316 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 317 "data//maps/Route103/scripts.pory"

# 318 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 319 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 320 "data//maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 321 "data//maps/Route103/scripts.pory"
	.string "a POKéMON as a gift.\p"
# 322 "data//maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 323 "data//maps/Route103/scripts.pory"
	.string "battle!\p"
# 324 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 325 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 326 "data//maps/Route103/scripts.pory"

# 327 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 328 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 329 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 330 "data//maps/Route103/scripts.pory"

# 331 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 332 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 333 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 334 "data//maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 335 "data//maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 336 "data//maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 337 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 338 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 339 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 340 "data//maps/Route103/scripts.pory"

# 341 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 342 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 343 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 344 "data//maps/Route103/scripts.pory"

# 345 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 346 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 347 "data//maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 348 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 349 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 350 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 351 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 352 "data//maps/Route103/scripts.pory"

# 353 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 354 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 355 "data//maps/Route103/scripts.pory"

# 356 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 357 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 358 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 359 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 360 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 361 "data//maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 362 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 363 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 364 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 365 "data//maps/Route103/scripts.pory"

# 366 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 367 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 368 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 369 "data//maps/Route103/scripts.pory"

# 370 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 371 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 372 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 373 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 374 "data//maps/Route103/scripts.pory"

# 375 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 376 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 377 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
