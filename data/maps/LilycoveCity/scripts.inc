# 1 "data//maps/LilycoveCity/scripts.pory"

# 2 "data//maps/LilycoveCity/scripts.pory"
.set LOCALID_WOMAN_1, 19
# 3 "data//maps/LilycoveCity/scripts.pory"
.set LOCALID_MAN_1, 20
# 4 "data//maps/LilycoveCity/scripts.pory"

# 5 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 6 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 7 "data//maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 8 "data//maps/LilycoveCity/scripts.pory"
	.byte 0
# 9 "data//maps/LilycoveCity/scripts.pory"

# 10 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 11 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_SYS_SAVE_GET
# 12 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 13 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 14 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 15 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 16 "data//maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data//maps/LilycoveCity/scripts.pory"
	end
# 18 "data//maps/LilycoveCity/scripts.pory"

# 19 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 20 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 21 "data//maps/LilycoveCity/scripts.pory"
	end
# 22 "data//maps/LilycoveCity/scripts.pory"

# 23 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 24 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 25 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 26 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 27 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 28 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 29 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 30 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 31 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 32 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 33 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 34 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 35 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 36 "data//maps/LilycoveCity/scripts.pory"
	return
# 37 "data//maps/LilycoveCity/scripts.pory"

# 38 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 39 "data//maps/LilycoveCity/scripts.pory"
	lock
# 40 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 41 "data//maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 42 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 43 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 44 "data//maps/LilycoveCity/scripts.pory"
	random 10
# 45 "data//maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 46 "data//maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 47 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 48 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 49 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 50 "data//maps/LilycoveCity/scripts.pory"
	release
# 51 "data//maps/LilycoveCity/scripts.pory"
	end
# 52 "data//maps/LilycoveCity/scripts.pory"

# 53 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 54 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 55 "data//maps/LilycoveCity/scripts.pory"
	release
# 56 "data//maps/LilycoveCity/scripts.pory"
	end
# 57 "data//maps/LilycoveCity/scripts.pory"

# 58 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 59 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 60 "data//maps/LilycoveCity/scripts.pory"
	end
# 61 "data//maps/LilycoveCity/scripts.pory"

# 62 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 63 "data//maps/LilycoveCity/scripts.pory"
	lock
# 64 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 65 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 66 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 67 "data//maps/LilycoveCity/scripts.pory"
	release
# 68 "data//maps/LilycoveCity/scripts.pory"
	end
# 69 "data//maps/LilycoveCity/scripts.pory"

# 70 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 71 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 72 "data//maps/LilycoveCity/scripts.pory"
	release
# 73 "data//maps/LilycoveCity/scripts.pory"
	end
# 74 "data//maps/LilycoveCity/scripts.pory"

# 75 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 76 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 77 "data//maps/LilycoveCity/scripts.pory"
	end
# 78 "data//maps/LilycoveCity/scripts.pory"

# 79 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 80 "data//maps/LilycoveCity/scripts.pory"
	lock
# 81 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 82 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 83 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 84 "data//maps/LilycoveCity/scripts.pory"
	release
# 85 "data//maps/LilycoveCity/scripts.pory"
	end
# 86 "data//maps/LilycoveCity/scripts.pory"

# 87 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 88 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 89 "data//maps/LilycoveCity/scripts.pory"
	release
# 90 "data//maps/LilycoveCity/scripts.pory"
	end
# 91 "data//maps/LilycoveCity/scripts.pory"

# 92 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 93 "data//maps/LilycoveCity/scripts.pory"
	lock
# 94 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 95 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 96 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 97 "data//maps/LilycoveCity/scripts.pory"
	release
# 98 "data//maps/LilycoveCity/scripts.pory"
	end
# 99 "data//maps/LilycoveCity/scripts.pory"

# 100 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 101 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 102 "data//maps/LilycoveCity/scripts.pory"
	release
# 103 "data//maps/LilycoveCity/scripts.pory"
	end
# 104 "data//maps/LilycoveCity/scripts.pory"

