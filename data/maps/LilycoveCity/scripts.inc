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
	setflag FLAG_VISITED_LILYCOVE_CITY
# 12 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 13 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 14 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 15 "data//maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 16 "data//maps/LilycoveCity/scripts.pory"
	end
# 17 "data//maps/LilycoveCity/scripts.pory"

# 18 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 19 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 20 "data//maps/LilycoveCity/scripts.pory"
	end
# 21 "data//maps/LilycoveCity/scripts.pory"

# 22 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 23 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 24 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 25 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 26 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 27 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 28 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 29 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 30 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 31 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 32 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 33 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 34 "data//maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 35 "data//maps/LilycoveCity/scripts.pory"
	return
# 36 "data//maps/LilycoveCity/scripts.pory"

# 37 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 38 "data//maps/LilycoveCity/scripts.pory"
	lock
# 39 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 40 "data//maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 41 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 42 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 43 "data//maps/LilycoveCity/scripts.pory"
	random 10
# 44 "data//maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 45 "data//maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 46 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 47 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 48 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 49 "data//maps/LilycoveCity/scripts.pory"
	release
# 50 "data//maps/LilycoveCity/scripts.pory"
	end
# 51 "data//maps/LilycoveCity/scripts.pory"

# 52 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 53 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 54 "data//maps/LilycoveCity/scripts.pory"
	release
# 55 "data//maps/LilycoveCity/scripts.pory"
	end
# 56 "data//maps/LilycoveCity/scripts.pory"

# 57 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 58 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 59 "data//maps/LilycoveCity/scripts.pory"
	end
# 60 "data//maps/LilycoveCity/scripts.pory"

# 61 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 62 "data//maps/LilycoveCity/scripts.pory"
	lock
# 63 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 64 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 65 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 66 "data//maps/LilycoveCity/scripts.pory"
	release
# 67 "data//maps/LilycoveCity/scripts.pory"
	end
# 68 "data//maps/LilycoveCity/scripts.pory"

# 69 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 70 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 71 "data//maps/LilycoveCity/scripts.pory"
	release
# 72 "data//maps/LilycoveCity/scripts.pory"
	end
# 73 "data//maps/LilycoveCity/scripts.pory"

# 74 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 75 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 76 "data//maps/LilycoveCity/scripts.pory"
	end
# 77 "data//maps/LilycoveCity/scripts.pory"

# 78 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 79 "data//maps/LilycoveCity/scripts.pory"
	lock
# 80 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 81 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 82 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 83 "data//maps/LilycoveCity/scripts.pory"
	release
# 84 "data//maps/LilycoveCity/scripts.pory"
	end
# 85 "data//maps/LilycoveCity/scripts.pory"

# 86 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 87 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 88 "data//maps/LilycoveCity/scripts.pory"
	release
# 89 "data//maps/LilycoveCity/scripts.pory"
	end
# 90 "data//maps/LilycoveCity/scripts.pory"

# 91 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 92 "data//maps/LilycoveCity/scripts.pory"
	lock
# 93 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 94 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 95 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 96 "data//maps/LilycoveCity/scripts.pory"
	release
# 97 "data//maps/LilycoveCity/scripts.pory"
	end
# 98 "data//maps/LilycoveCity/scripts.pory"

# 99 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 100 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 101 "data//maps/LilycoveCity/scripts.pory"
	release
# 102 "data//maps/LilycoveCity/scripts.pory"
	end
# 103 "data//maps/LilycoveCity/scripts.pory"

# 104 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 105 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 106 "data//maps/LilycoveCity/scripts.pory"
	end
# 107 "data//maps/LilycoveCity/scripts.pory"

# 108 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 109 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 110 "data//maps/LilycoveCity/scripts.pory"
	end
# 111 "data//maps/LilycoveCity/scripts.pory"

# 112 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 113 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 114 "data//maps/LilycoveCity/scripts.pory"
	end
# 115 "data//maps/LilycoveCity/scripts.pory"

# 116 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 117 "data//maps/LilycoveCity/scripts.pory"
	lock
# 118 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 119 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 120 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 121 "data//maps/LilycoveCity/scripts.pory"
	release
# 122 "data//maps/LilycoveCity/scripts.pory"
	end
