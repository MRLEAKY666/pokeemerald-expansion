# 1 "data//maps/LittlerootTown/scripts.pory"

# 2 "data//maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 3 "data//maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 4 "data//maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data//maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 6 "data//maps/LittlerootTown/scripts.pory"

# 7 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 8 "data//maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 9 "data//maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 10 "data//maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 11 "data//maps/LittlerootTown/scripts.pory"
	.byte 0
# 12 "data//maps/LittlerootTown/scripts.pory"

# 13 "data//maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 14 "data//maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 15 "data//maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 16 "data//maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 17 "data//maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 18 "data//maps/LittlerootTown/scripts.pory"

# 19 "data//maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 20 "data//maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 21 "data//maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 22 "data//maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 23 "data//maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 24 "data//maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 25 "data//maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 26 "data//maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 27 "data//maps/LittlerootTown/scripts.pory"

# 28 "data//maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 29 "data//maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 30 "data//maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 31 "data//maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 32 "data//maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 33 "data//maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 34 "data//maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 35 "data//maps/LittlerootTown/scripts.pory"

# 36 "data//maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 37 "data//maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 38 "data//maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 39 "data//maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 40 "data//maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 41 "data//maps/LittlerootTown/scripts.pory"

# 42 "data//maps/LittlerootTown/scripts.pory"

# 43 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 44 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 45 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 46 "data//maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 47 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 48 "data//maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 49 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 50 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 51 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 52 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 53 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 54 "data//maps/LittlerootTown/scripts.pory"
	@ call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 55 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 56 "data//maps/LittlerootTown/scripts.pory"
	end
# 57 "data//maps/LittlerootTown/scripts.pory"

# 58 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 59 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 60 "data//maps/LittlerootTown/scripts.pory"
	return
# 61 "data//maps/LittlerootTown/scripts.pory"

# 62 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 63 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 64 "data//maps/LittlerootTown/scripts.pory"
	return
# 65 "data//maps/LittlerootTown/scripts.pory"

# 66 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 67 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 68 "data//maps/LittlerootTown/scripts.pory"
	return
# 69 "data//maps/LittlerootTown/scripts.pory"

# 70 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 71 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 72 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 73 "data//maps/LittlerootTown/scripts.pory"
	return
# 74 "data//maps/LittlerootTown/scripts.pory"

# 75 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 76 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 77 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 78 "data//maps/LittlerootTown/scripts.pory"
	return
# 79 "data//maps/LittlerootTown/scripts.pory"

# 80 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 81 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 82 "data//maps/LittlerootTown/scripts.pory"
	return
# 83 "data//maps/LittlerootTown/scripts.pory"

# 84 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 85 "data//maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 86 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 87 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 88 "data//maps/LittlerootTown/scripts.pory"
	return
# 89 "data//maps/LittlerootTown/scripts.pory"

# 90 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 91 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 92 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 93 "data//maps/LittlerootTown/scripts.pory"
	return
# 94 "data//maps/LittlerootTown/scripts.pory"

# 95 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 96 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 97 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 98 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 99 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 100 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 101 "data//maps/LittlerootTown/scripts.pory"
	return
# 102 "data//maps/LittlerootTown/scripts.pory"

# 103 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 104 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 105 "data//maps/LittlerootTown/scripts.pory"
	return
# 106 "data//maps/LittlerootTown/scripts.pory"

# 107 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 108 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 109 "data//maps/LittlerootTown/scripts.pory"
	return
# 110 "data//maps/LittlerootTown/scripts.pory"

# 111 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 112 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 113 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 114 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 115 "data//maps/LittlerootTown/scripts.pory"
	.2byte 0
# 116 "data//maps/LittlerootTown/scripts.pory"

# 117 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 118 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 119 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 120 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 121 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 122 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 123 "data//maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 124 "data//maps/LittlerootTown/scripts.pory"
	waitstate
# 125 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 126 "data//maps/LittlerootTown/scripts.pory"
	end
# 127 "data//maps/LittlerootTown/scripts.pory"

# 128 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 129 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 130 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 131 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 132 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 133 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 134 "data//maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 135 "data//maps/LittlerootTown/scripts.pory"
	waitstate
# 136 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 137 "data//maps/LittlerootTown/scripts.pory"
	end
# 138 "data//maps/LittlerootTown/scripts.pory"

