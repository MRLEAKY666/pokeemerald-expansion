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
	case SPECIES_TREECKO, Route103_EventScript_BattleMayA
# 44 "data//maps/Route103/scripts.pory"
	case SPECIES_TORCHIC, Route103_EventScript_BattleMayB
# 45 "data//maps/Route103/scripts.pory"
	case SPECIES_MUDKIP, Route103_EventScript_BattleMayC
# 46 "data//maps/Route103/scripts.pory"
	case SPECIES_CASTFORM, Route103_EventScript_BattleMayA
# 47 "data//maps/Route103/scripts.pory"
	case SPECIES_PIPLUP, Route103_EventScript_BattleMayC
# 48 "data//maps/Route103/scripts.pory"
	case SPECIES_EEVEE, Route103_EventScript_BattleMayA
# 49 "data//maps/Route103/scripts.pory"
	case SPECIES_PICHU, Route103_EventScript_BattleMayB
# 50 "data//maps/Route103/scripts.pory"
	case SPECIES_TOGEPI, Route103_EventScript_BattleMayC
# 51 "data//maps/Route103/scripts.pory"
	case SPECIES_PORYGON, Route103_EventScript_BattleMayA
# 52 "data//maps/Route103/scripts.pory"
	case SPECIES_SNIVY, Route103_EventScript_BattleMayA
# 53 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA_HISUI, Route103_EventScript_BattleMayA
# 54 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA, Route103_EventScript_BattleMayA
# 55 "data//maps/Route103/scripts.pory"
	case SPECIES_GOTHITA, Route103_EventScript_BattleMayB
# 56 "data//maps/Route103/scripts.pory"
	case SPECIES_SOLOSIS, Route103_EventScript_BattleMayB
# 57 "data//maps/Route103/scripts.pory"
	case SPECIES_AXEW, Route103_EventScript_BattleMayC
# 58 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVESTA, Route103_EventScript_BattleMayB
# 59 "data//maps/Route103/scripts.pory"
	case SPECIES_GOOMY, Route103_EventScript_BattleMayC
# 60 "data//maps/Route103/scripts.pory"
	case SPECIES_ROWLET, Route103_EventScript_BattleMayA
# 61 "data//maps/Route103/scripts.pory"
	case SPECIES_APPLIN, Route103_EventScript_BattleMayA
# 62 "data//maps/Route103/scripts.pory"
	case SPECIES_MIME_JR, Route103_EventScript_BattleMayB
# 63 "data//maps/Route103/scripts.pory"
	case SPECIES_MAGBY, Route103_EventScript_BattleMayB
# 64 "data//maps/Route103/scripts.pory"
	case SPECIES_ELEKID, Route103_EventScript_BattleMayB
# 65 "data//maps/Route103/scripts.pory"
	case SPECIES_MANKEY, Route103_EventScript_BattleMayA
# 66 "data//maps/Route103/scripts.pory"
	case SPECIES_SWINUB, Route103_EventScript_BattleMayC
# 67 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVITAR, Route103_EventScript_BattleMayA
# 68 "data//maps/Route103/scripts.pory"
	case SPECIES_TURTWIG, Route103_EventScript_BattleMayA
# 69 "data//maps/Route103/scripts.pory"
	case SPECIES_CHARMANDER, Route103_EventScript_BattleMayB
# 70 "data//maps/Route103/scripts.pory"
	case SPECIES_SQUIRTLE, Route103_EventScript_BattleMayC
# 71 "data//maps/Route103/scripts.pory"
	case SPECIES_BULBASAUR, Route103_EventScript_BattleMayA
# 72 "data//maps/Route103/scripts.pory"
	case SPECIES_OSHAWOTT, Route103_EventScript_BattleMayC
# 73 "data//maps/Route103/scripts.pory"
	case SPECIES_CYNDAQUIL, Route103_EventScript_BattleMayB
# 74 "data//maps/Route103/scripts.pory"
	case SPECIES_BUDEW, Route103_EventScript_BattleMayA
# 75 "data//maps/Route103/scripts.pory"
	case SPECIES_SPHEAL, Route103_EventScript_BattleMayA