# 123 "data//maps/LilycoveCity/scripts.pory"

# 124 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 125 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 126 "data//maps/LilycoveCity/scripts.pory"
	release
# 127 "data//maps/LilycoveCity/scripts.pory"
	end
# 128 "data//maps/LilycoveCity/scripts.pory"

# 129 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 130 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 131 "data//maps/LilycoveCity/scripts.pory"
	end
# 132 "data//maps/LilycoveCity/scripts.pory"

# 133 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 134 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 135 "data//maps/LilycoveCity/scripts.pory"
	end
# 136 "data//maps/LilycoveCity/scripts.pory"

# 137 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 138 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 139 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 140 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
# 141 "data//maps/LilycoveCity/scripts.pory"
	end
# 142 "data//maps/LilycoveCity/scripts.pory"

# 143 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 144 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 145 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 146 "data//maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 147 "data//maps/LilycoveCity/scripts.pory"
	end
# 148 "data//maps/LilycoveCity/scripts.pory"

# 149 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 150 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 151 "data//maps/LilycoveCity/scripts.pory"
	end
# 152 "data//maps/LilycoveCity/scripts.pory"

# 153 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 154 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 155 "data//maps/LilycoveCity/scripts.pory"
	end
# 156 "data//maps/LilycoveCity/scripts.pory"

# 157 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 158 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 159 "data//maps/LilycoveCity/scripts.pory"
	end
# 160 "data//maps/LilycoveCity/scripts.pory"

# 161 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 162 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 163 "data//maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 164 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 165 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 166 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 167 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 168 "data//maps/LilycoveCity/scripts.pory"
	end
# 169 "data//maps/LilycoveCity/scripts.pory"

# 170 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 171 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 172 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 173 "data//maps/LilycoveCity/scripts.pory"
	end
# 174 "data//maps/LilycoveCity/scripts.pory"

# 175 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 176 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 177 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 178 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 179 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 180 "data//maps/LilycoveCity/scripts.pory"
	end
# 181 "data//maps/LilycoveCity/scripts.pory"

# 182 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 183 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 184 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 185 "data//maps/LilycoveCity/scripts.pory"
	end
# 186 "data//maps/LilycoveCity/scripts.pory"

# 187 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 188 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 189 "data//maps/LilycoveCity/scripts.pory"
	end
# 190 "data//maps/LilycoveCity/scripts.pory"

# 191 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 192 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 193 "data//maps/LilycoveCity/scripts.pory"
	end
# 194 "data//maps/LilycoveCity/scripts.pory"

# 195 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 196 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 197 "data//maps/LilycoveCity/scripts.pory"
	end
# 198 "data//maps/LilycoveCity/scripts.pory"

# 199 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 200 "data//maps/LilycoveCity/scripts.pory"
	lockall
# 201 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 202 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 203 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 204 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 205 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 206 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 207 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 208 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 209 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 210 "data//maps/LilycoveCity/scripts.pory"
	end
# 211 "data//maps/LilycoveCity/scripts.pory"

# 212 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 213 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 214 "data//maps/LilycoveCity/scripts.pory"
	releaseall
# 215 "data//maps/LilycoveCity/scripts.pory"
	end
# 216 "data//maps/LilycoveCity/scripts.pory"

# 217 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 218 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 219 "data//maps/LilycoveCity/scripts.pory"
	end
# 220 "data//maps/LilycoveCity/scripts.pory"

# 221 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 222 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 223 "data//maps/LilycoveCity/scripts.pory"
	end
# 224 "data//maps/LilycoveCity/scripts.pory"

# 225 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 226 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 227 "data//maps/LilycoveCity/scripts.pory"
	end
# 228 "data//maps/LilycoveCity/scripts.pory"

# 229 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 230 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 231 "data//maps/LilycoveCity/scripts.pory"
	end
# 232 "data//maps/LilycoveCity/scripts.pory"

# 233 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 234 "data//maps/LilycoveCity/scripts.pory"
	lock
# 235 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 236 "data//maps/LilycoveCity/scripts.pory"
	checkplayergender
# 237 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 238 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 239 "data//maps/LilycoveCity/scripts.pory"
	end
# 240 "data//maps/LilycoveCity/scripts.pory"