# 139 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 140 "data//maps/LittlerootTown/scripts.pory"
	delay 15
# 141 "data//maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 142 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 143 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 144 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 145 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 146 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 147 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 148 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 149 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 150 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 151 "data//maps/LittlerootTown/scripts.pory"
	delay 10
# 152 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 153 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 154 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 155 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 156 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 157 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 158 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 159 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 160 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 161 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 162 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 163 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 164 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 165 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 166 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 167 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 168 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 169 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 170 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 171 "data//maps/LittlerootTown/scripts.pory"
	return
# 172 "data//maps/LittlerootTown/scripts.pory"

# 173 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 174 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 175 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 176 "data//maps/LittlerootTown/scripts.pory"

# 177 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 178 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 179 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 180 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 181 "data//maps/LittlerootTown/scripts.pory"

# 182 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 183 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 184 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 185 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 186 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 187 "data//maps/LittlerootTown/scripts.pory"

# 188 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 189 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 190 "data//maps/LittlerootTown/scripts.pory"
	set_invisible
# 191 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 192 "data//maps/LittlerootTown/scripts.pory"

# 193 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 194 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 195 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 196 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 197 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 198 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 199 "data//maps/LittlerootTown/scripts.pory"

# 200 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 201 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 203 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 204 "data//maps/LittlerootTown/scripts.pory"

# 205 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 206 "data//maps/LittlerootTown/scripts.pory"
	jump_right
# 207 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 208 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 209 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 210 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 211 "data//maps/LittlerootTown/scripts.pory"

# 212 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 213 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 214 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 215 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 216 "data//maps/LittlerootTown/scripts.pory"
	end
# 217 "data//maps/LittlerootTown/scripts.pory"

# 218 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 219 "data//maps/LittlerootTown/scripts.pory"
	@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 220 "data//maps/LittlerootTown/scripts.pory"
	.2byte 0
# 221 "data//maps/LittlerootTown/scripts.pory"

# 222 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 223 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 224 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 225 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 226 "data//maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 227 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 228 "data//maps/LittlerootTown/scripts.pory"
	end
# 229 "data//maps/LittlerootTown/scripts.pory"

# 230 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 231 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 232 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 233 "data//maps/LittlerootTown/scripts.pory"
	end
# 234 "data//maps/LittlerootTown/scripts.pory"

# 235 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 236 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 237 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 238 "data//maps/LittlerootTown/scripts.pory"
	end
# 239 "data//maps/LittlerootTown/scripts.pory"

# 240 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 241 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 242 "data//maps/LittlerootTown/scripts.pory"
	end
# 243 "data//maps/LittlerootTown/scripts.pory"

# 244 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 245 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 246 "data//maps/LittlerootTown/scripts.pory"
	end
# 247 "data//maps/LittlerootTown/scripts.pory"

# 248 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 249 "data//maps/LittlerootTown/scripts.pory"
	lock
# 250 "data//maps/LittlerootTown/scripts.pory"
	faceplayer
# 251 "data//maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 252 "data//maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 253 "data//maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 254 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 255 "data//maps/LittlerootTown/scripts.pory"
	release
# 256 "data//maps/LittlerootTown/scripts.pory"
	end
# 257 "data//maps/LittlerootTown/scripts.pory"

# 258 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 259 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 260 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 261 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 262 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 263 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 264 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 265 "data//maps/LittlerootTown/scripts.pory"
	release
# 266 "data//maps/LittlerootTown/scripts.pory"
	end
# 267 "data//maps/LittlerootTown/scripts.pory"

# 268 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 269 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 270 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 271 "data//maps/LittlerootTown/scripts.pory"
	release
# 272 "data//maps/LittlerootTown/scripts.pory"
	end
# 273 "data//maps/LittlerootTown/scripts.pory"

# 274 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 275 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 276 "data//maps/LittlerootTown/scripts.pory"
	release
# 277 "data//maps/LittlerootTown/scripts.pory"
	end
# 278 "data//maps/LittlerootTown/scripts.pory"

# 279 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 280 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 281 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 282 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 283 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 284 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 285 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 286 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 287 "data//maps/LittlerootTown/scripts.pory"
	end
# 288 "data//maps/LittlerootTown/scripts.pory"

# 289 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 290 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 291 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 292 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 293 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 294 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 295 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 296 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 297 "data//maps/LittlerootTown/scripts.pory"
	return