# 76 "data//maps/Route103/scripts.pory"
	case SPECIES_SHINX, Route103_EventScript_BattleMayB
# 77 "data//maps/Route103/scripts.pory"
	case SPECIES_SANDILE, Route103_EventScript_BattleMayC
# 78 "data//maps/Route103/scripts.pory"
	case SPECIES_PAWNIARD, Route103_EventScript_BattleMayA
# 79 "data//maps/Route103/scripts.pory"
	case SPECIES_JANGMO_O, Route103_EventScript_BattleMayA
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
	case SPECIES_TREECKO, Route103_EventScript_BattleBrendanA
# 95 "data//maps/Route103/scripts.pory"
	case SPECIES_TORCHIC, Route103_EventScript_BattleBrendanB
# 96 "data//maps/Route103/scripts.pory"
	case SPECIES_MUDKIP, Route103_EventScript_BattleBrendanC
# 97 "data//maps/Route103/scripts.pory"
	case SPECIES_CASTFORM, Route103_EventScript_BattleBrendanA
# 98 "data//maps/Route103/scripts.pory"
	case SPECIES_PIPLUP, Route103_EventScript_BattleBrendanC
# 99 "data//maps/Route103/scripts.pory"
	case SPECIES_EEVEE, Route103_EventScript_BattleBrendanA
# 100 "data//maps/Route103/scripts.pory"
	case SPECIES_PICHU, Route103_EventScript_BattleBrendanB
# 101 "data//maps/Route103/scripts.pory"
	case SPECIES_TOGEPI, Route103_EventScript_BattleBrendanC
# 102 "data//maps/Route103/scripts.pory"
	case SPECIES_PORYGON, Route103_EventScript_BattleBrendanA
# 103 "data//maps/Route103/scripts.pory"
	case SPECIES_SNIVY, Route103_EventScript_BattleBrendanA
# 104 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA_HISUI, Route103_EventScript_BattleBrendanA
# 105 "data//maps/Route103/scripts.pory"
	case SPECIES_ZORUA, Route103_EventScript_BattleBrendanA
# 106 "data//maps/Route103/scripts.pory"
	case SPECIES_GOTHITA, Route103_EventScript_BattleBrendanB
# 107 "data//maps/Route103/scripts.pory"
	case SPECIES_SOLOSIS, Route103_EventScript_BattleBrendanB
# 108 "data//maps/Route103/scripts.pory"
	case SPECIES_AXEW, Route103_EventScript_BattleBrendanC
# 109 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVESTA, Route103_EventScript_BattleBrendanB
# 110 "data//maps/Route103/scripts.pory"
	case SPECIES_GOOMY, Route103_EventScript_BattleBrendanC
# 111 "data//maps/Route103/scripts.pory"
	case SPECIES_ROWLET, Route103_EventScript_BattleBrendanA
# 112 "data//maps/Route103/scripts.pory"
	case SPECIES_APPLIN, Route103_EventScript_BattleBrendanA
# 113 "data//maps/Route103/scripts.pory"
	case SPECIES_MIME_JR, Route103_EventScript_BattleBrendanB
# 114 "data//maps/Route103/scripts.pory"
	case SPECIES_MAGBY, Route103_EventScript_BattleBrendanB
# 115 "data//maps/Route103/scripts.pory"
	case SPECIES_ELEKID, Route103_EventScript_BattleBrendanB
# 116 "data//maps/Route103/scripts.pory"
	case SPECIES_MANKEY, Route103_EventScript_BattleBrendanA
# 117 "data//maps/Route103/scripts.pory"
	case SPECIES_SWINUB, Route103_EventScript_BattleBrendanC
# 118 "data//maps/Route103/scripts.pory"
	case SPECIES_LARVITAR, Route103_EventScript_BattleBrendanA
# 119 "data//maps/Route103/scripts.pory"
	case SPECIES_TURTWIG, Route103_EventScript_BattleBrendanA
# 120 "data//maps/Route103/scripts.pory"
	case SPECIES_CHARMANDER, Route103_EventScript_BattleBrendanB
# 121 "data//maps/Route103/scripts.pory"
	case SPECIES_SQUIRTLE, Route103_EventScript_BattleBrendanC
