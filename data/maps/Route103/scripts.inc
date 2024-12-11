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
	case SPECIES_TURTWIG, Route103_EventScript_StartMayBattleTorchic
# 69 "data//maps/Route103/scripts.pory"
	case SPECIES_CHARMANDER, Route103_EventScript_StartMayBattleMudkip
# 70 "data//maps/Route103/scripts.pory"
	case SPECIES_SQUIRTLE, Route103_EventScript_StartMayBattleTreecko
# 71 "data//maps/Route103/scripts.pory"
	case SPECIES_BULBASAUR, Route103_EventScript_StartMayBattleTorchic
# 72 "data//maps/Route103/scripts.pory"
	case SPECIES_OSHAWOTT, Route103_EventScript_StartMayBattleMudkip
# 73 "data//maps/Route103/scripts.pory"
	case SPECIES_CYNDAQUIL, Route103_EventScript_StartMayBattleTreecko
# 74 "data//maps/Route103/scripts.pory"
	case SPECIES_BUDEW, Route103_EventScript_StartMayBattleTorchic
# 75 "data//maps/Route103/scripts.pory"
	case SPECIES_SPHEAL, Route103_EventScript_StartMayBattleMudkip
# 76 "data//maps/Route103/scripts.pory"
	case SPECIES_SHINX, Route103_EventScript_StartMayBattleTreecko
# 77 "data//maps/Route103/scripts.pory"
	case SPECIES_SANDILE, Route103_EventScript_StartMayBattleTreecko
# 78 "data//maps/Route103/scripts.pory"
	case SPECIES_PAWNIARD, Route103_EventScript_StartMayBattleTorchic
# 79 "data//maps/Route103/scripts.pory"
	case SPECIES_JANGMO_O, Route103_EventScript_StartMayBattleMudkip
# 80 "data//maps/Route103/scripts.pory"
	end
# 81 "data//maps/Route103/scripts.pory"

# 82 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 83 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 84 "data//maps/Route103/scripts.pory"
	closemessage
# 85 "data//maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 86 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 87 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 88 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 89 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 90 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 91 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 92 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 93 "data//maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 94 "data//maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 95 "data//maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 96 "data//maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 97 "data//maps/Route103/scripts.pory"
	end
# 98 "data//maps/Route103/scripts.pory"

# 99 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 100 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 101 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 102 "data//maps/Route103/scripts.pory"
	end
# 103 "data//maps/Route103/scripts.pory"

# 104 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 105 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 106 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 107 "data//maps/Route103/scripts.pory"
	end
# 108 "data//maps/Route103/scripts.pory"

# 109 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 110 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 111 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 112 "data//maps/Route103/scripts.pory"
	end
# 113 "data//maps/Route103/scripts.pory"

# 114 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 115 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 116 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 117 "data//maps/Route103/scripts.pory"
	end
# 118 "data//maps/Route103/scripts.pory"

# 119 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 120 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 121 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 122 "data//maps/Route103/scripts.pory"
	end
# 123 "data//maps/Route103/scripts.pory"

# 124 "data//maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 125 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 126 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 127 "data//maps/Route103/scripts.pory"
	end
# 128 "data//maps/Route103/scripts.pory"

# 129 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 130 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 131 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 132 "data//maps/Route103/scripts.pory"
	end
# 133 "data//maps/Route103/scripts.pory"

# 134 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 135 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 136 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 137 "data//maps/Route103/scripts.pory"
	end
# 138 "data//maps/Route103/scripts.pory"

# 139 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 140 "data//maps/Route103/scripts.pory"
	closemessage
# 141 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 142 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 143 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 144 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 145 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 146 "data//maps/Route103/scripts.pory"
	end
# 147 "data//maps/Route103/scripts.pory"

# 148 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 149 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 150 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 151 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 152 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 153 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 154 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 155 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 156 "data//maps/Route103/scripts.pory"
	end
# 157 "data//maps/Route103/scripts.pory"

# 158 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 159 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 160 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 161 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 162 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 163 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 164 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 165 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 166 "data//maps/Route103/scripts.pory"
	end
# 167 "data//maps/Route103/scripts.pory"

# 168 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 169 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 170 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 171 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 172 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 173 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 174 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 175 "data//maps/Route103/scripts.pory"
	end
# 176 "data//maps/Route103/scripts.pory"

# 177 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 178 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 179 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 180 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 181 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 182 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 183 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 184 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 185 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 186 "data//maps/Route103/scripts.pory"
	releaseall
# 187 "data//maps/Route103/scripts.pory"
	end
# 188 "data//maps/Route103/scripts.pory"

# 189 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 190 "data//maps/Route103/scripts.pory"
	walk_left
# 191 "data//maps/Route103/scripts.pory"
	walk_down
# 192 "data//maps/Route103/scripts.pory"
	step_end
# 193 "data//maps/Route103/scripts.pory"

# 194 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 195 "data//maps/Route103/scripts.pory"
	jump_2_down
# 196 "data//maps/Route103/scripts.pory"
	delay_16
# 197 "data//maps/Route103/scripts.pory"
	walk_down
# 198 "data//maps/Route103/scripts.pory"
	walk_down
# 199 "data//maps/Route103/scripts.pory"
	walk_down
# 200 "data//maps/Route103/scripts.pory"
	walk_down
# 201 "data//maps/Route103/scripts.pory"
	step_end
# 202 "data//maps/Route103/scripts.pory"

# 203 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 204 "data//maps/Route103/scripts.pory"
	delay_16
# 205 "data//maps/Route103/scripts.pory"
	delay_4
