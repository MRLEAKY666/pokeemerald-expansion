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
	setflag FLAG_VISITED_LILYCOVE_CITY
# 17 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 18 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 19 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 20 "data//maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	end


LilycoveCity_OnResume::
# 25 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, LilycoveCity_OnResume_1
# 29 "data//maps/LilycoveCity/scripts.pory"
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
# 30 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_TEMP_E, 40
	goto_if_eq LilycoveCity_OnResume_5
	return

LilycoveCity_OnResume_1:
# 26 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_TEMP_1F
	return

LilycoveCity_OnResume_4:
# 31 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_TEMP_1E
# 32 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_TEMP_1F
# 33 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
	return

LilycoveCity_OnResume_5:
# 30 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_TEMP_F, 30
	goto_if_eq LilycoveCity_OnResume_4
	return


LilycoveCity_EventScript_ReturningFromShadyTruck::
# 39 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEMP_1F, LilycoveCity_EventScript_ReturningFromShadyTruck_2
LilycoveCity_EventScript_ReturningFromShadyTruck_1:
# 82 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_TEMP_F, 0
# 83 "data//maps/LilycoveCity/scripts.pory"
	release
	return

LilycoveCity_EventScript_ReturningFromShadyTruck_2:
# 40 "data//maps/LilycoveCity/scripts.pory"
	setobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY, 0
# 41 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 42 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_JumpOutOfTruck
# 43 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 44 "data//maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_KEEP_SHADY_TRUCK, LilycoveCity_EventScript_ReturningFromShadyTruck_5
LilycoveCity_EventScript_ReturningFromShadyTruck_4:
# 80 "data//maps/LilycoveCity/scripts.pory"
	resetobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY
	goto LilycoveCity_EventScript_ReturningFromShadyTruck_1

LilycoveCity_EventScript_ReturningFromShadyTruck_5:
# 45 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_MoveAwayFromTruck
# 46 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 47 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceFasterDown
# 48 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 49 "data//maps/LilycoveCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
# 50 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0
# 51 "data//maps/LilycoveCity/scripts.pory"
	waitmoncry
# 52 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 53 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 54 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, RustboroCity_Movement_AlakazamEnterTruck
# 55 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 56 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 57 "data//maps/LilycoveCity/scripts.pory"
	waitmovement LOCALID_LILYCOVE_SHADY_ALAKAZAM
# 58 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 59 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 60 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 61 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 62 "data//maps/LilycoveCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 63 "data//maps/LilycoveCity/scripts.pory"
	delay 60
# 64 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_MOVE
# 65 "data//maps/LilycoveCity/scripts.pory"
	delay 120
# 66 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_STOP
# 67 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 68 "data//maps/LilycoveCity/scripts.pory"
	delay 45
# 69 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_SHADY_TRUCK
# 70 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_SHADY_ALAKAZAM
# 71 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_TRUCK_COLLISION_A
# 72 "data//maps/LilycoveCity/scripts.pory"
	removeobject LOCALID_LILYCOVE_TRUCK_COLLISION_B
# 73 "data//maps/LilycoveCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 74 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 75 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_1
# 76 "data//maps/LilycoveCity/scripts.pory"
	waitmessage
# 77 "data//maps/LilycoveCity/scripts.pory"
	delay 90
# 78 "data//maps/LilycoveCity/scripts.pory"
	closemessage
	goto LilycoveCity_EventScript_ReturningFromShadyTruck_4


LilycoveCity_EventScript_ShadyAlakazam::
# 87 "data//maps/LilycoveCity/scripts.pory"
	lock
# 88 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 89 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 90 "data//maps/LilycoveCity/scripts.pory"
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_HIGH_PITCH
# 91 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0
# 92 "data//maps/LilycoveCity/scripts.pory"
	waitmoncry
# 93 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 94 "data//maps/LilycoveCity/scripts.pory"
	message LilycoveCity_EventScript_ShadyAlakazam_Text_0
# 95 "data//maps/LilycoveCity/scripts.pory"
	waitmessage
