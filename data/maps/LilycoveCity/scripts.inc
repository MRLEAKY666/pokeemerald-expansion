# 1 "data//maps/LilycoveCity/scripts.pory"

# 2 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 3 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 4 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 5 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, LilycoveCity_OnResume
# 6 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_OnFrame
# 7 "data//maps/LilycoveCity/scripts.pory"
	.byte 0

LilycoveCity_OnTransition::
# 15 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_TEMP_1E
# 16 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SHOW_SHADY_TRUCK, LilycoveCity_OnTransition_3
LilycoveCity_OnTransition_1:
# 19 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 20 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 21 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 22 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 23 "data//maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnTransition_2:
# 17 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_TEMP_1E
	goto LilycoveCity_OnTransition_1

LilycoveCity_OnTransition_3:
# 16 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_SHADY_TRUCK_LOCATION, 2
	goto_if_eq LilycoveCity_OnTransition_2
	goto LilycoveCity_OnTransition_1


LilycoveCity_OnResume::
# 28 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, LilycoveCity_OnResume_1
# 32 "data//maps/LilycoveCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 33 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_TEMP_E, 40
	goto_if_eq LilycoveCity_OnResume_5
	return

LilycoveCity_OnResume_1:
# 29 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_TEMP_1F
	return

LilycoveCity_OnResume_4:
# 34 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_TEMP_1E
# 35 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_TEMP_1F
# 36 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
	return

LilycoveCity_OnResume_5:
# 33 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_TEMP_F, 30
	goto_if_eq LilycoveCity_OnResume_4
	return


LilycoveCity_EventScript_ReturningFromShadyTruck::
# 42 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, LilycoveCity_EventScript_ReturningFromShadyTruck_2
LilycoveCity_EventScript_ReturningFromShadyTruck_1:
# 85 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_TEMP_F, 0
# 86 "data//maps/LilycoveCity/scripts.pory"
	release
	return

LilycoveCity_EventScript_ReturningFromShadyTruck_2:
# 43 "data//maps/LilycoveCity/scripts.pory"
	setobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY, 0
# 44 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 45 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_JumpOutOfTruck
# 46 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 47 "data//maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_SHOW_SHADY_TRUCK, LilycoveCity_EventScript_ReturningFromShadyTruck_5
LilycoveCity_EventScript_ReturningFromShadyTruck_4:
# 83 "data//maps/LilycoveCity/scripts.pory"
	resetobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY
	goto LilycoveCity_EventScript_ReturningFromShadyTruck_1

LilycoveCity_EventScript_ReturningFromShadyTruck_5:
# 48 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_MoveAwayFromTruck
# 49 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 50 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceFasterDown
# 51 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 52 "data//maps/LilycoveCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
# 53 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0
# 54 "data//maps/LilycoveCity/scripts.pory"
	waitmoncry
# 55 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 56 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 57 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, RustboroCity_Movement_AlakazamEnterTruck
# 58 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 59 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 60 "data//maps/LilycoveCity/scripts.pory"
	waitmovement LOCALID_LILYCOVE_SHADY_ALAKAZAM
# 61 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 62 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 63 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 64 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 65 "data//maps/LilycoveCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 66 "data//maps/LilycoveCity/scripts.pory"
	delay 60
# 67 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_MOVE
# 68 "data//maps/LilycoveCity/scripts.pory"
	delay 120
# 69 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_STOP
# 70 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 71 "data//maps/LilycoveCity/scripts.pory"
	delay 45
# 72 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_SHADY_TRUCK
# 73 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_SHADY_ALAKAZAM
# 74 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_TRUCK_COLLISION_A
# 75 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_TRUCK_COLLISION_B
# 76 "data//maps/LilycoveCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 77 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 78 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_1
# 79 "data//maps/LilycoveCity/scripts.pory"
	waitmessage
# 80 "data//maps/LilycoveCity/scripts.pory"
	delay 90