# 206 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 207 "data//maps/Route103/scripts.pory"
	delay_16
# 208 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 209 "data//maps/Route103/scripts.pory"
	step_end
# 210 "data//maps/Route103/scripts.pory"

# 211 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 212 "data//maps/Route103/scripts.pory"
	walk_down
# 213 "data//maps/Route103/scripts.pory"
	step_end
# 214 "data//maps/Route103/scripts.pory"

# 215 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 216 "data//maps/Route103/scripts.pory"
	jump_2_down
# 217 "data//maps/Route103/scripts.pory"
	delay_16
# 218 "data//maps/Route103/scripts.pory"
	walk_down
# 219 "data//maps/Route103/scripts.pory"
	walk_down
# 220 "data//maps/Route103/scripts.pory"
	walk_down
# 221 "data//maps/Route103/scripts.pory"
	step_end
# 222 "data//maps/Route103/scripts.pory"

# 223 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 224 "data//maps/Route103/scripts.pory"
	delay_16
# 225 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 226 "data//maps/Route103/scripts.pory"
	step_end
# 227 "data//maps/Route103/scripts.pory"

# 228 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 229 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 230 "data//maps/Route103/scripts.pory"
	end
# 231 "data//maps/Route103/scripts.pory"

# 232 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 233 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 234 "data//maps/Route103/scripts.pory"
	end
# 235 "data//maps/Route103/scripts.pory"

# 236 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 237 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 238 "data//maps/Route103/scripts.pory"
	end
# 239 "data//maps/Route103/scripts.pory"

# 240 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 241 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 242 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 243 "data//maps/Route103/scripts.pory"
	end
# 244 "data//maps/Route103/scripts.pory"

# 245 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 246 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 247 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 248 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 249 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 250 "data//maps/Route103/scripts.pory"
	end
# 251 "data//maps/Route103/scripts.pory"

# 252 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 253 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 254 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 255 "data//maps/Route103/scripts.pory"
	release
# 256 "data//maps/Route103/scripts.pory"
	end
# 257 "data//maps/Route103/scripts.pory"

# 258 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 259 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 260 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 261 "data//maps/Route103/scripts.pory"
	end
# 262 "data//maps/Route103/scripts.pory"

# 263 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 264 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 265 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 266 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 267 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 268 "data//maps/Route103/scripts.pory"
	end
# 269 "data//maps/Route103/scripts.pory"

# 270 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 271 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 272 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 273 "data//maps/Route103/scripts.pory"
	release
# 274 "data//maps/Route103/scripts.pory"
	end
# 275 "data//maps/Route103/scripts.pory"

# 276 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 277 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 278 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 279 "data//maps/Route103/scripts.pory"
	end
# 280 "data//maps/Route103/scripts.pory"

# 281 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 282 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 283 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 284 "data//maps/Route103/scripts.pory"
	end
# 285 "data//maps/Route103/scripts.pory"

# 286 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 287 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 288 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 289 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 290 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 291 "data//maps/Route103/scripts.pory"
	release
# 292 "data//maps/Route103/scripts.pory"
	end
# 293 "data//maps/Route103/scripts.pory"

# 294 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 295 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 296 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 297 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 298 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 299 "data//maps/Route103/scripts.pory"
	release
# 300 "data//maps/Route103/scripts.pory"
	end
# 301 "data//maps/Route103/scripts.pory"

# 302 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 303 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 304 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 305 "data//maps/Route103/scripts.pory"
	end
# 306 "data//maps/Route103/scripts.pory"

# 307 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 308 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 309 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 310 "data//maps/Route103/scripts.pory"
	end
# 311 "data//maps/Route103/scripts.pory"

# 312 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 313 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 314 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 315 "data//maps/Route103/scripts.pory"
	end
# 316 "data//maps/Route103/scripts.pory"

# 317 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 318 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 319 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 320 "data//maps/Route103/scripts.pory"
	end
# 321 "data//maps/Route103/scripts.pory"

# 322 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 323 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 324 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 325 "data//maps/Route103/scripts.pory"
	end
# 326 "data//maps/Route103/scripts.pory"

# 327 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 328 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 329 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 330 "data//maps/Route103/scripts.pory"

# 331 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 332 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 333 "data//maps/Route103/scripts.pory"
	.string "That old geezer wanted us\n"
# 334 "data//maps/Route103/scripts.pory"
	.string "to battle?\p"
# 335 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 336 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 337 "data//maps/Route103/scripts.pory"

# 338 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 339 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 340 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 341 "data//maps/Route103/scripts.pory"

# 342 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 343 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 344 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 345 "data//maps/Route103/scripts.pory"
	.string "I mean you found your way out here\n"
# 346 "data//maps/Route103/scripts.pory"
	.string "with dangerous POKéMON everywhere.\p"
# 347 "data//maps/Route103/scripts.pory"
	.string "You might be able to defeat any\n"
# 348 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 349 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 350 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 351 "data//maps/Route103/scripts.pory"

# 352 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 353 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 354 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 355 "data//maps/Route103/scripts.pory"

# 356 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 357 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 358 "data//maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 359 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 360 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 361 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 362 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 363 "data//maps/Route103/scripts.pory"

# 364 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 365 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 366 "data//maps/Route103/scripts.pory"

# 367 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 368 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 369 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 370 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 371 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 372 "data//maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 373 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 374 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 375 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 376 "data//maps/Route103/scripts.pory"

# 377 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 378 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 379 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 380 "data//maps/Route103/scripts.pory"

# 381 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 382 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 383 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 384 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 385 "data//maps/Route103/scripts.pory"

# 386 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 387 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 388 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