# 96 "data//maps/LilycoveCity/scripts.pory"
	delay 40
# 97 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 98 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq LilycoveCity_EventScript_ShadyAlakazam_2
# 102 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_EventScript_ShadyAlakazam_Text_2, MSGBOX_YESNO
# 104 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 105 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_EventScript_ShadyAlakazam_5
LilycoveCity_EventScript_ShadyAlakazam_1:
# 109 "data//maps/LilycoveCity/scripts.pory"
	release
	return

LilycoveCity_EventScript_ShadyAlakazam_2:
# 99 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_EventScript_ShadyAlakazam_Text_1, MSGBOX_DEFAULT
	goto LilycoveCity_EventScript_ShadyAlakazam_1

LilycoveCity_EventScript_ShadyAlakazam_5:
# 106 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_EnterShadyTruck
	goto LilycoveCity_EventScript_ShadyAlakazam_1


LilycoveCity_EventScript_TruckEntrance::
# 113 "data//maps/LilycoveCity/scripts.pory"
	goto_if_unset FLAG_TEMP_1E, LilycoveCity_EventScript_TruckEntrance_1
	return

LilycoveCity_EventScript_TruckEntrance_1:
# 114 "data//maps/LilycoveCity/scripts.pory"
	lock
# 115 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_FacePlayer
# 116 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 117 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 118 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 119 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne LilycoveCity_EventScript_TruckEntrance_4
LilycoveCity_EventScript_TruckEntrance_3:
# 123 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_ShadyAlakazam
	return

LilycoveCity_EventScript_TruckEntrance_4:
# 120 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 121 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
	goto LilycoveCity_EventScript_TruckEntrance_3


LilycoveCity_EventScript_EnterShadyTruck::
# 128 "data//maps/LilycoveCity/scripts.pory"
	delay 30
# 129 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_SHADY_ALAKAZAM, Common_Movement_WalkInPlaceDown
# 130 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 131 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 132 "data//maps/LilycoveCity/scripts.pory"
	playse SE_TRUCK_DOOR
# 133 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 134 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 135 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 136 "data//maps/LilycoveCity/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_ne LilycoveCity_EventScript_EnterShadyTruck_2
LilycoveCity_EventScript_EnterShadyTruck_1:
# 140 "data//maps/LilycoveCity/scripts.pory"
	setobjectsubpriority LOCALID_LILYCOVE_SHADY_TRUCK, MAP_LILYCOVE_CITY, 0
# 141 "data//maps/LilycoveCity/scripts.pory"
	hidefollower
# 142 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerEnterTruck
# 143 "data//maps/LilycoveCity/scripts.pory"
	delay 32
# 144 "data//maps/LilycoveCity/scripts.pory"
	playse SE_BIKE_HOP
# 145 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
# 146 "data//maps/LilycoveCity/scripts.pory"
	playse SE_EXIT
# 147 "data//maps/LilycoveCity/scripts.pory"
	waitse
# 148 "data//maps/LilycoveCity/scripts.pory"
	delay 20
# 149 "data//maps/LilycoveCity/scripts.pory"
	warpcontinuescript MAP_SHADY_GUYS_TRUCK, 5, 2, ShadyGuysTruck_EventScript_PlayerEntersTruck
	return

LilycoveCity_EventScript_EnterShadyTruck_2:
# 137 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 138 "data//maps/LilycoveCity/scripts.pory"
	waitmovement
	goto LilycoveCity_EventScript_EnterShadyTruck_1


# 152 "data//maps/LilycoveCity/scripts.pory"

# 153 "data//maps/LilycoveCity/scripts.pory"

# 154 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnFrame:
# 155 "data//maps/LilycoveCity/scripts.pory"
	map_script_2 VAR_TEMP_F, 30, LilycoveCity_EventScript_ReturningFromShadyTruck
# 156 "data//maps/LilycoveCity/scripts.pory"
	.2byte 0
# 157 "data//maps/LilycoveCity/scripts.pory"

# 158 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 159 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 160 "data//maps/LilycoveCity/scripts.pory"
	end