# 81 "data//maps/LilycoveCity/scripts.pory"
	closemessage
	goto LilycoveCity_EventScript_ReturningFromShadyTruck_4


LilycoveCity_EventScript_ShadyAlakazam::
# 90 "data//maps/LilycoveCity/scripts.pory"
	lock
# 91 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 92 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 93 "data//maps/LilycoveCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_HIGH_PITCH
# 94 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0
# 95 "data//maps/LilycoveCity/scripts.pory"
	waitmoncry
# 96 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 97 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ShadyAlakazam_Text_0
# 98 "data//maps/LilycoveCity/scripts.pory"
	waitmessage
# 99 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 100 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 101 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LilycoveCity_EventScript_ShadyAlakazam_2
# 105 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_EventScript_ShadyAlakazam_Text_2, MSGBOX_YESNO
# 107 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 108 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_EventScript_ShadyAlakazam_5
LilycoveCity_EventScript_ShadyAlakazam_1:
# 112 "data//maps/LilycoveCity/scripts.pory"
	release
	return

LilycoveCity_EventScript_ShadyAlakazam_2:
# 102 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_EventScript_ShadyAlakazam_Text_1, MSGBOX_DEFAULT
	goto LilycoveCity_EventScript_ShadyAlakazam_1

LilycoveCity_EventScript_ShadyAlakazam_5:
# 109 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_EnterShadyTruck
	goto LilycoveCity_EventScript_ShadyAlakazam_1


LilycoveCity_EventScript_TruckEntrance::
# 116 "data//maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_TEMP_1E, LilycoveCity_EventScript_TruckEntrance_1
	return

LilycoveCity_EventScript_TruckEntrance_1:
# 117 "data//maps/LilycoveCity/scripts.pory"
	lock
# 118 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 119 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 120 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 121 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 122 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne LilycoveCity_EventScript_TruckEntrance_4
LilycoveCity_EventScript_TruckEntrance_3:
# 126 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_ShadyAlakazam
	return

LilycoveCity_EventScript_TruckEntrance_4:
# 123 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 124 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
	goto LilycoveCity_EventScript_TruckEntrance_3


LilycoveCity_EventScript_EnterShadyTruck::
# 131 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 132 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceDown
# 133 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 134 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 135 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 136 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 137 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 138 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 139 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne LilycoveCity_EventScript_EnterShadyTruck_2
LilycoveCity_EventScript_EnterShadyTruck_1:
# 143 "data//maps/LilycoveCity/scripts.pory"
	setobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY, 0
# 144 "data//maps/LilycoveCity/scripts.pory"
	hidefollower
# 145 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerEnterTruck
# 146 "data//maps/LilycoveCity/scripts.pory"
	delay 32
# 147 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 148 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 149 "data//maps/LilycoveCity/scripts.pory"
	playse SE_EXIT
# 150 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 151 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 152 "data//maps/LilycoveCity/scripts.pory"
	warpcontinuescript MAP_SHADY_GUYS_TRUCK, 5, 2, ShadyGuysTruck_EventScript_PlayerEntersTruck
	return

LilycoveCity_EventScript_EnterShadyTruck_2:
# 140 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 141 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
	goto LilycoveCity_EventScript_EnterShadyTruck_1


# 155 "data//maps/LilycoveCity/scripts.pory"

# 156 "data//maps/LilycoveCity/scripts.pory"

# 157 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnFrame:
# 158 "data//maps/LilycoveCity/scripts.pory"
	map_script_2 VAR_TEMP_F, 30, LilycoveCity_EventScript_ReturningFromShadyTruck
# 159 "data//maps/LilycoveCity/scripts.pory"
	.2byte 0
# 160 "data//maps/LilycoveCity/scripts.pory"

# 161 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 162 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 163 "data//maps/LilycoveCity/scripts.pory"
	end
# 164 "data//maps/LilycoveCity/scripts.pory"