# 241 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 242 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 243 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 244 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 245 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 246 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 247 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 248 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TREECKO, LilycoveCity_EventScript_BattleMayTreecko
# 249 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TORCHIC, LilycoveCity_EventScript_BattleMayTorchic
# 250 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MUDKIP, LilycoveCity_EventScript_BattleMayMudkip
# 251 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_CASTFORM, LilycoveCity_EventScript_BattleMayTreecko
# 252 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PIPLUP, LilycoveCity_EventScript_BattleMayTorchic
# 253 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_EEVEE, LilycoveCity_EventScript_BattleMayMudkip
# 254 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PICHU, LilycoveCity_EventScript_BattleMayTreecko
# 255 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_TOGEPI, LilycoveCity_EventScript_BattleMayTorchic
# 256 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_PORYGON, LilycoveCity_EventScript_BattleMayMudkip
# 257 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SNIVY, LilycoveCity_EventScript_BattleMayTreecko
# 258 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA_HISUIAN, LilycoveCity_EventScript_BattleMayTorchic
# 259 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ZORUA, LilycoveCity_EventScript_BattleMayMudkip
# 260 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOTHITA, LilycoveCity_EventScript_BattleMayTreecko
# 261 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SOLOSIS, LilycoveCity_EventScript_BattleMayTorchic
# 262 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_AXEW, LilycoveCity_EventScript_BattleMayMudkip
# 263 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVESTA, LilycoveCity_EventScript_BattleMayTreecko
# 264 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_GOOMY, LilycoveCity_EventScript_BattleMayTorchic
# 265 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ROWLET, LilycoveCity_EventScript_BattleMayMudkip
# 266 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_APPLIN, LilycoveCity_EventScript_BattleMayTreecko
# 267 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MIME_JR, LilycoveCity_EventScript_BattleMayTorchic
# 268 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MAGBY, LilycoveCity_EventScript_BattleMayMudkip
# 269 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_ELEKID, LilycoveCity_EventScript_BattleMayTreecko
# 270 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_MANKEY, LilycoveCity_EventScript_BattleMayTorchic
# 271 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_SWINUB, LilycoveCity_EventScript_BattleMayMudkip
# 272 "data//maps/LilycoveCity/scripts.pory"
	case SPECIES_LARVITAR, LilycoveCity_EventScript_BattleMayTreecko
# 273 "data//maps/LilycoveCity/scripts.pory"
	end
# 274 "data//maps/LilycoveCity/scripts.pory"

# 275 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 276 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 277 "data//maps/LilycoveCity/scripts.pory"
	return
# 278 "data//maps/LilycoveCity/scripts.pory"

# 279 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 280 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 281 "data//maps/LilycoveCity/scripts.pory"
	return
# 282 "data//maps/LilycoveCity/scripts.pory"

# 283 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 284 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 285 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 286 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 287 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 288 "data//maps/LilycoveCity/scripts.pory"
	release
# 289 "data//maps/LilycoveCity/scripts.pory"
	end
# 290 "data//maps/LilycoveCity/scripts.pory"

# 291 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 292 "data//maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 293 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 294 "data//maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 295 "data//maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 296 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 297 "data//maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 298 "data//maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 299 "data//maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 300 "data//maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 301 "data//maps/LilycoveCity/scripts.pory"
	end
# 302 "data//maps/LilycoveCity/scripts.pory"

# 303 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 304 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 305 "data//maps/LilycoveCity/scripts.pory"
	return
# 306 "data//maps/LilycoveCity/scripts.pory"

# 307 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 308 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 309 "data//maps/LilycoveCity/scripts.pory"
	return
# 310 "data//maps/LilycoveCity/scripts.pory"

# 311 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 312 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 313 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 314 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 315 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 316 "data//maps/LilycoveCity/scripts.pory"
	release
# 317 "data//maps/LilycoveCity/scripts.pory"
	end
# 318 "data//maps/LilycoveCity/scripts.pory"

# 319 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 320 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 321 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 322 "data//maps/LilycoveCity/scripts.pory"
	end
# 323 "data//maps/LilycoveCity/scripts.pory"

# 324 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 325 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 326 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 327 "data//maps/LilycoveCity/scripts.pory"
	end