# 161 "data//maps/LilycoveCity/scripts.pory"

# 162 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 163 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 164 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 165 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 166 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 167 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 168 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 169 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 170 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 171 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 172 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 173 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 174 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 175 "data//maps/LilycoveCity/scripts.pory"
	return
# 176 "data//maps/LilycoveCity/scripts.pory"

# 177 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 178 "data//maps/LilycoveCity/scripts.pory"
	lock
# 179 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 180 "data//maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 181 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 182 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 183 "data//maps/LilycoveCity/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
# 184 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 185 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 186 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 187 "data//maps/LilycoveCity/scripts.pory"
	release
# 188 "data//maps/LilycoveCity/scripts.pory"
	end
# 189 "data//maps/LilycoveCity/scripts.pory"

# 190 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 191 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 192 "data//maps/LilycoveCity/scripts.pory"
	release
# 193 "data//maps/LilycoveCity/scripts.pory"
	end
# 194 "data//maps/LilycoveCity/scripts.pory"

# 195 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 196 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 197 "data//maps/LilycoveCity/scripts.pory"
	end
# 198 "data//maps/LilycoveCity/scripts.pory"

# 199 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 200 "data//maps/LilycoveCity/scripts.pory"
	lock
# 201 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 202 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 203 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 204 "data//maps/LilycoveCity/scripts.pory"
	release
# 205 "data//maps/LilycoveCity/scripts.pory"
	end
# 206 "data//maps/LilycoveCity/scripts.pory"

# 207 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 208 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 209 "data//maps/LilycoveCity/scripts.pory"
	release
# 210 "data//maps/LilycoveCity/scripts.pory"
	end
# 211 "data//maps/LilycoveCity/scripts.pory"

# 212 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 213 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 214 "data//maps/LilycoveCity/scripts.pory"
	end
# 215 "data//maps/LilycoveCity/scripts.pory"

# 216 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 217 "data//maps/LilycoveCity/scripts.pory"
	lock
# 218 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 219 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 220 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 221 "data//maps/LilycoveCity/scripts.pory"
	release
# 222 "data//maps/LilycoveCity/scripts.pory"
	end
# 223 "data//maps/LilycoveCity/scripts.pory"

# 224 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 225 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 226 "data//maps/LilycoveCity/scripts.pory"
	release
# 227 "data//maps/LilycoveCity/scripts.pory"
	end
# 228 "data//maps/LilycoveCity/scripts.pory"

# 229 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 230 "data//maps/LilycoveCity/scripts.pory"
	lock
# 231 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 232 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 233 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 234 "data//maps/LilycoveCity/scripts.pory"
	release
# 235 "data//maps/LilycoveCity/scripts.pory"
	end
# 236 "data//maps/LilycoveCity/scripts.pory"

# 237 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 238 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 239 "data//maps/LilycoveCity/scripts.pory"
	release
# 240 "data//maps/LilycoveCity/scripts.pory"
	end
# 241 "data//maps/LilycoveCity/scripts.pory"

# 242 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 243 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 244 "data//maps/LilycoveCity/scripts.pory"
	end
# 245 "data//maps/LilycoveCity/scripts.pory"

# 246 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 247 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 248 "data//maps/LilycoveCity/scripts.pory"
	end
# 249 "data//maps/LilycoveCity/scripts.pory"

# 250 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 251 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 252 "data//maps/LilycoveCity/scripts.pory"
	end
# 253 "data//maps/LilycoveCity/scripts.pory"

# 254 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 255 "data//maps/LilycoveCity/scripts.pory"
	lock
# 256 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 257 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 258 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 259 "data//maps/LilycoveCity/scripts.pory"
	release
# 260 "data//maps/LilycoveCity/scripts.pory"
	end
# 261 "data//maps/LilycoveCity/scripts.pory"

# 262 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 263 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 264 "data//maps/LilycoveCity/scripts.pory"
	release
# 265 "data//maps/LilycoveCity/scripts.pory"
	end