# 105 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 106 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 107 "data//maps/LilycoveCity/scripts.pory"
	end
# 108 "data//maps/LilycoveCity/scripts.pory"

# 109 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 110 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 111 "data//maps/LilycoveCity/scripts.pory"
	end
# 112 "data//maps/LilycoveCity/scripts.pory"

# 113 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 114 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 115 "data//maps/LilycoveCity/scripts.pory"
	end
# 116 "data//maps/LilycoveCity/scripts.pory"

# 117 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 118 "data//maps/LilycoveCity/scripts.pory"
	lock
# 119 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 120 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 121 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 122 "data//maps/LilycoveCity/scripts.pory"
	release
# 123 "data//maps/LilycoveCity/scripts.pory"
	end
# 124 "data//maps/LilycoveCity/scripts.pory"

# 125 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 126 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 127 "data//maps/LilycoveCity/scripts.pory"
	release
# 128 "data//maps/LilycoveCity/scripts.pory"
	end
# 129 "data//maps/LilycoveCity/scripts.pory"

# 130 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 131 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 132 "data//maps/LilycoveCity/scripts.pory"
	end
# 133 "data//maps/LilycoveCity/scripts.pory"

# 134 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 135 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 136 "data//maps/LilycoveCity/scripts.pory"
	end
# 137 "data//maps/LilycoveCity/scripts.pory"

# 138 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 139 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 140 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 141 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
# 142 "data//maps/LilycoveCity/scripts.pory"
	end
# 143 "data//maps/LilycoveCity/scripts.pory"

# 144 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 145 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 146 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 147 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 148 "data//maps/LilycoveCity/scripts.pory"
	end
# 149 "data//maps/LilycoveCity/scripts.pory"

# 150 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 151 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 152 "data//maps/LilycoveCity/scripts.pory"
	end
# 153 "data//maps/LilycoveCity/scripts.pory"

# 154 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 155 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 156 "data//maps/LilycoveCity/scripts.pory"
	end
# 157 "data//maps/LilycoveCity/scripts.pory"

# 158 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 159 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 160 "data//maps/LilycoveCity/scripts.pory"
	end
# 161 "data//maps/LilycoveCity/scripts.pory"

# 162 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 163 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 164 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 165 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 166 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 167 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 168 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 169 "data//maps/LilycoveCity/scripts.pory"
	end
# 170 "data//maps/LilycoveCity/scripts.pory"

# 171 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 172 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 173 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 174 "data//maps/LilycoveCity/scripts.pory"
	end
# 175 "data//maps/LilycoveCity/scripts.pory"

# 176 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 177 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 178 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 179 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 180 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 181 "data//maps/LilycoveCity/scripts.pory"
	end
# 182 "data//maps/LilycoveCity/scripts.pory"

# 183 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 184 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 185 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 186 "data//maps/LilycoveCity/scripts.pory"
	end
# 187 "data//maps/LilycoveCity/scripts.pory"

# 188 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 189 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 190 "data//maps/LilycoveCity/scripts.pory"
	end
# 191 "data//maps/LilycoveCity/scripts.pory"

# 192 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 193 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 194 "data//maps/LilycoveCity/scripts.pory"
	end
# 195 "data//maps/LilycoveCity/scripts.pory"

# 196 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 197 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 198 "data//maps/LilycoveCity/scripts.pory"
	end
# 199 "data//maps/LilycoveCity/scripts.pory"

# 200 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 201 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 202 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 203 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 204 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 205 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 206 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 207 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 208 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 209 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 210 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 211 "data//maps/LilycoveCity/scripts.pory"
	end
# 212 "data//maps/LilycoveCity/scripts.pory"

# 213 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 214 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 215 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 216 "data//maps/LilycoveCity/scripts.pory"
	end
# 217 "data//maps/LilycoveCity/scripts.pory"

# 218 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 219 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 220 "data//maps/LilycoveCity/scripts.pory"
	end
# 221 "data//maps/LilycoveCity/scripts.pory"