# 298 "data//maps/LittlerootTown/scripts.pory"

# 299 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 300 "data//maps/LittlerootTown/scripts.pory"
	face_right
# 301 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 302 "data//maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 303 "data//maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 304 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 305 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 306 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 307 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 308 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 309 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 310 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 311 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 312 "data//maps/LittlerootTown/scripts.pory"
	face_down
# 313 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 314 "data//maps/LittlerootTown/scripts.pory"

# 315 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 316 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 317 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 318 "data//maps/LittlerootTown/scripts.pory"

# 319 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 320 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 321 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 322 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 323 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 324 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 325 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 326 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 327 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 328 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 329 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 330 "data//maps/LittlerootTown/scripts.pory"

# 331 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 332 "data//maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 333 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 334 "data//maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 335 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 336 "data//maps/LittlerootTown/scripts.pory"

# 337 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 338 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 339 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 340 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 341 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 342 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 343 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 344 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 345 "data//maps/LittlerootTown/scripts.pory"
	end
# 346 "data//maps/LittlerootTown/scripts.pory"

# 347 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 348 "data//maps/LittlerootTown/scripts.pory"
	face_right
# 349 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 350 "data//maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 351 "data//maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 352 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 353 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 354 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 355 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 356 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 357 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 358 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 359 "data//maps/LittlerootTown/scripts.pory"
	face_down
# 360 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 361 "data//maps/LittlerootTown/scripts.pory"

# 362 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 363 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 364 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 365 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 366 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 367 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 368 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 369 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 370 "data//maps/LittlerootTown/scripts.pory"

# 371 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 372 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 373 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 374 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 375 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 376 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 377 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 378 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 379 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 380 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 381 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 382 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 383 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 384 "data//maps/LittlerootTown/scripts.pory"
	end
# 385 "data//maps/LittlerootTown/scripts.pory"

# 386 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 387 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 388 "data//maps/LittlerootTown/scripts.pory"
	end
# 389 "data//maps/LittlerootTown/scripts.pory"

# 390 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 391 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 392 "data//maps/LittlerootTown/scripts.pory"
	end
# 393 "data//maps/LittlerootTown/scripts.pory"

# 394 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 395 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 396 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 397 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 398 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 399 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 400 "data//maps/LittlerootTown/scripts.pory"
	end
# 401 "data//maps/LittlerootTown/scripts.pory"

# 402 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 403 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 404 "data//maps/LittlerootTown/scripts.pory"
	return
# 405 "data//maps/LittlerootTown/scripts.pory"

# 406 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 407 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 408 "data//maps/LittlerootTown/scripts.pory"
	return
# 409 "data//maps/LittlerootTown/scripts.pory"

# 410 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 411 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 412 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 413 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 414 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 415 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 416 "data//maps/LittlerootTown/scripts.pory"
	end
# 417 "data//maps/LittlerootTown/scripts.pory"

# 418 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 419 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 420 "data//maps/LittlerootTown/scripts.pory"
	return
# 421 "data//maps/LittlerootTown/scripts.pory"

# 422 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 423 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 424 "data//maps/LittlerootTown/scripts.pory"
	return
# 425 "data//maps/LittlerootTown/scripts.pory"

# 426 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 427 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 428 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 429 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 430 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 431 "data//maps/LittlerootTown/scripts.pory"
	end
# 432 "data//maps/LittlerootTown/scripts.pory"

# 433 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 434 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 435 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 436 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 437 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 438 "data//maps/LittlerootTown/scripts.pory"
	end
# 439 "data//maps/LittlerootTown/scripts.pory"

# 440 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 441 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 442 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 443 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 444 "data//maps/LittlerootTown/scripts.pory"
	end
# 445 "data//maps/LittlerootTown/scripts.pory"

# 446 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 447 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 448 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 449 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 450 "data//maps/LittlerootTown/scripts.pory"
	end
# 451 "data//maps/LittlerootTown/scripts.pory"

# 452 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 453 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 454 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 455 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 456 "data//maps/LittlerootTown/scripts.pory"
	end
# 457 "data//maps/LittlerootTown/scripts.pory"

# 458 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 459 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 460 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 461 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 462 "data//maps/LittlerootTown/scripts.pory"
	end
# 463 "data//maps/LittlerootTown/scripts.pory"

