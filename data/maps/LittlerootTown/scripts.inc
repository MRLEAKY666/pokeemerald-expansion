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
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 45 "data//maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 46 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 47 "data//maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 48 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 49 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 50 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 51 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 52 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 53 "data//maps/LittlerootTown/scripts.pory"
	@ call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 54 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 55 "data//maps/LittlerootTown/scripts.pory"
	end
# 56 "data//maps/LittlerootTown/scripts.pory"

# 57 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 58 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 59 "data//maps/LittlerootTown/scripts.pory"
	return
# 60 "data//maps/LittlerootTown/scripts.pory"

# 61 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 62 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 63 "data//maps/LittlerootTown/scripts.pory"
	return
# 64 "data//maps/LittlerootTown/scripts.pory"

# 65 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 66 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 67 "data//maps/LittlerootTown/scripts.pory"
	return
# 68 "data//maps/LittlerootTown/scripts.pory"

# 69 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 70 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 71 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 72 "data//maps/LittlerootTown/scripts.pory"
	return
# 73 "data//maps/LittlerootTown/scripts.pory"

# 74 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 75 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 76 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 77 "data//maps/LittlerootTown/scripts.pory"
	return
# 78 "data//maps/LittlerootTown/scripts.pory"

# 79 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 80 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 81 "data//maps/LittlerootTown/scripts.pory"
	return
# 82 "data//maps/LittlerootTown/scripts.pory"

# 83 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 84 "data//maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 85 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 86 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 87 "data//maps/LittlerootTown/scripts.pory"
	return
# 88 "data//maps/LittlerootTown/scripts.pory"

# 89 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 90 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 91 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 92 "data//maps/LittlerootTown/scripts.pory"
	return
# 93 "data//maps/LittlerootTown/scripts.pory"

# 94 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 95 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 96 "data//maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 97 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 98 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 99 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 100 "data//maps/LittlerootTown/scripts.pory"
	return
# 101 "data//maps/LittlerootTown/scripts.pory"

# 102 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 103 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 104 "data//maps/LittlerootTown/scripts.pory"
	return
# 105 "data//maps/LittlerootTown/scripts.pory"

# 106 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 107 "data//maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 108 "data//maps/LittlerootTown/scripts.pory"
	return
# 109 "data//maps/LittlerootTown/scripts.pory"

# 110 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 111 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 112 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 113 "data//maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 114 "data//maps/LittlerootTown/scripts.pory"
	.2byte 0
# 115 "data//maps/LittlerootTown/scripts.pory"

# 116 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 117 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 118 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 119 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 120 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 121 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 122 "data//maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 123 "data//maps/LittlerootTown/scripts.pory"
	waitstate
# 124 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 125 "data//maps/LittlerootTown/scripts.pory"
	end
# 126 "data//maps/LittlerootTown/scripts.pory"

# 127 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 128 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 129 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 130 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 131 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 132 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 133 "data//maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 134 "data//maps/LittlerootTown/scripts.pory"
	waitstate
# 135 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 136 "data//maps/LittlerootTown/scripts.pory"
	end
# 137 "data//maps/LittlerootTown/scripts.pory"

# 138 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 139 "data//maps/LittlerootTown/scripts.pory"
	delay 15
# 140 "data//maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 141 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 142 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 143 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 144 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 145 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 146 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 147 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 148 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 149 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 150 "data//maps/LittlerootTown/scripts.pory"
	delay 10
# 151 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 152 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 153 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 154 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 155 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 156 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 157 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 158 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 159 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 160 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 161 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 162 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 163 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 164 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 165 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 166 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 167 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 168 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 169 "data//maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 170 "data//maps/LittlerootTown/scripts.pory"
	return
# 171 "data//maps/LittlerootTown/scripts.pory"

# 172 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 173 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 174 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 175 "data//maps/LittlerootTown/scripts.pory"

# 176 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 177 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 178 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 179 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 180 "data//maps/LittlerootTown/scripts.pory"

# 181 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 182 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 183 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 184 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 185 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 186 "data//maps/LittlerootTown/scripts.pory"

# 187 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 188 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 189 "data//maps/LittlerootTown/scripts.pory"
	set_invisible
# 190 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 191 "data//maps/LittlerootTown/scripts.pory"

# 192 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 193 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 194 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 195 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 196 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 197 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 198 "data//maps/LittlerootTown/scripts.pory"

