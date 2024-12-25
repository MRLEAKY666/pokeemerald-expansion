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
	case SPECIES_TREECKO, LilycoveCity_EventScript_BattleMayA
# 250 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TORCHIC, LilycoveCity_EventScript_BattleMayB
# 251 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MUDKIP, LilycoveCity_EventScript_BattleMayC
# 252 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CASTFORM, LilycoveCity_EventScript_BattleMayA
# 253 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PIPLUP, LilycoveCity_EventScript_BattleMayC
# 254 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_EEVEE, LilycoveCity_EventScript_BattleMayA
# 255 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PICHU, LilycoveCity_EventScript_BattleMayB
# 256 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TOGEPI, LilycoveCity_EventScript_BattleMayC
# 257 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PORYGON, LilycoveCity_EventScript_BattleMayA
# 258 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SNIVY, LilycoveCity_EventScript_BattleMayA
# 259 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA_HISUI, LilycoveCity_EventScript_BattleMayA
# 260 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA, LilycoveCity_EventScript_BattleMayA
# 261 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOTHITA, LilycoveCity_EventScript_BattleMayB
# 262 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SOLOSIS, LilycoveCity_EventScript_BattleMayB
# 263 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_AXEW, LilycoveCity_EventScript_BattleMayC
# 264 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVESTA, LilycoveCity_EventScript_BattleMayB
# 265 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOOMY, LilycoveCity_EventScript_BattleMayC
# 266 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ROWLET, LilycoveCity_EventScript_BattleMayA
# 267 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_APPLIN, LilycoveCity_EventScript_BattleMayA
# 268 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MIME_JR, LilycoveCity_EventScript_BattleMayB
# 269 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MAGBY, LilycoveCity_EventScript_BattleMayB
# 270 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ELEKID, LilycoveCity_EventScript_BattleMayB
# 271 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MANKEY, LilycoveCity_EventScript_BattleMayA
# 272 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SWINUB, LilycoveCity_EventScript_BattleMayC
# 273 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVITAR, LilycoveCity_EventScript_BattleMayA
# 274 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TURTWIG, LilycoveCity_EventScript_BattleMayA
# 275 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CHARMANDER, LilycoveCity_EventScript_BattleMayB
# 276 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SQUIRTLE, LilycoveCity_EventScript_BattleMayC
# 277 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_BULBASAUR, LilycoveCity_EventScript_BattleMayA
# 278 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_OSHAWOTT, LilycoveCity_EventScript_BattleMayC
# 279 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CYNDAQUIL, LilycoveCity_EventScript_BattleMayB
# 280 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_BUDEW, LilycoveCity_EventScript_BattleMayA
# 281 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SPHEAL, LilycoveCity_EventScript_BattleMayA
# 282 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SHINX, LilycoveCity_EventScript_BattleMayB
# 283 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SANDILE, LilycoveCity_EventScript_BattleMayC
# 284 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PAWNIARD, LilycoveCity_EventScript_BattleMayA
# 285 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_JANGMO_O, LilycoveCity_EventScript_BattleMayA
# 286 "data//maps/LilycoveCity/scripts.pory"
	end
# 287 "data//maps/LilycoveCity/scripts.pory"

# 288 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 289 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 290 "data//maps/LilycoveCity/scripts.pory"
	return
# 291 "data//maps/LilycoveCity/scripts.pory"

# 292 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 293 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 294 "data//maps/LilycoveCity/scripts.pory"
	return
# 295 "data//maps/LilycoveCity/scripts.pory"

# 296 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 297 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 298 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 299 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 300 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 301 "data//maps/LilycoveCity/scripts.pory"
	release
# 302 "data//maps/LilycoveCity/scripts.pory"
	end
# 303 "data//maps/LilycoveCity/scripts.pory"

