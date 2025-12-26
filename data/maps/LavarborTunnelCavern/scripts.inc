LavarborTunnelCavern_MapScripts::
# 8 "data//maps/LavarborTunnelCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD
# 17 "data//maps/LavarborTunnelCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD:
# 9 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 23
	goto_if_lt LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_1
# 10 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_unset FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_1
# 11 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 23
	goto_if_eq LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_7
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 12 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 22, 12, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 13 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 23, 12, METATILE_Cave_Regular_Dark_Cave_Wall, TRUE
# 14 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 23, 13, METATILE_Cave_Sandbottom_Dark_Cave_Wall, TRUE
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_6:
# 11 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 11 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_LOAD_6
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 18 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
# 26 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_LAVARBOR_TUNNEL_QUEST_STATE, 24
	goto_if_lt LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 34 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_5
# 35 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_6
# 36 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_7
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 20 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_TEMP_5, 1
# 21 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_TEMP_6, 1
# 22 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_5
# 23 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_6
# 24 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_7
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 29 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_5
# 30 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_6
# 31 "data//maps/LavarborTunnelCavern/scripts.pory"
	setobjectxyperm LOCALID_CAVERN_TUNNEL_MANIAC, 24, 15
	return

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 28 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_unset FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	goto LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_3

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 27 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	goto LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_3

LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 19 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_unset FLAG_DEFEATED_LAVARBOR_GARCHOMP, LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto LavarborTunnelCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION_6


LavarborTunnelCavern_EventScript_GarchompRumble::
# 42 "data//maps/LavarborTunnelCavern/scripts.pory"
	lock
# 43 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8004, 1
# 44 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8005, 1
# 45 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8006, 8
# 46 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8007, 3
# 47 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 48 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 49 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 50 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 51 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 52 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_GarchompRumble_Text_0, MSGBOX_DEFAULT
# 53 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_TEMP_6, 0
# 54 "data//maps/LavarborTunnelCavern/scripts.pory"
	release
	return


LavarborTunnelCavern_EventScript_GarchompAttacks::
# 58 "data//maps/LavarborTunnelCavern/scripts.pory"
	lock
# 59 "data//maps/LavarborTunnelCavern/scripts.pory"
	fadeoutbgm 0
# 60 "data//maps/LavarborTunnelCavern/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 61 "data//maps/LavarborTunnelCavern/scripts.pory"
	addobject LOCALID_LAVARBOR_CAVERN_GARCHOMP, MAP_LAVARBOR_TUNNEL_CAVERN
# 62 "data//maps/LavarborTunnelCavern/scripts.pory"
	clearflag FLAG_TEMP_5
# 63 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8004, 1
# 64 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8005, 1
# 65 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8006, 8
# 66 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_0x8007, 3
# 67 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 68 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 69 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 70 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 71 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 72 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 73 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 74 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 75 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 76 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 77 "data//maps/LavarborTunnelCavern/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 78 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_TEMP_E, 19
	goto_if_eq LavarborTunnelCavern_EventScript_GarchompAttacks_2
# 82 "data//maps/LavarborTunnelCavern/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_CAVERN_GARCHOMP, 20, 16
LavarborTunnelCavern_EventScript_GarchompAttacks_1:
# 84 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_LAVARBOR_CAVERN_GARCHOMP, LavarborTunnelCavern_Movement_GarchompUnearthed
# 85 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BIKE_HOP
# 86 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 87 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 88 "data//maps/LavarborTunnelCavern/scripts.pory"
	playmoncry SPECIES_GARCHOMP, CRY_MODE_ENCOUNTER
# 89 "data//maps/LavarborTunnelCavern/scripts.pory"
	message LavarborTunnelCavern_EventScript_GarchompAttacks_Text_0
# 90 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmessage
# 91 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 60
# 92 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 93 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 94 "data//maps/LavarborTunnelCavern/scripts.pory"
	setwildbossmon 1
# 95 "data//maps/LavarborTunnelCavern/scripts.pory"
	clearflag FLAG_TEMP_NO_RUNNING