# 199 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 200 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 201 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 203 "data//maps/LittlerootTown/scripts.pory"

# 204 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 205 "data//maps/LittlerootTown/scripts.pory"
	jump_right
# 206 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 207 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 208 "data//maps/LittlerootTown/scripts.pory"
	delay_16
# 209 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 210 "data//maps/LittlerootTown/scripts.pory"

# 211 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 212 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 213 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 214 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 215 "data//maps/LittlerootTown/scripts.pory"
	end
# 216 "data//maps/LittlerootTown/scripts.pory"

# 217 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 218 "data//maps/LittlerootTown/scripts.pory"
	@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 219 "data//maps/LittlerootTown/scripts.pory"
	.2byte 0
# 220 "data//maps/LittlerootTown/scripts.pory"

# 221 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 222 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 223 "data//maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 224 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 225 "data//maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 226 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 227 "data//maps/LittlerootTown/scripts.pory"
	end
# 228 "data//maps/LittlerootTown/scripts.pory"

# 229 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 230 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 231 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 232 "data//maps/LittlerootTown/scripts.pory"
	end
# 233 "data//maps/LittlerootTown/scripts.pory"

# 234 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 235 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 236 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 237 "data//maps/LittlerootTown/scripts.pory"
	end
# 238 "data//maps/LittlerootTown/scripts.pory"

# 239 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 240 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 241 "data//maps/LittlerootTown/scripts.pory"
	end
# 242 "data//maps/LittlerootTown/scripts.pory"

# 243 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 244 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 245 "data//maps/LittlerootTown/scripts.pory"
	end
# 246 "data//maps/LittlerootTown/scripts.pory"

# 247 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 248 "data//maps/LittlerootTown/scripts.pory"
	lock
# 249 "data//maps/LittlerootTown/scripts.pory"
	faceplayer
# 250 "data//maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 251 "data//maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 252 "data//maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 253 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 254 "data//maps/LittlerootTown/scripts.pory"
	release
# 255 "data//maps/LittlerootTown/scripts.pory"
	end
# 256 "data//maps/LittlerootTown/scripts.pory"

# 257 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 258 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 259 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 260 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 261 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 262 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 263 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 264 "data//maps/LittlerootTown/scripts.pory"
	release
# 265 "data//maps/LittlerootTown/scripts.pory"
	end
# 266 "data//maps/LittlerootTown/scripts.pory"

# 267 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 268 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 269 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 270 "data//maps/LittlerootTown/scripts.pory"
	release
# 271 "data//maps/LittlerootTown/scripts.pory"
	end
# 272 "data//maps/LittlerootTown/scripts.pory"

# 273 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 274 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 275 "data//maps/LittlerootTown/scripts.pory"
	release
# 276 "data//maps/LittlerootTown/scripts.pory"
	end
# 277 "data//maps/LittlerootTown/scripts.pory"

# 278 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 279 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 280 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 281 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 282 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 283 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 284 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 285 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 286 "data//maps/LittlerootTown/scripts.pory"
	end
# 287 "data//maps/LittlerootTown/scripts.pory"

# 288 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 289 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 290 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 291 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 292 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 293 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 294 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 295 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 296 "data//maps/LittlerootTown/scripts.pory"
	return
# 297 "data//maps/LittlerootTown/scripts.pory"

# 298 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 299 "data//maps/LittlerootTown/scripts.pory"
	face_right
# 300 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 301 "data//maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 302 "data//maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 303 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 304 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 305 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 306 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 307 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 308 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 309 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 310 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 311 "data//maps/LittlerootTown/scripts.pory"
	face_down
# 312 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 313 "data//maps/LittlerootTown/scripts.pory"

# 314 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 315 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 316 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 317 "data//maps/LittlerootTown/scripts.pory"

# 318 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 319 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 320 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 322 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 323 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 324 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 325 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 326 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 327 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 328 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 329 "data//maps/LittlerootTown/scripts.pory"

# 330 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 331 "data//maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 332 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 333 "data//maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 334 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 335 "data//maps/LittlerootTown/scripts.pory"

# 336 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 337 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 338 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 339 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 340 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 341 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 342 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 343 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 344 "data//maps/LittlerootTown/scripts.pory"
	end
# 345 "data//maps/LittlerootTown/scripts.pory"

# 346 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 347 "data//maps/LittlerootTown/scripts.pory"
	face_right
