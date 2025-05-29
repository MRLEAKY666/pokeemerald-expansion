# 1 "data//maps/Route120/scripts.pory"

# 2 "data//maps/Route120/scripts.pory"
Route120_MapScripts::
# 3 "data//maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 4 "data//maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 5 "data//maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
# 6 "data//maps/Route120/scripts.pory"
	.byte 0
# 7 "data//maps/Route120/scripts.pory"

# 8 "data//maps/Route120/scripts.pory"
Route120_OnResume:
# 9 "data//maps/Route120/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 10 "data//maps/Route120/scripts.pory"
	end
# 11 "data//maps/Route120/scripts.pory"

# 12 "data//maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject::
# 13 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
# 14 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
# 15 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
# 16 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
# 17 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
# 18 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
# 19 "data//maps/Route120/scripts.pory"
	return
# 20 "data//maps/Route120/scripts.pory"

# 21 "data//maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon::
# 22 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data//maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 24 "data//maps/Route120/scripts.pory"
	@ removeobject LOCALID_ROUTE120_BRIDGE_KECLEON
# 25 "data//maps/Route120/scripts.pory"
	@ removeobject LOCALID_ROUTE120_BRIDGE_KECLEON_SHADOW
# 26 "data//maps/Route120/scripts.pory"
	return
# 27 "data//maps/Route120/scripts.pory"

# 28 "data//maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon::
# 29 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data//maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 31 "data//maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 32 "data//maps/Route120/scripts.pory"
	return
# 33 "data//maps/Route120/scripts.pory"

# 34 "data//maps/Route120/scripts.pory"
Route120_OnLoad:
# 35 "data//maps/Route120/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
# 36 "data//maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 37 "data//maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 38 "data//maps/Route120/scripts.pory"
	end
# 39 "data//maps/Route120/scripts.pory"

# 40 "data//maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb::
# 41 "data//maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
# 42 "data//maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
# 43 "data//maps/Route120/scripts.pory"
	return
# 44 "data//maps/Route120/scripts.pory"

# 45 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles::
# 46 "data//maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 47 "data//maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 48 "data//maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 49 "data//maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 50 "data//maps/Route120/scripts.pory"
	return
# 51 "data//maps/Route120/scripts.pory"

# 52 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement::
# 53 "data//maps/Route120/scripts.pory"
	@ setobjectmovementtype LOCALID_ROUTE120_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 54 "data//maps/Route120/scripts.pory"
	return
# 55 "data//maps/Route120/scripts.pory"

# 56 "data//maps/Route120/scripts.pory"
Route120_OnTransition:
# 57 "data//maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 58 "data//maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 59 "data//maps/Route120/scripts.pory"
	end
# 60 "data//maps/Route120/scripts.pory"

# 61 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetWeather::
# 62 "data//maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 63 "data//maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
# 64 "data//maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
# 65 "data//maps/Route120/scripts.pory"
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
# 66 "data//maps/Route120/scripts.pory"
	return
# 67 "data//maps/Route120/scripts.pory"

# 68 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather::
# 69 "data//maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 70 "data//maps/Route120/scripts.pory"
	return
# 71 "data//maps/Route120/scripts.pory"

# 72 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather::
# 73 "data//maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 74 "data//maps/Route120/scripts.pory"
	return
# 75 "data//maps/Route120/scripts.pory"

# 76 "data//maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather::
# 77 "data//maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
# 78 "data//maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
# 79 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 80 "data//maps/Route120/scripts.pory"
	end
# 81 "data//maps/Route120/scripts.pory"

# 82 "data//maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather::
# 83 "data//maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 84 "data//maps/Route120/scripts.pory"
	return
# 85 "data//maps/Route120/scripts.pory"

# 86 "data//maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty::
# 87 "data//maps/Route120/scripts.pory"
	lock
# 88 "data//maps/Route120/scripts.pory"
	faceplayer
# 89 "data//maps/Route120/scripts.pory"
	dotimebasedevents
# 90 "data//maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 91 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 92 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
# 93 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
# 94 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 95 "data//maps/Route120/scripts.pory"
	switch VAR_RESULT
# 96 "data//maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 97 "data//maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 98 "data//maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 99 "data//maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 100 "data//maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 101 "data//maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 102 "data//maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 103 "data//maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 104 "data//maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 105 "data//maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 106 "data//maps/Route120/scripts.pory"
	end
# 107 "data//maps/Route120/scripts.pory"

# 108 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry::
# 109 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 110 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 111 "data//maps/Route120/scripts.pory"
	end