# 96 "data//maps/LavarborTunnelCavern/scripts.pory"
	createmon 1, 3, SPECIES_GARCHOMP, 40, nature = NATURE_ADAMANT, abilityNum = 2, atkEv = 252, defEv = 4, speedEv = 252, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31, move1 = MOVE_DIG, move2 = MOVE_SANDSTORM, move3 = MOVE_ROCK_SLIDE, move4 = MOVE_POISON_JAB
# 97 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 98 "data//maps/LavarborTunnelCavern/scripts.pory"
	special StartRegiBattle
# 99 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitstate
# 100 "data//maps/LavarborTunnelCavern/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 101 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_TEMP_NO_RUNNING
# 102 "data//maps/LavarborTunnelCavern/scripts.pory"
	endwildbossmon
# 103 "data//maps/LavarborTunnelCavern/scripts.pory"
	setvar VAR_TEMP_5, 0
# 104 "data//maps/LavarborTunnelCavern/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 105 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LavarborTunnelCavern_EventScript_DefeatedGarchomp
# 106 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LavarborTunnelCavern_EventScript_RanFromGarchomp
# 107 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LavarborTunnelCavern_EventScript_RanFromGarchomp
# 108 "data//maps/LavarborTunnelCavern/scripts.pory"
	release
	return

LavarborTunnelCavern_EventScript_GarchompAttacks_2:
# 79 "data//maps/LavarborTunnelCavern/scripts.pory"
	setobjectxy LOCALID_LAVARBOR_CAVERN_GARCHOMP, 19, 16
	goto LavarborTunnelCavern_EventScript_GarchompAttacks_1


LavarborTunnelCavern_EventScript_DefeatedGarchomp::
# 112 "data//maps/LavarborTunnelCavern/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 113 "data//maps/LavarborTunnelCavern/scripts.pory"
	removeobject LOCALID_LAVARBOR_CAVERN_GARCHOMP
# 114 "data//maps/LavarborTunnelCavern/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 115 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_0, MSGBOX_DEFAULT
# 116 "data//maps/LavarborTunnelCavern/scripts.pory"
	setflag FLAG_DEFEATED_LAVARBOR_GARCHOMP
# 117 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 118 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 119 "data//maps/LavarborTunnelCavern/scripts.pory"
	goto_if_set FLAG_LAVARBOR_FALLARBOR_OPENED, LavarborTunnelCavern_EventScript_DefeatedGarchomp_2
# 190 "data//maps/LavarborTunnelCavern/scripts.pory"
	message LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_4
# 191 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmessage
# 192 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 10
# 193 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 194 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_PIN
# 195 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 196 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 197 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 198 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 199 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 200 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 201 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 202 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 203 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 204 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 205 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_5, MSGBOX_DEFAULT
# 206 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 207 "data//maps/LavarborTunnelCavern/scripts.pory"
	addobject LOCALID_CAVERN_TUNNEL_MANIAC, MAP_LAVARBOR_TUNNEL_CAVERN
# 208 "data//maps/LavarborTunnelCavern/scripts.pory"
	clearflag FLAG_TEMP_7
# 209 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_TUNNEL_MANIAC, LavarborTunnelCavern_Movement_TunnelManiacEnters
# 210 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 45
# 211 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 212 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement LOCALID_CAVERN_TUNNEL_MANIAC
# 213 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 214 "data//maps/LavarborTunnelCavern/scripts.pory"
	setobjectxyperm LOCALID_CAVERN_TUNNEL_MANIAC, 15, 14
# 215 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_TUNNEL_MANIAC, Common_Movement_WalkInPlaceRight
# 216 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_6, MSGBOX_DEFAULT
# 219 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 220 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 221 "data//maps/LavarborTunnelCavern/scripts.pory"
	message LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_7
# 222 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmessage
# 223 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 20
# 224 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 225 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 40
# 226 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_8, MSGBOX_DEFAULT
LavarborTunnelCavern_EventScript_DefeatedGarchomp_1:
# 231 "data//maps/LavarborTunnelCavern/scripts.pory"
	release
	return

LavarborTunnelCavern_EventScript_DefeatedGarchomp_2:
# 120 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 121 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 122 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 123 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 124 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 125 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 126 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 127 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 128 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 129 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitse
# 130 "data//maps/LavarborTunnelCavern/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 131 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 132 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_PIN
# 133 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitse
# 134 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_1, MSGBOX_DEFAULT
# 135 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 136 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 137 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 138 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 139 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 140 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 30
# 141 "data//maps/LavarborTunnelCavern/scripts.pory"
	special ShakeCamera