# 222 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 223 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 224 "data//maps/LilycoveCity/scripts.pory"
	end
# 225 "data//maps/LilycoveCity/scripts.pory"

# 226 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 227 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 228 "data//maps/LilycoveCity/scripts.pory"
	end
# 229 "data//maps/LilycoveCity/scripts.pory"

# 230 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 231 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 232 "data//maps/LilycoveCity/scripts.pory"
	end
# 233 "data//maps/LilycoveCity/scripts.pory"

# 234 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 235 "data//maps/LilycoveCity/scripts.pory"
	lock
# 236 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 237 "data//maps/LilycoveCity/scripts.pory"
	checkplayergender
# 238 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 239 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 240 "data//maps/LilycoveCity/scripts.pory"
	end
# 241 "data//maps/LilycoveCity/scripts.pory"

# 242 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 243 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 244 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 245 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 246 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 247 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 248 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 249 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleMay
# 250 "data//maps/LilycoveCity/scripts.pory"
	end
# 251 "data//maps/LilycoveCity/scripts.pory"

# 252 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 253 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 254 "data//maps/LilycoveCity/scripts.pory"
	return
# 255 "data//maps/LilycoveCity/scripts.pory"

# 256 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 257 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 258 "data//maps/LilycoveCity/scripts.pory"
	return
# 259 "data//maps/LilycoveCity/scripts.pory"

# 260 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 261 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 262 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 263 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 264 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 265 "data//maps/LilycoveCity/scripts.pory"
	release
# 266 "data//maps/LilycoveCity/scripts.pory"
	end
# 267 "data//maps/LilycoveCity/scripts.pory"

# 268 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 269 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 270 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 271 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 272 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 273 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 274 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 275 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_BattleBrendan
# 276 "data//maps/LilycoveCity/scripts.pory"
	end
# 277 "data//maps/LilycoveCity/scripts.pory"

# 278 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 279 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 280 "data//maps/LilycoveCity/scripts.pory"
	return
# 281 "data//maps/LilycoveCity/scripts.pory"

# 282 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 283 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 284 "data//maps/LilycoveCity/scripts.pory"
	return
# 285 "data//maps/LilycoveCity/scripts.pory"

# 286 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 287 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 288 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 289 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 290 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 291 "data//maps/LilycoveCity/scripts.pory"
	release
# 292 "data//maps/LilycoveCity/scripts.pory"
	end
# 293 "data//maps/LilycoveCity/scripts.pory"

# 294 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMay::
# 295 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_A, LilycoveCity_Text_MayDefeat
# 296 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 297 "data//maps/LilycoveCity/scripts.pory"
	end
# 298 "data//maps/LilycoveCity/scripts.pory"

# 299 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendan::
# 300 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_A, LilycoveCity_Text_BrendanDefeat
# 301 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 302 "data//maps/LilycoveCity/scripts.pory"
	end
# 303 "data//maps/LilycoveCity/scripts.pory"

# 304 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 305 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 306 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 307 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 308 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 309 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 310 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 311 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 312 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 313 "data//maps/LilycoveCity/scripts.pory"
	end
# 314 "data//maps/LilycoveCity/scripts.pory"

# 315 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 316 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 317 "data//maps/LilycoveCity/scripts.pory"
	return
# 318 "data//maps/LilycoveCity/scripts.pory"

# 319 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 320 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 321 "data//maps/LilycoveCity/scripts.pory"
	return
# 322 "data//maps/LilycoveCity/scripts.pory"

# 323 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 324 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 325 "data//maps/LilycoveCity/scripts.pory"
	return
# 326 "data//maps/LilycoveCity/scripts.pory"

# 327 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 328 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 329 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 330 "data//maps/LilycoveCity/scripts.pory"
	return
# 331 "data//maps/LilycoveCity/scripts.pory"

# 332 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 333 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 334 "data//maps/LilycoveCity/scripts.pory"
	return
# 335 "data//maps/LilycoveCity/scripts.pory"