# 165 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 166 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 167 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 168 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 169 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 170 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 171 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 172 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 173 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 174 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 175 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 176 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 177 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 178 "data//maps/LilycoveCity/scripts.pory"
	return
# 179 "data//maps/LilycoveCity/scripts.pory"

# 180 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 181 "data//maps/LilycoveCity/scripts.pory"
	lock
# 182 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 183 "data//maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 184 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 185 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 186 "data//maps/LilycoveCity/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
# 187 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 188 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 189 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 190 "data//maps/LilycoveCity/scripts.pory"
	release
# 191 "data//maps/LilycoveCity/scripts.pory"
	end
# 192 "data//maps/LilycoveCity/scripts.pory"

# 193 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 194 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 195 "data//maps/LilycoveCity/scripts.pory"
	release
# 196 "data//maps/LilycoveCity/scripts.pory"
	end
# 197 "data//maps/LilycoveCity/scripts.pory"

# 198 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 199 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 200 "data//maps/LilycoveCity/scripts.pory"
	end
# 201 "data//maps/LilycoveCity/scripts.pory"

# 202 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 203 "data//maps/LilycoveCity/scripts.pory"
	lock
# 204 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 205 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 206 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 207 "data//maps/LilycoveCity/scripts.pory"
	release
# 208 "data//maps/LilycoveCity/scripts.pory"
	end
# 209 "data//maps/LilycoveCity/scripts.pory"

# 210 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 211 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 212 "data//maps/LilycoveCity/scripts.pory"
	release
# 213 "data//maps/LilycoveCity/scripts.pory"
	end
# 214 "data//maps/LilycoveCity/scripts.pory"

# 215 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 216 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 217 "data//maps/LilycoveCity/scripts.pory"
	end
# 218 "data//maps/LilycoveCity/scripts.pory"

# 219 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 220 "data//maps/LilycoveCity/scripts.pory"
	lock
# 221 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 222 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 223 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 224 "data//maps/LilycoveCity/scripts.pory"
	release
# 225 "data//maps/LilycoveCity/scripts.pory"
	end
# 226 "data//maps/LilycoveCity/scripts.pory"

# 227 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 228 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 229 "data//maps/LilycoveCity/scripts.pory"
	release
# 230 "data//maps/LilycoveCity/scripts.pory"
	end
# 231 "data//maps/LilycoveCity/scripts.pory"

# 232 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 233 "data//maps/LilycoveCity/scripts.pory"
	lock
# 234 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 235 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 236 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 237 "data//maps/LilycoveCity/scripts.pory"
	release
# 238 "data//maps/LilycoveCity/scripts.pory"
	end
# 239 "data//maps/LilycoveCity/scripts.pory"

# 240 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 241 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 242 "data//maps/LilycoveCity/scripts.pory"
	release
# 243 "data//maps/LilycoveCity/scripts.pory"
	end
# 244 "data//maps/LilycoveCity/scripts.pory"

# 245 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 246 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 247 "data//maps/LilycoveCity/scripts.pory"
	end
# 248 "data//maps/LilycoveCity/scripts.pory"

# 249 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 250 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 251 "data//maps/LilycoveCity/scripts.pory"
	end
# 252 "data//maps/LilycoveCity/scripts.pory"

# 253 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 254 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 255 "data//maps/LilycoveCity/scripts.pory"
	end
# 256 "data//maps/LilycoveCity/scripts.pory"

# 257 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 258 "data//maps/LilycoveCity/scripts.pory"
	lock
# 259 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 260 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 261 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 262 "data//maps/LilycoveCity/scripts.pory"
	release
# 263 "data//maps/LilycoveCity/scripts.pory"
	end
# 264 "data//maps/LilycoveCity/scripts.pory"

# 265 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 266 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 267 "data//maps/LilycoveCity/scripts.pory"
	release
# 268 "data//maps/LilycoveCity/scripts.pory"
	end
# 269 "data//maps/LilycoveCity/scripts.pory"

# 270 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 271 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 272 "data//maps/LilycoveCity/scripts.pory"
	end