# 142 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 143 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 144 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BANG
# 145 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitse
# 146 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 22, 12, METATILE_Cave_Dark_Door_Edge, TRUE
# 147 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 23, 12, METATILE_Cave_Dark_Door_Top, TRUE
# 148 "data//maps/LavarborTunnelCavern/scripts.pory"
	setmetatile 23, 13, METATILE_Cave_Dark_Door_Bottom, FALSE
# 149 "data//maps/LavarborTunnelCavern/scripts.pory"
	special DrawWholeMapView
# 150 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_BREAKABLE_DOOR
# 151 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitse
# 152 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 15
# 153 "data//maps/LavarborTunnelCavern/scripts.pory"
	addobject LOCALID_CAVERN_FOSSIL_MANIAC, MAP_LAVARBOR_TUNNEL_CAVERN
# 154 "data//maps/LavarborTunnelCavern/scripts.pory"
	clearflag FLAG_TEMP_6
# 155 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_EXIT
# 156 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, LavarborTunnelCavern_Movement_FossilManiacWalksIn
# 157 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 158 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, Common_Movement_ExclamationMark
# 159 "data//maps/LavarborTunnelCavern/scripts.pory"
	playse SE_PIN
# 160 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitse
# 161 "data//maps/LavarborTunnelCavern/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 162 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_TEMP_E, 19
	goto_if_eq LavarborTunnelCavern_EventScript_DefeatedGarchomp_6
# 166 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, LavarborTunnelCavern_Movement_FossilManiacApproachB
LavarborTunnelCavern_EventScript_DefeatedGarchomp_5:
# 168 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 169 "data//maps/LavarborTunnelCavern/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 170 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 10
# 171 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_2, MSGBOX_DEFAULT
# 174 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 175 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 45
# 176 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_3, MSGBOX_DEFAULT
# 178 "data//maps/LavarborTunnelCavern/scripts.pory"
	closemessage
# 179 "data//maps/LavarborTunnelCavern/scripts.pory"
	compare VAR_TEMP_E, 19
	goto_if_eq LavarborTunnelCavern_EventScript_DefeatedGarchomp_10
# 183 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, LavarborTunnelCavern_Movement_FossilManiacLeavesB
LavarborTunnelCavern_EventScript_DefeatedGarchomp_9:
# 185 "data//maps/LavarborTunnelCavern/scripts.pory"
	waitmovement
# 186 "data//maps/LavarborTunnelCavern/scripts.pory"
	removeobject LOCALID_CAVERN_FOSSIL_MANIAC
	goto LavarborTunnelCavern_EventScript_DefeatedGarchomp_1

LavarborTunnelCavern_EventScript_DefeatedGarchomp_6:
# 163 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, LavarborTunnelCavern_Movement_FossilManiacApproachA
	goto LavarborTunnelCavern_EventScript_DefeatedGarchomp_5

LavarborTunnelCavern_EventScript_DefeatedGarchomp_10:
# 180 "data//maps/LavarborTunnelCavern/scripts.pory"
	applymovement LOCALID_CAVERN_FOSSIL_MANIAC, LavarborTunnelCavern_Movement_FossilManiacLeavesA
	goto LavarborTunnelCavern_EventScript_DefeatedGarchomp_9


LavarborTunnelCavern_EventScript_TunnelManiac::
# 235 "data//maps/LavarborTunnelCavern/scripts.pory"
	lock
# 236 "data//maps/LavarborTunnelCavern/scripts.pory"
	faceplayer
# 237 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay 1
# 238 "data//maps/LavarborTunnelCavern/scripts.pory"
	release
	return


# 241 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_TunnelManiacEnters:
# 242 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 243 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 244 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 245 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 246 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 247 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 248 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 249 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 250 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 251 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 254 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_FossilManiacLeavesA:
# 255 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 256 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 257 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 258 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 259 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 260 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 261 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 262 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 263 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 264 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 265 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 266 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 267 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 268 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 271 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_FossilManiacLeavesB:
# 272 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 273 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 274 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 275 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 276 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_up
# 277 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 278 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 279 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 280 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 281 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 282 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 283 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 284 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 285 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_right
# 286 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 289 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_FossilManiacApproachA:
# 290 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 291 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 292 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 293 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 294 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 295 "data//maps/LavarborTunnelCavern/scripts.pory"
	face_up