# 266 "data//maps/LilycoveCity/scripts.pory"

# 267 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 268 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 269 "data//maps/LilycoveCity/scripts.pory"
	end
# 270 "data//maps/LilycoveCity/scripts.pory"

# 271 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 272 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 273 "data//maps/LilycoveCity/scripts.pory"
	end
# 274 "data//maps/LilycoveCity/scripts.pory"

# 275 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 276 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 277 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 278 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 279 "data//maps/LilycoveCity/scripts.pory"
	end
# 280 "data//maps/LilycoveCity/scripts.pory"

# 281 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 282 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 283 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 284 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 285 "data//maps/LilycoveCity/scripts.pory"
	end
# 286 "data//maps/LilycoveCity/scripts.pory"

# 287 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 288 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 289 "data//maps/LilycoveCity/scripts.pory"
	end
# 290 "data//maps/LilycoveCity/scripts.pory"

# 291 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 292 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 293 "data//maps/LilycoveCity/scripts.pory"
	end
# 294 "data//maps/LilycoveCity/scripts.pory"

# 295 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 296 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 297 "data//maps/LilycoveCity/scripts.pory"
	end
# 298 "data//maps/LilycoveCity/scripts.pory"

# 299 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 300 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 301 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 302 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 303 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 304 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 305 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 306 "data//maps/LilycoveCity/scripts.pory"
	end
# 307 "data//maps/LilycoveCity/scripts.pory"

# 308 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 309 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 310 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 311 "data//maps/LilycoveCity/scripts.pory"
	end
# 312 "data//maps/LilycoveCity/scripts.pory"

# 313 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 314 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 315 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 316 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 317 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 318 "data//maps/LilycoveCity/scripts.pory"
	end
# 319 "data//maps/LilycoveCity/scripts.pory"

# 320 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 321 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 322 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 323 "data//maps/LilycoveCity/scripts.pory"
	end
# 324 "data//maps/LilycoveCity/scripts.pory"

# 325 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 326 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 327 "data//maps/LilycoveCity/scripts.pory"
	end
# 328 "data//maps/LilycoveCity/scripts.pory"

# 329 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 330 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 331 "data//maps/LilycoveCity/scripts.pory"
	end
# 332 "data//maps/LilycoveCity/scripts.pory"

# 333 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 334 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 335 "data//maps/LilycoveCity/scripts.pory"
	end
# 336 "data//maps/LilycoveCity/scripts.pory"

# 337 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 338 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 339 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 340 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 341 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 342 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 343 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 344 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 345 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 346 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 347 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 348 "data//maps/LilycoveCity/scripts.pory"
	end
# 349 "data//maps/LilycoveCity/scripts.pory"

# 350 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 351 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 352 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 353 "data//maps/LilycoveCity/scripts.pory"
	end
# 354 "data//maps/LilycoveCity/scripts.pory"

# 355 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 356 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 357 "data//maps/LilycoveCity/scripts.pory"
	end
# 358 "data//maps/LilycoveCity/scripts.pory"

# 359 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 360 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 361 "data//maps/LilycoveCity/scripts.pory"
	end
# 362 "data//maps/LilycoveCity/scripts.pory"

# 363 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 364 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 365 "data//maps/LilycoveCity/scripts.pory"
	end
# 366 "data//maps/LilycoveCity/scripts.pory"

# 367 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 368 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 369 "data//maps/LilycoveCity/scripts.pory"
	end
# 370 "data//maps/LilycoveCity/scripts.pory"

# 371 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 372 "data//maps/LilycoveCity/scripts.pory"
	lock
# 373 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 374 "data//maps/LilycoveCity/scripts.pory"
	checkplayergender
# 375 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 376 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 377 "data//maps/LilycoveCity/scripts.pory"
	end
# 378 "data//maps/LilycoveCity/scripts.pory"

# 379 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 380 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 381 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 382 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 383 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 384 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 385 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 386 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleMay
# 387 "data//maps/LilycoveCity/scripts.pory"
	end
# 388 "data//maps/LilycoveCity/scripts.pory"