# 304 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 305 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 306 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 307 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 308 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 309 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 310 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 311 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TREECKO, LilycoveCity_EventScript_BattleBrendanA
# 312 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TORCHIC, LilycoveCity_EventScript_BattleBrendanB
# 313 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MUDKIP, LilycoveCity_EventScript_BattleBrendanC
# 314 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CASTFORM, LilycoveCity_EventScript_BattleBrendanA
# 315 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PIPLUP, LilycoveCity_EventScript_BattleBrendanC
# 316 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_EEVEE, LilycoveCity_EventScript_BattleBrendanA
# 317 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PICHU, LilycoveCity_EventScript_BattleBrendanB
# 318 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TOGEPI, LilycoveCity_EventScript_BattleBrendanC
# 319 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PORYGON, LilycoveCity_EventScript_BattleBrendanA
# 320 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SNIVY, LilycoveCity_EventScript_BattleBrendanA
# 321 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA_HISUI, LilycoveCity_EventScript_BattleBrendanA
# 322 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA, LilycoveCity_EventScript_BattleBrendanA
# 323 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOTHITA, LilycoveCity_EventScript_BattleBrendanB
# 324 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SOLOSIS, LilycoveCity_EventScript_BattleBrendanB
# 325 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_AXEW, LilycoveCity_EventScript_BattleBrendanC
# 326 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVESTA, LilycoveCity_EventScript_BattleBrendanB
# 327 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOOMY, LilycoveCity_EventScript_BattleBrendanC
# 328 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ROWLET, LilycoveCity_EventScript_BattleBrendanA
# 329 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_APPLIN, LilycoveCity_EventScript_BattleBrendanA
# 330 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MIME_JR, LilycoveCity_EventScript_BattleBrendanB
# 331 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MAGBY, LilycoveCity_EventScript_BattleBrendanB
# 332 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ELEKID, LilycoveCity_EventScript_BattleBrendanB
# 333 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MANKEY, LilycoveCity_EventScript_BattleBrendanA
# 334 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SWINUB, LilycoveCity_EventScript_BattleBrendanC
# 335 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVITAR, LilycoveCity_EventScript_BattleBrendanA
# 336 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TURTWIG, LilycoveCity_EventScript_BattleBrendanA
# 337 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CHARMANDER, LilycoveCity_EventScript_BattleBrendanB
# 338 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SQUIRTLE, LilycoveCity_EventScript_BattleBrendanC
# 339 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_BULBASAUR, LilycoveCity_EventScript_BattleBrendanA
# 340 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_OSHAWOTT, LilycoveCity_EventScript_BattleBrendanC
# 341 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CYNDAQUIL, LilycoveCity_EventScript_BattleBrendanB
# 342 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_BUDEW, LilycoveCity_EventScript_BattleBrendanA
# 343 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SPHEAL, LilycoveCity_EventScript_BattleBrendanA
# 344 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SHINX, LilycoveCity_EventScript_BattleBrendanB
# 345 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SANDILE, LilycoveCity_EventScript_BattleBrendanC
# 346 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PAWNIARD, LilycoveCity_EventScript_BattleBrendanA
# 347 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_JANGMO_O, LilycoveCity_EventScript_BattleBrendanA
# 348 "data//maps/LilycoveCity/scripts.pory"
	end
# 349 "data//maps/LilycoveCity/scripts.pory"

# 350 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 351 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 352 "data//maps/LilycoveCity/scripts.pory"
	return
# 353 "data//maps/LilycoveCity/scripts.pory"

# 354 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 355 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 356 "data//maps/LilycoveCity/scripts.pory"
	return
# 357 "data//maps/LilycoveCity/scripts.pory"

# 358 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 359 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 360 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 361 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 362 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 363 "data//maps/LilycoveCity/scripts.pory"
	release
# 364 "data//maps/LilycoveCity/scripts.pory"
	end
# 365 "data//maps/LilycoveCity/scripts.pory"

# 366 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayA::
# 367 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_A, LilycoveCity_Text_MayDefeat
# 368 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 369 "data//maps/LilycoveCity/scripts.pory"
	end
# 370 "data//maps/LilycoveCity/scripts.pory"

# 371 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayB::
# 372 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_B, LilycoveCity_Text_MayDefeat
# 373 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 374 "data//maps/LilycoveCity/scripts.pory"
	end
# 375 "data//maps/LilycoveCity/scripts.pory"

# 376 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayC::
# 377 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_C, LilycoveCity_Text_MayDefeat
# 378 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 379 "data//maps/LilycoveCity/scripts.pory"
	end
# 380 "data//maps/LilycoveCity/scripts.pory"

# 381 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanA::
# 382 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_A, LilycoveCity_Text_BrendanDefeat
# 383 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 384 "data//maps/LilycoveCity/scripts.pory"
	end
# 385 "data//maps/LilycoveCity/scripts.pory"

# 386 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanB::
# 387 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_B, LilycoveCity_Text_BrendanDefeat
# 388 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 389 "data//maps/LilycoveCity/scripts.pory"
	end
# 390 "data//maps/LilycoveCity/scripts.pory"

# 391 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanC::
# 392 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_C, LilycoveCity_Text_BrendanDefeat
# 393 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 394 "data//maps/LilycoveCity/scripts.pory"
	end