# 112 "data//maps/Route120/scripts.pory"

# 113 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry::
# 114 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 115 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 116 "data//maps/Route120/scripts.pory"
	end
# 117 "data//maps/Route120/scripts.pory"

# 118 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry::
# 119 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 120 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 121 "data//maps/Route120/scripts.pory"
	end
# 122 "data//maps/Route120/scripts.pory"

# 123 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry::
# 124 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 125 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 126 "data//maps/Route120/scripts.pory"
	end
# 127 "data//maps/Route120/scripts.pory"

# 128 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry::
# 129 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 130 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 131 "data//maps/Route120/scripts.pory"
	end
# 132 "data//maps/Route120/scripts.pory"

# 133 "data//maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry::
# 134 "data//maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 135 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 136 "data//maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 137 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 138 "data//maps/Route120/scripts.pory"
	release
# 139 "data//maps/Route120/scripts.pory"
	end
# 140 "data//maps/Route120/scripts.pory"

# 141 "data//maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry::
# 142 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 143 "data//maps/Route120/scripts.pory"
	release
# 144 "data//maps/Route120/scripts.pory"
	end
# 145 "data//maps/Route120/scripts.pory"

# 146 "data//maps/Route120/scripts.pory"
Route120_EventScript_BerryLove::
# 147 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 148 "data//maps/Route120/scripts.pory"
	return
# 149 "data//maps/Route120/scripts.pory"

# 150 "data//maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove::
# 151 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 152 "data//maps/Route120/scripts.pory"
	return
# 153 "data//maps/Route120/scripts.pory"

# 154 "data//maps/Route120/scripts.pory"
Route120_EventScript_Steven::
# 155 "data//maps/Route120/scripts.pory"
	lock
# 156 "data//maps/Route120/scripts.pory"
	faceplayer
# 157 "data//maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 158 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 159 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 160 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 161 "data//maps/Route120/scripts.pory"
	end
# 162 "data//maps/Route120/scripts.pory"

# 163 "data//maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady::
# 164 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 165 "data//maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 166 "data//maps/Route120/scripts.pory"
	release
# 167 "data//maps/Route120/scripts.pory"
	end
# 168 "data//maps/Route120/scripts.pory"

# 169 "data//maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle::
# 170 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 171 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 172 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 173 "data//maps/Route120/scripts.pory"
	end
# 174 "data//maps/Route120/scripts.pory"

# 175 "data//maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon::
# 176 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 177 "data//maps/Route120/scripts.pory"
	closemessage
# 178 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route120_EventScript_PlayerApproachKecleonNorth
# 179 "data//maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route120_EventScript_PlayerApproachKecleonWest
# 180 "data//maps/Route120/scripts.pory"
	@ applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 181 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 182 "data//maps/Route120/scripts.pory"
	delay 20
# 183 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 184 "data//maps/Route120/scripts.pory"
	closemessage
# 185 "data//maps/Route120/scripts.pory"
	@ applymovement LOCALID_ROUTE120_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterRight
# 186 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 187 "data//maps/Route120/scripts.pory"
	@ applymovement LOCALID_ROUTE120_BRIDGE_KECLEON, Movement_KecleonAppears
# 188 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 189 "data//maps/Route120/scripts.pory"
	waitse
# 190 "data//maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 191 "data//maps/Route120/scripts.pory"
	delay 40
# 192 "data//maps/Route120/scripts.pory"
	waitmoncry
# 193 "data//maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, 30
# 194 "data//maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 195 "data//maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 196 "data//maps/Route120/scripts.pory"
	dowildbattle
# 197 "data//maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 198 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 199 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 200 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 201 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 202 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 203 "data//maps/Route120/scripts.pory"
	end
# 204 "data//maps/Route120/scripts.pory"

# 205 "data//maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle::
# 206 "data//maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 207 "data//maps/Route120/scripts.pory"
	@ removeobject LOCALID_ROUTE120_BRIDGE_KECLEON
# 208 "data//maps/Route120/scripts.pory"
	@ removeobject LOCALID_ROUTE120_BRIDGE_KECLEON_SHADOW
# 209 "data//maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 210 "data//maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 211 "data//maps/Route120/scripts.pory"
	end
# 212 "data//maps/Route120/scripts.pory"

# 213 "data//maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope::
# 214 "data//maps/Route120/scripts.pory"
	@ applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 215 "data//maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 216 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 217 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 218 "data//maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 219 "data//maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 220 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 221 "data//maps/Route120/scripts.pory"
	closemessage
