# 1 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 2 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_MapScripts::
# 3 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 4 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 5 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 6 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 7 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 8 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 9 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 10 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 11 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 12 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Hoenn mons
# 13 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 14 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 15 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 16 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 17 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Never occurs
# 18 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Chose starter
# 19 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 20 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 103
# 21 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 22 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 23 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnTransition:
# 24 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 25 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 26 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 27 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 28 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 29 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 30 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 31 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 32 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 33 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 34 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 35 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 36 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 37 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 38 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 39 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 40 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 41 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 42 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 43 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 44 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 45 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 46 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 47 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 48 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 49 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
# 50 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 51 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 52 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnWarp:
# 53 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 54 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 55 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 56 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 57 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 58 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 59 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 60 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 61 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 62 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 63 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 64 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 65 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 66 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 67 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 68 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_BIRCH
# 69 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 70 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
# 71 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
# 72 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 73 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
# 74 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
# 75 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
# 76 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 77 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 78 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 79 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 80 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 81 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 82 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 83 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 84 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 85 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 86 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCHS_LAB_RIVAL
# 87 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
# 88 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
# 89 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
# 90 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
# 91 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
# 92 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
# 93 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
# 94 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
# 95 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
# 96 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
# 97 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 98 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 99 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_OnFrame:
# 100 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 101 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 102 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 103 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 104 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 105 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 106 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ The starter is technically given prior to this on Route 101 by special ChooseStarter
# 107 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ This is just where the game tells you its yours and lets you nickname it
# 108 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 109 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 110 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 111 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 112 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 113 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 114 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 115 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 116 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 117 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_0x8004, 0
# 118 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 119 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 120 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 121 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 122 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 123 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 124 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 125 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 126 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 127 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 128 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 129 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 130 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 131 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 132 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 133 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 134 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 135 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 136 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 137 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 138 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 139 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 140 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 141 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 142 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 143 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 144 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 145 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 146 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 147 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 148 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 149 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 150 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 151 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 152 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 153 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 154 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 155 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 156 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 157 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 158 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 159 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 160 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 161 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 162 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 163 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 164 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 165 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 166 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 167 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 168 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 169 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 170 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 171 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 172 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 173 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 174 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 175 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 176 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 177 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 178 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 179 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 180 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PC_ON
# 181 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitse
# 182 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 183 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 184 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 185 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 186 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 187 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 188 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 189 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 190 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 191 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 192 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 193 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 194 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 195 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 196 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 197 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 198 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 199 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 200 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 201 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 202 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 203 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 204 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 205 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 206 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 207 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 208 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 209 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 210 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 211 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 212 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 213 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 214 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 215 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 216 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 217 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 218 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 219 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 220 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 221 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 222 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 223 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 224 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 225 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 226 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 227 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 228 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 229 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 230 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 231 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 232 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_up
# 233 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 234 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 235 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 236 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 237 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 238 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 239 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 240 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 241 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 242 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 243 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 244 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 245 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 246 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 247 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 248 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 249 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 250 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 251 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 252 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 253 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 254 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 255 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 256 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 257 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 258 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 259 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 260 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 261 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 262 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 263 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 264 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 265 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 266 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
# 267 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 268 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 269 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 270 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 271 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 272 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 273 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 274 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 275 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 276 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 277 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 278 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 279 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 280 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 281 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 282 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 283 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 284 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 285 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 286 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 287 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 288 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 289 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 290 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 291 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 292 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 293 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 294 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 295 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 296 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 297 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
# 298 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 299 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 300 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 301 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 302 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 303 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 304 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 305 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 306 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 307 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 308 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
# 309 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 310 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 311 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 312 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 313 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 314 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 315 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 316 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 317 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 318 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 319 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 320 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 321 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 322 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 323 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 324 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 325 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 326 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 327 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 328 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 329 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 330 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 331 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 332 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 333 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5
# 334 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 335 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 336 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 337 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 338 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 339 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 340 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 341 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 342 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 343 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 344 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 345 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 346 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 347 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 348 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 349 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 350 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 351 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 352 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
# 353 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 354 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 355 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 356 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 357 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 358 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 359 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 360 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 361 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 362 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 363 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 364 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 365 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 366 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 367 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 368 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 369 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 370 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 371 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 372 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 373 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 374 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5
# 375 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 376 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 377 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 378 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 379 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 380 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 381 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 382 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 383 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 384 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 385 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 386 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 387 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 388 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 389 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 390 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 391 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 392 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 393 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
# 394 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 395 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 396 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 397 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 398 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 399 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 400 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 401 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 402 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 403 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 404 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 405 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 406 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 407 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 408 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 409 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 410 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 411 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 412 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 413 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 414 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 415 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5
# 416 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 417 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 418 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 419 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 420 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 421 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 422 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 423 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 424 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 425 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 426 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 427 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 428 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 429 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 430 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 431 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 432 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 433 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 434 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
# 435 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 436 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 437 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 438 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 439 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 440 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 441 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 442 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 443 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 444 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 445 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 446 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 447 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 448 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 449 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 450 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 451 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 452 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 453 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 454 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 455 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 456 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 457 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 458 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 459 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 460 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
# 461 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 462 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 463 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 464 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 465 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 466 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 467 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 468 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 469 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 470 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 471 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 472 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 473 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 474 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 475 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 476 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 477 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 478 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 479 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 480 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 481 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 482 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 483 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 484 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 485 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 486 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 487 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 488 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 489 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch::
# 490 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 491 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 492 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 493 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 494 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 495 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 496 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 497 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 498 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 499 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 500 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 501 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 502 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 503 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 504 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 505 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 506 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 507 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 508 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 509 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 510 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 511 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 512 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 513 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 514 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 515 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 516 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 517 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 518 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 519 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 520 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 521 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 522 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 523 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 524 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 525 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 526 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 527 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 528 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 529 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 530 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 531 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 532 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 533 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 534 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 535 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 536 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 537 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 538 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 539 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 540 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 541 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 542 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 543 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 544 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 545 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 546 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 547 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 548 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 549 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 550 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 551 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 552 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 553 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 554 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 555 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 556 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 557 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 558 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 559 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 560 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 561 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 562 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 563 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 564 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 565 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 566 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_left
# 567 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 568 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 569 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
# 570 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 571 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 572 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 573 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
# 574 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 575 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 576 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 577 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 578 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 579 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 580 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 581 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 582 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 583 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 584 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 585 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 586 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 587 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 588 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 589 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 590 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 591 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 592 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 593 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 594 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 595 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 596 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 597 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 598 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 599 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 600 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 601 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 602 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 603 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 604 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 605 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 606 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 607 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 608 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 609 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 610 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 611 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 612 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 613 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 614 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 615 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 616 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 617 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 618 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 619 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 620 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 621 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 622 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 623 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 624 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 625 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 626 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 627 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 628 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 629 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 630 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 631 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 632 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 633 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 634 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 635 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 636 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	return
# 637 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 638 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_PC::
# 639 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 640 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 641 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 642 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 643 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 644 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 645 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 646 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Book::
# 647 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 648 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 649 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 650 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 651 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 652 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 653 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 654 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 655 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 656 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2::
# 661 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 662 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 663 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_10
LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_7:
# 681 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_6
LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_4:
# 685 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_5, MSGBOX_DEFAULT
LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_1:
# 687 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_2:
# 664 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_AIDE2_BALLS, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_13
# 668 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_BIRCH_AIDE2_BALLS, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_14
# 673 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	addvar VAR_BIRCH_AIDE2_BALLS, -1
# 674 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_BIRCH_AIDE2_BALLS
# 675 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_2, MSGBOX_DEFAULT
# 676 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_PREMIER_BALL, VAR_BIRCH_AIDE2_BALLS
# 677 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_3, MSGBOX_DEFAULT
# 678 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_AIDE2_BALLS, 1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_1

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_3:
# 682 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_4, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_1

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_5:
# 681 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_3
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_4

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_6:
# 681 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_5
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_4

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_10:
# 663 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_2
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_7

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_13:
# 665 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_0, MSGBOX_DEFAULT
# 666 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_AIDE2_BALLS, 1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_1

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_14:
# 669 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_1, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_1