# 273 "data//maps/LilycoveCity/scripts.pory"

# 274 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 275 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 276 "data//maps/LilycoveCity/scripts.pory"
	end
# 277 "data//maps/LilycoveCity/scripts.pory"

# 278 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 279 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 280 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 281 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 282 "data//maps/LilycoveCity/scripts.pory"
	end
# 283 "data//maps/LilycoveCity/scripts.pory"

# 284 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 285 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 286 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 287 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 288 "data//maps/LilycoveCity/scripts.pory"
	end
# 289 "data//maps/LilycoveCity/scripts.pory"

# 290 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 291 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 292 "data//maps/LilycoveCity/scripts.pory"
	end
# 293 "data//maps/LilycoveCity/scripts.pory"

# 294 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 295 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 296 "data//maps/LilycoveCity/scripts.pory"
	end
# 297 "data//maps/LilycoveCity/scripts.pory"

# 298 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 299 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 300 "data//maps/LilycoveCity/scripts.pory"
	end
# 301 "data//maps/LilycoveCity/scripts.pory"

# 302 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 303 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 304 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 305 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 306 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 307 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 308 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 309 "data//maps/LilycoveCity/scripts.pory"
	end
# 310 "data//maps/LilycoveCity/scripts.pory"

# 311 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 312 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 313 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 314 "data//maps/LilycoveCity/scripts.pory"
	end
# 315 "data//maps/LilycoveCity/scripts.pory"

# 316 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 317 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 318 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 319 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 320 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 321 "data//maps/LilycoveCity/scripts.pory"
	end
# 322 "data//maps/LilycoveCity/scripts.pory"

# 323 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 324 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 325 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 326 "data//maps/LilycoveCity/scripts.pory"
	end
# 327 "data//maps/LilycoveCity/scripts.pory"

# 328 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 329 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 330 "data//maps/LilycoveCity/scripts.pory"
	end
# 331 "data//maps/LilycoveCity/scripts.pory"

# 332 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 333 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 334 "data//maps/LilycoveCity/scripts.pory"
	end
# 335 "data//maps/LilycoveCity/scripts.pory"

# 336 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 337 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 338 "data//maps/LilycoveCity/scripts.pory"
	end
# 339 "data//maps/LilycoveCity/scripts.pory"

# 340 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 341 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 342 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 343 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 344 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 345 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 346 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 347 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 348 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 349 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 350 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 351 "data//maps/LilycoveCity/scripts.pory"
	end
# 352 "data//maps/LilycoveCity/scripts.pory"

# 353 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 354 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 355 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 356 "data//maps/LilycoveCity/scripts.pory"
	end
# 357 "data//maps/LilycoveCity/scripts.pory"

# 358 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 359 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 360 "data//maps/LilycoveCity/scripts.pory"
	end
# 361 "data//maps/LilycoveCity/scripts.pory"

# 362 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 363 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 364 "data//maps/LilycoveCity/scripts.pory"
	end
# 365 "data//maps/LilycoveCity/scripts.pory"

# 366 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 367 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 368 "data//maps/LilycoveCity/scripts.pory"
	end
# 369 "data//maps/LilycoveCity/scripts.pory"

# 370 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 371 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 372 "data//maps/LilycoveCity/scripts.pory"
	end
# 373 "data//maps/LilycoveCity/scripts.pory"

# 374 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 375 "data//maps/LilycoveCity/scripts.pory"
	lock
# 376 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 377 "data//maps/LilycoveCity/scripts.pory"
	checkplayergender
# 378 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 379 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 380 "data//maps/LilycoveCity/scripts.pory"
	end
# 381 "data//maps/LilycoveCity/scripts.pory"

# 382 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 383 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 384 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 385 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 386 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 387 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 388 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 389 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleMay
# 390 "data//maps/LilycoveCity/scripts.pory"
	end
# 391 "data//maps/LilycoveCity/scripts.pory"

# 392 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 393 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 394 "data//maps/LilycoveCity/scripts.pory"
	return