# 389 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 390 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 391 "data//maps/LilycoveCity/scripts.pory"
	return
# 392 "data//maps/LilycoveCity/scripts.pory"

# 393 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 394 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 395 "data//maps/LilycoveCity/scripts.pory"
	return
# 396 "data//maps/LilycoveCity/scripts.pory"

# 397 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 398 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 399 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 400 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 401 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 402 "data//maps/LilycoveCity/scripts.pory"
	release
# 403 "data//maps/LilycoveCity/scripts.pory"
	end
# 404 "data//maps/LilycoveCity/scripts.pory"

# 405 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 406 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 407 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 408 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 409 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 410 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 411 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 412 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleBrendan
# 413 "data//maps/LilycoveCity/scripts.pory"
	end
# 414 "data//maps/LilycoveCity/scripts.pory"

# 415 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 416 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 417 "data//maps/LilycoveCity/scripts.pory"
	return
# 418 "data//maps/LilycoveCity/scripts.pory"

# 419 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 420 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 421 "data//maps/LilycoveCity/scripts.pory"
	return
# 422 "data//maps/LilycoveCity/scripts.pory"

# 423 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 424 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 425 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 426 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 427 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 428 "data//maps/LilycoveCity/scripts.pory"
	release
# 429 "data//maps/LilycoveCity/scripts.pory"
	end
# 430 "data//maps/LilycoveCity/scripts.pory"

# 431 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMay::
# 432 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_A, LilycoveCity_Text_MayDefeat
# 433 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 434 "data//maps/LilycoveCity/scripts.pory"
	end
# 435 "data//maps/LilycoveCity/scripts.pory"

# 436 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendan::
# 437 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_A, LilycoveCity_Text_BrendanDefeat
# 438 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 439 "data//maps/LilycoveCity/scripts.pory"
	end
# 440 "data//maps/LilycoveCity/scripts.pory"

# 441 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 442 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 443 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 444 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 445 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 446 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 447 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 448 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 449 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 450 "data//maps/LilycoveCity/scripts.pory"
	end
# 451 "data//maps/LilycoveCity/scripts.pory"

# 452 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 453 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 454 "data//maps/LilycoveCity/scripts.pory"
	return
# 455 "data//maps/LilycoveCity/scripts.pory"

# 456 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 457 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 458 "data//maps/LilycoveCity/scripts.pory"
	return
# 459 "data//maps/LilycoveCity/scripts.pory"

# 460 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 461 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 462 "data//maps/LilycoveCity/scripts.pory"
	return
# 463 "data//maps/LilycoveCity/scripts.pory"

# 464 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 465 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 466 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 467 "data//maps/LilycoveCity/scripts.pory"
	return
# 468 "data//maps/LilycoveCity/scripts.pory"

# 469 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 470 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 471 "data//maps/LilycoveCity/scripts.pory"
	return
# 472 "data//maps/LilycoveCity/scripts.pory"

# 473 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 474 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 475 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 476 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 477 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 478 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 479 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 480 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 481 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 482 "data//maps/LilycoveCity/scripts.pory"
	end
# 483 "data//maps/LilycoveCity/scripts.pory"

# 484 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 485 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 486 "data//maps/LilycoveCity/scripts.pory"
	return
# 487 "data//maps/LilycoveCity/scripts.pory"

# 488 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 489 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 490 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 491 "data//maps/LilycoveCity/scripts.pory"
	return
# 492 "data//maps/LilycoveCity/scripts.pory"

# 493 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 494 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 495 "data//maps/LilycoveCity/scripts.pory"
	return
# 496 "data//maps/LilycoveCity/scripts.pory"

# 497 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 498 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 499 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 500 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 501 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 502 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 503 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 504 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 505 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 506 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 507 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 508 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 509 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 510 "data//maps/LilycoveCity/scripts.pory"
	release
# 511 "data//maps/LilycoveCity/scripts.pory"
	end
# 512 "data//maps/LilycoveCity/scripts.pory"

# 513 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 514 "data//maps/LilycoveCity/scripts.pory"
	lock