# 328 "data//maps/LilycoveCity/scripts.pory"

# 329 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 330 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 331 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 332 "data//maps/LilycoveCity/scripts.pory"
	end
# 333 "data//maps/LilycoveCity/scripts.pory"

# 334 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 335 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 336 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 337 "data//maps/LilycoveCity/scripts.pory"
	end
# 338 "data//maps/LilycoveCity/scripts.pory"

# 339 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 340 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 341 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 342 "data//maps/LilycoveCity/scripts.pory"
	end
# 343 "data//maps/LilycoveCity/scripts.pory"

# 344 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 345 "data//maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 346 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 347 "data//maps/LilycoveCity/scripts.pory"
	end
# 348 "data//maps/LilycoveCity/scripts.pory"

# 349 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 350 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 351 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 352 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 353 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 354 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 355 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 356 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 357 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 358 "data//maps/LilycoveCity/scripts.pory"
	end
# 359 "data//maps/LilycoveCity/scripts.pory"

# 360 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 361 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 362 "data//maps/LilycoveCity/scripts.pory"
	return
# 363 "data//maps/LilycoveCity/scripts.pory"

# 364 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 365 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 366 "data//maps/LilycoveCity/scripts.pory"
	return
# 367 "data//maps/LilycoveCity/scripts.pory"

# 368 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 369 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 370 "data//maps/LilycoveCity/scripts.pory"
	return
# 371 "data//maps/LilycoveCity/scripts.pory"

# 372 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 373 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 374 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 375 "data//maps/LilycoveCity/scripts.pory"
	return
# 376 "data//maps/LilycoveCity/scripts.pory"

# 377 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 378 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 379 "data//maps/LilycoveCity/scripts.pory"
	return
# 380 "data//maps/LilycoveCity/scripts.pory"

# 381 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 382 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 383 "data//maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 384 "data//maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 385 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 386 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 387 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 388 "data//maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 389 "data//maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 390 "data//maps/LilycoveCity/scripts.pory"
	end
# 391 "data//maps/LilycoveCity/scripts.pory"

# 392 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 393 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 394 "data//maps/LilycoveCity/scripts.pory"
	return
# 395 "data//maps/LilycoveCity/scripts.pory"

# 396 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 397 "data//maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 398 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 399 "data//maps/LilycoveCity/scripts.pory"
	return
# 400 "data//maps/LilycoveCity/scripts.pory"

# 401 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 402 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 403 "data//maps/LilycoveCity/scripts.pory"
	return
# 404 "data//maps/LilycoveCity/scripts.pory"

# 405 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 406 "data//maps/LilycoveCity/scripts.pory"
	closemessage
# 407 "data//maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 408 "data//maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 409 "data//maps/LilycoveCity/scripts.pory"
	delay 50
# 410 "data//maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 411 "data//maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 412 "data//maps/LilycoveCity/scripts.pory"
	delay 15
# 413 "data//maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 414 "data//maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 415 "data//maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 416 "data//maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 417 "data//maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 418 "data//maps/LilycoveCity/scripts.pory"
	release
# 419 "data//maps/LilycoveCity/scripts.pory"
	end
# 420 "data//maps/LilycoveCity/scripts.pory"

# 421 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 422 "data//maps/LilycoveCity/scripts.pory"
	lock
# 423 "data//maps/LilycoveCity/scripts.pory"
	faceplayer
# 424 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 425 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 426 "data//maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 427 "data//maps/LilycoveCity/scripts.pory"
	release
# 428 "data//maps/LilycoveCity/scripts.pory"
	end
# 429 "data//maps/LilycoveCity/scripts.pory"

# 430 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 431 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 432 "data//maps/LilycoveCity/scripts.pory"
	return
# 433 "data//maps/LilycoveCity/scripts.pory"

# 434 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 435 "data//maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 436 "data//maps/LilycoveCity/scripts.pory"
	return
# 437 "data//maps/LilycoveCity/scripts.pory"

# 438 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 439 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 440 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 441 "data//maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 442 "data//maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 443 "data//maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 444 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 445 "data//maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 446 "data//maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 447 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 448 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 449 "data//maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 450 "data//maps/LilycoveCity/scripts.pory"