# 336 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 337 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 338 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 339 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 340 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 341 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 342 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 343 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 344 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 345 "data//maps/LilycoveCity/scripts.pory"
	end
# 346 "data//maps/LilycoveCity/scripts.pory"

# 347 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 348 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 349 "data//maps/LilycoveCity/scripts.pory"
	return
# 350 "data//maps/LilycoveCity/scripts.pory"

# 351 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 352 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 353 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 354 "data//maps/LilycoveCity/scripts.pory"
	return
# 355 "data//maps/LilycoveCity/scripts.pory"

# 356 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 357 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 358 "data//maps/LilycoveCity/scripts.pory"
	return
# 359 "data//maps/LilycoveCity/scripts.pory"

# 360 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 361 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 362 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 363 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 364 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 365 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 366 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 367 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 368 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 369 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 370 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 371 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 372 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 373 "data//maps/LilycoveCity/scripts.pory"
	release
# 374 "data//maps/LilycoveCity/scripts.pory"
	end
# 375 "data//maps/LilycoveCity/scripts.pory"

# 376 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 377 "data//maps/LilycoveCity/scripts.pory"
	lock
# 378 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 379 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 380 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 381 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 382 "data//maps/LilycoveCity/scripts.pory"
	release
# 383 "data//maps/LilycoveCity/scripts.pory"
	end
# 384 "data//maps/LilycoveCity/scripts.pory"

# 385 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 386 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 387 "data//maps/LilycoveCity/scripts.pory"
	return
# 388 "data//maps/LilycoveCity/scripts.pory"

# 389 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 390 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 391 "data//maps/LilycoveCity/scripts.pory"
	return
# 392 "data//maps/LilycoveCity/scripts.pory"

# 393 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 394 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 395 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 396 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 397 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 398 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 399 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 400 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 401 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 402 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 403 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 404 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 405 "data//maps/LilycoveCity/scripts.pory"

# 406 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 407 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 408 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 409 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 410 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 411 "data//maps/LilycoveCity/scripts.pory"

# 412 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 413 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 414 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 415 "data//maps/LilycoveCity/scripts.pory"

# 416 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 417 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 418 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 419 "data//maps/LilycoveCity/scripts.pory"

# 420 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 421 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 422 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 423 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 424 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 425 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 426 "data//maps/LilycoveCity/scripts.pory"

# 427 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 428 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 429 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 430 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 431 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 432 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 433 "data//maps/LilycoveCity/scripts.pory"

# 434 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 435 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 436 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 437 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 438 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 439 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 440 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 441 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 442 "data//maps/LilycoveCity/scripts.pory"

# 443 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 444 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 445 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 446 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 447 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 448 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 449 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 450 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 451 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 452 "data//maps/LilycoveCity/scripts.pory"

# 453 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 454 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 455 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 456 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 457 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 458 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 459 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 460 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 461 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 462 "data//maps/LilycoveCity/scripts.pory"

# 463 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 464 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 465 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 466 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 467 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 468 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 469 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 470 "data//maps/LilycoveCity/scripts.pory"

# 471 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 472 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 473 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 474 "data//maps/LilycoveCity/scripts.pory"

# 475 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 476 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 477 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 478 "data//maps/LilycoveCity/scripts.pory"

# 479 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 480 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 481 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 482 "data//maps/LilycoveCity/scripts.pory"

# 483 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 484 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 485 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 486 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 487 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 488 "data//maps/LilycoveCity/scripts.pory"

# 489 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 490 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 491 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 492 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 493 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 494 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 495 "data//maps/LilycoveCity/scripts.pory"

# 496 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 497 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 498 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 499 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 500 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 501 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 502 "data//maps/LilycoveCity/scripts.pory"

# 503 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 504 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 505 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 506 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 507 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 508 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 509 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 510 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 511 "data//maps/LilycoveCity/scripts.pory"

# 512 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 513 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 514 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 515 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 516 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 517 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 518 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 519 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 520 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 521 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 522 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 523 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 524 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 525 "data//maps/LilycoveCity/scripts.pory"

