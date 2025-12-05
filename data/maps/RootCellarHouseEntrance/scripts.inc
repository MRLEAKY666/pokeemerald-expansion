# 1 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 2 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_MapScripts::
# 3 "data//maps/RootCellarHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RootCellarHouseEntrance_MapScripts_OnTransition
# 4 "data//maps/RootCellarHouseEntrance/scripts.pory"
    map_script MAP_SCRIPT_ON_FRAME_TABLE, RootCellarHouseEntrance_MapScripts_OnFrame
# 5 "data//maps/RootCellarHouseEntrance/scripts.pory"
	.byte 0
# 6 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 7 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_MapScripts_OnFrame:
# 8 "data//maps/RootCellarHouseEntrance/scripts.pory"
    map_script_2 VAR_TEMP_0, 1, RootCellarHouseEntrance_EventScript_BerryMaster
# 9 "data//maps/RootCellarHouseEntrance/scripts.pory"
	.2byte 0
# 10 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 11 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_MapScripts_OnTransition::
# 12 "data//maps/RootCellarHouseEntrance/scripts.pory"
    call_if_unset FLAG_DISCOVERED_ROOT_CELLAR, RootCellarHouseEntrance_EventScript_QueueBerryMasterScene
# 13 "data//maps/RootCellarHouseEntrance/scripts.pory"
    end
# 14 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 15 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_EventScript_QueueBerryMasterScene::
# 16 "data//maps/RootCellarHouseEntrance/scripts.pory"
    setvar VAR_TEMP_0, 1
# 17 "data//maps/RootCellarHouseEntrance/scripts.pory"
    return
# 18 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 19 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_EventScript_BerryMaster::
# 20 "data//maps/RootCellarHouseEntrance/scripts.pory"
    lock
# 21 "data//maps/RootCellarHouseEntrance/scripts.pory"
    delay 15
# 22 "data//maps/RootCellarHouseEntrance/scripts.pory"
    playse SE_PIN
# 23 "data//maps/RootCellarHouseEntrance/scripts.pory"
    waitse
# 24 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
# 25 "data//maps/RootCellarHouseEntrance/scripts.pory"
    delay 16
# 26 "data//maps/RootCellarHouseEntrance/scripts.pory"
    msgbox RootCellarHouseEntrance_Text_BerryMaster1, MSGBOX_DEFAULT
# 27 "data//maps/RootCellarHouseEntrance/scripts.pory"
    closemessage
# 28 "data//maps/RootCellarHouseEntrance/scripts.pory"
    delay 20
# 29 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, Common_Movement_FaceUp
# 30 "data//maps/RootCellarHouseEntrance/scripts.pory"
    setobjectxy LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, 2, 4
# 31 "data//maps/RootCellarHouseEntrance/scripts.pory"
    showobjectat LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, MAP_ROOT_CELLAR_HOUSE_ENTRANCE
# 32 "data//maps/RootCellarHouseEntrance/scripts.pory"
    playse SE_EXIT
# 33 "data//maps/RootCellarHouseEntrance/scripts.pory"
    waitse
# 34 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, RootCellarHouseEntrance_Movement_BerryMasterWalkUp
# 35 "data//maps/RootCellarHouseEntrance/scripts.pory"
    waitmovement LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER
# 36 "data//maps/RootCellarHouseEntrance/scripts.pory"
    delay 15
# 37 "data//maps/RootCellarHouseEntrance/scripts.pory"
    msgbox RootCellarHouseEntrance_Text_BerryMaster2, MSGBOX_DEFAULT
# 38 "data//maps/RootCellarHouseEntrance/scripts.pory"
    closemessage
# 39 "data//maps/RootCellarHouseEntrance/scripts.pory"
    delay 30
# 40 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, RootCellarHouseEntrance_Movement_BerryMasterWalkDown
# 41 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_PLAYER, RootCellarHouseEntrance_Movement_BerryMasterWalkDown
# 42 "data//maps/RootCellarHouseEntrance/scripts.pory"
    waitmovement
# 43 "data//maps/RootCellarHouseEntrance/scripts.pory"
    hideobjectat LOCALID_ROOT_CELLAR_HOUSE_ENTRANCE_BERRY_MASTER, MAP_ROOT_CELLAR_HOUSE_ENTRANCE
# 44 "data//maps/RootCellarHouseEntrance/scripts.pory"
    playse SE_EXIT
# 45 "data//maps/RootCellarHouseEntrance/scripts.pory"
    applymovement LOCALID_PLAYER, RootCellarHouseEntrance_Movement_BerryMasterWalkDown
# 46 "data//maps/RootCellarHouseEntrance/scripts.pory"
    setflag FLAG_DISCOVERED_ROOT_CELLAR
# 47 "data//maps/RootCellarHouseEntrance/scripts.pory"
    setvar VAR_TEMP_0, 0
# 48 "data//maps/RootCellarHouseEntrance/scripts.pory"
    warp MAP_ROUTE123_BERRY_MASTERS_HOUSE, WARP_ID_BERRY_MASTER_CELLAR_DOOR
# 49 "data//maps/RootCellarHouseEntrance/scripts.pory"
    end
# 50 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 51 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_Text_BerryMaster1:
# 52 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "???: What's that back there?!$"
# 53 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 54 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_Text_BerryMaster2:
# 55 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "BERRY MASTER: Ah! a TRAINER found my\n"
# 56 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "root cellar!\p"
# 57 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "Well come on through!\l"
# 58 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "And I'm always glad to give you some\n"
# 59 "data//maps/RootCellarHouseEntrance/scripts.pory"
    .string "berries, but don't go sneaking around!$"
# 60 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 61 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_Movement_BerryMasterWalkUp:
# 62 "data//maps/RootCellarHouseEntrance/scripts.pory"
    walk_up
# 63 "data//maps/RootCellarHouseEntrance/scripts.pory"
    step_end
# 64 "data//maps/RootCellarHouseEntrance/scripts.pory"

# 65 "data//maps/RootCellarHouseEntrance/scripts.pory"
RootCellarHouseEntrance_Movement_BerryMasterWalkDown:
# 66 "data//maps/RootCellarHouseEntrance/scripts.pory"
    walk_down
# 67 "data//maps/RootCellarHouseEntrance/scripts.pory"
    step_end