# 395 "data//maps/LilycoveCity/scripts.pory"

# 396 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 397 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 398 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 399 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 400 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 401 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 402 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 403 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 404 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 405 "data//maps/LilycoveCity/scripts.pory"
	end
# 406 "data//maps/LilycoveCity/scripts.pory"

# 407 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 408 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 409 "data//maps/LilycoveCity/scripts.pory"
	return
# 410 "data//maps/LilycoveCity/scripts.pory"

# 411 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 412 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 413 "data//maps/LilycoveCity/scripts.pory"
	return
# 414 "data//maps/LilycoveCity/scripts.pory"

# 415 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 416 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 417 "data//maps/LilycoveCity/scripts.pory"
	return
# 418 "data//maps/LilycoveCity/scripts.pory"

# 419 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 420 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 421 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 422 "data//maps/LilycoveCity/scripts.pory"
	return
# 423 "data//maps/LilycoveCity/scripts.pory"

# 424 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 425 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 426 "data//maps/LilycoveCity/scripts.pory"
	return
# 427 "data//maps/LilycoveCity/scripts.pory"

# 428 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 429 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 430 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 431 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 432 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 433 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 434 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 435 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 436 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 437 "data//maps/LilycoveCity/scripts.pory"
	end
# 438 "data//maps/LilycoveCity/scripts.pory"

# 439 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 440 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 441 "data//maps/LilycoveCity/scripts.pory"
	return
# 442 "data//maps/LilycoveCity/scripts.pory"

# 443 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 444 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 445 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 446 "data//maps/LilycoveCity/scripts.pory"
	return
# 447 "data//maps/LilycoveCity/scripts.pory"

# 448 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 449 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 450 "data//maps/LilycoveCity/scripts.pory"
	return
# 451 "data//maps/LilycoveCity/scripts.pory"

# 452 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 453 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 454 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 455 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 456 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 457 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 458 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 459 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 460 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 461 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 462 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 463 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 464 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 465 "data//maps/LilycoveCity/scripts.pory"
	release
# 466 "data//maps/LilycoveCity/scripts.pory"
	end
# 467 "data//maps/LilycoveCity/scripts.pory"

# 468 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 469 "data//maps/LilycoveCity/scripts.pory"
	lock
# 470 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 471 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 472 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 473 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 474 "data//maps/LilycoveCity/scripts.pory"
	release
# 475 "data//maps/LilycoveCity/scripts.pory"
	end
# 476 "data//maps/LilycoveCity/scripts.pory"

# 477 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 478 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 479 "data//maps/LilycoveCity/scripts.pory"
	return
# 480 "data//maps/LilycoveCity/scripts.pory"

# 481 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 482 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 483 "data//maps/LilycoveCity/scripts.pory"
	return
# 484 "data//maps/LilycoveCity/scripts.pory"

# 485 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 486 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 487 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 488 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 489 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 490 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 491 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 492 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 493 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 494 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 495 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 496 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 497 "data//maps/LilycoveCity/scripts.pory"

# 498 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 499 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 500 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 501 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 502 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 503 "data//maps/LilycoveCity/scripts.pory"

# 504 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 505 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 506 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 507 "data//maps/LilycoveCity/scripts.pory"

# 508 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 509 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 510 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 511 "data//maps/LilycoveCity/scripts.pory"

# 512 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 513 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 514 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 515 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 516 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 517 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 518 "data//maps/LilycoveCity/scripts.pory"

# 519 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 520 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 521 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 522 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 523 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 524 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 525 "data//maps/LilycoveCity/scripts.pory"

# 526 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 527 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 528 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 529 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 530 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 531 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 532 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 533 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 534 "data//maps/LilycoveCity/scripts.pory"

# 535 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 540 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 541 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 542 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 543 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 544 "data//maps/LilycoveCity/scripts.pory"

# 545 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 546 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 547 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 548 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 549 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 550 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 551 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 552 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 553 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 554 "data//maps/LilycoveCity/scripts.pory"

# 555 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 556 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 557 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 559 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 560 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 561 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 562 "data//maps/LilycoveCity/scripts.pory"

# 563 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 564 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 565 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 566 "data//maps/LilycoveCity/scripts.pory"

# 567 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 568 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 570 "data//maps/LilycoveCity/scripts.pory"

# 571 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 572 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 573 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 574 "data//maps/LilycoveCity/scripts.pory"

# 575 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 577 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 578 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 579 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 580 "data//maps/LilycoveCity/scripts.pory"

# 581 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 582 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 583 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 585 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 586 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 587 "data//maps/LilycoveCity/scripts.pory"