# 451 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 452 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 453 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 454 "data//maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 455 "data//maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 456 "data//maps/LilycoveCity/scripts.pory"

# 457 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 458 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 459 "data//maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 460 "data//maps/LilycoveCity/scripts.pory"

# 461 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 462 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 463 "data//maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 464 "data//maps/LilycoveCity/scripts.pory"

# 465 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 466 "data//maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 467 "data//maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 468 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 469 "data//maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 470 "data//maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 471 "data//maps/LilycoveCity/scripts.pory"

# 472 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 473 "data//maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 474 "data//maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 475 "data//maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 476 "data//maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 477 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 478 "data//maps/LilycoveCity/scripts.pory"

# 479 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 480 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 481 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 482 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 483 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 484 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 485 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 486 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 487 "data//maps/LilycoveCity/scripts.pory"

# 488 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 489 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 490 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 491 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 492 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 493 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 494 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 495 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 496 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 497 "data//maps/LilycoveCity/scripts.pory"

# 498 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 499 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 500 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 501 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 502 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 503 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 504 "data//maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 505 "data//maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 506 "data//maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 507 "data//maps/LilycoveCity/scripts.pory"

# 508 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 509 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 510 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 511 "data//maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 512 "data//maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 513 "data//maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 514 "data//maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 515 "data//maps/LilycoveCity/scripts.pory"

# 516 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 517 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 518 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 519 "data//maps/LilycoveCity/scripts.pory"

# 520 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 521 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 522 "data//maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 523 "data//maps/LilycoveCity/scripts.pory"

# 524 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 525 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 526 "data//maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 527 "data//maps/LilycoveCity/scripts.pory"

# 528 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 529 "data//maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 530 "data//maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 531 "data//maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 532 "data//maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 533 "data//maps/LilycoveCity/scripts.pory"

# 534 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 535 "data//maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 536 "data//maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 537 "data//maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 538 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 539 "data//maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 540 "data//maps/LilycoveCity/scripts.pory"

# 541 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 542 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 543 "data//maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 544 "data//maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 545 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 546 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 547 "data//maps/LilycoveCity/scripts.pory"

# 548 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 549 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 550 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 551 "data//maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 552 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 553 "data//maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 554 "data//maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 555 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 556 "data//maps/LilycoveCity/scripts.pory"

# 557 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 558 "data//maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 559 "data//maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 560 "data//maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 561 "data//maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 562 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 563 "data//maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 564 "data//maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 565 "data//maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 566 "data//maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 567 "data//maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 568 "data//maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 569 "data//maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 570 "data//maps/LilycoveCity/scripts.pory"

# 571 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 572 "data//maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 573 "data//maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 574 "data//maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 575 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 576 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 577 "data//maps/LilycoveCity/scripts.pory"

# 578 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 579 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 580 "data//maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 581 "data//maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 582 "data//maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 583 "data//maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 584 "data//maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 585 "data//maps/LilycoveCity/scripts.pory"

# 586 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 587 "data//maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 588 "data//maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 589 "data//maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 590 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 591 "data//maps/LilycoveCity/scripts.pory"

# 592 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 593 "data//maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 594 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 595 "data//maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 596 "data//maps/LilycoveCity/scripts.pory"

# 597 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 598 "data//maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 599 "data//maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 600 "data//maps/LilycoveCity/scripts.pory"

# 601 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 602 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 603 "data//maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 604 "data//maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 605 "data//maps/LilycoveCity/scripts.pory"

# 606 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 607 "data//maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 608 "data//maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 609 "data//maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 610 "data//maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 611 "data//maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 612 "data//maps/LilycoveCity/scripts.pory"

# 613 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 614 "data//maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 615 "data//maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 616 "data//maps/LilycoveCity/scripts.pory"

# 617 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 618 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 619 "data//maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 620 "data//maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 621 "data//maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 622 "data//maps/LilycoveCity/scripts.pory"