# 464 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 465 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 466 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 467 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 468 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 469 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 470 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 471 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 472 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 473 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 474 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 475 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 476 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 477 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 478 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 479 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 480 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 481 "data//maps/LittlerootTown/scripts.pory"
	end
# 482 "data//maps/LittlerootTown/scripts.pory"

# 483 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 484 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 485 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 486 "data//maps/LittlerootTown/scripts.pory"
	return
# 487 "data//maps/LittlerootTown/scripts.pory"

# 488 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 489 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 490 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 491 "data//maps/LittlerootTown/scripts.pory"
	return
# 492 "data//maps/LittlerootTown/scripts.pory"

# 493 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 494 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 495 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 496 "data//maps/LittlerootTown/scripts.pory"
	return
# 497 "data//maps/LittlerootTown/scripts.pory"

# 498 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 499 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 500 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 501 "data//maps/LittlerootTown/scripts.pory"
	return
# 502 "data//maps/LittlerootTown/scripts.pory"

# 503 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 504 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 505 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 506 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 507 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 508 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 509 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 510 "data//maps/LittlerootTown/scripts.pory"
	return
# 511 "data//maps/LittlerootTown/scripts.pory"

# 512 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 513 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 514 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 515 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 516 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 517 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 518 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 519 "data//maps/LittlerootTown/scripts.pory"
	return
# 520 "data//maps/LittlerootTown/scripts.pory"

# 521 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 522 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 523 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 524 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 525 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 526 "data//maps/LittlerootTown/scripts.pory"
	return
# 527 "data//maps/LittlerootTown/scripts.pory"

# 528 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 529 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 530 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 531 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 532 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 533 "data//maps/LittlerootTown/scripts.pory"
	return
# 534 "data//maps/LittlerootTown/scripts.pory"

# 535 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 536 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 537 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 538 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 539 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 540 "data//maps/LittlerootTown/scripts.pory"
	return
# 541 "data//maps/LittlerootTown/scripts.pory"

# 542 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 543 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 544 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 545 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 546 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 547 "data//maps/LittlerootTown/scripts.pory"
	return
# 548 "data//maps/LittlerootTown/scripts.pory"

# 549 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 550 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 551 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 552 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 553 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 554 "data//maps/LittlerootTown/scripts.pory"
	return
# 555 "data//maps/LittlerootTown/scripts.pory"

# 556 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 557 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 558 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 559 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 560 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 561 "data//maps/LittlerootTown/scripts.pory"
	return
# 562 "data//maps/LittlerootTown/scripts.pory"

# 563 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 564 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 565 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 566 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 567 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 568 "data//maps/LittlerootTown/scripts.pory"
	return
# 569 "data//maps/LittlerootTown/scripts.pory"

# 570 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 571 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 572 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 573 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 574 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 575 "data//maps/LittlerootTown/scripts.pory"
	return
# 576 "data//maps/LittlerootTown/scripts.pory"

# 577 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 578 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 579 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 580 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 581 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 582 "data//maps/LittlerootTown/scripts.pory"
	return
# 583 "data//maps/LittlerootTown/scripts.pory"

# 584 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 585 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 586 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 587 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 588 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 589 "data//maps/LittlerootTown/scripts.pory"
	return
# 590 "data//maps/LittlerootTown/scripts.pory"

# 591 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 592 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 593 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 594 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 595 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 596 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 597 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 598 "data//maps/LittlerootTown/scripts.pory"
	return
# 599 "data//maps/LittlerootTown/scripts.pory"

# 600 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 601 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 602 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 603 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 604 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 605 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 606 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 607 "data//maps/LittlerootTown/scripts.pory"
	return
# 608 "data//maps/LittlerootTown/scripts.pory"

# 609 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 610 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 611 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 612 "data//maps/LittlerootTown/scripts.pory"
	return
# 613 "data//maps/LittlerootTown/scripts.pory"

# 614 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 615 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 616 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 617 "data//maps/LittlerootTown/scripts.pory"
	return
# 618 "data//maps/LittlerootTown/scripts.pory"

# 619 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 620 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 621 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 623 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 624 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 625 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 626 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 627 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 628 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 629 "data//maps/LittlerootTown/scripts.pory"
	return
# 630 "data//maps/LittlerootTown/scripts.pory"

# 631 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 632 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 633 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 634 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 635 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 636 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 637 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 638 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 639 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 640 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 641 "data//maps/LittlerootTown/scripts.pory"
	return