# 515 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 516 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 517 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 518 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 519 "data//maps/LilycoveCity/scripts.pory"
	release
# 520 "data//maps/LilycoveCity/scripts.pory"
	end
# 521 "data//maps/LilycoveCity/scripts.pory"

# 522 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 523 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 524 "data//maps/LilycoveCity/scripts.pory"
	return
# 525 "data//maps/LilycoveCity/scripts.pory"

# 526 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 527 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 528 "data//maps/LilycoveCity/scripts.pory"
	return
# 529 "data//maps/LilycoveCity/scripts.pory"

# 530 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 531 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 532 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 533 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 534 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 535 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 540 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 541 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 542 "data//maps/LilycoveCity/scripts.pory"

# 543 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 544 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 545 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 546 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 547 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 548 "data//maps/LilycoveCity/scripts.pory"

# 549 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 550 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 551 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 552 "data//maps/LilycoveCity/scripts.pory"

# 553 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 554 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 555 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 556 "data//maps/LilycoveCity/scripts.pory"

# 557 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 559 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 560 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 561 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 562 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 563 "data//maps/LilycoveCity/scripts.pory"

# 564 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 565 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 566 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 567 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 568 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 570 "data//maps/LilycoveCity/scripts.pory"

# 571 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 572 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 573 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 574 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 575 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 577 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 578 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 579 "data//maps/LilycoveCity/scripts.pory"

# 580 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 581 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 582 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 583 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 585 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 586 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 587 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 588 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 589 "data//maps/LilycoveCity/scripts.pory"

# 590 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 591 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 592 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 593 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 594 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 595 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 596 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 597 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 598 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 599 "data//maps/LilycoveCity/scripts.pory"

# 600 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 601 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 602 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 603 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 604 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 605 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 606 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 607 "data//maps/LilycoveCity/scripts.pory"

# 608 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 609 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 610 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 611 "data//maps/LilycoveCity/scripts.pory"

# 612 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 613 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 614 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 615 "data//maps/LilycoveCity/scripts.pory"

# 616 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 617 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 618 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 619 "data//maps/LilycoveCity/scripts.pory"

# 620 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 622 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 623 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 624 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 625 "data//maps/LilycoveCity/scripts.pory"

# 626 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 628 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 629 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 630 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 631 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 632 "data//maps/LilycoveCity/scripts.pory"

# 633 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 634 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 635 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 636 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 637 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 638 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 639 "data//maps/LilycoveCity/scripts.pory"

# 640 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 641 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 642 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 643 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 644 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 645 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 646 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 647 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 648 "data//maps/LilycoveCity/scripts.pory"

# 649 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 650 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 651 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 652 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 653 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 654 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 655 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 656 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 659 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 660 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 661 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 662 "data//maps/LilycoveCity/scripts.pory"

# 663 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 664 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 665 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 666 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 667 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 668 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 669 "data//maps/LilycoveCity/scripts.pory"

# 670 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 671 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 672 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 673 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 674 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 676 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 677 "data//maps/LilycoveCity/scripts.pory"

# 678 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 680 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 681 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 682 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 683 "data//maps/LilycoveCity/scripts.pory"

# 684 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 685 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 686 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 687 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 688 "data//maps/LilycoveCity/scripts.pory"

# 689 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 690 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 691 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 692 "data//maps/LilycoveCity/scripts.pory"

# 693 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 694 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 695 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 696 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 697 "data//maps/LilycoveCity/scripts.pory"

# 698 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 699 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 700 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 701 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 702 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 703 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 704 "data//maps/LilycoveCity/scripts.pory"

# 705 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 706 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 707 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 708 "data//maps/LilycoveCity/scripts.pory"

# 709 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 710 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 711 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 712 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 713 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 714 "data//maps/LilycoveCity/scripts.pory"

# 715 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 716 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 717 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 718 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 719 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 720 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 721 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 722 "data//maps/LilycoveCity/scripts.pory"

# 723 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 724 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 725 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 726 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 727 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 728 "data//maps/LilycoveCity/scripts.pory"