# 395 "data//maps/LilycoveCity/scripts.pory"

# 396 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 397 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 398 "data//maps/LilycoveCity/scripts.pory"
	return
# 399 "data//maps/LilycoveCity/scripts.pory"

# 400 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 401 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 402 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 403 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 404 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 405 "data//maps/LilycoveCity/scripts.pory"
	release
# 406 "data//maps/LilycoveCity/scripts.pory"
	end
# 407 "data//maps/LilycoveCity/scripts.pory"

# 408 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 409 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 410 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 411 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 412 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 413 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 414 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 415 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleBrendan
# 416 "data//maps/LilycoveCity/scripts.pory"
	end
# 417 "data//maps/LilycoveCity/scripts.pory"

# 418 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 419 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 420 "data//maps/LilycoveCity/scripts.pory"
	return
# 421 "data//maps/LilycoveCity/scripts.pory"

# 422 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 423 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 424 "data//maps/LilycoveCity/scripts.pory"
	return
# 425 "data//maps/LilycoveCity/scripts.pory"

# 426 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 427 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 428 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 429 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 430 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 431 "data//maps/LilycoveCity/scripts.pory"
	release
# 432 "data//maps/LilycoveCity/scripts.pory"
	end
# 433 "data//maps/LilycoveCity/scripts.pory"

# 434 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMay::
# 435 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_A, LilycoveCity_Text_MayDefeat
# 436 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 437 "data//maps/LilycoveCity/scripts.pory"
	end
# 438 "data//maps/LilycoveCity/scripts.pory"

# 439 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendan::
# 440 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_A, LilycoveCity_Text_BrendanDefeat
# 441 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 442 "data//maps/LilycoveCity/scripts.pory"
	end
# 443 "data//maps/LilycoveCity/scripts.pory"

# 444 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 445 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 446 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 447 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 448 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 449 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 450 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 451 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 452 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 453 "data//maps/LilycoveCity/scripts.pory"
	end
# 454 "data//maps/LilycoveCity/scripts.pory"

# 455 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 456 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 457 "data//maps/LilycoveCity/scripts.pory"
	return
# 458 "data//maps/LilycoveCity/scripts.pory"

# 459 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 460 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 461 "data//maps/LilycoveCity/scripts.pory"
	return
# 462 "data//maps/LilycoveCity/scripts.pory"

# 463 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 464 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 465 "data//maps/LilycoveCity/scripts.pory"
	return
# 466 "data//maps/LilycoveCity/scripts.pory"

# 467 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 468 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 469 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 470 "data//maps/LilycoveCity/scripts.pory"
	return
# 471 "data//maps/LilycoveCity/scripts.pory"

# 472 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 473 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 474 "data//maps/LilycoveCity/scripts.pory"
	return
# 475 "data//maps/LilycoveCity/scripts.pory"

# 476 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 477 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 478 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 479 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 480 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 481 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 482 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 483 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 484 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 485 "data//maps/LilycoveCity/scripts.pory"
	end
# 486 "data//maps/LilycoveCity/scripts.pory"

# 487 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 488 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 489 "data//maps/LilycoveCity/scripts.pory"
	return
# 490 "data//maps/LilycoveCity/scripts.pory"

# 491 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 492 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 493 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 494 "data//maps/LilycoveCity/scripts.pory"
	return
# 495 "data//maps/LilycoveCity/scripts.pory"

# 496 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 497 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 498 "data//maps/LilycoveCity/scripts.pory"
	return
# 499 "data//maps/LilycoveCity/scripts.pory"

# 500 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 501 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 502 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 503 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 504 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 505 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 506 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 507 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 508 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 509 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 510 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 511 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 512 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 513 "data//maps/LilycoveCity/scripts.pory"
	release
# 514 "data//maps/LilycoveCity/scripts.pory"
	end
# 515 "data//maps/LilycoveCity/scripts.pory"

# 516 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 517 "data//maps/LilycoveCity/scripts.pory"
	lock