# 348 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 349 "data//maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 350 "data//maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 351 "data//maps/LittlerootTown/scripts.pory"
	delay_8
# 352 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 353 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 354 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 355 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 356 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 357 "data//maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 358 "data//maps/LittlerootTown/scripts.pory"
	face_down
# 359 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 360 "data//maps/LittlerootTown/scripts.pory"

# 361 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 362 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 363 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 364 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 365 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 366 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 367 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 368 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 369 "data//maps/LittlerootTown/scripts.pory"

# 370 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 371 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 372 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 373 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 374 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 375 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 376 "data//maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 377 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 378 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 379 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 380 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 381 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 382 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 383 "data//maps/LittlerootTown/scripts.pory"
	end
# 384 "data//maps/LittlerootTown/scripts.pory"

# 385 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 386 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 387 "data//maps/LittlerootTown/scripts.pory"
	end
# 388 "data//maps/LittlerootTown/scripts.pory"

# 389 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 390 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 391 "data//maps/LittlerootTown/scripts.pory"
	end
# 392 "data//maps/LittlerootTown/scripts.pory"

# 393 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 394 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 395 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 396 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 397 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 398 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 399 "data//maps/LittlerootTown/scripts.pory"
	end
# 400 "data//maps/LittlerootTown/scripts.pory"

# 401 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 402 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 403 "data//maps/LittlerootTown/scripts.pory"
	return
# 404 "data//maps/LittlerootTown/scripts.pory"

# 405 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 406 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 407 "data//maps/LittlerootTown/scripts.pory"
	return
# 408 "data//maps/LittlerootTown/scripts.pory"

# 409 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 410 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 411 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 412 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 413 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 414 "data//maps/LittlerootTown/scripts.pory"
	releaseall
# 415 "data//maps/LittlerootTown/scripts.pory"
	end
# 416 "data//maps/LittlerootTown/scripts.pory"

# 417 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 418 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 419 "data//maps/LittlerootTown/scripts.pory"
	return
# 420 "data//maps/LittlerootTown/scripts.pory"

# 421 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 422 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 423 "data//maps/LittlerootTown/scripts.pory"
	return
# 424 "data//maps/LittlerootTown/scripts.pory"

# 425 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 426 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 427 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 428 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 429 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 430 "data//maps/LittlerootTown/scripts.pory"
	end
# 431 "data//maps/LittlerootTown/scripts.pory"

# 432 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 433 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 434 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 435 "data//maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 436 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 437 "data//maps/LittlerootTown/scripts.pory"
	end
# 438 "data//maps/LittlerootTown/scripts.pory"

# 439 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 440 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 441 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 442 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 443 "data//maps/LittlerootTown/scripts.pory"
	end
# 444 "data//maps/LittlerootTown/scripts.pory"

# 445 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 446 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 447 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 448 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 449 "data//maps/LittlerootTown/scripts.pory"
	end
# 450 "data//maps/LittlerootTown/scripts.pory"

# 451 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 452 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 453 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 454 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 455 "data//maps/LittlerootTown/scripts.pory"
	end
# 456 "data//maps/LittlerootTown/scripts.pory"

# 457 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 458 "data//maps/LittlerootTown/scripts.pory"
	lockall
# 459 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 460 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 461 "data//maps/LittlerootTown/scripts.pory"
	end
# 462 "data//maps/LittlerootTown/scripts.pory"

# 463 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 464 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 465 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 466 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 467 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 468 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 469 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 470 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 471 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 472 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 473 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 474 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 475 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 476 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 477 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 478 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 479 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 480 "data//maps/LittlerootTown/scripts.pory"
	end
# 481 "data//maps/LittlerootTown/scripts.pory"

# 482 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 483 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 484 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 485 "data//maps/LittlerootTown/scripts.pory"
	return
# 486 "data//maps/LittlerootTown/scripts.pory"

# 487 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 488 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 489 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 490 "data//maps/LittlerootTown/scripts.pory"
	return
# 491 "data//maps/LittlerootTown/scripts.pory"

# 492 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 493 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 494 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 495 "data//maps/LittlerootTown/scripts.pory"
	return
# 496 "data//maps/LittlerootTown/scripts.pory"

# 497 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 498 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 499 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 500 "data//maps/LittlerootTown/scripts.pory"
	return
# 501 "data//maps/LittlerootTown/scripts.pory"