# 122 "data//maps/Route103/scripts.pory"
	case SPECIES_BULBASAUR, Route103_EventScript_BattleBrendanA
# 123 "data//maps/Route103/scripts.pory"
	case SPECIES_OSHAWOTT, Route103_EventScript_BattleBrendanC
# 124 "data//maps/Route103/scripts.pory"
	case SPECIES_CYNDAQUIL, Route103_EventScript_BattleBrendanB
# 125 "data//maps/Route103/scripts.pory"
	case SPECIES_BUDEW, Route103_EventScript_BattleBrendanA
# 126 "data//maps/Route103/scripts.pory"
	case SPECIES_SPHEAL, Route103_EventScript_BattleBrendanA
# 127 "data//maps/Route103/scripts.pory"
	case SPECIES_SHINX, Route103_EventScript_BattleBrendanB
# 128 "data//maps/Route103/scripts.pory"
	case SPECIES_SANDILE, Route103_EventScript_BattleBrendanC
# 129 "data//maps/Route103/scripts.pory"
	case SPECIES_PAWNIARD, Route103_EventScript_BattleBrendanA
# 130 "data//maps/Route103/scripts.pory"
	case SPECIES_JANGMO_O, Route103_EventScript_BattleBrendanA
# 131 "data//maps/Route103/scripts.pory"
	end
# 132 "data//maps/Route103/scripts.pory"

# 133 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleMayA::
# 134 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_A, Route103_Text_MayDefeated
# 135 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 136 "data//maps/Route103/scripts.pory"
	end
# 137 "data//maps/Route103/scripts.pory"

# 138 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleMayB::
# 139 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_B, Route103_Text_MayDefeated
# 140 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 141 "data//maps/Route103/scripts.pory"
	end
# 142 "data//maps/Route103/scripts.pory"

# 143 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleMayC::
# 144 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_C, Route103_Text_MayDefeated
# 145 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 146 "data//maps/Route103/scripts.pory"
	end
# 147 "data//maps/Route103/scripts.pory"

# 148 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleBrendanA::
# 149 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_A, Route103_Text_BrendanDefeated
# 150 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 151 "data//maps/Route103/scripts.pory"
	end
# 152 "data//maps/Route103/scripts.pory"

# 153 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleBrendanB::
# 154 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_B, Route103_Text_BrendanDefeated
# 155 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 156 "data//maps/Route103/scripts.pory"
	end
# 157 "data//maps/Route103/scripts.pory"

# 158 "data//maps/Route103/scripts.pory"
Route103_EventScript_BattleBrendanC::
# 159 "data//maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_C, Route103_Text_BrendanDefeated
# 160 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 161 "data//maps/Route103/scripts.pory"
	end
# 162 "data//maps/Route103/scripts.pory"

# 163 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 164 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 165 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 166 "data//maps/Route103/scripts.pory"
	end
# 167 "data//maps/Route103/scripts.pory"

# 168 "data//maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 169 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 170 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 171 "data//maps/Route103/scripts.pory"
	end
# 172 "data//maps/Route103/scripts.pory"

# 173 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 174 "data//maps/Route103/scripts.pory"
	closemessage
# 175 "data//maps/Route103/scripts.pory"
	switch VAR_FACING
# 176 "data//maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 177 "data//maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 178 "data//maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 179 "data//maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 180 "data//maps/Route103/scripts.pory"
	end
# 181 "data//maps/Route103/scripts.pory"

# 182 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 183 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 184 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 185 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 186 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 187 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 188 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 189 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 190 "data//maps/Route103/scripts.pory"
	end
# 191 "data//maps/Route103/scripts.pory"

# 192 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 193 "data//maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 194 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 195 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 196 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 197 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 198 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 199 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 200 "data//maps/Route103/scripts.pory"
	end
# 201 "data//maps/Route103/scripts.pory"

# 202 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 203 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 204 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 205 "data//maps/Route103/scripts.pory"
	playse SE_LEDGE
# 206 "data//maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 207 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 208 "data//maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 209 "data//maps/Route103/scripts.pory"
	end