# 518 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 519 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 520 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 521 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 522 "data//maps/LilycoveCity/scripts.pory"
	release
# 523 "data//maps/LilycoveCity/scripts.pory"
	end
# 524 "data//maps/LilycoveCity/scripts.pory"

# 525 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 526 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 527 "data//maps/LilycoveCity/scripts.pory"
	return
# 528 "data//maps/LilycoveCity/scripts.pory"

# 529 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 530 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 531 "data//maps/LilycoveCity/scripts.pory"
	return
# 532 "data//maps/LilycoveCity/scripts.pory"

# 533 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 534 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 535 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 540 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 541 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 542 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 543 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 544 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 545 "data//maps/LilycoveCity/scripts.pory"

# 546 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 547 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 548 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 549 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 550 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 551 "data//maps/LilycoveCity/scripts.pory"

# 552 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 553 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 554 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 555 "data//maps/LilycoveCity/scripts.pory"

# 556 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 557 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 559 "data//maps/LilycoveCity/scripts.pory"

# 560 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 561 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 562 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 563 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 564 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 565 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 566 "data//maps/LilycoveCity/scripts.pory"

# 567 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 568 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 570 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 571 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 572 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 573 "data//maps/LilycoveCity/scripts.pory"

# 574 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 575 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 577 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 578 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 579 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 580 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 581 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 582 "data//maps/LilycoveCity/scripts.pory"

# 583 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 585 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 586 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 587 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 588 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 589 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 590 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 591 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 592 "data//maps/LilycoveCity/scripts.pory"

# 593 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 594 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 595 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 596 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 597 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 598 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 599 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 600 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 601 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 602 "data//maps/LilycoveCity/scripts.pory"

# 603 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 604 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 605 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 606 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 607 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 608 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 609 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 610 "data//maps/LilycoveCity/scripts.pory"

# 611 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 612 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 613 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 614 "data//maps/LilycoveCity/scripts.pory"

# 615 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 616 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 617 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 618 "data//maps/LilycoveCity/scripts.pory"

# 619 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 620 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 622 "data//maps/LilycoveCity/scripts.pory"

# 623 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 624 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 625 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 626 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 628 "data//maps/LilycoveCity/scripts.pory"

# 629 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 630 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 631 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 632 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 633 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 634 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 635 "data//maps/LilycoveCity/scripts.pory"

# 636 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 637 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 638 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 639 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 640 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 641 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 642 "data//maps/LilycoveCity/scripts.pory"

# 643 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 644 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 645 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 646 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 647 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 648 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 649 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 650 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 651 "data//maps/LilycoveCity/scripts.pory"

# 652 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 653 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 654 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 655 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 656 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 659 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 660 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 661 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 662 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 663 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 664 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 665 "data//maps/LilycoveCity/scripts.pory"

# 666 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 667 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 668 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 669 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 670 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 671 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 672 "data//maps/LilycoveCity/scripts.pory"

# 673 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 674 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 676 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 677 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 678 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 680 "data//maps/LilycoveCity/scripts.pory"

# 681 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 682 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 683 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 684 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 685 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 686 "data//maps/LilycoveCity/scripts.pory"

# 687 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 688 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 689 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 690 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 691 "data//maps/LilycoveCity/scripts.pory"

# 692 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 693 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 694 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 695 "data//maps/LilycoveCity/scripts.pory"

# 696 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 697 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 698 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 699 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 700 "data//maps/LilycoveCity/scripts.pory"

# 701 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 702 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 703 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 704 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 705 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 706 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 707 "data//maps/LilycoveCity/scripts.pory"

# 708 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 709 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 710 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 711 "data//maps/LilycoveCity/scripts.pory"

# 712 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 713 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 714 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 715 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 716 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 717 "data//maps/LilycoveCity/scripts.pory"

# 718 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 719 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 720 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 721 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 722 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 723 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 724 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 725 "data//maps/LilycoveCity/scripts.pory"