# 222 "data//maps/Route120/scripts.pory"
	@ applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 223 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 224 "data//maps/Route120/scripts.pory"
	delay 50
# 225 "data//maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 226 "data//maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 227 "data//maps/Route120/scripts.pory"
	delay 15
# 228 "data//maps/Route120/scripts.pory"
	@ removeobject LOCALID_ROUTE120_STEVEN
# 229 "data//maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 230 "data//maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 231 "data//maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 232 "data//maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 233 "data//maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 234 "data//maps/Route120/scripts.pory"
	special DrawWholeMapView
# 235 "data//maps/Route120/scripts.pory"
	release
# 236 "data//maps/Route120/scripts.pory"
	end
# 237 "data//maps/Route120/scripts.pory"

# 238 "data//maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth::
# 239 "data//maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 240 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 241 "data//maps/Route120/scripts.pory"
	return
# 242 "data//maps/Route120/scripts.pory"

# 243 "data//maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonWest::
# 244 "data//maps/Route120/scripts.pory"
	applymovement LOCALID_PLAYER, Route120_Movement_ApproachKecleonWest
# 245 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 246 "data//maps/Route120/scripts.pory"
	return
# 247 "data//maps/Route120/scripts.pory"

# 248 "data//maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonWest:
# 249 "data//maps/Route120/scripts.pory"
	walk_down
# 250 "data//maps/Route120/scripts.pory"
	walk_left
# 251 "data//maps/Route120/scripts.pory"
	step_end
# 252 "data//maps/Route120/scripts.pory"

# 253 "data//maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon::
# 254 "data//maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 255 "data//maps/Route120/scripts.pory"
	end
# 256 "data//maps/Route120/scripts.pory"

# 257 "data//maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree::
# 258 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 259 "data//maps/Route120/scripts.pory"
	end
# 260 "data//maps/Route120/scripts.pory"

# 261 "data//maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121::
# 262 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 263 "data//maps/Route120/scripts.pory"
	end
# 264 "data//maps/Route120/scripts.pory"

# 265 "data//maps/Route120/scripts.pory"
Route120_EventScript_Colin::
# 266 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
# 267 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 268 "data//maps/Route120/scripts.pory"
	end
# 269 "data//maps/Route120/scripts.pory"

# 270 "data//maps/Route120/scripts.pory"
Route120_EventScript_Robert::
# 271 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
# 272 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 273 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
# 274 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 275 "data//maps/Route120/scripts.pory"
	release
# 276 "data//maps/Route120/scripts.pory"
	end
# 277 "data//maps/Route120/scripts.pory"

# 278 "data//maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert::
# 279 "data//maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 280 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 281 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 282 "data//maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 283 "data//maps/Route120/scripts.pory"
	release
# 284 "data//maps/Route120/scripts.pory"
	end
# 285 "data//maps/Route120/scripts.pory"

# 286 "data//maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert::
# 287 "data//maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 288 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 289 "data//maps/Route120/scripts.pory"
	end
# 290 "data//maps/Route120/scripts.pory"

# 291 "data//maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo::
# 292 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
# 293 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 294 "data//maps/Route120/scripts.pory"
	end
# 295 "data//maps/Route120/scripts.pory"

# 296 "data//maps/Route120/scripts.pory"
Route120_EventScript_Jenna::
# 297 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
# 298 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 299 "data//maps/Route120/scripts.pory"
	end
# 300 "data//maps/Route120/scripts.pory"

# 301 "data//maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey::
# 302 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
# 303 "data//maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 304 "data//maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
# 305 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 306 "data//maps/Route120/scripts.pory"
	release
# 307 "data//maps/Route120/scripts.pory"
	end
# 308 "data//maps/Route120/scripts.pory"

# 309 "data//maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey::
# 310 "data//maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 311 "data//maps/Route120/scripts.pory"
	waitmovement 0
# 312 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 313 "data//maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 314 "data//maps/Route120/scripts.pory"
	release
# 315 "data//maps/Route120/scripts.pory"
	end
# 316 "data//maps/Route120/scripts.pory"

# 317 "data//maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey::
# 318 "data//maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 319 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 320 "data//maps/Route120/scripts.pory"
	end
# 321 "data//maps/Route120/scripts.pory"

# 322 "data//maps/Route120/scripts.pory"
Route120_EventScript_Jennifer::
# 323 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
# 324 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 325 "data//maps/Route120/scripts.pory"
	end
# 326 "data//maps/Route120/scripts.pory"