# 502 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 503 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 504 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 505 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 506 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 507 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 508 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 509 "data//maps/LittlerootTown/scripts.pory"
	return
# 510 "data//maps/LittlerootTown/scripts.pory"

# 511 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 512 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 513 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 514 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 515 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 516 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 517 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 518 "data//maps/LittlerootTown/scripts.pory"
	return
# 519 "data//maps/LittlerootTown/scripts.pory"

# 520 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 521 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 522 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 523 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 524 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 525 "data//maps/LittlerootTown/scripts.pory"
	return
# 526 "data//maps/LittlerootTown/scripts.pory"

# 527 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 528 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 529 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 530 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 531 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 532 "data//maps/LittlerootTown/scripts.pory"
	return
# 533 "data//maps/LittlerootTown/scripts.pory"

# 534 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 535 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 536 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 537 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 538 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 539 "data//maps/LittlerootTown/scripts.pory"
	return
# 540 "data//maps/LittlerootTown/scripts.pory"

# 541 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 542 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 543 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 544 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 545 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 546 "data//maps/LittlerootTown/scripts.pory"
	return
# 547 "data//maps/LittlerootTown/scripts.pory"

# 548 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 549 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 550 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 551 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 552 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 553 "data//maps/LittlerootTown/scripts.pory"
	return
# 554 "data//maps/LittlerootTown/scripts.pory"

# 555 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 556 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 557 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 558 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 559 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 560 "data//maps/LittlerootTown/scripts.pory"
	return
# 561 "data//maps/LittlerootTown/scripts.pory"

# 562 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 563 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 564 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 565 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 566 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 567 "data//maps/LittlerootTown/scripts.pory"
	return
# 568 "data//maps/LittlerootTown/scripts.pory"

# 569 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 570 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 571 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 572 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 573 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 574 "data//maps/LittlerootTown/scripts.pory"
	return
# 575 "data//maps/LittlerootTown/scripts.pory"

# 576 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 577 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 578 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 579 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 580 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 581 "data//maps/LittlerootTown/scripts.pory"
	return
# 582 "data//maps/LittlerootTown/scripts.pory"

# 583 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 584 "data//maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 585 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 586 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 587 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 588 "data//maps/LittlerootTown/scripts.pory"
	return
# 589 "data//maps/LittlerootTown/scripts.pory"

# 590 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 591 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 592 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 593 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 594 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 595 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 596 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 597 "data//maps/LittlerootTown/scripts.pory"
	return
# 598 "data//maps/LittlerootTown/scripts.pory"

# 599 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 600 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 601 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 602 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 603 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 604 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 605 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 606 "data//maps/LittlerootTown/scripts.pory"
	return
# 607 "data//maps/LittlerootTown/scripts.pory"

# 608 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 609 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 610 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 611 "data//maps/LittlerootTown/scripts.pory"
	return
# 612 "data//maps/LittlerootTown/scripts.pory"

# 613 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 614 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 615 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 616 "data//maps/LittlerootTown/scripts.pory"
	return
# 617 "data//maps/LittlerootTown/scripts.pory"

# 618 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 619 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 620 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 621 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 622 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 623 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 624 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 625 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 626 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 627 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 628 "data//maps/LittlerootTown/scripts.pory"
	return
# 629 "data//maps/LittlerootTown/scripts.pory"

# 630 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 631 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 632 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 633 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 634 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 635 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 636 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 637 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 638 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 639 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 640 "data//maps/LittlerootTown/scripts.pory"
	return
# 641 "data//maps/LittlerootTown/scripts.pory"

# 642 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 643 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 644 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 645 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 646 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 647 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 648 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 649 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 650 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 651 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 652 "data//maps/LittlerootTown/scripts.pory"
	return
# 653 "data//maps/LittlerootTown/scripts.pory"

# 654 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 655 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 656 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 657 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 658 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 659 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 660 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 661 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 662 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 663 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 664 "data//maps/LittlerootTown/scripts.pory"
	return
# 665 "data//maps/LittlerootTown/scripts.pory"

# 666 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 667 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 668 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 669 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 670 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 671 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 672 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 673 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 674 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 675 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 676 "data//maps/LittlerootTown/scripts.pory"
	return
# 677 "data//maps/LittlerootTown/scripts.pory"

# 678 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 679 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 680 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 681 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 682 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 683 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 684 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 685 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 686 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 687 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 688 "data//maps/LittlerootTown/scripts.pory"
	return