# 210 "data//maps/Route103/scripts.pory"

# 211 "data//maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 212 "data//maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 213 "data//maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 214 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 215 "data//maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 216 "data//maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 217 "data//maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 218 "data//maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 219 "data//maps/Route103/scripts.pory"
	fadedefaultbgm
# 220 "data//maps/Route103/scripts.pory"
	releaseall
# 221 "data//maps/Route103/scripts.pory"
	end
# 222 "data//maps/Route103/scripts.pory"

# 223 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 224 "data//maps/Route103/scripts.pory"
	walk_left
# 225 "data//maps/Route103/scripts.pory"
	walk_down
# 226 "data//maps/Route103/scripts.pory"
	step_end
# 227 "data//maps/Route103/scripts.pory"

# 228 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 229 "data//maps/Route103/scripts.pory"
	jump_2_down
# 230 "data//maps/Route103/scripts.pory"
	delay_16
# 231 "data//maps/Route103/scripts.pory"
	walk_down
# 232 "data//maps/Route103/scripts.pory"
	walk_down
# 233 "data//maps/Route103/scripts.pory"
	walk_down
# 234 "data//maps/Route103/scripts.pory"
	walk_down
# 235 "data//maps/Route103/scripts.pory"
	step_end
# 236 "data//maps/Route103/scripts.pory"

# 237 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 238 "data//maps/Route103/scripts.pory"
	delay_16
# 239 "data//maps/Route103/scripts.pory"
	delay_4
# 240 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 241 "data//maps/Route103/scripts.pory"
	delay_16
# 242 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 243 "data//maps/Route103/scripts.pory"
	step_end
# 244 "data//maps/Route103/scripts.pory"

# 245 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 246 "data//maps/Route103/scripts.pory"
	walk_down
# 247 "data//maps/Route103/scripts.pory"
	step_end
# 248 "data//maps/Route103/scripts.pory"

# 249 "data//maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 250 "data//maps/Route103/scripts.pory"
	jump_2_down
# 251 "data//maps/Route103/scripts.pory"
	delay_16
# 252 "data//maps/Route103/scripts.pory"
	walk_down
# 253 "data//maps/Route103/scripts.pory"
	walk_down
# 254 "data//maps/Route103/scripts.pory"
	walk_down
# 255 "data//maps/Route103/scripts.pory"
	step_end
# 256 "data//maps/Route103/scripts.pory"

# 257 "data//maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 258 "data//maps/Route103/scripts.pory"
	delay_16
# 259 "data//maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 260 "data//maps/Route103/scripts.pory"
	step_end
# 261 "data//maps/Route103/scripts.pory"

# 262 "data//maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 263 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 264 "data//maps/Route103/scripts.pory"
	end
# 265 "data//maps/Route103/scripts.pory"

# 266 "data//maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 267 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 268 "data//maps/Route103/scripts.pory"
	end
# 269 "data//maps/Route103/scripts.pory"

# 270 "data//maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 271 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 272 "data//maps/Route103/scripts.pory"
	end
# 273 "data//maps/Route103/scripts.pory"

# 274 "data//maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 275 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 276 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 277 "data//maps/Route103/scripts.pory"
	end
# 278 "data//maps/Route103/scripts.pory"

# 279 "data//maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 280 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 281 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 282 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 283 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 284 "data//maps/Route103/scripts.pory"
	end
# 285 "data//maps/Route103/scripts.pory"

# 286 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 287 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 288 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 289 "data//maps/Route103/scripts.pory"
	release
# 290 "data//maps/Route103/scripts.pory"
	end
# 291 "data//maps/Route103/scripts.pory"

# 292 "data//maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 293 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 294 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 295 "data//maps/Route103/scripts.pory"
	end
# 296 "data//maps/Route103/scripts.pory"

# 297 "data//maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 298 "data//maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 299 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 300 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 301 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 302 "data//maps/Route103/scripts.pory"
	end
# 303 "data//maps/Route103/scripts.pory"

# 304 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 305 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 306 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 307 "data//maps/Route103/scripts.pory"
	release
