# 1 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 2 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_1, 1
# 3 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_2, 2
# 4 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_SHELLY, 3
# 5 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_SCIENTIST, 5
# 6 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_3, 7
# 7 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_4, 8
# 8 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 9 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_MapScripts::
# 10 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
# 11 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.byte 0
# 12 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 13 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_OnTransition:
# 14 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
# 15 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
# 16 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
# 17 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 18 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 19 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
# 20 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
# 21 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 22 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 23 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 24 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
# 25 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
# 26 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 27 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 28 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 29 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
# 30 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
# 31 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
# 32 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 33 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 34 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt5::
# 35 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
# 36 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 37 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 38 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 39 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt2::
# 40 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
# 41 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 42 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 43 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 44 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt3::
# 45 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
# 46 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 47 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 48 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 49 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Shelly::
# 50 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
# 51 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
# 52 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 53 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 54 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
# 55 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
# 56 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 57 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	addobject LOCALID_GRUNT_3
# 58 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
# 59 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
# 60 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 61 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
# 62 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 63 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	playse SE_PIN
# 64 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
# 65 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 66 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
# 67 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 68 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
# 69 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 70 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
# 71 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 72 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadedefaultbgm
# 73 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 74 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
# 75 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
# 76 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 77 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 78 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_SHELLY
# 79 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 80 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 81 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
# 82 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 83 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 84 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
# 85 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 86 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	copyobjectxytoperm LOCALID_SCIENTIST
# 87 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 88 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 89 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 90 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
# 91 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 92 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
# 93 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	randompercentage 25
# 94 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER, isShiny=VAR_RESULT
# 95 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
# 96 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
# 97 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 98 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 99 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 100 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
# 101 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 102 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 103 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 104 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 105 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 106 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 107 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 108 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 109 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
# 110 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 111 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 112 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 113 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 114 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 115 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 116 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 117 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
# 118 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 119 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 120 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 121 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 122 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
# 123 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 124 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
# 125 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmessage
# 126 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitfanfare
# 127 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
# 128 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 129 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 130 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
# 131 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
# 132 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_RECEIVED_CASTFORM
# 133 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 134 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 135 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 136 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
# 137 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
# 138 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
# 139 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 140 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 141 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 142 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
# 143 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_0x8004, 0
# 144 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 145 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 146 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
# 147 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
# 148 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
# 149 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
# 150 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
# 151 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 152 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 153 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 154 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
# 155 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
# 156 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 157 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 158 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 159 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
# 160 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	special CreateAbnormalWeatherEvent
# 161 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 162 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 163 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 164 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
# 165 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	addvar VAR_0x8004, 1
# 166 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 167 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 168 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
# 169 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
# 170 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 171 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 172 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 173 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
# 174 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 175 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 176 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 177 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 178 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 179 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 180 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 181 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 182 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 183 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 184 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 185 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 186 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 187 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
# 188 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 189 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 190 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 191 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 192 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 193 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	ride_water_current_up
# 194 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_faster_down
# 195 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 196 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 197 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
# 198 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	slide_down
# 199 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_faster_left
# 200 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 201 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 202 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
# 203 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 204 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 205 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 206 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 207 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 208 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
# 209 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	lock
# 210 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 211 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
# 212 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 213 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 214 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 215 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Intro:
# 216 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The INSTITUTE created a type of\n"
# 217 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "POKéMON that has something to do with\l"
# 218 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the weather. We're here to take them!$"
# 219 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 220 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
# 221 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Our plan's being spoiled by a kid?$"
# 222 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 223 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
# 224 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "If the POKéMON they made here can\n"
# 225 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "control the weather freely, then we of\l"
# 226 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM AQUA definitely need it!$"
# 227 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 228 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Intro:
# 229 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We're TEAM AQUA!\n"
# 230 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We appear wherever anything rare is\l"
# 231 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "found!$"
# 232 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 233 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
# 234 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You got me!$"
# 235 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 236 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
# 237 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You don't have any idea what we of\n"
# 238 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM AQUA are working towards!\l"
# 239 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You stay out of our way!$"
# 240 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 241 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Intro:
# 242 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Don't tell me you're looking for that\n"
# 243 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "weather POKéMON, too?\p"
# 244 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That's a no-no!\n"
# 245 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We were here to get it first!$"
# 246 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 247 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
# 248 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Oh, will you look at my POKéMON?$"
# 249 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 250 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
# 251 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Humph, so what?\n"
# 252 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we want…\p"
# 253 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we really want isn't here…\n"
# 254 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ihihihihi…$"
# 255 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 256 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyIntro:
# 257 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\p"
# 258 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're going to meddle in TEAM AQUA's\n"
# 259 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "affairs?\p"
# 260 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're either absolutely fearless,\n"
# 261 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "simply ignorant, or both!\p"
# 262 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're so cute, you're disgusting!\n"
# 263 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I'll put you down, kiddy!$"
# 264 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 265 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyDefeat:
# 266 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 267 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're disgustingly strong!$"
# 268 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 269 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
# 270 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It's bad enough to have TEAM MAGMA\n"
# 271 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "blunder about, but now there's you!\p"
# 272 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What makes you want to sniff around\n"
# 273 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in our business, anyway?$"
# 274 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 275 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
# 276 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have a situation here!\p"
# 277 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "A TEAM MAGMA mob just passed\n"
# 278 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the WEATHER INSTITUTE.\p"
# 279 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "They appear to be headed for\n"
# 280 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "MT. PYRE!$"
# 281 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 282 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
# 283 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What?!\p"
# 284 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We can't waste any more time here!\n"
# 285 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have to hurry to MT. PYRE, too!\p"
# 286 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 287 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM MAGMA, just you wait!$"
# 288 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 289 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
# 290 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks!\n"
# 291 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks to you, we're safe!\p"
# 292 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It might be an odd way of thanking you,\n"
# 293 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "but take this POKéMON.$"
# 294 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 295 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
@ Unused
# 296 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
# 297 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Hm? You don't seem to have any room\n"
# 298 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "for this POKéMON.$"
# 299 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 300 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
# 301 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{PLAYER} received CASTFORM!$"
# 302 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 303 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
# 304 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That POKéMON changes shape according\n"
# 305 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "to the weather conditions.\p"
# 306 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "There're plenty of them in the\n"
# 307 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "INSTITUTE--go ahead and take it.$"
# 308 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 309 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
# 310 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I've been researching rain for many\n"
# 311 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "years, but it's ridiculous to think that\l"
# 312 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "humans can freely change the weather.$"
# 313 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 314 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_GroudonWeather:
# 315 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 316 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the HOENN region.\p"
# 317 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, a drought has been recorded\n"
# 318 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in {STR_VAR_1}.\p"
# 319 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 320 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 321 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 322 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_KyogreWeather:
# 323 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 324 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the HOENN region.\p"
# 325 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, heavy rainfall has been\n"
# 326 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "recorded over {STR_VAR_1}.\p"
# 327 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 328 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 329 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 330 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
# 331 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Abnormal weather conditions are\n"
# 332 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "no longer being reported.\p"
# 333 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The occasional rainfall is a blessing,\n"
# 334 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "really.$"