# 623 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 624 "data//maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 625 "data//maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 626 "data//maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 627 "data//maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 628 "data//maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 629 "data//maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 630 "data//maps/LilycoveCity/scripts.pory"

# 631 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 632 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 633 "data//maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 634 "data//maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 635 "data//maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 636 "data//maps/LilycoveCity/scripts.pory"

# 637 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 638 "data//maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 639 "data//maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 640 "data//maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 641 "data//maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 642 "data//maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 643 "data//maps/LilycoveCity/scripts.pory"

# 644 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 645 "data//maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 646 "data//maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 647 "data//maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 648 "data//maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 649 "data//maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 650 "data//maps/LilycoveCity/scripts.pory"

# 651 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 652 "data//maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 653 "data//maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 654 "data//maps/LilycoveCity/scripts.pory"

# 655 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 656 "data//maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 657 "data//maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 658 "data//maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 659 "data//maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 660 "data//maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 661 "data//maps/LilycoveCity/scripts.pory"

# 662 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 663 "data//maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 664 "data//maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 665 "data//maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 666 "data//maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 667 "data//maps/LilycoveCity/scripts.pory"

# 668 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 669 "data//maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 670 "data//maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 671 "data//maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 672 "data//maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 673 "data//maps/LilycoveCity/scripts.pory"

# 674 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 675 "data//maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 676 "data//maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 677 "data//maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 678 "data//maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 679 "data//maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 680 "data//maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 681 "data//maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 682 "data//maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 683 "data//maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 684 "data//maps/LilycoveCity/scripts.pory"

# 685 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 686 "data//maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 687 "data//maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 688 "data//maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 689 "data//maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 690 "data//maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 691 "data//maps/LilycoveCity/scripts.pory"

# 692 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 693 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 694 "data//maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 695 "data//maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 696 "data//maps/LilycoveCity/scripts.pory"

# 697 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 698 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 699 "data//maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 700 "data//maps/LilycoveCity/scripts.pory"

# 701 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 702 "data//maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 703 "data//maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 704 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 705 "data//maps/LilycoveCity/scripts.pory"

# 706 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 707 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 708 "data//maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 709 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 710 "data//maps/LilycoveCity/scripts.pory"

# 711 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 712 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 713 "data//maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 714 "data//maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 715 "data//maps/LilycoveCity/scripts.pory"

# 716 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 717 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 718 "data//maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 719 "data//maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 720 "data//maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 721 "data//maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 722 "data//maps/LilycoveCity/scripts.pory"

# 723 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 724 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 725 "data//maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 726 "data//maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 727 "data//maps/LilycoveCity/scripts.pory"

# 728 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 729 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 730 "data//maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 731 "data//maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 732 "data//maps/LilycoveCity/scripts.pory"

# 733 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 734 "data//maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 735 "data//maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 736 "data//maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 737 "data//maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 738 "data//maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 739 "data//maps/LilycoveCity/scripts.pory"

# 740 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 741 "data//maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 742 "data//maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 743 "data//maps/LilycoveCity/scripts.pory"

# 744 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 745 "data//maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 746 "data//maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 747 "data//maps/LilycoveCity/scripts.pory"

# 748 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 749 "data//maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 750 "data//maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 751 "data//maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 752 "data//maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 753 "data//maps/LilycoveCity/scripts.pory"

# 754 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 755 "data//maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 756 "data//maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 757 "data//maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 758 "data//maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 759 "data//maps/LilycoveCity/scripts.pory"

# 760 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 761 "data//maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 762 "data//maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 763 "data//maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 764 "data//maps/LilycoveCity/scripts.pory"

# 765 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 766 "data//maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 767 "data//maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 768 "data//maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 769 "data//maps/LilycoveCity/scripts.pory"

# 770 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 771 "data//maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 772 "data//maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 773 "data//maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 774 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 775 "data//maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 776 "data//maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 777 "data//maps/LilycoveCity/scripts.pory"

# 778 "data//maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 779 "data//maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 780 "data//maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 781 "data//maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 782 "data//maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 783 "data//maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"