# 689 "data//maps/LittlerootTown/scripts.pory"

# 690 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 691 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 692 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 693 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 694 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 695 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 696 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 697 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 698 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 699 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 700 "data//maps/LittlerootTown/scripts.pory"
	return
# 701 "data//maps/LittlerootTown/scripts.pory"

# 702 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 703 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 704 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 705 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 706 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 707 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 708 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 710 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 711 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 712 "data//maps/LittlerootTown/scripts.pory"
	return
# 713 "data//maps/LittlerootTown/scripts.pory"

# 714 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 715 "data//maps/LittlerootTown/scripts.pory"
	walk_up
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
	step_end
# 722 "data//maps/LittlerootTown/scripts.pory"

# 723 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 724 "data//maps/LittlerootTown/scripts.pory"
	walk_up
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
	step_end
# 731 "data//maps/LittlerootTown/scripts.pory"

# 732 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 733 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 734 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 735 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 736 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 737 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 738 "data//maps/LittlerootTown/scripts.pory"

# 739 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 740 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 741 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 742 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 743 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 744 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 745 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 746 "data//maps/LittlerootTown/scripts.pory"

# 747 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 748 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 749 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 750 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 751 "data//maps/LittlerootTown/scripts.pory"

# 752 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 753 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 754 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 755 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 756 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 757 "data//maps/LittlerootTown/scripts.pory"

# 758 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 759 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 760 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 761 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 762 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 763 "data//maps/LittlerootTown/scripts.pory"

# 764 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 765 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 766 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 767 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 768 "data//maps/LittlerootTown/scripts.pory"

# 769 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 770 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 771 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 772 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 773 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 774 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 775 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 776 "data//maps/LittlerootTown/scripts.pory"

# 777 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 778 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 779 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 780 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 781 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 782 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 783 "data//maps/LittlerootTown/scripts.pory"

# 784 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 785 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 786 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 787 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 788 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 789 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 790 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 791 "data//maps/LittlerootTown/scripts.pory"

# 792 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 793 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 794 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 795 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 796 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 797 "data//maps/LittlerootTown/scripts.pory"
	walk_down
# 798 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 799 "data//maps/LittlerootTown/scripts.pory"

# 800 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 801 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 802 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 803 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 805 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 806 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 807 "data//maps/LittlerootTown/scripts.pory"

# 808 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 809 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 810 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 811 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 812 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 813 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 814 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 815 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 816 "data//maps/LittlerootTown/scripts.pory"

# 817 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 818 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 819 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 821 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 822 "data//maps/LittlerootTown/scripts.pory"

# 823 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 824 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data//maps/LittlerootTown/scripts.pory"
	walk_left
# 827 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 828 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 829 "data//maps/LittlerootTown/scripts.pory"

# 830 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 831 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 832 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 833 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 834 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 835 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 836 "data//maps/LittlerootTown/scripts.pory"

# 837 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 838 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 839 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 840 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 841 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 842 "data//maps/LittlerootTown/scripts.pory"

# 843 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 844 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 846 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 847 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 848 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 849 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 850 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 851 "data//maps/LittlerootTown/scripts.pory"

# 852 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 853 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 854 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data//maps/LittlerootTown/scripts.pory"
	walk_right
# 857 "data//maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 858 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 859 "data//maps/LittlerootTown/scripts.pory"

# 860 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 861 "data//maps/LittlerootTown/scripts.pory"
	walk_up
# 862 "data//maps/LittlerootTown/scripts.pory"
	step_end
# 863 "data//maps/LittlerootTown/scripts.pory"

# 864 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 865 "data//maps/LittlerootTown/scripts.pory"
	lock
# 866 "data//maps/LittlerootTown/scripts.pory"
	faceplayer
# 867 "data//maps/LittlerootTown/scripts.pory"
	checkplayergender
# 868 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 869 "data//maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 870 "data//maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 871 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 872 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 873 "data//maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 874 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 875 "data//maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 876 "data//maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 877 "data//maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 878 "data//maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 879 "data//maps/LittlerootTown/scripts.pory"
	waitdooranim
# 880 "data//maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 881 "data//maps/LittlerootTown/scripts.pory"
	end
# 882 "data//maps/LittlerootTown/scripts.pory"

# 883 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 884 "data//maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 885 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 886 "data//maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 887 "data//maps/LittlerootTown/scripts.pory"
	release