# 296 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 299 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_FossilManiacApproachB:
# 300 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 301 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 302 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 303 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_left
# 304 "data//maps/LavarborTunnelCavern/scripts.pory"
	face_up
# 305 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 308 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_FossilManiacWalksIn:
# 309 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_down
# 310 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 311 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 312 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_in_place_left
# 313 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 314 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 315 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_in_place_down
# 316 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 317 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_in_place_left
# 318 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 319 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_in_place_down
# 320 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_8
# 321 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_in_place_left
# 322 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_4
# 323 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

LavarborTunnelCavern_EventScript_RanFromGarchomp::
# 327 "data//maps/LavarborTunnelCavern/scripts.pory"
	fadescreen FADE_TO_BLACK
# 328 "data//maps/LavarborTunnelCavern/scripts.pory"
	msgbox LavarborTunnelCavern_EventScript_RanFromGarchomp_Text_0, MSGBOX_DEFAULT
# 330 "data//maps/LavarborTunnelCavern/scripts.pory"
	warp MAP_LAVARBOR_TUNNEL_UNFINISHED, WARP_ID_LAVARBOR_EXIT
# 331 "data//maps/LavarborTunnelCavern/scripts.pory"
	release
	return


# 334 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_GarchompUnearthed:
# 335 "data//maps/LavarborTunnelCavern/scripts.pory"
	set_visible
# 336 "data//maps/LavarborTunnelCavern/scripts.pory"
	jump_in_place_up
# 337 "data//maps/LavarborTunnelCavern/scripts.pory"
	delay_16
# 338 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

# 341 "data//maps/LavarborTunnelCavern/scripts.pory"
LavarborTunnelCavern_Movement_GarchompAttacks:
# 342 "data//maps/LavarborTunnelCavern/scripts.pory"
	walk_fast_up
# 343 "data//maps/LavarborTunnelCavern/scripts.pory"
	step_end

LavarborTunnelCavern_EventScript_GarchompRumble_Text_0:
# 52 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "Something powerful is lurking below…$"

LavarborTunnelCavern_EventScript_GarchompAttacks_Text_0:
# 89 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "G{PAUSE 2}A{PAUSE 2}A{PAUSE 2}A{PAUSE 2}A{PAUSE 2}A{PAUSE 2}R!$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_0:
# 115 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "The defeated corpse of the powerful\n"
	.string "GARCHOMP sank back into the sand…$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_1:
# 134 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "Something else is coming!$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_2:
# 171 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "FOSSIL MANIAC: Wow, did I really\n"
	.string "connect the tunnels?\p"
	.string "The rumbling I heard seemed to calm\n"
	.string "down, so I punched through the wall\l"
	.string "and found this cavern!\p"
	.string "But you were already here!\p"
	.string "So that means those rare fossils are\n"
	.string "nearby too, right?$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_3:
# 176 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "No time to waste!\l"
	.string "I've gotta see those fossils!$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_4:
# 190 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "{PLAYER}!$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_5:
# 205 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "{PLAYER}?\l"
	.string "Are you all right?$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_6:
# 216 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "TUNNEL MANIAC: Ah!\p"
	.string "That ominous rumbling calmed down, so I\n"
	.string "thought it would be safe enough to\l"
	.string "take a look.\p"
	.string "It's great to see you in one piece!$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_7:
# 221 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

LavarborTunnelCavern_EventScript_DefeatedGarchomp_Text_8:
# 226 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "Wow!\p"
	.string "You defeated a powerful POKéMON that\n"
	.string "was hiding in the sand down there?\p"
	.string "You may have saved our lives,\n"
	.string "{PLAYER}.\p"
	.string "And now we can continue digging!\p"
	.string "You're a hero!$"

LavarborTunnelCavern_EventScript_RanFromGarchomp_Text_0:
# 328 "data//maps/LavarborTunnelCavern/scripts.pory"
	.string "The GARCHOMP was too powerful to\n"
	.string "overcome!\p"
	.string "You fled the cavern to escape harm!$"