# 308 "data//maps/Route103/scripts.pory"
	end
# 309 "data//maps/Route103/scripts.pory"

# 310 "data//maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 311 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 312 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 313 "data//maps/Route103/scripts.pory"
	end
# 314 "data//maps/Route103/scripts.pory"

# 315 "data//maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 316 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 317 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 318 "data//maps/Route103/scripts.pory"
	end
# 319 "data//maps/Route103/scripts.pory"

# 320 "data//maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 321 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 322 "data//maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 323 "data//maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 324 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 325 "data//maps/Route103/scripts.pory"
	release
# 326 "data//maps/Route103/scripts.pory"
	end
# 327 "data//maps/Route103/scripts.pory"

# 328 "data//maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 329 "data//maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 330 "data//maps/Route103/scripts.pory"
	waitmovement 0
# 331 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 332 "data//maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 333 "data//maps/Route103/scripts.pory"
	release
# 334 "data//maps/Route103/scripts.pory"
	end
# 335 "data//maps/Route103/scripts.pory"

# 336 "data//maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 337 "data//maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 338 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 339 "data//maps/Route103/scripts.pory"
	end
# 340 "data//maps/Route103/scripts.pory"

# 341 "data//maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 342 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 343 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 344 "data//maps/Route103/scripts.pory"
	end
# 345 "data//maps/Route103/scripts.pory"

# 346 "data//maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 347 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 348 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 349 "data//maps/Route103/scripts.pory"
	end
# 350 "data//maps/Route103/scripts.pory"

# 351 "data//maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 352 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 353 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 354 "data//maps/Route103/scripts.pory"
	end
# 355 "data//maps/Route103/scripts.pory"

# 356 "data//maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 357 "data//maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 358 "data//maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 359 "data//maps/Route103/scripts.pory"
	end
# 360 "data//maps/Route103/scripts.pory"

# 361 "data//maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 362 "data//maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 363 "data//maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 364 "data//maps/Route103/scripts.pory"

# 365 "data//maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 366 "data//maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 367 "data//maps/Route103/scripts.pory"
	.string "That old geezer wanted us\n"
# 368 "data//maps/Route103/scripts.pory"
	.string "to battle?\p"
# 369 "data//maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 370 "data//maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 371 "data//maps/Route103/scripts.pory"

# 372 "data//maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 373 "data//maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 374 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 375 "data//maps/Route103/scripts.pory"

# 376 "data//maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 377 "data//maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 378 "data//maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 379 "data//maps/Route103/scripts.pory"
	.string "I mean you found your way out here\n"
# 380 "data//maps/Route103/scripts.pory"
	.string "with dangerous POKéMON everywhere.\p"
# 381 "data//maps/Route103/scripts.pory"
	.string "You might be able to defeat any\n"
# 382 "data//maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 383 "data//maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 384 "data//maps/Route103/scripts.pory"
	.string "the LAB.$"
# 385 "data//maps/Route103/scripts.pory"

# 386 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 387 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 388 "data//maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 389 "data//maps/Route103/scripts.pory"

# 390 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 391 "data//maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 392 "data//maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 393 "data//maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 394 "data//maps/Route103/scripts.pory"
	.string "battle?\p"
# 395 "data//maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 396 "data//maps/Route103/scripts.pory"
	.string "about!$"
# 397 "data//maps/Route103/scripts.pory"

# 398 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 399 "data//maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 400 "data//maps/Route103/scripts.pory"

# 401 "data//maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 402 "data//maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 403 "data//maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 404 "data//maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 405 "data//maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 406 "data//maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 407 "data//maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 408 "data//maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 409 "data//maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 410 "data//maps/Route103/scripts.pory"

# 411 "data//maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 412 "data//maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 413 "data//maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 414 "data//maps/Route103/scripts.pory"

# 415 "data//maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 416 "data//maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 417 "data//maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 418 "data//maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 419 "data//maps/Route103/scripts.pory"

# 420 "data//maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 421 "data//maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 422 "data//maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