# 642 "data//maps/LittlerootTown/scripts.pory"

# 643 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 644 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 645 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 646 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 647 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 648 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 649 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 650 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 651 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 652 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 653 "data//maps/LittlerootTown/scripts.pory"
	return
# 654 "data//maps/LittlerootTown/scripts.pory"

# 655 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 656 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 657 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 658 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 659 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 660 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 661 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 662 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 663 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 664 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 665 "data//maps/LittlerootTown/scripts.pory"
	return
# 666 "data//maps/LittlerootTown/scripts.pory"

# 667 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 668 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 669 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 670 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 671 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 672 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 673 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 674 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 675 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 676 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 677 "data//maps/LittlerootTown/scripts.pory"
	return
# 678 "data//maps/LittlerootTown/scripts.pory"

# 679 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 680 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 681 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 682 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 683 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 684 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 685 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 686 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 687 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 688 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 689 "data//maps/LittlerootTown/scripts.pory"
	return
# 690 "data//maps/LittlerootTown/scripts.pory"

# 691 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 692 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 693 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 694 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 695 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 696 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 697 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 698 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 699 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 700 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 701 "data//maps/LittlerootTown/scripts.pory"
	return
# 702 "data//maps/LittlerootTown/scripts.pory"

# 703 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 704 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 705 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 706 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 707 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 708 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 709 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 710 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 711 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 712 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 713 "data//maps/LittlerootTown/scripts.pory"
	return
# 714 "data//maps/LittlerootTown/scripts.pory"

# 715 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 716 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 717 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 718 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 719 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 720 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 721 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 722 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 723 "data//maps/LittlerootTown/scripts.pory"

# 724 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 725 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 726 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 727 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 728 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 729 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 730 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 731 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 732 "data//maps/LittlerootTown/scripts.pory"

# 733 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 734 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 735 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 736 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 737 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 738 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 739 "data//maps/LittlerootTown/scripts.pory"

# 740 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 741 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 742 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 743 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 744 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 745 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 746 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 747 "data//maps/LittlerootTown/scripts.pory"

# 748 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 749 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 750 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 751 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 752 "data//maps/LittlerootTown/scripts.pory"

# 753 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 754 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 755 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 756 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 757 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 758 "data//maps/LittlerootTown/scripts.pory"

# 759 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 760 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 761 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 762 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 763 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 764 "data//maps/LittlerootTown/scripts.pory"

# 765 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 766 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 767 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 768 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 769 "data//maps/LittlerootTown/scripts.pory"

# 770 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 771 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 772 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 773 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 774 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 775 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 776 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 777 "data//maps/LittlerootTown/scripts.pory"

# 778 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 779 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 780 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 781 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 782 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 783 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 784 "data//maps/LittlerootTown/scripts.pory"

# 785 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 786 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 787 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 788 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 789 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 790 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 791 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 792 "data//maps/LittlerootTown/scripts.pory"

# 793 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 794 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 795 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 796 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 797 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 798 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 799 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 800 "data//maps/LittlerootTown/scripts.pory"

# 801 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 802 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 803 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 805 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 806 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 807 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 808 "data//maps/LittlerootTown/scripts.pory"

# 809 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 810 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 811 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 812 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 813 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 814 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 815 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 816 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 817 "data//maps/LittlerootTown/scripts.pory"

# 818 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 819 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 822 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 823 "data//maps/LittlerootTown/scripts.pory"

# 824 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 825 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 827 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 828 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 829 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 830 "data//maps/LittlerootTown/scripts.pory"

# 831 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 832 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 833 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 834 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 835 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 836 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 837 "data//maps/LittlerootTown/scripts.pory"

# 838 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 839 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 840 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 842 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 843 "data//maps/LittlerootTown/scripts.pory"

# 844 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 845 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 846 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 847 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 848 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 849 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 851 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 852 "data//maps/LittlerootTown/scripts.pory"

# 853 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 854 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 857 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 858 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 859 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 860 "data//maps/LittlerootTown/scripts.pory"

# 861 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 862 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 863 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 864 "data//maps/LittlerootTown/scripts.pory"

# 865 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 866 "data//maps/LittlerootTown/scripts.pory"
	lock
# 867 "data//maps/LittlerootTown/scripts.pory"
	faceplayer
# 868 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 869 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 870 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 871 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 872 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 873 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 874 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 875 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 876 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 877 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 878 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 879 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 880 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 881 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 882 "data//maps/LittlerootTown/scripts.pory"
	end