# 726 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 727 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 728 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 729 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 731 "data//maps/LilycoveCity/scripts.pory"

# 732 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 733 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 734 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 735 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 736 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 737 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 738 "data//maps/LilycoveCity/scripts.pory"

# 739 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 740 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 741 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 742 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 743 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 744 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 745 "data//maps/LilycoveCity/scripts.pory"

# 746 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 747 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 748 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 749 "data//maps/LilycoveCity/scripts.pory"

# 750 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 751 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 752 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 753 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 754 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 755 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 756 "data//maps/LilycoveCity/scripts.pory"

# 757 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 758 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 759 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 760 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 761 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 762 "data//maps/LilycoveCity/scripts.pory"

# 763 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 764 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 765 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 766 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 767 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 768 "data//maps/LilycoveCity/scripts.pory"

# 769 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 770 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 771 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 772 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 773 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 774 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 775 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 776 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 777 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 778 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 779 "data//maps/LilycoveCity/scripts.pory"

# 780 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 781 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 782 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 783 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 784 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 785 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 786 "data//maps/LilycoveCity/scripts.pory"

# 787 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 788 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 789 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 790 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 791 "data//maps/LilycoveCity/scripts.pory"

# 792 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 793 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 794 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 795 "data//maps/LilycoveCity/scripts.pory"

# 796 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 797 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 798 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 799 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 800 "data//maps/LilycoveCity/scripts.pory"

# 801 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 802 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 803 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 804 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 805 "data//maps/LilycoveCity/scripts.pory"

# 806 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 807 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 808 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 809 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 810 "data//maps/LilycoveCity/scripts.pory"

# 811 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 812 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 813 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 814 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 815 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 816 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 817 "data//maps/LilycoveCity/scripts.pory"

# 818 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 819 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 820 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 821 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 822 "data//maps/LilycoveCity/scripts.pory"

# 823 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 824 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 825 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 826 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 827 "data//maps/LilycoveCity/scripts.pory"

# 828 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 829 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 830 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 831 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 832 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 833 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 834 "data//maps/LilycoveCity/scripts.pory"

# 835 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 836 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 837 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 838 "data//maps/LilycoveCity/scripts.pory"

# 839 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 840 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 841 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 842 "data//maps/LilycoveCity/scripts.pory"

# 843 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 844 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 845 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 846 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 847 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 848 "data//maps/LilycoveCity/scripts.pory"

# 849 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 850 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 851 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 852 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 853 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 854 "data//maps/LilycoveCity/scripts.pory"

# 855 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 856 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 857 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 858 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 859 "data//maps/LilycoveCity/scripts.pory"

# 860 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 861 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 862 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 863 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 864 "data//maps/LilycoveCity/scripts.pory"

# 865 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 866 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 867 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 868 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 869 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 870 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 871 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 872 "data//maps/LilycoveCity/scripts.pory"

# 873 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 874 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 875 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 876 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 877 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 878 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"

LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0:
# 53 "data//maps/LilycoveCity/scripts.pory"
	.string "ZAZAZAAAAAAM!!$"

LilycoveCity_EventScript_ReturningFromShadyTruck_Text_1:
# 78 "data//maps/LilycoveCity/scripts.pory"
	.string "The truck drove off…$"

LilycoveCity_EventScript_ShadyAlakazam_Text_0:
# 97 "data//maps/LilycoveCity/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

LilycoveCity_EventScript_ShadyAlakazam_Text_1:
# 102 "data//maps/LilycoveCity/scripts.pory"
	.string "ALAKAZAM is beckoning you towards the\n"
	.string "truck doors.$"

LilycoveCity_EventScript_ShadyAlakazam_Text_2:
# 105 "data//maps/LilycoveCity/scripts.pory"
	.string "This shady-looking ALAKAZAM is asking\n"
	.string "if you want to enter the truck.\p"
	.string "Do you trust ALAKAZAM enough to get\n"
	.string "into the sketchy truck?$"