# 729 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 731 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 732 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 733 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 734 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 735 "data//maps/LilycoveCity/scripts.pory"

# 736 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 737 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 738 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 739 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 740 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 741 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 742 "data//maps/LilycoveCity/scripts.pory"

# 743 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 744 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 745 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 746 "data//maps/LilycoveCity/scripts.pory"

# 747 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 748 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 749 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 750 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 751 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 752 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 753 "data//maps/LilycoveCity/scripts.pory"

# 754 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 755 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 756 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 757 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 758 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 759 "data//maps/LilycoveCity/scripts.pory"

# 760 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 761 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 762 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 763 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 764 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 765 "data//maps/LilycoveCity/scripts.pory"

# 766 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 767 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 768 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 769 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 770 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 771 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 772 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 773 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 774 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 775 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 776 "data//maps/LilycoveCity/scripts.pory"

# 777 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 778 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 779 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 780 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 781 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 782 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 783 "data//maps/LilycoveCity/scripts.pory"

# 784 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 785 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 786 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 787 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 788 "data//maps/LilycoveCity/scripts.pory"

# 789 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 790 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 791 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 792 "data//maps/LilycoveCity/scripts.pory"

# 793 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 794 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 795 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 796 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 797 "data//maps/LilycoveCity/scripts.pory"

# 798 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 799 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 800 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 801 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 802 "data//maps/LilycoveCity/scripts.pory"

# 803 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 804 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 805 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 806 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 807 "data//maps/LilycoveCity/scripts.pory"

# 808 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 809 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 810 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 811 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 812 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 813 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 814 "data//maps/LilycoveCity/scripts.pory"

# 815 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 816 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 817 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 818 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 819 "data//maps/LilycoveCity/scripts.pory"

# 820 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 821 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 822 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 823 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 824 "data//maps/LilycoveCity/scripts.pory"

# 825 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 826 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 827 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 828 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 829 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 830 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 831 "data//maps/LilycoveCity/scripts.pory"

# 832 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 833 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 834 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 835 "data//maps/LilycoveCity/scripts.pory"

# 836 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 837 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 838 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 839 "data//maps/LilycoveCity/scripts.pory"

# 840 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 841 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 842 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 843 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 844 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 845 "data//maps/LilycoveCity/scripts.pory"

# 846 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 847 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 848 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 849 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 850 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 851 "data//maps/LilycoveCity/scripts.pory"

# 852 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 853 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 854 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 855 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 856 "data//maps/LilycoveCity/scripts.pory"

# 857 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 858 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 859 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 860 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 861 "data//maps/LilycoveCity/scripts.pory"

# 862 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 863 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 864 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 865 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 866 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 867 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 868 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 869 "data//maps/LilycoveCity/scripts.pory"

# 870 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 871 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 872 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 873 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 874 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 875 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"

LilycoveCity_EventScript_ReturningFromShadyTruck_Text_0:
# 50 "data//maps/LilycoveCity/scripts.pory"
	.string "ZAZAZAAAAAAM!!$"

LilycoveCity_EventScript_ReturningFromShadyTruck_Text_1:
# 75 "data//maps/LilycoveCity/scripts.pory"
	.string "The truck drove off…$"

LilycoveCity_EventScript_ShadyAlakazam_Text_0:
# 94 "data//maps/LilycoveCity/scripts.pory"
	.string "… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}… {PAUSE 5}…$"

LilycoveCity_EventScript_ShadyAlakazam_Text_1:
# 99 "data//maps/LilycoveCity/scripts.pory"
	.string "ALAKAZAM is beckoning you towards the\n"
	.string "truck doors.$"

LilycoveCity_EventScript_ShadyAlakazam_Text_2:
# 102 "data//maps/LilycoveCity/scripts.pory"
	.string "This shady-looking ALAKAZAM is asking\n"
	.string "if you want to enter the truck.\p"
	.string "Do you trust ALAKAZAM enough to get\n"
	.string "into the sketchy truck?$"