# 883 "data//maps/LittlerootTown/scripts.pory"

# 884 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 885 "data//maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 886 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 887 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 888 "data//maps/LittlerootTown/scripts.pory"
	release
# 889 "data//maps/LittlerootTown/scripts.pory"
	end
# 890 "data//maps/LittlerootTown/scripts.pory"

# 891 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 892 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 893 "data//maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 894 "data//maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 895 "data//maps/LittlerootTown/scripts.pory"
	waitfanfare
# 896 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 897 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 898 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 899 "data//maps/LittlerootTown/scripts.pory"
	delay 30
# 900 "data//maps/LittlerootTown/scripts.pory"
	return
# 901 "data//maps/LittlerootTown/scripts.pory"

# 902 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 903 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: We're here.\p"
# 904 "data//maps/LittlerootTown/scripts.pory"
	.string "It must be dangerous riding with our\n"
# 905 "data//maps/LittlerootTown/scripts.pory"
	.string "things in the back of the moving truck.\p"
# 906 "data//maps/LittlerootTown/scripts.pory"
	.string "Well, this is our new house\n"
# 907 "data//maps/LittlerootTown/scripts.pory"
	.string "in LITTLEROOT TOWN.\p"
# 908 "data//maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 909 "data//maps/LittlerootTown/scripts.pory"

# 910 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 911 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 912 "data//maps/LittlerootTown/scripts.pory"

# 913 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 914 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: Did you introduce\n"
# 915 "data//maps/LittlerootTown/scripts.pory"
	.string "yourself to PROF. BIRCH?\p"
# 916 "data//maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on\n"
# 917 "data//maps/LittlerootTown/scripts.pory"
	.string "your own, wear these RUNNING SHOES.$"
# 918 "data//maps/LittlerootTown/scripts.pory"

# 919 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 920 "data//maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} put on their\n"
# 921 "data//maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 922 "data//maps/LittlerootTown/scripts.pory"

# 923 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 924 "data//maps/LittlerootTown/scripts.pory"
	.string ". . . . . .\n"
# 925 "data//maps/LittlerootTown/scripts.pory"
	.string ". . . . . .\p"
# 926 "data//maps/LittlerootTown/scripts.pory"
	.string "Stay out of the papers . . .\p"
# 927 "data//maps/LittlerootTown/scripts.pory"
	.string "And don't get caught!$"
# 928 "data//maps/LittlerootTown/scripts.pory"

# 929 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 930 "data//maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 931 "data//maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 932 "data//maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 933 "data//maps/LittlerootTown/scripts.pory"

# 934 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 935 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 936 "data//maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 937 "data//maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 938 "data//maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 939 "data//maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 940 "data//maps/LittlerootTown/scripts.pory"

# 941 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 942 "data//maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 943 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH said he's working on\n"
# 944 "data//maps/LittlerootTown/scripts.pory"
	.string "something, so don't bother him!$"
# 945 "data//maps/LittlerootTown/scripts.pory"

# 946 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 947 "data//maps/LittlerootTown/scripts.pory"
	.string "That's what he told me\n"
# 948 "data//maps/LittlerootTown/scripts.pory"
	.string "at least . . .$"
# 949 "data//maps/LittlerootTown/scripts.pory"

# 950 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 951 "data//maps/LittlerootTown/scripts.pory"
	.string "The Professor needs help!$"
# 952 "data//maps/LittlerootTown/scripts.pory"

# 953 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 954 "data//maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 955 "data//maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 956 "data//maps/LittlerootTown/scripts.pory"

# 957 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 958 "data//maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 959 "data//maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 960 "data//maps/LittlerootTown/scripts.pory"

# 961 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 962 "data//maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 963 "data//maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 964 "data//maps/LittlerootTown/scripts.pory"

# 965 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 966 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 967 "data//maps/LittlerootTown/scripts.pory"

# 968 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 969 "data//maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 970 "data//maps/LittlerootTown/scripts.pory"

# 971 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 972 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 973 "data//maps/LittlerootTown/scripts.pory"

# 974 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 975 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 976 "data//maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 977 "data//maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 978 "data//maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 979 "data//maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 980 "data//maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 981 "data//maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 982 "data//maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 983 "data//maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_BirchSpawn::
# 988 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
	return