# 526 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 527 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 528 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 529 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 530 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 531 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 532 "data//maps/LilycoveCity/scripts.pory"

# 533 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 534 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 535 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 540 "data//maps/LilycoveCity/scripts.pory"

# 541 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 542 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 543 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 544 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 545 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 546 "data//maps/LilycoveCity/scripts.pory"

# 547 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 548 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 549 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 550 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 551 "data//maps/LilycoveCity/scripts.pory"

# 552 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 553 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 554 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 555 "data//maps/LilycoveCity/scripts.pory"

# 556 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 557 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 559 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 560 "data//maps/LilycoveCity/scripts.pory"

# 561 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 562 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 563 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 564 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 565 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 566 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 567 "data//maps/LilycoveCity/scripts.pory"

# 568 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 570 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 571 "data//maps/LilycoveCity/scripts.pory"

# 572 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 573 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 574 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 575 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 577 "data//maps/LilycoveCity/scripts.pory"

# 578 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 579 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 580 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 581 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 582 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 583 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 585 "data//maps/LilycoveCity/scripts.pory"

# 586 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 587 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 588 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 589 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 590 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 591 "data//maps/LilycoveCity/scripts.pory"

# 592 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 593 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 594 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 595 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 596 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 597 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 598 "data//maps/LilycoveCity/scripts.pory"

# 599 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 600 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 601 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 602 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 603 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 604 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 605 "data//maps/LilycoveCity/scripts.pory"

# 606 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 607 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 608 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 609 "data//maps/LilycoveCity/scripts.pory"

# 610 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 611 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 612 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 613 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 614 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 615 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 616 "data//maps/LilycoveCity/scripts.pory"

# 617 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 618 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 619 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 620 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 622 "data//maps/LilycoveCity/scripts.pory"

# 623 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 624 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 625 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 626 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 628 "data//maps/LilycoveCity/scripts.pory"

# 629 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 630 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 631 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 632 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 633 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 634 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 635 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 636 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 637 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 638 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 639 "data//maps/LilycoveCity/scripts.pory"

# 640 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 641 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 642 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 643 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 644 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 645 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 646 "data//maps/LilycoveCity/scripts.pory"

# 647 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 648 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 649 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 650 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 651 "data//maps/LilycoveCity/scripts.pory"

# 652 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 653 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 654 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 655 "data//maps/LilycoveCity/scripts.pory"

# 656 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 659 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 660 "data//maps/LilycoveCity/scripts.pory"

# 661 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 662 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 663 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 664 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 665 "data//maps/LilycoveCity/scripts.pory"

# 666 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 667 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 668 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 669 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 670 "data//maps/LilycoveCity/scripts.pory"

# 671 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 672 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 673 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 674 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 676 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 677 "data//maps/LilycoveCity/scripts.pory"

# 678 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 680 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 681 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 682 "data//maps/LilycoveCity/scripts.pory"

# 683 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 684 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 685 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 686 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 687 "data//maps/LilycoveCity/scripts.pory"

# 688 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 689 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 690 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 691 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 692 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 693 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 694 "data//maps/LilycoveCity/scripts.pory"

# 695 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 696 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 697 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 698 "data//maps/LilycoveCity/scripts.pory"

# 699 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 700 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 701 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 702 "data//maps/LilycoveCity/scripts.pory"

# 703 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 704 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 705 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 706 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 707 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 708 "data//maps/LilycoveCity/scripts.pory"

# 709 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 710 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 711 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 712 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 713 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 714 "data//maps/LilycoveCity/scripts.pory"

# 715 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 716 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 717 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 718 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 719 "data//maps/LilycoveCity/scripts.pory"

# 720 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 721 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 722 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 723 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 724 "data//maps/LilycoveCity/scripts.pory"

# 725 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 726 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 727 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 728 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 729 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 731 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 732 "data//maps/LilycoveCity/scripts.pory"

# 733 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 734 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 735 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 736 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 737 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 738 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