LittlerootTown_ProfessorBirchsLab_EventScript_BlockBasementAccess::
# 692 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 693 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidefollower
# 694 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 695 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 696 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay 5
# 697 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_EventScript_BlockBasementAccess_Text_0, MSGBOX_DEFAULT
# 698 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 699 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_BlockBasementAccess
# 700 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 701 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
	end


# 705 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 706 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 707 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_BlockBasementAccess:
# 708 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 709 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 710 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 711 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 712 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 713 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 714 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 715 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 716 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 717 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 718 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 719 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 720 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 721 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 722 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 723 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 724 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 725 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 726 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 727 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 728 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 729 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 730 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 731 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 732 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 733 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 734 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 735 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 736 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 737 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
# 738 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
# 739 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard so much about you from\n"
# 740 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "your father.\p"
# 741 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The way you just battled out there…\p"
# 742 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You must have his blood in your\n"
# 743 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "veins…\p$"
# 744 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 745 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 746 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
# 747 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 748 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 749 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 750 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: If you work at POKéMON\n"
# 751 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you could\l"
# 752 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "be useful…\p"
# 753 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, see if you can beat my kid,\n"
# 754 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}, in a POKéMON battle.$"
# 755 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 756 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 757 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Great!\n"
# 758 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's see how you fare…$"
# 759 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 760 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 761 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, don't be that way.\n"
# 762 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Go fetch {RIVAL} and come back here.$"
# 763 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 764 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 765 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {RIVAL}!?\n"
# 766 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} snatched my POKéMON!\p"
# 767 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Go fetch {RIVAL} and come back here.$"
# 768 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 769 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 770 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
# 771 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL}…\p"
# 772 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 773 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 774 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéDEX.$"
# 775 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 776 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 777 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"
# 778 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 779 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 780 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: You'll want a POKéDEX \n"
# 781 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "if you're travelling around Hoenn.\p"
# 782 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Like I mentioned before, strange\n"
# 783 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON have started appearing.\p"
# 784 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The less you know about a wilderness,\n"
# 785 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the more dangerous it can be!\p"
# 786 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Use your POKéDEX to document the wild\n"
# 787 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON you see.$"
# 788 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 789 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 790 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Countless POKéMON\n"
# 791 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 792 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 793 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 794 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 795 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 796 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 797 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a POKéDEX, too!\p"
# 798 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's great! Just like me!\n"
# 799 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I've got something for you, too!$"
# 800 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 801 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 802 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Try and catch some more\n"
# 803 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON.$"
# 804 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 805 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 806 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your BAG's full.$"
# 807 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 808 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 809 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I wonder where I should go look\n"
# 810 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for POKéMON next?$"
# 811 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 812 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 813 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Huh…\n"
# 814 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a POKéDEX, too.\p"
# 815 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Well then, here.\n"
# 816 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll give you these.$"
# 817 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 818 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 819 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Try and catch some more\n"
# 820 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON.$"
# 821 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 822 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 823 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your BAG's full.$"
# 824 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 825 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 826 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Where should I look for\n"
# 827 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON next…$"
# 828 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 829 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 830 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 831 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF must use this for research.$"
# 832 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 833 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 834 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 835 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 836 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 837 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 838 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on POKéMON.$"
# 839 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 840 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 841 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 842 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 843 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 844 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Now…\p"
# 845 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 846 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study POKéMON.\p"
# 847 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 848 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 849 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the HOENN region,\n"
# 850 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also POKéMON from other\l"
# 851 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "regions.\p"
# 852 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It goes to show how rich and varied\n"
# 853 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the natural environments of HOENN\l"
# 854 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "happen to be.\p"
# 855 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's why I think it's necessary for\n"
# 856 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "me to upgrade your POKéDEX to\l"
# 857 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode.\p"
# 858 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, let me see your POKéDEX units.$"
# 859 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 860 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 861 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Eheheh!\p"
# 862 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cool that even my POKéDEX\n"
# 863 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "is getting updated!\p"
# 864 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's because you went out and caught\n"
# 865 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
# 866 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 867 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 868 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: I went out all over HOENN\n"
# 869 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and checked out POKéMON.\p"
# 870 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can thank me for getting\n"
# 871 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode POKéDEX.\p"
# 872 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yep, you're lucky, {PLAYER}!$"
# 873 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 874 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
# 875 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Okay, all done!$"
# 876 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 877 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 878 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 879 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "to the NATIONAL Mode!$"
# 880 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 881 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 882 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: But listen.\n"
# 883 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the CHAMPION,\l"
# 884 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 885 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 886 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 887 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 888 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 889 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 890 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 891 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I think I'll take a short break\n"
# 892 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from fieldwork.\p"
# 893 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I think I'll help the PROF here for\n"
# 894 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "a while.$"
# 895 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 896 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 897 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: For the time being,\n"
# 898 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm taking a break from fieldwork.\p"
# 899 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll be helping out the PROF here\n"
# 900 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for a while.$"
# 901 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 902 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 903 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 904 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your POKéDEX.\p"
# 905 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 906 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 907 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 908 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the HOENN\n"
# 909 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "region's POKéDEX.\p"
# 910 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 911 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 912 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 913 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 914 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare POKéMON only found\n"
# 915 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 916 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 917 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 918 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 919 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 920 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: These are rare POKéMON\n"
# 921 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 922 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 923 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 924 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 925 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 926 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The FIRE POKéMON\n"
# 927 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 928 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 929 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 930 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 931 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 932 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The WATER POKéMON\n"
# 933 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 934 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 935 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 936 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 937 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 938 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The GRASS POKéMON\n"
# 939 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 940 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 941 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 942 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 943 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 944 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Take your time before\n"
# 945 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 946 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable POKéMON.$"
# 947 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 948 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 949 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 950 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: I see!\n"
# 951 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You picked a fine POKéMON!$"
# 952 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 953 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 954 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 955 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "from PROF. BIRCH!$"
# 956 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 957 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 958 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 959 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 960 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 961 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 962 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 963 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 964 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the HOENN POKéDEX,\l"
# 965 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 966 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 967 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 968 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 969 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 970 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 971 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 972 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised POKéMON.\n"
# 973 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 974 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 975 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 976 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 977 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 978 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéMON.$"
# 979 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 980 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 981 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, after this…\n"
# 982 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 983 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 984 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 985 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 986 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL POKéDEX?\p"
# 987 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the PROF.$"
# 988 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 989 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 990 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Rather than collecting\n"
# 991 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON, I prefer slowly and \l"
# 992 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 993 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 994 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 995 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 996 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 997 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 998 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 999 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 1000 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}!\n"
# 1001 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 1002 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 1003 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1004 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 1005 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1006 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 1007 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
# 1008 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, SCOTT.\p"
# 1009 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. TIDAL now.\n"
# 1010 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 1011 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 1012 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 1013 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 1014 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 1015 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "at either SLATEPORT or LILYCOVE.\p"
# 1016 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 1017 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 1018 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1019 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_0:
# 665 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So the PROFESSOR gave you a POKéDEX?\p"
	.string "It can be hard to get started\n"
	.string "collecting POKéDEX data when you're a\l"
	.string "new TRAINER.\p"
	.string "Let me do you a favor to help.\p"
	.string "For every new POKéMON you catch,\n"
	.string "I'll give you a PREMIER BALL.\p"
	.string "That should make it a bit easier to\n"
	.string "practice catching…\p"
	.string "and PREMIER BALLS will really impress\n"
	.string "the other TRAINERS you meet!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_1:
# 669 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "What?\n"
	.string "You haven't caught any new POKéMON?\p"
	.string "Get out there and learn something!\n"
	.string "There's a PREMIER BALL with your name\l"
	.string "on it for each new catch!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_2:
# 675 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "So you've caught {STR_VAR_1} since\n"
	.string "the last time we spoke?\p"
	.string "Then here's your reward!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_3:
# 677 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Now that your POKéBALLS pocket is\n"
	.string "topped off you should have no trouble\l"
	.string "getting back out there to catch more\l"
	.string "POKéMON!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_4:
# 682 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's see how you're doing…\p"
	.string "… … … …\p"
	.string "Ah!\n"
	.string "You've gotten your first GYM BADGE!\p"
	.string "That means you're a real TRAINER now!\p"
	.string "As such, I can't be giving you handouts\n"
	.string "anymore.\l"
	.string "A TRAINER knows how to fend for\l"
	.string "theirself!\p"
	.string "But don't worry, the more competent you\n"
	.string "become at navigating the wilderness,\l"
	.string "the better you will become at field\l"
	.string "research too!$"

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2_Text_5:
# 685 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROFESSOR has been collecting data\n"
	.string "on POKéMON his whole life,\p"
	.string "but once our lab partnered with DEVON\n"
	.string "CORP, access to modern research tools\l"
	.string "and international data sharing allowed\l"
	.string "him to really pick up the pace!$"

LittlerootTown_ProfessorBirchsLab_EventScript_BlockBasementAccess_Text_0:
# 697 "data//maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You shouldn't go down there without\n"
	.string "permission…$"