# 327 "data//maps/Route120/scripts.pory"
Route120_EventScript_Chip::
# 328 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
# 329 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 330 "data//maps/Route120/scripts.pory"
	end
# 331 "data//maps/Route120/scripts.pory"

# 332 "data//maps/Route120/scripts.pory"
Route120_EventScript_Clarissa::
# 333 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
# 334 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 335 "data//maps/Route120/scripts.pory"
	end
# 336 "data//maps/Route120/scripts.pory"

# 337 "data//maps/Route120/scripts.pory"
Route120_EventScript_Angelica::
# 338 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
# 339 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 340 "data//maps/Route120/scripts.pory"
	end
# 341 "data//maps/Route120/scripts.pory"

# 342 "data//maps/Route120/scripts.pory"
Route120_EventScript_Keigo::
# 343 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
# 344 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 345 "data//maps/Route120/scripts.pory"
	end
# 346 "data//maps/Route120/scripts.pory"

# 347 "data//maps/Route120/scripts.pory"
Route120_EventScript_Riley::
# 348 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
# 349 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 350 "data//maps/Route120/scripts.pory"
	end
# 351 "data//maps/Route120/scripts.pory"

# 352 "data//maps/Route120/scripts.pory"
Route120_EventScript_Leonel::
# 353 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 354 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 355 "data//maps/Route120/scripts.pory"
	end
# 356 "data//maps/Route120/scripts.pory"

# 357 "data//maps/Route120/scripts.pory"
Route120_EventScript_Callie::
# 358 "data//maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
# 359 "data//maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 360 "data//maps/Route120/scripts.pory"
	end
# 361 "data//maps/Route120/scripts.pory"

# 362 "data//maps/Route120/scripts.pory"
Route120_Text_StevenGreeting:
# 363 "data//maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
# 364 "data//maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 365 "data//maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 366 "data//maps/Route120/scripts.pory"
	.string "see, right?\p"
# 367 "data//maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 368 "data//maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 369 "data//maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 370 "data//maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 371 "data//maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 372 "data//maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
# 373 "data//maps/Route120/scripts.pory"
	.string "battle?$"
# 374 "data//maps/Route120/scripts.pory"

# 375 "data//maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere:
# 376 "data//maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
# 377 "data//maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 378 "data//maps/Route120/scripts.pory"

# 379 "data//maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle:
# 380 "data//maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
# 381 "data//maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 382 "data//maps/Route120/scripts.pory"

# 383 "data//maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower:
# 384 "data//maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
# 385 "data//maps/Route120/scripts.pory"
	.string "power as a TRAINER!$"
# 386 "data//maps/Route120/scripts.pory"

# 387 "data//maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope:
# 388 "data//maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
# 389 "data//maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 390 "data//maps/Route120/scripts.pory"
	.string "visible!\p"
# 391 "data//maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 392 "data//maps/Route120/scripts.pory"

# 393 "data//maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope:
# 394 "data//maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
# 395 "data//maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 396 "data//maps/Route120/scripts.pory"
	.string "Your POKéMON have obviously grown\n"
# 397 "data//maps/Route120/scripts.pory"
	.string "since I first met you in DEWFORD.\p"
# 398 "data//maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 399 "data//maps/Route120/scripts.pory"
	.string "DEVON SCOPE.\p"
# 400 "data//maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 401 "data//maps/Route120/scripts.pory"
	.string "concealed POKéMON.$"
# 402 "data//maps/Route120/scripts.pory"

# 403 "data//maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye:
# 404 "data//maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
# 405 "data//maps/Route120/scripts.pory"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
# 406 "data//maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 407 "data//maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 408 "data//maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 409 "data//maps/Route120/scripts.pory"

# 410 "data//maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable:
# 411 "data//maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 412 "data//maps/Route120/scripts.pory"

# 413 "data//maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope:
# 414 "data//maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 415 "data//maps/Route120/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 416 "data//maps/Route120/scripts.pory"

# 417 "data//maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked:
# 418 "data//maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 419 "data//maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 420 "data//maps/Route120/scripts.pory"
	.string "visible!\p"
# 421 "data//maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 422 "data//maps/Route120/scripts.pory"

# 423 "data//maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree:
# 424 "data//maps/Route120/scripts.pory"
	.string "ROUTE 120\n"
# 425 "data//maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} FORTREE CITY$"
# 426 "data//maps/Route120/scripts.pory"

# 427 "data//maps/Route120/scripts.pory"
Route120_Text_RouteSign121:
# 428 "data//maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121\n"
# 429 "data//maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 120$"
