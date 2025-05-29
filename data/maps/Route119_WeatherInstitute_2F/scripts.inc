# 1 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 2 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_MapScripts::
# 3 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
# 4 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.byte 0
# 5 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 6 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_OnTransition:
# 7 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
# 8 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
# 9 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
# 10 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 11 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 12 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
# 13 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
# 14 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 15 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 16 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 17 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
# 18 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
# 19 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 20 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 21 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 22 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
# 23 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
# 24 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
# 25 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 26 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 27 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt5::
# 28 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
# 29 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 30 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 31 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 32 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt2::
# 33 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
# 34 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 35 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 36 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 37 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt3::
# 38 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
# 39 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 40 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 41 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 42 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Shelly::
# 43 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
# 44 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
# 45 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 46 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 47 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
# 48 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
# 49 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 50 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
# 51 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
# 52 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
# 53 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 54 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
# 55 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 56 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	playse SE_PIN
# 57 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
# 58 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 59 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
# 60 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 61 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
# 62 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 63 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
# 64 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 65 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadedefaultbgm
# 66 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 67 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
# 68 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
# 69 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
# 70 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
# 71 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
# 72 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
# 73 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
# 74 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
# 75 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 76 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 77 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
# 78 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 79 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
# 80 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 81 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 82 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 83 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
# 84 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 85 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
# 86 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	randompercentage 25
# 87 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER, isShiny=VAR_RESULT
# 88 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
# 89 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
# 90 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 91 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 92 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 93 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
# 94 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 95 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 96 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 97 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 98 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 99 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 100 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 101 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 102 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
# 103 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 104 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 105 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 106 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 107 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 108 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 109 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 110 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
# 111 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 112 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 113 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 114 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 115 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
# 116 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 117 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
# 118 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmessage
# 119 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitfanfare
# 120 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
# 121 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 122 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 123 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
# 124 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
# 125 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_RECEIVED_CASTFORM
# 126 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 127 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 128 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 129 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
# 130 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
# 131 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
# 132 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 133 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 134 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 135 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
# 136 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_0x8004, 0
# 137 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 138 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 139 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
# 140 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
# 141 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
# 142 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
# 143 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
# 144 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 145 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 146 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 147 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
# 148 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
# 149 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 150 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 151 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 152 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
# 153 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	special CreateAbnormalWeatherEvent
# 154 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 155 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 156 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 157 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
# 158 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	addvar VAR_0x8004, 1
# 159 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 160 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 161 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
# 162 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
# 163 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 164 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 165 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 166 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
# 167 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 168 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 169 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 170 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 171 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 172 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 173 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 174 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 175 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 176 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 177 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 178 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 179 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 180 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
# 181 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 182 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 183 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 184 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 185 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 186 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	ride_water_current_up
# 187 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_faster_down
# 188 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 189 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 190 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
# 191 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	slide_down
# 192 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_faster_left
# 193 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 194 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 195 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
# 196 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 197 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 198 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 199 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 200 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 201 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
# 202 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	lock
# 203 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 204 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
# 205 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 206 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 207 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 208 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Intro:
# 209 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The INSTITUTE created a type of\n"
# 210 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "POKéMON that has something to do with\l"
# 211 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the weather. We're here to take them!$"
# 212 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 213 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
# 214 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Our plan's being spoiled by a kid?$"
# 215 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 216 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
# 217 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "If the POKéMON they made here can\n"
# 218 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "control the weather freely, then we of\l"
# 219 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM AQUA definitely need it!$"
# 220 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 221 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Intro:
# 222 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We're TEAM AQUA!\n"
# 223 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We appear wherever anything rare is\l"
# 224 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "found!$"
# 225 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 226 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
# 227 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You got me!$"
# 228 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 229 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
# 230 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You don't have any idea what we of\n"
# 231 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM AQUA are working towards!\l"
# 232 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You stay out of our way!$"
# 233 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 234 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Intro:
# 235 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Don't tell me you're looking for that\n"
# 236 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "weather POKéMON, too?\p"
# 237 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That's a no-no!\n"
# 238 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We were here to get it first!$"
# 239 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 240 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
# 241 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Oh, will you look at my POKéMON?$"
# 242 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 243 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
# 244 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Humph, so what?\n"
# 245 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we want…\p"
# 246 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we really want isn't here…\n"
# 247 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ihihihihi…$"
# 248 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 249 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyIntro:
# 250 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\p"
# 251 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're going to meddle in TEAM AQUA's\n"
# 252 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "affairs?\p"
# 253 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're either absolutely fearless,\n"
# 254 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "simply ignorant, or both!\p"
# 255 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're so cute, you're disgusting!\n"
# 256 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I'll put you down, kiddy!$"
# 257 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 258 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyDefeat:
# 259 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 260 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're disgustingly strong!$"
# 261 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 262 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
# 263 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It's bad enough to have TEAM MAGMA\n"
# 264 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "blunder about, but now there's you!\p"
# 265 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What makes you want to sniff around\n"
# 266 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in our business, anyway?$"
# 267 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 268 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
# 269 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have a situation here!\p"
# 270 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "A TEAM MAGMA mob just passed\n"
# 271 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the WEATHER INSTITUTE.\p"
# 272 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "They appear to be headed for\n"
# 273 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "MT. PYRE!$"
# 274 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 275 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
# 276 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What?!\p"
# 277 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We can't waste any more time here!\n"
# 278 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have to hurry to MT. PYRE, too!\p"
# 279 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 280 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "TEAM MAGMA, just you wait!$"
# 281 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 282 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
# 283 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks!\n"
# 284 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks to you, we're safe!\p"
# 285 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It might be an odd way of thanking you,\n"
# 286 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "but take this POKéMON.$"
# 287 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 288 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
@ Unused
# 289 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
# 290 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Hm? You don't seem to have any room\n"
# 291 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "for this POKéMON.$"
# 292 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 293 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
# 294 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{PLAYER} received CASTFORM!$"
# 295 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 296 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
# 297 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That POKéMON changes shape according\n"
# 298 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "to the weather conditions.\p"
# 299 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "There're plenty of them in the\n"
# 300 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "INSTITUTE--go ahead and take it.$"
# 301 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 302 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
# 303 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I've been researching rain for many\n"
# 304 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "years, but it's ridiculous to think that\l"
# 305 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "humans can freely change the weather.$"
# 306 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 307 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_GroudonWeather:
# 308 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 309 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the HOENN region.\p"
# 310 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, a drought has been recorded\n"
# 311 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in {STR_VAR_1}.\p"
# 312 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 313 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 314 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 315 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_KyogreWeather:
# 316 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 317 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the HOENN region.\p"
# 318 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, heavy rainfall has been\n"
# 319 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "recorded over {STR_VAR_1}.\p"
# 320 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 321 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 322 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"

# 323 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
# 324 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Abnormal weather conditions are\n"
# 325 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "no longer being reported.\p"
# 326 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The occasional rainfall is a blessing,\n"
# 327 "data//maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "really.$"