# 888 "data//maps/LittlerootTown/scripts.pory"
	end
# 889 "data//maps/LittlerootTown/scripts.pory"

# 890 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 891 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 892 "data//maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 893 "data//maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 894 "data//maps/LittlerootTown/scripts.pory"
	waitfanfare
# 895 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 896 "data//maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 897 "data//maps/LittlerootTown/scripts.pory"
	closemessage
# 898 "data//maps/LittlerootTown/scripts.pory"
	delay 30
# 899 "data//maps/LittlerootTown/scripts.pory"
	return
# 900 "data//maps/LittlerootTown/scripts.pory"

# 901 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 902 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: We're here.\p"
# 903 "data//maps/LittlerootTown/scripts.pory"
	.string "It must be dangerous riding with our\n"
# 904 "data//maps/LittlerootTown/scripts.pory"
	.string "things in the back of the moving truck.\p"
# 905 "data//maps/LittlerootTown/scripts.pory"
	.string "Well, this is our new house\n"
# 906 "data//maps/LittlerootTown/scripts.pory"
	.string "in LITTLEROOT TOWN.\p"
# 907 "data//maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 908 "data//maps/LittlerootTown/scripts.pory"

# 909 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 910 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 911 "data//maps/LittlerootTown/scripts.pory"

# 912 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 913 "data//maps/LittlerootTown/scripts.pory"
	.string "MOM: Did you introduce\n"
# 914 "data//maps/LittlerootTown/scripts.pory"
	.string "yourself to PROF. BIRCH?\p"
# 915 "data//maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on\n"
# 916 "data//maps/LittlerootTown/scripts.pory"
	.string "your own, wear these RUNNING SHOES.$"
# 917 "data//maps/LittlerootTown/scripts.pory"

# 918 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 919 "data//maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} put on their\n"
# 920 "data//maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 921 "data//maps/LittlerootTown/scripts.pory"

# 922 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 923 "data//maps/LittlerootTown/scripts.pory"
	.string ". . . . . .\n"
# 924 "data//maps/LittlerootTown/scripts.pory"
	.string ". . . . . .\p"
# 925 "data//maps/LittlerootTown/scripts.pory"
	.string "Stay out of the papers . . .\p"
# 926 "data//maps/LittlerootTown/scripts.pory"
	.string "And don't get caught!$"
# 927 "data//maps/LittlerootTown/scripts.pory"

# 928 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 929 "data//maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 930 "data//maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 931 "data//maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 932 "data//maps/LittlerootTown/scripts.pory"

# 933 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 934 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 935 "data//maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 936 "data//maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 937 "data//maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 938 "data//maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 939 "data//maps/LittlerootTown/scripts.pory"

# 940 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 941 "data//maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 942 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH said he's working on\n"
# 943 "data//maps/LittlerootTown/scripts.pory"
	.string "something, so don't bother him!$"
# 944 "data//maps/LittlerootTown/scripts.pory"

# 945 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 946 "data//maps/LittlerootTown/scripts.pory"
	.string "That's what he told me\n"
# 947 "data//maps/LittlerootTown/scripts.pory"
	.string "at least . . .$"
# 948 "data//maps/LittlerootTown/scripts.pory"

# 949 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 950 "data//maps/LittlerootTown/scripts.pory"
	.string "The Professor needs help!$"
# 951 "data//maps/LittlerootTown/scripts.pory"

# 952 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 953 "data//maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 954 "data//maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 955 "data//maps/LittlerootTown/scripts.pory"

# 956 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 957 "data//maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 958 "data//maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 959 "data//maps/LittlerootTown/scripts.pory"

# 960 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 961 "data//maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 962 "data//maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 963 "data//maps/LittlerootTown/scripts.pory"

# 964 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 965 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 966 "data//maps/LittlerootTown/scripts.pory"

# 967 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 968 "data//maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 969 "data//maps/LittlerootTown/scripts.pory"

# 970 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 971 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 972 "data//maps/LittlerootTown/scripts.pory"

# 973 "data//maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 974 "data//maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 975 "data//maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 976 "data//maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 977 "data//maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 978 "data//maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 979 "data//maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 980 "data//maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 981 "data//maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 982 "data//maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_BirchSpawn::
# 987 "data//maps/LittlerootTown/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
	return