# 588 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 589 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 590 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 591 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 592 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 593 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 594 "data//maps/LilycoveCity/scripts.pory"

# 595 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 596 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 597 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 598 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 599 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 600 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 601 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 602 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 603 "data//maps/LilycoveCity/scripts.pory"

# 604 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 605 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 606 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 607 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 608 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 609 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 610 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 611 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 612 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 613 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 614 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 615 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 616 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 617 "data//maps/LilycoveCity/scripts.pory"

# 618 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 619 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 620 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 622 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 623 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 624 "data//maps/LilycoveCity/scripts.pory"

# 625 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 626 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 628 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 629 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 630 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 631 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 632 "data//maps/LilycoveCity/scripts.pory"

# 633 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 634 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 635 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 636 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 637 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 638 "data//maps/LilycoveCity/scripts.pory"

# 639 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 640 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 641 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 642 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 643 "data//maps/LilycoveCity/scripts.pory"

# 644 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 645 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 646 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 647 "data//maps/LilycoveCity/scripts.pory"

# 648 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 649 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 650 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 651 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 652 "data//maps/LilycoveCity/scripts.pory"

# 653 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 654 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 655 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 656 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 659 "data//maps/LilycoveCity/scripts.pory"

# 660 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 661 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 662 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 663 "data//maps/LilycoveCity/scripts.pory"

# 664 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 665 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 666 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 667 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 668 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 669 "data//maps/LilycoveCity/scripts.pory"

# 670 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 671 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 672 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 673 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 674 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 676 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 677 "data//maps/LilycoveCity/scripts.pory"

# 678 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 680 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 681 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 682 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 683 "data//maps/LilycoveCity/scripts.pory"

# 684 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 685 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 686 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 687 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 688 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 689 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 690 "data//maps/LilycoveCity/scripts.pory"

# 691 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 692 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 693 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 694 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 695 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 696 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 697 "data//maps/LilycoveCity/scripts.pory"

# 698 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 699 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 700 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 701 "data//maps/LilycoveCity/scripts.pory"

# 702 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 703 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 704 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 705 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 706 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 707 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 708 "data//maps/LilycoveCity/scripts.pory"

# 709 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 710 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 711 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 712 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 713 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 714 "data//maps/LilycoveCity/scripts.pory"

# 715 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 716 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 717 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 718 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 719 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 720 "data//maps/LilycoveCity/scripts.pory"

# 721 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 722 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 723 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 724 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 725 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 726 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 727 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 728 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 729 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 731 "data//maps/LilycoveCity/scripts.pory"

# 732 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 733 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 734 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 735 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 736 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 737 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 738 "data//maps/LilycoveCity/scripts.pory"

# 739 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 740 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 741 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 742 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 743 "data//maps/LilycoveCity/scripts.pory"

# 744 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 745 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 746 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 747 "data//maps/LilycoveCity/scripts.pory"

# 748 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 749 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 750 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 751 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 752 "data//maps/LilycoveCity/scripts.pory"

# 753 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 754 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 755 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 756 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 757 "data//maps/LilycoveCity/scripts.pory"

# 758 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 759 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 760 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 761 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 762 "data//maps/LilycoveCity/scripts.pory"

# 763 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 764 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 765 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 766 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 767 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 768 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 769 "data//maps/LilycoveCity/scripts.pory"

# 770 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 771 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 772 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 773 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 774 "data//maps/LilycoveCity/scripts.pory"

# 775 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 776 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 777 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 778 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 779 "data//maps/LilycoveCity/scripts.pory"

# 780 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 781 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 782 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 783 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 784 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 785 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 786 "data//maps/LilycoveCity/scripts.pory"

# 787 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 788 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 789 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 790 "data//maps/LilycoveCity/scripts.pory"

# 791 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 792 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 793 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 794 "data//maps/LilycoveCity/scripts.pory"

# 795 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 796 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 797 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 798 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 799 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 800 "data//maps/LilycoveCity/scripts.pory"

# 801 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 802 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 803 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 804 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 805 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 806 "data//maps/LilycoveCity/scripts.pory"

# 807 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 808 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 809 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 810 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 811 "data//maps/LilycoveCity/scripts.pory"

# 812 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 813 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 814 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 815 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 816 "data//maps/LilycoveCity/scripts.pory"

# 817 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 818 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 819 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 820 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 821 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 822 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 823 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 824 "data//maps/LilycoveCity/scripts.pory"

# 825 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 826 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 827 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 828 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 829 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 830 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
